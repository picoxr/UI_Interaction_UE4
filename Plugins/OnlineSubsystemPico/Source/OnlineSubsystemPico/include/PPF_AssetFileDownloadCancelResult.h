#ifndef PPF_ASSETFILEDOWNLOADCANCELRESULT_H
#define PPF_ASSETFILEDOWNLOADCANCELRESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>

typedef struct ppfAssetFileDownloadCancelResult *ppfAssetFileDownloadCancelResultHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetFileDownloadCancelResult_GetAssetId(const ppfAssetFileDownloadCancelResultHandle obj);

/// File path of the asset file.
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetFileDownloadCancelResult_GetFilepath(const ppfAssetFileDownloadCancelResultHandle obj);

/// Whether the cancel request is succeeded.
PPF_PUBLIC_FUNCTION(bool) ppf_AssetFileDownloadCancelResult_GetSuccess(const ppfAssetFileDownloadCancelResultHandle obj);


#endif
