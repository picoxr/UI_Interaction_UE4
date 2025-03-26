//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PxrAudioSpatializerListener.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		std::atomic<bool> FListener::bNeedSceneCommit(false);
		
		FListener::FListener()
			: OwningAudioDevice(nullptr),
			  PicoSpatialAudioModule(nullptr),
			  SpatializationPtr(nullptr),
			  ReverbPtr(nullptr)
		{
			bNeedSceneCommit = true;
		}

		FListener::~FListener()
		{
		}

		void FListener::OnListenerInitialize(FAudioDevice* AudioDevice, UWorld* ListenerWorld)
		{
			if (!PicoSpatialAudioModule)
			{
				PicoSpatialAudioModule = &FModuleManager::GetModuleChecked<FPicoSpatialAudioModule>("PicoSpatialAudio");
			}

			ReverbPtr = static_cast<FReverb*>(AudioDevice->ReverbPluginInterface.Get());
			SpatializationPtr = static_cast<FSpatialization*>(AudioDevice->GetSpatializationPluginInterface().Get());

			// Make sure that both spatialization *AND* reverb plugins are enabled, since we use spatialization to take source input, and reverb to output mixed result
			if (ReverbPtr == nullptr || SpatializationPtr == nullptr)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT(
					       "Requires both Spatialization and Reverb plugins. Please select them in the Project Settings."
				       ));
				return;
			}

			// Initialize Pico Audio Context.
			const size_t FramesPerBuffer = static_cast<size_t>(AudioDevice->GetBufferLength());
			const int SampleRate = static_cast<int>(AudioDevice->GetSampleRate());

			PxrAudioSpatializer_RenderingMode RenderingModeInternal = ConvertToInternalRenderingMode(
				GetDefault<UPicoSpatialAudioSettings>()->RenderingMode);
			auto Result = FContextSingleton::Init(RenderingModeInternal, FramesPerBuffer, SampleRate);

			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT("Failed to initialize contetx, error code: %d"), Result);
				return;
			}
			else
			{
				UE_LOG(LogPicoSpatialAudio, Display,
				       TEXT("Context is initialized, Quality = %s"),
				       *(UEnum::GetDisplayValueAsText(GetDefault<UPicoSpatialAudioSettings>()->RenderingMode).ToString()
				       ));
				check(AudioDevice);
				OwningAudioDevice = AudioDevice;
			}

			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Listener is initialized"));
			int Major, Minor, Patch;
			FContextSingleton::GetInstance()->GetVersion(&Major, &Minor, &Patch);
			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Engine version is: %d.%d.%d"), Major, Minor,
			       Patch);
		}

		DECLARE_CYCLE_STAT(TEXT("FListener::OnListenerUpdated"), STAT_FListener_OnListenerUpdated, STATGROUP_PicoSpatialAudio)
		void FListener::OnListenerUpdated(FAudioDevice* AudioDevice, const int32 ViewportIndex,
		                                  const FTransform& ListenerTransform, const float InDeltaSeconds)
		{
			SCOPE_CYCLE_COUNTER(STAT_FListener_OnListenerUpdated)
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}

			ConvertToPicoSpatialAudioCoordinates(ListenerTransform.GetLocation(), PositionPicoCoordinate);
			const FQuat Rotation = ListenerTransform.GetRotation();
			ConvertToPicoSpatialAudioCoordinates(Rotation.GetUpVector(), UpPicoCoordinate);
			ConvertToPicoSpatialAudioCoordinates(Rotation.GetForwardVector(), FrontPicoCoordinate);

			const auto Result = FContextSingleton::GetInstance()->SetListenerPose(
				PositionPicoCoordinate, FrontPicoCoordinate, UpPicoCoordinate);
			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT("Failed to set listener pose, error code is: %d"), Result);
			}
		}

		void FListener::OnListenerShutdown(FAudioDevice* AudioDevice)
		{
			if (!FContextSingleton::IsInitialized())
			{
				UE_LOG(LogPicoSpatialAudio, Error, TEXT("Context is not initialized"));
				return;
			}

			const auto Result = FContextSingleton::Destroy();

			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT("Failed to destroy contxt, error code is: %d"), Result);
				return;
			}
			UE_LOG(LogPicoSpatialAudio, Display,
			       TEXT("Context is destroyed"));

			PicoSpatialAudioModule->UnregisterAudioDevice(OwningAudioDevice);
			OwningAudioDevice = nullptr;
			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Listener is destroyed"));
		}
		
		DECLARE_CYCLE_STAT(TEXT("FListener::OnTick"), STAT_FListener_OnTick, STATGROUP_PicoSpatialAudio)
		void FListener::OnTick(UWorld* InWorld, const int32 ViewportIndex, const FTransform& ListenerTransform,
		                       const float InDeltaSeconds)
		{
			SCOPE_CYCLE_COUNTER(STAT_FListener_OnTick)
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}
			bool bExpected = true;
			if (bNeedSceneCommit.compare_exchange_strong(bExpected, false))
			{
				const auto Result = FContextSingleton::GetInstance()->CommitScene();
				if (Result != PASP_SUCCESS)
				{
					UE_LOG(LogPicoSpatialAudio, Error,
						   TEXT("Failed to commit scene, error code: %d"), Result);
					return;
				}

				UE_LOG(LogPicoSpatialAudio, Display,
					   TEXT("Scene is committed"));
			}
			
			const auto Result = FContextSingleton::GetInstance()->UpdateScene();

			if (Result != PASP_SUCCESS)
			{
				UE_LOG(LogPicoSpatialAudio, Error,
				       TEXT("Failed to update scene, error code is: %d"), Result);
			}
		}
	}
}
