//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoSpatialAudioSceneMaterialSettings.h"

UPicoSpatialAudioSceneMaterialSettings::UPicoSpatialAudioSceneMaterialSettings()
{
}

#if WITH_EDITOR
void UPicoSpatialAudioSceneMaterialSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, MaterialPreset))
	{
		const auto MaterialInternal = static_cast<PxrAudioSpatializer_AcousticsMaterial>(MaterialPreset);
		float TempAbsorptions[4] = {0};
		PxrAudioSpatializer_GetAbsorptionFactor(MaterialInternal, TempAbsorptions);
		AbsorptionBand0 = TempAbsorptions[0];
		AbsorptionBand1 = TempAbsorptions[1];
		AbsorptionBand2 = TempAbsorptions[2];
		AbsorptionBand3 = TempAbsorptions[3];
		PxrAudioSpatializer_GetScatteringFactor(MaterialInternal, &Scattering);
		PxrAudioSpatializer_GetTransmissionFactor(MaterialInternal, &Transmission);
	}
	else
	{
		const auto MaterialInternal = static_cast<PxrAudioSpatializer_AcousticsMaterial>(MaterialPreset);
		float TempAbsorptions[4] = {0};
		float TempScattering;
		float TempTransmission;
		PxrAudioSpatializer_GetAbsorptionFactor(MaterialInternal, TempAbsorptions);
		PxrAudioSpatializer_GetScatteringFactor(MaterialInternal, &TempScattering);
		PxrAudioSpatializer_GetTransmissionFactor(MaterialInternal, &TempTransmission);
		
		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, AbsorptionBand0) &&
			!FMath::IsNearlyEqual(AbsorptionBand0, TempAbsorptions[0]))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}

		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, AbsorptionBand1) &&
			!FMath::IsNearlyEqual(AbsorptionBand1, TempAbsorptions[1]))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}

		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, AbsorptionBand2) &&
			!FMath::IsNearlyEqual(AbsorptionBand2, TempAbsorptions[2]))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}

		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, AbsorptionBand3) &&
			!FMath::IsNearlyEqual(AbsorptionBand3, TempAbsorptions[3]))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}

		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, Scattering) &&
			!FMath::IsNearlyEqual(Scattering, TempScattering))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}
		
		if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UPicoSpatialAudioSceneMaterialSettings, Transmission) &&
			!FMath::IsNearlyEqual(Transmission, TempTransmission))
		{
			MaterialPreset = EPxrAudioSpatializer_SceneMaterialPreset::Custom;
		}
	}
}
#endif
