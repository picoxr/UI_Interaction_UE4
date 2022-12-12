#ifndef PPF_ASSETSTATUS_H
#define PPF_ASSETSTATUS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"

typedef struct ppfAssetStatus *ppfAssetStatusHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetStatus_GetAssetId(const ppfAssetStatusHandle obj);

/// Asset filename
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetStatus_GetFilename(const ppfAssetStatusHandle obj);

/// File path of the asset file
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetStatus_GetFilepath(const ppfAssetStatusHandle obj);

/// One of 'available', 'downloaded', or 'in-progress'
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetStatus_GetDownloadStatus(const ppfAssetStatusHandle obj);

#endif
