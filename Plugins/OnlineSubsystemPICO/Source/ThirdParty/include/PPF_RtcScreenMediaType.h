// This file is generated automatically. Please don't edit it.
/*
struct VideoFrame{
1:VideoFrameType FrameType;
2:VideoPixelFormat PixelFormat;
8:ColorSpace ColorSpace;
3:i64 TimestampInUs;
4:i32 Width;
5:i32 Height;
6:VideoRotation Ratation;
7:bool Flip;
9:i32 NumberOfPlanes;
10:base.Uint8Array PlaneData;
11:base.Uint8Array ExtraData;
12:i32 ExtraDataSize;
13:base.Uint8Array SupplementaryInfo;
14:i32 SupplementaryInfoSize;
//TODO:补全字段
}
*/

#ifndef PPF_RTCSCREENMEDIATYPE_H
#define PPF_RTCSCREENMEDIATYPE_H

#include "PPF_Platform_Defs.h"

typedef enum {
    ppfRtcScreenMediaType_VideoOnly = 0,
    ppfRtcScreenMediaType_AudioOnly = 1,
    ppfRtcScreenMediaType_VideoAndAudio = 2
} ppfRtcScreenMediaType;
#endif

