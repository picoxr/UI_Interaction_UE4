// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineIdentityPico.h"
#include "RTCPicoUserInterface.h"
#include "OnlineSessionSettings.h"
#include "OnlineSessionInterfacePico.h"
#include "UObject/Object.h"
#include "OnlineSubsystemPicoManager.generated.h"
/**
 * 
 */

UENUM(BlueprintType)
enum class EPresenceStatus : uint8
{
    Unknow,
    OnLine,
    OffLine
};
UENUM(BlueprintType)
enum class EOnlineAsyncTaskStatePicoType : uint8
{
    NotStarted,
    InProgress,
    Done,
    Failed
};
UENUM(BlueprintType)
enum class EOnJoinSessionCompleteResultPicoType : uint8
{
    Success,
    SessionIsFull,
    SessionDoesNotExist,
    CouldNotRetrieveAddress,
    AlreadyInSession,
    UnknownError
};
UENUM(BlueprintType)
enum class EOnlineSessionStatePicoType : uint8
{
    NoSession,
    Creating,
    Pending,
    Starting,
    InProgress,
    Ending,
    Ended,
    Destroying
};
USTRUCT(BlueprintType, meta = (DisplayName = "OnlinePicoFriend"))
struct FPicoFriend
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoFriend")
    FString UserId;

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoFriend")
    FString DisPlayName;

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoFriend")
    EPresenceStatus FriendPresenceStatus;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSettings"))
struct FPicoOnlineSessionSettings
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int NumPublicConnections;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int NumPrivateConnections;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bShouldAdvertise;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowInvites;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bUsesPresence;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowJoinViaPresence;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowJoinViaPresenceFriendsOnly;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int BuildUniqueId;

    // Settings
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    TArray<FString> KeyArray;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    TArray<FString> ValueArray;
};
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSession"))
struct FPicoOnlineSession
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString OwningUserId;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString OwningUserName;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FPicoOnlineSessionSettings SessionSettings;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString SessionInfoRoomID;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    int32 NumOpenPrivateConnections;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    int32 NumOpenPublicConnections;
};
USTRUCT(BlueprintType, meta = (DisplayName = "PicoNamedOnlineSession"))
struct FPicoNamedOnlineSession
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString SessionName;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 HostingPlayerNum;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    bool bHosting;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString LocalOwnerId;

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    TArray< FString > RegisteredPlayers;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    EOnlineSessionStatePicoType SessionState;

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString OwningUserId;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString OwningUserName;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FPicoOnlineSessionSettings SessionSettings;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString SessionInfoRoomID;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 NumOpenPrivateConnections;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 NumOpenPublicConnections;
};
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSearchResult"))
struct FPicoOnlineSessionSearchResult
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearchResult")
    FPicoOnlineSession Session;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearchResult")
    int32 PingInMs;
};
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSearch"))
struct FPicoOnlineSessionSearch
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FPicoOnlineSessionSearchResult> SearchResults;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    EOnlineAsyncTaskStatePicoType SearchState;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 MaxSearchResults;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FString> QuerySettingsKeyArray;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FString> QuerySettingsValueArray;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    bool bIsLanQuery;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 PingBucketSize;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 PlatformHash;
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    float TimeoutInSeconds;
};



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

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnlineManagerRtcGetTokenDelegate, FString, Token, bool, IsSuccessed, FString, ErrorMessage);

// Game
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnCreateSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnStartSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnUpdateSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnEndSessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnDestroySessionCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnCancelMatchmakingCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnMatchmakingCompleteDelegate, FName, SessionName, bool, bWasSuccessful);
// DECLARE_DELEGATE_ThreeParams(FOnStartMatchmakingComplete, FName /*SessionName*/, const struct FOnlineError& /*ErrorDetails*/, const struct FSessionMatchmakingResults& /*Results*/);
// DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMatchmakingComplete, FName, bool);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoManagerOnFindSessionCompleteDelegate, bool, bWasSuccessful);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FPicoManagerOnSingleSessionResultCompleteDelegate, int32, LocalUserNum, bool, bWasSuccessful, const FPicoOnlineSessionSearchResult&, SearchResult);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoManagerOnJoinSessionCompleteDelegate, FName, SessionName, EOnJoinSessionCompleteResultPicoType, Type);

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
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomUpdateNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomUpdateNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FOnRoomInviteAcceptedNotifyDelegate, UOnlineSubsystemPicoManager, OnRoomInviteAcceptedNotifyDelegate, const FString&, RoomID, bool, bWasSuccessful);

