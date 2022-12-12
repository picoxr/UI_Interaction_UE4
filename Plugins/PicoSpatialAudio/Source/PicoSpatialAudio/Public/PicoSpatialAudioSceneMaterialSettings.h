// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PicoSpatialAudioEnums.h"
#include "pxr_audio_spatializer.h"
#include "pxr_audio_spatializer_types.h"
#include "PicoSpatialAudioSceneMaterialSettings.generated.h"

/**
 * 
 */
UCLASS()
class PICOSPATIALAUDIO_API UPicoSpatialAudioSceneMaterialSettings : public UObject
{
	GENERATED_BODY()

public:
	UPicoSpatialAudioSceneMaterialSettings();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	//	Material setups
	UPROPERTY(EditAnywhere, Category = "Presets")
	EPxrAudioSpatializer_SceneMaterialPreset MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile;
	
	UPROPERTY(EditAnywhere, Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand0 = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand1 = 0.5f;
	
	UPROPERTY(EditAnywhere, Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand2 = 0.5f;
    	
	UPROPERTY(EditAnywhere, Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand3 = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Acoustic Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float Scattering = 0.1f;

	UPROPERTY(EditAnywhere, Category = "Acoustic Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float Transmission = 0.0f;
};
