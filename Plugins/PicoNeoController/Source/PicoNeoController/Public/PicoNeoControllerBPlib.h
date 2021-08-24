// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PicoNeoControllerBPlib.generated.h"

DECLARE_DYNAMIC_DELEGATE(FDelegateWithoutParam);

UENUM(BlueprintType)
enum class EPicoNeoArmModelJoint : uint8
{
	Controller = 0,
	Wrist = 1,
	Elbow = 2,
	Shoulder = 3
};
UENUM(BlueprintType)
enum class ENeoGazeBehavior : uint8
{
	Never = 0,
	DuringMotion = 1,
	Always = 2,
};

UCLASS()
class PICONEOCONTROLLER_API UPicoNeoControllerBPlib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static int32 GetNeoDeviceType();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static bool IsMainControllerConnect();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static bool IsSubControllerConnect();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static bool IsMainControllerSupport6Dof();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static bool IsSubControllerSupport6Dof();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static int32 GetMainControllerBatteryLevel();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static int32 GetSubControllerBatteryLevel();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void SetNativeTreadStartDelegate(FDelegateWithoutParam OnNativeTreadStart);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void SetControllerConnectedStatusDelegate(
			FDelegateWithoutParam OnMainControllerConnect,
			FDelegateWithoutParam OnMainControllerDisconnect, 
			FDelegateWithoutParam OnSubControllerConnect,
			FDelegateWithoutParam OnSubControllerDisconnect);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetLeftControllerAcc(FVector& value);
	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetRightControllerAcc(FVector& value);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetLeftControllerAgl(FVector& value);
	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetRightControllerAgl(FVector& value);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetLeftControllerLvc(FVector& value);
	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetRightControllerLvc(FVector& value);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoShakeMainController();
	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoShakeSubController();

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoShakeCV2Controller(float strength, int32 time, int32 hand);

	UFUNCTION(BlueprintCallable, meta = (inArmJoint = "Controller", inGazeType = "DuringMotion", inEHeight = "0.0", inEDepth = "0.0", inPointerTiltAngle = "15.0"), Category = "Pico Neo|Controller")
		static void PicoMainControllerSetArmModel(EPicoNeoArmModelJoint inArmJoint, ENeoGazeBehavior inGazeType, float inEHeight, float inEDepth, float inPointerTiltAngle);

	UFUNCTION(BlueprintCallable, meta = (inArmJoint = "Controller", inGazeType = "DuringMotion", inEHeight = "0.0", inEDepth = "0.0", inPointerTiltAngle = "15.0"), Category = "Pico Neo|Controller")
		static void PicoSubControllerSetArmModel(EPicoNeoArmModelJoint inArmJoint, ENeoGazeBehavior inGazeType, float inEHeight, float inEDepth, float inPointerTiltAngle);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoMainControllerGetArmModel(EPicoNeoArmModelJoint & outArmJoint, ENeoGazeBehavior & outGazeType, float & outEHeight, float & outEDepth, float & outPointerTiltAngle);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoSubControllerGetArmModel(EPicoNeoArmModelJoint & outArmJoint, ENeoGazeBehavior & outGazeType, float & outEHeight, float & outEDepth, float & outPointerTiltAngle);

	UFUNCTION(BlueprintCallable, Category = "Pico Neo|Controller")
		static void PicoGetMainControllerValue(int32& value);

public:
	static FDelegateWithoutParam NativeTreadStart;
	static FDelegateWithoutParam MainControllerConnect;
	static FDelegateWithoutParam MainControllerDisconnect;
	static FDelegateWithoutParam SubControllerConnect;
	static FDelegateWithoutParam SubControllerDisconnect;
};
