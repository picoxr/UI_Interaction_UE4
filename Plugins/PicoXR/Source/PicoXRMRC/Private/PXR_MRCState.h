//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PXR_MRCState.generated.h"

struct FPXRTrackedCamera
{
	float FOV;
	int32 Width;
	int32 Height;
	FRotator CalibratedRotation;
	FVector CalibratedOffset;
	
	FPXRTrackedCamera()
		: FOV(90.0f)
		, Width(1280)
		, Height(720)
		, CalibratedRotation(EForceInit::ForceInitToZero)
		, CalibratedOffset(EForceInit::ForceInitToZero)
	{}
};

UCLASS()
class UPXRInGameThirdCamState : public UObject
{
	GENERATED_BODY()

public:

	UPXRInGameThirdCamState(const FObjectInitializer& ObjectInitializer);

	FPXRTrackedCamera TrackedCamera;

	FTransform FinalTransform;//Relative to the tracking reference

	float ZOffset;

	class USceneComponent* CurrentTrackingReference;

	bool bUseCustomTrans;

	FTransform CustomTrans;
};
