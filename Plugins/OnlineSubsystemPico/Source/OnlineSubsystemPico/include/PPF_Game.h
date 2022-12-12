// Copyright © 2022-2025 Pico Technology Co., Ltd. All Rights Reserved.

#ifndef PPF_GAME_H
#define PPF_GAME_H

#include "PPF_Types.h"

/// @defgroup Game Game
/// @file PPF_Game.h
/// @ingroup Game


/// @brief Prepare multi-player utilities (e.g., matchmaking, room)
/// @param accessToken Access token of current logged in user
/// @return Async id of the initialize request
/// 
/// The initialization is asynchronous procedure, a message with type ::ppfMessageType_PlatformGameInitializeAsynchronous will be generated in response.
/// Use ppf_Message_GetPlatformGameInitialize/ppf_PlatformGameInitialize_GetResult to retrieve the asynchronous result. 
/// A result of ppfPlatformGameInitialize_Success means a successful initialization, and then multi-player relative requests may be issued.
/// Other result indicates some errors(e.g., network is unavailable), you should re-initialize when the error is fixed.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Game_InitializeWithToken(const char* accessToken);
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Game_InitializeWithTokenAccountTypeOne(const char* accessToken);

/// @brief Prepare multi-player utilities (e.g., matchmaking, room) auto got accesstoken
/// @return Async id of the initialize request
///
/// The initialization is asynchronous procedure, a message with type ::ppfMessageType_PlatformGameInitializeAsynchronous will be generated in response.
/// Use ppf_Message_GetPlatformGameInitialize/ppf_PlatformGameInitialize_GetResult to retrieve the asynchronous result.
/// A result of ppfPlatformGameInitialize_Success means a successful initialization, and then multi-player relative requests may be issued.
/// Other result indicates some errors(e.g., network is unavailable), you should re-initialize when the error is fixed.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Game_InitializeAuto();


/// @brief Uninitialize multi-player utilities. 
/// @return true if the uninitialize is success
///
/// Each ppf_Game_InitializeWithToken should be paired with a ppf_Game_UnInitialize.
/// Most commonly, you will call this before exit program. 
/// Also, if any unrecoverable error occurred(e.g., ppfPlatformGameInitialize_InvalidCredentials on initialization, ppfPlatformGameConnectionEvent_KickedByRelogin in game procedure),
/// you should call ppf_Game_UnInitialize first, before re-initialize with ppf_Game_InitializeWithToken.
PPF_PUBLIC_FUNCTION(bool) ppf_Game_UnInitialize();

#endif //PPF_GAME_H
