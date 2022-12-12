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
			PxrAudioSpatializer_SourceConfig SourceConfig;
			SourceConfig.source_gain = DB2Mag(SourceSetting->SourceGainDb);
			SourceConfig.enable_doppler = SourceSetting->EnableDoppler;
			Result = FContextSingleton::GetInstance()->AddSourceWithConfig(
				&SourceConfig, &InternalSourceProperty.SourceId, true);

			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Failed to create source (UE source ID: %i) (Internal source ID: %i), error code: %i"
				       ), SourceId, InternalSourceProperty.SourceId, Result);
				return;
			}

			// Set distance attenuation model.
			switch (SourceSetting->AttenuationMode)
			{
			case EPxrAudioSpatializer_SourceAttenuationMode::None:
				FContextSingleton::GetInstance()->SetSourceAttenuationMode(
					InternalSourceProperty.SourceId, PASP_SOURCE_ATTENUATION_MODE_NONE);
				break;
			case EPxrAudioSpatializer_SourceAttenuationMode::Fixed:
				FContextSingleton::GetInstance()->SetSourceAttenuationMode(
					InternalSourceProperty.SourceId, PASP_SOURCE_ATTENUATION_MODE_FIXED);
				break;
			case EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare:
				FContextSingleton::GetInstance()->SetSourceAttenuationMode(
					InternalSourceProperty.SourceId, PASP_SOURCE_ATTENUATION_MODE_INVERSE_SQUARE);
				FContextSingleton::GetInstance()->SetSourceRange(
					InternalSourceProperty.SourceId, SourceSetting->MinAttenuationDistance,
					SourceSetting->MaxAttenuationDistance);
				break;
			case EPxrAudioSpatializer_SourceAttenuationMode::Customized:
				FContextSingleton::GetInstance()->SetSourceAttenuationMode(
					InternalSourceProperty.SourceId, PASP_SOURCE_ATTENUATION_MODE_INVERSE_SQUARE,
					SourceSetting->DirectSoundDistanceAttenuationCallback,
					SourceSetting->IndirectSoundDistanceAttenuationCallback);
				break;
			default:
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT("FPicoAudioSpatialization::OnInitSource: Undefined distance attenuation method!"));
				break;
			}

			//	A Hack to ensure volumetric size setup executed across different playbacks
			InternalSourceProperty.VolumetricSize = 0.f;
			
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
			ConvertToPicoSpatialAudioCoordinates(InputData.SpatializationParams->EmitterWorldPosition,
			                                     InternalSourceProperty.Position);
			auto Result = FContextSingleton::GetInstance()->SetSourcePosition(
				InternalSourceProperty.SourceId, InternalSourceProperty.Position);
			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Failed to set source position (UE source ID: %i) (Internal source ID: %i), error code: %i"
				       ), InputData.SourceId,
				       InternalSourceProperty.SourceId, Result);
			}

			// Set sound source gain.
			if (!FMath::IsNearlyEqual(InternalSourceProperty.SourceGainDb, SourceSetting->SourceGainDb))
			{
				Result = FContextSingleton::GetInstance()->SetSourceGain(
					InternalSourceProperty.SourceId, DB2Mag(SourceSetting->SourceGainDb));
				if (Result == PASP_SUCCESS)
				{
					InternalSourceProperty.SourceGainDb = SourceSetting->SourceGainDb;
				}
				else
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT(
						       "Failed to set source gain (UE source ID: %i) (Internal source ID: %i), error code is: %d"
					       ), InputData.SourceId, InternalSourceProperty.SourceId, Result);
				}
			}

			// Set source volumetric size (radius).
			if (!FMath::IsNearlyEqual(InternalSourceProperty.VolumetricSize, SourceSetting->VolumetricSize))
			{
				Result = FContextSingleton::GetInstance()->SetSourceSize(
					InternalSourceProperty.SourceId, SourceSetting->VolumetricSize);
				if (Result == PASP_SUCCESS)
				{
					InternalSourceProperty.VolumetricSize = SourceSetting->VolumetricSize;
				}
				else
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT("Failed to set source size (UE source ID: %i) (Internal source ID: %i)"
					       ), InputData.SourceId, InternalSourceProperty.SourceId);
				}
			}

			// Set source doppler on/off.
			if (InternalSourceProperty.EnableDoppler != SourceSetting->EnableDoppler)
			{
				Result = FContextSingleton::GetInstance()->SetDopplerEffect(
					InternalSourceProperty.SourceId, SourceSetting->EnableDoppler);
				if (Result == PASP_SUCCESS)
				{
					InternalSourceProperty.EnableDoppler = SourceSetting->EnableDoppler;
				}
				else
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT(
						       "Failed to set source Doppler effect on/off (UE source ID: %i) (Internal source ID: %i), error code: %d"
					       ), InputData.SourceId, InternalSourceProperty.SourceId, Result);
				}
			}

			// Set source attenuation distances.
			if (SourceSetting->AttenuationMode == EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare &&
				!(FMath::IsNearlyEqual(InternalSourceProperty.MinAttenuationDistance,
				                       SourceSetting->MinAttenuationDistance) &&
					FMath::IsNearlyEqual(InternalSourceProperty.MaxAttenuationDistance,
					                     SourceSetting->MaxAttenuationDistance)))
			{
				Result = FContextSingleton::GetInstance()->SetSourceRange(
					InternalSourceProperty.SourceId, SourceSetting->MinAttenuationDistance,
					SourceSetting->MaxAttenuationDistance);
				if (Result == PASP_SUCCESS)
				{
					InternalSourceProperty.MinAttenuationDistance = SourceSetting->MinAttenuationDistance;
					InternalSourceProperty.MaxAttenuationDistance = SourceSetting->MaxAttenuationDistance;
				}
				else
				{
					UE_LOG(LogPicoSpatialAudio, Error,
					       TEXT(
						       "Failed to set source attenuation range (UE source ID: %i) (Internal source ID: %i), error code: %d"
					       ), InputData.SourceId, InternalSourceProperty.SourceId, Result);
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
			Result = FContextSingleton::GetInstance()->SubmitSourceBuffer(
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
