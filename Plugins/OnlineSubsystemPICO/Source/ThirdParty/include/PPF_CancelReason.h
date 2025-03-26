#ifndef MATRIX_PPF_CANCELREASON_H
#define MATRIX_PPF_CANCELREASON_H

/// @file PPF_CancelReason.h
/// @ingroup IAP

typedef enum ppfCancelReason_ {
    ppfCancelReason_None = 0,
    ppfCancelReason_UserCancelsExpiration = 1,
    ppfCancelReason_DeductionFailedExpired = 2,
    ppfCancelReason_NoMainApplicationInterest = 3,
} ppfCancelReason;

#endif //MATRIX_PPF_CANCELREASON_H
