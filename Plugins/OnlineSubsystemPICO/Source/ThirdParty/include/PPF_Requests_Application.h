#ifndef MATRIX_PPF_REQUESTS_APPLICATION_H
#define MATRIX_PPF_REQUESTS_APPLICATION_H

/// @file PPF_Requests_Application.h
/// @ingroup Social

/// *** Application Overview:
/// An application is what you're writing! These requests/methods will allow you to
/// pull basic metadata about your application.

/// @brief Launches a different application in the user's library. If the user does
/// not have that application installed, they will be taken to that app's page
/// in the Pico Store
/// @param packageName The packageName of the app to launch
/// @param deeplink_options Additional configuration for this requests. Optional.
///
/// A message with type ::ppfMessageType_Application_LaunchOtherApp will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ppf_Message_GetString().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_LaunchOtherApp(const char *packageName, ppfApplicationOptionsHandle deeplink_options);

/// @brief Launches a different application in the user's library. If the user does
/// not have that application installed, they will be taken to that app's page
/// in the Pico Store
/// @param appID The appId of the app to launch
/// @param deeplink_options Additional configuration for this requests. Optional.
///
/// A message with type ::ppfMessageType_Application_LaunchOtherApp will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ppf_Message_GetString().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_LaunchOtherAppByAppID(const char *appID, ppfApplicationOptionsHandle deeplink_options);

/// @brief Launches a different application in the user's library. If the user does
/// not have that application installed, they will be taken to that app's page
/// in the Pico Store
/// @param appID The ID of the app to launch
/// @param packageName The package name of the app to launch
/// @param options Additional configuration for this requests
///
/// A message with type ::ppfMessageType_Application_LaunchOtherAppByPresence will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ppf_Message_GetString().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_LaunchOtherAppByPresence(const char *appID, const char *packageName, ppfApplicationByPresenceOptionsHandle options);

/// @brief Launches a different application in the user's library. If the user does
/// not have that application installed, they will be taken to that app's page
/// in the Pico Store
/// @param options Additional configuration for this requests
///
/// A message with type ::ppfMessageType_Application_LaunchOtherAppByMessage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type const char *.
/// Extract the payload from the message handle with ::ppf_Message_GetString().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_LaunchOtherAppByMessage(ppfApplicationByMessageOptionsHandle options);

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_GetVersion();

PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Application_LaunchStore();

#endif //MATRIX_PPF_REQUESTS_APPLICATION_H
