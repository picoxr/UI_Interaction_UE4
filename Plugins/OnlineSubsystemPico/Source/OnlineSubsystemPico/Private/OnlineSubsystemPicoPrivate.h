// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
