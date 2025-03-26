// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PXR_AnchorComponent.h"
#include "PXR_HMD.h"
#include "PXR_MRTypes.h"

DECLARE_DELEGATE_OneParam(FPICOPollFutureDelegate, const FPICOSpatialHandle&);

DECLARE_MULTICAST_DELEGATE_FourParams(FPICOCreateAnchorEntityEventDelegate, uint64_t, EPICOResult, const FPICOSpatialHandle&, const FPICOSpatialUUID&);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FPICOPersistAnchorEntityEventDelegate, uint64_t, EPICOResult, EPICOPersistLocation);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FPICOUnpersistAnchorEntityEventDelegate, uint64_t, EPICOResult, EPICOPersistLocation);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FPICOClearAnchorEntityEventDelegate, uint64_t, EPICOResult, EPICOPersistLocation);
DECLARE_MULTICAST_DELEGATE_FourParams(FPICOLoadAnchorEntityEventDelegate, uint64_t, EPICOResult, uint32_t, EPICOPersistLocation);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FPICOStartSpatialSceneCaptureEventDelegate, uint64_t, EPICOResult, EPICOSpatialSceneCaptureStatus);

DECLARE_DELEGATE_TwoParams(FPICOCreateAnchorEntityDelegate, EPICOResult, const UPICOAnchorComponent*);
DECLARE_DELEGATE_OneParam(FPICODestroyAnchorEntityDelegate, EPICOResult);
DECLARE_DELEGATE_TwoParams(FPICOPersistAnchorEntityDelegate, EPICOResult, const UPICOAnchorComponent*);
DECLARE_DELEGATE_TwoParams(FPICOUnpersistAnchorEntityDelegate, EPICOResult, const UPICOAnchorComponent*);
DECLARE_DELEGATE_OneParam(FPICOClearAnchorEntityDelegate, EPICOResult);
DECLARE_DELEGATE_TwoParams(FPICOLoadAnchorEntityDelegate, EPICOResult, const TArray<FAnchorLoadResult>&);
DECLARE_DELEGATE_TwoParams(FPICOStartSpatialSceneCaptureDelegate, EPICOResult, EPICOSpatialSceneCaptureStatus);

DECLARE_MULTICAST_DELEGATE_TwoParams(FPICOSpatialTrackingStateUpdateDelegate, EPICOSpatialTrackingState, EPICOSpatialTrackingStateMessage);




class IPXR_BaseProvider : public FNoncopyable
{
public:
	virtual ~IPXR_BaseProvider() = default;
	virtual bool CreateProvider(const FPICOSenseDataProviderCreateInfoBase& CreateInfo) =0;
	bool StartProvider(const FPICOPollFutureDelegate& StartSenseDataProviderDelegate,EPICOResult& OutResult);
	bool StartSenseDataProviderComplete(const FPICOSpatialHandle& FutureHandle, FPICOSenseDataProviderStartCompletion& Completion,EPICOResult& OutResult);
	bool QuerySenseDataComplete(const FPICOSpatialHandle& FutureHandle, FPICOSenseDataQueryCompletion& Completion,EPICOResult& OutResult);
	bool GetQueriedSenseData(const FPICOSpatialHandle& QueryResultHandle, FPICOQueriedSenseData& QueriedSenseData,EPICOResult& OutResult);
	bool DestroySenseDataQueryResult(const FPICOSpatialHandle& QueryResultHandle,EPICOResult& OutResult);
	
	virtual bool StopProvider();
	virtual bool DestroyProvider();
	EPICOMRState GetSenseDataProviderState() const;
	bool IsHandleValid() const { return ProviderHandle.IsValid(); }
	bool IsInitialized() const { return GetSenseDataProviderState() == EPICOMRState::Initialized; }
	bool IsRunning() const { return GetSenseDataProviderState() == EPICOMRState::Running; }
	bool IsEqualProvider(const FPICOSpatialHandle& Handle) const { return ProviderHandle==Handle; }
	void PXR_PollFuture();

	bool GetSpatialEntityLocation(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, FTransform& Transform,const FTransform& TrackingToWorld,const FQuat& BaseOrientation,const FVector& BaseOffsetInMeters,float WorldToMetersScale);
	bool GetSpatialEntitySemantic(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, TArray<EPICOSemanticLabel>& Semantics);
	bool GetSpatialEntityBoundary3D(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, FPICOBoundingBox3D& Box);
	bool GetSpatialEntityBoundary2D(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, FPICOBoundingBox2D& Box);
	bool GetSpatialEntityPolygon(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, TArray<FVector>& Vertices);
	bool GetSpatialEntityTriangleMesh(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, TArray<FVector>& Vertices, TArray<uint16>& Triangles);

