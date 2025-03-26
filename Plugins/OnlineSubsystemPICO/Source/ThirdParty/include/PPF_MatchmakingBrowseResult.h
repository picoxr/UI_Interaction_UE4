#ifndef PPF_MATCHMAKINGBROWSERESULT_H
#define PPF_MATCHMAKINGBROWSERESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingEnqueueResult.h"
#include "PPF_MatchmakingRoomArray.h"

/// @file PPF_MatchmakingBrowserResult.h
/// @ingroup Game

typedef struct ppfMatchmakingBrowseResult *ppfMatchmakingBrowseResultHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultHandle) ppf_MatchmakingBrowseResult_GetEnqueueResult(const ppfMatchmakingBrowseResultHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingRoomArrayHandle)     ppf_MatchmakingBrowseResult_GetRooms(const ppfMatchmakingBrowseResultHandle obj);

#endif
