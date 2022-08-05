// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "RTCPicoUserInterface.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "PPF_RtcEngineInitResult.h"

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
}

void FRTCPicoUserInterface::GetToken(const FString& UserId, const FString& RoomId, int Ttl, int InValue, const FOnGetTokenComplete& Delegate)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::GetToken!"));
#if PLATFORM_ANDROID
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

#endif
}

void FRTCPicoUserInterface::OnQueryGetTokenComplete(ppfMessageHandle Message, bool bIsError, const FOnGetTokenComplete& Delegate)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnQueryGetTokenComplete!"));
#if PLATFORM_ANDROID
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

#endif
}

void FRTCPicoUserInterface::OnJoinRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnJoinRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Join room result error!"));
        return;
    }
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::OnLeaveRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnLeaveRoomResult"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Leave room result error!"));
    }

#if PLATFORM_ANDROID
    auto LeaveRoomResult = ppf_Message_GetRtcLeaveRoomResult(Message);
    FString RoomId = UTF8_TO_TCHAR(ppf_RtcLeaveRoomResult_GetRoomId(LeaveRoomResult));
    RtcLeaveRoomCallback.Broadcast(RoomId);
#endif
}

void FRTCPicoUserInterface::OnUserJoinRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserJoinRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User join room result error!"));
        return;
    }
#if PLATFORM_ANDROID
    auto UserJoinInfo = ppf_Message_GetRtcUserJoinInfo(Message);
    FString UserId = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetUserId(UserJoinInfo)));
    FString UserExtra = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetUserExtra(UserJoinInfo)));
    int Elapsed = ppf_RtcUserJoinInfo_GetElapsed(UserJoinInfo);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcUserJoinInfo_GetRoomId(UserJoinInfo)));
    RtcUserJoinInfoCallback.Broadcast(UserId, UserExtra, Elapsed, RoomId);
#endif
}

void FRTCPicoUserInterface::OnUserLeaveRoomResult(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserLeaveRoomResult!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User leave room result error!"));
        return;
    }
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::OnRoomStatsNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomStatsNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room stats error!"));
        return;
    }
#if PLATFORM_ANDROID
    auto RoomStates = ppf_Message_GetRtcRoomStats(Message);
    int TotalDuration = ppf_RtcRoomStats_GetTotalDuration(RoomStates);
    int UserCount = ppf_RtcRoomStats_GetUserCount(RoomStates);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomStats_GetRoomId(RoomStates)));

    RtcRoomStateCallback.Broadcast(TotalDuration, UserCount, RoomId);
#endif
}

void FRTCPicoUserInterface::OnWarnNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnWarnNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Warn notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    int32 MessageCode = (ppf_Message_GetInt32(Message));
    RtcWarnCallback.Broadcast(MessageCode);
#endif
}

void FRTCPicoUserInterface::OnErrorNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnErrorNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Error notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    int32 MessageCode = (ppf_Message_GetInt32(Message));
    RtcErrorCallback.Broadcast(MessageCode);
#endif
}

void FRTCPicoUserInterface::OnRoomWarnNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomWarnNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room warn notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    auto RoomWarn = ppf_Message_GetRtcRoomWarn(Message);
    int Code = ppf_RtcRoomWarn_GetCode(RoomWarn);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomWarn_GetRoomId(RoomWarn)));
    RtcRoomWarnCallback.Broadcast(Code, RoomId);
#endif
}

void FRTCPicoUserInterface::OnRoomErrorNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRoomErrorNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Room error notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    auto RoomError = ppf_Message_GetRtcRoomError(Message);
    int Code = ppf_RtcRoomError_GetCode(RoomError);
    FString RoomId = UTF8_TO_TCHAR((ppf_RtcRoomError_GetRoomId(RoomError)));
    RtcRoomErrorCallback.Broadcast(Code, RoomId);
#endif
}

void FRTCPicoUserInterface::OnConnectionStateChangeNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnConnectionStateChangeNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("ConnectionStateChange notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcConnectStateChangedCallback.Broadcast(MessageString);
#endif
}

void FRTCPicoUserInterface::OnUserStartAudioCaptureNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserStartAudioCaptureNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("UserStartAudioCapture notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcUserStopAudioCaptureCallback.Broadcast(MessageString);
#endif
}

void FRTCPicoUserInterface::OnUserStopAudioCaptureNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserStopAudioCaptureNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("UserStopAudioCapture notification error!"));
        return;
    }
#if PLATFORM_ANDROID
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    RtcUserStopAudioCaptureCallback.Broadcast(MessageString);
#endif
}

void FRTCPicoUserInterface::OnAudioPlaybackDeviceChangeNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnAudioPlaybackDeviceChangeNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Audio playback device change notification error!"));
        return;
    }
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::OnRemoteAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnRemoteAudioPropertiesReportNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Remote audio properties report notification error!"));
        return;
    }
#if PLATFORM_ANDROID
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

#endif
}

