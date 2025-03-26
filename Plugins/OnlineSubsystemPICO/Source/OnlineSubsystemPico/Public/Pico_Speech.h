// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pico_Speech.generated.h"

/// @file Pico_Speech.h

DECLARE_LOG_CATEGORY_EXTERN(PicoSpeech, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FSpeechAsrResultNotify, UPico_AsrResult* /*AsrResultObj*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FSpeechErrorNotify, UPico_SpeechError* /*SpeechErrorObj*/);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Speech Speech
  *  This is the Speech group
  *  @{
  */

  /// @brief PicoSpeechInterface class.
class ONLINESUBSYSTEMPICO_API FPicoSpeechInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoSpeechInterface(FOnlineSubsystemPico& InSubsystem);
	~FPicoSpeechInterface();

    /// <summary>
    /// Sets the callback to get whether the ASR function is enabled successfully.
    /// UPico_AsrResult *.
    /// </summary>
    FSpeechAsrResultNotify SpeechAsrResultCallback;

    /// <summary>
    /// Gets the error occurred during the speech recognition.
    /// UPico_SpeechError *.
    /// </summary>
    FSpeechErrorNotify SpeechErrorCallback;

    /// <summary> Initialize the ASR engine. </summary>
    /// <returns>EAsrEngineInitResult：The initialization result. </returns>
    EAsrEngineInitResult InitAsrEngine();

    /// <summary>
    /// Starts automatic speech recognition.
    /// </summary>
    /// <param name="bAutoStop"> Whether to automatically stop ASR when detects an end-of-speech point to improve the effIciency and accuracy of ASR. </param>
    /// <param name="VadMaxDurationInSeconds"> Sets the maximum duration of Voice Activity Detection (VAD) in seconds before automatically stopping recognition if `bAutoStop` is enabled.
    /// VAD is used to identify speech segments in the audio.
    ///  </param>
    /// <param name="bShowPunctual"> Whether to show the punctuation marks during the speech recognition process. </param>
    /// <returns>Int:
    /// <ul>
    /// <li>`0`: success </li>
    /// <li> Other values: failure </li>
    /// </ul>
    /// </returns>
    int32 StartAsr(bool bAutoStop, int32 VadMaxDurationInSeconds, bool bShowPunctual);

    /// <summary>
    /// Stops automatic speech recognition.  </summary>
    /// <returns>None </returns>  
    void StopAsr();

    FDelegateHandle SpeechAsrResultHandle;
    void OnSpeechAsrResult(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle SpeechErrorHandle;
    void OnSpeechError(ppfMessageHandle Message, bool bIsError);
};
/** @} */
/** @} */



  /// @brief OnlinePicoSpeech Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoSpeechFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

 /** @defgroup BP_Speech BP_Speech
  *  This is the BP_Speech group
  *  @{
  */

    /// <summary>
    /// Initialize the ASR engine.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <returns>The initialization result. </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Speech")
    static EAsrEngineInitResult InitAsrEngine(UObject* WorldContextObject);

    /// <summary>
    /// Starts automatic speech recognition.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="bAutoStop"> Whether to automatically stop ASR when detects an end-of-speech point to improve the effIciency and accuracy of ASR. </param>
    /// <param name="VadMaxDurationInSeconds"> Sets the maximum duration of Voice Activity Detection (VAD) in seconds before automatically stopping recognition if `bAutoStop` is enabled.
    /// VAD is used to identify speech segments in the audio.
    ///  </param>
    /// <param name="bShowPunctual"> Whether to show the punctuation marks during the speech recognition process. </param>
    /// <returns>Int:
    /// <ul>
    /// <li>`0`: success </li>
    /// <li> Other values: failure </li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Speech")
    static int32 StartAsr(UObject* WorldContextObject, bool bAutoStop, int32 VadMaxDurationInSeconds, bool bShowPunctual);

    /// <summary>
    /// Stops automatic speech recognition.  </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <returns>None </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Speech")
    static void StopAsr(UObject* WorldContextObject);

    /** @} */
    /** @} */
};



/// @brief UPico_AsrResult class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AsrResult : public UObject
{
    GENERATED_BODY()

private:
    FString Text = FString();
    bool bIsFinalResult = false;
    FString SessionId = FString();


public:
    void InitParams(ppfAsrResult* InppfAsrResultHandle);

    /**@brief Gets the recognized text from the ASR result. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|AsrResult")
	FString GetText();

    /**@brief Check whether the ASR result is a final result or an interim result. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|AsrResult")
	bool GetIsFinalResult();

    /**@brief Retrieves the unique session ID associated with the ASR result. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|AsrResult")
	FString GetSessionId();

};

/// @brief UPico_SpeechError class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SpeechError : public UObject
{
    GENERATED_BODY()

private:
    FString Message = FString();
    FString SessionId = FString();
    int32 Code = -999;

public:
    void InitParams(ppfSpeechError* InppfSpeechErrorHandle);

    /**@brief Retrieves the error message associated with the speech error.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|SpeechError")
	FString GetMessage();

    /**@brief Retrieves the unique session ID associated with the speech error. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|SpeechError")
	FString GetSessionId();

    /**@brief Retrieves the error code associated with the speech error. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Speech|SpeechError")
	int32 GetCode();
};