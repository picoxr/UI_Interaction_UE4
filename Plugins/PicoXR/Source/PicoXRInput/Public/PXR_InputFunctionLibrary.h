//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PXR_InputFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum  class EPicoXRHandedness :uint8
{
	LeftHand,
	RightHand,
};

UENUM(BlueprintType)
enum  class EPicoXRControllerType :uint8
{
	LeftHand    UMETA(DisplayName = "Pico Neo LeftHand"),
    RightHand   UMETA(DisplayName = "Pico Neo RightHand"),
    G2Hand      UMETA(DisplayName = "Pico G2 Hand"),
};

UENUM(BlueprintType)
enum class EPicoXRArmModelJoint : uint8
{
	Controller,
	Wrist,
	Elbow,
	Shoulder
};

UENUM(BlueprintType)
enum class EPicoXRGazeBehavior : uint8
{
	Never,
	DuringMotion,
	Always
};

UENUM(BlueprintType)
enum class EPicoXRControllerDeviceType : uint8
{
	UnKnown = 0  UMETA(DisplayName = "UnKnown Controller"),
	G2      = 3  UMETA(DisplayName = "Pico G2"),
    Neo2    = 4  UMETA(DisplayName = "Pico Neo2"),
	Neo3    = 5  UMETA(DisplayName = "Pico Neo3"),
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


UCLASS()
class PICOXRINPUT_API UPicoXRInputFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	* Get controller power.
	* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Power           (Out) The power of controller.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
		static bool PXR_GetControllerPower(EPicoXRControllerType ControllerType,int32 &Power);

	/**
	* Get controller connect state.
	* @param ControllerType   (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Status          (Out) Connect state,true:Connected,false:DisConnected.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_GetControllerConnectionState(EPicoXRControllerType ControllerType,bool &Status);

	/**
	* Get the main controller.
	* @param Handedness     (Out) Main handedness(Neo LeftController/Neo RightController).
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_GetMainControllerHandle(EPicoXRHandedness &Handedness);

	/**
	* Set the main controller.
	* @param Handedness     (In) Main handedness(Neo LeftController/Neo RightController).
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
		static bool PXR_SetMainControllerHandle(EPicoXRHandedness Handedness);

	/**
	* Get controller angular velocity.
	* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param AngularVelocity   (Out) Controller angular velocity.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_GetControllerAngularVelocity(EPicoXRControllerType ControllerType,FVector &AngularVelocity);

	/**
	* Get controller acceleration.
	* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Acceleration     (Out) Controller acceleration.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_GetControllerAcceleration(EPicoXRControllerType ControllerType,FVector &Acceleration);

	/**
	* Get controller linear velocity.
	* @param ControllerType     (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param LinearVelocity    (Out) Controller linear velocity.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_GetControllerLinearVelocity(EPicoXRControllerType ControllerType,FVector &LinearVelocity);

	/**
	* Vibration the controller.
	* @param ControllerType    (In) The controller type(G2 controller/Neo LeftController/Neo RightController).
	* @param Strength          (In) Vibration strength.
	* @param Time              (In) Vibration time.
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static bool PXR_VibrateController(EPicoXRControllerType ControllerType,float Strength, int Time);

	/**
	* Get the controller type.
	* @param ControllerType    (Out) The controller type(G2 /Neo).
	*/
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
        static void PXR_GetControllerDeviceType(EPicoXRControllerDeviceType &ControllerType);

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
		static void PXR_SetControllerArmModelParam(EPicoXRControllerType Controller,EPicoXRHandedness Handness,EPicoXRArmModelJoint ArmJoint, EPicoXRGazeBehavior GazeType, float ElbowHeight, float ElbowDepth, float PointerTiltAngle);
	
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
        static void PXR_GetControllerArmModelParam(EPicoXRControllerType Controller,EPicoXRHandedness& Handness,EPicoXRArmModelJoint & ArmJoint, EPicoXRGazeBehavior & GazeType, float & ElbowHeight, float & ElbowDepth, float & PointerTiltAngle);

	/**
	* Get handedness.
	* @param  Handedness        (Out) Handedness.
	* @return True if get succeed.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
		static bool PXR_GetHandedness(EPicoXRHandedness &Handedness);

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
		static void PXR_SetControllerOriginOffset(EPicoXRControllerType Controller, FVector Offset);

	 /**
	 * Get controller location and rotation with predicted time.
	 * @param DeviceHand      (In) Select the left or right handle.
	 * @param PredictedTime   (In) Prediction time (ms).
	 * @param OutLocation    (Out) Location with predicted time.
	 * @param OutRotation    (Out) Rotation with predicted time.
	 */
	UFUNCTION(BlueprintCallable,Category="PXR|PXRInput")
	static bool PXR_GetControllerPredictedLocationAndRotation(EControllerHand DeviceHand,float PredictedTime, FVector& OutLocation,FRotator &OutRotation);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRInput")
	static int  PXR_SetControllerEnableKey(bool isEnable, EPxrControllerKeyMap Key);

};
