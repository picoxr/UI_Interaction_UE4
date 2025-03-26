// This file is generated automatically. Please don't edit it.


#ifndef PPF_SYSTEMINFO_H
#define PPF_SYSTEMINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
typedef struct ppfSystemInfo *ppfSystemInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_SystemInfo_GetROMVersion(const ppfSystemInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_SystemInfo_GetLocale(const ppfSystemInfoHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_SystemInfo_GetProductName(const ppfSystemInfoHandle obj);


PPF_PUBLIC_FUNCTION(bool) ppf_SystemInfo_GetIsCnDevice(const ppfSystemInfoHandle obj);

PPF_PUBLIC_FUNCTION(const char*) ppf_SystemInfo_GetMatrixVersionName(const ppfSystemInfoHandle obj);
PPF_PUBLIC_FUNCTION(int64_t) ppf_SystemInfo_GetMatrixVersionCode(const ppfSystemInfoHandle obj);
#endif

