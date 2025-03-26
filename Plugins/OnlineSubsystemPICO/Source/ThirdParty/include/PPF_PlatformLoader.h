// Copyright © 2022-2025 Pico Technology Co., Ltd. All Rights Reserved.

#ifndef PPF_PLATFORMLoader_H
#define PPF_PLATFORMLoader_H

#include "PPF_Platform_Defs.h"
#include "PPF_PlatformInitializeResult.h"
#include "PPF_Types.h"

//PC init function
PPF_PUBLIC_FUNCTION(ppfPlatformInitializeResult) ppf_PcInitWrapper(const char *appId, const char *configPath, const char *logPath);
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_PcInitAsynchronousWrapper(const char *appId, const char *configJson, const char *logPath);
PPF_PUBLIC_FUNCTION(int) ppf_PcUnInitialize();
//bind functions with matrix,only available for unity now.
PPF_PUBLIC_FUNCTION(void) ppf_RegisterFunctions();
//get the version of loader
PPF_PUBLIC_FUNCTION(int) ppf_GetLoaderVersion();

#endif // PPF_PLATFORMLoader_H
