// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_FaceTrackingComponent.h"
#include "PXR_HMD.h"
#include "PXR_PluginWrapper.h"
#include "PXR_MotionTrackingFunctionLibrary.h"
#include "PXR_MotionTrackingUtility.h"
#include "PXR_Log.h"
#include "Engine/SkeletalMesh.h"

int UPXR_FaceTrackingComponent::FTComponentCount = 0;

UPXR_FaceTrackingComponent::UPXR_FaceTrackingComponent()
	: FTTargetMeshComponentName(NAME_None)
	, InvalidFaceDataResetTime(2.0f)
	, bUpdateFaceTracking(true)
	, FTTargetMeshComponent(nullptr)
	, IsTracking(false)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	BlendShapeNameMapping.Add(EPXRFaceBlendShape::BrowInnerUp, "browInnerUp");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::BrowDown_R, "browDown_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::BrowDown_L, "browDown_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::BrowOuterUp_L, "browOuterUp_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::BrowOuterUp_R, "browOuterUp_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::CheekSquint_L, "cheekSquint_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::CheekSquint_R, "cheekSquint_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::CheekPuff, "cheekPuff");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookDown_L, "eyeLookDown_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookIn_L, "eyeLookIn_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookIn_R, "eyeLookIn_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookDown_R, "eyeLookDown_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeSquint_L, "eyeSquint_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeBlink_L, "eyeBlink_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookUp_L, "eyeLookUp_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookUp_R, "eyeLookUp_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeBlink_R, "eyeBlink_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeSquint_R, "eyeSquint_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookOut_L, "eyeLookOut_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeLookOut_R, "eyeLookOut_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeWide_R, "eyeWide_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::EyeWide_L, "eyeWide_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::JawOpen, "jawOpen");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::JawRight, "jawRight");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::JawForward, "jawForward");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::JawLeft, "jawLeft");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthClose, "mouthClose");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthLowerDown_R, "mouthLowerDown_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthUpperUp_R, "mouthUpperUp_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthShrugUpper, "mouthShrugUpper");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthFunnel, "mouthFunnel");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthRollUpper, "mouthRollUpper");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthShrugLower, "mouthShrugLower");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthRollLower, "mouthRollLower");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthSmile_L, "mouthSmile_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthPress_L, "mouthPress_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthSmile_R, "mouthSmile_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthPress_R, "mouthPress_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthDimple_R, "mouthDimple_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthLeft, "mouthLeft");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthFrown_L, "mouthFrown_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthStretch_L, "mouthStretch_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthPucker, "mouthPucker");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthUpperUp_L, "mouthUpperUp_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthFrown_R, "mouthFrown_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthStretch_R, "mouthStretch_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthRight, "mouthRight");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthDimple_L, "mouthDimple_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::MouthLowerDown_L, "mouthLowerDown_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::NoseSneer_L, "noseSneer_L");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::NoseSneer_R, "noseSneer_R");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::TongueOut, "tongueOut");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::PP, "PP");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::CH, "CH");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::o, "o");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::O, "O");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::I, "I");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::u, "u");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::RR, "RR");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::XX, "XX");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::aa, "aa");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::i, "i");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::FF, "FF");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::U, "U");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::TH, "TH");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::kk, "kk");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::SS, "SS");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::e, "e");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::DD, "DD");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::E, "E");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::nn, "nn");
	BlendShapeNameMapping.Add(EPXRFaceBlendShape::sil, "sil");
}

