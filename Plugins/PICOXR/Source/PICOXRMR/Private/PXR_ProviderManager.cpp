// Fill out your copyright notice in the Description page of Project Settings.


#include "PXR_ProviderManager.h"

#include "PXR_AnchorComponent.h"
#include "PXR_HMD.h"
#include "PXR_HMDModule.h"
#include "PXR_MRTypes.h"
#include "PXR_Plugin_Types.h"
#include "PXR_Log.h"
#include "Algo/Transform.h"

TSharedPtr<FPICOXRHMD> FPICOProviderManager::PICOXRHMDPtr = nullptr;
FDelegateHandle FPICOProviderManager::HandleOfPollEvent;
FDelegateHandle FPICOProviderManager::HandleOfPollFuture;


FPICOCreateAnchorEntityEventDelegate FPICOProviderManager::CreateAnchorEntityEventDelegate;
FPICOPersistAnchorEntityEventDelegate FPICOProviderManager::PersistAnchorEntityEventDelegate;
FPICOUnpersistAnchorEntityEventDelegate FPICOProviderManager::UnpersistAnchorEntityEventDelegate;
FPICOClearAnchorEntityEventDelegate FPICOProviderManager::ClearAnchorEntityEventDelegate;
FPICOLoadAnchorEntityEventDelegate FPICOProviderManager::LoadAnchorEntityEventDelegate;
FPICOStartSpatialSceneCaptureEventDelegate FPICOProviderManager::StartSpatialSceneCaptureEventDelegate;

uint64 FPICOProviderManager::GlobalUUIDCount = 0;

bool IPXR_BaseProvider::StartProvider(const FPICOPollFutureDelegate& StartSenseDataProviderDelegate,EPICOResult& Result)
{
	FPICOSpatialHandle Handle;
	PXR_LOGI(PxrMR, "StartSenseDataProviderAsync Type:%d,ProviderHandle:%llu", Type, ProviderHandle.Value);
	int pxrResult =FPICOXRHMDModule::GetPluginWrapper().StartSenseDataProviderAsync(ProviderHandle.Value,&Handle.Value);
	bool bResult = PXRP_SUCCESS(pxrResult);
	Result=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(pxrResult));
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, StartSenseDataProviderDelegate);
	}
	PXR_LOGI(PxrMR, "ProviderType:%d,StartProvider:%d", Type, bResult);

	bResult = bResult ? Handle.IsValid() : false;
	return bResult;
}

bool IPXR_BaseProvider::StartSenseDataProviderComplete(const FPICOSpatialHandle& FutureHandle, FPICOSenseDataProviderStartCompletion& Completion,EPICOResult& OutResult)
{
	PxrSenseDataProviderStartCompletion SenseDataProviderStartCompletionBD = {};
	SenseDataProviderStartCompletionBD.type = PxrStructureType::PXR_TYPE_SENSE_DATA_PROVIDER_START_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().StartSenseDataProviderComplete(FutureHandle.GetValue(), &SenseDataProviderStartCompletionBD);
	Completion.FutureResult = FPICOProviderManager::CastToPICOResult(SenseDataProviderStartCompletionBD.futureResult);
	PXR_LOGV(PxrMR, "SenseDataProviderStartCompletionBD.futureResult:%d", SenseDataProviderStartCompletionBD.futureResult);

	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool IPXR_BaseProvider::QuerySenseDataComplete(const FPICOSpatialHandle& FutureHandle, FPICOSenseDataQueryCompletion& Completion,EPICOResult& OutResult)
{
	PxrSenseDataQueryCompletion cPxrSenseDataQueryCompletionBD = {};
	cPxrSenseDataQueryCompletionBD.type = PxrStructureType::PXR_TYPE_SENSE_DATA_QUERY_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().QuerySenseDataComplete(ProviderHandle.Value,FutureHandle.Value,&cPxrSenseDataQueryCompletionBD);
	Completion.SnapShotHandle = cPxrSenseDataQueryCompletionBD.snapshotHandle;
	
	PXR_LOGV(PxrMR, "cPxrSenseDataQueryCompletionBD.futureResult:%d", cPxrSenseDataQueryCompletionBD.futureResult);
	PXR_LOGV(PxrMR, "cPxrSenseDataQueryCompletionBD.snapshotHandle:%llu", cPxrSenseDataQueryCompletionBD.snapshotHandle);

	Completion.FutureResult = FPICOProviderManager::CastToPICOResult(cPxrSenseDataQueryCompletionBD.futureResult);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool IPXR_BaseProvider::GetQueriedSenseData(const FPICOSpatialHandle& QueryResultHandle, FPICOQueriedSenseData& QueriedSenseData,EPICOResult& OutResult)
{
	PxrQueriedSenseData cPxrQueriedSenseDataBD = {};
	cPxrQueriedSenseDataBD.type = PxrStructureType::PXR_TYPE_QUERIED_SENSE_DATA;
	cPxrQueriedSenseDataBD.queriedSpatialEntities = nullptr;
	cPxrQueriedSenseDataBD.queriedSpatialEntityCountOutput = 0;
	cPxrQueriedSenseDataBD.queriedSpatialEntityCapacityInput = 0;

	PxrQueriedSenseDataGetInfo cPxrQueriedSenseDataGetInfoBD = {};
	cPxrQueriedSenseDataGetInfoBD.snapshotHandle = QueryResultHandle.Value;
	PXR_LOGV(PxrMR, "GetQueriedSenseData QueryResultHandle:%llu", QueryResultHandle.Value);

	int Result = FPICOXRHMDModule::GetPluginWrapper().GetQueriedSenseData(ProviderHandle.Value,&cPxrQueriedSenseDataGetInfoBD,&cPxrQueriedSenseDataBD);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	bool bResult=PXRP_SUCCESS(Result);
	if (bResult)
	{
		PXR_LOGV(PxrMR, "GetQueriedSenseData queriedSpatialEntityCountOutput:%d", cPxrQueriedSenseDataBD.queriedSpatialEntityCountOutput);

		if (cPxrQueriedSenseDataBD.queriedSpatialEntityCountOutput == 0)
		{
			return bResult;
		}
		cPxrQueriedSenseDataBD.queriedSpatialEntityCapacityInput = cPxrQueriedSenseDataBD.queriedSpatialEntityCountOutput;

		QueriedSenseData.QueriedSpatialEntityInfos.SetNum(cPxrQueriedSenseDataBD.queriedSpatialEntityCapacityInput);
		cPxrQueriedSenseDataBD.queriedSpatialEntities = QueriedSenseData.QueriedSpatialEntityInfos.GetData();
		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetQueriedSenseData(ProviderHandle.Value,&cPxrQueriedSenseDataGetInfoBD,&cPxrQueriedSenseDataBD));
	}
	PXR_LOGV(PxrMR, "PXR_AnchorProvider->GetQueriedSenseData result:%d",bResult);

	return bResult;
}

bool IPXR_BaseProvider::DestroySenseDataQueryResult(const FPICOSpatialHandle& QueryResultHandle,EPICOResult& OutResult)
{
	FRWScopeLock Lock(DestroyLock, SLT_Write);
	PXR_LOGV(PxrMR, "DestroySenseDataQueryResult:%llu", QueryResultHandle.Value);
	int Result = FPICOXRHMDModule::GetPluginWrapper().DestroySenseDataQueryResult(QueryResultHandle.GetValue());
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool IPXR_BaseProvider::StopProvider()
{
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StopSenseDataProvider(ProviderHandle.GetValue()));
	PXR_LOGI(PxrMR, "Provider_Mesh StopProvider:%d", bResult);

	return bResult;
}

bool IPXR_BaseProvider::DestroyProvider()
{
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().DestroySenseDataProvider(ProviderHandle.GetValue()));
	PXR_LOGI(PxrMR, "Provider_Mesh DestroyProvider:%d", bResult);

	if (bResult)
	{
		ProviderHandle.Reset();
	}
	
	return bResult;
}

void IPXR_BaseProvider::PXR_PollFuture()
{
	PXR_LOGV(PxrMR, "PXR_PollFuture FutureToDelegateMap:%d", FutureToDelegateMap.Num());

	FFutureMessage CurrentMessage;
	PxrFuturePollInfoEXT FuturePollInfoEXT = {};
	FuturePollInfoEXT.type = PxrStructureType::PXR_TYPE_FUTURE_POLL_INFO_EXT;
	PxrFuturePollResultEXT FuturePollResultEXT = {};
	FuturePollResultEXT.type = PxrStructureType::PXR_TYPE_FUTURE_POLL_RESULT_EXT;

	PXR_LOGV(PxrMR, "Provider PollFuture Frame:%d", FPICOProviderManager::GetNextGameFrameNumber());

	uint64 LeftMessageCount = 0;
	bool hasFoundFrameBarrier = false;
	while (FutureQueueForProviders.Peek(CurrentMessage))
	{
		if (CurrentMessage.IsFrameBarrier)
		{
			PXR_LOGV(PxrMR, "Find FrameBarrier break!!!");
			CurrentMessage.IsFrameBarrier = false;
			FutureQueueForProviders.Pop();
			FutureQueueForProviders.Enqueue(CurrentMessage);
			break;
		}

		FutureQueueForProviders.Pop();

		FuturePollInfoEXT.future = CurrentMessage.MessageHandle.Value;
		FuturePollInfoEXT.type = PxrStructureType::PXR_TYPE_FUTURE_POLL_INFO_EXT;
		const bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().PollFutureEXT(&FuturePollInfoEXT,&FuturePollResultEXT));
		PXR_LOGV(PxrMR, "futurehandle:%llu", FuturePollInfoEXT.future);

		if (!bResult)
		{
			PXR_LOGV(PxrMR, "Provider PollFuture failed at:%d", FuturePollInfoEXT.future);
		}

		if (FuturePollResultEXT.state == PxrFutureStateEXT::PXR_FUTURE_STATE_READY_EXT
			&& FutureToDelegateMap.Contains(CurrentMessage.Uuid))
		{
			PXR_LOGV(PxrMR, "Future:%llu is Ready", CurrentMessage.Uuid);
			FutureToDelegateMap[CurrentMessage.Uuid].ExecuteIfBound(CurrentMessage.MessageHandle);
			FutureToDelegateMap.Remove(CurrentMessage.Uuid);
			PXR_LOGV(PxrMR, "FutureToDelegateMap.Remove %llu Finished", CurrentMessage.Uuid);
		}
		else
		{
			LeftMessageCount++;
			if (!hasFoundFrameBarrier)
			{
				CurrentMessage.IsFrameBarrier = true;
				hasFoundFrameBarrier = true;
				PXR_LOGV(PxrMR, "Provider has Set FoundFrameBarrier");
			}
			FutureQueueForProviders.Enqueue(CurrentMessage);
		}
	}
	PXR_LOGV(PxrMR, "Provider PollFuture LeftMessageCount:%d,FutureToDelegateMap:%d", LeftMessageCount, FutureToDelegateMap.Num());
}

bool IPXR_BaseProvider::GetSpatialEntityLocation(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, FTransform& Transform, const FTransform& TrackingToWorld,const FQuat& BaseOrientation, const FVector& BaseOffsetInMeters, float WorldToMetersScale)
{
	PxrSpatialEntityLocationGetInfo cComponentInfoGetInfo = {};

	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_LOCATION_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_LOCATION;
	cComponentInfoGetInfo.entity = EntityHandle.Value;

	PxrSpatialEntityLocationInfo cComponentInfo = {};
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_LOCATION_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

	if (bResult)
	{
		FPose UnrealPose;
		ConvertPose_Private(cComponentInfo.pose, UnrealPose, BaseOrientation, BaseOffsetInMeters, WorldToMetersScale);

		PXR_LOGV(PxrMR, "GetSpatialEntityLocation x:%f,y:%f,z:%f", UnrealPose.Position.X, UnrealPose.Position.Y, UnrealPose.Position.Z);

		Transform.SetLocation(TrackingToWorld.TransformPosition(UnrealPose.Position));
		Transform.SetRotation(TrackingToWorld.TransformRotation(UnrealPose.Orientation));
	}

	return bResult;
}

bool IPXR_BaseProvider::GetSpatialEntitySemantic(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, TArray<EPICOSemanticLabel>& Semantics)
{
	PxrSpatialEntitySemanticGetInfo cComponentInfoGetInfo = {};
	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_SEMANTIC_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_SEMANTIC;
	cComponentInfoGetInfo.entity = EntityHandle.Value;
	PxrSpatialEntitySemanticInfo cComponentInfo;
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_SEMANTIC_INFO;
	cComponentInfo.semanticLabels = nullptr;
	cComponentInfo.semanticCapacityInput = 0;

	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

	if (bResult)
	{
		cComponentInfo.semanticCapacityInput = cComponentInfo.semanticCountOutput;
		TArray<PxrSemanticLabel> TempSemantics;
		TempSemantics.SetNum(cComponentInfo.semanticCapacityInput);
		cComponentInfo.semanticLabels = TempSemantics.GetData();

		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
			.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
				, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

		if (bResult)
		{
			for (auto Semantic : TempSemantics)
			{
				Semantics.Add(static_cast<EPICOSemanticLabel>(Semantic));
			}
		}
	}

	return bResult;
}

bool IPXR_BaseProvider::GetSpatialEntityBoundary3D(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, FPICOBoundingBox3D& Box)
{
	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	PxrSpatialEntityBoundingBox3DGetInfo cComponentInfoGetInfo = {};
	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_BOUNDING_BOX_3D_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_BOUNDING_BOX_3D;
	cComponentInfoGetInfo.entity = EntityHandle.Value;
	PxrSpatialEntityBoundingBox3DInfo cComponentInfo = {};
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_BOUNDING_BOX_3D_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

	if (bResult)
	{
		PXR_LOGV(PxrMR, "GetSpatialEntityBoundary3D Success!");

		Box.Center.SetLocation(FVector(cComponentInfo.boundingBox3D.center.position.x,
							 cComponentInfo.boundingBox3D.center.position.y,
							 cComponentInfo.boundingBox3D.center.position.z) * WorldToMetersScale);

		Box.Center.SetRotation(FQuat(cComponentInfo.boundingBox3D.center.orientation.x,
							 cComponentInfo.boundingBox3D.center.orientation.y,
							 cComponentInfo.boundingBox3D.center.orientation.z,
							 cComponentInfo.boundingBox3D.center.orientation.w));
		
		Box.Extent.Width = cComponentInfo.boundingBox3D.extents.width * WorldToMetersScale;
		Box.Extent.Height = cComponentInfo.boundingBox3D.extents.height * WorldToMetersScale;
		Box.Extent.Depth = cComponentInfo.boundingBox3D.extents.depth * WorldToMetersScale;

		PXR_LOGV(PxrMR, "GetSpatialEntityBoundary3D Width:%f Height:%f Depth:%f!", Box.Extent.Width, Box.Extent.Height, Box.Extent.Depth);
	}

	return bResult;
}

bool IPXR_BaseProvider::GetSpatialEntityBoundary2D(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, FPICOBoundingBox2D& Box)
{
	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	PxrSpatialEntityBoundingBox2DGetInfo cComponentInfoGetInfo = {};
	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_BOUNDING_BOX_2D_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_BOUNDING_BOX_2D;
	cComponentInfoGetInfo.entity = EntityHandle.Value;
	PxrSpatialEntityBoundingBox2DInfo cComponentInfo = {};
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_BOUNDING_BOX_2D_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

	if (bResult)
	{
		PXR_LOGV(PxrMR, "GetSpatialEntityBoundary2D Success!");

		Box.Center = FVector(0, cComponentInfo.boundingBox2D.offset.x, cComponentInfo.boundingBox2D.offset.y) * WorldToMetersScale;
		Box.Extent.Width = cComponentInfo.boundingBox2D.extent.width * WorldToMetersScale;
		Box.Extent.Height = cComponentInfo.boundingBox2D.extent.height * WorldToMetersScale;

		PXR_LOGV(PxrMR, "GetSpatialEntityBoundary2D Width:%f Height:%f!", Box.Extent.Width, Box.Extent.Height);
	}

	return bResult;
}

