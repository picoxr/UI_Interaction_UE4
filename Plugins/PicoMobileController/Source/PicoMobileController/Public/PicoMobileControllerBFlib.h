// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PicoMobileControllerBFlib.generated.h"

DECLARE_DYNAMIC_DELEGATE(FDelegateWithoutParam);

UENUM(BlueprintType)
enum class EPicoArmModelJoint : uint8
{
	Controller = 0,
	Wrist = 1,
	Elbow = 2,
	Shoulder = 3
};
UENUM(BlueprintType)
enum class EGazeBehavior : uint8
{
	Never = 0,
	DuringMotion = 1,
	Always = 2,
};

UCLASS()
class PICOMOBILECONTROLLER_API UPicoMobileControllerBFlib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static bool IsPicoControllerAvailable();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 GetDeviceType();

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void GetPicoControllerOrientationAndPosition(
			FRotator& OutOrientation,
			FVector& OutPosition
		);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static int32 PicoGetControllerBatteryLevel();

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSetGazeType(EGazeBehavior NewGazeType);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoGetGazeType(EGazeBehavior& OutGazeType);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSetElbowHeight(float NewHeight);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoGetElbowHeight(float& OutHeight);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSetElbowDepth(float NewDepth);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoGetElbowDepth(float& OutDepth);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoGetPointerTiltAngle(float& OutPointerTiltAngle);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSetPointerTiltAngle(float NewPointerTiltAngle);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoChooseArmModelJoint(EPicoArmModelJoint chosenArmJoint);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoGetArmModelJoint(EPicoArmModelJoint& OutArmJoint);

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSwitchArmModelJoint();

	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static void PicoSetControllerConnectedStatusChangedDelegate(
			FDelegateWithoutParam OnPicoControllerConnected,
			FDelegateWithoutParam OnPicoControllerDisconnected);
public:
	static FDelegateWithoutParam PicoControllerConnected;
	static FDelegateWithoutParam PicoControllerDisconnected;

public:
	UFUNCTION(BlueprintCallable, Category = "Pico Goblin|Controller")
		static bool PicoResetG1Controller();
};
