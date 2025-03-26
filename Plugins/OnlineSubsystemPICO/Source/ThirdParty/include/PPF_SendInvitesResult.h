// This file was @generated with LibPPFPlatform/codegen/main. Do not modify it!

#ifndef PPF_SENDINVITESRESULT_H
#define PPF_SENDINVITESRESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_ApplicationInviteArray.h"

/// @file PPF_SendInvitesResult.h
/// @ingroup Social

typedef struct ppfSendInvitesResult *ppfSendInvitesResultHandle;

/// The list of invites that was sent
PPF_PUBLIC_FUNCTION(ppfApplicationInviteArrayHandle) ppf_SendInvitesResult_GetInvites(const ppfSendInvitesResultHandle obj);


#endif
