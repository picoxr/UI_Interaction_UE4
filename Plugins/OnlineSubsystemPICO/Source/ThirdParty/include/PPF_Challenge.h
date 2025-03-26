#ifndef PPF_CHALLENGE_H
#define PPF_CHALLENGE_H

#include "PPF_Platform_Defs.h"
#include "PPF_ChallengeCreationType.h"
#include "PPF_ChallengeVisibility.h"
#include "PPF_Leaderboard.h"
#include "PPF_Types.h"
#include "PPF_UserArray.h"

typedef struct ppfChallenge *ppfChallengeHandle;
PPF_PUBLIC_FUNCTION(ppfChallengeCreationType) ppf_Challenge_GetCreationType(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle) ppf_Challenge_GetInvitedUsers(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(ppfLeaderboardHandle) ppf_Challenge_GetLeaderboard(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle) ppf_Challenge_GetParticipants(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_Challenge_GetTitle(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(ppfChallengeVisibility) ppf_Challenge_GetVisibility(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_Challenge_GetEndDate(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(ppfID) ppf_Challenge_GetID(const ppfChallengeHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_Challenge_GetStartDate(const ppfChallengeHandle obj);
#endif
