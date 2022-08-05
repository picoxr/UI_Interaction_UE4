// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCUSERLEAVEINFO_H
#define PPF_RTCUSERLEAVEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcUserLeaveReasonType.h"

/// @file PPF_RtcUserLeaveInfo.h
/// @ingroup RTC

typedef struct ppfRtcUserLeaveInfo *ppfRtcUserLeaveInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserLeaveInfo_GetUserId(const ppfRtcUserLeaveInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcUserLeaveReasonType) ppf_RtcUserLeaveInfo_GetOfflineReason(const ppfRtcUserLeaveInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserLeaveInfo_GetRoomId(const ppfRtcUserLeaveInfoHandle obj);



#endif

