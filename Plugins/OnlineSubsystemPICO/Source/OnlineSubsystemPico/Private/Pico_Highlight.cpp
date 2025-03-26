// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "Pico_Highlight.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"


DEFINE_LOG_CATEGORY(PicoHighlight);

FPicoHighlightInterface::FPicoHighlightInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    HighlightRecordStopHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Highlight_OnRecordStop)
        .AddRaw(this, &FPicoHighlightInterface::OnHighlightRecordStop);
}

FPicoHighlightInterface::~FPicoHighlightInterface()
{

}

bool FPicoHighlightInterface::CaptureScreen(FCaptureScreenResult InCaptureScreenResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::CaptureScreen"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_CaptureScreen();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InCaptureScreenResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("CaptureScreen return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InCaptureScreenResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("CaptureScreen Successfully"));
                auto Res = NewObject<UPico_CaptureInfo>();
                Res->InitParams(ppf_Message_GetCaptureInfo(Message));
                InCaptureScreenResultDelegate.ExecuteIfBound(false, 0, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::ListMedia(const FString& SessionId, FListMediaResult InListMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::ListMedia"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_ListMedia(TCHAR_TO_UTF8(*SessionId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InListMediaResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("ListMedia return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InListMediaResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("ListMedia Successfully"));
                auto Res = NewObject<UPico_SessionMedia>();
                Res->InitParams(ppf_Message_GetSessionMedia(Message));
                InListMediaResultDelegate.ExecuteIfBound(false, 0, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::SaveMedia(const FString& JobId, const FString& SessionId, FSaveMediaResult InSaveMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::SaveMedia"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_SaveMedia(TCHAR_TO_UTF8(*JobId), TCHAR_TO_UTF8(*SessionId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InSaveMediaResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("SaveMedia return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InSaveMediaResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("SaveMedia Successfully"));
                InSaveMediaResultDelegate.ExecuteIfBound(false, 0, FString());
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::ShareMedia(const FString& JobId, const FString& SessionId, FShareMediaResult InShareMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::ShareMedia"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_ShareMedia(TCHAR_TO_UTF8(*JobId), TCHAR_TO_UTF8(*SessionId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InShareMediaResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("ShareMedia return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InShareMediaResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("ShareMedia Successfully"));
                InShareMediaResultDelegate.ExecuteIfBound(false, 0, FString());
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::StartRecord(FStartRecordResult InStartRecordResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::StartRecord"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_StartRecord();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InStartRecordResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("StartRecord return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InStartRecordResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("StartRecord Successfully"));
                InStartRecordResultDelegate.ExecuteIfBound(false, 0, FString());
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::StopRecord(FStopRecordResult InStopRecordResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::StopRecord"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_StopRecord();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InStopRecordResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("StopRecord return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InStopRecordResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("StopRecord Successfully"));
                auto Res = NewObject<UPico_RecordInfo>();
                Res->InitParams(ppf_Message_GetRecordInfo(Message));
                InStopRecordResultDelegate.ExecuteIfBound(false, 0, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoHighlightInterface::StartSession(FStartSessionResult InStartSessionResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::StartSession"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Highlight_StartSession();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InStartSessionResultDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoHighlight, Log, TEXT("StartSession return failed: %d, %s"), ErrorCode, *ErrorMessage);
                InStartSessionResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, FString());
            }
            else
            {
                UE_LOG(PicoHighlight, Log, TEXT("StartSession Successfully"));
                FString SessionID = ppf_Message_GetString(Message);
                InStartSessionResultDelegate.ExecuteIfBound(false, 0, FString(), SessionID);
            }
        }));
    return true;
#endif
    return false;
}

void FPicoHighlightInterface::OnHighlightRecordStop(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(PicoHighlight, Log, TEXT("FPicoHighlightInterface::OnHighlightRecordStop"));
    if (bIsError)
    {
        UE_LOG(PicoHighlight, Error, TEXT("HighlightRecordStop error!"));
    }

#if PLATFORM_ANDROID
    UPico_RecordInfo* InfoObject = NewObject<UPico_RecordInfo>();
    InfoObject->InitParams(ppf_Message_GetRecordInfo(Message));
    HighlightRecordStopCallback.Broadcast(InfoObject);
#endif
}

void UPico_CaptureInfo::InitParams(ppfCaptureInfo* InppfCaptureInfoHandle)
{
    UE_LOG(PicoHighlight, Log, TEXT("UPico_CaptureInfo::InitParams"));
#if PLATFORM_ANDROID
    ImagePath = UTF8_TO_TCHAR(ppf_CaptureInfo_GetImagePath(InppfCaptureInfoHandle));
    JobId = UTF8_TO_TCHAR(ppf_CaptureInfo_GetJobId(InppfCaptureInfoHandle));
#endif
}

FString UPico_CaptureInfo::GetImagePath()
{
    return ImagePath;
}

FString UPico_CaptureInfo::GetJobId()
{
    return JobId;
}

