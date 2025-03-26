//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.


#include "PicoSpatialAudioSceneGeometryComponent.h"

#include "PxrAudioSpatializerContextSingleton.h"

// Sets default values for this component's properties
UPicoSpatialAudioSceneGeometryComponent::UPicoSpatialAudioSceneGeometryComponent()
	: InternalGeomId(-1),
	  InternalBakedGeomId(-1),
	  bSubmitted(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UPicoSpatialAudioSceneGeometryComponent::~UPicoSpatialAudioSceneGeometryComponent()
{
}

void UPicoSpatialAudioSceneGeometryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Pxr_Audio::Spatializer::FContextSingleton::IsInitialized())
		return;

	if (!bSubmitted)
	{
		const int32 SubmittedTriangleNum = SubmitToContext();
		if (SubmittedTriangleNum > 0)
		{
			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Submit mesh of %d triangles: %s"), SubmittedTriangleNum,
			       *GetOwner()->GetName());
		}

		const int32 SubmittedBakedTriangleNum = SubmitBakedMeshToContext();
		if (SubmittedBakedTriangleNum > 0)
		{
			UE_LOG(LogPicoSpatialAudio, Display, TEXT("Submit baked mesh of %d triangles: %s"),
			       SubmittedBakedTriangleNum,
			       *GetOwner()->GetName());
		}

		PreviousTransformUnreal = GetOwner()->GetTransform();
		bSubmitted = true;
	}

	//	Update geometry transform
	// 3D transform
	const FTransform Transform = GetOwner()->GetTransform();
	if (!Transform.Equals(PreviousTransformUnreal))
	{
		Pxr_Audio::Spatializer::ConvertToPicoSpatialAudioCoordinates(Transform, MeshConfig.to_world_transform);
		PropertyMask |= PASP_MeshProperty_ToWorldTransform;
		PreviousTransformUnreal = Transform;
	}

	//	Update changed mesh config
	if (PropertyMask != PASP_MeshProperty_None)
	{
		if (InternalGeomId >= 0)
		{
			const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->SetMeshConfig(
				InternalGeomId, &MeshConfig, PropertyMask);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to set config for mesh #%d (%s), PropertyMask = %ud, error code is: %d"),
			        InternalGeomId, *GetOwner()->GetName(), PropertyMask, Result);
			Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		}
		if (InternalBakedGeomId >= 0)
		{
			const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->SetMeshConfig(
				InternalBakedGeomId, &MeshConfig, PropertyMask);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to set config for static mesh #%d (%s), PropertyMask = %ud, error code is: %d"),
			        InternalBakedGeomId, *GetOwner()->GetName(), PropertyMask, Result);
			Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		}

		PropertyMask = PASP_MeshProperty_None;
	}
}

void UPicoSpatialAudioSceneGeometryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (bSubmitted && Pxr_Audio::Spatializer::FContextSingleton::IsInitialized())
	{
		if (InternalGeomId != -1)
		{
			const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->RemoveMesh(InternalGeomId);
			UE_CLOG(Result == PASP_SUCCESS, LogPicoSpatialAudio, Display,
					TEXT("Removed mesh #%d"), InternalGeomId);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
					TEXT("Failed to remove mesh #%d, error code is: %d"), InternalGeomId, Result);
			Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		}
		if (InternalBakedGeomId != -1)
		{
			const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->RemoveMesh(
				InternalBakedGeomId);
			UE_CLOG(Result == PASP_SUCCESS, LogPicoSpatialAudio, Display,
					TEXT("Removed baked static mesh #%d"), InternalBakedGeomId);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
					TEXT("Failed to remove baked static mesh #%d, error code is: %d"), InternalBakedGeomId, Result);
			Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		}
		bSubmitted = false;
	}
}

