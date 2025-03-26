// This file is generated automatically. Please don't edit it.


#ifndef PPF_REQUESTS_IAP_H
#define PPF_REQUESTS_IAP_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_ConsumePurchase(const char *sku);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_GetNextProductArrayPage(const char *nextPageParam);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_GetNextPurchaseArrayPage(const char *nextPageParam);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_GetProductsBySKU(const char **skus, int size);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_GetViewerPurchases();


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_LaunchCheckoutFlow(const char *sku, const char *price, const char *currency);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_LaunchCheckoutFlowV2(const char *sku, const char *price, const char *currency, const char *outerId);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_LaunchCheckoutFlowV3(const char *sku, const char *price, const char *currency, const char *outerId, const char *orderComment);

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_LaunchCheckoutFlowWithUid(const char *sku, const char *price, const char *currency, const char *outerId, const char *orderComment, const char *userUniqueId);

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_IAP_GetSubscriptionStatus(const char *sku);

#endif

