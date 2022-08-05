#ifndef PPF_ROOM_JOIN_POLICY_H
#define PPF_ROOM_JOIN_POLICY_H

#include "PPF_Platform_Defs.h"

/// @file PPF_RoomJoinPolicy.h
/// @ingroup Game

typedef enum ppfRoomJoinPolicy_ {
    ppfRoom_JoinPolicyNone             = 0,
    ppfRoom_JoinPolicyEveryone         = 1,
    ppfRoom_JoinPolicyFriendsOfMembers = 2,
    ppfRoom_JoinPolicyFriendsOfOwner   = 3,
    ppfRoom_JoinPolicyInvitedUsers     = 4,
    ppfRoom_JoinPolicyUnknown          = 5,
} ppfRoomJoinPolicy;

PPF_PUBLIC_FUNCTION(const char*) ppfRoomJoinPolicy_ToString(ppfRoomJoinPolicy value);

PPF_PUBLIC_FUNCTION(ppfRoomJoinPolicy) ppfRoomJoinPolicy_FromString(const char* str);

#endif
