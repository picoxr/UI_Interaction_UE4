// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "InputDevice.h"

struct FPicoNeoKeyNames
{
	typedef FName Type;

	static const FName PicoNeoController_Main_Home;
	static const FName PicoNeoController_Main_App;
	static const FName PicoNeoController_Main_Touchpad;
	static const FName PicoNeoController_Main_Volume_Up;
	static const FName PicoNeoController_Main_Volume_Down;
	static const FName PicoNeoController_Main_Trigger;
	static const FName PicoNeoController_Main_TriggerAxis;
	static const FName PicoNeoController_Main_TouchX;
	static const FName PicoNeoController_Main_TouchY;

	static const FName PicoNeoController_Main_TouchUp;
	static const FName PicoNeoController_Main_TouchDown;
	static const FName PicoNeoController_Main_TouchLeft;
	static const FName PicoNeoController_Main_TouchRight;

	static const FName PicoNeoController_Main_TouchClickUp;
	static const FName PicoNeoController_Main_TouchClickDown;
	static const FName PicoNeoController_Main_TouchClickLeft;
	static const FName PicoNeoController_Main_TouchClickRight;


	static const FName PicoNeoController_L_Home;
	static const FName PicoNeoController_L_App;
	static const FName PicoNeoController_L_RockerC;
	static const FName PicoNeoController_L_X;
	static const FName PicoNeoController_L_Y;
	static const FName PicoNeoController_L_TriggerAxis;
	static const FName PicoNeoController_L_Trigger;
	static const FName PicoNeoController_L_RockerX;
	static const FName PicoNeoController_L_RockerY;
	static const FName PicoNeoController_L_LGrip;
	static const FName PicoNeoController_L_RGrip;

	static const FName PicoNeoController_L_RockerUp;
	static const FName PicoNeoController_L_RockerDown;
	static const FName PicoNeoController_L_RockerLeft;
	static const FName PicoNeoController_L_RockerRight;

	static const FName PicoNeoController_L_RockerClickUp;
	static const FName PicoNeoController_L_RockerClickDown;
	static const FName PicoNeoController_L_RockerClickLeft;
	static const FName PicoNeoController_L_RockerClickRight;

	static const FName PicoNeoController_Sub_Home;
	static const FName PicoNeoController_Sub_App;
	static const FName PicoNeoController_Sub_Touchpad;
	static const FName PicoNeoController_Sub_Volume_Up;
	static const FName PicoNeoController_Sub_Volume_Down;
	static const FName PicoNeoController_Sub_Trigger;
	static const FName PicoNeoController_Sub_TriggerAxis;
	static const FName PicoNeoController_Sub_TouchX;
	static const FName PicoNeoController_Sub_TouchY;

	static const FName PicoNeoController_Sub_TouchUp;
	static const FName PicoNeoController_Sub_TouchDown;
	static const FName PicoNeoController_Sub_TouchLeft;
	static const FName PicoNeoController_Sub_TouchRight;

	static const FName PicoNeoController_Sub_TouchClickUp;
	static const FName PicoNeoController_Sub_TouchClickDown;
	static const FName PicoNeoController_Sub_TouchClickLeft;
	static const FName PicoNeoController_Sub_TouchClickRight;

	static const FName PicoNeoController_R_Home;
	static const FName PicoNeoController_R_App;
	static const FName PicoNeoController_R_RockerC;
	static const FName PicoNeoController_R_A;
	static const FName PicoNeoController_R_B;
	static const FName PicoNeoController_R_Trigger;
	static const FName PicoNeoController_R_TriggerAxis;
	static const FName PicoNeoController_R_RockerX;
	static const FName PicoNeoController_R_RockerY;
	static const FName PicoNeoController_R_LGrip;
	static const FName PicoNeoController_R_RGrip;

	static const FName PicoNeoController_R_RockerUp;
	static const FName PicoNeoController_R_RockerDown;
	static const FName PicoNeoController_R_RockerLeft;
	static const FName PicoNeoController_R_RockerRight;

	static const FName PicoNeoController_R_RockerClickUp;
	static const FName PicoNeoController_R_RockerClickDown;
	static const FName PicoNeoController_R_RockerClickLeft;
	static const FName PicoNeoController_R_RockerClickRight;
	//ShortPress
	static const FName PicoNeoController_Main_Home_ShortPress;
	static const FName PicoNeoController_Main_App_ShortPress;
	static const FName PicoNeoController_Main_Touchpad_ShortPress;
	static const FName PicoNeoController_Main_Volume_Up_ShortPress;
	static const FName PicoNeoController_Main_Volume_Down_ShortPress;
	static const FName PicoNeoController_Main_Trigger_ShortPress;

