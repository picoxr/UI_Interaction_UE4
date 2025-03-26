// This file is generated automatically. Please don't edit it.


#ifndef PPF_SPORTUSERINFO_H
#define PPF_SPORTUSERINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_Gender.h"
#include "PPF_SportTarget.h"


typedef struct ppfSportUserInfo *ppfSportUserInfoHandle;


PPF_PUBLIC_FUNCTION(ppfGender) ppf_SportUserInfo_GetGender(const ppfSportUserInfoHandle obj);

// 出生日期，年月日
PPF_PUBLIC_FUNCTION(int64_t) ppf_SportUserInfo_GetBirthday(const ppfSportUserInfoHandle obj);

// 身高，单位cm
PPF_PUBLIC_FUNCTION(int) ppf_SportUserInfo_GetStature(const ppfSportUserInfoHandle obj);

// 体重，单位kg
PPF_PUBLIC_FUNCTION(int) ppf_SportUserInfo_GetWeight(const ppfSportUserInfoHandle obj);

// 计划运动级别，1-低；2-中；3-高
PPF_PUBLIC_FUNCTION(int) ppf_SportUserInfo_GetSportLevel(const ppfSportUserInfoHandle obj);

// 计划每天运动时长，单位分钟
PPF_PUBLIC_FUNCTION(int) ppf_SportUserInfo_GetDailyDurationInMinutes(const ppfSportUserInfoHandle obj);

// 每周计划运动天数
PPF_PUBLIC_FUNCTION(int) ppf_SportUserInfo_GetDaysPerWeek(const ppfSportUserInfoHandle obj);

// 运动目标：减脂、保健
PPF_PUBLIC_FUNCTION(ppfSportTarget) ppf_SportUserInfo_GetSportTarget(const ppfSportUserInfoHandle obj);



#endif

