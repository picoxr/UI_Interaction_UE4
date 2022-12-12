// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCUSERPUBLISHINFO_H
#define PPF_RTCUSERPUBLISHINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcMediaStreamType.h"


typedef struct ppfRtcUserPublishInfo *ppfRtcUserPublishInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserPublishInfo_GetUserId(const ppfRtcUserPublishInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaStreamType) ppf_RtcUserPublishInfo_GetMediaStreamType(const ppfRtcUserPublishInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserPublishInfo_GetRoomId(const ppfRtcUserPublishInfoHandle obj);



#endif

