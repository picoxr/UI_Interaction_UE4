//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

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
	
	// Acoustic material preset corresponding to real-world material types.
	// Absorption, scattering, and transmission will be automatically set based on the physical nature of the selected material.
	// Deviating acoustic parameters away from preset values will automatically set this field to 'Custom'
	UPROPERTY(EditAnywhere, Category = "Presets")
	EPxrAudioSpatializer_SceneMaterialPreset MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile;

	// Ratio of sound energy absorbed by each reflection for band 1000 Hz
	UPROPERTY(EditAnywhere, DisplayName="Absorption Band 1000 Hz", Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand0 = 0.5f;

	// Ratio of sound energy absorbed by each reflection for band 2000 Hz
	UPROPERTY(EditAnywhere, DisplayName="Absorption Band 2000 Hz", Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand1 = 0.5f;

	// Ratio of sound energy absorbed by each reflection for band 4000 Hz
	UPROPERTY(EditAnywhere, DisplayName="Absorption Band 4000 Hz", Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand2 = 0.5f;

	// Ratio of sound energy absorbed by each reflection for band 8000 Hz
	UPROPERTY(EditAnywhere, DisplayName="Absorption Band 8000 Hz", Category = "Acoustic Properties | Absorption", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float AbsorptionBand3 = 0.5f;

	// Ratio of sound energy get scattered by each reflection.
	//   - Low scattering will result in a more echoic sound
	//   - high scattering will result in a more reverberant sound
	UPROPERTY(EditAnywhere, Category = "Acoustic Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float Scattering = 0.1f;

	// Ratio of sound energy get transmitted through this material.
	UPROPERTY(EditAnywhere, Category = "Acoustic Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float Transmission = 0.0f;
};