bool IPXR_BaseProvider::GetSpatialEntityPolygon(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, TArray<FVector>& Vertices)
{
	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	PxrSpatialEntityPolygonGetInfo cComponentInfoGetInfo = {};
	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_POLYGON_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_POLYGON;
	cComponentInfoGetInfo.entity = EntityHandle.Value;
	PxrSpatialEntityPolygonInfo cComponentInfo = {};
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_POLYGON_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));
	PXR_LOGV(PxrMR, "cComponentInfo.polygonCountOutput:%d EntityHandle.Value:%llu", cComponentInfo.polygonCountOutput, EntityHandle.Value);

	if (bResult)
	{
		cComponentInfo.polygonCapacityInput = cComponentInfo.polygonCountOutput;

		TArray<PxrVector2f> TempVertices;
		TempVertices.SetNum(cComponentInfo.polygonCapacityInput);
		cComponentInfo.polygonVertices = TempVertices.GetData();

		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
			.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
				, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));


		if (bResult)
		{
			Vertices.Empty(TempVertices.Num());
			Algo::Transform(TempVertices, Vertices, [WorldToMetersScale](const auto& Vertex) { return FVector(0.f, Vertex.x, Vertex.y) * WorldToMetersScale; });
		}
	}

	return bResult;
}

bool IPXR_BaseProvider::GetSpatialEntityTriangleMesh(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, TArray<FVector>& Vertices, TArray<uint16>& Triangles)
{
	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	PxrSpatialEntityTriangleMeshGetInfo cComponentInfoGetInfo = {};
	cComponentInfoGetInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_TRIANGLE_MESH_GET_INFO;
	cComponentInfoGetInfo.componentType = PxrSpatialEntityComponentType::PXR_SPATIAL_ENTITY_COMPONENT_TYPE_TRIANGLE_MESH;
	cComponentInfoGetInfo.entity = EntityHandle.Value;
	PxrSpatialEntityTriangleMeshInfo cComponentInfo = {};
	cComponentInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ENTITY_TRIANGLE_MESH_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
			, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));
	PXR_LOGV(PxrMR, "cComponentInfo.vertexCountOutput:%d EntityHandle.Value:%llu", cComponentInfo.vertexCountOutput, EntityHandle.Value);

	if (bResult)
	{
		cComponentInfo.indexCapacityInput = cComponentInfo.indexCountOutput;
		cComponentInfo.vertexCapacityInput = cComponentInfo.vertexCountOutput;

		Triangles.SetNum(cComponentInfo.indexCapacityInput);
		cComponentInfo.indices = Triangles.GetData();


		TArray<PxrVector3f> TempVertices;
		TempVertices.SetNum(cComponentInfo.vertexCapacityInput);
		cComponentInfo.vertices = TempVertices.GetData();

		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
			.GetSpatialEntityComponentInfo(SnapshotHandle,reinterpret_cast<PxrSpatialEntityComponentInfoGetInfoBaseHeader*>(&cComponentInfoGetInfo)
				, reinterpret_cast<PxrSpatialEntityComponentInfoBaseHeader*>(&cComponentInfo)));

		if (bResult)
		{
			for (auto Vertice : TempVertices)
			{
				FVector VertexPose = ToFVector(Vertice) * WorldToMetersScale;
				if (VertexPose.ContainsNaN())
				{
					PXR_LOGE(PxrMR, "VertexPose.ContainsNaN EntityHandle.Value:%llu", EntityHandle.Value);
					return false;
				}
				Vertices.Add(VertexPose);
			}
		}
	}

	return bResult;
}

bool IPXR_BaseProvider::EnumerateSpatialEntityComponentTypes(const FPICOSpatialHandle& SnapshotHandle, const FPICOSpatialHandle& EntityHandle, TArray<EPICOSpatialEntityComponentType>& componentTypes)
{
	uint32_t ComponentTypeCapacityInput = 0;
	uint32_t ComponentTypeCountOutput = 0;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
		.EnumerateSpatialEntityComponentTypes(SnapshotHandle,EntityHandle.Value,ComponentTypeCapacityInput,&ComponentTypeCountOutput, nullptr));

	if (bResult && ComponentTypeCountOutput != 0)
	{
		ComponentTypeCapacityInput = ComponentTypeCountOutput;

		TArray<PxrSpatialEntityComponentType> TempComponentTypes;
		TempComponentTypes.SetNum(ComponentTypeCapacityInput);

		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper()
			.EnumerateSpatialEntityComponentTypes(SnapshotHandle,
				EntityHandle.Value,ComponentTypeCapacityInput,
				&ComponentTypeCountOutput,
				TempComponentTypes.GetData()));

		for (auto ComponentTypeBD : TempComponentTypes)
		{
			componentTypes.Add(static_cast<EPICOSpatialEntityComponentType>(ComponentTypeBD));
		}
	}

	return bResult;
}

EPICOProviderType IPXR_BaseProvider::GetProviderType()
{
	return Type;
}

EPICOMRState IPXR_BaseProvider::GetSenseDataProviderState() const
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		return EPICOMRState::Running;
	}
	
	EPICOMRState SenseDataProviderState = EPICOMRState::Stopped;
	PxrSenseDataProviderState cPxrSenseDataProviderStateBD = {};

	if (PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetSenseDataProviderState(ProviderHandle.Value,&cPxrSenseDataProviderStateBD)))
	{
		SenseDataProviderState = static_cast<EPICOMRState>(cPxrSenseDataProviderStateBD);
	}

	return SenseDataProviderState;
}

bool FPICOProviderManager::Initialize(FPICOXRHMD* InPICOXRHMD)
{
	PXR_LOGI(PxrMR, "FPICOProviderManager::Initialize");
	PICOXRHMDPtr = TSharedPtr<FPICOXRHMD>(InPICOXRHMD);

	bool bInitialized = false;
	const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();

	if (PICOXRHMDPtr)
	{
		PXR_LOGI(PxrMR, "FPICOProviderManager::Initialize Bind PollEvent");
		HandleOfPollEvent = PICOXRHMDPtr->OnPollEventDelegate().AddStatic(FPICOProviderManager::PollEvent);
		HandleOfPollFuture = PICOXRHMDPtr->OnPollFutureDelegate().AddStatic(FPICOProviderManager::PXR_PollFutureForProviders);
		if (ShouldUseLegacyMR()&&Settings->bEnableSceneCapture)
		{
			UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->RawLongHomePressedDelegate.AddStatic(FPICOProviderManager::PXR_SimulateUpdateForSceneCapture);
			FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddStatic(FPICOProviderManager::PXR_SimulateUpdateForSceneCapture);
		}
		
	}

	if (Settings->bEnableMesh)
	{
		FPICOSenseDataProviderCreateInfoMesh cFPICOSenseDataProviderCreateInfoMesh = {};
		cFPICOSenseDataProviderCreateInfoMesh.Lod = Settings->MeshLod;
		if (Settings->bSemanticsAlignWithTriangle)
		{
			cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic);
		}
		else if (Settings->bSemanticsAlignWithVertex)
		{
			cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic);
			cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic_Align_With_Vertex);
		}

		bInitialized = PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Mesh)->CreateProvider(cFPICOSenseDataProviderCreateInfoMesh);
	}

	if (Settings->bEnableAnchor)
	{
		FPICOSenseDataProviderCreateInfoAnchor cFPICOSenseDataProviderCreateInfoAnchor = {};

		bInitialized = PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Anchor)->CreateProvider(cFPICOSenseDataProviderCreateInfoAnchor);
	}

	if (Settings->bEnableSceneCapture)
	{
		FPICOSenseDataProviderCreateInfoSceneCapture cFPICOSenseDataProviderCreateInfoSceneCapture = {};

		bInitialized = PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Scene_Capture)->CreateProvider(cFPICOSenseDataProviderCreateInfoSceneCapture);
	}

	return bInitialized;
}

void FPICOProviderManager::PollEvent(PxrEventDataBuffer* EventData)
{
	PxrStructureType EventType = EventData->type;
	PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent %d", EventType);

	switch (EventType)
	{
	case PXR_TYPE_EVENT_DATA_SENSE_DATA_UPDATED:
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_SENSE_DATA_UPDATED");
			const PxrEventDataSenseDataUpdated* DataSenseDataState = reinterpret_cast<const PxrEventDataSenseDataUpdated*>(EventData);

			PXR_LOGV(PxrMR, "DataSenseDataState->provider %llu", DataSenseDataState->provider);

			switch (GetProviderTypeByHandle(DataSenseDataState->provider))
			{
			case EPICOProviderType::Pico_Provider_Anchor:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->AnchorDataUpdatedDelegate.Broadcast();
					PXR_LOGV(PxrMR, "FPICOProviderManager::AnchorDataUpdated");
				}
				break;
			case EPICOProviderType::Pico_Provider_Mesh:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshDataUpdatedDelegate.Broadcast();
					PXR_LOGV(PxrMR, "FPICOProviderManager::MeshDataUpdated");
				}
				break;
			case EPICOProviderType::Pico_Provider_Scene_Capture:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->SceneCaptureDataUpdatedDelegate.Broadcast();
					PXR_LOGV(PxrMR, "FPICOProviderManager::SceneCaptureDataUpdated");
				}
				break;
			default: ;
			};

			break;
		}
	case PXR_TYPE_EVENT_DATA_SENSE_DATA_PROVIDER_STATE_CHANGED:
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_SENSE_DATA_PROVIDER_STATE_CHANGED");
			const PxrEventDataSenseDataProviderStateChanged* SenseDataProviderState = reinterpret_cast<const PxrEventDataSenseDataProviderStateChanged*>(EventData);
			const EPICOMRState State=static_cast<EPICOMRState>(SenseDataProviderState->newState);
			switch (GetProviderTypeByHandle(SenseDataProviderState->provider))
			{
			case EPICOProviderType::Pico_Provider_Anchor:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->SpatialAnchorServiceStateUpdatedDelegate.Broadcast(State);
					PXR_LOGV(PxrMR, "FPICOProviderManager::SpatialAnchorServiceStateUpdated");
				}
				break;
			case EPICOProviderType::Pico_Provider_Mesh:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshScanningStateUpdatedDelegate.Broadcast(State);
					PXR_LOGV(PxrMR, "FPICOProviderManager::MeshScanningStateUpdated");
				}
				break;
			case EPICOProviderType::Pico_Provider_Scene_Capture:
				{
					UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->SceneCaptureServiceStateUpdatedDelegate.Broadcast(State);
					PXR_LOGV(PxrMR, "FPICOProviderManager::SceneCaptureServiceStateUpdated");
				}
				break;
			default: ;
			};
			break;
		}
	case PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CREATED: // CreateAnchorEntity				Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CREATED");
			const PxrEventDataAnchorEntityCreated* CreatedInfo = reinterpret_cast<const PxrEventDataAnchorEntityCreated*>(EventData);
			EPICOResult Result = CastToPICOResult(CreatedInfo->result);
			FPICOSpatialHandle AnchorHandle = CreatedInfo->anchorHandle;
			FPICOSpatialUUID AnchorUUID = CreatedInfo->uuid.value;
			CreateAnchorEntityEventDelegate.Broadcast(CreatedInfo->taskId, Result, AnchorHandle, AnchorUUID);
			break;
		}
	case PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_PERSISTED: // PersistAnchorEntity				Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_PERSISTED");
			const PxrEventDataAnchorEntityPersisted* PersistedInfo = reinterpret_cast<const PxrEventDataAnchorEntityPersisted*>(EventData);
			EPICOPersistLocation PersistLocation = (EPICOPersistLocation)PersistedInfo->location;
			EPICOResult Result = CastToPICOResult(PersistedInfo->result);
			PersistAnchorEntityEventDelegate.Broadcast(PersistedInfo->taskId, Result, PersistLocation);
			break;
		}
	case PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_UNPERSISTED: // UnpersistAnchorEntity			Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_UNPERSISTED");
			const PxrEventDataAnchorEntityUnpersisted* UnpersistedInfo = reinterpret_cast<const PxrEventDataAnchorEntityUnpersisted*>(EventData);
			EPICOPersistLocation PersistLocation = (EPICOPersistLocation)UnpersistedInfo->location;
			EPICOResult Result = CastToPICOResult(UnpersistedInfo->result);
			UnpersistAnchorEntityEventDelegate.Broadcast(UnpersistedInfo->taskId, Result, PersistLocation);
			break;
		}
	case PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CLEARED: // ClearAnchorEntity				Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_CLEARED");
			const PxrEventDataAnchorEntityCleared* ClearInfo = reinterpret_cast<const PxrEventDataAnchorEntityCleared*>(EventData);
			EPICOPersistLocation PersistLocation = (EPICOPersistLocation)ClearInfo->location;
			EPICOResult Result = CastToPICOResult(ClearInfo->result);
			ClearAnchorEntityEventDelegate.Broadcast(ClearInfo->taskId, Result, PersistLocation);
			break;
		}
	case PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_LOADED: // LoadAnchorEntity					Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_ANCHOR_ENTITY_LOADED");
			const PxrEventDataAnchorEntityLoaded* LoadedInfo = reinterpret_cast<const PxrEventDataAnchorEntityLoaded*>(EventData);
			EPICOPersistLocation PersistLocation = (EPICOPersistLocation)LoadedInfo->location;
			EPICOResult Result = CastToPICOResult(LoadedInfo->result);
			LoadAnchorEntityEventDelegate.Broadcast(LoadedInfo->taskId, Result, LoadedInfo->count, PersistLocation);
			break;
		}
	case PXR_TYPE_EVENT_DATA_SPATIAL_SCENE_CAPTURED: // SpatialSceneCaptured				Event
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent PXR_TYPE_EVENT_DATA_SPATIAL_SCENE_CAPTURED");
			const PxrEventDataSpatialSceneCaptured* CapturedInfo = reinterpret_cast<const PxrEventDataSpatialSceneCaptured*>(EventData);
			EPICOResult Result = CastToPICOResult(CapturedInfo->result);
			EPICOSpatialSceneCaptureStatus Status = (EPICOSpatialSceneCaptureStatus)CapturedInfo->status;
			StartSpatialSceneCaptureEventDelegate.Broadcast(CapturedInfo->taskId, Result, Status);
			break;
		}
	default:
		{
			PXR_LOGV(PxrMR, "FPICOProviderManager::PollEvent default");
			break;
		}
	}
}

