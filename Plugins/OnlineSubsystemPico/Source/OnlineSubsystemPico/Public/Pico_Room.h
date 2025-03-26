// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "UObject/NoExportTypes.h"
#include "OnlineSubsystemPicoNames.h"
#include "PPF_Platform.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pico_Room.generated.h"
//

DECLARE_LOG_CATEGORY_EXTERN(PicoRoom, Log, All);

class UPico_User;
class UPico_DataStore;
class UPico_UserArray;
class UPico_Room;
class UPico_RoomArray;


/**
 * 
*/
DECLARE_MULTICAST_DELEGATE_FourParams(FRoomUpdateNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&, /*ErrorMessage*/ UPico_Room* /*Room*/);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRoomUpdateOwnerNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&/*ErrorMessage*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FRoomJoinNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&, /*ErrorMessage*/ UPico_Room* /*Room*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FRoomLeaveNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&, /*ErrorMessage*/ UPico_Room* /*Room*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FRoomInviteAcceptedNotify, bool, /*bIsError*/ int, /*ErrorCode*/ const FString&, /*ErrorMessage*/ const FString& /*RoomID*/);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FRoomLaunchInvitableUserFlow, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomUpdateDataStore, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomCreateAndJoinPrivate2, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGet, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGetCurrent, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGetCurrentForUser, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGetInvitableUsers2, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_UserArray*, UserArray);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGetModeratedRooms, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomArray*, RoomArray);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomInviteUser, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomJoin2, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomKickUser, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomLeave, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomSetDescription, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomUpdateMembershipLockStatus, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FRoomUpdateOwner, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomUpdatePrivateRoomJoinPolicy, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomJoinOrCreateNamedRoom, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room*, Room);
DECLARE_DYNAMIC_DELEGATE_FourParams(FRoomGetNamedRooms, bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomArray*, RoomArray);
// FRoom_LaunchInvitableUserFlow
// FRoom_GetNextRoomArrayPage

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Room Room
 *  This is the Room group
 *  @{
 */

/// @brief PicoRoomInterface class.
class ONLINESUBSYSTEMPICO_API FPicoRoomInterface
{
private:
	FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoRoomInterface(FOnlineSubsystemPico& InSubsystem);
	~FPicoRoomInterface();

	FDelegateHandle RoomUpdateHandle;
	void OnRoomUpdateNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle RoomUpdateOwnerHandle;
	void OnRoomUpdateOwnerNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle RoomJoinHandle;
	void OnRoomJoinNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle RoomLeaveHandle;
	void OnRoomLeaveNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle RoomInviteAcceptedHandle;
	void OnRoomInviteAcceptedNotification(ppfMessageHandle Message, bool bIsError);
	
	FRoomUpdateNotify RoomUpdateNotify;
	FRoomUpdateOwnerNotify RoomUpdateOwnerNotify;
	FRoomJoinNotify RoomJoinNotify;
	FRoomLeaveNotify RoomLeaveNotify;
	FRoomInviteAcceptedNotify RoomInviteAcceptedNotify;

	FRoomLaunchInvitableUserFlow LaunchInvitableUserFlowDelegate;
	FRoomUpdateDataStore UpdateDataStoreDelegate;
	FRoomCreateAndJoinPrivate2 CreateAndJoinPrivate2Delegate;
	FRoomGet GetDelegate;
	FRoomGetCurrent GetCurrentDelegate;
	FRoomGetCurrentForUser GetCurrentForUserDelegate;
	FRoomGetInvitableUsers2 GetInvitableUsers2Delegate;
	FRoomGetModeratedRooms GetModeratedRoomsDelegate;
	FRoomInviteUser InviteUserDelegate;
	FRoomJoin2 Join2Delegate;
	FRoomKickUser KickUserDelegate;
	FRoomLeave LeaveDelegate;
	FRoomSetDescription SetDescriptionDelegate;
	FRoomUpdateMembershipLockStatus UpdateMembershipLockStatusDelegate;
	FRoomUpdateOwner UpdateOwnerDelegate;
	FRoomUpdatePrivateRoomJoinPolicy UpdatePrivateRoomJoinPolicyDelegate;
	FRoomJoinOrCreateNamedRoom JoinOrCreateNamedRoomDelegate;
	FRoomGetNamedRooms GetNamedRoomsDelegate;

    /// <summary>Launches the invitation flow to let the current user invite friends to a specified room. 
	/// This launches the system default invite UI where the user can select friends to invite and then send invitations to them. 
	/// Therefore, this is a shortcut if you do not want to build the invite UI by yourself.</summary>
	/// <param name="RoomID">The ID of the room.</param>
    /// <param name="OnLaunchInvitableUserFlowCallback">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool LaunchInvitableUserFlow(const FString& RoomID, FRoomLaunchInvitableUserFlow OnLaunchInvitableUserFlowCallback);

	/// <summary>Updates the data store of the current room (the caller should be the room owner).
	/// @note Room data stores only allow string values. The maximum key length is 32 bytes and the maximum value length is 64 bytes.
	/// If you provide illegal values, this method will return an error.</summary>
	/// <param name="roomId">The ID of the room that you currently own (call `Room.OwnerOptional` to check).</param>
	/// <param name="data">The key/value pairs to add or update. Null value will clear a given key.</param>
    /// <param name="OnUpdateDataStoreCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool UpdateDataStore(const FString& RoomID, const TMap<FString, FString>& Data, FRoomUpdateDataStore OnUpdateDataStoreCallback);

	/// <summary>Creates a new private room and joins it.
	/// @note This type of room can be obtained by querying the room where
	/// a friend is, so it is suitable for playing with friends.</summary>
	///
	/// <param name="JoinPolicy">Specifies who can join the room:
	/// * `0`: nobody
	/// * `1`: everybody
	/// * `2`: friends of members
	/// * `3`: friends of the room owner
	/// * `4`: invited users
	/// * `5`: unknown
	/// </param>
	/// <param name="MaxUsers">The maximum number of members allowed in the room, including the room creator.</param>
	/// <param name="RoomOptions">Room configuration for this request.</param>
    /// <param name="OnCreateAndJoinPrivate2Callback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns> 
	bool CreateAndJoinPrivate2(ERoomJoinPolicy JoinPolicy, uint32 MaxUsers, FPicoRoomOptions RoomOptions, FRoomCreateAndJoinPrivate2 OnCreateAndJoinPrivate2Callback);
	
	/// <summary>Gets the information about a specified room.</summary>
	/// <param name="RoomID">The ID of the room to get information for.</param>
    /// <param name="OnGetCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool Get(const FString& RoomID, FRoomGet OnGetCallback);

	/// <summary>Gets the data of the room you are currently in.</summary>
    /// <param name="OnGetCurrentCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool GetCurrent(FRoomGetCurrent OnGetCurrentCallback);

	/// <summary>Gets the current room of the specified user.
	/// @note The user's privacy settings may not allow you to access their room.
	/// </summary>
	///
	/// <param name="UserId">The ID of the user.</param>
    /// <param name="OnGetCurrentForUserCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool GetCurrentForUser(const FString& UserId, FRoomGetCurrentForUser OnGetCurrentForUserCallback);

	/// <summary>Gets a list of members the user can invite to the room.
	/// These members are drawn from the user's friends list and recently
	/// encountered list, and filtered based on relevance and interests.</summary>
	///
	/// <param name="roomOptions">Additional configuration for this request.
	/// If you pass `null`, the response will return code `0`.</param>
    /// <param name="OnGetInvitableUsers2Callback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool GetInvitableUsers2(FPicoRoomOptions roomOptions, FRoomGetInvitableUsers2 OnGetInvitableUsers2Callback);

	/// <summary>
	/// Gets the list of moderated rooms created for the application.
	/// The payload returned is `roomarray`. The room info contained in `roomarray` does not include userlist info.
	/// </summary>
	///
	/// <param name="index">Start page index.</param>
	/// <param name="size">Page entry number in response (should range from `5` to `20`).</param>
    /// <param name="OnGetModeratedRoomsCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomArray *, RoomArray).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool GetModeratedRooms(int PageIndex, int PageSize, FRoomGetModeratedRooms OnGetModeratedRoomsCallback);

	/// <summary>Invites a user to the current room.
	/// @note  The user invited will receive a notification of type `MessageType.Notification_Room_InviteReceived`.
	/// </summary>
	///
	/// <param name="roomId">The ID of the room.</param>
	/// <param name="token">The user's invitation token, which is returned by `RoomService.GetInvitableUsers2()`.</param>
    /// <param name="OnInviteUserCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool InviteUser(const FString& RoomID, const FString& Token, FRoomInviteUser OnInviteUserCallback);


	/// <summary>Joins the target room and meanwhile leaves the current room.</summary>
	///
	/// <param name="RoomID">The ID of the room to join.</param>
	/// <param name="options">(Optional) Additional room configuration for this request.</param>
    /// <param name="OnJoin2Callback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool Join2(const FString& RoomID, FPicoRoomOptions options, FRoomJoin2 OnJoin2Callback);

	/// <summary>Kicks a user out of a room. For use by homeowners only.</summary>
	///
	/// <param name="RoomID">The ID of the room.</param>
	/// <param name="UserID">The ID of the user to be kicked (cannot be yourself).</param>
	/// <param name="kickDuration">The Length of the ban (in seconds).</param>
    /// <param name="OnKickUserCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool KickUser(const FString& RoomID, const FString& UserID, int KickDurationSeconds, FRoomKickUser OnKickUserCallback);

	/// <summary>Leaves the current room.
	/// @note  The room you are now in will be returned if the request succeeds.</summary>
	///
	/// <param name="RoomID">The ID of the room.</param>
    /// <param name="OnLeaveCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool Leave(const FString& RoomID, FRoomLeave OnLeaveCallback);

	/// <summary>Sets the description of a room.  For use by homeowners only.</summary>
	///
	/// <param name="RoomID">The ID of the room to set description for.</param>
	/// <param name="Description">The new description of the room.</param>
    /// <param name="OnSetDescriptionCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool SetDescription(const FString& RoomID, const FString& Description, FRoomSetDescription OnSetDescriptionCallback);

	/// <summary>Locks/unlocks the membership of a room (the caller should be the room owner) to allow/disallow new members from being able to join the room.
	/// @note  Locking membership will prevent other users from joining the room through `Join2()`, invitations, etc. Users that are in the room at the time of lock will be able to rejoin.</summary>
	///
	/// <param name="RoomID">The ID of the room to lock/unlock membership for.</param>
	/// <param name="MembershipLockStatus">The new membership status to set for the room:
	/// * `0`: Unknown
	/// * `1`: lock
	/// * `2`: unlock
	/// </param>
    /// <param name="OnUpdateMembershipLockStatusCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool UpdateMembershipLockStatus(const FString& RoomID, ERoomMembershipLockStatus MembershipLockStatus, FRoomUpdateMembershipLockStatus OnUpdateMembershipLockStatusCallback);

	/// <summary>Modifies the owner of the room, this person needs to be the person in this room.</summary>
	///
	/// <param name="RoomID">The ID of the room to change ownership for.</param>
	/// <param name="UserID">The ID of the new user to own the room. The new user must be in the same room.</param>
    /// <param name="OnUpdateOwnerCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool UpdateOwner(const FString& RoomID, const FString& UserID, FRoomUpdateOwner OnUpdateOwnerCallback);

	/// <summary>Sets the join policy for a specified private room.</summary>
	///
	/// <param name="RoomID">The ID of the room you want to set join policy for.</param>
	/// <param name="JoinPolicy">Specifies who can join the room:
	/// * `0`: nobody
	/// * `1`: everybody
	/// * `2`: friends of members
	/// * `3`: friends of the room owner
	/// * `4`: invited users
	/// * `5`: unknown
	/// </param>
    /// <param name="OnUpdatePrivateRoomJoinPolicyCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool UpdatePrivateRoomJoinPolicy(const FString& RoomID, ERoomJoinPolicy JoinPolicy, FRoomUpdatePrivateRoomJoinPolicy OnUpdatePrivateRoomJoinPolicyCallback);

	/// <summary>Fetches the list of named rooms created in the app.</summary>
	///
	/// <param name="PageIndex">Start page index.</param>
	/// <param name="PageSize">The number of entries to return on each page. Range from `5` to `20`.</param>
	/// <param name="OnGetNamedRoomsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool GetNamedRooms(int PageIndex, int PageSize, FRoomGetNamedRooms OnGetNamedRoomsCallback);

	/// <summary>Join or create a named room.</summary>
	///
	/// <param name="JoinPolicy">Specifies who can join the room. Currently only supports 'RoomJoinPolicy Everyone.'</param>
	/// <param name="CreateIfNotExist">Create a new room if the named room does not exist.</param>
	/// <param name="MaxUsers">The maximum number of users allowed in the room, including the creator.</param>
	/// <param name="Options">Additional room configuration for this request. Optional.</param>
	/// <param name="OnRoomJoinOrCreateNamedRoomCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>  
	bool JoinOrCreateNamedRoom(ERoomJoinPolicy JoinPolicy, bool CreateIfNotExist, uint32 MaxUsers, FPicoRoomOptions Options, FRoomJoinOrCreateNamedRoom OnRoomJoinOrCreateNamedRoomCallback);

private:
	ppfRoomOptions* GetppfRoomOptions(FPicoRoomOptions PicoRoomOptions);
	
	ppfRoomJoinPolicy GetppfRoomJoinPolicy(ERoomJoinPolicy JoinPolicy);
	ppfID GetppfID(const FString& StringID);
	ppfRoomMembershipLockStatus GetppfRoomMembershipLockStatus(ERoomMembershipLockStatus RoomMembershipLockStatus);
};

/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_Room BP_Room
 *  This is the BP_Room group
 *  @{
 */

/// @brief OnlinePicoRoom Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoRoomFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	/// <summary>Gets the friends of the logged-in user and the rooms the friends might be in. If a friend is not in any room, the 'room' field will be null.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room.</param>
    /// <param name="InGetLoggedInuserFriendsAndRoomsCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void LaunchInvitableUserFlow(UObject* WorldContextObject, const FString& RoomID, FRoomLaunchInvitableUserFlow OnLaunchInvitableUserFlowCallback);

	/// <summary>Updates the data store of the current room (the caller should be the room owner).
	/// @note Room data stores only allow string values. The maximum key length is 32 bytes and the maximum value length is 64 bytes.
	/// If you provide illegal values, this method will return an error.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="roomId">The ID of the room that you currently own (call `Room.OwnerOptional` to check).</param>
	/// <param name="data">The key/value pairs to add or update. Null value will clear a given key.</param>
    /// <param name="OnUpdateDataStoreCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void UpdateDataStore(UObject* WorldContextObject, const FString& RoomID, const TMap<FString, FString>& Data, FRoomUpdateDataStore OnUpdateDataStoreCallback);

	/// <summary>Creates a new private room and joins it.
	/// @note This type of room can be obtained by querying the room where
	/// a friend is, so it is suitable for playing with friends.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="JoinPolicy">Specifies who can join the room:
	/// * `0`: nobody
	/// * `1`: everybody
	/// * `2`: friends of members
	/// * `3`: friends of the room owner
	/// * `4`: invited users
	/// * `5`: unknown
	/// </param>
	/// <param name="MaxUsers">The maximum number of members allowed in the room, including the room creator.</param>
	/// <param name="RoomOptions">Room configuration for this request.</param>
    /// <param name="OnCreateAndJoinPrivate2Callback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void CreateAndJoinPrivate2(UObject* WorldContextObject, ERoomJoinPolicy JoinPolicy, int32 MaxUsers, FPicoRoomOptions RoomOptions, FRoomCreateAndJoinPrivate2 OnCreateAndJoinPrivate2Callback);

	/// <summary>Gets the information about a specified room.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room to get information for.</param>
    /// <param name="OnGetCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void Get(UObject* WorldContextObject, const FString& RoomID, FRoomGet OnGetCallback);

	/// <summary>Gets the data of the room you are currently in.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="OnGetCurrentCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void GetCurrent(UObject* WorldContextObject, FRoomGetCurrent OnGetCurrentCallback);

	/// <summary>Gets the current room of the specified user.
	/// @note The user's privacy settings may not allow you to access their room.
	/// </summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="UserId">The ID of the user.</param>
    /// <param name="OnGetCurrentForUserCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void GetCurrentForUser(UObject* WorldContextObject, const FString& UserId, FRoomGetCurrentForUser OnGetCurrentForUserCallback);

	/// <summary>Gets a list of members the user can invite to the room.
	/// These members are drawn from the user's friends list and recently
	/// encountered list, and filtered based on relevance and interests.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomOptions">Additional configuration for this request.
	/// If you pass `null`, the response will return code `0`.</param>
    /// <param name="OnGetInvitableUsers2Callback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void GetInvitableUsers2(UObject* WorldContextObject, FPicoRoomOptions RoomOptions, FRoomGetInvitableUsers2 OnGetInvitableUsers2Callback);

    /// <summary>
    /// Gets the list of moderated rooms created for the application.
    /// The payload returned is `roomarray`. The room info contained in `roomarray` does not include userlist info.
    /// </summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="PageIndex">Start page index.</param>
	/// <param name="PageSize">The number of entries to return on each page. Range from `5` to `20`.</param>
    /// <param name="OnGetModeratedRoomsCallback">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_RoomArray *, RoomArray).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void GetModeratedRooms(UObject* WorldContextObject, int PageIndex, int PageSize, FRoomGetModeratedRooms OnGetModeratedRoomsCallback);

	/// <summary>Invites a user to the current room.
	/// @note  The user invited will receive a notification of type `MessageType.Notification_Room_InviteReceived`.
	/// </summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room.</param>
	/// <param name="Token">The user's invitation token, which is returned by `RoomService.GetInvitableUsers2()`.</param>
    /// <param name="OnInviteUserCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void InviteUser(UObject* WorldContextObject, const FString& RoomID, const FString& Token, FRoomInviteUser OnInviteUserCallback);


	/// <summary>Joins the target room and meanwhile leaves the current room.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room to join.</param>
	/// <param name="RoomOptions">(Optional) Additional room configuration for this request.</param>
    /// <param name="OnJoin2Callback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void Join2(UObject* WorldContextObject, const FString& RoomID, FPicoRoomOptions RoomOptions, FRoomJoin2 OnJoin2Callback);

	/// <summary>Kicks a user out of a room. For use by homeowners only.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room.</param>
	/// <param name="UserID">The ID of the user to be kicked (cannot be yourself).</param>
	/// <param name="KickDurationSeconds">The Length of the ban (in seconds).</param>
    /// <param name="OnKickUserCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void KickUser(UObject* WorldContextObject, const FString& RoomID, const FString& UserID, int32 KickDurationSeconds, FRoomKickUser OnKickUserCallback);

	/// <summary>Leaves the current room.
	/// @note  The room you are now in will be returned if the request succeeds.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room.</param>
    /// <param name="OnLeaveCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void Leave(UObject* WorldContextObject, const FString& RoomID, FRoomLeave OnLeaveCallback);

	/// <summary>Sets the description of a room.  For use by homeowners only.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room to set description for.</param>
	/// <param name="Description">The new description of the room.</param>
    /// <param name="OnSetDescriptionCallback">Will be executed when the request has been completed.   
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void SetDescription(UObject* WorldContextObject, const FString& RoomID, const FString& Description, FRoomSetDescription OnSetDescriptionCallback);

	/// <summary>Locks/unlocks the membership of a room (the caller should be the room owner) to allow/disallow new members from being able to join the room.
	/// @note  Locking membership will prevent other users from joining the room through `Join2()`, invitations, etc. Users that are in the room at the time of lock will be able to rejoin.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room to lock/unlock membership for.</param>
	/// <param name="MembershipLockStatus">The new membership status to set for the room:
	/// * `0`: Unknown
	/// * `1`: lock
	/// * `2`: unlock
	/// </param>
    /// <param name="OnUpdateMembershipLockStatusCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room") 
	static void UpdateMembershipLockStatus(UObject* WorldContextObject, const FString& RoomID, ERoomMembershipLockStatus MembershipLockStatus, FRoomUpdateMembershipLockStatus OnUpdateMembershipLockStatusCallback);

	/// <summary>Modifies the owner of the room, this person needs to be the person in this room.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room to change ownership for.</param>
	/// <param name="UserID">The ID of the new user to own the room. The new user must be in the same room.</param>
    /// <param name="OnUpdateOwnerCallback">Will be executed when the request has been completed.    
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void UpdateOwner(UObject* WorldContextObject, const FString& RoomID, const FString& UserID, FRoomUpdateOwner OnUpdateOwnerCallback);

	/// <summary>Sets the join policy for a specified private room.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="RoomID">The ID of the room you want to set join policy for.</param>
	/// <param name="JoinPolicy">Specifies who can join the room:
	/// * `0`: nobody
	/// * `1`: everybody
	/// * `2`: friends of members
	/// * `3`: friends of the room owner
	/// * `4`: invited users
	/// * `5`: unknown
	/// </param>
    /// <param name="OnUpdatePrivateRoomJoinPolicyCallback">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_Room *, Room).</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void UpdatePrivateRoomJoinPolicy(UObject* WorldContextObject, const FString& RoomID, ERoomJoinPolicy JoinPolicy, FRoomUpdatePrivateRoomJoinPolicy OnUpdatePrivateRoomJoinPolicyCallback);
	
	/// <summary>Fetches the list of named rooms created for the application.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="PageIndex">Start page index.</param>
	/// <param name="PageSize">The number of entries to return on each page. Range from `5` to `20`.</param>
	/// <param name="OnGetNamedRoomsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void GetNamedRooms(UObject* WorldContextObject, int PageIndex, int PageSize, FRoomGetNamedRooms OnGetNamedRoomsCallback);

	/// <summary>Joins or creates a named room.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="JoinPolicy">Specifies who can join the room. Currently only supports 'RoomJoinPolicy Everyone.'</param>
	/// <param name="CreateIfNotExist">Create a new room if the named room does not exist.</param>
	/// <param name="MaxUsers">The maximum number of users allowed in the room, including the creator.</param>
	/// <param name="Options">Additional room configuration for this request. Optional.</param>
	/// <param name="OnRoomJoinOrCreateNamedRoomCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Room")
	static void JoinOrCreateNamedRoom(UObject* WorldContextObject, ERoomJoinPolicy JoinPolicy, bool CreateIfNotExist, int32 MaxUsers, FPicoRoomOptions Options, FRoomJoinOrCreateNamedRoom OnRoomJoinOrCreateNamedRoomCallback);

	/// <summary>Get the room options for creating a private room. You can use it when you call 'CreateAndJoinPrivate2'.</summary>
	/// <param name="DataStoreKey">The key to add.</param>
	/// <param name="DataStoreValue">The value to add.</param>
	/// <returns>The room options for creating a private room.</returns>  
	UFUNCTION(BlueprintPure, Category = "OnlinePico|Room")
	static FPicoRoomOptions GetCreatePrivateRoomOptions(const FString& DataStoreKey, const FString& DataStoreValue);

	/// <summary>Get the room options for create a named room. You can use it when you call 'JoinOrCreateNamedRoom'.</summary>
	/// <param name="DataStoreKey">The key to add.</param>
	/// <param name="DataStoreValue">The value to add.</param>
	/// <param name="Name">The name of the named room.</param>
	/// <param name="Password">The password of the named room.</param>
	/// <returns>The room options for creating a named room.</returns>  
	UFUNCTION(BlueprintPure, Category = "OnlinePico|Room")
	static FPicoRoomOptions GetJoinOrCreateNamedRoomOptions(const FString& DataStoreKey, const FString& DataStoreValue, const FString& Name, const FString& Password);
};

/** @} */
/** @} */


/// @brief UPico_Room class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Room : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UPico_DataStore* DataStore = nullptr;

	UPROPERTY()
	UPico_User* Owner = nullptr;

	UPROPERTY()
	UPico_UserArray* Users = nullptr;

	FString Description = FString();

	ppfID ID = 0;

	FString RoomName = FString();

	FString RoomID = FString();

	bool bIsMembershipLocked = false;

	ERoomJoinPolicy RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyUnknown;

	ERoomJoinabilit RoomJoinabilit = ERoomJoinabilit::JoinabilityUnknown;

	int32 MaxUserNum = 0;

	ERoomType RoomType = ERoomType::TypeUnknown;

	int32 PlayerNum = 0;

public:
	void InitParams(ppfRoomHandle InRoomHandle);

	/** @brief Get the datastore that stores a room's metadata. The maximum datastore key length is 32 bytes and the maximum datastore value length is 64 bytes. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	UPico_DataStore* GetDataStore();

	/** @brief Get the room owner. This field can be null. Need to check whether it is null before use. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	UPico_User* GetOwner();

	/** @brief Get the room members. This field can be null. Need to check whether it is null before use. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	UPico_UserArray* GetUsers();

	/** @brief Room description. The maximum length is 128 bytes. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	FString GetDescription();

	/** @brief Room name. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	FString GetName();

	ppfID GetppfID();

	/** @brief Room ID. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	FString GetRoomID();

	/** @brief Whether the room is locked. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	bool GetIsMembershipLocked();

	/** @brief Room's join policy. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	ERoomJoinPolicy GetJoinPolicy();

	/** @brief Room's joinability. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	ERoomJoinabilit GetJoinability();

	/** @brief The maximum number of users allowed to join a room, which is `100`. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	int32 GetMaxUsers();

	/** @brief The number of users in the room. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	int32 GetPlayerNumber();

	/** @brief Room type. */
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	ERoomType GetRoomType();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
	FString GetDebugString();
};


/// @brief UPico_RoomArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_RoomArray : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TArray<UPico_Room*> RoomArray;
	int32 Size = 0;
	int32 TotalSize = 0;
	bool bHasNextPage;
	int32 PageIndex = 0;
	int32 PageSize = 0;
public:
	void InitParams(ppfRoomArrayHandle InppfRoomArrayHandle);

	/** @brief Get RoomArray element form Index.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	UPico_Room* GetElement(int32 Index);
	
	/** @brief Get the size of RoomArray .*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	int32 GetSize();
    
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	int32 GetTotalSize();

	/** @brief Get whether the list has the next page.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	bool HasNextPage();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	int32 GetPageIndex();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	int32 GetPageSize();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room Array")
	FString GetDebugString();
};
