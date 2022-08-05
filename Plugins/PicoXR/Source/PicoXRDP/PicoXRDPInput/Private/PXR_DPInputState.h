//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "InputDevice.h"
#if WITH_EDITOR
struct FPicoKeyNames
{
	typedef FName Type;

	static const FName PicoTouch_Left_X_Click;
	static const FName PicoTouch_Left_Y_Click;
	static const FName PicoTouch_Left_Menu_Click;
	static const FName PicoTouch_Left_Grip_Click;
	static const FName PicoTouch_Left_Home_Click;
	static const FName PicoTouch_Left_Trigger_Click;
	static const FName PicoTouch_Left_VolumeUp_Click;
	static const FName PicoTouch_Left_VolumeDown_Click;
	static const FName PicoTouch_Left_Thumbstick_Click;
	
	static const FName PicoTouch_Left_Grip_Axis;
	static const FName PicoTouch_Left_Trigger_Axis;
	static const FName PicoTouch_Left_Thumbstick_X;
	static const FName PicoTouch_Left_Thumbstick_Y;
	
	static const FName PicoTouch_Left_X_Touch;
	static const FName PicoTouch_Left_Y_Touch;
	static const FName PicoTouch_Left_Trigger_Touch;
	static const FName PicoTouch_Left_Thumbrest_Touch;
	static const FName PicoTouch_Left_Thumbstick_Touch;

	static const FName PicoTouch_Left_Thumbstick_Up;
	static const FName PicoTouch_Left_Thumbstick_Down;
	static const FName PicoTouch_Left_Thumbstick_Left;
	static const FName PicoTouch_Left_Thumbstick_Right;
	
	static const FName PicoTouch_Right_A_Click;
	static const FName PicoTouch_Right_B_Click;
	static const FName PicoTouch_Right_System_Click;
	static const FName PicoTouch_Right_Grip_Click;
	static const FName PicoTouch_Right_Home_Click;
	static const FName PicoTouch_Right_Trigger_Click;
	static const FName PicoTouch_Right_VolumeUp_Click;
	static const FName PicoTouch_Right_VolumeDown_Click;
	static const FName PicoTouch_Right_Thumbstick_Click;
	
	
	static const FName PicoTouch_Right_Grip_Axis;
	static const FName PicoTouch_Right_Trigger_Axis;
	static const FName PicoTouch_Right_Thumbstick_X;
	static const FName PicoTouch_Right_Thumbstick_Y;
	
	static const FName PicoTouch_Right_A_Touch;
	static const FName PicoTouch_Right_B_Touch;
	static const FName PicoTouch_Right_Trigger_Touch;
	static const FName PicoTouch_Right_Thumbrest_Touch;
	static const FName PicoTouch_Right_Thumbstick_Touch;

	static const FName PicoTouch_Right_Thumbstick_Up;
	static const FName PicoTouch_Right_Thumbstick_Down;
	static const FName PicoTouch_Right_Thumbstick_Left;
	static const FName PicoTouch_Right_Thumbstick_Right;

};

struct FPicoTouchKey
{
	// Pico Touch Controller
	static const FKey PicoTouch_Left_X_Click;
	static const FKey PicoTouch_Left_Y_Click;
	static const FKey PicoTouch_Left_Menu_Click;
	static const FKey PicoTouch_Left_Grip_Click;
	static const FKey PicoTouch_Left_Home_Click;
	static const FKey PicoTouch_Left_Trigger_Click;
	static const FKey PicoTouch_Left_VolumeUp_Click;
	static const FKey PicoTouch_Left_VolumeDown_Click;
	static const FKey PicoTouch_Left_Thumbstick_Click;
	
	static const FKey PicoTouch_Left_Grip_Axis;
	static const FKey PicoTouch_Left_Trigger_Axis;
	static const FKey PicoTouch_Left_Thumbstick_X;
	static const FKey PicoTouch_Left_Thumbstick_Y;
	
	static const FKey PicoTouch_Left_X_Touch;
	static const FKey PicoTouch_Left_Y_Touch;
	static const FKey PicoTouch_Left_Trigger_Touch;
	static const FKey PicoTouch_Left_Thumbrest_Touch;
	static const FKey PicoTouch_Left_Thumbstick_Touch;

	static const FKey PicoTouch_Left_Thumbstick_Up;
	static const FKey PicoTouch_Left_Thumbstick_Down;
	static const FKey PicoTouch_Left_Thumbstick_Left;
	static const FKey PicoTouch_Left_Thumbstick_Right;
	
	static const FKey PicoTouch_Right_A_Click;
	static const FKey PicoTouch_Right_B_Click;
	static const FKey PicoTouch_Right_System_Click;
	static const FKey PicoTouch_Right_Grip_Click;
	static const FKey PicoTouch_Right_Home_Click;
	static const FKey PicoTouch_Right_Trigger_Click;
	static const FKey PicoTouch_Right_VolumeUp_Click;
	static const FKey PicoTouch_Right_VolumeDown_Click;
	static const FKey PicoTouch_Right_Thumbstick_Click;
	
	static const FKey PicoTouch_Right_Grip_Axis;
	static const FKey PicoTouch_Right_Trigger_Axis;
	static const FKey PicoTouch_Right_Thumbstick_X;
	static const FKey PicoTouch_Right_Thumbstick_Y;
	
	static const FKey PicoTouch_Right_A_Touch;
	static const FKey PicoTouch_Right_B_Touch;
	static const FKey PicoTouch_Right_Trigger_Touch;
	static const FKey PicoTouch_Right_Thumbrest_Touch;
	static const FKey PicoTouch_Right_Thumbstick_Touch;

	static const FKey PicoTouch_Right_Thumbstick_Up;
	static const FKey PicoTouch_Right_Thumbstick_Down;
	static const FKey PicoTouch_Right_Thumbstick_Left;
	static const FKey PicoTouch_Right_Thumbstick_Right;
	
};
#endif