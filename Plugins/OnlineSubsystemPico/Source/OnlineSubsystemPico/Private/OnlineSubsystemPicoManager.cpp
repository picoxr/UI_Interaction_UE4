// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "OnlineSubsystemPicoManager.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemUtils.h"
#include "Engine/Engine.h"
#include "Online.h"
#include "OnlineSubsystemPicoNames.h"


FOnlineManagerReadFriendListDelegate UOnlineSubsystemPicoManager::ReadFrendListDelegate;
FOnlineManagerRtcGetTokenDelegate UOnlineSubsystemPicoManager::RtcGetTokenDelegate;
FOnlineManagerLoginCompleteDelegate UOnlineSubsystemPicoManager::LoginCompleteDelegate;

FPicoManagerOnCreateSessionCompleteDelegate UOnlineSubsystemPicoManager::OnCreateSessionCompleteDelegate;
FPicoManagerOnStartSessionCompleteDelegate UOnlineSubsystemPicoManager::OnStartSessionCompleteDelegate;
FPicoManagerOnUpdateSessionCompleteDelegate UOnlineSubsystemPicoManager::OnUpdateSessionCompleteDelegate;
FPicoManagerOnEndSessionCompleteDelegate UOnlineSubsystemPicoManager::OnEndSessionCompleteDelegate;
FPicoManagerOnDestroySessionCompleteDelegate UOnlineSubsystemPicoManager::OnDestroySessionCompleteDelegate;
FPicoManagerOnCancelMatchmakingCompleteDelegate UOnlineSubsystemPicoManager::OnCancelMatchmakingCompleteDelegate;
FPicoManagerOnMatchmakingCompleteDelegate UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate;
FPicoManagerOnFindSessionCompleteDelegate UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate;
FPicoManagerOnSingleSessionResultCompleteDelegate UOnlineSubsystemPicoManager::OnSingleSessionResultCompleteDelegate;
FPicoManagerOnJoinSessionCompleteDelegate UOnlineSubsystemPicoManager::OnJoinSessionCompleteDelegate;


UOnlineSubsystemPicoManager::UOnlineSubsystemPicoManager()
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
   
    if (Subsystem)
    {
        RtcInterface = Subsystem->GetRtcUserInterface();
        if (RtcInterface)
        {
            RtcInterface->RtcJoinRoomCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcJoinRoomResult);
            RtcInterface->RtcLeaveRoomCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcLeaveRoomResult);
            RtcInterface->RtcRoomStateCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcRoomState);
            RtcInterface->RtcUserJoinInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserJoinInfo);
            RtcInterface->RtcUserLeaveInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserLeaveInfo);
            RtcInterface->RtcRoomWarnCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcRoomWarn);
            RtcInterface->RtcRoomErrorCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcRoomError);
            RtcInterface->RtcUserMuteAudioInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcMuteState);
            RtcInterface->RtcAudioPlaybackDeviceChangeCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcAudioChangePlaybackDevice);
            RtcInterface->RtcMediaDeviceChangeInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcMediaDeviceChangeInfo);
            RtcInterface->RtcLocalAudioPropertiesReportCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcLocalAudioPropertiesReport);
            RtcInterface->RtcRemoteAudioPropertiesReportCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcRemoteAudioPropertiesReport);
            RtcInterface->RtcWarnCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcWarn);
            RtcInterface->RtcErrorCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcError);
            RtcInterface->RtcConnectStateChangedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcConnectStateChanged);
            RtcInterface->RtcUserStartAudioCaptureCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserStartAudioCapture);
            RtcInterface->RtcUserStopAudioCaptureCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserStopAudioCapture);
        }
        GameInterface = Subsystem->GetGameSessionInterface();
        if (GameInterface)
        {
            GameInterface->GameConnectionCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameConnectionNotification);
            GameInterface->GameRequestFailedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameRequestFailedNotification);
            GameInterface->GameStateResetCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameStateResetNotification);
            GameInterface->MatchmakingCancel2Callback.AddUObject(this, &UOnlineSubsystemPicoManager::OnMatchmakingCancel2Notification);
            GameInterface->RoomLeaveCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomLeaveNotification);
            GameInterface->RoomJoin2Callback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomJoin2Notification);
            GameInterface->RoomSetDescriptionCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomSetDescriptionNotification);
            GameInterface->RoomKickUserCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomKickUserNotification);
            GameInterface->RoomUpdateOwnerCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateOwnerNotification);
            GameInterface->RoomUpdateDataStoreCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateDataStoreNotification);
            GameInterface->RoomUpdateMembershipLockStatusCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateMembershipLockStatusNotification);
        }
    }

}

