// This file is generated automatically. Please don't edit it.


#ifndef PPF_DETECTSENSITIVERESULT_H
#define PPF_DETECTSENSITIVERESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_SensitiveProposal.h"


typedef struct ppfDetectSensitiveResult *ppfDetectSensitiveResultHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_DetectSensitiveResult_GetFilteredText(const ppfDetectSensitiveResultHandle obj);


PPF_PUBLIC_FUNCTION(ppfSensitiveProposal) ppf_DetectSensitiveResult_GetProposal(const ppfDetectSensitiveResultHandle obj);



#endif

