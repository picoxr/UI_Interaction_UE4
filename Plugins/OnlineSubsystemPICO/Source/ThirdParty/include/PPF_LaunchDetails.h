#ifndef MATRIX_PPF_LAUNCHDETAILS_H
#define MATRIX_PPF_LAUNCHDETAILS_H

#include "PPF_User.h"
#include "PPF_UserArray.h"
#include "PPF_LaunchType.h"

/// @file PPF_LaunchDetails.h
/// @ingroup Social

typedef struct ppfLaunchDetails *ppfLaunchDetailsHandle;

/// @brief An opaque string provided by the developer to help them deeplink to content
/// on app startup.
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetDeeplinkMessage(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended destination the user would like to go to
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetDestinationApiName(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended lobby the user would like to be in
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetLobbySessionID(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended session the user would like to be in
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetMatchSessionID(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended session the user would like to be in
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetExtra(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended room the user would like to be in
PPF_PUBLIC_FUNCTION(ppfID)
ppf_LaunchDetails_GetRoomID(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended challenge the user would like to be in
PPF_PUBLIC_FUNCTION(ppfID)
ppf_LaunchDetails_GetChallengeID(const ppfLaunchDetailsHandle obj);

/// @brief A unique identifer to keep track of a user going through the deeplinking
/// flow
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetTrackingID(const ppfLaunchDetailsHandle obj);


PPF_PUBLIC_FUNCTION(ppfLaunchType)
ppf_LaunchDetails_GetLaunchType(const ppfLaunchDetailsHandle obj);

PPF_PUBLIC_FUNCTION(const char*)
ppf_LaunchDetails_GetClientAction(const ppfLaunchDetailsHandle obj);

/// @brief A string typically used to distinguish where the deeplink came from. For
/// instance, a DEEPLINK launch type could be coming from events or rich
/// presence.
//Deprecated,use LaunchType
PPF_PUBLIC_FUNCTION(const char *)
ppf_LaunchDetails_GetLaunchSource(const ppfLaunchDetailsHandle obj);

/// @brief If provided, the intended users the user would like to be with
/// This method may return null. This indicates that the value is not present or that the curent
/// app or user is not permitted to access it.
// Deprecated,don't use this function.
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle)
ppf_LaunchDetails_GetUsers(const ppfLaunchDetailsHandle obj);

#endif // MATRIX_PPF_LAUNCHDETAILS_H