int32 UPicoSpatialAudioSceneGeometryComponent::SubmitToContext()
{
	if (MaterialSettings == nullptr)
		return 0;

	//	1. Gather list of UStaticMesh that need to be combined;
	GatheredStaticMeshes.Reset(0);
	GatheredStaticMeshTransforms.Reset(0);
	GatherStaticMeshes(GatheredStaticMeshes, GatheredStaticMeshTransforms, true);

	//	2. Batch UStaticMesh into one vertices and indices buffer;
	//	2.1 count gathered vertices and indices
	BatchStaticMeshes(GatheredStaticMeshes, GatheredStaticMeshTransforms, GetOwner()->GetTransform(),
	                  BatchedMeshVerticesBuffer,
	                  BatchedMeshIndicesBuffer);

	//	3. Submit batched UStaticMeshes to engine
	if (BatchedMeshVerticesBuffer.Num() > 0 && BatchedMeshIndicesBuffer.Num() > 0)
	{
		MeshConfig.enabled = true;
		MeshConfig.material_type = static_cast<PxrAudioSpatializer_AcousticsMaterial>(MaterialSettings->MaterialPreset);
		MeshConfig.absorption[0] = MaterialSettings->AbsorptionBand0;
		MeshConfig.absorption[1] = MaterialSettings->AbsorptionBand1;
		MeshConfig.absorption[2] = MaterialSettings->AbsorptionBand2;
		MeshConfig.absorption[3] = MaterialSettings->AbsorptionBand3;
		MeshConfig.scattering = MaterialSettings->Scattering;
		MeshConfig.transmission = MaterialSettings->Transmission;
		Pxr_Audio::Spatializer::ConvertToPicoSpatialAudioCoordinates(GetOwner()->GetTransform(),
		                                                             MeshConfig.to_world_transform);
		const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->SubmitMeshWithConfig(
			BatchedMeshVerticesBuffer.GetData(), BatchedMeshVerticesBuffer.Num() / 3,
			BatchedMeshIndicesBuffer.GetData(), BatchedMeshIndicesBuffer.Num() / 3, &MeshConfig, &InternalGeomId);

		if (Result != PASP_SUCCESS)
		{
			UE_LOG(LogPicoSpatialAudio, Error, TEXT("Failed to Submit mesh for Actor: %s"), *GetOwner()->GetName());
		}

		Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		return BatchedMeshIndicesBuffer.Num() / 3;
	}
	else
	{
		return 0;
	}
}

int32 UPicoSpatialAudioSceneGeometryComponent::SubmitBakedMeshToContext()
{
	if (MaterialSettings == nullptr)
		return 0;

	//	3. Submit batched UStaticMeshes to engine
	if (BatchedBakedMeshVerticesBuffer.Num() > 0 && BatchedBakedMeshIndicesBuffer.Num() > 0)
	{
		MeshConfig.enabled = true;
		MeshConfig.material_type = static_cast<PxrAudioSpatializer_AcousticsMaterial>(MaterialSettings->MaterialPreset);
		MeshConfig.absorption[0] = MaterialSettings->AbsorptionBand0;
		MeshConfig.absorption[1] = MaterialSettings->AbsorptionBand1;
		MeshConfig.absorption[2] = MaterialSettings->AbsorptionBand2;
		MeshConfig.absorption[3] = MaterialSettings->AbsorptionBand3;
		MeshConfig.scattering = MaterialSettings->Scattering;
		MeshConfig.transmission = MaterialSettings->Transmission;
		Pxr_Audio::Spatializer::ConvertToPicoSpatialAudioCoordinates(GetOwner()->GetTransform(),
		                                                             MeshConfig.to_world_transform);
		const auto Result = Pxr_Audio::Spatializer::FContextSingleton::GetInstance()->SubmitMeshWithConfig(
			BatchedBakedMeshVerticesBuffer.GetData(), BatchedBakedMeshVerticesBuffer.Num() / 3,
			BatchedBakedMeshIndicesBuffer.GetData(), BatchedBakedMeshIndicesBuffer.Num() / 3, &MeshConfig, &InternalBakedGeomId);

		if (Result != PASP_SUCCESS)
		{
			UE_LOG(LogPicoSpatialAudio, Error, TEXT("Failed to submit baked mesh for Actor: %s"),
			       *GetOwner()->GetName());
		}

		Pxr_Audio::Spatializer::FListener::bNeedSceneCommit = true;
		return BatchedBakedMeshIndicesBuffer.Num() / 3;
	}
	else
	{
		return 0;
	}
}