	static const FName PicoNeoController_L_Home_ShortPress;
	static const FName PicoNeoController_L_App_ShortPress;
	static const FName PicoNeoController_L_RockerC_ShortPress;
	static const FName PicoNeoController_L_X_ShortPress;
	static const FName PicoNeoController_L_Y_ShortPress;
	static const FName PicoNeoController_L_Trigger_ShortPress;
	static const FName PicoNeoController_L_LGrip_ShortPress;
	static const FName PicoNeoController_L_RGrip_ShortPress;

	static const FName PicoNeoController_Sub_Home_ShortPress;
	static const FName PicoNeoController_Sub_App_ShortPress;
	static const FName PicoNeoController_Sub_Touchpad_ShortPress;
	static const FName PicoNeoController_Sub_Volume_Up_ShortPress;
	static const FName PicoNeoController_Sub_Volume_Down_ShortPress;
	static const FName PicoNeoController_Sub_Trigger_ShortPress;

	static const FName PicoNeoController_R_Home_ShortPress;
	static const FName PicoNeoController_R_App_ShortPress;
	static const FName PicoNeoController_R_RockerC_ShortPress;
	static const FName PicoNeoController_R_A_ShortPress;
	static const FName PicoNeoController_R_B_ShortPress;
	static const FName PicoNeoController_R_Trigger_ShortPress;
	static const FName PicoNeoController_R_LGrip_ShortPress;
	static const FName PicoNeoController_R_RGrip_ShortPress;

	//LongPress
	static const FName PicoNeoController_Main_Home_LongPress;
	static const FName PicoNeoController_Main_App_LongPress;
	static const FName PicoNeoController_Main_Touchpad_LongPress;
	static const FName PicoNeoController_Main_Volume_Up_LongPress;
	static const FName PicoNeoController_Main_Volume_Down_LongPress;
	static const FName PicoNeoController_Main_Trigger_LongPress;

	static const FName PicoNeoController_L_Home_LongPress;
	static const FName PicoNeoController_L_App_LongPress;
	static const FName PicoNeoController_L_RockerC_LongPress;
	static const FName PicoNeoController_L_X_LongPress;
	static const FName PicoNeoController_L_Y_LongPress;
	static const FName PicoNeoController_L_Trigger_LongPress;
	static const FName PicoNeoController_L_LGrip_LongPress;
	static const FName PicoNeoController_L_RGrip_LongPress;

	static const FName PicoNeoController_Sub_Home_LongPress;
	static const FName PicoNeoController_Sub_App_LongPress;
	static const FName PicoNeoController_Sub_Touchpad_LongPress;
	static const FName PicoNeoController_Sub_Volume_Up_LongPress;
	static const FName PicoNeoController_Sub_Volume_Down_LongPress;
	static const FName PicoNeoController_Sub_Trigger_LongPress;

	static const FName PicoNeoController_R_Home_LongPress;
	static const FName PicoNeoController_R_App_LongPress;
	static const FName PicoNeoController_R_RockerC_LongPress;
	static const FName PicoNeoController_R_A_LongPress;
	static const FName PicoNeoController_R_B_LongPress;
	static const FName PicoNeoController_R_Trigger_LongPress;
	static const FName PicoNeoController_R_LGrip_LongPress;
	static const FName PicoNeoController_R_RGrip_LongPress;


	//Add For Neo3
	static const FName PicoNeoController_L_Rocker_CapTouch;
	static const FName PicoNeoController_L_X_CapTouch;
	static const FName PicoNeoController_L_Y_CapTouch;
	static const FName PicoNeoController_L_Thumbrest;
	static const FName PicoNeoController_L_Trigger_CapTouch;
	static const FName PicoNeoController_L_Grip_Axis;
	
	static const FName PicoNeoController_R_Rocker_CapTouch;
	static const FName PicoNeoController_R_A_CapTouch;
	static const FName PicoNeoController_R_B_CapTouch;
	static const FName PicoNeoController_R_Thumbrest;
	static const FName PicoNeoController_R_Trigger_CapTouch;
	static const FName PicoNeoController_R_Grip_Axis;
};

