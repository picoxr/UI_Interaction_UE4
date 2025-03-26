// This file is generated automatically. Please don't edit it.


#ifndef PPF_ASRRESULT_H
#define PPF_ASRRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfAsrResult *ppfAsrResultHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_AsrResult_GetText(const ppfAsrResultHandle obj);


PPF_PUBLIC_FUNCTION(bool) ppf_AsrResult_GetIsFinalResult(const ppfAsrResultHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_AsrResult_GetSessionId(const ppfAsrResultHandle obj);



#endif

