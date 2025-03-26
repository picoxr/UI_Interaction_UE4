#ifndef PPF_MATCHMAKING_CRITERION_IMPORTANCE_H
#define PPF_MATCHMAKING_CRITERION_IMPORTANCE_H

#include "PPF_Platform_Defs.h"

/// @file PPF_MatchmakingCriterionImportance.h
/// @ingroup Game

typedef enum ppfMatchmakingCriterionImportance_ {
    ppfMatchmaking_CriterionImportanceRequired = 0,
    ppfMatchmaking_CriterionImportanceHigh     = 1,
    ppfMatchmaking_CriterionImportanceMedium   = 2,
    ppfMatchmaking_CriterionImportanceLow      = 3,
    ppfMatchmaking_CriterionImportanceUnknown  = 4,
} ppfMatchmakingCriterionImportance;

PPF_PUBLIC_FUNCTION(const char*) ppfMatchmakingCriterionImportance_ToString(ppfMatchmakingCriterionImportance value);

PPF_PUBLIC_FUNCTION(ppfMatchmakingCriterionImportance) ppfMatchmakingCriterionImportance_FromString(const char* str);

#endif
