#ifndef MATRIX_PPF_ROSTEROPTIONS_H
#define MATRIX_PPF_ROSTEROPTIONS_H

/// @file PPF_RosterOptions.h
/// @ingroup Social

typedef struct ppfRosterOptions* ppfRosterOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfRosterOptionsHandle) ppf_RosterOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_RosterOptions_Destroy(ppfRosterOptionsHandle handle);
/// @brief Passing in these users will add them to the invitable users list. From the
/// roster panel, the user can open the invite list, where the suggested users
/// will be added.
PPF_PUBLIC_FUNCTION(void) ppf_RosterOptions_AddSuggestedUser(ppfRosterOptionsHandle handle, ppfID value);
PPF_PUBLIC_FUNCTION(void) ppf_RosterOptions_ClearSuggestedUsers(ppfRosterOptionsHandle handle);


#endif //MATRIX_PPF_ROSTEROPTIONS_H
