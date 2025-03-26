//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "IAudioExtensionPlugin.h"
#include "Sound/SoundEffectSubmix.h"
#include "PicoSpatialAudioModule.h"
#include "PicoSpatialAudioSettings.h"
#include "PxrAudioSpatializerContextSingleton.h"
#include "Sound/SoundSubmix.h"
#include "PxrAudioSpatializerReverb.generated.h"

class UPxrAudioSpatializerReverbPluginPreset;
namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FReverb : public IAudioReverb
		{
		public:
			FReverb();
			virtual ~FReverb() override;
		
			virtual void Initialize(const FAudioPluginInitializationParams InitializationParams) override;
			virtual void OnInitSource(const uint32 SourceId, const FName& AudioComponentUserId, const uint32 NumChannels, UReverbPluginSourceSettingsBase* InSettings) override;
			virtual void OnReleaseSource(const uint32 SourceId) override;
			virtual FSoundEffectSubmixPtr GetEffectSubmix() override;
			virtual USoundSubmix* GetSubmix() override;
			virtual void ProcessSourceAudio(const FAudioPluginSourceInputData& InputData, FAudioPluginSourceOutputData& OutputData) override;

			void ProcessMixedAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData);

		private:
			FPicoSpatialAudioModule* PicoSpatialAudioModule;
			Audio::AlignedFloatBuffer TemporaryStereoBuffer;

			FSoundEffectSubmixPtr SubmixEffect;

			UPxrAudioSpatializerReverbPluginPreset* ReverbPreset;

			void InitSubmixEffect();
		};
	}
}

class FPxrAudioSpatializerReverbPlugin : public FSoundEffectSubmix
{
public:
	FPxrAudioSpatializerReverbPlugin();

	virtual void Init(const FSoundEffectSubmixInitData& InData) override;
	virtual uint32 GetDesiredInputChannelCountOverride() const override;
	virtual void OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData) override;
	virtual void OnPresetChanged() override;

	void SetAudioReverbPluginImpl(Pxr_Audio::Spatializer::FReverb* InReverb);

private:
	Pxr_Audio::Spatializer::FReverb* Reverb;
};

USTRUCT()
struct PICOSPATIALAUDIO_API FPxrAudioSpatializerReverbPluginSettings
{
	GENERATED_USTRUCT_BODY()

	FPxrAudioSpatializerReverbPluginSettings() = default;
};
		
UCLASS()
class PICOSPATIALAUDIO_API UPxrAudioSpatializerReverbPluginPreset : public USoundEffectSubmixPreset
{
	GENERATED_BODY()

public:
	EFFECT_PRESET_METHODS(PxrAudioSpatializerReverbPlugin);

	UFUNCTION()
	void SetSettings(const FPxrAudioSpatializerReverbPluginSettings& InSettings)
	{
		Settings = InSettings;
	}

	UPROPERTY()
	FPxrAudioSpatializerReverbPluginSettings Settings;
};
