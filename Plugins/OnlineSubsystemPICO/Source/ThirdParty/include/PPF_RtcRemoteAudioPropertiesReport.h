// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCREMOTEAUDIOPROPERTIESREPORT_H
#define PPF_RTCREMOTEAUDIOPROPERTIESREPORT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcRemoteAudioPropertiesInfo.h"


/// @file PPF_RtcRemoteAudioPropertiesReport.h
/// @ingroup RTC


typedef struct ppfRtcRemoteAudioPropertiesReport *ppfRtcRemoteAudioPropertiesReportHandle;


PPF_PUBLIC_FUNCTION(ppfRtcRemoteAudioPropertiesInfoHandle) ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos(const ppfRtcRemoteAudioPropertiesReportHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize(const ppfRtcRemoteAudioPropertiesReportHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume(const ppfRtcRemoteAudioPropertiesReportHandle obj);



#endif

