#ifndef PPF_ROOMINVITENOTIFICATION_H
#define PPF_ROOMINVITENOTIFICATION_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"

typedef struct ppfRoomInviteNotification *ppfRoomInviteNotificationHandle;

PPF_PUBLIC_FUNCTION(ppfID)              ppf_RoomInviteNotification_GetID(const ppfRoomInviteNotificationHandle obj);
PPF_PUBLIC_FUNCTION(ppfID)              ppf_RoomInviteNotification_GetRoomID(const ppfRoomInviteNotificationHandle obj);
PPF_PUBLIC_FUNCTION(const char*)        ppf_RoomInviteNotification_GetSenderID(const ppfRoomInviteNotificationHandle obj);
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_RoomInviteNotification_GetSentTime(const ppfRoomInviteNotificationHandle obj);

#endif
