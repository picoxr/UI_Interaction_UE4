#ifndef PPF_ROOM_TYPE_H
#define PPF_ROOM_TYPE_H

#include "PPF_Platform_Defs.h"

/// @file PPF_RoomType.h
/// @ingroup Game

typedef enum ppfRoomType_ {
    ppfRoom_TypeUnknown     = 0,
    ppfRoom_TypeMatchmaking = 1,
    ppfRoom_TypeModerated   = 2,
    ppfRoom_TypePrivate     = 3,
    ppfRoom_TypeNamed       = 4,
} ppfRoomType;

PPF_PUBLIC_FUNCTION(const char*) ppfRoomType_ToString(ppfRoomType value);

PPF_PUBLIC_FUNCTION(ppfRoomType) ppfRoomType_FromString(const char* str);

#endif
