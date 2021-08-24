// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoNeoControllerBPlib.h"
#include "PicoNeoControllerPrivatePCH.h"
#include "PicoNeoControllerJni.h"

FDelegateWithoutParam UPicoNeoControllerBPlib::NativeTreadStart;

FDelegateWithoutParam UPicoNeoControllerBPlib::MainControllerConnect;
FDelegateWithoutParam UPicoNeoControllerBPlib::MainControllerDisconnect;
FDelegateWithoutParam UPicoNeoControllerBPlib::SubControllerConnect;
FDelegateWithoutParam UPicoNeoControllerBPlib::SubControllerDisconnect;

int32 UPicoNeoControllerBPlib::GetNeoDeviceType()
{
#if PLATFORM_ANDROID
	return FPicoNeoControllerJni::GetInstance()->GetNeoDeviceType();
#endif
	return 0;
}

bool UPicoNeoControllerBPlib::IsMainControllerConnect()
{
#if PLATFORM_ANDROID
	return (bool)(FPicoNeoControllerJni::GetInstance()->GetMainControllerConnectState());
#endif
	return false;
}

bool UPicoNeoControllerBPlib::IsSubControllerConnect()
{
#if PLATFORM_ANDROID
	return (bool)(FPicoNeoControllerJni::GetInstance()->GetSubControllerConnectState());
#endif
	return false;
}

bool UPicoNeoControllerBPlib::IsMainControllerSupport6Dof()
{
#if PLATFORM_ANDROID
	int32 abilityIndex = -1;
	abilityIndex = FPicoNeoControllerJni::GetInstance()->GetMainController6DofAbility();
	if (2 == abilityIndex)
	{
		return true;
	}
	else
	{
		return false;
	}
#endif
	return false;
}

bool UPicoNeoControllerBPlib::IsSubControllerSupport6Dof()
{
#if PLATFORM_ANDROID
	int32 abilityIndex = -1;
	abilityIndex = FPicoNeoControllerJni::GetInstance()->GetSubController6DofAbility();
	if (2 == abilityIndex)
	{
		return true;
	}
	else
	{
		return false;
	}
#endif
	return false;
}

int32 UPicoNeoControllerBPlib::GetMainControllerBatteryLevel()
{
#if PLATFORM_ANDROID
	return FPicoNeoControllerJni::GetInstance()->GetMainControllerBatteryLevel();
#endif
	return 0;
}

int32 UPicoNeoControllerBPlib::GetSubControllerBatteryLevel()
{
#if PLATFORM_ANDROID
	return FPicoNeoControllerJni::GetInstance()->GetSubControllerBatteryLevel();
#endif
	return 0;
}

void UPicoNeoControllerBPlib::SetNativeTreadStartDelegate(FDelegateWithoutParam OnNativeTreadStart)
{
#if PLATFORM_ANDROID
	NativeTreadStart = OnNativeTreadStart;
#endif
}

void UPicoNeoControllerBPlib::SetControllerConnectedStatusDelegate(
	FDelegateWithoutParam OnMainControllerConnect, 
	FDelegateWithoutParam OnMainControllerDisconnect, 
	FDelegateWithoutParam OnSubControllerConnect, 
	FDelegateWithoutParam OnSubControllerDisconnect)
{
#if PLATFORM_ANDROID
	MainControllerConnect = OnMainControllerConnect;
	MainControllerDisconnect = OnMainControllerDisconnect;
	SubControllerConnect = OnSubControllerConnect;
	SubControllerDisconnect = OnSubControllerDisconnect;
#endif
}

void UPicoNeoControllerBPlib::PicoGetLeftControllerAcc(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetMainControllerAcc(value);
#endif
}

void UPicoNeoControllerBPlib::PicoGetRightControllerAcc(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetSubControllerAcc(value);
#endif
}

void UPicoNeoControllerBPlib::PicoGetLeftControllerAgl(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetMainControllerAgl(value);
#endif
}

void UPicoNeoControllerBPlib::PicoGetRightControllerAgl(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetSubControllerAgl(value);
#endif
}

void UPicoNeoControllerBPlib::PicoGetLeftControllerLvc(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetLeftControllerLvc(value);
#endif
}

void UPicoNeoControllerBPlib::PicoGetRightControllerLvc(FVector& value)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->GetRightControllerLvc(value);
#endif
}

void UPicoNeoControllerBPlib::PicoShakeMainController() 
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->ShakeMainController();
#endif
}

void UPicoNeoControllerBPlib::PicoShakeSubController()
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->ShakeSubController();
#endif
}

void UPicoNeoControllerBPlib::PicoShakeCV2Controller(float strength, int32 time, int32 hand)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->ShakeCV2Controller(strength, time, hand);
#endif
}

