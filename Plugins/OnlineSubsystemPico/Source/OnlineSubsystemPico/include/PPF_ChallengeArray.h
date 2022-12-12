#ifndef PPF_CHALLENGEARRAY_H
#define PPF_CHALLENGEARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Challenge.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfChallengeArray *ppfChallengeArrayHandle;

PPF_PUBLIC_FUNCTION(ppfChallengeHandle) ppf_ChallengeArray_GetElement(const ppfChallengeArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)       ppf_ChallengeArray_GetNextUrl(const ppfChallengeArrayHandle obj);
PPF_PUBLIC_FUNCTION(const char *)       ppf_ChallengeArray_GetPreviousUrl(const ppfChallengeArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)             ppf_ChallengeArray_GetSize(const ppfChallengeArrayHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_ChallengeArray_GetTotalCount(const ppfChallengeArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)               ppf_ChallengeArray_HasNextPage(const ppfChallengeArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)               ppf_ChallengeArray_HasPreviousPage(const ppfChallengeArrayHandle obj);

#endif