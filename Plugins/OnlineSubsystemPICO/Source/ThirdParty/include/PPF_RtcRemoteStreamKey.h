// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCREMOTESTREAMKEY_H
#define PPF_RTCREMOTESTREAMKEY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcStreamIndex.h"


/// @file PPF_RtcRemoteStreamKey.h
/// @ingroup RTC

typedef struct ppfRtcRemoteStreamKey *ppfRtcRemoteStreamKeyHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRemoteStreamKey_GetRoomId(const ppfRtcRemoteStreamKeyHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRemoteStreamKey_GetUserId(const ppfRtcRemoteStreamKeyHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcStreamIndex) ppf_RtcRemoteStreamKey_GetStreamIndex(const ppfRtcRemoteStreamKeyHandle obj);



#endif