	bool EnumerateSpatialEntityComponentTypes(const FPICOSpatialHandle& SnapshotHandle,const FPICOSpatialHandle& EntityHandle, TArray<EPICOSpatialEntityComponentType>& componentTypes);
	EPICOProviderType GetProviderType();
protected:
	FPICOSpatialHandle ProviderHandle;
	TQueue<FFutureMessage> FutureQueueForProviders;
	TMap<uint64_t, FPICOPollFutureDelegate> FutureToDelegateMap;
	bool AddPollFutureRequirement(const FPICOSpatialHandle& FutureHandle, const FPICOPollFutureDelegate& Delegate);
	FRWLock DestroyLock;
	EPICOProviderType Type=EPICOProviderType::Pico_Provider_Unknown;
};

struct FAnchorCreateInfo
{
	uint64_t AsyncTaskId;
	FPICOCreateAnchorEntityDelegate Delegate;
	UPICOAnchorComponent* AnchorComponent;
};

struct FAnchorPersistInfo
{
	uint64_t AsyncTaskId;
	FPICOPersistAnchorEntityDelegate Delegate;
	UPICOAnchorComponent* AnchorComponent;
};

struct FAnchorUnpersistInfo
{
	uint64_t AsyncTaskId;
	FPICOUnpersistAnchorEntityDelegate Delegate;
	UPICOAnchorComponent* AnchorComponent;
};

struct FAnchorClearInfo
{
	uint64_t AsyncTaskId;
	FPICOClearAnchorEntityDelegate Delegate;
};

struct FAnchorLoadInfo
{
	uint64_t AsyncTaskId;
	FPICOLoadAnchorEntityDelegate Delegate;
};

struct FStartSpatialSceneCaptureInfo
{
	uint64_t AsyncTaskId;
	FPICOStartSpatialSceneCaptureDelegate Delegate;
};

/**
 * 
 */
class FPICOProviderManager
{
public:
	static bool PXR_CreateSenseDataProvider(const FPICOSenseDataProviderCreateInfoBase& createInfo);
	static bool PXR_StartSenseDataProviderAsync(FPICOPollFutureDelegate Delegate, EPICOProviderType type,EPICOResult& Result);
	static bool PXR_StopSenseDataProvider(EPICOProviderType type);
	static bool PXR_DestroySenseDataProvider(EPICOProviderType type);
	static IPXR_BaseProvider* PXR_GetProviderInstance(EPICOProviderType type);

	static void PXR_PollFutureForProviders();
	static void PXR_SimulateUpdateForSceneCapture();
	static bool Initialize(FPICOXRHMD* InPICOXRHMD);
	static void PollEvent(PxrEventDataBuffer* EventData);
	static bool Finalize();
	static EPICOProviderType GetProviderTypeByHandle(const FPICOSpatialHandle& Handle);
	static EPICOResult CastToPICOResult(PxrResult Result);
	
	static float GetWorldToMetersScale();
	static FQuat GetBaseOrientation();
	static FVector GetBaseOffsetInMeters();
	static uint32 GetNextGameFrameNumber();
	static FTransform GetTrackingToWorldTransform();
	static double GetPredictedTime();
	static uint64 GetUUID();
	static bool ShouldUseLegacyMR(); 
	
	static FPICOCreateAnchorEntityEventDelegate CreateAnchorEntityEventDelegate;
	static FPICOPersistAnchorEntityEventDelegate PersistAnchorEntityEventDelegate;
	static FPICOUnpersistAnchorEntityEventDelegate UnpersistAnchorEntityEventDelegate;
	static FPICOClearAnchorEntityEventDelegate ClearAnchorEntityEventDelegate;
	static FPICOLoadAnchorEntityEventDelegate LoadAnchorEntityEventDelegate;
	static FPICOStartSpatialSceneCaptureEventDelegate StartSpatialSceneCaptureEventDelegate;
	
	static PxrSpatialSceneDataTypeFlags ConvertSemanticToSceneFlag(EPICOSemanticLabel Label);

private:
	static TSharedPtr<FPICOXRHMD> GetPICOXRHMDPtr();
	
	static TSharedPtr<FPICOXRHMD> PICOXRHMDPtr;

	static FDelegateHandle HandleOfPollEvent;
	static FDelegateHandle HandleOfPollFuture;
	static uint64 GlobalUUIDCount;
	
};


class PXR_AnchorProvider : public IPXR_BaseProvider
{
public:
	PXR_AnchorProvider();
	virtual ~PXR_AnchorProvider() override;
	virtual bool CreateProvider(const FPICOSenseDataProviderCreateInfoBase& CreateInfo) override;

