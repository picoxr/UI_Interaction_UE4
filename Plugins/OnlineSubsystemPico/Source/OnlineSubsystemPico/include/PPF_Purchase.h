//
// Created by admin on 2022/2/17.
//

#ifndef MATRIX_PPF_PURCHASE_H
#define MATRIX_PPF_PURCHASE_H

typedef struct ppfPurchase *ppfPurchaseHandle;

PPF_PUBLIC_FUNCTION(unsigned long long) ppf_Purchase_GetExpirationTime(const ppfPurchaseHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_Purchase_GetGrantTime(const ppfPurchaseHandle obj);
PPF_PUBLIC_FUNCTION(const char *)       ppf_Purchase_GetPurchaseStrID(const ppfPurchaseHandle obj);
PPF_PUBLIC_FUNCTION(const char *)       ppf_Purchase_GetSKU(const ppfPurchaseHandle obj);


#endif //MATRIX_PPF_PURCHASE_H
