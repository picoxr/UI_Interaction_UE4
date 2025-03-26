// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "RTCPicoUserInterface.h"
#include "OnlineSessionSettings.h"
#include "UObject/Object.h"
#include "Interfaces/OnlineFriendsInterface.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "PicoPresenceInterface.h"
#include "PicoApplicationInterface.h"
#include "ApplicationLifecycleInterface.h"
#include "Pico_AssetFile.h"
#include "Pico_User.h"
#include "Pico_Speech.h"
#include "Pico_Highlight.h"
#include "OnlineSubsystemPicoManager.generated.h"
/**
 * 
 */



// Identity
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnlineManagerLoginCompleteDelegate, int, LocalUserNum, const FString, UserId, bool, bIsSuccessed, const FString, ErrorMessage);

// Friend
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnlineManagerReadFriendListDelegate, int, LocalUserNum, bool, bWasSuccessful, const FString, ListName, const FString, ErrorStr);

// RTC
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams(FRtcJoinRoomResultDelegate, UOnlineSubsystemPicoManager, OnRtcJoinRoomResultDelegate, const FString&, RoomId, const FString&, UserId, int, ErrorCode, int, Elapsed, ERtcJoinRoomType, InJoinRoomType);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcLeaveRoomResultDelegate, UOnlineSubsystemPicoManager, OnRtcLeaveRoomResultDelegate, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcRoomStateDelegate, UOnlineSubsystemPicoManager, OnRtcRoomStateDelegate, int, TotalDuration, int, UserCount, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FRtcUserJoinInfoDelegate, UOnlineSubsystemPicoManager, OnRtcUserJoinInfoDelegate, const FString&, UserId, const FString&, UserExtra, int, Elapsed, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcUserLeaveInfoDelegate, UOnlineSubsystemPicoManager, OnRtcUserLeaveInfoDelegate, const FString&, UserId, ERtcUserLeaveReasonType, RtcUserLeaveReasonType, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FRtcRoomWarnDelegate, UOnlineSubsystemPicoManager, OnRtcRoomWarnDelegate, int, Code, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FRtcRoomErrorDelegate, UOnlineSubsystemPicoManager, OnRtcRoomErrorDelegate, int, Code, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FRtcRoomMuteStateDelegate, UOnlineSubsystemPicoManager, OnRtcRoomMuteStateDelegate, const FString&, UserId, ERtcMuteState, RtcMuteState);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcAudioChangePlaybackDeviceDelegate, UOnlineSubsystemPicoManager, OnRtcAudioChangePlaybackDelegate, ERtcAudioPlaybackDevice, RtcAudioPlaybackDevice);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FRtcMediaDeviceChangeInfoDelegate, UOnlineSubsystemPicoManager, OnRtcMediaDeviceChangeInfoDelegate, const FString&, DeviceId, ERtcMediaDeviceType, MediaDeciveType, ERtcMediaDeviceState, MediaDeviceState, ERtcMediaDeviceError, MediaDeviceError);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FRtcLocalAudioPropertiesReportDelegate, UOnlineSubsystemPicoManager, OnRtcLocalAudioPropertiesReportDelegate, const TArray<ERtcStreamIndex>&, StreamIndexs, const TArray<int32>&, Volumes);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams(FRtcRemoteAudioPropertiesReportDelegate, UOnlineSubsystemPicoManager, OnRtcRemoteAudioPropertiesReportDelegate, int, TotalRemoteVolume, const TArray<int32>&, Volumes, const TArray<FString>&, RoomIds, const TArray<FString>&, UserIds, const TArray<ERtcStreamIndex>&, StreamIndexs);

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcWarnDelegate, UOnlineSubsystemPicoManager, OnRtcWarnDelegate, int, MessageCode);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcErrorDelegate, UOnlineSubsystemPicoManager, OnRtcErrorDelegate, int, MessageCode);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcConnectStateChangedDelegate, UOnlineSubsystemPicoManager, OnRtcConnectStateChangedDelegate, const FString&, StringMessage);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcUserStartAudioCaptureDelegate, UOnlineSubsystemPicoManager, OnRtcUserStartAudioCaptureDelegate, const FString&, StringMessage);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcUserStopAudioCaptureDelegate, UOnlineSubsystemPicoManager, OnRtcUserStopAudioCaptureDelegate, const FString&, StringMessage);

