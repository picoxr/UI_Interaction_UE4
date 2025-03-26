// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/DelegateCombinations.h"
#include "PXR_AnchorComponent.h"

#include "PXR_MRAsyncActions.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICOCreateSpatialAnchorActionSuccess, EPICOResult, Result,const UPICOAnchorComponent*, AnchorComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOCreateSpatialAnchorActionFailure, EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICOPersistSpatialAnchorActionSuccess, EPICOResult, Result,const UPICOAnchorComponent*, AnchorComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOPersistSpatialAnchorActionFailure, EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICOUnpersistSpatialAnchorActionSuccess, EPICOResult, Result,const UPICOAnchorComponent*, AnchorComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOUnpersistSpatialAnchorActionFailure, EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICOLoadSpatialAnchorActionSuccess, EPICOResult, Result, const TArray<FAnchorLoadResult>&, AnchorLoadResults);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOLoadSpatialAnchorActionFailure, EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICOStartSpatialSceneCaptureActionSuccess, EPICOResult, Result, EPICOSpatialSceneCaptureStatus, SpatialSceneCaptureStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOStartSpatialSceneCaptureActionFailure, EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOStartProviderActionSuccess,EPICOResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOStartProviderActionFailure,EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOLaunchSceneCaptureAppActionSuccess,EPICOResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICOLaunchSceneCaptureAppActionFailure,EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICORequestSpatialMeshActionSuccess,EPICOResult, Result, const TArray<FPICOSpatialMeshInfo>&, MeshInfos);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICORequestSpatialMeshActionFailure,EPICOResult, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPICORequestSceneCapturesActionSuccess,EPICOResult, Result, const TArray<FPICOMRSceneInfo>&, SceneInfos);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPICORequestSceneCapturesActionFailure,EPICOResult, Result);

//////////////////////////////////////////////////////////////////////////
/// Spatial Anchor
//////////////////////////////////////////////////////////////////////////

