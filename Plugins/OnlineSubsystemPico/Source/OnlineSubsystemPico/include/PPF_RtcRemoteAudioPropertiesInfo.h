// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCREMOTEAUDIOPROPERTIESINFO_H
#define PPF_RTCREMOTEAUDIOPROPERTIESINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcRemoteStreamKey.h"
#include "PPF_RtcAudioPropertyInfo.h"

/// @file PPF_RtcRemoteAudioPropertiesInfo.h
/// @ingroup RTC

typedef struct ppfRtcRemoteAudioPropertiesInfo *ppfRtcRemoteAudioPropertiesInfoHandle;

PPF_PUBLIC_FUNCTION(ppfRtcRemoteStreamKeyHandle) ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey(const ppfRtcRemoteAudioPropertiesInfoHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcAudioPropertyInfoHandle) ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo(const ppfRtcRemoteAudioPropertiesInfoHandle obj);



#endif

