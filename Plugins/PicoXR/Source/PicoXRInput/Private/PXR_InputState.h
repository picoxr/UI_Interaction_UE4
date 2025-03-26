// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "IInputDevice.h"

struct FPICOKeyNames
{
	typedef FName Type;

	static const FName PICOTouch_Left_X_Click;
	static const FName PICOTouch_Left_Y_Click;
	static const FName PICOTouch_Left_Menu_Click;
	static const FName PICOTouch_Left_Grip_Click;
	static const FName PICOTouch_Left_Home_Click;
	static const FName PICOTouch_Left_Trigger_Click;
	static const FName PICOTouch_Left_VolumeUp_Click;
	static const FName PICOTouch_Left_VolumeDown_Click;
	static const FName PICOTouch_Left_Thumbstick_Click;
	
	static const FName PICOTouch_Left_Grip_Axis;
	static const FName PICOTouch_Left_Trigger_Axis;
	static const FName PICOTouch_Left_Thumbstick_X;
	static const FName PICOTouch_Left_Thumbstick_Y;
	
	static const FName PICOTouch_Left_X_Touch;
	static const FName PICOTouch_Left_Y_Touch;
	static const FName PICOTouch_Left_Trigger_Touch;
	static const FName PICOTouch_Left_Thumbrest_Touch;
	static const FName PICOTouch_Left_Thumbstick_Touch;

	static const FName PICOTouch_Left_Thumbstick_Up;
	static const FName PICOTouch_Left_Thumbstick_Down;
	static const FName PICOTouch_Left_Thumbstick_Left;
	static const FName PICOTouch_Left_Thumbstick_Right;
	
	static const FName PICOTouch_Right_A_Click;
	static const FName PICOTouch_Right_B_Click;
	static const FName PICOTouch_Right_System_Click;
	static const FName PICOTouch_Right_Grip_Click;
	static const FName PICOTouch_Right_Home_Click;
	static const FName PICOTouch_Right_Trigger_Click;
	static const FName PICOTouch_Right_VolumeUp_Click;
	static const FName PICOTouch_Right_VolumeDown_Click;
	static const FName PICOTouch_Right_Thumbstick_Click;
	
	
	static const FName PICOTouch_Right_Grip_Axis;
	static const FName PICOTouch_Right_Trigger_Axis;
	static const FName PICOTouch_Right_Thumbstick_X;
	static const FName PICOTouch_Right_Thumbstick_Y;
	
	static const FName PICOTouch_Right_A_Touch;
	static const FName PICOTouch_Right_B_Touch;
	static const FName PICOTouch_Right_Trigger_Touch;
	static const FName PICOTouch_Right_Thumbrest_Touch;
	static const FName PICOTouch_Right_Thumbstick_Touch;

	static const FName PICOTouch_Right_Thumbstick_Up;
	static const FName PICOTouch_Right_Thumbstick_Down;
	static const FName PICOTouch_Right_Thumbstick_Left;
	static const FName PICOTouch_Right_Thumbstick_Right;

	static const FName PICOHand_Left_Pinch;
	static const FName PICOHand_Right_Pinch;

	static const FName PICOHand_Left_PinchStrength;
	static const FName PICOHand_Right_PinchStrength;
};

struct PICOXRINPUT_API FPICOTouchKey
{
	// PICO Touch Controller
	static const FKey PICOTouch_Left_X_Click;
	static const FKey PICOTouch_Left_Y_Click;
	static const FKey PICOTouch_Left_Menu_Click;
	static const FKey PICOTouch_Left_Grip_Click;
	static const FKey PICOTouch_Left_Home_Click;
	static const FKey PICOTouch_Left_Trigger_Click;
	static const FKey PICOTouch_Left_VolumeUp_Click;
	static const FKey PICOTouch_Left_VolumeDown_Click;
	static const FKey PICOTouch_Left_Thumbstick_Click;
	
	static const FKey PICOTouch_Left_Grip_Axis;
	static const FKey PICOTouch_Left_Trigger_Axis;
	static const FKey PICOTouch_Left_Thumbstick_X;
	static const FKey PICOTouch_Left_Thumbstick_Y;
	
	static const FKey PICOTouch_Left_X_Touch;
	static const FKey PICOTouch_Left_Y_Touch;
	static const FKey PICOTouch_Left_Trigger_Touch;
	static const FKey PICOTouch_Left_Thumbrest_Touch;
	static const FKey PICOTouch_Left_Thumbstick_Touch;

	static const FKey PICOTouch_Left_Thumbstick_Up;
	static const FKey PICOTouch_Left_Thumbstick_Down;
	static const FKey PICOTouch_Left_Thumbstick_Left;
	static const FKey PICOTouch_Left_Thumbstick_Right;
	
	static const FKey PICOTouch_Right_A_Click;
	static const FKey PICOTouch_Right_B_Click;
	static const FKey PICOTouch_Right_System_Click;
	static const FKey PICOTouch_Right_Grip_Click;
	static const FKey PICOTouch_Right_Home_Click;
	static const FKey PICOTouch_Right_Trigger_Click;
	static const FKey PICOTouch_Right_VolumeUp_Click;
	static const FKey PICOTouch_Right_VolumeDown_Click;
	static const FKey PICOTouch_Right_Thumbstick_Click;
	
	static const FKey PICOTouch_Right_Grip_Axis;
	static const FKey PICOTouch_Right_Trigger_Axis;
	static const FKey PICOTouch_Right_Thumbstick_X;
	static const FKey PICOTouch_Right_Thumbstick_Y;
	
	static const FKey PICOTouch_Right_A_Touch;
	static const FKey PICOTouch_Right_B_Touch;
	static const FKey PICOTouch_Right_Trigger_Touch;
	static const FKey PICOTouch_Right_Thumbrest_Touch;
	static const FKey PICOTouch_Right_Thumbstick_Touch;

	static const FKey PICOTouch_Right_Thumbstick_Up;
	static const FKey PICOTouch_Right_Thumbstick_Down;
	static const FKey PICOTouch_Right_Thumbstick_Left;
	static const FKey PICOTouch_Right_Thumbstick_Right;

	static const FKey PICOHand_Left_Pinch;
	static const FKey PICOHand_Right_Pinch;
	
	static const FKey PICOHand_Left_PinchStrength;
	static const FKey PICOHand_Right_PinchStrength;
	
};
