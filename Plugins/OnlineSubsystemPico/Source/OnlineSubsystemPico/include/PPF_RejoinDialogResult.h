// This file was @generated with LibPPFPlatform/codegen/main. Do not modify it!

#ifndef PPF_REJOINDIALOGRESULT_H
#define PPF_REJOINDIALOGRESULT_H

#include "PPF_Platform_Defs.h"
#include <stdbool.h>

/// @file PPF_RejoinDialogResult.h
/// @ingroup Social

typedef struct ppfRejoinDialogResult *ppfRejoinDialogResultHandle;

/// @brief A boolean for if the user decided to rejoin.
PPF_PUBLIC_FUNCTION(bool) ppf_RejoinDialogResult_GetRejoinSelected(const ppfRejoinDialogResultHandle obj);


#endif
