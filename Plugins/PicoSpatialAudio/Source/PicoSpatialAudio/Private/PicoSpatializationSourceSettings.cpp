#include "PicoSpatializationSourceSettings.h"

#if WITH_EDITOR
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#endif

UPicoSpatializationSourceSettings::UPicoSpatializationSourceSettings()
	: SourceGainDb(0.0),
	  VolumetricSize(0.0),
	  AttenuationMode(EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare),
	  MinAttenuationDistance(0.2),
	  MaxAttenuationDistance(100.0),
	  DirectSoundDistanceAttenuationCallback(nullptr),
	  IndirectSoundDistanceAttenuationCallback(nullptr)
{
}

#if WITH_EDITOR
bool UPicoSpatializationSourceSettings::DoesAudioComponentReferenceThis(UAudioComponent* InAudioComponent)
{
	const FSoundAttenuationSettings* ComponentSettings = InAudioComponent->GetAttenuationSettingsToApply();
	if (ComponentSettings != nullptr)
	{
		return ComponentSettings->PluginSettings.SpatializationPluginSettingsArray.Contains(this);
	}
	else
	{
		return false;
	}
}

bool UPicoSpatializationSourceSettings::CanEditChange(const FProperty* InProperty) const
{
	const bool ParentVal = Super::CanEditChange(InProperty);

	//	Disable min and max attenuation distance setting when attenuation mode is not inverse square
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings,
	                                                      MinAttenuationDistance))
	{
		return ParentVal && AttenuationMode == EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings,
	                                                      MaxAttenuationDistance))
	{
		return ParentVal && AttenuationMode == EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare;
	}

	return ParentVal;
}

void UPicoSpatializationSourceSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void UPicoSpatializationSourceSettings::SetSoundSourceGain(float GainDb)
{
	SourceGainDb = GainDb;
}

void UPicoSpatializationSourceSettings::SetSoundSourceSize(float Radius)
{
	VolumetricSize = Radius;
}

void UPicoSpatializationSourceSettings::SetSoundSourceAttenuationDistance(float Min, float Max)
{
	MinAttenuationDistance = Min;
	MaxAttenuationDistance = Max;
}

void UPicoSpatializationSourceSettings::SetSoundSourceDoppler(bool On)
{
	EnableDoppler = On;
}
