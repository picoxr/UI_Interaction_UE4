#ifndef PPF_CHALLENGE_CREATION_TYPE_H
#define PPF_CHALLENGE_CREATION_TYPE_H

#include "PPF_Platform_Defs.h"

typedef enum ppfChallengeCreationType_ {
  ppfChallengeCreationType_Unknown,
  ppfChallengeCreationType_UserCreated,
  ppfChallengeCreationType_DeveloperCreated,
} ppfChallengeCreationType;

/// Converts an ppfChallengeCreationType enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfChallengeCreationType_ToString(ppfChallengeCreationType value);

/// Converts a string representing an ppfChallengeCreationType enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfChallengeCreationType) ppfChallengeCreationType_FromString(const char* str);

#endif
