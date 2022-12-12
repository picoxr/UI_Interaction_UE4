// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCLOCALVIDEOSTATECHANGEINFO_H
#define PPF_RTCLOCALVIDEOSTATECHANGEINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcLocalVideoStreamState.h"
#include "PPF_RtcLocalVideoStreamError.h"


typedef struct ppfRtcLocalVideoStateChangeInfo *ppfRtcLocalVideoStateChangeInfoHandle;


PPF_PUBLIC_FUNCTION(ppfRtcStreamIndex) ppf_RtcLocalVideoStateChangeInfo_GetStreamIndex(const ppfRtcLocalVideoStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcLocalVideoStreamState) ppf_RtcLocalVideoStateChangeInfo_GetState(const ppfRtcLocalVideoStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcLocalVideoStreamError) ppf_RtcLocalVideoStateChangeInfo_GetError(const ppfRtcLocalVideoStateChangeInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcLocalVideoStateChangeInfo_GetRoomId(const ppfRtcLocalVideoStateChangeInfoHandle obj);



#endif

