// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Delegates/Delegate.h"
#include "PXR_HMDTypes.h"
#include "PXR_EventManager.generated.h"

//ControllerDelegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRDeviceMainChangedDelegate,int32,Handness);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRHandnessChangedDelegate, int32, Handness);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPXRDeviceConnectChangedDelegate,int32,Handness,int32,State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRInputDeviceChangedDelegate,int32,State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRBatteryStateChangedDelegate,int32,State);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRLongHomeKey);
DECLARE_MULTICAST_DELEGATE(PXRRawLongHomeKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRResume);
//HMDDelegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRIpdChanged,float,NewIpd);
//SystemDisplayRateDelegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRRefreshRateChanged, float, NewRate);
//BodyTracking Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPXRDeviceMotionTrackerBatteryDelegate,int32,Id,int32,BatteryState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPXRDeviceBodyTrackingStateError,int32,Status,int32,ErrorCode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPXRDeviceMotionTrackerConnectionDelegate,int32,Count,int32,ConnectionState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRDeviceMotionTrackerRecalibrationDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPXRDeviceBodyTrackingActionDelegate,int32, BoneIndex, EPxrBodyActionList, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXREventDataMotionTrackerKeyDelegate, FPXREventDataMotionTrackerKey, MotionTrackerKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXREventDataExtDevConnectEventDelegate, FPXREventDataExtDevConnectEvent, ExtDevConnectEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXREventDataExtDevBatteryEventDelegate, FPXREventDataExtDevBatteryEvent, ExtDevBatteryEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXREventDataExtDevPassDataEventDelegate, int32, status);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXREventDataMotionTrackingModeChangedEventDelegate, int32, mode);

//MR
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRAnchorDataUpdatedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRMeshDataUpdatedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPXRSceneCaptureDataUpdatedDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRAnchorServiceStateUpdatedDelegate,EPICOMRState,State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRMeshScanningStateUpdatedDelegate,EPICOMRState,State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRSceneCaptureServiceStateUpdatedDelegate,EPICOMRState,State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPXRVSTDisplayChangedDelegate,EPICOVSTDisplayStatus,Status);

UCLASS()
class UPICOXREventManager : public UObject
{
	GENERATED_BODY()
public:
	
	static UPICOXREventManager* GetInstance();
	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceMainChangedDelegate DeviceMainChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRHandnessChangedDelegate HandnessChangedDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceConnectChangedDelegate DeviceConnectChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRIpdChanged IpdChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRLongHomeKey LongHomePressedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRResume ResumeDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRRefreshRateChanged RefreshRateChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRInputDeviceChangedDelegate InputDeviceChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FPXRBatteryStateChangedDelegate BatteryStateChangedDelegate;

	/// <summary>Gets the notification of Motion Tracker battery change.
	/// </summary>
	/// <returns>
	/// - Id: Tracker ID.
	/// - BatteryState: For Tracker1.0, value range:[0,1]. For Tracker2.0, value range:[0,10].
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceMotionTrackerBatteryDelegate MotionTrackerBatteryDelegate;

	/// <summary>Gets the notification of Motion Tracker connection state change.
	/// </summary>
	/// <returns>
	/// - Count: The count of connected Motion Trackers.
	/// - ConnectionState: The connection state, `0` for disconnected, `1` for connected.
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceMotionTrackerConnectionDelegate MotionTrackerConnectionDelegate;
	
	/// <summary>Gets the notification of Motion Tracking status code and error code.
	/// </summary>
	/// <returns>
	/// - Status: Refer to the EPXRBodyTrackingStatusCode enum for status code.
	/// - Error code: Refer to the EPXRBodyTrackingErrorCode enum for error code. Currently, the returned error message result is unique, and you temporarily can not identify the error causes only in the result.
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceBodyTrackingStateError BodyTrackingStateErrorDelegate;

	/// <summary>Gets the notification about changes in the Action state of body tracking.
	/// </summary>
	/// <returns>
	/// - BoneIndex: Bone index numbers, currently only include 7 and 8, which are used to distinguish between the left and right feet.
	/// - Body Action list:
	///   - Touch Ground: heels on the ground.
	///   - Keep Static: will be triggered by keep static for 3 seconds.
	///   - Touch Ground And Keep Static: heels on the ground and keep static.
	///   - Touch Ground Toe: toes on the ground.
	///   - Foot Down Action: foot down action. 	 
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceBodyTrackingActionDelegate BodyTrackingActionDelegate;

	/// <summary>Gets the notification of Motion Tracker errors. It is suggested to recalibrate the Motion Tracker after receiving the notification.
	/// </summary>	
	UPROPERTY(BlueprintAssignable)
	FPXRDeviceMotionTrackerRecalibrationDelegate MotionTrackerRecalibrationDelegate;