void FRTCPicoUserInterface::OnLocalAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnLocalAudioPropertiesReportNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Local audio properties report notification error!"));
        return;
    }
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::OnUserMuteAudioNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnUserMuteAudioNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("User mute audio error!"));
        return;
    }
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::OnMediaDeviceStateChangedNotification(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::OnMediaDeviceStateChangedNotification!"));
    if (bIsError)
    {
        UE_LOG(RtcInterface, Error, TEXT("Media device state changed info error!"));
        return;
    }
#if PLATFORM_ANDROID
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
    case ppfRtcMediaDeviceState_Removed:
        MediaDeviceState = ERtcMediaDeviceState::Removed;
    case ppfRtcMediaDeviceState_RuntimeError:
        MediaDeviceState = ERtcMediaDeviceState::RuntimeError;
    case ppfRtcMediaDeviceState_Started:
        MediaDeviceState = ERtcMediaDeviceState::Started;
    case ppfRtcMediaDeviceState_Stopped:
        MediaDeviceState = ERtcMediaDeviceState::Stopped;
    default:
        break;
    }
    ppfRtcMediaDeviceError RtcMediaDeviceError = ppf_RtcMediaDeviceChangeInfo_GetDeviceError(MediaDeviceChangeInfo);
    ERtcMediaDeviceError MediaDeviceError = ERtcMediaDeviceError::None;
    switch (RtcMediaDeviceError)
    {
    case ppfRtcMediaDeviceError_DeviceBusy:
        MediaDeviceError = ERtcMediaDeviceError::DeviceBusy;
    case  ppfRtcMediaDeviceError_DeviceDisconnected:
        MediaDeviceError = ERtcMediaDeviceError::DeviceDisconnected;
    case ppfRtcMediaDeviceError_DeviceFailure:
        MediaDeviceError = ERtcMediaDeviceError::DeviceFailure;
    case ppfRtcMediaDeviceError_DeviceNoCallback:
        MediaDeviceError = ERtcMediaDeviceError::DeviceNoCallback;
    case  ppfRtcMediaDeviceError_DeviceNotFound:
        MediaDeviceError = ERtcMediaDeviceError::DeviceNotFound;
    case ppfRtcMediaDeviceError_NoPermission:
        MediaDeviceError = ERtcMediaDeviceError::NoPermission;
    case ppfRtcMediaDeviceError_Ok:
        MediaDeviceError = ERtcMediaDeviceError::Ok;
    case ppfRtcMediaDeviceError_UnSupporttedFormat:
        MediaDeviceError = ERtcMediaDeviceError::UnSupporttedFormat;
    default:
        break;
    }
    RtcMediaDeviceChangeInfoCallback.Broadcast(DeviceId, MediaDeciveType, MediaDeviceState, MediaDeviceError);

#endif


}

ERtcEngineInitResult FRTCPicoUserInterface::RtcEngineInit()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcEngineInit!"));
#if PLATFORM_ANDROID

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
#endif
    return ERtcEngineInitResult::Unknow;
}

int FRTCPicoUserInterface::RtcJoinRoom(const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcJoinRoom!"));
#if PLATFORM_ANDROID
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
    ppf_RtcRoomOptions_SetRoomId(RtcRoomOpiton, TCHAR_TO_ANSI(*RoomId));
    ppf_RtcRoomOptions_SetUserId(RtcRoomOpiton, TCHAR_TO_ANSI(*UserId));
    ppf_RtcRoomOptions_SetToken(RtcRoomOpiton, TCHAR_TO_ANSI(*Token));
    ppf_RtcRoomOptions_SetUserExtra(RtcRoomOpiton, TCHAR_TO_ANSI(*UserExtra));
    ppf_RtcRoomOptions_SetIsAutoSubscribeAudio(RtcRoomOpiton, bIsAutoSubscribeAudio);
    int Res = ppf_Rtc_JoinRoom(RtcRoomOpiton);
    ppf_RtcRoomOptions_Destroy(RtcRoomOpiton);
    return Res;
#endif
    return 0;
}

int FRTCPicoUserInterface::RtcDestroyRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcDestroyRoom!"));
#if PLATFORM_ANDROID
    ppf_Rtc_DestroyRoom(TCHAR_TO_ANSI(*RoomId));
    return 1;
#endif
    return 0;
}

void FRTCPicoUserInterface::RtcEnableAudioPropertiesReport(int Interval)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcEnableAudioPropertiesReport!"));
#if PLATFORM_ANDROID
    auto RtcAudioPropertyOptions = ppf_RtcAudioPropertyOptions_Create();
    ppf_RtcAudioPropertyOptions_SetInterval(RtcAudioPropertyOptions, Interval);
    ppf_Rtc_EnableAudioPropertiesReport(RtcAudioPropertyOptions);
    ppf_RtcAudioPropertyOptions_Destroy(RtcAudioPropertyOptions);
#endif
}