void UPicoSpatialAudioSceneGeometryComponent::BakeMesh()
{
	//	1. Gather list of UStaticMesh that need to be combined;
	GatheredStaticMeshes.Reset(0);
	GatheredStaticMeshTransforms.Reset(0);
	GatherStaticMeshes(GatheredStaticMeshes, GatheredStaticMeshTransforms, false);

	//	2. Batch UStaticMesh into one vertices and indices buffer;
	//	2.1 count gathered vertices and indices
	BatchStaticMeshes(GatheredStaticMeshes, GatheredStaticMeshTransforms, GetOwner()->GetTransform(),
	                  BatchedBakedMeshVerticesBuffer,
	                  BatchedBakedMeshIndicesBuffer);

	UE_LOG(LogPicoSpatialAudio, Display, TEXT("Baked meshes of %d triangles for %s"),
	       BatchedBakedMeshIndicesBuffer.Num() / 3, *GetOwner()->GetName());

	if (BatchedBakedMeshVerticesBuffer.Num() != 0 && BatchedBakedMeshIndicesBuffer.Num() != 0)
	{
		GetWorld()->MarkPackageDirty();
		ULevel::LevelDirtiedEvent.Broadcast();
	}
}

void UPicoSpatialAudioSceneGeometryComponent::ClearBakedMesh()
{
	if (BatchedBakedMeshVerticesBuffer.Num() != 0 && BatchedBakedMeshIndicesBuffer.Num() != 0)
	{
		BatchedBakedMeshVerticesBuffer.Empty();
		BatchedBakedMeshIndicesBuffer.Empty();
		UE_LOG(LogPicoSpatialAudio, Display, TEXT("Cleared baked meshes in %s"), *GetOwner()->GetName());
		GetWorld()->MarkPackageDirty();
		ULevel::LevelDirtiedEvent.Broadcast();
	}
}

void UPicoSpatialAudioSceneGeometryComponent::GatherStaticMeshes(TArray<UStaticMesh*>& OutGatheredStaticMeshes,
                                                                 TArray<FTransform>& OutGatheredStaticMeshTransforms,
                                                                 bool InAllowCPUAccess)
{
	//	1. Gather meshes from this geometry and it's children components
	//	1.1 If this pico geometry is the root component of it's owner actor
	if (GetAttachmentRoot() == Cast<USceneComponent>(this))
	{
		//	We only traverse children components of this, since there's only one root component.
		GatherStaticMeshesInComponentHierarchy(this, OutGatheredStaticMeshes,
		                                       OutGatheredStaticMeshTransforms, IncludeChildrenComponent,
		                                       InAllowCPUAccess);
	}
	else //	1.2 If this pico geometry is not the root component of it's owner actor
	{
		//	We traverse the component hierarchy of our parent scene component
		GatherStaticMeshesInComponentHierarchy(GetAttachParent(), OutGatheredStaticMeshes,
		                                       OutGatheredStaticMeshTransforms, IncludeChildrenComponent,
		                                       InAllowCPUAccess);
	}

	//	2. Gather meshes from children actors of the owner actor of this component
	if (IncludeChildrenActor)
	{
		TArray<AActor*> ChildrenActors;
		GetOwner()->GetAttachedActors(ChildrenActors);
		for (const auto& Child : ChildrenActors)
		{
			const auto* ChildSceneGeometry = Child->GetComponentByClass(StaticClass());
			if (ChildSceneGeometry != nullptr)
				continue;

			GatherStaticMeshesInChildrenActors(Child, OutGatheredStaticMeshes, OutGatheredStaticMeshTransforms,
			                                   IncludeChildrenActor, IncludeChildrenComponent, InAllowCPUAccess);
		}
	}
}

