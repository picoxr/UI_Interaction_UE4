#ifndef PPF_CHALLENGE_OPTIONS_H
#define PPF_CHALLENGE_OPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_ChallengeViewerFilter.h"
#include "PPF_ChallengeVisibility.h"

struct ppfChallengeOptions;
typedef struct ppfChallengeOptions* ppfChallengeOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfChallengeOptionsHandle) ppf_ChallengeOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_Destroy(ppfChallengeOptionsHandle handle);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetEndDate(ppfChallengeOptionsHandle handle, unsigned long long value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetIncludeActiveChallenges(ppfChallengeOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetIncludeFutureChallenges(ppfChallengeOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetIncludePastChallenges(ppfChallengeOptionsHandle handle, bool value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetLeaderboardName(ppfChallengeOptionsHandle handle, const char * value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetStartDate(ppfChallengeOptionsHandle handle, unsigned long long value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetTitle(ppfChallengeOptionsHandle handle, const char * value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle handle, ppfChallengeViewerFilter value);
PPF_PUBLIC_FUNCTION(void) ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle handle, ppfChallengeVisibility value);

#endif
