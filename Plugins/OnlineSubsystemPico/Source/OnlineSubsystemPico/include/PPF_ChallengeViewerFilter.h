#ifndef PPF_CHALLENGE_VIEWER_FILTER_H
#define PPF_CHALLENGE_VIEWER_FILTER_H

#include "PPF_Platform_Defs.h"

typedef enum ppfChallengeViewerFilter_ {
  ppfChallengeViewerFilter_Unknown,
  ppfChallengeViewerFilter_AllVisible,
  ppfChallengeViewerFilter_Participating,
  ppfChallengeViewerFilter_Invited,
  ppfChallengeViewerFilter_ParticipatingOrInvited,
} ppfChallengeViewerFilter;

/// Converts an ppfChallengeViewerFilter enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfChallengeViewerFilter_ToString(ppfChallengeViewerFilter value);

/// Converts a string representing an ppfChallengeViewerFilter enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfChallengeViewerFilter) ppfChallengeViewerFilter_FromString(const char* str);

#endif
