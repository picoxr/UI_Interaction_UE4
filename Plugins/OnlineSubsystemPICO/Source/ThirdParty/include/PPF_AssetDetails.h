#ifndef PPF_ASSETDETAILS_H
#define PPF_ASSETDETAILS_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"

typedef struct ppfAssetDetails *ppfAssetDetailsHandle;

/// ID of the asset file
PPF_PUBLIC_FUNCTION(ppfID) ppf_AssetDetails_GetAssetId(const ppfAssetDetailsHandle obj);

/// One of 'default', 'store'. The 'default' type denotes
/// this Asset File is used purely as an implementation detail (to download
/// extra content post-installation). The 'store' type shows, that the Asset
/// File should be shown in Store.
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetAssetType(const ppfAssetDetailsHandle obj);

/// One of 'available', 'downloaded', or 'in-progress'
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetDownloadStatus(const ppfAssetDetailsHandle obj);

/// File path of the asset file
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetFilepath(const ppfAssetDetailsHandle obj);

/// One of 'entitled', or 'not-entitled'
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapStatus(const ppfAssetDetailsHandle obj);

/// Extra metadata associated with this asset file
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetMetadata(const ppfAssetDetailsHandle obj);

/// Asset filename
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetFilename(const ppfAssetDetailsHandle obj);

/// Asset version
PPF_PUBLIC_FUNCTION(int) ppf_AssetDetails_GetVersion(const ppfAssetDetailsHandle obj);

/// Iap SKU
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapSku(const ppfAssetDetailsHandle obj);

/// Iap name
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapName(const ppfAssetDetailsHandle obj);

/// Iap price
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapPrice(const ppfAssetDetailsHandle obj);

/// Iap currency
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapCurrency(const ppfAssetDetailsHandle obj);

/// Iap description
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapDescription(const ppfAssetDetailsHandle obj);

/// Iap icon
PPF_PUBLIC_FUNCTION(const char *) ppf_AssetDetails_GetIapIcon(const ppfAssetDetailsHandle obj);

#endif
