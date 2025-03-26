// This file is generated automatically. Please don't edit it.


#ifndef PPF_SUBSCRIPTIONSTATUS_H
#define PPF_SUBSCRIPTIONSTATUS_H

#include "PPF_Types.h"
#include "PPF_PeriodType.h"
#include "PPF_Platform_Defs.h"
#include "PPF_EntitlementStatus.h"
#include "PPF_CancelReason.h"



typedef struct ppfSubscriptionStatus *ppfSubscriptionStatusHandle;

PPF_PUBLIC_FUNCTION(const char*) ppf_SubscriptionStatus_GetSKU(const ppfSubscriptionStatusHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_SubscriptionStatus_GetOuterId(const ppfSubscriptionStatusHandle obj);

//The start time of the subscribed product currently.
PPF_PUBLIC_FUNCTION(int64_t) ppf_SubscriptionStatus_GetStartTime(const ppfSubscriptionStatusHandle obj);

//The end time of the subscribed product currently.
PPF_PUBLIC_FUNCTION(int64_t) ppf_SubscriptionStatus_GetEndTime(const ppfSubscriptionStatusHandle obj);

// The subscription product's cycle type.
PPF_PUBLIC_FUNCTION(ppfPeriodType) ppf_SubscriptionStatus_GetPeriodType(const ppfSubscriptionStatusHandle obj);

// The subscription status of the subscription product.
PPF_PUBLIC_FUNCTION(ppfEntitlementStatus) ppf_SubscriptionStatus_GetEntitlementStatus(const ppfSubscriptionStatusHandle obj);

// The current subscription is valid, but the reason why the user canceled the subscription to continue.
PPF_PUBLIC_FUNCTION(ppfCancelReason) ppf_SubscriptionStatus_GetCancelReason(const ppfSubscriptionStatusHandle obj);

// Are you currently in the probation period
PPF_PUBLIC_FUNCTION(bool) ppf_SubscriptionStatus_GetIsFreeTrial(const ppfSubscriptionStatusHandle obj);

// What is the next issue (in the case of unsubscription, the next issue is 0)
PPF_PUBLIC_FUNCTION(int) ppf_SubscriptionStatus_GetNextPeriod(const ppfSubscriptionStatusHandle obj);
#endif