UOnlineSubsystemPicoManager::~UOnlineSubsystemPicoManager()
{
}

void UOnlineSubsystemPicoManager::PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& InUserId, const FString& InType, const FString& InToken, FOnlineManagerLoginCompleteDelegate InLoginCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetIdentityInterface())
    {
        UOnlineSubsystemPicoManager::LoginCompleteDelegate = InLoginCompleteDelegate;
        FOnlineAccountCredentials Credentials;
        Credentials.Id = InUserId;
        Credentials.Type = InType;
        Credentials.Token = InToken;
        Subsystem->GetIdentityInterface()->OnLoginCompleteDelegates->AddUObject(this, &UOnlineSubsystemPicoManager::OnLoginComplete);
        Subsystem->GetIdentityInterface()->Login(LocalUserNum, Credentials);
    }
}


FString UOnlineSubsystemPicoManager::PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum)
{
    FString NickName = FString();
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetIdentityInterface())
    {
        NickName = Subsystem->GetIdentityInterface()->GetPlayerNickname(LocalUserNum);
    }
    return NickName;
}

void UOnlineSubsystemPicoManager::OnLoginComplete(int LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& ErrorString)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetIdentityInterface()->ClearOnLoginCompleteDelegates(LocalUserNum, this);
    if (UOnlineSubsystemPicoManager::LoginCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LoginCompleteDelegate.Execute(LocalUserNum, UserId.ToString(), bWasSuccessful, ErrorString);
        UOnlineSubsystemPicoManager::LoginCompleteDelegate.Unbind();
    }
}

void UOnlineSubsystemPicoManager::PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetFriendsInterface())
    {
        UOnlineSubsystemPicoManager::ReadFrendListDelegate = InReadFriendListDelegate;
        ReadCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnReadListComplete);
        Subsystem->GetFriendsInterface()->ReadFriendsList(LocalUserNum, ListName, ReadCompleteDelegate);
    }
}

void UOnlineSubsystemPicoManager::OnReadListComplete(int32 InLocalUserNum/*LocalUserNum*/, bool bWasSuccessful/*bWasSuccessful*/, const FString& ListName/*ListName*/, const FString& ErrorStr/*ErrorStr*/)
{
    ReadCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::ReadFrendListDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::ReadFrendListDelegate.Execute(InLocalUserNum, bWasSuccessful, ListName, ErrorStr);
        UOnlineSubsystemPicoManager::ReadFrendListDelegate.Unbind();
    }
    
}

void UOnlineSubsystemPicoManager::PicoGetFriendList(UObject* WorldContextObject, int32 InLocalUserNum, const FString& ListName, TArray<FPicoFriend>& OutFriendList)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetFriendsInterface())
    {
        TArray< TSharedRef<FOnlineFriend> > OutFriends;
        Subsystem->GetFriendsInterface()->GetFriendsList(InLocalUserNum, ListName, OutFriends);
        OutFriendList.Empty();
        for (auto Friend : OutFriends)
        {
            FPicoFriend NewFriend;
            // StaticCastSharedPtr
            TSharedRef<FOnlinePicoFriend> OnlineFriend = StaticCastSharedRef<FOnlinePicoFriend>(Friend);
            NewFriend.DisPlayName = OnlineFriend->GetDisplayName();
            NewFriend.UserId = OnlineFriend->GetUserStrId();
            const FOnlineUserPresence& Presence = OnlineFriend->GetPresence();
            NewFriend.FriendPresenceStatus = EPresenceStatus::Unknow;
            if (Presence.bIsOnline)
            {
                NewFriend.FriendPresenceStatus = EPresenceStatus::OnLine;
            }
            else
            {
                NewFriend.FriendPresenceStatus = EPresenceStatus::OffLine;
            }
            OutFriendList.Add(NewFriend);
        }
    }
}

