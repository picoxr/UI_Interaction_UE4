// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCVIDEODEVICESTATECHANGEINFO_H
#define PPF_RTCVIDEODEVICESTATECHANGEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcVideoDeviceType.h"
#include "PPF_RtcMediaDeviceState.h"
#include "PPF_RtcMediaDeviceError.h"


typedef struct ppfRtcVideoDeviceStateChangeInfo *ppfRtcVideoDeviceStateChangeInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcVideoDeviceStateChangeInfo_GetDeviceId(const ppfRtcVideoDeviceStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoDeviceType) ppf_RtcVideoDeviceStateChangeInfo_GetDeviceType(const ppfRtcVideoDeviceStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceState) ppf_RtcVideoDeviceStateChangeInfo_GetDeviceState(const ppfRtcVideoDeviceStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceError) ppf_RtcVideoDeviceStateChangeInfo_GetDeviceError(const ppfRtcVideoDeviceStateChangeInfoHandle obj);



#endif

