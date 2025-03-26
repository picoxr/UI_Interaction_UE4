// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "OnlineSubsystemPicoManager.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemUtils.h"
#include "Engine/Engine.h"
#include "Online.h"
#include "OnlineSubsystemPicoNames.h"
#include "Interfaces/OnlineLeaderboardInterface.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineIdentityPico.h"
#include "OnlineSessionInterfacePico.h"
#include "OnlineLeaderboardInterfacePico.h"
#include "Pico_Challenges.h"
#include "Pico_Matchmaking.h"


// Friends
FOnlineManagerReadFriendListDelegate UOnlineSubsystemPicoManager::ReadFrendListDelegate;

// Rtc
FOnlineManagerRtcGetTokenDelegate UOnlineSubsystemPicoManager::RtcGetTokenDelegate;

//Identity
FOnlineManagerLoginCompleteDelegate UOnlineSubsystemPicoManager::LoginCompleteDelegate;

// Game 
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

// Leaderboard
FPicoManagerOnReadLeaderboardsCompleteDelegate UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate;

// Presence
FOnlineManagerPresenceClearDelegate UOnlineSubsystemPicoManager::PresenceClearDelegate;
FOnlineManagerPresenceReadInvitableUserDelegate UOnlineSubsystemPicoManager::PresenceReadInvitableUserDelegate;
FOnlineManagerPresenceSetDelegate UOnlineSubsystemPicoManager::PresenceSetDelegate;
FOnlineManagerPresenceSetDestinationDelegate UOnlineSubsystemPicoManager::PresenceSetDestinationDelegate;
FOnlineManagerPresenceSetIsJoinableDelegate UOnlineSubsystemPicoManager::PresenceSetIsJoinableDelegate;
FOnlineManagerPresenceSetLobbySessionDelegate UOnlineSubsystemPicoManager::PresenceSetLobbySessionDelegate;
FOnlineManagerPresenceSetMatchSessionDelegate UOnlineSubsystemPicoManager::PresenceSetMatchSessionDelegate;
FOnlineManagerPresenceSetExtraDelegate UOnlineSubsystemPicoManager::PresenceSetExtraDelegate;
FOnlineManagerPresenceReadSentInvitesDelegate UOnlineSubsystemPicoManager::PresenceReadSentInvitesDelegate;
FOnlineManagerPresenceSentInvitesDelegate UOnlineSubsystemPicoManager::PresenceSentInvitesDelegate;
FOnlineManagerPresenceGetDestinationsDelegate UOnlineSubsystemPicoManager::PresenceGetDestinationsDelegate;
FOnlineManagerLaunchInvitePanelDelegate UOnlineSubsystemPicoManager::LaunchInvitePanelDelegate;
FOnlineManagerShareMediaDelegate UOnlineSubsystemPicoManager::ShareMediaDelegate;

// Application
FOnlineManagerLaunchOtherAppDelegate UOnlineSubsystemPicoManager::LaunchOtherAppDelegate;
FOnlineManagerLaunchOtherAppByAppIdDelegate UOnlineSubsystemPicoManager::LaunchOtherAppByAppIdDelegate;
FOnlineManagerLaunchOtherAppByPresenceDelegate UOnlineSubsystemPicoManager::LaunchOtherAppByPresenceDelegate;
FOnlineManagerGetVersionDelegate UOnlineSubsystemPicoManager::GetVersionDelegate;
FOnlineManagerLaunchStoreDelegate UOnlineSubsystemPicoManager::LaunchStoreDelegate;

// ApplicationLifecycle
FOnlineManagerApplicationLifecycleReadDetailsDelegate UOnlineSubsystemPicoManager::ApplicationLifecycleReadDetailsDelegate;

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

            // V2
            RtcInterface->RtcUserPublishInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserPublishInfo);
            RtcInterface->RtcUserUnPublishInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserUnPublishInfo);
            RtcInterface->RtcStreamSyncInfoCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGetRtcStreamSyncInfo);
            RtcInterface->RtcMessageSendResultCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcMessageSendResult);
            RtcInterface->RtcBinaryMessageReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcBinaryMessageReceived);
            RtcInterface->RtcBinaryArrayMessageReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcBinaryArrayMessageReceived);
            RtcInterface->RtcRoomMessageReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcRoomMessageReceived);
            RtcInterface->RtcUserMessageReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcUserMessageReceived);
            RtcInterface->RtcTokenWillExpireCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRtcTokenWilExpire);
        }
        GameInterface = Subsystem->GetGameSessionInterface();
        if (GameInterface)
        {
            GameInterface->GameInitializeCompleteCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameInitializeCallback);
            GameInterface->GameConnectionCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameConnectionNotification);
            GameInterface->GameRequestFailedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameRequestFailedNotification);
            GameInterface->GameStateResetCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnGameStateResetNotification);
            GameInterface->MatchmakingCancel2Callback.AddUObject(this, &UOnlineSubsystemPicoManager::OnMatchmakingCancel2Notification);
            GameInterface->RoomLeaveCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnSessionLeaveNotification);
            GameInterface->RoomJoin2Callback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomJoin2Notification);
            GameInterface->RoomSetDescriptionCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomSetDescriptionNotification);
            GameInterface->RoomKickUserCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomKickUserNotification);
            GameInterface->RoomUpdateOwnerCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateOwnerNotification);
            GameInterface->RoomUpdateDataStoreCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateDataStoreNotification);
            GameInterface->RoomUpdateMembershipLockStatusCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateMembershipLockStatusNotification);
            GameInterface->RoomInviteAcceptedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomInviteAcceptedComplete);
            GameInterface->PicoSessionUserInviteAcceptedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnSessionUserInviteAccepted);
            GameInterface->RoomUpdateCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnRoomUpdateComplete);
            GameInterface->MatchmakingFoundCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnMatchmakingFoundComplete);
        }
        PresenceInterface = Subsystem->GetPicoPresenceInterface();
        if (PresenceInterface)
        {
            PresenceInterface->JoinIntentReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnPresenceJoinIntentReceivedResult);
            PresenceInterface->LeaveIntentReceivedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnPresenceLeavententReceivedResult);
        }
        if (Subsystem->GetApplicationLifecycleInterface())
        {
            Subsystem->GetApplicationLifecycleInterface()->LaunchIntentChangedCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnLaunchIntentChangedResult);
        }
        PicoAssetFileInterface = Subsystem->GetPicoAssetFileInterface();
        if (PicoAssetFileInterface)
        {
            PicoAssetFileInterface->AssetFileDownloadUpdateCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnAssetFileDownloadUpdate);
            PicoAssetFileInterface->AssetFileDeleteForSafetyCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnAssetFileDeleteForSafety);
        }
        PicoHighlightInterface = Subsystem->GetPicoHighlightInterface();
        if (PicoHighlightInterface)
        {
            PicoHighlightInterface->HighlightRecordStopCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnHighlightRecordStop);
        }

        // Pico_Room Notification
        PicoRoomInterface = Subsystem->GetPicoRoomInterface();
        if (PicoRoomInterface)
        {
            PicoRoomInterface->RoomUpdateNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoRoomUpdateNotification);
            PicoRoomInterface->RoomUpdateOwnerNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoRoomUpdateOwnerNotification);
            PicoRoomInterface->RoomJoinNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoRoomJoinNotification);
            PicoRoomInterface->RoomLeaveNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoRoomLeaveNotification);
            PicoRoomInterface->RoomInviteAcceptedNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoRoomInviteAcceptedNotification);
        }
        // Pico_Matchmaking Notification
        PicoMatchmakingInterface = Subsystem->GetPicoMatchmakingInterface();
        if (PicoMatchmakingInterface)
        {
            PicoMatchmakingInterface->MatchmakingCancelNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoMatchmakingCancelNotification);
            PicoMatchmakingInterface->MatchmakingMatchFoundNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoMatchmakingMatchFoundNotification);
        }
        // Pico_Challenges Notification
        PicoChallengesInterface = Subsystem->GetPicoChallengesInterface();
        if (PicoChallengesInterface)
        {
            PicoChallengesInterface->ChallengeInviteAcceptedOrLaunchAppNotify.AddUObject(this, &UOnlineSubsystemPicoManager::OnPicoChallengeInviteAcceptedOrLaunchAppNotification);
        }
        PicoSpeechInterface = Subsystem->GetPicoSpeechInterface();
        if (PicoSpeechInterface)
        {
            PicoSpeechInterface->SpeechAsrResultCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnSpeechAsrResult);
            PicoSpeechInterface->SpeechErrorCallback.AddUObject(this, &UOnlineSubsystemPicoManager::OnSpeechError);
        }
    }
}
/*
 * Pico_Room Notification begin
 */
