// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/PoseableMeshComponent.h"

#include "PXR_MotionTrackingTypes.h"

#include "PXR_EyeTrackingComponent.generated.h"

struct FPXREyeBoneManager
{
public:
	FPXREyeBoneManager()
		: EyeIsMapped(false)
		, MappedBoneName(NAME_None)
	{
	}

	bool EyeIsMapped;
	FName MappedBoneName;
	FQuat InitialRotation;
};

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent, DisplayName = "PICO Eye Tracking Component"), ClassGroup = OculusHMD)
class PICOXRMOTIONTRACKING_API UPXR_EyeTrackingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UPXR_EyeTrackingComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
	void ResetEyeRotationValues();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PXR|EyeTracking")
	FName ETTargetMeshComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PXR|EyeTracking")
	TMap<EPICOEye, FName> EyeToBoneMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
	bool bUpdatePosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
	bool bUpdateRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
	float ConfidenceThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
	bool bCanEyeDataInvalid;

private:
	bool InitializeEyeTracking();

	float WorldToMetersScale;

	// Per eye, eye tracking data
	TStaticArray<FPXREyeBoneManager, static_cast<uint32>(EPICOEye::COUNT)> PerEyeData;

	UPROPERTY()
	UPoseableMeshComponent* ETTargetMeshComponent;

	static int ETComponentCount;

	bool IsTracking;

	FPXREyeTrackingState TrackingState;
};