void UPicoSpatialAudioSceneGeometryComponent::GatherStaticMeshesInChildrenActors(AActor* Actor,
	TArray<UStaticMesh*>& OutGatheredStaticMeshes,
	TArray<FTransform>&
	OutGatheredStaticMeshTransforms,
	bool InIncludeChildrenActor,
	bool InIncludeChildrenComponent,
	bool InAllowCPUAccess)
{
	//  1. Gather meshes in component hierarchy of current AActor
	GatherStaticMeshesInComponentHierarchy(Actor->GetRootComponent(), OutGatheredStaticMeshes,
	                                       OutGatheredStaticMeshTransforms, InIncludeChildrenComponent,
	                                       InAllowCPUAccess);

	//	2. Traverse into children AActors if InIncludeChildren == true
	if (InIncludeChildrenActor)
	{
		TArray<AActor*> ChildrenActors;
		Actor->GetAttachedActors(ChildrenActors);
		for (const auto& Child : ChildrenActors)
		{
			const auto* ChildSceneGeometry = Child->GetComponentByClass(StaticClass());
			if (ChildSceneGeometry != nullptr)
				continue;

			GatherStaticMeshesInChildrenActors(Child, OutGatheredStaticMeshes, OutGatheredStaticMeshTransforms,
			                                   InIncludeChildrenActor, InIncludeChildrenComponent, InAllowCPUAccess);
		}
	}
}

void UPicoSpatialAudioSceneGeometryComponent::GatherStaticMeshesInComponentHierarchy(USceneComponent* Component,
	TArray<UStaticMesh*>& OutGatheredStaticMeshes, TArray<FTransform>& OutGatheredStaticMeshTransforms,
	bool InIncludeChildrenComponent, bool InAllowCPUAccess)
{
	//  1. Get static mesh
	const UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(Component);
	UStaticMesh* StaticMesh = (StaticMeshComponent == nullptr) ? nullptr : StaticMeshComponent->GetStaticMesh();

	const UChildActorComponent* ChildActorComponent = Cast<UChildActorComponent>(Component);
	const AStaticMeshActor* StaticMeshActor = (ChildActorComponent == nullptr)
		                                          ? nullptr
		                                          : Cast<AStaticMeshActor>(ChildActorComponent->GetChildActor());
	const UStaticMeshComponent* StaticMeshComponentInChildActorComponent = (StaticMeshActor == nullptr)
		                                                                       ? nullptr
		                                                                       : StaticMeshActor->
		                                                                       GetStaticMeshComponent();
	UStaticMesh* StaticMeshInChildActorComponent = (StaticMeshComponentInChildActorComponent == nullptr)
		                                               ? nullptr
		                                               : StaticMeshComponentInChildActorComponent->
		                                               GetStaticMesh();

	//	2. Gather this static mesh if it exist and allows CPU access
	if (StaticMesh != nullptr && StaticMesh->bAllowCPUAccess == InAllowCPUAccess)
	{
		OutGatheredStaticMeshes.Push(StaticMesh);
		OutGatheredStaticMeshTransforms.Push(StaticMeshComponent->GetComponentTransform());
	}
	if (StaticMeshInChildActorComponent != nullptr &&
		StaticMeshInChildActorComponent->bAllowCPUAccess == InAllowCPUAccess)
	{
		OutGatheredStaticMeshes.Push(StaticMeshInChildActorComponent);
		OutGatheredStaticMeshTransforms.Push(StaticMeshComponentInChildActorComponent->GetComponentTransform());
	}

	//	3. Traverse into children USceneComponents if InIncludeChildren == true
	if (InIncludeChildrenComponent && StaticMeshActor == nullptr)
	{
		const auto& ChildrenComponents = Component->GetAttachChildren();
		for (auto Child : ChildrenComponents)
		{
			if (Child == nullptr)
				continue;
			//	If one of the the child's child is a pico geometry, it means that this child have another explicit geometry definition, thus we skip this
			const auto& GrandChildrenComponents = Child->GetAttachChildren();
			bool bFoundAnotherPicoGeometry = false;
			for (const auto& GrandChildrenComponent : GrandChildrenComponents)
			{
				if (Cast<UPicoSpatialAudioSceneGeometryComponent>(GrandChildrenComponent) != nullptr)
				{
					bFoundAnotherPicoGeometry = true;
				}
			}

			//	We only traverse to children without another explicit pico geometry definition
			if (!bFoundAnotherPicoGeometry)
			{
				GatherStaticMeshesInComponentHierarchy(Child, OutGatheredStaticMeshes, OutGatheredStaticMeshTransforms,
				                                       InIncludeChildrenComponent, InAllowCPUAccess);
			}
		}
	}
}

