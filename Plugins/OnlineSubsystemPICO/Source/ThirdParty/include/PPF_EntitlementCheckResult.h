// This file is generated automatically. Please don't edit it.


#ifndef PPF_ENTITLEMENTCHECKRESULT_H
#define PPF_ENTITLEMENTCHECKRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"


typedef struct ppfEntitlementCheckResult *ppfEntitlementCheckResultHandle;

PPF_PUBLIC_FUNCTION(bool) ppf_EntitlementCheckResult_GetHasEntitlement(const ppfEntitlementCheckResultHandle obj);

PPF_PUBLIC_FUNCTION(int) ppf_EntitlementCheckResult_GetStatusCode(const ppfEntitlementCheckResultHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_EntitlementCheckResult_GetStatusMessage(const ppfEntitlementCheckResultHandle obj);



#endif