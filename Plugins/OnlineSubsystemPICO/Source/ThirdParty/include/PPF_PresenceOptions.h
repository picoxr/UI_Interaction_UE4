#ifndef MATRIX_PPF_PRESENCEOPTIONS_H
#define MATRIX_PPF_PRESENCEOPTIONS_H

/// @file PPF_PresenceOptions.h
/// @ingroup Social

typedef struct ppfPresenceOptions* ppfPresenceOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfPresenceOptionsHandle) ppf_PresenceOptions_Create();

PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_Destroy(ppfPresenceOptionsHandle handle);

/// @brief This the unique API Name that refers to an in-app destination
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetDestinationApiName(ppfPresenceOptionsHandle handle, const char * value);

/// @brief Set whether or not the person is shown as joinable or not to others. A user
/// that is joinable can invite others to join them. Set this to false if other
/// users would not be able to join this user. For example: the current session
/// is full, or only the host can invite others and the current user is not the
/// host.
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetIsJoinable(ppfPresenceOptionsHandle handle, bool value);

/// @brief This is a session that represents a closer group/squad/party of users. It
/// is expected that all users with the same lobby session id can see or hear
/// each other. Users with the same lobby session id in their group presence
/// will show up in the roster and will show up as "Recently Played With" for
/// future invites if they aren't already friends. This must be set in
/// addition to is_joinable being true for a user to use invites.
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetLobbySessionId(ppfPresenceOptionsHandle handle, const char * value);

/// @brief This is a session that represents all the users that are playing a specific
/// instance of a map, game mode, round, etc. This can include users from
/// multiple different lobbies that joined together and the users may or may
/// not remain together after the match is over. Users with the same match
/// session id in their group presence will not show up in the Roster, but will
/// show up as "Recently Played with" for future invites.
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetMatchSessionId(ppfPresenceOptionsHandle handle, const char * value);

/// @brief This is a session that represents custom param.
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetExtra(ppfPresenceOptionsHandle handle, const char * value);
/// @brief Set target app by package name.
PPF_PUBLIC_FUNCTION(void) ppf_PresenceOptions_SetTargetAppID(ppfPresenceOptionsHandle handle, const char * value);


#endif //MATRIX_PPF_PRESENCEOPTIONS_H
