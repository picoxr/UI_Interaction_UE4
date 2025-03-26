// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTC_ROOM_MESSAGE_RECEIVED_H
#define PPF_RTC_ROOM_MESSAGE_RECEIVED_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfRtcRoomMessageReceived *ppfRtcRoomMessageReceivedHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRoomMessageReceived_GetRoomId(const ppfRtcRoomMessageReceivedHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRoomMessageReceived_GetUserId(const ppfRtcRoomMessageReceivedHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRoomMessageReceived_GetMessage(const ppfRtcRoomMessageReceivedHandle obj);


#endif

