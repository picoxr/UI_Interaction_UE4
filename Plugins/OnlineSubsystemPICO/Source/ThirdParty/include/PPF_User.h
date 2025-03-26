// This file is generated automatically. Please don't edit it.

#ifndef PPF_USER_H
#define PPF_USER_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_UserPresenceStatus.h"
#include "PPF_Gender.h"

/// @defgroup UserFriends User&Friends
/// @file PPF_User.h
/// @ingroup UserFriends

typedef struct ppfUser *ppfUserHandle;

/// @brief Get A non unique displayable name from ppfUserHandle obj.
///
/// @param  obj the ppfUserHandle object.
/// @return The display name from this user obj.
///
PPF_PUBLIC_FUNCTION(const char*)ppf_User_GetDisplayName(const ppfUserHandle obj);

/// @brief Get the image URL from ppfUserHandle obj.
///
/// @param  obj the ppfUserHandle object.
/// @return The image URL from this user obj.
///
PPF_PUBLIC_FUNCTION(const char*)ppf_User_GetImageUrl(const ppfUserHandle obj);

/// @brief Get the openid from ppfUserHandle obj.
///
/// @param  obj the ppfUserHandle object.
/// @return The openid from this user obj.
///
PPF_PUBLIC_FUNCTION(const char*)ppf_User_GetID(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetInviteToken(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetSmallImageUrl(const ppfUserHandle obj);

/// @brief Get the enum value of what the user is currently doing.
///
/// @param  obj the ppfUserHandle object.
/// @return The enum value of user currently status.
///
PPF_PUBLIC_FUNCTION(ppfUserPresenceStatus) ppf_User_GetPresenceStatus(const ppfUserHandle obj);


PPF_PUBLIC_FUNCTION(ppfGender) ppf_User_GetGender(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresence(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresenceDeeplinkMessage(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresenceDestinationApiName(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresenceLobbySessionId(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresenceMatchSessionId(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresencePackage(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetPresenceExtra(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(bool) ppf_User_GetPresenceIsJoinable(const ppfUserHandle obj);

PPF_PUBLIC_FUNCTION(const char *)ppf_User_GetStoreRegion(const ppfUserHandle obj);

#endif

