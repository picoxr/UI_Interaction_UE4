//
// Created by admin on 2022/2/17.
//

#ifndef MATRIX_PPF_PURCHASEARRAY_H
#define MATRIX_PPF_PURCHASEARRAY_H

typedef struct ppfPurchaseArray *ppfPurchaseArrayHandle;

PPF_PUBLIC_FUNCTION(ppfPurchaseHandle) ppf_PurchaseArray_GetElement(const ppfPurchaseArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)      ppf_PurchaseArray_GetNextUrl(const ppfPurchaseArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)            ppf_PurchaseArray_GetSize(const ppfPurchaseArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)              ppf_PurchaseArray_HasNextPage(const ppfPurchaseArrayHandle obj);


#endif //MATRIX_PPF_PURCHASEARRAY_H
