#ifndef PPF_ROOMARRAY_H
#define PPF_ROOMARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Room.h"
#include <stdbool.h>
#include <stddef.h>

/// @file PPF_RoomArray.h
/// @ingroup Game

typedef struct ppfRoomArray *ppfRoomArrayHandle;

PPF_PUBLIC_FUNCTION(ppfRoomHandle) ppf_RoomArray_GetElement(const ppfRoomArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(size_t)        ppf_RoomArray_GetSize(const ppfRoomArrayHandle obj);
PPF_PUBLIC_FUNCTION(int32_t)       ppf_RoomArray_GetTotalCount(const ppfRoomArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)          ppf_RoomArray_HasNextPage(const ppfRoomArrayHandle obj);
PPF_PUBLIC_FUNCTION(int32_t)       ppf_RoomArray_GetPageSize(const ppfRoomArrayHandle obj);
PPF_PUBLIC_FUNCTION(int32_t)       ppf_RoomArray_GetPageIndex(const ppfRoomArrayHandle obj);

#endif
