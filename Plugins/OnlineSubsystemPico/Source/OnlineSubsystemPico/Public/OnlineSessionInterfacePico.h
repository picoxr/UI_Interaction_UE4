// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystemPicoPackage.h"

/// @file OnlineSessionInterfacePico.h

/// @brief Used to set the matchmaking pool name.
#define SETTING_PICO_POOL FName(TEXT("PICOPOOL"))
/// @brief Used to set the pico build unique ID.
#define SETTING_PICO_BUILD_UNIQUE_ID FName(TEXT("PICOSESSIONBUILDUNIQUEID"))
/// @brief Used to set whether to search for moderated rooms.
#define SEARCH_PICO_MODERATED_ROOMS_ONLY FName(TEXT("PICOMODERATEDROOMSONLY"))
/// @brief Used to set the page index when searching for moderated rooms.
#define GET_MODERATEDROOMS_PAGEINDEX FName(TEXT("GETMODERATEDROOMSPAGEINDEX"))
/// @brief Used to set the page size when searching for moderated rooms.
#define GET_MODERATEDROOMS_PAGESIZE FName(TEXT("GETMODERATEDROOMSPAGESIZE"))

class FUniqueNetIdPico;
class FOnlineSessionInfoPico;


// Notifications
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnGameConnectionComplete, int /*Result*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnGameRequestFailedComplete, int /*Result*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateResetComplete, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchmakingCancel2Complete, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomLeaveComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomJoin2Complete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomSetDescriptionComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomKickUserComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnRoomUpdateOwnerComplete, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomUpdateDataStoreComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomUpdateMembershipLockStatusComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomUpdateComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomInviteAcceptedComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);


/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Session Session
 *  This is the Session group
 *  @{
 */


/// @brief FOnlineSessionPico class inherited from IOnlineSession(Unreal Engine).
class FOnlineSessionPico : public IOnlineSession
{
private:

	/// @brief Reference to the main Pico subsystem.
	FOnlineSubsystemPico& PicoSubsystem;

	/// @brief Current sessions map.
	TMap<FName, TSharedPtr<FNamedOnlineSession>> Sessions;

	/// @brief The SearchSettings for matchmaking.
	TSharedPtr<FOnlineSessionSearch> InProgressMatchmakingSearch;

	/// @brief The SessionName when in matchmaking.
	FName InProgressMatchmakingSearchName;

	/// @brief Gets the room ID of the session.
	/// @param Session The session to get room ID for.
	/// @return return The room ID of the specified session.
	ppfID GetRoomIDOfSession(const FNamedOnlineSession& Session) const;
	
	/// @brief Returns the search results of the sessions where the invitation has been accepted. Supported version: 4.8.0 or later.
	TArray<TSharedRef<const FOnlineSessionSearchResult>> InviteAcceptedSessions;
	
	/// @brief Gets the build unique ID of a room.
	/// @param Room The handle of the room.
	/// @return The build unique ID of the room.
	int32 GetRoomBuildUniqueId(const ppfRoomHandle Room);

PACKAGE_SCOPE:

	FDelegateHandle OnRoomNotificationUpdateHandle;
	void OnRoomNotificationUpdate(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationInviteAcceptedHandle;
	void OnRoomInviteAccepted(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnMatchmakingNotificationMatchFoundHandle;
	void OnMatchmakingNotificationMatchFound(ppfMessageHandle Message, bool bIsError);

	TSharedRef<FOnlineSession> CreateSessionFromRoom(ppfRoomHandle Room) const;

	void UpdateSessionFromRoom(FNamedOnlineSession& Session, ppfRoomHandle Room) const;
	void UpdateSessionSettingsFromDataStore(FOnlineSessionSettings& SessionSettings, ppfDataStoreHandle DataStore) const;

	void TickPendingInvites(float DeltaTime);

	bool CreateRoomSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy);
	bool CreateMatchmakingSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy);
	void OnCreateRoomComplete(ppfMessageHandle Message, bool bIsError, FName SessionName);
	
