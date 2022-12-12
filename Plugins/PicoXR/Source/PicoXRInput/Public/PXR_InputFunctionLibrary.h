//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "SampleBuffer.h"
#include <AudioDevice.h>

#include "Sound/SampleBufferIO.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "PXR_InputFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EPICOXRHandTrackingConfidence : uint8
{
	Low,
	High
};

UENUM(BlueprintType)
enum class EPICOXRActiveInputDevice: uint8
{
	NoneActive,
	ControllerActive,
	HandTrackingActive,
};

UENUM(BlueprintType)
enum class EPICOXRHandFinger :uint8
{
	None,
	Index,
	Middle,
	Ring,
	Pinky
};

UENUM(BlueprintType)
enum class EPICOXRHandJoint : uint8
{
	Palm,
	Wrist,
	ThumbMetacarpal,
	ThumbProximal,
	ThumbDistal,
	ThumbTip,
	IndexMetacarpal,
	IndexProximal,
	IndexIntermediate,
	IndexDistal,
	IndexTip,
	MiddleMetacarpal,
	MiddleProximal,
	MiddleIntermediate,
	MiddleDistal,
	MiddleTip,
	RingMetacarpal,
	RingProximal,
	RingIntermediate,
	RingDistal,
	RingTip,
	LittleMetacarpal,
	LittleProximal,
	LittleIntermediate,
	LittleDistal,
	LittleTip
};

constexpr int32 EHandJointCount = static_cast<int32>(EPICOXRHandJoint::LittleTip) + 1;

UENUM(BlueprintType)
enum class EPICOXRHandType : uint8
{
	None,
	HandLeft,
	HandRight,
};

UENUM(BlueprintType)
enum class EPICOXRHandedness :uint8
{
	LeftHand,
	RightHand,
};

UENUM(BlueprintType)
enum class EPICOXRControllerType :uint8
{
	LeftHand UMETA(DisplayName = "PICO LeftHand"),
	RightHand UMETA(DisplayName = "PICO RightHand"),
	G2Hand UMETA(DisplayName = "PICO G2 Hand"),
};

UENUM(BlueprintType)
enum class EPICOXRArmModelJoint : uint8
{
	Controller,
	Wrist,
	Elbow,
	Shoulder
};

UENUM(BlueprintType)
enum class EPICOXRGazeBehavior : uint8
{
	Never,
	DuringMotion,
	Always
};

UENUM(BlueprintType)
enum class EPICOXRControllerDeviceType : uint8
{
	UnKnown = 0 UMETA(DisplayName = "UnKnown Controller"),
	G2 = 3 UMETA(DisplayName = "PICO G2"),
	Neo2 = 4 UMETA(DisplayName = "PICO Neo2"),
	Neo3 = 5 UMETA(DisplayName = "PICO Neo3"),
	PICO_4 = 6 UMETA(DisplayName = "PICO 4"),
};

UENUM(BlueprintType)
enum class EPICOXRVibrateController : uint8
{
	No = 0,
	Left = 1,
	Right = 2,
	LeftAndRight = 3
};

UENUM(BlueprintType)
enum class EPICOXRChannelFlip : uint8
{
	No = 0,
	Yes = 1
};

UENUM(BlueprintType)
enum class EPICOXRCacheConfig : uint8
{
	CacheAndVibrate,
	CacheNoVibrate
};


UENUM(BlueprintType)
enum class EPxrControllerKeyMap : uint8
{
	PXR_CONTROLLER_KEY_HOME = 0,
	PXR_CONTROLLER_KEY_AX = 1,
	PXR_CONTROLLER_KEY_BY = 2,
	PXR_CONTROLLER_KEY_BACK = 3,
	PXR_CONTROLLER_KEY_TRIGGER = 4,
	PXR_CONTROLLER_KEY_VOL_UP = 5,
	PXR_CONTROLLER_KEY_VOL_DOWN = 6,
	PXR_CONTROLLER_KEY_ROCKER = 7,
	PXR_CONTROLLER_KEY_GRIP = 8,
	PXR_CONTROLLER_KEY_TOUCHPAD = 9,
	PXR_CONTROLLER_KEY_LASTONE = 127,

