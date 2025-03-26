#ifndef PPF_LEADERBOARDENTRY_H
#define PPF_LEADERBOARDENTRY_H

#include "PPF_Platform_Defs.h"
#include "PPF_SupplementaryMetric.h"
#include "PPF_Types.h"
#include "PPF_User.h"

typedef struct ppfLeaderboardEntry *ppfLeaderboardEntryHandle;

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
PPF_PUBLIC_FUNCTION(ppfSupplementaryMetricHandle) ppf_LeaderboardEntry_GetSupplementaryMetric(const ppfLeaderboardEntryHandle obj);

PPF_PUBLIC_FUNCTION(const char *)       ppf_LeaderboardEntry_GetDisplayScore(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(const void *)       ppf_LeaderboardEntry_GetExtraData(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int)       ppf_LeaderboardEntry_GetExtraDataLength(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(ppfID)              ppf_LeaderboardEntry_GetID(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(int)                ppf_LeaderboardEntry_GetRank(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(long long)          ppf_LeaderboardEntry_GetScore(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_LeaderboardEntry_GetTimestamp(const ppfLeaderboardEntryHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserHandle)      ppf_LeaderboardEntry_GetUser(const ppfLeaderboardEntryHandle obj);

#endif
