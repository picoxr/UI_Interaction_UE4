//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.


#include "PXR_MRCState.h"

UPXRInGameThirdCamState::UPXRInGameThirdCamState(const FObjectInitializer& ObjectInitializer)
	: TrackedCamera()
	,FinalTransform(FTransform::Identity)
	,ZOffset(0)
	,CurrentTrackingReference(nullptr)
	,bUseCustomTrans(false)
{
	CustomTrans = FTransform::Identity;
}