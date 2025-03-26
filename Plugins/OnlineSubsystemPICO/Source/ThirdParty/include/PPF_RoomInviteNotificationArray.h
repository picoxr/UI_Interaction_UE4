#ifndef PPF_ROOMINVITENOTIFICATIONARRAY_H
#define PPF_ROOMINVITENOTIFICATIONARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_RoomInviteNotification.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct ppfRoomInviteNotificationArray *ppfRoomInviteNotificationArrayHandle;

PPF_PUBLIC_FUNCTION(ppfRoomInviteNotificationHandle) ppf_RoomInviteNotificationArray_GetElement(const ppfRoomInviteNotificationArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)                    ppf_RoomInviteNotificationArray_GetNextUrl(const ppfRoomInviteNotificationArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                          ppf_RoomInviteNotificationArray_GetSize(const ppfRoomInviteNotificationArrayHandle obj);
PPF_PUBLIC_FUNCTION(int32_t)                         ppf_RoomInviteNotificationArray_GetTotalCount(const ppfRoomInviteNotificationArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                            ppf_RoomInviteNotificationArray_HasNextPage(const ppfRoomInviteNotificationArrayHandle obj);

#endif
