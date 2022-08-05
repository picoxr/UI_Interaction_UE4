#ifndef PPF_MATCHMAKINGADMINSNAPSHOTCANDIDATE_H
#define PPF_MATCHMAKINGADMINSNAPSHOTCANDIDATE_H

#include "PPF_Platform_Defs.h"
#include <stdbool.h>

/// @file PPF_MatchmakingAdminSnapshotCandidate.h
/// @ingroup Game

typedef struct ppfMatchmakingAdminSnapshotCandidate *ppfMatchmakingAdminSnapshotCandidateHandle;

PPF_PUBLIC_FUNCTION(bool)         ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch(const ppfMatchmakingAdminSnapshotCandidateHandle obj);
PPF_PUBLIC_FUNCTION(double)       ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore(const ppfMatchmakingAdminSnapshotCandidateHandle obj);
PPF_PUBLIC_FUNCTION(double)       ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold(const ppfMatchmakingAdminSnapshotCandidateHandle obj);

#endif
