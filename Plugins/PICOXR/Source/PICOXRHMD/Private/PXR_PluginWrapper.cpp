// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_PluginWrapper.h"
#include "PXR_HMDModule.h"

#if PLATFORM_ANDROID
#include <dlfcn.h>
#endif

DEFINE_LOG_CATEGORY(LogPICOPluginWrapper);

static void* LoadEntryPoint(void* handle, const char* EntryPointName);

bool InitializePICOPluginWrapper(PICOPluginWrapper* wrapper)
{
	if (wrapper->Initialized)
	{
		UE_LOG(LogPICOPluginWrapper, Warning, TEXT("wrapper already initialized"));
		return true;
	}

#if PICO_HMD_SUPPORTED_PLATFORMS
	void* LibraryHandle = nullptr;

#if PLATFORM_ANDROID
	const bool VersionValid = FAndroidMisc::GetAndroidBuildVersion() > 23;
#else
	const bool VersionValid = true;
#endif

	if (VersionValid)
	{
		LibraryHandle = FPICOXRHMDModule::GetPVRPluginHandle();
		if (LibraryHandle == nullptr)
		{
			UE_LOG(LogPICOPluginWrapper, Warning, TEXT("GetPVRPluginHandle() returned NULL"));
			return false;
		}
	}
	else
	{
		return false;
	}
#else
	return false;
#endif

	struct PICOEntryPoint
	{
		const char* EntryPointName;
		void** EntryPointPtr;
	};

#define PICO_BIND_ENTRY_POINT(Func)	{ "Pxr_"#Func, (void**)&wrapper->Func }

	PICOEntryPoint entryPointArray[] =
	{
		// PXRPlugin.h
		PICO_BIND_ENTRY_POINT(SetGraphicOption),
		PICO_BIND_ENTRY_POINT(SetPlatformOption),
		PICO_BIND_ENTRY_POINT(IsInitialized),
		PICO_BIND_ENTRY_POINT(SetInitializeData),
		PICO_BIND_ENTRY_POINT(Initialize),
		PICO_BIND_ENTRY_POINT(Shutdown),
		PICO_BIND_ENTRY_POINT(GetDeviceExtensionsVk),
		PICO_BIND_ENTRY_POINT(GetInstanceExtensionsVk),
		PICO_BIND_ENTRY_POINT(CreateVulkanSystem),
		PICO_BIND_ENTRY_POINT(GetFeatureSupported),
		PICO_BIND_ENTRY_POINT(CreateLayer),
		PICO_BIND_ENTRY_POINT(GetLayerImageCount),
		PICO_BIND_ENTRY_POINT(GetLayerImageExt),
		PICO_BIND_ENTRY_POINT(GetLayerImage),
		PICO_BIND_ENTRY_POINT(GetLayerNextImageIndex),
		PICO_BIND_ENTRY_POINT(GetLayerFoveationImage),
		PICO_BIND_ENTRY_POINT(DestroyLayer),
		PICO_BIND_ENTRY_POINT(IsRunning),
		PICO_BIND_ENTRY_POINT(BeginXr),
		PICO_BIND_ENTRY_POINT(EndXr),
		PICO_BIND_ENTRY_POINT(GetPredictedDisplayTime),
		PICO_BIND_ENTRY_POINT(GetPredictedMainSensorState),
		PICO_BIND_ENTRY_POINT(GetPredictedMainSensorState2),
		PICO_BIND_ENTRY_POINT(GetPredictedMainSensorStateWithEyePose),
		PICO_BIND_ENTRY_POINT(ResetSensor),
		PICO_BIND_ENTRY_POINT(WaitFrame),
		PICO_BIND_ENTRY_POINT(BeginFrame),
		PICO_BIND_ENTRY_POINT(SubmitLayer),
		PICO_BIND_ENTRY_POINT(SubmitLayer2),
		PICO_BIND_ENTRY_POINT(EndFrame),
		PICO_BIND_ENTRY_POINT(GetDeviceName),
		PICO_BIND_ENTRY_POINT(PollEvent),
		PICO_BIND_ENTRY_POINT(LogPrint),
		PICO_BIND_ENTRY_POINT(GetFov),
		PICO_BIND_ENTRY_POINT(GetFrustum),
		PICO_BIND_ENTRY_POINT(SetPerformanceLevels),
		PICO_BIND_ENTRY_POINT(GetPerformanceLevels),
		PICO_BIND_ENTRY_POINT(SetColorSpace),
		PICO_BIND_ENTRY_POINT(GetFoveationLevel),
		PICO_BIND_ENTRY_POINT(SetFoveationLevel),
		PICO_BIND_ENTRY_POINT(SetFoveationParams),
		PICO_BIND_ENTRY_POINT(SetTrackingMode),
		PICO_BIND_ENTRY_POINT(GetTrackingMode),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingData),
		PICO_BIND_ENTRY_POINT(GetFaceTrackingData),
		PICO_BIND_ENTRY_POINT(SetTrackingOrigin),
		PICO_BIND_ENTRY_POINT(GetTrackingOrigin),
		PICO_BIND_ENTRY_POINT(GetIPD),
		PICO_BIND_ENTRY_POINT(GetEyeOrientation),
		PICO_BIND_ENTRY_POINT(GetAppHasFocus),
		PICO_BIND_ENTRY_POINT(GetConfigInt),
		PICO_BIND_ENTRY_POINT(GetConfigFloat),
		PICO_BIND_ENTRY_POINT(SetConfigFloatArray),
		PICO_BIND_ENTRY_POINT(SetConfigInt),
		PICO_BIND_ENTRY_POINT(SetConfigString),
		PICO_BIND_ENTRY_POINT(SetConfigUint64),
		PICO_BIND_ENTRY_POINT(GetBoundaryConfigured),
		PICO_BIND_ENTRY_POINT(GetBoundaryEnabled),
		PICO_BIND_ENTRY_POINT(SetBoundaryVisible),
		PICO_BIND_ENTRY_POINT(SetSeeThroughBackground),
		PICO_BIND_ENTRY_POINT(GetBoundaryVisible),
		PICO_BIND_ENTRY_POINT(TestNodeIsInBoundary),
		PICO_BIND_ENTRY_POINT(TestPointIsInBoundary),
		PICO_BIND_ENTRY_POINT(GetBoundaryGeometry),
		PICO_BIND_ENTRY_POINT(GetBoundaryDimensions),
		PICO_BIND_ENTRY_POINT(EnableMultiview),
		PICO_BIND_ENTRY_POINT(GetExternalCameraInfo),
		PICO_BIND_ENTRY_POINT(GetExternalCameraPose),
		PICO_BIND_ENTRY_POINT(SetIsSupportMovingMrc),
		PICO_BIND_ENTRY_POINT(SetSensorLostCustomMode),
		PICO_BIND_ENTRY_POINT(SetSensorLostCMST),
		PICO_BIND_ENTRY_POINT(GetDisplayRefreshRatesAvailable),
		PICO_BIND_ENTRY_POINT(SetDisplayRefreshRate),
		PICO_BIND_ENTRY_POINT(GetDisplayRefreshRate),
		PICO_BIND_ENTRY_POINT(SetExtraLatencyMode),
		PICO_BIND_ENTRY_POINT(getPsensorState),
		PICO_BIND_ENTRY_POINT(GetControllerCapabilities),
		PICO_BIND_ENTRY_POINT(GetControllerConnectStatus),
		PICO_BIND_ENTRY_POINT(GetControllerTrackingState),
		PICO_BIND_ENTRY_POINT(GetControllerInputState),
		PICO_BIND_ENTRY_POINT(SetControllerVibration),
		PICO_BIND_ENTRY_POINT(SetControllerVibrationEvent),
		PICO_BIND_ENTRY_POINT(SetControllerEnableKey),
		PICO_BIND_ENTRY_POINT(SetControllerMainInputHandle),
		PICO_BIND_ENTRY_POINT(GetControllerMainInputHandle),
		PICO_BIND_ENTRY_POINT(StopControllerVCMotor),
		PICO_BIND_ENTRY_POINT(StartControllerVCMotor),
		PICO_BIND_ENTRY_POINT(SetControllerAmp),
		PICO_BIND_ENTRY_POINT(SetControllerDelay),
		PICO_BIND_ENTRY_POINT(GetVibrateDelayTime),
		PICO_BIND_ENTRY_POINT(StartVibrateBySharemF),
		PICO_BIND_ENTRY_POINT(StartVibrateBySharemU),
		PICO_BIND_ENTRY_POINT(StartVibrateByCache),
		PICO_BIND_ENTRY_POINT(ClearVibrateByCache),
		PICO_BIND_ENTRY_POINT(StartVibrateByPHF),
		PICO_BIND_ENTRY_POINT(PauseVibrate),
		PICO_BIND_ENTRY_POINT(ResumeVibrate),
		PICO_BIND_ENTRY_POINT(UpdateVibrateParams),
		PICO_BIND_ENTRY_POINT(CreateHapticStream),
		PICO_BIND_ENTRY_POINT(WriteHapticStream),
		PICO_BIND_ENTRY_POINT(SetPHFHapticSpeed),
		PICO_BIND_ENTRY_POINT(GetPHFHapticSpeed),
		PICO_BIND_ENTRY_POINT(GetCurrentFrameSequence),
		PICO_BIND_ENTRY_POINT(StartPHFHaptic),
		PICO_BIND_ENTRY_POINT(StopPHFHaptic),
		PICO_BIND_ENTRY_POINT(RemovePHFHaptic),
		PICO_BIND_ENTRY_POINT(SetAppHandTrackingEnabled),
		PICO_BIND_ENTRY_POINT(GetHandTrackerSettingState),
		PICO_BIND_ENTRY_POINT(GetHandTrackerActiveInputType),
		PICO_BIND_ENTRY_POINT(GetHandTrackerJointLocations),
		PICO_BIND_ENTRY_POINT(GetHandTrackerAimState),
		PICO_BIND_ENTRY_POINT(GetHandTrackerAimStateWithPTFG),
		PICO_BIND_ENTRY_POINT(GetHandTrackerJointLocationsWithPTFG),
		PICO_BIND_ENTRY_POINT(GetHandTrackerAimStateWithPT),
		PICO_BIND_ENTRY_POINT(GetHandTrackerJointLocationsWithPT),
		PICO_BIND_ENTRY_POINT(GetHandTrackerHandScale),
		PICO_BIND_ENTRY_POINT(ResetController),
		PICO_BIND_ENTRY_POINT(SetArmModelParameters),
		PICO_BIND_ENTRY_POINT(LogSdkApi),

		PICO_BIND_ENTRY_POINT(GetControllerHandness),
		//----------------Body Tracking-------
		PICO_BIND_ENTRY_POINT(SetBodyTrackingStaticCalibState),
		PICO_BIND_ENTRY_POINT(SetBodyTrackingMode),
		PICO_BIND_ENTRY_POINT(GetBodyTrackingPose),
		PICO_BIND_ENTRY_POINT(GetBodyTrackingImuData),
		PICO_BIND_ENTRY_POINT(GetFitnessBandConnectState),
		PICO_BIND_ENTRY_POINT(GetFitnessBandBattery),
		PICO_BIND_ENTRY_POINT(GetFitnessBandCalibState),
		PICO_BIND_ENTRY_POINT(SetBodyTrackingAlgParam),
		//----------------Body Tracking-------
		
		//----------------Eye Tracking-------
		PICO_BIND_ENTRY_POINT(WantEyeTrackingService),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingSupported),
		PICO_BIND_ENTRY_POINT(StartEyeTracking1),
		PICO_BIND_ENTRY_POINT(StopEyeTracking1),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingState),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingData1),
		PICO_BIND_ENTRY_POINT(GetEyeOpenness),
		PICO_BIND_ENTRY_POINT(GetEyePupilInfo),
		PICO_BIND_ENTRY_POINT(GetPerEyePose),
		PICO_BIND_ENTRY_POINT(GetEyeBlink),
		//----------------Eye Tracking-------

		//----------------Face Tracking-------
		PICO_BIND_ENTRY_POINT(WantFaceTrackingService),
		PICO_BIND_ENTRY_POINT(GetFaceTrackingSupported),
		PICO_BIND_ENTRY_POINT(StartFaceTracking),
		PICO_BIND_ENTRY_POINT(StopFaceTracking),
		PICO_BIND_ENTRY_POINT(GetFaceTrackingState),
		PICO_BIND_ENTRY_POINT(GetFaceTrackingData1),
		//----------------Face Tracking-------

		//----------------New Body Tracking-------
		PICO_BIND_ENTRY_POINT(WantBodyTrackingService),
		PICO_BIND_ENTRY_POINT(GetBodyTrackingSupported),
		PICO_BIND_ENTRY_POINT(StartBodyTracking),
		PICO_BIND_ENTRY_POINT(StopBodyTracking),
		PICO_BIND_ENTRY_POINT(GetBodyTrackingState),
		PICO_BIND_ENTRY_POINT(GetBodyTrackingData),
		PICO_BIND_ENTRY_POINT(StartBodyTrackingCalibApp),
		//----------------New Body Tracking-------

		//----------------Standalone Tracker------
		PICO_BIND_ENTRY_POINT(GetMotionTrackerConnectState),
		PICO_BIND_ENTRY_POINT(GetMotionTrackerType),
		PICO_BIND_ENTRY_POINT(GetMotionTrackerMode),
		PICO_BIND_ENTRY_POINT(GetMotionTrackerLocations),
		PICO_BIND_ENTRY_POINT(GetMotionTrackerLocationsWithConfidence),
		PICO_BIND_ENTRY_POINT(CheckMotionTrackerModeAndNumber),
		//----------------Standalone Tracker------

		//----------------ExtDevTracker----------------
		PICO_BIND_ENTRY_POINT(GetExtDevTrackerConnectState),
		PICO_BIND_ENTRY_POINT(SetExtDevTrackerMotorVibrate),
		PICO_BIND_ENTRY_POINT(SetExtDevTrackerPassDataState),
		PICO_BIND_ENTRY_POINT(SetExtDevTrackerByPassData),
		PICO_BIND_ENTRY_POINT(GetExtDevTrackerByPassData),
		PICO_BIND_ENTRY_POINT(GetExtDevTrackerBattery),
		PICO_BIND_ENTRY_POINT(GetExtDevTrackerKeyData),
		//----------------ExtDevTracker----------------
		
		//----------------MR-------
		PICO_BIND_ENTRY_POINT(CreateAnchorEntity),
		PICO_BIND_ENTRY_POINT(DestroyAnchorEntity),
		PICO_BIND_ENTRY_POINT(GetAnchorPose),
		PICO_BIND_ENTRY_POINT(GetAnchorEntityUuid),
		PICO_BIND_ENTRY_POINT(GetAnchorComponentFlags),
		PICO_BIND_ENTRY_POINT(GetAnchorSceneLabel),
		PICO_BIND_ENTRY_POINT(GetAnchorPlaneBoundaryInfo),
		PICO_BIND_ENTRY_POINT(GetAnchorPlanePolygonInfo),
		PICO_BIND_ENTRY_POINT(GetAnchorBoxInfo),
		PICO_BIND_ENTRY_POINT(PersistAnchorEntity),
		PICO_BIND_ENTRY_POINT(UnpersistAnchorEntity),
		PICO_BIND_ENTRY_POINT(ClearPersistedAnchorEntity),
		PICO_BIND_ENTRY_POINT(LoadAnchorEntity),
		PICO_BIND_ENTRY_POINT(GetAnchorEntityLoadResults),
		PICO_BIND_ENTRY_POINT(StartSpatialSceneCapture),
		//----------------MR-------
		//----------------MR 3.0-------
		/*
		 * future ext
		 */
		PICO_BIND_ENTRY_POINT(PollFutureEXT),
		/*
		 * mr sdk 3.0
		 */
		PICO_BIND_ENTRY_POINT(CreateSenseDataProvider),
		PICO_BIND_ENTRY_POINT(StartSenseDataProviderAsync),
		PICO_BIND_ENTRY_POINT(StartSenseDataProviderComplete),
		PICO_BIND_ENTRY_POINT(GetSenseDataProviderState),
		PICO_BIND_ENTRY_POINT(QuerySenseDataComplete),
		PICO_BIND_ENTRY_POINT(DestroySenseDataQueryResult),
		PICO_BIND_ENTRY_POINT(StopSenseDataProvider),
		PICO_BIND_ENTRY_POINT(DestroySenseDataProvider),
		PICO_BIND_ENTRY_POINT(QuerySenseDataAsync),
		PICO_BIND_ENTRY_POINT(GetQueriedSenseData),
		PICO_BIND_ENTRY_POINT(GetSpatialEntityUuid),
		PICO_BIND_ENTRY_POINT(EnumerateSpatialEntityComponentTypes),
		PICO_BIND_ENTRY_POINT(GetSpatialEntityComponentInfo),
	
		PICO_BIND_ENTRY_POINT(RetrieveSpatialEntityAnchor),
		PICO_BIND_ENTRY_POINT(DestroyAnchor),
		PICO_BIND_ENTRY_POINT(GetAnchorUuid),
		PICO_BIND_ENTRY_POINT(LocateAnchor),
	
		PICO_BIND_ENTRY_POINT(CreateSpatialAnchorAsync),
		PICO_BIND_ENTRY_POINT(CreateSpatialAnchorComplete),
		PICO_BIND_ENTRY_POINT(PersistSpatialAnchorAsync),
		PICO_BIND_ENTRY_POINT(PersistSpatialAnchorComplete),
		PICO_BIND_ENTRY_POINT(UnpersistSpatialAnchorAsync),
		PICO_BIND_ENTRY_POINT(UnpersistSpatialAnchorComplete),
	
		/**
		*  mr sdk 3.0 scene capture
		*/
		PICO_BIND_ENTRY_POINT(StartSceneCaptureAsync),
		PICO_BIND_ENTRY_POINT(StartSceneCaptureComplete),

		 /*
		* mr sdk 3.0 cloud anchor
		*/
		PICO_BIND_ENTRY_POINT(ShareSpatialAnchorAsync),
		PICO_BIND_ENTRY_POINT(ShareSpatialAnchorComplete),
		PICO_BIND_ENTRY_POINT(DownloadSharedSpatialAnchorAsync),
		PICO_BIND_ENTRY_POINT(DownloadSharedSpatialAnchorComplete),
		
		//----------------MR 3.0-------


		//----------------ETFR-------
		PICO_BIND_ENTRY_POINT(GetEyeTrackingFoveationRenderingSupported),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingFoveationRenderingState),
		PICO_BIND_ENTRY_POINT(SetEyeTrackingFoveationRenderingState),
		PICO_BIND_ENTRY_POINT(GetEyeTrackingFoveationRenderingCenter),
		//----------------ETFR-------

	};

