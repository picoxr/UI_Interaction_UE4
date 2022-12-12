#pragma once
#include "IAudioExtensionPlugin.h"
#include "PicoSpatializationSourceSettings.h"
#include "PicoSpatialAudioModule.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include "PxrAudioSpatializerContextSingleton.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FSpatialization : public IAudioSpatialization
		{
		public:
			FSpatialization();
			virtual ~FSpatialization() override;

			virtual void Initialize(const FAudioPluginInitializationParams InitializationParams) override;
			virtual bool IsSpatializationEffectInitialized() const override;
			virtual void OnInitSource(const uint32 SourceId, const FName& AudioComponentUserId,
			                          USpatializationPluginSourceSettingsBase* InSettings) override;
			virtual void OnReleaseSource(const uint32 SourceId) override;
			virtual void ProcessAudio(const FAudioPluginSourceInputData& InputData,
			                          FAudioPluginSourceOutputData& OutputData) override;
		private:
			struct FInternalSourceProperties
			{
				int SourceId = -1;
				float Position[3] = {0.f, 0.f, 0.f};

				//	Source settings
				float SourceGainDb;
				float VolumetricSize;
				bool EnableDoppler;
				float MinAttenuationDistance;
				float MaxAttenuationDistance;
				FInternalSourceProperties()
				{
					const auto* DefaultSourceSettings = FPicoSpatialAudioModule::GetDefaultSourceSettings();
					SourceGainDb = DefaultSourceSettings->SourceGainDb;
					VolumetricSize = DefaultSourceSettings->VolumetricSize;
					EnableDoppler = DefaultSourceSettings->EnableDoppler;
					MinAttenuationDistance = DefaultSourceSettings->MinAttenuationDistance;
					MaxAttenuationDistance = DefaultSourceSettings->MaxAttenuationDistance;
				}
			};

			bool bIsInitialized;
			FPicoSpatialAudioModule* PicoSpatialAudioModule;
			TArray<UPicoSpatializationSourceSettings*> SpatializationSettings;
			TArray<FInternalSourceProperties> InternalSourceProperties;
		};
	}
}
