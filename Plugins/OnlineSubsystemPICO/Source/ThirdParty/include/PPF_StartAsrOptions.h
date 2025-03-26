// This file is generated automatically. Please don't edit it.


#ifndef PPF_STARTASROPTIONS_H
#define PPF_STARTASROPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>



struct ppfStartAsrOptions;
typedef struct ppfStartAsrOptions *ppfStartAsrOptionsHandle;



PPF_PUBLIC_FUNCTION(void) ppf_StartAsrOptions_Destroy(ppfStartAsrOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfStartAsrOptionsHandle) ppf_StartAsrOptions_Create();


PPF_PUBLIC_FUNCTION(void) ppf_StartAsrOptions_SetAutoStop(ppfStartAsrOptionsHandle obj,bool value);


PPF_PUBLIC_FUNCTION(void) ppf_StartAsrOptions_SetVadMaxDurationInSeconds(ppfStartAsrOptionsHandle obj,int value);


PPF_PUBLIC_FUNCTION(void) ppf_StartAsrOptions_SetShowPunctual(ppfStartAsrOptionsHandle obj,bool value);


#endif

