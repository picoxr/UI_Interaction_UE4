#ifndef PPF_MATCHMAKINGENQUEUERESULT_H
#define PPF_MATCHMAKINGENQUEUERESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingAdminSnapshot.h"

/// @file PPF_MatchmakingEnqueueResult.h
/// @ingroup Game

typedef struct ppfMatchmakingEnqueueResult *ppfMatchmakingEnqueueResultHandle;

/// @brief Get snapshot from the enqueue result
/// @param obj Result handle from enqueue response
/// @return Handle of the snapshot
///
/// If 'IsDebug' is set in ppfMatchmakingOptionsHandle, this will return with the enqueue results.
/// Note don't set 'IsDebug' in production environment
/// This method may return null. This indicates that the value is not present
PPF_PUBLIC_FUNCTION(ppfMatchmakingAdminSnapshotHandle) ppf_MatchmakingEnqueueResult_GetAdminSnapshot(const ppfMatchmakingEnqueueResultHandle obj);

/// @brief Get average wait time from the enqueue result
/// @param obj Result handle from enqueue response
/// @return Average amount of wait time(seconds) that users in this queue have waited
///
/// The wait times, whether the users canceled or found a match, are used to generate this value. 
/// Use this to give users an indication of how long they can expect to wait.
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingEnqueueResult_GetAverageWait(const ppfMatchmakingEnqueueResultHandle obj);

/// @brief Get match times from the enqueue result
/// @param obj Result handle from enqueue response
/// @return Number of matches made from the pool ther user is currently in
///
/// Use this to give users an indication of whether they should bother to wait.
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount(const ppfMatchmakingEnqueueResultHandle obj);

/// @brief Get max expected wait time from the enqueue result
/// @param obj Result handle from enqueue response
/// @return The amount of time the 95th percentile waited during the last hour or more.
///
/// Use this to give users an indication of the maximum amount of time they can expect to wait.
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingEnqueueResult_GetMaxExpectedWait(const ppfMatchmakingEnqueueResultHandle obj);

/// @brief Get match percentage from the enqueue result
/// @param obj Result handle from enqueue response
/// @return Percentage of people who got matched
/// 
/// Use this to give users an indication of whether they should wait.
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage(const ppfMatchmakingEnqueueResultHandle obj);

/// @brief Get pool name from the enqueue result
/// @param obj Result handle from enqueue response
/// @return Pool name
PPF_PUBLIC_FUNCTION(const char *) ppf_MatchmakingEnqueueResult_GetPool(const ppfMatchmakingEnqueueResultHandle obj);

#endif