struct FPicoNeoControllerKey
{
	//Simple State
	static const FKey PicoNeoController_Main_Home;
	static const FKey PicoNeoController_Main_App;
	static const FKey PicoNeoController_Main_Touchpad;
	static const FKey PicoNeoController_Main_Volume_Up;
	static const FKey PicoNeoController_Main_Volume_Down;
	static const FKey PicoNeoController_Main_Trigger;
	static const FKey PicoNeoController_Main_TriggerAxis;
	static const FKey PicoNeoController_Main_TouchX;
	static const FKey PicoNeoController_Main_TouchY;

	static const FKey PicoNeoController_Main_TouchUp;
	static const FKey PicoNeoController_Main_TouchDown;
	static const FKey PicoNeoController_Main_TouchLeft;
	static const FKey PicoNeoController_Main_TouchRight;

	static const FKey PicoNeoController_Main_TouchClickUp;
	static const FKey PicoNeoController_Main_TouchClickDown;
	static const FKey PicoNeoController_Main_TouchClickLeft;
	static const FKey PicoNeoController_Main_TouchClickRight;

	static const FKey PicoNeoController_L_Home;
	static const FKey PicoNeoController_L_App;
	static const FKey PicoNeoController_L_RockerC;
	static const FKey PicoNeoController_L_X;
	static const FKey PicoNeoController_L_Y;
	static const FKey PicoNeoController_L_Trigger;
	static const FKey PicoNeoController_L_TriggerAxis;
	static const FKey PicoNeoController_L_RockerX;
	static const FKey PicoNeoController_L_RockerY;
	static const FKey PicoNeoController_L_LGrip;
	static const FKey PicoNeoController_L_RGrip;

	static const FKey PicoNeoController_L_RockerUp;
	static const FKey PicoNeoController_L_RockerDown;
	static const FKey PicoNeoController_L_RockerLeft;
	static const FKey PicoNeoController_L_RockerRight;

	static const FKey PicoNeoController_L_RockerClickUp;
	static const FKey PicoNeoController_L_RockerClickDown;
	static const FKey PicoNeoController_L_RockerClickLeft;
	static const FKey PicoNeoController_L_RockerClickRight;

	static const FKey PicoNeoController_Sub_Home;
	static const FKey PicoNeoController_Sub_App;
	static const FKey PicoNeoController_Sub_Touchpad;
	static const FKey PicoNeoController_Sub_Volume_Up;
	static const FKey PicoNeoController_Sub_Volume_Down;
	static const FKey PicoNeoController_Sub_Trigger;
	static const FKey PicoNeoController_Sub_TriggerAxis;
	static const FKey PicoNeoController_Sub_TouchX;
	static const FKey PicoNeoController_Sub_TouchY;

	static const FKey PicoNeoController_Sub_TouchUp;
	static const FKey PicoNeoController_Sub_TouchDown;
	static const FKey PicoNeoController_Sub_TouchLeft;
	static const FKey PicoNeoController_Sub_TouchRight;

	static const FKey PicoNeoController_Sub_TouchClickUp;
	static const FKey PicoNeoController_Sub_TouchClickDown;
	static const FKey PicoNeoController_Sub_TouchClickLeft;
	static const FKey PicoNeoController_Sub_TouchClickRight;


	static const FKey PicoNeoController_R_Home;
	static const FKey PicoNeoController_R_App;
	static const FKey PicoNeoController_R_RockerC;
	static const FKey PicoNeoController_R_A;
	static const FKey PicoNeoController_R_B;
	static const FKey PicoNeoController_R_Trigger;
	static const FKey PicoNeoController_R_TriggerAxis;
	static const FKey PicoNeoController_R_RockerX;
	static const FKey PicoNeoController_R_RockerY;
	static const FKey PicoNeoController_R_LGrip;
	static const FKey PicoNeoController_R_RGrip;

	static const FKey PicoNeoController_R_RockerUp;
	static const FKey PicoNeoController_R_RockerDown;
	static const FKey PicoNeoController_R_RockerLeft;
	static const FKey PicoNeoController_R_RockerRight;

	static const FKey PicoNeoController_R_RockerClickUp;
	static const FKey PicoNeoController_R_RockerClickDown;
	static const FKey PicoNeoController_R_RockerClickLeft;
	static const FKey PicoNeoController_R_RockerClickRight;

	//Short Pressed
	static const FKey PicoNeoController_Main_Home_ShortPressed;
	static const FKey PicoNeoController_Main_App_ShortPressed;
	static const FKey PicoNeoController_Main_Touchpad_ShortPressed;
	static const FKey PicoNeoController_Main_Volume_Up_ShortPressed;
	static const FKey PicoNeoController_Main_Volume_Down_ShortPressed;
	static const FKey PicoNeoController_Main_Trigger_ShortPressed;

