// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_Speech.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

DEFINE_LOG_CATEGORY(PicoSpeech);

FPicoSpeechInterface::FPicoSpeechInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    SpeechAsrResultHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Speech_OnAsrResult)
        .AddRaw(this, &FPicoSpeechInterface::OnSpeechAsrResult);

    SpeechErrorHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Speech_OnSpeechError)
        .AddRaw(this, &FPicoSpeechInterface::OnSpeechError);
}

FPicoSpeechInterface::~FPicoSpeechInterface()
{
    if (SpeechAsrResultHandle.IsValid())
    {
        SpeechAsrResultHandle.Reset();
    }

    if (SpeechErrorHandle.IsValid())
    {
        SpeechErrorHandle.Reset();
    }
}

EAsrEngineInitResult FPicoSpeechInterface::InitAsrEngine()
{
    UE_LOG(PicoSpeech, Log, TEXT("FPicoSpeechInterface::InitAsrEngine"));
#if PLATFORM_ANDROID
    ppfAsrEngineInitResult pRes = ppf_Speech_InitAsrEngine();
    if (pRes == ppfAsrEngineInitResult_Success)
    {
        return EAsrEngineInitResult::Success;
    }
    else if (pRes == ppfAsrEngineInitResult_AlreadyInitialized)
    {
        return EAsrEngineInitResult::AlreadyInitialized;
    }
    else if (pRes == ppfAsrEngineInitResult_Arch32BitNotSupported)
    {
        return EAsrEngineInitResult::Arch32BitNotSupported;
    }
    else if (pRes == ppfAsrEngineInitResult_InvalidConfig)
    {
        return EAsrEngineInitResult::InvalidConfig;
    }
    else
    {
        return EAsrEngineInitResult::Unknown;
    }
#endif
    return EAsrEngineInitResult::None;
}

int32 FPicoSpeechInterface::StartAsr(bool bAutoStop, int32 VadMaxDurationInSeconds, bool bShowPunctual)
{
    UE_LOG(PicoSpeech, Log, TEXT("FPicoSpeechInterface::StartAsr"));
#if PLATFORM_ANDROID   
    auto Options = ppf_StartAsrOptions_Create();
    ppf_StartAsrOptions_SetAutoStop(Options, bAutoStop);
    ppf_StartAsrOptions_SetVadMaxDurationInSeconds(Options, VadMaxDurationInSeconds);
    ppf_StartAsrOptions_SetShowPunctual(Options, bShowPunctual);
    int32 Res = ppf_Speech_StartAsr(Options);
    ppf_StartAsrOptions_Destroy(Options);
    return Res;
#endif
    return -999;
}

void FPicoSpeechInterface::StopAsr()
{
    UE_LOG(PicoSpeech, Log, TEXT("FPicoSpeechInterface::StopAsr"));
#if PLATFORM_ANDROID
    ppf_Speech_StopAsr();
#endif
}

void FPicoSpeechInterface::OnSpeechAsrResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(PicoSpeech, Log, TEXT("FPicoSpeechInterface::OnSpeechAsrResult"));
    if (bIsError)
    {
        UE_LOG(PicoSpeech, Error, TEXT("OnSpeechAsrResult error!"));
    }
#if PLATFORM_ANDROID
    UPico_AsrResult* Obj = NewObject<UPico_AsrResult>();
    Obj->InitParams(ppf_Message_GetAsrResult(Message));
    SpeechAsrResultCallback.Broadcast(Obj);
#endif
}

void FPicoSpeechInterface::OnSpeechError(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(PicoSpeech, Log, TEXT("FPicoSpeechInterface::OnSpeechError"));
    if (bIsError)
    {
        UE_LOG(PicoSpeech, Error, TEXT("OnSpeechError error!"));
    }
#if PLATFORM_ANDROID
    UPico_SpeechError* Obj = NewObject<UPico_SpeechError>();
    Obj->InitParams(ppf_Message_GetSpeechError(Message));
    SpeechErrorCallback.Broadcast(Obj);
#endif
}

void UPico_AsrResult::InitParams(ppfAsrResult* InppfAsrResultHandle)
{
    UE_LOG(PicoSpeech, Log, TEXT("UPico_AsrResult::InitParams"));
#if PLATFORM_ANDROID
    Text = UTF8_TO_TCHAR(ppf_AsrResult_GetText(InppfAsrResultHandle));
    bIsFinalResult = ppf_AsrResult_GetIsFinalResult(InppfAsrResultHandle);
    SessionId = UTF8_TO_TCHAR(ppf_AsrResult_GetSessionId(InppfAsrResultHandle));
#endif
}

FString UPico_AsrResult::GetText()
{
    return Text;
}

bool UPico_AsrResult::GetIsFinalResult()
{
    return bIsFinalResult;
}

FString UPico_AsrResult::GetSessionId()
{
    return SessionId;
}

void UPico_SpeechError::InitParams(ppfSpeechError* InppfSpeechErrorHandle)
{
    UE_LOG(PicoSpeech, Log, TEXT("UPico_SpeechError::InitParams"));
#if PLATFORM_ANDROID
    Message = UTF8_TO_TCHAR(ppf_SpeechError_GetMessage(InppfSpeechErrorHandle));
    SessionId = UTF8_TO_TCHAR(ppf_SpeechError_GetSessionId(InppfSpeechErrorHandle));
    Code = ppf_SpeechError_GetCode(InppfSpeechErrorHandle);
#endif
}

FString UPico_SpeechError::GetMessage()
{
    return Message;
}

FString UPico_SpeechError::GetSessionId()
{
    return SessionId;
}

int32 UPico_SpeechError::GetCode()
{
    return Code;
}

EAsrEngineInitResult UOnlinePicoSpeechFunction::InitAsrEngine(UObject* WorldContextObject)
{
    UE_LOG(PicoSpeech, Log, TEXT("UOnlinePicoSpeechFunction::InitAsrEngine"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSpeechInterface())
    {
        return Subsystem->GetPicoSpeechInterface()->InitAsrEngine();
    }
    else
    {
        UE_LOG(PicoSpeech, Log, TEXT("InitAsrEngine Failed, PicoSpeechInterface Not Vailed!"));
        return EAsrEngineInitResult::None;
    }
}

int32 UOnlinePicoSpeechFunction::StartAsr(UObject* WorldContextObject, bool bAutoStop, int32 VadMaxDurationInSeconds, bool bShowPunctual)
{
    UE_LOG(PicoSpeech, Log, TEXT("UOnlinePicoSpeechFunction::StartAsr"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSpeechInterface())
    {
        return Subsystem->GetPicoSpeechInterface()->StartAsr(bAutoStop, VadMaxDurationInSeconds, bShowPunctual);
    }
    else
    {
        UE_LOG(PicoSpeech, Log, TEXT("StartAsr Failed, PicoSpeechInterface Not Vailed!"));
        return -999;
    }
}

void UOnlinePicoSpeechFunction::StopAsr(UObject* WorldContextObject)
{
    UE_LOG(PicoSpeech, Log, TEXT("UOnlinePicoSpeechFunction::StopAsr"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSpeechInterface())
    {
        Subsystem->GetPicoSpeechInterface()->StopAsr();
    }
    else
    {
        UE_LOG(PicoSpeech, Log, TEXT("StopAsr Failed, PicoSpeechInterface Not Vailed!"));
    }
}
