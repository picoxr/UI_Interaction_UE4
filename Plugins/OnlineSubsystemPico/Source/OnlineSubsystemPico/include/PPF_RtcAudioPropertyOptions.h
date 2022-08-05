// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCAUDIOPROPERTYOPTIONS_H
#define PPF_RTCAUDIOPROPERTYOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

/// @file PPF_RtcAudioPropertyOptions.h
/// @ingroup RTC

struct ppfRtcAudioPropertyOptions;
typedef struct ppfRtcAudioPropertyOptions *ppfRtcAudioPropertyOptionsHandle;


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioPropertyOptions_Destroy(ppfRtcAudioPropertyOptionsHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcAudioPropertyOptionsHandle) ppf_RtcAudioPropertyOptions_Create();

PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioPropertyOptions_SetInterval(ppfRtcAudioPropertyOptionsHandle obj,int value);


#endif

