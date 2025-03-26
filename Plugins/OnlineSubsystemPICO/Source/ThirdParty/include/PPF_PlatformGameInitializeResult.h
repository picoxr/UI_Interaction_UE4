#ifndef PPF_PLATFORM_GAME_INITIALIZE_RESULT_H
#define PPF_PLATFORM_GAME_INITIALIZE_RESULT_H

#include "PPF_Platform_Defs.h"

typedef enum ppfPlatformGameInitializeResult_ {
    ppfPlatformGameInitialize_Success             = 0,
    ppfPlatformGameInitialize_Uninitialized       = 1,
    ppfPlatformGameInitialize_NetworkError        = 2,
    ppfPlatformGameInitialize_InvalidCredentials  = 3,
    ppfPlatformGameInitialize_ServiceNotAvaliable = 4,
    ppfPlatformGameInitialize_Unknown             = 5,
    ppfPlatformGameInitialize_InvalidServerAddr   = 6,
    ppfPlatformGameInitialize_DupInitialize       = 7,
} ppfPlatformGameInitializeResult;

PPF_PUBLIC_FUNCTION(const char*) ppfPlatformGameInitializeResult_ToString(ppfPlatformGameInitializeResult value);

PPF_PUBLIC_FUNCTION(ppfPlatformGameInitializeResult) ppfPlatformGameInitializeResult_FromString(const char* str);

#endif
