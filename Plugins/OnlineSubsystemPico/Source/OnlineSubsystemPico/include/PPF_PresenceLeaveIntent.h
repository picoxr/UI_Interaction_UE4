#ifndef MATRIX_PPF_PRESENCELEAVEINTENT_H
#define MATRIX_PPF_PRESENCELEAVEINTENT_H

/// @file PPF_PresenceLeaveIntent.h
/// @ingroup Social

typedef struct ppfPresenceLeaveIntent *ppfPresenceLeaveIntentHandle;

/// @brief If populated, the destination the current user wants to leave
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceLeaveIntent_GetDestinationApiName(const ppfPresenceLeaveIntentHandle obj);

/// @brief If populated, the lobby session the current user wants to leave
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceLeaveIntent_GetLobbySessionId(const ppfPresenceLeaveIntentHandle obj);

/// @brief If populated, the match session the current user wants to leave
PPF_PUBLIC_FUNCTION(const char *) ppf_PresenceLeaveIntent_GetMatchSessionId(const ppfPresenceLeaveIntentHandle obj);


#endif //MATRIX_PPF_PRESENCELEAVEINTENT_H
