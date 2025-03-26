#ifndef MATRIX_PPF_PRESENCEJOININTENT_H
#define MATRIX_PPF_PRESENCEJOININTENT_H

/// @file PPF_PresenceJoinIntent.h
/// @ingroup Social

typedef struct ppfPresenceJoinIntent *ppfPresenceJoinIntentHandle;

/// @brief An opaque string provided by the developer to help them deeplink to
/// content.
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceJoinIntent_GetDeeplinkMessage(const ppfPresenceJoinIntentHandle obj);

/// @brief If populated, the destination the current user wants to go to
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceJoinIntent_GetDestinationApiName(const ppfPresenceJoinIntentHandle obj);

/// @brief If populated, the lobby session the current user wants to go to
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceJoinIntent_GetLobbySessionId(const ppfPresenceJoinIntentHandle obj);

/// @brief If populated, the match session the current user wants to go to
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceJoinIntent_GetMatchSessionId(const ppfPresenceJoinIntentHandle obj);

/// @brief If populated, the extra data
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceJoinIntent_GetExtra(const ppfPresenceJoinIntentHandle obj);


#endif //MATRIX_PPF_PRESENCEJOININTENT_H
