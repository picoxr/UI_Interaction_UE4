// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCGETTOKENOPTIONS_H
#define PPF_RTCGETTOKENOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RtcPrivilege.h"


/// @file PPF_RtcGetTokenOptions.h
/// @ingroup RTC


struct ppfRtcGetTokenOptions;
typedef struct ppfRtcGetTokenOptions *ppfRtcGetTokenOptionsHandle;

PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_Destroy(ppfRtcGetTokenOptionsHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcGetTokenOptionsHandle) ppf_RtcGetTokenOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_SetUserId(ppfRtcGetTokenOptionsHandle obj,const char* value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_SetRoomId(ppfRtcGetTokenOptionsHandle obj,const char* value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_SetTtl(ppfRtcGetTokenOptionsHandle obj,int value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_ClearPrivileges(ppfRtcGetTokenOptionsHandle obj);

PPF_PUBLIC_FUNCTION(void) ppf_RtcGetTokenOptions_SetPrivileges(ppfRtcGetTokenOptionsHandle obj,ppfRtcPrivilege k,int v);


#endif

