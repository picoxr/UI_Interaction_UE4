#ifndef MATRIX_PPF_DESTINATION_H
#define MATRIX_PPF_DESTINATION_H

/// @file PPF_Destination.h
/// @ingroup Social

typedef struct ppfDestination *ppfDestinationHandle;

/// Pass it into ppf_RichPresenceOptions_SetApiName() when calling
/// ppf_RichPresence_Set() to set this user's rich presence
PPF_PUBLIC_FUNCTION(const char *) ppf_Destination_GetApiName(const ppfDestinationHandle obj);

/// The information that will be in ppf_LaunchDetails_GetDeeplinkMessage() when
/// a user enters via a deeplink. Alternatively will be in
/// ppf_User_GetPresenceDeeplinkMessage() if the rich presence is set for the
/// user.
PPF_PUBLIC_FUNCTION(const char *) ppf_Destination_GetDeeplinkMessage(const ppfDestinationHandle obj);

PPF_PUBLIC_FUNCTION(const char *) ppf_Destination_GetDisplayName(const ppfDestinationHandle obj);


#endif //MATRIX_PPF_DESTINATION_H
