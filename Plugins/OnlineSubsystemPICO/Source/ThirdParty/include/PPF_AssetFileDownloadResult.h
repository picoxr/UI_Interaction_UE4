#ifndef PPF_ASSETFILEDOWNLOADRESULT_H
#define PPF_ASSETFILEDOWNLOADRESULT_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"

typedef struct ppfAssetFileDownloadResult *ppfAssetFileDownloadResultHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetFileDownloadResult_GetAssetId(const ppfAssetFileDownloadResultHandle obj);

/// File path of the asset file.
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetFileDownloadResult_GetFilepath(const ppfAssetFileDownloadResultHandle obj);


#endif
