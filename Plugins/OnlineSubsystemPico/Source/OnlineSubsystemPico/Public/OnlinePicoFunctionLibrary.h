// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlineSubsystemPicoManager.h"
#include "RTCPicoUserInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "OnlinePicoFunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnlinePicoVerifyAppDelegate, const int32&, code);
/// @file OnlinePicoFunctionLibrary.h
 

/// @brief Pico blueprint function library.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UOnlinePicoFunctionLibrary();
	static UOnlineSubsystemPicoManager* PicoSubsystemManager;

    /** @defgroup BlueprintFunction BlueprintFunction
     *  This is the BlueprintFunction group
     *  @{
     */

    /** @defgroup BP_Identity BP_Identity
     *  This is the BP_Identity group
     *  @{
     */

    // Pico Identity 
    
    /// @brief Gets the account login information for the current device.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalUserNum The controller number of the user to get login information for.   
    /// @param UserId User ID.
    /// @param InToken User token.
    /// @param InType User type.
    /// @param InLoginComleteDelegate Callback function proxy.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static void PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& UserId, const FString& InToken, const FString& InType, FOnlineManagerLoginCompleteDelegate InLoginComleteDelegate);

    /// @brief Gets a user's nickname.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalUserNum The controller number of the user to get nickname for.   
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static FString PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum);


    /** @} */ // end of BP_Identity

    /** @defgroup BP_Friends BP_Friends
     *  This is the BP_Friends group
     *  @{
     */

	// Pico FriendInterface
    
    
    /// @brief Read user's friend list by account number.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalUserNum User's account number.
    /// @param ListName The name of the list. Valid value is `Default` or `OnlinePlayers`.
    /// @param InReadFriendListDelegate Callback function proxy. 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static void PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate);

    
    /// @brief Gets an arrary of friends for a specified user by friend list name.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalUserNum User's account number.
    /// @param ListName The name of the list. Valid value is `Default` or `OnlinePlayers`.
    /// @param OutFriends Returns an array of friends.   
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static void PicoGetFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, TArray<FPicoFriend> &OutFriends);


    
    /// @brief Gets a user's friends by friend list name and friend ID.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalUserNum User's account number.
    /// @param FriendId Friend ID.
    /// @param ListName The name of the list. Valid value is `Default` or `OnlinePlayers`.
    /// @return FPicoFriend Pico friend struct.  
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static FPicoFriend PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName);


    /** @} */ // end of BP_Friends


    /** @defgroup BP_RTC BP_RTC
     *  This is the BP_RTC group
     *  @{
     */

	// Pico RtcInterface
    
    /// @brief Gets the rtc token.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param UserId User ID.
    /// @param RoomId Room ID.
    /// @param Ttl The effective duration of the room (in seconds).
    /// @param InValue Channel effective time (in seconds).
    /// @param InRtcGetTokenDelegate Callback function proxy.    
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
	static void PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate);

    // Function Call

    
    /// @brief Initializes the RTC engine.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @return Voice The initialization result.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static ERtcEngineInitResult PicoGetRtcEngineInit(UObject* WorldContextObject);

    
    /// @brief Joins a user to a rtc room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.
    /// @param UserId User ID.
    /// @param Token Room token.
    /// @param UserExtra Extra information added by the user.
    /// @param InRoomProfileType Room type: `0`-communication room; `1`-live broadcasting room; `2`-game room; `3`-cloud game room; `4`-low-latency room.
    /// @param bIsAutoSubscribeAudio Whether to automatically subscribe to the audio of the room: `true`-yes; `false`-no.
    /// @return Int: `0` indicates success, and other values indicate failure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
	static int PicoRtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio);

    
    /// @brief Destroys a room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.
    /// @return Int: `0` indicates success, and other values indicate failure.     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// @brief Enables audio properties report. When this switch is turned on, you will regularly receive a statistical report of audio data.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param Interval The interval (in milliseconds) between one report and the next. You can set this parameter to `0` or any negative integer to stop receiving audio properties report. For any integer between (0, 100), the SDK will regard it as invalid and automatically set this parameter to `100`; any integer equal to or greater than `100` is valid.    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval);

    /// @brief Leaves a rtc room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.
    /// @return Int: `0` indicates success, and other values indicate failure.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId);


    /// @brief Mutes local audio to make one's voice unable to be heard be others in the same room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InRtcMuteState The state of local audio: `0`-off; `1`-on.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState);

    
    /// @brief Publishes local audio stream to a room, thereby making the voice heard be others in the same room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// @brief Stops publishing local audio stream to a room, so others in the same room cannot hear the voice.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.        
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// @brief Pauses all subscribed streams of a room. Once paused, the voice of users in the room is blocked so nothing can be heard from this room.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.
    /// @param InPauseResumeMediaType Media type. 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    
    /// @brief Resumes all subscribed streams of a room. Once resumed, the voice of users in the room can be heard again.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId The ID of the room to resume subscribed streams for.
    /// @param InPauseResumeMediaType Media type.     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    
    /// @brief Sets the type of audio playback device.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InRtcAudioPlaybackDevice Device type.       
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice);

    
    /// @brief Sets audio scenario type.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InRtcAudioScenarioType Audio scenario type: `0`-Music; `1`-HighQualityCommunication; `2`-Communication; `3`-Media; `4`-GameStreaming.       
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType);

    
    /// @brief Sets volume for audio capture.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InRtcStreamIndex Stream index main/screen.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.       
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume);

    
    /// @brief Sets the in-ear monitoring mode.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InRtcEarMonitorMode The state of in-ear monitoring mode: `0`-off; `1`-on.      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode);

    
    /// @brief Sets the volume for in-ear monitoring.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume);

    
    /// @brief Sets the playback volume.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume);

    
    /// @brief Starts audio capture.
    /// @param WorldContextObject Used to get the information about the current world.    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcStartAudioCapture(UObject* WorldContextObject);

    
    /// @brief Stops audio capture.
    /// @param WorldContextObject Used to get the information about the current world.      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcStopAudioCapture(UObject* WorldContextObject);

    
    /// @brief Updates room token.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param RoomId Room ID.
    /// @param Token The new token.      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token);
    /** @} */ // end of BP_RTC

    /** @defgroup BP_Session BP_Session
     *  This is the BP_Session group
     *  @{
     */

    // Game

    /// @brief Creates a private session or a matchmaking session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param HostingPlayerNum The index in the current userId array.
    /// @param SessionName The session name.
    /// @param NewSessionSettings The session settings.
    /// @param OnCreateSessionCompleteDelegate Executes this parameter after the session has been created.
    /// @return Bool: `true`-success; `false`-falure.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate);

    /// @brief Changes the session state to `InProgress`.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param OnStartSessionCompleteDelegate Executes this parameter after the session has been started.
    /// @return Bool: `true`-success; `false`-falure.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate);

    /// @brief Updates the datastore of a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param UpdatedSessionSettings The settings with new datastore.
    /// @param bShouldRefreshOnlineData (not used)
    /// @param OnUpdateSessionCompleteDelegate Executes this parameter after the session has been updated.
    /// @return Bool: `true`-success; `false`-falure.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool UpdateSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData = true);

    /// @brief Changes the session state to `Ended`.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param OnEndSessionCompleteDelegate Executes this parameter after the session has been ended.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate);

	// todo CompletionDelegate
    /// @brief Destroys the current session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param OnDestroySessionCompleteDelegate Executes this parameter after the session has been destroyed.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate);

    /// @brief Checks whether a player is in a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param UniqueId The unique ID of the player.
    /// @return Bool: `true`-success; `false`-falure.
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FString& UniqueId);

    /// @brief Starts matchmaking for a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param LocalPlayers The logged-in users in the session.
    /// @param SessionName The session name.
    /// @param NewSessionSettings Set `NumPrivateConnections` to `0`.
    /// @param NewSessionSearch Used to modify the search state.
    /// @param OnMatchmakingCompleteDelegate Executes this parameter after the matchmaking has been completed.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool StartMatchmaking(UObject* WorldContextObject, const TArray<FString>& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, const FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);

    /// @brief Cancels matchmaking for a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SearchingPlayerNum (not used)
    /// @param SessionName The session name.
    /// @param OnCancelMatchmakingCompleteDelegate Executes this parameter after the matchmaking has been canceled.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool CancelMatchmaking(UObject* WorldContextObject, int SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate);

    /// @brief Finds matchmaking sessions or moderated sessions.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SearchingPlayerNum (not used)
    /// @param NewSessionSearch The search settings.
    /// @param OnFindSessionCompleteDelegate Executes this parameter after the session has been found.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, const FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate);

	// todo FriendId /// CompletionDelegate
    /// @brief Gets session data by session ID.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SearchingUserId The ID of the logged-in player. If the played has not logged in, the session data will be unable to get.
    /// @param SessionId The session ID.
    /// @param OnSingleSessionResultCompleteDelegate Executes this parameter after the session data has been got.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool FindSessionById(UObject* WorldContextObject, const FString& SearchingUserId, const FString& SessionId, FPicoManagerOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate);

    /// @brief Joins a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param PlayerNum The `LocalOwnerId` of the session.
    /// @param SessionName The name of the session to join.
    /// @param SearchResult The search session result settings.
    /// @param OnJoinSessionCompleteDelegate Executes this parameter after the session has been joined.
    /// @return Bool: `true`-success; `false`-falure.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool JoinSession(UObject* WorldContextObject, int PlayerNum, FName SessionName, const FPicoOnlineSessionSearchResult& SearchResult, FPicoManagerOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate);

    /// @brief Dumps a session.
    /// @param WorldContextObject Used to get the information about the current world.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static void DumpSessionState(UObject* WorldContextObject);

    /// @brief Gets the state of a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The name of the session to get state for.
    /// @return The state of the session.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static EOnlineSessionStatePicoType GetSessionState(UObject* WorldContextObject, FName SessionName);

    /// @brief Gets the data about a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @return The data about the session.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession GetNamedSession(UObject* WorldContextObject, FName SessionName);

    /// @brief Adds session by session settings.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param SessionSettings The settings of the session.
    /// @return The session added.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession AddNamedSessionBySettings(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& SessionSettings);

    /// @brief Adds a session.
    /// @param WorldContextObject Used to get the information about the current world.
    /// @param SessionName The session name.
    /// @param Session The session will be added.
    /// @return The session added.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession AddNamedSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSession& Session);

	/// @brief Gets the settings of a session.
	/// @param WorldContextObject Used to get the information about the current world.
	/// @param SessionName The session name.
	/// @return The settings of the session.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoOnlineSessionSettings GetSessionSettings(UObject* WorldContextObject, FName SessionName);

    /** @} */ // end of BP_Session
	
