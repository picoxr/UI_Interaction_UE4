#ifndef PPF_MATCHMAKINGADMINSNAPSHOTCANDIDATEARRAY_H
#define PPF_MATCHMAKINGADMINSNAPSHOTCANDIDATEARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_MatchmakingAdminSnapshotCandidate.h"
#include <stddef.h>

/// @file PPF_MatchmakingAdminSnapshotCandidateArray.h
/// @ingroup Game

typedef struct ppfMatchmakingAdminSnapshotCandidateArray *ppfMatchmakingAdminSnapshotCandidateArrayHandle;

PPF_PUBLIC_FUNCTION(ppfMatchmakingAdminSnapshotCandidateHandle) ppf_MatchmakingAdminSnapshotCandidateArray_GetElement(const ppfMatchmakingAdminSnapshotCandidateArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(size_t)                                     ppf_MatchmakingAdminSnapshotCandidateArray_GetSize(const ppfMatchmakingAdminSnapshotCandidateArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                                     ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount(const ppfMatchmakingAdminSnapshotCandidateArrayHandle obj);

#endif
