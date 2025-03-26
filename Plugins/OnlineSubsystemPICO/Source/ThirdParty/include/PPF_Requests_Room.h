#ifndef PPF_REQUESTS_ROOM_H
#define PPF_REQUESTS_ROOM_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RoomArray.h"
#include "PPF_RoomJoinPolicy.h"
#include "PPF_RoomMembershipLockStatus.h"
#include "PPF_RoomOptions.h"
#include <stdbool.h>

/// @file PPF_Requests_Room.h
/// @ingroup Game

/// @brief Create a privated room and join it
/// @param joinPolicy Specifies who can join the room without an invite.
/// @param maxUsers The maximum number of users allowed in the room, including the creator.
/// @param roomOptions Additional room configuration for this request. Optional.
/// @return The request ID of this async function.
/// 
/// Privated room is good for matches where the user wants to play with
/// friends, as they're primarially discoverable by examining which rooms your
/// friends are in.
///
/// A message with type ::ppfMessageType_Room_CreateAndJoinPrivate2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_CreateAndJoinPrivate2(ppfRoomJoinPolicy joinPolicy, unsigned int maxUsers, ppfRoomOptionsHandle roomOptions);

/// @brief Get info of a specified room
/// @param roomID The room to load.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_Get will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_Get(ppfID roomID);

/// @brief Get info of current room
/// @return The request ID of this async function.
///
/// Easy loading of the room you're currently in. If you don't want live
/// updates on your current room (by using subscribeToUpdates), you can use
/// this to refresh the data.
///
/// A message with type ::ppfMessageType_Room_GetCurrent will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_GetCurrent();

/// @brief Get info of the current room for a specified user
/// @param userID ID of the user for which to load the room.
/// @return The request ID of this async function.
///
/// Remember that the user's privacy settings may not allow their room to be loaded. 
/// Because of this, it's often possible to load the users in a room, but not to take
/// those users and load their room.
///
/// A message with type ::ppfMessageType_Room_GetCurrentForUser will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_GetCurrentForUser(const char* userID);

/// @brief Loads a list of users you can invite to current room
/// @param roomOptions Additional configuration for this request. Optional.
/// @return The request ID of this async function.
///
/// The list are pulled from your friends list and recently met lists and filtered for relevance and
/// interest. If the room cannot be joined, this list will be empty. By
/// default, the invitable users returned will be for the user's current room.
///
/// Customization can be done via RoomOptions. Create this object with
/// ppf_RoomOptions_Create. The params that could be used are:
///
/// 1. ppf_RoomOptions_SetRoomId - should be your current room.
///
/// 2. ppf_RoomOptions_SetOrdering - (beta feature, don't use it) returns the list of users in the provided
/// ordering (see UserOrdering enum).
///
/// 3. ppf_RoomOptions_SetRecentlyMetTimeWindow - (beta feature, don't use it) how long long ago should we
/// include users you've recently met in the results?
///
/// 4. ppf_RoomOptions_SetMaxUserResults - we will limit the number of results
/// returned. By default, the number is unlimited, but the server may choose to
/// limit results for performance reasons.
///
/// 5. ppf_RoomOptions_SetExcludeRecentlyMet - (beta feature, don't use it) Don't include users recently in
/// rooms with this user in the result. Also, see the above comment.
///
/// Example custom C++ usage:
///
///   auto roomOptions = ppf_RoomOptions_Create();
///   ppf_RoomOptions_SetOrdering(roomOptions, ppfUserOrdering_PresenceAlphabetical);
///   ppf_RoomOptions_SetRoomId(roomOptions, roomID);
///   ppf_Room_GetInvitableUsers2(roomOptions);
///   ppf_RoomOptions_Destroy(roomOptions);
///
/// A message with type ::ppfMessageType_Room_GetInvitableUsers2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfUserArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUserArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_GetInvitableUsers2(ppfRoomOptionsHandle roomOptions);

/// @brief Fetches the list of moderated rooms created for the application.
/// @param page_idx start page index
/// @param page_size page entry number in response (should range in [5,20])
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_GetModeratedRooms will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoomArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_GetModeratedRooms(int32_t page_idx, int32_t page_size);

/// @brief Join(Create) a named room
/// @param joinPolicy current only support 'ppfRoom_JoinPolicyEveryone'.
/// @param createIfNotExist create new room, if the named room is currently not exist.
/// @param maxUsers The maximum number of users allowed in the room, including the creator.
/// @param roomOptions Additional room configuration for this request. Optional.
/// @return The request ID of this async function.
/// 
/// named room is good for public scene that can be joined to with a well-known name
///
/// A message with type ::ppfMessageType_Room_JoinNamed will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_JoinNamed(ppfRoomJoinPolicy joinPolicy, bool createIfNotExist, unsigned int maxUsers, ppfRoomOptionsHandle roomOptions);

