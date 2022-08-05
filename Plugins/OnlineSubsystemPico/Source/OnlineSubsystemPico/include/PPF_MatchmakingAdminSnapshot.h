#ifndef PPF_MATCHMAKINGADMINSNAPSHOT_H
#define PPF_MATCHMAKINGADMINSNAPSHOT_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingAdminSnapshotCandidateArray.h"

/// @file PPF_MatchmakingAdminSnapshot.h
/// @ingroup Game

typedef struct ppfMatchmakingAdminSnapshot *ppfMatchmakingAdminSnapshotHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingAdminSnapshotCandidateArrayHandle) ppf_MatchmakingAdminSnapshot_GetCandidates(const ppfMatchmakingAdminSnapshotHandle obj);
PPF_PUBLIC_FUNCTION(double)                                          ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold(const ppfMatchmakingAdminSnapshotHandle obj);

#endif
