#ifndef MATRIX_PPF_APPLICATIONVERSION_H
#define MATRIX_PPF_APPLICATIONVERSION_H

/// @file PPF_ApplicationVersion.h
/// @ingroup Social

typedef struct ppfApplicationVersion *ppfApplicationVersionHandle;

PPF_PUBLIC_FUNCTION(int)          ppf_ApplicationVersion_GetCurrentCode(const ppfApplicationVersionHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_ApplicationVersion_GetCurrentName(const ppfApplicationVersionHandle obj);
PPF_PUBLIC_FUNCTION(int)          ppf_ApplicationVersion_GetLatestCode(const ppfApplicationVersionHandle obj);
PPF_PUBLIC_FUNCTION(const char *) ppf_ApplicationVersion_GetLatestName(const ppfApplicationVersionHandle obj);


#endif //MATRIX_PPF_APPLICATIONVERSION_H
