// This file was @generated with LibPPFPlatform/codegen/main. Do not modify it!

#ifndef PPF_PIDARRAY_H
#define PPF_PIDARRAY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Pid.h"
#include <stddef.h>

typedef struct ppfPidArray *ppfPidArrayHandle;

PPF_PUBLIC_FUNCTION(ppfPidHandle) ppf_PidArray_GetElement(const ppfPidArrayHandle obj, size_t index);
PPF_PUBLIC_FUNCTION(size_t)       ppf_PidArray_GetSize(const ppfPidArrayHandle obj);

#endif
