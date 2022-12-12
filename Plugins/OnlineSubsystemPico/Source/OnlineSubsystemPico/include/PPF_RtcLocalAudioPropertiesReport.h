// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCLOCALAUDIOPROPERTIESREPORT_H
#define PPF_RTCLOCALAUDIOPROPERTIESREPORT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RtcLocalAudioPropertiesInfo.h"


/// @file PPF_RtcLocalAudioPropertiesReport.h
/// @ingroup RTC

typedef struct ppfRtcLocalAudioPropertiesReport *ppfRtcLocalAudioPropertiesReportHandle;


PPF_PUBLIC_FUNCTION(ppfRtcLocalAudioPropertiesInfoHandle) ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos(const ppfRtcLocalAudioPropertiesReportHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize(const ppfRtcLocalAudioPropertiesReportHandle obj);



#endif
