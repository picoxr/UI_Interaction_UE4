// This file is generated automatically. Please don't edit it.

#ifndef PPF_RTCROOMOPTIONS_H
#define PPF_RTCROOMOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RtcRoomProfileType.h"

/// @file PPF_RtcRoomOptions.h
/// @ingroup RTC

struct ppfRtcRoomOptions;
typedef struct ppfRtcRoomOptions *ppfRtcRoomOptionsHandle;



PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_Destroy(ppfRtcRoomOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcRoomOptionsHandle) ppf_RtcRoomOptions_Create();

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetRoomProfileType(ppfRtcRoomOptionsHandle obj,ppfRtcRoomProfileType value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetIsAutoSubscribeAudio(ppfRtcRoomOptionsHandle obj,bool value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetRoomId(ppfRtcRoomOptionsHandle obj,const char* value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetUserId(ppfRtcRoomOptionsHandle obj,const char* value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetUserExtra(ppfRtcRoomOptionsHandle obj,const char* value);

PPF_PUBLIC_FUNCTION(void) ppf_RtcRoomOptions_SetToken(ppfRtcRoomOptionsHandle obj,const char* value);


#endif

