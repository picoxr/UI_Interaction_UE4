// This file is generated automatically. Please don't edit it.

#ifndef PPF_REQUESTS_RTC_H
#define PPF_REQUESTS_RTC_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
#include "PPF_RtcGetTokenOptions.h"

/// @defgroup RTC RTC
/// @file PPF_Request_Rtc.h
/// @ingroup RTC

/// @brief Retrieve a new RTC token.
///
/// @param options The options to get token.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Rtc_GetToken will be generated in response.
/// Call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type const char*.
/// Extract the payload from the message handle with ::ppf_Message_GetString()
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Rtc_GetToken(ppfRtcGetTokenOptionsHandle options);

#endif