int FRTCPicoUserInterface::RtcLeaveRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcLeaveRoom!"));
#if PLATFORM_ANDROID
    return ppf_Rtc_LeaveRoom(TCHAR_TO_ANSI(*RoomId));
#endif
    return 0;
}

void FRTCPicoUserInterface::RtcMuteLocalAudio(ERtcMuteState InRtcMuteState)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcMuteLocalAudio!"));
#if PLATFORM_ANDROID
    if (InRtcMuteState == ERtcMuteState::On)
    {
        ppf_Rtc_MuteLocalAudio(ppfRtcMuteState_On);
    }
    else if (InRtcMuteState == ERtcMuteState::Off)
    {
        ppf_Rtc_MuteLocalAudio(ppfRtcMuteState_Off);
    }
#endif
}

void FRTCPicoUserInterface::RtcPublishRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcPublishRoom!"));
#if PLATFORM_ANDROID
    return ppf_Rtc_PublishRoom(TCHAR_TO_ANSI(*RoomId));
#endif
}

void FRTCPicoUserInterface::RtcRoomPauseAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomPauseAllSubscribedStream!"));
#if PLATFORM_ANDROID
    if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Audio)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_Audio);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Video)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_Video);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::AudioAndVideo)
    {
        ppf_Rtc_RoomPauseAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_AudioAndVideo);
    }
#endif
}

void FRTCPicoUserInterface::RtcRoomResumeAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcRoomResumeAllSubscribedStream!"));
#if PLATFORM_ANDROID
    if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Audio)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_Audio);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::Video)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_Video);
    }
    else if (InPauseResumeMediaType == ERtcPauseResumeMediaType::AudioAndVideo)
    {
        ppf_Rtc_RoomResumeAllSubscribedStream(TCHAR_TO_ANSI(*RoomId), ppfRtcPauseResumeMediaType_AudioAndVideo);
    }
#endif
}

void FRTCPicoUserInterface::RtcSetAudioPlaybackDevice(ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetAudioPlaybackDevice!"));
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::RtcSetAudioScenario(ERtcAudioScenarioType InRtcAudioScenarioType)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetAudioScenario!"));
#if PLATFORM_ANDROID
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
#endif
}

void FRTCPicoUserInterface::RtcSetCaptureVolume(ERtcStreamIndex InRtcStreamIndex, int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetCaptureVolume!"));
#if PLATFORM_ANDROID
    if (InRtcStreamIndex == ERtcStreamIndex::Main)
    {
        ppf_Rtc_SetCaptureVolume(ppfRtcStreamIndex_Main, InVolume);
    }
    else if (InRtcStreamIndex == ERtcStreamIndex::Screen)
    {
        ppf_Rtc_SetCaptureVolume(ppfRtcStreamIndex_Screen, InVolume);
    }
#endif
}

void FRTCPicoUserInterface::RtcSetEarMonitorMode(ERtcEarMonitorMode InRtcEarMonitorMode)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetEarMonitorMode!"));
#if PLATFORM_ANDROID
    if (InRtcEarMonitorMode == ERtcEarMonitorMode::Off)
    {
        ppf_Rtc_SetEarMonitorMode(ppfRtcEarMonitorMode_Off);
    }
    else if (InRtcEarMonitorMode == ERtcEarMonitorMode::On)
    {
        ppf_Rtc_SetEarMonitorMode(ppfRtcEarMonitorMode_On);
    }
#endif
}

void FRTCPicoUserInterface::RtcSetEarMonitorVolume(int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetEarMonitorVolume!"));
#if PLATFORM_ANDROID
    ppf_Rtc_SetEarMonitorVolume(InVolume);
#endif
}

void FRTCPicoUserInterface::RtcSetPlaybackVolume(int InVolume)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcSetPlaybackVolume!"));
#if PLATFORM_ANDROID
    ppf_Rtc_SetPlaybackVolume(InVolume);
#endif
}

void FRTCPicoUserInterface::RtcStartAudioCapture()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcStartAudioCapture!"));
#if PLATFORM_ANDROID
    ppf_Rtc_StartAudioCapture();
#endif
}

void FRTCPicoUserInterface::RtcStopAudioCatpure()
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcStopAudioCatpure!"));
#if PLATFORM_ANDROID
    ppf_Rtc_StopAudioCapture();
#endif
}

void FRTCPicoUserInterface::RtcUnPublishRoom(const FString& RoomId)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcUnPublishRoom!"));
#if PLATFORM_ANDROID
    ppf_Rtc_UnPublishRoom(TCHAR_TO_ANSI(*RoomId));
#endif
}

void FRTCPicoUserInterface::RtcUpdateToken(const FString& RoomId, const FString& Token)
{
    UE_LOG(RtcInterface, Log, TEXT("FRTCPicoUserInterface::RtcUpdateToken!"));
#if PLATFORM_ANDROID
    ppf_Rtc_UpdateToken(TCHAR_TO_ANSI(*RoomId), TCHAR_TO_ANSI(*Token));
#endif
}
