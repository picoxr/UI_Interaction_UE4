// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCLOCALVIDEOSIZECHANGEINFO_H
#define PPF_RTCLOCALVIDEOSIZECHANGEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcVideoFrameInfo.h"


typedef struct ppfRtcLocalVideoSizeChangeInfo *ppfRtcLocalVideoSizeChangeInfoHandle;


PPF_PUBLIC_FUNCTION(ppfRtcStreamIndex) ppf_RtcLocalVideoSizeChangeInfo_GetStreamIndex(const ppfRtcLocalVideoSizeChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoFrameInfoHandle) ppf_RtcLocalVideoSizeChangeInfo_GetVideoFrameInfo(const ppfRtcLocalVideoSizeChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcLocalVideoSizeChangeInfo_GetRoomId(const ppfRtcLocalVideoSizeChangeInfoHandle obj);



#endif