#undef PICO_BIND_ENTRY_POINT

#if PLATFORM_WINDOWS && WITH_EDITOR
	bool result = true;
	for (int i = 0; i < UE_ARRAY_COUNT(entryPointArray); ++i)
	{
		*(entryPointArray[i].EntryPointPtr) = LoadEntryPoint(LibraryHandle, entryPointArray[i].EntryPointName);
	}
	
	return result;
#else
	bool result = true;
	for (int i = 0; i < UE_ARRAY_COUNT(entryPointArray); ++i)
	{
		*(entryPointArray[i].EntryPointPtr) = LoadEntryPoint(LibraryHandle, entryPointArray[i].EntryPointName);

		if (*entryPointArray[i].EntryPointPtr == NULL)
		{
			UE_LOG(LogPICOPluginWrapper, Error, TEXT("PICOPlugin EntryPoint could not be loaded: %hs"), ANSI_TO_TCHAR(entryPointArray[i].EntryPointName));
			result = false;
		}
	}

	if (result)
	{
		UE_LOG(LogPICOPluginWrapper, Log, TEXT("PICOPlugin initialized successfully"));
	}
	else
	{
		DestroyPICOPluginWrapper(wrapper);
	}

	wrapper->Initialized=result;
	
	return result;
	
#endif
}

void DestroyPICOPluginWrapper(PICOPluginWrapper* wrapper)
{
	if (!wrapper->Initialized)
	{
		return;
	}
	wrapper->Reset();
	UE_LOG(LogPICOPluginWrapper, Log, TEXT("PICOPlugin destroyed successfully"));
}

static void* LoadEntryPoint(void* Handle, const char* EntryPointName)
{
	if (Handle == nullptr)
	{
		return nullptr;
	}
#if PLATFORM_WINDOWS && WITH_EDITOR
	void* ptr=reinterpret_cast<void*>(GetProcAddress((HMODULE)Handle, EntryPointName));
	return ptr;
#elif PLATFORM_ANDROID
	void* ptr = dlsym(Handle, EntryPointName);
	if (ptr == nullptr)
	{
		UE_LOG(LogPICOPluginWrapper, Error, TEXT("Unable to load entry point: %s, error %s"), ANSI_TO_TCHAR(EntryPointName), ANSI_TO_TCHAR(dlerror()));
	}
	return ptr;
#else
	UE_LOG(LogPICOPluginWrapper, Error, TEXT("LoadEntryPoint: Unsupported platform"));
	return nullptr;
#endif
}