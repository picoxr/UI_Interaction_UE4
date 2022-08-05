// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"
#include "Misc/ConfigCacheIni.h"

#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoModule.h"
#include "OnlineSubsystemModule.h"
#include "OnlineSubsystem.h"

#define INVALID_INDEX -1
/** URL suffix when using Pico NetDriver */
#define Pico_URL_SUFFIX TEXT(".pico")

/** pre-pended to all Pico logging */
#undef ONLINE_LOG_PREFIX
#define ONLINE_LOG_PREFIX TEXT("Pico: ")
/** Pico Platform SDK header*/
#include "PPF_Platform.h"
/**
 * 
 */
