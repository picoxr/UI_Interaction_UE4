#ifndef PPF_KEY_VALUE_PAIR_H
#define PPF_KEY_VALUE_PAIR_H

#include "PPF_Platform_Defs.h"
#include "PPF_KeyValuePairType.h"

/// @file PPF_KeyValuePair.h
/// @ingroup Global

typedef struct ppfKeyValuePair *ppfKeyValuePairHandle;

PPF_PUBLIC_FUNCTION(ppfKeyValuePairHandle) ppf_KeyValuePair_Create();
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePair_Destroy(const ppfKeyValuePairHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_KeyValuePair_GetKey(const ppfKeyValuePairHandle obj);
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePair_SetKey(const ppfKeyValuePairHandle obj, const char* key);

PPF_PUBLIC_FUNCTION(ppfKeyValuePairType) ppf_KeyValuePair_GetValueType(const ppfKeyValuePairHandle obj);

PPF_PUBLIC_FUNCTION(int) ppf_KeyValuePair_GetIntValue(const ppfKeyValuePairHandle obj);
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePair_SetIntValue(const ppfKeyValuePairHandle obj, int value);

PPF_PUBLIC_FUNCTION(double) ppf_KeyValuePair_GetDoubleValue(const ppfKeyValuePairHandle obj);
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePair_SetDoubleValue(const ppfKeyValuePairHandle obj, double value);

PPF_PUBLIC_FUNCTION(const char*) ppf_KeyValuePair_GetStringValue(const ppfKeyValuePairHandle obj);
PPF_PUBLIC_FUNCTION(void) ppf_KeyValuePair_SetStringValue(const ppfKeyValuePairHandle obj, const char* value);


#endif  // PPF_KEY_VALUE_PAIR_H
