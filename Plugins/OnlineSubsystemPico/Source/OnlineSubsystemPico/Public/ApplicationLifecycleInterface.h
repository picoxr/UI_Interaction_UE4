// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineSubsystemPicoNames.h"

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup ApplicationLifecycle ApplicationLifecycle
  *  This is the ApplicationLifecycle group
  *  @{
  */
DECLARE_LOG_CATEGORY_EXTERN(ApplicationLifecycleInterface, Log, All);


// Notification
DECLARE_MULTICAST_DELEGATE_OneParam(FApplicationLifecycleStringResult, const FString& /*MessageString*/);

/// <summary>Pico Application interface class.</summary>
class ONLINESUBSYSTEMPICO_API FApplicationLifecycleInterface
{

private:
    FLaunchDetails LaunchDetails;
    FOnlineSubsystemPico& PicoSubsystem;
    TArray<FPicoUserInfo> DetailsUserArray;
public:
    FApplicationLifecycleInterface(FOnlineSubsystemPico& InSubsystem);
    ~FApplicationLifecycleInterface();

    bool ReadLaunchDetails();

    /// <summary>Gets information about how the app was launched.</summary>
    /// <param name ="OutLaunchDetails">The [out] struct of launch details.</param> 
    /// <returns>Bool: 
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    bool GetLaunchDetails(FLaunchDetails& OutLaunchDetails);

    /// <summary>Logs whether the user has been successfully directed to the desired destination via a deep link.</summary>
    /// <param name ="TrackingID">The tracking ID of the app launch event.</param> 
    /// <param name ="LaunchResult">Enumerations of the launch result:
    /// * `Unknown`
    /// * `Success`
    /// * `FailedRoomFull`
    /// * `FailedGameAlreadyStarted`
    /// * `FailedRoomNotFound`
    /// * `FailedUserDeclined`
    /// * `FailedOtherReason`
    /// </param> 
    /// <returns>Bool: 
    /// * `true`: the result has been logged
    /// * `false`: failed to log the result
    /// </returns>
    bool LogDeeplinkResult(const FString& TrackingID, ELaunchResult LaunchResult);

    FDelegateHandle OnLaunchIntentChangedNotificationHandle;
    void OnLaunchIntentChangedNotification(ppfMessageHandle Message, bool bIsError);

public:
    /// @brief Gets notified when the launch intent has been changed.
    FApplicationLifecycleStringResult LaunchIntentChangedCallback;
};


/** @} */ // end of ApplicationLifecycle
/** @} */ // end of Function