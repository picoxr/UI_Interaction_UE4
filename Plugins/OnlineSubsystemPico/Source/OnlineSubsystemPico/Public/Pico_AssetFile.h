// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_AssetFile.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_EXTERN(PicoAssetFile, Log, All);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FAssetFileDeleteResult, bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDeleteResult*, DeleteResult);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FAssetFileDownloadResult, bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadResult*, DownloadResult);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FAssetFileDownloadCancelResult, bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadCancelResult*, DownloadCancelResult);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetAssetFileStatus, bool, bIsError, const FString&, ErrorMessage, UPico_AssetStatus*, AssetFileStatus);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetAssetFileList, bool, bIsError, const FString&, ErrorMessage, UPico_AssetDetailsArray*, AssetDetailsArray);

DECLARE_MULTICAST_DELEGATE_OneParam(FAssetFileDownloadUpdateNotify, UPico_AssetFileDownloadUpdate* /*AssetFileDownloadUpdateObj*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FAssetFileDeleteForSafetyNotify, UPico_AssetFileDeleteForSafety* /*AssetFileDeleteForSafetyObj*/);

class ONLINESUBSYSTEMPICO_API FPicoAssetFileInterface
{
private:
	
	FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoAssetFileInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoAssetFileInterface();
	
	FAssetFileDeleteResult DeleteByIDDelegate;
	FAssetFileDeleteResult DeleteByNameDelegate;
    FAssetFileDownloadResult DownloadByIdDelegate;
    FAssetFileDownloadResult DownloadByNameDelegate;
    FAssetFileDownloadCancelResult DownloadCancelByIdDelegate;
    FAssetFileDownloadCancelResult DownloadCancelNameIdDelegate;
    FGetAssetFileStatus GetAssetFileStatusByIdDelegate;
    FGetAssetFileStatus GetAssetFileStatusByNameDelegate;
    FGetAssetFileList GetAssetFileListDelegate;
    FGetAssetFileList GetNextAssetDetailsArrayPageDelegate;

    /// <summary>
    /// Sets the callback to track the download progress of asset file.
    /// The `Transferred` field indicates the number of bytes downloaded.
    /// The `CompleteStatus` field indicates the download status.
    /// </summary>
    FAssetFileDownloadUpdateNotify AssetFileDownloadUpdateCallback;

    /// <summary>
    /// Sets the callback to automatically delete a downloaded asset file if it is different from the original one,
    /// and the app will receive a notification. 
    /// </summary>
    FAssetFileDeleteForSafetyNotify AssetFileDeleteForSafetyCallback;

    /// <summary>
    /// Deletes an installed asset file by asset file ID. The corresponding
    /// asset file will be removed from the device. 
    /// </summary>
    /// <param name="AssetFileID">The ID of the asset file to delete.</param>
    /// <param name="InDeleteByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
	bool DeleteByID(FString AssetFileID, FAssetFileDeleteResult InDeleteByIDDelegate);

    /// <summary>
    /// Deletes an installed asset file by asset file name. The corresponding
    /// asset file will be removed from the device. 
    /// </summary>
    /// <param name="AssetFileName">The name of the asset file to delete.</param>
    /// <param name="InDeleteByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
	bool DeleteByName(FString AssetFileName, FAssetFileDeleteResult InDeleteByNameDelegate);

    /// <summary>
    /// Downloads an asset file by asset file ID.
    /// </summary>
    /// <param name="AssetFileID">The ID of the asset file to download.</param>
    /// <param name="InDownloadByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool DownloadById(FString AssetFileID, FAssetFileDownloadResult InDownloadByIDDelegate);

    /// <summary>
    /// Downloads an asset file by asset file name.
    /// </summary>
    /// <param name="AssetFileName">The name of the asset file to download.</param>
    /// <param name="InDownloadByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool DownloadByName(FString AssetFileName, FAssetFileDownloadResult InDownloadByNameDelegate);

    /// <summary>
    /// Cancels the download of an asset file by asset file ID.
    /// </summary>
    /// <param name="AssetFileID">The ID of the asset file to cancel download for.</param>
    /// <param name="InDownloadCancelByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool DownloadCancelById(FString AssetFileID, FAssetFileDownloadCancelResult InDownloadCancelByIDDelegate);

    /// <summary>
    /// Cancels the download of an asset file by asset file name.
    /// </summary>
    /// <param name="AssetFileName">The name of the asset file to cancel download for.</param>
    /// <param name="InDownloadCancelByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool DownloadCancelByName(FString AssetFileName, FAssetFileDownloadCancelResult InDownloadCancelByNameDelegate);

