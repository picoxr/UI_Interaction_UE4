//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#if WITH_EDITOR
#include "Editor.h"
#endif
#include "IAudioExtensionPlugin.h"
#include "PicoSpatialAudioEnums.h"
#include "pxr_audio_spatializer_types.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include "PicoSpatializationSourceSettings.generated.h"

/**
 * 
 */
UCLASS()
class PICOSPATIALAUDIO_API UPicoSpatializationSourceSettings : public USpatializationPluginSourceSettingsBase
{
	GENERATED_BODY()

public:
	UPicoSpatializationSourceSettings();
#if WITH_EDITOR
	// See if Audio Component references this settings instance:
	bool DoesAudioComponentReferenceThis(class UAudioComponent* InAudioComponent);

	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	// Master gain of this sound source in dBFS.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings",
		meta = (ClampMin = "0.0", ClampMax = "24.0", UIMin = "0.0", UIMax = "24.0"))
	float SourceGainDb;

	// Gain of the reflection sound of this sound source in dBFS.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings",
		meta = (ClampMin = "-120.0", ClampMax = "48.0", UIMin = "-120.0", UIMax = "48.0"))
	float ReflectionGainDb;
	
	// Volumetric radius of this sound source in meters.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings",
		meta = (ClampMin = "0.0", ClampMax = "100000.0", UIMin = "0.0", UIMax = "100000.0"))
	float VolumetricSize;

	// Whether Pico Doppler Simulation is enabled for this sound source, which affects both direct and reflection path of it.
	//   - If you disabled this option before run or build, you cannot turn it on during runtime, since doppler effect unit is not initialized to save memory.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options")
	bool EnableDoppler;

	// Mode of distance attenuation of this sound source.\n
	//   - None && Fixed: Source volume doesn't decrease when source-listener distance increases.\n
	//   - Inversed Squared: Source volume decrease when source-listener distance increases, just like the real world.\n
	//   - Customized: Don't use it!!!!
	// Select 'None' (default) to use Unreal attenuation settings
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options|Attenuation")
	EPxrAudioSpatializer_SourceAttenuationMode AttenuationMode;

	// Source volume will not further increase when source-listener distance is less than this.
	//   - Only effective when source attenuation mode == Inversed Squared
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options|Attenuation",
		meta = (ClampMin = "0.0", ClampMax = "1000000.0", UIMin = "0.0", UIMax = "1000000.0"))
	float MinAttenuationDistance;

	// Source volume will not further decrease when source-listener distance is more than this.
	//   - Only effective when source attenuation mode == Inversed Squared
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options|Attenuation",
		meta = (ClampMin = "0.0", ClampMax = "1000000.0", UIMin = "0.0", UIMax = "1000000.0"))
	float MaxAttenuationDistance;

	DistanceAttenuationCallback DirectSoundDistanceAttenuationCallback;
	DistanceAttenuationCallback IndirectSoundDistanceAttenuationCallback;

	// Determine shape of the radiation polar pattern of this sound source.
	//   - Alpha = 0 gives you omnidirectional polar pattern
	//   - Alpha = 0.5 gives you cardioid polar pattern
	//   - Alpha = 1 gives you figure-8 polar pattern
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options|Directivity",
		meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float DirectivityAlpha;

	// Determine width of the radiation polar pattern of this sound source.
	//   - Larger order gives you narrower radiation pattern.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Advanced Options|Directivity",
		meta = (ClampMin = "0.0", ClampMax = "100.0", UIMin = "0.0", UIMax = "100.0"))
	float DirectivityOrder;

	UPROPERTY(EditAnywhere, Category = "SpatializationSettings|Advanced Options|Directivity")
	bool bVisualizePolarPattern;

	UPROPERTY(EditAnywhere, Category = "SpatializationSettings|Advanced Options|Directivity")
	UMaterial* PolarPatternMaterial;

	// Sets the sound source gain, applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceGain(float GainDb);

	// Sets the sound source reflection gain, applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceReflectionGain(float GainDb);

	// Sets the sound source volumetric size (radius), applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceSize(float Radius);

	// Sets the sound source attenuation distance (meters), applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceAttenuationDistance(float Min, float Max);

	// Sets on/off status of source doppler effect, applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceDoppler(bool On);

	// Sets source directivity, applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceDirectivity(float Alpha, float Order);

	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourcePolarPatternVisualization(bool OnOff);

	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourcePolarPatternMaterial(UMaterial* Material);
};

