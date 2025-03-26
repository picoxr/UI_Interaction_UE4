// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "RTCPicoUserInterface.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "PPF_RtcEngineInitResult.h"

#if PLATFORM_WINDOWS
#include <stdio.h>
#endif

DEFINE_LOG_CATEGORY(RtcInterface);

FRTCPicoUserInterface::FRTCPicoUserInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    OnJoinRoomNotificationResultHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnJoinRoom)
        .AddRaw(this, &FRTCPicoUserInterface::OnJoinRoomResult);

    OnLeaveRoomNotificationResultHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnLeaveRoom)
        .AddRaw(this, &FRTCPicoUserInterface::OnLeaveRoomResult);

    OnUserJoinRoomNotificationResultHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserJoinRoom)
        .AddRaw(this, &FRTCPicoUserInterface::OnUserJoinRoomResult);

    OnUserLeaveRoomNotificationResultHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserLeaveRoom)
        .AddRaw(this, &FRTCPicoUserInterface::OnUserLeaveRoomResult);

    OnRoomStatsNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomStats)
        .AddRaw(this, &FRTCPicoUserInterface::OnRoomStatsNotification);

    OnWarnNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnWarn)
        .AddRaw(this, &FRTCPicoUserInterface::OnWarnNotification);

    OnErrorNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnError)
        .AddRaw(this, &FRTCPicoUserInterface::OnErrorNotification);

    OnRoomWarnNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomWarn)
        .AddRaw(this, &FRTCPicoUserInterface::OnRoomWarnNotification);

    OnRoomErrorNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomError)
        .AddRaw(this, &FRTCPicoUserInterface::OnRoomErrorNotification);

    OnConnectionStateChangeNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnConnectionStateChange)
        .AddRaw(this, &FRTCPicoUserInterface::OnConnectionStateChangeNotification);

    OnUserStartAudioCaptureNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserStartAudioCapture)
        .AddRaw(this, &FRTCPicoUserInterface::OnUserStartAudioCaptureNotification);

    OnUserStopAudioCaptureNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserStopAudioCapture)
        .AddRaw(this, &FRTCPicoUserInterface::OnUserStopAudioCaptureNotification);

    OnAudioPlaybackDeviceChangedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnAudioPlaybackDeviceChanged)
        .AddRaw(this, &FRTCPicoUserInterface::OnAudioPlaybackDeviceChangeNotification);

    OnRemoteAudioPropertiesReportNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRemoteAudioPropertiesReport)
        .AddRaw(this, &FRTCPicoUserInterface::OnRemoteAudioPropertiesReportNotification);

    OnLocalAudioPropertiesReportNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnLocalAudioPropertiesReport)
        .AddRaw(this, &FRTCPicoUserInterface::OnLocalAudioPropertiesReportNotification);

    OnUserMuteAudioNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserMuteAudio)
        .AddRaw(this, &FRTCPicoUserInterface::OnUserMuteAudioNotification);

    OnMediaDeviceStateChangedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnMediaDeviceStateChanged)
        .AddRaw(this, &FRTCPicoUserInterface::OnMediaDeviceStateChangedNotification);

    OnRtcUserPublishInfoNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserPublishStream)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcUserPublishInfoNotification);

    OnRtcUserUnPublishInfoNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserUnPublishStream)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcUserUnPublishInfoNotification);

    OnGetRtcStreamSyncInfoNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnStreamSyncInfoReceived)
        .AddRaw(this, &FRTCPicoUserInterface::OnGetRtcStreamSyncInfoNotification);

    OnRtcUserMessageSendResultNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomMessageSendResult)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcMessageSendResultNotification);

    OnRtcRoomMessageSendResultNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserMessageSendResult)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcMessageSendResultNotification);

    OnRtcUserBinaryMessageReceivedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserBinaryMessageReceived)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcBinaryMessageReceivedNotification);

    OnRtcRoomBinaryMessageReceivedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomBinaryMessageReceived)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcBinaryMessageReceivedNotification);

    OnRtcRoomMessageReceivedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnRoomMessageReceived)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcRoomMessageReceivedNotification);

    OnRtcUserMessageReceivedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnUserMessageReceived)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcUserMessageReceivedNotification);

    OnRtcTokenWilExpireNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Rtc_OnTokenWillExpire)
        .AddRaw(this, &FRTCPicoUserInterface::OnRtcTokenWilExpireNotification);

}

FRTCPicoUserInterface::~FRTCPicoUserInterface()
{
    if (OnJoinRoomNotificationResultHandle.IsValid())
    {
        OnJoinRoomNotificationResultHandle.Reset();
    }

    if (OnUserJoinRoomNotificationResultHandle.IsValid())
    {
        OnUserJoinRoomNotificationResultHandle.Reset();
    }

    if (OnUserLeaveRoomNotificationResultHandle.IsValid())
    {
        OnUserLeaveRoomNotificationResultHandle.Reset();
    }

    if (OnRoomStatsNotificationHandle.IsValid())
    {
        OnRoomStatsNotificationHandle.Reset();
    }

    if (OnWarnNotificationHandle.IsValid())
    {
        OnWarnNotificationHandle.Reset();
    }

    if (OnErrorNotificationHandle.IsValid())
    {
        OnErrorNotificationHandle.Reset();
    }

    if (OnRoomWarnNotificationHandle.IsValid())
    {
        OnRoomWarnNotificationHandle.Reset();
    }

    if (OnRoomErrorNotificationHandle.IsValid())
    {
        OnRoomErrorNotificationHandle.Reset();
    }

    if (OnConnectionStateChangeNotificationHandle.IsValid())
    {
        OnConnectionStateChangeNotificationHandle.Reset();
    }

    if (OnUserStartAudioCaptureNotificationHandle.IsValid())
    {
        OnUserStartAudioCaptureNotificationHandle.Reset();
    }

    if (OnUserStopAudioCaptureNotificationHandle.IsValid())
    {
        OnUserStopAudioCaptureNotificationHandle.Reset();
    }

    if (OnAudioPlaybackDeviceChangedNotificationHandle.IsValid())
    {
        OnAudioPlaybackDeviceChangedNotificationHandle.Reset();
    }

    if (OnRemoteAudioPropertiesReportNotificationHandle.IsValid())
    {
        OnRemoteAudioPropertiesReportNotificationHandle.Reset();
    }

    if (OnLocalAudioPropertiesReportNotificationHandle.IsValid())
    {
        OnLocalAudioPropertiesReportNotificationHandle.Reset();
    }

    if (OnUserMuteAudioNotificationHandle.IsValid())
    {
        OnUserMuteAudioNotificationHandle.Reset();
    }

    if (OnMediaDeviceStateChangedNotificationHandle.IsValid())
    {
        OnMediaDeviceStateChangedNotificationHandle.Reset();
    }

    // v2
    if (OnRtcUserPublishInfoNotificationHandle.IsValid())
    {
        OnRtcUserPublishInfoNotificationHandle.Reset();
    }

    if (OnRtcUserUnPublishInfoNotificationHandle.IsValid())
    {
        OnRtcUserUnPublishInfoNotificationHandle.Reset();
    }

    if (OnGetRtcStreamSyncInfoNotificationHandle.IsValid())
    {
        OnGetRtcStreamSyncInfoNotificationHandle.Reset();
    }

    if (OnRtcUserMessageSendResultNotificationHandle.IsValid())
    {
        OnRtcUserMessageSendResultNotificationHandle.Reset();
    }

    if (OnRtcRoomMessageSendResultNotificationHandle.IsValid())
    {
        OnRtcRoomMessageSendResultNotificationHandle.Reset();
    }

    if (OnRtcUserBinaryMessageReceivedNotificationHandle.IsValid())
    {
        OnRtcUserBinaryMessageReceivedNotificationHandle.Reset();
    }

    if (OnRtcRoomBinaryMessageReceivedNotificationHandle.IsValid())
    {
        OnRtcRoomBinaryMessageReceivedNotificationHandle.Reset();
    }

    if (OnRtcRoomMessageReceivedNotificationHandle.IsValid())
    {
        OnRtcRoomMessageReceivedNotificationHandle.Reset();
    }

    if (OnRtcUserMessageReceivedNotificationHandle.IsValid())
    {
        OnRtcUserMessageReceivedNotificationHandle.Reset();
    }

    if (OnRtcTokenWilExpireNotificationHandle.IsValid())
    {
        OnRtcTokenWilExpireNotificationHandle.Reset();
    }
}