	/// @brief Searches for moderated rooms.
	/// @param SearchSettings The search settings.
	/// @return Bool: `true`-success; `false`-failure.
	bool FindModeratedRoomSessions(const TSharedRef<FOnlineSessionSearch>& SearchSettings);
	
	/// @brief Searches for the "browse" type matchmaking rooms.
	/// @param Pool The name of the matchmaking pool to look in.
	/// @param SearchSettings The search settings (to set the search results and the searchState).
	/// @return Bool: `true`-success; `false`-failure.
	bool FindMatchmakingSessions(const FString Pool, const TSharedRef<FOnlineSessionSearch>& SearchSettings);
	
	bool UpdateRoomDataStore(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings);

public:

	/// @brief The constructor.
	/// @param InSubsystem A reference to the online subsystem.
	FOnlineSessionPico(FOnlineSubsystemPico& InSubsystem);
	
    /// The default destructor.
	virtual ~FOnlineSessionPico();


	// Begin IOnlineSession interface

	/// @brief Creates an online session based on the specified settings.
	/// NOTE: Online session registration is an async process and will not complete
	/// until the `OnCreateSessionComplete` delegate is called.
	/// @param HostingPlayerNum The index of the player hosting the session.
	/// @param SessionName The name of the session to create.
	/// @param NewSessionSettings The settings to use for the new session.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool CreateSession(int32 HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings) override;
	virtual bool CreateSession(const FUniqueNetId& HostingPlayerId, FName SessionName, const FOnlineSessionSettings& NewSessionSettings) override;
	
	/// @brief Marks an online session as in progress (as opposed to being in lobby or pending).
	/// @param SessionName The name of session to change state for.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool StartSession(FName SessionName) override;

	/// @brief Updates the localized settings/properties for the session in question.
	/// @param SessionName The name of the session to update.
	/// @param UpdatedSessionSettings The object to update the session settings with.
	/// @param bShouldRefreshOnlineData Whether to submit the data to the backend or not.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool UpdateSession(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, bool bShouldRefreshOnlineData = true) override;

	/// @brief Marks an online session as having been ended.
	/// @param SessionName The name of the session the to end.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool EndSession(FName SessionName) override;

	/// @brief Destroys the specified online session.
	/// NOTE: Online session de-registration is an async process and will not complete
	/// until the `OnDestroySessionComplete` delegate is called.
	/// @param SessionName The name of the session to destroy.
	/// @param CompletionDelegate Used when the session destroy request has been completed.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool DestroySession(FName SessionName, const FOnDestroySessionCompleteDelegate& CompletionDelegate = FOnDestroySessionCompleteDelegate()) override;

	/// @brief Determines if the player is registered in the specified session.
	/// @param SessionName The name of the session.
	/// @param UniqueId The ID of the player to check if in session or not.
	/// @return Bool: `true`-in session; `false`-not in session.
	virtual bool IsPlayerInSession(FName SessionName, const FUniqueNetId& UniqueId) override;

	/// @brief Starts cloud-based matchmaking for a session.
	/// @param LocalPlayers The IDs of all local players that will participate in the match.
	/// @param SessionName The name of the session to use.
	/// @param NewSessionSettings The desired settings to match against or create with when forming new sessions. `NumPrivateConnections` needs to be zero.
	/// @param SearchSettings The desired settings that the matched session will have.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool StartMatchmaking(const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings) override;

	/// @brief Cancels a matchmaking request for a given session.
	/// @param SearchingPlayerNum The index of the player canceling the search.
	/// @param SessionName The name of the session that was passed to `StartMatchmaking` (or `CreateSession`).
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool CancelMatchmaking(int32 SearchingPlayerNum, FName SessionName) override;
	virtual bool CancelMatchmaking(const FUniqueNetId& SearchingPlayerId, FName SessionName) override;

	/// @brief Searches for sessions matching the settings specified.
	/// @param SearchingPlayerNum The index of the player searching for a match.
	/// @param SearchSettings The desired settings that the returned sessions will have.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool FindSessions(int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings) override;
	virtual bool FindSessions(const FUniqueNetId& SearchingPlayerId, const TSharedRef<FOnlineSessionSearch>& SearchSettings) override;

