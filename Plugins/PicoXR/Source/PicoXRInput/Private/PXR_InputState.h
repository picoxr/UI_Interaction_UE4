//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

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

	static const FName PICOHand_Left_ThumbClick;
	static const FName PICOHand_Left_IndexPinch;
	static const FName PICOHand_Left_MiddlePinch;
	static const FName PICOHand_Left_RingPinch;
	static const FName PICOHand_Left_PinkyPinch;

	static const FName PICOHand_Right_ThumbClick;
	static const FName PICOHand_Right_IndexPinch;
	static const FName PICOHand_Right_MiddlePinch;
	static const FName PICOHand_Right_RingPinch;
	static const FName PICOHand_Right_PinkyPinch;

	static const FName PICOHand_Left_SystemGesture;
	static const FName PICOHand_Right_SystemGesture;

	static const FName PICOHand_Left_ThumbClickStrength;
	static const FName PICOHand_Left_IndexPinchStrength;
	static const FName PICOHand_Left_MiddlePinchStrength;
	static const FName PICOHand_Left_RingPinchStrength;
	static const FName PICOHand_Left_PinkyPinchStrength;
	
	static const FName PICOHand_Right_ThumbClickStrength;
	static const FName PICOHand_Right_IndexPinchStrength;
	static const FName PICOHand_Right_MiddlePinchStrength;
	static const FName PICOHand_Right_RingPinchStrength;
	static const FName PICOHand_Right_PinkyPinchStrength;
};

struct FPICOTouchKey
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

	static const FKey PICOHand_Left_ThumbClick;
	static const FKey PICOHand_Left_IndexPinch;
	static const FKey PICOHand_Left_MiddlePinch;
	static const FKey PICOHand_Left_RingPinch;
	static const FKey PICOHand_Left_PinkyPinch;

	static const FKey PICOHand_Right_ThumbClick;
	static const FKey PICOHand_Right_IndexPinch;
	static const FKey PICOHand_Right_MiddlePinch;
	static const FKey PICOHand_Right_RingPinch;
	static const FKey PICOHand_Right_PinkyPinch;

	static const FKey PICOHand_Left_SystemGesture;
	static const FKey PICOHand_Right_SystemGesture;

	static const FKey PICOHand_Left_ThumbClickStrength;
	static const FKey PICOHand_Left_IndexPinchStrength;
	static const FKey PICOHand_Left_MiddlePinchStrength;
	static const FKey PICOHand_Left_RingPinchStrength;
	static const FKey PICOHand_Left_PinkyPinchStrength;

	static const FKey PICOHand_Right_ThumbClickStrength;
	static const FKey PICOHand_Right_IndexPinchStrength;
	static const FKey PICOHand_Right_MiddlePinchStrength;
	static const FKey PICOHand_Right_RingPinchStrength;
	static const FKey PICOHand_Right_PinkyPinchStrength;
	
};
