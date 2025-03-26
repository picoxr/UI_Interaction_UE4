// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTC_USER_MESSAGE_RECEIVED_H
#define PPF_RTC_USER_MESSAGE_RECEIVED_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfRtcUserMessageReceived *ppfRtcUserMessageReceivedHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserMessageReceived_GetRoomId(const ppfRtcUserMessageReceivedHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserMessageReceived_GetUserId(const ppfRtcUserMessageReceivedHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_RtcUserMessageReceived_GetMessage(const ppfRtcUserMessageReceivedHandle obj);


#endif

