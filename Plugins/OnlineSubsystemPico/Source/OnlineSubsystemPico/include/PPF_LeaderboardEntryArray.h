#ifndef PPF_LEADERBOARDENTRYARRAY_H
#define PPF_LEADERBOARDENTRYARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_LeaderboardEntry.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfLeaderboardEntryArray *ppfLeaderboardEntryArrayHandle;

PPF_PUBLIC_FUNCTION(ppfLeaderboardEntryHandle) ppf_LeaderboardEntryArray_GetElement(const ppfLeaderboardEntryArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)              ppf_LeaderboardEntryArray_GetNextUrl(const ppfLeaderboardEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(const char *)              ppf_LeaderboardEntryArray_GetPreviousUrl(const ppfLeaderboardEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                    ppf_LeaderboardEntryArray_GetSize(const ppfLeaderboardEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long)        ppf_LeaderboardEntryArray_GetTotalCount(const ppfLeaderboardEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                      ppf_LeaderboardEntryArray_HasNextPage(const ppfLeaderboardEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                      ppf_LeaderboardEntryArray_HasPreviousPage(const ppfLeaderboardEntryArrayHandle obj);

#endif
