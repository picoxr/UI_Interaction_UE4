// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include <array>
#include "HeadMountedDisplayTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PXR_HMDTypes.h"
#include "PXR_HMDFunctionLibrary.generated.h"

class UTexture2D;

/* Boundary boundary types*/
UENUM(BlueprintType)
enum class EPICOXRBoundaryType : uint8
{
	Outer UMETA(DisplayName = "The Outer Boundary"),
	PlayArea UMETA(DisplayName = "The Play Area Boundary"),
};

UENUM(BlueprintType)
enum class EPICOXRBoundaryState :uint8
{
	GobackDialog,
	ToofarDialog,
	LostDialog,
	LostNoReason,
	LostCamera,
	LostHighLight,
	LostLowLight,
	LostLowFeatureCount,
	LostReLocation,
	LostInitialization,
	LostNoCamera,
	LostNoIMU,
	LostIMUJitter,
	LostUnknown,
	NothingDialog = 111,
	LostNoDialog = 112
};

UENUM(BlueprintType)
enum class EPICOXRTrackedDeviceType : uint8
{
	None UMETA(DisplayName = "No Devices"),
	HMD UMETA(DisplayName = "HMD"),
	LTouch UMETA(DisplayName = "Left Hand"),
	RTouch UMETA(DisplayName = "Right Hand"),
	Touch UMETA(DisplayName = "All Hands"),
	All UMETA(DisplayName = "All Devices")
};

UENUM(BlueprintType)
enum class EPICOXRNodeType : uint8
{
	LeftHand,
	RightHand,
	Head
};

UENUM(BlueprintType)
enum class EPICOXRCameraType :uint8
{
	Left UMETA(DisplayName = "Left Camera"),
	Right UMETA(DisplayName = "Right Camera")
};

UENUM(BlueprintType, meta = (DisplayName = "PICOXR Foveated Rendering Level", ToolTip = "PICOXR Foveated Rendering Level"))
enum class EPICOXRFoveationLevel :uint8
{
	None,
	Low,
	Medium,
	High,
	TopHigh
};

UENUM(BlueprintType)
enum class EPICOXREyeType :uint8
{
	LeftEye UMETA(DisplayName = "LeftEye"),
	RightEye UMETA(DisplayName = "RightEye"),
	BothEye UMETA(DisplayName = "BothEye")
};

UENUM(BlueprintType)
enum class EPICOXRDeviceAbilities :uint8
{
	TRACKING_MODE_ROTATION_BIT UMETA(DisplayName = "SupportRotationTracking"),
	TRACKING_MODE_POSITION_BIT UMETA(DisplayName = "SupportPositionTracking"),
	TRACKING_MODE_EYE_BIT UMETA(DisplayName = "SupportEyeTracking"),
	TRACKING_MODE_FACE_BIT UMETA(DisplayName = "SupportFaceTracking"),
	TRACKING_MODE_VCMOTOR_BIT UMETA(DisplayName = "SupportBroadBandMotor"),
	TRACKING_MODE_HAND_BIT UMETA(DisplayName = "SupportHandTracking")
};

UENUM(BlueprintType)
enum class EPerfSettingsLevel :uint8
{
	XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT = 0 UMETA(DisplayName = "PowerSavings"),
	XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT = 1 UMETA(DisplayName = "SustainedLow"),
	XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT = 3 UMETA(DisplayName = "SustainedHigh"),
	XR_PERF_SETTINGS_LEVEL_BOOST_EXT = 5 UMETA(DisplayName = "Boost(*)"),
};

UENUM(BlueprintType)
enum class EPerformanceSettingTypes :uint8
{
	CPULevel UMETA(DisplayName = "CPU Level"),
	GPULevel UMETA(DisplayName = "GPU Level"),
};

UENUM(BlueprintType)
enum class EFtLipsyncCtlVal :uint8
{
	STOP_FT,
	STOP_LIPSYNC,
	START_FT,
	START_LIPSYNC,
};

