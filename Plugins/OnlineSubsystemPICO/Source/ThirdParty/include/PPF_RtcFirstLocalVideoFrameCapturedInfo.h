// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCFIRSTLOCALVIDEOFRAMECAPTUREDINFO_H
#define PPF_RTCFIRSTLOCALVIDEOFRAMECAPTUREDINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcVideoFrameInfo.h"


typedef struct ppfRtcFirstLocalVideoFrameCapturedInfo *ppfRtcFirstLocalVideoFrameCapturedInfoHandle;


PPF_PUBLIC_FUNCTION(ppfRtcStreamIndex) ppf_RtcFirstLocalVideoFrameCapturedInfo_GetStreamIndex(const ppfRtcFirstLocalVideoFrameCapturedInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoFrameInfoHandle) ppf_RtcFirstLocalVideoFrameCapturedInfo_GetInfo(const ppfRtcFirstLocalVideoFrameCapturedInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcFirstLocalVideoFrameCapturedInfo_GetRoomId(const ppfRtcFirstLocalVideoFrameCapturedInfoHandle obj);



#endif

