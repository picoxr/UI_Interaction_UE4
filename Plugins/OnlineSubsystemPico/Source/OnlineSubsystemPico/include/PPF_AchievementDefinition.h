#ifndef PPF_ACHIEVEMENTDEFINITION_H
#define PPF_ACHIEVEMENTDEFINITION_H

#include "PPF_Platform_Defs.h"
#include "PPF_AchievementType.h"
#include "PPF_AchievementWritePolicy.h"
#include "PPF_Types.h"

typedef struct ppfAchievementDefinition *ppfAchievementDefinitionHandle;

PPF_PUBLIC_FUNCTION(ppfID)                      ppf_AchievementDefinition_GetID(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char *)               ppf_AchievementDefinition_GetName(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(unsigned int)               ppf_AchievementDefinition_GetBitfieldLength(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(long long)                  ppf_AchievementDefinition_GetTarget(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(ppfAchievementType)         ppf_AchievementDefinition_GetType(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(ppfAchievementWritePolicy)  ppf_AchievementDefinition_GetWritePolicy(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(bool)                       ppf_AchievementDefinition_IsArchived(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(bool)                       ppf_AchievementDefinition_IsSecret(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                ppf_AchievementDefinition_GetTitle(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                ppf_AchievementDefinition_GetDescription(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                ppf_AchievementDefinition_GetUnlockedDescription(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                ppf_AchievementDefinition_GetLockedImageURL(const ppfAchievementDefinitionHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                ppf_AchievementDefinition_GetUnlockedImageURL(const ppfAchievementDefinitionHandle obj);

#endif
