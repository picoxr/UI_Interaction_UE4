#ifndef MATRIX_PPF_INVITEOPTIONS_H
#define MATRIX_PPF_INVITEOPTIONS_H

/// @file PPF_InviteOptions.h
/// @ingroup Social


typedef struct ppfInviteOptions* ppfInviteOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfInviteOptionsHandle) ppf_InviteOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_InviteOptions_Destroy(ppfInviteOptionsHandle handle);
/// Passing in these users will add them to the invitable users list
PPF_PUBLIC_FUNCTION(void) ppf_InviteOptions_AddSuggestedUser(ppfInviteOptionsHandle handle, const char* value);
PPF_PUBLIC_FUNCTION(void) ppf_InviteOptions_ClearSuggestedUsers(ppfInviteOptionsHandle handle);


#endif //MATRIX_PPF_INVITEOPTIONS_H