void FRTCPicoUserInterface::GetToken(const FString& UserId, const FString& RoomId, int Ttl, int InValue, const FOnGetTokenComplete& Delegate)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::GetToken!"));
    auto TokenOptions = ppf_RtcGetTokenOptions_Create();
    ppf_RtcGetTokenOptions_ClearPrivileges(TokenOptions);
    ppf_RtcGetTokenOptions_SetUserId(TokenOptions, TCHAR_TO_UTF8(*UserId));
    ppf_RtcGetTokenOptions_SetRoomId(TokenOptions, TCHAR_TO_UTF8(*RoomId));
    ppf_RtcGetTokenOptions_SetTtl(TokenOptions, Ttl);
    ppf_RtcGetTokenOptions_SetPrivileges(TokenOptions, ppfRtcPrivilege_PublishAudioStream, InValue);
    ppf_RtcGetTokenOptions_SetPrivileges(TokenOptions, ppfRtcPrivilege_PublishStream, InValue);
    ppf_RtcGetTokenOptions_SetPrivileges(TokenOptions, ppfRtcPrivilege_PublishVideoStream, InValue);
    ppf_RtcGetTokenOptions_SetPrivileges(TokenOptions, ppfRtcPrivilege_SubscribeStream, InValue);
    PicoSubsystem.AddAsyncTask
    (
        ppf_Rtc_GetToken(TokenOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryGetTokenComplete(Message, bIsError, Delegate);
            }
        )
    );
    ppf_RtcGetTokenOptions_Destroy(TokenOptions);
}

int32 FRTCPicoUserInterface::RtcSendStreamSyncInfo(int32 Info, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendStreamSyncInfo!"));
    auto RtcStreamSyncInfoOptions = ppf_RtcStreamSyncInfoOptions_Create();
    if (InStreamIndex == ERtcStreamIndex::None || InSyncInfoStreamType == ERtcSyncInfoStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcSendStreamSyncInfo wrong param!"));
        return -1;
    }
    ppfRtcStreamIndex pRtcStreamIndex;
    if (InStreamIndex == ERtcStreamIndex::Main)
    {
        pRtcStreamIndex = ppfRtcStreamIndex_Main;
    }
    else
    {   
        pRtcStreamIndex = ppfRtcStreamIndex_Screen;
    }
    ppfRtcSyncInfoStreamType pRtcSyncInfoStreamType = ppfRtcSyncInfoStreamType_Audio;
    ppf_RtcStreamSyncInfoOptions_SetStreamIndex(RtcStreamSyncInfoOptions, pRtcStreamIndex);
    ppf_RtcStreamSyncInfoOptions_SetRepeatCount(RtcStreamSyncInfoOptions, RepeatCount);
    ppf_RtcStreamSyncInfoOptions_SetStreamType(RtcStreamSyncInfoOptions, pRtcSyncInfoStreamType);
    TArray<uint8> Res = GetBytesByInt(Info);
    int32 Length = Res.Num();
    //uint8* Res = nullptr;
    //int32 Length = 0;
    //StringToBytes(FString::FromInt(Info), Res, Length);
    int32 ReturnCode = ppf_Rtc_SendStreamSyncInfo(Res.GetData(), Length, RtcStreamSyncInfoOptions);
    ppf_RtcStreamSyncInfoOptions_Destroy(RtcStreamSyncInfoOptions);
    return ReturnCode;
}

int32 FRTCPicoUserInterface::RtcSendStreamSyncInfo(TArray<uint8> Bytes, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendStreamSyncInfo Bytes!"));
    auto RtcStreamSyncInfoOptions = ppf_RtcStreamSyncInfoOptions_Create();
    if (InStreamIndex == ERtcStreamIndex::None || InSyncInfoStreamType == ERtcSyncInfoStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcSendStreamSyncInfo wrong param!"));
        return -1;
    }
    ppfRtcStreamIndex pRtcStreamIndex;
    if (InStreamIndex == ERtcStreamIndex::Main)
    {
        pRtcStreamIndex = ppfRtcStreamIndex_Main;
    }
    else
    {
        pRtcStreamIndex = ppfRtcStreamIndex_Screen;
    }
    ppfRtcSyncInfoStreamType pRtcSyncInfoStreamType = ppfRtcSyncInfoStreamType_Audio;
    ppf_RtcStreamSyncInfoOptions_SetStreamIndex(RtcStreamSyncInfoOptions, pRtcStreamIndex);
    ppf_RtcStreamSyncInfoOptions_SetRepeatCount(RtcStreamSyncInfoOptions, RepeatCount);
    ppf_RtcStreamSyncInfoOptions_SetStreamType(RtcStreamSyncInfoOptions, pRtcSyncInfoStreamType);
    int32 Length = Bytes.Num();
    int32 ReturnCode = ppf_Rtc_SendStreamSyncInfo(Bytes.GetData(), Length, RtcStreamSyncInfoOptions);
    ppf_RtcStreamSyncInfoOptions_Destroy(RtcStreamSyncInfoOptions);
    return ReturnCode;
}