    /// <summary>
    /// Gets the asset file list.  
    /// </summary>
    /// <param name="InGetAssetFileListDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetAssetFileList(FGetAssetFileList InGetAssetFileListDelegate);

    /// <summary>
    /// Gets the next page of the asset file list.
    /// </summary>
    /// <param name="InAssetDetailsArray">The current asset details array object.</param>
    /// <param name="InGetNextAssetDetailsArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetNextAssetDetailsArrayPage(UPico_AssetDetailsArray* InAssetDetailsArray, FGetAssetFileList InGetNextAssetDetailsArrayPageDelegate);
   
    /// <summary>
    /// Gets the download status of an asset file by asset file ID.
    /// </summary>
    /// <param name="AssetFileID">The ID of the asset file to get the download status for.</param>
    /// <param name="InGetAssetFileStatusByIdDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>     
    bool GetAssetFileStatusById(FString AssetFileID, FGetAssetFileStatus InGetAssetFileStatusByIdDelegate);

    /// <summary>
    /// Gets the download status of an asset file by asset file name.
    /// </summary>
    /// <param name="AssetFileName">The name of the asset file to get the download status for.</param>
    /// <param name="InGetAssetFileStatusByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>     
    bool GetAssetFileStatusByName(FString AssetFileName, FGetAssetFileStatus InGetAssetFileStatusByNameDelegate);

    FDelegateHandle AssetFileDownloadUpdateHandle;
    void OnAssetFileDownloadUpdate(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle AssetFileDeleteForSafetyHandle;
    void OnAssetFileDeleteForSafety(ppfMessageHandle Message, bool bIsError);
};

UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoAssetFileFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:


    /// <summary>
    /// Deletes an installed asset file by asset file ID. The corresponding
    /// asset file will be removed from the device. 
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileID">The ID of the installed asset file to delete.</param>
    /// <param name="InDeleteByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DeleteByID(UObject* WorldContextObject, FString AssetFileID, FAssetFileDeleteResult InDeleteByIDDelegate);

    /// <summary>
    /// Deletes an installed asset file by asset file name. The corresponding
    /// asset file will be removed from the device. 
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileName">The name of the installed asset file to delete.</param>
    /// <param name="InDeleteByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DeleteByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDeleteResult InDeleteByNameDelegate);

    /// <summary>
    /// Downloads an asset file by asset file ID.
    /// </summary>
    /// <param name ="WorldContextObject">The ID of the asset file to download.</param>
    /// <param name="AssetFileID">The asset file ID.</param>
    /// <param name="InDownloadByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DownloadById(UObject* WorldContextObject, FString AssetFileID, FAssetFileDownloadResult InDownloadByIDDelegate);

    /// <summary>
    /// Downloads an asset file by asset file name.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileName">The name of the asset file to download.</param>
    /// <param name="InDownloadByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DownloadByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDownloadResult InDownloadByNameDelegate);

    /// <summary>
    /// Cancels the download of an asset file by asset file ID.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileID">The ID of the asset file to cancel download for.</param>
    /// <param name="InDownloadCancelByIDDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DownloadCancelById(UObject* WorldContextObject, FString AssetFileID, FAssetFileDownloadCancelResult InDownloadCancelByIDDelegate);

    /// <summary>
    /// Cancels the download of an asset file by asset file name.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileName">The name of the asset file to cancel download for.</param>
    /// <param name="InDownloadCancelByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool DownloadCancelByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDownloadCancelResult InDownloadCancelByNameDelegate);

    /// <summary>
    /// Gets the asset file list.  
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetAssetFileListDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool GetAssetFileList(UObject* WorldContextObject, FGetAssetFileList InGetAssetFileListDelegate);

    /// <summary>
    /// Gets the next page of the asset file list.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InAssetDetailsArray">The current asset details array object.</param>
    /// <param name="InGetNextAssetDetailsArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool GetNextAssetDetailsArrayPage(UObject* WorldContextObject, UPico_AssetDetailsArray* InAssetDetailsArray, FGetAssetFileList InGetNextAssetDetailsArrayPageDelegate);

    /// <summary>
    /// Gets the download status of an asset file by asset file ID.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileID">The ID of the asset file to get the download status for.</param>
    /// <param name="InGetAssetFileStatusByIdDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool GetAssetFileStatusById(UObject* WorldContextObject, FString AssetFileID, FGetAssetFileStatus InGetAssetFileStatusByIdDelegate);

