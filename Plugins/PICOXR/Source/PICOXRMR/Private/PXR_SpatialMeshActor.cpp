// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_SpatialMeshActor.h"

#include "MRMeshComponent.h"
#include "PXR_EventManager.h"
#include "PXR_MRAsyncActions.h"
#include "PXR_ProviderManager.h"
#include "PXR_Log.h"
#include "Algo/Transform.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/Material.h"


#define UPDATE_FRAME_NUM_MAX 10


APXRSpatialMeshActor::APXRSpatialMeshActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	if (SpatialMeshMaterial==nullptr)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> DefaultMaterialFinder(TEXT("Material'/PICOXR/Materials/Mat_WireframeMaterial.Mat_WireframeMaterial'"));
		SpatialMeshMaterial= DefaultMaterialFinder.Object;
	}
	for (EPICOSemanticLabel Val : TEnumRange<EPICOSemanticLabel>())
	{
		SemanticToColors.Emplace(Val, FColor::MakeRandomSeededColor(static_cast<int32>(Val)));
	}
}

void APXRSpatialMeshActor::BeginPlay()
{
	Super::BeginPlay();

	USceneComponent* RootSceneComponent = NewObject<USceneComponent>(this, USceneComponent::StaticClass());
	RootSceneComponent->SetMobility(EComponentMobility::Static);
	RootSceneComponent->RegisterComponent();
	SetRootComponent(RootSceneComponent);
	SpatialMeshInstance = UMaterialInstanceDynamic::Create(SpatialMeshMaterial, nullptr);

	if (bDrawOnBeginPlay)
	{
		StartDraw();
	}
}

void APXRSpatialMeshActor::HandleMeshDataUpdatedEvent()
{
	PXR_LOGV(PxrMR, "Received MeshDataUpdatedEvent");

	UPICORequestSpatialMesh_AsyncAction* RequestSpatialMeshAction = UPICORequestSpatialMesh_AsyncAction::PXR_RequestSpatialMeshInfos_Async();
	RequestSpatialMeshAction->OnSuccess.AddDynamic(this, &APXRSpatialMeshActor::HandleRequestSpatialMeshContentsEvent);
	RequestSpatialMeshAction->Activate();
}

void APXRSpatialMeshActor::Tick(float DeltaTime)
{
	PXR_LOGV(PxrMR, "EntityToMeshMap Num:%d", EntityToMeshMap.Num());
	TArray<FPICOSpatialMeshInfo> MRMeshInfos;
	MeshInfoQueue.Dequeue(MRMeshInfos);
	PXR_LOGV(PxrMR, "APXRSpatialMeshActor::Tick MeshInfos.Num:%d", MRMeshInfos.Num());

	for (auto MeshInfo : MRMeshInfos)
	{
		PXR_LOGV(PxrMR, "MRMeshInfo UUID:%s State:%d", *MeshInfo.UUID.ToString(), MeshInfo.State);

		switch (MeshInfo.State)
		{
		case EPICOSpatialMeshState::Added:
			{
				UPICOSpatialMeshComponent* SpatialMesh = NewObject<UPICOSpatialMeshComponent>(this);
				SpatialMesh->RegisterComponent();
				SpatialMesh->SetMaterial(0,SpatialMeshInstance);
				SpatialMesh->SetUseWireframe(false);
				SpatialMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
				SpatialMesh->SetVisibility(bSpatialMeshVisible);
				SpatialMesh->SetCollisionEnabled(CollisionType);
				SpatialMesh->SetEnableMeshOcclusion(true);
				AddOwnedComponent(SpatialMesh);

				if (EntityToMeshMap.Contains(MeshInfo.UUID))
				{
					if (EntityToMeshMap[MeshInfo.UUID]!=nullptr)
					{
						EntityToMeshMap[MeshInfo.UUID]->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						EntityToMeshMap[MeshInfo.UUID]->DestroyComponent();
					}
					EntityToMeshMap.Remove(MeshInfo.UUID);
					PXR_LOGE(PxrMR, "When Added New Mesh,EntityToMeshMap Already Contains:%s",*MeshInfo.UUID.ToString());
				}

				EntityToMeshMap.Emplace(MeshInfo.UUID, SpatialMesh);
				PXR_LOGV(PxrMR, "EntityToMeshMap Emplace UUID:%s", *MeshInfo.UUID.ToString());

				UpdateMeshByMeshInfo(SpatialMesh, MeshInfo);
			}
			break;
		case EPICOSpatialMeshState::Stable:
			break;
		case EPICOSpatialMeshState::Updated:
			{
				if (EntityToMeshMap.Contains(MeshInfo.UUID))
				{
					if (EntityToMeshMap[MeshInfo.UUID] == nullptr)
					{
						PXR_LOGE(PxrMR, "SpatialMesh is nullptr");
						continue;
					}
					UpdateMeshByMeshInfo(EntityToMeshMap[MeshInfo.UUID], MeshInfo);
				}
			}
			break;
		case EPICOSpatialMeshState::Removed:
			{
				if (EntityToMeshMap.Contains(MeshInfo.UUID)
					&&EntityToMeshMap[MeshInfo.UUID]!=nullptr)
				{
					PXR_LOGV(PxrMR, "EntityToMeshMap Contains UUID:%s", *MeshInfo.UUID.ToString());

					EntityToMeshMap[MeshInfo.UUID]->SetCollisionEnabled(ECollisionEnabled::NoCollision);
					EntityToMeshMap[MeshInfo.UUID]->DestroyComponent();
					EntityToMeshMap.Remove(MeshInfo.UUID);
				}
				else
				{
					PXR_LOGV(PxrMR, "EntityToMeshMap Not Contains UUID:%s", *MeshInfo.UUID.ToString());
				}
			}
			break;
		default: ;
		}
	}
}

