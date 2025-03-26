// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_MRFunctionLibrary.h"
#include "PXR_ProviderManager.h"
#include "MRMeshComponent.h"


bool UPICOXRMRFunctionLibrary::PXR_GetAnchorEntityUuid(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID,EPICOResult& OutResult)
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		return  PXR_AnchorProvider::GetInstance()->GetAnchorEntityUUIDLegacy(BoundActor, OutAnchorUUID);
	}
	return PXR_AnchorProvider::GetInstance()->GetAnchorEntityUUID(BoundActor, OutAnchorUUID,OutResult);
}

bool UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingBox2D(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& Box2D)
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		return  PXR_AnchorProvider::GetInstance()->GetSpatialSceneBoundingBox2DLegacy(UUID,Box2D);
	}
	
	return PXR_SceneProvider::GetInstance()->GetSpatialSceneBoundingBox2D(UUID, Box2D);
}

bool UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingPolygon(const FPICOSpatialUUID& UUID, TArray<FVector>& OutPolygonVertices)
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		return  PXR_AnchorProvider::GetInstance()->GetSpatialSceneBoundingPolygonLegacy(UUID,OutPolygonVertices);
	}
	
	return PXR_SceneProvider::GetInstance()->GetSpatialSceneBoundingPolygon(UUID, OutPolygonVertices);
}

bool UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingBox3D(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& Box3D)
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		return  PXR_AnchorProvider::GetInstance()->GetSpatialSceneBoundingBox3DLegacy(UUID,Box3D);
	}
	
	return PXR_SceneProvider::GetInstance()->GetSpatialSceneBoundingBox3D(UUID, Box3D);
}

bool UPICOXRMRFunctionLibrary::PXR_GetAnchorPoseByActor(AActor* BoundActor, FTransform& OutTransform,EPICOResult& OutResult)
{
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		if (FPICOProviderManager::ShouldUseLegacyMR())
		{
			return PXR_AnchorProvider::GetInstance()->GetAnchorPoseLegacy(AnchorComponent, OutTransform);
		}
	
		return PXR_AnchorProvider::GetInstance()->GetAnchorPose(AnchorComponent, OutTransform,OutResult);
	}

	return false;
}

bool UPICOXRMRFunctionLibrary::PXR_GetAnchorPoseByComponent(UPICOAnchorComponent* AnchorComponent, FTransform& OutTransform,EPICOResult& OutResult)
{
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		if (FPICOProviderManager::ShouldUseLegacyMR())
		{
			return PXR_AnchorProvider::GetInstance()->GetAnchorPoseLegacy(AnchorComponent, OutTransform);
		}
	
		return PXR_AnchorProvider::GetInstance()->GetAnchorPose(AnchorComponent, OutTransform,OutResult);
	}

	return false;
}

AActor* UPICOXRMRFunctionLibrary::PXR_SpawnActorFromLoadResult(UObject* WorldContext, const FAnchorLoadResult& LoadResult, UClass* ActorClass)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull);
	if (!IsValid(World))
	{
		PXR_LOGV(PxrMR, "UPICOXRMRFunctionLibrary::PXR_SpawnActorFromLoadResult is Invalid");
		return nullptr;
	}

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.ObjectFlags |= RF_Transient;

	AActor* AnchorActor = World->SpawnActor(ActorClass, nullptr, nullptr, SpawnInfo);
	if (!IsValid(AnchorActor))
	{
		PXR_LOGV(PxrMR, "UPICOXRMRFunctionLibrary::PXR_SpawnActorFromLoadResult Spawn Actor Failed");
		return nullptr;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(AnchorActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		PXR_LOGV(PxrMR, "UPICOXRMRFunctionLibrary::PXR_SpawnActorFromLoadResult Anchor is Already Valid, Return Old Anchor Actor");
		return AnchorActor;
	}
	if (AnchorComponent == nullptr)
	{
		AnchorComponent = Cast<UPICOAnchorComponent>(AnchorActor->AddComponentByClass(UPICOAnchorComponent::StaticClass(), false, FTransform::Identity, false));
	}

	AnchorComponent->SetAnchorHandle(LoadResult.AnchorHandle);
	return AnchorActor;
}

