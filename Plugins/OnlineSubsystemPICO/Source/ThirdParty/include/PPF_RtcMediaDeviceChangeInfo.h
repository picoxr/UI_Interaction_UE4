// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCMEDIADEVICECHANGEINFO_H
#define PPF_RTCMEDIADEVICECHANGEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcMediaDeviceType.h"
#include "PPF_RtcMediaDeviceState.h"
#include "PPF_RtcMediaDeviceError.h"

/// @file PPF_RtcMediaDeviceChangeInfo.h
/// @ingroup RTC

typedef struct ppfRtcMediaDeviceChangeInfo *ppfRtcMediaDeviceChangeInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcMediaDeviceChangeInfo_GetDeviceId(const ppfRtcMediaDeviceChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceType) ppf_RtcMediaDeviceChangeInfo_GetDeviceType(const ppfRtcMediaDeviceChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceState) ppf_RtcMediaDeviceChangeInfo_GetDeviceState(const ppfRtcMediaDeviceChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceError) ppf_RtcMediaDeviceChangeInfo_GetDeviceError(const ppfRtcMediaDeviceChangeInfoHandle obj);



#endif