FPicoFriend UOnlineSubsystemPicoManager::PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName)
{
    FPicoFriend NewFriend;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetFriendsInterface())
    {
        FUniqueNetIdPico PicoFriend(FriendId);
        TSharedPtr<FOnlineFriend> OlFriend = Subsystem->GetFriendsInterface()->GetFriend(LocalUserNum, PicoFriend, ListName);
        TSharedPtr<FOnlinePicoFriend> OnlineFriend = StaticCastSharedPtr<FOnlinePicoFriend>(OlFriend);
        if (OnlineFriend.IsValid())
        {
            NewFriend.DisPlayName = OnlineFriend->GetDisplayName();
            NewFriend.UserId = OnlineFriend->GetUserStrId();
        }
    }
    return NewFriend;
}


void UOnlineSubsystemPicoManager::PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        UOnlineSubsystemPicoManager::RtcGetTokenDelegate = InRtcGetTokenDelegate;
        RtcGetTokenCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnGetTokenComplete);
        Subsystem->GetRtcUserInterface()->GetToken(UserId, RoomId, Ttl, InValue, RtcGetTokenCompleteDelegate);
    }
}

void UOnlineSubsystemPicoManager::OnGetTokenComplete(const FString& Token, bool bIsSuccessed, const FString& ErrorMessage)
{
    RtcGetTokenCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::RtcGetTokenDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::RtcGetTokenDelegate.Execute(Token, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::RtcGetTokenDelegate.Unbind();
    }
}

ERtcEngineInitResult UOnlineSubsystemPicoManager::PicoRtcEngineInit(UObject* WorldContextObject)
{
    ERtcEngineInitResult Result = ERtcEngineInitResult::None;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Result = Subsystem->GetRtcUserInterface()->RtcEngineInit();
    }
    return Result;
}

int UOnlineSubsystemPicoManager::RtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio)
{
    int ReturenCode = 999;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        ReturenCode = Subsystem->GetRtcUserInterface()->RtcJoinRoom(RoomId, UserId, Token, UserExtra, InRoomProfileType, bIsAutoSubscribeAudio);
    }
    return ReturenCode;
}

int UOnlineSubsystemPicoManager::RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId)
{
    int ReturenCode = 999;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        ReturenCode = Subsystem->GetRtcUserInterface()->RtcDestroyRoom(RoomId);
    }
    return ReturenCode;
}

void UOnlineSubsystemPicoManager::RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcEnableAudioPropertiesReport(Interval);
    }
}

int UOnlineSubsystemPicoManager::RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId)
{
    int ReturenCode = 999;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        ReturenCode = Subsystem->GetRtcUserInterface()->RtcLeaveRoom(RoomId);
    }
    return ReturenCode;
}

void UOnlineSubsystemPicoManager::RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcMuteLocalAudio(InRtcMuteState);
    }
}

void UOnlineSubsystemPicoManager::RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcPublishRoom(RoomId);
    }
}

void UOnlineSubsystemPicoManager::RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomPauseAllSubscribedStream(RoomId, InPauseResumeMediaType);
    }
}

void UOnlineSubsystemPicoManager::RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomResumeAllSubscribedStream(RoomId, InPauseResumeMediaType);
    }
}

void UOnlineSubsystemPicoManager::RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetAudioPlaybackDevice(InRtcAudioPlaybackDevice);
    }
}

void UOnlineSubsystemPicoManager::RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetAudioScenario(InRtcAudioScenarioType);
    }
}

void UOnlineSubsystemPicoManager::RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetCaptureVolume(InRtcStreamIndex, InVolume);
    }
}

void UOnlineSubsystemPicoManager::RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetEarMonitorMode(InRtcEarMonitorMode);
    }
}

void UOnlineSubsystemPicoManager::RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetEarMonitorVolume(InVolume);
    }
}

void UOnlineSubsystemPicoManager::RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcSetPlaybackVolume(InVolume);
    }
}

void UOnlineSubsystemPicoManager::RtcStartAudioCapture(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcStartAudioCapture();
    }
}

void UOnlineSubsystemPicoManager::RtcStopAudioCapture(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcStopAudioCatpure();
    }
}

void UOnlineSubsystemPicoManager::RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcUnPublishRoom(RoomId);
    }
}

void UOnlineSubsystemPicoManager::RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcUpdateToken(RoomId, Token);
    }
}

void UOnlineSubsystemPicoManager::OnRtcJoinRoomResult(const FString& RoomId, const FString& UserId, int ErrorCode, int Elapsed, ERtcJoinRoomType InJoinRoomType)
{
    OnRtcJoinRoomResultDelegate.Broadcast(RoomId, UserId, ErrorCode, Elapsed, InJoinRoomType);
}

