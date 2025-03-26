#ifndef PPF_REQUESTS_ASSETFILE_H
#define PPF_REQUESTS_ASSETFILE_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"


/// \file
/// # Asset Files
///
/// An asset file is an extra dynamic contents which can be downloaded post-installation at runtime. This allows reducing initial installation size, and download the contents as users progress in your app. As an example might be extra game levels which are downloaded after finishing first set of levels.
///
/// Asset files are also used as a storage layer for DLCs (downloadable content), which can be proposed to a user separately from the main app.
///
/// If your apps supports asset files, users are able to download them. and you also can manage the asset files from your app itself via SDK calls.

/// Removes an previously installed asset file from the device by its ID.
/// Returns an object containing the asset ID and file name, and a success
/// flag.
/// \param assetFileID The asset file ID
///
/// A message with type ::ppfMessageType_AssetFile_DeleteById will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDeleteResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDeleteResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DeleteById(ppfID assetFileID);

/// Removes an previously installed asset file from the device by its name.
/// Returns an object containing the asset ID and file name, and a success
/// flag.
/// \param assetFileName The asset file name
///
/// A message with type ::ppfMessageType_AssetFile_DeleteByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDeleteResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDeleteResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DeleteByName(const char *assetFileName);

/// Downloads an asset file by its ID on demand. Returns an object containing
/// the asset ID and filepath. Sends periodic
/// ppfNotification_AssetFile_DownloadUpdate to track the downloads.
/// \param assetFileID The asset file ID
///
/// A message with type ::ppfMessageType_AssetFile_DownloadById will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDownloadResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDownloadResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DownloadById(ppfID assetFileID);

/// Downloads an asset file by its name on demand. Returns an object containing
/// the asset ID and filepath. Sends periodic
/// {notifications.asset_file.download_update}} to track the downloads.
/// \param assetFileName The asset file name
///
/// A message with type ::ppfMessageType_AssetFile_DownloadByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDownloadResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDownloadResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DownloadByName(const char *assetFileName);

/// Cancels a previously spawned download request for an asset file by its ID.
/// Returns an object containing the asset ID and file path, and a success
/// flag.
/// \param assetFileID The asset file ID
///
/// A message with type ::ppfMessageType_AssetFile_DownloadCancelById will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDownloadCancelResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDownloadCancelResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DownloadCancelById(ppfID assetFileID);

/// Cancels a previously spawned download request for an asset file by its
/// name. Returns an object containing the asset ID and file path, and a
/// success flag.
/// \param assetFileName The asset file name
///
/// A message with type ::ppfMessageType_AssetFile_DownloadCancelByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetFileDownloadCancelResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetFileDownloadCancelResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_DownloadCancelByName(const char *assetFileName);

/// Returns an array of objects with asset file names and their associated IDs,
/// and and whether it's currently installed.
///
/// A message with type ::ppfMessageType_AssetFile_GetList will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetDetailsArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetDetailsArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_GetList();

/// @brief Get the next page of entries
///
/// A message with type ::ppfMessageType_AssetFile_GetNextAssetDetailsArrayPage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetDetailsArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetDetailsArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_GetNextAssetDetailsArrayPage(const char* params);

/// Returns the details on a single asset: ID, file name, and whether it's
/// currently installed
/// \param assetFileID The asset file ID
///
/// A message with type ::ppfMessageType_AssetFile_StatusById will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetStatusHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetStatus().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_StatusById(ppfID assetFileID);

/// Returns the details on a single asset: ID, file name, and whether it's
/// currently installed
/// \param assetFileName The asset file name
///
/// A message with type ::ppfMessageType_AssetFile_StatusByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAssetStatusHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAssetStatus().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_AssetFile_StatusByName(const char *assetFileName);

#endif