	static PXR_AnchorProvider* GetInstance()
	{
		static PXR_AnchorProvider Instance;
		return &Instance;
	}
	
	bool CreateSpatialAnchorAsync(const FPICOPollFutureDelegate& Delegate,const FTransform& InAnchorEntityTransform,EPICOResult& OutResult);
	bool PersistSpatialAnchorAsync(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult);
	bool UnpersistSpatialAnchorAsync(AActor* BoundActor,const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult);
	bool ShareSpatialAnchorAsync(AActor* BoundActor,const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult);
	bool LoadAnchorEntityAsync(const FPICOAnchorLoadInfo& LoadInfo, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult);
	bool DownloadSharedSpatialAnchorsAsync(const FPICOAnchorLoadInfo& LoadInfo,const FPICOPollFutureDelegate& Delegate,TSet<FPICOSpatialHandle>& HandleSet,EPICOResult& OutResult);
	
	bool CreateSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorCreateCompletion& completion,EPICOResult& OutResult);
	bool PersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorPersistCompletion& completion,EPICOResult& OutResult);
	bool UnpersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorUnpersistCompletion& completion,EPICOResult& OutResult);
	bool ShareSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorShareCompletion& completion,EPICOResult& OutResult);
	bool DownloadSharedSpatialAnchorsComplete(const FPICOSpatialHandle& FutureHandle, FPICOSharedSpatialAnchorDownloadCompletion& completion,EPICOResult& OutResult);

	bool GetAnchorLoadResults(const FPICOSpatialHandle& FutureHandle,TArray<FAnchorLoadResult>& LoadResult,EPICOResult& OutResult);

	bool DestroyAnchorByHandle(const FPICOSpatialHandle& AnchorHandle,EPICOResult& OutResult);
	bool GetAnchorEntityUUID(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID,EPICOResult& OutResult);
	bool GetAnchorPose(UPICOAnchorComponent* AnchorComponent, FTransform& OutAnchorPose,EPICOResult& OutResult);
	bool UpdateAnchor(UPICOAnchorComponent* AnchorComponent,EPICOResult& OutResult);
	
	bool CreateAnchorEntityLegacy(AActor* BoundActor, const FTransform& AnchorEntityTransform, float Timeout, const FPICOCreateAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool DestroyAnchorEntityLegacy(AActor* BoundActor, const FPICODestroyAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool PersistAnchorEntityLegacy(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOPersistAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool UnpersistAnchorEntityLegacy(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOUnpersistAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool ClearAnchorEntityLegacy(EPICOPersistLocation PersistLocation, const FPICOClearAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool LoadAnchorEntityLegacy(EPICOLoadFilterType LoadFilterType,const FPICOAnchorLoadInfo& LoadInfo,const FPICOSceneLoadInfo& SceneLoadInfo, const FPICOLoadAnchorEntityDelegate& Delegate, EPICOResult& OutResult);
	bool StartSpatialSceneCapture(const FPICOStartSpatialSceneCaptureDelegate& Delegate, EPICOResult& OutResult);

	bool GetAnchorPoseLegacy(const FPICOSpatialHandle& AnchorHandle, FTransform& OutAnchorPose);
	bool GetAnchorComponentFlags(const FPICOSpatialHandle& AnchorHandle, TArray<EPICOAnchorComponentTypeFlag>& OutAnchorComponentFlags);
	bool GetAnchorSceneLabelLegacy(const FPICOSpatialHandle& AnchorHandle,EPICOSemanticLabel& OutSemanticLabel);
	bool GetAnchorEntityUUIDLegacy(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID);
	bool GetAnchorPoseLegacy(UPICOAnchorComponent* AnchorComponent, FTransform& OutAnchorPose);
	bool DestroyAnchorByHandleLegacy(const FPICOSpatialHandle& AnchorHandle);

	bool GetSpatialAnchorSceneInfosLegacy(const TArray<FAnchorLoadResult>& AnchorLoadResults,TArray<FPICOMRSceneInfo>& MRSceneInfos);

	bool GetSpatialSceneBoundingBox3DLegacy(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& Box);
	bool GetSpatialSceneBoundingBox2DLegacy(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& Box2D);
	bool GetSpatialSceneBoundingPolygonLegacy(const FPICOSpatialUUID& UUID, TArray<FVector>& Polygon);
	
private:
	bool IsAnchorValid(AActor* BoundActor);
	bool IsAnchorValid(UPICOAnchorComponent* AnchorComponent);
	
	UPICOAnchorComponent* GetAnchorComponent(AActor* BoundActor);

	FDelegateHandle HandleOfCreateAnchorEntity;
	FDelegateHandle HandleOfPersistAnchorEntity;
	FDelegateHandle HandleOfUnpersistAnchorEntity;
	FDelegateHandle HandleOfClearAnchorEntity;
	FDelegateHandle HandleOfLoadAnchorEntity;
	FDelegateHandle HandleOfStartSpatialSceneCapture;
	
	void HandleCreateAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, const FPICOSpatialHandle& AnchorHandle, const FPICOSpatialUUID& AnchorUUID);
	void HandlePersistAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation);
	void HandleUnpersistAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation);
	void HandleClearAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation);
	void HandleLoadAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, uint32_t AnchorCount, EPICOPersistLocation PersistLocation);
	void HandleStartSpatialSceneCaptureEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOSpatialSceneCaptureStatus SpatialSceneCaptureStatus);
	
	TMap<uint64_t, FAnchorCreateInfo> CreateAnchorBindings;
	TMap<uint64_t, FAnchorPersistInfo> PersistAnchorsBindings;
	TMap<uint64_t, FAnchorUnpersistInfo> UnpersistAnchorsBindings;
	TMap<uint64_t, FAnchorClearInfo> ClearAnchorsBindings;
	TMap<uint64_t, FAnchorLoadInfo> LoadAnchorsBindings;
	TMap<uint64_t, FStartSpatialSceneCaptureInfo> StartSpatialSceneCaptureBindings;

	TMap<FPICOSpatialUUID,FPICOSpatialHandle> UUIDToAnchorHandleMap;
};

