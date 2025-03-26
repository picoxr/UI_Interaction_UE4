// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "PXR_MotionTrackingTypes.h"
#include "PXR_MotionTrackingFunctionLibrary.generated.h"

UCLASS()
class  PICOXRMOTIONTRACKING_API UPICOXRMotionTrackingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/// <summary>
	/// Gets whether the current device supports face tracking.
	/// </summary>
	/// <param name="Supported">Indicates whether the device supports face tracking:
	/// * `true`: Support
	/// * `false`: Not support
	/// </param>
	/// <param name="SupportedModes"> The EPXRFaceTrackingMode enum. Returns the face tracking modes supported by the current device.
	/// - `PXR_FTM_NONE		  = (uint8)-1`: Do not enable face tracking
	/// - `PXR_FTM_FACE		  = 0`: Image-driven mode
	/// - `PXR_FTM_LIPS		  = 1`: Audio-driven mode
	/// - `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode
	/// - `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingSupported(bool& Supported, TArray<EPXRFaceTrackingMode>& SupportedModes);

	/// <summary>
	/// Gets the state of face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="IsTracking">Returns a bool indicating whether face tracking is working:
	/// * `true`: face tracking is working
	/// * `false`: face tracking has been stopped
	/// </param>
	/// <param name="TrackingState">Returns the face tracking state information, including the face tracking mode and face tracking state code.
	/// - `CurrentTrackingMode`: EPXRFaceTrackingMode enum
	/// 	- `PXR_FTM_NONE		  = (uint8)-1`: Do not enable face tracking
	/// 	- `PXR_FTM_FACE		  = 0`: Image-driven mode
	/// 	- `PXR_FTM_LIPS		  = 1`: Audio-driven mode
	/// 	- `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode
	/// 	- `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode
	/// - `TrackingStateCode`: The [EPXRTrackingStateCode](https://developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#94bd97fa) enum
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingState(bool& IsTracking, FPXRFaceTrackingState& TrackingState);

	/// <summary>
	/// Starts face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StartInfo">Passes the information for starting face tracking. Here you need to choose the face tracking mode. For details, see the above EPXRFaceTrackingMode enum.</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool StartFaceTracking(const FPXRFaceTrackingStartInfo& StartInfo);

	/// <summary>
	/// Stops face tracking.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StopInfo">Passes the information for stopping face tracking:
	/// `Pause`: Bool. `true` indicates pausing face tracking and `false` indicates directly stopping face tracking.
	/// If you need to switch the face-tracking mode, you can set `Pause` to true and then call `StartFaceTracking` to select another mode, instead of completely stop it.
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool StopFaceTracking(const FPXRFaceTrackingStopInfo& StopInfo);

	/// <summary>
	/// Gets face tracking data.
	/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.
	/// </summary>
	/// <param name="GetInfo">Specifies the face tracking data you want.
	/// - DisplayTime: Int. Set as the prediction time. Currently, this parameter is only supported to be set as 0.
	/// </param>
	/// <param name="OutFaceTrackingData">Returns the desired face tracking data:
	/// - `BlendShapeWeights`: See the [EPXRFaceBlendShape](https://developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#ab7d460b) enum for details. 
	/// - `TimeStamp`: Int. The time at which the data was retrieved.
	/// - `LaughingProb`: The probability of "laughing," ranging from 0 to 1, where 0 represents no smile, and 1 represents a hearty laugh.
	/// - `EyeValid`: Indicates whether the data for the eye area is valid.
	/// - `FaceValid`: Indicates whether the data for the facial area is valid.
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|FaceTracking")
		static bool GetFaceTrackingData(const FPXRFaceTrackingDataGetInfo& GetInfo, FPXRFaceTrackingData& OutFaceTrackingData);

	/// <summary>
	/// Gets whether the current device supports eye tracking.
	/// </summary>
	/// <param name="Supported">
	/// Returns a bool indicating whether eye tracking is supported:
	/// * `true`: Supported
	/// * `false`: Not supported
	/// </param>
	/// <param name="SupportedModes">
	/// Returns the eye tracking modes supported by the current device:
	/// `PXR_ETM_BOTH`: The device supports tracking both eyes, namely binocular-tracking mode
	/// `PXR_ETM_NONE`: The device does not support eye tracking
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeTrackingSupported(bool& Supported, TArray<EPXREyeTrackingMode>& SupportedModes);

	/// <summary>
	/// Gets the state of eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="IsTracking">Returns a bool that indicates whether eye tracking is working:
	/// * `true`: eye tracking is working
	/// * `false`: eye tracking has been stopped
	/// </param>
	/// <param name="TrackingState">Returns the eye tracking state information, including:
	/// - `CurrentTrackingMode`: The EPXREyeTrackingMode enum
	/// - `TrackingStateCode`:  The EPXRTrackingStateCode enum
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeTrackingState(bool& IsTracking, FPXREyeTrackingState& TrackingState);

	/// <summary>
	/// Starts eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StartInfo">Passes the information for starting eye tracking.
	/// - `NeedCalibration`: Whether your app needs eye tracking calibration
	/// - `StartMode`: EPXREyeTrackingMode enum
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool StartEyeTracking(const FPXREyeTrackingStartInfo& StartInfo);

	/// <summary>
	/// Stops eye tracking.
	/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="StopInfo">Passes the information for stopping eye tracking. Currently, you do not need to pass anything.</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool StopEyeTracking(const FPXREyeTrackingStopInfo& StopInfo);

	/// <summary>Gets eye tracking data.
    /// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise. To call this API, you need to enable eye tracking first for your project.
	/// </summary>
	/// <param name="WorldToMetersScale"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>
	/// <param name="GetInfo">Specifies the eye tracking data you want:
	/// - DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.
	/// - QueryPosition: Bool. Whether to query the position data.
	/// - QueryOrientation: Bool. Whether to query the orientation data.
	/// </param>
	/// <param name="OutEyeTrackingData">Returns the desired eye tracking data. The structure containing the following details:
    /// <ul>
    /// <li>`EyeType`: EPICOEye type:
	///		- Left: The left eye
	///		- Right: The right eye
	///		- Center: The midpoint between eyes
	/// </li>
    /// <li>`Position`: FVector, the current position of eyes </li>
	/// <li>`Orientation`: FRotator, the current eye gaze direction </li>
	/// <li>`bIsPoseValid`: Bool, whether the current eye's position data is valid </li>
	/// <li>`Openness`: Float, the openness data of the left eye or right eye </li>
	/// <li>`bIsOpennessValid`: Bool, whether the current eye's openness data is valid </li>
    /// </ul>
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking", meta = (WorldToMetersScale = "100.0"))
		static bool GetEyeTrackingData(float WorldToMetersScale, const FPXREyeTrackingDataGetInfo& GetInfo, FPXREyeTrackingData& OutEyeTrackingData);

	/// <summary>
	/// Gets the openness of the left and right eyes.
	/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name="pvr.app.et_tob_advance" android:value="true"/>` to the AndroidManifest.xml file.
	/// </summary>
	/// <param name="LeftEyeOpenness">The openness of the left eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>
	/// <param name="RightEyeOpenness">The openness of the right eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyeOpenness(float& LeftEyeOpenness, float& RightEyeOpenness);

	/// <summary>
	/// Gets the information about the pupils of both eyes.
	/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name="pvr.app.et_tob_advance" android:value="true"/>` to the AndroidManifest.xml file.
	/// </summary>
	/// <param name="EyePupilInfo">Returns the diameters and positions of both pupils.
	/// - LeftEyePupilDiameter: Float. The left eye pupil diameter in pixels.
	///	- RightEyePupilDiameter: Float. The right eye pupil diameter in pixels.
	///	- LeftEyePupilPosition: FVector2D. The location of the left eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.
	///	- RightEyePupilPosition: FVector2D. The location of the right eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
		static bool GetEyePupilInfo(FPXREyePupilInfo& EyePupilInfo);
		
	/// <summary>
	/// Retrieves the per-eye pose information.
	/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name="pvr.app.et_tob_advance" android:value="true"/>` to the AndroidManifest.xml file.
	/// </summary>
	/// <param name="Timestamp">Int. The time at which the data was retrieved.</param>
	/// <param name="LeftEyePose"> FTransform. Indicates the location and rotation of the left eye.</param>
	/// <param name="RightEyePose">FTransform. Indicates the location and rotation of the right eye.</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
	static bool GetPerEyePose(int64& Timestamp, FTransform& LeftEyePose, FTransform& RightEyePose);

	/// <summary>
	/// Retrieves the eye blink information.
	/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name="pvr.app.et_tob_advance" android:value="true"/>` to the AndroidManifest.xml file.
	/// </summary>
	/// <param name="Timestamp"> Int. The time at which the data was retrieved.</param>
	/// <param name="bLeftBlink">Bool. Indicates whether the left eye is blinked (true) or not (false).</param>
	/// <param name="bRightBlink">Bool. Indicates whether the right eye is blinked (true) or not (false).</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|EyeTracking")
	static bool GetEyeBlink(int64& Timestamp, bool& bLeftBlink, bool& bRightBlink);

    /// <summary>
	/// Starts the motion tracking service.
	/// </summary>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_WantBodyTrackingService();
	
	/// <summary>
	/// Gets whether the current device supports body tracking.
	/// </summary>
	/// <param name="Supported">
	/// Returns a bool indicating whether body tracking is supported:
	/// * `true`: Supported
	/// * `false`: Not supported
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_GetBodyTrackingSupported(bool& Supported);

	/// <summary>
	/// Gets the state of body tracking.
	/// </summary>
	/// <param name="IsTracking">Returns a bool that indicates whether body tracking is working:
	/// * `true`: Body tracking is working.
	/// * `false`: Body tracking has been stopped.
	/// </param>
	/// <param name="TrackingState">Returns the body tracking state information, including:
	/// - `CurrentTrackingMode`: The EPXRBodyTrackingMode enum.
	/// - `TrackingStateCode`:  The EPXRTrackingStateCode enum.
	/// - `TrackingStatusCode`: The EPXRBodyTrackingStatusCode enum.
	/// - `TrackingErrorCode`: The EPXRBodyTrackingErrorCode enum.
	/// - `Connected Band Count`: Connected count of bands.
	/// - `Connected Fitness Band`: Array of connected bands.
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_GetBodyTrackingState(bool& IsTracking, FPXRBodyTrackingState& TrackingState);

	/// <summary>
	/// Starts body tracking.
	/// </summary>
	/// <param name="StartInfo">Passes the information for starting body tracking.
	/// - `Body Tracking Mode`: The EBodyTrackingMode enum.
	/// - `Bone Length`: Specifies bone length.
	/// - `Other Mode`: The default value is `-1`, it is reserved for special requirements. Currently, you do not need to pass anything.
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_StartBodyTracking(const FPXRBodyTrackingStartInfo& StartInfo);

	/// <summary>
	/// Stops body tracking.
	/// </summary>
	/// <param name="StopInfo">Passes the information for stopping body tracking. Currently, you do not need to pass anything.</param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_StopBodyTracking(const FPXRBodyTrackingStopInfo& StopInfo);

	/// <summary>Gets body tracking data.
	/// </summary>
	/// <param name="WorldToMetersScale"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>
	/// <param name="GetInfo">Specifies the body tracking data you want:
	/// - DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.
	/// - DataFlags: The EPXRBodyTrackingGetDataFlags enum.
	/// </param>
	/// <param name="BodyTrackingData">Returns the desired body tracking data. The structure containing the following details:
    /// <ul>
	/// <li>`TimeStamp`: Int, the time at which the data was retrieved.</li>
    /// <li>`bone`: EPxrBodyTrackerRole, Bone name. If bone == NONE_ROLE, this bone is not calculated.</li>
    /// <li>`LocalPose`: FTransform, bone local transform. </li>
	/// <li>`GlobalPose`: FTransform, bone global transform.</li>
	/// <li>`velo`: FVector, velocity of x,y,z. </li>
	/// <li>`acce`: FVector, acceleration of x,y,z. </li>
	/// <li>`wvelo`: FVector, angular velocity of x,y,z. </li>
	/// <li>`wacce`: FVector, angular acceleration of x,y,z. </li>
	/// <li>`bodyAction`: EPxrBodyActionList, multiple actions can be supported at the same time by means of BodyActionList, which includes:
    /// - `NoneAction  = 0`, None action.
    /// - `TouchGround = 1`, Touch ground.
    /// - `KeepStatic  = 2`, Keep static.
    /// - `TouchGroundAndKeepStatic=3`, Touch ground and keep static.
    /// - `TouchGroundToe=4`, Touch ground toe.
    /// - `FootDownAction=5`, Foot down action.
	/// </li>
    /// </ul>
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking", meta = (WorldToMetersScale = "100.0"))
	static bool PXR_GetBodyTrackingData(float WorldToMetersScale, const FPXRBodyTrackingDataGetInfo& GetInfo, FPXRBodyTrackingData& BodyTrackingData);

	/// <summary>Starts motion tracker calibration app.
	/// </summary>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|BodyTracking")
	static bool PXR_StartMotionTrackerCalibApp();

	/// <summary>Gets the connect state of motion tracker.
	/// </summary>
	/// <param name="connectState">Connect state of the motion tracker, which includes:
	/// - `Tracker Sum`: The count of trackers.
	/// - `Trackers SN Array`: The array of trackers' SN.
	/// </param>	
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetMotionTrackerConnectStateWithSN(FPXRMotionConnectState& connectState);

	/// <summary>Gets the device type of motion tracker.
	/// </summary>
	/// <param name="trackerType">Device type of the motion tracker, which includes:
	/// - `PICO MOTION TRACKER 1.0`: Motion Tracker 1.0.
	/// - `PICO MOTION TRACKER 2.0`: Motion Tracker 2.0.
	/// </param>	
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetMotionTrackerDeviceType(EPXRMotionTrackerType& trackerType);

	/// <summary>Gets the mode of motion tracker.
	/// </summary>
	/// <param name="trackerMode">Mode of the motion tracker, which includes:
	/// - `BODY TRACKING MODE`: Body tracking mode.
	/// - `OBJECT TRACKING MODE`: Object tracking mode.
	/// </param>	
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetMotionTrackerMode(EPXRMotionTrackerMode& trackerMode);

	/// <summary>Gets the location of motion tracker.
	/// </summary>
	/// <param name="WorldToMetersScale"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>
	/// <param name="trackerSN"> The array of trackers' SN.</param>
	/// <param name="locations">SN location data, which includes:
	/// - TrackerSN: Int. SN of the Tracker corresponding to the data.
	/// - Local Pose: Same frame pose as HMD.
	/// - Global Pose: Pose in the global reference frame of the system. It is not recommended to use without special requirements.
	/// </param>
	/// <param name="Confidence"> The EPXRMotionTrackerConfidence enum:
	/// - `PXR_STATIC_ACCURATE = 0 UMETA`: Static, accurate tracking.
	/// - `PXR_6DOF_ACCURATE = 1 UMETA`: 6DoF data, tracking accurate.
	/// - `PXR_3DOF_NOT_ACCURATE = 2 UMETA`: 3DoF data, tracking is not accurate.
	/// - `PXR_6DOF_NOT_ACCURATE = 3 UMETA`: 6DoF data, tracking is not accurate.
	/// </param>	
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker", meta = (WorldToMetersScale = "100.0"))
	static bool PXR_GetMotionTrackerLocations(float WorldToMetersScale ,const FString& trackerSN, FPXRMotionTrackerLocations& locations,EPXRMotionTrackerConfidence& Confidence);

	/// <summary>Checks the mode and number of motion tracker.
	/// </summary>
	/// <param name="trackerType">Desired tracking mode:
	/// - `BODY TRACKING MODE`: Body tracking mode.
	/// - `OBJECT TRACKING MODE`: Object tracking mode.
	/// </param>	
	/// <param name="TrackerNumber">Desired number of tracker, value range:[0,3].
	/// </param>		
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static void PXR_CheckMotionTrackerModeAndNumber(EPXRMotionTrackerMode trackerType,int32 TrackerNumber);

	/// <summary>Gets the connect state of externally developed trackers.
	/// </summary>
	/// <param name="connectState">The connect state of externally developed trackers, which includes:
	/// - `Ext Number`: Connected number of externally developed trackers.
	/// - `ExDevTrackerInfos`: Infomation on externally developed trackers, which includes:
	///   - `Tracker SN`: SN of externally developed trackers.
	///   - `Charger Status`: The charger status, `0` represents in charging, `1` reresents not in charging.
	///   - `Battery Volume`: Battery volume of externally developed trackers, value range:[0,10].
	/// </param>	
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetExtDevTrackerConnectState(FPXRExtDevTrackerConnectState &connectState);

	/// <summary>Sets the viberation of externally developed trackers.
	/// </summary>
	/// <param name="motorViberate">Spread spectrum vibration, the parameter includes:
	///	- `Tracker SN`: SN of externally developed trackers.
	/// - `Level`: Motor vibration intensity, stop vibrating if the value is `0`,value range:[0,255].
	/// - `Frequency`: Motor viberation frequency, value range:(40,500).
	/// - `Duration`: Motor vibration time, unit ms, when the value is `-999`, it means that the vibration is constant.
	/// </param>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_SetExtDevTrackerMotorVibrate(const  FPXRExtDevTrackerMotorVibrate &motorVibrate);

	/// <summary>Sets the pass data state of externally developed trackers.
	/// </summary>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: enable the pass data</li>
    /// <li>`false`: pass data closed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_SetExtDevTrackerPassDataState(bool State);

	/// <summary>Sets the externally developed trackers by pass data.
	/// </summary>
	/// <param name="passData">Array of pass data, includes:
	///	- `Tracker SN`: SN of externally developed trackers.
	/// - `PassData`: Currently valid pass data array.
	/// </param>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_SetExtDevTrackerByPassData(const FPXRExtDevTrackerPassData &passData);

	/// <summary>Gets the externally developed trackers by pass data.
	/// </summary>
	/// <param name="PassDatas">Array of pass data, includes:
	///	- `Tracker SN`: SN of externally developed trackers.
	/// - `PassData`: Currently valid pass data array.
	/// </param>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetExtDevTrackerByPassData(TArray<FPXRExtDevTrackerPassData> &PassDatas);

	/// <summary>Gets the externally developed trackers' battery.
	/// </summary>
	/// <param name="trackerSN">SN of externally developed trackers.</param>
	/// <param name="out_battery">Battery of externally developed trackers, value range: [0-10]</param>
    /// <param name="0ut_charger">Whether the tracker is on charging, `0` for not on charging, `1` for on charging.</param>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetExtDevTrackerBattery(const FString& trackerSN,int32& out_battery,int32& out_charger);

	/// <summary>Gets the key data of externally developed trackers.
	/// </summary>
	/// <param name="trackerSN">SN of externally developed trackers.</param>
	/// <param name="KeyData"> Key data of the trackers including:
    /// - `Ext Dev ID`: ID of the externally developed tracker.
	/// - `key`: `0` for not pressed, `1` for pressed.
	/// - `touch`: `0` for not pressed, `1` for pressed.
	/// - `Trigger`: Value range:[0,255].
	/// - `Grip`: Value range:[0,255].
	/// - `Rocker_x`: Value range:[0,255].	
	/// - `TRocker_y`: Value range:[0,255].
    /// </param>
	/// <returns>Bool:
    /// <ul>
	/// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
	UFUNCTION(BlueprintCallable, Category = "PXR|MotionTracker")
	static bool PXR_GetExtDevTrackerKeyData(const FString& trackerSN, FPXRExtDevTrackerKeyData &keyData);
};