bool FPICOProviderManager::Finalize()
{
	bool bResult = false;
	if (PXR_AnchorProvider::GetInstance()->IsHandleValid())
	{
		if (PXR_AnchorProvider::GetInstance()->IsRunning()
			&& PXR_AnchorProvider::GetInstance()->StopProvider())
		{
			bResult = PXR_AnchorProvider::GetInstance()->DestroyProvider();
		}
		else if (PXR_AnchorProvider::GetInstance()->IsInitialized())
		{
			bResult = PXR_AnchorProvider::GetInstance()->DestroyProvider();
		}
	}
	if (PXR_MeshProvider::GetInstance()->IsHandleValid())
	{
		if (PXR_MeshProvider::GetInstance()->IsRunning()
			&& PXR_MeshProvider::GetInstance()->StopProvider())
		{
			bResult = PXR_MeshProvider::GetInstance()->DestroyProvider();
		}
		else if (PXR_MeshProvider::GetInstance()->IsInitialized())
		{
			bResult = PXR_MeshProvider::GetInstance()->DestroyProvider();
		}
	}
	if (PXR_SceneProvider::GetInstance()->IsHandleValid())
	{
		if (PXR_SceneProvider::GetInstance()->IsRunning()
			&& PXR_SceneProvider::GetInstance()->StopProvider())
		{
			bResult = PXR_SceneProvider::GetInstance()->DestroyProvider();
		}
		else if (PXR_SceneProvider::GetInstance()->IsInitialized())
		{
			bResult = PXR_SceneProvider::GetInstance()->DestroyProvider();
		}
	}

	if (HandleOfPollEvent.IsValid() && GetPICOXRHMDPtr().IsValid())
	{
		GetPICOXRHMDPtr()->OnPollEventDelegate().Remove(HandleOfPollEvent);
	}

	if (HandleOfPollFuture.IsValid() && GetPICOXRHMDPtr().IsValid())
	{
		GetPICOXRHMDPtr()->OnPollFutureDelegate().Remove(HandleOfPollFuture);
	}

	PXR_LOGI(PxrMR, "FPICOProviderManager::Finalize Result:%d", bResult);
	return bResult;
}

EPICOProviderType FPICOProviderManager::GetProviderTypeByHandle(const FPICOSpatialHandle& Handle)
{
	if (PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Anchor)->IsEqualProvider(Handle.Value))
	{
		return EPICOProviderType::Pico_Provider_Anchor;
	}

	if (PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Mesh)->IsEqualProvider(Handle.Value))
	{
		return EPICOProviderType::Pico_Provider_Mesh;
	}

	if (PXR_GetProviderInstance(EPICOProviderType::Pico_Provider_Scene_Capture)->IsEqualProvider(Handle.Value))
	{
		return EPICOProviderType::Pico_Provider_Scene_Capture;
	}

	return EPICOProviderType::Pico_Provider_Max;
}


EPICOResult FPICOProviderManager::CastToPICOResult(PxrResult Result)
{
	EPICOResult PICOResult = EPICOResult::PXR_Error_Unknow;
	switch (Result)
	{
	case PxrResult::PXR_SUCCESS: PICOResult = EPICOResult::PXR_Success;
		break;
	case PxrResult::PXR_TIMEOUT_EXPIRED: PICOResult = EPICOResult::PXR_TimeoutExpired;
		break;
	case PxrResult::PXR_ERROR_VALIDATION_FAILURE: PICOResult = EPICOResult::PXR_Error_ValidationFailure;
		break;
	case PxrResult::PXR_ERROR_RUNTIME_FAILURE: PICOResult = EPICOResult::PXR_Error_RuntimeFailure;
		break;
	case PxrResult::PXR_ERROR_OUT_OF_MEMORY: PICOResult = EPICOResult::PXR_Error_OutOfMemory;
		break;
	case PxrResult::PXR_ERROR_API_VERSION_UNSUPPORTED: PICOResult = EPICOResult::PXR_Error_APIVersionUnsupported;
		break;
	case PxrResult::PXR_ERROR_INITIALIZATION_FAILED: PICOResult = EPICOResult::PXR_Error_InitializationFailed;
		break;
	case PxrResult::PXR_ERROR_FUNCTION_UNSUPPORTED: PICOResult = EPICOResult::PXR_Error_FunctionUnsupported;
		break;
	case PxrResult::PXR_ERROR_FEATURE_UNSUPPORTED: PICOResult = EPICOResult::PXR_Error_FeatureUnsupported;
		break;
	case PxrResult::PXR_ERROR_LIMIT_REACHED: PICOResult = EPICOResult::PXR_Error_LimitReached;
		break;
	case PxrResult::PXR_ERROR_SIZE_INSUFFICIENT: PICOResult = EPICOResult::PXR_Error_SizeInsufficient;
		break;
	case PxrResult::PXR_ERROR_HANDLE_INVALID: PICOResult = EPICOResult::PXR_Error_HandleInvalid;
		break;
	case PxrResult::PXR_ERROR_POSE_INVALID: PICOResult = EPICOResult::PXR_Error_Pose_Invalid;
		break;
	case PxrResult::PXR_ERROR_SPATIAL_LOCALIZATION_RUNNING: PICOResult = EPICOResult::PXR_Error_SpatialLocalizationRunning;
		break;
	case PxrResult::PXR_ERROR_SPATIAL_LOCALIZATION_NOT_RUNNING: PICOResult = EPICOResult::PXR_Error_SpatialLocalizationNotRunning;
		break;
	case PxrResult::PXR_ERROR_SPATIAL_MAP_CREATED: PICOResult = EPICOResult::PXR_Error_SpatialMapCreated;
		break;
	case PxrResult::PXR_ERROR_SPATIAL_MAP_NOT_CREATED: PICOResult = EPICOResult::PXR_Error_SpatialMapNotCreated;
		break;
	case PxrResult::PXR_ERROR_SPATIAL_SENSING_SERVICE_UNAVAILABLE: PICOResult = EPICOResult::PXR_Error_SpatialSensingServiceUnavailable;
		break;
	case PxrResult::PXR_ERROR_COMPONENT_NOT_SUPPORTED: PICOResult = EPICOResult::PXR_Error_ComponentNotSupported;
		break;
	case PxrResult::PXR_ERROR_COMPONENT_CONFLICT: PICOResult = EPICOResult::PXR_Error_ComponentConflict;
		break;
	case PxrResult::PXR_ERROR_COMPONENT_NOT_ADDED: PICOResult = EPICOResult::PXR_Error_ComponentNotAdded;
		break;
	case PxrResult::PXR_ERROR_COMPONENT_ADDED: PICOResult = EPICOResult::PXR_Error_ComponentAdded;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_ENTITY_NOT_FOUND: PICOResult = EPICOResult::PXR_Error_AnchorEntityNotFound;
		break;
	case PxrResult::PXR_ERROR_TRACKING_STATE_INVALID: PICOResult = EPICOResult::PXR_Error_Tracking_State_Invalid;
		break;
	case PxrResult::PXR_ERROR_SPACE_LOCATING: PICOResult = EPICOResult::PXR_Error_Space_Locating;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_SHARING_NETWORK_TIMEOUT: PICOResult = EPICOResult::PXR_Error_Anchor_Sharing_Network_Timeout;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_SHARING_AUTHENTICATION_FAILURE: PICOResult = EPICOResult::PXR_Error_Anchor_Sharing_Authentication_Failure;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_SHARING_NETWORK_FAILURE: PICOResult = EPICOResult::PXR_Error_Anchor_Sharing_Network_Failure;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_SHARING_LOCALIZATION_FAIL: PICOResult = EPICOResult::PXR_Error_Anchor_Sharing_Localization_Fail;
		break;
	case PxrResult::PXR_ERROR_ANCHOR_SHARING_MAP_INSUFFICIENT: PICOResult = EPICOResult::PXR_Error_Anchor_Sharing_Map_Insufficient;
		break;
	case PxrResult::PXR_ERROR_PERMISSION_INSUFFICIENT: PICOResult = EPICOResult::PXR_Error_Permission_Insufficient;
		break;
	default: break;
	}
	return PICOResult;
}

bool IPXR_BaseProvider::AddPollFutureRequirement(const FPICOSpatialHandle& FutureHandle, const FPICOPollFutureDelegate& Delegate)
{
	FFutureMessage cFutureMessage;
	cFutureMessage.MessageHandle = FutureHandle;
	cFutureMessage.Uuid = FPICOProviderManager::GetUUID();
	FutureToDelegateMap.Add(cFutureMessage.Uuid, Delegate);

	PXR_LOGV(PxrMR, "AddPollFutureRequirement:%llu cFutureMessage.Uuid:%llu", FutureHandle.Value, cFutureMessage.Uuid);

	PXR_LOGV(PxrMR, "FutureToDelegateMap:%d", FutureToDelegateMap.Num());

	return FutureQueueForProviders.Enqueue(cFutureMessage);
}

bool FPICOProviderManager::PXR_CreateSenseDataProvider(const FPICOSenseDataProviderCreateInfoBase& createInfo)
{
	switch (createInfo.Type)
	{
	case EPICOProviderType::Pico_Provider_Anchor:
		return PXR_AnchorProvider::GetInstance()->CreateProvider(createInfo);
	case EPICOProviderType::Pico_Provider_Mesh:
		return PXR_MeshProvider::GetInstance()->CreateProvider(createInfo);
	case EPICOProviderType::Pico_Provider_Scene_Capture:
		return PXR_SceneProvider::GetInstance()->CreateProvider(createInfo);
	default: ;
	}

	return false;
}

bool FPICOProviderManager::PXR_StartSenseDataProviderAsync(FPICOPollFutureDelegate Delegate, EPICOProviderType type,EPICOResult& Result)
{
	switch (type)
	{
	case EPICOProviderType::Pico_Provider_Anchor:
		return PXR_AnchorProvider::GetInstance()->StartProvider(Delegate,Result);
	case EPICOProviderType::Pico_Provider_Mesh:
		return PXR_MeshProvider::GetInstance()->StartProvider(Delegate,Result);
	case EPICOProviderType::Pico_Provider_Scene_Capture:
		return PXR_SceneProvider::GetInstance()->StartProvider(Delegate,Result);
	case EPICOProviderType::Pico_Provider_Max:
		break;
	default: ;
	}

	return false;
}

bool FPICOProviderManager::PXR_StopSenseDataProvider(EPICOProviderType type)
{
	switch (type)
	{
	case EPICOProviderType::Pico_Provider_Anchor:
		return PXR_AnchorProvider::GetInstance()->StopProvider();
	case EPICOProviderType::Pico_Provider_Mesh:
		return PXR_MeshProvider::GetInstance()->StopProvider();
	case EPICOProviderType::Pico_Provider_Scene_Capture:
		return PXR_SceneProvider::GetInstance()->StopProvider();
	default: ;
	}

	return false;
}

bool FPICOProviderManager::PXR_DestroySenseDataProvider(EPICOProviderType type)
{
	switch (type)
	{
	case EPICOProviderType::Pico_Provider_Anchor:
		return PXR_AnchorProvider::GetInstance()->DestroyProvider();
	case EPICOProviderType::Pico_Provider_Mesh:
		return PXR_MeshProvider::GetInstance()->DestroyProvider();
	case EPICOProviderType::Pico_Provider_Scene_Capture:
		return PXR_SceneProvider::GetInstance()->DestroyProvider();
	default: ;
	}

	return false;
}

IPXR_BaseProvider* FPICOProviderManager::PXR_GetProviderInstance(EPICOProviderType type)
{
	switch (type)
	{
	case EPICOProviderType::Pico_Provider_Anchor:
		return PXR_AnchorProvider::GetInstance();
	case EPICOProviderType::Pico_Provider_Mesh:
		return PXR_MeshProvider::GetInstance();
	case EPICOProviderType::Pico_Provider_Scene_Capture:
		return PXR_SceneProvider::GetInstance();
	default: ;
	}

	return nullptr;
}

void FPICOProviderManager::PXR_PollFutureForProviders()
{
	if (PXR_AnchorProvider::GetInstance()->IsHandleValid())
	{
		PXR_LOGV(PxrMR, "PXR_PollFutureForAnchorProvider");
		PXR_AnchorProvider::GetInstance()->PXR_PollFuture();
	}

	if (PXR_MeshProvider::GetInstance()->IsHandleValid())
	{
		PXR_LOGV(PxrMR, "PXR_PollFutureForMeshProvider");
		PXR_MeshProvider::GetInstance()->PXR_PollFuture();
	}

	if (PXR_SceneProvider::GetInstance()->IsHandleValid())
	{
		PXR_LOGV(PxrMR, "PXR_PollFutureForSceneProvider");
		PXR_SceneProvider::GetInstance()->PXR_PollFuture();
	}
}

void FPICOProviderManager::PXR_SimulateUpdateForSceneCapture()
{
	UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->SceneCaptureDataUpdatedDelegate.Broadcast();
	PXR_LOGV(PxrMR, "Simulate FPICOProviderManager::SceneCaptureDataUpdated");
}

TSharedPtr<FPICOXRHMD> FPICOProviderManager::GetPICOXRHMDPtr()
{
	return PICOXRHMDPtr;
}

float FPICOProviderManager::GetWorldToMetersScale()
{
	return GetPICOXRHMDPtr().IsValid() ? GetPICOXRHMDPtr()->GetWorldToMetersScale() : 100;
}

FQuat FPICOProviderManager::GetBaseOrientation()
{
	return GetPICOXRHMDPtr().IsValid()?GetPICOXRHMDPtr()->GetBaseOrientation():FQuat();
}

FVector FPICOProviderManager::GetBaseOffsetInMeters()
{
	return GetPICOXRHMDPtr().IsValid()?GetPICOXRHMDPtr()->GetBaseOffsetInMeters():FVector();
}

uint32 FPICOProviderManager::GetNextGameFrameNumber()
{
	return GetPICOXRHMDPtr().IsValid()?GetPICOXRHMDPtr()->NextGameFrameNumber:0;
}

FTransform FPICOProviderManager::GetTrackingToWorldTransform()
{
	return GetPICOXRHMDPtr().IsValid()?GetPICOXRHMDPtr()->GetTrackingToWorldTransform():FTransform();
}

double FPICOProviderManager::GetPredictedTime()
{
	return GetPICOXRHMDPtr().IsValid()?GetPICOXRHMDPtr()->CurrentFramePredictedTime:0;
}

uint64 FPICOProviderManager::GetUUID()
{
	return GlobalUUIDCount++;
}

bool FPICOProviderManager::ShouldUseLegacyMR()
{
	FString DeviceName = UPICOXRHMDFunctionLibrary::PXR_GetDeviceName();
	if (DeviceName.Equals("PICO 4")
		|| DeviceName.Equals("PICO 4 Pro")
		|| DeviceName.Equals("PICO 4 Enterprise"))
	{
		return true;
	}

	return false;
}


PxrSpatialSceneDataTypeFlags FPICOProviderManager::ConvertSemanticToSceneFlag(EPICOSemanticLabel Label)
{
	switch (Label)
	{
	case EPICOSemanticLabel::Unknown:
		return PXR_SPATIAL_SCENE_DATA_TYPE_UNKNOWN_BIT_;
	case EPICOSemanticLabel::Floor:
		return PXR_SPATIAL_SCENE_DATA_TYPE_FLOOR_BIT_;
	case EPICOSemanticLabel::Ceiling:
		return PXR_SPATIAL_SCENE_DATA_TYPE_CEILING_BIT_;
	case EPICOSemanticLabel::Wall:
		return PXR_SPATIAL_SCENE_DATA_TYPE_WALL_BIT_;
	case EPICOSemanticLabel::Door:
		return PXR_SPATIAL_SCENE_DATA_TYPE_DOOR_BIT_;
	case EPICOSemanticLabel::Window:
		return PXR_SPATIAL_SCENE_DATA_TYPE_WINDOW_BIT_;
	case EPICOSemanticLabel::Opening:
		return PXR_SPATIAL_SCENE_DATA_TYPE_OPENING_BIT_;
	case EPICOSemanticLabel::Table:
		return PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_;
	case EPICOSemanticLabel::Sofa:
		return PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_;
	case EPICOSemanticLabel::Chair:
		return PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_;
	case EPICOSemanticLabel::Human:
		return PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_;
	case EPICOSemanticLabel::VirtualWall:
		return PXR_SPATIAL_SCENE_DATA_TYPE_WALL_BIT_;
	default:
		PXR_LOGE(PxrMR, "Invalid EPICOSemanticLabel value:%d", Label);
		return PXR_SPATIAL_SCENE_DATA_TYPE_UNKNOWN_BIT_;
	}
}