void APXRSpatialMeshActor::HandleRequestSpatialMeshContentsEvent(EPICOResult Result, const TArray<FPICOSpatialMeshInfo>& MeshInfos)
{
	PXR_LOGV(PxrMR, "Received RequestSpatialMeshContentsEvent MeshInfos:%d", MeshInfos.Num());
	TArray<FPICOSpatialMeshInfo> MRMeshInfos = {};
	int32 Counter = 0;
	bool bIsDone = false;
	const int32 MeshCountPerFrame= FMath::CeilToInt((static_cast<float>(MeshInfos.Num())) / UPDATE_FRAME_NUM_MAX);
	PXR_LOGV(PxrMR, "Received RequestSpatialMeshContentsEvent MeshCountPerFrame:%d", MeshCountPerFrame);

	for (auto MeshInfo : MeshInfos)
	{
		Counter++;
		if (Counter < MeshCountPerFrame)
		{
			bIsDone = false;
			MRMeshInfos.Add(MeshInfo);
		}
		else
		{
			bIsDone = true;
			MRMeshInfos.Add(MeshInfo);
			MeshInfoQueue.Enqueue(MRMeshInfos);
			PXR_LOGV(PxrMR, "Received RequestSpatialMeshContentsEvent QueueMRMeshInfos:%d", MRMeshInfos.Num());
			Counter = 0;
			MRMeshInfos.Empty();
		}
	}

	if (!bIsDone)
	{
		MeshInfoQueue.Enqueue(MRMeshInfos);
		PXR_LOGV(PxrMR, "Received RequestSpatialMeshContentsEvent QueueMRMeshInfos:%d", MRMeshInfos.Num());
		MRMeshInfos.Empty();
	}
}

void APXRSpatialMeshActor::EndPlay(EEndPlayReason::Type Reason)
{
	ClearMesh();
}

void APXRSpatialMeshActor::SetSemanticToColors(const TMap<EPICOSemanticLabel, FLinearColor>& In_SemanticToColors)
{
	for (EPICOSemanticLabel Val : TEnumRange<EPICOSemanticLabel>())
	{
		if (In_SemanticToColors.Contains(Val))
		{
			SemanticToColors.Emplace(Val, In_SemanticToColors[Val].ToFColorSRGB());
		}
	}
}

bool APXRSpatialMeshActor::StartDraw()
{
	SetActorTickEnabled(true);
	if (!UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshDataUpdatedDelegate.Contains(this, GET_FUNCTION_NAME_CHECKED(APXRSpatialMeshActor, HandleMeshDataUpdatedEvent)))
	{
		UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshDataUpdatedDelegate.AddDynamic(this, &APXRSpatialMeshActor::HandleMeshDataUpdatedEvent);
		return true;
	}
	
	return false;
}

bool APXRSpatialMeshActor::PauseDraw()
{
	SetActorTickEnabled(false);
	if (UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshDataUpdatedDelegate.Contains(this, GET_FUNCTION_NAME_CHECKED(APXRSpatialMeshActor, HandleMeshDataUpdatedEvent)))
	{
		UPICOXRHMDFunctionLibrary::PXR_GetEventManager()->MeshDataUpdatedDelegate.RemoveDynamic(this, &APXRSpatialMeshActor::HandleMeshDataUpdatedEvent);
		return true;
	}

	return false;
}

void APXRSpatialMeshActor::SetMeshVisibility(bool visibility)
{
	bSpatialMeshVisible = visibility;
	for (const auto Pair : EntityToMeshMap)
	{
		if (Pair.Value)
		{
			Pair.Value->SetVisibility(visibility);
		}
	}
}