USTRUCT(BlueprintType)
struct FPxrSensorState
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FQuat poseQuat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector poseVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FQuat globalPoseQuat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector globalPoseVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector angularVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector linearVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector angularAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	FVector linearAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 poseTimeStampNs;

	FPxrSensorState()
		: status(0),
	 poseQuat(ForceInit),
	 poseVector(ForceInitToZero),
	 globalPoseQuat(ForceInitToZero),
	 globalPoseVector(ForceInitToZero),
	 angularVelocity(ForceInitToZero),
	 linearVelocity(ForceInitToZero),
	 angularAcceleration(ForceInitToZero),
	 linearAcceleration(ForceInitToZero),
	poseTimeStampNs(0)
	{
	}
};

USTRUCT(BlueprintType, meta = (DisplayName = "PICOXREyeTrackingData"))
struct FPICOXREyeTrackingData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	int32 LeftEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	int32 RightEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	int32 CombinedEyePoseStatus;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector LeftEyeGazePoint;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector RightEyeGazePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector CombinedEyeGazePoint;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector LeftEyeGazeVector;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector RightEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector CombinedEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	float LeftEyeOpenness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	float RightEyeOpenness;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	float LeftEyePupilDilation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	float RightEyePupilDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector LeftEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector RightEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	FVector FoveatedGazeDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICOXREyeTrackingData")
	int32 FoveatedGazeTrackingState;

	FPICOXREyeTrackingData()
		: LeftEyePoseStatus(0),
	RightEyePoseStatus(0),
	CombinedEyePoseStatus(0),
	LeftEyeGazePoint(ForceInitToZero),
	RightEyeGazePoint(ForceInitToZero),
	CombinedEyeGazePoint(ForceInitToZero),
	LeftEyeGazeVector(ForceInitToZero),
	RightEyeGazeVector(ForceInitToZero),
	CombinedEyeGazeVector(ForceInitToZero),
	LeftEyeOpenness(0),
	RightEyeOpenness(0),
	LeftEyePupilDilation(0),
	RightEyePupilDilation(0),
	LeftEyePositionGuide(ForceInitToZero),
	RightEyePositionGuide(ForceInitToZero),
	FoveatedGazeDirection(ForceInitToZero),
	FoveatedGazeTrackingState(0)
	{
	}
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOXRIPDChangedDelegate, float, Ipd);

