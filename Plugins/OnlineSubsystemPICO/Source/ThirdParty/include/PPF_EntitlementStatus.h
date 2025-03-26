#ifndef MATRIX_PPF_ENTITLEMENTSTATUS_H
#define MATRIX_PPF_ENTITLEMENTSTATUS_H

/// @file PPF_EntitlementStatus.h
/// @ingroup IAP

typedef enum ppfEntitlementStatus_ {
    ppfEntitlementStatus_None = 0,
    ppfEntitlementStatus_Valid = 1,
    ppfEntitlementStatus_Invalid = 2,
    ppfEntitlementStatus_GracePeriod = 3,
    ppfEntitlementStatus_Pause = 4,
    ppfEntitlementStatus_Expired = 5,
    ppfEntitlementStatus_Cancel = 6
} ppfEntitlementStatus;

#endif //MATRIX_PPF_ENTITLEMENTSTATUS_H
