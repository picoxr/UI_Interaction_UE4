#ifndef PPF_ACHIEVEMENTUPDATE_H
#define PPF_ACHIEVEMENTUPDATE_H

#include "PPF_Platform_Defs.h"
#include <stdbool.h>

typedef struct ppfAchievementUpdate *ppfAchievementUpdateHandle;

PPF_PUBLIC_FUNCTION(bool)         ppf_AchievementUpdate_GetJustUnlocked(const ppfAchievementUpdateHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_AchievementUpdate_GetName(const ppfAchievementUpdateHandle obj);

#endif
