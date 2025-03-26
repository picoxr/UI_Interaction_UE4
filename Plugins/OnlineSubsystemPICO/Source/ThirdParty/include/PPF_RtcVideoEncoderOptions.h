// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCVIDEOENCODEROPTIONS_H
#define PPF_RTCVIDEOENCODEROPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RtcVideoStreamScaleMode.h"
#include "PPF_RtcVideoEncodePreference.h"


struct ppfRtcVideoEncoderOptions;
typedef struct ppfRtcVideoEncoderOptions *ppfRtcVideoEncoderOptionsHandle;



PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_Destroy(ppfRtcVideoEncoderOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoEncoderOptionsHandle) ppf_RtcVideoEncoderOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetWidth(ppfRtcVideoEncoderOptionsHandle obj,int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetHeight(ppfRtcVideoEncoderOptionsHandle obj,int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetFrameRate(ppfRtcVideoEncoderOptionsHandle obj,int value);

// 默认值-1
PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetMaxBitRate(ppfRtcVideoEncoderOptionsHandle obj,int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetScaleMode(ppfRtcVideoEncoderOptionsHandle obj,ppfRtcVideoStreamScaleMode value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoEncoderOptions_SetEncoderPreference(ppfRtcVideoEncoderOptionsHandle obj,ppfRtcVideoEncodePreference value);


#endif

