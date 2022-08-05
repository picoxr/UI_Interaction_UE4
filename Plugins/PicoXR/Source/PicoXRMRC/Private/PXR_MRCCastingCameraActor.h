//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Engine/SceneCapture2D.h"
#include "PXR_MRCModule.h"
#include "PXR_MRCCastingCameraActor.generated.h"

class UPXRInGameThirdCamState;
class UTextureRenderTarget2D;
class UMaterial;
class UMaterialInstanceDynamic;

UCLASS(NotPlaceable, NotBlueprintable)
class APicoXRMRC_CastingCameraActor : public ASceneCapture2D
{
	GENERATED_BODY()
public:
	APicoXRMRC_CastingCameraActor(const FObjectInitializer& ObjectInitializer);

	/** Initialize the MRC settings and states */
	void InitializeStates(UPXRInGameThirdCamState * MRStateIn);

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginDestroy() override;

	UPROPERTY()
	ASceneCapture2D* ForegroundCaptureActor;

	UPROPERTY()
	UTextureRenderTarget2D* BackgroundRenderTarget;

	UPROPERTY()
	UTextureRenderTarget2D* ForegroundRenderTarget;

	bool bEnableForeground;
private:
	
	void InitializeInGameCam();
	void InitializeRTSize();
	void SetMRCTrackingReference();
	void UpdateInGameCamPose();
	void UpdateCamMatrixAndDepth();
	void SpawnForegroundCaptureActor();
	void DestroyForeroundCaptureActor();

	float ForegroundMaxDistance;
	bool bHasInitializedInGameCamOnce;

private:
	UPROPERTY()
	UPXRInGameThirdCamState* MRState;

	UPROPERTY()
	UMaterial* M_MRC;

	UPROPERTY()
	UMaterialInstanceDynamic * MI_Background;

	UPROPERTY()
	UMaterialInstanceDynamic*  MI_Foreground;
	
	void OnHMDRecentered();

	void OnHMDResume();
};
