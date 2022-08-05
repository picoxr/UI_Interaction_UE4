// This file is generated automatically. Please don't edit it.

#ifndef PPF_MESSAGE_H
#define PPF_MESSAGE_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_User.h"
#include "PPF_UserAndRoomArray.h"
#include "PPF_DataStore.h"
#include "PPF_MessageType.h"
#include "PPF_Error.h"
#include "PPF_UserArray.h"
#include "PPF_LaunchFriendRequestFlowResult.h"
#include "PPF_RtcJoinRoomResult.h"
#include "PPF_RtcLeaveRoomResult.h"
#include "PPF_RtcRoomStats.h"
#include "PPF_RtcUserJoinInfo.h"
#include "PPF_RtcUserLeaveInfo.h"
#include "PPF_MatchmakingBrowseResult.h"
#include "PPF_MatchmakingEnqueueResult.h"
#include "PPF_MatchmakingEnqueueResultAndRoom.h"
#include "PPF_MatchmakingRoomArray.h"
#include "PPF_MatchmakingStats.h"
#include "PPF_MessageType.h"
#include "PPF_Room.h"
#include "PPF_RoomArray.h"
#include "PPF_RtcRoomWarn.h"
#include "PPF_RtcRoomError.h"
#include "PPF_RtcMuteInfo.h"
#include "PPF_RtcRoomMessageReceived.h"
#include "PPF_RtcUserMessageReceived.h"
#include "PPF_RtcAudioPlaybackDevice.h"
#include "PPF_RtcMediaDeviceChangeInfo.h"
#include "PPF_RtcLocalAudioPropertiesReport.h"
#include "PPF_RtcRemoteAudioPropertiesReport.h"
#include "PPF_PlatformGameInitialize.h"
#include "PPF_PlatformGameNotification.h"
#include "PPF_Destination.h"
#include "PPF_DestinationArray.h"
#include "PPF_ApplicationInvite.h"
#include "PPF_ApplicationInviteArray.h"
#include "PPF_SendInvitesResult.h"
#include "PPF_PresenceJoinIntent.h"
#include "PPF_PresenceLeaveIntent.h"
#include "PPF_RoomInviteNotificationArray.h"

/// @file PPF_Message.h
/// @ingroup Global

/// @file PPF_Message.h
/// @ingroup Global

typedef struct ppfMessage *ppfMessageHandle;

PPF_PUBLIC_FUNCTION(ppfUserHandle)                               ppf_Message_GetUser(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(const char*)                                 ppf_Message_GetString(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(int)                                         ppf_Message_GetInt32(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMessageType)                              ppf_Message_GetType(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfErrorHandle)                              ppf_Message_GetError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(bool)                                        ppf_Message_IsError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRequest)                                  ppf_Message_GetRequestID(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle)                          ppf_Message_GetUserArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfLaunchFriendRequestFlowResultHandle)      ppf_Message_GetLaunchFriendRequestFlowResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserAndRoomArrayHandle) ppf_Message_GetUserAndRoomArray(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcJoinRoomResultHandle)                  ppf_Message_GetRtcJoinRoomResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcLeaveRoomResultHandle)                 ppf_Message_GetRtcLeaveRoomResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomStatsHandle)                       ppf_Message_GetRtcRoomStats(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserJoinInfoHandle)                    ppf_Message_GetRtcUserJoinInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserLeaveInfoHandle)                   ppf_Message_GetRtcUserLeaveInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomWarnHandle)                        ppf_Message_GetRtcRoomWarn(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomErrorHandle)                       ppf_Message_GetRtcRoomError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcMuteInfoHandle)                        ppf_Message_GetRtcMuteInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcAudioPlaybackDevice)                   ppf_Message_GetRtcAudioPlaybackDevice(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceChangeInfoHandle)           ppf_Message_GetRtcMediaDeviceChangeInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcLocalAudioPropertiesReportHandle)      ppf_Message_GetRtcLocalAudioPropertiesReport(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRemoteAudioPropertiesReportHandle)     ppf_Message_GetRtcRemoteAudioPropertiesReport(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomMessageReceivedHandle) ppf_Message_GetRtcRoomMessageReceived(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserMessageReceivedHandle) ppf_Message_GetRtcUserMessageReceived(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfMatchmakingAdminSnapshotHandle)           ppf_Message_GetMatchmakingAdminSnapshot(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingBrowseResultHandle)            ppf_Message_GetMatchmakingBrowseResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultHandle)           ppf_Message_GetMatchmakingEnqueueResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultAndRoomHandle)    ppf_Message_GetMatchmakingEnqueueResultAndRoom(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingStatsHandle)                   ppf_Message_GetMatchmakingStats(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomHandle)                               ppf_Message_GetRoom(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomArrayHandle)                          ppf_Message_GetRoomArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPlatformGameInitializeHandle)             ppf_Message_GetPlatformGameInitialize(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfGameConnectionEvent)                      ppf_Message_GetGameConnectionEvent(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfGameRequestFailedReason)                  ppf_Message_GetGameRequestFailedReason(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfApplicationInviteArrayHandle)             ppf_Message_GetApplicationInviteArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSendInvitesResultHandle)                  ppf_Message_GetSendInvitesResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfDestinationArrayHandle)                   ppf_Message_GetDestinationArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPresenceJoinIntentHandle)                 ppf_Message_GetPresenceJoinIntent(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPresenceLeaveIntentHandle)                ppf_Message_GetPresenceLeaveIntent(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomInviteNotificationArrayHandle)        ppf_Message_GetRoomInviteNotificationArray(const ppfMessageHandle obj);

#endif