void UPicoSpatialAudioSceneGeometryComponent::BatchStaticMeshes(const TArray<UStaticMesh*>& InGatheredStaticMeshes,
                                                                const TArray<FTransform>&
                                                                InGatheredStaticMeshTransforms,
                                                                const FTransform& RootTransform,
                                                                TArray<float>& OutBatchedMeshVerticesBuffer,
                                                                TArray<int32>& OutBatchedMeshIndicesBuffer)
{
	size_t VerticesCount = 0;
	size_t IndicesCount = 0;
	for (const auto& StaticMesh : InGatheredStaticMeshes)
	{
#if ENGINE_MAJOR_VERSION < 5
		const auto& MeshLODResources = StaticMesh->RenderData->LODResources[0];
#else
		const auto& MeshLODResources = StaticMesh->GetRenderData()->LODResources[0];
#endif
		VerticesCount += MeshLODResources.VertexBuffers.PositionVertexBuffer.GetNumVertices();
		IndicesCount += MeshLODResources.IndexBuffer.GetNumIndices();
	}
	OutBatchedMeshVerticesBuffer.SetNum(VerticesCount * 3, true);
	OutBatchedMeshIndicesBuffer.SetNum(IndicesCount, true);

	float* OutVertex = OutBatchedMeshVerticesBuffer.GetData();
	TArray<uint32> TempIndicesBuffer;
	uint32 BatchedIndicesOffset = 0;
	uint32 BatchedIndicesStart = 0;
	for (size_t MeshIdx = 0; MeshIdx < InGatheredStaticMeshes.Num(); ++MeshIdx)
	{
		//	Take alias of specific input static mesh && it's actor's transform 
		const auto& StaticMesh = InGatheredStaticMeshes[MeshIdx];
		const auto& Transform = InGatheredStaticMeshTransforms[MeshIdx];
		const auto RelativeTransformToRoot = Transform.GetRelativeTransform(RootTransform);
#if ENGINE_MAJOR_VERSION < 5
		const auto& MeshLODResources = StaticMesh->RenderData->LODResources[0];
#else
		const auto& MeshLODResources = StaticMesh->GetRenderData()->LODResources[0];
#endif

		//	Write vertices data into OutBatchedMeshVerticesBuffer
		const auto& VertexBuffer = MeshLODResources.VertexBuffers.PositionVertexBuffer;
		const uint32 VertexCount = VertexBuffer.GetNumVertices();
		for (uint32 VertexIdx = 0; VertexIdx < VertexCount; ++VertexIdx)
		{
#if ENGINE_MAJOR_VERSION < 5
			Pxr_Audio::Spatializer::ConvertToPicoSpatialAudioCoordinates(
				RelativeTransformToRoot.TransformPosition(VertexBuffer.VertexPosition(VertexIdx)),
				OutVertex);
#else
			const auto& Temp = VertexBuffer.VertexPosition(VertexIdx);
			UE::Math::TVector<double> Position(Temp.X, Temp.Y, Temp.Z);
			Pxr_Audio::Spatializer::ConvertToPicoSpatialAudioCoordinates(
				RelativeTransformToRoot.TransformPosition(Position),
				OutVertex);
#endif
			
			OutVertex += 3;
		}

		//	Write indices data into OutBatchedMeshIndicesBuffer
		MeshLODResources.IndexBuffer.GetCopy(TempIndicesBuffer);
		for (size_t TempIndexIdx = 0; TempIndexIdx < TempIndicesBuffer.Num(); ++TempIndexIdx)
		{
			OutBatchedMeshIndicesBuffer[BatchedIndicesOffset + TempIndexIdx] = TempIndicesBuffer[TempIndexIdx] +
				BatchedIndicesStart;
		}

		BatchedIndicesOffset += TempIndicesBuffer.Num();
		BatchedIndicesStart += VertexCount;
	}
}
