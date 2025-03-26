// This file is generated automatically. Please don't edit it.
#ifndef PPF_RTCAUDIOFRAME_H
#define PPF_RTCAUDIOFRAME_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>
#include "PPF_RtcAudioSampleRate.h"
#include "PPF_RtcAudioChannel.h"

struct ppfRtcAudioFrame;
typedef struct ppfRtcAudioFrame *ppfRtcAudioFrameHandle;

PPF_PUBLIC_FUNCTION(ppfRtcAudioSampleRate) ppf_RtcAudioFrame_GetSampleRate(ppfRtcAudioFrameHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcAudioChannel) ppf_RtcAudioFrame_GetChannel(ppfRtcAudioFrameHandle obj);
PPF_PUBLIC_FUNCTION(int64_t) ppf_RtcAudioFrame_GetTimeStampInUs(ppfRtcAudioFrameHandle obj);
PPF_PUBLIC_FUNCTION(UInt8Array) ppf_RtcAudioFrame_GetData(ppfRtcAudioFrameHandle obj);
PPF_PUBLIC_FUNCTION(int64_t) ppf_RtcAudioFrame_GetDataSize(ppfRtcAudioFrameHandle obj);
#endif
