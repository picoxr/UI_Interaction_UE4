#ifndef PPF_ASSETFILEDOWNLOADUPDATE_H
#define PPF_ASSETFILEDOWNLOADUPDATE_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include "PPF_AssetFileDownloadCompleteStatus.h"
#include <stdbool.h>

typedef struct ppfAssetFileDownloadUpdate *ppfAssetFileDownloadUpdateHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetFileDownloadUpdate_GetAssetId(const ppfAssetFileDownloadUpdateHandle obj);

/// Total number of bytes.
///
PPF_PUBLIC_FUNCTION(unsigned long long) ppf_AssetFileDownloadUpdate_GetBytesTotal(const ppfAssetFileDownloadUpdateHandle obj);

/// Number of bytes have been downloaded. -1 If the download hasn't started
/// yet.
///
PPF_PUBLIC_FUNCTION(long long)          ppf_AssetFileDownloadUpdate_GetBytesTransferred(const ppfAssetFileDownloadUpdateHandle obj);

/// Flag indicates the status of this download progress.
PPF_PUBLIC_FUNCTION(ppfAssetFileDownloadCompleteStatus) ppf_AssetFileDownloadUpdate_GetCompleteStatus(const ppfAssetFileDownloadUpdateHandle obj);


#endif
