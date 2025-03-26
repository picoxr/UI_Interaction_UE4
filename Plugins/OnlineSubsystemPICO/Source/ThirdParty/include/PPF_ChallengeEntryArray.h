#ifndef PPF_CHALLENGEENTRYARRAY_H
#define PPF_CHALLENGEENTRYARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_ChallengeEntry.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfChallengeEntryArray *ppfChallengeEntryArrayHandle;

PPF_PUBLIC_FUNCTION(ppfChallengeEntryHandle) ppf_ChallengeEntryArray_GetElement(const ppfChallengeEntryArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)            ppf_ChallengeEntryArray_GetNextUrl(const ppfChallengeEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(const char *)            ppf_ChallengeEntryArray_GetPreviousUrl(const ppfChallengeEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                  ppf_ChallengeEntryArray_GetSize(const ppfChallengeEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long)      ppf_ChallengeEntryArray_GetTotalCount(const ppfChallengeEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                    ppf_ChallengeEntryArray_HasNextPage(const ppfChallengeEntryArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                    ppf_ChallengeEntryArray_HasPreviousPage(const ppfChallengeEntryArrayHandle obj);

#endif
