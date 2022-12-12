// This file is generated automatically. Please don't edit it.


#ifndef PPF_PURCHASE_H
#define PPF_PURCHASE_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfPurchase *ppfPurchaseHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_Purchase_GetExpirationTime(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Purchase_GetGrantTime(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetID(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetSKU(const ppfPurchaseHandle obj);



#endif

