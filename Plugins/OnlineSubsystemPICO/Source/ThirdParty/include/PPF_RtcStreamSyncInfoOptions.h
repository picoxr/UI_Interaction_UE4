// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCSTREAMSYNCINFOOPTIONS_H
#define PPF_RTCSTREAMSYNCINFOOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcSyncInfoStreamType.h"


struct ppfRtcStreamSyncInfoOptions;
typedef struct ppfRtcStreamSyncInfoOptions *ppfRtcStreamSyncInfoOptionsHandle;

PPF_PUBLIC_FUNCTION(void) ppf_RtcStreamSyncInfoOptions_Destroy(ppfRtcStreamSyncInfoOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcStreamSyncInfoOptionsHandle) ppf_RtcStreamSyncInfoOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_RtcStreamSyncInfoOptions_SetStreamIndex(ppfRtcStreamSyncInfoOptionsHandle obj,ppfRtcStreamIndex value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcStreamSyncInfoOptions_SetRepeatCount(ppfRtcStreamSyncInfoOptionsHandle obj,int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcStreamSyncInfoOptions_SetStreamType(ppfRtcStreamSyncInfoOptionsHandle obj,ppfRtcSyncInfoStreamType value);


#endif