	static const FKey PicoNeoController_L_Home_ShortPressed;
	static const FKey PicoNeoController_L_App_ShortPressed;
	static const FKey PicoNeoController_L_RockerC_ShortPressed;
	static const FKey PicoNeoController_L_X_ShortPressed;
	static const FKey PicoNeoController_L_Y_ShortPressed;
	static const FKey PicoNeoController_L_Trigger_ShortPressed;

	static const FKey PicoNeoController_L_LGrip_ShortPressed;
	static const FKey PicoNeoController_L_RGrip_ShortPressed;

	static const FKey PicoNeoController_Sub_Home_ShortPressed;
	static const FKey PicoNeoController_Sub_App_ShortPressed;
	static const FKey PicoNeoController_Sub_Touchpad_ShortPressed;
	static const FKey PicoNeoController_Sub_Volume_Up_ShortPressed;
	static const FKey PicoNeoController_Sub_Volume_Down_ShortPressed;
	static const FKey PicoNeoController_Sub_Trigger_ShortPressed;

	static const FKey PicoNeoController_R_Home_ShortPressed;
	static const FKey PicoNeoController_R_App_ShortPressed;
	static const FKey PicoNeoController_R_RockerC_ShortPressed;
	static const FKey PicoNeoController_R_A_ShortPressed;
	static const FKey PicoNeoController_R_B_ShortPressed;
	static const FKey PicoNeoController_R_Trigger_ShortPressed;
	static const FKey PicoNeoController_R_LGrip_ShortPressed;
	static const FKey PicoNeoController_R_RGrip_ShortPressed;

	//Long Pressed
	static const FKey PicoNeoController_Main_Home_LongPressed;
	static const FKey PicoNeoController_Main_App_LongPressed;
	static const FKey PicoNeoController_Main_Touchpad_LongPressed;
	static const FKey PicoNeoController_Main_Volume_Up_LongPressed;
	static const FKey PicoNeoController_Main_Volume_Down_LongPressed;
	static const FKey PicoNeoController_Main_Trigger_LongPressed;

	static const FKey PicoNeoController_L_Home_LongPressed;
	static const FKey PicoNeoController_L_App_LongPressed;
	static const FKey PicoNeoController_L_RockerC_LongPressed;
	static const FKey PicoNeoController_L_X_LongPressed;
	static const FKey PicoNeoController_L_Y_LongPressed;
	static const FKey PicoNeoController_L_Trigger_LongPressed;

	static const FKey PicoNeoController_L_LGrip_LongPressed;
	static const FKey PicoNeoController_L_RGrip_LongPressed;

	static const FKey PicoNeoController_Sub_Home_LongPressed;
	static const FKey PicoNeoController_Sub_App_LongPressed;
	static const FKey PicoNeoController_Sub_Touchpad_LongPressed;
	static const FKey PicoNeoController_Sub_Volume_Up_LongPressed;
	static const FKey PicoNeoController_Sub_Volume_Down_LongPressed;
	static const FKey PicoNeoController_Sub_Trigger_LongPressed;

	static const FKey PicoNeoController_R_Home_LongPressed;
	static const FKey PicoNeoController_R_App_LongPressed;
	static const FKey PicoNeoController_R_RockerC_LongPressed;
	static const FKey PicoNeoController_R_A_LongPressed;
	static const FKey PicoNeoController_R_B_LongPressed;
	static const FKey PicoNeoController_R_Trigger_LongPressed;
	static const FKey PicoNeoController_R_LGrip_LongPressed;
	static const FKey PicoNeoController_R_RGrip_LongPressed;


	//Add For Neo3
	static const FKey PicoNeoController_L_Rocker_CapTouch;
	static const FKey PicoNeoController_L_X_CapTouch;
	static const FKey PicoNeoController_L_Y_CapTouch;
	static const FKey PicoNeoController_L_Thumbrest;
	static const FKey PicoNeoController_L_Trigger_CapTouch;
	static const FKey PicoNeoController_L_Grip_Axis;
	
	static const FKey PicoNeoController_R_Rocker_CapTouch;
	static const FKey PicoNeoController_R_A_CapTouch;
	static const FKey PicoNeoController_R_B_CapTouch;
	static const FKey PicoNeoController_R_Thumbrest;
	static const FKey PicoNeoController_R_Trigger_CapTouch;
	static const FKey PicoNeoController_R_Grip_Axis;
};