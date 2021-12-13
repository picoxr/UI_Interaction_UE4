// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.
#pragma once
DEFINE_LOG_CATEGORY_STATIC(PxrUnreal, Log, All);
#if WITH_EDITOR
	#define PLATFORM_CHAR(str) str

	#define PXR_LOGV(CategoryName, Format, ...) UE_LOG(CategoryName, Verbose, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGD(CategoryName, Format, ...) UE_LOG(CategoryName, Display, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGI(CategoryName, Format, ...) UE_LOG(CategoryName, Display, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGW(CategoryName, Format, ...) UE_LOG(CategoryName, Warning, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGE(CategoryName, Format, ...) UE_LOG(CategoryName, Error, TEXT(Format), ##__VA_ARGS__)
	#define PXR_LOGF(CategoryName, Format, ...) UE_LOG(CategoryName, Error, TEXT(Format), ##__VA_ARGS__)

#elif PLATFORM_ANDROID
	#define PLATFORM_CHAR(str) TCHAR_TO_UTF8(str)
	#include "Android/AndroidApplication.h"
	#include "Android/AndroidJNI.h"
	#include "PxrApi.h"
	#include <android/Log.h>
	#define PXR_LOGV(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_VERBOSE, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGD(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_DEBUG, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGI(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_INFO, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGW(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_WARN, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGE(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_ERROR, #TAG, fmt, ##__VA_ARGS__)
	#define PXR_LOGF(TAG, fmt, ...) Pxr_LogPrint(PxrLogPriority::PXR_LOG_FATAL, #TAG, fmt, ##__VA_ARGS__)

#else
	#define PLATFORM_CHAR(str) str
	#define PXR_LOGV(TAG, fmt, ...)
	#define PXR_LOGD(TAG, fmt, ...)
	#define PXR_LOGI(TAG, fmt, ...)
	#define PXR_LOGW(TAG, fmt, ...)
	#define PXR_LOGE(TAG, fmt, ...)
	#define PXR_LOGF(TAG, fmt, ...)
#endif