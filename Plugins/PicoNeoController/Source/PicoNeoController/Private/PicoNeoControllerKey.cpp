// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoNeoControllerKey.h"
#include "PicoNeoControllerPrivatePCH.h"

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Home("PicoNeoController_Main_Home");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_App("PicoNeoController_Main_App");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Touchpad("PicoNeoController_Main_Touchpad");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up("PicoNeoController_Main_Volume_Up");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down("PicoNeoController_Main_Volume_Down");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Trigger("PicoNeoController_Main_Trigger");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TriggerAxis("PicoNeoController_Main_TriggerAxis");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchX("PicoNeoController_Main_TouchX");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchY("PicoNeoController_Main_TouchY");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchUp("PicoNeoController_Main_TouchUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchDown("PicoNeoController_Main_TouchDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchLeft("PicoNeoController_Main_TouchLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchRight("PicoNeoController_Main_TouchRight");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchClickUp("PicoNeoController_Main_TouchClickUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchClickDown("PicoNeoController_Main_TouchClickDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchClickLeft("PicoNeoController_Main_TouchClickLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_TouchClickRight("PicoNeoController_Main_TouchClickRight");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Home("PicoNeoController_L_Home");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_App("PicoNeoController_L_App");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerC("PicoNeoController_L_RockerC");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_X("PicoNeoController_L_X");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Y("PicoNeoController_L_Y");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_TriggerAxis("PicoNeoController_L_TriggerAxis");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Trigger("PicoNeoController_L_Trigger");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerX("PicoNeoController_L_RockerX");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerY("PicoNeoController_L_RockerY");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_LGrip("PicoNeoController_L_LGrip");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RGrip("PicoNeoController_L_RGrip");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerUp("PicoNeoController_L_RockerUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerDown("PicoNeoController_L_RockerDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerLeft("PicoNeoController_L_RockerLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerRight("PicoNeoController_L_RockerRight");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerClickUp("PicoNeoController_L_RockerClickUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerClickDown("PicoNeoController_L_RockerClickDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerClickLeft("PicoNeoController_L_RockerClickLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerClickRight("PicoNeoController_L_RockerClickRight");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Home("PicoNeoController_Sub_Home");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_App("PicoNeoController_Sub_App");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad("PicoNeoController_Sub_Touchpad");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up("PicoNeoController_Sub_Volume_Up");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down("PicoNeoController_Sub_Volume_Down");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Trigger("PicoNeoController_Sub_Trigger");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TriggerAxis("PicoNeoController_Sub_TriggerAxis");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchX("PicoNeoController_Sub_Touchpad_X");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchY("PicoNeoController_Sub_Touchpad_Y");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchUp("PicoNeoController_Sub_TouchUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchDown("PicoNeoController_Sub_TouchDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchLeft("PicoNeoController_Sub_TouchLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchRight("PicoNeoController_Sub_TouchRight");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickUp("PicoNeoController_Sub_TouchClickUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickDown("PicoNeoController_Sub_TouchClickDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickLeft("PicoNeoController_Sub_TouchClickLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickRight("PicoNeoController_Sub_TouchClickRight");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Home("PicoNeoController_R_Home");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_App("PicoNeoController_R_App");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerC("PicoNeoController_R_RockerC");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_A("PicoNeoController_R_A");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_B("PicoNeoController_R_B");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Trigger("PicoNeoController_R_Trigger");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_TriggerAxis("PicoNeoController_R_TriggerAxis");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerX("PicoNeoController_R_RockerX");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerY("PicoNeoController_R_RockerY");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_LGrip("PicoNeoController_R_LGrip");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RGrip("PicoNeoController_R_RGrip");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerUp("PicoNeoController_R_RockerUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerDown("PicoNeoController_R_RockerDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerLeft("PicoNeoController_R_RockerLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerRight("PicoNeoController_R_RockerRight");

const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerClickUp("PicoNeoController_R_RockerClickUp");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerClickDown("PicoNeoController_R_RockerClickDown");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerClickLeft("PicoNeoController_R_RockerClickLeft");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerClickRight("PicoNeoController_R_RockerClickRight");


//ShortPress
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Home_ShortPress("PicoNeoController_Main_Home_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_App_ShortPress("PicoNeoController_Main_App_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Touchpad_ShortPress("PicoNeoController_Main_Touchpad_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up_ShortPress("PicoNeoController_Main_Volume_Up_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down_ShortPress("PicoNeoController_Main_Volume_Down_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Trigger_ShortPress("PicoNeoController_Main_Trigger_ShortPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Home_ShortPress("PicoNeoController_L_Home_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_App_ShortPress("PicoNeoController_L_App_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerC_ShortPress("PicoNeoController_L_RockerC_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_X_ShortPress("PicoNeoController_L_X_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Y_ShortPress("PicoNeoController_L_Y_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Trigger_ShortPress("PicoNeoController_L_Trigger_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_LGrip_ShortPress("PicoNeoController_L_LGrip_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RGrip_ShortPress("PicoNeoController_L_RGrip_ShortPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Home_ShortPress("PicoNeoController_Sub_Home_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_App_ShortPress("PicoNeoController_Sub_App_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad_ShortPress("PicoNeoController_Sub_Touchpad_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up_ShortPress("PicoNeoController_Sub_Volume_Up_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down_ShortPress("PicoNeoController_Sub_Volume_Down_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Trigger_ShortPress("PicoNeoController_Sub_Trigger_ShortPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Home_ShortPress("PicoNeoController_R_Home_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_App_ShortPress("PicoNeoController_R_App_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerC_ShortPress("PicoNeoController_R_RockerC_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_A_ShortPress("PicoNeoController_R_A_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_B_ShortPress("PicoNeoController_R_B_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Trigger_ShortPress("PicoNeoController_R_Trigger_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_LGrip_ShortPress("PicoNeoController_R_LGrip_ShortPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RGrip_ShortPress("PicoNeoController_R_RGrip_ShortPress");

//LongPress
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Home_LongPress("PicoNeoController_Main_Home_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_App_LongPress("PicoNeoController_Main_App_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Touchpad_LongPress("PicoNeoController_Main_Touchpad_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up_LongPress("PicoNeoController_Main_Volume_Up_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down_LongPress("PicoNeoController_Main_Volume_Down_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Main_Trigger_LongPress("PicoNeoController_Main_Trigger_LongPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Home_LongPress("PicoNeoController_L_Home_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_App_LongPress("PicoNeoController_L_App_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RockerC_LongPress("PicoNeoController_L_RockerC_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_X_LongPress("PicoNeoController_L_X_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Y_LongPress("PicoNeoController_L_Y_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Trigger_LongPress("PicoNeoController_L_Trigger_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_LGrip_LongPress("PicoNeoController_L_LGrip_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_RGrip_LongPress("PicoNeoController_L_RGrip_LongPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Home_LongPress("PicoNeoController_Sub_Home_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_App_LongPress("PicoNeoController_Sub_App_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad_LongPress("PicoNeoController_Sub_Touchpad_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up_LongPress("PicoNeoController_Sub_Volume_Up_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down_LongPress("PicoNeoController_Sub_Volume_Down_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_Sub_Trigger_LongPress("PicoNeoController_Sub_Trigger_LongPress");


const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Home_LongPress("PicoNeoController_R_Home_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_App_LongPress("PicoNeoController_R_App_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RockerC_LongPress("PicoNeoController_R_RockerC_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_A_LongPress("PicoNeoController_R_A_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_B_LongPress("PicoNeoController_R_B_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Trigger_LongPress("PicoNeoController_R_Trigger_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_LGrip_LongPress("PicoNeoController_R_LGrip_LongPress");
const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_RGrip_LongPress("PicoNeoController_R_RGrip_LongPress");

//Add For Neo3
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Rocker_CapTouch("PicoNeoController_L_Rocker_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_X_CapTouch("PicoNeoController_L_X_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Y_CapTouch("PicoNeoController_L_Y_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Thumbrest("PicoNeoController_L_Thumbrest");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Trigger_CapTouch("PicoNeoController_L_Trigger_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_L_Grip_Axis("PicoNeoController_L_Grip_Axis");
	
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Rocker_CapTouch("PicoNeoController_R_Rocker_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_A_CapTouch("PicoNeoController_R_A_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_B_CapTouch("PicoNeoController_R_B_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Thumbrest("PicoNeoController_R_Thumbrest");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Trigger_CapTouch("PicoNeoController_R_Trigger_CapTouch");
 const FPicoNeoKeyNames::Type FPicoNeoKeyNames::PicoNeoController_R_Grip_Axis("PicoNeoController_R_Grip_Axis");


//FKey
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Home("PicoNeoController_Main_Home");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_App("PicoNeoController_Main_App");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Touchpad("PicoNeoController_Main_Touchpad");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up("PicoNeoController_Main_Volume_Up");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down("PicoNeoController_Main_Volume_Down");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Trigger("PicoNeoController_Main_Trigger");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TriggerAxis("PicoNeoController_Main_TriggerAxis");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchX("PicoNeoController_Main_TouchX");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchY("PicoNeoController_Main_TouchY");

const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchUp("PicoNeoController_Main_TouchUp");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchDown("PicoNeoController_Main_TouchDown");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchLeft("PicoNeoController_Main_TouchLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchRight("PicoNeoController_Main_TouchRight");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchClickUp("PicoNeoController_Main_TouchClickUp");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchClickDown("PicoNeoController_Main_TouchClickDown");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchClickLeft("PicoNeoController_Main_TouchClickLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_TouchClickRight("PicoNeoController_Main_TouchClickRight");


const FKey FPicoNeoControllerKey::PicoNeoController_L_Home("PicoNeoController_L_Home");
const FKey FPicoNeoControllerKey::PicoNeoController_L_App("PicoNeoController_L_App");
const FKey FPicoNeoControllerKey::PicoNeoController_L_X("PicoNeoController_L_X");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Y("PicoNeoController_L_Y");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerC("PicoNeoController_L_RockerC");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Trigger("PicoNeoController_L_Trigger");
const FKey FPicoNeoControllerKey::PicoNeoController_L_TriggerAxis("PicoNeoController_L_TriggerAxis");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerX("PicoNeoController_L_RockerX");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerY("PicoNeoController_L_RockerY");
const FKey FPicoNeoControllerKey::PicoNeoController_L_LGrip("PicoNeoController_L_LGrip");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RGrip("PicoNeoController_L_RGrip");

const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerUp("PicoNeoController_L_RockerUp");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerDown("PicoNeoController_L_RockerDown");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerLeft("PicoNeoController_L_RockerLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerRight("PicoNeoController_L_RockerRight");

const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerClickUp("PicoNeoController_L_RockerClickUp");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerClickDown("PicoNeoController_L_RockerClickDown");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerClickLeft("PicoNeoController_L_RockerClickLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerClickRight("PicoNeoController_L_RockerClickRight");


const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Home("PicoNeoController_Sub_Home");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_App("PicoNeoController_Sub_App");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad("PicoNeoController_Sub_Touchpad");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up("PicoNeoController_Sub_Volume_Up");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down("PicoNeoController_Sub_Volume_Down");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Trigger("PicoNeoController_Sub_Trigger");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TriggerAxis("PicoNeoController_Sub_TriggerAxis");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchX("PicoNeoController_Sub_Touchpad_X");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchY("PicoNeoController_Sub_Touchpad_Y");

const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchUp("PicoNeoController_Sub_TouchUp");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchDown("PicoNeoController_Sub_TouchDown");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchLeft("PicoNeoController_Sub_TouchLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchRight("PicoNeoController_Sub_TouchRight");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickUp("PicoNeoController_Sub_TouchClickUp");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickDown("PicoNeoController_Sub_TouchClickDown");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickLeft("PicoNeoController_Sub_TouchClickLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickRight("PicoNeoController_Sub_TouchClickRight");

const FKey FPicoNeoControllerKey::PicoNeoController_R_Home("PicoNeoController_R_Home");
const FKey FPicoNeoControllerKey::PicoNeoController_R_App("PicoNeoController_R_App");
const FKey FPicoNeoControllerKey::PicoNeoController_R_A("PicoNeoController_R_A");
const FKey FPicoNeoControllerKey::PicoNeoController_R_B("PicoNeoController_R_B");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerC("PicoNeoController_R_RockerC");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Trigger("PicoNeoController_R_Trigger");
const FKey FPicoNeoControllerKey::PicoNeoController_R_TriggerAxis("PicoNeoController_R_TriggerAxis");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerX("PicoNeoController_R_RockerX");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerY("PicoNeoController_R_RockerY");
const FKey FPicoNeoControllerKey::PicoNeoController_R_LGrip("PicoNeoController_R_LGrip");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RGrip("PicoNeoController_R_RGrip");

const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerUp("PicoNeoController_R_RockerUp");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerDown("PicoNeoController_R_RockerDown");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerLeft("PicoNeoController_R_RockerLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerRight("PicoNeoController_R_RockerRight");

const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerClickUp("PicoNeoController_R_RockerClickUp");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerClickDown("PicoNeoController_R_RockerClickDown");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerClickLeft("PicoNeoController_R_RockerClickLeft");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerClickRight("PicoNeoController_R_RockerClickRight");

//ShortPress
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Home_ShortPressed("PicoNeoController_Main_Home_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_App_ShortPressed("PicoNeoController_Main_App_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Touchpad_ShortPressed("PicoNeoController_Main_Touchpad_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up_ShortPressed("PicoNeoController_Main_Volume_Up_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down_ShortPressed("PicoNeoController_Main_Volume_Down_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Trigger_ShortPressed("PicoNeoController_Main_Trigger_ShortPress");

const FKey FPicoNeoControllerKey::PicoNeoController_L_Home_ShortPressed("PicoNeoController_L_Home_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_App_ShortPressed("PicoNeoController_L_App_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_X_ShortPressed("PicoNeoController_L_X_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Y_ShortPressed("PicoNeoController_L_Y_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerC_ShortPressed("PicoNeoController_L_RockerC_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Trigger_ShortPressed("PicoNeoController_L_Trigger_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_LGrip_ShortPressed("PicoNeoController_L_LGrip_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RGrip_ShortPressed("PicoNeoController_L_RGrip_ShortPress");

const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Home_ShortPressed("PicoNeoController_Sub_Home_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_App_ShortPressed("PicoNeoController_Sub_App_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad_ShortPressed("PicoNeoController_Sub_Touchpad_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up_ShortPressed("PicoNeoController_Sub_Volume_Up_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down_ShortPressed("PicoNeoController_Sub_Volume_Down_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Trigger_ShortPressed("PicoNeoController_Sub_Trigger_ShortPress");

const FKey FPicoNeoControllerKey::PicoNeoController_R_Home_ShortPressed("PicoNeoController_R_Home_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_App_ShortPressed("PicoNeoController_R_App_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_A_ShortPressed("PicoNeoController_R_A_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_B_ShortPressed("PicoNeoController_R_B_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerC_ShortPressed("PicoNeoController_R_RockerC_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Trigger_ShortPressed("PicoNeoController_R_Trigger_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_LGrip_ShortPressed("PicoNeoController_R_LGrip_ShortPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RGrip_ShortPressed("PicoNeoController_R_RGrip_ShortPress");

//LongPress
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Home_LongPressed("PicoNeoController_Main_Home_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_App_LongPressed("PicoNeoController_Main_App_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Touchpad_LongPressed("PicoNeoController_Main_Touchpad_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up_LongPressed("PicoNeoController_Main_Volume_Up_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down_LongPressed("PicoNeoController_Main_Volume_Down_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Main_Trigger_LongPressed("PicoNeoController_Main_Trigger_LongPress");

const FKey FPicoNeoControllerKey::PicoNeoController_L_Home_LongPressed("PicoNeoController_L_Home_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_App_LongPressed("PicoNeoController_L_App_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_X_LongPressed("PicoNeoController_L_X_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Y_LongPressed("PicoNeoController_L_Y_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RockerC_LongPressed("PicoNeoController_L_RockerC_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Trigger_LongPressed("PicoNeoController_L_Trigger_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_LGrip_LongPressed("PicoNeoController_L_LGrip_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_L_RGrip_LongPressed("PicoNeoController_L_RGrip_LongPress");

const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Home_LongPressed("PicoNeoController_Sub_Home_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_App_LongPressed("PicoNeoController_Sub_App_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad_LongPressed("PicoNeoController_Sub_Touchpad_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up_LongPressed("PicoNeoController_Sub_Volume_Up_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down_LongPressed("PicoNeoController_Sub_Volume_Down_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_Sub_Trigger_LongPressed("PicoNeoController_Sub_Trigger_LongPress");

const FKey FPicoNeoControllerKey::PicoNeoController_R_Home_LongPressed("PicoNeoController_R_Home_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_App_LongPressed("PicoNeoController_R_App_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_A_LongPressed("PicoNeoController_R_A_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_B_LongPressed("PicoNeoController_R_B_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RockerC_LongPressed("PicoNeoController_R_RockerC_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Trigger_LongPressed("PicoNeoController_R_Trigger_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_LGrip_LongPressed("PicoNeoController_R_LGrip_LongPress");
const FKey FPicoNeoControllerKey::PicoNeoController_R_RGrip_LongPressed("PicoNeoController_R_RGrip_LongPress");

//Add For Neo3
const FKey FPicoNeoControllerKey::PicoNeoController_L_Rocker_CapTouch("PicoNeoController_L_Rocker_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_L_X_CapTouch("PicoNeoController_L_X_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Y_CapTouch("PicoNeoController_L_Y_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Thumbrest("PicoNeoController_L_Thumbrest");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Trigger_CapTouch("PicoNeoController_L_Trigger_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_L_Grip_Axis("PicoNeoController_L_Grip_Axis");
	
const FKey FPicoNeoControllerKey::PicoNeoController_R_Rocker_CapTouch("PicoNeoController_R_Rocker_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_R_A_CapTouch("PicoNeoController_R_A_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_R_B_CapTouch("PicoNeoController_R_B_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Thumbrest("PicoNeoController_R_Thumbrest");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Trigger_CapTouch("PicoNeoController_R_Trigger_CapTouch");
const FKey FPicoNeoControllerKey::PicoNeoController_R_Grip_Axis("PicoNeoController_R_Grip_Axis");