void UPXR_FaceTrackingComponent::BeginPlay()
{
	Super::BeginPlay();
	bool Supported;
	TArray<EPXRFaceTrackingMode> Modes;
	UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingSupported(Supported, Modes);
	if (!Supported)
	{
		PXR_LOGW(PxrUnreal, "Face tracking is not supported. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (FTTargetMeshComponentName == NAME_None)
	{
		PXR_LOGW(PxrUnreal, "Invalid mesh component name. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!InitializeFaceTracking())
	{
		PXR_LOGW(PxrUnreal, "Failed to initialize face tracking. (%s:%s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	FPXRFaceTrackingStartInfo StartInfo;
	StartInfo.StartMode = EPXRFaceTrackingMode::PXR_FTM_FACE;
	if (!UPICOXRMotionTrackingFunctionLibrary::StartFaceTracking(StartInfo))
	{
		PXR_LOGW(PxrUnreal, "Failed to start face tracking. (%s: %s)", *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	++FTComponentCount;
}

void UPXR_FaceTrackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsComponentTickEnabled())
	{
		if (--FTComponentCount == 0)
		{
			FPXRFaceTrackingStopInfo StopInfo;
			StopInfo.Pause = false;
			if (!UPICOXRMotionTrackingFunctionLibrary::StopFaceTracking(StopInfo))
			{
				PXR_LOGW(PxrUnreal, "Failed to stop face tracking. (%s: %s)", *GetOwner()->GetName(), *GetName());
			}
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UPXR_FaceTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(FTTargetMeshComponent))
	{
		PXR_LOGV(PxrUnreal, "No target mesh specified. (%s:%s)", *GetOwner()->GetName(), *GetName());
		return;
	}
	FPXRFaceTrackingDataGetInfo GetInfo;
	GetInfo.DisplayTime = 0;
	UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingState(IsTracking, TrackingState);
	if (IsTracking && bUpdateFaceTracking)
	{
		UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingData(GetInfo, FaceData);
		InvalidFaceDataTimer = 0.0f;

		MorphTargetsManager.ResetMeshMorphTargetCurves(FTTargetMeshComponent);

		for (int32 FaceBlendShapeIndex = 0; FaceBlendShapeIndex < static_cast<int32>(EPXRFaceBlendShape::COUNT); ++FaceBlendShapeIndex)
		{
			if (ValidBlendShape[FaceBlendShapeIndex])
			{
				FName BlendShapeName = BlendShapeNameMapping[static_cast<EPXRFaceBlendShape>(FaceBlendShapeIndex)];
				MorphTargetsManager.SetMeshMorphTargetValue(BlendShapeName, FaceData.BlendShapeWeights[FaceBlendShapeIndex]);
			}
		}
	}
	else
	{
		InvalidFaceDataTimer += DeltaTime;
		if (InvalidFaceDataTimer >= InvalidFaceDataResetTime)
		{
			MorphTargetsManager.ResetMeshMorphTargetCurves(FTTargetMeshComponent);
			static const UEnum* Enum = StaticEnum<EPXRFaceTrackingMode>();
			check(Enum);
			PXR_LOGW(PxrUnreal, "Face tracker is not tracking.Mode:%s,State code:%s", *Enum->GetNameStringByValue(int64(TrackingState.TrackingStateCode)));
		}
	}

	MorphTargetsManager.UpdateMeshMorphTargets(FTTargetMeshComponent);
}

void UPXR_FaceTrackingComponent::SetBlendShapeValue(EPXRFaceBlendShape BlendShape, float Value)
{
	if (BlendShape >= EPXRFaceBlendShape::COUNT)
	{
		PXR_LOGW(PxrUnreal, "Cannot set BlendShape value with invalid BlendShape index.");
		return;
	}

	if (!ValidBlendShape[static_cast<int32>(BlendShape)])
	{
		PXR_LOGW(PxrUnreal, "Cannot set BlendShape value for an BlendShape with an invalid associated morph target name. BlendShape name: %s", *StaticEnum<EPXRFaceBlendShape>()->GetValueAsString(BlendShape));
		return;
	}

	FName BlendShapeName = BlendShapeNameMapping[BlendShape];
	MorphTargetsManager.SetMeshMorphTargetValue(BlendShapeName, Value);
}

float UPXR_FaceTrackingComponent::GetBlendShapeValue(EPXRFaceBlendShape BlendShape) const
{
	if (BlendShape >= EPXRFaceBlendShape::COUNT)
	{
		PXR_LOGW(PxrUnreal, "Cannot request BlendShape value using an invalid BlendShape index.");
		return 0.0f;
	}

	FName BlendShapeName = BlendShapeNameMapping[BlendShape];
	if (BlendShapeName == NAME_None)
	{
		PXR_LOGW(PxrUnreal, "Cannot request BlendShape value for an BlendShape with an invalid associated morph target name. BlendShape name: %s", *StaticEnum<EPXRFaceBlendShape>()->GetValueAsString(BlendShape));
		return 0.0f;
	}

	return MorphTargetsManager.GetMeshMorphTargetValue(BlendShapeName);
}

void UPXR_FaceTrackingComponent::ClearBlendShapeValues()
{
	MorphTargetsManager.EmptyMorphTargets();
}

bool UPXR_FaceTrackingComponent::InitializeFaceTracking()
{
	FTTargetMeshComponent = PXRUtility::FindComponentByName<USkinnedMeshComponent>(GetOwner(), FTTargetMeshComponentName);

	if (!IsValid(FTTargetMeshComponent))
	{
		PXR_LOGW(PxrUnreal, "Could not find skeletal mesh component with name: (%s). (%s:%s)", *FTTargetMeshComponentName.ToString(), *GetOwner()->GetName(), *GetName());
		return false;
	}

	if (FTTargetMeshComponent && FTTargetMeshComponent->GetSkinnedAsset())
	{
		const TMap<FName, int32>& MorphTargetIndexMap = Cast<USkeletalMesh>(FTTargetMeshComponent->GetSkinnedAsset())->GetMorphTargetIndexMap();

		for (const auto& it : BlendShapeNameMapping)
		{
			ValidBlendShape[static_cast<int32>(it.Key)] = MorphTargetIndexMap.Contains(it.Value);
		}

		return true;
	}

	return false;
}
