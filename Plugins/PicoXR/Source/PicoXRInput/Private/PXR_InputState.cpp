//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_InputState.h"

#define LOCTEXT_NAMESPACE "PicoInputKeys"
//FPicoXRKeyNames
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_X_Click("PicoTouch_Left_X_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Y_Click("PicoTouch_Left_Y_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_X_Touch("PicoTouch_Left_X_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Y_Touch("PicoTouch_Left_Y_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Grip_Axis("PicoTouch_Left_Grip_Axis");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Menu_Click("PicoTouch_Left_Menu_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Home_Click("PicoTouch_Left_Home_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Grip_Click("PicoTouch_Left_Grip_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_X("PicoTouch_Left_Thumbstick_X");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Y("PicoTouch_Left_Thumbstick_Y");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Trigger_Axis("PicoTouch_Left_Trigger_Axis");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Trigger_Touch("PicoTouch_Left_Trigger_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Trigger_Click("PicoTouch_Left_Trigger_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_VolumeUp_Click("PicoTouch_Left_VolumeUp_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_VolumeDown_Click("PicoTouch_Left_VolumeDown_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Click("PicoTouch_Left_Thumbstick_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Touch("PicoTouch_Left_Thumbstick_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbrest_Touch("PicoTouch_Left_Thumbrest_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Up("PicoTouch_Left_Thumbstick_Up");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Down("PicoTouch_Left_Thumbstick_Down");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Left("PicoTouch_Left_Thumbstick_Left");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Left_Thumbstick_Right("PicoTouch_Left_Thumbstick_Right");

const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_A_Click("PicoTouch_Right_A_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_B_Click("PicoTouch_Right_B_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_A_Touch("PicoTouch_Right_A_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_B_Touch("PicoTouch_Right_B_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_System_Click("PicoTouch_Right_System_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Grip_Click("PicoTouch_Right_Grip_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Grip_Axis("PicoTouch_Right_Grip_Axis");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Trigger_Click("PicoTouch_Right_Trigger_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Trigger_Axis("PicoTouch_Right_Trigger_Axis");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Trigger_Touch("PicoTouch_Right_Trigger_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_X("PicoTouch_Right_Thumbstick_X");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Y("PicoTouch_Right_Thumbstick_Y");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Home_Click("PicoTouch_Right_Home_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_VolumeUp_Click("PicoTouch_Right_VolumeUp_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_VolumeDown_Click("PicoTouch_Right_VolumeDown_Click");	
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Click("PicoTouch_Right_Thumbstick_Click");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Touch("PicoTouch_Right_Thumbstick_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbrest_Touch("PicoTouch_Right_Thumbrest_Touch");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Up("PicoTouch_Right_Thumbstick_Up");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Down("PicoTouch_Right_Thumbstick_Down");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Left("PicoTouch_Right_Thumbstick_Left");
const FPicoKeyNames::Type FPicoKeyNames::PicoTouch_Right_Thumbstick_Right("PicoTouch_Right_Thumbstick_Right");

const FKey FPicoTouchKey::PicoTouch_Left_Home_Click("PicoTouch_Left_Home_Click");
const FKey FPicoTouchKey::PicoTouch_Left_VolumeUp_Click("PicoTouch_Left_VolumeUp_Click");
const FKey FPicoTouchKey::PicoTouch_Left_VolumeDown_Click("PicoTouch_Left_VolumeDown_Click");
const FKey FPicoTouchKey::PicoTouch_Left_X_Click("PicoTouch_Left_X_Click");
const FKey FPicoTouchKey::PicoTouch_Left_Y_Click("PicoTouch_Left_Y_Click");
const FKey FPicoTouchKey::PicoTouch_Left_X_Touch("PicoTouch_Left_X_Touch");
const FKey FPicoTouchKey::PicoTouch_Left_Y_Touch("PicoTouch_Left_Y_Touch");
const FKey FPicoTouchKey::PicoTouch_Left_Menu_Click("PicoTouch_Left_Menu_Click");
const FKey FPicoTouchKey::PicoTouch_Left_Grip_Click("PicoTouch_Left_Grip_Click");
const FKey FPicoTouchKey::PicoTouch_Left_Grip_Axis("PicoTouch_Left_Grip_Axis");
const FKey FPicoTouchKey::PicoTouch_Left_Trigger_Click("PicoTouch_Left_Trigger_Click");
const FKey FPicoTouchKey::PicoTouch_Left_Trigger_Axis("PicoTouch_Left_Trigger_Axis");
const FKey FPicoTouchKey::PicoTouch_Left_Trigger_Touch("PicoTouch_Left_Trigger_Touch");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_X("PicoTouch_Left_Thumbstick_X");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Y("PicoTouch_Left_Thumbstick_Y");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Click("PicoTouch_Left_Thumbstick_Click");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Touch("PicoTouch_Left_Thumbstick_Touch");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbrest_Touch("PicoTouch_Left_Thumbrest_Touch");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Up("PicoTouch_Left_Thumbstick_Up");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Down("PicoTouch_Left_Thumbstick_Down");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Left("PicoTouch_Left_Thumbstick_Left");
const FKey FPicoTouchKey::PicoTouch_Left_Thumbstick_Right("PicoTouch_Left_Thumbstick_Right");

const FKey FPicoTouchKey::PicoTouch_Right_Home_Click("PicoTouch_Right_Home_Click");
const FKey FPicoTouchKey::PicoTouch_Right_VolumeUp_Click("PicoTouch_Right_VolumeUp_Click");
const FKey FPicoTouchKey::PicoTouch_Right_VolumeDown_Click("PicoTouch_Right_VolumeDown_Click");
const FKey FPicoTouchKey::PicoTouch_Right_A_Click("PicoTouch_Right_A_Click");
const FKey FPicoTouchKey::PicoTouch_Right_B_Click("PicoTouch_Right_B_Click");
const FKey FPicoTouchKey::PicoTouch_Right_A_Touch("PicoTouch_Right_A_Touch");
const FKey FPicoTouchKey::PicoTouch_Right_B_Touch("PicoTouch_Right_B_Touch");
const FKey FPicoTouchKey::PicoTouch_Right_System_Click("PicoTouch_Right_System_Click");
const FKey FPicoTouchKey::PicoTouch_Right_Grip_Click("PicoTouch_Right_Grip_Click");
const FKey FPicoTouchKey::PicoTouch_Right_Grip_Axis("PicoTouch_Right_Grip_Axis");
const FKey FPicoTouchKey::PicoTouch_Right_Trigger_Click("PicoTouch_Right_Trigger_Click");
const FKey FPicoTouchKey::PicoTouch_Right_Trigger_Axis("PicoTouch_Right_Trigger_Axis");
const FKey FPicoTouchKey::PicoTouch_Right_Trigger_Touch("PicoTouch_Right_Trigger_Touch");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_X("PicoTouch_Right_Thumbstick_X");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Y("PicoTouch_Right_Thumbstick_Y");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Click("PicoTouch_Right_Thumbstick_Click");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Touch("PicoTouch_Right_Thumbstick_Touch");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbrest_Touch("PicoTouch_Right_Thumbrest_Touch");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Up("PicoTouch_Right_Thumbstick_Up");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Down("PicoTouch_Right_Thumbstick_Down");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Left("PicoTouch_Right_Thumbstick_Left");
const FKey FPicoTouchKey::PicoTouch_Right_Thumbstick_Right("PicoTouch_Right_Thumbstick_Right");

#undef LOCTEXT_NAMESPACE