PXR_AnchorProvider::PXR_AnchorProvider()
{
	HandleOfCreateAnchorEntity = FPICOProviderManager::CreateAnchorEntityEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandleCreateAnchorEntityEvent);
	HandleOfPersistAnchorEntity = FPICOProviderManager::PersistAnchorEntityEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandlePersistAnchorEntityEvent);
	HandleOfUnpersistAnchorEntity = FPICOProviderManager::UnpersistAnchorEntityEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandleUnpersistAnchorEntityEvent);
	HandleOfClearAnchorEntity = FPICOProviderManager::ClearAnchorEntityEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandleClearAnchorEntityEvent);
	HandleOfLoadAnchorEntity = FPICOProviderManager::LoadAnchorEntityEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandleLoadAnchorEntityEvent);
	HandleOfStartSpatialSceneCapture = FPICOProviderManager::StartSpatialSceneCaptureEventDelegate.AddRaw(this, &PXR_AnchorProvider::HandleStartSpatialSceneCaptureEvent);
}

PXR_AnchorProvider::~PXR_AnchorProvider()
{
	PXR_LOGI(PxrMR, "PXR_AnchorProvider Destruction");
	FPICOProviderManager::CreateAnchorEntityEventDelegate.Remove(HandleOfCreateAnchorEntity);
	FPICOProviderManager::PersistAnchorEntityEventDelegate.Remove(HandleOfPersistAnchorEntity);
	FPICOProviderManager::UnpersistAnchorEntityEventDelegate.Remove(HandleOfUnpersistAnchorEntity);
	FPICOProviderManager::ClearAnchorEntityEventDelegate.Remove(HandleOfClearAnchorEntity);
	FPICOProviderManager::LoadAnchorEntityEventDelegate.Remove(HandleOfLoadAnchorEntity);
	FPICOProviderManager::StartSpatialSceneCaptureEventDelegate.Remove(HandleOfStartSpatialSceneCapture);

	CreateAnchorBindings.Empty();
	PersistAnchorsBindings.Empty();
	UnpersistAnchorsBindings.Empty();
	ClearAnchorsBindings.Empty();
	LoadAnchorsBindings.Empty();
	StartSpatialSceneCaptureBindings.Empty();
	UUIDToAnchorHandleMap.Empty();
}

