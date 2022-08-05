#ifndef MATRIX_PPF_DESTINATIONARRAY_H
#define MATRIX_PPF_DESTINATIONARRAY_H

/// @file PPF_DestinationArray.h
/// @ingroup Social

typedef struct ppfDestinationArray *ppfDestinationArrayHandle;

PPF_PUBLIC_FUNCTION(ppfDestinationHandle) ppf_DestinationArray_GetElement(const ppfDestinationArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(const char *)         ppf_DestinationArray_GetNextPageParam(const ppfDestinationArrayHandle obj);
PPF_PUBLIC_FUNCTION(size_t)               ppf_DestinationArray_GetSize(const ppfDestinationArrayHandle obj);
PPF_PUBLIC_FUNCTION(bool)                 ppf_DestinationArray_HasNextPage(const ppfDestinationArrayHandle obj);


#endif //MATRIX_PPF_DESTINATIONARRAY_H
