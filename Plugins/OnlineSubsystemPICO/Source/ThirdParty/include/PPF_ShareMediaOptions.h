// This file is generated automatically. Please don't edit it.


#ifndef PPF_SHAREMEDIAOPTIONS_H
#define PPF_SHAREMEDIAOPTIONS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>
#include <stdbool.h>

#include "PPF_ShareMediaType.h"
#include "PPF_ShareAppType.h"


struct ppfShareMediaOptions;
typedef struct ppfShareMediaOptions *ppfShareMediaOptionsHandle;



PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_Destroy(ppfShareMediaOptionsHandle obj);


PPF_PUBLIC_FUNCTION(ppfShareMediaOptionsHandle) ppf_ShareMediaOptions_Create();

// 要分享的内容类型
PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_SetShareMediaType(ppfShareMediaOptionsHandle obj,ppfShareMediaType value);


PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_SetVideoPath(ppfShareMediaOptionsHandle obj,const char* value);

// 视频封面路径
PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_SetVideoThumbPath(ppfShareMediaOptionsHandle obj,const char* value);


PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_AddImagePath(ppfShareMediaOptionsHandle obj,const char* value);


PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_ClearImagePaths(ppfShareMediaOptionsHandle obj);

// 要分享到的平台
PPF_PUBLIC_FUNCTION(void) ppf_ShareMediaOptions_SetShareAppType(ppfShareMediaOptionsHandle obj,ppfShareAppType value);


#endif