	/// @brief Finds a session by session ID.
	/// @param SearchingUserId The ID of the user initiating the request.
	/// @param SessionId The session ID to search for
	/// @param FriendId Not supported. Set it invalid.
	/// @param CompletionDelegate Will be executed when ppf_Room_Get completes.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool FindSessionById(const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FOnSingleSessionResultCompleteDelegate& CompletionDelegate) override;
	virtual bool CancelFindSessions() override;
	virtual bool PingSearchResults(const FOnlineSessionSearchResult& SearchResult) override;

	/// @brief Joins the session specified.
	/// @param PlayerNum The index of the player searching for a match.
	/// @param SessionName The name of the session to join.
	/// @param DesiredSession The desired session to join.
	/// @return Bool: `true`-success; `false`-failure.
	virtual bool JoinSession(int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession) override;
	virtual bool JoinSession(const FUniqueNetId& PlayerId, FName SessionName, const FOnlineSessionSearchResult& DesiredSession) override;

	/// @brief not supported in version 4.7.0
	virtual bool FindFriendSession(int32 LocalUserNum, const FUniqueNetId& Friend) override;
	virtual bool FindFriendSession(const FUniqueNetId& LocalUserId, const FUniqueNetId& Friend) override;
	virtual bool FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<FUniqueNetIdRef>& FriendList) override;
	
	/// @brief not supported in version 4.7.0
	virtual bool SendSessionInviteToFriend(int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend) override;
	virtual bool SendSessionInviteToFriend(const FUniqueNetId& LocalUserId, FName SessionName, const FUniqueNetId& Friend) override;
	virtual bool SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< FUniqueNetIdRef >& Friends) override;
	virtual bool SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< FUniqueNetIdRef >& Friends) override;
	virtual bool GetResolvedConnectString(FName SessionName, FString& ConnectInfo, FName PortType = NAME_GamePort) override;
	virtual bool GetResolvedConnectString(const class FOnlineSessionSearchResult& SearchResult, FName PortType, FString& ConnectInfo) override;
	virtual FOnlineSessionSettings* GetSessionSettings(FName SessionName) override;
	virtual bool RegisterPlayer(FName SessionName, const FUniqueNetId& PlayerId, bool bWasInvited) override;
	virtual bool RegisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players, bool bWasInvited = false) override;
	virtual bool UnregisterPlayer(FName SessionName, const FUniqueNetId& PlayerId) override;
	virtual bool UnregisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players) override;
	virtual void RegisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnRegisterLocalPlayerCompleteDelegate& Delegate) override;
	virtual void UnregisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnUnregisterLocalPlayerCompleteDelegate& Delegate) override;
	virtual int32 GetNumSessions() override;
	virtual void DumpSessionState() override;

	virtual FUniqueNetIdPtr CreateSessionIdFromString(const FString& SessionIdStr) override;
	FNamedOnlineSession* GetNamedSession(FName SessionName) override;
	virtual void RemoveNamedSession(FName SessionName) override;
	virtual EOnlineSessionState::Type GetSessionState(FName SessionName) const override;
	virtual bool HasPresenceSession() override;
	class FNamedOnlineSession* AddNamedSession(FName SessionName, const FOnlineSessionSettings& SessionSettings) override;
	class FNamedOnlineSession* AddNamedSession(FName SessionName, const FOnlineSession& Session) override;


private:
	FString InitStateErrorMessage = FString("Error: InitSuccess is false");
	bool InitSuccess = false;
	bool OnUpdateRoomData(ppfRoomHandle Room, ppfID RoomId);
