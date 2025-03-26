#ifndef PPF_ASSETFILEDELETERESULT_H
#define PPF_ASSETFILEDELETERESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>

typedef struct ppfAssetFileDeleteResult *ppfAssetFileDeleteResultHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetFileDeleteResult_GetAssetId(const ppfAssetFileDeleteResultHandle obj);

/// File path of the asset file.
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetFileDeleteResult_GetFilepath(const ppfAssetFileDeleteResultHandle obj);

/// Whether the asset delete was successful.
PPF_PUBLIC_FUNCTION(bool) ppf_AssetFileDeleteResult_GetSuccess(const ppfAssetFileDeleteResultHandle obj);


#endif