private:
	static FOnlineSessionSettings GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	static FPicoOnlineSessionSettings GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings);
	static FPicoNamedOnlineSession GetPicoOnlineSession(const FNamedOnlineSession& Session);
	static FOnlineSession GetOnlineSession(const FPicoOnlineSession& PicoSession);
	static TSharedPtr<FOnlineSessionSearch> GetOnlineSessionSearch(const FPicoOnlineSessionSearch& SessionSearch);
	static bool IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	static bool IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& SessionSearch);
	

public:
    static FOnlinePicoVerifyAppDelegate VerifyAppDelegate;
    static int32 VerifyAppCode;

    /** @defgroup BP_Common BP_Common
     *  This is the BP_Common group
     *  @{
     */

    /// @brief Gets the class of online subsystem Pico manager for binding notifications.
    /// @return The UOnlineSubsystemPicoManager class.
    UFUNCTION(BlueprintPure, Category = "OnlinePico")
    static UOnlineSubsystemPicoManager* GetOnlineSubsystemPicoManager();

    /** @} */ // end of BP_Common
    /** @} */ // end of BlueprintFunction
    // Old Online Pico
    UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
    static void PicoEntitlementVerifyAppDelegate(FOnlinePicoVerifyAppDelegate OnVerifyAppCallback);

    UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
    static void PicoEntitlementVerifyCheck();

    UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
    static FString PicoGetDeviceSN();

    UFUNCTION(BlueprintCallable, Category = "OnlinePico|Platform")
    static FString GetOpenId();
};

