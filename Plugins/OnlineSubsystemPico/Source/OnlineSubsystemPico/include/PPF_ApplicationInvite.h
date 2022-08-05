
/// @file PPF_ApplicationInvite.h
/// @ingroup Social

#ifndef MATRIX_PPF_APPLICATIONINVITE_H
#define MATRIX_PPF_APPLICATIONINVITE_H

typedef struct ppfApplicationInvite *ppfApplicationInviteHandle;

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
PPF_PUBLIC_FUNCTION(ppfDestinationHandle) ppf_ApplicationInvite_GetDestination(const ppfApplicationInviteHandle obj);

/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
PPF_PUBLIC_FUNCTION(ppfUserHandle) ppf_ApplicationInvite_GetRecipient(const ppfApplicationInviteHandle obj);

PPF_PUBLIC_FUNCTION(ppfID)        ppf_ApplicationInvite_GetID(const ppfApplicationInviteHandle obj);
PPF_PUBLIC_FUNCTION(bool)         ppf_ApplicationInvite_GetIsActive(const ppfApplicationInviteHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_ApplicationInvite_GetLobbySessionId(const ppfApplicationInviteHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_ApplicationInvite_GetMatchSessionId(const ppfApplicationInviteHandle obj);



#endif //MATRIX_PPF_APPLICATIONINVITE_H
