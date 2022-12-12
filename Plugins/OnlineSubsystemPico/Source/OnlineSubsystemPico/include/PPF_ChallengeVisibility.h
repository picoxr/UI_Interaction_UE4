#ifndef PPF_CHALLENGE_VISIBILITY_H
#define PPF_CHALLENGE_VISIBILITY_H

#include "PPF_Platform_Defs.h"

typedef enum ppfChallengeVisibility_ {
  ppfChallengeVisibility_Unknown,
  /// Only those invited can participate in it. Everyone can see it
  ppfChallengeVisibility_InviteOnly,
  /// Everyone can participate and see this challenge
  ppfChallengeVisibility_Public,
  /// Only those invited can participate and see this challenge
  ppfChallengeVisibility_Private,
} ppfChallengeVisibility;

/// Converts an ppfChallengeVisibility enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfChallengeVisibility_ToString(ppfChallengeVisibility value);

/// Converts a string representing an ppfChallengeVisibility enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfChallengeVisibility) ppfChallengeVisibility_FromString(const char* str);

#endif
