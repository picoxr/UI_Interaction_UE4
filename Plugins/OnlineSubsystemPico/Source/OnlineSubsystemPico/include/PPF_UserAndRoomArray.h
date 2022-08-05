// This file is generated automatically. Please don't edit it.

#ifndef PPF_USERANDROOMARRAY_H
#define PPF_USERANDROOMARRAY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include <stdbool.h>
#include <stddef.h>
#include "PPF_UserAndRoom.h"


typedef struct ppfUserAndRoomArray *ppfUserAndRoomArrayHandle;



PPF_PUBLIC_FUNCTION(ppfUserAndRoomHandle) ppf_UserAndRoomArray_GetElement(const ppfUserAndRoomArrayHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_UserAndRoomArray_GetSize(const ppfUserAndRoomArrayHandle obj);


PPF_PUBLIC_FUNCTION(bool) ppf_UserAndRoomArray_HasNextPage(const ppfUserAndRoomArrayHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_UserAndRoomArray_GetNextPageParam(const ppfUserAndRoomArrayHandle obj);

#endif
