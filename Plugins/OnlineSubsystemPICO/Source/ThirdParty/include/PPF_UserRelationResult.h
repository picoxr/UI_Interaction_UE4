// This file is generated automatically. Please don't edit it.


#ifndef PPF_USERRELATIONRESULT_H
#define PPF_USERRELATIONRESULT_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_UserRelationType.h"


typedef struct ppfUserRelationResult *ppfUserRelationResultHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_UserRelationResult_GetRelationsKey(const ppfUserRelationResultHandle obj,int index);


PPF_PUBLIC_FUNCTION(ppfUserRelationType) ppf_UserRelationResult_GetRelationsValue(const ppfUserRelationResultHandle obj,int index);


PPF_PUBLIC_FUNCTION(int) ppf_UserRelationResult_GetRelationsSize(const ppfUserRelationResultHandle obj);



#endif

