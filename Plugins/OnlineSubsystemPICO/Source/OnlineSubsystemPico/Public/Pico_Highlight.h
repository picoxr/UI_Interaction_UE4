// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Pico_Highlight.generated.h"
/**
 * 
 */

DECLARE_LOG_CATEGORY_EXTERN(PicoHighlight, Log, All);

DECLARE_DYNAMIC_DELEGATE_FourParams(FCaptureScreenResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_CaptureInfo*, CaptureInfo);
DECLARE_DYNAMIC_DELEGATE_FourParams(FListMediaResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_SessionMedia*, SessionMedia);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FSaveMediaResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FShareMediaResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FStartRecordResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_FourParams(FStartSessionResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, const FString&, SessionId);
DECLARE_DYNAMIC_DELEGATE_FourParams(FStopRecordResult, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RecordInfo*, RecordInfo);

DECLARE_MULTICAST_DELEGATE_OneParam(FHighlightRecordStopNotify, UPico_RecordInfo* /*RecordInfoObj*/);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Highlight Highlight
  *  This is the Highlight group
  *  @{
  */

  /// @brief PicoHighlightInterface class.
class ONLINESUBSYSTEMPICO_API FPicoHighlightInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoHighlightInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoHighlightInterface();


    /// <summary>
    /// Callback for handling notifications related to stopping highlight recording.
    /// UPico_AssetFileDeleteForSafety *
    /// </summary>
    FHighlightRecordStopNotify HighlightRecordStopCallback;

    /// <summary> Captures the current screen contents. </summary>
    /// <param name="InCaptureScreenResultDelegate"> Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_CaptureInfo *, CaptureInfo).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool CaptureScreen(FCaptureScreenResult InCaptureScreenResultDelegate);

    /// <summary>Lists screenshots or videos associated with the specified session ID.</summary>
    /// <param name ="SessionId">The ID of the session for which media will be listed.</param>
    /// <param name="InListMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_SessionMedia *, SessionMedia).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool ListMedia(const FString& SessionId, FListMediaResult InListMediaResultDelegate);

    /// <summary>Saves a screenshot or a video associated with a specified job ID and session ID.</summary>
    /// <param name ="JobId">The job ID of the screenshot or video to be saved.</param>
    /// <param name ="SessionId">The session ID of the screenshot or video to be saved.</param>
    /// <param name="InSaveMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool SaveMedia(const FString& JobId, const FString& SessionId, FSaveMediaResult InSaveMediaResultDelegate);

    /// <summary>Shares a screenshot or a video associated with a specified job ID and session ID.</summary>
    /// <param name ="JobId">The job ID of the screenshot or video to be shared.</param>
    /// <param name ="SessionId">The session ID of the screenshot or video to be shared.</param>
    /// <param name="InShareMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool ShareMedia(const FString& JobId, const FString& SessionId, FShareMediaResult InShareMediaResultDelegate);

    /// <summary>
    /// Starts recording the current screen. </summary>
    /// <param name="InStartRecordResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool StartRecord(FStartRecordResult InStartRecordResultDelegate);

    /// <summary>
    /// Stops recording the current screen. </summary>
    /// <param name="InStopRecordResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RecordInfo *, RecordInfo) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool StopRecord(FStopRecordResult InStopRecordResultDelegate);

    /// <summary>
    /// Starts a session to prepare for capturing or recording a screen.
    /// </summary>
    /// <param name="InStartSessionResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, const FString&, SessionId) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool StartSession(FStartSessionResult InStartSessionResultDelegate);


    FDelegateHandle HighlightRecordStopHandle;
    void OnHighlightRecordStop(ppfMessageHandle Message, bool bIsError);
};


/** @} */
/** @} */


  /// @brief OnlinePicoHighlight Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoHighlightFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

/** @addtogroup BlueprintFunction BlueprintFunction
*  This is the BlueprintFunction group
*  @{
*/

