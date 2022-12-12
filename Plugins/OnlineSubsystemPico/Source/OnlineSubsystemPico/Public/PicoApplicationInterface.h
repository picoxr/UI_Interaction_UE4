// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineSubsystemPicoNames.h"

/// @file PicoApplicationInterface.h

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Application Application
  *  This is the Application group
  *  @{
  */

DECLARE_LOG_CATEGORY_EXTERN(ApplicationInterface, Log, All);

// Request
DECLARE_DELEGATE_ThreeParams(FOnLaunchOtherAppComplete, const FString& /*String Message*/, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_ThreeParams(FOnLaunchOtherAppByPresenceComplete, const FString& /*String Message*/, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_ThreeParams(FOnGetVersion, const FString& /*String Message*/, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_ThreeParams(FOnLaunchOtherAppByAppIdComplete, const FString& /*String Message*/, bool /*IsSuccessed*/, const FString& /*Error Message*/);

/// <summary>Pico Application interface class.</summary>
class ONLINESUBSYSTEMPICO_API FPicoApplicationInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoApplicationInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoApplicationInterface();

    /// <summary>
    /// Launches a different app in a user's library.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name ="PackageName">The package name of the app to launch.</param> 
    /// <param name ="Message">A message to be passed to the launched app.</param> 
    /// <param name ="Delegate">Will be executed when the request has been complete.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool LaunchOtherApp(const FString& PackageName, const FString& Message, const FOnLaunchOtherAppComplete& Delegate = FOnLaunchOtherAppComplete());
    void OnQueryLaunchOtherAppComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppComplete& Delegate);

    bool GetVersion(const FOnGetVersion& Delegate = FOnGetVersion());
    void OnQueryGetVersionComplete(ppfMessageHandle Message, bool bIsError, const FOnGetVersion& Delegate);

    /// <summary>
    /// Launches a different app in a user's library.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name ="AppID">The ID of the app to launch.</param> 
    /// <param name ="PackageName">The package name of the app to launch.</param> 
    /// <param name ="Message">A message to be passed to the launched app.</param> 
    /// <param name ="ApiName">The API name of the destination in the app.</param> 
    /// <param name ="LobbySessionId">The lobby session ID of the user's presence, which identifies a user group or team. Users with the same lobby session ID can play together or form a team in a game.</param> 
    /// <param name ="MatchSessionId">The match session ID of the user's presence, which identifies all users within the same destination, such as maps and levels. Users with different lobby session IDs will have the same match session ID when playing the same match.</param> 
    /// <param name ="TrackId">The tracking ID of the app launch event.</param> 
    /// <param name ="Extra">Extra data defined by the developer.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool LaunchOtherAppByPresence(const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, const FOnLaunchOtherAppByPresenceComplete& Delegate = FOnLaunchOtherAppByPresenceComplete());
    void OnQueryLaunchOtherAppByPresenceComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppByPresenceComplete& Delegate);

    /// <summary>
    /// Launches a different app in a user's library by app ID.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name ="AppId">The ID of the app to launch.</param> 
    /// <param name ="Message">A message to be passed to the launched app.</param> 
    /// <param name ="Delegate">Will be executed when the request has been complete.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool LaunchOtherAppByAppId(const FString& AppId, const FString& Message, const FOnLaunchOtherAppByAppIdComplete& Delegate = FOnLaunchOtherAppByAppIdComplete());
    void OnQueryLaunchOtherAppByAppIdComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppByAppIdComplete& Delegate);
};
/** @} */ // end of Application
/** @} */ // end of Function