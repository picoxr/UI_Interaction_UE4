// This file is generated automatically. Please don't edit it.


#ifndef PPF_RTCMESSAGESENDRESULT_H
#define PPF_RTCMESSAGESENDRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfRtcMessageSendResult *ppfRtcMessageSendResultHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_RtcMessageSendResult_GetMessageId(const ppfRtcMessageSendResultHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_RtcMessageSendResult_GetError(const ppfRtcMessageSendResultHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcMessageSendResult_GetRoomId(const ppfRtcMessageSendResultHandle obj);



#endif

