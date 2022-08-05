//
// Created by admin on 2022/2/17.
//

#ifndef MATRIX_PPF_PRODUCT_H
#define MATRIX_PPF_PRODUCT_H

typedef struct ppfProduct *ppfProductHandle;

PPF_PUBLIC_FUNCTION(const char *) ppf_Product_GetDescription(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_Product_GetFormattedPrice(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_Product_GetName(const ppfProductHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_Product_GetSKU(const ppfProductHandle obj);


#endif //MATRIX_PPF_PRODUCT_H
