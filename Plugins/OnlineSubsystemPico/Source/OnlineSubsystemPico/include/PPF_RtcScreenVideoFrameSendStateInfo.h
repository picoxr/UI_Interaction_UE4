// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCSCREENVIDEOFRAMESENDSTATEINFO_H
#define PPF_RTCSCREENVIDEOFRAMESENDSTATEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcFirstFrameSendState.h"


typedef struct ppfRtcScreenVideoFrameSendStateInfo *ppfRtcScreenVideoFrameSendStateInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcScreenVideoFrameSendStateInfo_GetUserId(const ppfRtcScreenVideoFrameSendStateInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcScreenVideoFrameSendStateInfo_GetUserExtra(const ppfRtcScreenVideoFrameSendStateInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcFirstFrameSendState) ppf_RtcScreenVideoFrameSendStateInfo_GetState(const ppfRtcScreenVideoFrameSendStateInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcScreenVideoFrameSendStateInfo_GetRoomId(const ppfRtcScreenVideoFrameSendStateInfoHandle obj);



#endif

