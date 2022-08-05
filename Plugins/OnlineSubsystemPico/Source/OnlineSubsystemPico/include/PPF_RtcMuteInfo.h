// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCMUTEINFO_H
#define PPF_RTCMUTEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcMuteState.h"


/// @file PPF_RtcMuteInfo.h
/// @ingroup RTC

typedef struct ppfRtcMuteInfo *ppfRtcMuteInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcMuteInfo_GetUserId(const ppfRtcMuteInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMuteState) ppf_RtcMuteInfo_GetMuteState(const ppfRtcMuteInfoHandle obj);



#endif

