// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pico_CloudStorage.generated.h"

/// @file Pico_CloudStorage.h

DECLARE_LOG_CATEGORY_EXTERN(PicoCloudStorage, Log, All);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FStartNewCloud_Backup, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup CloudStorage CloudStorage
  *  This is the CloudStorage group
  *  @{
  */

  /// @brief PicoCloudStorageInterface class.
class ONLINESUBSYSTEMPICO_API FPicoCloudStorageInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoCloudStorageInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoCloudStorageInterface();

    FStartNewCloud_Backup CloudStartNewBackupDelegate;


    /// <summary>
    /// Triggers a data-backup task based on the Cloud Storage service.
    /// </summary>
    /// <param name="InDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>  
    bool StartNewBackup(FStartNewCloud_Backup InDelegate);



};

/** @} */
/** @} */

/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

 /** @defgroup BP_CloudStorage BP_CloudStorage
  *  This is the BP_CloudStorage group
  *  @{
  */

  /// @brief OnlinePicoCloudStorage Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoCloudStorageFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /// <summary>
    /// Triggers a data-backup task based on the Cloud Storage service.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult *, DetectSensitiveResult).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|CloudStorage")
    static bool StartNewBackup(UObject* WorldContextObject, FStartNewCloud_Backup InDelegate);
};

/** @} */
/** @} */