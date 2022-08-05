#ifndef PPF_PLATFORM_GAME_INITIALIZE_H
#define PPF_PLATFORM_GAME_INITIALIZE_H

#include "PPF_Platform_Defs.h"
#include "PPF_PlatformGameInitializeResult.h"

typedef struct ppfPlatformGameInitialize *ppfPlatformGameInitializeHandle;

PPF_PUBLIC_FUNCTION(ppfPlatformGameInitializeResult) ppf_PlatformGameInitialize_GetResult(const ppfPlatformGameInitializeHandle obj);

#endif
