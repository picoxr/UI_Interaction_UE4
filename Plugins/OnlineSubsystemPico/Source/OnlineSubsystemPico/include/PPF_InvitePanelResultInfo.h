// This file was @generated with LibPPFPlatform/codegen/main. Do not modify it!


#ifndef PPF_INVITEPANELRESULTINFO_H
#define PPF_INVITEPANELRESULTINFO_H

#include "PPF_Platform_Defs.h"
#include <stdbool.h>

/// @file PPF_InvitePanelResultInfo.h
/// @ingroup Social

typedef struct ppfInvitePanelResultInfo *ppfInvitePanelResultInfoHandle;

/// A boolean for whether or not any invites has been sent.
PPF_PUBLIC_FUNCTION(bool) ppf_InvitePanelResultInfo_GetInvitesSent(const ppfInvitePanelResultInfoHandle obj);


#endif