bool APXRSpatialMeshActor::ClearMesh()
{
	for (const auto Pair : EntityToMeshMap)
	{
		if (Pair.Value)
		{
			Pair.Value->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			Pair.Value->Clear();
			Pair.Value->DestroyComponent();
		}
	}
	EntityToMeshMap.Empty();
	MeshInfoQueue.Empty();
	PXR_MeshProvider::GetInstance()->ClearMeshProviderBuffer();
	
	return true;
}

FColor APXRSpatialMeshActor::GetColorBySceneLabel(EPICOSemanticLabel SceneLabel)
{
	return SemanticToColors.Contains(SceneLabel)?SemanticToColors[SceneLabel]:FColor::MakeRandomSeededColor(static_cast<int32>(SceneLabel));
}

bool APXRSpatialMeshActor::UpdateMeshByMeshInfo(UPICOSpatialMeshComponent* SpatialMesh, const FPICOSpatialMeshInfo& MeshInfo)
{
	if (SpatialMesh)
	{
		TArray<MRMESH_INDEX_TYPE> TempIndices;
		TArray<FVector> TempVertices;
		TArray<FColor> VertexColors;
		const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
		TArray<FVector> EmptyNormals;
		TArray<FVector2D> EmptyUV;
		TArray<FProcMeshTangent> EmptyTangents;

		if (Settings->bSemanticsAlignWithTriangle)
		{
			for (int32 Index = 0; Index < MeshInfo.Semantics.Num(); ++Index)
			{
				EPICOSemanticLabel Semantic = MeshInfo.Semantics[Index];
				int32 IndicesIndex = Index * 3;

				if (MeshInfo.Indices.IsValidIndex(IndicesIndex + 0)
					&& MeshInfo.Indices.IsValidIndex(IndicesIndex + 1)
					&& MeshInfo.Indices.IsValidIndex(IndicesIndex + 2))
				{
					int32 VerticesIndex0 = MeshInfo.Indices[IndicesIndex + 0];
					int32 VerticesIndex1 = MeshInfo.Indices[IndicesIndex + 1];
					int32 VerticesIndex2 = MeshInfo.Indices[IndicesIndex + 2];

					int32 IndicesStart = TempVertices.Num();

					if (MeshInfo.Vertices.IsValidIndex(VerticesIndex0)
						&& MeshInfo.Vertices.IsValidIndex(VerticesIndex1)
						&& MeshInfo.Vertices.IsValidIndex(VerticesIndex2))
					{
						TempVertices.Add(MeshInfo.Vertices[VerticesIndex0]);
						TempVertices.Add(MeshInfo.Vertices[VerticesIndex1]);
						TempVertices.Add(MeshInfo.Vertices[VerticesIndex2]);

						TempIndices.Add(IndicesStart + 0);
						TempIndices.Add(IndicesStart + 1);
						TempIndices.Add(IndicesStart + 2);

						VertexColors.Add(GetColorBySceneLabel(Semantic));
						VertexColors.Add(GetColorBySceneLabel(Semantic));
						VertexColors.Add(GetColorBySceneLabel(Semantic));

						SpatialMesh->AddAnchorToSceneLabel(Index, Semantic);
					}
				}
			}
		}
		else
		{
			TempVertices = MeshInfo.Vertices;
			if (Settings->bSemanticsAlignWithVertex)
			{
				for (int32 Index = 0; Index < MeshInfo.Semantics.Num(); ++Index)
				{
					EPICOSemanticLabel Semantic = MeshInfo.Semantics[Index];
					VertexColors.Add(GetColorBySceneLabel(Semantic));
				}

				for (int32 Index = 0; Index < MeshInfo.Indices.Num() / 3; ++Index)
				{
					EPICOSemanticLabel SemanticLabel = MeshInfo.Semantics[MeshInfo.Indices[Index * 3]];
					SpatialMesh->AddAnchorToSceneLabel(Index, SemanticLabel);
				}
			}

			if (MeshInfo.Vertices.Num() && MeshInfo.Indices.Num())
			{
				TempIndices.Empty(MeshInfo.Indices.Num());
				Algo::Transform(MeshInfo.Indices, TempIndices, [](const auto& Indice) { return static_cast<MRMESH_INDEX_TYPE>(Indice); });
			}
		}

		if (TempVertices.Num() && TempIndices.Num())
		{
			SpatialMesh->UpdateMesh(MeshInfo.MeshPose.GetLocation(), MeshInfo.MeshPose.GetRotation(),
			                        FVector(1, 1, 1), TempVertices, TempIndices, TArray<FVector2D>(), TArray<FPackedNormal>(), VertexColors);
		}
	}


	return false;
}
