//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PxrAudioSpatializerReverb.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		/**
		 * @brief FReverbPluginImpl implementation
		 */
		FReverb::FReverb()
			: PicoSpatialAudioModule(nullptr),
			  ReverbPreset(nullptr)
		{
		}

		FReverb::~FReverb()
		{
		}

		void FReverb::Initialize(const FAudioPluginInitializationParams InitializationParams)
		{
			PicoSpatialAudioModule = &FModuleManager::GetModuleChecked<FPicoSpatialAudioModule>("PicoSpatialAudio");
			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Reverb is initialized"));
		}

		void FReverb::OnInitSource(const uint32 SourceId, const FName& AudioComponentUserId,
		                           const uint32 NumChannels, UReverbPluginSourceSettingsBase* InSettings)
		{
		}

		void FReverb::OnReleaseSource(const uint32 SourceId)
		{
		}

		FSoundEffectSubmixPtr FReverb::GetEffectSubmix()
		{
			if (!SubmixEffect.IsValid())
			{
				InitSubmixEffect();
			}

			return SubmixEffect;
		}

		USoundSubmix* FReverb::GetSubmix()
		{
			const UPicoSpatialAudioSettings* Settings = GetDefault<UPicoSpatialAudioSettings>();

			USoundSubmix* ReverbSubmix = Cast<USoundSubmix>(Settings->OutputSubmix.TryLoad());

			if (!ReverbSubmix)
			{
				static const FString DefaultSubmixName = TEXT("Pico Spatial Audio Reverb Submix");
				UE_LOG(LogPicoSpatialAudio, Warning,
				       TEXT(
					       "Failed to load Pico Spatial Audio Reverb Submix from object path '%s' in PicoSpatialAudioSettings. Creating '%s' as stub."
				       ),
				       *Settings->OutputSubmix.GetAssetPathString(),
				       *DefaultSubmixName);

				ReverbSubmix = NewObject<USoundSubmix>(USoundSubmix::StaticClass(), *DefaultSubmixName);
				ReverbSubmix->bMuteWhenBackgrounded = true;
			}
#if ENGINE_MAJOR_VERSION >= 5
			ReverbSubmix->bAutoDisable = false;
#endif

			if (!SubmixEffect.IsValid())
			{
				InitSubmixEffect();
			}

			if (ReverbPreset)
			{
				bool bFoundPreset = false;
				for (USoundEffectSubmixPreset* Preset : ReverbSubmix->SubmixEffectChain)
				{
					if (UPxrAudioSpatializerReverbPluginPreset* PluginPreset = Cast<
						UPxrAudioSpatializerReverbPluginPreset>(
						Preset))
					{
						bFoundPreset = true;
						break;
					}
				}

				if (!bFoundPreset)
				{
					static const FString DefaultPresetName = TEXT("PicoSpatialAudioReverbDefault_0");
					UE_LOG(LogPicoSpatialAudio, Warning,
					       TEXT(
						       "Failed to find Pico UPxrAudioSpatializerReverbPluginPreset on default reverb submix. Creating stub '%s'."
					       ),
					       *Settings->OutputSubmix.GetAssetPathString(),
					       *DefaultPresetName);
					ReverbSubmix->SubmixEffectChain.Add(ReverbPreset);
				}
			}

			return ReverbSubmix;
		}

		void FReverb::ProcessSourceAudio(const FAudioPluginSourceInputData& InputData,
		                                 FAudioPluginSourceOutputData& OutputData)
		{
			//	Left empty since we don't process object sound source in reverb plugin
		}

		void FReverb::ProcessMixedAudio(const FSoundEffectSubmixInputData& InData,
		                                FSoundEffectSubmixOutputData& OutData)
		{
			if (PicoSpatialAudioModule == nullptr || !FContextSingleton::IsInitialized())
			{
				return;
			}

			if (OutData.NumChannels == 2)
			{
				FContextSingleton::GetInstance()->GetInterleavedBinauralBuffer(OutData.AudioBuffer->GetData(),
				                                                               OutData.AudioBuffer->Num() / 2, false);
			}
			else if (OutData.NumChannels > 2) //	Fill output to the first 2 channels
			{
				TemporaryStereoBuffer.Reset();
				TemporaryStereoBuffer.AddZeroed(2 * InData.NumFrames);

				FContextSingleton::GetInstance()->GetInterleavedBinauralBuffer(TemporaryStereoBuffer.GetData(),
				                                                               OutData.AudioBuffer->Num() / 2, false);
				float* OutputBufferPtr = OutData.AudioBuffer->GetData();
				for (int32 i = 0; i < InData.NumFrames; ++i)
				{
					const int32 SubmixFrameHead = i * OutData.NumChannels;
					const int32 StereoBufferFrameHead = i * 2;
					OutputBufferPtr[SubmixFrameHead] = TemporaryStereoBuffer[StereoBufferFrameHead];
					OutputBufferPtr[SubmixFrameHead + 1] = TemporaryStereoBuffer[StereoBufferFrameHead + 1];
				}
			}
			else if (OutData.NumChannels == 1)
			{
				UE_LOG(LogPicoSpatialAudio, Warning,
				       TEXT(
					       "Reverb is connected to 1-channel output, down-mixing binaural audio (sound quality is degraded)"
				       ));

				// FillInterleavedOutputBuffer (below) can fail if the graph does not have any sources to process, so the temp buffer must be zeroed
				TemporaryStereoBuffer.Reset();
				TemporaryStereoBuffer.AddZeroed(2 * InData.NumFrames);

				FContextSingleton::GetInstance()->GetInterleavedBinauralBuffer(TemporaryStereoBuffer.GetData(),
				                                                               OutData.AudioBuffer->Num() / 2, false);
				float* OutputBufferPtr = OutData.AudioBuffer->GetData();
				for (int32 i = 0; i < InData.NumFrames; ++i)
				{
					const int32 StereoBufferFrameHead = i * 2;
					OutputBufferPtr[i] = 0.5f * (TemporaryStereoBuffer[StereoBufferFrameHead] +
						TemporaryStereoBuffer[StereoBufferFrameHead + 1]);
				}
			}
		}

		void FReverb::InitSubmixEffect()
		{
			if (!ReverbPreset)
			{
				ReverbPreset = NewObject<UPxrAudioSpatializerReverbPluginPreset>();
				ReverbPreset->AddToRoot();
			}
			SubmixEffect = USoundEffectPreset::CreateInstance<FSoundEffectSubmixInitData, FSoundEffectSubmix>(
				FSoundEffectSubmixInitData(), *ReverbPreset);
			StaticCastSharedPtr<FPxrAudioSpatializerReverbPlugin, FSoundEffectSubmix, ESPMode::ThreadSafe>(
					SubmixEffect)->
				SetAudioReverbPluginImpl(this);
			SubmixEffect->SetEnabled(true);
		}
	}
}

/**
		 * @brief FReverbPlugin implementations
		 */
FPxrAudioSpatializerReverbPlugin::FPxrAudioSpatializerReverbPlugin()
	: Reverb(nullptr)
{
}

void FPxrAudioSpatializerReverbPlugin::Init(const FSoundEffectSubmixInitData& InData)
{
}

uint32 FPxrAudioSpatializerReverbPlugin::GetDesiredInputChannelCountOverride() const
{
	return 2;
}

void FPxrAudioSpatializerReverbPlugin::OnProcessAudio(const FSoundEffectSubmixInputData& InData,
                                                      FSoundEffectSubmixOutputData& OutData)
{
	if (Reverb)
	{
		Reverb->ProcessMixedAudio(InData, OutData);
	}
}

void FPxrAudioSpatializerReverbPlugin::OnPresetChanged()
{
}

void FPxrAudioSpatializerReverbPlugin::SetAudioReverbPluginImpl(Pxr_Audio::Spatializer::FReverb* InReverb)
{
	Reverb = InReverb;
}