/** @defgroup BP_Highlight BP_Highlight
*  This is the BP_Highlight group
*  @{
*/

    /// <summary> Captures the current screen contents. </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InCaptureScreenResultDelegate"> Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_CaptureInfo *, CaptureInfo).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool CaptureScreen(UObject* WorldContextObject, FCaptureScreenResult InCaptureScreenResultDelegate);

    /// <summary>Lists screenshots or videos associated with the specified session ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SessionId">The ID of the session for which media will be listed.</param>
    /// <param name="InListMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_SessionMedia *, SessionMedia).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool ListMedia(UObject* WorldContextObject, const FString& SessionId, FListMediaResult InListMediaResultDelegate);

    /// <summary>Saves a screenshot or a video associated with a specified job ID and session ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="JobId">The job ID of the screenshot or video to be saved.</param>
    /// <param name ="SessionId">The session ID of the screenshot or video to be saved.</param>
    /// <param name="InSaveMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool SaveMedia(UObject* WorldContextObject, const FString& JobId, const FString& SessionId, FSaveMediaResult InSaveMediaResultDelegate);

    /// <summary>Shares a screenshot or a video associated with a specified job ID and session ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="JobId">The job ID of the screenshot or video to be saved.</param>
    /// <param name ="SessionId">The session ID of the screenshot or video to be saved.</param>
    /// <param name="InShareMediaResultDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool ShareMedia(UObject* WorldContextObject, const FString& JobId, const FString& SessionId, FShareMediaResult InShareMediaResultDelegate);
   
    /// <summary>Starts recording the current screen. </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InStartRecordResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool StartRecord(UObject* WorldContextObject, FStartRecordResult InStartRecordResultDelegate);

    /// <summary>Stops recording the current screen. </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InStopRecordResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RecordInfo *, RecordInfo) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool StopRecord(UObject* WorldContextObject, FStopRecordResult InStopRecordResultDelegate);

    /// <summary>Starts a session to prepare for capturing or recording a screen. </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InStartSessionResultDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, const FString&, SessionId) </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Highlight")
    static bool StartSession(UObject* WorldContextObject, FStartSessionResult InStartSessionResultDelegate);


    /** @} */
    /** @} */
};



/// @brief UPico_CaptureInfo class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_CaptureInfo : public UObject
{

    GENERATED_BODY()
private:
    FString ImagePath = FString();
    FString JobId = FString();
public:
    void InitParams(ppfCaptureInfo* InppfCaptureInfoHandle);

    /** @brief The image's path.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Capture Info")
    FString GetImagePath();

    /** @brief The job ID of a screenshot.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Capture Info")
    FString GetJobId();
};

/// @brief UPico_RecordInfo class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_RecordInfo : public UObject
{

    GENERATED_BODY()
private:
    FString VideoPath = FString();
    FString JobId = FString();
    int32 DurationInMilliSeconds = 0;
    int32 Width = 0;
    int32 Height = 0;
public:
    void InitParams(ppfRecordInfo* InppfRecordInfoHandle);

    /** @brief The video's path.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    FString GetVideoPath();

    /** @brief The job ID of a video.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    FString GetJobId();

    /** @brief The duration time of a video. The units are in milliseconds.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    int32 GetDurationInMilliSeconds();

    /** @brief The width of a video. The units are in pixels.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    int32 GetWidth();

    /** @brief The height of a video. The units are in pixels. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    int32 GetHeight();
};

/// @brief UPico_SessionMedia class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SessionMedia : public UObject
{

    GENERATED_BODY()
private:
    TArray<UPico_CaptureInfo*> Images;
    TArray<UPico_RecordInfo*> Videos;
public:
    void InitParams(ppfSessionMedia* InppfSessionMediaHandle);

    /** @brief The number of images in the image array.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Capture Info")
    int32 GetImagesSize();

    /** @brief The element of an image array.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Capture Info")
    UPico_CaptureInfo* GetImagesElement(int32 Index);

    /** @brief The number of videos in the video array.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    int32 GetVideosSize();

    /** @brief The element of a video array.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Highlight|Record Info")
    UPico_RecordInfo* GetVideosElement(int32 Index);
};
