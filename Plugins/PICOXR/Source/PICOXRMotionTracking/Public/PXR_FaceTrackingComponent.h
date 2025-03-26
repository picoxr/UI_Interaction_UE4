// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "PXR_MorphTargetsManager.h"
#include "PXR_MotionTrackingTypes.h"
#include "PXR_FaceTrackingComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent, DisplayName = "PICO Face Tracking Component"), ClassGroup = PXRHMD)
class PICOXRMOTIONTRACKING_API UPXR_FaceTrackingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UPXR_FaceTrackingComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Components|FaceTracking", meta = (UnsafeDuringActorConstruction = "true"))
	void SetBlendShapeValue(EPXRFaceBlendShape BlendShape, float Value);

	UFUNCTION(BlueprintCallable, Category = "Components|FaceTracking")
	float GetBlendShapeValue(EPXRFaceBlendShape BlendShape) const;

	UFUNCTION(BlueprintCallable, Category = "Components|FaceTracking")
	void ClearBlendShapeValues();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PXR|FaceTracking")
	FName FTTargetMeshComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PXR|FaceTracking")
	float InvalidFaceDataResetTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PXR|FaceTracking")
	TMap<EPXRFaceBlendShape, FName> BlendShapeNameMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FaceTracking")
	bool bUpdateFaceTracking;

private:
	bool InitializeFaceTracking();

	UPROPERTY()
	USkinnedMeshComponent* FTTargetMeshComponent;

	TStaticArray<bool, static_cast<uint32>(EPXRFaceBlendShape::COUNT)> ValidBlendShape;

	FPXRMorphTargetsManager MorphTargetsManager;

	FPXRFaceTrackingData FaceData;

	float InvalidFaceDataTimer;

	static int FTComponentCount;

	bool IsTracking;

	FPXRFaceTrackingState TrackingState;
};
