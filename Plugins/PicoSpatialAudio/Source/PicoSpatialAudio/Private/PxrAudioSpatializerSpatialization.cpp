//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PxrAudioSpatializerSpatialization.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		FSpatialization::FSpatialization()
			: bIsInitialized(false),
			  PicoSpatialAudioModule(nullptr)
		{
		}

		FSpatialization::~FSpatialization()
		{
		}

		void FSpatialization::Initialize(const FAudioPluginInitializationParams InitializationParams)
		{
			PicoSpatialAudioModule = &FModuleManager::GetModuleChecked<FPicoSpatialAudioModule>("PicoSpatialAudio");

			// Initialize spatialization settings array for each sound source.
			SpatializationSettings.Init(nullptr, InitializationParams.NumSources);
			InternalSourceProperties.Init(FInternalSourceProperties(), InitializationParams.NumSources);

			bIsInitialized = true;

			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Spatialization is initialized"));
		}

		bool FSpatialization::IsSpatializationEffectInitialized() const
		{
			return bIsInitialized;
		}

		void FSpatialization::OnInitSource(const uint32 SourceId, const FName& AudioComponentUserId,
		                                   USpatializationPluginSourceSettingsBase* InSettings)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}

			// Create a sound source and register it with Pico Spatial Audio Context.
			auto& InternalSourceProperty = InternalSourceProperties[SourceId];
			auto*& SourceSetting = SpatializationSettings[SourceId];
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (InternalSourceProperty.SourceId != -1)
			{
				const int InternalSourceIdBackup = InternalSourceProperty.SourceId;
				Result = FContextSingleton::GetInstance()->RemoveSource(InternalSourceIdBackup);
				if (Result == PASP_SUCCESS)
				{
					InternalSourceProperty.SourceId = -1;
				}
				else
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT(
						       "Failed to remove previously created source (UE source ID: %i) (Internal source ID: %i) to make space for new source, error code: %i"
					       ), SourceId, InternalSourceIdBackup, Result);
					return;
				}
			}

			// If we weren't passed in any settings, we apply the default setting
			if (!InSettings)
			{
				SourceSetting = FPicoSpatialAudioModule::GetDefaultSourceSettings();
			}
			else
			{
				SourceSetting = static_cast<UPicoSpatializationSourceSettings*>(InSettings);
			}


			if (SourceSetting == nullptr)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "No Spatialization Settings Preset added to the sound source, even the default setting!"
				       ));
				return;
			}

			InternalSourceProperty.Config.source_gain = DB2Mag(SourceSetting->SourceGainDb);
			InternalSourceProperty.Config.reflection_gain = DB2Mag(SourceSetting->ReflectionGainDb);
			InternalSourceProperty.Config.radius = SourceSetting->VolumetricSize;
			InternalSourceProperty.Config.use_direct_path_spread = false;
			InternalSourceProperty.Config.enable_doppler = SourceSetting->EnableDoppler;
			InternalSourceProperty.Config.attenuation_mode = static_cast<PxrAudioSpatializer_SourceAttenuationMode>(
				SourceSetting->AttenuationMode);
			InternalSourceProperty.Config.range_min = SourceSetting->MinAttenuationDistance;
			InternalSourceProperty.Config.range_max = SourceSetting->MaxAttenuationDistance;
			InternalSourceProperty.Config.directivity_alpha = SourceSetting->DirectivityAlpha;
			InternalSourceProperty.Config.directivity_order = SourceSetting->DirectivityOrder;
			Result = FContextSingleton::GetInstance()->AddSourceWithConfig(
				&InternalSourceProperty.Config, &InternalSourceProperty.SourceId, true);

			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Failed to create source (UE source ID: %i) (Internal source ID: %i), error code: %i"
				       ), SourceId, InternalSourceProperty.SourceId, Result);
				return;
			}

			UE_LOG(LogPicoSpatialAudio, Display,
			       TEXT("Initialized Source (UE source ID: %i) (Internal source ID: %i)"),
			       SourceId, InternalSourceProperty.SourceId);
		}

		void FSpatialization::OnReleaseSource(const uint32 SourceId)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}

			auto& InternalSourceProperty = InternalSourceProperties[SourceId];
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			const int InternalSourceIdBackup = InternalSourceProperty.SourceId;
			if (InternalSourceProperty.SourceId != -1)
			{
				Result = FContextSingleton::GetInstance()->RemoveSource(InternalSourceIdBackup);
				if (Result == PASP_SUCCESS)
					InternalSourceProperty.SourceId = -1;
			}

			if (Result == PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Display, TEXT("Removed Source (UE source ID: %i) (Internal source ID: %i)"),
				       SourceId,
				       InternalSourceIdBackup);
			}
			else
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Failed to remove sound source (UE source ID: %i) (Internal source ID: %i), error code: %i"
				       ), SourceId,
				       InternalSourceProperty.SourceId, Result);
			}
		}

		void FSpatialization::ProcessAudio(const FAudioPluginSourceInputData& InputData,
		                                   FAudioPluginSourceOutputData& OutputData)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}

			const auto* SourceSetting = SpatializationSettings[InputData.SourceId];
			auto& InternalSourceProperty = InternalSourceProperties[InputData.SourceId];

			//	Setup source transform
			ConvertToPicoSpatialAudioCoordinates(InputData.SpatializationParams->EmitterWorldPosition,
			                                     InternalSourceProperty.Config.position);
			ConvertToPicoSpatialAudioCoordinates(
				InputData.SpatializationParams->EmitterWorldRotation.GetForwardVector() * 100.f,
				InternalSourceProperty.Config.front);
			ConvertToPicoSpatialAudioCoordinates(
				InputData.SpatializationParams->EmitterWorldRotation.GetUpVector() * 100.f,
				InternalSourceProperty.Config.up);
			InternalSourceProperty.PropertyMask |= PASP_SourceProperty_Position | PASP_SourceProperty_Orientation;

			// Set sound source gain.
			const float NewSourceGainAmplitude = DB2Mag(SourceSetting->SourceGainDb);
			if (!FMath::IsNearlyEqual(InternalSourceProperty.Config.source_gain, NewSourceGainAmplitude))
			{
				InternalSourceProperty.Config.source_gain = NewSourceGainAmplitude;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_SourceGain;
			}

			// Set sound source reflection gain.
			const float NewSourceReflectionGainAmplitude = DB2Mag(SourceSetting->ReflectionGainDb);
			if (!FMath::IsNearlyEqual(InternalSourceProperty.Config.reflection_gain, NewSourceReflectionGainAmplitude))
			{
				InternalSourceProperty.Config.reflection_gain = NewSourceReflectionGainAmplitude;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_ReflectionGain;
			}

			// Set source volumetric size (radius).
			if (!FMath::IsNearlyEqual(InternalSourceProperty.Config.radius, SourceSetting->VolumetricSize))
			{
				InternalSourceProperty.Config.radius = SourceSetting->VolumetricSize;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_VolumetricRadius;
			}

			// Set source doppler on/off.
			if (InternalSourceProperty.Config.enable_doppler != SourceSetting->EnableDoppler)
			{
				InternalSourceProperty.Config.enable_doppler = SourceSetting->EnableDoppler;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_DopplerOnOff;
			}

			// Set source attenuation distances.
			if (SourceSetting->AttenuationMode == EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare &&
				!(FMath::IsNearlyEqual(InternalSourceProperty.Config.range_min,
				                       SourceSetting->MinAttenuationDistance) &&
					FMath::IsNearlyEqual(InternalSourceProperty.Config.range_max,
					                     SourceSetting->MaxAttenuationDistance)))
			{
				InternalSourceProperty.Config.range_min = SourceSetting->MinAttenuationDistance;
				InternalSourceProperty.Config.range_max = SourceSetting->MaxAttenuationDistance;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_RangeMin | PASP_SourceProperty_RangeMax;
			}

			// Set source directivity.
			if (!(FMath::IsNearlyEqual(InternalSourceProperty.Config.directivity_alpha,
			                           SourceSetting->DirectivityAlpha) &&
				FMath::IsNearlyEqual(InternalSourceProperty.Config.directivity_order,
				                     SourceSetting->DirectivityOrder)))
			{
				InternalSourceProperty.Config.directivity_alpha = SourceSetting->DirectivityAlpha;
				InternalSourceProperty.Config.directivity_order = SourceSetting->DirectivityOrder;
				InternalSourceProperty.PropertyMask |= PASP_SourceProperty_Directivity;
			}

			if (InternalSourceProperty.PropertyMask != PASP_SourceProperty_None)
			{
				auto Result = FContextSingleton::GetInstance()->SetSourceConfig(
					InternalSourceProperty.SourceId, &InternalSourceProperty.Config,
					InternalSourceProperty.PropertyMask);
				InternalSourceProperty.PropertyMask = PASP_SourceProperty_None;
				if (Result != PASP_SUCCESS)
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT(
						       "Failed to update source config (UE source ID: %i) (Internal source ID: %i), error code: %i"
					       ), InputData.SourceId,
					       InternalSourceProperty.SourceId,
					       Result);
				}
			}

			//	Force input data to mono, in-places
			if (InputData.NumChannels > 1)
			{
				float* InputBuffer = InputData.AudioBuffer->GetData();
				size_t BufferWriteIdx = 0;
				for (size_t Frame = 0; Frame < InputData.AudioBuffer->Num(); Frame += InputData.NumChannels)
				{
					InputBuffer[BufferWriteIdx] = InputBuffer[Frame];
					for (size_t Channel = 1; Channel < InputData.NumChannels; ++Channel)
					{
						InputBuffer[BufferWriteIdx] += InputBuffer[Frame + Channel];
					}
					InputBuffer[BufferWriteIdx++] /= static_cast<float>(InputData.NumChannels);
				}
			}

			// Add source buffer to process.
			auto Result = FContextSingleton::GetInstance()->SubmitSourceBuffer(
				InternalSourceProperty.SourceId, InputData.AudioBuffer->GetData(),
				InputData.AudioBuffer->Num() / InputData.NumChannels);
			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Failed to submit source buffer (UE source ID: %i) (Internal source ID: %i), error code: %i"
				       ), InputData.SourceId,
				       InternalSourceProperty.SourceId,
				       Result);
			}
		}
	}
}
