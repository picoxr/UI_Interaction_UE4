#ifndef PPF_LEADERBOARD_START_AT_H
#define PPF_LEADERBOARD_START_AT_H

#include "PPF_Platform_Defs.h"

typedef enum ppfLeaderboardStartAt_ {
    ppfLeaderboard_StartAtTop                   = 0,
    ppfLeaderboard_StartAtCenteredOnViewer      = 1,
    ppfLeaderboard_StartAtCenteredOnViewerOrTop = 2,
    ppfLeaderboard_StartAtUnknown               = 3,
} ppfLeaderboardStartAt;

/// Converts an ppfLeaderboardStartAt enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfLeaderboardStartAt_ToString(ppfLeaderboardStartAt value);

/// Converts a string representing an ppfLeaderboardStartAt enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfLeaderboardStartAt) ppfLeaderboardStartAt_FromString(const char* str);

#endif
