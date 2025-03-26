// This file is generated automatically. Please don't edit it.


#ifndef PPF_PURCHASE_H
#define PPF_PURCHASE_H

#include "PPF_Types.h"
#include "PPF_AddonsType.h"
#include "PPF_PeriodType.h"
#include "PPF_DiscountType.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfPurchase *ppfPurchaseHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_Purchase_GetExpirationTime(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Purchase_GetGrantTime(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetID(const ppfPurchaseHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetSKU(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetIcon(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(ppfAddonsType) ppf_Purchase_GetAddonsType(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetOuterId(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(ppfPeriodType) ppf_Purchase_GetCurrentPeriodType(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(ppfPeriodType) ppf_Purchase_GetNextPeriodType(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(int64_t) ppf_Purchase_GetNextPayTime(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(ppfDiscountType) ppf_Purchase_GetDiscountType(const ppfPurchaseHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Purchase_GetOrderComment(const ppfPurchaseHandle obj);


#endif

