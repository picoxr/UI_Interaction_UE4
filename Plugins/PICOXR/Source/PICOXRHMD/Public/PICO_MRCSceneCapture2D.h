// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "PICO_MRCSceneCapture2D.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (PICOXRComponent), meta = (BlueprintSpawnableComponent))
class PICOXRHMD_API AMRCSceneCapture2DPICO : public ASceneCapture2D
{
	GENERATED_BODY()
	
public:
	AMRCSceneCapture2DPICO(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY()
	UTextureRenderTarget2D* BackgroundRT;

	UPROPERTY()
	UTextureRenderTarget2D* ForegroundRT;

private:
	class FPICOXRHMD* HMDPICO;
	int Width;
	int Height;
	float Fov;
	bool FlipFlop;
	void InitializeRTRenderResource(UTextureRenderTarget2D* RT);
	void UpdateCamMatrixAndDepth(bool bIsForeground);
	bool GetExternalCameraPose(FTransform& Pose);
};
