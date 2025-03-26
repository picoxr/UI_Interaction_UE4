// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_PluginWrapper.h"
#include "Interfaces/IPluginManager.h"

#if PLATFORM_ANDROID
#include <dlfcn.h>
#endif

DEFINE_LOG_CATEGORY(LogPICOPluginWrapper_PASP);

static void* PASP_LoadEntryPoint(void* handle, const char* EntryPointName);

bool PASP_InitializePICOPluginWrapper(PICOPluginWrapper* wrapper)
{
	if (wrapper->Initialized)
	{
		UE_LOG(LogPICOPluginWrapper_PASP, Warning, TEXT("wrapper already initialized"));
		return true;
	}

#if PASP_PICO_HMD_SUPPORTED_PLATFORMS
	void* LibraryHandle = nullptr;

#if PLATFORM_ANDROID
	const bool VersionValid = FAndroidMisc::GetAndroidBuildVersion() > 23;
#else
	const bool VersionValid = true;
#endif

	if (VersionValid)
	{
		LibraryHandle = PASP_GetPVRPluginHandle();
		if (LibraryHandle == nullptr)
		{
			UE_LOG(LogPICOPluginWrapper_PASP, Warning, TEXT("GetPVRPluginHandle() returned NULL"));
			return false;
		}
	}
	else
	{
		return false;
	}
#else
	return false;
#endif

	struct PICOEntryPoint
	{
		const char* EntryPointName;
		void** EntryPointPtr;
	};

#define PICO_BIND_ENTRY_POINT(Func)	{ "Pxr_"#Func, (void**)&wrapper->Func }

	PICOEntryPoint entryPointArray[] =
	{
		PICO_BIND_ENTRY_POINT(LogSdkApi)
	};

#undef PICO_BIND_ENTRY_POINT

	bool result = true;
	for (int i = 0; i < UE_ARRAY_COUNT(entryPointArray); ++i)
	{
		*(entryPointArray[i].EntryPointPtr) = PASP_LoadEntryPoint(LibraryHandle, entryPointArray[i].EntryPointName);

		if (*entryPointArray[i].EntryPointPtr == NULL)
		{
			UE_LOG(LogPICOPluginWrapper_PASP, Error, TEXT("PICOPlugin EntryPoint could not be loaded: %s"), ANSI_TO_TCHAR(entryPointArray[i].EntryPointName));
			result = false;
		}
	}

	if (result)
	{
		UE_LOG(LogPICOPluginWrapper_PASP, Log, TEXT("PICOPlugin initialized successfully"));
		wrapper->Initialized = result;
	}
	else
	{
		PASP_DestroyPICOPluginWrapper(wrapper);
	}

	return result;
}

void PASP_DestroyPICOPluginWrapper(PICOPluginWrapper* wrapper)
{
	if (!wrapper->Initialized)
	{
		return;
	}
	wrapper->Reset();
	UE_LOG(LogPICOPluginWrapper_PASP, Log, TEXT("PICOPlugin destroyed successfully"));
}

void* PASP_GetPVRPluginHandle()
{
	void* PVRPluginHandle = nullptr;

#if PLATFORM_ANDROID
	PVRPluginHandle = FPlatformProcess::GetDllHandle(TEXT("libpxr_api.so"));
#endif
	return PVRPluginHandle;
}

static void* PASP_LoadEntryPoint(void* Handle, const char* EntryPointName)
{
	if (Handle == nullptr)
	{
		return nullptr;
	}
#if PLATFORM_WINDOWS && WITH_EDITOR
	void* ptr=reinterpret_cast<void*>(GetProcAddress((HMODULE)Handle, EntryPointName));
	
	if (ptr == nullptr)
	{
		UE_LOG(LogPICOPluginWrapper_PASP, Error, TEXT("Unable to load entry point: %hs"), ANSI_TO_TCHAR(EntryPointName));
	}
	return ptr;
#elif PLATFORM_ANDROID
	void* ptr = dlsym(Handle, EntryPointName);
	if (ptr == nullptr)
	{
		UE_LOG(LogPICOPluginWrapper_PASP, Error, TEXT("Unable to load entry point: %s, error %s"), ANSI_TO_TCHAR(EntryPointName), ANSI_TO_TCHAR(dlerror()));
	}
	return ptr;
#else
	UE_LOG(LogPICOPluginWrapper_PASP, Error, TEXT("LoadEntryPoint: Unsupported platform"));
	return nullptr;
#endif
}
