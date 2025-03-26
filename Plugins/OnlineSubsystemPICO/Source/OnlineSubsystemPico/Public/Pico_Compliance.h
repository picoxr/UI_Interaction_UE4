// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pico_Compliance.generated.h"

/// @file Pico_Compliance.h

DECLARE_LOG_CATEGORY_EXTERN(PicoCompliance, Log, All);

DECLARE_DYNAMIC_DELEGATE_FourParams(FDetectSensitive, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult*, DetectSensitiveResult);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Compliance Compliance
  *  This is the Compliance group
  *  @{
  */

  /// @brief PicoComplianceInterface class.
class ONLINESUBSYSTEMPICO_API FPicoComplianceInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoComplianceInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoComplianceInterface();

    FDetectSensitive DetectSensitiveDelegate;

    /// <summary>
    /// Detects if a user name, room name, or the in-room chat content contains sensitive words.
    /// </summary>
    /// <param name="DetectSensitiveScene">The type of content to verify. It can be a username, a room name, or in-room chat.</param>
    /// <param name="InDetectContent">The content to verify.</param>
    /// <param name="InDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult *, DetectSensitiveResult).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>  
    bool DetectSensitive(EDetectSensitiveScene DetectSensitiveScene, const FString& InDetectContent, FDetectSensitive InDelegate);



};

/** @} */
/** @} */

/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

 /** @defgroup BP_Compliance BP_Compliance
  *  This is the BP_Compliance group
  *  @{
  */

  /// @brief OnlinePicoCompliance Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoComplianceFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /// <summary>
    /// Detects if a user name, room name, or the in-room chat content contains sensitive words.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="DetectSensitiveScene">The type of content to verify. It can be a username, a room name, or in-room chat.</param>
    /// <param name="InDetectContent">The content to verify.</param>
    /// <param name="InDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult *, DetectSensitiveResult).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Complianc")
    static bool DetectSensitive(UObject* WorldContextObject, EDetectSensitiveScene DetectSensitiveScene, const FString& InDetectContent, FDetectSensitive InDelegate);
};

/** @} */
/** @} */

/// @brief UPico_DetectSensitiveResult class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_DetectSensitiveResult : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfDetectSensitiveResult* ppfDetectSensitiveResultHandle);

private:
    ESensitiveProposal SensitiveProposal = ESensitiveProposal::None;
    FString FilteredText = FString();
public:

    /** @brief The text-handling proposal. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Compliance|DetectSensitiveResult")
    ESensitiveProposal GetSensitiveProposal();

    /** @brief The filtered text is a string which replace sensitive words with `*`. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Compliance|DetectSensitiveResult")
    FString GetFilteredText();
};