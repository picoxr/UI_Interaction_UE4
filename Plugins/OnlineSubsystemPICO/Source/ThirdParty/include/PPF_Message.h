

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
#include "PPF_RtcJoinRoomResult.h"
#include "PPF_RtcLeaveRoomResult.h"
#include "PPF_RtcRoomStats.h"
#include "PPF_RtcUserJoinInfo.h"
#include "PPF_RtcUserLeaveInfo.h"
#include "PPF_RtcRoomWarn.h"
#include "PPF_RtcRoomError.h"
#include "PPF_RtcMuteInfo.h"
#include "PPF_RtcAudioPlaybackDevice.h"
#include "PPF_RtcMediaDeviceChangeInfo.h"
#include "PPF_RtcLocalAudioPropertiesReport.h"
#include "PPF_RtcRemoteAudioPropertiesReport.h"
#include "PPF_RtcRoomMessageReceived.h"
#include "PPF_RtcBinaryMessageReceived.h"
#include "PPF_RtcStreamSyncInfo.h"
#include "PPF_RtcVideoDeviceStateChangeInfo.h"
#include "PPF_RtcFirstLocalVideoFrameCapturedInfo.h"
#include "PPF_RtcLocalVideoSizeChangeInfo.h"
#include "PPF_RtcScreenVideoFrameSendStateInfo.h"
#include "PPF_RtcLocalVideoStateChangeInfo.h"
#include "PPF_RtcUserPublishInfo.h"
#include "PPF_RtcUserUnPublishInfo.h"
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
#include "PPF_RtcMessageSendResult.h"
#include "PPF_PlatformGameInitialize.h"
#include "PPF_PlatformGameNotification.h"
#include "PPF_Destination.h"
#include "PPF_DestinationArray.h"
#include "PPF_ApplicationInvite.h"
#include "PPF_ApplicationInviteArray.h"
#include "PPF_SendInvitesResult.h"
#include "PPF_PresenceJoinIntent.h"
#include "PPF_RoomInviteNotificationArray.h"
#include "PPF_SportUserInfo.h"
#include "PPF_SportDailySummaryArray.h"
#include "PPF_SportSummary.h"
#include "PPF_LeaderboardArray.h"
#include "PPF_LeaderboardUpdateStatus.h"
#include "PPF_LeaderboardEntryArray.h"
#include "PPF_AchievementDefinitionArray.h"
#include "PPF_AchievementProgressArray.h"
#include "PPF_AchievementUpdate.h"
#include "PPF_Challenge.h"
#include "PPF_ChallengeArray.h"
#include "PPF_ChallengeEntryArray.h"
#include "PPF_PurchaseArray.h"
#include "PPF_Product.h"
#include "PPF_ProductArray.h"
#include "PPF_Purchase.h"
#include "PPF_PermissionResult.h"
#include "PPF_ApplicationVersion.h"
#include "PPF_AsrResult.h"
#include "PPF_SubscriptionStatus.h"
#include "PPF_AssetDetails.h"
#include "PPF_AssetDetailsArray.h"
#include "PPF_AssetFileDeleteResult.h"
#include "PPF_AssetFileDownloadCancelResult.h"
#include "PPF_AssetFileDownloadResult.h"
#include "PPF_AssetFileDownloadUpdate.h"
#include "PPF_AssetFileDeleteForSafety.h"
#include "PPF_AssetStatus.h"
#include "PPF_UserRelationResult.h"
#include "PPF_DetectSensitiveResult.h"
#include "PPF_SpeechError.h"
#include "PPF_EntitlementCheckResult.h"
#include "PPF_OrgScopedID.h"
#include "PPF_SessionMedia.h"

/// @file PPF_Message.h
/// @ingroup Global

typedef struct ppfMessage *ppfMessageHandle;

