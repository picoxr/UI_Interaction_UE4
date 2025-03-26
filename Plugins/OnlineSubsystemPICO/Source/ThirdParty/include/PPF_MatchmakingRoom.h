#ifndef PPF_MATCHMAKINGROOM_H
#define PPF_MATCHMAKINGROOM_H

#include "PPF_Platform_Defs.h"
#include "PPF_Room.h"
#include <stdbool.h>

/// @file PPF_MatchmakingRoom.h
/// @ingroup Game

typedef struct ppfMatchmakingRoom *ppfMatchmakingRoomHandle;

PPF_PUBLIC_FUNCTION(unsigned int)  ppf_MatchmakingRoom_GetPingTime(const ppfMatchmakingRoomHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomHandle) ppf_MatchmakingRoom_GetRoom(const ppfMatchmakingRoomHandle obj);
PPF_PUBLIC_FUNCTION(bool)          ppf_MatchmakingRoom_HasPingTime(const ppfMatchmakingRoomHandle obj);

#endif
