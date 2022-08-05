// Copyright © 2022-2025 Pico Technology Co., Ltd. All Rights Reserved.

#ifndef PPF_PLATFORM_H
#define PPF_PLATFORM_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_PlatformInitializeResult.h"

#include "PPF_Error.h"
#include "PPF_Message.h"
#include "PPF_MessageType.h"

#include "PPF_User.h"
#include "PPF_UserArray.h"
#include "PPF_LaunchFriendRequestFlowResult.h"

#include "PPF_RtcLeaveRoomResult.h"
#include "PPF_RtcRoomStats.h"
#include "PPF_RtcJoinRoomResult.h"
#include "PPF_RtcUserLeaveInfo.h"
#include "PPF_RtcUserJoinInfo.h"
#include "PPF_RtcRoomOptions.h"
#include "PPF_RtcRemoteStreamKey.h"
#include "PPF_RtcRemoteAudioPropertiesInfo.h"
#include "PPF_RtcLocalAudioPropertiesReport.h"
#include "PPF_RtcAudioPropertyOptions.h"
#include "PPF_RtcRemoteAudioPropertiesReport.h"
#include "PPF_RtcMediaDeviceChangeInfo.h"
#include "PPF_RtcAudioPropertyInfo.h"
#include "PPF_RtcLocalAudioPropertiesInfo.h"
#include "PPF_RtcMediaDeviceState.h"
#include "PPF_RtcMediaDeviceError.h"
#include "PPF_RtcPauseResumeMediaType.h"
#include "PPF_RtcAudioPlaybackDevice.h"
#include "PPF_RtcMediaDeviceType.h"
#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcRoomMessageReceived.h"


#include "PPF_RtcMuteInfo.h"
#include "PPF_RtcJoinRoomType.h"
#include "PPF_RtcAudioScenarioType.h"
#include "PPF_RtcUserLeaveReasonType.h"
#include "PPF_RtcMuteState.h"
#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcEarMonitorMode.h"
#include "PPF_RtcRoomWarn.h"
#include "PPF_RtcRoomError.h"
#include "PPF_RtcRoomProfileType.h"
#include "PPF_Gender.h"
#include "PPF_UserPresenceStatus.h"
#include "PPF_Requests_User.h"
#include "PPF_Functions_Rtc.h"
#include "PPF_Requests_Rtc.h"
#include "PPF_RtcGetTokenOptions.h"

#include "PPF_Game.h"
#include "PPF_PlatformGameInitialize.h"
#include "PPF_PlatformGameInitializeResult.h"
#include "PPF_PlatformGameNotification.h"
#include "PPF_DataStore.h"
#include "PPF_KeyValuePair.h"
#include "PPF_KeyValuePairArray.h"
#include "PPF_KeyValuePairType.h"
#include "PPF_MatchmakingAdminSnapshot.h"
#include "PPF_MatchmakingAdminSnapshotCandidate.h"
#include "PPF_MatchmakingAdminSnapshotCandidateArray.h"
#include "PPF_MatchmakingBrowseResult.h"
#include "PPF_MatchmakingCriterionImportance.h"
#include "PPF_MatchmakingEnqueueResult.h"
#include "PPF_MatchmakingEnqueueResultAndRoom.h"
#include "PPF_MatchmakingRoom.h"
#include "PPF_MatchmakingRoomArray.h"
#include "PPF_MatchmakingStatApproach.h"
#include "PPF_MatchmakingStats.h"
#include "PPF_Packet.h"
#include "PPF_Room.h"
#include "PPF_RoomArray.h"
#include "PPF_Requests_Matchmaking.h"
#include "PPF_Requests_Room.h"
#include "PPF_MatchmakingOptions.h"
#include "PPF_RoomJoinability.h"
#include "PPF_RoomJoinPolicy.h"
#include "PPF_RoomMembershipLockStatus.h"
#include "PPF_RoomOptions.h"
#include "PPF_RoomType.h"
#include "PPF_Functions_Networking.h"
#include "PPF_UserAndRoom.h"
#include "PPF_UserAndRoomArray.h"

#include "PPF_ApplicationOptions.h"
#include "PPF_ApplicationByPresenceOptions.h"
#include "PPF_Requests_Application.h"
#include "PPF_LaunchType.h"
#include "PPF_LaunchDetails.h"
#include "PPF_LaunchResult.h"
#include "PPF_Functions_ApplicationLifecycle.h"
#include "PPF_Destination.h"
#include "PPF_ApplicationOptions.h"
#include "PPF_ApplicationInvite.h"
#include "PPF_LaunchType.h"
#include "PPF_LaunchDetails.h"
#include "PPF_Pid.h"

#include "PPF_Product.h"
#include "PPF_Purchase.h"
#include "PPF_RosterOptions.h"
#include "PPF_PresenceOptions.h"
#include "PPF_InviteOptions.h"
#include "PPF_Destination.h"
#include "PPF_DestinationArray.h"
#include "PPF_ApplicationInvite.h"
#include "PPF_ApplicationInviteArray.h"
#include "PPF_ProductArray.h"
#include "PPF_PurchaseArray.h"
#include "PPF_SendInvitesResult.h"
#include "PPF_Requests_Presence.h"
#include "PPF_PresenceJoinIntent.h"
#include "PPF_PresenceLeaveIntent.h"

/// @defgroup Global Global
/// @file PPF_Platform.h
/// @ingroup Global

#ifdef __ANDROID__

#include <jni.h>

/// @brief Synchronously Initialize Platform SDK from Android application.
///
/// @param  appId The application ID get from developer dashboard.
/// @return The initialize result.
///
PPF_PUBLIC_FUNCTION(ppfPlatformInitializeResult) ppf_InitializeAndroid(const char *appId, jobject applicationObject, JNIEnv *jni);

/// @brief Asynchronously Initialize Platform SDK from Android application.
/// The result will be put on the message queue with the message type: ppfMessage_PlatformInitializeAndroidAsynchronous
///
/// @param  appId The application ID get from developer dashboard.
/// @return The request ID of this async function.
///
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_InitializeAndroidAsynchronous(const char *appId, jobject applicationObject, JNIEnv *jni);
#endif //ANDROID

/// @brief Synchronously Initialize Platform SDK from Unity application.
///
/// @param  appId The application ID get from developer dashboard.
/// @return The initialize result.
///
PPF_PUBLIC_FUNCTION(ppfPlatformInitializeResult) ppf_UnityInitWrapper(const char *appId);

/// @brief Asynchronously Initialize Platform SDK from Unity application.
/// The result will be put on the message queue with the message type: ppfMessage_PlatformInitializeAndroidAsynchronous
///
/// @param  appId The application ID get from developer dashboard.
/// @return The request ID of this async function.
///
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_UnityInitAsynchronousWrapper(const char *appId);

/// @brief Return the next message in the queue (FIFO order), or null if none
/// is available.  Safe to call on any thread.  Each returned message
/// should eventually be freed with ppf_FreeMessage.
///
/// @return The message object or null if none is avaiable.
///
PPF_PUBLIC_FUNCTION(ppfMessageHandle) ppf_PopMessage();

/// @brief Free the message object.
///
/// @param obj the message object to be freed.
///
/// A message returned by ppf_PopMessage() should eventually be freed with ppf_FreeMessage.
PPF_PUBLIC_FUNCTION(void) ppf_FreeMessage(ppfMessageHandle obj);

#endif //PPF_PLATFORM_H
