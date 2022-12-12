#ifndef PPF_LEADERBOARD_H
#define PPF_LEADERBOARD_H

#include "PPF_Platform_Defs.h"
#include "PPF_Destination.h"
#include "PPF_Types.h"

typedef struct ppfLeaderboard* ppfLeaderboardHandle;

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
PPF_PUBLIC_FUNCTION(ppfDestinationHandle) ppf_Leaderboard_GetDestination(const ppfLeaderboardHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Leaderboard_GetApiName(const ppfLeaderboardHandle obj);
PPF_PUBLIC_FUNCTION(ppfID) ppf_Leaderboard_GetID(const ppfLeaderboardHandle obj);

#endif
