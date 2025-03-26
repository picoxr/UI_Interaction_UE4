// This file is generated automatically. Please don't edit it.

#ifndef PPF_PURCHASEARRAY_H
#define PPF_PURCHASEARRAY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include <stdbool.h>
#include <stddef.h>
#include "PPF_Purchase.h"


typedef struct ppfPurchaseArray *ppfPurchaseArrayHandle;



PPF_PUBLIC_FUNCTION(ppfPurchaseHandle) ppf_PurchaseArray_GetElement(const ppfPurchaseArrayHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_PurchaseArray_GetSize(const ppfPurchaseArrayHandle obj);


PPF_PUBLIC_FUNCTION(bool) ppf_PurchaseArray_HasNextPage(const ppfPurchaseArrayHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_PurchaseArray_GetNextPageParam(const ppfPurchaseArrayHandle obj);

#endif
