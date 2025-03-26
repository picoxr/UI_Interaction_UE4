// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCVIDEOFRAMEINFO_H
#define PPF_RTCVIDEOFRAMEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcVideoRotation.h"


typedef struct ppfRtcVideoFrameInfo *ppfRtcVideoFrameInfoHandle;


PPF_PUBLIC_FUNCTION(int) ppf_RtcVideoFrameInfo_GetWidth(const ppfRtcVideoFrameInfoHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcVideoFrameInfo_GetHeight(const ppfRtcVideoFrameInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoRotation) ppf_RtcVideoFrameInfo_GetRotation(const ppfRtcVideoFrameInfoHandle obj);



#endif