/* UAsyncTask_LaunchAnchorService
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOLaunchSpatialAnchorService_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;


	/// <summary>
	/// Launch Spatial Anchor service.
	/// </summary>
	/// <returns>
	/// Result: Returns 0 for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// </returns>
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOLaunchSpatialAnchorService_AsyncAction* PXR_LaunchSpatialAnchorService_Async();

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionFailure OnFailure;

private:
	void HandleLaunchSpatialAnchorServiceComplete(const FPICOSpatialHandle& FutureHandle);
};

/* UAsyncTask_CreateAnchorEntity
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOCreateSpatialAnchor_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Creates an anchor entity in the app's memory.
	/// </summary>
	/// <param name="BoundActor">(In) Sets the actor of the anchor entity.</param>
	/// <param name="InSpatialAnchorTransform">(In) Sets the position, rotation, and scale of the anchor entity.</param>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// - AnchorComponent: Associated with an Actor. Each component updates the anchor entity's pose to the Actor during each Actor Tick. 
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOCreateSpatialAnchor_AsyncAction* PXR_CreateSpatialAnchor_Async(AActor* BoundActor, const FTransform& InSpatialAnchorTransform);

	UPROPERTY(BlueprintAssignable)
	FPICOCreateSpatialAnchorActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOCreateSpatialAnchorActionFailure OnFailure;

	UPROPERTY(Transient)
	AActor* BoundActor;

	FTransform SpatialAnchorTransform;

private:
	void HandleCreateSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleCreateAnchorEntityComplete(EPICOResult Result,const  UPICOAnchorComponent* AnchorComponent);

};

/* UAsyncTask_PersistAnchorEntity
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOPersistSpatialAnchor_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;
	/// <summary>
	/// Make specified anchor entities persistent, which means saving achor entities to specified location. You can choose local storage location or cloud storage location.
	/// </summary>
	/// <param name="BoundActor">Specifies the bound Actors of the to-be-persisted anchor entities.</param>
	/// <param name="PersistLocation">The location that the anchor entities are saved to:
	/// - Persist Location Local: device's local storage.
	/// - Persist Location Shared: cloud storage.
	/// </param>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// - AnchorComponent: Associated with an Actor. Each component updates the anchor entity's pose to the Actor during each Actor Tick. 
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOPersistSpatialAnchor_AsyncAction* PXR_PersistSpatialAnchor_Async(AActor* BoundActor, EPICOPersistLocation PersistLocation = EPICOPersistLocation::PersistLocation_Local);

	UPROPERTY(BlueprintAssignable)
	FPICOPersistSpatialAnchorActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOPersistSpatialAnchorActionFailure OnFailure;

	UPROPERTY()
	AActor* BoundActor;

	EPICOPersistLocation PersistLocation;

private:
	void HandlePersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleShareSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle);

	void HandlePersistAnchorEntityComplete(EPICOResult Result, const UPICOAnchorComponent* AnchorComponent);

};

/* UAsyncTask_UnpersistAnchorEntity
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOUnpersistSpatialAnchor_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Unpersists specified anchor entities, which means deleting anchor entities from the location where they are saved. Currently, it only supports deleting anchor entities saved in the device's local storage.
	/// </summary>
	/// <param name="BoundActor">Specifies the bound Actors of the to-be-unpersisted anchor entities.</param>
	/// <param name="PersistLocation">Specifies the location where the anchor entities are saved:
	/// - Persist Location Local: device's local storage.
	/// - Persist Location Shared: not supported.
	/// </param>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// - AnchorComponent: Associated with an Actor. Each component updates the anchor entity's pose to the Actor during each Actor Tick. 
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOUnpersistSpatialAnchor_AsyncAction* PXR_UnpersistSpatialAnchor_Async(AActor* BoundActor, EPICOPersistLocation PersistLocation = EPICOPersistLocation::PersistLocation_Local);

	UPROPERTY(BlueprintAssignable)
	FPICOUnpersistSpatialAnchorActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOUnpersistSpatialAnchorActionFailure OnFailure;

	UPROPERTY()
	AActor* BoundActor;

	EPICOPersistLocation PersistLocation;

private:
	void HandleUnpersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleUnpersistAnchorEntityComplete(EPICOResult Result, const UPICOAnchorComponent* AnchorComponent);

};

/* UAsyncTask_LoadAnchorEntity
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICORequestSpatialAnchors_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;


	/// <summary>
	/// Loads anchor entities from the device's local storage or cloud storage.
	/// </summary>
	/// <param name="LoadInfo">Specifying which anchor entities to load.
	/// - Persist Location:
	///   	- Persist Location Local: device's local storage
	/// 	- Persist Location Shared: cloud storage
	/// </param>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// - AnchorComponent: Associated with an Actor. Each component updates the anchor entity's pose to the Actor during each Actor Tick. 
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICORequestSpatialAnchors_AsyncAction* PXR_LoadSpatialAnchor_Async(const FPICOAnchorLoadInfo& LoadInfo);

	UPROPERTY(BlueprintAssignable)
	FPICOLoadSpatialAnchorActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOLoadSpatialAnchorActionFailure OnFailure;

	FPICOAnchorLoadInfo LoadInfo;

private:
	void HandleLoadSpatialAnchorsComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleDownloadSharedAnchorsComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleLoadAnchorEntityComplete(EPICOResult Result, const TArray<FAnchorLoadResult>& AnchorLoadResults);

	
	TSet<FPICOSpatialHandle> FutureHandleSet;
	TArray<FAnchorLoadResult> SharedAnchorLoadResults;
};

//////////////////////////////////////////////////////////////////////////
/// Spatial Mesh
//////////////////////////////////////////////////////////////////////////
/* UAsyncTask_LaunchMRMesh
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOLaunchSpatialMeshScanning_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Launches Spatial Mesh scanning.
	/// </summary>
	/// <returns>
	/// Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOLaunchSpatialMeshScanning_AsyncAction* PXR_LaunchSpatialMeshScanning_Async();

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionFailure OnFailure;

private:
	void HandleLaunchMeshScanningComplete(const FPICOSpatialHandle& FutureHandle);
};

/* UAsyncTask_RequestSpatialMesh
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICORequestSpatialMesh_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Requests Spatial Mesh Infos.
	/// </summary>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// - MeshInfos:An array of SpatialMeshInfo, contains Mesh UUID, pose, vertices, indices and so on.
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICORequestSpatialMesh_AsyncAction* PXR_RequestSpatialMeshInfos_Async();

	UPROPERTY(BlueprintAssignable)
	FPICORequestSpatialMeshActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICORequestSpatialMeshActionFailure OnFailure;

private:
	void HandleRequestSpatialMeshComplete(const FPICOSpatialHandle& FutureHandle);
};
//////////////////////////////////////////////////////////////////////////
/// Scene Capture
//////////////////////////////////////////////////////////////////////////
/* UAsyncTask_LaunchSceneCaptureService
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOLaunchSceneCaptureService_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Launches SceneCapture service.
	/// </summary>
	/// <returns>
	/// Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOLaunchSceneCaptureService_AsyncAction* PXR_LaunchSceneCaptureService_Async();

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOStartProviderActionFailure OnFailure;

private:
	void HandleLaunchSceneCaptureServiceComplete(const FPICOSpatialHandle& FutureHandle);
};

/* UAsyncTask_LaunchSceneCaptureApp
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICOLaunchSceneCaptureApp_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Launches SceneCapture App.
	/// </summary>
	/// <returns>
	/// Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes.
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICOLaunchSceneCaptureApp_AsyncAction* PXR_LaunchSceneCaptureApp_Async();

	UPROPERTY(BlueprintAssignable)
	FPICOLaunchSceneCaptureAppActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICOLaunchSceneCaptureAppActionFailure OnFailure;
	
private:
	void HandleLaunchSceneCaptureAppComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleStartSpatialSceneCaptureComplete(EPICOResult Result, EPICOSpatialSceneCaptureStatus SpatialSceneCaptureStatus);

};

/* UAsyncTask_RequestSpatialSceneInfo
 *****************************************************************************/
UCLASS()
class PICOXRMR_API UPICORequestSceneCaptures_AsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	virtual void Activate() override;

	/// <summary>
	/// Request SceneCaptures.
	/// </summary>
	/// <returns>
	/// - Result: Returns `0` for success and other values for failure. For failure reasons, refer to the EPICOResult enum. Currently, the returned error message result is unique, and you temporarily can not identify the error causes only in the result.
	/// - SceneloadInfos: An array of SceneInfo, contains UUID, pose, Semantic, SceneType and so on.
	/// </returns>	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPICORequestSceneCaptures_AsyncAction* PXR_RequestSceneCaptures_Async(const FPICOSceneLoadInfo& SceneLoadInfo);

	UPROPERTY(BlueprintAssignable)
	FPICORequestSceneCapturesActionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FPICORequestSceneCapturesActionFailure OnFailure;

	FPICOSceneLoadInfo SceneLoadInfo;

private:
	void HandleRequestSpatialSceneComplete(const FPICOSpatialHandle& FutureHandle);
	void HandleLoadSceneAnchorEntityComplete(EPICOResult Result, const TArray<FAnchorLoadResult>& AnchorLoadResults);

};