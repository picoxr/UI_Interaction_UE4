// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCVIDEOFRAMEOPTIONS_H
#define PPF_RTCVIDEOFRAMEOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>
#include "PPF_RtcVideoFrameType.h"
#include "PPF_RtcVideoPixelFormat.h"
#include "PPF_RtcColorSpace.h"
#include "PPF_RtcVideoRotation.h"


struct ppfRtcVideoFrameOptions;
typedef struct ppfRtcVideoFrameOptions *ppfRtcVideoFrameOptionsHandle;

#ifdef __ANDROID__

#include "jni.h"
PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetEglContext(ppfRtcVideoFrameOptionsHandle obj,jobject value);
#endif

PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_Destroy(ppfRtcVideoFrameOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoFrameOptionsHandle) ppf_RtcVideoFrameOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetFrameType(ppfRtcVideoFrameOptionsHandle obj, ppfRtcVideoFrameType value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetPixelFormat(ppfRtcVideoFrameOptionsHandle obj, ppfRtcVideoPixelFormat value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetColorSpace(ppfRtcVideoFrameOptionsHandle obj, ppfRtcColorSpace value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetTimestampInUs(ppfRtcVideoFrameOptionsHandle obj, int64_t value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetWidth(ppfRtcVideoFrameOptionsHandle obj, int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetHeight(ppfRtcVideoFrameOptionsHandle obj, int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetRotation(ppfRtcVideoFrameOptionsHandle obj, ppfRtcVideoRotation value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetFlip(ppfRtcVideoFrameOptionsHandle obj, bool value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetPlaneData(ppfRtcVideoFrameOptionsHandle obj, int index, UInt8Array value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetPlaneDataLineSize(ppfRtcVideoFrameOptionsHandle obj, int index, int value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetExtraData(ppfRtcVideoFrameOptionsHandle obj, UInt8Array value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetExtraDataSize(ppfRtcVideoFrameOptionsHandle obj, int value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetSupplementaryInfo(ppfRtcVideoFrameOptionsHandle obj, UInt8Array value);


PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetSupplementaryInfoSize(ppfRtcVideoFrameOptionsHandle obj, int value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetHwaccelBuffer(ppfRtcVideoFrameOptionsHandle obj, void *buffer);
PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetTextureId(ppfRtcVideoFrameOptionsHandle obj, uint32_t textureId);
PPF_PUBLIC_FUNCTION(void) ppf_RtcVideoFrameOptions_SetTextureMatrix(ppfRtcVideoFrameOptionsHandle obj, int index, float value);

#endif

