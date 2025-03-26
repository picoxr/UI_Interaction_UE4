#ifndef PPF_ACHIEVEMENTPROGRESSARRAY_H
#define PPF_ACHIEVEMENTPROGRESSARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_AchievementProgress.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfAchievementProgressArray *ppfAchievementProgressArrayHandle;

PPF_PUBLIC_FUNCTION(ppfAchievementProgressHandle) ppf_AchievementProgressArray_GetElement(const ppfAchievementProgressArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)                 ppf_AchievementProgressArray_GetNextUrl(const ppfAchievementProgressArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                       ppf_AchievementProgressArray_GetSize(const ppfAchievementProgressArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                       ppf_AchievementProgressArray_GetTotalSize(const ppfAchievementProgressArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                         ppf_AchievementProgressArray_HasNextPage(const ppfAchievementProgressArrayHandle obj);

#endif
