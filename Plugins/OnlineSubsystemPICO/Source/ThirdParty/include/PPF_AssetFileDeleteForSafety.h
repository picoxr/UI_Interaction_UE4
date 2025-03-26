#ifndef PPF_ASSETFILEDELETEFORSAFETY_H
#define PPF_ASSETFILEDELETEFORSAFETY_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>

typedef struct ppfAssetFileDeleteForSafety *ppfAssetFileDeleteForSafetyHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetFileDeleteForSafety_GetAssetId(const ppfAssetFileDeleteForSafetyHandle obj);

/// reason for the delete
PPF_PUBLIC_FUNCTION(const char*) ppf_AssetFileDeleteForSafety_GetReason(const ppfAssetFileDeleteForSafetyHandle obj);

#endif
