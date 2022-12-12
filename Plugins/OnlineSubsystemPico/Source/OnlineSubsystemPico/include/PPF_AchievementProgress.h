#ifndef PPF_ACHIEVEMENTPROGRESS_H
#define PPF_ACHIEVEMENTPROGRESS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>

typedef struct ppfAchievementProgress *ppfAchievementProgressHandle;

PPF_PUBLIC_FUNCTION(ppfID)              ppf_AchievementProgress_GetID(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(const char *)       ppf_AchievementProgress_GetBitfield(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(long long)          ppf_AchievementProgress_GetCount(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(bool)               ppf_AchievementProgress_GetIsUnlocked(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(const char *)       ppf_AchievementProgress_GetName(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_AchievementProgress_GetUnlockTime(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(const void *)       ppf_AchievementProgress_GetExtraData(const ppfAchievementProgressHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int)       ppf_AchievementProgress_GetExtraDataLength(const ppfAchievementProgressHandle obj);

#endif
