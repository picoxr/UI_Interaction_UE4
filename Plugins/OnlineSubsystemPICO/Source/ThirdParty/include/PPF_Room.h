#ifndef PPF_ROOM_H
#define PPF_ROOM_H

#include "PPF_Platform_Defs.h"
#include "PPF_DataStore.h"
#include "PPF_RoomJoinability.h"
#include "PPF_RoomJoinPolicy.h"
#include "PPF_RoomType.h"
#include "PPF_Types.h"
#include "PPF_User.h"
#include "PPF_UserArray.h"
#include <stdbool.h>

/// @file PPF_Room.h
/// @ingroup Game


typedef struct ppfRoom *ppfRoomHandle;

/// @brief get room datastore
/// @param obj room handle
/// @return datastore handle
/// 
/// This method may return null. This indicates that the value is not present.
PPF_PUBLIC_FUNCTION(ppfDataStoreHandle) ppf_Room_GetDataStore(const ppfRoomHandle obj);

/// @brief get room owner
/// @param obj room handle
/// @return user handle of the room owner
/// 
/// This method may return null. This indicates that the value is not present.
PPF_PUBLIC_FUNCTION(ppfUserHandle) ppf_Room_GetOwner(const ppfRoomHandle obj);

/// @brief get room name (for named room)
/// @param obj room handle
/// @return name of the room
/// 
/// This method may return null. This indicates it's not a named room or the value is not present.
PPF_PUBLIC_FUNCTION(const char*) ppf_Room_GetName(const ppfRoomHandle obj);

/// @brief get room user array
/// @param obj room handle
/// @return user array of the room
/// 
/// This method may return null. This indicates that the value is not present
PPF_PUBLIC_FUNCTION(ppfUserArrayHandle) ppf_Room_GetUsers(const ppfRoomHandle obj);

/// @brief get room description
/// @param obj room handle
/// @return room description
PPF_PUBLIC_FUNCTION(const char *)       ppf_Room_GetDescription(const ppfRoomHandle obj);

/// @brief get room id
/// @param obj room handle
/// @return room id
PPF_PUBLIC_FUNCTION(ppfID)              ppf_Room_GetID(const ppfRoomHandle obj);

/// @brief get room lock flag
/// @param obj room handle
/// @return room lock flag
PPF_PUBLIC_FUNCTION(bool)               ppf_Room_GetIsMembershipLocked(const ppfRoomHandle obj);

/// @brief get room join policy
/// @param obj room handle
/// @return room join policy
PPF_PUBLIC_FUNCTION(ppfRoomJoinPolicy)  ppf_Room_GetJoinPolicy(const ppfRoomHandle obj);

/// @brief get room joinablility
/// @param obj room handle
/// @return room joinability
PPF_PUBLIC_FUNCTION(ppfRoomJoinability) ppf_Room_GetJoinability(const ppfRoomHandle obj);

/// @brief get room max user number
/// @param obj room handle
/// @return room max user number
PPF_PUBLIC_FUNCTION(unsigned int)       ppf_Room_GetMaxUsers(const ppfRoomHandle obj);

/// @brief get room type
/// @param obj room handle
/// @return room type
PPF_PUBLIC_FUNCTION(ppfRoomType)        ppf_Room_GetType(const ppfRoomHandle obj);

/// @brief get room player number
/// @param obj room handle
/// @return room player number
PPF_PUBLIC_FUNCTION(unsigned int)        ppf_Room_GetPlayerNumber(const ppfRoomHandle obj);

#endif