void FRTCPicoUserInterface::RtcRoomPublishStream(const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomPublishStream!"));
    if (InRtcMediaStreamType == ERtcMediaStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcRoomPublishStream wrong param!"));
        return;
    }
    ppfRtcMediaStreamType pRtcMediaStreamType;
    if (InRtcMediaStreamType == ERtcMediaStreamType::Audio)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Audio;
    }
    else if (InRtcMediaStreamType == ERtcMediaStreamType::Video)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Video;
    }
    else
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Both;
    }
    ppf_Rtc_RoomPublishStream(TCHAR_TO_UTF8(*RoomId), pRtcMediaStreamType);
}

void FRTCPicoUserInterface::RtcRoomSetRemoteAudioPlaybackVolume(const FString& RoomId, const FString& UserId, int32 Volume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomSetRemoteAudioPlaybackVolume!"));
    ppf_Rtc_RoomSetRemoteAudioPlaybackVolume(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), Volume);
}

void FRTCPicoUserInterface::RtcRoomSubscribeStream(const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomSubscribeStream!"));
    if (InRtcMediaStreamType == ERtcMediaStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcRoomSubscribeStream wrong param!"));
        return;
    }
    ppfRtcMediaStreamType pRtcMediaStreamType;
    if (InRtcMediaStreamType == ERtcMediaStreamType::Audio)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Audio;
    }
    else if (InRtcMediaStreamType == ERtcMediaStreamType::Video)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Video;
    }
    else
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Both;
    }
    ppf_Rtc_RoomSubscribeStream(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), pRtcMediaStreamType);
}

void FRTCPicoUserInterface::RtcRoomUnPublishStream(const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomUnPublishStream!"));
    if (InRtcMediaStreamType == ERtcMediaStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcRoomUnPublishStream wrong param!"));
        return;
    }
    ppfRtcMediaStreamType pRtcMediaStreamType;
    if (InRtcMediaStreamType == ERtcMediaStreamType::Audio)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Audio;
    }
    else if (InRtcMediaStreamType == ERtcMediaStreamType::Video)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Video;
    }
    else
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Both;
    }
    ppf_Rtc_RoomUnPublishStream(TCHAR_TO_UTF8(*RoomId), pRtcMediaStreamType);
}

void FRTCPicoUserInterface::RtcRoomUnsubscribeStream(const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomUnsubscribeStream!"));
    if (InRtcMediaStreamType == ERtcMediaStreamType::None)
    {
        UE_LOG(RtcInterface, Log, TEXT("RtcRoomUnsubscribeStream wrong param!"));
        return;
    }
    ppfRtcMediaStreamType pRtcMediaStreamType;
    if (InRtcMediaStreamType == ERtcMediaStreamType::Audio)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Audio;
    }
    else if (InRtcMediaStreamType == ERtcMediaStreamType::Video)
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Video;
    }
    else
    {
        pRtcMediaStreamType = ppfRtcMediaStreamType_Both;
    }
    ppf_Rtc_RoomUnsubscribeStream(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), pRtcMediaStreamType);
}

int64 FRTCPicoUserInterface::RtcSendRoomBinaryMessage(const FString& RoomId, const FString& MessageInfo)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendRoomBinaryMessage!"));
    TArray<uint8> Bytes;
    Bytes.SetNumUninitialized(MessageInfo.Len());
    int32 NumBytes = StringToBytes(MessageInfo, Bytes.GetData(), Bytes.Num());
    return ppf_Rtc_SendRoomBinaryMessage(TCHAR_TO_UTF8(*RoomId), Bytes.GetData(), NumBytes);
}

int64 FRTCPicoUserInterface::RtcSendRoomBinaryMessage(const FString& RoomId, TArray<uint8> Bytes)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendRoomBinaryMessage Bytes!"));
    int32 NumBytesArray = Bytes.Num();
    return ppf_Rtc_SendRoomBinaryMessage(TCHAR_TO_UTF8(*RoomId), Bytes.GetData(), NumBytesArray);
}

int64 FRTCPicoUserInterface::RtcSendRoomMessage(const FString& RoomId, const FString& Message)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendRoomMessage!"));
    return ppf_Rtc_SendRoomMessage(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*Message));
}

int64 FRTCPicoUserInterface::RtcSendUserBinaryMessage(const FString& RoomId, const FString& UserId, const FString& MessageInfo)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendUserBinaryMessage!"));
    TArray<uint8> Bytes;
    Bytes.SetNumUninitialized(MessageInfo.Len());
    int32 NumBytes = StringToBytes(MessageInfo, Bytes.GetData(), Bytes.Num());
    return ppf_Rtc_SendUserBinaryMessage(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), Bytes.GetData(), NumBytes);
}

int64 FRTCPicoUserInterface::RtcSendUserBinaryMessage(const FString& RoomId, const FString& UserId, TArray<uint8> Bytes)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendUserBinaryMessage Bytes!"));
    int32 NumBytesArray = Bytes.Num();
    return ppf_Rtc_SendUserBinaryMessage(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), Bytes.GetData(), NumBytesArray);
}

int64 FRTCPicoUserInterface::RtcSendUserMessage(const FString& RoomId, const FString& UserId, const FString& Message)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSendUserMessage!"));
    return ppf_Rtc_SendUserMessage(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*UserId), TCHAR_TO_UTF8(*Message));
}

TArray<uint8> FRTCPicoUserInterface::GetBytesByInt(int32 Inint)
{
    std::string StrRes;
    int32 Count = 0;
    if (Inint == 0)
    {
        StrRes = "0";
    }
    while (Inint && Count++ < 8)
    {
        StrRes = HEX[(Inint & 0x0f)] + StrRes;
        Inint >>= 4;
    }
    TArray<uint8> Res;
    std::string Temps;
    int Bytelen = StrRes.length() / 2;
    unsigned int n;
    for (int i = 0; i < Bytelen; i++)
    {
        Temps = StrRes.substr(i * 2, 2);
#if PLATFORM_ANDROID
        sscanf(Temps.c_str(), "%x", &n);
#elif PLATFORM_WINDOWS
        sscanf_s(Temps.c_str(), "%x", &n);
#endif
        Res.Add(n);
    }
    return Res;
}

void FRTCPicoUserInterface::OnQueryGetTokenComplete(ppfMessageHandle Message, bool bIsError, const FOnGetTokenComplete& Delegate)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnQueryGetTokenComplete!"));
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        ErrorStr = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        Delegate.ExecuteIfBound(FString(), false, ErrorStr);
        return;
    }
    else
    {
        FString Token = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(Token, true, FString());
    }
}

