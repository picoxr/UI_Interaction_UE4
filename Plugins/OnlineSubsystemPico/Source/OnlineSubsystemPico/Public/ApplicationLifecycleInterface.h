// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
    /// * `true`: Call success
    /// * `false`: Call failure
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
    /// * `true`: Call success
    /// * `false`: Call failure
    /// </returns>
    bool LogDeeplinkResult(const FString& TrackingID, ELaunchResult LaunchResult);

    /// <summary>
    /// Get device system information synchronously. 
    /// </summary>
    /// <param name ="SystemInfo">The [out] struct of system info:
    /// * `ROMVersion`: The ROM version of the device system
    /// * `Locale`: The region of the device system
    /// * `ProductName`: The product name of the device system
    /// * `bIsCnDevice`: Whether the device system is global or in mainland China
    /// * `MatrixVersionName`: The matrix version name of the device system
    /// * `MatrixVersionCode`: The matrix version code of the device system
    /// </param> 
    /// <returns>Bool:
    /// * `true`: Call success
    /// * `false`: Call failure
    /// </returns>
    bool GetSystemInfo(FPicoSystemInfo &SystemInfo);

    FDelegateHandle OnLaunchIntentChangedNotificationHandle;
    void OnLaunchIntentChangedNotification(ppfMessageHandle Message, bool bIsError);

public:
    /// @brief Gets notified when the launch intent has been changed.
    FApplicationLifecycleStringResult LaunchIntentChangedCallback;
};


/** @} */ // end of ApplicationLifecycle
/** @} */ // end of Function