/// @brief Fetches the list of named rooms created for the application.
/// @param page_idx start page index
/// @param page_size page entry number in response (should range in [5,20])
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_GetNamedRooms will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoomArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_GetNamedRooms(int32_t page_idx, int32_t page_size);

/// @brief Invites a user to the specified room. 
/// @param roomID The ID of your current room.
/// @param inviteToken A user's invite token, returned by ppf_Room_GetInvitableUsers().
/// @return The request ID of this async function.
///
/// The invitee will receive a notification via ppfNotification_Room_InviteReceived, and/or they
/// can poll for room invites using ppf_Notification_GetRoomInvites().
///
/// A message with type ::ppfMessageType_Room_InviteUser will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_InviteUser(ppfID roomID, const char *inviteToken);

/// @brief Joins the target room (leaving the one you're currently in).
/// @param roomID The room to join.
/// @param roomOptions Additional room configuration for this request. Optional.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_Join2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_Join2(ppfID roomID, ppfRoomOptionsHandle roomOptions);

/// @brief Kick a user out of the current room (caller should be the room owner).
/// @param roomID The room that you currently own (check ppf_Room_GetOwner()).
/// @param userID The user to be kicked (cannot be yourself).
/// @param kickDurationSeconds Length of the ban, in seconds.
/// @return The request ID of this async function.
/// 
/// A message with type ::ppfMessageType_Room_KickUser will be generated in response.
///
/// First call ::ppf_Room_Leavef_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_KickUser(ppfID roomID, const char* userID, int kickDurationSeconds);

/// @brief Launch the invitable user flow to invite to the logged in user's current room. 
/// @param roomID The room you're currently in.
/// @return The request ID of this async function.
///
/// This is intended to be a nice shortcut for developers not wanting to
/// build out their own Invite UI although it has the same rules as if you
/// build it yourself.
///
/// A message with type ::ppfMessageType_Room_LaunchInvitableUserFlow will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_LaunchInvitableUserFlow(ppfID roomID);

/// @brief Leave current room. 
/// @param roomID The room you're currently in.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_Leave will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom(), which is the left room info.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_Leave(ppfID roomID);

/// @brief Set the description of their room (caller should be the room owner).
/// @param roomID The room that you currently own (check ppf_Room_GetOwner()).
/// @param description The new name of the room.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_SetDescription will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_SetDescription(ppfID roomID, const char *description);

/// @brief Update data store of the current room (caller should be the room owner).
/// @param roomID The room that you currently own (check ppf_Room_GetOwner()).
/// @param data The key/value pairs to add or update; null values clear a given key.
/// @param numItems The length of data
/// @return The request ID of this async function.
///
/// NOTE: Room datastores only allow string values, and Max key length is 32 bytes, and max value length is 64 bytes.
/// If you provide illegal values, this returns an error. 
///
/// A message with type ::ppfMessageType_Room_UpdateDataStore will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_UpdateDataStore(ppfID roomID, ppfKeyValuePairArray data, unsigned int numItems);

/// @brief Lock/unlock the current room (caller should be the room owner).
/// @param roomID The room whose membership you want to lock or unlock.
/// @param membershipLockStatus The new LockStatus for the room
/// @return The request ID of this async function.
///
/// Allow/disallow new members from being able to join the room. This will prevent
/// joins from ppf_Room_Join2(), invites, etc. Users that are
/// in the room at the time of lockdown will be able to rejoin.
///
/// A message with type ::ppfMessageType_Room_UpdateMembershipLockStatus will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_UpdateMembershipLockStatus(ppfID roomID, ppfRoomMembershipLockStatus membershipLockStatus);

/// @brief Transfer ownership to someone else (caller should be the room owner).
/// @param roomID The room that the user owns (check ppf_Room_GetOwner()).
/// @param userID The new user to make an owner; the user must be in the room.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_UpdateOwner will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_UpdateOwner(ppfID roomID, const char* userID);

/// @brief Sets the join policy of the user's private room.
/// @param roomID The room ID that the user owns (check ppf_Room_GetOwner()).
/// @param newJoinPolicy The new join policy for the room.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_Room_UpdatePrivateRoomJoinPolicy will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Room_UpdatePrivateRoomJoinPolicy(ppfID roomID, ppfRoomJoinPolicy newJoinPolicy);

#endif