// Rtc V2
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcUserPublishInfoDelegate, UOnlineSubsystemPicoManager, OnRtcUserPublishInfoDelegate, const FString&, RoomId, const FString&, UserId, ERtcMediaStreamType, MediaStreamType);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FRtcUserUnPublishInfoDelegate, UOnlineSubsystemPicoManager, OnRtcUserUnPublishInfoDelegate, const FString&, RoomId, const FString&, UserId, ERtcMediaStreamType, MediaStreamType, ERtcStreamRemoveReason, Reason);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams(FGetRtcStreamSyncInfoDelegate, UOnlineSubsystemPicoManager, OnGetRtcStreamSyncInfoDelegate, const FString&, RoomId, const FString&, UserId, ERtcStreamIndex, StreamIndex, ERtcSyncInfoStreamType, RtcSyncInfoStreamType, const FString&, Info);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcMessageSendResultDelegate, UOnlineSubsystemPicoManager, OnRtcMessageSendResultDelegate, int64, MessageId, int32, Error, const FString&, RoomId);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcBinaryMessageReceivedDelegate, UOnlineSubsystemPicoManager, OnRtcBinaryMessageReceivedDelegate, const FString&, RoomId, const FString&, UserId, const FString&, Info);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcBinaryArrayMessageReceivedDelegate, UOnlineSubsystemPicoManager, OnRtcBinaryArrayMessageReceivedDelegate, const FString&, RoomId, const FString&, UserId, TArray<uint8>, BinaryArray);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcRoomMessageReceivedDelegate, UOnlineSubsystemPicoManager, OnRtcRoomMessageReceivedDelegateDelegate, const FString&, RoomId, const FString&, UserId, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FRtcUserMessageReceivedDelegate, UOnlineSubsystemPicoManager, OnRtcUserMessageReceivedDelegate, const FString&, RoomId, const FString&, UserId, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FRtcOnTokenWilExpireCallbackDelegate, UOnlineSubsystemPicoManager, OnRtcTokenWilExpireCallbackDelegate, const FString&, StringMessage);


DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerRtcGetTokenDelegate, FString, Token, bool, IsSuccessed, FString, ErrorMessage);

// Presence
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceClearDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceReadInvitableUserDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetDestinationDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetIsJoinableDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetLobbySessionDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetMatchSessionDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSetExtraDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceReadSentInvitesDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceSentInvitesDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerPresenceGetDestinationsDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerLaunchInvitePanelDelegate, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerShareMediaDelegate, bool, IsSuccessed, FString, ErrorMessage);


DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FiveParams(FPresenceJoinIntentReceivedDelegate, UOnlineSubsystemPicoManager, OnPresenceJoinIntentReceivedDelegate, const FString&, DeeplinkMessage, const FString&, DestinationApiName, const FString&, LobbySessionId, const FString&, MatchSessionId, const FString&, Extra);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FPresenceLeaveIntentReceivedDelegate, UOnlineSubsystemPicoManager, OnPresenceLeaveIntentReceivedDelegate, const FString&, DestinationApiName, const FString&, LobbySessionId, const FString&, MatchSessionId);

// ApplicationInterface
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerLaunchOtherAppDelegate, FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerLaunchOtherAppByPresenceDelegate, FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_SixParams(FOnlineManagerGetVersionDelegate, int64, CurrentCode, FString, CurrentName, int64, LatestCode, FString, LatestName, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerLaunchOtherAppByAppIdDelegate, FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerLaunchStoreDelegate, FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage);

// ApplicationLifecycle
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlineManagerApplicationLifecycleReadDetailsDelegate, bool, IsSuccessed, FString, ErrorMessage);


DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FApplicationLifecycleStringResultDelegate, UOnlineSubsystemPicoManager, OnApplicationLifecycleStringResultDelegate, const FString&, MessageString);


// Game
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnCreateSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnStartSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnUpdateSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnEndSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnDestroySessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnCancelMatchmakingCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnMatchmakingCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoManagerOnFindSessionCompleteDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FPicoManagerOnSingleSessionResultCompleteDelegate, int32, LocalUserNum, bool, bWasSuccessful, const FPicoOnlineSessionSearchResult&, SearchResult);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnJoinSessionCompleteDelegate, FName, SessionName, EOnJoinSessionCompleteResultPicoType, Type);

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FOnGameInitializeCallbackDelegate, UOnlineSubsystemPicoManager, OnGameInitializeCallbackDelegate, bool, bWasSuccessful, int, ErrorCode, const FString&, ErrorMessage, int, Result);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnGameConnectionNotifyDelegate, UOnlineSubsystemPicoManager, OnGameConnectionNotifyDelegate, int, Result, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnGameRequestFailedNotifyDelegate, UOnlineSubsystemPicoManager, OnGameRequestFailedNotifyDelegate, int, Result, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnGameStateResetNotifyDelegate, UOnlineSubsystemPicoManager, OnGameStateResetNotifyDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnMatchmakingCancel2NotifyDelegate, UOnlineSubsystemPicoManager, OnMatchmakingCancel2NotifyDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomLeaveNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomLeaveNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomJoin2NotifyDelegate, UOnlineSubsystemPicoManager, OnRoomJoin2NotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomSetDescriptionNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomSetDescriptionNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomKickUserNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomKickUserNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnRoomUpdateOwnerNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomUpdateOwnerNotifyDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomUpdateDataStoreNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomUpdateDataStoreNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomUpdateMembershipLockStatusNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomUpdateMembershipLockStatusNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomInviteAcceptedNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomInviteAcceptedNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FOnRoomUpdateNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomUpdateNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FOnMatchmakingFoundNotifyDelegate, UOnlineSubsystemPicoManager, OnMatchmakingFoundNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful, int, ErrorCode, const FString&, ErrorMessage);

