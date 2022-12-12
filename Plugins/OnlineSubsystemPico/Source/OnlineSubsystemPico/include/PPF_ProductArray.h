// This file is generated automatically. Please don't edit it.

#ifndef PPF_PRODUCTARRAY_H
#define PPF_PRODUCTARRAY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include <stdbool.h>
#include <stddef.h>
#include "PPF_Product.h"


typedef struct ppfProductArray *ppfProductArrayHandle;



PPF_PUBLIC_FUNCTION(ppfProductHandle) ppf_ProductArray_GetElement(const ppfProductArrayHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_ProductArray_GetSize(const ppfProductArrayHandle obj);


PPF_PUBLIC_FUNCTION(bool) ppf_ProductArray_HasNextPage(const ppfProductArrayHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_ProductArray_GetNextPageParam(const ppfProductArrayHandle obj);

#endif
