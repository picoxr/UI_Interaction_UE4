//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include <atomic>
#include "AudioPluginUtilities.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include "PicoSpatialAudioModule.h"
#include "PxrAudioSpatializerSpatialization.h"
#include "PxrAudioSpatializerReverb.h"
#include "PxrAudioSpatializerContextSingleton.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FListener : public IAudioPluginListener
		{
		public:
			FListener();
			virtual ~FListener() override;

			virtual void OnListenerInitialize(FAudioDevice* AudioDevice, UWorld* ListenerWorld) override;
			virtual void OnListenerUpdated(FAudioDevice* AudioDevice, const int32 ViewportIndex,
			                               const FTransform& ListenerTransform, const float InDeltaSeconds) override;
			virtual void OnListenerShutdown(FAudioDevice* AudioDevice) override;
			virtual void OnTick(UWorld* InWorld, const int32 ViewportIndex, const FTransform& ListenerTransform,
			                    const float InDeltaSeconds) override;

			static std::atomic<bool> bNeedSceneCommit;
		private:
			FAudioDevice* OwningAudioDevice;

			FPicoSpatialAudioModule* PicoSpatialAudioModule;
			FSpatialization* SpatializationPtr;
			FReverb* ReverbPtr;

			float PositionPicoCoordinate[3] = {0,0,0};
			float UpPicoCoordinate[3] = {0,1,0};
			float FrontPicoCoordinate[3] = {0,0,-1};
		};
	}
}
