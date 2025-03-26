// This file is generated automatically. Please don't edit it.


#ifndef PPF_SPEECHERROR_H
#define PPF_SPEECHERROR_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfSpeechError *ppfSpeechErrorHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_SpeechError_GetMessage(const ppfSpeechErrorHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_SpeechError_GetSessionId(const ppfSpeechErrorHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_SpeechError_GetCode(const ppfSpeechErrorHandle obj);



#endif

