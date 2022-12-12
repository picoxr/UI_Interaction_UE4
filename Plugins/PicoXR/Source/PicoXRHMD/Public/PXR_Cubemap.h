//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PXR_Cubemap.generated.h"

class USceneCaptureComponent2D;
UCLASS()
class PICOXRHMD_API APXR_Cubemap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APXR_Cubemap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool isCatchImageWP = false;
	FString OutputDir;
	uint32 CaptureBoxSideRes = 1024;
	FQuat Orientation = FQuat::Identity;
	FVector Location = FVector::ZeroVector;
	EPixelFormat CaptureFormat = PF_A16B16G16R16;

	bool SaveCubeMap_PICO();

private:
	UPROPERTY()
		TArray<USceneCaptureComponent2D*> CaptureComponents;

	UFUNCTION(BlueprintCallable, CallInEditor)
		void PXR_CubemapHandler();

};
