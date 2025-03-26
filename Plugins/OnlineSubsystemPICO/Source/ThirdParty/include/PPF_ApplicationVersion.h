
#ifndef PPF_APPLICATIONVERSION_H
#define PPF_APPLICATIONVERSION_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"



typedef struct ppfApplicationVersion *ppfApplicationVersionHandle;


PPF_PUBLIC_FUNCTION(int64_t) ppf_ApplicationVersion_GetCurrentCode(const ppfApplicationVersionHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_ApplicationVersion_GetCurrentName(const ppfApplicationVersionHandle obj);


PPF_PUBLIC_FUNCTION(int64_t) ppf_ApplicationVersion_GetLatestCode(const ppfApplicationVersionHandle obj);


PPF_PUBLIC_FUNCTION(const char*) ppf_ApplicationVersion_GetLatestName(const ppfApplicationVersionHandle obj);



#endif
