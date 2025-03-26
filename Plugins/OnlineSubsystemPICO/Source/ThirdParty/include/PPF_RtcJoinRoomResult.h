// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCJOINROOMRESULT_H
#define PPF_RTCJOINROOMRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcJoinRoomType.h"

/// @file PPF_RtcJoinRoomResult.h
/// @ingroup RTC

typedef struct ppfRtcJoinRoomResult *ppfRtcJoinRoomResultHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcJoinRoomResult_GetRoomId(const ppfRtcJoinRoomResultHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcJoinRoomResult_GetUserId(const ppfRtcJoinRoomResultHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcJoinRoomResult_GetErrorCode(const ppfRtcJoinRoomResultHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcJoinRoomResult_GetElapsed(const ppfRtcJoinRoomResultHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcJoinRoomType) ppf_RtcJoinRoomResult_GetJoinType(const ppfRtcJoinRoomResultHandle obj);



#endif