// Leaderboard
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoManagerOnReadLeaderboardsCompleteDelegate, bool, bWasSuccessful);

// AssetFile
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FAssetFileDownloadUpdateDelegate, UOnlineSubsystemPicoManager, OnAssetFileDownloadUpdateDelegate, UPico_AssetFileDownloadUpdate*, AssetFileDownloadUpdateObj);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FAssetFileDeleteForSafetyDelegate, UOnlineSubsystemPicoManager, OnAssetFileDeleteForSafetyDelegate, UPico_AssetFileDeleteForSafety*, AssetFileDeleteForSafetyObj);

// Speech
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FSpeechAsrResultDelegate, UOnlineSubsystemPicoManager, OnSpeechAsrResultDelegate, UPico_AsrResult*, AsrResultObj);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FSpeechErrorDelegate, UOnlineSubsystemPicoManager, OnSpeechErrorDelegate, UPico_SpeechError*, SpeechErrorObj);

// Highlight
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FHighlightRecordStopDelegate, UOnlineSubsystemPicoManager, OnHighlightRecordStopDelegate, UPico_RecordInfo*, RecordInfoObj);

// Pico_Room
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoRoomUpdateNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoRoomUpdateNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FPicoRoomUpdateOwnerNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoRoomUpdateOwnerNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoRoomLeaveNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoRoomLeaveNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoRoomJoinNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoRoomJoinNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoRoomInviteAcceptedNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoRoomInviteAcceptedNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, const FString&, RoomID);
// Pico_Matchmaking
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FPicoMatchmakingCancelNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoMatchmakingCancelNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoMatchmakingMatchFoundNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoMatchmakingMatchFoundNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
// Pico_Challenges
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_FourParams(FPicoChallengeInviteAcceptedOrLaunchAppNotifyDelegate, UOnlineSubsystemPicoManager, OnPicoChallengeInviteAcceptedOrLaunchAppNotifyDelegate, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, const FString&, ChallengeID);



UCLASS(BlueprintType, Within = GameInstanceSubsystem)
class UOnlineSubsystemPicoManager : public UObject
{
    GENERATED_BODY()

public:
	UOnlineSubsystemPicoManager();
	~UOnlineSubsystemPicoManager();


	FOnReadFriendsListComplete ReadCompleteDelegate;

    TSharedPtr<FRTCPicoUserInterface> RtcInterface;
    TSharedPtr<FPicoPresenceInterface> PresenceInterface;
    TSharedPtr<FPicoAssetFileInterface> PicoAssetFileInterface;
    TSharedPtr<FPicoHighlightInterface> PicoHighlightInterface;
	TSharedPtr<FPicoRoomInterface> PicoRoomInterface;
	TSharedPtr<FPicoMatchmakingInterface> PicoMatchmakingInterface;
	TSharedPtr<FPicoChallengesInterface> PicoChallengesInterface;
    TSharedPtr<FPicoSpeechInterface> PicoSpeechInterface;

    FOnGetTokenComplete RtcGetTokenCompleteDelegate;
    // Presence
    FOnPresenceClearComplete PresenceClearCompleteDelegate;
    FOnReadInvitableUserComplete PresenceReadInvitableUserCompleteDelegate;
    FOnPresenceSetComplete PresenceSetCompleteDelegate;
    FOnPresenceSetDestinationComplete PresenceSetDestinationCompleteDelegate;
    FOnPresenceSetIsJoinableComplete PresenceSetIsJoinableCompleteDelegate;
    FOnPresenceSetLobbySessionComplete PresenceSetLobbySessionCompleteDelegate;
    FOnPresenceSetMatchSessionComplete PresenceSetMatchSessionCompleteDelegate;
    FOnPresenceSetPresenceExtraComplete PresenceSetExtraCompleteDelegate;
    FOnReadSentInvitesComplete PresenceReadSentInvitesCompleteDelegate;
    FOnSentInvitesComplete PresenceSentInvitesCompleteDelegate;
    FOnGetDestinationsComplete PresenceGetDestinationsCompleteDelegate;
    FOnLaunchInvitePanelComplete LaunchInvitePanelCompleteDelegate;
    FOnShareMediaComplete SharedMediaCompleteDelegate;

    // Application
    FOnLaunchOtherAppComplete LaunchOtherAppCompleteDelegate;
    FOnLaunchOtherAppByAppIdComplete LaunchOtherAppByAppIdCompleteDelegate;
    FOnLaunchOtherAppByPresenceComplete LaunchOtherAppByPresenceCompleteDelegate;
    FOnGetVersionComplete GetVersionCompleteDelegate;
    FOnLaunchStoreComplete LaunchStoreCompleteDelegate;

    // ApplicationLifecycle
    //FOnReadDetailsComplete ApplicationLifecycleReadDetailsCompleteDelegate;

    FOnlineSessionPicoPtr GameInterface;

    // Friend
	static FOnlineManagerReadFriendListDelegate ReadFrendListDelegate;

