#ifndef PPF_MATCHMAKING_OPTIONS_H
#define PPF_MATCHMAKING_OPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_RoomJoinPolicy.h"

/// @file PPF_MatchmakingOptions.h
/// @ingroup Game

struct ppfMatchmakingOptions;
typedef struct ppfMatchmakingOptions* ppfMatchmakingOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingOptionsHandle) ppf_MatchmakingOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_Destroy(ppfMatchmakingOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetCreateRoomDataStoreString(ppfMatchmakingOptionsHandle handle, const char* key, const char* value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_ClearCreateRoomDataStore(ppfMatchmakingOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle handle, ppfRoomJoinPolicy value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetCreateRoomMaxUsers(ppfMatchmakingOptionsHandle handle, unsigned int value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_ClearEnqueueAdditionalUsers(ppfMatchmakingOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetEnqueueDataSettingsInt(ppfMatchmakingOptionsHandle handle, const char* key, int value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetEnqueueDataSettingsDouble(ppfMatchmakingOptionsHandle handle, const char* key, double value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetEnqueueDataSettingsString(ppfMatchmakingOptionsHandle handle, const char* key, const char* value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_ClearEnqueueDataSettings(ppfMatchmakingOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetEnqueueIsDebug(ppfMatchmakingOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_MatchmakingOptions_SetEnqueueQueryKey(ppfMatchmakingOptionsHandle handle, const char * value);

#endif
