// This file is generated automatically. Please don't edit it.


#ifndef PPF_RECORDINFO_H
#define PPF_RECORDINFO_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfRecordInfo *ppfRecordInfoHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_RecordInfo_GetVideoPath(const ppfRecordInfoHandle obj);
PPF_PUBLIC_FUNCTION(const char*) ppf_RecordInfo_GetJobId(const ppfRecordInfoHandle obj);
PPF_PUBLIC_FUNCTION(int) ppf_RecordInfo_GetDurationInMilliSeconds(const ppfRecordInfoHandle obj);
PPF_PUBLIC_FUNCTION(int) ppf_RecordInfo_GetWidth(const ppfRecordInfoHandle obj);
PPF_PUBLIC_FUNCTION(int) ppf_RecordInfo_GetHeight(const ppfRecordInfoHandle obj);
#endif