void FRTCPicoUserInterface::OnJoinRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnJoinRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Join room result error!"));
        return;
    }
    auto JoinRoomResult = ppf_Message_GetRtcJoinRoomResult(Message);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcJoinRoomResult_GetRoomId(JoinRoomResult)));
    FString UserId = UTF8_TO_TCHAR((ppf_RtcJoinRoomResult_GetUserId(JoinRoomResult)));
    int ErrorCode = ppf_RtcJoinRoomResult_GetErrorCode(JoinRoomResult);
    int Elapsed = ppf_RtcJoinRoomResult_GetElapsed(JoinRoomResult);
    ppfRtcJoinRoomType GetType = ppf_RtcJoinRoomResult_GetJoinType(JoinRoomResult);
    ERtcJoinRoomType JoinRoomType;
    if (GetType == ppfRtcJoinRoomType_First)
    {
        JoinRoomType = ERtcJoinRoomType::First;
    }
    else if (GetType == ppfRtcJoinRoomType_Reconnected)
    {
        JoinRoomType = ERtcJoinRoomType::Reconnected;
    }
    else
    {
        JoinRoomType = ERtcJoinRoomType::None;
    }
    RtcJoinRoomCallback.Broadcast(RoomId, UserId, ErrorCode, Elapsed, JoinRoomType);
}

void FRTCPicoUserInterface::OnLeaveRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnLeaveRoomResult"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Leave room result error!"));
    }
    auto LeaveRoomResult = ppf_Message_GetRtcLeaveRoomResult(Message);
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcLeaveRoomResult_GetRoomId(LeaveRoomResult));
    RtcLeaveRoomCallback.Broadcast(RoomId);
}

void FRTCPicoUserInterface::OnUserJoinRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserJoinRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User join room result error!"));
        return;
    }
    auto UserJoinInfo = ppf_Message_GetRtcUserJoinInfo(Message);
    FString UserId = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetUserId(UserJoinInfo)));
    FString UserExtra = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetUserExtra(UserJoinInfo)));
    int Elapsed = ppf_RtcUserJoinInfo_GetElapsed(UserJoinInfo);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetRoomId(UserJoinInfo)));
    RtcUserJoinInfoCallback.Broadcast(UserId, UserExtra, Elapsed, RoomId);
}

void FRTCPicoUserInterface::OnUserLeaveRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserLeaveRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User leave room result error!"));
        return;
    }
    auto UserLeaveInfo = ppf_Message_GetRtcUserLeaveInfo(Message);
    FString UserId = UTF8_TO_TCHAR((ppf_RtcUserLeaveInfo_GetUserId(UserLeaveInfo)));
    ppfRtcUserLeaveReasonType LeaveReason = ppf_RtcUserLeaveInfo_GetOfflineReason(UserLeaveInfo);
    ERtcUserLeaveReasonType RtcUserLeaveReasonType;
    if (LeaveReason == ppfRtcUserLeaveReasonType_Dropped)
    {
        RtcUserLeaveReasonType = ERtcUserLeaveReasonType::Dropped;
    }
    else if (LeaveReason == ppfRtcUserLeaveReasonType_Quit)
    {
        RtcUserLeaveReasonType = ERtcUserLeaveReasonType::Quit;
    }
    else
    {
        RtcUserLeaveReasonType = ERtcUserLeaveReasonType::None;
    }
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcUserLeaveInfo_GetRoomId(UserLeaveInfo)));
    RtcUserLeaveInfoCallback.Broadcast(UserId, RtcUserLeaveReasonType, RoomId);
}

void FRTCPicoUserInterface::OnRoomStatsNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomStatsNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room stats error!"));
        return;
    }
    auto RoomStates = ppf_Message_GetRtcRoomStats(Message);
    int TotalDuration = ppf_RtcRoomStats_GetTotalDuration(RoomStates);
    int UserCount = ppf_RtcRoomStats_GetUserCount(RoomStates);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomStats_GetRoomId(RoomStates)));
    RtcRoomStateCallback.Broadcast(TotalDuration, UserCount, RoomId);
}

void FRTCPicoUserInterface::OnWarnNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnWarnNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Warn notification error!"));
        return;
    }
    int32 MessageCode = (ppf_Message_GetInt32(Message));
    RtcWarnCallback.Broadcast(MessageCode);
}

void FRTCPicoUserInterface::OnErrorNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnErrorNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Error notification error!"));
        return;
    }
    int32 MessageCode = (ppf_Message_GetInt32(Message));
    RtcErrorCallback.Broadcast(MessageCode);
}

void FRTCPicoUserInterface::OnRoomWarnNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomWarnNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room warn notification error!"));
        return;
    }
    auto RoomWarn = ppf_Message_GetRtcRoomWarn(Message);
    int Code = ppf_RtcRoomWarn_GetCode(RoomWarn);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomWarn_GetRoomId(RoomWarn)));
    RtcRoomWarnCallback.Broadcast(Code, RoomId);
}

void FRTCPicoUserInterface::OnRoomErrorNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomErrorNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room error notification error!"));
        return;
    }
    auto RoomError = ppf_Message_GetRtcRoomError(Message);
    int Code = ppf_RtcRoomError_GetCode(RoomError);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomError_GetRoomId(RoomError)));
    RtcRoomErrorCallback.Broadcast(Code, RoomId);
}

void FRTCPicoUserInterface::OnConnectionStateChangeNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnConnectionStateChangeNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("ConnectionStateChange notification error!"));
        return;
    }
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcConnectStateChangedCallback.Broadcast(MessageString);
}

void FRTCPicoUserInterface::OnUserStartAudioCaptureNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserStartAudioCaptureNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("UserStartAudioCapture notification error!"));
        return;
    }
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcUserStartAudioCaptureCallback.Broadcast(MessageString);
}

void FRTCPicoUserInterface::OnUserStopAudioCaptureNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserStopAudioCaptureNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("UserStopAudioCapture notification error!"));
        return;
    }
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcUserStopAudioCaptureCallback.Broadcast(MessageString);
}

void FRTCPicoUserInterface::OnAudioPlaybackDeviceChangeNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnAudioPlaybackDeviceChangeNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Audio playback device change notification error!"));
        return;
    }
    ppfRtcAudioPlaybackDevice AudioPlaybackDeviceChange = ppf_Message_GetRtcAudioPlaybackDevice(Message);
    ERtcAudioPlaybackDevice RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::None;
    if (AudioPlaybackDeviceChange == ppfRtcAudioPlaybackDevice_EarPiece)
    {
        RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::EarPiece;
    }
    else if (AudioPlaybackDeviceChange == ppfRtcAudioPlaybackDevice_Headset)
    {
        RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::Headset;
    }
    else if (AudioPlaybackDeviceChange == ppfRtcAudioPlaybackDevice_HeadsetBlueTooth)
    {
        RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::HeadsetBlueTooth;
    }
    else if (AudioPlaybackDeviceChange == ppfRtcAudioPlaybackDevice_HeadsetUsb)
    {
        RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::HeadsetUsb;
    }
    else if (AudioPlaybackDeviceChange == ppfRtcAudioPlaybackDevice_SpeakerPhone)
    {
        RtcAudioPlaybackDevice = ERtcAudioPlaybackDevice::SpeakerPhone;
    }
    RtcAudioPlaybackDeviceChangeCallback.Broadcast(RtcAudioPlaybackDevice);
}

