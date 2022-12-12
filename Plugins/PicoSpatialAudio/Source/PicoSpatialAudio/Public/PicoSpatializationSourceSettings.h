#pragma once
#include "CoreMinimal.h"
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
	// Extra gain of the sound source (in dBFS).
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings",
		meta = (ClampMin = "0.0", ClampMax = "24.0", UIMin = "0.0", UIMax = "24.0"))
	float SourceGainDb;

	// Volumetric Size (Radius) of the sound source (in meters).
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings",
		meta = (ClampMin = "0.0", ClampMax = "100000.0", UIMin = "0.0", UIMax = "100000.0"))
	float VolumetricSize;

	// Volumetric Size (Radius) of the sound source (in meters).
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings")
	bool EnableDoppler;

	// Roll-off model to use for sound source distance attenuation. Select 'None' (default) to use Unreal attenuation settings
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Attenuation")
	EPxrAudioSpatializer_SourceAttenuationMode AttenuationMode;

	// Minimum attenuation distance when chosen "Inverse Squared" attenuation mode
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Attenuation",
		meta = (ClampMin = "0.0", ClampMax = "1000000.0", UIMin = "0.0", UIMax = "1000000.0"))
	float MinAttenuationDistance;

	// Maximum attenuation distance when chosen "Inverse Squared" attenuation mode
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "SpatializationSettings|Attenuation",
		meta = (ClampMin = "0.0", ClampMax = "1000000.0", UIMin = "0.0", UIMax = "1000000.0"))
	float MaxAttenuationDistance;

	DistanceAttenuationCallback DirectSoundDistanceAttenuationCallback;
	DistanceAttenuationCallback IndirectSoundDistanceAttenuationCallback;

	// Sets the sound source gain, applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceGain(float GainDb);

	// Sets the sound source volumetric size (radius), applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceSize(float Radius);

	// Sets the sound source attenuation distance (meters), applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceAttenuationDistance(float Min, float Max);

	// Sets the sound source attenuation distance (meters), applies, and updates
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|SoundSourceSpatializationSettings")
	void SetSoundSourceDoppler(bool On);
};

