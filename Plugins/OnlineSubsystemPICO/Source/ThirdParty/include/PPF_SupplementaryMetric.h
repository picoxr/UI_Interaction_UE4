#ifndef PPF_SUPPLEMENTARYMETRIC_H
#define PPF_SUPPLEMENTARYMETRIC_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"

typedef struct ppfSupplementaryMetric *ppfSupplementaryMetricHandle;

PPF_PUBLIC_FUNCTION(ppfID)     ppf_SupplementaryMetric_GetID(const ppfSupplementaryMetricHandle obj);
PPF_PUBLIC_FUNCTION(long long) ppf_SupplementaryMetric_GetMetric(const ppfSupplementaryMetricHandle obj);

#endif
