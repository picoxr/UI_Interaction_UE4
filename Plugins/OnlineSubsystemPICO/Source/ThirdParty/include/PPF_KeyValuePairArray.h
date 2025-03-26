#ifndef PPF_KEY_VALUE_PAIR_ARRAY_H
#define PPF_KEY_VALUE_PAIR_ARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_KeyValuePair.h"

/// @file PPF_KeyValuePairArray.h
/// @ingroup Global

typedef struct ppfKeyValuePair *ppfKeyValuePairArray;

PPF_PUBLIC_FUNCTION(ppfKeyValuePairArray) ppf_KeyValuePairArray_Create(const size_t size);
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePairArray_Destroy(const ppfKeyValuePairArray obj);

PPF_PUBLIC_FUNCTION(ppfKeyValuePairHandle) ppf_KeyValuePairArray_GetElement(const ppfKeyValuePairArray obj, const size_t index);

#endif  // PPF_KEY_VALUE_PAIR_ARRAY_H