void UOnlineSubsystemPicoManager::OnRtcLeaveRoomResult(const FString& RoomId)
{
    OnRtcLeaveRoomResultDelegate.Broadcast(RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcRoomState(int TotalDuration, int UserCount, const FString& RoomId)
{
    OnRtcRoomStateDelegate.Broadcast(TotalDuration, UserCount, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcUserJoinInfo(const FString& UserId, const FString& UserExtra, int Elapsed, const FString& RoomId)
{
    OnRtcUserJoinInfoDelegate.Broadcast(UserId, UserExtra, Elapsed, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcUserLeaveInfo(const FString& UserId, ERtcUserLeaveReasonType RtcUserLeaveReasonType, const FString& RoomId)
{
    OnRtcUserLeaveInfoDelegate.Broadcast(UserId, RtcUserLeaveReasonType, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcRoomWarn(int Code, const FString& RoomId)
{
    OnRtcRoomWarnDelegate.Broadcast(Code, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcRoomError(int Code, const FString& RoomId)
{
    OnRtcRoomErrorDelegate.Broadcast(Code, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcMuteState(const FString& UserId, ERtcMuteState RtcMuteState)
{
    OnRtcRoomMuteStateDelegate.Broadcast(UserId, RtcMuteState);
}

void UOnlineSubsystemPicoManager::OnRtcAudioChangePlaybackDevice(ERtcAudioPlaybackDevice RtcAudioPlaybackDevice)
{
    OnRtcAudioChangePlaybackDelegate.Broadcast(RtcAudioPlaybackDevice);
}

void UOnlineSubsystemPicoManager::OnRtcMediaDeviceChangeInfo(const FString& DeviceId, ERtcMediaDeviceType MediaDeciveType, ERtcMediaDeviceState MediaDeviceState, ERtcMediaDeviceError MediaDeviceError)
{
    OnRtcMediaDeviceChangeInfoDelegate.Broadcast(DeviceId, MediaDeciveType, MediaDeviceState, MediaDeviceError);
}

void UOnlineSubsystemPicoManager::OnRtcLocalAudioPropertiesReport(TArray<ERtcStreamIndex> StreamIndexs, TArray<int> Volumes)
{
    OnRtcLocalAudioPropertiesReportDelegate.Broadcast(StreamIndexs, Volumes);
}

void UOnlineSubsystemPicoManager::OnRtcRemoteAudioPropertiesReport(int TotalRemoteVolume, TArray<int> Volumes, const TArray<FString>& RoomIds, const TArray<FString>& UserIds, TArray<ERtcStreamIndex> StreamIndexs)
{
    OnRtcRemoteAudioPropertiesReportDelegate.Broadcast(TotalRemoteVolume, Volumes, RoomIds, UserIds, StreamIndexs);
}

void UOnlineSubsystemPicoManager::OnRtcWarn(int MessageCode)
{
    OnRtcWarnDelegate.Broadcast(MessageCode);
}

void UOnlineSubsystemPicoManager::OnRtcError(int MessageCode)
{
    OnRtcErrorDelegate.Broadcast(MessageCode);
}

void UOnlineSubsystemPicoManager::OnRtcConnectStateChanged(const FString& StringMessage)
{
    OnRtcConnectStateChangedDelegate.Broadcast(StringMessage);
}

void UOnlineSubsystemPicoManager::OnRtcUserStartAudioCapture(const FString& StringMessage)
{
    OnRtcUserStartAudioCaptureDelegate.Broadcast(StringMessage);
}

void UOnlineSubsystemPicoManager::OnRtcUserStopAudioCapture(const FString& StringMessage)
{
    OnRtcUserStopAudioCaptureDelegate.Broadcast(StringMessage);
}

// Game IOnlineSession
bool UOnlineSubsystemPicoManager::CreateSession(UObject* WorldContextObject, int32 HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnCreateSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnCreateSessionCompleteDelegate_Handle(
            FOnCreateSessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnCreateSessionComplete));
        return (Subsystem->GetGameSessionInterface())->CreateSession(HostingPlayerNum, SessionName, NewSessionSettings);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnStartSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnStartSessionCompleteDelegate_Handle(
            FOnStartSessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnStartSessionComplete));
        return Subsystem->GetGameSessionInterface()->StartSession(SessionName);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::UpdateSession(UObject* WorldContextObject, FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnCompleteDelegate, bool bShouldRefreshOnlineData)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnUpdateSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnUpdateSessionCompleteDelegate_Handle(
            FOnUpdateSessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnUpdateSessionComplete));
        return Subsystem->GetGameSessionInterface()->UpdateSession(SessionName, UpdatedSessionSettings, bShouldRefreshOnlineData);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnEndSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnEndSessionCompleteDelegate_Handle(
            FOnEndSessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnEndSessionComplete));
        return Subsystem->GetGameSessionInterface()->EndSession(SessionName);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnDestroySessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnDestroySessionCompleteDelegate_Handle(
            FOnDestroySessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnDestroySessionComplete));
        return (Subsystem->GetGameSessionInterface())->DestroySession(SessionName); // todo
    }
    return false;
}
bool UOnlineSubsystemPicoManager::IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FUniqueNetId& UniqueId)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->IsPlayerInSession(SessionName, UniqueId);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings, FPicoManagerOnMatchmakingCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnMatchmakingCompleteDelegate_Handle(
            FOnMatchmakingCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnMatchmakingComplete));
        return Subsystem->GetGameSessionInterface()->StartMatchmaking(LocalPlayers, SessionName, NewSessionSettings, SearchSettings);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::CancelMatchmaking(UObject* WorldContextObject, int32 SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnCancelMatchmakingCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnCancelMatchmakingCompleteDelegate_Handle(
            FOnCancelMatchmakingCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnCancelMatchmakingComplete));
        return (Subsystem->GetGameSessionInterface())->CancelMatchmaking(SearchingPlayerNum, SessionName);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings, FPicoManagerOnFindSessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnFindSessionsCompleteDelegate_Handle(
            FOnFindSessionsCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnFindSessionComplete));
        return (Subsystem->GetGameSessionInterface())->FindSessions(SearchingPlayerNum, SearchSettings);
    }
    return false;
}
bool UOnlineSubsystemPicoManager::FindSessionById(UObject* WorldContextObject, const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FPicoManagerOnSingleSessionResultCompleteDelegate& CompletionDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        // todo 这里直接传了delegate进去，而不是用trigger的形式
        UOnlineSubsystemPicoManager::OnSingleSessionResultCompleteDelegate = CompletionDelegate;
        return Subsystem->GetGameSessionInterface()->FindSessionById(SearchingUserId, SessionId, FriendId, FOnSingleSessionResultCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnFindSessionByIdComplete));
    }
    return false;
}
bool UOnlineSubsystemPicoManager::JoinSession(UObject* WorldContextObject, int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession, const FPicoManagerOnJoinSessionCompleteDelegate& OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        UOnlineSubsystemPicoManager::OnJoinSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnJoinSessionCompleteDelegate_Handle(
            FOnJoinSessionCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnJoinSessionComplete));
        return Subsystem->GetGameSessionInterface()->JoinSession(PlayerNum, SessionName, DesiredSession);
    }
    return false;
}

