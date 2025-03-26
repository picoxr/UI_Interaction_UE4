#ifndef PPF_ROOM_JOINABILITY_H
#define PPF_ROOM_JOINABILITY_H

#include "PPF_Platform_Defs.h"

/// @file PPF_RoomJoinability.h
/// @ingroup Game

typedef enum ppfRoomJoinability_ {
    ppfRoom_JoinabilityUnknown        = 0,
    ppfRoom_JoinabilityAreIn          = 1,
    ppfRoom_JoinabilityAreKicked      = 2,
    ppfRoom_JoinabilityCanJoin        = 3,
    ppfRoom_JoinabilityIsFull         = 4,
    ppfRoom_JoinabilityNoViewer       = 5,
    ppfRoom_JoinabilityPolicyPrevents = 6,
} ppfRoomJoinability;

PPF_PUBLIC_FUNCTION(const char*) ppfRoomJoinability_ToString(ppfRoomJoinability value);

PPF_PUBLIC_FUNCTION(ppfRoomJoinability) ppfRoomJoinability_FromString(const char* str);

#endif
