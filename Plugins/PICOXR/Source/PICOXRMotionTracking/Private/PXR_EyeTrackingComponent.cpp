// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_EyeTrackingComponent.h"

#include "GameFramework/WorldSettings.h"
#include "GameFramework/PlayerController.h"
#include "PXR_HMDModule.h"
#include "PXR_HMDPrivate.h"
#include "PXR_PluginWrapper.h"
#include "PXR_MotionTrackingFunctionLibrary.h"
#include "PXR_MotionTrackingUtility.h"
#include "PXR_Log.h"

int UPXR_EyeTrackingComponent::ETComponentCount = 0;

UPXR_EyeTrackingComponent::UPXR_EyeTrackingComponent()
	: ETTargetMeshComponentName(NAME_None)
	, bUpdatePosition(true)
	, bUpdateRotation(true)
	, ConfidenceThreshold(0.0f)
	, bCanEyeDataInvalid(false)
	, WorldToMetersScale(100.f)
	, ETTargetMeshComponent(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	EyeToBoneMapping.Add(EPICOEye::Left, "LeftEye");
	EyeToBoneMapping.Add(EPICOEye::Right, "RightEye");
}

void UPXR_EyeTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	bool Supported;
	TArray<EPXREyeTrackingMode> Modes;
	UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingSupported(Supported, Modes);
	if (!Supported)
	{
		PXR_LOGW(PxrUnreal, "Eye tracking is not supported. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!InitializeEyeTracking())
	{
		PXR_LOGW(PxrUnreal, "Failed to initialize eye tracking data. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
	}
	FPXREyeTrackingStartInfo Info;
	Info.StartMode = EPXREyeTrackingMode::PXR_ETM_BOTH;
	Info.NeedCalibration = false;
	if (!UPICOXRMotionTrackingFunctionLibrary::StartEyeTracking(Info))
	{
		PXR_LOGW(PxrUnreal, "Failed to start eye tracking. (%s: %s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	++ETComponentCount;
}

void UPXR_EyeTrackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsComponentTickEnabled())
	{
		if (--ETComponentCount == 0)
		{
			FPXREyeTrackingStopInfo Info;
			if (!UPICOXRMotionTrackingFunctionLibrary::StopEyeTracking(Info))
			{
				PXR_LOGW(PxrUnreal, "Failed to stop eye tracking. (%s: %s)", *GetOwner()->GetName(), *GetName());
			}
		}
	}
	Super::EndPlay(EndPlayReason);
}

void UPXR_EyeTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(ETTargetMeshComponent))
	{
		PXR_LOGV(PxrUnreal, "No target mesh specified. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	FPXREyeTrackingDataGetInfo Info;
	FPXREyeTrackingData EyeData;
	Info.DisplayTime = 0;
	Info.QueryPosition = bUpdatePosition;
	Info.QueryOrientation = bUpdateRotation;

	if (UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingData(WorldToMetersScale, Info, EyeData))
	{
		for (uint8 i = 0; i < static_cast<uint8>(EPICOEye::COUNT); ++i)
		{
			if ((bCanEyeDataInvalid || EyeData.PerEyeDatas[i].bIsPoseValid))
			{
				if (PerEyeData[i].EyeIsMapped)
				{
					const auto& Bone = PerEyeData[i].MappedBoneName;
					int32 BoneIndex = ETTargetMeshComponent->GetBoneIndex(Bone);
					FTransform CurrentTransform = ETTargetMeshComponent->GetBoneTransformByName(Bone, EBoneSpaces::ComponentSpace);
					if (bUpdatePosition)
					{
						CurrentTransform.SetLocation(EyeData.PerEyeDatas[i].Position);
					}

					if (bUpdateRotation)
					{
						CurrentTransform.SetRotation(EyeData.PerEyeDatas[i].Orientation.Quaternion() * PerEyeData[i].InitialRotation);
					}

					ETTargetMeshComponent->SetBoneTransformByName(Bone, CurrentTransform, EBoneSpaces::ComponentSpace);
				}
			}
		}
	}
	else
	{
		PXR_LOGV(PxrUnreal, "Failed to get Eye state from EyeTrackingComponent. (%s:%s)", *GetOwner()->GetName(), *GetName());
	}
}

void UPXR_EyeTrackingComponent::ResetEyeRotationValues()
{
	if (!IsValid(ETTargetMeshComponent))
	{
		PXR_LOGV(PxrUnreal, "No target mesh specified. (%s:%s)", *GetOwner()->GetName(), *GetName());
		return;
	}

	for (uint8 i = 0u; i < static_cast<uint8>(EPICOEye::COUNT); ++i)
	{
		if (PerEyeData[i].EyeIsMapped)
		{
			const auto& Bone = PerEyeData[i].MappedBoneName;

			int32 BoneIndex = ETTargetMeshComponent->GetBoneIndex(Bone);
			FTransform CurrentTransform = ETTargetMeshComponent->GetBoneTransformByName(Bone, EBoneSpaces::ComponentSpace);

			CurrentTransform.SetRotation(PerEyeData[i].InitialRotation);

			ETTargetMeshComponent->SetBoneTransformByName(Bone, CurrentTransform, EBoneSpaces::ComponentSpace);
		}
	}
}

bool UPXR_EyeTrackingComponent::InitializeEyeTracking()
{
	bool bIsAnythingMapped = false;

	ETTargetMeshComponent = PXRUtility::FindComponentByName<UPoseableMeshComponent>(GetOwner(), ETTargetMeshComponentName);

	if (!IsValid(ETTargetMeshComponent))
	{
		PXR_LOGW(PxrUnreal, "Could not find mesh with name (%s) for component. (%s:%s)", *ETTargetMeshComponentName.ToString(), *GetOwner()->GetName(), *GetName());
		return false;
	}

	for (uint8 i = 0u; i < static_cast<uint8>(EPICOEye::COUNT); ++i)
	{
		const EPICOEye Eye = static_cast<EPICOEye>(i);
		const FName* BoneNameForThisEye = EyeToBoneMapping.Find(Eye);
		PerEyeData[i].EyeIsMapped = (nullptr != BoneNameForThisEye);

		if (PerEyeData[i].EyeIsMapped)
		{
			int32 BoneIndex = ETTargetMeshComponent->GetBoneIndex(*BoneNameForThisEye);
			if (BoneIndex == INDEX_NONE)
			{
				PerEyeData[i].EyeIsMapped = false;
				PXR_LOGW(PxrUnreal, "Could not find bone by name (%s) in mesh %s. (%s:%s)", *BoneNameForThisEye->ToString(), *ETTargetMeshComponent->GetName(), *GetOwner()->GetName(), *GetName());
			}
			else
			{
				PerEyeData[i].MappedBoneName = *BoneNameForThisEye;
				PerEyeData[i].InitialRotation = ETTargetMeshComponent->GetBoneTransformByName(*BoneNameForThisEye, EBoneSpaces::ComponentSpace).GetRotation();
				bIsAnythingMapped = true;
			}
		}
		else
		{
			PXR_LOGD(PxrUnreal, "Eye (%s) is not mapped to any bone on mesh (%s)", *StaticEnum<EPICOEye>()->GetValueAsString(Eye), *ETTargetMeshComponent->GetName());
		}
	}

	if (!bIsAnythingMapped)
	{
		PXR_LOGW(PxrUnreal, "Component name -- %s:%s, doesn't have a valid configuration.", *GetOwner()->GetName(), *GetName());
	}

	if (!GetWorldToMetersScaleFromSettings(GetWorld(), WorldToMetersScale))
	{
		PXR_LOGW(PxrUnreal, "Cannot get world settings. (%s:%s)", *GetOwner()->GetName(), *GetName());
	}

	return bIsAnythingMapped;
}
