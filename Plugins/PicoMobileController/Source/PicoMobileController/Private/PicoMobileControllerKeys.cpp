// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobileControllerKeys.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Home("Pico_Handle_Home");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Back("Pico_Handle_Back");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Touchpad("Pico_Handle_Touchpad");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeUp("Pico_Handle_VolumeUp");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeDown("Pico_Handle_VolumeDown");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchX("Pico_Handle_TouchX");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchY("Pico_Handle_TouchY");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Trigger("Pico_Handle_Trigger");

const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchUp("Pico_Handle_TouchUp");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchDown("Pico_Handle_TouchDown");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchLeft("Pico_Handle_TouchLeft");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchRight("Pico_Handle_TouchRight");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchClickUp("Pico_Handle_TouchClickUp");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchClickDown("Pico_Handle_TouchClickDown");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchClickLeft("Pico_Handle_TouchClickLeft");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_TouchClickRight("Pico_Handle_TouchClickRight");

const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Home_ShortPress("Pico_Handle_Home_ShortPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Back_ShortPress("Pico_Handle_Back_ShortPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Touchpad_ShortPress("Pico_Handle_Touchpad_ShortPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeUp_ShortPress("Pico_Handle_VolumeUp_ShortPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeDown_ShortPress("Pico_Handle_VolumeDown_ShortPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Trigger_ShortPress("Pico_Handle_Trigger_ShortPress");

const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Home_LongPress("Pico_Handle_Home_LongPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Back_LongPress("Pico_Handle_Back_LongPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Touchpad_LongPress("Pico_Handle_Touchpad_LongPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeUp_LongPress("Pico_Handle_VolumeUp_LongPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_VolumeDown_LongPress("Pico_Handle_VolumeDown_LongPress");
const FPicoMobileKeysNames::Type FPicoMobileKeysNames::Pico_Handle_Trigger_LongPress("Pico_Handle_Trigger_LongPress");

const FKey FPicoMobileControllerKeys::Pico_Handle_Home("Pico_Handle_Home");
const FKey FPicoMobileControllerKeys::Pico_Handle_Back("Pico_Handle_Back");
const FKey FPicoMobileControllerKeys::Pico_Handle_Touchpad("Pico_Handle_Touchpad");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeUp("Pico_Handle_VolumeUp");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeDown("Pico_Handle_VolumeDown");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchX("Pico_Handle_TouchX");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchY("Pico_Handle_TouchY");
const FKey FPicoMobileControllerKeys::Pico_Handle_Trigger("Pico_Handle_Trigger");

const FKey FPicoMobileControllerKeys::Pico_Handle_TouchUp("Pico_Handle_TouchUp");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchDown("Pico_Handle_TouchDown");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchLeft("Pico_Handle_TouchLeft");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchRight("Pico_Handle_TouchRight");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchClickUp("Pico_Handle_TouchClickUp");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchClickDown("Pico_Handle_TouchClickDown");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchClickLeft("Pico_Handle_TouchClickLeft");
const FKey FPicoMobileControllerKeys::Pico_Handle_TouchClickRight("Pico_Handle_TouchClickRight");

const FKey FPicoMobileControllerKeys::Pico_Handle_Home_ShortPress("Pico_Handle_Home_ShortPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Back_ShortPress("Pico_Handle_Back_ShortPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Touchpad_ShortPress("Pico_Handle_Touchpad_ShortPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeUp_ShortPress("Pico_Handle_VolumeUp_ShortPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeDown_ShortPress("Pico_Handle_VolumeDown_ShortPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Trigger_ShortPress("Pico_Handle_Trigger_ShortPress");

const FKey FPicoMobileControllerKeys::Pico_Handle_Home_LongPress("Pico_Handle_Home_LongPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Back_LongPress("Pico_Handle_Back_LongPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Touchpad_LongPress("Pico_Handle_Touchpad_LongPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeUp_LongPress("Pico_Handle_VolumeUp_LongPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_VolumeDown_LongPress("Pico_Handle_VolumeDown_LongPress");
const FKey FPicoMobileControllerKeys::Pico_Handle_Trigger_LongPress("Pico_Handle_Trigger_LongPress");
