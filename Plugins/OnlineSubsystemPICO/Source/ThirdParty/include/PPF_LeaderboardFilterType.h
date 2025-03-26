#ifndef PPF_LEADERBOARD_FILTER_TYPE_H
#define PPF_LEADERBOARD_FILTER_TYPE_H

#include "PPF_Platform_Defs.h"

typedef enum ppfLeaderboardFilterType_ {
    ppfLeaderboard_FilterNone    = 0,
    ppfLeaderboard_FilterFriends = 1,
    ppfLeaderboard_FilterUnknown = 2,
    ppfLeaderboard_FilterUserIds = 3,
} ppfLeaderboardFilterType;

/// Converts an ppfLeaderboardFilterType enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfLeaderboardFilterType_ToString(ppfLeaderboardFilterType value);

/// Converts a string representing an ppfLeaderboardFilterType enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfLeaderboardFilterType) ppfLeaderboardFilterType_FromString(const char* str);

#endif
