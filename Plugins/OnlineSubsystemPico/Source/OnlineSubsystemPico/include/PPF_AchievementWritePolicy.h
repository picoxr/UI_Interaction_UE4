#ifndef PPF_ACHIEVEMENT_WRITE_POLICY_H
#define PPF_ACHIEVEMENT_WRITE_POLICY_H

#include "PPF_Platform_Defs.h"

typedef enum ppfAchievementWritePolicy_ {
  ppfAchievement_WritePolicyUnknown,
  ppfAchievement_WritePolicyClient,
  ppfAchievement_WritePolicyServer,
} ppfAchievementWritePolicy;

PPF_PUBLIC_FUNCTION(const char*) ppfAchievementWritePolicy_ToString(ppfAchievementWritePolicy value);
PPF_PUBLIC_FUNCTION(ppfAchievementWritePolicy) ppfAchievementWritePolicy_FromString(const char* str);

#endif
