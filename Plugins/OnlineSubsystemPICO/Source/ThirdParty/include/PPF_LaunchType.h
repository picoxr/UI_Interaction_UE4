#ifndef MATRIX_PPF_LAUNCHTYPE_H
#define MATRIX_PPF_LAUNCHTYPE_H

/// @file PPF_LaunchType.h
/// @ingroup Social

typedef enum ppfLaunchType_ {
    ppfLaunchType_Unknown = 0,
    ppfLaunchType_Normal = 1,
    ppfLaunchType_RoomInvite = 2,
    // deprecated,don't use it
    // ppfLaunchType_Coordinated = 3,
    ppfLaunchType_Deeplink = 4,
    ppfLaunchType_ChallengeInvite = 5,
} ppfLaunchType;

#endif //MATRIX_PPF_LAUNCHTYPE_H
