// This file is generated automatically. Please don't edit it.
/*
struct AudioFrame{
1:AudioSampleRate SampleRate;
2:AudioChannel Channel;
3:i64 TimeStampInUs;
4:base.Uint8Array Data;
5:i64 DataSize;
6:bool DeepCopy;
}
*/

#ifndef PPF_RTCVIDEOFRAMETYPE_H
#define PPF_RTCVIDEOFRAMETYPE_H

#include "PPF_Platform_Defs.h"

typedef enum {
    ppfRtcVideoFrameType_RawMemory = 0,
    ppfRtcVideoFrameType_CVPixelBuffer = 1,
    ppfRtcVideoFrameType_GLTexture = 2,
    ppfRtcVideoFrameType_Cuda = 3,
    ppfRtcVideoFrameType_D3D11 = 4,
    ppfRtcVideoFrameType_D3D9 = 5,
    ppfRtcVideoFrameType_JavaFrame = 6,
    ppfRtcVideoFrameType_VAAPI = 7
} ppfRtcVideoFrameType;
#endif