void FRTCPicoUserInterface::OnRemoteAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRemoteAudioPropertiesReportNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Remote audio properties report notification error!"));
        return;
    }
    ppfRtcRemoteAudioPropertiesReportHandle RtcRemoteAudioProperitesReport = ppf_Message_GetRtcRemoteAudioPropertiesReport(Message);
    size_t S_AudioPropertiesInfosSize = ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize(RtcRemoteAudioProperitesReport);
    int TotalRemoteVolume = ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume(RtcRemoteAudioProperitesReport);
    TArray<FString> RoomIdArray;
    TArray<FString> UserIdArray;
    TArray<ERtcStreamIndex> StreamIndexArray;
    TArray<int> VolumeArray;
    for (size_t i = 0; i < S_AudioPropertiesInfosSize; i++)
    {
        auto AudioPropertiesInfos = ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos(RtcRemoteAudioProperitesReport, i);
        auto AudioPropertiesInfo = ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo(AudioPropertiesInfos);
        int Volume = ppf_RtcAudioPropertyInfo_GetVolume(AudioPropertiesInfo);
        VolumeArray.Add(Volume);
        auto StreamKey = ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey(AudioPropertiesInfos);
        FString RoomId = UTF8_TO_TCHAR(ppf_RtcRemoteStreamKey_GetRoomId(StreamKey));
        RoomIdArray.Add(RoomId);
        FString UserId = UTF8_TO_TCHAR(ppf_RtcRemoteStreamKey_GetUserId(StreamKey));
        UserIdArray.Add(UserId);
        ppfRtcStreamIndex RtcStreamIndex = ppf_RtcRemoteStreamKey_GetStreamIndex(StreamKey);
        ERtcStreamIndex StreamIndex = ERtcStreamIndex::None;
        if (RtcStreamIndex == ppfRtcStreamIndex_Main)
        {
            StreamIndex = ERtcStreamIndex::Main;
        }
        else if (RtcStreamIndex == ppfRtcStreamIndex_Screen)
        {
            StreamIndex = ERtcStreamIndex::Screen;
        }
        StreamIndexArray.Add(StreamIndex);

    }
    UE_LOG(RtcInterface, Log, TEXT("Remote audio properties broadcast!"));
    RtcRemoteAudioPropertiesReportCallback.Broadcast(TotalRemoteVolume, VolumeArray, RoomIdArray, UserIdArray, StreamIndexArray);
}

void FRTCPicoUserInterface::OnLocalAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnLocalAudioPropertiesReportNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Local audio properties report notification error!"));
        return;
    }
    auto RtcLocalAudioProperitesReport = ppf_Message_GetRtcLocalAudioPropertiesReport(Message);
    size_t S_AudioPropertiesInfosSize = ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize(RtcLocalAudioProperitesReport);
    TArray<ERtcStreamIndex> StreamIndexArray;
    TArray<int> VolumeArray;
    for (size_t i = 0; i < S_AudioPropertiesInfosSize; i++)
    {
        auto AudioPropertiesInfos = ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos(RtcLocalAudioProperitesReport, i);
        ppfRtcStreamIndex RtcStreamIndex = ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex(AudioPropertiesInfos);
        ERtcStreamIndex StreamIndex = ERtcStreamIndex::None;
        if (RtcStreamIndex == ppfRtcStreamIndex_Main)
        {
            StreamIndex = ERtcStreamIndex::Main;
        }
        else if (RtcStreamIndex == ppfRtcStreamIndex_Screen)
        {
            StreamIndex = ERtcStreamIndex::Screen;
        }

        auto AudioPropertyInfo = ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo(AudioPropertiesInfos);
        int Volume = ppf_RtcAudioPropertyInfo_GetVolume(AudioPropertyInfo);
        StreamIndexArray.Add(StreamIndex);
        VolumeArray.Add(Volume);
    }
    RtcLocalAudioPropertiesReportCallback.Broadcast(StreamIndexArray, VolumeArray);
}

void FRTCPicoUserInterface::OnUserMuteAudioNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserMuteAudioNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User mute audio error!"));
        return;
    }
    auto MuteInfo = ppf_Message_GetRtcMuteInfo(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcMuteInfo_GetUserId(MuteInfo));
    ppfRtcMuteState ppfMuteState = ppf_RtcMuteInfo_GetMuteState(MuteInfo);
    ERtcMuteState RtcMuteState = ERtcMuteState::None;
    if (ppfMuteState == ppfRtcMuteState_Off)
    {
        RtcMuteState = ERtcMuteState::Off;
    }
    else if (ppfMuteState == ppfRtcMuteState_On)
    {
        RtcMuteState = ERtcMuteState::On;
    }
    RtcUserMuteAudioInfoCallback.Broadcast(UserId, RtcMuteState);
}

