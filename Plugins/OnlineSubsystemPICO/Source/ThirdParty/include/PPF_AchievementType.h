#ifndef PPF_ACHIEVEMENT_TYPE_H
#define PPF_ACHIEVEMENT_TYPE_H

#include "PPF_Platform_Defs.h"

typedef enum ppfAchievementType_ {
  ppfAchievement_TypeUnknown,
  ppfAchievement_TypeSimple,
  ppfAchievement_TypeCount,
  ppfAchievement_TypeBitfield,
} ppfAchievementType;

/// Converts an ppfAchievementType enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfAchievementType_ToString(ppfAchievementType value);

/// Converts a string representing an ppfAchievementType enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfAchievementType) ppfAchievementType_FromString(const char* str);

#endif
