// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include <memory.h>

#define PASP_PICO_HMD_SUPPORTED_PLATFORMS (PLATFORM_WINDOWS && WINVER > 0x0502)  || (PLATFORM_ANDROID_ARM || PLATFORM_ANDROID_ARM64)

#if PLATFORM_SUPPORTS_PRAGMA_PACK
#pragma pack (push,8)
#endif

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#pragma warning(push)
#pragma warning(disable:4201)		// nonstandard extension used: nameless struct/union
//#pragma warning(disable:4668)		// 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'

#define PVRP_EXPORT typedef
#include "PXR_Plugin.h"
#undef PVRP_EXPORT
#pragma warning(pop)

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#if PLATFORM_SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogPICOPluginWrapper_PASP, Log, All);

#define PICO_DECLARE_ENTRY_POINT(Func)		Pxr_##Func* Func

struct PICOPluginWrapper
{
	PICOPluginWrapper()
	{
		Reset();
	}

	void Reset()
	{
		memset(this, 0, sizeof(PICOPluginWrapper));
	}

	bool Initialized;
	bool bIsSessionInitialized;

	// PXRPlugin.h
	PICO_DECLARE_ENTRY_POINT(LogSdkApi);
};

#undef PICO_DECLARE_ENTRY_POINT

bool PASP_InitializePICOPluginWrapper(PICOPluginWrapper* wrapper);
void PASP_DestroyPICOPluginWrapper(PICOPluginWrapper* wrapper);
#if PASP_PICO_HMD_SUPPORTED_PLATFORMS
void* PASP_GetPVRPluginHandle();
#endif