    /// <summary>
    /// Gets the download status of an asset file by asset file name.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="AssetFileName">The name of the asset file to get the download status for.</param>
    /// <param name="InGetAssetFileStatusByNameDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|AssetFile")
    static bool GetAssetFileStatusByName(UObject* WorldContextObject, FString AssetFileName, FGetAssetFileStatus InGetAssetFileStatusByNameDelegate);

};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetFileDeleteResult : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetFileDeleteResult* InppfAssetFileDeleteResultHandle);

private:
	FString AssetId = FString();
	FString FilePath = FString();
	bool bIsSuccessed = false;
	ppfID ppfAssetId = 0;

public:

	UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Delete Result")
	FString GetAssetId();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Delete Result")
	FString GetFilePath();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Delete Result")
	bool GetSuccess();

	ppfID GetppfAssetId();
};


UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetDetails : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetDetails* InppfAssetDetailsHandle);

private:
    FString AssetId = FString();
	FString AssetType = FString();
	FString DownloadStatus = FString();
    FString FilePath = FString();
	FString IapStatus = FString();
	FString Metadata = FString();
	FString Filename = FString();
	int32 Version = -1;
	FString IapSku = FString();
	FString IapName = FString();
	FString IapPrice = FString();
	FString IapCurrency = FString();
	FString IapDescription = FString();
	FString IapIconUrl = FString();
    ppfID ppfAssetId = 0;
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetFilePath();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
	FString GetAssetType();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetDownloadStatus();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapStatus();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetMetadata();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetFilename();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    int32 GetVersion();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapSku();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapPrice();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapCurrency();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapDescription();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details")
    FString GetIapIconUrl();

    ppfID GetppfAssetId();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetDetailsArray : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetDetailsArray* InppfAssetDetailsArrayHandle);

private:
    UPROPERTY()
    TArray<UPico_AssetDetails*> AssetDetailsArray;

    int32 Size = 0;
    bool bHasNextPage = false;
    FString NextPageParam = FString();


public:
    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details Array")
    UPico_AssetDetails* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details Array")
    int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details Array")
    bool GetHasNextPage();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Details Array")
    FString GetNextPageParam();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetFileDownloadCancelResult : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetFileDownloadCancelResult* InppfAssetFileDownloadCancelResultHandle);

private:
    FString AssetId = FString();
    FString FilePath = FString();
    bool bIsSuccessed = false;
    ppfID ppfAssetId = 0;

public:
    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Cancel Result")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Cancel Result")
    FString GetFilePath();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Cancel Result")
    bool GetSuccess();

    ppfID GetppfAssetId();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetFileDownloadUpdate : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetFileDownloadUpdate* InppfAssetFileDownloadUpdateHandle);

private:
    FString AssetId = FString();
    int64 BytesTotal = 0;
    int64 BytesTransferred = 0;
    EAssetFileDownloadCompleteStatus AssetFileDownloadCompleteStatus = EAssetFileDownloadCompleteStatus::Unkonw;
    ppfID ppfAssetId = 0;

public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Update")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Update")
    int64 GetBytesTotal();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Update")
    int64 GetBytesTransferred();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Update")
    EAssetFileDownloadCompleteStatus GetCompleteStatus();

    ppfID GetppfAssetId();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetFileDownloadResult : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetFileDownloadResult* InppfAssetFileDownloadResultHandle);

private:
    FString AssetId = FString();
    FString FilePath = FString();
    ppfID ppfAssetId = 0;

public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Result")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Download Result")
    FString GetFilePath();

    ppfID GetppfAssetId();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetStatus : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetStatus* InppfAssetStatusHandle);

private:
    FString AssetId = FString();
    FString FilePath = FString();
    FString FileName = FString();
    FString DownloadStatus = FString();
    ppfID ppfAssetId = 0;

public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Status")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Status")
    FString GetFilePath();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Status")
    FString GetFileName();

    // One of 'installed', 'available', or 'in-progress'
    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Asset Status")
    FString GetDownloadStatus();

    ppfID GetppfAssetId();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AssetFileDeleteForSafety : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAssetFileDeleteForSafety* InppfAssetFileDeleteForSafetyHandle);

private:
    FString AssetId = FString();
    FString Reason = FString();
    ppfID ppfAssetId = 0;

public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Delete For Safety")
    FString GetAssetId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|AssetFile|Delete For Safety")
    FString GetReason();

    ppfID GetppfAssetId();
};