	/// <summary>Gets the notification of Motion Tracker key.
	/// </summary>
	/// <returns>
    ///	- TrackerSN: Serial number of Tracker.
    ///	- Code: Key value, converted to Android standard key value. (Power key: 26)
    ///	- Action: up: `1` and down: `0`. now only action `0` is supported.
    ///	- Repeat: Currently, it appears to be `1`.
    ///	- Short Press: Is it a short press? Currently, short press is supported, so it is all true.
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXREventDataMotionTrackerKeyDelegate DataMotionTrackerKeyDelegate;

	/// <summary>Gets the notification of Motion Tracker connect state.
	/// </summary>
	/// <returns>
    ///	- TrackerSN: Serial number of Tracker.
    ///	- State: `1` for connected and `0` for disconnected.
	/// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXREventDataExtDevConnectEventDelegate DataExtDevConnectEventDelegate;

	/// <summary>Gets the notification about changes of Motion Tracking battery.
	/// </summary>
	/// <returns>
    ///	- TrackerSN: Serial number of Tracker.
    ///	- OutBattery: Battery, value range:[0,10]
    ///	- OutCharger: Whether the Tracker is on charging, `1` for on charging, `0` for not.
    /// </returns>		
	UPROPERTY(BlueprintAssignable)
	FPXREventDataExtDevBatteryEventDelegate DataExtDevBatteryEventDelegate;

	/// <summary>Gets the notification about changes of Motion Tracking pass data.
	/// </summary>
	/// <returns>Status:
	///   '1': Pass data is ready, you need to call `PXR_GetExtDevTrackerByPassData` to retrieve the data by frame.
	///   `0`: Pass data is stopped.
    /// </returns>			
	UPROPERTY(BlueprintAssignable)
	FPXREventDataExtDevPassDataEventDelegate DataExtDevPassDataEventDelegate;

	/// <summary>Gets the notification about changes of Motion Tracking mode.
	/// </summary>
	/// <returns>
    ///	Mode: `0` for BodyTracking and `1` for ObjectTracking.
    /// </returns>		
	UPROPERTY(BlueprintAssignable)
	FPXREventDataMotionTrackingModeChangedEventDelegate DataMotionTrackingModeChangedEventDelegate;

	/// <summary>Gets the update of Anchor data.
	/// </summary>
	PXRRawLongHomeKey RawLongHomePressedDelegate;
	UPROPERTY(BlueprintAssignable)
	FPXRAnchorDataUpdatedDelegate AnchorDataUpdatedDelegate;

	/// <summary>Gets the update of Mesh data.
	/// </summary>	
	UPROPERTY(BlueprintAssignable)
	FPXRMeshDataUpdatedDelegate MeshDataUpdatedDelegate;

	/// <summary>Gets the update of Scene Capture data.
	/// </summary>	
	UPROPERTY(BlueprintAssignable)
	FPXRSceneCaptureDataUpdatedDelegate SceneCaptureDataUpdatedDelegate;

	/// <summary>Gets the updated state of Spatial Anchor service.
	/// </summary>	
	/// <returns>State of Spatial Anchor service:
    ///	- Initialized: After checking the Spatial Anchor feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Spatial Anchor service has been successfully started.
	///	- Stopped: This state is set after the Spatial Anchor service has been successfully shut down.
    /// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRAnchorServiceStateUpdatedDelegate SpatialAnchorServiceStateUpdatedDelegate;

	/// <summary>Gets the updated state of Mesh scanning.
	/// </summary>	
	/// <returns>State of Spatial Mesh scanning:
    ///	- Initialized: After checking the Spacial Mesh feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Spatial Mesh scanning has been successfully started.
	///	- Stopped: This state is set after the Spatial Mesh scanning has been successfully shut down.
    /// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRMeshScanningStateUpdatedDelegate MeshScanningStateUpdatedDelegate;

	/// <summary>Gets the updated state of Scene Capture service.
	/// </summary>
    /// <returns>State of Scene Capture service:
    ///	- Initialized: After checking the Scene Capture feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Scene Capture service has been successfully started.
	///	- Stopped: This state is set after the Scene Capture service has been successfully shut down.
    /// </returns>			
	UPROPERTY(BlueprintAssignable)
	FPXRSceneCaptureServiceStateUpdatedDelegate SceneCaptureServiceStateUpdatedDelegate;

	/// <summary>Gets the change of VST display.
	/// </summary>	
	/// <returns> The change of VST state:
    ///	- Display Disabled: VST is disabled.
    ///	- Display Enabling: VST is enabling.
    ///	- Display Enabled: VST is enabled.
    ///	- Display Disabling: VST is diabling.
    /// </returns>	
	UPROPERTY(BlueprintAssignable)
	FPXRVSTDisplayChangedDelegate VSTDisplayChangedDelegate;
};
