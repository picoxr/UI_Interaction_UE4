#ifndef PPF_ACHIEVEMENTDEFINITIONARRAY_H
#define PPF_ACHIEVEMENTDEFINITIONARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_AchievementDefinition.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfAchievementDefinitionArray *ppfAchievementDefinitionArrayHandle;

PPF_PUBLIC_FUNCTION(ppfAchievementDefinitionHandle) ppf_AchievementDefinitionArray_GetElement(const ppfAchievementDefinitionArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)                   ppf_AchievementDefinitionArray_GetNextUrl(const ppfAchievementDefinitionArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                         ppf_AchievementDefinitionArray_GetSize(const ppfAchievementDefinitionArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                         ppf_AchievementDefinitionArray_GetTotalSize(const ppfAchievementDefinitionArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                           ppf_AchievementDefinitionArray_HasNextPage(const ppfAchievementDefinitionArrayHandle obj);

#endif
