// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCROOMERROR_H
#define PPF_RTCROOMERROR_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

/// @file PPF_RtcRoomError.h
/// @ingroup RTC

typedef struct ppfRtcRoomError *ppfRtcRoomErrorHandle;


PPF_PUBLIC_FUNCTION(int) ppf_RtcRoomError_GetCode(const ppfRtcRoomErrorHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_RtcRoomError_GetRoomId(const ppfRtcRoomErrorHandle obj);



#endif

