// This file is generated automatically. Please don't edit it.


#ifndef PPF_USERANDROOM_H
#define PPF_USERANDROOM_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_User.h"
#include "PPF_Room.h"


typedef struct ppfUserAndRoom *ppfUserAndRoomHandle;


PPF_PUBLIC_FUNCTION(ppfUserHandle) ppf_UserAndRoom_GetUser(const ppfUserAndRoomHandle obj);


PPF_PUBLIC_FUNCTION(ppfRoomHandle) ppf_UserAndRoom_GetRoom(const ppfUserAndRoomHandle obj);



#endif

