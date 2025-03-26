#ifndef MATRIX_PPF_ADDONSTYPE_H
#define MATRIX_PPF_ADDONSTYPE_H

/// @file PPF_AddonsType.h
/// @ingroup IAP

typedef enum ppfAddonsType_ {
    ppfAddonsType_Invalid=-1        ,   //Invalid
    ppfAddonsType_Durable=0         ,	//Durable
    ppfAddonsType_Consumable=1      ,	//Consumable
    ppfAddonsType_Subscription=2    ,	//Subscription
} ppfAddonsType;

#endif //MATRIX_PPF_ADDONSTYPE_H
