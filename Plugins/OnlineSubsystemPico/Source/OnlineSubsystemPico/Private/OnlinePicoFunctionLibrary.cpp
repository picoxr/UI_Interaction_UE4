// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "OnlinePicoFunctionLibrary.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystem.h"
#include "OnlinePicoSettings.h"

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

void UOnlinePicoFunctionLibrary::PicoGetFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, TArray<FPicoFriend>& OutFriends)
{
    if (PicoSubsystemManager)
    {
        PicoSubsystemManager->PicoGetFriendList(WorldContextObject, LocalUserNum, ListName, OutFriends);
    }
}

FPicoFriend UOnlinePicoFunctionLibrary::PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName)
{
    FPicoFriend NewFriend;
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

UOnlineSubsystemPicoManager* UOnlinePicoFunctionLibrary::GetOnlineSubsystemPicoManager()
{
    if (PicoSubsystemManager)
    {
        return PicoSubsystemManager;
    }
    return nullptr;
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
    PicoSession.LocalOwnerId = *Session.LocalOwnerId->ToString();
    PicoSession.OwningUserId = *Session.OwningUserId->ToString();
    PicoSession.OwningUserName = Session.OwningUserName;
    PicoSession.NumOpenPrivateConnections = Session.NumOpenPrivateConnections;
    PicoSession.NumOpenPublicConnections = Session.NumOpenPublicConnections;
	auto SessionInfo = static_cast<const FOnlineSessionInfoPico*>(Session.SessionInfo.Get());
    PicoSession.SessionInfoRoomID = SessionInfo->GetSessionId().ToString();
    return PicoSession;
}
FOnlineSession UOnlinePicoFunctionLibrary::GetOnlineSession(const FPicoOnlineSession& PicoSession)
{
    FOnlineSession Session;
    Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(FCString::Strtoui64(*PicoSession.SessionInfoRoomID, NULL, 10)));
    Session.SessionSettings = GetOnlineSessionSettings(PicoSession.SessionSettings);
    Session.OwningUserId = FUniqueNetIdPico::Create(PicoSession.OwningUserId);
    Session.OwningUserName = PicoSession.OwningUserName;
    Session.NumOpenPrivateConnections = PicoSession.NumOpenPrivateConnections;
    Session.NumOpenPublicConnections = PicoSession.NumOpenPublicConnections;
    return Session;
}
TSharedPtr<FOnlineSessionSearch> UOnlinePicoFunctionLibrary::GetOnlineSessionSearch(const FPicoOnlineSessionSearch& SessionSearch)
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
bool UOnlinePicoFunctionLibrary::StartMatchmaking(UObject* WorldContextObject, const TArray<FString>& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, const FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate)
{
	if (PicoSubsystemManager)
	{
	    if (!IsInputSessionSettingsDataStoreValid(NewSessionSettings))
	    {
	        return false;
	    }
	    auto SessionSettings = GetOnlineSessionSettings(NewSessionSettings);
	    if (!IsInputSessionSearchQueryDataValid(NewSessionSearch))
	    {
	        return false;
	    }
        TSharedRef<FOnlineSessionSearch> SearchSettingsRef = GetOnlineSessionSearch(NewSessionSearch).ToSharedRef();
	    IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        TArray<TSharedRef<const FUniqueNetId>> GameLocalPlayers;
	    for (int i = 0; i < LocalPlayers.Num(); i++)
	    {
	        auto UniqueNetIdRef = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(LocalPlayers[i]).ToSharedRef();
	        GameLocalPlayers.Add(UniqueNetIdRef);
	    }
		return PicoSubsystemManager->StartMatchmaking(WorldContextObject, GameLocalPlayers, SessionName, SessionSettings, SearchSettingsRef, OnMatchmakingCompleteDelegate);
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
bool UOnlinePicoFunctionLibrary::FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, const FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate)
{
	if (PicoSubsystemManager)
	{
	    if (!IsInputSessionSearchQueryDataValid(NewSessionSearch))
	    {
	        return false;
	    }
        TSharedRef<FOnlineSessionSearch> SearchSettingsRef = GetOnlineSessionSearch(NewSessionSearch).ToSharedRef();
		return PicoSubsystemManager->FindSessions(WorldContextObject, SearchingPlayerNum, SearchSettingsRef, OnFindSessionCompleteDelegate);
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
	    FUniqueNetIdString FriendId = FUniqueNetIdString();
		return PicoSubsystemManager->FindSessionById(WorldContextObject, SearchingUserIdPtr.Get(), SessionIdIdPtr.Get(), FriendId, OnSingleSessionResultCompleteDelegate);
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
        return GetPicoOnlineSession(*PicoSubsystemManager->GetNamedSession(WorldContextObject, SessionName));
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

FString UOnlinePicoFunctionLibrary::GetOpenId()
{
    FString ret = FString("");
#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetOpenID", "()Ljava/lang/String;", false);
        jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
        if (JavaString != NULL)
        {
            const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
            ret = FString(UTF8_TO_TCHAR(JavaChars));
            Env->ReleaseStringUTFChars(JavaString, JavaChars);
            Env->DeleteLocalRef(JavaString);
}
    }
#endif
    return ret;
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


