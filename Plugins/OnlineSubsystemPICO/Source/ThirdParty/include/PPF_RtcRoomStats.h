// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCROOMSTATS_H
#define PPF_RTCROOMSTATS_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

/// @file PPF_RtcRoomStates.h
/// @ingroup RTC

typedef struct ppfRtcRoomStats *ppfRtcRoomStatsHandle;


PPF_PUBLIC_FUNCTION(int) ppf_RtcRoomStats_GetTotalDuration(const ppfRtcRoomStatsHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcRoomStats_GetUserCount(const ppfRtcRoomStatsHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRoomStats_GetRoomId(const ppfRtcRoomStatsHandle obj);



#endif