PACKAGE_SCOPE:

	void OnGetAccessTokenComplete(ppfMessageHandle Message, bool bIsError);
	void OnGameInitializeComplete(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnNetNotificationConnectionHandle;
	void OnNetNotificationConnection(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnNetNotificationRequestFailedHandle;
	void OnNetNotificationRequestFailed(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnNetNotificationGameStateResetHandle;
	void OnNetNotificationGameStateReset(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnMatchmakingNotificationCancel2Handle;
	void OnMatchmakingNotificationCancel2(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationLeaveHandle;
	void OnRoomNotificationLeave(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationJoin2Handle;
	void OnRoomNotificationJoin2(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationSetDescriptionHandle;
	void OnRoomNotificationSetDescription(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationKickUserHandle;
	void OnRoomNotificationKickUser(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationUpdateOwnerHandle;
	void OnRoomNotificationUpdateOwner(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationUpdateDataStoreHandle;
	void OnRoomNotificationUpdateDataStore(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomNotificationUpdateMembershipLockStatusHandle;
	void OnRoomNotificationUpdateMembershipLockStatus(ppfMessageHandle Message, bool bIsError);

	void LogRoomData(ppfRoomHandle Room) const;

public:
	/// @brief Initializes the game module.
	void Initialize();

	/// @brief Uninitializes the game module.
	/// @return Always returns `true`.
	bool Uninitialize();

	/// @brief Sets `InitSuccess` for the game module.
	/// @param State `true` when setting `InitSuccess` to `true` or `false` when setting `InitSuccess` to `false`.
	void SetInitState(bool State);

	/// @brief Checks the current state of `InitSuccess`.
	/// @return The state of `InitSuccess`: `true` or `false`.
	bool IsInitSuccess() const;

	/// @brief Force cancels matchmaking.
	void OnForcedCancelMatchmaking();

	/// @brief Force leaves the specified room.
	/// @param RoomID The ID of the room to force leave.
	void OnForcedLeaveRoom(ppfID RoomID);

	/// @brief Checks `InProgressMatchmakingSearch` and `SearchState`.
	/// @return Returns `true` if `InProgressMatchmakingSearch` is `valid` and `SearchState` is `EOnlineAsyncTaskState::InProgress`; `false` otherwise.
	bool IsInMatchmakingProgress();

	FOnRoomUpdateComplete RoomUpdateCallback;
	FOnRoomInviteAcceptedComplete RoomInviteAcceptedCallback;

	FOnGameConnectionComplete GameConnectionCallback;
	FOnGameRequestFailedComplete GameRequestFailedCallback;
	FOnGameStateResetComplete GameStateResetCallback;
	FOnMatchmakingCancel2Complete MatchmakingCancel2Callback;
	FOnRoomLeaveComplete RoomLeaveCallback;
	FOnRoomJoin2Complete RoomJoin2Callback;
	FOnRoomSetDescriptionComplete RoomSetDescriptionCallback;
	FOnRoomKickUserComplete RoomKickUserCallback;
	FOnRoomUpdateOwnerComplete RoomUpdateOwnerCallback;
	FOnRoomUpdateDataStoreComplete RoomUpdateDataStoreCallback;
	FOnRoomUpdateMembershipLockStatusComplete RoomUpdateMembershipLockStatusCallback;

	const char* JoinPolicyNames[6] = { "None", "Everyone", "FriendsOfMembers", "FriendsOfOwner", "InvitedUsers", "Unknown" };
	const char* RoomTypeNames[4] = { "Unknown", "Matchmaking", "Moderated", "Private" };
	const char* ConnectionResultNames[8] = { "Connected", "Closed", "Lost", "Resumed", "KickedByRelogin", "KickedByGameServer", "GameLogicError", "Unknown" };
	const char* JoinabilityNames[7] = { "Unknown", "AreIn", "AreKicked", "CanJoin", "IsFull", "NoViewer", "PolicyPrevents" };
	
	void TestDumpNamedSession(const FNamedOnlineSession* NamedSession) const;
	void TestDumpSession(const FOnlineSession* Session) const;
	void TestDumpSessionSettings(const FOnlineSessionSettings* SessionSettings) const;
};
/** @} */ // end of Session
/** @} */ // end of Function
typedef TSharedPtr<FOnlineSessionPico, ESPMode::ThreadSafe> FOnlineSessionPicoPtr;
