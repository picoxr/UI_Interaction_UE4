// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCROOMBINARYMESSAGERECEIVED_H
#define PPF_RTCROOMBINARYMESSAGERECEIVED_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfRtcBinaryMessageReceived *ppfRtcBinaryMessageReceivedHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcBinaryMessageReceived_GetUserId(const ppfRtcBinaryMessageReceivedHandle obj);


PPF_PUBLIC_FUNCTION(UInt8Array) ppf_RtcBinaryMessageReceived_GetData(const ppfRtcBinaryMessageReceivedHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcBinaryMessageReceived_GetLength(const ppfRtcBinaryMessageReceivedHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcBinaryMessageReceived_GetRoomId(const ppfRtcBinaryMessageReceivedHandle obj);



#endif

