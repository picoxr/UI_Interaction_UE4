#ifndef MATRIX_PPF_LAUNCHRESULT_H
#define MATRIX_PPF_LAUNCHRESULT_H

/// @file PPF_LaunchResult.h
/// @ingroup Social

typedef enum ppfLaunchResult_ {
    ppfLaunchResult_Unknown,
    ppfLaunchResult_Success,
    ppfLaunchResult_FailedRoomFull,
    ppfLaunchResult_FailedGameAlreadyStarted,
    ppfLaunchResult_FailedRoomNotFound,
    ppfLaunchResult_FailedUserDeclined,
    ppfLaunchResult_FailedOtherReason,
} ppfLaunchResult;

/// @brief Converts an ppfLaunchResult enum value to a string
/// The returned string does not need to be freed
PPF_PUBLIC_FUNCTION(const char*) ppfLaunchResult_ToString(ppfLaunchResult value);

/// @brief Converts a string representing an ppfLaunchResult enum value to an enum value
///
PPF_PUBLIC_FUNCTION(ppfLaunchResult) ppfLaunchResult_FromString(const char* str);


#endif //MATRIX_PPF_LAUNCHRESULT_H
