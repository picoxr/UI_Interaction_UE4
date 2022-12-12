// This file is generated automatically. Please don't edit it.


#ifndef PPF_PERMISSIONRESULT_H
#define PPF_PERMISSIONRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfPermissionResult *ppfPermissionResultHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_PermissionResult_GetAuthorizedPermissions(const ppfPermissionResultHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_PermissionResult_GetAuthorizedPermissionsSize(const ppfPermissionResultHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_PermissionResult_GetAccessToken(const ppfPermissionResultHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_PermissionResult_GetUserID(const ppfPermissionResultHandle obj);



#endif

