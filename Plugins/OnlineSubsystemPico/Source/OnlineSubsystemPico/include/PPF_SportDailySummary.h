// This file is generated automatically. Please don't edit it.


#ifndef PPF_SPORTDAILYSUMMARY_H
#define PPF_SPORTDAILYSUMMARY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfSportDailySummary *ppfSportDailySummaryHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_SportDailySummary_GetId(const ppfSportDailySummaryHandle obj);

// 运动的日期
PPF_PUBLIC_FUNCTION(int64_t) ppf_SportDailySummary_GetDate(const ppfSportDailySummaryHandle obj);

// 单位秒
PPF_PUBLIC_FUNCTION(int) ppf_SportDailySummary_GetDurationInSeconds(const ppfSportDailySummaryHandle obj);

// 单位：分钟
PPF_PUBLIC_FUNCTION(int) ppf_SportDailySummary_GetPlanDurationInMinutes(const ppfSportDailySummaryHandle obj);


PPF_PUBLIC_FUNCTION(double) ppf_SportDailySummary_GetCalorie(const ppfSportDailySummaryHandle obj);

// 单位：千卡
PPF_PUBLIC_FUNCTION(double) ppf_SportDailySummary_GetPlanCalorie(const ppfSportDailySummaryHandle obj);



#endif

