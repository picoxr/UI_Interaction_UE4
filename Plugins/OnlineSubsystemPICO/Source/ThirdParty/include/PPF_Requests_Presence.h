#ifndef MATRIX_PPF_REQUESTS_PRESENCE_H
#define MATRIX_PPF_REQUESTS_PRESENCE_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
#include "PPF_PresenceOptions.h"
#include "PPF_ShareMediaOptions.h"
#include "PPF_InviteOptions.h"

/// @file PPF_Requests_Presence.h
/// @ingroup Social

/// @brief Clear group presence for running app
///
/// A message with type ::ppfMessage_Presence_Clear will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_Clear();

/// @brief Returns a list of users that can be invited to your current lobby. These
/// are pulled from your friends and recently met lists.
///
/// A message with type ::ppfMessage_Presence_GetInvitableUsers will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfUserArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetUserArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_GetInvitableUsers(ppfInviteOptionsHandle options);

/// @brief Get the next page of entries
///
/// A message with type ::ppfMessage_Presence_GetNextApplicationInviteArrayPage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfApplicationInviteArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetApplicationInviteArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_GetNextApplicationInviteArrayPage(const char *params);

/// @brief Returns a list of users that can be invited to your current lobby. These
/// are pulled from your friends and recently met lists.
///
/// A message with type ::ppfMessage_Presence_GetSentInvites will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfApplicationInviteArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetApplicationInviteArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_GetSentInvites();

/// @brief Returns a list of users that can be invited to your current lobby. These
/// are pulled from your friends and recently met lists.
///
/// A message with type ::ppfMessage_Presence_SendInvites will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfSendInvitesResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetSendInvitesResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SendInvites(const char **userIDs, unsigned int userIDLength);
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SendCustomInvites(const char*msg,const char **userIDs, unsigned int userIDLength);

/// @brief Set group presence for running app
///
/// A message with type ::ppfMessage_GroupPresence_Set will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_Set(ppfPresenceOptionsHandle presenceOptions);

/// @brief Replaces the user's current destination for the provided one. All other
/// existing group presence parameters will remain the same.
///
/// A message with type ::ppfMessage_Presence_SetDestination will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SetDestination(const char *api_name);

/// @brief Set if the current user's destination and session is joinable while keeping
/// the other group presence parameters the same. If the destination or session
/// ids of the user is not set, they cannot be set to joinable.
///
/// A message with type ::ppfMessage_Presence_SetIsJoinable will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SetIsJoinable(bool is_joinable);

/// @brief Replaces the user's current lobby session id for the provided one. All
/// other existing group presence parameters will remain the same.
///
/// A message with type ::ppfMessage_Presence_SetLobbySession will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SetLobbySession(const char *id);

/// @brief Replaces the user's current match session id for the provided one. All
/// other existing group presence parameters will remain the same.
///
/// A message with type ::ppfMessage_Presence_SetMatchSession will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SetMatchSession(const char *id);

/// @brief Replaces the user's custom param.
///
/// A message with type ::ppfMessage_Presence_SetExtra will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_SetExtra(const char *extra);

/// @brief Gets all the destinations that the presence can be set to
///
/// A message with type ::ppfMessage_RichPresence_GetDestinations will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfDestinationArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetDestinationArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_GetDestinations();


/// @brief Get the next page of entries
///
/// A message with type ::ppfMessage_RichPresence_GetNextDestinationArrayPage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfDestinationArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetDestinationArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_GetNextDestinationArrayPage(const char *params);

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_ShareMedia(ppfShareMediaOptionsHandle shareMediaOptions);

// 调起邀请好友面板
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Presence_LaunchInvitePanel();


#endif //MATRIX_PPF_REQUESTS_PRESENCE_H
