// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "OnlinePicoFunctionLibrary.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystem.h"
#include "OnlinePicoSettings.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPicoManager.h"
#include "Interfaces/OnlineLeaderboardInterface.h"
#include "OnlineSessionInterfacePico.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "OnlineSubsystemPicoTypes.h"


#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif


FOnlinePicoVerifyAppDelegate UOnlinePicoFunctionLibrary::VerifyAppDelegate;
int32 UOnlinePicoFunctionLibrary::VerifyAppCode = 1;


UOnlineSubsystemPicoManager* UOnlinePicoFunctionLibrary::PicoSubsystemManager = nullptr;
UOnlinePicoFunctionLibrary::UOnlinePicoFunctionLibrary()
{
    PicoSubsystemManager = NewObject<UOnlineSubsystemPicoManager>();
}

void UOnlinePicoFunctionLibrary::PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->PicoReadFriendList(WorldContextObject, LocalUserNum, ListName, InReadFriendListDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoGetFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, TArray<FPicoUserInfo>& OutFriends)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->PicoGetFriendList(WorldContextObject, LocalUserNum, ListName, OutFriends);
    }
}

FPicoUserInfo UOnlinePicoFunctionLibrary::PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName)
{
    FPicoUserInfo NewFriend;
    if (PicoSubsystemManager)
    {
        NewFriend = PicoSubsystemManager->PicoGetFriend(WorldContextObject, LocalUserNum, FriendId, ListName);
    }
    return NewFriend;
}

ERtcEngineInitResult UOnlinePicoFunctionLibrary::PicoGetRtcEngineInit(UObject* WorldContextObject)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PicoRtcEngineInit(WorldContextObject);
    }
    return ERtcEngineInitResult::None;
}

UOnlineSubsystemPicoManager* UOnlinePicoFunctionLibrary::GetOnlineSubsystemPicoManager(UObject* WorldContextObject)
{

    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem)
    {
        if (!PicoSubsystemManager)
        {
            PicoSubsystemManager = NewObject<UOnlineSubsystemPicoManager>();
        }
        return PicoSubsystemManager;
    }
    return nullptr;
}


void UOnlinePicoFunctionLibrary::FindFileOrForder(TArray<FString>& OutFindArray, const FString& FindName, const FString& FindPath, bool IsFile /*= false*/, bool IsInDirectories /*= true*/)
{
    OutFindArray.Empty();
    class FFileMatch : public IPlatformFile::FDirectoryVisitor
    {
    public:
        TArray<FString>& Result;
        FString WildCard;
        bool bFiles;
        bool bDirectories;
        FFileMatch(TArray<FString>& InResult, const FString& InWildCard, bool bInFiles, bool bInDirectories)
            : Result(InResult)
            , WildCard(InWildCard)
            , bFiles(bInFiles)
            , bDirectories(bInDirectories)
        {
        }
        virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
        {
            if (!bDirectories && bIsDirectory)
            {
                return false;
            }
            if (((bIsDirectory && bDirectories) || (!bIsDirectory && bFiles))
                && FPaths::GetCleanFilename(FilenameOrDirectory).MatchesWildcard(WildCard))
            {
                FString LongPackageName;
                Result.Add(FilenameOrDirectory);
            }
            return true;
        }
    };
    const FString CleanFilename = TEXT("*") + FindName;
    FFileMatch FileMatch(OutFindArray, CleanFilename, IsFile, IsInDirectories);

    IFileManager::Get().IterateDirectoryRecursively(*FindPath, FileMatch);
}

void UOnlinePicoFunctionLibrary::PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& UserId, const FString& InToken, const FString& InType, FOnlineManagerLoginCompleteDelegate InLoginComleteDelegate)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->PicoLogin(WorldContextObject, LocalUserNum, UserId, InType, InToken, InLoginComleteDelegate);
    }
}


FString UOnlinePicoFunctionLibrary::PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum)
{
    FString NickName = FString();
    if (PicoSubsystemManager)
    {
        NickName = PicoSubsystemManager->PicoGetNickName(WorldContextObject, LocalUserNum);
    }
    return NickName;
}

UPico_User* UOnlinePicoFunctionLibrary::GetLoginPicoUser(UObject* WorldContextObject, int32 LocalUserNum)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->GetLoginPicoUser(WorldContextObject, LocalUserNum);
    }
    return nullptr;
}

