// This file is generated automatically. Please don't edit it.


#ifndef PPF_SPORTSUMMARY_H
#define PPF_SPORTSUMMARY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfSportSummary *ppfSportSummaryHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_SportSummary_GetDurationInSeconds(const ppfSportSummaryHandle obj);

// 单位：千卡
PPF_PUBLIC_FUNCTION(double) ppf_SportSummary_GetCalorie(const ppfSportSummaryHandle obj);


PPF_PUBLIC_FUNCTION(int64_t) ppf_SportSummary_GetStartTime(const ppfSportSummaryHandle obj);


PPF_PUBLIC_FUNCTION(int64_t) ppf_SportSummary_GetEndTime(const ppfSportSummaryHandle obj);



#endif

