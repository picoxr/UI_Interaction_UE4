// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "IEyeTrackerModule.h"
#include "EyeTrackerTypes.h"
#include "IEyeTracker.h"
#include "Modules/ModuleManager.h"

#include "GameFramework/WorldSettings.h"
#include "Engine/World.h"
#include "IXRTrackingSystem.h"
#include "Engine/Engine.h"
#include "PXR_HMDModule.h"
#include "PXR_HMDPrivate.h"

#if PICO_HMD_SUPPORTED_PLATFORMS

class FPICOXREyeTracker : public IEyeTracker
{
public:
	FPICOXREyeTracker()
	{
		GetWorldToMetersScaleFromSettings(GWorld,WorldToMeters);
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == TEXT("PICOXRHMD")))
			{
				PICOXRHMD = GEngine->XRSystem.Get();
			}
		}
	}

	virtual ~FPICOXREyeTracker()
	{
		if (bIsTrackerStarted)
		{
			PxrEyeTrackingStopInfo info;
			info.apiVersion = PXR_FACE_TRACKING_API_VERSION;
			ensureMsgf(PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StopEyeTracking1(&info)), TEXT("Can not stop eye tracking."));
		}
	}

private:
	// IEyeTracker
	virtual void SetEyeTrackedPlayer(APlayerController*) override
	{
		unimplemented();
	}

	virtual bool GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const override
	{
#if PLATFORM_ANDROID
		return ReactOnEyeTrackerState([this, &OutGazeData](const PxrEyeTrackingData1& pxrEyeData, const FTransform& TrackingToWorld) {
			OutGazeData.FixationPoint = FVector::ZeroVector;
			OutGazeData.ConfidenceValue = 1;
			OutGazeData.GazeDirection = TrackingToWorld.TransformVector(ToFQuat(pxrEyeData.eyeDatas[PxrPerEyeUsage::combined].pose.orientation).GetForwardVector());
			OutGazeData.GazeOrigin = TrackingToWorld.TransformPosition(ToFVector(pxrEyeData.eyeDatas[PxrPerEyeUsage::combined].pose.position) * WorldToMeters);
		});
#endif // PLATFORM_ANDROID
        return false;
	}

	virtual bool GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const override
	{
		return false;
	}

	virtual EEyeTrackerStatus GetEyeTrackerStatus() const override
	{
#if PLATFORM_ANDROID
		bool bResult = false;
		bool supported = false;
		bool isTracking = false;
		int modesCount = 0;
		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&supported, &modesCount, nullptr));
		if (bResult && modesCount > 0)
		{
			PxrEyeTrackingState state;
			state.apiVersion = PXR_EYE_TRACKING_API_VERSION;
			bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingState(&isTracking, &state));
			if (bResult)
			{
				if (supported && isTracking)
				{
					return EEyeTrackerStatus::Tracking;
				}
				else if (supported)
				{
					return EEyeTrackerStatus::NotTracking;
				}
			}
		}					
#endif // PLATFORM_ANDROID					
		return EEyeTrackerStatus::NotConnected;
	}

	virtual bool IsStereoGazeDataAvailable() const override
	{
		return false;
	}

private:
	// FPICOXREyeTracker
	template <typename ReactOnState>
	bool ReactOnEyeTrackerState(ReactOnState&& React) const
	{
		if (!bIsTrackerStarted)
		{
			PxrEyeTrackingStartInfo info;
			info.apiVersion = PXR_FACE_TRACKING_API_VERSION;
			info.mode = PxrEyeTrackingMode::PXR_ETM_BOTH;
			info.needCalibration = false;
			bIsTrackerStarted = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartEyeTracking1(&info));
		}

		if (bIsTrackerStarted)
		{
			bool bResult = false;

			PxrEyeTrackingDataGetInfo getInfo;
			getInfo.apiVersion = PXR_EYE_TRACKING_API_VERSION;
			getInfo.displayTime = 0;
			getInfo.flags = PXR_EYE_DEFAULT | PXR_EYE_POSITION | PXR_EYE_ORIENTATION;

			PxrEyeTrackingData1 data;
			FMemory::Memzero(&data, sizeof(data));
			data.apiVersion = PXR_EYE_TRACKING_API_VERSION;
			bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingData1(&getInfo, &data));
			if (bResult && IsStateValidForBothEyes(data))
			{
				FTransform TrackingToWorld = PICOXRHMD ? PICOXRHMD->GetTrackingToWorldTransform() : FTransform::Identity;
				React(data, TrackingToWorld);
				return true;
			}
		}
		return false;
	}

	static float IsStateValidForBothEyes(const PxrEyeTrackingData1& data)
	{
		return data.eyeDatas[PxrPerEyeUsage::combined].isPoseValid;
	}

	float WorldToMeters = 100.f;
	IXRTrackingSystem* PICOXRHMD = nullptr;
	mutable bool bIsTrackerStarted = false;
};
#endif // PICO_HMD_SUPPORTED_PLATFORMS

class FPICOXREyeTrackerModule : public IEyeTrackerModule
{
public:
	static inline FPICOXREyeTrackerModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FPICOXREyeTrackerModule>("PICOXREyeTracker");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PICOXREyeTracker");
	}

	virtual FString GetModuleKeyName() const override
	{
		return TEXT("PICOXREyeTracker");
	}

	virtual bool IsEyeTrackerConnected() const override
	{
#if PICO_HMD_SUPPORTED_PLATFORMS
		if (FPICOXRHMDModule::Get().IsPXRPluginAvailable() && FPICOXRHMDModule::GetPluginWrapper().bIsSessionInitialized)
		{
			bool bResult = false;
			bool supported = false;
			int modesCount = 0;
			bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&supported, &modesCount, nullptr));
			return bResult && supported;
		}
#endif // PICO_HMD_SUPPORTED_PLATFORMS
		return false;
	}

	virtual TSharedPtr<class IEyeTracker, ESPMode::ThreadSafe> CreateEyeTracker() override
	{
#if PICO_HMD_SUPPORTED_PLATFORMS
		return TSharedPtr<class IEyeTracker, ESPMode::ThreadSafe>(new FPICOXREyeTracker);
#else
		return TSharedPtr<class IEyeTracker, ESPMode::ThreadSafe>();
#endif // PICO_HMD_SUPPORTED_PLATFORMS
	}
};

IMPLEMENT_MODULE(FPICOXREyeTrackerModule, PICOXREyeTracker)
