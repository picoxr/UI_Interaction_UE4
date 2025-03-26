#ifndef PPF_ROOM_MEMBERSHIP_LOCK_STATUS_H
#define PPF_ROOM_MEMBERSHIP_LOCK_STATUS_H

#include "PPF_Platform_Defs.h"

/// @file PPF_RoomMembershipLockStatus.h
/// @ingroup Game

typedef enum ppfRoomMembershipLockStatus_ {
    ppfRoomMembershipLockStatus_Unknown = 0,
    ppfRoomMembershipLockStatus_Lock    = 1,
    ppfRoomMembershipLockStatus_Unlock  = 2,
} ppfRoomMembershipLockStatus;

PPF_PUBLIC_FUNCTION(const char*) ppfRoomMembershipLockStatus_ToString(ppfRoomMembershipLockStatus value);

PPF_PUBLIC_FUNCTION(ppfRoomMembershipLockStatus) ppfRoomMembershipLockStatus_FromString(const char* str);

#endif