void UOnlineSubsystemPicoManager::OnPicoRoomUpdateNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room)
{
    OnPicoRoomUpdateNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, Room);
}
void UOnlineSubsystemPicoManager::OnPicoRoomUpdateOwnerNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage)
{
    OnPicoRoomUpdateOwnerNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage);
}
void UOnlineSubsystemPicoManager::OnPicoRoomJoinNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room)
{
    OnPicoRoomLeaveNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, Room);
}
void UOnlineSubsystemPicoManager::OnPicoRoomLeaveNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room)
{
    OnPicoRoomJoinNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, Room);
}
void UOnlineSubsystemPicoManager::OnPicoRoomInviteAcceptedNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, const FString& RoomID)
{
    OnPicoRoomInviteAcceptedNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, RoomID);
}
/*
 * Pico_Room Notification end
 */

/*
 * Pico_Matchmaking Notification begin
 */
void UOnlineSubsystemPicoManager::OnPicoMatchmakingCancelNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage)
{
    OnPicoMatchmakingCancelNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage);
}
void UOnlineSubsystemPicoManager::OnPicoMatchmakingMatchFoundNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room)
{
    OnPicoMatchmakingMatchFoundNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, Room);
}
/*
 * Pico_Matchmaking Notification end
 */
/*
 * Pico_Challenges Notification begin
 */
void UOnlineSubsystemPicoManager::OnPicoChallengeInviteAcceptedOrLaunchAppNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, const FString& ChallengeID)
{
    OnPicoChallengeInviteAcceptedOrLaunchAppNotifyDelegate.Broadcast(bIsError, ErrorCode, ErrorMessage, ChallengeID);
}
/*
 * Pico_Challenges Notification end
 */

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

UPico_User* UOnlineSubsystemPicoManager::GetLoginPicoUser(UObject* WorldContextObject, int32 LocalUserNum)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetIdentityInterface())
    {
        TSharedPtr<FOnlineIdentityPico, ESPMode::ThreadSafe> IdentityInterfacePicoPtr = StaticCastSharedPtr<FOnlineIdentityPico>(Subsystem->GetIdentityInterface());
        if (IdentityInterfacePicoPtr.IsValid())
        {
            return IdentityInterfacePicoPtr->GetLoginPicoUser(LocalUserNum);
        }
    }
    return nullptr;
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
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(WorldContextObject->GetWorld(), PICO_SUBSYSTEM));
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

void UOnlineSubsystemPicoManager::PicoGetFriendList(UObject* WorldContextObject, int32 InLocalUserNum, const FString& ListName, TArray<FPicoUserInfo>& OutFriendList)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetFriendsInterface())
    {
        TArray< TSharedRef<FOnlineFriend> > OutFriends;
        Subsystem->GetFriendsInterface()->GetFriendsList(InLocalUserNum, ListName, OutFriends);
        OutFriendList.Empty();
        for (auto Friend : OutFriends)
        {
            // StaticCastSharedPtr
            TSharedRef<FOnlinePicoFriend> OnlineFriend = StaticCastSharedRef<FOnlinePicoFriend>(Friend);
            FPicoUserInfo NewFriend = GetBPPicoFriend(OnlineFriend);
            OutFriendList.Add(NewFriend);
        }
    }
}

FPicoUserInfo UOnlineSubsystemPicoManager::PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName)
{
    FPicoUserInfo NewFriend;
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetFriendsInterface())
    {
        FUniqueNetIdPico PicoFriend(FriendId);
        TSharedPtr<FOnlineFriend> OlFriend = Subsystem->GetFriendsInterface()->GetFriend(LocalUserNum, PicoFriend, ListName);
        TSharedPtr<FOnlinePicoFriend> OnlineFriend = StaticCastSharedPtr<FOnlinePicoFriend>(OlFriend);
        if (OnlineFriend.IsValid())
        {
            NewFriend = GetBPPicoFriend(OnlineFriend.ToSharedRef());
        }
    }
    return NewFriend;
}


