#ifndef MATRIX_PPF_FUNCTIONS_APPLICATIONLIFECYCLE_H
#define MATRIX_PPF_FUNCTIONS_APPLICATIONLIFECYCLE_H

#include "PPF_LaunchDetails.h"
#include "PPF_LaunchResult.h"
#include "PPF_SystemInfo.h"
/// @defgroup Social SocialConnect
/// @file PPF_Functions_ApplicationLifecycle.h
/// @ingroup Social

/// @brief Returns information about how the application was started.
PPF_PUBLIC_FUNCTION(ppfLaunchDetailsHandle)
ppf_ApplicationLifecycle_GetLaunchDetails();

/// @brief Logs if the user successfully deeplinked to a destination.
PPF_PUBLIC_FUNCTION(void)
ppf_ApplicationLifecycle_LogDeeplinkResult(const char *trackingID, ppfLaunchResult result);


PPF_PUBLIC_FUNCTION(ppfSystemInfoHandle) ppf_Application_GetSystemInfo();

#endif // MATRIX_PPF_FUNCTIONS_APPLICATIONLIFECYCLE_H
