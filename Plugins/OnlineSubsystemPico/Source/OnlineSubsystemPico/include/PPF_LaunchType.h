#ifndef MATRIX_PPF_LAUNCHTYPE_H
#define MATRIX_PPF_LAUNCHTYPE_H

/// @file PPF_LaunchType.h
/// @ingroup Social

typedef enum ppfLaunchType_ {
    ppfLaunchType_Unknown,
    ppfLaunchType_Normal,
    ppfLaunchType_Invite,
    ppfLaunchType_Coordinated,
    ppfLaunchType_Deeplink,
} ppfLaunchType;

/// @brief Converts an ppfLaunchType enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfLaunchType_ToString(ppfLaunchType value);

/// @brief Converts a string representing an ppfLaunchType enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfLaunchType) ppfLaunchType_FromString(const char* str);


#endif //MATRIX_PPF_LAUNCHTYPE_H
