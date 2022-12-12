#ifndef PPF_CHALLENGEENTRY_H
#define PPF_CHALLENGEENTRY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include "PPF_User.h"

typedef struct ppfChallengeEntry *ppfChallengeEntryHandle;

PPF_PUBLIC_FUNCTION(const char *)       ppf_ChallengeEntry_GetDisplayScore(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(const void *)       ppf_ChallengeEntry_GetExtraData(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int)       ppf_ChallengeEntry_GetExtraDataLength(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(ppfID)              ppf_ChallengeEntry_GetID(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(int)                ppf_ChallengeEntry_GetRank(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(long long)          ppf_ChallengeEntry_GetScore(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_ChallengeEntry_GetTimestamp(const ppfChallengeEntryHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserHandle)      ppf_ChallengeEntry_GetUser(const ppfChallengeEntryHandle obj);

#endif
