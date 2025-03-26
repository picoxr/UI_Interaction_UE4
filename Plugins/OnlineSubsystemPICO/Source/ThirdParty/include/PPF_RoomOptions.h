#ifndef PPF_ROOM_OPTIONS_H
#define PPF_ROOM_OPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

/// @file PPF_RoomOptions.h
/// @ingroup Game

struct ppfRoomOptions;
typedef struct ppfRoomOptions* ppfRoomOptionsHandle;
typedef int64_t ppfTimeWindow;

typedef enum ppfUserOrdering_ {
    ppfUserOrdering_None                    = 0,
    ppfUserOrdering_PresenceAlphabetical    = 1
} ppfUserOrdering;

PPF_PUBLIC_FUNCTION(ppfRoomOptionsHandle) ppf_RoomOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_Destroy(ppfRoomOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetDataStoreString(ppfRoomOptionsHandle handle, const char* key, const char* value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_ClearDataStore(ppfRoomOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetExcludeRecentlyMet(ppfRoomOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetMaxUserResults(ppfRoomOptionsHandle handle, unsigned int value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetOrdering(ppfRoomOptionsHandle handle, ppfUserOrdering value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetRecentlyMetTimeWindow(ppfRoomOptionsHandle handle, ppfTimeWindow value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetRoomId(ppfRoomOptionsHandle handle, ppfID value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetTurnOffUpdates(ppfRoomOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetName(ppfRoomOptionsHandle handle, const char* name);
PPF_PUBLIC_FUNCTION(void) ppf_RoomOptions_SetPassword(ppfRoomOptionsHandle handle, const char* password);

#endif