void UOnlinePicoFunctionLibrary::PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->PicoRtcGetToken(WorldContextObject, UserId, RoomId, Ttl, InValue, InRtcGetTokenDelegate);
    }
}

int UOnlinePicoFunctionLibrary::PicoRtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->RtcJoinRoom(WorldContextObject, RoomId, UserId, Token, UserExtra, InRoomProfileType, bIsAutoSubscribeAudio);
    }
    return 999;
}

int UOnlinePicoFunctionLibrary::RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->RtcDestroyRoom(WorldContextObject, RoomId);
    }
    return 999;
}

void UOnlinePicoFunctionLibrary::RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcEnableAudioPropertiesReport(WorldContextObject, Interval);
    }
}

int UOnlinePicoFunctionLibrary::RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->RtcLeaveRoom(WorldContextObject, RoomId);
    }
    return 999;
}

void UOnlinePicoFunctionLibrary::RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcMuteLocalAudio(WorldContextObject, InRtcMuteState);
    }
}

void UOnlinePicoFunctionLibrary::RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcPublishRoom(WorldContextObject, RoomId);
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcRoomPauseAllSubscribedStream(WorldContextObject, RoomId, InPauseResumeMediaType);
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcRoomResumeAllSubscribedStream(WorldContextObject, RoomId, InPauseResumeMediaType);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetAudioPlaybackDevice(WorldContextObject, InRtcAudioPlaybackDevice);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetAudioScenario(WorldContextObject, InRtcAudioScenarioType);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetCaptureVolume(WorldContextObject, InRtcStreamIndex, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetEarMonitorMode(WorldContextObject, InRtcEarMonitorMode);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetEarMonitorVolume(WorldContextObject, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcSetPlaybackVolume(WorldContextObject, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcStartAudioCapture(UObject* WorldContextObject)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcStartAudioCapture(WorldContextObject);
    }
}

void UOnlinePicoFunctionLibrary::RtcStopAudioCapture(UObject* WorldContextObject)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcStopAudioCapture(WorldContextObject);
    }
}

void UOnlinePicoFunctionLibrary::RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcUnPublishRoom(WorldContextObject, RoomId);
    }
}

void UOnlinePicoFunctionLibrary::RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->RtcUpdateToken(WorldContextObject, RoomId, Token);
    }
}

int32 UOnlinePicoFunctionLibrary::RtcSendStreamSyncInfo(UObject* WorldContextObject, int32 Info, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendStreamSyncInfo"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendStreamSyncInfo(Info, InStreamIndex, RepeatCount, InSyncInfoStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendStreamSyncInfo Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomPublishStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomPublishStream(RoomId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomPublishStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomSetRemoteAudioPlaybackVolume(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, int32 Volume)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomSetRemoteAudioPlaybackVolume"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomSetRemoteAudioPlaybackVolume(RoomId, UserId, Volume);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomSetRemoteAudioPlaybackVolume Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomSubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomSubscribeStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomSubscribeStream(RoomId, UserId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomSubscribeStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomUnPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomUnPublishStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomUnPublishStream(RoomId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomUnPublishStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomUnsubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomUnsubscribeStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomUnsubscribeStream(RoomId, UserId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomUnsubscribeStream Failed, RtcUserInterface Not Vailed!"));
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendRoomBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& MessageInfo)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendRoomBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendRoomBinaryMessage(RoomId, MessageInfo);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendRoomBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendRoomMessage(UObject* WorldContextObject, const FString& RoomId, const FString& Message)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendRoomMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendRoomMessage(RoomId, Message);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendRoomMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendUserBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& MessageInfo)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendUserBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendUserBinaryMessage(RoomId, UserId, MessageInfo);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendUserBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendUserMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Message)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendUserMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendUserMessage(RoomId, UserId, Message);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendUserMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

// Game
bool UOnlinePicoFunctionLibrary::IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    bool Valid = UpdatedSessionSettings.ValueArray.Num() == UpdatedSessionSettings.KeyArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSettingsDataStoreValid keys count != values count"));
    }
    return Valid;
}

bool UOnlinePicoFunctionLibrary::IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& SessionSearch)
{
    bool Valid = SessionSearch.QuerySettingsKeyArray.Num() == SessionSearch.QuerySettingsValueArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSearchQueryDataValid keys count != values count"));
    }
    return Valid;
}

