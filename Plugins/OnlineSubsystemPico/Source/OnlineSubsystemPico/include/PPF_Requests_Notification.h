#ifndef PPF_REQUESTS_NOTIFICATION_H
#define PPF_REQUESTS_NOTIFICATION_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_RoomInviteNotificationArray.h"

/// \file
/// *** Notifications Overview:
/// Notifications are a way for the Pico platform to push timely updates to your
/// application. These are typically time-sensitive items and try to be prolific.
/// In addition to your application, they usually present themselves in the 2D/3D
/// Stores as well as Universal Menu.
///
/// *** Read Status:
/// Notifications will currently show up in these areas until they either expire or
/// they're marked as read. If you mark a notification as read, it'll be removed
/// from all surfaces.

/// Get the next page of entries
///
/// A message with type ::ppfMessage_Notification_GetNextRoomInviteNotificationArrayPage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomInviteNotificationArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoomInviteNotificationArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Notification_GetNextRoomInviteNotificationArrayPage(ppfRoomInviteNotificationArrayHandle handle);

/// Retrieve a list of all pending room invites for your application (for
/// example, notifications that may have been sent before the user launched
/// your game). You can also get push notifications with
/// ppfNotification_Room_InviteReceived.
///
/// A message with type ::ppfMessage_Notification_GetRoomInvites will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfRoomInviteNotificationArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetRoomInviteNotificationArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Notification_GetRoomInvites(int pageIdx, int pageSize);

/// Mark a notification as read. This causes it to disappear from the Universal
/// Menu, the Pico App, Pico Home, and in-app retrieval.
///
/// A message with type ::ppfMessage_Notification_MarkAsRead will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Notification_MarkAsRead(ppfID notificationID);

#endif
