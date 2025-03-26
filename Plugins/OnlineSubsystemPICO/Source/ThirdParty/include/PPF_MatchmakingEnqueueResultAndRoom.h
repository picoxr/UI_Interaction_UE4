#ifndef PPF_MATCHMAKINGENQUEUERESULTANDROOM_H
#define PPF_MATCHMAKINGENQUEUERESULTANDROOM_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingEnqueueResult.h"
#include "PPF_Room.h"

/// @file PPF_MatchmakingEnqueueResultAndRoom.h
/// @ingroup Game

typedef struct ppfMatchmakingEnqueueResultAndRoom *ppfMatchmakingEnqueueResultAndRoomHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultHandle) ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(const ppfMatchmakingEnqueueResultAndRoomHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomHandle)                     ppf_MatchmakingEnqueueResultAndRoom_GetRoom(const ppfMatchmakingEnqueueResultAndRoomHandle obj);

#endif
