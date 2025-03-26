// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.
#pragma once
DEFINE_LOG_CATEGORY_STATIC(PxrUnreal, Log, All);
DEFINE_LOG_CATEGORY_STATIC(PxrUnrealFunctionLibrary, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogMRC, Log, All);
#if !UE_BUILD_SHIPPING
	#define PLATFORM_CHAR(str) str

	#define PXR_LOGV(CategoryName, Format, ...) UE_LOG(CategoryName, Verbose, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGD(CategoryName, Format, ...) UE_LOG(CategoryName, Display, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGI(CategoryName, Format, ...) UE_LOG(CategoryName, Log, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGW(CategoryName, Format, ...) UE_LOG(CategoryName, Warning, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGE(CategoryName, Format, ...) UE_LOG(CategoryName, Error, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGF(CategoryName, Format, ...) UE_LOG(CategoryName, Fatal, TEXT(Format), ##__VA_ARGS__)

#elif PLATFORM_ANDROID
	#define PLATFORM_CHAR(str) TCHAR_TO_UTF8(str)
	#include <android/Log.h>

	#define PXR_LOGV(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_VERBOSE, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGD(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_DEBUG, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGI(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_INFO, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGW(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_WARN, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGE(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_ERROR, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGF(TAG, fmt, ...) FPICOXRHMDModule::GetPluginWrapper().LogPrint(PxrLogPriority::PXR_LOG_FATAL, #TAG, fmt, ##__VA_ARGS__)

#else
	#define PLATFORM_CHAR(str) str
	#define PXR_LOGV(TAG, fmt, ...)
	#define PXR_LOGD(TAG, fmt, ...)
	#define PXR_LOGI(TAG, fmt, ...)
	#define PXR_LOGW(TAG, fmt, ...)
	#define PXR_LOGE(TAG, fmt, ...)
	#define PXR_LOGF(TAG, fmt, ...)
#endif