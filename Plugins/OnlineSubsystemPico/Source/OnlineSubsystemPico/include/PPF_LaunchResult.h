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

#endif //MATRIX_PPF_LAUNCHRESULT_H