bool UPICOXRMRFunctionLibrary::PXR_IsAnchorValidForActor(AActor* BoundActor)
{
	if (!IsValid(BoundActor))
	{
		return false;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		return true;
	}

	return false;
}

bool UPICOXRMRFunctionLibrary::PXR_IsAnchorValidForComponent(UPICOAnchorComponent* AnchorComponent)
{
	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		return true;
	}

	return false;
}

FString UPICOXRMRFunctionLibrary::PXR_FromAnchorToString(const FPICOSpatialHandle& Anchor)
{
	return Anchor.ToString();
}

FString UPICOXRMRFunctionLibrary::PXR_FromUUIDToString(const FPICOSpatialUUID& AnchorUUID)
{
	return AnchorUUID.ToString();
}

FPICOSpatialUUID UPICOXRMRFunctionLibrary::PXR_FromStringToUUID(const FString& AnchorUUIDString)
{
	FPICOSpatialUUID OutAnchorUUID;
	TArray<FString> UUIDArray;
	AnchorUUIDString.ParseIntoArray(UUIDArray, TEXT("-"));
	if (UUIDArray.Num() == PXR_UUID_SIZE)
	{
		for (int32 Index = 0; Index < PXR_UUID_SIZE; ++Index)
		{
			OutAnchorUUID.UUIDArray[Index] = (uint64_t)FCString::Strtoui64(*UUIDArray[Index], nullptr, 16);
		}
	}
	return OutAnchorUUID;
}

bool UPICOXRMRFunctionLibrary::PXR_CloseSpatialMeshScanning()
{
	return FPICOProviderManager::PXR_StopSenseDataProvider(EPICOProviderType::Pico_Provider_Mesh);
}

bool UPICOXRMRFunctionLibrary::PXR_ChangeSpatialMeshLodSetting(EPICOSpatialMeshLod SpatialMeshLod)
{
	bool bResult=false;
	
	if (PXR_MeshProvider::GetInstance()->GetCurrentSpatialMeshLod()!=SpatialMeshLod)
	{
		bResult=FPICOProviderManager::PXR_StopSenseDataProvider(EPICOProviderType::Pico_Provider_Mesh);

		if (bResult)
		{
			bResult=FPICOProviderManager::PXR_DestroySenseDataProvider(EPICOProviderType::Pico_Provider_Mesh);
		
			if (bResult)
			{
				FPICOSenseDataProviderCreateInfoMesh cFPICOSenseDataProviderCreateInfoMesh = {};
				cFPICOSenseDataProviderCreateInfoMesh.Lod = SpatialMeshLod;
				const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();

				if(Settings)
				{
					if (Settings->bSemanticsAlignWithTriangle)
					{
						cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic);
					}
					else if (Settings->bSemanticsAlignWithVertex)
					{
						cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic);
						cFPICOSenseDataProviderCreateInfoMesh.ConfigArray.Add(EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic_Align_With_Vertex);
					}
				}
				
				bResult=FPICOProviderManager::PXR_CreateSenseDataProvider(cFPICOSenseDataProviderCreateInfoMesh);
			}
		}
	}
	
	return bResult;
}

EPICOSpatialMeshLod UPICOXRMRFunctionLibrary::PXR_GetSpatialMeshLodSetting()
{
	return PXR_MeshProvider::GetInstance()->GetCurrentSpatialMeshLod();
}

EPICOMRState UPICOXRMRFunctionLibrary::PXR_GetSpatialMeshScanningState()
{
	return PXR_MeshProvider::GetInstance()->GetSenseDataProviderState();
}

EPICOMRState UPICOXRMRFunctionLibrary::PXR_GetSpatialAnchorServiceState()
{
	return PXR_AnchorProvider::GetInstance()->GetSenseDataProviderState();
}

EPICOMRState UPICOXRMRFunctionLibrary::PXR_GetSceneCaptureServiceState()
{
	return PXR_SceneProvider::GetInstance()->GetSenseDataProviderState();
}