FPicoUserInfo UOnlineSubsystemPicoManager::GetBPPicoFriend(const TSharedRef<FOnlinePicoFriend> InOnlinePicoFriend)
{
    FPicoUserInfo NewFriend;
    NewFriend.DisplayName = InOnlinePicoFriend->GetDisplayName();
    NewFriend.UserId = InOnlinePicoFriend->GetUserStrId();
    NewFriend.ImageUrl = InOnlinePicoFriend->GetImageUrl();
    NewFriend.SmallImageUrl = InOnlinePicoFriend->GetSmallImageUrl();
    NewFriend.InviteToken = InOnlinePicoFriend->GetInviteToken();
    NewFriend.PresencePackage = InOnlinePicoFriend->GetPresencePackage();
    NewFriend.PresenceStr = InOnlinePicoFriend->GetPresencechar();
    NewFriend.PresenceDeeplinkMessage = InOnlinePicoFriend->GetPresenceDeeplinkMessage();
    NewFriend.PresenceDestinationApiName = InOnlinePicoFriend->GetPresenceDestinationApiName();
    NewFriend.PresenceLobbySessionId = InOnlinePicoFriend->GetPresenceLobbySessionId();
    NewFriend.PresenceMatchSessionId = InOnlinePicoFriend->GetPresenceMatchSessionId();
    NewFriend.PresenceExtra = InOnlinePicoFriend->GetPresenceExtra();
    const ppfGender Gender = InOnlinePicoFriend->GetGender();
    if (Gender == ppfGender_Female)
    {
        NewFriend.Gender = EUserGender::Female;
    }
    else if (Gender == ppfGender_Male)
    {
        NewFriend.Gender = EUserGender::Male;
    }
    else
    {
        NewFriend.Gender = EUserGender::Unknow;
    }
    const FOnlineUserPresence& Presence = InOnlinePicoFriend->GetPresence();
    NewFriend.UserPresenceStatus = EUserPresenceStatus::Unknow;
    if (Presence.bIsOnline)
    {
        NewFriend.UserPresenceStatus = EUserPresenceStatus::OnLine;
    }
    else
    {
        NewFriend.UserPresenceStatus = EUserPresenceStatus::OffLine;
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



void UOnlineSubsystemPicoManager::OnRtcUserPublishInfo(const FString& RoomId, const FString& UserId, ERtcMediaStreamType MediaStreamType)
{
    OnRtcUserPublishInfoDelegate.Broadcast(RoomId, UserId, MediaStreamType);
}

void UOnlineSubsystemPicoManager::OnRtcUserUnPublishInfo(const FString& RoomId, const FString& UserId, ERtcMediaStreamType MediaStreamType, ERtcStreamRemoveReason Reason)
{
    OnRtcUserUnPublishInfoDelegate.Broadcast(RoomId, UserId, MediaStreamType, Reason);
}

void UOnlineSubsystemPicoManager::OnGetRtcStreamSyncInfo(const FString& RoomId, const FString& UserId, ERtcStreamIndex StreamIndex, ERtcSyncInfoStreamType RtcSyncInfoStreamType, const FString& Info)
{
    OnGetRtcStreamSyncInfoDelegate.Broadcast(RoomId, UserId, StreamIndex, RtcSyncInfoStreamType, Info);
}

void UOnlineSubsystemPicoManager::OnRtcMessageSendResult(int64 MessageId, int32 Error, const FString& RoomId)
{
    OnRtcMessageSendResultDelegate.Broadcast(MessageId, Error, RoomId);
}

void UOnlineSubsystemPicoManager::OnRtcBinaryMessageReceived(const FString& RoomId, const FString& UserId, const FString& Info)
{
    OnRtcBinaryMessageReceivedDelegate.Broadcast(RoomId, UserId, Info);
}

void UOnlineSubsystemPicoManager::OnRtcBinaryArrayMessageReceived(const FString& RoomId, const FString& UserId, TArray<uint8> BinaryArray)
{
    OnRtcBinaryArrayMessageReceivedDelegate.Broadcast(RoomId, UserId, BinaryArray);
}

void UOnlineSubsystemPicoManager::OnRtcRoomMessageReceived(const FString& RoomId, const FString& UserId, const FString& Message)
{
    OnRtcRoomMessageReceivedDelegateDelegate.Broadcast(RoomId, UserId, Message);
}

void UOnlineSubsystemPicoManager::OnRtcUserMessageReceived(const FString& RoomId, const FString& UserId, const FString& Message)
{
    OnRtcUserMessageReceivedDelegate.Broadcast(RoomId, UserId, Message);
}

void UOnlineSubsystemPicoManager::OnRtcTokenWilExpire(const FString& Message)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlineSubsystemPicoManager::OnRtcTokenWilExpire"));
    OnRtcTokenWilExpireCallbackDelegate.Broadcast(Message);
}


void UOnlineSubsystemPicoManager::OnPresenceJoinIntentReceivedResult(const FString& DeeplinkMessage, const FString& DestinationApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& Extra)
{
    OnPresenceJoinIntentReceivedDelegate.Broadcast(DeeplinkMessage, DestinationApiName, LobbySessionId, MatchSessionId, Extra);
}

void UOnlineSubsystemPicoManager::OnPresenceLeavententReceivedResult(const FString& DestinationApiName, const FString& LobbySessionId, const FString& MatchSessionId)
{
    OnPresenceLeaveIntentReceivedDelegate.Broadcast(DestinationApiName, LobbySessionId, MatchSessionId);
}

void UOnlineSubsystemPicoManager::OnLaunchIntentChangedResult(const FString& MessageString)
{
    OnApplicationLifecycleStringResultDelegate.Broadcast(MessageString);
}

// Game IOnlineSession
bool UOnlineSubsystemPicoManager::IsGameInitSuccess(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->IsInitSuccess();
    }
    return false;
}

bool UOnlineSubsystemPicoManager::GameInitialize(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        Subsystem->GetGameSessionInterface()->Initialize();
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::GameUninitialize(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        Subsystem->GetGameSessionInterface()->Uninitialize();
        return true;
    }
    return false;
}

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
        return (Subsystem->GetGameSessionInterface())->DestroySession(SessionName);
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

#if ENGINE_MAJOR_VERSION > 4
bool UOnlineSubsystemPicoManager::StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnCompleteDelegate)
#elif ENGINE_MINOR_VERSION > 26
bool UOnlineSubsystemPicoManager::StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnCompleteDelegate)
#elif ENGINE_MINOR_VERSION > 24
bool UOnlineSubsystemPicoManager::StartMatchmaking(UObject* WorldContextObject, const TArray< TSharedRef<const FUniqueNetId> >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnCompleteDelegate)
#endif
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        // Session Settings
        if (!IsInputSessionSettingsDataStoreValid(NewSessionSettings))
        {
            return false;
        }
        //auto SessionSettings = GetOnlineSessionSettings(NewSessionSettings);
        SetOnlineSessionSettings(NewSessionSettings);

        // Session Search
        if (!IsInputSessionSearchQueryDataValid(NewSessionSearch))
        {
            return false;
        }
        PicoSessionSearchPtr = &NewSessionSearch;
        SetOnlineSessionSearch(NewSessionSearch);
        TSharedRef<FOnlineSessionSearch> SessionSearchRef = SessionSearchPtr.ToSharedRef();

        UOnlineSubsystemPicoManager::OnMatchmakingCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnMatchmakingCompleteDelegate_Handle(
            FOnMatchmakingCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnMatchmakingComplete));
        return Subsystem->GetGameSessionInterface()->StartMatchmaking(LocalPlayers, SessionName, SessionSettings, SessionSearchRef);
    }
    return false;
}

