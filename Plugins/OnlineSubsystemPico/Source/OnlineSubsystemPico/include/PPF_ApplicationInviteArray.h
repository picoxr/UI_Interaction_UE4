#ifndef MATRIX_PPF_APPLICATIONINVITEARRAY_H
#define MATRIX_PPF_APPLICATIONINVITEARRAY_H

/// @file PPF_ApplicationInviteArray.h
/// @ingroup Social

typedef struct ppfApplicationInviteArray *ppfApplicationInviteArrayHandle;

PPF_PUBLIC_FUNCTION(ppfApplicationInviteHandle) ppf_ApplicationInviteArray_GetElement(const ppfApplicationInviteArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)               ppf_ApplicationInviteArray_GetNextPageParam(const ppfApplicationInviteArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)                     ppf_ApplicationInviteArray_GetSize(const ppfApplicationInviteArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                       ppf_ApplicationInviteArray_HasNextPage(const ppfApplicationInviteArrayHandle obj);


#endif //MATRIX_PPF_APPLICATIONINVITEARRAY_H