bool PXR_AnchorProvider::CreateSpatialAnchorAsync(const FPICOPollFutureDelegate& Delegate, const FTransform& InAnchorEntityTransform,EPICOResult& OutResult)
{
	FPICOSpatialHandle Handle;
	PxrSpatialAnchorCreateInfo cSpatialAnchorCreateInfoBD = {};
	cSpatialAnchorCreateInfoBD.type = PXR_TYPE_SPATIAL_ANCHOR_CREATE_INFO;
	FTransform TrackingToWorld=FPICOProviderManager::GetTrackingToWorldTransform();
	const FQuat TrackingOrientation = TrackingToWorld.Inverse().TransformRotation(InAnchorEntityTransform.Rotator().Quaternion());
	const FVector TrackingPosition = TrackingToWorld.Inverse().TransformPosition(InAnchorEntityTransform.GetLocation());
	
	FPose UnrealPose = FPose(TrackingOrientation, TrackingPosition);

	PxrPosef AnchorPose;
	ConvertPose_Private(UnrealPose, AnchorPose,
	                    FPICOProviderManager::GetBaseOrientation
	                    (), FPICOProviderManager::GetBaseOffsetInMeters(),
	                    FPICOProviderManager::GetWorldToMetersScale());

	cSpatialAnchorCreateInfoBD.pose = AnchorPose;
	cSpatialAnchorCreateInfoBD.timeMs=FPICOProviderManager::GetPredictedTime();
	int Result=FPICOXRHMDModule::GetPluginWrapper().CreateSpatialAnchorAsync(ProviderHandle.Value,&cSpatialAnchorCreateInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(Result);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_AnchorProvider::PersistSpatialAnchorAsync(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult)
{
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGV(PxrMR, "PersistSpatialAnchorAsync Actor is Invalid: Actor[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);

	FPICOSpatialHandle Handle;
	PxrSpatialAnchorPersistInfo SpatialAnchorPersistInfoBD = {};
	SpatialAnchorPersistInfoBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_PERSIST_INFO;
	SpatialAnchorPersistInfoBD.anchor = AnchorComponent->GetAnchorHandle();
	SpatialAnchorPersistInfoBD.location = static_cast<PxrPersistenceLocation>(PersistLocation);

	int Result=FPICOXRHMDModule::GetPluginWrapper().PersistSpatialAnchorAsync(ProviderHandle.Value,&SpatialAnchorPersistInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(Result);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_AnchorProvider::UnpersistSpatialAnchorAsync(AActor* BoundActor, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult)
{
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGV(PxrMR, "UnpersistSpatialAnchorAsync Actor is Invalid: Actor[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);

	FPICOSpatialHandle Handle;
	PxrSpatialAnchorUnpersistInfo SpatialAnchorUnpersistInfoBD = {};
	SpatialAnchorUnpersistInfoBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_PERSIST_INFO;
	SpatialAnchorUnpersistInfoBD.anchor = AnchorComponent->GetAnchorHandle();
	int Result=FPICOXRHMDModule::GetPluginWrapper().UnpersistSpatialAnchorAsync(ProviderHandle.Value,&SpatialAnchorUnpersistInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(Result);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_AnchorProvider::ShareSpatialAnchorAsync(AActor* BoundActor, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult)
{
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGV(PxrMR, "ShareSpatialAnchor Actor is Invalid: Actor[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);

	FPICOSpatialHandle Handle;
	PxrSpatialAnchorShareInfo SpatialAnchorShareInfo = {};
	SpatialAnchorShareInfo.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_SHARE_INFO;
	SpatialAnchorShareInfo.anchor = AnchorComponent->GetAnchorHandle();
	PXR_LOGV(PxrMR, "SpatialAnchorShareInfo.anchor:%llu", SpatialAnchorShareInfo.anchor);
	int Result=FPICOXRHMDModule::GetPluginWrapper().ShareSpatialAnchorAsync(ProviderHandle,&SpatialAnchorShareInfo,&Handle.Value);
	bool bResult = PXRP_SUCCESS(Result);

	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	
	PXR_LOGV(PxrMR, "ShareSpatialAnchorAsync bResult:%d", bResult);

	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_AnchorProvider::DownloadSharedSpatialAnchorsAsync(const FPICOAnchorLoadInfo& LoadInfo, const FPICOPollFutureDelegate& Delegate, TSet<FPICOSpatialHandle>& HandleSet,EPICOResult& OutResult)
{
	FPICOSpatialHandle Handle;
	bool bResult = false;
	
	if (LoadInfo.UUIDFilter.Num() > 0)
	{
		for (auto Uuid : LoadInfo.UUIDFilter)
		{
			PxrSharedSpatialAnchorDownloadInfo cSenseDataQueryInfoBD = {};
			cSenseDataQueryInfoBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_DOWNLOAD_INFO;

			PXR_LOGV(PxrMR, "SpatialAnchorShareInfo.uuid:%s", *Uuid.ToString());

			FMemory::Memcpy(cSenseDataQueryInfoBD.uuid.value, Uuid.UUIDArray);
			int Result=FPICOXRHMDModule::GetPluginWrapper().DownloadSharedSpatialAnchorAsync(ProviderHandle,&cSenseDataQueryInfoBD,&Handle.Value);
			bResult = PXRP_SUCCESS(Result);
			OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
			if (bResult)
			{
				bResult = AddPollFutureRequirement(Handle, Delegate);
				HandleSet.Add(Handle);
			}
		}
	}
	else
	{
		OutResult=EPICOResult::PXR_Error_ValidationFailure;
	}

	return bResult;
}

bool PXR_AnchorProvider::CreateSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorCreateCompletion& completion,EPICOResult& OutResult)
{
	PxrSpatialAnchorCreateCompletion SpatialAnchorCreateCompletionBD = {};
	SpatialAnchorCreateCompletionBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_CREATE_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().CreateSpatialAnchorComplete(ProviderHandle.Value,FutureHandle.GetValue(), &SpatialAnchorCreateCompletionBD);
	PXR_LOGV(PxrMR, "SpatialAnchorCreateCompletionBD FutureResult:%d", SpatialAnchorCreateCompletionBD.futureResult);
	PXR_LOGV(PxrMR, "SpatialAnchorCreateCompletionBD Result:%d", Result);
	completion.AnchorHandle = SpatialAnchorCreateCompletionBD.anchor;
	completion.UUID = SpatialAnchorCreateCompletionBD.uuid.value;
	completion.FutureResult = FPICOProviderManager::CastToPICOResult(SpatialAnchorCreateCompletionBD.futureResult);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	
	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::PersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorPersistCompletion& completion,EPICOResult& OutResult)
{
	PxrSpatialAnchorPersistCompletion SpatialAnchorPersistCompletionBD = {};
	SpatialAnchorPersistCompletionBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_PERSIST_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().PersistSpatialAnchorComplete(ProviderHandle.Value,FutureHandle.GetValue(), &SpatialAnchorPersistCompletionBD);
	PXR_LOGV(PxrMR, "SpatialAnchorPersistCompletionBD FutureResult:%d", SpatialAnchorPersistCompletionBD.futureResult);
	PXR_LOGV(PxrMR, "SpatialAnchorPersistCompletionBD Result:%d", Result);
	completion.AnchorHandle = SpatialAnchorPersistCompletionBD.anchor;
	completion.UUID = SpatialAnchorPersistCompletionBD.uuid.value;
	completion.FutureResult = FPICOProviderManager::CastToPICOResult(SpatialAnchorPersistCompletionBD.futureResult);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::UnpersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorUnpersistCompletion& completion,EPICOResult& OutResult)
{
	PxrSpatialAnchorUnpersistCompletion SpatialAnchorUnpersistCompletionBD = {};
	SpatialAnchorUnpersistCompletionBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_UNPERSIST_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().UnpersistSpatialAnchorComplete(ProviderHandle.Value,FutureHandle.GetValue(), &SpatialAnchorUnpersistCompletionBD);
	PXR_LOGV(PxrMR, "SpatialAnchorUnpersistCompletionBD FutureResult:%d", SpatialAnchorUnpersistCompletionBD.futureResult);
	PXR_LOGV(PxrMR, "SpatialAnchorUnpersistCompletionBD Result:%d", Result);
	completion.AnchorHandle = SpatialAnchorUnpersistCompletionBD.anchor;
	completion.UUID = SpatialAnchorUnpersistCompletionBD.uuid.value;
	completion.FutureResult = FPICOProviderManager::CastToPICOResult(SpatialAnchorUnpersistCompletionBD.futureResult);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::ShareSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle, FPICOSpatialAnchorShareCompletion& completion,EPICOResult& OutResult)
{
	PxrSpatialAnchorShareCompletion SpatialAnchorShareCompletion = {};
	SpatialAnchorShareCompletion.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_SHARE_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().ShareSpatialAnchorComplete(ProviderHandle,FutureHandle.GetValue(), &SpatialAnchorShareCompletion);
	PXR_LOGV(PxrMR, "ShareSpatialAnchorComplete FutureResult:%d", SpatialAnchorShareCompletion.futureResult);
	PXR_LOGV(PxrMR, "ShareSpatialAnchorComplete Result:%d", Result);
	completion.FutureResult = FPICOProviderManager::CastToPICOResult(SpatialAnchorShareCompletion.futureResult);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::DownloadSharedSpatialAnchorsComplete(const FPICOSpatialHandle& FutureHandle, FPICOSharedSpatialAnchorDownloadCompletion& completion,EPICOResult& OutResult)
{
	PxrSharedSpatialAnchorDownloadCompletion SharedSpatialAnchorDownloadCompletion = {};
	SharedSpatialAnchorDownloadCompletion.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_DOWNLOAD_COMPLETION;
	int Result = FPICOXRHMDModule::GetPluginWrapper().DownloadSharedSpatialAnchorComplete(ProviderHandle,FutureHandle.GetValue(), &SharedSpatialAnchorDownloadCompletion);
	PXR_LOGV(PxrMR, "DownloadSharedSpatialAnchorsComplete FutureResult:%d", SharedSpatialAnchorDownloadCompletion.futureResult);
	PXR_LOGV(PxrMR, "DownloadSharedSpatialAnchorsComplete Result:%d", Result);
	completion.FutureResult = FPICOProviderManager::CastToPICOResult(SharedSpatialAnchorDownloadCompletion.futureResult);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::LoadAnchorEntityAsync(const FPICOAnchorLoadInfo& LoadInfo, const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult)
{
	FPICOSpatialHandle Handle;
	PxrSenseDataQueryInfo cSenseDataQueryInfoBD = {};
	cSenseDataQueryInfoBD.type = PxrStructureType::PXR_TYPE_SENSE_DATA_QUERY_INFO;

	PxrSpatialEntityUuidFilter cPxrSpatialEntityUuidFilterBD = {};
	cPxrSpatialEntityUuidFilterBD.type = PXR_TYPE_SPATIAL_ENTITY_UUID_FILTER;
	cPxrSpatialEntityUuidFilterBD.uuidCount = LoadInfo.UUIDFilter.Num();
	TArray<PxrUuid> TempPxrUuidArray;
	TempPxrUuidArray.SetNum(cPxrSpatialEntityUuidFilterBD.uuidCount);

	if (cPxrSpatialEntityUuidFilterBD.uuidCount)
	{
		if (cPxrSpatialEntityUuidFilterBD.uuidCount > 0)
		{
			cPxrSpatialEntityUuidFilterBD.uuidList = TempPxrUuidArray.GetData();
			for (uint32_t Index = 0; Index < cPxrSpatialEntityUuidFilterBD.uuidCount; ++Index)
			{
				FMemory::Memcpy(cPxrSpatialEntityUuidFilterBD.uuidList[Index].value, LoadInfo.UUIDFilter[Index].UUIDArray);
			}
		}
		cSenseDataQueryInfoBD.filter = reinterpret_cast<PxrSenseDataQueryFilterBaseHeader*>(&cPxrSpatialEntityUuidFilterBD);
	}
	else
	{
		cSenseDataQueryInfoBD.filter = nullptr;
	}
	int Result=FPICOXRHMDModule::GetPluginWrapper().QuerySenseDataAsync(ProviderHandle.Value,&cSenseDataQueryInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(Result);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_AnchorProvider::GetAnchorLoadResults(const FPICOSpatialHandle& FutureHandle, TArray<FAnchorLoadResult>& LoadResult, EPICOResult& OutResult)
{
	FPICOSenseDataQueryCompletion SenseDataQueryCompletion;
	if (!QuerySenseDataComplete(FutureHandle, SenseDataQueryCompletion,OutResult))
	{
		return false;
	}
	
	if (PXR_FAILURE(SenseDataQueryCompletion.FutureResult))
	{
		OutResult = SenseDataQueryCompletion.FutureResult;
		return false;
	}

	if (!SenseDataQueryCompletion.SnapShotHandle.IsValid())
	{
		OutResult =EPICOResult::PXR_Error_HandleInvalid;
		return false;
	}
	
	FPICOQueriedSenseData QueriedSenseData;
	if (!GetQueriedSenseData(SenseDataQueryCompletion.SnapShotHandle, QueriedSenseData,OutResult))
	{
		return false;
	}
	
	for (auto Entity : QueriedSenseData.QueriedSpatialEntityInfos)
	{
		PxrSpatialEntityAnchorRetrieveInfo cPxrSpatialEntityAnchorRetrieveInfo = {};
		cPxrSpatialEntityAnchorRetrieveInfo.type = PXR_TYPE_SPATIAL_ENTITY_ANCHOR_RETRIEVE_INFO;
		cPxrSpatialEntityAnchorRetrieveInfo.spatialEntity = Entity.spatialEntity;
		FAnchorLoadResult cAnchorLoadResult;
		cAnchorLoadResult.PersistLocation = EPICOPersistLocation::PersistLocation_Local;
		cAnchorLoadResult.AnchorUUID=Entity.uuid.value;
		PXR_LOGV(PxrMR, "cPxrSpatialEntityAnchorRetrieveInfo.spatialEntity:%llu !!!", cPxrSpatialEntityAnchorRetrieveInfo.spatialEntity);
		
		if (PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().RetrieveSpatialEntityAnchor(SenseDataQueryCompletion.SnapShotHandle,
																								&cPxrSpatialEntityAnchorRetrieveInfo,
																								&cAnchorLoadResult.AnchorHandle.Value)))
		{
			LoadResult.Add(cAnchorLoadResult);
		}
		else
		{
			PXR_LOGV(PxrMR, "RetrieveSpatialEntityAnchor:%llu failed!!!", cPxrSpatialEntityAnchorRetrieveInfo.spatialEntity);
		}
	}
	
	if(!DestroySenseDataQueryResult(SenseDataQueryCompletion.SnapShotHandle,OutResult))
	{
		PXR_LOGV(PxrMR, "DestroySenseDataQueryResult Failed OutResult:%d", OutResult);
		return false;
	}
	
	return true;
}

bool PXR_AnchorProvider::CreateProvider(const FPICOSenseDataProviderCreateInfoBase& createInfo)
{
	check(createInfo.Type == EPICOProviderType::Pico_Provider_Anchor);

	Type = EPICOProviderType::Pico_Provider_Anchor;

	const FPICOSenseDataProviderCreateInfoAnchor& AnchorCreateInfo = static_cast<const FPICOSenseDataProviderCreateInfoAnchor&>(createInfo);
	PxrSpatialAnchorProviderCreateInfo cSpatialAnchorProviderCreateInfoBD = {};
	cSpatialAnchorProviderCreateInfoBD.type = PxrStructureType::PXR_TYPE_SPATIAL_ANCHOR_PROVIDER_CREATE_INFO;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().CreateSenseDataProvider(reinterpret_cast<PxrSenseDataProviderCreateInfoBaseHeader*>(&cSpatialAnchorProviderCreateInfoBD),&ProviderHandle.Value));

	if (!bResult)
	{
		ProviderHandle.Reset();
	}
	
	PXR_LOGI(PxrMR, "AnchorProvider CreateProvider:%d ProviderHandle:%llu", bResult, ProviderHandle.GetValue());

	bResult = bResult ? ProviderHandle.IsValid() : false;

	return bResult;
}

bool PXR_AnchorProvider::DestroyAnchorByHandle(const FPICOSpatialHandle& AnchorHandle,EPICOResult& OutResult)
{
	int Result = FPICOXRHMDModule::GetPluginWrapper().DestroyAnchor(AnchorHandle);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));
	
	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::IsAnchorValid(AActor* BoundActor)
{
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	if (!IsValid(AnchorComponent) || !AnchorComponent->IsAnchorValid())
	{
		return false;
	}
	return true;
}

bool PXR_AnchorProvider::IsAnchorValid(UPICOAnchorComponent* AnchorComponent)
{
	if (!IsValid(AnchorComponent) || !AnchorComponent->IsAnchorValid())
	{
		return false;
	}
	return true;
}

bool PXR_AnchorProvider::GetAnchorComponentFlags(const FPICOSpatialHandle& AnchorHandle, TArray<EPICOAnchorComponentTypeFlag>& OutAnchorComponentFlags)
{
	OutAnchorComponentFlags.Empty();

	PxrAnchorComponentTypeFlags PxrComponentFlags;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorComponentFlags(AnchorHandle.GetValue(), &PxrComponentFlags));

	PXR_LOGV(PxrMR, "GetAnchorComponentFlags Call PxrAPI Result[%d], Handle[%llu], FlagsValue[%llu]", (int32)Result, (uint64)AnchorHandle.GetValue(), (uint64)PxrComponentFlags);
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	UEnum* ComponentFlagsEnum = StaticEnum<EPICOAnchorComponentTypeFlag>();
	int32 EnumNum = ComponentFlagsEnum->NumEnums() - 1;
	for (int32 Index = 0; Index < EnumNum; ++Index)
	{
		int64 Value = ComponentFlagsEnum->GetValueByIndex(Index);
		if (Value != 0)
		{
			int64 PxrValue = 1ULL << (Value - 1);
			if (PxrValue & PxrComponentFlags)
			{
				PXR_LOGV(PxrMR, "GetAnchorComponentFlags FlagName[%s]", *ComponentFlagsEnum->GetNameStringByIndex(Index));
				OutAnchorComponentFlags.Add((EPICOAnchorComponentTypeFlag)Value);
			}
		}
	}
	return true;
}


bool PXR_AnchorProvider::GetAnchorPoseLegacy(const FPICOSpatialHandle& AnchorHandle, FTransform& OutAnchorPose)
{
	PxrTrackingOrigin TrackingOrigin = PxrTrackingOrigin::PXR_EYE_LEVEL;
	FPICOXRHMDModule::GetPluginWrapper().GetTrackingOrigin(&TrackingOrigin);

	PxrPosef AnchorPose;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPose(AnchorHandle.GetValue(), TrackingOrigin, &AnchorPose));

	PXR_LOGV(PxrMR, "GetAnchorPoseLegacy Call PxrAPI Result[%d]", (int32)Result);
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();

	FPose UnrealPose;
	ConvertPose_Private(AnchorPose, UnrealPose, FPICOProviderManager::GetBaseOrientation(), FPICOProviderManager::GetBaseOffsetInMeters(), WorldToMetersScale);

	FTransform TrackingToWorld = FPICOProviderManager::GetTrackingToWorldTransform();

	OutAnchorPose.SetLocation(TrackingToWorld.TransformPosition(UnrealPose.Position));
	OutAnchorPose.SetRotation(TrackingToWorld.TransformRotation(UnrealPose.Orientation));
	return true;
}

bool PXR_AnchorProvider::GetAnchorSceneLabelLegacy(const FPICOSpatialHandle& AnchorHandle, EPICOSemanticLabel& OutSemanticLabel)
{
	PxrSceneLabel SceneLabel;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorSceneLabel(AnchorHandle.GetValue(), &SceneLabel));

	PXR_LOGV(PxrMR, "GetAnchorSceneLabelLegacy Call PxrAPI Result[%d], Handle[%llu], SceneLabel[%d]", (int32)Result, (uint64)AnchorHandle.GetValue(), (int32)SceneLabel);
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	OutSemanticLabel = (EPICOSemanticLabel)SceneLabel;
	return true;
}

bool PXR_AnchorProvider::GetAnchorEntityUUIDLegacy(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID)
{
	if (!IsAnchorValid(BoundActor))
	{
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);
	FPICOSpatialHandle AnchorHandle = AnchorComponent->GetAnchorHandle();
	PxrUUid PxrAnchorUUID;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorEntityUuid(AnchorHandle.GetValue(), &PxrAnchorUUID));

	PXR_LOGV(PxrMR, "GetAnchorEntityUUIDLegacy Call PxrAPI Result[%d], Handle[%llu]", (int32)Result, (uint64)AnchorHandle.GetValue());
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	OutAnchorUUID = PxrAnchorUUID.value;

	PXR_LOGV(PxrMR, "GetAnchorEntityUUIDLegacy AnchorUUID[%s]", *OutAnchorUUID.ToString());
	return true;
}

bool PXR_AnchorProvider::GetAnchorPoseLegacy(UPICOAnchorComponent* AnchorComponent, FTransform& OutAnchorPose)
{
	if (!IsAnchorValid(AnchorComponent))
	{
		return false;
	}

	FPICOSpatialHandle AnchorHandle = AnchorComponent->GetAnchorHandle();

	PxrTrackingOrigin TrackingOrigin = PxrTrackingOrigin::PXR_EYE_LEVEL;
	FPICOXRHMDModule::GetPluginWrapper().GetTrackingOrigin(&TrackingOrigin);

	PxrPosef AnchorPose;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPose(AnchorHandle.GetValue(), TrackingOrigin, &AnchorPose));

	PXR_LOGV(PxrMR, "GetAnchorPoseLegacy Call PxrAPI Result[%d]", (int32)Result);
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	float WorldToMetersScale = AnchorComponent->GetWorld()->GetWorldSettings()->WorldToMeters;

	FPose UnrealPose;
	ConvertPose_Private(AnchorPose, UnrealPose, FPICOProviderManager::GetBaseOrientation(), FPICOProviderManager::GetBaseOffsetInMeters(), WorldToMetersScale);

	FTransform TrackingToWorld = FPICOProviderManager::GetTrackingToWorldTransform();

	OutAnchorPose.SetLocation(TrackingToWorld.TransformPosition(UnrealPose.Position));
	OutAnchorPose.SetRotation(TrackingToWorld.TransformRotation(UnrealPose.Orientation));
	return true;
}

bool PXR_AnchorProvider::DestroyAnchorByHandleLegacy(const FPICOSpatialHandle& AnchorHandle)
{
	if (!AnchorHandle.IsValid())
	{
		PXR_LOGV(PxrMR, "DestroyAnchorByHandleLegacy AnchorHandle is Invalid");
		return false;
	}

	PxrAnchorEntityDestroyInfo EntityInfo;
	EntityInfo.anchor = AnchorHandle.GetValue();
	PXR_LOGV(PxrMR, "DestroyAnchorByHandleLegacy: AnchorHandle[%llu]", EntityInfo.anchor);

	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().DestroyAnchorEntity(&EntityInfo));
	
	PXR_LOGV(PxrMR, "DestroyAnchorByHandleLegacy: Result[%d]", (int32)Result);

	return PXR_SUCCESS(Result);
}

bool PXR_AnchorProvider::GetSpatialAnchorSceneInfosLegacy(const TArray<FAnchorLoadResult>& AnchorLoadResults, TArray<FPICOMRSceneInfo>& MRSceneInfos)
{
	UUIDToAnchorHandleMap.Empty();
	
	for (auto LoadResult:AnchorLoadResults)
	{
		FPICOSpatialHandle AnchorHandle=LoadResult.AnchorHandle;
		FPICOMRSceneInfo MRSceneInfo;
		PxrTrackingOrigin TrackingOrigin = PxrTrackingOrigin::PXR_EYE_LEVEL;
		FPICOXRHMDModule::GetPluginWrapper().GetTrackingOrigin(&TrackingOrigin);
		PxrUUid PxrAnchorUUID;
		EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorEntityUuid(AnchorHandle, &PxrAnchorUUID));
		MRSceneInfo.UUID = PxrAnchorUUID.value;

		UUIDToAnchorHandleMap.Emplace(MRSceneInfo.UUID,AnchorHandle);

		bool bSingleLoopResult=false;
		
		if (PXR_SUCCESS(Result))
		{
			PxrPosef AnchorPose;
			Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPose(AnchorHandle, TrackingOrigin, &AnchorPose));
			if (PXR_SUCCESS(Result))
			{
				if (GetAnchorPoseLegacy(AnchorHandle, MRSceneInfo.ScenePose))
				{
					if (GetAnchorSceneLabelLegacy(AnchorHandle, MRSceneInfo.Semantic))
					{
						TArray<EPICOAnchorComponentTypeFlag> AnchorComponentFlags;
						if (GetAnchorComponentFlags(AnchorHandle, AnchorComponentFlags))
						{
							if (AnchorComponentFlags.Contains(EPICOAnchorComponentTypeFlag::ComponentFlag_Plane))
							{
								if (MRSceneInfo.Semantic == EPICOSemanticLabel::Floor
									|| MRSceneInfo.Semantic == EPICOSemanticLabel::Ceiling)
								{
									MRSceneInfo.SceneType = EPICOSceneType::BoundingPolygon;
								}
								else
								{
									MRSceneInfo.SceneType = EPICOSceneType::BoundingBox2D;
								}
							}
							else if (AnchorComponentFlags.Contains(EPICOAnchorComponentTypeFlag::ComponentFlag_Volume))
							{
								MRSceneInfo.SceneType = EPICOSceneType::BoundingBox3D;
							}
							bSingleLoopResult=true;
							MRSceneInfos.Add(MRSceneInfo);
						}
					}
				}
			}
		}

		if (!bSingleLoopResult)
		{
			return false;
		}
	}
	
	return true;
}

bool PXR_AnchorProvider::GetSpatialSceneBoundingBox3DLegacy(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& Box)
{
	if(!UUIDToAnchorHandleMap.Contains(UUID))
	{
		return false;
	}

	const FPICOSpatialHandle AnchorHandle=UUIDToAnchorHandleMap[UUID];

	PxrAnchorBoxInfo BoxInfo;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorBoxInfo(AnchorHandle.GetValue(), &BoxInfo));

	PXR_LOGV(PxrMR, "GetAnchorBoxInfo Call PxrAPI Result[%d], Handle[%llu]", (int32)Result, (uint64)AnchorHandle.GetValue());
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	Box.Center.SetLocation(FVector(BoxInfo.center.x,BoxInfo.center.y,BoxInfo.center.z) * WorldToMetersScale);
	Box.Extent.Width = BoxInfo.extent.x * WorldToMetersScale;
	Box.Extent.Height = BoxInfo.extent.y * WorldToMetersScale;
	Box.Extent.Depth = BoxInfo.extent.z * WorldToMetersScale;

	return true;
}

bool PXR_AnchorProvider::GetSpatialSceneBoundingBox2DLegacy(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& Box2D)
{
	if(!UUIDToAnchorHandleMap.Contains(UUID))
	{
		return false;
	}
	
	const FPICOSpatialHandle AnchorHandle=UUIDToAnchorHandleMap[UUID];
	
	PxrAnchorPlaneBoundaryInfo BoundaryInfo;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPlaneBoundaryInfo(AnchorHandle, &BoundaryInfo));
	if (PXR_FAILURE(Result))
	{
		return false;
	}

	const float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	Box2D.Center = ToFVector(BoundaryInfo.center) * WorldToMetersScale;
	Box2D.Extent.Height = BoundaryInfo.extent.height * WorldToMetersScale;
	Box2D.Extent.Width = BoundaryInfo.extent.width * WorldToMetersScale;

	return true;
}