TSharedPtr<FOnlineSessionSearch> UOnlineSubsystemPicoManager::GetOnlineSessionSearch(const FPicoOnlineSessionSearch& SessionSearch)
{
    TSharedPtr<FOnlineSessionSearch> newSessionSearch = MakeShareable(new FOnlineSessionSearch());
    newSessionSearch->PlatformHash = SessionSearch.PlatformHash;
    newSessionSearch->TimeoutInSeconds = SessionSearch.TimeoutInSeconds;
    newSessionSearch->MaxSearchResults = SessionSearch.MaxSearchResults;
    newSessionSearch->bIsLanQuery = SessionSearch.bIsLanQuery;
    newSessionSearch->PingBucketSize = SessionSearch.PingBucketSize;
    newSessionSearch->SearchState = (EOnlineAsyncTaskState::Type)SessionSearch.SearchState;
    // SearchResults
    newSessionSearch->SearchResults.Reset();
    for (int i = 0; i < SessionSearch.SearchResults.Num(); i++)
    {
        auto newSession = SessionSearch.SearchResults[i].Session;
        FOnlineSessionSearchResult newResult;
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto OwningUserId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(newSession.OwningUserId).ToSharedRef();
        newResult.Session.OwningUserId = OwningUserId;
        newResult.Session.OwningUserName = newSession.OwningUserName;
        ppfID RoomID = FCString::Strtoui64(*newSession.SessionInfoRoomID, NULL, 10);
        newResult.Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomID));
        newResult.Session.SessionSettings = GetOnlineSessionSettings(newSession.SessionSettings);
        newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
        newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
        newResult.PingInMs = SessionSearch.SearchResults[i].PingInMs;
        newSessionSearch->SearchResults.Add(MoveTemp(newResult));
    }
    // QuerySettings
    if (SessionSearch.QuerySettingsKeyArray.Num() != SessionSearch.QuerySettingsValueArray.Num())
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME FindSessions keys count != values count"));
        return newSessionSearch;
    }
    for (int i = 0; i < SessionSearch.QuerySettingsKeyArray.Num(); i++)
    {
        if (*SessionSearch.QuerySettingsKeyArray[i] == SEARCH_PICO_MODERATED_ROOMS_ONLY)
        {
            newSessionSearch->QuerySettings.Set(FName(*SessionSearch.QuerySettingsKeyArray[i]), SessionSearch.QuerySettingsValueArray[i].ToBool(), EOnlineComparisonOp::Equals);
        }
        else
        {
            newSessionSearch->QuerySettings.Set(FName(*SessionSearch.QuerySettingsKeyArray[i]), SessionSearch.QuerySettingsValueArray[i], EOnlineComparisonOp::Equals);
        }
    }
    return newSessionSearch;
}

FOnlineSessionSettings UOnlineSubsystemPicoManager::GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    //FOnlineSessionSettings SessionSettings;
    SessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    SessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    SessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    SessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    SessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    SessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    SessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    if (UpdatedSessionSettings.ValueArray.Num() != UpdatedSessionSettings.KeyArray.Num())
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME GetOnlineSessionSettings keys count != values count"));
        return SessionSettings;
    }
    for (int i = 0; i < UpdatedSessionSettings.KeyArray.Num(); i++)
    {
        FName Key = FName(*UpdatedSessionSettings.KeyArray[i]);
        FString Value = UpdatedSessionSettings.ValueArray[i];
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME GetOnlineSessionSettings Key: %s, Value: %s"), *UpdatedSessionSettings.KeyArray[i], *Value);
        SessionSettings.Settings.Add(Key, Value);
    }
    return SessionSettings;
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

bool UOnlineSubsystemPicoManager::FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        if (!IsInputSessionSearchQueryDataValid(NewSessionSearch))
        {
            return false;
        }

        PicoSessionSearchPtr = &NewSessionSearch;
        SetOnlineSessionSearch(NewSessionSearch);

        UOnlineSubsystemPicoManager::OnFindSessionCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetGameSessionInterface()->AddOnFindSessionsCompleteDelegate_Handle(
            FOnFindSessionsCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnFindSessionComplete));
        return (Subsystem->GetGameSessionInterface())->FindSessions(SearchingPlayerNum, SessionSearchPtr.ToSharedRef());
    }
    return false;
}

bool UOnlineSubsystemPicoManager::IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& InputSessionSearch)
{
    bool Valid = InputSessionSearch.QuerySettingsKeyArray.Num() == InputSessionSearch.QuerySettingsValueArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSearchQueryDataValid keys count != values count"));
    }
    return Valid;
}

bool UOnlineSubsystemPicoManager::IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    bool Valid = UpdatedSessionSettings.ValueArray.Num() == UpdatedSessionSettings.KeyArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSettingsDataStoreValid keys count != values count"));
    }
    return Valid;
}

// FPicoOnlineSessionSearch -> FOnlineSessionSearch
void UOnlineSubsystemPicoManager::SetOnlineSessionSearch(const FPicoOnlineSessionSearch& InputSessionSearch)
{
    SessionSearchPtr = MakeShareable(new FOnlineSessionSearch());
    SessionSearchPtr->PlatformHash = InputSessionSearch.PlatformHash;
    SessionSearchPtr->TimeoutInSeconds = InputSessionSearch.TimeoutInSeconds;
    SessionSearchPtr->MaxSearchResults = InputSessionSearch.MaxSearchResults;
    SessionSearchPtr->bIsLanQuery = InputSessionSearch.bIsLanQuery;
    SessionSearchPtr->PingBucketSize = InputSessionSearch.PingBucketSize;
    SessionSearchPtr->SearchState = (EOnlineAsyncTaskState::Type)InputSessionSearch.SearchState;
    // SearchResults
    SessionSearchPtr->SearchResults.Reset();
    for (int i = 0; i < InputSessionSearch.SearchResults.Num(); i++)
    {
        auto newSession = InputSessionSearch.SearchResults[i].Session;
        FOnlineSessionSearchResult newResult;
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto OwningUserId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(newSession.OwningUserId).ToSharedRef();
        newResult.Session.OwningUserId = OwningUserId;
        newResult.Session.OwningUserName = newSession.OwningUserName;
        ppfID RoomID = FCString::Strtoui64(*newSession.SessionInfoRoomID, NULL, 10);
        newResult.Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomID));
        SetOnlineSessionSettings(newSession.SessionSettings); 
        newResult.Session.SessionSettings = SessionSettings;
        newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
        newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
        newResult.PingInMs = InputSessionSearch.SearchResults[i].PingInMs;
        SessionSearchPtr->SearchResults.Add(MoveTemp(newResult));
    }
    // QuerySettings
    if (InputSessionSearch.QuerySettingsKeyArray.Num() != InputSessionSearch.QuerySettingsValueArray.Num())
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME FindSessions keys count != values count"));
        return;
    }
    for (int i = 0; i < InputSessionSearch.QuerySettingsKeyArray.Num(); i++)
    {
        if (*InputSessionSearch.QuerySettingsKeyArray[i] == SEARCH_PICO_MODERATED_ROOMS_ONLY)
        {
            SessionSearchPtr->QuerySettings.Set(FName(*InputSessionSearch.QuerySettingsKeyArray[i]), InputSessionSearch.QuerySettingsValueArray[i].ToBool(), EOnlineComparisonOp::Equals);
        }
        else
        {
            SessionSearchPtr->QuerySettings.Set(FName(*InputSessionSearch.QuerySettingsKeyArray[i]), InputSessionSearch.QuerySettingsValueArray[i], EOnlineComparisonOp::Equals);
        }
    }
}

