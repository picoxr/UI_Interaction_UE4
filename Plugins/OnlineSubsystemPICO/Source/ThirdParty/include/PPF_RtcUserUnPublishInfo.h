// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCUSERUNPUBLISHSTREAMINFO_H
#define PPF_RTCUSERUNPUBLISHSTREAMINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcMediaStreamType.h"
#include "PPF_RtcStreamRemoveReason.h"


typedef struct ppfRtcUserUnPublishInfo *ppfRtcUserUnPublishInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserUnPublishInfo_GetUserId(const ppfRtcUserUnPublishInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcMediaStreamType) ppf_RtcUserUnPublishInfo_GetMediaStreamType(const ppfRtcUserUnPublishInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcStreamRemoveReason) ppf_RtcUserUnPublishInfo_GetReason(const ppfRtcUserUnPublishInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserUnPublishInfo_GetRoomId(const ppfRtcUserUnPublishInfoHandle obj);



#endif

