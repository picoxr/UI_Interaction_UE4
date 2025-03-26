#ifndef PPF_DATASTORE_H
#define PPF_DATASTORE_H

#include "PPF_Platform_Defs.h"
#include <stddef.h>

/// @file PPF_DataStore.h
/// @ingroup Global

typedef struct ppfDataStore *ppfDataStoreHandle;

PPF_PUBLIC_FUNCTION(unsigned int) ppf_DataStore_Contains(const ppfDataStoreHandle obj, const char *key);
PPF_PUBLIC_FUNCTION(const char *) ppf_DataStore_GetKey(const ppfDataStoreHandle obj, int index);
PPF_PUBLIC_FUNCTION(size_t)       ppf_DataStore_GetNumKeys(const ppfDataStoreHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_DataStore_GetValue(const ppfDataStoreHandle obj, const char *key);

#endif