bool PXR_AnchorProvider::GetSpatialSceneBoundingPolygonLegacy(const FPICOSpatialUUID& UUID, TArray<FVector>& Polygon)
{
	if(!UUIDToAnchorHandleMap.Contains(UUID))
	{
		return false;
	}

	const FPICOSpatialHandle AnchorHandle=UUIDToAnchorHandleMap[UUID];

	PxrAnchorPlanePolygonInfo PolygonInfo;
	PolygonInfo.polygonSizeCapacityInput = 0;
	PolygonInfo.polygonSizeCountOutput = 0;
	PolygonInfo.polygonVertices = nullptr;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPlanePolygonInfo(AnchorHandle.GetValue(), &PolygonInfo));

	PXR_LOGV(PxrMR, "GetAnchorPlanePolygonInfo Call PxrAPI Result[%d], Handle[%llu], VerticesNum[%u]", (int32)Result, (uint64)AnchorHandle.GetValue(), (uint32)PolygonInfo.polygonSizeCountOutput);
	if (PXR_SUCCESS(Result) && PolygonInfo.polygonSizeCountOutput > 0)
	{
		PolygonInfo.polygonSizeCapacityInput = PolygonInfo.polygonSizeCountOutput;
		PxrVector3f* Data = new PxrVector3f[PolygonInfo.polygonSizeCountOutput];
		PolygonInfo.polygonVertices = Data;
		EPICOResult DoubleResult = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorPlanePolygonInfo(AnchorHandle.GetValue(), &PolygonInfo));

		PXR_LOGV(PxrMR, "GetAnchorPlanePolygonInfo Double Call PxrAPI Result[%d]", (int32)Result);
		if (PXR_SUCCESS(DoubleResult))
		{
			float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();

			Polygon.SetNum(PolygonInfo.polygonSizeCountOutput);
			for (uint32 Index = 0; Index < PolygonInfo.polygonSizeCountOutput; ++Index)
			{
				Polygon[Index] = ToFVector(Data[Index]) * WorldToMetersScale;
			}
			delete[] Data;
			return true;
		}
		delete[] Data;
	}

	return false;
}


UPICOAnchorComponent* PXR_AnchorProvider::GetAnchorComponent(AActor* BoundActor)
{
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		return nullptr;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	return AnchorComponent;
}

bool PXR_AnchorProvider::GetAnchorEntityUUID(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID,EPICOResult& OutResult)
{
	if (!IsAnchorValid(BoundActor))
	{
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);
	FPICOSpatialHandle AnchorHandle = AnchorComponent->GetAnchorHandle();
	PxrUUid PxrAnchorUUID;
	int Result = FPICOXRHMDModule::GetPluginWrapper().GetAnchorUuid(AnchorHandle.GetValue(), &PxrAnchorUUID);

	PXR_LOGV(PxrMR, "GetAnchorEntityUUID Call PxrAPI Result[%d], Handle[%llu]", Result, AnchorHandle.GetValue());
	OutAnchorUUID = PxrAnchorUUID.value;
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	PXR_LOGV(PxrMR, "GetAnchorEntityUUID AnchorUUID[%s]", *OutAnchorUUID.ToString());
	return PXRP_SUCCESS(Result);
}

bool PXR_AnchorProvider::GetAnchorPose(UPICOAnchorComponent* AnchorComponent, FTransform& OutAnchorPose,EPICOResult& OutResult)
{
	if (!IsAnchorValid(AnchorComponent))
	{
		return false;
	}

	FPICOSpatialHandle AnchorHandle = AnchorComponent->GetAnchorHandle();

	PxrSpaceLocation cPxrSpaceLocation = {};
	PxrAnchorLocateInfo cPxrAnchorLocateInfoBD = {};
	cPxrAnchorLocateInfoBD.type = PxrStructureType::PXR_TYPE_ANCHOR_LOCATE_INFO;
	cPxrAnchorLocateInfoBD.anchor = AnchorHandle.GetValue();

	int Result = FPICOXRHMDModule::GetPluginWrapper().LocateAnchor(&cPxrAnchorLocateInfoBD, &cPxrSpaceLocation);
	bool bResult=PXRP_SUCCESS(Result);
	OutResult =FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(Result));

	if (bResult)
	{
		bResult = (cPxrSpaceLocation.locationFlags & PXR_SPACE_LOCATION_ORIENTATION_VALID_BIT)
			&& (cPxrSpaceLocation.locationFlags & PXR_SPACE_LOCATION_POSITION_VALID_BIT)
			&& (cPxrSpaceLocation.locationFlags & PXR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT)
			&& (cPxrSpaceLocation.locationFlags & PXR_SPACE_LOCATION_POSITION_TRACKED_BIT);

		PXR_LOGV(PxrMR, "UpdateAnchor Call PxrAPI Result[%d]", bResult);
		float WorldToMetersScale = AnchorComponent->GetWorld()->GetWorldSettings()->WorldToMeters;

		FPose UnrealPose;
		ConvertPose_Private(cPxrSpaceLocation.pose, UnrealPose, FPICOProviderManager::GetBaseOrientation(), FPICOProviderManager::GetBaseOffsetInMeters(), WorldToMetersScale);

		FTransform TrackingToWorld = FPICOProviderManager::GetTrackingToWorldTransform();

		OutAnchorPose.SetLocation(TrackingToWorld.TransformPosition(UnrealPose.Position));
		OutAnchorPose.SetRotation(TrackingToWorld.TransformRotation(UnrealPose.Orientation));

		PXR_LOGV(PxrMR, "LocateAnchor OutAnchorPose:%s", *OutAnchorPose.ToString());
	}

	return bResult;
}

bool PXR_AnchorProvider::UpdateAnchor(UPICOAnchorComponent* AnchorComponent,EPICOResult& OutResult)
{
	FTransform AnchorTransform;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		if (!GetAnchorPoseLegacy(AnchorComponent, AnchorTransform))
		{
			return false;
		}
	}
	else
	{
		if (!GetAnchorPose(AnchorComponent, AnchorTransform,OutResult))
		{
			return false;
		}
	}

	PXR_LOGV(PxrMR, "UpdateAnchor Pose[%s]", *AnchorTransform.ToString());

	AActor* BoundActor = AnchorComponent->GetOwner();
	BoundActor->SetActorLocationAndRotation(AnchorTransform.GetLocation(), AnchorTransform.GetRotation());
	return true;
}

bool PXR_AnchorProvider::CreateAnchorEntityLegacy(AActor* BoundActor, const FTransform& AnchorEntityTransform, float Timeout, const FPICOCreateAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	PXR_LOGV(PxrMR, "CreateAnchorEntity");
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		PXR_LOGV(PxrMR, "CreateAnchorEntity Actor is Invalid[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		OutResult = EPICOResult::PXR_Error_ValidationFailure;
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		PXR_LOGV(PxrMR, "CreateAnchorEntity AnchorComponent and AnchorHandle is Already Valid[%llu]", (uint64)AnchorComponent->GetAnchorHandle().GetValue());
		OutResult = EPICOResult::PXR_Error_ValidationFailure;
		return false;
	}
	if (!AnchorComponent)
	{
		AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->AddComponentByClass(UPICOAnchorComponent::StaticClass(), false, FTransform::Identity, false));
	}

	float WorldToMetersScale = BoundActor->GetWorld()->GetWorldSettings()->WorldToMeters;
	FTransform TrackingToWorld = FPICOProviderManager::GetTrackingToWorldTransform();
	const FQuat TrackingOrientation = TrackingToWorld.Inverse().TransformRotation(AnchorEntityTransform.Rotator().Quaternion());
	const FVector TrackingPosition = TrackingToWorld.Inverse().TransformPosition(AnchorEntityTransform.GetLocation());
	FPose UnrealPose = FPose(TrackingOrientation, TrackingPosition);

	PxrPosef AnchorPose;
	ConvertPose_Private(UnrealPose, AnchorPose, FPICOProviderManager::GetBaseOrientation(), FPICOProviderManager::GetBaseOffsetInMeters(), WorldToMetersScale);

	PxrAnchorEntityCreateInfo EntityInfo;
	FPICOXRHMDModule::GetPluginWrapper().GetTrackingOrigin(&EntityInfo.pxrTrackingOrigin);
	EntityInfo.timeMs = static_cast<double>(Timeout);
	EntityInfo.pose = AnchorPose;

	PXR_LOGV(PxrMR, "CreateAnchorEntity Params: TrackingOrigin[%d], Timeout[%f], Pose[%s]", (int32)EntityInfo.pxrTrackingOrigin, Timeout, *AnchorEntityTransform.ToString());

	uint64_t AsyncTaskId = 0;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().CreateAnchorEntity(&EntityInfo, &AsyncTaskId));

	PXR_LOGV(PxrMR, "CreateAnchorEntity Call PxrAPI Result[%d], TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FAnchorCreateInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	TaskInfo.AnchorComponent = AnchorComponent;
	CreateAnchorBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

void PXR_AnchorProvider::HandleCreateAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, const FPICOSpatialHandle& AnchorHandle, const FPICOSpatialUUID& AnchorUUID)
{
	PXR_LOGV(PxrMR, "HandleCreateAnchorEntityEvent Params: AsyncTaskId[%llu], Result[%d], AnchorHandle[%llu], AnchorUUID[%s]", (uint64)AsyncTaskId, (int32)Result, (uint64)AnchorHandle.GetValue(), *AnchorUUID.ToString());

	FAnchorCreateInfo* TaskInfo = CreateAnchorBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGV(PxrMR, "HandleCreateAnchorEntityEvent No Task");
		return;
	}

	if (PXR_FAILURE(Result) || !IsValid(TaskInfo->AnchorComponent))
	{
		PXR_LOGV(PxrMR, "HandleCreateAnchorEntityEvent Failed, Maybe AnchorComponent is Invalid");
		TaskInfo->Delegate.ExecuteIfBound(Result, TaskInfo->AnchorComponent);
		PersistAnchorsBindings.Remove(AsyncTaskId);
		return;
	}

	TaskInfo->AnchorComponent->SetAnchorHandle(AnchorHandle);
	TaskInfo->Delegate.ExecuteIfBound(Result, TaskInfo->AnchorComponent);
	CreateAnchorBindings.Remove(AsyncTaskId);
}

void PXR_AnchorProvider::HandlePersistAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation)
{
	PXR_LOGV(PxrMR, "HandlePersistAnchorEntityEvent Params: AsyncTaskId[%llu], Result[%d], Location[%d]", (uint64)AsyncTaskId, (int32)Result, (int32)PersistLocation);

	FAnchorPersistInfo* TaskInfo = PersistAnchorsBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGV(PxrMR, "HandlePersistAnchorEntityEvent No Task");
		return;
	}

	if (PXR_FAILURE(Result))
	{
		TaskInfo->Delegate.ExecuteIfBound(Result, nullptr);
		PersistAnchorsBindings.Remove(AsyncTaskId);
		return;
	}

	TaskInfo->Delegate.ExecuteIfBound(Result, TaskInfo->AnchorComponent);
	PersistAnchorsBindings.Remove(AsyncTaskId);
}

void PXR_AnchorProvider::HandleUnpersistAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation)
{
	PXR_LOGV(PxrMR, "HandleUnpersistAnchorEntityEvent Params: AsyncTaskId[%llu], Result[%d], Location[%d]", (uint64)AsyncTaskId, (int32)Result, (int32)PersistLocation);

	FAnchorUnpersistInfo* TaskInfo = UnpersistAnchorsBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGV(PxrMR, "HandleUnpersistAnchorEntityEvent No Task");
		return;
	}

	TaskInfo->Delegate.ExecuteIfBound(Result, TaskInfo->AnchorComponent);
	UnpersistAnchorsBindings.Remove(AsyncTaskId);
}

void PXR_AnchorProvider::HandleClearAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOPersistLocation PersistLocation)
{
	PXR_LOGV(PxrMR, "HandleClearAnchorEntityEvent Params: AsyncTaskId[%llu], Result[%d], Location[%d]", (uint64)AsyncTaskId, (int32)Result, (int32)PersistLocation);

	FAnchorClearInfo* TaskInfo = ClearAnchorsBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGV(PxrMR, "HandleClearAnchorEntityEvent No Task");
		return;
	}

	TaskInfo->Delegate.ExecuteIfBound(Result);
	ClearAnchorsBindings.Remove(AsyncTaskId);
}

void PXR_AnchorProvider::HandleLoadAnchorEntityEvent(uint64_t AsyncTaskId, EPICOResult Result, uint32_t AnchorCount, EPICOPersistLocation PersistLocation)
{
	PXR_LOGV(PxrMR, "HandleLoadAnchorEntityEvent Params: AsyncTaskId[%llu], Result[%d], AnchorCount[%u], Location[%d]", (uint64)AsyncTaskId, (int32)Result, (uint32)AnchorCount, (int32)PersistLocation);

	FAnchorLoadInfo* TaskInfo = LoadAnchorsBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGV(PxrMR, "HandleLoadAnchorEntityEvent No Task");
		return;
	}

	TArray<FAnchorLoadResult> LoadedAnchors;

	if (PXR_FAILURE(Result))
	{
		TaskInfo->Delegate.ExecuteIfBound(Result, LoadedAnchors);
		LoadAnchorsBindings.Remove(AsyncTaskId);
		return;
	}

	if (AnchorCount == 0)
	{
		PXR_LOGW(PxrMR, "HandleLoadAnchorEntityEvent AnchorCount == 0");
		TaskInfo->Delegate.ExecuteIfBound(Result, LoadedAnchors);
		LoadAnchorsBindings.Remove(AsyncTaskId);
		return;
	}

	TArray<PxrAnchorEntityLoadResult> PxrLoadedAnchors;
	PxrLoadedAnchors.SetNum(AnchorCount);

	PxrAnchorEntityLoadResults PxrLoadResults;
	PxrLoadResults.resultCapacityInput = AnchorCount;
	PxrLoadResults.resultCountOutput = AnchorCount;
	PxrLoadResults.results = PxrLoadedAnchors.GetData();

	EPICOResult LoadResult = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().GetAnchorEntityLoadResults(AsyncTaskId, &PxrLoadResults));
	if (PXR_FAILURE(LoadResult))
	{
		PXR_LOGE(PxrMR, "HandleLoadAnchorEntityEvent LoadResults Failed: LoadResult[%d]", (int32)LoadResult);
		TaskInfo->Delegate.ExecuteIfBound(LoadResult, LoadedAnchors);
		LoadAnchorsBindings.Remove(AsyncTaskId);
		return;
	}

	LoadedAnchors.SetNum(AnchorCount);
	for (uint32_t Index = 0; Index < AnchorCount; ++Index)
	{
		LoadedAnchors[Index].PersistLocation = EPICOPersistLocation::PersistLocation_Local;
		LoadedAnchors[Index].AnchorHandle = PxrLoadedAnchors[Index].anchor;
		LoadedAnchors[Index].AnchorUUID=PxrLoadedAnchors[Index].uuid.value;
	}
	TaskInfo->Delegate.ExecuteIfBound(LoadResult, LoadedAnchors);
	LoadAnchorsBindings.Remove(AsyncTaskId);
}

void PXR_AnchorProvider::HandleStartSpatialSceneCaptureEvent(uint64_t AsyncTaskId, EPICOResult Result, EPICOSpatialSceneCaptureStatus SpatialSceneCaptureStatus)
{
	PXR_LOGV(PxrMR, "HandleStartSpatialSceneCaptureEvent Params: AsyncTaskId[%llu], Result[%d], bUpdated[%d]", (uint64)AsyncTaskId, (int32)Result, (int32)SpatialSceneCaptureStatus);

	FStartSpatialSceneCaptureInfo* TaskInfo = StartSpatialSceneCaptureBindings.Find(AsyncTaskId);
	if (!TaskInfo)
	{
		PXR_LOGW(PxrMR, "HandleStartSpatialSceneCaptureEvent No Task");
		return;
	}

	TaskInfo->Delegate.ExecuteIfBound(Result, SpatialSceneCaptureStatus);
	StartSpatialSceneCaptureBindings.Remove(AsyncTaskId);
}

