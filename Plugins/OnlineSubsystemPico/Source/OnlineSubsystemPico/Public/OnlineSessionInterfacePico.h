// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystemPicoPackage.h"

/// @file OnlineSessionInterfacePico.h

// @brief Used to set the matchmaking pool name.
#define SETTING_PICO_POOL FName(TEXT("PICOPOOL"))
// @brief Used to set the pico build unique ID.
#define SETTING_PICO_BUILD_UNIQUE_ID FName(TEXT("PICOSESSIONBUILDUNIQUEID"))
// @brief Used to set whether to search for moderated rooms.
#define SEARCH_PICO_MODERATED_ROOMS_ONLY FName(TEXT("PICOMODERATEDROOMSONLY"))
// @brief Used to set the page index when searching for moderated rooms.
#define GET_MODERATEDROOMS_PAGEINDEX FName(TEXT("GETMODERATEDROOMSPAGEINDEX"))
// @brief Used to set the page size when searching for moderated rooms.
#define GET_MODERATEDROOMS_PAGESIZE FName(TEXT("GETMODERATEDROOMSPAGESIZE"))

class FUniqueNetIdPico;
class FOnlineSessionInfoPico;


// Notifications
DECLARE_MULTICAST_DELEGATE_FourParams(FOnGameInitializeComplete, bool /*bWasSuccessful*/, int, /*ErrorCode,*/ const FString& /*ErrorMessage*/, int /*Result*/);
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
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRoomInviteAcceptedComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FOnPicoSessionUserInviteAcceptedComplete, const bool /*bWasSuccessful*/, const int32 /*ControllerId*/, const FString& /*UserId*/, const FPicoOnlineSessionSearchResult& /*InviteResult*/);

DECLARE_MULTICAST_DELEGATE_FourParams(FOnRoomUpdateComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/, int, /*ErrorCode,*/ const FString& /*ErrorMessage*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FOnMatchmakingFoundComplete, const FString& /*RoomID*/, bool /*bWasSuccessful*/, int, /*ErrorCode,*/ const FString& /*ErrorMessage*/);


