//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HandComponent.h"
#include <GameFramework/PlayerController.h>
#include "PXR_Settings.h"
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
#if PLATFORM_ANDROID
#include "PxrInput.h"
#endif

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
	if (SkeletalMesh)
	{
		bCustomHandMesh = true;
	}
	//Hide Component if HandTracking is Disabled
	const bool bStartHidden = UPICOXRInputFunctionLibrary::IsHandTrackingEnabled() ? false : true;
	SetHiddenInGame(bStartHidden, true);
}

void UPICOXRHandComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

		if (SkeletalMesh)
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

void UPICOXRHandComponent::UpdateBonePose()
{
	if (bCustomHandMesh)
	{
		for (auto& BoneElem : BoneNameMappings)
		{
			if (BoneElem.Key == EPICOXRHandJoint::Wrist)
			{
				FTransform BoneTransform = UPICOXRInputFunctionLibrary::GetHandRootPose(SkeletonType);
				if (!BoneTransform.Rotator().ContainsNaN() && !BoneTransform.Rotator().IsZero())
				{
					SetBoneRotationByName(BoneElem.Value, BoneTransform.Rotator(), EBoneSpaces::WorldSpace);
				}
			}
			else
			{
#if ENGINE_MINOR_VERSION >26
 				const int32 BoneIndex = SkeletalMesh->GetRefSkeleton().FindBoneIndex(BoneElem.Value);
#else
				const int32 BoneIndex = SkeletalMesh->RefSkeleton.FindBoneIndex(BoneElem.Value);
#endif
				if (BoneIndex >= 0)
				{
					FQuat BoneRotation = UPICOXRInputFunctionLibrary::GetBoneRotation(SkeletonType, BoneElem.Key);
					if (!BoneRotation.IsIdentity())
					{
						BoneSpaceTransforms[BoneIndex].SetRotation(BoneRotation);
					}
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