UCLASS()
class PICOXRHMD_API UPICOXRHMDFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FPICOXRIPDChangedDelegate PICOXRIPDChangedCallback;

	UPICOXRHMDFunctionLibrary();

	static class FPICOXRHMD* PICOXRHMD;
	static FPICOXRHMD* GetPICOXRHMD();

	/// <summary>Gets the current orientation of the HMD.</summary>
	/// <returns> Quat, the current orientation of the HMD. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FQuat PXR_GetCurrentOrientation();

	/// <summary>Gets the current position of the HMD.</summary>
	/// <returns> Quat, the current position of the HMD. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetCurrentPosition();

	/// <summary>Checks if the HMD supports positional tracking.</summary>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: support positional tracking (6DOF mode enabled)</li>
    /// <li>`false`: not support positional tracking (3DOF mode enabled)</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_DoesSupportPositionalTracking();

	/// @brief Gets the angular velocity of the headset.
	/// @return A FVector representing the angular velocity of the headset.
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetAngularVelocity();

	/// @brief Gets the acceleration data of the headset.
	/// @return A FVector representing the acceleration of the headset.
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetAcceleration();

	/// @brief Gets the velocity data of the headset.
	/// @return A FVector representing the velocity of the headset.
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetVelocity();

	/// @brief Gets the angular acceleration data of the headset.
	/// @return A FVector representing the angular acceleration of the headset.
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetAngularAcceleration();

   	/// <summary>Detect whether the user is wearing the HMD.</summary>
	/// <returns>
    /// <ul>
    /// <li>EHMDWornState::Worn if we detect that the user is wearing the HMD</li>
    /// <li>EHMDWornState::NotWorn if we detect the user is not wearing the HMD</li>
    /// <li>EEHMDWornState::Unknown if we cannot detect the state.</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static EHMDWornState::Type PXR_GetHMDWornState();

	/**
	* Reset HMD Position and Orientation.
	* @return true: reset HMD sensor Succeed, false :reset HMD sensor Failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_ResetHMDSensor();

   	/// <summary>Gets the horizontal and vertical FOV of the HMD.</summary>
    /// <param name ="HFOVInDegrees">(Out) Float, the horizontal FOV (in degrees). </param>
    /// <param name ="VFOVInDegrees">(Out) Float, the vertical FOV (in degrees). </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetFieldOfView(float& HFOVInDegrees, float& VFOVInDegrees);

   	/// <summary>Sets FOV in the four directions: left, right, up, and down for specified eye(s).</summary>
    /// <param name ="Eye">(In) Enum, the eye to set FOV for:
    /// <ul>
    /// <li>`LeftEye`
    /// <li>`RightEye`
    /// </ul>
	/// </param>
    /// <param name ="FovLeftInDegrees">(In) Float, the horizontal FOV (in degrees) for the left part of the eye, for example, `47.5` </param>
    /// <param name ="FovRightInDegrees">(In) Float, the horizontal FOV (in degrees) for the right part of the eye </param>
	/// <param name ="FovUpInDegrees">(In) Float, the vertical FOV (in degrees) for the upper part of the eye </param>
	/// <param name ="FovDownInDegrees">(In) Float, the vertical FOV (in degrees) for the lower part of the eye </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_SetFieldOfView(EPICOXREyeType Eye, float FovLeftInDegrees, float FovRightInDegrees, float FovUpInDegrees, float FovDownInDegrees);

	/**
	* Get device vertical Fov.
	* @param VFOVInDegrees    (out) Vertical FOV.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_GetVFov(float& VFOVInDegrees);

	/**
	* Get device horizontal Fov.
	* @param HFOVInDegrees    (out) Horizontal FOV.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_GetHFov(float& HFOVInDegrees);

   	/// <summary>Gets the interpupillary distance (IPD) of the current device.</summary>
	/// <returns>Float, the IPD of the current device. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static float PXR_GetIPD();

   	/// <summary>Gets the new interpupillary distance (IPD) through binding the callback event.</summary>
	/// <param name ="OnPICOXRIPDChanged">(In) Delegate, bind the callback event to get the new IPD. The callback parameter is a float-type value Ipd that indicates the current IPD. </param>
	/// <returns>None </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_IPDChangedDelegates(FPICOXRIPDChangedDelegate OnPICOXRIPDChanged);

   	/// <summary>Gets the current callback event manager, which can be used to bind callback events for delegates.
	/// @note Currently available callback events for binding:
	/// </summary>
    /// <ul>
    /// <li>Device Connect Changed Delegate </li>
    /// <li>Ipd Changed Delegate </li>
    /// <li>Long Home Pressed Delegate</li>
	/// <li>Refresh Rate Changed Delegate</li>
	/// <li>Resume Delegate</li>
    /// </ul>
	/// <returns>UPICOXREventManager class reference. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static class UPICOXREventManager* PXR_GetEventManager();

   	/// <summary>Gets the device model's series number.</summary>
	/// <returns> FString, the current device model's series number. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FString PXR_GetDeviceModel();

	/// <summary>Gets the current display refresh rate.</summary>
	/// <returns>Float
    /// <ul>
    /// <li>`0`: failed to get display refresh rate </li>
    /// <li>`72`: 72Hz</li>
    /// <li>`90`: 90Hz</li>
	/// <li>`120`: 120Hz</li>
    /// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static float PXR_GetCurrentDisplayFrequency();

	/// <summary>Sets the clock frequency level for CPU and GPU.
	/// @note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).
	/// </summary>
	/// <param name ="CPULevel">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>
	/// <param name ="GPULevel">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>
	/// <returns>None </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD", meta=(DeprecatedFunction, DeprecatedMessage="Deprecated. Please use Get/PXR_SetPerformanceLevel instead"))
	static void PXR_SetCPUAndGPULevels(int32 CPULevel, int32 GPULevel);

	/// <summary>Gets the clock frequency level for CPU and GPU.
	/// @note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).
	/// </summary>
	/// <param name ="CPULevel">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>
	/// <param name ="GPULevel">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>
	/// <returns>None </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD",meta=(DeprecatedFunction, DeprecatedMessage="Deprecated. Please use Get/PXR_GetPerformanceLevel instead"))
	static void PXR_GetCPUAndGPULevels(int32& CPULevel, int32& GPULevel);

	/// <summary>Sets a GPU or CPU level for the device.</summary>
	/// <param name ="SettingType">(In) Enum, choose to set a GPU or CPU level:
    /// <ul>
    /// <li>`CPULevel`</li>
    /// <li>`GPULevel`</li>
    /// </ul>
	/// </param>
	/// <param name ="Level">(In) Enum, select a level from the following:
    /// <ul>
    /// <li>`PowerSaving`: power-saving level</li>
    /// <li>`SustainedLow`: low level</li>
    /// <li>`SustainedHigh`: high level</li>
    /// <li>`Boost(*)`: top-high level, be careful to use this level</li>
    /// </ul>
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_SetPerformanceLevel(EPerformanceSettingTypes SettingType, EPerfSettingsLevel Level);

	/// <summary>Gets the device's GPU or CPU level.</summary>
	/// <param name ="SettingType">(In) Enum, choose to set a GPU or CPU level:
    /// <ul>
    /// <li>`CPULevel`</li>
    /// <li>`GPULevel`</li>
    /// </ul>
	/// </param>
	/// <param name ="Level">(Out) Enum, select a level from the following:
    /// <ul>
    /// <li>`PowerSaving`: power-saving level</li>
    /// <li>`SustainedLow`: low level</li>
    /// <li>`SustainedHigh`: high level</li>
    /// <li>`Boost(*)`: top-high level, be careful to use this level</li>
    /// </ul>
	/// </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetPerformanceLevel(EPerformanceSettingTypes SettingType, EPerfSettingsLevel& Level);
	
	/**
	* Gets the system display frequency rate.
	* @return The system display frequency rate.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static float PXR_GetSystemDisplayFrequency();

	/**
	* Sets the system display frequency rate.
	* @param Rate    (In) The frequency rate: 72; 90; 120. Other values are invalid.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_SetSystemDisplayFrequency(float Rate);

	/**
	* Set eye buffer and overlay color space.
	* @param ColorScale         (In) Color scale.
	* @param ColorOffset        (In) Color offset.
	* @param bApplyToAllLayers  (In) If apply to all Layers,default false.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers = false);

	/// <summary>Gets the current focus state of the HMD.</summary>
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: the HMD has focus</li>
    /// <li>`false`: the HMD has lost focus</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHMD")
	static bool GetFocusState();

#pragma region Boundary
	static class UPICOXRBoundarySystem* GetBoundarySystemInterface();

	/// <summary> Gets whether there is a valid boundary configured in the system. </summary>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - yes</li>
	/// <li>`false` - no</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetBoundaryConfigured();

	/// <summary>Gets whether the boundary is enabled.</summary>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - enabled</li>
	/// <li>`false` - disabled</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetBoundaryEnabled();

	/// <summary>Sets the boundary as visible or invisible.
    /// @note If the application is paused, this function will cease. Therefore, you need to call this function again after the application has been resumed.
    /// </summary>
    /// <param name ="NewVisible">Bool, the visibility of the the boundary.
    /// <ul>
    /// <li>`true`: visible</li>
    /// <li>`false`: invisible</li>
    /// </ul>
	/// </param>
    /// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_SetBoundaryVisible(bool NewVisible);

	/// <summary>Gets whether the boundary is set as visible or invisible.</summary>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: visible</li>
    /// <li>`false`: invisible</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetBoundaryVisible();

	/// <summary>Checks whether a tracked device (Left hand, Right hand, Head) will trigger the boundary.</summary>
    /// <param name ="DeviceType">(In) Enum, the type of the tracked device:
    /// <ul>
    /// <li>`LeftHand`: Left hand</li>
    /// <li>`RightHand`: Right hand</li>
    /// <li>`Head`: Headset</li>
    /// </ul>
	/// </param>
    /// <param name ="BoundaryType">(In) Enum, boundary type:
    /// <ul>
    /// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>
    /// <li>`PlayArea`: the biggest internal rectangle of the customized boundary（no such a bounary for on-site quick setting boundary）</li>
    /// </ul>
	/// </param>
	/// <param name ="IsTriggering">(Out) bool, whether the boundary is triggered </param>
	/// <param name ="ClosestDistance">(Out) float, the minimum distance between the tracked node and the boundary </param>
	/// <param name ="ClosestPoint">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>
	/// <param name ="ClosestPointNormal">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>
    /// <returns>Bool:
	/// <ul>
    /// <li>`true`: result got</li>
    /// <li>`false`: failed to get the result</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_BoundaryTestNode(EPICOXRNodeType DeviceType, EPICOXRBoundaryType BoundaryType, bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint, FVector& ClosestPointNormal);

	/// <summary>Checks whether a tracked point in the Unreal coordinate system will trigger the boundary.</summary>
    /// <param name ="Point">(In) FVector, the tracked point, (x,y,z) </param>
    /// <param name ="BoundaryType">(In) Enum, boundary type:
    /// <ul>
    /// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>
    /// <li>`PlayArea`: the biggest internal rectangle of the customized boundary（no such a bounary for on-site quick setting boundary）</li>
    /// </ul>
	/// </param>
	/// <param name ="IsTriggering">(Out) bool, whether the boundary is triggered </param>
	/// <param name ="ClosestDistance">(Out) float, the minimum distance between the tracked node and the boundary </param>
	/// <param name ="ClosestPoint">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>
	/// <param name ="ClosestPointNormal">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>
	/// <returns>Bool:
    /// <ul>
    /// <li>`true`: result got</li>
    /// <li>`false`: failed to get the result</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_BoundaryTestPoint(FVector Point, EPICOXRBoundaryType BoundaryType, bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint, FVector& ClosestPointNormal);

	/// <summary>Gets an array of boundary coordinates.</summary>
    /// <param name ="BoundaryType">(In) Enum, boundary type:
    /// <ul>
    /// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>
    /// <li>`PlayArea`: the biggest internal rectangle of the customized boundary（no such a bounary for on-site quick setting boundary）</li>
    /// </ul>
	/// </param>
	/// <returns>TArray, an array of boundary coordinates. </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static TArray<FVector> PXR_GetBoundaryGeometry(EPICOXRBoundaryType BoundaryType);

	/**
	* Returns the dimensions in UE world space of the requested Boundary Type.
	* @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static FVector PXR_GetBoundaryDimensions(EPICOXRBoundaryType BoundaryType);

	/// <summary>Sets the camera image as the background. </summary>
	/// <param name="Value">(In) Bool:
	/// <ul>
	/// <li>`true` - set camera image as background</li>
	/// <li>`false` - stop using camera image as background</li>
	/// </ul>
	/// </param>
	/// <returns>Int:
	/// <ul>
	/// <li>`0` - success</li>
	/// <li>`-1` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static int PXR_SetSeeThroughBackground(bool Value);

#pragma  endregion Boundary

	/// <summary>Gets the current foveated rendering level.</summary>
	/// <param name="Level">(Out) Enum, the current foveated rendering level:
	/// <ul>
	/// <li>`None`</li>
	/// <li>`Low`</li>
	/// <li>`Medium`</li>
	/// <li>`High`</li>
	/// <li>`TopHigh`</li>
	/// </ul>
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD", meta = (DisplayName = "PXR Get Foveated Rendering Level"))
	static bool PXR_GetFoveationLevel(EPICOXRFoveationLevel& Level);

	/// <summary>Sets a foveated rendering level. </summary>
	/// <param name="Level">(In) Enum, the target foveated rendering level:
	/// <ul>
	/// <li>`None`</li>
	/// <li>`Low`</li>
	/// <li>`Medium`</li>
	/// <li>`High`</li>
	/// <li>`TopHigh`</li>
	/// </ul>
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD", meta = (DisplayName = "PXR Set Foveated Rendering Level"))
	static bool PXR_SetFoveationLevel(EPICOXRFoveationLevel Level);

	/// <summary>Sets foveated rendering parameters.
	/// @note If you are not familiar with foveated rendering, it is recommended to use the predefined Level.
	/// </summary>
	/// <param name="FoveationGainValue">(In) Vector2, it controls the rate of falloff in X and Y direction. The higher the value, the more the reduction. Value range: [1.0, 10.0].</param>
	/// <param name="FoveationAreaValue">(In) Float, it defines the size of the foveated region in which the resolution does not change and this moves with user's gaze point. The value of this parameter is the radius of the region. The higher the value, the larger region. Value range: [0.0, 4.0].</param>
	/// <param name="FoveationMinimumValue">(In) Float, the minimum pixel density. The actual pixel density is greater than or equal to the minimum pixel density. Recommend values: `1/32`, `1/16`, `1/8`, `1/4`, or `1/2`.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD", meta = (DisplayName = "PXR Set Foveated Rendering Parameter"))
	static bool PXR_SetFoveationParameter(FVector2D FoveationGainValue, float FoveationAreaValue, float FoveationMinimumValue);

	/**
	* Set sensor lost custom mode.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static int PXR_SetSensorLostCustomMode(bool Value);

	/**
	* Set sensor lost CMST.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static int PXR_SetSensorLostCMST(bool Value);

	/**
	* Get display frequencies available.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetDisplayFrequenciesAvailable(int& Count, TArray<float>& AvailableRates);

	/// @brief Sets the extra latency mode. Note: Call this function once only.
	/// @param Mode The latency mode:
	/// - 0: ExtraLatencyModeOff (Disable ExtraLatencyMode mode. This option will display the latest rendered frame for display)
	/// - 1: ExtraLatencyModeOn (Enable ExtraLatencyMode mode. This option will display one frame prior to the latest rendered frame)
	/// - 2: ExtraLatencyModeDynamic (Use the system default setup)
	/// @return Whether the extra latency mode has been set:
	/// - true: success
	/// - false: failure
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_SetExtraLatencyMode(int Mode);

	/// <summary>
	/// Gets the predicted state of the main sensor of the HMD.
	/// </summary>
	/// <param name="sensorState">(Out) The predicted sensor state as an FPxrSensorState structure.</param>
	/// <param name="sensorFrameIndex">(Out) The frame index associated with the sensor state.</param>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_GetPredictedMainSensorState(FPxrSensorState& sensorState, int& sensorFrameIndex);

	/**
	* Query Abilities of Device.
	* @param DeviceAbility     (int) Device Ability Type
	* @return bool  The execution result.
	*/
	UFUNCTION(BlueprintCallable, Category= "PXR|PXRHMD")
	static bool PXR_QueryDeviceAbilities(EPICOXRDeviceAbilities DeviceAbility);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_SetLateLatchingEnable(bool Value);


	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options);

	UFUNCTION(BlueprintPure, Category = "PXR|PXRHMD")
	static void PXR_GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters);

	/// <summary>Gets the percentage of power remaining in the HMD.</summary>
	/// <param name="Battery">(Out) Int, the percentage of power, value range: [0, 100]</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_GetHmdBatteryLevel(int32& Battery);
	/**
	* Select Coordinate.
	* @param CoordinateType Coordinate Space  
	* @return bool  The execution result.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_SelectCoordinateSpace(const EPICOXRCoordinateType CoordinateType);

	/// <summary>Sets foveated rendering mode. </summary>
	/// <param name="Mode">Foveated rendering mode:
	/// <ul>
	/// <li> `FixedFoveationRendering`: Fixed foveated rendering (FFR)
	/// <li> `EyeTrackingFoveationRendering`: Eye tracked foveated rendering (ETFR)
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_SetFoveatedRenderingMode(EFoveationRenderingMode Mode);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static float PXR_GetToDeltaSensorY();

	/// <summary>
	/// Gets the predicted display time of a frame, including the see-through camera image.
	/// </summary>
	/// <returns> Float. The predicted time (in miliseconds). </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static float PXR_GetPredictedDisplayTime();
	
	/// <summary>
	/// Gets the Device Name.
	/// </summary>
	/// <returns> FString. The device name,such as PICO 4. </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHMD")
	static FString PXR_GetDeviceName();
};