PPF_PUBLIC_FUNCTION(ppfUserHandle) ppf_Message_GetUser(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(const char*)ppf_Message_GetString(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(int) ppf_Message_GetInt32(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMessageType) ppf_Message_GetType(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfErrorHandle) ppf_Message_GetError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(bool) ppf_Message_IsError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Message_GetRequestID(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle) ppf_Message_GetUserArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfLaunchFriendRequestFlowResultHandle) ppf_Message_GetLaunchFriendRequestFlowResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserAndRoomArrayHandle) ppf_Message_GetUserAndRoomArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPermissionResultHandle) ppf_Message_GetPermissionResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfApplicationVersionHandle) ppf_Message_GetApplicationVersion(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfUserRelationResultHandle) ppf_Message_GetUserRelationResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSubscriptionStatusHandle) ppf_Message_GetSubscriptionStatus(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfEntitlementCheckResultHandle) ppf_Message_GetEntitlementCheckResult(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcJoinRoomResultHandle) ppf_Message_GetRtcJoinRoomResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcLeaveRoomResultHandle) ppf_Message_GetRtcLeaveRoomResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomStatsHandle) ppf_Message_GetRtcRoomStats(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserJoinInfoHandle) ppf_Message_GetRtcUserJoinInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserLeaveInfoHandle) ppf_Message_GetRtcUserLeaveInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomWarnHandle) ppf_Message_GetRtcRoomWarn(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomErrorHandle) ppf_Message_GetRtcRoomError(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcMuteInfoHandle) ppf_Message_GetRtcMuteInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcAudioPlaybackDevice) ppf_Message_GetRtcAudioPlaybackDevice(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcMediaDeviceChangeInfoHandle) ppf_Message_GetRtcMediaDeviceChangeInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcLocalAudioPropertiesReportHandle) ppf_Message_GetRtcLocalAudioPropertiesReport(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRemoteAudioPropertiesReportHandle) ppf_Message_GetRtcRemoteAudioPropertiesReport(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcRoomMessageReceivedHandle) ppf_Message_GetRtcRoomMessageReceived(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserMessageReceivedHandle) ppf_Message_GetRtcUserMessageReceived(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcBinaryMessageReceivedHandle) ppf_Message_GetRtcBinaryMessageReceived(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcStreamSyncInfoHandle) ppf_Message_GetRtcStreamSyncInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcVideoDeviceStateChangeInfoHandle) ppf_Message_GetRtcVideoDeviceStateChangeInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcFirstLocalVideoFrameCapturedInfoHandle) ppf_Message_GetRtcFirstLocalVideoFrameCapturedInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcLocalVideoSizeChangeInfoHandle) ppf_Message_GetRtcLocalVideoSizeChangeInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRtcScreenVideoFrameSendStateInfoHandle) ppf_Message_GetRtcScreenVideoFrameSendStateInfo(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcLocalVideoStateChangeInfoHandle) ppf_Message_GetRtcLocalVideoStateChangeInfo(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcMessageSendResultHandle) ppf_Message_GetRtcMessageSendResult(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfRtcUserPublishInfoHandle) ppf_Message_GetRtcUserPublishInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRtcUserUnPublishInfoHandle) ppf_Message_GetRtcUserUnPublishInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingAdminSnapshotHandle) ppf_Message_GetMatchmakingAdminSnapshot(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingBrowseResultHandle) ppf_Message_GetMatchmakingBrowseResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingBrowseResultHandle) ppf_Message_GetMatchmakingBrowseCustomPageResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultHandle) ppf_Message_GetMatchmakingEnqueueResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingEnqueueResultAndRoomHandle) ppf_Message_GetMatchmakingEnqueueResultAndRoom(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfMatchmakingStatsHandle) ppf_Message_GetMatchmakingStats(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomHandle) ppf_Message_GetRoom(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomArrayHandle) ppf_Message_GetRoomArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPlatformGameInitializeHandle) ppf_Message_GetPlatformGameInitialize(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfGameConnectionEvent) ppf_Message_GetGameConnectionEvent(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfGameRequestFailedReason) ppf_Message_GetGameRequestFailedReason(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfApplicationInviteArrayHandle) ppf_Message_GetApplicationInviteArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSendInvitesResultHandle) ppf_Message_GetSendInvitesResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfDestinationArrayHandle) ppf_Message_GetDestinationArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPresenceJoinIntentHandle) ppf_Message_GetPresenceJoinIntent(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfRoomInviteNotificationArrayHandle) ppf_Message_GetRoomInviteNotificationArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfLeaderboardArrayHandle) ppf_Message_GetLeaderboardArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfLeaderboardUpdateStatusHandle) ppf_Message_GetLeaderboardUpdateStatus(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfLeaderboardEntryArrayHandle) ppf_Message_GetLeaderboardEntryArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAchievementDefinitionArrayHandle) ppf_Message_GetAchievementDefinitionArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAchievementProgressArrayHandle) ppf_Message_GetAchievementProgressArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAchievementUpdateHandle) ppf_Message_GetAchievementUpdate(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfChallengeHandle) ppf_Message_GetChallenge(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfChallengeArrayHandle) ppf_Message_GetChallengeArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfChallengeEntryArrayHandle) ppf_Message_GetChallengeEntryArray(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfPurchaseArrayHandle) ppf_Message_GetPurchaseArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfProductArrayHandle) ppf_Message_GetProductArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfPurchaseHandle) ppf_Message_GetPurchase(const ppfMessageHandle obj);

//Sport
PPF_PUBLIC_FUNCTION(ppfSportUserInfoHandle) ppf_Message_GetSportUserInfo(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSportDailySummaryArrayHandle) ppf_Message_GetSportDailySummaryArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSportSummaryHandle) ppf_Message_GetSportSummary(const ppfMessageHandle obj);

// dlc
PPF_PUBLIC_FUNCTION(ppfAssetDetailsHandle) ppf_Message_GetAssetDetails(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetDetailsArrayHandle) ppf_Message_GetAssetDetailsArray(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetFileDeleteResultHandle) ppf_Message_GetAssetFileDeleteResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetFileDownloadCancelResultHandle) ppf_Message_GetAssetFileDownloadCancelResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetFileDownloadResultHandle) ppf_Message_GetAssetFileDownloadResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetFileDownloadUpdateHandle) ppf_Message_GetAssetFileDownloadUpdate(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetStatusHandle) ppf_Message_GetAssetStatus(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfAssetFileDeleteForSafetyHandle) ppf_Message_GetAssetFileDeleteForSafety(const ppfMessageHandle obj);

// speech
PPF_PUBLIC_FUNCTION(ppfAsrResultHandle) ppf_Message_GetAsrResult(const ppfMessageHandle obj);
PPF_PUBLIC_FUNCTION(ppfSpeechErrorHandle) ppf_Message_GetSpeechError(const ppfMessageHandle obj);

// compliance
PPF_PUBLIC_FUNCTION(ppfDetectSensitiveResultHandle) ppf_Message_GetDetectSensitiveResult(const ppfMessageHandle obj);

PPF_PUBLIC_FUNCTION(ppfOrgScopedIDHandle) ppf_Message_GetOrgScopedID(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfCaptureInfoHandle) ppf_Message_GetCaptureInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfRecordInfoHandle) ppf_Message_GetRecordInfo(const ppfMessageHandle obj);


PPF_PUBLIC_FUNCTION(ppfSessionMediaHandle) ppf_Message_GetSessionMedia(const ppfMessageHandle obj);


#endif

