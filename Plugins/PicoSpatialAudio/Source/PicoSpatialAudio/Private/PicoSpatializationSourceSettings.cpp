//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoSpatializationSourceSettings.h"

#if WITH_EDITOR
#include "PicoSpatializationSourceDirectivityVisualizer.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#endif

UPicoSpatializationSourceSettings::UPicoSpatializationSourceSettings()
	: SourceGainDb(0.0),
	  ReflectionGainDb(0.0),
	  VolumetricSize(0.0),
	  EnableDoppler(false),
	  AttenuationMode(EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare),
	  MinAttenuationDistance(0.2),
	  MaxAttenuationDistance(100.0),
	  DirectSoundDistanceAttenuationCallback(nullptr),
	  IndirectSoundDistanceAttenuationCallback(nullptr),
	  DirectivityAlpha(0.0),
	  DirectivityOrder(1.0),
	  bVisualizePolarPattern(false),
	  PolarPatternMaterial(nullptr)
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

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings,
	                                                      PolarPatternMaterial))
	{
		return bVisualizePolarPattern;
	}

	return ParentVal;
}

void UPicoSpatializationSourceSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != nullptr)
		                     ? PropertyChangedEvent.Property->GetFName()
		                     : NAME_None;

	if ((PropertyName == GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings, bVisualizePolarPattern)))
	{
		if (bVisualizePolarPattern)
		{
			for (TObjectIterator<UAudioComponent> Itr; Itr; ++Itr)
			{
				UAudioComponent* AudioComponent = *Itr;
				if (!AudioComponent->IsPendingKill() && DoesAudioComponentReferenceThis(AudioComponent))
				{
					AActor* CurrentActor = AudioComponent->GetOwner();
					if (CurrentActor != nullptr)
					{
						//	Use CurrentActor->GetWorld() instead of UPicoSpatializationSourceSettings::GetWorld(),
						//	in order to 100% register to the world the sound source actor is in
						auto DirectivityVisualizer =
							CurrentActor->GetWorld()->SpawnActor<APicoSpatializationSourceDirectivityVisualizer>(
								APicoSpatializationSourceDirectivityVisualizer::StaticClass());
						// Attach the visualizer to the owning object so that it can be moved with it in the editor.
						DirectivityVisualizer->AttachToActor(CurrentActor,
						                                     FAttachmentTransformRules::SnapToTargetNotIncludingScale);
						DirectivityVisualizer->SetSettings(this);
						DirectivityVisualizer->SetMaterial(PolarPatternMaterial);
						DirectivityVisualizer->DrawPattern();
					}
				}
			}
		}
		else
		{
			for (TObjectIterator<APicoSpatializationSourceDirectivityVisualizer> Itr; Itr; ++Itr)
			{
				if ((*Itr)->GetSettings() == this)
				{
					(*Itr)->Destroy();
				}
			}
		}
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings, DirectivityAlpha) || PropertyName ==
		GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings, DirectivityOrder) || PropertyName ==
		GET_MEMBER_NAME_CHECKED(UPicoSpatializationSourceSettings, PolarPatternMaterial))
	{
		for (TObjectIterator<APicoSpatializationSourceDirectivityVisualizer> Itr; Itr; ++Itr)
		{
			if ((*Itr)->GetSettings() == this)
			{
				(*Itr)->SetSettings(this);
				(*Itr)->SetMaterial(PolarPatternMaterial);
				(*Itr)->DrawPattern();
			}
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void UPicoSpatializationSourceSettings::SetSoundSourceGain(float GainDb)
{
	SourceGainDb = GainDb;
}

void UPicoSpatializationSourceSettings::SetSoundSourceReflectionGain(float GainDb)
{
	ReflectionGainDb = GainDb;
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

void UPicoSpatializationSourceSettings::SetSoundSourceDirectivity(float Alpha, float Order)
{
	DirectivityAlpha = Alpha;
	DirectivityOrder = Order;
}

void UPicoSpatializationSourceSettings::SetSoundSourcePolarPatternVisualization(bool OnOff)
{
	bVisualizePolarPattern = OnOff;
}

void UPicoSpatializationSourceSettings::SetSoundSourcePolarPatternMaterial(UMaterial* Material)
{
	PolarPatternMaterial = Material;
}