bool PXR_AnchorProvider::DestroyAnchorEntityLegacy(AActor* BoundActor, const FPICODestroyAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGW(PxrMR, "DestroyAnchorEntity Actor is Invalid");
		OutResult = EPICOResult::PXR_Error_ValidationFailure;
		return false;
	}
	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);

	PxrAnchorEntityDestroyInfo EntityInfo;
	EntityInfo.anchor = AnchorComponent->GetAnchorHandle().GetValue();

	PXR_LOGV(PxrMR, "DestroyAnchorEntity Params: Handle[%llu]", (uint64)AnchorComponent->GetAnchorHandle().GetValue());

	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().DestroyAnchorEntity(&EntityInfo));

	PXR_LOGV(PxrMR, "DestroyAnchorEntity Call Complete: Result[%d]", (int32)Result);

	if (PXR_SUCCESS(Result))
	{
		AnchorComponent->SetAnchorHandle(0);
	}
	else
	{
		OutResult = Result;
	}

	Delegate.ExecuteIfBound(Result);
	return PXR_SUCCESS(Result);
}

bool PXR_AnchorProvider::PersistAnchorEntityLegacy(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOPersistAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	TArray<uint64_t> AnchorHandles;
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGW(PxrMR, "PersistAnchorEntity Actor is Invalid: Actor[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		OutResult = EPICOResult::PXR_Error_ValidationFailure;
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);
	AnchorHandles.Add(AnchorComponent->GetAnchorHandle().GetValue());

	uint64_t AsyncTaskId = 0;
	PxrAnchorEntityPersistInfo PersistInfo;
	PersistInfo.anchorList.anchors = AnchorHandles.GetData();
	PersistInfo.anchorList.count = AnchorHandles.Num();
	PersistInfo.location =PxrPersistLocation::PXR_PERSIST_LOCATION_LOCAL;
	
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().PersistAnchorEntity(&PersistInfo, &AsyncTaskId));

	PXR_LOGV(PxrMR, "PersistAnchorEntity Call PxrAPI Result[%d]: TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FAnchorPersistInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	TaskInfo.AnchorComponent = AnchorComponent;
	PersistAnchorsBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

bool PXR_AnchorProvider::UnpersistAnchorEntityLegacy(AActor* BoundActor, EPICOPersistLocation PersistLocation, const FPICOUnpersistAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	TArray<uint64_t> AnchorHandles;
	if (!IsAnchorValid(BoundActor))
	{
		PXR_LOGW(PxrMR, "UnpersistAnchorEntity Actor is Invalid: Actor[%s]", IsValid(BoundActor) ? *BoundActor->GetName() : TEXT("nullptr"));
		OutResult = EPICOResult::PXR_Error_ValidationFailure;
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = GetAnchorComponent(BoundActor);
	AnchorHandles.Add(AnchorComponent->GetAnchorHandle().GetValue());

	uint64_t AsyncTaskId = 0;
	PxrAnchorEntityUnpersistInfo UnpersistInfo;
	UnpersistInfo.anchorList.anchors = AnchorHandles.GetData();
	UnpersistInfo.anchorList.count = AnchorHandles.Num();
	UnpersistInfo.location = PxrPersistLocation::PXR_PERSIST_LOCATION_LOCAL;
	
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().UnpersistAnchorEntity(&UnpersistInfo, &AsyncTaskId));

	PXR_LOGV(PxrMR, "UnpersistAnchorEntity Call PxrAPI Result[%d]: TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FAnchorUnpersistInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	TaskInfo.AnchorComponent = AnchorComponent;
	UnpersistAnchorsBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

bool PXR_AnchorProvider::ClearAnchorEntityLegacy(EPICOPersistLocation PersistLocation, const FPICOClearAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	uint64_t AsyncTaskId = 0;
	PxrAnchorEntityClearInfo ClearInfo;
	ClearInfo.location = (PxrPersistLocation)PersistLocation;

	PXR_LOGV(PxrMR, "ClearAnchorEntity Params: Location[%d]", (int32)PersistLocation);

	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().ClearPersistedAnchorEntity(&ClearInfo, &AsyncTaskId));

	PXR_LOGV(PxrMR, "ClearAnchorEntity Call PxrAPI Result[%d]: TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FAnchorClearInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	ClearAnchorsBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

bool PXR_AnchorProvider::LoadAnchorEntityLegacy(EPICOLoadFilterType LoadFilterType, const FPICOAnchorLoadInfo& LoadInfo, const FPICOSceneLoadInfo& SceneLoadInfo, const FPICOLoadAnchorEntityDelegate& Delegate, EPICOResult& OutResult)
{
	uint64_t AsyncTaskId = 0;
	PxrAnchorEntityLoadInfo PxrLoadInfo;
	//Todo:Diff with 3.0
	PxrLoadInfo.maxResult = 1024;
	//PxrLoadInfo.timeout = static_cast<double>(LoadInfo.Timeout);
	PxrLoadInfo.location = PxrPersistLocation::PXR_PERSIST_LOCATION_LOCAL;

	PxrAnchorEntityLoadUuidFilter IncludeUUIDFilter, ExcludeUUIDFilter;
	IncludeUUIDFilter.type = ExcludeUUIDFilter.type = PXR_TYPE_ANCHOR_ENTITY_LOAD_UUID_FILTER;
	IncludeUUIDFilter.uuidList = ExcludeUUIDFilter.uuidList = nullptr;

	PxrAnchorEntityLoadSpatialSceneFilter IncludeSpatialSceneFilter, ExcludeSpatialSceneFilter;
	IncludeSpatialSceneFilter.type = ExcludeSpatialSceneFilter.type = PXR_TYPE_ANCHOR_ENTITY_LOAD_SPATIAL_SCENE_FILTER;

	if (LoadFilterType == EPICOLoadFilterType::LoadFilterType_UUID)
	{
		PXR_LOGV(PxrMR, "LoadAnchorEntity UUID Include Num[%d]", LoadInfo.UUIDFilter.Num());

		IncludeUUIDFilter.uuidCount = LoadInfo.UUIDFilter.Num();
		if (IncludeUUIDFilter.uuidCount > 0)
		{
			IncludeUUIDFilter.uuidList = new PxrUUid[IncludeUUIDFilter.uuidCount];
			for (uint32_t Index = 0; Index < IncludeUUIDFilter.uuidCount; ++Index)
			{
				PXR_LOGV(PxrMR, "LoadAnchorEntity UUID Include[%d/%d][%s]", Index, LoadInfo.UUIDFilter.Num(), *LoadInfo.UUIDFilter[Index].ToString());

				FMemory::Memcpy(IncludeUUIDFilter.uuidList[Index].value, LoadInfo.UUIDFilter[Index].UUIDArray);
			}
		}
		PxrLoadInfo.include = (const PxrAnchorEntityLoadFilterBaseHeader*)(&IncludeUUIDFilter);
	}
	else if (LoadFilterType == EPICOLoadFilterType::LoadFilterType_SpatialSceneData)
	{
		uint64_t IncludeSpatialSceneDataTypeFilter = 0;
		TArray<EPICOSpatialSceneDataTypeFlags> SceneDataTypeFlags;

		if (SceneLoadInfo.SemanticFilter.Num()==0)
		{
			IncludeSpatialSceneDataTypeFilter |= PXR_SPATIAL_SCENE_DATA_TYPE_UNKNOWN_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_FLOOR_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_CEILING_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_WALL_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_DOOR_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_WINDOW_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_OPENING_BIT_
			| PXR_SPATIAL_SCENE_DATA_TYPE_OBJECT_BIT_;
		}
		
		for (int32 Index = 0; Index < SceneLoadInfo.SemanticFilter.Num(); ++Index)
		{
			uint64_t BitValue = FPICOProviderManager::ConvertSemanticToSceneFlag(SceneLoadInfo.SemanticFilter[Index]);
			IncludeSpatialSceneDataTypeFilter |= BitValue;
		}
		IncludeSpatialSceneFilter.typeFlags = (PxrSpatialSceneDataTypeFlags)IncludeSpatialSceneDataTypeFilter;
		PxrLoadInfo.include = (const PxrAnchorEntityLoadFilterBaseHeader*)(&IncludeSpatialSceneFilter);
	}
	else
	{
		PxrLoadInfo.include = nullptr;
	}

	PXR_LOGV(PxrMR, "LoadAnchorEntity Params: %s", *LoadInfo.ToString());

	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().LoadAnchorEntity(&PxrLoadInfo, &AsyncTaskId));

	if (IncludeUUIDFilter.uuidList)
	{
		delete[] IncludeUUIDFilter.uuidList;
	}
	if (ExcludeUUIDFilter.uuidList)
	{
		delete[] ExcludeUUIDFilter.uuidList;
	}

	PXR_LOGV(PxrMR, "LoadAnchorEntity Call PxrAPI Result[%d]: TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FAnchorLoadInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	LoadAnchorsBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

bool PXR_AnchorProvider::StartSpatialSceneCapture(const FPICOStartSpatialSceneCaptureDelegate& Delegate, EPICOResult& OutResult)
{
	PXR_LOGI(PxrMR, "StartSpatialSceneCapture");

	uint64_t AsyncTaskId = 0;
	EPICOResult Result = FPICOProviderManager::CastToPICOResult(FPICOXRHMDModule::GetPluginWrapper().StartSpatialSceneCapture(&AsyncTaskId));

	PXR_LOGI(PxrMR, "StartSpatialSceneCapture Call PxrAPI Result[%d]: TaskID[%llu]", (int32)Result, (uint64)AsyncTaskId);
	if (PXR_FAILURE(Result))
	{
		OutResult = Result;
		return false;
	}

	FStartSpatialSceneCaptureInfo TaskInfo;
	TaskInfo.AsyncTaskId = AsyncTaskId;
	TaskInfo.Delegate = Delegate;
	StartSpatialSceneCaptureBindings.Add(AsyncTaskId, TaskInfo);
	return true;
}

bool PXR_MeshProvider::CreateProvider(const FPICOSenseDataProviderCreateInfoBase& createInfo)
{
	check(createInfo.Type == EPICOProviderType::Pico_Provider_Mesh);

	Type = EPICOProviderType::Pico_Provider_Mesh;

	const FPICOSenseDataProviderCreateInfoMesh& MeshCreateInfo = static_cast<const FPICOSenseDataProviderCreateInfoMesh&>(createInfo);
	PxrSpatialMeshProviderCreateInfo cSpatialMeshProviderCreateInfoBD = {};
	cSpatialMeshProviderCreateInfoBD.type = PxrStructureType::PXR_TYPE_SPATIAL_MESH_PROVIDER_CREATE_INFO;

	cSpatialMeshProviderCreateInfoBD.lod = static_cast<PxrSpatialMeshLod>(MeshCreateInfo.Lod);
	CurrentLod = MeshCreateInfo.Lod;
	for (auto Config : MeshCreateInfo.ConfigArray)
	{
		cSpatialMeshProviderCreateInfoBD.configFlags |= static_cast<uint64_t>(Config);
	}

	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().CreateSenseDataProvider(reinterpret_cast<PxrSenseDataProviderCreateInfoBaseHeader*>(&cSpatialMeshProviderCreateInfoBD),&ProviderHandle.Value));

	if (!bResult)
	{
		ProviderHandle.Reset();
	}
	
	PXR_LOGI(PxrMR, "MeshProvider CreateProvider:%d ProviderHandle:%llu，MeshConfigFlgs:%llu", bResult, ProviderHandle.GetValue(), cSpatialMeshProviderCreateInfoBD.configFlags);
	bResult = bResult ? ProviderHandle.IsValid() : false;

	return bResult;
}

bool PXR_MeshProvider::StopProvider()
{
	ClearMeshProviderBuffer();
	return IPXR_BaseProvider::StopProvider();
}

bool PXR_MeshProvider::GetSpatialTriangleMeshInfos(const FPICOSpatialHandle& FutureHandle,const FTransform& TrackingToWorld,
                                                   const FQuat& BaseOrientation,
                                                   const FVector& BaseOffsetInMeters,
                                                   float WorldToMetersScale,
                                                   TArray<FPICOSpatialMeshInfo>& MeshInfos, EPICOResult& OutResult)
{
	FScopeLock Lock(&CriticalSection);
	FPICOSenseDataQueryCompletion SenseDataQueryCompletion;
	if (!QuerySenseDataComplete(FutureHandle, SenseDataQueryCompletion,OutResult))
	{
		return false;
	}
	
	if (PXR_FAILURE(SenseDataQueryCompletion.FutureResult))
	{
		OutResult = SenseDataQueryCompletion.FutureResult;
		return false;
	}

	if (!SenseDataQueryCompletion.SnapShotHandle.IsValid())
	{
		OutResult =EPICOResult::PXR_Error_HandleInvalid;
		return false;
	}
	
	FPICOQueriedSenseData QueriedSenseData;
	if (!GetQueriedSenseData(SenseDataQueryCompletion.SnapShotHandle, QueriedSenseData,OutResult))
	{
		return false;
	}
	TSet<FPICOSpatialUUID> CurrentUUIDSet;
	TSet<FPICOSpatialUUID> RemovedUUIDSet;

	MeshInfos.Empty();
	CurrentUUIDSet.Empty();
	PXR_LOGV(PxrMR, "QueriedSenseData.QueriedSpatialEntityInfos Count:%d", QueriedSenseData.QueriedSpatialEntityInfos.Num());
	PXR_LOGV(PxrMR, "CachedUUIDToMRMeshInfoMap.Num:%d", CachedUUIDToMRMeshInfoMap.Num());

	int32 CountAfterDiff = 0;
	for (auto EntityInfo : QueriedSenseData.QueriedSpatialEntityInfos)
	{
		if (!EntityInfo.spatialEntity)
		{
			continue;
		}

		CurrentUUIDSet.Add(EntityInfo.uuid.value);

		CountAfterDiff++;
		TArray<uint16> Triangles;
		FPICOSpatialMeshInfo cFPICOMRMeshInfo;
		cFPICOMRMeshInfo.UUID = EntityInfo.uuid.value;
		cFPICOMRMeshInfo.UpdateTime = static_cast<int64>(EntityInfo.time);

		if (IsContainsInLastUpdate(EntityInfo.uuid.value))
		{
			if (GetLastUpdateTimeByUUID(EntityInfo.uuid.value) >= EntityInfo.time)
			{
				CachedUUIDToMRMeshInfoMap[EntityInfo.uuid.value].State = EPICOSpatialMeshState::Stable;
				PXR_LOGV(PxrMR, "cComponentInfoGetInfo UUID:%llu Not Update", EntityInfo.uuid.value[0]);;
				continue;
			}
			cFPICOMRMeshInfo.State = EPICOSpatialMeshState::Updated;
		}
		else
		{
			cFPICOMRMeshInfo.State = EPICOSpatialMeshState::Added;
		}

		if (!GetSpatialEntityLocation(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity,
		                              cFPICOMRMeshInfo.MeshPose,TrackingToWorld,
		                              BaseOrientation,
		                              BaseOffsetInMeters,
		                              WorldToMetersScale))
		{
			PXR_LOGE(PxrMR, "spatialEntity:%llu,GetSpatialEntityLocation failed!!!", EntityInfo.spatialEntity);
			continue;
		}

		const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
		if (Settings->bSemanticsAlignWithTriangle || Settings->bSemanticsAlignWithVertex)
		{
			if (!GetSpatialEntitySemantic(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, cFPICOMRMeshInfo.Semantics))
			{
				PXR_LOGE(PxrMR, "spatialEntity:%llu,GetSpatialEntitySemantic failed!!!", EntityInfo.spatialEntity);
				continue;
			}
		}

		if (!GetSpatialEntityTriangleMesh(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, cFPICOMRMeshInfo.Vertices, Triangles))
		{
			PXR_LOGE(PxrMR, "spatialEntity:%llu,GetSpatialEntityTriangleMesh failed!!!", EntityInfo.spatialEntity);
			continue;
		}

		if (!GetSpatialEntityBoundary3D(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, cFPICOMRMeshInfo.BoundingBox))
		{
			PXR_LOGE(PxrMR, "spatialEntity:%llu,GetSpatialEntityBoundary3D failed!!!", EntityInfo.spatialEntity);
			continue;
		}

		cFPICOMRMeshInfo.Indices.SetNum(Triangles.Num());
		cFPICOMRMeshInfo.Indices = static_cast<TArray<int32>>(Triangles);

		CachedUUIDToMRMeshInfoMap.Emplace(EntityInfo.uuid.value, MoveTemp(cFPICOMRMeshInfo));
	}
	PXR_LOGV(PxrMR, "QueriedSenseData.QueriedSpatialEntityInfos CountAfterDiff:%d", CountAfterDiff);

	for (auto MRMeshInfo : CachedUUIDToMRMeshInfoMap)
	{
		PXR_LOGV(PxrMR, "MRMeshInfo State:%d", MRMeshInfo.Value.State);

		if (!CurrentUUIDSet.Contains(MRMeshInfo.Key))
		{
			CachedUUIDToMRMeshInfoMap[MRMeshInfo.Key].State = EPICOSpatialMeshState::Removed;
			RemovedUUIDSet.Add(MRMeshInfo.Key);
		}
	}

	CachedUUIDToMRMeshInfoMap.GenerateValueArray(MeshInfos);
	PXR_LOGV(PxrMR, "New CachedUUIDToMRMeshInfoMap.Num:%d", CachedUUIDToMRMeshInfoMap.Num());

	for (auto RemovedUUID : RemovedUUIDSet)
	{
		PXR_LOGV(PxrMR, "RemovedUUID:%s", *RemovedUUID.ToString());
		CachedUUIDToMRMeshInfoMap.Remove(RemovedUUID);
	}
	PXR_LOGV(PxrMR, "After Delete CachedUUIDToMRMeshInfoMap.Num:%d", CachedUUIDToMRMeshInfoMap.Num());

	if(!DestroySenseDataQueryResult(SenseDataQueryCompletion.SnapShotHandle,OutResult))
	{
		PXR_LOGV(PxrMR, "DestroySenseDataQueryResult Failed OutResult:%d", OutResult);
		return false;
	}
	
	return true;
}

EPICOSpatialMeshLod PXR_MeshProvider::GetCurrentSpatialMeshLod()
{
	return CurrentLod;
}

void PXR_MeshProvider::ClearMeshProviderBuffer()
{
	FScopeLock Lock(&CriticalSection);
	CachedUUIDToMRMeshInfoMap.Empty();
}

bool PXR_MeshProvider::IsContainsInLastUpdate(const FPICOSpatialUUID& UUID)
{
	return CachedUUIDToMRMeshInfoMap.Contains(UUID);
}

uint64 PXR_MeshProvider::GetLastUpdateTimeByUUID(const FPICOSpatialUUID& UUID)
{
	if (IsContainsInLastUpdate(UUID))
	{
		return CachedUUIDToMRMeshInfoMap[UUID].UpdateTime;
	}

	return 0;
}


bool PXR_MeshProvider::RequestSpatialTriangleMesh(const FPICOPollFutureDelegate& Delegate,EPICOResult& OutResult)
{
	FPICOSpatialHandle Handle;
	PxrSenseDataQueryInfo cSenseDataQueryInfoBD = {};
	cSenseDataQueryInfoBD.type = PxrStructureType::PXR_TYPE_SENSE_DATA_QUERY_INFO;
	cSenseDataQueryInfoBD.filter = nullptr;
	int pxrResult=FPICOXRHMDModule::GetPluginWrapper().QuerySenseDataAsync(ProviderHandle.Value,&cSenseDataQueryInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(pxrResult);
	OutResult=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(pxrResult));
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

PXR_MeshProvider::PXR_MeshProvider():CurrentLod(EPICOSpatialMeshLod::High)
{
}

PXR_SceneProvider::PXR_SceneProvider()
{
}

bool PXR_SceneProvider::RequestSpatialSceneInfos(const FPICOSceneLoadInfo& LoadInfo, const FPICOPollFutureDelegate& Delegate,EPICOResult& Result)
{
	FPICOSpatialHandle Handle;
	PxrSenseDataQueryInfo cSenseDataQueryInfoBD = {};
	cSenseDataQueryInfoBD.type = PxrStructureType::PXR_TYPE_SENSE_DATA_QUERY_INFO;

	PxrSpatialEntitySemanticFilter cPxrSpatialEntitySemanticFilter = {};
	cPxrSpatialEntitySemanticFilter.type = PXR_TYPE_SPATIAL_ENTITY_SEMANTIC_FILTER;
	cPxrSpatialEntitySemanticFilter.semanticCount = LoadInfo.SemanticFilter.Num();

	PXR_LOGV(PxrMR, "SemanticLabels Num:%d", cPxrSpatialEntitySemanticFilter.semanticCount);

	TArray<PxrSemanticLabel> SemanticLabels;

	for (auto Semantic : LoadInfo.SemanticFilter)
	{
		SemanticLabels.Add(static_cast<PxrSemanticLabel>(Semantic));
		PXR_LOGV(PxrMR, "SemanticLabels:%d", Semantic);
	}

	SemanticLabels.SetNum(LoadInfo.SemanticFilter.Num());
	cPxrSpatialEntitySemanticFilter.semantics = SemanticLabels.GetData();

	cSenseDataQueryInfoBD.filter = reinterpret_cast<PxrSenseDataQueryFilterBaseHeader*>(&cPxrSpatialEntitySemanticFilter);
	int pxrResult=FPICOXRHMDModule::GetPluginWrapper().QuerySenseDataAsync(ProviderHandle.Value,&cSenseDataQueryInfoBD,&Handle.Value);
	bool bResult = PXRP_SUCCESS(pxrResult);

	Result=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(pxrResult));
	
	if (bResult)
	{
		bResult = AddPollFutureRequirement(Handle, Delegate);
	}

	return bResult;
}

bool PXR_SceneProvider::GetSpatialSceneInfos(const FPICOSpatialHandle& FutureHandle, TArray<FPICOMRSceneInfo>& SceneInfos, EPICOResult& OutResult)
{
	FPICOSenseDataQueryCompletion SenseDataQueryCompletion;
	if (!QuerySenseDataComplete(FutureHandle, SenseDataQueryCompletion,OutResult))
	{
		return false;
	}
	
	if (PXR_FAILURE(SenseDataQueryCompletion.FutureResult))
	{
		OutResult = SenseDataQueryCompletion.FutureResult;
		return false;
	}

	if (!SenseDataQueryCompletion.SnapShotHandle.IsValid())
	{
		OutResult =EPICOResult::PXR_Error_HandleInvalid;
		return false;
	}
	
	FPICOQueriedSenseData QueriedSenseData;
	if (!GetQueriedSenseData(SenseDataQueryCompletion.SnapShotHandle, QueriedSenseData,OutResult))
	{
		return false;
	}
	
	ClearComponentBuffer();
	PXR_LOGV(PxrMR, "PXR_SceneProvider::GetQueriedSenseData:%d", QueriedSenseData.QueriedSpatialEntityInfos.Num());

	for (auto EntityInfo : QueriedSenseData.QueriedSpatialEntityInfos)
	{
		TArray<EPICOSpatialEntityComponentType> ComponentTypes;
		FPICOMRSceneInfo cFPICOMRSceneInfo = {};
		cFPICOMRSceneInfo.UUID = EntityInfo.uuid.value;

		if (!EnumerateSpatialEntityComponentTypes(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, ComponentTypes))
		{
			PXR_LOGE(PxrMR, "EnumerateSpatialEntityComponentTypes:%llu Failed!!!", EntityInfo.spatialEntity);
			continue;
		}

		for (EPICOSpatialEntityComponentType ComponentType : ComponentTypes)
		{
			PXR_LOGV(PxrMR, "ComponentType:%d", ComponentType);
			switch (ComponentType)
			{
			case EPICOSpatialEntityComponentType::Location:
				{
					FTransform cFTransform;
					FQuat BaseOrientation = FPICOProviderManager::GetBaseOrientation();
					FVector BaseOffsetInMeters = FPICOProviderManager::GetBaseOffsetInMeters();
					float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
					FTransform TrackingToWorld = FPICOProviderManager::GetTrackingToWorldTransform();

					if (GetSpatialEntityLocation(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, cFTransform, TrackingToWorld,BaseOrientation, BaseOffsetInMeters, WorldToMetersScale))
					{
						cFPICOMRSceneInfo.ScenePose = cFTransform;
						PXR_LOGV(PxrMR, "cFPICOMRSceneInfo.ScenePose:%s", *cFPICOMRSceneInfo.ScenePose.ToString());
					}
				}
				break;
			case EPICOSpatialEntityComponentType::Semantic:
				{
					TArray<EPICOSemanticLabel> Semantics;
					if (GetSpatialEntitySemantic(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, Semantics))
					{
						if (Semantics.Num())
						{
							cFPICOMRSceneInfo.Semantic = Semantics[0];
						}
					}
				}
				break;
			case EPICOSpatialEntityComponentType::Boundary_2D:
				{
					TSharedRef<FPICOBoundingBox2D> Box = MakeShared<FPICOBoundingBox2D>();
					if (GetSpatialEntityBoundary2D(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, Box.Get()))
					{
						cFPICOMRSceneInfo.SceneType = EPICOSceneType::BoundingBox2D;
						EntityToBoundingBox2DMap.Add(EntityInfo.uuid.value, Box);
					}
				}
				break;
			case EPICOSpatialEntityComponentType::Polygon:
				{
					TSharedRef<TArray<FVector>> Polygon = MakeShareable(new TArray<FVector>());
					if (GetSpatialEntityPolygon(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, Polygon.Get()))
					{
						cFPICOMRSceneInfo.SceneType = EPICOSceneType::BoundingPolygon;
						EntityToPolygonMap.Add(EntityInfo.uuid.value, Polygon);
					}
				}
				break;
			case EPICOSpatialEntityComponentType::Boundary_3D:
				{
					TSharedRef<FPICOBoundingBox3D> Box = MakeShared<FPICOBoundingBox3D>();
					if (GetSpatialEntityBoundary3D(SenseDataQueryCompletion.SnapShotHandle, EntityInfo.spatialEntity, Box.Get()))
					{
						cFPICOMRSceneInfo.SceneType = EPICOSceneType::BoundingBox3D;
						EntityToBoundingBox3DMap.Add(EntityInfo.uuid.value, Box);
					}
				}
				break;
			default: ;
			}
		}

		SceneInfos.Add(cFPICOMRSceneInfo);
	}
	
	if(!DestroySenseDataQueryResult(SenseDataQueryCompletion.SnapShotHandle,OutResult))
	{
		PXR_LOGV(PxrMR, "DestroySenseDataQueryResult Failed OutResult:%d", OutResult);
		return false;
	}

	return true;
}

bool PXR_SceneProvider::StartSceneCaptureAsync(const FPICOPollFutureDelegate& Delegate,EPICOResult& Result)
{
	FPICOSpatialHandle FutureHandle;
	int pxrResult=FPICOXRHMDModule::GetPluginWrapper().StartSceneCaptureAsync(ProviderHandle,&FutureHandle.Value);
	bool bResult = PXRP_SUCCESS(pxrResult);

	Result=FPICOProviderManager::CastToPICOResult(static_cast<PxrResult>(pxrResult));
	
	PXR_LOGV(PxrMR, "StartSceneCaptureAsync:%d", bResult);

	if (bResult)
	{
		bResult = AddPollFutureRequirement(FutureHandle, Delegate);
	}

	return bResult;
}

void PXR_SceneProvider::ClearComponentBuffer()
{
	EntityToBoundingBox3DMap.Empty();
	EntityToBoundingBox2DMap.Empty();
	EntityToPolygonMap.Empty();
}

bool PXR_SceneProvider::GetSpatialSceneBoundingBox3D(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& Box3D)
{
	if (EntityToBoundingBox3DMap.Contains(UUID))
	{
		Box3D = EntityToBoundingBox3DMap.Find(UUID)->Get();
		return true;
	}
	return false;
}

bool PXR_SceneProvider::GetSpatialSceneBoundingBox2D(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& Box2D)
{
	if (EntityToBoundingBox2DMap.Contains(UUID))
	{
		Box2D = EntityToBoundingBox2DMap.Find(UUID)->Get();
		return true;
	}
	return false;
}

bool PXR_SceneProvider::GetSpatialSceneBoundingPolygon(const FPICOSpatialUUID& UUID, TArray<FVector>& Polygon)
{
	if (EntityToPolygonMap.Contains(UUID))
	{
		Polygon = EntityToPolygonMap.Find(UUID)->Get();
		return true;
	}
	return false;
}

bool PXR_SceneProvider::StartSceneCaptureComplete(const FPICOSpatialHandle& FutureHandle, FPICOSceneCaptureStartCompletion& completion)
{
	PxrSceneCaptureStartCompletion cPxrSceneCaptureStartCompletionBD = {};
	cPxrSceneCaptureStartCompletionBD.type = PxrStructureType::PXR_TYPE_SCENE_CAPTURE_START_COMPLETION;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartSceneCaptureComplete(ProviderHandle,FutureHandle.GetValue(), &cPxrSceneCaptureStartCompletionBD));

	PXR_LOGV(PxrMR, "StartSceneCaptureComplete:%d", bResult);

	completion.FutureResult = FPICOProviderManager::CastToPICOResult(cPxrSceneCaptureStartCompletionBD.futureResult);
	return bResult && completion.FutureResult == EPICOResult::PXR_Success;
}

bool PXR_SceneProvider::CreateProvider(const FPICOSenseDataProviderCreateInfoBase& createInfo)
{
	check(createInfo.Type == EPICOProviderType::Pico_Provider_Scene_Capture);

	Type = EPICOProviderType::Pico_Provider_Scene_Capture;

	const FPICOSenseDataProviderCreateInfoSceneCapture& SceneCreateInfo = static_cast<const FPICOSenseDataProviderCreateInfoSceneCapture&>(createInfo);
	PxrSceneCaptureProviderCreateInfo cSceneCaptureProviderCreateInfoBD = {};
	cSceneCaptureProviderCreateInfoBD.type = PxrStructureType::PXR_TYPE_SCENE_CAPTURE_PROVIDER_CREATE_INFO;

	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().CreateSenseDataProvider(reinterpret_cast<PxrSenseDataProviderCreateInfoBaseHeader*>(&cSceneCaptureProviderCreateInfoBD),&ProviderHandle.Value));

	if (!bResult)
	{
		ProviderHandle.Reset();
	}
	
	PXR_LOGI(PxrMR, "SceneProvider CreateProvider:%d ProviderHandle:%llu", bResult, ProviderHandle.GetValue());

	bResult = bResult ? ProviderHandle.IsValid() : false;

	return bResult;
}