// FPicoOnlineSessionSettings -> FOnlineSessionSettings
void UOnlineSubsystemPicoManager::SetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    SessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    SessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    SessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    SessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    SessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    SessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    SessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    if (UpdatedSessionSettings.ValueArray.Num() != UpdatedSessionSettings.KeyArray.Num())
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME GetOnlineSessionSettings keys count != values count"));
        return;
    }
    for (int i = 0; i < UpdatedSessionSettings.KeyArray.Num(); i++)
    {
        FName Key = FName(*UpdatedSessionSettings.KeyArray[i]);
        FString Value = UpdatedSessionSettings.ValueArray[i];
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME GetOnlineSessionSettings Key: %s, Value: %s"), *UpdatedSessionSettings.KeyArray[i], *Value);
        SessionSettings.Settings.Add(Key, Value);
    }
}

// FOnlineSessionSettings -> FPicoOnlineSessionSettings
FPicoOnlineSessionSettings UOnlineSubsystemPicoManager::GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings)
{
    FPicoOnlineSessionSettings PicoSessionSettings;
    PicoSessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    PicoSessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    PicoSessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    PicoSessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    PicoSessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    PicoSessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    PicoSessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    PicoSessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    for (auto& item : UpdatedSessionSettings.Settings)
    {
        PicoSessionSettings.KeyArray.Add(*item.Key.ToString());
        PicoSessionSettings.ValueArray.Add(*item.Value.Data.ToString());
    }
    return PicoSessionSettings;
}

// FOnlineSessionSearch -> FPicoOnlineSessionSearch
void UOnlineSubsystemPicoManager::SetPicoOnlineSessionSearch()
{
    PicoSessionSearchPtr->PlatformHash = SessionSearchPtr->PlatformHash;
    PicoSessionSearchPtr->SearchState = (EOnlineAsyncTaskStatePicoType)SessionSearchPtr->SearchState;
    PicoSessionSearchPtr->bIsLanQuery = SessionSearchPtr->bIsLanQuery;
    PicoSessionSearchPtr->MaxSearchResults = SessionSearchPtr->MaxSearchResults;
    PicoSessionSearchPtr->PingBucketSize = SessionSearchPtr->PingBucketSize;
    PicoSessionSearchPtr->TimeoutInSeconds = SessionSearchPtr->TimeoutInSeconds;

    // searchResults
    PicoSessionSearchPtr->SearchResults.Reset();
    for (int i = 0; i < SessionSearchPtr->SearchResults.Num(); i++)
    {
        auto newSession = SessionSearchPtr->SearchResults[i].Session;
        FPicoOnlineSessionSearchResult newResult;
        newResult.Session.OwningUserId = newSession.OwningUserId->ToString();
        newResult.Session.OwningUserName = newSession.OwningUserName;
        newResult.Session.SessionInfoRoomID = newSession.SessionInfo->GetSessionId().ToString();
        newResult.Session.SessionSettings = GetPicoOnlineSessionSettings(newSession.SessionSettings);
        newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
        newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
        newResult.PingInMs = SessionSearchPtr->SearchResults[i].PingInMs;
        PicoSessionSearchPtr->SearchResults.Add(newResult);
    }
}

bool UOnlineSubsystemPicoManager::FindSessionById(UObject* WorldContextObject, const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FPicoManagerOnSingleSessionResultCompleteDelegate& CompletionDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
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

FNamedOnlineSession* UOnlineSubsystemPicoManager::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSessionSettings& InputSessionSettings)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->AddNamedSession(SessionName, InputSessionSettings);
    }
    return nullptr;
}

FNamedOnlineSession* UOnlineSubsystemPicoManager::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSession& InputSession)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->AddNamedSession(SessionName, InputSession);
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

bool UOnlineSubsystemPicoManager::SendSessionInviteToFriend(UObject* WorldContextObject, int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetGameSessionInterface())
    {
        return Subsystem->GetGameSessionInterface()->SendSessionInviteToFriend(LocalUserNum, SessionName, Friend);
    }
    return false;
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
        SetPicoOnlineSessionSearch();
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
        SetPicoOnlineSessionSearch();
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
        if (SearchResult.IsSessionInfoValid())
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
            newResult.Session.SessionSettings = GetPicoOnlineSessionSettings(Settings);
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

void UOnlineSubsystemPicoManager::OnGameInitializeCallback(bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage, int Result)
{
    OnGameInitializeCallbackDelegate.Broadcast(bWasSuccessful, ErrorCode, ErrorMessage, Result);
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

void UOnlineSubsystemPicoManager::OnSessionLeaveNotification(const FString& RoomID, bool bWasSuccessful)
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

void UOnlineSubsystemPicoManager::OnRoomUpdateComplete(const FString& RoomID, bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage)
{
    UE_LOG(LogTemp, Log, TEXT("OnRoomUpdateComplete OnRoomUpdateNotifyDelegate.Broadcast"));
    OnRoomUpdateNotifyDelegate.Broadcast(RoomID, bWasSuccessful, ErrorCode, ErrorMessage);
}

void UOnlineSubsystemPicoManager::OnRoomInviteAcceptedComplete(const FString& RoomID, bool bWasSuccessful)
{
    OnRoomInviteAcceptedNotifyDelegate.Broadcast(RoomID, bWasSuccessful);
}
void UOnlineSubsystemPicoManager::OnMatchmakingFoundComplete(const FString& RoomID, bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage)
{
    UE_LOG(LogTemp, Log, TEXT("OnMatchmakingFoundComplete OnMatchmakingFoundNotifyDelegate.Broadcast"));
    OnMatchmakingFoundNotifyDelegate.Broadcast(RoomID, bWasSuccessful, ErrorCode, ErrorMessage);
}
void UOnlineSubsystemPicoManager::OnSessionUserInviteAccepted(const bool bWasSuccessful, const int32 ControllerId,
                                                    const FString& UserId,
                                                    const FPicoOnlineSessionSearchResult& InviteResult)
{
    // OnPicoSessionUserInviteAcceptedDelegate.Broadcast(bWasSuccessful, ControllerId, UserId, InviteResult);
}


bool UOnlineSubsystemPicoManager::PresenceClear(UObject* WorldContextObject, FOnlineManagerPresenceClearDelegate InPresenceClearDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceClearDelegate = InPresenceClearDelegate;
        PresenceClearCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceClearComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceClear(PresenceClearCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceClearComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceClearCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceClearDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceClearDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceClearDelegate.Unbind();
    }
}

void UOnlineSubsystemPicoManager::ReadInvitableUser(UObject* WorldContextObject, TArray<FString> SuggestedUserList, FOnlineManagerPresenceReadInvitableUserDelegate InReadInvitableUserDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceReadInvitableUserDelegate = InReadInvitableUserDelegate;
        PresenceReadInvitableUserCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnReadInvitableUserComplete);
        Subsystem->GetPicoPresenceInterface()->ReadInvitableUser(SuggestedUserList, PresenceReadInvitableUserCompleteDelegate);
    }
}

