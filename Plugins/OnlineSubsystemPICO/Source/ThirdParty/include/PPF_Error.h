// This file is generated automatically. Please don't edit it.


#ifndef PPF_ERROR_H
#define PPF_ERROR_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

/// @file PPF_Error.h
/// @ingroup Global

typedef struct ppfError *ppfErrorHandle;


PPF_PUBLIC_FUNCTION(const char*) ppf_Error_GetMessage(const ppfErrorHandle obj);


PPF_PUBLIC_FUNCTION(int) ppf_Error_GetCode(const ppfErrorHandle obj);



#endif