/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Session Session(OnlineSub)
 *  This is the Session(OnlineSub) group
 *  @{
 */


/// <summary>FOnlineSessionPico class inherited from IOnlineSession(Unreal Engine).</summary>
class FOnlineSessionPico : public IOnlineSession
{
private:

	// <summary>Reference to the main Pico subsystem.</summary>
	FOnlineSubsystemPico& PicoSubsystem;

	// <summary>Current sessions map.</summary>
	TMap<FName, TSharedPtr<FNamedOnlineSession>> Sessions;

	// <summary>The SearchSettings for matchmaking.</summary>
	TSharedPtr<FOnlineSessionSearch> InProgressMatchmakingSearch;

	// <summary>The SessionName when in matchmaking.</summary>
	FName InProgressMatchmakingSearchName;

	/// <summary>Gets the room ID of the session.</summary>
	/// <param name="Session">The session to get room ID for.</param>
	/// <returns>The room ID of the specified session.</returns>
	ppfID GetRoomIDOfSession(const FNamedOnlineSession& Session) const;
	
	// <summary>Returns the search results of the sessions where the invitation has been accepted. Supported version: 4.8.0 or later.</summary>
	TArray<TSharedRef<const FOnlineSessionSearchResult>> InviteAcceptedSessions;
	
	
	TArray<TSharedRef<const FOnlineSessionSearchResult>> PendingInviteAcceptedSessions;
	ppfID InviteAcceptedRoomID;
	
	/// <summary>Gets the build unique ID of a room.</summary>
	/// <param name="Room">The handle of the room.</param>
	/// <returns>The build unique ID of the room.</returns>
	int32 GetRoomBuildUniqueId(const ppfRoomHandle Room);

	static void SaveLog(const ELogVerbosity::Type Verbosity, const FString& Log);

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
	
	/// <summary>Searches for moderated rooms.</summary>
	/// <param name="SearchSettings">The search settings.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	bool FindModeratedRoomSessions(const TSharedRef<FOnlineSessionSearch>& SearchSettings);
	
	/// <summary>Searches for the "browse" type matchmaking rooms.</summary>
	/// <param name="Pool">The name of the matchmaking pool to look in.</param>
	/// <param name="SearchSettings">The search settings (to set the search results and the searchState).</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	bool FindMatchmakingSessions(const FString Pool, const TSharedRef<FOnlineSessionSearch>& SearchSettings);
	
	bool UpdateRoomDataStore(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings);


public:

	// <summary>The constructor.</summary>
	// <param name="InSubsystem">A reference to the online subsystem.</param>
	FOnlineSessionPico(FOnlineSubsystemPico& InSubsystem);
	
    /// The default destructor.
	virtual ~FOnlineSessionPico();


	// Begin IOnlineSession interface

	/// <summary>Creates an online session based on the specified settings.
	/// @note Online session registration is an async process and will not complete
	/// until the `OnCreateSessionComplete` delegate is called.
	/// </summary>
	/// <param name="HostingPlayerNum">The index of the player hosting the session.</param>
	/// <param name="SessionName">The name of the session to create.</param>
	/// <param name="NewSessionSettings">The settings to use for the new session.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool CreateSession(int32 HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings) override;
	virtual bool CreateSession(const FUniqueNetId& HostingPlayerId, FName SessionName, const FOnlineSessionSettings& NewSessionSettings) override;
	
	/// <summary>Marks an online session as in progress (as opposed to being in lobby or pending).</summary>
	/// <param name="SessionName">The name of session to change state for.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool StartSession(FName SessionName) override;

	/// <summary>Updates the localized settings/properties for the session in question.</summary>
	/// <param name="SessionName">The name of the session to update.</param>
	/// <param name="UpdatedSessionSettings">The object to update the session settings with.</param>
	/// <param name="bShouldRefreshOnlineData">Whether to submit the data to the backend or not.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool UpdateSession(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, bool bShouldRefreshOnlineData = true) override;

	/// <summary>Marks an online session as having been ended.</summary>
	/// <param name="SessionName">The name of the session to end.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool EndSession(FName SessionName) override;

	/// <summary>Destroys the specified online session.
	/// @note Online session de-registration is an async process and will not complete
	/// until the `OnDestroySessionComplete` delegate is called.
	/// </summary>
	/// <param name="SessionName">The name of the session to destroy.</param>
	/// <param name="CompletionDelegate">Used when the session destroy request has been completed.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool DestroySession(FName SessionName, const FOnDestroySessionCompleteDelegate& CompletionDelegate = FOnDestroySessionCompleteDelegate()) override;

	/// <summary>Determines if the player is registered in the specified session.</summary>
	/// <param name="SessionName">The name of the session.</param>
	/// <param name="UniqueId">The ID of the player to check if in session or not.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: in session</li>
	/// <li>`false`: not in session</li>
	/// </ul>
	/// </returns>
	virtual bool IsPlayerInSession(FName SessionName, const FUniqueNetId& UniqueId) override;

	/// <summary>Starts cloud-based matchmaking for a session.</summary>
	/// <param name="LocalPlayers">The IDs of all local players that will participate in the match.</param>
	/// <param name="SessionName">The name of the session to use.</param>
	/// <param name="NewSessionSettings">The desired settings to match against or create with when forming new sessions. `NumPrivateConnections` needs to be zero.</param>
	/// <param name="SearchSettings">The desired settings that the matched session will have.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool StartMatchmaking(const TArray< TSharedRef<const FUniqueNetId> >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings) override;

	/// <summary>Cancels a matchmaking request for a given session.</summary>
	/// <param name="SearchingPlayerNum">The index of the player canceling the search.</param>
	/// <param name="SessionName">The name of the session that was passed to `StartMatchmaking` (or `CreateSession`).</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool CancelMatchmaking(int32 SearchingPlayerNum, FName SessionName) override;
	virtual bool CancelMatchmaking(const FUniqueNetId& SearchingPlayerId, FName SessionName) override;

	/// <summary>Searches for sessions matching the settings specified.</summary>
	/// <param name="SearchingPlayerNum">The index of the player searching for a match.</param>
	/// <param name="SearchSettings">The desired settings that the returned sessions will have.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool FindSessions(int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings) override;
	virtual bool FindSessions(const FUniqueNetId& SearchingPlayerId, const TSharedRef<FOnlineSessionSearch>& SearchSettings) override;

	/// <summary>Finds a session by session ID.</summary>
	/// <param name="SearchingUserId">The ID of the user initiating the request.</param>
	/// <param name="SessionId">The session ID to search for.</param>
	/// <param name="FriendId">Not supported. Set it invalid.</param>
	/// <param name="CompletionDelegate">Will be executed when ppf_Room_Get is complete.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool FindSessionById(const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FOnSingleSessionResultCompleteDelegate& CompletionDelegate) override;
	virtual bool CancelFindSessions() override;
	virtual bool PingSearchResults(const FOnlineSessionSearchResult& SearchResult) override;

	/// <summary>Joins the session specified.</summary>
	/// <param name="PlayerNum">The index of the player searching for a match.</param>
	/// <param name="SessionName">The name of the session to join.</param>
	/// <param name="DesiredSession">The desired session to join.</param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	virtual bool JoinSession(int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession) override;
	virtual bool JoinSession(const FUniqueNetId& PlayerId, FName SessionName, const FOnlineSessionSearchResult& DesiredSession) override;

	virtual bool FindFriendSession(int32 LocalUserNum, const FUniqueNetId& Friend) override;
	virtual bool FindFriendSession(const FUniqueNetId& LocalUserId, const FUniqueNetId& Friend) override;
	virtual bool FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<TSharedRef<const FUniqueNetId>>& FriendList) override;
	
	virtual bool SendSessionInviteToFriend(int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend) override;
	virtual bool SendSessionInviteToFriend(const FUniqueNetId& LocalUserId, FName SessionName, const FUniqueNetId& Friend) override;
	virtual bool SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Friends) override;
	virtual bool SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Friends) override;
	virtual bool GetResolvedConnectString(FName SessionName, FString& ConnectInfo, FName PortType = NAME_GamePort) override;
	virtual bool GetResolvedConnectString(const class FOnlineSessionSearchResult& SearchResult, FName PortType, FString& ConnectInfo) override;
	virtual FOnlineSessionSettings* GetSessionSettings(FName SessionName) override;
	virtual bool RegisterPlayer(FName SessionName, const FUniqueNetId& PlayerId, bool bWasInvited) override;
	virtual bool RegisterPlayers(FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Players, bool bWasInvited = false) override;
	virtual bool UnregisterPlayer(FName SessionName, const FUniqueNetId& PlayerId) override;
	virtual bool UnregisterPlayers(FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Players) override;
	virtual void RegisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnRegisterLocalPlayerCompleteDelegate& Delegate) override;
	virtual void UnregisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnUnregisterLocalPlayerCompleteDelegate& Delegate) override;
	virtual int32 GetNumSessions() override;
	virtual void DumpSessionState() override;

	virtual TSharedPtr<const FUniqueNetId> CreateSessionIdFromString(const FString& SessionIdStr) override;
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
	void OnRoomInviteAccepted(ppfID RoomId);
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
	/// <summary>Initializes the game module.</summary>
	void Initialize();

	/// <summary>Uninitializes the game module.</summary>
	/// <returns>Always returns `true`.</returns>
	bool Uninitialize();

	/// <summary>Sets `InitSuccess` for the game module.</summary>
	/// <param name="State">
	/// <ul>
	/// <li>`true` when setting `InitSuccess` to `true`</li>
	/// <li>`false` when setting `InitSuccess` to `false`</li>
	/// </ul>
	/// </param>
	void SetInitState(bool State);

	/// <summary>Checks the current state of `InitSuccess`.</summary>
	/// <returns>The state of `InitSuccess`:
	/// <ul>
	/// <li>`true`</li>
	/// <li>`false`</li>
	/// </ul>
	/// </returns>
	bool IsInitSuccess() const;

	/// <summary>Forces to cancel matchmaking.</summary>
	void OnForcedCancelMatchmaking();

	/// <summary>Forces to leave the specified room.</summary>
	/// <param name="RoomID">The ID of the room to force leave.</param>
	void OnForcedLeaveRoom(ppfID RoomID);

	/// <summary>Checks `InProgressMatchmakingSearch` and `SearchState`.</summary>
	/// <returns>
	/// <ul>
	/// <li>`true` if `InProgressMatchmakingSearch` is `valid` and `SearchState` is `EOnlineAsyncTaskState::InProgress`</li>
	/// <li>`false`: otherwise</li>
	/// </ul>
	/// </returns>
	bool IsInMatchmakingProgress();

	FOnMatchmakingFoundComplete MatchmakingFoundCallback;
	FOnRoomUpdateComplete RoomUpdateCallback;
	
	FOnRoomInviteAcceptedComplete RoomInviteAcceptedCallback;
	FOnPicoSessionUserInviteAcceptedComplete PicoSessionUserInviteAcceptedCallback;

	FOnGameInitializeComplete GameInitializeCompleteCallback;
	FOnGameConnectionComplete GameConnectionCallback;
	FOnGameRequestFailedComplete GameRequestFailedCallback;
	FOnGameStateResetComplete GameStateResetCallback;
	FOnMatchmakingCancel2Complete MatchmakingCancel2Callback;
	FOnRoomLeaveComplete RoomLeaveCallback;
	FOnRoomJoin2Complete RoomJoin2Callback;
	FOnRoomUpdateOwnerComplete RoomUpdateOwnerCallback;
	// Not Used
	FOnRoomSetDescriptionComplete RoomSetDescriptionCallback;
	FOnRoomKickUserComplete RoomKickUserCallback;
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
/** @} */ // end of Session(OnlineSub)
/** @} */ // end of Function
typedef TSharedPtr<FOnlineSessionPico, ESPMode::ThreadSafe> FOnlineSessionPicoPtr;
