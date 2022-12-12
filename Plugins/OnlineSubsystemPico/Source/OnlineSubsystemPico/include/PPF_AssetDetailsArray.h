#ifndef PPF_ASSETDETAILSARRAY_H
#define PPF_ASSETDETAILSARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_AssetDetails.h"
#include <stddef.h>

typedef struct ppfAssetDetailsArray *ppfAssetDetailsArrayHandle;

PPF_PUBLIC_FUNCTION(ppfAssetDetailsHandle) ppf_AssetDetailsArray_GetElement(const ppfAssetDetailsArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(size_t)                ppf_AssetDetailsArray_GetSize(const ppfAssetDetailsArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                  ppf_AssetDetailsArray_HasNextPage(const ppfAssetDetailsArrayHandle obj);
PPF_PUBLIC_FUNCTION(const char*)           ppf_AssetDetailsArray_GetNextPageParam(const ppfAssetDetailsArrayHandle obj);
#endif
