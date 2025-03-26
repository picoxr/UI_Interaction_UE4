#ifndef PPF_MATCHMAKINGSTATS_H
#define PPF_MATCHMAKINGSTATS_H

#include "PPF_Platform_Defs.h"

/// @file PPF_MatchmakingStats.h
/// @ingroup Game

typedef struct ppfMatchmakingStats *ppfMatchmakingStatsHandle;

PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingStats_GetDrawCount(const ppfMatchmakingStatsHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingStats_GetLossCount(const ppfMatchmakingStatsHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingStats_GetSkillLevel(const ppfMatchmakingStatsHandle obj);
PPF_PUBLIC_FUNCTION(double)       ppf_MatchmakingStats_GetSkillMean(const ppfMatchmakingStatsHandle obj);
PPF_PUBLIC_FUNCTION(double)       ppf_MatchmakingStats_GetSkillStandardDeviation(const ppfMatchmakingStatsHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int) ppf_MatchmakingStats_GetWinCount(const ppfMatchmakingStatsHandle obj);

#endif
