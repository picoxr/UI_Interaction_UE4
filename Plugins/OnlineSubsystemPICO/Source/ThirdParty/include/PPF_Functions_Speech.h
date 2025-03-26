// This file is generated automatically. Please don't edit it.


#ifndef PPF_FUNCTIONS_SPEECH_H
#define PPF_FUNCTIONS_SPEECH_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
#include "PPF_AsrEngineInitResult.h"
#include "PPF_StartAsrOptions.h"




PPF_PUBLIC_FUNCTION(ppfAsrEngineInitResult) ppf_Speech_InitAsrEngine();


PPF_PUBLIC_FUNCTION(int) ppf_Speech_StartAsr(ppfStartAsrOptionsHandle option);


PPF_PUBLIC_FUNCTION(void) ppf_Speech_StopAsr();


#endif