void FRTCPicoUserInterface::OnMediaDeviceStateChangedNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnMediaDeviceStateChangedNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Media device state changed info error!"));
        return;
    }
    auto MediaDeviceChangeInfo = ppf_Message_GetRtcMediaDeviceChangeInfo(Message);
    FString DeviceId = UTF8_TO_TCHAR((ppf_RtcMediaDeviceChangeInfo_GetDeviceId(MediaDeviceChangeInfo)));
    ppfRtcMediaDeviceType RtcMediaDeviceType = ppf_RtcMediaDeviceChangeInfo_GetDeviceType(MediaDeviceChangeInfo);
    ERtcMediaDeviceType MediaDeciveType = ERtcMediaDeviceType::None;
    if (RtcMediaDeviceType == ppfRtcMediaDeviceType_AudioCaptureDevice)
    {
        MediaDeciveType = ERtcMediaDeviceType::AudioCaptureDevice;
    }
    else if (RtcMediaDeviceType == ppfRtcMediaDeviceType_AudioRenderDevice)
    {
        MediaDeciveType = ERtcMediaDeviceType::AudioRenderDevice;
    }
    else if (RtcMediaDeviceType == ppfRtcMediaDeviceType_AudioUnknown)
    {
        MediaDeciveType = ERtcMediaDeviceType::AudioUnknown;
    }
    ppfRtcMediaDeviceState RtcMediaDeviceState = ppf_RtcMediaDeviceChangeInfo_GetDeviceState(MediaDeviceChangeInfo);
    ERtcMediaDeviceState MediaDeviceState = ERtcMediaDeviceState::None;
    switch (RtcMediaDeviceState)
    {
    case ppfRtcMediaDeviceState_Added:
        MediaDeviceState = ERtcMediaDeviceState::Added;
        break;
    case ppfRtcMediaDeviceState_Removed:
        MediaDeviceState = ERtcMediaDeviceState::Removed;
        break;
    case ppfRtcMediaDeviceState_RuntimeError:
        MediaDeviceState = ERtcMediaDeviceState::RuntimeError;
        break;
    case ppfRtcMediaDeviceState_Started:
        MediaDeviceState = ERtcMediaDeviceState::Started;
        break;
    case ppfRtcMediaDeviceState_Stopped:
        MediaDeviceState = ERtcMediaDeviceState::Stopped;
        break;
    default:
        break;
    }
    ppfRtcMediaDeviceError RtcMediaDeviceError = ppf_RtcMediaDeviceChangeInfo_GetDeviceError(MediaDeviceChangeInfo);
    ERtcMediaDeviceError MediaDeviceError = ERtcMediaDeviceError::None;
    switch (RtcMediaDeviceError)
    {
    case ppfRtcMediaDeviceError_DeviceBusy:
        MediaDeviceError = ERtcMediaDeviceError::DeviceBusy;
        break;
    case  ppfRtcMediaDeviceError_DeviceDisconnected:
        MediaDeviceError = ERtcMediaDeviceError::DeviceDisconnected;
        break;
    case ppfRtcMediaDeviceError_DeviceFailure:
        MediaDeviceError = ERtcMediaDeviceError::DeviceFailure;
        break;
    case ppfRtcMediaDeviceError_DeviceNoCallback:
        MediaDeviceError = ERtcMediaDeviceError::DeviceNoCallback;
        break;
    case  ppfRtcMediaDeviceError_DeviceNotFound:
        MediaDeviceError = ERtcMediaDeviceError::DeviceNotFound;
        break;
    case ppfRtcMediaDeviceError_NoPermission:
        MediaDeviceError = ERtcMediaDeviceError::NoPermission;
        break;
    case ppfRtcMediaDeviceError_Ok:
        MediaDeviceError = ERtcMediaDeviceError::Ok;
        break;
    case ppfRtcMediaDeviceError_UnSupporttedFormat:
        MediaDeviceError = ERtcMediaDeviceError::UnSupporttedFormat;
        break;
    default:
        break;
    }
    RtcMediaDeviceChangeInfoCallback.Broadcast(DeviceId, MediaDeciveType, MediaDeviceState, MediaDeviceError);
}

void FRTCPicoUserInterface::OnRtcUserPublishInfoNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcUserPublishInfoNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcUserPublishInfoNotification error!"));
        return;
    }
    auto RtcUserPublishInfo = ppf_Message_GetRtcUserPublishInfo(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcUserPublishInfo_GetUserId(RtcUserPublishInfo));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcUserPublishInfo_GetRoomId(RtcUserPublishInfo));
    ppfRtcMediaStreamType pRtcMediaStreamType = ppf_RtcUserPublishInfo_GetMediaStreamType(RtcUserPublishInfo);
    ERtcMediaStreamType MediaStreamType = ERtcMediaStreamType::None;
    if (pRtcMediaStreamType == ppfRtcMediaStreamType_Audio)
    {
        MediaStreamType = ERtcMediaStreamType::Audio;
    }
    else if (pRtcMediaStreamType == ppfRtcMediaStreamType_Video)
    {
        MediaStreamType = ERtcMediaStreamType::Video;
    }
    else
    {
        MediaStreamType = ERtcMediaStreamType::Both;
    }
    RtcUserPublishInfoCallback.Broadcast(RoomId, UserId, MediaStreamType);
}

void FRTCPicoUserInterface::OnRtcUserUnPublishInfoNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcUserUnPublishInfoNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcUserUnPublishInfoNotification error!"));
        return;
    }
    auto RtcUserUnPublishInfo = ppf_Message_GetRtcUserUnPublishInfo(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcUserUnPublishInfo_GetUserId(RtcUserUnPublishInfo));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcUserUnPublishInfo_GetRoomId(RtcUserUnPublishInfo));
    ppfRtcMediaStreamType pRtcMediaStreamType = ppf_RtcUserUnPublishInfo_GetMediaStreamType(RtcUserUnPublishInfo);
    ERtcMediaStreamType MediaStreamType = ERtcMediaStreamType::None;
    if (pRtcMediaStreamType == ppfRtcMediaStreamType_Audio)
    {
        MediaStreamType = ERtcMediaStreamType::Audio;
    }
    else if (pRtcMediaStreamType == ppfRtcMediaStreamType_Video)
    {
        MediaStreamType = ERtcMediaStreamType::Video;
    }
    else
    {
        MediaStreamType = ERtcMediaStreamType::Both;
    }
    ppfRtcStreamRemoveReason pRtcStreamRemoveReason = ppf_RtcUserUnPublishInfo_GetReason(RtcUserUnPublishInfo);
    ERtcStreamRemoveReason RtcStreamRemoveReason = ERtcStreamRemoveReason::None;

    switch (pRtcStreamRemoveReason)
    {
    case ppfRtcStreamRemoveReason_Unpublish:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::Unpublish;
        break;
    case ppfRtcStreamRemoveReason_PublishFailed:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::PublishFailed;
        break;
    case ppfRtcStreamRemoveReason_KeepLiveFailed:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::KeepLiveFailed;
        break;
    case ppfRtcStreamRemoveReason_ClientDisconnected:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::ClientDisconnected;
        break;
    case ppfRtcStreamRemoveReason_Republish:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::Republish;
        break;
    case ppfRtcStreamRemoveReason_Other:
        RtcStreamRemoveReason = ERtcStreamRemoveReason::Other;
        break;
    default:
        break;
    }
    RtcUserUnPublishInfoCallback.Broadcast(RoomId, UserId, MediaStreamType, RtcStreamRemoveReason);
}

void FRTCPicoUserInterface::OnGetRtcStreamSyncInfoNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnGetRtcStreamSyncInfoNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnGetRtcStreamSyncInfoNotification error!"));
        return;
    }
    auto RtcStreamSyncInfo = ppf_Message_GetRtcStreamSyncInfo(Message);
    FString Info = BytesToString(ppf_RtcStreamSyncInfo_GetData(RtcStreamSyncInfo), ppf_RtcStreamSyncInfo_GetLength(RtcStreamSyncInfo));
    ppfRtcSyncInfoStreamType pRtcSyncInfoStreamType = ppf_RtcStreamSyncInfo_GetStreamType(RtcStreamSyncInfo);
    auto RtcRemoteStreamKey = ppf_RtcStreamSyncInfo_GetStreamKey(RtcStreamSyncInfo);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcRemoteStreamKey_GetUserId(RtcRemoteStreamKey));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcRemoteStreamKey_GetRoomId(RtcRemoteStreamKey));
    ppfRtcStreamIndex pRtcStreamIndex = ppf_RtcRemoteStreamKey_GetStreamIndex(RtcRemoteStreamKey);
    ERtcSyncInfoStreamType RtcSyncInfoStreamType = ERtcSyncInfoStreamType::None;
    if (pRtcSyncInfoStreamType == ppfRtcSyncInfoStreamType_Audio)
    {
        RtcSyncInfoStreamType = ERtcSyncInfoStreamType::Audio;
    }

    ERtcStreamIndex RtcStreamIndex = ERtcStreamIndex::None;
    if (pRtcStreamIndex == ppfRtcStreamIndex_Main)
    {
        RtcStreamIndex = ERtcStreamIndex::Main;
    }
    else if (pRtcStreamIndex == ppfRtcStreamIndex_Screen)
    {
        RtcStreamIndex = ERtcStreamIndex::Screen;
    }
    RtcStreamSyncInfoCallback.Broadcast(RoomId, UserId, RtcStreamIndex, RtcSyncInfoStreamType, Info);
}