	void PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate);
    void OnReadListComplete(int32 InLocalUserNum/*LocalUserNum*/, bool bWasSuccessful/*bWasSuccessful*/, const FString& ListName/*ListName*/, const FString& ErrorStr/*ErrorStr*/);
    void PicoGetFriendList(UObject* WorldContextObject, int32 InLocalUserNum, const FString& ListName, TArray<FPicoUserInfo>& OutFriendList);
    FPicoUserInfo PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName);
    FPicoUserInfo GetBPPicoFriend(const TSharedRef<FOnlinePicoFriend> InOnlinePicoFriend);

    // Identity
    static FOnlineManagerLoginCompleteDelegate LoginCompleteDelegate;

    void PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& InUserId, const FString& InType, const FString& InToken, FOnlineManagerLoginCompleteDelegate InLoginCompleteDelegate);
    FString PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum);
    UPico_User* GetLoginPicoUser(UObject* WorldContextObject, int32 LocalUserNum);
    void OnLoginComplete(int LocalUserNum, bool bWasSuccessful,const FUniqueNetId& UserId, const FString& ErrorString);
    // Rtc

    // RTC Function
    static FOnlineManagerRtcGetTokenDelegate RtcGetTokenDelegate;

    void PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate);
    void OnGetTokenComplete(const FString& Token, bool bIsSuccessed, const FString& ErrorMessage);

    ERtcEngineInitResult PicoRtcEngineInit(UObject* WorldContextObject);
    int RtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio);
    int RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId);
    void RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval);
    int RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId);
    void RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState);
    void RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId);
    void RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);
    void RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);
    void RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice);
    void RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType);
    void RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume);
    void RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode);
    void RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume);
    void RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume);
    void RtcStartAudioCapture(UObject* WorldContextObject);
    void RtcStopAudioCapture(UObject* WorldContextObject);
    void RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId);
    void RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token);

    //RTC Notify React
    void OnRtcJoinRoomResult(const FString& RoomId, const FString& UserId, int ErrorCode, int Elapsed, ERtcJoinRoomType InJoinRoomType);
    void OnRtcLeaveRoomResult(const FString& RoomId);
    void OnRtcRoomState(int TotalDuration, int UserCount, const FString& RoomId);
    void OnRtcUserJoinInfo(const FString& UserId, const FString& UserExtra, int Elapsed, const FString& RoomId);
    void OnRtcUserLeaveInfo(const FString& UserId, ERtcUserLeaveReasonType RtcUserLeaveReasonType, const FString& RoomId);
    void OnRtcRoomWarn(int Code, const FString& RoomId);
    void OnRtcRoomError(int Code, const FString& RoomId);
    void OnRtcMuteState(const FString& UserId, ERtcMuteState RtcMuteState);
    void OnRtcAudioChangePlaybackDevice(ERtcAudioPlaybackDevice RtcAudioPlaybackDevice);
    void OnRtcMediaDeviceChangeInfo(const FString& DeviceId, ERtcMediaDeviceType MediaDeciveType, ERtcMediaDeviceState MediaDeviceState, ERtcMediaDeviceError MediaDeviceError);
    void OnRtcLocalAudioPropertiesReport(TArray<ERtcStreamIndex> StreamIndexs, TArray<int> Volumes);
    void OnRtcRemoteAudioPropertiesReport(int TotalRemoteVolume, TArray<int> Volumes, const TArray<FString>& RoomIds, const TArray<FString>& UserIds, TArray<ERtcStreamIndex> StreamIndexs);
    void OnRtcWarn(int MessageCode);
    void OnRtcError(int MessageCode);
    void OnRtcConnectStateChanged(const FString& StringMessage);
    void OnRtcUserStartAudioCapture(const FString& StringMessage);
    void OnRtcUserStopAudioCapture(const FString& StringMessage);

    // Rtc V2
    void OnRtcUserPublishInfo(const FString& RoomId, const FString& UserId, ERtcMediaStreamType MediaStreamType);
    void OnRtcUserUnPublishInfo(const FString& RoomId, const FString& UserId, ERtcMediaStreamType MediaStreamType, ERtcStreamRemoveReason Reason);
    void OnGetRtcStreamSyncInfo(const FString& RoomId, const FString& UserId, ERtcStreamIndex StreamIndex, ERtcSyncInfoStreamType RtcSyncInfoStreamType, const FString& Info);
    void OnRtcMessageSendResult(int64 MessageId, int32 Error, const FString& RoomId);
    void OnRtcBinaryMessageReceived(const FString& RoomId, const FString& UserId, const FString& Info);
    void OnRtcBinaryArrayMessageReceived(const FString& RoomId, const FString& UserId, TArray<uint8> BinaryArray);
    void OnRtcRoomMessageReceived(const FString& RoomId, const FString& UserId, const FString& Message);
    void OnRtcUserMessageReceived(const FString& RoomId, const FString& UserId, const FString& Message);
    void OnRtcTokenWilExpire(const FString& Message);


    //Presence Notify React
    void OnPresenceJoinIntentReceivedResult(const FString& DeeplinkMessage, const FString& DestinationApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& Extra);
    void OnPresenceLeavententReceivedResult(const FString& DestinationApiName, const FString& LobbySessionId, const FString& MatchSessionId);

    //ApplicationLifecycle Notify React
    void OnLaunchIntentChangedResult(const FString& MessageString);


    // RTC Notification Delegate
    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcJoinRoomResultDelegate OnRtcJoinRoomResultDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcLeaveRoomResultDelegate OnRtcLeaveRoomResultDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRoomStateDelegate OnRtcRoomStateDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserJoinInfoDelegate OnRtcUserJoinInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserLeaveInfoDelegate OnRtcUserLeaveInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRoomWarnDelegate OnRtcRoomWarnDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRoomErrorDelegate OnRtcRoomErrorDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRoomMuteStateDelegate OnRtcRoomMuteStateDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcAudioChangePlaybackDeviceDelegate OnRtcAudioChangePlaybackDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcMediaDeviceChangeInfoDelegate OnRtcMediaDeviceChangeInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcLocalAudioPropertiesReportDelegate OnRtcLocalAudioPropertiesReportDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRemoteAudioPropertiesReportDelegate OnRtcRemoteAudioPropertiesReportDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcWarnDelegate OnRtcWarnDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcErrorDelegate OnRtcErrorDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcConnectStateChangedDelegate OnRtcConnectStateChangedDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserStartAudioCaptureDelegate OnRtcUserStartAudioCaptureDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserStopAudioCaptureDelegate OnRtcUserStopAudioCaptureDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserPublishInfoDelegate OnRtcUserPublishInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserUnPublishInfoDelegate OnRtcUserUnPublishInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FGetRtcStreamSyncInfoDelegate OnGetRtcStreamSyncInfoDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcMessageSendResultDelegate OnRtcMessageSendResultDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcBinaryMessageReceivedDelegate OnRtcBinaryMessageReceivedDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcBinaryArrayMessageReceivedDelegate OnRtcBinaryArrayMessageReceivedDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcRoomMessageReceivedDelegate OnRtcRoomMessageReceivedDelegateDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcUserMessageReceivedDelegate OnRtcUserMessageReceivedDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Rtc")
    FRtcOnTokenWilExpireCallbackDelegate OnRtcTokenWilExpireCallbackDelegate;
	// Game Notification Delegate
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnGameInitializeCallbackDelegate OnGameInitializeCallbackDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnGameConnectionNotifyDelegate OnGameConnectionNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnGameRequestFailedNotifyDelegate OnGameRequestFailedNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnGameStateResetNotifyDelegate OnGameStateResetNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnMatchmakingCancel2NotifyDelegate OnMatchmakingCancel2NotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomLeaveNotifyDelegate OnRoomLeaveNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomJoin2NotifyDelegate OnRoomJoin2NotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomSetDescriptionNotifyDelegate OnRoomSetDescriptionNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomKickUserNotifyDelegate OnRoomKickUserNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomUpdateOwnerNotifyDelegate OnRoomUpdateOwnerNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomUpdateDataStoreNotifyDelegate OnRoomUpdateDataStoreNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomUpdateMembershipLockStatusNotifyDelegate OnRoomUpdateMembershipLockStatusNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoomInviteAcceptedNotifyDelegate OnRoomInviteAcceptedNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnRoomUpdateNotifyDelegate OnRoomUpdateNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Game")
	FOnMatchmakingFoundNotifyDelegate OnMatchmakingFoundNotifyDelegate;
    
	void OnGameInitializeCallback(bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage, int Result);
    void OnGameConnectionNotification(int Result, bool bWasSuccessful);
    void OnGameRequestFailedNotification(int Result, bool bWasSuccessful);
    void OnGameStateResetNotification(bool bWasSuccessful);
    void OnMatchmakingCancel2Notification(bool bWasSuccessful);
    void OnSessionLeaveNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomJoin2Notification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomSetDescriptionNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomKickUserNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateOwnerNotification(bool bWasSuccessful);
    void OnRoomUpdateDataStoreNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateMembershipLockStatusNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateComplete(const FString& RoomID, bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage);
    void OnRoomInviteAcceptedComplete(const FString& RoomID, bool bWasSuccessful);
	void OnMatchmakingFoundComplete(const FString& RoomID, bool bWasSuccessful, int ErrorCode, const FString& ErrorMessage);
	void OnSessionUserInviteAccepted(const bool bWasSuccessful, const int32 ControllerId,
													const FString& UserId,
													const FPicoOnlineSessionSearchResult& InviteResult);
    
    // Game Delegate
    static FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
    static FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
    static FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate;
    static FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate;
    static FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
    static FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate;
    static FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate;
    static FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate;
    static FPicoManagerOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate;
    static FPicoManagerOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;

    // Leaderboard
	static FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate;

    // Presence Notification Delegate
    UPROPERTY(BlueprintAssignable, Category = "Presence")
    FPresenceJoinIntentReceivedDelegate OnPresenceJoinIntentReceivedDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Presence")
    FPresenceLeaveIntentReceivedDelegate OnPresenceLeaveIntentReceivedDelegate;

    // ApplicationLifecycle Notification Delegate
    UPROPERTY(BlueprintAssignable, Category = "ApplicationLifecycle")
    FApplicationLifecycleStringResultDelegate OnApplicationLifecycleStringResultDelegate;


    // Game IOnlineSession
	bool IsGameInitSuccess(UObject* WorldContextObject);
	bool GameInitialize(UObject* WorldContextObject);
	bool GameUninitialize(UObject* WorldContextObject);
    bool CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate);
    bool StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate);
    bool UpdateSession(UObject* WorldContextObject, FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData = true);
    bool EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate);
    bool DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate);
    bool IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FUniqueNetId& UniqueId);
