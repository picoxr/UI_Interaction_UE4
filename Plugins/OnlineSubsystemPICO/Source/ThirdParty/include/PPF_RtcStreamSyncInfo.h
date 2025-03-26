// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCSTREAMSYNCINFO_H
#define PPF_RTCSTREAMSYNCINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcRemoteStreamKey.h"
#include "PPF_RtcSyncInfoStreamType.h"


typedef struct ppfRtcStreamSyncInfo *ppfRtcStreamSyncInfoHandle;


PPF_PUBLIC_FUNCTION(ppfRtcRemoteStreamKeyHandle) ppf_RtcStreamSyncInfo_GetStreamKey(const ppfRtcStreamSyncInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcSyncInfoStreamType) ppf_RtcStreamSyncInfo_GetStreamType(const ppfRtcStreamSyncInfoHandle obj);


PPF_PUBLIC_FUNCTION(UInt8Array) ppf_RtcStreamSyncInfo_GetData(const ppfRtcStreamSyncInfoHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcStreamSyncInfo_GetLength(const ppfRtcStreamSyncInfoHandle obj);



#endif

