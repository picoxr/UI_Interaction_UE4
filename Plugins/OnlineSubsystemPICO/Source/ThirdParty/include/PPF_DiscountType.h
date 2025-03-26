#ifndef MATRIX_PPF_DISCOUNTTYPE_H
#define MATRIX_PPF_DISCOUNTTYPE_H

/// @file PPF_DiscountType.h
/// @ingroup IAP

typedef enum ppfDiscountType_ {
    ppfDiscountType_Invalid=-1    ,	//Invalid
    ppfDiscountType_Null=0        ,	//Null
    ppfDiscountType_FreeTrial=1   ,	//FreeTrial
    ppfDiscountType_Discount=2    ,	//Discount
} ppfDiscountType;

#endif //MATRIX_PPF_DISCOUNTTYPE_H
