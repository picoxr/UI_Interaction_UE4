#ifndef PPF_PLATFORM_GAME_NOTIFICATION_H
#define PPF_PLATFORM_GAME_NOTIFICATION_H

#include "PPF_Platform_Defs.h"

/**
 * Describes the various events possible on networking.
 * */
typedef enum {
    ppfPlatformGameConnectionEvent_Connected = 0,
    ppfPlatformGameConnectionEvent_Closed = 1,
    ppfPlatformGameConnectionEvent_Lost = 2,
    ppfPlatformGameConnectionEvent_Resumed = 3,
    ppfPlatformGameConnectionEvent_KickedByRelogin = 4,
    ppfPlatformGameConnectionEvent_KickedByGameServer = 5,
    ppfPlatformGameConnectionEvent_GameLogicError = 6,
    ppfPlatformGameConnectionEvent_Unknown = 7,
} ppfGameConnectionEvent;

/**
 * Describes the various reason of failed requests to platform game service.
 */
typedef enum {
    ppfPlatformGameFailedReason_None = 0,
    ppfPlatformGameFailedReason_NotInitialized = 1,
    ppfPlatformGameFailedReason_Uninitialized = 2,
    ppfPlatformGameFailedReason_CurrentlyUnavailable = 3,
    ppfPlatformGameFailedReason_CurrentlyUnknown = 4
} ppfGameRequestFailedReason;

#endif
