#ifndef PPF_LEADERBOARDUPDATESTATUS_H
#define PPF_LEADERBOARDUPDATESTATUS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>

typedef struct ppfLeaderboardUpdateStatus *ppfLeaderboardUpdateStatusHandle;

PPF_PUBLIC_FUNCTION(bool)         ppf_LeaderboardUpdateStatus_GetDidUpdate(const ppfLeaderboardUpdateStatusHandle obj);
PPF_PUBLIC_FUNCTION(ppfID)        ppf_LeaderboardUpdateStatus_GetUpdatedChallengeId(const ppfLeaderboardUpdateStatusHandle obj, unsigned int index);
PPF_PUBLIC_FUNCTION(unsigned int) ppf_LeaderboardUpdateStatus_GetUpdatedChallengeIdsSize(const ppfLeaderboardUpdateStatusHandle obj);

#endif