void UPICOXRMRFunctionLibrary::PXR_ResetSpatialMeshInfosState()
{
	PXR_MeshProvider::GetInstance()->ClearMeshProviderBuffer();
}

bool UPICOXRMRFunctionLibrary::PXR_CloseSpatialAnchorService()
{
	return FPICOProviderManager::PXR_StopSenseDataProvider(EPICOProviderType::Pico_Provider_Anchor);
}

bool UPICOXRMRFunctionLibrary::PXR_CloseSceneCaptureService()
{
	return FPICOProviderManager::PXR_StopSenseDataProvider(EPICOProviderType::Pico_Provider_Scene_Capture);
}


bool UPICOXRMRFunctionLibrary::PXR_DestroyAnchorByComponent(UPICOAnchorComponent* AnchorComponent,EPICOResult& OutResult)
{
	bool bResult=false;

	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		if (FPICOProviderManager::ShouldUseLegacyMR())
		{
			bResult=PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandleLegacy(AnchorComponent->GetAnchorHandle());
		}
		else
		{
			bResult=PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandle(AnchorComponent->GetAnchorHandle(),OutResult);
		}
		AnchorComponent->ResetAnchorHandle();
	}

	return bResult;
}


bool UPICOXRMRFunctionLibrary::PXR_DestroyAnchorByActor(AActor* BoundActor,EPICOResult& OutResult)
{
	bool bResult=false;
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		return bResult;
	}

	UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));

	if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
	{
		if (FPICOProviderManager::ShouldUseLegacyMR())
		{
			bResult=PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandleLegacy(AnchorComponent->GetAnchorHandle());
		}
		else
		{
			bResult=PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandle(AnchorComponent->GetAnchorHandle(),OutResult);
		}
		AnchorComponent->ResetAnchorHandle();
	}

	return bResult;
}

bool UPICOXRMRFunctionLibrary::PXR_CreateSceneBoundingPolygon(AActor* BoundActor,bool bNeverCreateCollision,bool bFlipPolygon,bool UseWireframe, const FTransform& Transform, const TArray<FVector>& BoundaryVertices,UMaterialInterface* DefaultMeshMaterial)
{
	auto MRMeshComponent = NewObject<UMRMeshComponent>(BoundActor);

	if (!IsValid(BoundActor)||!BoundaryVertices.Num()||!DefaultMeshMaterial)
	{
		return false;
	}
	
	MRMeshComponent->SetUsingAbsoluteLocation(true);
	MRMeshComponent->SetUsingAbsoluteRotation(true);
	MRMeshComponent->SetUsingAbsoluteScale(true);
		
	MRMeshComponent->SetEnableMeshOcclusion(false);
	MRMeshComponent->SetUseWireframe(UseWireframe);
	MRMeshComponent->SetNeverCreateCollisionMesh(bNeverCreateCollision);
	MRMeshComponent->SetEnableNavMesh(false);
		
	if (DefaultMeshMaterial)
	{
		MRMeshComponent->SetMaterial(0, DefaultMeshMaterial);
		MRMeshComponent->SetWireframeMaterial(DefaultMeshMaterial);
	}

	MRMeshComponent->SetupAttachment(BoundActor->GetRootComponent());
	MRMeshComponent->RegisterComponent();
	
	auto Vertices = BoundaryVertices;
	const auto NumPolygons = Vertices.Num();
	TArray<MRMESH_INDEX_TYPE> Indices;
	Indices.Reset(3 * NumPolygons);
	if (bFlipPolygon)
	{
		for (auto Index = 0; Index < NumPolygons; ++Index)
		{
			Indices.Add(0);
			Indices.Add((Index + 2) % NumPolygons);
			Indices.Add((Index + 1) % NumPolygons);
		}
	}
	else
	{
		for (auto Index = 0; Index < NumPolygons; ++Index)
		{
			Indices.Add(0);
			Indices.Add((Index + 1) % NumPolygons);
			Indices.Add((Index + 2) % NumPolygons);
		}
	}

			
	MRMeshComponent->UpdateMesh(Transform.GetLocation(), Transform.GetRotation(), Transform.GetScale3D(), Vertices, Indices);
	
	return true;
}