void UOnlineSubsystemPicoManager::DumpSessionState(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        Subsystem->GetGameSessionInterface()->DumpSessionState();
    }
}

EOnlineSessionState::Type UOnlineSubsystemPicoManager::GetSessionState(UObject* WorldContextObject, FName SessionName)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->GetSessionState(SessionName);
    }
    return EOnlineSessionState::NoSession;
}
	
FNamedOnlineSession* UOnlineSubsystemPicoManager::GetNamedSession(UObject* WorldContextObject, FName SessionName)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->GetNamedSession(SessionName);
    }
    return nullptr;
}
	
FNamedOnlineSession* UOnlineSubsystemPicoManager::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSessionSettings& SessionSettings)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->AddNamedSession(SessionName, SessionSettings);
    }
    return nullptr;
}
	
FNamedOnlineSession* UOnlineSubsystemPicoManager::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSession& Session)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->AddNamedSession(SessionName, Session);
    }
    return nullptr;
}
	
FOnlineSessionSettings* UOnlineSubsystemPicoManager::GetSessionSettings(UObject* WorldContextObject, FName SessionName)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->GetSessionSettings(SessionName);
    }
    return nullptr;
}

// Game OnComplete
void UOnlineSubsystemPicoManager::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful) {
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnCreateSessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnCreateSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnCreateSessionCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnCreateSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnStartSessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnStartSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnStartSessionCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnStartSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnUpdateSessionComplete(FName SessionName, bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnUpdateSessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnUpdateSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnUpdateSessionCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnUpdateSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnEndSessionComplete(FName SessionName, bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnEndSessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnEndSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnEndSessionCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnEndSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnDestroySessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnDestroySessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnDestroySessionCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnDestroySessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnCancelMatchmakingComplete(FName SessionName, bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnCancelMatchmakingCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnCancelMatchmakingCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnCancelMatchmakingCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnCancelMatchmakingCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnMatchmakingComplete(FName SessionName, bool bWasSuccessful) {
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnMatchmakingCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate.Execute(SessionName, bWasSuccessful);
        UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnFindSessionComplete(bool Result)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnFindSessionsCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate.Execute(Result);
        UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnFindSessionByIdComplete(int32 LocalUserNum, bool bWasSuccessful, const FOnlineSessionSearchResult& SearchResult)
{
    // FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    // Subsystem->GetGameSessionInterface()->(this);
    if (UOnlineSubsystemPicoManager::OnSingleSessionResultCompleteDelegate.IsBound())
    {
        FPicoOnlineSessionSearchResult newResult;
        if (SearchResult.IsValid())
        {
            auto newSession = SearchResult.Session;
            auto Settings = newSession.SessionSettings;
            newResult.Session.OwningUserId = newSession.OwningUserId->ToString();
            newResult.Session.OwningUserName = newSession.OwningUserName;
            newResult.Session.SessionInfoRoomID = newSession.SessionInfo->ToString();
            newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
            newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
            newResult.PingInMs = SearchResult.PingInMs;
            // SessionSettings
            FPicoOnlineSessionSettings SessionSettings;
            SessionSettings.NumPublicConnections = Settings.NumPublicConnections;
            SessionSettings.NumPrivateConnections = Settings.NumPrivateConnections;
            SessionSettings.bShouldAdvertise = Settings.bShouldAdvertise;
            SessionSettings.bAllowInvites = Settings.bAllowInvites;
            SessionSettings.bUsesPresence = Settings.bUsesPresence;
            SessionSettings.bAllowJoinViaPresence = Settings.bAllowJoinViaPresence;
            SessionSettings.bAllowJoinViaPresenceFriendsOnly = Settings.bAllowJoinViaPresenceFriendsOnly;
            SessionSettings.BuildUniqueId = Settings.BuildUniqueId;
            for (FSessionSettings::TConstIterator It(Settings.Settings); It; ++It)
            {
                FName Key = It.Key();
                const FOnlineSessionSetting& Setting = It.Value();
                SessionSettings.KeyArray.Add(Key.ToString());
                SessionSettings.ValueArray.Add(Setting.ToString());
            }
            newResult.Session.SessionSettings = SessionSettings;
        }
        UOnlineSubsystemPicoManager::OnSingleSessionResultCompleteDelegate.Execute(LocalUserNum, bWasSuccessful, newResult);
        UOnlineSubsystemPicoManager::OnSingleSessionResultCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Type)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetGameSessionInterface()->ClearOnJoinSessionCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnJoinSessionCompleteDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::OnJoinSessionCompleteDelegate.Execute(SessionName, (EOnJoinSessionCompleteResultPicoType)Type);
        UOnlineSubsystemPicoManager::OnJoinSessionCompleteDelegate.Unbind();
    }
}
void UOnlineSubsystemPicoManager::OnGameConnectionNotification(int Result, bool bWasSuccessful)
{
    OnGameConnectionNotifyDelegate.Broadcast(Result, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnGameRequestFailedNotification(int Result, bool bWasSuccessful)
{
    OnGameRequestFailedNotifyDelegate.Broadcast(Result, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnGameStateResetNotification(bool bWasSuccessful)
{
    OnGameStateResetNotifyDelegate.Broadcast(bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnMatchmakingCancel2Notification(bool bWasSuccessful)
{
    OnMatchmakingCancel2NotifyDelegate.Broadcast(bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomLeaveNotification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomLeaveNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomJoin2Notification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomJoin2NotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomSetDescriptionNotification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomSetDescriptionNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomKickUserNotification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomKickUserNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomUpdateOwnerNotification(bool bWasSuccessful)
{
    OnRoomUpdateOwnerNotifyDelegate.Broadcast(bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomUpdateDataStoreNotification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomUpdateDataStoreNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomUpdateMembershipLockStatusNotification(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomUpdateMembershipLockStatusNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomUpdateComplete(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomUpdateNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnRoomInviteAcceptedComplete(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomInviteAcceptedNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}