void UOnlineSubsystemPicoManager::OnReadInvitableUserComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceReadInvitableUserCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceReadInvitableUserDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceReadInvitableUserDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceReadInvitableUserDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::GetInvitableFriendList(UObject* WorldContextObject, TArray<FPicoUserInfo>& OutFriendsList)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        TArray< TSharedRef<FOnlinePicoFriend> > OutFriends;
        Subsystem->GetPicoPresenceInterface()->GetInvitableFriendList(OutFriends);
        OutFriendsList.Empty();
        for (auto Friend : OutFriends)
        {
            FPicoUserInfo NewFriend = GetBPPicoFriend(Friend);
            // StaticCastSharedPtr
            //TSharedRef<FOnlinePicoFriend> OnlineFriend = StaticCastSharedRef<FOnlinePicoFriend>(Friend);           
            OutFriendsList.Add(NewFriend);

        }
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::PresenceSet(UObject* WorldContextObject, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, FOnlineManagerPresenceSetDelegate InPresenceSetDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetDelegate = InPresenceSetDelegate;
        PresenceSetCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSet(ApiName, LobbySessionId, MatchSessionId, bIsJoinable, Extra, PresenceSetCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSetDestination(UObject* WorldContextObject, const FString& ApiName, FOnlineManagerPresenceSetDestinationDelegate InPresenceSetDestinationDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetDestinationDelegate = InPresenceSetDestinationDelegate;
        PresenceSetDestinationCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetDestinationComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSetDestination(ApiName, PresenceSetDestinationCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetDestinationComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetDestinationCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetDestinationDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetDestinationDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetDestinationDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSetIsJoinable(UObject* WorldContextObject, bool bIsJoinable, FOnlineManagerPresenceSetIsJoinableDelegate InPresenceSetIsJoinableDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetIsJoinableDelegate = InPresenceSetIsJoinableDelegate;
        PresenceSetIsJoinableCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetIsJoinableComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSetSetIsJoinable(bIsJoinable, PresenceSetIsJoinableCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetIsJoinableComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetIsJoinableCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetIsJoinableDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetIsJoinableDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetIsJoinableDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSetLobbySession(UObject* WorldContextObject, const FString& LobbySession, FOnlineManagerPresenceSetLobbySessionDelegate InPresenceSetLobbySessionDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetLobbySessionDelegate = InPresenceSetLobbySessionDelegate;
        PresenceSetLobbySessionCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetLobbySessionComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSetLobbySession(LobbySession, PresenceSetLobbySessionCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetLobbySessionComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetLobbySessionCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetLobbySessionDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetLobbySessionDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetLobbySessionDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSetMatchSession(UObject* WorldContextObject, const FString& MatchSession, FOnlineManagerPresenceSetMatchSessionDelegate InPresenceSetMatchSessionDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetMatchSessionDelegate = InPresenceSetMatchSessionDelegate;
        PresenceSetMatchSessionCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetMatchSessionComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSetMatchSession(MatchSession, PresenceSetMatchSessionCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetMatchSessionComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetMatchSessionCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetMatchSessionDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetMatchSessionDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetMatchSessionDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSetExtra(UObject* WorldContextObject, const FString& Extra, FOnlineManagerPresenceSetExtraDelegate InPresenceSetExtraDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSetExtraDelegate = InPresenceSetExtraDelegate;
        PresenceSetExtraCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceSetExtraComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSetExtra(Extra, PresenceSetExtraCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceSetExtraComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSetExtraCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSetExtraDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSetExtraDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSetExtraDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceReadSendInvites(UObject* WorldContextObject, FOnlineManagerPresenceReadSentInvitesDelegate InPresenceReadSendInvitesDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceReadSentInvitesDelegate = InPresenceReadSendInvitesDelegate;
        PresenceReadSentInvitesCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnPresenceReadSendInvitesComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceReadSendInvites(PresenceReadSentInvitesCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnPresenceReadSendInvitesComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceReadSentInvitesCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceReadSentInvitesDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceReadSentInvitesDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceReadSentInvitesDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceSendInvites(UObject* WorldContextObject, TArray<FString> UserIdArray, FOnlineManagerPresenceSentInvitesDelegate InPresenceSentInvitesDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceSentInvitesDelegate = InPresenceSentInvitesDelegate;
        PresenceSentInvitesCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnSendInvitesComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceSendInvites(UserIdArray, PresenceSentInvitesCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnSendInvitesComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceSentInvitesCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceSentInvitesDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceSentInvitesDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceSentInvitesDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::GetSendInvitesList(UObject* WorldContextObject, TArray<FPicoApplicationInvite>& OutList)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        OutList.Empty();
        Subsystem->GetPicoPresenceInterface()->GetSendInvitesList(OutList);
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::PresenceGetDestinations(UObject* WorldContextObject, FOnlineManagerPresenceGetDestinationsDelegate InPresenceGetDestinationsDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::PresenceGetDestinationsDelegate = InPresenceGetDestinationsDelegate;
        PresenceGetDestinationsCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnGetDestinationsComplete);
        Subsystem->GetPicoPresenceInterface()->PresenceGetDestinations(PresenceGetDestinationsCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnGetDestinationsComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    PresenceGetDestinationsCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::PresenceGetDestinationsDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::PresenceGetDestinationsDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::PresenceGetDestinationsDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::PresenceGetDestinationsList(UObject* WorldContextObject, TArray<FPicoDestination>& OutList)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        OutList.Empty();
        Subsystem->GetPicoPresenceInterface()->PresenceGetDestnationsList(OutList);
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::LaunchInvitePanel(UObject* WorldContextObject, FOnlineManagerLaunchInvitePanelDelegate InLaunchInvitePanelDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::LaunchInvitePanelDelegate = InLaunchInvitePanelDelegate;
        LaunchInvitePanelCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnLaunchInvitePanelComplete);
        Subsystem->GetPicoPresenceInterface()->LaunchInvitePanel(LaunchInvitePanelCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnLaunchInvitePanelComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    LaunchInvitePanelCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::LaunchInvitePanelDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LaunchInvitePanelDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::LaunchInvitePanelDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::ShareMedia(UObject* WorldContextObject, EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, FOnlineManagerShareMediaDelegate InShareMediaDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoPresenceInterface())
    {
        UOnlineSubsystemPicoManager::ShareMediaDelegate = InShareMediaDelegate;
        SharedMediaCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnShareMediaComplete);
        Subsystem->GetPicoPresenceInterface()->ShareMedia(InMediaType, InVideoPath, InVideoThumbPath, InImagePaths, InShareType, SharedMediaCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnShareMediaComplete(bool bIsSuccessed, const FString& ErrorMessage)
{
    SharedMediaCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::ShareMediaDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::ShareMediaDelegate.Execute(bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::ShareMediaDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::LaunchOtherApp(UObject* WorldContextObject, const FString& PackageName, const FString& Message, FOnlineManagerLaunchOtherAppDelegate InLaunchOtherAppDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationInterface())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppDelegate = InLaunchOtherAppDelegate;
        LaunchOtherAppCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnLaunchOtherAppComplete);
        Subsystem->GetApplicationInterface()->LaunchOtherApp(PackageName, Message, LaunchOtherAppCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnLaunchOtherAppComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage)
{
    LaunchOtherAppCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::LaunchOtherAppDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppDelegate.Execute(Message, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::LaunchOtherAppDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::LaunchOtherAppByAppId(UObject* WorldContextObject, const FString& AppId, const FString& Message, FOnlineManagerLaunchOtherAppByAppIdDelegate InLaunchOtherAppByAppIdDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationInterface())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppByAppIdDelegate = InLaunchOtherAppByAppIdDelegate;
        LaunchOtherAppByAppIdCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnLaunchOtherAppByAppIdComplete);
        Subsystem->GetApplicationInterface()->LaunchOtherAppByAppId(AppId, Message, LaunchOtherAppByAppIdCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnLaunchOtherAppByAppIdComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage)
{
    LaunchOtherAppByAppIdCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::LaunchOtherAppByAppIdDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppByAppIdDelegate.Execute(Message, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::LaunchOtherAppByAppIdDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::GetVersion(UObject* WorldContextObject, FOnlineManagerGetVersionDelegate InGetVersionDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationInterface())
    {
        UOnlineSubsystemPicoManager::GetVersionDelegate = InGetVersionDelegate;
        GetVersionCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnGetVersionComplete);
        Subsystem->GetApplicationInterface()->GetVersion(GetVersionCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnGetVersionComplete(int64 CurrentCode, const FString& CurrentName, int64 LatestCode, const FString& LatestName, bool bIsSuccessed, const FString& ErrorMessage)
{
    GetVersionCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::GetVersionDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::GetVersionDelegate.Execute(CurrentCode, CurrentName, LatestCode, LatestName, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::GetVersionDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::LaunchOtherAppByPresence(UObject* WorldContextObject, const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, FOnlineManagerLaunchOtherAppByPresenceDelegate InLaunchOtherAppByPresenceDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationInterface())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppByPresenceDelegate = InLaunchOtherAppByPresenceDelegate;
        LaunchOtherAppByPresenceCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnLaunchOtherAppByPresenceComplete);
        Subsystem->GetApplicationInterface()->LaunchOtherAppByPresence(AppID, PackageName, Message, ApiName, LobbySessionId, MatchSessionId, TrackId, Extra, LaunchOtherAppByPresenceCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnLaunchOtherAppByPresenceComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage)
{
    LaunchOtherAppByPresenceCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::LaunchOtherAppByPresenceDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LaunchOtherAppByPresenceDelegate.Execute(Message, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::LaunchOtherAppByPresenceDelegate.Unbind();
    }
}

bool UOnlineSubsystemPicoManager::LaunchStore(UObject* WorldContextObject, FOnlineManagerLaunchStoreDelegate InLaunchStoreDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationInterface())
    {
        UOnlineSubsystemPicoManager::LaunchStoreDelegate = InLaunchStoreDelegate;
        LaunchStoreCompleteDelegate.BindUObject(this, &UOnlineSubsystemPicoManager::OnLaunchStoreComplete);
        Subsystem->GetApplicationInterface()->LaunchStore(LaunchStoreCompleteDelegate);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnLaunchStoreComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage)
{
    LaunchStoreCompleteDelegate.Unbind();
    if (UOnlineSubsystemPicoManager::LaunchStoreDelegate.IsBound())
    {
        UOnlineSubsystemPicoManager::LaunchStoreDelegate.Execute(Message, bIsSuccessed, ErrorMessage);
        UOnlineSubsystemPicoManager::LaunchStoreDelegate.Unbind();
    }
}


bool UOnlineSubsystemPicoManager::GetLaunchDetails(UObject* WorldContextObject, FLaunchDetails& OutLaunchDetails)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationLifecycleInterface())
    {
        Subsystem->GetApplicationLifecycleInterface()->GetLaunchDetails(OutLaunchDetails);
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::LogDeeplinkResult(UObject* WorldContextObject, const FString& TrackingID, ELaunchResult LaunchResult)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationLifecycleInterface())
    {
        Subsystem->GetApplicationLifecycleInterface()->LogDeeplinkResult(TrackingID, LaunchResult);
        return true;
    }
    return false;
}

bool UOnlineSubsystemPicoManager::GetSystemInfo(UObject* WorldContextObject, FPicoSystemInfo& SystemInfo)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetApplicationLifecycleInterface())
    {
        Subsystem->GetApplicationLifecycleInterface()->GetSystemInfo(SystemInfo);
        return true;
    }
    return false;
}

void UOnlineSubsystemPicoManager::OnAssetFileDownloadUpdate(UPico_AssetFileDownloadUpdate* AssetFileDownloadUpdateObj)
{
    OnAssetFileDownloadUpdateDelegate.Broadcast(AssetFileDownloadUpdateObj);
}

void UOnlineSubsystemPicoManager::OnAssetFileDeleteForSafety(UPico_AssetFileDeleteForSafety* AssetFileDeleteForSafetyObj)
{
    OnAssetFileDeleteForSafetyDelegate.Broadcast(AssetFileDeleteForSafetyObj);
}


void UOnlineSubsystemPicoManager::OnSpeechAsrResult(UPico_AsrResult* AsrResultObj)
{
    OnSpeechAsrResultDelegate.Broadcast(AsrResultObj);
}

void UOnlineSubsystemPicoManager::OnSpeechError(UPico_SpeechError* SpeechErrorObj)
{
    OnSpeechErrorDelegate.Broadcast(SpeechErrorObj);
}

void UOnlineSubsystemPicoManager::OnHighlightRecordStop(UPico_RecordInfo* RecordInfoObj)
{
    OnHighlightRecordStopDelegate.Broadcast(RecordInfoObj);
}
// Leaderboard
void UOnlineSubsystemPicoManager::SetOnlineLeaderboardRead(const FPicoOnlineLeaderboardRead& PicoLeaderboardReadObject)
{
    LeaderboardReadPtr = MakeShareable(new Pico_OnlineLeaderboardRead(PicoLeaderboardReadObject.LeaderboardName, PicoLeaderboardReadObject.PageIndex, PicoLeaderboardReadObject.PageSize));
    LeaderboardReadPtr->SortedColumn = FName(PicoLeaderboardReadObject.SortedColumn);
}
void UOnlineSubsystemPicoManager::RefreshPicoOnlineLeaderboardRead()
{
    PicoLeaderboardReadPtr->LeaderboardName = LeaderboardReadPtr->LeaderboardName.ToString();
    PicoLeaderboardReadPtr->ReadState = (EOnlineAsyncTaskStatePicoType)LeaderboardReadPtr->ReadState;
    PicoLeaderboardReadPtr->SortedColumn = LeaderboardReadPtr->SortedColumn.ToString();
    PicoLeaderboardReadPtr->Rows.Reset();
    for (int i = 0; i < LeaderboardReadPtr->Rows.Num(); i++)
    {
        FPicoOnlineStatsRow Row;
        auto RowItem = LeaderboardReadPtr->Rows[i];
        Row.Rank = RowItem.Rank;
        Row.NickName = RowItem.NickName;
        if (RowItem.PlayerId.IsValid())
        {
            Row.PlayerId = *RowItem.PlayerId->ToString();
        }
        auto ColsArray = RowItem.Columns;
        for (auto& item : ColsArray)
        {
            FVariantDataPico Value;
            Value.Type = (EPicoOnlineKeyValuePairDataType)item.Value.GetType();
            switch (Value.Type)
            {
            case EPicoOnlineKeyValuePairDataType::String:
                item.Value.GetValue(Value.Value);
                break;
            case EPicoOnlineKeyValuePairDataType::Bool:
                bool BoolResult;
                item.Value.GetValue(BoolResult);
                Value.Value = BoolResult ? TEXT("true") : TEXT("false");
                break;
            case EPicoOnlineKeyValuePairDataType::Double: //  todo
            case EPicoOnlineKeyValuePairDataType::Float:
                float FloatResult;
                item.Value.GetValue(FloatResult);
                Value.Value = FString::SanitizeFloat(FloatResult);
                break;
            case EPicoOnlineKeyValuePairDataType::Int32:
            case EPicoOnlineKeyValuePairDataType::Int64: //  todo
                int64 Int64Result;
                item.Value.GetValue(Int64Result);
                Value.Value = FString::FromInt(Int64Result);
                break;
            default: 
                break;
            }
            Row.Columns.Add(item.Key, Value);
        }
        PicoLeaderboardReadPtr->Rows.Add(Row);
    }
    for (int i = 0; i < LeaderboardReadPtr->ColumnMetadata.Num(); i++)
    {
        FPicoColumnMetaData Data;
        Data.ColumnName = LeaderboardReadPtr->ColumnMetadata[i].ColumnName.ToString();
        Data.DataType = (EPicoOnlineKeyValuePairDataType)LeaderboardReadPtr->ColumnMetadata[i].DataType;
        PicoLeaderboardReadPtr->ColumnMetadata.Add(Data);
    }
}

#if ENGINE_MAJOR_VERSION > 4
bool UOnlineSubsystemPicoManager::ReadLeaderboards(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnCompleteDelegate)
#elif ENGINE_MINOR_VERSION > 26
bool UOnlineSubsystemPicoManager::ReadLeaderboards(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnCompleteDelegate)
#elif ENGINE_MINOR_VERSION > 24
bool UOnlineSubsystemPicoManager::ReadLeaderboards(UObject* WorldContextObject, const TArray< TSharedRef<const FUniqueNetId> >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnCompleteDelegate)
#endif
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetLeaderboardsInterface())
    {
        PicoLeaderboardReadPtr = &PicoReadObject;
        SetOnlineLeaderboardRead(PicoReadObject);
        FOnlineLeaderboardReadRef ReadObjectRef = LeaderboardReadPtr.ToSharedRef();
        UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetLeaderboardsInterface()->AddOnLeaderboardReadCompleteDelegate_Handle(
            FOnLeaderboardReadCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnReadLeaderboardsComplete));
        return Subsystem->GetLeaderboardsInterface()->ReadLeaderboards(Players, ReadObjectRef);
    }
    return false;
}

bool UOnlineSubsystemPicoManager::ReadLeaderboardsForFriends(UObject* WorldContextObject, int32 LocalUserNum, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnCompleteDelegate)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetLeaderboardsInterface())
    {
        PicoLeaderboardReadPtr = &PicoReadObject;
        SetOnlineLeaderboardRead(PicoReadObject);
        FOnlineLeaderboardReadRef ReadObjectRef = LeaderboardReadPtr.ToSharedRef();
        UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate = OnCompleteDelegate;
        Subsystem->GetLeaderboardsInterface()->AddOnLeaderboardReadCompleteDelegate_Handle(
            FOnLeaderboardReadCompleteDelegate::CreateUObject(this, &UOnlineSubsystemPicoManager::OnReadLeaderboardsComplete));
        return Subsystem->GetLeaderboardsInterface()->ReadLeaderboardsForFriends(LocalUserNum, ReadObjectRef);
    }
    return false;
}

bool UOnlineSubsystemPicoManager::WriteLeaderboards(UObject* WorldContextObject, const FName& SessionName, const FUniqueNetId& Player, FOnlineLeaderboardWrite& WriteObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetLeaderboardsInterface())
    {
        return Subsystem->GetLeaderboardsInterface()->WriteLeaderboards(SessionName, Player, WriteObject);
    }
    return false;
}

// Leaderboard OnComplete
void UOnlineSubsystemPicoManager::OnReadLeaderboardsComplete(bool bWasSuccessful)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    Subsystem->GetLeaderboardsInterface()->ClearOnLeaderboardReadCompleteDelegates(this);
    if (UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate.IsBound())
    {
        RefreshPicoOnlineLeaderboardRead();
        UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate.Execute(bWasSuccessful);
        UOnlineSubsystemPicoManager::OnReadLeaderboardsCompleteDelegate.Unbind();
    }
}