FOnlineSessionSettings UOnlinePicoFunctionLibrary::GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    FOnlineSessionSettings SessionSettings;
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

FPicoOnlineSessionSettings UOnlinePicoFunctionLibrary::GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings)
{
    FPicoOnlineSessionSettings SessionSettings;
    SessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    SessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    SessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    SessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    SessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    SessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    SessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    for (auto& item : UpdatedSessionSettings.Settings)
    {
        SessionSettings.KeyArray.Add(*item.Key.ToString());
        SessionSettings.ValueArray.Add(*item.Value.Data.ToString());
    };
    return SessionSettings;
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::GetPicoOnlineSession(const FNamedOnlineSession& Session)
{
    FPicoNamedOnlineSession PicoSession;
    PicoSession.bHosting = Session.bHosting;
    PicoSession.SessionName = Session.SessionName.ToString();
    PicoSession.SessionSettings = GetPicoOnlineSessionSettings(Session.SessionSettings);
    PicoSession.SessionState = (EOnlineSessionStatePicoType)Session.SessionState;
    PicoSession.HostingPlayerNum = Session.HostingPlayerNum;
    if (Session.LocalOwnerId.IsValid())
    {
        PicoSession.LocalOwnerId = *Session.LocalOwnerId->ToString();
    }
    if (Session.OwningUserId.IsValid())
    {
        PicoSession.OwningUserId = *Session.OwningUserId->ToString();
    }
    PicoSession.OwningUserName = Session.OwningUserName;
    PicoSession.NumOpenPrivateConnections = Session.NumOpenPrivateConnections;
    PicoSession.NumOpenPublicConnections = Session.NumOpenPublicConnections;
    if (Session.SessionInfo.IsValid())
    {
        auto SessionInfoPtr = static_cast<const FOnlineSessionInfoPico*>(Session.SessionInfo.Get());
        PicoSession.SessionInfoRoomID = SessionInfoPtr->GetSessionId().ToString();
    }
    PicoSession.RegisteredPlayers.Reset();
    for (int i = 0; i < Session.RegisteredPlayers.Num(); i++)
    {
        //if (Session.RegisteredPlayers[i].IsValid()) // todo
        {
            PicoSession.RegisteredPlayers.Add(Session.RegisteredPlayers[i]->ToString());
        }
    }
    return PicoSession;
}

FOnlineSession UOnlinePicoFunctionLibrary::GetOnlineSession(const FPicoOnlineSession& PicoSession)
{
    FOnlineSession Session;
    Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(FCString::Strtoui64(*PicoSession.SessionInfoRoomID, NULL, 10)));
    Session.SessionSettings = GetOnlineSessionSettings(PicoSession.SessionSettings);
#if ENGINE_MAJOR_VERSION > 4
    Session.OwningUserId = FUniqueNetIdPico::Create(PicoSession.OwningUserId);
#elif ENGINE_MINOR_VERSION > 26
    Session.OwningUserId = FUniqueNetIdPico::Create(PicoSession.OwningUserId);
#elif ENGINE_MINOR_VERSION > 24
    Session.OwningUserId = MakeShareable(new FUniqueNetIdPico(PicoSession.OwningUserId));
#endif
    Session.OwningUserName = PicoSession.OwningUserName;
    Session.NumOpenPrivateConnections = PicoSession.NumOpenPrivateConnections;
    Session.NumOpenPublicConnections = PicoSession.NumOpenPublicConnections;
    return Session;
}

