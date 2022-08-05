//
// Created by admin on 2022/2/17.
//

#ifndef MATRIX_PPF_PRODUCTARRAY_H
#define MATRIX_PPF_PRODUCTARRAY_H

typedef struct ppfProductArray *ppfProductArrayHandle;

PPF_PUBLIC_FUNCTION(ppfProductHandle) ppf_ProductArray_GetElement(const ppfProductArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)     ppf_ProductArray_GetNextUrl(const ppfProductArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)           ppf_ProductArray_GetSize(const ppfProductArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)             ppf_ProductArray_HasNextPage(const ppfProductArrayHandle obj);


#endif //MATRIX_PPF_PRODUCTARRAY_H
