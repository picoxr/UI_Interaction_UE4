// This file is generated automatically. Please don't edit it.

#ifndef PPF_MESSAGETYPE_H
#define PPF_MESSAGETYPE_H

#include "PPF_Platform_Defs.h"

/// @file PPF_MessageType.h
/// @ingroup Global

typedef enum {
    ppfMessageType_Unknown                                          = -1,
    ppfMessageType_PlatformInitializeAndroidAsynchronous            = 1,
    ppfMessageType_User_GetLoggedInUser                             = 10000,
    ppfMessageType_User_GetAccessToken                              = 10001,
    ppfMessageType_User_Get                                         = 10002,
    ppfMessageType_User_LaunchFriendRequestFlow                     = 10003,
    ppfMessageType_User_GetLoggedInUserFriends                      = 10004,
    ppfMessageType_User_GetNextUserArrayPage                        = 10005,
    ppfMessageType_User_GetLoggedInUserFriendsAndRooms              = 10006,
    ppfMessageType_Notification_Rtc_OnRoomStats                     = 10200,
    ppfMessageType_Notification_Rtc_OnJoinRoom                      = 10201,
    ppfMessageType_Notification_Rtc_OnLeaveRoom                     = 10202,
    ppfMessageType_Notification_Rtc_OnUserLeaveRoom                 = 10203,
    ppfMessageType_Notification_Rtc_OnUserJoinRoom                  = 10204,
    ppfMessageType_Notification_Rtc_OnConnectionStateChange         = 10205,
    ppfMessageType_Notification_Rtc_OnWarn                          = 10206,
    ppfMessageType_Notification_Rtc_OnRoomWarn                      = 10207,
    ppfMessageType_Notification_Rtc_OnRoomError                     = 10208,
    ppfMessageType_Notification_Rtc_OnError                         = 10209,
    ppfMessageType_Notification_Rtc_OnUserStartAudioCapture         = 10210,
    ppfMessageType_Notification_Rtc_OnAudioPlaybackDeviceChanged    = 10211,
    ppfMessageType_Notification_Rtc_OnRemoteAudioPropertiesReport   = 10212,
    ppfMessageType_Notification_Rtc_OnLocalAudioPropertiesReport    = 10213,
    ppfMessageType_Notification_Rtc_OnUserStopAudioCapture          = 10214,
    ppfMessageType_Notification_Rtc_OnUserMuteAudio                 = 10215,
    ppfMessageType_Notification_Rtc_OnMediaDeviceStateChanged       = 10216,
    ppfMessageType_Notification_Rtc_OnRoomMessageReceived = 10217,
    ppfMessageType_Notification_Rtc_OnUserMessageReceived = 10218,
    ppfMessageType_Rtc_GetToken                                     = 10300,

    ppfMessage_Matchmaking_Browse2                                  = 10400,
    //use ppf_Matchmaking_Cancel2 instead
    // ppfMessage_Matchmaking_Cancel                                  = 10401,
    ppfMessage_Matchmaking_Cancel2                                  = 10402,
    //use ppf_Matchmaking_CreateAndEnqueueRoom2 instead
    // ppfMessage_Matchmaking_CreateAndEnqueueRoom                    = 10403,
    ppfMessage_Matchmaking_CreateAndEnqueueRoom2                    = 10404,
    //use ppf_Matchmaking_CreateAndEnqueueRoom2 instead
    // ppfMessage_Matchmaking_CreateRoom                              = 10405,
    //use ppf_Matchmaking_CreateAndEnqueueRoom2 instead
    // ppfMessage_Matchmaking_CreateRoom2                             = 10406,
    //use ppf_Matchmaking_Enqueue2 instead
    // ppfMessage_Matchmaking_Enqueue                                 = 10407,
    ppfMessage_Matchmaking_Enqueue2                                 = 10408,
    //use ppf_Matchmaking_CreateAndEnqueueRoom2 instead
    // ppfMessage_Matchmaking_EnqueueRoom                             = 10409,
    ppfMessage_Matchmaking_EnqueueRoom2                             = 10410,
    ppfMessage_Matchmaking_GetAdminSnapshot                         = 10411,
    ppfMessage_Matchmaking_GetStats                                 = 10412,
    //use ppf_Room_Join2 instead
    // ppfMessage_Matchmaking_JoinRoom                                = 10413,
    ppfMessage_Matchmaking_ReportResultInsecure                     = 10414,
    ppfMessage_Matchmaking_StartMatch                               = 10415,

    ppfMessage_Room_CreateAndJoinPrivate                            = 10500,
    ppfMessage_Room_CreateAndJoinPrivate2                           = 10501,
    ppfMessage_Room_Get                                             = 10502,
    ppfMessage_Room_GetCurrent                                      = 10503,
    ppfMessage_Room_GetCurrentForUser                               = 10504,
    ppfMessage_Room_GetInvitableUsers                               = 10505,
    ppfMessage_Room_GetInvitableUsers2                              = 10506,
    ppfMessage_Room_GetModeratedRooms                               = 10507,
    ppfMessage_Room_GetNextRoomArrayPage                            = 10508,
    ppfMessage_Room_InviteUser                                      = 10509,
    ppfMessage_Room_Join                                            = 10510,
    ppfMessage_Room_Join2                                           = 10511,
    ppfMessage_Room_KickUser                                        = 10512,
    ppfMessage_Room_LaunchInvitableUserFlow                         = 10513,
    ppfMessage_Room_Leave                                           = 10514,
    ppfMessage_Room_SetDescription                                  = 10515,
    ppfMessage_Room_UpdateDataStore                                 = 10516,
    ppfMessage_Room_UpdateMembershipLockStatus                      = 10517,
    ppfMessage_Room_UpdateOwner                                     = 10518,
    ppfMessage_Room_UpdatePrivateRoomJoinPolicy                     = 10519,

    ppfMessage_Notification_Matchmaking_MatchFound                  = 10600,
    ppfMessage_Notification_Room_InviteAccepted                     = 10601,
    ppfMessage_Notification_Room_InviteReceived                     = 10602,
    ppfMessage_Notification_Room_RoomUpdate                         = 10603,
    ppfMessage_Notification_Game_ConnectionEvent                    = 10604,
    ppfMessage_Notification_Game_RequestFailed                      = 10605,
    ppfMessage_Notification_Game_StateReset                         = 10606,
    ppfMessage_Notification_GetNextRoomInviteNotificationArrayPage  = 10607,
    ppfMessage_Notification_GetRoomInvites                          = 10608,
    ppfMessage_Notification_MarkAsRead                              = 10609,

    ppfMessage_PlatformGameInitializeAsynchronous                   = 10700,

    ppfMessageType_Application_LaunchOtherApp                       = 11001,
    ppfMessageType_Presence_GetSentInvites                          = 11002,
    ppfMessageType_Presence_GetInvitableUsers                       = 11003,
    ppfMessageType_Presence_SendInvites                             = 11004,
    ppfMessageType_Presence_GetDestinations                         = 11005,
    ppfMessageType_Presence_Clear                                   = 11006,
    ppfMessageType_Presence_Set                                     = 11007,
    ppfMessageType_Notification_ApplicationLifecycle_LaunchIntentChanged = 11008,
    ppfMessage_Notification_Presence_JoinIntentReceived             = 11009,
    ppfMessage_Notification_Presence_LeaveIntentReceived            = 11010,
    ppfMessageType_Application_LaunchOtherAppByPresence             = 11011,
    ppfMessageType_Notification_APPLICATION_ROOM_INVITE_ACCEPTED = 11012,
} ppfMessageType;
#endif