bool UOnlinePicoFunctionLibrary::CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        if (!IsInputSessionSettingsDataStoreValid(NewSessionSettings))
        {
            return false;
        }
        auto SessionSettings = GetOnlineSessionSettings(NewSessionSettings);
        return PicoSubsystemManager->CreateSession(WorldContextObject, HostingPlayerNum, SessionName, SessionSettings, OnCreateSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->StartSession(WorldContextObject, SessionName, OnStartSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::UpdateSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData)
{
    if (PicoSubsystemManager)
    {
        if (!IsInputSessionSettingsDataStoreValid(UpdatedSessionSettings))
        {
            return false;
        }
        auto SessionSettings = GetOnlineSessionSettings(UpdatedSessionSettings);
        return PicoSubsystemManager->UpdateSession(WorldContextObject, SessionName, SessionSettings, OnUpdateSessionCompleteDelegate, bShouldRefreshOnlineData);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->EndSession(WorldContextObject, SessionName, OnEndSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->DestroySession(WorldContextObject, SessionName, OnDestroySessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FString& UniqueId)
{
    if (PicoSubsystemManager)
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto NetId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(UniqueId).ToSharedRef();
        return PicoSubsystemManager->IsPlayerInSession(WorldContextObject, SessionName, NetId.Get());
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::StartMatchmaking(UObject* WorldContextObject, const TArray<FString>& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate)
{
    if (PicoSubsystemManager)
    {


        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        TArray<TSharedRef<const FUniqueNetId>> GameLocalPlayers;
        for (int i = 0; i < LocalPlayers.Num(); i++)
        {
            auto UniqueNetIdRef = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(LocalPlayers[i]).ToSharedRef();
            GameLocalPlayers.Add(UniqueNetIdRef);
        }
        return PicoSubsystemManager->StartMatchmaking(WorldContextObject, GameLocalPlayers, SessionName, NewSessionSettings, NewSessionSearch, OnMatchmakingCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::CancelMatchmaking(UObject* WorldContextObject, int SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->CancelMatchmaking(WorldContextObject, SearchingPlayerNum, SessionName, OnCancelMatchmakingCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->FindSessions(WorldContextObject, SearchingPlayerNum, NewSessionSearch, OnFindSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::FindSessionById(UObject* WorldContextObject, const FString& SearchingUserId, const FString& SessionId, FPicoManagerOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto SearchingUserIdPtr = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(SearchingUserId).ToSharedRef();
        auto SessionIdIdPtr = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(SessionId).ToSharedRef();
#if ENGINE_MAJOR_VERSION > 4
        FUniqueNetIdStringRef FriendId = FUniqueNetIdString::Create(FString(), FName("PicoSubsystem"));
        return PicoSubsystemManager->FindSessionById(WorldContextObject, SearchingUserIdPtr.Get(), SessionIdIdPtr.Get(), FriendId.Get(), OnSingleSessionResultCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 24
        FUniqueNetIdString FriendId = FUniqueNetIdString();
        return PicoSubsystemManager->FindSessionById(WorldContextObject, SearchingUserIdPtr.Get(), SessionIdIdPtr.Get(), FriendId, OnSingleSessionResultCompleteDelegate);
#endif

    }
    return false;
}

bool UOnlinePicoFunctionLibrary::JoinSession(UObject* WorldContextObject, int PlayerNum, FName SessionName, const FPicoOnlineSessionSearchResult& SearchResult, FPicoManagerOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        auto newSession = SearchResult.Session;
        FOnlineSessionSearchResult newResult;
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto OwningUserId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(newSession.OwningUserId).ToSharedRef();
        newResult.Session.OwningUserId = OwningUserId;
        newResult.Session.OwningUserName = newSession.OwningUserName;
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME FunctionLibrary JoinSession RoomID: %s"), *newSession.SessionInfoRoomID);
        ppfID RoomID = FCString::Strtoui64(*newSession.SessionInfoRoomID, NULL, 10);
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME FunctionLibrary JoinSession RoomID: %llu"), RoomID);
        newResult.Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomID));
        newResult.Session.SessionSettings = GetOnlineSessionSettings(newSession.SessionSettings);
        newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
        newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
        newResult.PingInMs = SearchResult.PingInMs;
        return PicoSubsystemManager->JoinSession(WorldContextObject, PlayerNum, SessionName, newResult, OnJoinSessionCompleteDelegate);
    }
    return false;
}

void UOnlinePicoFunctionLibrary::DumpSessionState(UObject* WorldContextObject)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->DumpSessionState(WorldContextObject);
    }
}

EOnlineSessionStatePicoType UOnlinePicoFunctionLibrary::GetSessionState(UObject* WorldContextObject, FName SessionName)
{
    if (PicoSubsystemManager)
    {
        return (EOnlineSessionStatePicoType)PicoSubsystemManager->GetSessionState(WorldContextObject, SessionName);
    }
    return EOnlineSessionStatePicoType::NoSession;
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::GetNamedSession(UObject* WorldContextObject, FName SessionName)
{
    if (PicoSubsystemManager)
    {
        auto SessionPtr = PicoSubsystemManager->GetNamedSession(WorldContextObject, SessionName);
        if (SessionPtr == nullptr)
            return FPicoNamedOnlineSession();
        return GetPicoOnlineSession(*SessionPtr);
    }
    return FPicoNamedOnlineSession();
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::AddNamedSessionBySettings(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& SessionSettings)
{
    if (PicoSubsystemManager)
    {
        return GetPicoOnlineSession(*PicoSubsystemManager->AddNamedSession(WorldContextObject, SessionName, GetOnlineSessionSettings(SessionSettings)));
    }
    return FPicoNamedOnlineSession();
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSession& Session)
{
    if (PicoSubsystemManager)
    {
        return GetPicoOnlineSession(*PicoSubsystemManager->AddNamedSession(WorldContextObject, SessionName, GetOnlineSession(Session)));
    }
    return FPicoNamedOnlineSession();
}

FPicoOnlineSessionSettings UOnlinePicoFunctionLibrary::GetSessionSettings(UObject* WorldContextObject, FName SessionName)
{
    if (PicoSubsystemManager)
    {
        FOnlineSessionSettings* Settings = PicoSubsystemManager->GetSessionSettings(WorldContextObject, SessionName);
        return GetPicoOnlineSessionSettings(*Settings);
    }
    return FPicoOnlineSessionSettings();
}

bool UOnlinePicoFunctionLibrary::SendSessionInviteToFriend(UObject* WorldContextObject, int32 LocalUserNum, FName SessionName, const FString& Friend)
{
    if (PicoSubsystemManager)
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto ID = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Friend).ToSharedRef();
        return PicoSubsystemManager->SendSessionInviteToFriend(WorldContextObject, LocalUserNum, SessionName, ID.Get());
    }
    return false;
}

// Presence
bool UOnlinePicoFunctionLibrary::PresenceClear(UObject* WorldContextObject, FOnlineManagerPresenceClearDelegate InPresenceClearDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceClear(WorldContextObject, InPresenceClearDelegate);
    }
    return false;
}

void UOnlinePicoFunctionLibrary::ReadInvitableUser(UObject* WorldContextObject, TArray<FString> SuggestedUserList, FOnlineManagerPresenceReadInvitableUserDelegate InReadInvitableUserDelegate)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->ReadInvitableUser(WorldContextObject, SuggestedUserList, InReadInvitableUserDelegate);
    }
}

bool UOnlinePicoFunctionLibrary::GetInvitableFriendList(UObject* WorldContextObject, TArray<FPicoUserInfo>& OutFriendsList)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->GetInvitableFriendList(WorldContextObject, OutFriendsList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSet(UObject* WorldContextObject, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, FOnlineManagerPresenceSetDelegate InPresenceSetDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSet(WorldContextObject, ApiName, LobbySessionId, MatchSessionId, bIsJoinable, Extra, InPresenceSetDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetDestination(UObject* WorldContextObject, const FString& ApiName, FOnlineManagerPresenceSetDestinationDelegate InPresenceSetDestinationDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSetDestination(WorldContextObject, ApiName, InPresenceSetDestinationDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetIsJoinable(UObject* WorldContextObject, bool bIsJoinable, FOnlineManagerPresenceSetIsJoinableDelegate InPresenceSetIsJoinableDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSetIsJoinable(WorldContextObject, bIsJoinable, InPresenceSetIsJoinableDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetLobbySession(UObject* WorldContextObject, const FString& LobbySession, FOnlineManagerPresenceSetLobbySessionDelegate InPresenceSetLobbySessionDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSetLobbySession(WorldContextObject, LobbySession, InPresenceSetLobbySessionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetMatchSession(UObject* WorldContextObject, const FString& MatchSession, FOnlineManagerPresenceSetMatchSessionDelegate InPresenceSetMatchSessionDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSetMatchSession(WorldContextObject, MatchSession, InPresenceSetMatchSessionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetExtra(UObject* WorldContextObject, const FString& Extra, FOnlineManagerPresenceSetExtraDelegate InPresenceSetExtraDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSetExtra(WorldContextObject, Extra, InPresenceSetExtraDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceReadSendInvites(UObject* WorldContextObject, FOnlineManagerPresenceReadSentInvitesDelegate InPresenceReadSendInvitesDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceReadSendInvites(WorldContextObject, InPresenceReadSendInvitesDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSendInvites(UObject* WorldContextObject, TArray<FString> UserIdArray, FOnlineManagerPresenceSentInvitesDelegate InPresenceSentInvitesDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceSendInvites(WorldContextObject, UserIdArray, InPresenceSentInvitesDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetSendInvitesList(UObject* WorldContextObject, TArray<FPicoApplicationInvite>& OutList)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->GetSendInvitesList(WorldContextObject, OutList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceGetDestinations(UObject* WorldContextObject, FOnlineManagerPresenceGetDestinationsDelegate InPresenceGetDestinationsDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceGetDestinations(WorldContextObject, InPresenceGetDestinationsDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceGetDestinationsList(UObject* WorldContextObject, TArray<FPicoDestination>& OutList)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->PresenceGetDestinationsList(WorldContextObject, OutList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchInvitePanel(UObject* WorldContextObject, FOnlineManagerLaunchInvitePanelDelegate InLaunchInvitePanelDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->LaunchInvitePanel(WorldContextObject, InLaunchInvitePanelDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::ShareMedia(UObject* WorldContextObject, EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, FOnlineManagerShareMediaDelegate InShareMediaDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->ShareMedia(WorldContextObject, InMediaType, InVideoPath, InVideoThumbPath, InImagePaths, InShareType, InShareMediaDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherApp(UObject* WorldContextObject, const FString& PackageName, const FString& Message, FOnlineManagerLaunchOtherAppDelegate InLaunchOtherAppDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->LaunchOtherApp(WorldContextObject, PackageName, Message, InLaunchOtherAppDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetVersion(UObject* WorldContextObject, FOnlineManagerGetVersionDelegate InGetVersionDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->GetVersion(WorldContextObject, InGetVersionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherAppByPresence(UObject* WorldContextObject, const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, FOnlineManagerLaunchOtherAppByPresenceDelegate InLaunchOtherAppByPresenceDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->LaunchOtherAppByPresence(WorldContextObject, AppID, PackageName, Message, ApiName, LobbySessionId, MatchSessionId, TrackId, Extra, InLaunchOtherAppByPresenceDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherAppByAppId(UObject* WorldContextObject, const FString& AppId, const FString& Message, FOnlineManagerLaunchOtherAppByAppIdDelegate InLaunchOtherAppByAppIdDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->LaunchOtherAppByAppId(WorldContextObject, AppId, Message, InLaunchOtherAppByAppIdDelegate);
    }
    return false;
}
bool UOnlinePicoFunctionLibrary::GetLaunchDetails(UObject* WorldContextObject, FLaunchDetails& OutLaunchDetails)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->GetLaunchDetails(WorldContextObject, OutLaunchDetails);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LogDeeplinkResult(UObject* WorldContextObject, const FString& TrackingID, ELaunchResult LaunchResult)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->LogDeeplinkResult(WorldContextObject, TrackingID, LaunchResult);
    }
    return false;
}

void UOnlinePicoFunctionLibrary::PicoEntitlementVerifyAppDelegate(FOnlinePicoVerifyAppDelegate OnVerifyAppCallback)
{
#if PLATFORM_ANDROID
    VerifyAppDelegate = OnVerifyAppCallback;
    if (GetDefault <UOnlinePicoSettings>()->bStartTimeEntitlementCheck)
    {
        if (VerifyAppCode != 1)
        {
            VerifyAppDelegate.Execute(VerifyAppCode);
        }
    }
#endif
}

void UOnlinePicoFunctionLibrary::PicoEntitlementVerifyCheck()
{
    if (GetDefault <UOnlinePicoSettings>()->bStartTimeEntitlementCheck)
    {
        if (GetDefault <UOnlinePicoSettings>()->bEntitlementCheckSimulation)
        {
            FString DeviceSN = PicoGetDeviceSN();
            if (GetDefault <UOnlinePicoSettings>()->DeviceSN.Num() > 0)
            {
                for (int i = 0; i < GetDefault <UOnlinePicoSettings>()->DeviceSN.Num(); i++)
                {
                    if (GetDefault <UOnlinePicoSettings>()->DeviceSN[i] == DeviceSN)
                    {
                        return;
                    }
                }
            }
        }

        FString PublicKey = "";
        FString AppID = GetDefault <UOnlinePicoSettings>()->EntitlementCheckAppID;
        if (AppID == "")
        {
            UE_LOG(LogTemp, Log, TEXT("APPID is required for Entitlement Check. Create / Find your APP ID on https://developer.pico-interactive.com/developer/overview."));
        }
#if PLATFORM_ANDROID
        if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
        {
            jstring j_appID = Env->NewStringUTF(TCHAR_TO_UTF8(*AppID));
            jstring j_publicKey = Env->NewStringUTF(TCHAR_TO_UTF8(*PublicKey));
            static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_VerifyApp", "(Ljava/lang/String;Ljava/lang/String;)I", false);
            if (Method)
            {
                FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, j_appID, j_publicKey);
            }
            Env->DeleteLocalRef(j_appID);
            Env->DeleteLocalRef(j_publicKey);
        }
#endif
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("EntitlementCheck is highly recommended which can protect the copyright of app. You can enable it when App start-up in the Inspector of \"Edit->Plugins->PicoMobile->Platform\" and Enter your APPID. If you want to call the APIs as needed, please refer to the development Document."));
    }
}

FString UOnlinePicoFunctionLibrary::PicoGetDeviceSN()
{
    FString DeviceSN = "";
#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OnlineGetDeviceSN", "()Ljava/lang/String;", false);
        jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
        if (JavaString != NULL)
        {
            const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
            DeviceSN = FString(UTF8_TO_TCHAR(JavaChars));
            Env->ReleaseStringUTFChars(JavaString, JavaChars);
            Env->DeleteLocalRef(JavaString);
        }
    }
#endif
    return DeviceSN;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCVerifyCallback(JNIEnv * env, jclass clazz, int32 code)
{
    UOnlinePicoFunctionLibrary::VerifyAppCode = code;
    if (UOnlinePicoFunctionLibrary::VerifyAppDelegate.IsBound())
    {
        UOnlinePicoFunctionLibrary::VerifyAppDelegate.Execute(code);
    }
}
#endif

// Leaderboard
bool UOnlinePicoFunctionLibrary::ReadLeaderboards(UObject* WorldContextObject, const TArray<FString>& Players, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        // Players
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        TArray<TSharedRef<const FUniqueNetId>> LeaderboardPlayers;
        for (int i = 0; i < Players.Num(); i++)
        {
            UE_LOG_ONLINE_LEADERBOARD(Display, TEXT("PPF_GAME Library ReadLeaderboards Players[%d]: %s"), i, *Players[i]);
            auto UniqueNetIdRef = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Players[i]).ToSharedRef();
            LeaderboardPlayers.Add(UniqueNetIdRef);
        }
        return PicoSubsystemManager->ReadLeaderboards(WorldContextObject, LeaderboardPlayers, PicoReadObject, OnReadLeaderboardsCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::ReadLeaderboardsForFriends(UObject* WorldContextObject, int32 LocalUserNum, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate)
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager->ReadLeaderboardsForFriends(WorldContextObject, LocalUserNum, PicoReadObject, OnReadLeaderboardsCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::WriteLeaderboards(UObject* WorldContextObject, const FString& SessionName, const FString& Player, UPARAM(ref)FPicoOnlineLeaderboardWrite& PicoWriteObject)
{
    if (PicoSubsystemManager)
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        UE_LOG_ONLINE_LEADERBOARD(Display, TEXT("PPF_GAME Library WriteLeaderboards begin"));
        auto LeaderboardPlayer = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Player).ToSharedRef();

        TSharedPtr<FOnlineLeaderboardWrite, ESPMode::ThreadSafe> PicoWritePtr = MakeShareable(new Pico_OnlineLeaderboardWrite(PicoWriteObject.LeaderboardNames));
        PicoWritePtr->UpdateMethod = (ELeaderboardUpdateMethod::Type)PicoWriteObject.UpdateMethod;
        PicoWritePtr->RatedStat = FName(PicoWriteObject.RatedStat);
        PicoWritePtr->SetIntStat(PicoWritePtr->RatedStat, PicoWriteObject.ValueToWrite);
        TSharedRef<FOnlineLeaderboardWrite, ESPMode::ThreadSafe> PicoWriteRef = PicoWritePtr.ToSharedRef();

        return PicoSubsystemManager->WriteLeaderboards(WorldContextObject, FName(SessionName), LeaderboardPlayer.Get(), PicoWriteRef.Get());
    }
    return false;
}


