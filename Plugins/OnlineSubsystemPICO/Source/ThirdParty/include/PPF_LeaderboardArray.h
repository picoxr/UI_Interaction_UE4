#ifndef PPF_LEADERBOARDARRAY_H
#define PPF_LEADERBOARDARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Leaderboard.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfLeaderboardArray *ppfLeaderboardArrayHandle;

PPF_PUBLIC_FUNCTION(ppfLeaderboardHandle) ppf_LeaderboardArray_GetElement(const ppfLeaderboardArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)         ppf_LeaderboardArray_GetNextUrl(const ppfLeaderboardArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)               ppf_LeaderboardArray_GetSize(const ppfLeaderboardArrayHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long)   ppf_LeaderboardArray_GetTotalCount(const ppfLeaderboardArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                 ppf_LeaderboardArray_HasNextPage(const ppfLeaderboardArrayHandle obj);

#endif