	PXR_CONTROLLER_TOUCH_AX = 128,
	PXR_CONTROLLER_TOUCH_BY = 129,
	PXR_CONTROLLER_TOUCH_ROCKER = 130,
	PXR_CONTROLLER_TOUCH_TRIGGER = 131,
	PXR_CONTROLLER_TOUCH_THUMB = 132,
	PXR_CONTROLLER_TOUCH_LASTONE = 255
};


USTRUCT(BlueprintType)
struct FAudioClipData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 delaytag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 slot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 buffersize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 sampleRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 channelMask;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
	int32 bitrate;
};

USTRUCT(BlueprintType)
struct FPHFDataContent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FPHFDataContent")
		FString data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FPHFDataContent")
		int size;
};

USTRUCT(BlueprintType)
struct PICOXRINPUT_API FPHFData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FPHFData")
		FPHFDataContent PHFDataContent;
};

UCLASS()
class PICOXRINPUT_API UPICOXRInputFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UPICOXRInputFunctionLibrary();

	/**
	* Get controller power.
	* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Power           (Out) The power of controller.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerPower(EPICOXRControllerType ControllerType, int32& Power);

	/**
	* Get controller connect state.
	* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Status          (Out) Connect state,true:Connected,false:DisConnected.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerConnectionState(EPICOXRControllerType ControllerType, bool& Status);

	/**
	* Get the main controller.
	* @param Handedness     (Out) Main handedness(Neo LeftController/Neo RightController).
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetMainControllerHandle(EPICOXRHandedness& Handedness);

	/**
	* Set the main controller.
	* @param Handedness     (In) Main handedness(Neo LeftController/Neo RightController).
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static bool PXR_SetMainControllerHandle(EPICOXRHandedness Handedness);

	/**
	* Get controller angular velocity.
	* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param AngularVelocity   (Out) Controller angular velocity.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerAngularVelocity(EPICOXRControllerType ControllerType, FVector& AngularVelocity);

	/**
	* Get controller acceleration.
	* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Acceleration     (Out) Controller acceleration.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerAcceleration(EPICOXRControllerType ControllerType, FVector& Acceleration);

	/**
	* Get controller linear velocity.
	* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param LinearVelocity    (Out) Controller linear velocity.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerLinearVelocity(EPICOXRControllerType ControllerType, FVector& LinearVelocity);

	/**
	* Vibration the controller.
	* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Strength          (In) Vibration strength.
	* @param Time              (In) Vibration time.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_VibrateController(EPICOXRControllerType ControllerType, float Strength, int Time);

	/**
	* Get the controller type.
	* @param ControllerType    (Out) The controller type(G2 /Neo).
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static void PXR_GetControllerDeviceType(EPICOXRControllerDeviceType& ControllerType);

	/**
	* Set controller arm model parameter.
	* @param Controller        (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Handness          (In) Determines if the controller is in the left hand or right hand.
	* @param ArmJoint          (In) The arm joint(Controller/Wrist/Elbow/Shoulder).
	* @param GazeType          (In) The gaze type(Never/DuringMotion/Always).
	* @param ElbowHeight       (In) The Height of the elbow..
	* @param ElbowDepth        (In) The Depth of the elbow.
	* @param PointerTiltAngle  (In) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput", meta = (ArmJoint = "Controller", GazeType = "DuringMotion", ElbowHeight = "0.0", ElbowDepth = "0.0", PointerTiltAngle = "15.0"))
	static void PXR_SetControllerArmModelParam(EPICOXRControllerType Controller, EPICOXRHandedness Handness, EPICOXRArmModelJoint ArmJoint, EPICOXRGazeBehavior GazeType, float ElbowHeight, float ElbowDepth, float PointerTiltAngle);

	/**
	* Set controller arm model parameter.
	* @param Controller         (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Handness          (Out) Determines if the controller is in the left hand or right hand.
	* @param ArmJoint          (Out) The arm joint(Controller/Wrist/Elbow/Shoulder).
	* @param GazeType          (Out) The gaze type(Never/DuringMotion/Always).
	* @param ElbowHeight       (Out) The Height of the elbow..
	* @param ElbowDepth        (Out) The Depth of the elbow.
	* @param PointerTiltAngle  (Out) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static void PXR_GetControllerArmModelParam(EPICOXRControllerType Controller, EPICOXRHandedness& Handness, EPICOXRArmModelJoint& ArmJoint, EPICOXRGazeBehavior& GazeType, float& ElbowHeight, float& ElbowDepth, float& PointerTiltAngle);

	/**
	* Get handedness.
	* @param  Handedness        (Out) Handedness.
	* @return True if get succeed.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static bool PXR_GetHandedness(EPICOXRHandedness& Handedness);

	/**
	* Get controller enable homeKey.
	* @return True if home key enable.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static bool PXR_GetControllerEnableHomekey();

	/**
	* Set controller origin offset.
	* @param Controller      (In) Controller type.
	* @param Offset          (In) Origin offset.   
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static void PXR_SetControllerOriginOffset(EPICOXRControllerType Controller, FVector Offset);

	/**
	* Get controller location and rotation with predicted time.
	* @param DeviceHand      (In) Select the left or right handle.
	* @param PredictedTime   (In) Prediction time (ms).
	* @param OutLocation    (Out) Location with predicted time.
	* @param OutRotation    (Out) Rotation with predicted time.
	*/
	UFUNCTION(BlueprintCallable, Category="PXR|PXRInput")
	static bool PXR_GetControllerPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FVector& OutLocation, FRotator& OutRotation);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_StartControllerVCMotor(FString file, EPICOXRVibrateController slot);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_SetControllerAmp(float mode);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_StopControllerVCMotor(int clientId);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_SetControllerVibrationEvent(int deviceID, int frequency, float strength, int time);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_StartVibrateBySharem(USoundWave* InSoundWave, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig, int& SourceId);

	//UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static void PXR_GetVibrateDelayTime(FString& data);
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_SetControllerEnableKey(bool isEnable, EPxrControllerKeyMap Key);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_SaveVibrateByCache(USoundWave* InSoundWave, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig, EPICOXRCacheConfig enableV, int& SourceId);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_StartVibrateByCache(int SourceId);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_ClearVibrateByCache(int SourceId);

	/**
	 * Get the BoneRotation
	 *
	 * @param DeviceHand				(in) The hand to get the Bone Rotation from
	 * @param Key                       (in) The HandJoint to get the Bone Rotation from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static FQuat GetBoneRotation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Get the BoneLocation
	 *
	 * @param DeviceHand				(in) The hand to get the Bone Location from
	 * @param Key                       (in) The HandJoint to get the Bone Location from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static FVector GetBoneLocation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Get the BoneRadii
	 *
	 * @param DeviceHand				(in) The hand to get the Bone Radii from
	 * @param Key                       (in) The HandJoint to get the Bone Radii from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static float GetBoneRadii(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Check if the specific HandJoint is Bone Orientation Valid
	 *
	 * @param DeviceHand          (in) The hand to get the Orientation Valid status from
	 * @param Key              (in) The HandJoint to get the Orientation Valid status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsBoneOrientationValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Check if the specific HandJoint is Bone Position Valid
	 *
	 * @param DeviceHand          (in) The hand to get the Position Valid status from
	 * @param Key              (in) The HandJoint to get the Position Valid status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsBonePositionValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Check if the specific HandJoint is Bone Orientation Tracked
	 *
	 * @param DeviceHand          (in) The hand to get the Orientation Tracked status from
	 * @param Key              (in) The HandJoint to get the Orientation Tracked status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsBoneOrientationTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Check if the specific HandJoint is Bone Position Tracked
	 *
	 * @param DeviceHand          (in) The hand to get the Position Tracked status from
	 * @param Key              (in) The HandJoint to get the Position Tracked status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsBonePositionTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key);
	/**
	 * Get the RootPose
	 *
	 * @param DeviceHand				(in) The hand to get the RootPose from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static FTransform GetHandRootPose(const EPICOXRHandType DeviceHand);
	/**
	 * Get the pointer pose
	 *
	 * @param DeviceHand				(in) The hand to get the pointer pose from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static FTransform GetPointerPose(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the hand is tracked
	 *
	 * @param DeviceHand				(in) The hand to get the hand status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsHandTracked(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the Aim state is valid
	 *
	 * @param DeviceHand				(in) The hand to get the Aim state from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsAimValid(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the AimRayTouched is valid
	 *
	 * @param DeviceHand				(in) The hand to get the ray status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsAimRayTouchedValid(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the system gesture is in progress
	 *
	 * @param DeviceHand				(in) The hand to get the SystemGesture status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsSystemGestureInProgress(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the hand is dominant
	 *
	 * @param DeviceHand				(in) The hand to get the hand status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsDominantHand(const EPICOXRHandType DeviceHand);
	/**
	 * Check if the menu pressed
	 *
	 * @param DeviceHand				(in) The hand to get the menu status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsMenuPressed(const EPICOXRHandType DeviceHand);
	/**
	 * Get the tracking confidence of the hand
	 *
	 * @param DeviceHand				(in) The hand to get tracking confidence of
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static EPICOXRHandTrackingConfidence GetTrackingConfidence(const EPICOXRHandType DeviceHand);
	/**
	 * Get the scale of the hand
	 *
	 * @param DeviceHand				(in) The hand to get scale of
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static float GetHandScale(const EPICOXRHandType DeviceHand);
	/**
	 * Get the click strength of the hand
	 *
	 * @param DeviceHand				(in) The hand to get click strength of
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static float GetClickStrength(const EPICOXRHandType DeviceHand);
	/**
	 * Check if hand tracking is enabled currently
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool IsHandTrackingEnabled();
	/**
     * Get the user's dominant hand
     *
    */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static EPICOXRHandType GetDominantHand();
	/**
	 * Check if the specific finger is pinching
	 *
	 * @param DeviceHand          (in) The hand to get the IsPinching status from
	 * @param Finger              (in) The Finger to get the IsPinching status from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static bool GetFingerIsPinching(const EPICOXRHandType DeviceHand, const EPICOXRHandFinger Finger);
	/**
	 * Get finger pinch strength of the specific finger
	 *
	 * @param DeviceHand          (in) The hand to get the IsPinching Strength from
	 * @param Finger              (in) The Finger to get the IsPinching Strength from
	 */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static float GetFingerPinchStrength(const EPICOXRHandType DeviceHand, const EPICOXRHandFinger Finger);
	/**
     * Get the active input device
     */
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHandTracking")
	static EPICOXRActiveInputDevice GetActiveInputDevice();
	static class UDataTable* PHFDataTable;
	/**
	* Start vibrate by data name at "/Plugins/PICOXR/Content/Blueprint/PHFDataTable.uasset".
	* You need put your *.phf files on "/Plugins/PICOXR/Content/Phf/" folder.
	* @param DataName		(In)  DataName on PHFDataTable.
	* @param SourceID       (Out) SourceID can be used to pause or resume vibrate.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_StartVibrateByPHF(FName DataName,EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig,float ampValue , int& SourceID);
	
	/**
	* Pause vibrate.
	* @param SourceID		(In)  SourceID got by PXR_StartVibrateByPHF.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_PauseVibrate(int SourceID);

	/**
	* Resume vibrate.
	* @param SourceID		(In)  SourceID got by PXR_StartVibrateByPHF.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_ResumeVibrate(int SourceID);

	/**
	* Update Vibrate Params
	* @param SourceID		(In)  SourceID got by PXR_StartVibrateByPHF.
	* 
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int PXR_UpdateVibrateParams(int SourceID, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig, float AmpValue);
};
