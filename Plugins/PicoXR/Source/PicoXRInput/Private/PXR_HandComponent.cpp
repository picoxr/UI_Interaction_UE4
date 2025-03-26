// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_HandComponent.h"
#include <GameFramework/PlayerController.h>
#include "PXR_HMDRuntimeSettings.h"
#include "PXR_EventManager.h"
#include "PXR_InputFunctionLibrary.h"
#include "PXR_InputState.h"
#include "Engine/SkeletalMesh.h"
#include "Components/InputComponent.h"
#include "Materials/MaterialInterface.h"
#include "PXR_HMDFunctionLibrary.h"
#include "Camera/PlayerCameraManager.h"
#include "PXR_Input.h"
#include "PXR_Log.h"

UPICOXRHandComponent::UPICOXRHandComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer),
	SkeletonType(EPICOXRHandType::None),
	bUpdateHandScale(false)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;

	bAutoActivate = true;
	bWantsInitializeComponent = true;
	for (uint8 BoneIndex = 0; BoneIndex < static_cast<uint8>(EHandJointCount); BoneIndex++)
	{
		BoneNameMappings.Add(static_cast<EPICOXRHandJoint>(BoneIndex), TEXT(""));
	}
}

void UPICOXRHandComponent::BeginPlay()
{
	Super::BeginPlay();
	// Use custom mesh if a skeletal mesh is already set, else try to load the runtime mesh
	if (GetSkinnedAsset())
	{
		bCustomHandMesh = true;
	}
	//Hide Component if HandTracking is Disabled
	const bool bStartHidden = UPICOXRInputFunctionLibrary::IsHandTrackingEnabled() ? false : true;
	SetHiddenInGame(bStartHidden, true);
	UPICOXRSettings* HMDSettings = GetMutableDefault<UPICOXRSettings>();

	if (HMDSettings)
	{
		bUpdateHandScale=HMDSettings->bAdaptiveHandModel;
	}
	
}

void UPICOXRHandComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsInGameThread())
	{
		const AActor* Owner = GetOwner();
		bHasAuthority = Owner->HasLocalNetOwner();
	}

	if (bHasAuthority)
	{
		bool bHidden = false;
		if (UPICOXRInputFunctionLibrary::IsHandTrackingEnabled())
		{
			if (bHideByConfidence)
			{
				const EPICOXRHandTrackingConfidence TrackingConfidence = UPICOXRInputFunctionLibrary::GetTrackingConfidence(SkeletonType);
				bHidden |= TrackingConfidence != EPICOXRHandTrackingConfidence::High;
			}

			if (bUpdateHandScale)
			{
				const float NewScale = UPICOXRInputFunctionLibrary::GetHandScale(SkeletonType);
				SetRelativeScale3D(FVector(NewScale));
			}

			if (GetSkinnedAsset())
			{
				UpdateBonePose();
				UpdateHandTransform();
			}
		}
		else
		{
			bHidden = true;
		}

		if (bHidden != bHiddenInGame)
		{
			SetHiddenInGame(bHidden, true);
		}
	}
}

void UPICOXRHandComponent::UpdateBonePose()
{
	if (bCustomHandMesh)
	{
		for (auto& BoneElem : BoneNameMappings)
		{
 			const int32 BoneIndex = GetSkinnedAsset()->GetRefSkeleton().FindBoneIndex(BoneElem.Value);
			if (BoneIndex >= 0)
			{
				FQuat BoneRotation = UPICOXRInputFunctionLibrary::GetBoneRotation(SkeletonType, BoneElem.Key);
				if (!BoneRotation.IsIdentity()&&BoneRotation.IsNormalized())
				{
					SetBoneRotationByName(BoneElem.Value, BoneRotation.Rotator(), EBoneSpaces::ComponentSpace);
				}

				const FVector BoneLocation = UPICOXRInputFunctionLibrary::GetBoneLocation(SkeletonType, BoneElem.Key);
				if (!BoneLocation.IsZero()&&!BoneLocation.ContainsNaN()&&bApplyLocationToBones)
				{
					SetBoneLocationByName(BoneElem.Value, BoneLocation, EBoneSpaces::WorldSpace);
				}
			}
		}
	}

	MarkRefreshTransformDirty();
}

void UPICOXRHandComponent::UpdateHandTransform()
{
	const FTransform HandPose = UPICOXRInputFunctionLibrary::GetHandRootPose(SkeletonType);
	if (HandPose.IsValid() && !HandPose.Equals(FTransform()))
	{
		if (!HandPose.GetLocation().ContainsNaN())
		{
			this->SetRelativeLocation(HandPose.GetLocation());
		}
	}
}