void FRTCPicoUserInterface::OnRtcMessageSendResultNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcMessageSendResultNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcMessageSendResultNotification error!"));
        return;
    }
    auto RtcMessageSendResult = ppf_Message_GetRtcMessageSendResult(Message);
    int64 MessageId = ppf_RtcMessageSendResult_GetMessageId(RtcMessageSendResult);
    int32 Error = ppf_RtcMessageSendResult_GetError(RtcMessageSendResult);
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcMessageSendResult_GetRoomId(RtcMessageSendResult));
    RtcMessageSendResultCallback.Broadcast(MessageId, Error, RoomId);
}

void FRTCPicoUserInterface::OnRtcBinaryMessageReceivedNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcBinaryMessageReceivedNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcBinaryMessageReceivedNotification error!"));
        return;
    }
    auto RtcBinaryMessageReceived = ppf_Message_GetRtcBinaryMessageReceived(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcBinaryMessageReceived_GetUserId(RtcBinaryMessageReceived));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcBinaryMessageReceived_GetRoomId(RtcBinaryMessageReceived));

    FString Info = BytesToString(ppf_RtcBinaryMessageReceived_GetData(RtcBinaryMessageReceived), ppf_RtcBinaryMessageReceived_GetLength(RtcBinaryMessageReceived));
    TArray<uint8> BinaryArray;
    BinaryArray.Append(ppf_RtcBinaryMessageReceived_GetData(RtcBinaryMessageReceived), ppf_RtcBinaryMessageReceived_GetLength(RtcBinaryMessageReceived));
    RtcBinaryMessageReceivedCallback.Broadcast(RoomId, UserId, Info);
    RtcBinaryArrayMessageReceivedCallback.Broadcast(RoomId, UserId, BinaryArray);
}

void FRTCPicoUserInterface::OnRtcRoomMessageReceivedNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcRoomMessageReceivedNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcRoomMessageReceivedNotification error!"));
        return;
    }
    auto RtcRoomMessageReceived = ppf_Message_GetRtcRoomMessageReceived(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcRoomMessageReceived_GetUserId(RtcRoomMessageReceived));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcRoomMessageReceived_GetRoomId(RtcRoomMessageReceived));
    FString MessageInfo = UTF8_TO_TCHAR(ppf_RtcRoomMessageReceived_GetMessage(RtcRoomMessageReceived));
    RtcRoomMessageReceivedCallback.Broadcast(RoomId, UserId, MessageInfo);
}

void FRTCPicoUserInterface::OnRtcUserMessageReceivedNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcUserMessageReceivedNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcUserMessageReceivedNotification error!"));
        return;
    }
    auto RtcUserMessageReceived = ppf_Message_GetRtcUserMessageReceived(Message);
    FString UserId = UTF8_TO_TCHAR(ppf_RtcUserMessageReceived_GetUserId(RtcUserMessageReceived));
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcUserMessageReceived_GetRoomId(RtcUserMessageReceived));
    FString MessageInfo = UTF8_TO_TCHAR(ppf_RtcUserMessageReceived_GetMessage(RtcUserMessageReceived));
    RtcUserMessageReceivedCallback.Broadcast(RoomId, UserId, MessageInfo);
}

void FRTCPicoUserInterface::OnRtcTokenWilExpireNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcOnTokenWilExpireNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("OnRtcOnTokenWilExpireNotification notification error!"));
        return;
    }
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRtcOnTokenWilExpireNotification %s!"), *MessageString);
    RtcTokenWillExpireCallback.Broadcast(MessageString);
}

ERtcEngineInitResult FRTCPicoUserInterface::RtcEngineInit()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcEngineInit!"));
    ppfRtcEngineInitResult InitRes = ppf_Rtc_InitRtcEngine();
    ERtcEngineInitResult InitResult = ERtcEngineInitResult::None;
    if (InitRes == ppfRtcEngineInitResult_Success)
    {
        InitResult = ERtcEngineInitResult::Success;
    }
    else if (InitRes == ppfRtcEngineInitResult_Unknown)
    {
        InitResult = ERtcEngineInitResult::Unknow;
    }
    else if (InitRes == ppfRtcEngineInitResult_InvalidConfig)
    {
        InitResult = ERtcEngineInitResult::InvalidConfig;
    }
    else if (InitRes == ppfRtcEngineInitResult_AlreadyInitialized)
    {
        InitResult = ERtcEngineInitResult::AlreadyInitialized;
    }
    return InitResult;
}

int FRTCPicoUserInterface::RtcJoinRoom(const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcJoinRoom!"));
    auto RtcRoomOpiton = ppf_RtcRoomOptions_Create();
    if (InRoomProfileType == ERtcRoomProfileType::CloundGame)
    {
        ppf_RtcRoomOptions_SetRoomProfileType(RtcRoomOpiton, ppfRtcRoomProfileType_CloudGame);
    }
    else if (InRoomProfileType == ERtcRoomProfileType::Communication)
    {
        ppf_RtcRoomOptions_SetRoomProfileType(RtcRoomOpiton, ppfRtcRoomProfileType_Communication);
    }
    else if (InRoomProfileType == ERtcRoomProfileType::Game)
    {
        ppf_RtcRoomOptions_SetRoomProfileType(RtcRoomOpiton, ppfRtcRoomProfileType_Game);
    }
    else if (InRoomProfileType == ERtcRoomProfileType::LiveBroadcasting)
    {
        ppf_RtcRoomOptions_SetRoomProfileType(RtcRoomOpiton, ppfRtcRoomProfileType_LiveBroadcasting);
    }
    else if (InRoomProfileType == ERtcRoomProfileType::LowLatency)
    {
        ppf_RtcRoomOptions_SetRoomProfileType(RtcRoomOpiton, ppfRtcRoomProfileType_LowLatency);
    }
    else
    {
        return -1;
    }
    ppf_RtcRoomOptions_SetRoomId(RtcRoomOpiton, TCHAR_TO_UTF8(*RoomId));
    ppf_RtcRoomOptions_SetUserId(RtcRoomOpiton, TCHAR_TO_UTF8(*UserId));
    ppf_RtcRoomOptions_SetToken(RtcRoomOpiton, TCHAR_TO_UTF8(*Token));
    ppf_RtcRoomOptions_SetUserExtra(RtcRoomOpiton, TCHAR_TO_UTF8(*UserExtra));
    ppf_RtcRoomOptions_SetIsAutoSubscribeAudio(RtcRoomOpiton, bIsAutoSubscribeAudio);
    int Res = ppf_Rtc_JoinRoom(RtcRoomOpiton);
    ppf_RtcRoomOptions_Destroy(RtcRoomOpiton);
    return Res;
}

