// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PICO_EnterpriseInterfaceWrapper.h"

#if PLATFORM_ANDROID
#include <dlfcn.h>
#endif

DEFINE_LOG_CATEGORY_STATIC(LogPXRBWrapper, Log, All);

FInterfaceWrapper FInterfaceWrapper::Wrapper;

void* LoadEntryPoint(void* Handle, const char* EntryPointName)
{
#if PLATFORM_ANDROID
	void* ptr = dlsym(Handle, EntryPointName);
	if (ptr)
	{
		UE_LOG(LogPXRBWrapper, Display, TEXT("Load libpxr_xrsdk_native.so [%s] Success"), ANSI_TO_TCHAR(EntryPointName));
	}
	else
	{
		UE_LOG(LogPXRBWrapper, Display, TEXT("Load libpxr_xrsdk_native.so [%s] Failed"), ANSI_TO_TCHAR(EntryPointName));
	}
	return ptr;
#endif
	UE_LOG(LogPXRBWrapper, Display, TEXT("Load libpxr_xrsdk_native.so [%s] Failed"), ANSI_TO_TCHAR(EntryPointName));
	return nullptr;
}

bool FInterfaceWrapper::Initialize()
{
	UE_LOG(LogPXRBWrapper, Display, TEXT("FInterfaceWrapper Begin Init"));
	if (Initialized)
	{
		UE_LOG(LogPXRBWrapper, Display, TEXT("FInterfaceWrapper Already Init"));
		return true;
	}

	void* Handle = nullptr;
#if PLATFORM_ANDROID
	Handle = FPlatformProcess::GetDllHandle(TEXT("libpxr_xrsdk_native.so"));
#endif
	if (Handle == nullptr)
	{
		UE_LOG(LogPXRBWrapper, Display, TEXT("GetDllHandle Failed"));
		return false;
	}

	PE_GetHeadTrackingConfidence_Interface = reinterpret_cast<getHeadTrackingConfidence*>(LoadEntryPoint(Handle, "getHeadTrackingConfidence"));
	PE_OpenVSTCamera_Interface = reinterpret_cast<openVSTCamera*>(LoadEntryPoint(Handle, "openVSTCamera"));
	PE_CloseVSTCamera_Interface = reinterpret_cast<closeVSTCamera*>(LoadEntryPoint(Handle, "closeVSTCamera"));
	PE_AcquireVSTCameraFrame_Interface = reinterpret_cast<acquireVSTCameraFrame*>(LoadEntryPoint(Handle, "acquireVSTCameraFrame"));
	PE_AcquireVSTCameraFrameAntiDistortion_Interface = reinterpret_cast<acquireVSTCameraFrameAntiDistortion*>(LoadEntryPoint(Handle, "acquireVSTCameraFrameAntiDistortion"));
	PE_GetCameraParameters_Interface = reinterpret_cast<getCameraParameters*>(LoadEntryPoint(Handle, "getCameraParameters"));

	UE_LOG(LogPXRBWrapper, Display, TEXT("FInterfaceWrapper Init Success"));
	Initialized = true;
	return true;
}

void FInterfaceWrapper::Destroy()
{
	Initialized = false;
	Reset();
}