void UPicoNeoControllerBPlib::PicoMainControllerSetArmModel(EPicoNeoArmModelJoint inArmJoint, ENeoGazeBehavior inGazeType, float inEHeight, float inEDepth, float inPointerTiltAngle)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->SetMainArmJoint((int32)inArmJoint);
	FPicoNeoControllerJni::GetInstance()->SetMainGazeType((int32)inGazeType);
	FPicoNeoControllerJni::GetInstance()->SetMainArmModelParm(FMath::Clamp(inEHeight, 0.0f, 0.2f), FMath::Clamp(inEDepth, 0.0f, 0.2f), FMath::Clamp(inPointerTiltAngle, 0.0f, 30.0f));
#endif
}

void UPicoNeoControllerBPlib::PicoSubControllerSetArmModel(EPicoNeoArmModelJoint inArmJoint, ENeoGazeBehavior inGazeType, float inEHeight, float inEDepth, float inPointerTiltAngle)
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->SetSubArmJoint((int32)inArmJoint);
	FPicoNeoControllerJni::GetInstance()->SetSubGazeType((int32)inGazeType);
	FPicoNeoControllerJni::GetInstance()->SetSubArmModelParm(FMath::Clamp(inEHeight, 0.0f, 0.2f), FMath::Clamp(inEDepth, 0.0f, 0.2f), FMath::Clamp(inPointerTiltAngle, 0.0f, 30.0f));
#endif
}

void UPicoNeoControllerBPlib::PicoMainControllerGetArmModel(EPicoNeoArmModelJoint & outArmJoint, ENeoGazeBehavior & outGazeType, float & outEHeight, float & outEDepth, float & outPointerTiltAngle)
{
#if PLATFORM_ANDROID
	int32 retAJ= -1;
	retAJ = FPicoNeoControllerJni::GetInstance()->GetMainArmJoint();
	switch (retAJ)
	{
	case 0:
		outArmJoint = EPicoNeoArmModelJoint::Controller;
		break;
	case 1:
		outArmJoint = EPicoNeoArmModelJoint::Wrist;
		break;
	case 2:
		outArmJoint = EPicoNeoArmModelJoint::Elbow;
		break;
	case 3:
		outArmJoint = EPicoNeoArmModelJoint::Shoulder;
		break;
	}

	int32 retGT = -1;
	retGT = FPicoNeoControllerJni::GetInstance()->GetMainGazeType();
	switch (retGT)
	{
	case 0:
		outGazeType = ENeoGazeBehavior::Never;
		break;
	case 1:
		outGazeType = ENeoGazeBehavior::DuringMotion;
		break;
	case 2:
		outGazeType = ENeoGazeBehavior::Always;
		break;
	}

	FVector parm = FVector::ZeroVector;
	FPicoNeoControllerJni::GetInstance()->GetMainArmModelParm(parm);
	outEHeight = parm.X;
	outEDepth = parm.Y;
	outPointerTiltAngle = parm.Z;
#endif
}

void UPicoNeoControllerBPlib::PicoSubControllerGetArmModel(EPicoNeoArmModelJoint & outArmJoint, ENeoGazeBehavior & outGazeType, float & outEHeight, float & outEDepth, float & outPointerTiltAngle)
{
#if PLATFORM_ANDROID
	int32 retAJ = -1;
	retAJ = FPicoNeoControllerJni::GetInstance()->GetSubArmJoint();
	switch (retAJ)
	{
	case 0:
		outArmJoint = EPicoNeoArmModelJoint::Controller;
		break;
	case 1:
		outArmJoint = EPicoNeoArmModelJoint::Wrist;
		break;
	case 2:
		outArmJoint = EPicoNeoArmModelJoint::Elbow;
		break;
	case 3:
		outArmJoint = EPicoNeoArmModelJoint::Shoulder;
		break;
	}

	int32 retGT = -1;
	retGT = FPicoNeoControllerJni::GetInstance()->GetSubGazeType();
	switch (retGT)
	{
	case 0:
		outGazeType = ENeoGazeBehavior::Never;
		break;
	case 1:
		outGazeType = ENeoGazeBehavior::DuringMotion;
		break;
	case 2:
		outGazeType = ENeoGazeBehavior::Always;
		break;
	}

	FVector parm = FVector::ZeroVector;
	FPicoNeoControllerJni::GetInstance()->GetSubArmModelParm(parm);
	outEHeight = parm.X;
	outEDepth = parm.Y;
	outPointerTiltAngle = parm.Z;
#endif
}

void UPicoNeoControllerBPlib::PicoGetMainControllerValue(int32& value)
{
#if PLATFORM_ANDROID
	value = FPicoNeoControllerJni::GetInstance()->GetMainControllerValue();
#endif
}
