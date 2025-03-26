//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

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
				
				//	Source settings
				PxrAudioSpatializer_SourceConfig Config;
				unsigned int PropertyMask = 0;
				
				FInternalSourceProperties()
				{
					const auto* DefaultSourceSettings = FPicoSpatialAudioModule::GetDefaultSourceSettings();
					Config.source_gain = DB2Mag(DefaultSourceSettings->SourceGainDb);
					Config.reflection_gain = DB2Mag(DefaultSourceSettings->ReflectionGainDb);
					Config.radius = DefaultSourceSettings->VolumetricSize;
					Config.enable_doppler = DefaultSourceSettings->EnableDoppler;
					Config.range_min = DefaultSourceSettings->MinAttenuationDistance;
					Config.range_max = DefaultSourceSettings->MaxAttenuationDistance;
					Config.directivity_alpha = DefaultSourceSettings->DirectivityAlpha;
					Config.directivity_order = DefaultSourceSettings->DirectivityOrder;
				}
			};

			bool bIsInitialized;
			FPicoSpatialAudioModule* PicoSpatialAudioModule;
			TArray<UPicoSpatializationSourceSettings*> SpatializationSettings;
			TArray<FInternalSourceProperties> InternalSourceProperties;
		};
	}
}
