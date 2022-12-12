//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_DPInputState.h"

#define LOCTEXT_NAMESPACE "PICOInputKeys"
//FPICOXRKeyNames
#if WITH_EDITOR
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

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_ThumbClick("PICOHand_Left_ThumbClick");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_IndexPinch("PICOHand_Left_IndexPinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_MiddlePinch("PICOHand_Left_MiddlePinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_RingPinch("PICOHand_Left_RingPinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_PinkyPinch("PICOHand_Left_PinkPinch");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_ThumbClick("PICOHand_Right_ThumbClick");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_IndexPinch("PICOHand_Right_IndexPinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_MiddlePinch("PICOHand_Right_MiddlePinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_RingPinch("PICOHand_Right_RingPinch");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_PinkyPinch("PICOHand_Right_PinkPinch");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_SystemGesture("PICOHand_Left_SystemGesture");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_SystemGesture("PICOHand_Right_SystemGesture");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_ThumbClickStrength("PICOHand_Left_ThumbClickStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_IndexPinchStrength("PICOHand_Left_IndexPinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_MiddlePinchStrength("PICOHand_Left_MiddlePinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_RingPinchStrength("PICOHand_Left_RingPinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Left_PinkyPinchStrength("PICOHand_Left_PinkPinchStrength");

const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_ThumbClickStrength("PICOHand_Right_ThumbClickStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_IndexPinchStrength("PICOHand_Right_IndexPinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_MiddlePinchStrength("PICOHand_Right_MiddlePinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_RingPinchStrength("PICOHand_Right_RingPinchStrength");
const FPICOKeyNames::Type FPICOKeyNames::PICOHand_Right_PinkyPinchStrength("PICOHand_Right_PinkPinchStrength");


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

const FKey FPICOTouchKey::PICOHand_Right_ThumbClick("PICOHand_Right_ThumbClick");
const FKey FPICOTouchKey::PICOHand_Right_IndexPinch("PICOHand_Right_IndexPinch");
const FKey FPICOTouchKey::PICOHand_Right_MiddlePinch("PICOHand_Right_MiddlePinch");
const FKey FPICOTouchKey::PICOHand_Right_RingPinch("PICOHand_Right_RingPinch");
const FKey FPICOTouchKey::PICOHand_Right_PinkyPinch("PICOHand_Right_PinkyPinch");

const FKey FPICOTouchKey::PICOHand_Left_ThumbClick("PICOHand_Left_ThumbClick");
const FKey FPICOTouchKey::PICOHand_Left_IndexPinch("PICOHand_Left_IndexPinch");
const FKey FPICOTouchKey::PICOHand_Left_MiddlePinch("PICOHand_Left_MiddlePinch");
const FKey FPICOTouchKey::PICOHand_Left_RingPinch("PICOHand_Left_RingPinch");
const FKey FPICOTouchKey::PICOHand_Left_PinkyPinch("PICOHand_Left_PinkyPinch");

const FKey FPICOTouchKey::PICOHand_Left_SystemGesture("PICOHand_Left_SystemGesture");
const FKey FPICOTouchKey::PICOHand_Right_SystemGesture("PICOHand_Right_SystemGesture");

const FKey FPICOTouchKey::PICOHand_Left_ThumbClickStrength("PICOHand_Left_ThumbClickStrength");
const FKey FPICOTouchKey::PICOHand_Left_IndexPinchStrength("PICOHand_Left_IndexPinchStrength");
const FKey FPICOTouchKey::PICOHand_Left_MiddlePinchStrength("PICOHand_Left_MiddlePinchStrength");
const FKey FPICOTouchKey::PICOHand_Left_RingPinchStrength("PICOHand_Left_RingPinchStrength");
const FKey FPICOTouchKey::PICOHand_Left_PinkyPinchStrength("PICOHand_Left_PinkyPinchStrength");

const FKey FPICOTouchKey::PICOHand_Right_ThumbClickStrength("PICOHand_Right_ThumbClickStrength");
const FKey FPICOTouchKey::PICOHand_Right_IndexPinchStrength("PICOHand_Right_IndexPinchStrength");
const FKey FPICOTouchKey::PICOHand_Right_MiddlePinchStrength("PICOHand_Right_MiddlePinchStrength");
const FKey FPICOTouchKey::PICOHand_Right_RingPinchStrength("PICOHand_Right_RingPinchStrength");
const FKey FPICOTouchKey::PICOHand_Right_PinkyPinchStrength("PICOHand_Right_PinkyPinchStrength");
#endif

#undef LOCTEXT_NAMESPACE