int FRTCPicoUserInterface::RtcDestroyRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcDestroyRoom!"));
    ppf_Rtc_DestroyRoom(TCHAR_TO_UTF8(*RoomId));
    return 1;
}

void FRTCPicoUserInterface::RtcEnableAudioPropertiesReport(int Interval)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcEnableAudioPropertiesReport!"));
    auto RtcAudioPropertyOptions = ppf_RtcAudioPropertyOptions_Create();
    ppf_RtcAudioPropertyOptions_SetInterval(RtcAudioPropertyOptions, Interval);
    ppf_Rtc_EnableAudioPropertiesReport(RtcAudioPropertyOptions);
    ppf_RtcAudioPropertyOptions_Destroy(RtcAudioPropertyOptions);
}

int FRTCPicoUserInterface::RtcLeaveRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcLeaveRoom!"));
    return ppf_Rtc_LeaveRoom(TCHAR_TO_UTF8(*RoomId));
}

void FRTCPicoUserInterface::RtcMuteLocalAudio(ERtcMuteState InRtcMuteState)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcMuteLocalAudio!"));
    if (InRtcMuteState == ERtcMuteState::On)
    {
        ppf_Rtc_MuteLocalAudio(ppfRtcMuteState_On);
    }
    else if (InRtcMuteState == ERtcMuteState::Off)
    {
        ppf_Rtc_MuteLocalAudio(ppfRtcMuteState_Off);
    }
}

void FRTCPicoUserInterface::RtcPublishRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcPublishRoom!"));
    return ppf_Rtc_PublishRoom(TCHAR_TO_UTF8(*RoomId));
}

void FRTCPicoUserInterface::RtcRoomPauseAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomPauseAllSubscribedStream!"));
    if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Audio)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_Audio);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Video)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_Video);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::AudioAndVideo)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_AudioAndVideo);
    }
}

void FRTCPicoUserInterface::RtcRoomResumeAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomResumeAllSubscribedStream!"));
    if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Audio)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_Audio);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Video)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_Video);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::AudioAndVideo)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_UTF8(*RoomId), ppfRtcPauseResumeMediaType_AudioAndVideo);
    }
}

void FRTCPicoUserInterface::RtcSetAudioPlaybackDevice(ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetAudioPlaybackDevice!"));
    if (InRtcAudioPlaybackDevice == ERtcAudioPlaybackDevice::Headset)
    {
        ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice_Headset);
    }
    else if (InRtcAudioPlaybackDevice == ERtcAudioPlaybackDevice::EarPiece)
    {
        ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice_EarPiece);
    }
    else if (InRtcAudioPlaybackDevice == ERtcAudioPlaybackDevice::SpeakerPhone)
    {
        ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice_SpeakerPhone);
    }
    else if (InRtcAudioPlaybackDevice == ERtcAudioPlaybackDevice::HeadsetBlueTooth)
    {
        ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice_HeadsetBlueTooth);
    }
    else if (InRtcAudioPlaybackDevice == ERtcAudioPlaybackDevice::HeadsetUsb)
    {
        ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice_HeadsetUsb);
    }
}

void FRTCPicoUserInterface::RtcSetAudioScenario(ERtcAudioScenarioType InRtcAudioScenarioType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetAudioScenario!"));
    if (InRtcAudioScenarioType == ERtcAudioScenarioType::Music)
    {
        ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType_Music);
    }
    else if (InRtcAudioScenarioType == ERtcAudioScenarioType::HighQualityCommunication)
    {
        ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType_HighQualityCommunication);
    }
    else if (InRtcAudioScenarioType == ERtcAudioScenarioType::Communication)
    {
        ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType_Communication);
    }
    else if (InRtcAudioScenarioType == ERtcAudioScenarioType::Media)
    {
        ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType_Media);
    }
    else if (InRtcAudioScenarioType == ERtcAudioScenarioType::GameStreaming)
    {
        ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType_GameStreaming);
    }
}

void FRTCPicoUserInterface::RtcSetCaptureVolume(ERtcStreamIndex InRtcStreamIndex, int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetCaptureVolume!"));
    if (InRtcStreamIndex == ERtcStreamIndex::Main)
    {
        ppf_Rtc_SetCaptureVolume(ppfRtcStreamIndex_Main, InVolume);
    }
    else if (InRtcStreamIndex == ERtcStreamIndex::Screen)
    {
        ppf_Rtc_SetCaptureVolume(ppfRtcStreamIndex_Screen, InVolume);
    }
}

void FRTCPicoUserInterface::RtcSetEarMonitorMode(ERtcEarMonitorMode InRtcEarMonitorMode)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetEarMonitorMode!"));
    if (InRtcEarMonitorMode == ERtcEarMonitorMode::Off)
    {
        ppf_Rtc_SetEarMonitorMode(ppfRtcEarMonitorMode_Off);
    }
    else if (InRtcEarMonitorMode == ERtcEarMonitorMode::On)
    {
        ppf_Rtc_SetEarMonitorMode(ppfRtcEarMonitorMode_On);
    }
}

void FRTCPicoUserInterface::RtcSetEarMonitorVolume(int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetEarMonitorVolume!"));
    ppf_Rtc_SetEarMonitorVolume(InVolume);
}

void FRTCPicoUserInterface::RtcSetPlaybackVolume(int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetPlaybackVolume!"));
    ppf_Rtc_SetPlaybackVolume(InVolume);
}

void FRTCPicoUserInterface::RtcStartAudioCapture()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcStartAudioCapture!"));
    ppf_Rtc_StartAudioCapture();
}

void FRTCPicoUserInterface::RtcStopAudioCatpure()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcStopAudioCatpure!"));
    ppf_Rtc_StopAudioCapture();
}

void FRTCPicoUserInterface::RtcUnPublishRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcUnPublishRoom!"));
    ppf_Rtc_UnPublishRoom(TCHAR_TO_UTF8(*RoomId));
}

void FRTCPicoUserInterface::RtcUpdateToken(const FString& RoomId, const FString& Token)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcUpdateToken!"));
    ppf_Rtc_UpdateToken(TCHAR_TO_UTF8(*RoomId), TCHAR_TO_UTF8(*Token));
}