class PXR_MeshProvider : public IPXR_BaseProvider
{
public:
	PXR_MeshProvider();

	static PXR_MeshProvider* GetInstance()
	{
		static PXR_MeshProvider Instance;
		return &Instance;
	}

	virtual bool CreateProvider(const FPICOSenseDataProviderCreateInfoBase& CreateInfo) override;
	virtual bool StopProvider() override;
	bool RequestSpatialTriangleMesh(const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult);
	bool GetSpatialTriangleMeshInfos(const FPICOSpatialHandle& FutureHandle,const FTransform& TrackingToWorld,
		const FQuat& BaseOrientation,
		const FVector& BaseOffsetInMeters,
		float WorldToMetersScale,
		TArray<FPICOSpatialMeshInfo>& MeshInfos,EPICOResult& OutResult);

	EPICOSpatialMeshLod GetCurrentSpatialMeshLod();
	void ClearMeshProviderBuffer();
	
private:
	bool IsContainsInLastUpdate(const FPICOSpatialUUID& UUID);
	uint64 GetLastUpdateTimeByUUID(const FPICOSpatialUUID& UUID);
	
	TMap<FPICOSpatialUUID, FPICOSpatialMeshInfo> CachedUUIDToMRMeshInfoMap;

	EPICOSpatialMeshLod CurrentLod;
	mutable FCriticalSection CriticalSection;
};

class PXR_SceneProvider : public IPXR_BaseProvider
{
public:
	PXR_SceneProvider();
	virtual bool CreateProvider(const FPICOSenseDataProviderCreateInfoBase& CreateInfo) override;
	static PXR_SceneProvider* GetInstance()
	{
		static PXR_SceneProvider Instance;
		return &Instance;
	}
	bool RequestSpatialSceneInfos(const FPICOSceneLoadInfo& LoadInfo, const FPICOPollFutureDelegate& Delegate,EPICOResult& Result);
	bool GetSpatialSceneInfos(const FPICOSpatialHandle& FutureHandle,TArray<FPICOMRSceneInfo>& SceneLoadInfos,EPICOResult& Result);
	bool StartSceneCaptureAsync(const FPICOPollFutureDelegate& Delegate,EPICOResult& Result);

	void ClearComponentBuffer();

	bool GetSpatialSceneBoundingBox3D(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& Box);
	bool GetSpatialSceneBoundingBox2D(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& Box2D);
	bool GetSpatialSceneBoundingPolygon(const FPICOSpatialUUID& UUID, TArray<FVector>& Polygon);
	bool StartSceneCaptureComplete(const FPICOSpatialHandle& FutureHandle,FPICOSceneCaptureStartCompletion& cPICOSceneCaptureStartCompletion);
	
private:
	TMap<FPICOSpatialUUID, TSharedRef<FPICOBoundingBox3D>> EntityToBoundingBox3DMap;
	TMap<FPICOSpatialUUID, TSharedRef<FPICOBoundingBox2D>> EntityToBoundingBox2DMap;
	TMap<FPICOSpatialUUID,TSharedRef<TArray<FVector>>> EntityToPolygonMap;

};
