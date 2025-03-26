// This file is generated automatically. Please don't edit it.

#ifndef PPF_REQUESTS_USER_H
#define PPF_REQUESTS_USER_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

/// @file PPF_Requests_User.h
/// @ingroup UserFriends

/// @brief Retrieve the user with the given ID. This might fail if the ID is invalid.
/// 
/// @param  userID User ID retrieved with this application.
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessageType_User_Get will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type ::ppfUserHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUser().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_Get(const char* userID);

/// @brief Return an access token for current logged user, suitable for making REST calls.
///
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_GetAccessToken will be generated in response.
/// Call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type const char*.
/// Extract the payload from the message handle with ::ppf_Message_GetString()
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetAccessToken();


/// @brief Return an ID access token for current logged user.
///
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_GetIdToken will be generated in response.
/// Call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type const char*.
/// Extract the payload from the message handle with ::ppf_Message_GetString()
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetIdToken();

/// @brief Return the currently signed in user.
///
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_GetLoggedInUser will be generated in response.
/// Call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type ::ppfUserHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUser()
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetLoggedInUser();

/// @brief Retrieve a list of the logged in user's friends.
///
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_GetLoggedInUserFriends will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type ::ppfUserArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUserArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetLoggedInUserFriends();

/// @brief Get the next page of entries
///
/// @param param ...
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_GetNextUserArrayPage will be generated in response.
/// First call ::ppf_Message_IsError() to check if an error occurred.
/// If no error occurred, the message will contain a payload of type ::ppfUserArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUserArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetNextUserArrayPage(const char* param);

/// @brief Launch the flow for sending a friend request to a user.
///
/// @param userID User ID of user to send a friend request to
/// @return The request ID of this async function.
///
/// A message with type ::ppfMessage_User_LaunchFriendRequestFlow will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfLaunchFriendRequestFlowResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetLaunchFriendRequestFlowResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_LaunchFriendRequestFlow(const char* userID);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetLoggedInUserFriendsAndRooms();


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetNextUserAndRoomArrayPage(const char* param);


PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetAuthorizedPermissions();

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_RequestUserPermissions(const char** permissions, int size);

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetRelations(const char** userIds,int size);

//
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_EntitlementCheck(bool killApp);

/// returns an string id which is unique per org. allows different apps within the
/// same org to identify the user.
/// \param userID to load the org scoped id of
///
/// A message with type ::ppfMessageType_User_GetOrgScopedID will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfOrgScopedIDHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetOrgScopedID().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_User_GetOrgScopedID(const char* userID);
#endif

