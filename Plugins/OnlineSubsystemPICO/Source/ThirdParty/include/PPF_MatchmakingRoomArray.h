#ifndef PPF_MATCHMAKINGROOMARRAY_H
#define PPF_MATCHMAKINGROOMARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingRoom.h"
#include <stddef.h>

/// @file PPF_MatchmakingRoomArray.h
/// @ingroup Game

typedef struct ppfMatchmakingRoomArray *ppfMatchmakingRoomArrayHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingRoomHandle) ppf_MatchmakingRoomArray_GetElement(const ppfMatchmakingRoomArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(size_t)                   ppf_MatchmakingRoomArray_GetSize(const ppfMatchmakingRoomArrayHandle obj);
PPF_PUBLIC_FUNCTION(int32_t)                  ppf_MatchmakingRoomArray_GetTotalCount(const ppfMatchmakingRoomArrayHandle obj);

#endif