void UPico_RecordInfo::InitParams(ppfRecordInfo* InppfRecordInfoHandle)
{
    UE_LOG(PicoHighlight, Log, TEXT("UPico_RecordInfo::InitParams"));
#if PLATFORM_ANDROID
    VideoPath = UTF8_TO_TCHAR(ppf_RecordInfo_GetVideoPath(InppfRecordInfoHandle));
    JobId = UTF8_TO_TCHAR(ppf_RecordInfo_GetJobId(InppfRecordInfoHandle));
    DurationInMilliSeconds = ppf_RecordInfo_GetDurationInMilliSeconds(InppfRecordInfoHandle);
    Width = ppf_RecordInfo_GetWidth(InppfRecordInfoHandle);
    Height = ppf_RecordInfo_GetHeight(InppfRecordInfoHandle);
#endif
}

FString UPico_RecordInfo::GetVideoPath()
{
    return VideoPath;
}

FString UPico_RecordInfo::GetJobId()
{
    return JobId;
}

int32 UPico_RecordInfo::GetDurationInMilliSeconds()
{
    return DurationInMilliSeconds;
}

int32 UPico_RecordInfo::GetWidth()
{
    return Width;
}

int32 UPico_RecordInfo::GetHeight()
{
    return Height;
}

void UPico_SessionMedia::InitParams(ppfSessionMedia* InppfSessionMediaHandle)
{
    UE_LOG(PicoHighlight, Log, TEXT("UPico_SessionMedia::InitParams"));
#if PLATFORM_ANDROID
    int32 ImageSize = ppf_SessionMedia_GetImagesSize(InppfSessionMediaHandle);
    for (int32 i = 0; i < ImageSize; i++)
    {
        UPico_CaptureInfo* ThisElement = NewObject<UPico_CaptureInfo>();
        ThisElement->InitParams(ppf_SessionMedia_GetImages(InppfSessionMediaHandle, i));
        Images.Add(ThisElement);
    }
    int32 VideosSize = ppf_SessionMedia_GetVideosSize(InppfSessionMediaHandle);
    for (int32 i = 0; i < VideosSize; i++)
    {
        UPico_RecordInfo* ThisElement = NewObject<UPico_RecordInfo>();
        ThisElement->InitParams(ppf_SessionMedia_GetVideos(InppfSessionMediaHandle, i));
        Videos.Add(ThisElement);
    }
#endif
}

int32 UPico_SessionMedia::GetImagesSize()
{
    return Images.Num();
}

UPico_CaptureInfo* UPico_SessionMedia::GetImagesElement(int32 Index)
{
    if (Images.IsValidIndex(Index))
    {
        return Images[Index];
    }
    return nullptr;
}

int32 UPico_SessionMedia::GetVideosSize()
{
    return Videos.Num();
}

UPico_RecordInfo* UPico_SessionMedia::GetVideosElement(int32 Index)
{
    if (Videos.IsValidIndex(Index))
    {
        return Videos[Index];
    }
    return nullptr;
}

bool UOnlinePicoHighlightFunction::CaptureScreen(UObject* WorldContextObject, FCaptureScreenResult InCaptureScreenResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::CaptureScreen"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->CaptureScreen(InCaptureScreenResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("CaptureScreen Failed, PicoHighlightInterface Not Vailed!"));
        InCaptureScreenResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoHighlightFunction::ListMedia(UObject* WorldContextObject, const FString& SessionId, FListMediaResult InListMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::ListMedia"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->ListMedia(SessionId, InListMediaResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("ListMedia Failed, PicoHighlightInterface Not Vailed!"));
        InListMediaResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoHighlightFunction::SaveMedia(UObject* WorldContextObject, const FString& JobId, const FString& SessionId, FSaveMediaResult InSaveMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::SaveMedia"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->SaveMedia(JobId, SessionId, InSaveMediaResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("SaveMedia Failed, PicoHighlightInterface Not Vailed!"));
        InSaveMediaResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")));
        return false;
    }
}

bool UOnlinePicoHighlightFunction::ShareMedia(UObject* WorldContextObject, const FString& JobId, const FString& SessionId, FShareMediaResult InShareMediaResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::ShareMedia"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->ShareMedia(JobId, SessionId, InShareMediaResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("ShareMedia Failed, PicoHighlightInterface Not Vailed!"));
        InShareMediaResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")));
        return false;
    }
}

bool UOnlinePicoHighlightFunction::StartRecord(UObject* WorldContextObject, FStartRecordResult InStartRecordResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::StartRecord"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->StartRecord(InStartRecordResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("StartRecord Failed, PicoHighlightInterface Not Vailed!"));
        InStartRecordResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")));
        return false;
    }
}

bool UOnlinePicoHighlightFunction::StopRecord(UObject* WorldContextObject, FStopRecordResult InStopRecordResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::StopRecord"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->StopRecord(InStopRecordResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("StopRecord Failed, PicoHighlightInterface Not Vailed!"));
        InStopRecordResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoHighlightFunction::StartSession(UObject* WorldContextObject, FStartSessionResult InStartSessionResultDelegate)
{
    UE_LOG(PicoHighlight, Log, TEXT("UOnlinePicoHighlightFunction::StartSession"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoHighlightInterface())
    {
        return Subsystem->GetPicoHighlightInterface()->StartSession(InStartSessionResultDelegate);
    }
    else
    {
        UE_LOG(PicoHighlight, Log, TEXT("StartSession Failed, PicoHighlightInterface Not Vailed!"));
        InStartSessionResultDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoHighlightInterface Not Vailed")), FString());
        return false;
    }
}
