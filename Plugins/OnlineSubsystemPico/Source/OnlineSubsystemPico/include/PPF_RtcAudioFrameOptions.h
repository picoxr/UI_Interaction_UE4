// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCAUDIOFRAMEOPTIONS_H
#define PPF_RTCAUDIOFRAMEOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RtcAudioSampleRate.h"
#include "PPF_RtcAudioChannel.h"


struct ppfRtcAudioFrameOptions;
typedef struct ppfRtcAudioFrameOptions *ppfRtcAudioFrameOptionsHandle;



PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_Destroy(ppfRtcAudioFrameOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcAudioFrameOptionsHandle) ppf_RtcAudioFrameOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetSampleRate(ppfRtcAudioFrameOptionsHandle obj,ppfRtcAudioSampleRate value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetChannel(ppfRtcAudioFrameOptionsHandle obj,ppfRtcAudioChannel value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetTimeStampInUs(ppfRtcAudioFrameOptionsHandle obj,int64_t value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetData(ppfRtcAudioFrameOptionsHandle obj,UInt8Array value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetDataSize(ppfRtcAudioFrameOptionsHandle obj,int64_t value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcAudioFrameOptions_SetDeepCopy(ppfRtcAudioFrameOptionsHandle obj,bool value);


#endif

