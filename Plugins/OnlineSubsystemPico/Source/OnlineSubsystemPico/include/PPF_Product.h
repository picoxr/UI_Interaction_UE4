// This file is generated automatically. Please don't edit it.


#ifndef PPF_PRODUCT_H
#define PPF_PRODUCT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfProduct *ppfProductHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetDescription(const ppfProductHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetFormattedPrice(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetPrice(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetCurrency(const ppfProductHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetName(const ppfProductHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_Product_GetSKU(const ppfProductHandle obj);



#endif

