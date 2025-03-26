#ifndef PPF_KEY_VALUE_PAIR_TYPE_H
#define PPF_KEY_VALUE_PAIR_TYPE_H

#include "PPF_Platform_Defs.h"

/// @file PPF_KeyValuePairType.h
/// @ingroup Global

typedef enum ppfKeyValuePairType_ {
  ppfKeyValuePairType_String,
  ppfKeyValuePairType_Int,
  ppfKeyValuePairType_Double,
  ppfKeyValuePairType_Unknown,
} ppfKeyValuePairType;

/// Converts an ppfKeyValuePairType enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfKeyValuePairType_ToString(ppfKeyValuePairType value);

/// Converts a string representing an ppfKeyValuePairType enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfKeyValuePairType) ppfKeyValuePairType_FromString(const char* str);

#endif
