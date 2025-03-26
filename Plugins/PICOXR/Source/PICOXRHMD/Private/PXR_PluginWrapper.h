// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include <memory.h>

#if PLATFORM_SUPPORTS_PRAGMA_PACK
#pragma pack (push,8)
#endif

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#pragma warning(push)
#pragma warning(disable:4201)		// nonstandard extension used: nameless struct/union
//#pragma warning(disable:4668)		// 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'

#define PVRP_EXPORT typedef
#include "PXR_Plugin.h"
#undef PVRP_EXPORT
#pragma warning(pop)

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#if PLATFORM_SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogPICOPluginWrapper, Log, All);

#define PICO_DECLARE_ENTRY_POINT(Func)		Pxr_##Func* Func

struct PICOPluginWrapper
{
	PICOPluginWrapper()
	{
		Reset();
	}

	void Reset()
	{
		memset(this, 0, sizeof(PICOPluginWrapper));
	}

	bool Initialized;
	bool bIsSessionInitialized;

	// PXRPlugin.h
	PICO_DECLARE_ENTRY_POINT(SetGraphicOption);
	PICO_DECLARE_ENTRY_POINT(SetPlatformOption);
	PICO_DECLARE_ENTRY_POINT(IsInitialized);
	PICO_DECLARE_ENTRY_POINT(SetInitializeData);
	PICO_DECLARE_ENTRY_POINT(Initialize);
	PICO_DECLARE_ENTRY_POINT(Shutdown);
	PICO_DECLARE_ENTRY_POINT(GetDeviceExtensionsVk);
	PICO_DECLARE_ENTRY_POINT(GetInstanceExtensionsVk);
	PICO_DECLARE_ENTRY_POINT(CreateVulkanSystem);
	PICO_DECLARE_ENTRY_POINT(GetFeatureSupported);
	PICO_DECLARE_ENTRY_POINT(CreateLayer);
	PICO_DECLARE_ENTRY_POINT(GetLayerImageCount);
	PICO_DECLARE_ENTRY_POINT(GetLayerImageExt);
	PICO_DECLARE_ENTRY_POINT(GetLayerImage);
	PICO_DECLARE_ENTRY_POINT(GetLayerNextImageIndex);
	PICO_DECLARE_ENTRY_POINT(GetLayerFoveationImage);
	PICO_DECLARE_ENTRY_POINT(DestroyLayer);
	PICO_DECLARE_ENTRY_POINT(IsRunning);
	PICO_DECLARE_ENTRY_POINT(BeginXr);
	PICO_DECLARE_ENTRY_POINT(EndXr);
	PICO_DECLARE_ENTRY_POINT(GetPredictedDisplayTime);
	PICO_DECLARE_ENTRY_POINT(GetPredictedMainSensorState);
	PICO_DECLARE_ENTRY_POINT(GetPredictedMainSensorState2);
	PICO_DECLARE_ENTRY_POINT(GetPredictedMainSensorStateWithEyePose);
	PICO_DECLARE_ENTRY_POINT(ResetSensor);
	PICO_DECLARE_ENTRY_POINT(WaitFrame);
	PICO_DECLARE_ENTRY_POINT(BeginFrame);
	PICO_DECLARE_ENTRY_POINT(SubmitLayer);
	PICO_DECLARE_ENTRY_POINT(SubmitLayer2);
	PICO_DECLARE_ENTRY_POINT(EndFrame);
	PICO_DECLARE_ENTRY_POINT(GetDeviceName);
	PICO_DECLARE_ENTRY_POINT(PollEvent);
	PICO_DECLARE_ENTRY_POINT(LogPrint);
	PICO_DECLARE_ENTRY_POINT(GetFov);
	PICO_DECLARE_ENTRY_POINT(GetFrustum);
	PICO_DECLARE_ENTRY_POINT(SetPerformanceLevels);
	PICO_DECLARE_ENTRY_POINT(GetPerformanceLevels);
	PICO_DECLARE_ENTRY_POINT(SetColorSpace);
	PICO_DECLARE_ENTRY_POINT(GetFoveationLevel);
	PICO_DECLARE_ENTRY_POINT(SetFoveationLevel);
	PICO_DECLARE_ENTRY_POINT(SetFoveationParams);
	PICO_DECLARE_ENTRY_POINT(SetTrackingMode);
	PICO_DECLARE_ENTRY_POINT(GetTrackingMode);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingData);
	PICO_DECLARE_ENTRY_POINT(GetFaceTrackingData);
	PICO_DECLARE_ENTRY_POINT(SetTrackingOrigin);
	PICO_DECLARE_ENTRY_POINT(GetTrackingOrigin);
	PICO_DECLARE_ENTRY_POINT(GetIPD);
	PICO_DECLARE_ENTRY_POINT(GetEyeOrientation);
	PICO_DECLARE_ENTRY_POINT(GetAppHasFocus);
	PICO_DECLARE_ENTRY_POINT(GetConfigInt);
	PICO_DECLARE_ENTRY_POINT(GetConfigFloat);
	PICO_DECLARE_ENTRY_POINT(SetConfigFloatArray);
	PICO_DECLARE_ENTRY_POINT(SetConfigInt);
	PICO_DECLARE_ENTRY_POINT(SetConfigString);
	PICO_DECLARE_ENTRY_POINT(SetConfigUint64);
	PICO_DECLARE_ENTRY_POINT(GetBoundaryConfigured);
	PICO_DECLARE_ENTRY_POINT(GetBoundaryEnabled);
	PICO_DECLARE_ENTRY_POINT(SetBoundaryVisible);
	PICO_DECLARE_ENTRY_POINT(SetSeeThroughBackground);
	PICO_DECLARE_ENTRY_POINT(GetBoundaryVisible);
	PICO_DECLARE_ENTRY_POINT(TestNodeIsInBoundary);
	PICO_DECLARE_ENTRY_POINT(TestPointIsInBoundary);
	PICO_DECLARE_ENTRY_POINT(GetBoundaryGeometry);
	PICO_DECLARE_ENTRY_POINT(GetBoundaryDimensions);
	PICO_DECLARE_ENTRY_POINT(EnableMultiview);
	PICO_DECLARE_ENTRY_POINT(GetExternalCameraInfo);
	PICO_DECLARE_ENTRY_POINT(GetExternalCameraPose);
	PICO_DECLARE_ENTRY_POINT(SetIsSupportMovingMrc);
	PICO_DECLARE_ENTRY_POINT(SetSensorLostCustomMode);
	PICO_DECLARE_ENTRY_POINT(SetSensorLostCMST);
	PICO_DECLARE_ENTRY_POINT(GetDisplayRefreshRatesAvailable);
	PICO_DECLARE_ENTRY_POINT(SetDisplayRefreshRate);
	PICO_DECLARE_ENTRY_POINT(GetDisplayRefreshRate);
	PICO_DECLARE_ENTRY_POINT(SetExtraLatencyMode);
	PICO_DECLARE_ENTRY_POINT(getPsensorState);
	PICO_DECLARE_ENTRY_POINT(GetControllerCapabilities);					
	PICO_DECLARE_ENTRY_POINT(GetControllerConnectStatus);				
	PICO_DECLARE_ENTRY_POINT(GetControllerTrackingState);			
	PICO_DECLARE_ENTRY_POINT(GetControllerInputState);		
	PICO_DECLARE_ENTRY_POINT(SetControllerVibration);
	PICO_DECLARE_ENTRY_POINT(SetControllerVibrationEvent);				
	PICO_DECLARE_ENTRY_POINT(SetControllerEnableKey);				
	PICO_DECLARE_ENTRY_POINT(SetControllerMainInputHandle);				
	PICO_DECLARE_ENTRY_POINT(GetControllerMainInputHandle);						
	PICO_DECLARE_ENTRY_POINT(StopControllerVCMotor);
	PICO_DECLARE_ENTRY_POINT(StartControllerVCMotor);
	PICO_DECLARE_ENTRY_POINT(SetControllerAmp);
	PICO_DECLARE_ENTRY_POINT(SetControllerDelay);
	PICO_DECLARE_ENTRY_POINT(GetVibrateDelayTime);
	PICO_DECLARE_ENTRY_POINT(StartVibrateBySharemF);
	PICO_DECLARE_ENTRY_POINT(StartVibrateBySharemU);
	PICO_DECLARE_ENTRY_POINT(StartVibrateByCache);
	PICO_DECLARE_ENTRY_POINT(ClearVibrateByCache);
	PICO_DECLARE_ENTRY_POINT(StartVibrateByPHF);
	PICO_DECLARE_ENTRY_POINT(PauseVibrate);
	PICO_DECLARE_ENTRY_POINT(ResumeVibrate);
	PICO_DECLARE_ENTRY_POINT(UpdateVibrateParams);	
	PICO_DECLARE_ENTRY_POINT(CreateHapticStream);
	PICO_DECLARE_ENTRY_POINT(WriteHapticStream);
	PICO_DECLARE_ENTRY_POINT(SetPHFHapticSpeed);
	PICO_DECLARE_ENTRY_POINT(GetPHFHapticSpeed);
	PICO_DECLARE_ENTRY_POINT(GetCurrentFrameSequence);
	PICO_DECLARE_ENTRY_POINT(StartPHFHaptic);
	PICO_DECLARE_ENTRY_POINT(StopPHFHaptic);
	PICO_DECLARE_ENTRY_POINT(RemovePHFHaptic);
	PICO_DECLARE_ENTRY_POINT(SetAppHandTrackingEnabled);				
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerSettingState);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerActiveInputType);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerJointLocations);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerAimState);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerAimStateWithPTFG);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerHandScale);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerJointLocationsWithPTFG);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerAimStateWithPT);
	PICO_DECLARE_ENTRY_POINT(GetHandTrackerJointLocationsWithPT);
	PICO_DECLARE_ENTRY_POINT(LogSdkApi);

	//----------------G3 device-------
	PICO_DECLARE_ENTRY_POINT(ResetController);
	PICO_DECLARE_ENTRY_POINT(SetArmModelParameters);
	PICO_DECLARE_ENTRY_POINT(GetControllerHandness);
	//----------------G3 device-------
	//----------------Body Tracking-------
	PICO_DECLARE_ENTRY_POINT(SetBodyTrackingStaticCalibState);
	PICO_DECLARE_ENTRY_POINT(SetBodyTrackingMode);
	PICO_DECLARE_ENTRY_POINT(GetBodyTrackingPose);
	PICO_DECLARE_ENTRY_POINT(GetBodyTrackingImuData);
	PICO_DECLARE_ENTRY_POINT(GetFitnessBandConnectState);
	PICO_DECLARE_ENTRY_POINT(GetFitnessBandBattery);
	PICO_DECLARE_ENTRY_POINT(GetFitnessBandCalibState);
	PICO_DECLARE_ENTRY_POINT(SetBodyTrackingAlgParam);
	//----------------Body Tracking-------
	
	//----------------Eye Tracking-------
	PICO_DECLARE_ENTRY_POINT(WantEyeTrackingService);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingSupported);
	PICO_DECLARE_ENTRY_POINT(StartEyeTracking1);
	PICO_DECLARE_ENTRY_POINT(StopEyeTracking1);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingState);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingData1);
	PICO_DECLARE_ENTRY_POINT(GetEyeOpenness);
	PICO_DECLARE_ENTRY_POINT(GetEyePupilInfo);
	PICO_DECLARE_ENTRY_POINT(GetPerEyePose);
	PICO_DECLARE_ENTRY_POINT(GetEyeBlink);
	//----------------Eye Tracking-------

	//----------------Face Tracking-------
	PICO_DECLARE_ENTRY_POINT(WantFaceTrackingService);
	PICO_DECLARE_ENTRY_POINT(GetFaceTrackingSupported);
	PICO_DECLARE_ENTRY_POINT(StartFaceTracking);
	PICO_DECLARE_ENTRY_POINT(StopFaceTracking);
	PICO_DECLARE_ENTRY_POINT(GetFaceTrackingState);
	PICO_DECLARE_ENTRY_POINT(GetFaceTrackingData1);
	//----------------Face Tracking-------

	//----------------New Body Tracking-------
	PICO_DECLARE_ENTRY_POINT(WantBodyTrackingService);
	PICO_DECLARE_ENTRY_POINT(GetBodyTrackingSupported);
	PICO_DECLARE_ENTRY_POINT(StartBodyTracking);
	PICO_DECLARE_ENTRY_POINT(StopBodyTracking);
	PICO_DECLARE_ENTRY_POINT(GetBodyTrackingState);
	PICO_DECLARE_ENTRY_POINT(GetBodyTrackingData);
	PICO_DECLARE_ENTRY_POINT(StartBodyTrackingCalibApp);
	//----------------New Body Tracking-------

	//----------------Standalone Tracker------
	PICO_DECLARE_ENTRY_POINT(GetMotionTrackerConnectState);
	PICO_DECLARE_ENTRY_POINT(GetMotionTrackerType);
	PICO_DECLARE_ENTRY_POINT(GetMotionTrackerMode);
	PICO_DECLARE_ENTRY_POINT(GetMotionTrackerLocations);
	PICO_DECLARE_ENTRY_POINT(GetMotionTrackerLocationsWithConfidence);
	PICO_DECLARE_ENTRY_POINT(CheckMotionTrackerModeAndNumber);
	//----------------Standalone Tracker------

	//----------------ExtDevTracker----------------
	PICO_DECLARE_ENTRY_POINT(GetExtDevTrackerConnectState);
	PICO_DECLARE_ENTRY_POINT(SetExtDevTrackerMotorVibrate);
	PICO_DECLARE_ENTRY_POINT(SetExtDevTrackerPassDataState);
	PICO_DECLARE_ENTRY_POINT(SetExtDevTrackerByPassData);
	PICO_DECLARE_ENTRY_POINT(GetExtDevTrackerByPassData);
	PICO_DECLARE_ENTRY_POINT(GetExtDevTrackerBattery);
	PICO_DECLARE_ENTRY_POINT(GetExtDevTrackerKeyData);
	//----------------ExtDevTracker----------------
	
	//----------------MR-------
	PICO_DECLARE_ENTRY_POINT(CreateAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(DestroyAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(GetAnchorPose);
	PICO_DECLARE_ENTRY_POINT(GetAnchorEntityUuid);
	PICO_DECLARE_ENTRY_POINT(GetAnchorComponentFlags);
	PICO_DECLARE_ENTRY_POINT(GetAnchorSceneLabel);
	PICO_DECLARE_ENTRY_POINT(GetAnchorPlaneBoundaryInfo);
	PICO_DECLARE_ENTRY_POINT(GetAnchorPlanePolygonInfo);
	PICO_DECLARE_ENTRY_POINT(GetAnchorBoxInfo);
	PICO_DECLARE_ENTRY_POINT(PersistAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(UnpersistAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(ClearPersistedAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(LoadAnchorEntity);
	PICO_DECLARE_ENTRY_POINT(GetAnchorEntityLoadResults);
	PICO_DECLARE_ENTRY_POINT(StartSpatialSceneCapture);
	//----------------MR-------
	//----------------MR 3.0-------
	/*
	 * future ext
	*/
	PICO_DECLARE_ENTRY_POINT(PollFutureEXT);
	/*
	 * mr sdk 3.0
	 */
	PICO_DECLARE_ENTRY_POINT(CreateSenseDataProvider);
	PICO_DECLARE_ENTRY_POINT(StartSenseDataProviderAsync);
	PICO_DECLARE_ENTRY_POINT(StartSenseDataProviderComplete);
	PICO_DECLARE_ENTRY_POINT(GetSenseDataProviderState);
	PICO_DECLARE_ENTRY_POINT(QuerySenseDataComplete);
	PICO_DECLARE_ENTRY_POINT(DestroySenseDataQueryResult);
	PICO_DECLARE_ENTRY_POINT(StopSenseDataProvider);
	PICO_DECLARE_ENTRY_POINT(DestroySenseDataProvider);
	PICO_DECLARE_ENTRY_POINT(QuerySenseDataAsync);
	PICO_DECLARE_ENTRY_POINT(GetQueriedSenseData);
	PICO_DECLARE_ENTRY_POINT(GetSpatialEntityUuid);
	PICO_DECLARE_ENTRY_POINT(EnumerateSpatialEntityComponentTypes);
	PICO_DECLARE_ENTRY_POINT(GetSpatialEntityComponentInfo);
	
	PICO_DECLARE_ENTRY_POINT(RetrieveSpatialEntityAnchor);
	PICO_DECLARE_ENTRY_POINT(DestroyAnchor);
	PICO_DECLARE_ENTRY_POINT(GetAnchorUuid);
	PICO_DECLARE_ENTRY_POINT(LocateAnchor);
	
	PICO_DECLARE_ENTRY_POINT(CreateSpatialAnchorAsync);
	PICO_DECLARE_ENTRY_POINT(CreateSpatialAnchorComplete);
	PICO_DECLARE_ENTRY_POINT(PersistSpatialAnchorAsync);
	PICO_DECLARE_ENTRY_POINT(PersistSpatialAnchorComplete);
	PICO_DECLARE_ENTRY_POINT(UnpersistSpatialAnchorAsync);
	PICO_DECLARE_ENTRY_POINT(UnpersistSpatialAnchorComplete);
	
	/**
	*  mr sdk 3.0 scene capture
	*/
	PICO_DECLARE_ENTRY_POINT(StartSceneCaptureAsync);
	PICO_DECLARE_ENTRY_POINT(StartSceneCaptureComplete);
	 /*
	* mr sdk 3.0 cloud anchor
	*/
	PICO_DECLARE_ENTRY_POINT(ShareSpatialAnchorAsync);
	PICO_DECLARE_ENTRY_POINT(ShareSpatialAnchorComplete);
	PICO_DECLARE_ENTRY_POINT(DownloadSharedSpatialAnchorAsync);
	PICO_DECLARE_ENTRY_POINT(DownloadSharedSpatialAnchorComplete);
	//----------------MR 3.0-------

	//----------------ETFR-------
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingFoveationRenderingSupported);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingFoveationRenderingState);
	PICO_DECLARE_ENTRY_POINT(SetEyeTrackingFoveationRenderingState);
	PICO_DECLARE_ENTRY_POINT(GetEyeTrackingFoveationRenderingCenter);
	//----------------ETFR-------
};

#undef PICO_DECLARE_ENTRY_POINT

bool InitializePICOPluginWrapper(PICOPluginWrapper* wrapper);
void DestroyPICOPluginWrapper(PICOPluginWrapper* wrapper);
