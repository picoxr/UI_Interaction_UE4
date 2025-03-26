// This file is generated automatically. Please don't edit it.


#ifndef PPF_PRODUCT_H
#define PPF_PRODUCT_H

#include "PPF_Types.h"
#include "PPF_AddonsType.h"
#include "PPF_PeriodType.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfProduct *ppfProductHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetDescription(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetDetailDescription(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetPrice(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetCurrency(const ppfProductHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetName(const ppfProductHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetSKU(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetIcon(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(ppfAddonsType) ppf_Product_GetAddonsType(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(ppfPeriodType) ppf_Product_GetPeriodType(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(ppfPeriodType) ppf_Product_GetTrialPeriodUnit(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(int32_t) ppf_Product_GetTrialPeriodValue(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetOuterId(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetOriginalPrice(const ppfProductHandle obj);

// reserve
PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetGroupId(const ppfProductHandle obj);

// reserve
PPF_PUBLIC_FUNCTION(int32_t) ppf_Product_GetLevel(const ppfProductHandle obj);

PPF_PUBLIC_FUNCTION(bool) ppf_Product_IsContinuous(const ppfProductHandle obj);




#endif

