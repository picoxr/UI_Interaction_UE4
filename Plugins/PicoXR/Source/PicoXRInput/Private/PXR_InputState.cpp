// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_InputState.h"

#define LOCTEXT_NAMESPACE "PICOInputKeys"
//FPICOXRKeyNames
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_X_Click("PICOTouch_Left_X_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Y_Click("PICOTouch_Left_Y_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_X_Touch("PICOTouch_Left_X_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Y_Touch("PICOTouch_Left_Y_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Grip_Axis("PICOTouch_Left_Grip_Axis");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Menu_Click("PICOTouch_Left_Menu_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Home_Click("PICOTouch_Left_Home_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Grip_Click("PICOTouch_Left_Grip_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_X("PICOTouch_Left_Thumbstick_X");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Y("PICOTouch_Left_Thumbstick_Y");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Trigger_Axis("PICOTouch_Left_Trigger_Axis");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Trigger_Touch("PICOTouch_Left_Trigger_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Trigger_Click("PICOTouch_Left_Trigger_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_VolumeUp_Click("PICOTouch_Left_VolumeUp_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_VolumeDown_Click("PICOTouch_Left_VolumeDown_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Click("PICOTouch_Left_Thumbstick_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Touch("PICOTouch_Left_Thumbstick_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbrest_Touch("PICOTouch_Left_Thumbrest_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Up("PICOTouch_Left_Thumbstick_Up");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Down("PICOTouch_Left_Thumbstick_Down");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Left("PICOTouch_Left_Thumbstick_Left");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Left_Thumbstick_Right("PICOTouch_Left_Thumbstick_Right");

const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_A_Click("PICOTouch_Right_A_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_B_Click("PICOTouch_Right_B_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_A_Touch("PICOTouch_Right_A_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_B_Touch("PICOTouch_Right_B_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_System_Click("PICOTouch_Right_System_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Grip_Click("PICOTouch_Right_Grip_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Grip_Axis("PICOTouch_Right_Grip_Axis");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Trigger_Click("PICOTouch_Right_Trigger_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Trigger_Axis("PICOTouch_Right_Trigger_Axis");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Trigger_Touch("PICOTouch_Right_Trigger_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_X("PICOTouch_Right_Thumbstick_X");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Y("PICOTouch_Right_Thumbstick_Y");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Home_Click("PICOTouch_Right_Home_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_VolumeUp_Click("PICOTouch_Right_VolumeUp_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_VolumeDown_Click("PICOTouch_Right_VolumeDown_Click");	
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Click("PICOTouch_Right_Thumbstick_Click");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Touch("PICOTouch_Right_Thumbstick_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbrest_Touch("PICOTouch_Right_Thumbrest_Touch");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Up("PICOTouch_Right_Thumbstick_Up");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Down("PICOTouch_Right_Thumbstick_Down");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Left("PICOTouch_Right_Thumbstick_Left");
const FPICOKeyNames::Type FPICOKeyNames::PICOTouch_Right_Thumbstick_Right("PICOTouch_Right_Thumbstick_Right");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_Pinch("PICOHand_Left_Pinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_Pinch("PICOHand_Right_Pinch");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_PinchStrength("PICOHand_Left_PinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_PinchStrength("PICOHand_Right_PinchStrength");

const FKey FPICOTouchKey::PICOTouch_Left_Home_Click("PICOTouch_Left_Home_Click");
const FKey FPICOTouchKey::PICOTouch_Left_VolumeUp_Click("PICOTouch_Left_VolumeUp_Click");
const FKey FPICOTouchKey::PICOTouch_Left_VolumeDown_Click("PICOTouch_Left_VolumeDown_Click");
const FKey FPICOTouchKey::PICOTouch_Left_X_Click("PICOTouch_Left_X_Click");
const FKey FPICOTouchKey::PICOTouch_Left_Y_Click("PICOTouch_Left_Y_Click");
const FKey FPICOTouchKey::PICOTouch_Left_X_Touch("PICOTouch_Left_X_Touch");
const FKey FPICOTouchKey::PICOTouch_Left_Y_Touch("PICOTouch_Left_Y_Touch");
const FKey FPICOTouchKey::PICOTouch_Left_Menu_Click("PICOTouch_Left_Menu_Click");
const FKey FPICOTouchKey::PICOTouch_Left_Grip_Click("PICOTouch_Left_Grip_Click");
const FKey FPICOTouchKey::PICOTouch_Left_Grip_Axis("PICOTouch_Left_Grip_Axis");
const FKey FPICOTouchKey::PICOTouch_Left_Trigger_Click("PICOTouch_Left_Trigger_Click");
const FKey FPICOTouchKey::PICOTouch_Left_Trigger_Axis("PICOTouch_Left_Trigger_Axis");
const FKey FPICOTouchKey::PICOTouch_Left_Trigger_Touch("PICOTouch_Left_Trigger_Touch");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_X("PICOTouch_Left_Thumbstick_X");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Y("PICOTouch_Left_Thumbstick_Y");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Click("PICOTouch_Left_Thumbstick_Click");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Touch("PICOTouch_Left_Thumbstick_Touch");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbrest_Touch("PICOTouch_Left_Thumbrest_Touch");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Up("PICOTouch_Left_Thumbstick_Up");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Down("PICOTouch_Left_Thumbstick_Down");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Left("PICOTouch_Left_Thumbstick_Left");
const FKey FPICOTouchKey::PICOTouch_Left_Thumbstick_Right("PICOTouch_Left_Thumbstick_Right");

const FKey FPICOTouchKey::PICOTouch_Right_Home_Click("PICOTouch_Right_Home_Click");
const FKey FPICOTouchKey::PICOTouch_Right_VolumeUp_Click("PICOTouch_Right_VolumeUp_Click");
const FKey FPICOTouchKey::PICOTouch_Right_VolumeDown_Click("PICOTouch_Right_VolumeDown_Click");
const FKey FPICOTouchKey::PICOTouch_Right_A_Click("PICOTouch_Right_A_Click");
const FKey FPICOTouchKey::PICOTouch_Right_B_Click("PICOTouch_Right_B_Click");
const FKey FPICOTouchKey::PICOTouch_Right_A_Touch("PICOTouch_Right_A_Touch");
const FKey FPICOTouchKey::PICOTouch_Right_B_Touch("PICOTouch_Right_B_Touch");
const FKey FPICOTouchKey::PICOTouch_Right_System_Click("PICOTouch_Right_System_Click");
const FKey FPICOTouchKey::PICOTouch_Right_Grip_Click("PICOTouch_Right_Grip_Click");
const FKey FPICOTouchKey::PICOTouch_Right_Grip_Axis("PICOTouch_Right_Grip_Axis");
const FKey FPICOTouchKey::PICOTouch_Right_Trigger_Click("PICOTouch_Right_Trigger_Click");
const FKey FPICOTouchKey::PICOTouch_Right_Trigger_Axis("PICOTouch_Right_Trigger_Axis");
const FKey FPICOTouchKey::PICOTouch_Right_Trigger_Touch("PICOTouch_Right_Trigger_Touch");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_X("PICOTouch_Right_Thumbstick_X");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Y("PICOTouch_Right_Thumbstick_Y");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Click("PICOTouch_Right_Thumbstick_Click");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Touch("PICOTouch_Right_Thumbstick_Touch");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbrest_Touch("PICOTouch_Right_Thumbrest_Touch");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Up("PICOTouch_Right_Thumbstick_Up");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Down("PICOTouch_Right_Thumbstick_Down");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Left("PICOTouch_Right_Thumbstick_Left");
const FKey FPICOTouchKey::PICOTouch_Right_Thumbstick_Right("PICOTouch_Right_Thumbstick_Right");

const FKey FPICOTouchKey::PICOHand_Right_Pinch("PICOHand_Right_Pinch");
const FKey FPICOTouchKey::PICOHand_Left_Pinch("PICOHand_Left_Pinch");

const FKey FPICOTouchKey::PICOHand_Left_PinchStrength("PICOHand_Left_PinchStrength");
const FKey FPICOTouchKey::PICOHand_Right_PinchStrength("PICOHand_Right_PinchStrength");
#undef LOCTEXT_NAMESPACE