UCLASS()
class UOnlineSubsystemPicoManager : public UObject
{
    GENERATED_BODY()

public:
	UOnlineSubsystemPicoManager();
	~UOnlineSubsystemPicoManager();

	FOnReadFriendsListComplete ReadCompleteDelegate;

    TSharedPtr<FRTCPicoUserInterface> RtcInterface;
    FOnGetTokenComplete RtcGetTokenCompleteDelegate;

    FOnlineSessionPicoPtr GameInterface;

    // Friend
	static FOnlineManagerReadFriendListDelegate ReadFrendListDelegate;

	void PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate);
    void OnReadListComplete(int32 InLocalUserNum/*LocalUserNum*/, bool bWasSuccessful/*bWasSuccessful*/, const FString& ListName/*ListName*/, const FString& ErrorStr/*ErrorStr*/);
    void PicoGetFriendList(UObject* WorldContextObject, int32 InLocalUserNum, const FString& ListName, TArray<FPicoFriend>& OutFriendList);
    FPicoFriend PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName);

    // Identity
    static FOnlineManagerLoginCompleteDelegate LoginCompleteDelegate;

    void PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& InUserId, const FString& InType, const FString& InToken, FOnlineManagerLoginCompleteDelegate InLoginCompleteDelegate);
    FString PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum);
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


    // Game Notification Delegate
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
    FOnRoomUpdateNotifyDelegate OnRoomUpdateNotifyDelegate;
    UPROPERTY(BlueprintAssignable, Category = "Game")
    FOnRoomInviteAcceptedNotifyDelegate OnRoomInviteAcceptedNotifyDelegate;
    
    void OnGameConnectionNotification(int Result, bool bWasSuccessful);
    void OnGameRequestFailedNotification(int Result, bool bWasSuccessful);
    void OnGameStateResetNotification(bool bWasSuccessful);
    void OnMatchmakingCancel2Notification(bool bWasSuccessful);
    void OnRoomLeaveNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomJoin2Notification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomSetDescriptionNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomKickUserNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateOwnerNotification(bool bWasSuccessful);
    void OnRoomUpdateDataStoreNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateMembershipLockStatusNotification(const FString& RoomID, bool bWasSuccessful);
    void OnRoomUpdateComplete(const FString& RoomID, bool bWasSuccessful);
    void OnRoomInviteAcceptedComplete(const FString& RoomID, bool bWasSuccessful);
    
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
    // todo 480
    // DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnFindFriendSessionComplete, int32, bool, const TArray<FOnlineSessionSearchResult>&);
    // DECLARE_MULTICAST_DELEGATE_FourParams(FOnSessionUserInviteAccepted, const bool, const int32, FUniqueNetIdPtr, const FOnlineSessionSearchResult&);
    // DECLARE_MULTICAST_DELEGATE_FourParams(FOnSessionInviteReceived, const FUniqueNetId& /*UserId*/, const FUniqueNetId& /*FromId*/, const FString& /*AppId*/, const FOnlineSessionSearchResult& /*InviteResult*/);

    

    // Game IOnlineSession
    bool CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate);
    bool StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate);
    bool UpdateSession(UObject* WorldContextObject, FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData = true);
    bool EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate);
    bool DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate);
    bool IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FUniqueNetId& UniqueId);
    bool StartMatchmaking(UObject* WorldContextObject, const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);
    bool CancelMatchmaking(UObject* WorldContextObject, int32 SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate);
    bool FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate);
    bool FindSessionById(UObject* WorldContextObject, const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FPicoManagerOnSingleSessionResultCompleteDelegate& CompletionDelegate);
    bool JoinSession(UObject* WorldContextObject, int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession, const FPicoManagerOnJoinSessionCompleteDelegate& OnJoinSessionCompleteDelegate);
    void DumpSessionState(UObject* WorldContextObject);
    EOnlineSessionState::Type GetSessionState(UObject* WorldContextObject, FName SessionName);
    FNamedOnlineSession* GetNamedSession(UObject* WorldContextObject, FName SessionName);
    FNamedOnlineSession* AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSessionSettings& SessionSettings);
    FNamedOnlineSession* AddNamedSession(UObject* WorldContextObject, FName SessionName, const FOnlineSession& Session);
    FOnlineSessionSettings* GetSessionSettings(UObject* WorldContextObject, FName SessionName);
    
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

};
