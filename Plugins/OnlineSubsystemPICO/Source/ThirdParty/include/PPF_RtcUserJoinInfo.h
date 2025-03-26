// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCUSERJOININFO_H
#define PPF_RTCUSERJOININFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

/// @file PPF_RtcUserJoinInfo.h
/// @ingroup RTC

typedef struct ppfRtcUserJoinInfo *ppfRtcUserJoinInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserJoinInfo_GetUserId(const ppfRtcUserJoinInfoHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserJoinInfo_GetUserExtra(const ppfRtcUserJoinInfoHandle obj);

PPF_PUBLIC_FUNCTION(int) ppf_RtcUserJoinInfo_GetElapsed(const ppfRtcUserJoinInfoHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserJoinInfo_GetRoomId(const ppfRtcUserJoinInfoHandle obj);

#endif

