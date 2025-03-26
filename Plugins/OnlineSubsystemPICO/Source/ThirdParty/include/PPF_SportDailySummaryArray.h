// This file is generated automatically. Please don't edit it.

#ifndef PPF_SPORTDAILYSUMMARYARRAY_H
#define PPF_SPORTDAILYSUMMARYARRAY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include <stdbool.h>
#include <stddef.h>
#include "PPF_SportDailySummary.h"


typedef struct ppfSportDailySummaryArray *ppfSportDailySummaryArrayHandle;



PPF_PUBLIC_FUNCTION(ppfSportDailySummaryHandle) ppf_SportDailySummaryArray_GetElement(const ppfSportDailySummaryArrayHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_SportDailySummaryArray_GetSize(const ppfSportDailySummaryArrayHandle obj);

#endif