#if ENGINE_MAJOR_VERSION > 4
    bool StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& SearchSettings, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 26
    bool StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& SearchSettings, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 24
    bool StartMatchmaking(UObject* WorldContextObject, const TArray< TSharedRef<const FUniqueNetId> >& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoOnlineSessionSearch& SearchSettings, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);
#endif  
    bool CancelMatchmaking(UObject* WorldContextObject, int32 SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate);
    bool FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate);
    bool FindSessionById(UObject* WorldContextObject, const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FPicoManagerOnSingleSessionResultCompleteDelegate& CompletionDelegate);
    bool JoinSession(UObject* WorldContextObject, int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession, const FPicoManagerOnJoinSessionCompleteDelegate& OnJoinSessionCompleteDelegate);
    void DumpSessionState(UObject* WorldContextObject);
    EOnlineSessionState::Type GetSessionState(UObject* WorldContextObject, FName SessionName);
    FNamedOnlineSession* GetNamedSession(UObject* WorldContextObject, FName SessionName);
    FNamedOnlineSession* AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSessionSettings& SessionSettings);
    FNamedOnlineSession* AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSession& Session);
    FOnlineSessionSettings* GetSessionSettings(UObject* WorldContextObject, FName SessionName);
	bool SendSessionInviteToFriend(UObject* WorldContextObject, int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend);

	// findsessions
	FPicoOnlineSessionSearch* PicoSessionSearchPtr;
	TSharedPtr<FOnlineSessionSearch> SessionSearchPtr;
	FOnlineSessionSettings SessionSettings;

	// tool 
	bool IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& InputSessionSearch);
	bool IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	void SetOnlineSessionSearch(const FPicoOnlineSessionSearch& InputSessionSearch);
	FPicoOnlineSessionSettings GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings);
	void SetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	void SetPicoOnlineSessionSearch();
	FOnlineSessionSettings GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	TSharedPtr<FOnlineSessionSearch> GetOnlineSessionSearch(const FPicoOnlineSessionSearch& SessionSearch);
    
    // Game OnComplete
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnUpdateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnEndSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
    void OnMatchmakingComplete(FName SessionName, bool bWasSuccessful);
    void OnCancelMatchmakingComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionComplete(bool Result);
    void OnFindSessionByIdComplete(int32 LocalUserNum, bool bWasSuccessful, const FOnlineSessionSearchResult& SearchResult);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Type);


	// Leaderboard
