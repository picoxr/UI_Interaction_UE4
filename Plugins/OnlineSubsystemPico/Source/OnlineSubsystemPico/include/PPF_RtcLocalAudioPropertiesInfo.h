// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCLOCALAUDIOPROPERTIESINFO_H
#define PPF_RTCLOCALAUDIOPROPERTIESINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcAudioPropertyInfo.h"


/// @file PPF_RtcLocalAudioPropertiesInfo.h
/// @ingroup RTC

typedef struct ppfRtcLocalAudioPropertiesInfo *ppfRtcLocalAudioPropertiesInfoHandle;


PPF_PUBLIC_FUNCTION(ppfRtcStreamIndex) ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex(const ppfRtcLocalAudioPropertiesInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcAudioPropertyInfoHandle) ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo(const ppfRtcLocalAudioPropertiesInfoHandle obj);



#endif

