// This file is generated automatically. Please don't edit it.

#ifndef PPF_USERARRAY_H
#define PPF_USERARRAY_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include <stdbool.h>
#include <stddef.h>
#include "PPF_User.h"

/// @file PPF_UserArray.h
/// @ingroup UserFriends

typedef struct ppfUserArray *ppfUserArrayHandle;


/// @brief Get a ppfUserHandle obj from ppfUserArrayHandle at position 'index'.
/// 
/// @param obj the ppfUserArrayHandle object.
/// @param index the position. 
/// @return The ppfUserHandle object or null.
///
PPF_PUBLIC_FUNCTION(ppfUserHandle) ppf_UserArray_GetElement(const ppfUserArrayHandle obj,size_t index);

/// @brief Get the size of ppfUserArrayHandle object.
/// 
/// @param obj the ppfUserArrayHandle object.
/// @return The size of this array.
///
PPF_PUBLIC_FUNCTION(size_t) ppf_UserArray_GetSize(const ppfUserArrayHandle obj);

/// @brief Check whether there has more ppfUserHandle objects?
/// 
/// @param obj the ppfUserArrayHandle object.
/// @return Indicate has more ppfUserHandle objects or not.
///
PPF_PUBLIC_FUNCTION(bool) ppf_UserArray_HasNextPage(const ppfUserArrayHandle obj);

/// @brief Get the next page param from ppfUserArrayHandle object.
/// 
/// @param obj the ppfUserArrayHandle object.
/// @return The next page param.
///
PPF_PUBLIC_FUNCTION(const char*) ppf_UserArray_GetNextPageParam(const ppfUserArrayHandle obj);

#endif