#if ENGINE_MAJOR_VERSION > 4
    bool ReadLeaderboards(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 26
    bool ReadLeaderboards(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 24
    bool ReadLeaderboards(UObject* WorldContextObject, const TArray< TSharedRef<const FUniqueNetId> >& Players, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
#endif
	
	bool ReadLeaderboardsForFriends(UObject* WorldContextObject, int32 LocalUserNum, FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
	bool WriteLeaderboards(UObject* WorldContextObject, const FName& SessionName, const FUniqueNetId& Player, FOnlineLeaderboardWrite& WriteObject);
	void SetOnlineLeaderboardRead(const FPicoOnlineLeaderboardRead& PicoLeaderboardRead);
	void RefreshPicoOnlineLeaderboardRead();      
	
	
	// Leaderboard OnComplete
    void OnReadLeaderboardsComplete(bool bWasSuccessful);

	FPicoOnlineLeaderboardRead* PicoLeaderboardReadPtr;
	FOnlineLeaderboardReadPtr LeaderboardReadPtr;


    // Presence 
    static FOnlineManagerPresenceClearDelegate PresenceClearDelegate;
    static FOnlineManagerPresenceReadInvitableUserDelegate PresenceReadInvitableUserDelegate;
    static FOnlineManagerPresenceSetDelegate PresenceSetDelegate;
    static FOnlineManagerPresenceSetDestinationDelegate PresenceSetDestinationDelegate;
    static FOnlineManagerPresenceSetIsJoinableDelegate PresenceSetIsJoinableDelegate;
    static FOnlineManagerPresenceSetLobbySessionDelegate PresenceSetLobbySessionDelegate;
    static FOnlineManagerPresenceSetMatchSessionDelegate PresenceSetMatchSessionDelegate;
    static FOnlineManagerPresenceSetExtraDelegate PresenceSetExtraDelegate;
    static FOnlineManagerPresenceReadSentInvitesDelegate PresenceReadSentInvitesDelegate;
    static FOnlineManagerPresenceSentInvitesDelegate PresenceSentInvitesDelegate;
    static FOnlineManagerPresenceGetDestinationsDelegate PresenceGetDestinationsDelegate;
    static FOnlineManagerLaunchInvitePanelDelegate LaunchInvitePanelDelegate;
    static FOnlineManagerShareMediaDelegate ShareMediaDelegate;


    bool PresenceClear(UObject* WorldContextObject, FOnlineManagerPresenceClearDelegate InPresenceClearDelegate);
    void OnPresenceClearComplete(bool bIsSuccessed, const FString& ErrorMessage);

    void ReadInvitableUser(UObject* WorldContextObject, TArray<FString> SuggestedUserList, FOnlineManagerPresenceReadInvitableUserDelegate InReadInvitableUserDelegate);
    void OnReadInvitableUserComplete(bool bIsSuccessed, const FString& ErrorMessage);
    
    bool GetInvitableFriendList(UObject* WorldContextObject, TArray<FPicoUserInfo>& OutFriendsList);

    bool PresenceSet(UObject* WorldContextObject, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, FOnlineManagerPresenceSetDelegate InPresenceSetDelegate);
    void OnPresenceSetComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceSetDestination(UObject* WorldContextObject, const FString& ApiName, FOnlineManagerPresenceSetDestinationDelegate InPresenceSetDestinationDelegate);
    void OnPresenceSetDestinationComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceSetIsJoinable(UObject* WorldContextObject, bool bIsJoinable, FOnlineManagerPresenceSetIsJoinableDelegate InPresenceSetIsJoinableDelegate);
    void OnPresenceSetIsJoinableComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceSetLobbySession(UObject* WorldContextObject, const FString& LobbySession, FOnlineManagerPresenceSetLobbySessionDelegate InPresenceSetLobbySessionDelegate);
    void OnPresenceSetLobbySessionComplete( bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceSetMatchSession(UObject* WorldContextObject, const FString& MatchSession, FOnlineManagerPresenceSetMatchSessionDelegate InPresenceSetMatchSessionDelegate);
    void OnPresenceSetMatchSessionComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceSetExtra(UObject* WorldContextObject, const FString& Extra, FOnlineManagerPresenceSetExtraDelegate InPresenceSetExtraDelegate);
    void OnPresenceSetExtraComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceReadSendInvites(UObject* WorldContextObject, FOnlineManagerPresenceReadSentInvitesDelegate InPresenceReadSendInvitesDelegate);
    void OnPresenceReadSendInvitesComplete(bool bIsSuccessed, const FString& ErrorMessage);


    bool PresenceSendInvites(UObject* WorldContextObject, TArray<FString> UserIdArray, FOnlineManagerPresenceSentInvitesDelegate InPresenceSentInvitesDelegate);
    void OnSendInvitesComplete( bool bIsSuccessed, const FString& ErrorMessage);

    bool GetSendInvitesList(UObject* WorldContextObject, TArray<FPicoApplicationInvite>& OutList);

    bool PresenceGetDestinations(UObject* WorldContextObject, FOnlineManagerPresenceGetDestinationsDelegate InPresenceGetDestinationsDelegate);
    void OnGetDestinationsComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool PresenceGetDestinationsList(UObject* WorldContextObject, TArray<FPicoDestination>& OutList);

    bool LaunchInvitePanel(UObject* WorldContextObject, FOnlineManagerLaunchInvitePanelDelegate InLaunchInvitePanelDelegate);
    void OnLaunchInvitePanelComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool ShareMedia(UObject* WorldContextObject, EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, FOnlineManagerShareMediaDelegate InShareMediaDelegate);
    void OnShareMediaComplete(bool bIsSuccessed, const FString& ErrorMessage);

    // ApplicationInterface
    static FOnlineManagerLaunchOtherAppDelegate LaunchOtherAppDelegate;
    static FOnlineManagerLaunchOtherAppByAppIdDelegate LaunchOtherAppByAppIdDelegate;
    static FOnlineManagerLaunchOtherAppByPresenceDelegate LaunchOtherAppByPresenceDelegate;
    static FOnlineManagerGetVersionDelegate GetVersionDelegate;
    static FOnlineManagerLaunchStoreDelegate LaunchStoreDelegate;

    bool LaunchOtherApp(UObject* WorldContextObject, const FString& PackageName, const FString& Message, FOnlineManagerLaunchOtherAppDelegate InLaunchOtherAppDelegate);
    void OnLaunchOtherAppComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage);

    bool LaunchOtherAppByAppId(UObject* WorldContextObject, const FString& AppId, const FString& Message, FOnlineManagerLaunchOtherAppByAppIdDelegate InLaunchOtherAppByAppIdDelegate);
    void OnLaunchOtherAppByAppIdComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage);

    bool GetVersion(UObject* WorldContextObject, FOnlineManagerGetVersionDelegate InGetVersionDelegate);
    void OnGetVersionComplete(int64 CurrentCode, const FString& CurrentName, int64 LatestCode, const FString& LatestName, bool bIsSuccessed, const FString& ErrorMessage);

    bool LaunchOtherAppByPresence(UObject* WorldContextObject, const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, FOnlineManagerLaunchOtherAppByPresenceDelegate InLaunchOtherAppByPresenceDelegate);
    void OnLaunchOtherAppByPresenceComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage);

    bool LaunchStore(UObject* WorldContextObject, FOnlineManagerLaunchStoreDelegate InLaunchStoreDelegate);
    void OnLaunchStoreComplete(const FString& Message, bool bIsSuccessed, const FString& ErrorMessage);

    // ApplicationLifecycle
    static FOnlineManagerApplicationLifecycleReadDetailsDelegate ApplicationLifecycleReadDetailsDelegate;

    //bool ReadLaunchDetails(UObject* WorldContextObject, FOnlineManagerApplicationLifecycleReadDetailsDelegate InApplicationLifecycleReadDetailsDelegate);
    //void OnReadLaunchDetailsComplete(bool bIsSuccessed, const FString& ErrorMessage);

    bool GetLaunchDetails(UObject* WorldContextObject, FLaunchDetails& OutLaunchDetails);

    bool LogDeeplinkResult(UObject* WorldContextObject, const FString& TrackingID, ELaunchResult LaunchResult);

    bool GetSystemInfo(UObject* WorldContextObject, FPicoSystemInfo &SystemInfo);

    // 

    UPROPERTY(BlueprintAssignable, Category = "AssetFile")
    FAssetFileDownloadUpdateDelegate OnAssetFileDownloadUpdateDelegate;

    UPROPERTY(BlueprintAssignable, Category = "AssetFile")
    FAssetFileDeleteForSafetyDelegate OnAssetFileDeleteForSafetyDelegate;

    UPROPERTY(BlueprintAssignable, Category = "Highlight")
    FHighlightRecordStopDelegate OnHighlightRecordStopDelegate;

    void OnHighlightRecordStop(UPico_RecordInfo* RecordInfoObj);

    void OnAssetFileDownloadUpdate(UPico_AssetFileDownloadUpdate* AssetFileDownloadUpdateObj);

    void OnAssetFileDeleteForSafety(UPico_AssetFileDeleteForSafety* AssetFileDeleteForSafetyObj);

    // Speech

    UPROPERTY(BlueprintAssignable, Category = "AssetFile")
    FSpeechAsrResultDelegate OnSpeechAsrResultDelegate;

    UPROPERTY(BlueprintAssignable, Category = "AssetFile")
    FSpeechErrorDelegate OnSpeechErrorDelegate;

    void OnSpeechAsrResult(UPico_AsrResult* AsrResultObj);

    void OnSpeechError(UPico_SpeechError* SpeechErrorObj);	/*
	 * Pico_Room Notification begin
	 */
	UPROPERTY(BlueprintAssignable, Category = "Pico Room")
	FPicoRoomUpdateNotifyDelegate OnPicoRoomUpdateNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Pico Room")
	FPicoRoomUpdateOwnerNotifyDelegate OnPicoRoomUpdateOwnerNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Pico Room")
	FPicoRoomLeaveNotifyDelegate OnPicoRoomLeaveNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Pico Room")
	FPicoRoomJoinNotifyDelegate OnPicoRoomJoinNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Pico Room")
	FPicoRoomInviteAcceptedNotifyDelegate OnPicoRoomInviteAcceptedNotifyDelegate;

	void OnPicoRoomUpdateNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room);
	void OnPicoRoomUpdateOwnerNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage);
	void OnPicoRoomJoinNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room);
	void OnPicoRoomLeaveNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room);
	void OnPicoRoomInviteAcceptedNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, const FString& RoomID);
	/*
	 * Pico_Room Notification end
	 */
	
	/*
	 * Pico_Matchmaking Notification begin
	 */
	UPROPERTY(BlueprintAssignable, Category = "Pico Matchmaking")
	FPicoMatchmakingCancelNotifyDelegate OnPicoMatchmakingCancelNotifyDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Pico Matchmaking")
	FPicoMatchmakingMatchFoundNotifyDelegate OnPicoMatchmakingMatchFoundNotifyDelegate;

	void OnPicoMatchmakingCancelNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage);
	void OnPicoMatchmakingMatchFoundNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, UPico_Room* Room);
	/*
	 * Pico_Matchmaking Notification end
	 */

	/*
	 * Pico_Challenges Notification begin
	 */
	UPROPERTY(BlueprintAssignable, Category = "Pico Challenges")
	FPicoChallengeInviteAcceptedOrLaunchAppNotifyDelegate OnPicoChallengeInviteAcceptedOrLaunchAppNotifyDelegate;

	void OnPicoChallengeInviteAcceptedOrLaunchAppNotification(bool bIsError, int ErrorCode, const FString& ErrorMessage, const FString& ChallengeID);
	/*
	 * Pico_Challenges Notification end
	 */
};
