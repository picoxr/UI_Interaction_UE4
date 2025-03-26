// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_MRAsyncActions.h"
#include "PXR_ProviderManager.h"
#include "PXR_Log.h"
#include "Async/Async.h"

void UPICORequestSpatialMesh_AsyncAction::Activate()
{
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	const bool bStarted = PXR_MeshProvider::GetInstance()->RequestSpatialTriangleMesh
	(
		FPICOPollFutureDelegate::CreateUObject(this, &UPICORequestSpatialMesh_AsyncAction::HandleRequestSpatialMeshComplete),Result
	);

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}
void UPICORequestSceneCaptures_AsyncAction::Activate()
{
	bool bStarted;
	EPICOResult Result = EPICOResult::PXR_Error_RuntimeFailure;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->LoadAnchorEntityLegacy
		(
			EPICOLoadFilterType::LoadFilterType_SpatialSceneData,
		    FPICOAnchorLoadInfo(),
		    SceneLoadInfo,
		    FPICOLoadAnchorEntityDelegate::CreateUObject(this, &UPICORequestSceneCaptures_AsyncAction::HandleLoadSceneAnchorEntityComplete),
		    Result
		);
	}
	else
	{
		bStarted = PXR_SceneProvider::GetInstance()->RequestSpatialSceneInfos
		(
			SceneLoadInfo,
			FPICOPollFutureDelegate::CreateUObject(this, &UPICORequestSceneCaptures_AsyncAction::HandleRequestSpatialSceneComplete),
			Result
		);
	}
	
	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}
UPICORequestSceneCaptures_AsyncAction* UPICORequestSceneCaptures_AsyncAction::PXR_RequestSceneCaptures_Async(const FPICOSceneLoadInfo& InSceneLoadInfo)
{
	UPICORequestSceneCaptures_AsyncAction* Action = NewObject<UPICORequestSceneCaptures_AsyncAction>();
	Action->SceneLoadInfo = InSceneLoadInfo;
	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICORequestSceneCaptures_AsyncAction::HandleRequestSpatialSceneComplete(const FPICOSpatialHandle& FutureHandle)
{
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;
	TArray<FPICOMRSceneInfo> SceneLoadInfos;
	if (PXR_SceneProvider::GetInstance()->GetSpatialSceneInfos(FutureHandle, SceneLoadInfos, Result))
	{
		OnSuccess.Broadcast(Result, SceneLoadInfos);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}
	SetReadyToDestroy();
}

void UPICORequestSceneCaptures_AsyncAction::HandleLoadSceneAnchorEntityComplete(EPICOResult Result, const TArray<FAnchorLoadResult>& AnchorLoadResults)
{
	TArray<FPICOMRSceneInfo> MRSceneInfos;
	if (PXR_SUCCESS(Result)
		&& PXR_AnchorProvider::GetInstance()->GetSpatialAnchorSceneInfosLegacy(AnchorLoadResults, MRSceneInfos))
	{
		OnSuccess.Broadcast(Result, MRSceneInfos);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}

UPICORequestSpatialMesh_AsyncAction* UPICORequestSpatialMesh_AsyncAction::PXR_RequestSpatialMeshInfos_Async()
{
	UPICORequestSpatialMesh_AsyncAction* Action = NewObject<UPICORequestSpatialMesh_AsyncAction>();
	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICORequestSpatialMesh_AsyncAction::HandleRequestSpatialMeshComplete(const FPICOSpatialHandle& FutureHandle)
{
	FQuat BaseOrientation = FPICOProviderManager::GetBaseOrientation();
	FVector BaseOffsetInMeters = FPICOProviderManager::GetBaseOffsetInMeters();
	float WorldToMetersScale = FPICOProviderManager::GetWorldToMetersScale();
	FTransform TrackingToWorld=FPICOProviderManager::GetTrackingToWorldTransform();
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [FutureHandle,TrackingToWorld,BaseOrientation,BaseOffsetInMeters,WorldToMetersScale,this]()
	{
		TArray<FPICOSpatialMeshInfo> MeshInfos;
		TSet<FPICOSpatialUUID> NeedDeleteEntitySet;
		EPICOResult Result = EPICOResult::PXR_Error_Unknow;
		if (PXR_MeshProvider::GetInstance()->GetSpatialTriangleMeshInfos(FutureHandle, TrackingToWorld,BaseOrientation, BaseOffsetInMeters, WorldToMetersScale, MeshInfos, Result))
		{
			OnSuccess.Broadcast(Result, MeshInfos);
		}
		else
		{
			OnFailure.Broadcast(Result);
		}
		SetReadyToDestroy();
	});
}

void UPICOLaunchSpatialMeshScanning_AsyncAction::Activate()
{
	if(!PXR_MeshProvider::GetInstance()->IsHandleValid())
	{
		const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
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

			FPICOProviderManager::PXR_CreateSenseDataProvider(cFPICOSenseDataProviderCreateInfoMesh);
		}
	}
	
	EPICOResult Result=EPICOResult::PXR_Error_Unknow;
	const bool bStarted = FPICOProviderManager::PXR_StartSenseDataProviderAsync
	(
		FPICOPollFutureDelegate::CreateUObject(this,
		&UPICOLaunchSpatialMeshScanning_AsyncAction::HandleLaunchMeshScanningComplete)
		, EPICOProviderType::Pico_Provider_Mesh,Result
	);

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOLaunchSpatialMeshScanning_AsyncAction* UPICOLaunchSpatialMeshScanning_AsyncAction::PXR_LaunchSpatialMeshScanning_Async()
{
	UPICOLaunchSpatialMeshScanning_AsyncAction* Action = NewObject<UPICOLaunchSpatialMeshScanning_AsyncAction>();

	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICOLaunchSpatialMeshScanning_AsyncAction::HandleLaunchMeshScanningComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSenseDataProviderStartCompletion SenseDataProviderStartCompletion;
	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;

	if(PXR_MeshProvider::GetInstance()->StartSenseDataProviderComplete(FutureHandle, SenseDataProviderStartCompletion,OutResult))
	{
		if (PXR_SUCCESS(SenseDataProviderStartCompletion.FutureResult))
		{
			OnSuccess.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
		else
		{
			OnFailure.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}

	SetReadyToDestroy();
}

void UPICOLaunchSpatialAnchorService_AsyncAction::Activate()
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		OnSuccess.Broadcast(EPICOResult::PXR_Success);
		return;
	}
	
	if(!PXR_AnchorProvider::GetInstance()->IsHandleValid())
	{
		const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
		if (Settings->bEnableAnchor)
		{
			FPICOSenseDataProviderCreateInfoAnchor cFPICOSenseDataProviderCreateInfoAnchor = {};
			FPICOProviderManager::PXR_CreateSenseDataProvider(cFPICOSenseDataProviderCreateInfoAnchor);
		}
	}
	EPICOResult Result=EPICOResult::PXR_Error_Unknow;
	const bool bStarted = FPICOProviderManager::PXR_StartSenseDataProviderAsync(
	FPICOPollFutureDelegate::CreateUObject(this,&UPICOLaunchSpatialAnchorService_AsyncAction::HandleLaunchSpatialAnchorServiceComplete),
	EPICOProviderType::Pico_Provider_Anchor,
	Result
	);

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOLaunchSpatialAnchorService_AsyncAction* UPICOLaunchSpatialAnchorService_AsyncAction::PXR_LaunchSpatialAnchorService_Async()
{
	UPICOLaunchSpatialAnchorService_AsyncAction* Action = NewObject<UPICOLaunchSpatialAnchorService_AsyncAction>();

	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICOLaunchSpatialAnchorService_AsyncAction::HandleLaunchSpatialAnchorServiceComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSenseDataProviderStartCompletion SenseDataProviderStartCompletion;

	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;

	if(PXR_AnchorProvider::GetInstance()->StartSenseDataProviderComplete(FutureHandle, SenseDataProviderStartCompletion,OutResult))
	{
		if (PXR_SUCCESS(SenseDataProviderStartCompletion.FutureResult))
		{
			OnSuccess.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
		else
		{
			OnFailure.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}

	SetReadyToDestroy();
}

void UPICOLaunchSceneCaptureService_AsyncAction::Activate()
{
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		OnSuccess.Broadcast(EPICOResult::PXR_Success);
		return;
	}

	if(!PXR_SceneProvider::GetInstance()->IsHandleValid())
	{
		const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
		if (Settings->bEnableSceneCapture)
		{
			FPICOSenseDataProviderCreateInfoSceneCapture cSenseDataProviderCreateInfoSceneCapture = {};
			FPICOProviderManager::PXR_CreateSenseDataProvider(cSenseDataProviderCreateInfoSceneCapture);
		}
	}	
	
	EPICOResult Result=EPICOResult::PXR_Error_Unknow;
	
	const bool bStarted = FPICOProviderManager::PXR_StartSenseDataProviderAsync(
		FPICOPollFutureDelegate::CreateUObject(this,
		&UPICOLaunchSceneCaptureService_AsyncAction::HandleLaunchSceneCaptureServiceComplete)
		, EPICOProviderType::Pico_Provider_Scene_Capture,Result);

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOLaunchSceneCaptureService_AsyncAction* UPICOLaunchSceneCaptureService_AsyncAction::PXR_LaunchSceneCaptureService_Async()
{
	UPICOLaunchSceneCaptureService_AsyncAction* Action = NewObject<UPICOLaunchSceneCaptureService_AsyncAction>();

	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICOLaunchSceneCaptureService_AsyncAction::HandleLaunchSceneCaptureServiceComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSenseDataProviderStartCompletion SenseDataProviderStartCompletion;

	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;

	if(PXR_SceneProvider::GetInstance()->StartSenseDataProviderComplete(FutureHandle, SenseDataProviderStartCompletion,OutResult))
	{
		if (PXR_SUCCESS(SenseDataProviderStartCompletion.FutureResult))
		{
			OnSuccess.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
		else
		{
			OnFailure.Broadcast(SenseDataProviderStartCompletion.FutureResult);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}

	SetReadyToDestroy();
}

void UPICOLaunchSceneCaptureApp_AsyncAction::HandleLaunchSceneCaptureAppComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSceneCaptureStartCompletion cPICOSceneCaptureStartCompletion;
	PXR_SceneProvider::GetInstance()->StartSceneCaptureComplete(FutureHandle, cPICOSceneCaptureStartCompletion);
	
	if (PXR_SUCCESS(cPICOSceneCaptureStartCompletion.FutureResult))
	{
		OnSuccess.Broadcast(cPICOSceneCaptureStartCompletion.FutureResult);
	}
	else
	{
		OnFailure.Broadcast(cPICOSceneCaptureStartCompletion.FutureResult);
	}

	SetReadyToDestroy();
}

void UPICOLaunchSceneCaptureApp_AsyncAction::HandleStartSpatialSceneCaptureComplete(EPICOResult Result, EPICOSpatialSceneCaptureStatus SpatialSceneCaptureStatus)
{
	if (PXR_SUCCESS(Result))
	{
		OnSuccess.Broadcast(Result);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}

UPICOLaunchSceneCaptureApp_AsyncAction* UPICOLaunchSceneCaptureApp_AsyncAction::PXR_LaunchSceneCaptureApp_Async()
{
	UPICOLaunchSceneCaptureApp_AsyncAction* Action = NewObject<UPICOLaunchSceneCaptureApp_AsyncAction>();

	Action->RegisterWithGameInstance(GWorld);

	return Action;
}

void UPICOLaunchSceneCaptureApp_AsyncAction::Activate()
{
	bool bStarted =false;
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->StartSpatialSceneCapture(
			FPICOStartSpatialSceneCaptureDelegate::CreateUObject(this, &UPICOLaunchSceneCaptureApp_AsyncAction::HandleStartSpatialSceneCaptureComplete),
			Result
		);
	}
	else
	{
		bStarted = PXR_SceneProvider::GetInstance()->StartSceneCaptureAsync
		(
			FPICOPollFutureDelegate::CreateUObject(this, &UPICOLaunchSceneCaptureApp_AsyncAction::HandleLaunchSceneCaptureAppComplete),
			Result
		);
	}

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

//////////////////////////////////////////////////////////////////////////
/// Create Anchor Entity
//////////////////////////////////////////////////////////////////////////
void UPICOCreateSpatialAnchor_AsyncAction::Activate()
{
	if (!IsValid(BoundActor) || !IsValid(BoundActor->GetWorld()))
	{
		OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		return;
	}

	bool bStarted=false;
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->CreateAnchorEntityLegacy(
			BoundActor,
			SpatialAnchorTransform,
			0,
			FPICOCreateAnchorEntityDelegate::CreateUObject(this, &UPICOCreateSpatialAnchor_AsyncAction::HandleCreateAnchorEntityComplete),
			Result
		);
	}
	else
	{
		bStarted = PXR_AnchorProvider::GetInstance()->CreateSpatialAnchorAsync
		(
			FPICOPollFutureDelegate::CreateUObject(this, &UPICOCreateSpatialAnchor_AsyncAction::HandleCreateSpatialAnchorComplete)
			, SpatialAnchorTransform
			,Result
		);
	}

	
	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOCreateSpatialAnchor_AsyncAction* UPICOCreateSpatialAnchor_AsyncAction::PXR_CreateSpatialAnchor_Async(AActor* BoundActor, const FTransform& InSpatialAnchorTransform)
{
	UPICOCreateSpatialAnchor_AsyncAction* Action = NewObject<UPICOCreateSpatialAnchor_AsyncAction>();
	Action->BoundActor = BoundActor;
	Action->SpatialAnchorTransform = InSpatialAnchorTransform;

	if (IsValid(BoundActor))
	{
		Action->RegisterWithGameInstance(BoundActor->GetWorld());
	}
	else
	{
		Action->RegisterWithGameInstance(GWorld);
	}

	return Action;
}

void UPICOCreateSpatialAnchor_AsyncAction::HandleCreateSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSpatialAnchorCreateCompletion SpatialAnchorCreateCompletion;
	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
	if(PXR_AnchorProvider::GetInstance()->CreateSpatialAnchorComplete(FutureHandle, SpatialAnchorCreateCompletion,OutResult))
	{
		UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
		if (!AnchorComponent)
		{
			AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->AddComponentByClass(UPICOAnchorComponent::StaticClass(), false, FTransform::Identity, false));
		}
		AnchorComponent->SetAnchorHandle(SpatialAnchorCreateCompletion.AnchorHandle);

		if (PXR_SUCCESS(SpatialAnchorCreateCompletion.FutureResult))
		{
			OnSuccess.Broadcast(SpatialAnchorCreateCompletion.FutureResult,AnchorComponent);
		}
		else
		{
			OnFailure.Broadcast(SpatialAnchorCreateCompletion.FutureResult);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}

	SetReadyToDestroy();
}

void UPICOCreateSpatialAnchor_AsyncAction::HandleCreateAnchorEntityComplete(EPICOResult Result,const  UPICOAnchorComponent* AnchorComponent)
{
	if (PXR_SUCCESS(Result))
	{
		OnSuccess.Broadcast(Result,AnchorComponent);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}

//////////////////////////////////////////////////////////////////////////
/// Persist Anchor Entity
//////////////////////////////////////////////////////////////////////////
void UPICOPersistSpatialAnchor_AsyncAction::Activate()
{
	if (!IsValid(BoundActor))
	{
		OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		return;
	}
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	bool bStarted = false;
	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->PersistAnchorEntityLegacy(
			BoundActor,
			PersistLocation,
			FPICOPersistAnchorEntityDelegate::CreateUObject(this, &UPICOPersistSpatialAnchor_AsyncAction::HandlePersistAnchorEntityComplete),
			Result
		);
	}
	else
	{
		switch (PersistLocation)
		{
		case EPICOPersistLocation::PersistLocation_Local:
			{
				bStarted = PXR_AnchorProvider::GetInstance()->PersistSpatialAnchorAsync
				(
					BoundActor,
					PersistLocation,
					FPICOPollFutureDelegate::CreateUObject(this, &UPICOPersistSpatialAnchor_AsyncAction::HandlePersistSpatialAnchorComplete),
					Result
				);
			}
			break;
		case EPICOPersistLocation::PersistLocation_Shared:
			{
				bStarted = PXR_AnchorProvider::GetInstance()->ShareSpatialAnchorAsync
				(
					BoundActor,
					FPICOPollFutureDelegate::CreateUObject(this, &UPICOPersistSpatialAnchor_AsyncAction::HandleShareSpatialAnchorComplete),
					Result
				);
			}
			break;
		default: ;
		}
	}

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOPersistSpatialAnchor_AsyncAction* UPICOPersistSpatialAnchor_AsyncAction::PXR_PersistSpatialAnchor_Async(AActor* InBoundActor, EPICOPersistLocation InPersistLocation)
{
	UPICOPersistSpatialAnchor_AsyncAction* Action = NewObject<UPICOPersistSpatialAnchor_AsyncAction>();
	Action->BoundActor = InBoundActor;
	Action->PersistLocation = InPersistLocation;

	if (IsValid(InBoundActor))
	{
		Action->RegisterWithGameInstance(InBoundActor->GetWorld());
	}
	else
	{
		Action->RegisterWithGameInstance(GWorld);
	}

	return Action;
}

void UPICOPersistSpatialAnchor_AsyncAction::HandlePersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSpatialAnchorPersistCompletion SpatialAnchorPersistCompletion;
	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
	if (PXR_AnchorProvider::GetInstance()->PersistSpatialAnchorComplete(FutureHandle, SpatialAnchorPersistCompletion,OutResult))
	{
		UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
		if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
		{
			if (PXR_SUCCESS(SpatialAnchorPersistCompletion.FutureResult))
			{
				OnSuccess.Broadcast(SpatialAnchorPersistCompletion.FutureResult,AnchorComponent);
			}
			else
			{
				OnFailure.Broadcast(SpatialAnchorPersistCompletion.FutureResult);
			}
		}
		else
		{
			OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}
	
	SetReadyToDestroy();
}

void UPICOPersistSpatialAnchor_AsyncAction::HandleShareSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSpatialAnchorShareCompletion SpatialAnchorShareCompletion;
	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
	if (PXR_AnchorProvider::GetInstance()->ShareSpatialAnchorComplete(FutureHandle, SpatialAnchorShareCompletion,OutResult))
	{
		UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
		if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
		{
			if (PXR_SUCCESS(SpatialAnchorShareCompletion.FutureResult))
			{
				OnSuccess.Broadcast(SpatialAnchorShareCompletion.FutureResult,AnchorComponent);
			}
			else
			{
				OnFailure.Broadcast(SpatialAnchorShareCompletion.FutureResult);
			}
		}
		else
		{
			OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}
	
	SetReadyToDestroy();
}

void UPICOPersistSpatialAnchor_AsyncAction::HandlePersistAnchorEntityComplete(EPICOResult Result, const UPICOAnchorComponent* AnchorComponent)
{
	if (PXR_SUCCESS(Result))
	{
		OnSuccess.Broadcast(Result,AnchorComponent);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}


//////////////////////////////////////////////////////////////////////////
/// Unpersist Anchor Entity
//////////////////////////////////////////////////////////////////////////
void UPICOUnpersistSpatialAnchor_AsyncAction::Activate()
{
	if (!IsValid(BoundActor))
	{
		OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		return;
	}
	bool bStarted=false;
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->UnpersistAnchorEntityLegacy(
			BoundActor,
			PersistLocation,
			FPICOUnpersistAnchorEntityDelegate::CreateUObject(this, &UPICOUnpersistSpatialAnchor_AsyncAction::HandleUnpersistAnchorEntityComplete),
			Result
		);
	}
	else
	{
		bStarted = PXR_AnchorProvider::GetInstance()->UnpersistSpatialAnchorAsync(
			BoundActor,
			FPICOPollFutureDelegate::CreateUObject(this, &UPICOUnpersistSpatialAnchor_AsyncAction::HandleUnpersistSpatialAnchorComplete),
			Result
			);
	}


	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICOUnpersistSpatialAnchor_AsyncAction* UPICOUnpersistSpatialAnchor_AsyncAction::PXR_UnpersistSpatialAnchor_Async(AActor* BoundActor, EPICOPersistLocation InPersistLocation)
{
	UPICOUnpersistSpatialAnchor_AsyncAction* Action = NewObject<UPICOUnpersistSpatialAnchor_AsyncAction>();
	Action->BoundActor = BoundActor;
	Action->PersistLocation = InPersistLocation;

	if (IsValid(BoundActor))
	{
		Action->RegisterWithGameInstance(BoundActor->GetWorld());
	}
	else
	{
		Action->RegisterWithGameInstance(GWorld);
	}

	return Action;
}

void UPICOUnpersistSpatialAnchor_AsyncAction::HandleUnpersistSpatialAnchorComplete(const FPICOSpatialHandle& FutureHandle)
{
	FPICOSpatialAnchorUnpersistCompletion SpatialAnchorUnpersistCompletion;
	EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
	
	if(PXR_AnchorProvider::GetInstance()->UnpersistSpatialAnchorComplete(FutureHandle, SpatialAnchorUnpersistCompletion,OutResult))
	{
		UPICOAnchorComponent* AnchorComponent = Cast<UPICOAnchorComponent>(BoundActor->GetComponentByClass(UPICOAnchorComponent::StaticClass()));
		if (IsValid(AnchorComponent) && AnchorComponent->IsAnchorValid())
		{
			if (PXR_SUCCESS(SpatialAnchorUnpersistCompletion.FutureResult))
			{
				OnSuccess.Broadcast(SpatialAnchorUnpersistCompletion.FutureResult,AnchorComponent);
			}
			else
			{
				OnFailure.Broadcast(SpatialAnchorUnpersistCompletion.FutureResult);
			}
		}
		else
		{
			OnFailure.Broadcast(EPICOResult::PXR_Error_ValidationFailure);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}
	
	
	
	SetReadyToDestroy();
}

void UPICOUnpersistSpatialAnchor_AsyncAction::HandleUnpersistAnchorEntityComplete(EPICOResult Result,  const UPICOAnchorComponent* AnchorComponent)
{
	if (PXR_SUCCESS(Result))
	{
		OnSuccess.Broadcast(Result,AnchorComponent);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}

//////////////////////////////////////////////////////////////////////////
/// Load Anchor Entity
//////////////////////////////////////////////////////////////////////////
void UPICORequestSpatialAnchors_AsyncAction::Activate()
{
	bool bStarted = false;
	EPICOResult Result = EPICOResult::PXR_Error_Unknow;

	if (FPICOProviderManager::ShouldUseLegacyMR())
	{
		bStarted = PXR_AnchorProvider::GetInstance()->LoadAnchorEntityLegacy
		(
			EPICOLoadFilterType::LoadFilterType_UUID,
		    LoadInfo, FPICOSceneLoadInfo(),
		    FPICOLoadAnchorEntityDelegate::CreateUObject(this, &UPICORequestSpatialAnchors_AsyncAction::HandleLoadAnchorEntityComplete),
		    Result
		);
	}
	else
	{
		FutureHandleSet.Empty();
		switch (LoadInfo.PersistLocation)
		{
		case EPICOPersistLocation::PersistLocation_Local:
			{
				PXR_LOGV(PxrMR, "UPICORequestSpatialAnchors_AsyncAction Activate Start");
				bStarted = PXR_AnchorProvider::GetInstance()->LoadAnchorEntityAsync
				(
					LoadInfo,
					FPICOPollFutureDelegate::CreateUObject(this, &UPICORequestSpatialAnchors_AsyncAction::HandleLoadSpatialAnchorsComplete),
					Result
				);
			}
			break;
		case EPICOPersistLocation::PersistLocation_Shared:
			{
				bStarted = PXR_AnchorProvider::GetInstance()->DownloadSharedSpatialAnchorsAsync
				(
					LoadInfo,
					FPICOPollFutureDelegate::CreateUObject(this,&UPICORequestSpatialAnchors_AsyncAction::HandleDownloadSharedAnchorsComplete),
					FutureHandleSet,
					Result
				);
			}
			break;
		default: ;
		}
	}

	if (!bStarted)
	{
		OnFailure.Broadcast(Result);
	}
}

UPICORequestSpatialAnchors_AsyncAction* UPICORequestSpatialAnchors_AsyncAction::PXR_LoadSpatialAnchor_Async(const FPICOAnchorLoadInfo& InLoadInfo)
{
	UPICORequestSpatialAnchors_AsyncAction* Action = NewObject<UPICORequestSpatialAnchors_AsyncAction>();
	Action->LoadInfo = InLoadInfo;
	Action->RegisterWithGameInstance(GWorld);
	return Action;
}

void UPICORequestSpatialAnchors_AsyncAction::HandleLoadSpatialAnchorsComplete(const FPICOSpatialHandle& FutureHandle)
{
	EPICOResult LoadResult=EPICOResult::PXR_Error_Unknow;

	TArray<FAnchorLoadResult> AnchorLoadResults;
	PXR_LOGV(PxrMR, "HandleLoadSpatialAnchorsComplete Start");
	
	PXR_AnchorProvider::GetInstance()->GetAnchorLoadResults(FutureHandle,AnchorLoadResults,LoadResult);
	
	if (PXR_SUCCESS(LoadResult))
	{
		OnSuccess.Broadcast(LoadResult,AnchorLoadResults);
	}
	else
	{
		OnFailure.Broadcast(LoadResult);
	}

	SetReadyToDestroy();
}

void UPICORequestSpatialAnchors_AsyncAction::HandleDownloadSharedAnchorsComplete(const FPICOSpatialHandle& FutureHandle)
{
	EPICOResult OutResult = EPICOResult::PXR_Error_Unknow;
	FPICOSharedSpatialAnchorDownloadCompletion SharedSpatialAnchorDownloadCompletion;
	FutureHandleSet.Remove(FutureHandle);
	if(PXR_AnchorProvider::GetInstance()->DownloadSharedSpatialAnchorsComplete(FutureHandle, SharedSpatialAnchorDownloadCompletion,OutResult))
	{
		if(PXR_SUCCESS(SharedSpatialAnchorDownloadCompletion.FutureResult))
		{
			if (!FutureHandleSet.Num())
			{
				if(!PXR_AnchorProvider::GetInstance()->LoadAnchorEntityAsync(
				LoadInfo,
				FPICOPollFutureDelegate::CreateUObject(this, &UPICORequestSpatialAnchors_AsyncAction::HandleLoadSpatialAnchorsComplete),
				OutResult
				))
				{
					OnFailure.Broadcast(OutResult);
				}
			}
		}
		else
		{
			OnFailure.Broadcast(SharedSpatialAnchorDownloadCompletion.FutureResult);
		}
	}
	else
	{
		OnFailure.Broadcast(OutResult);
	}

	SetReadyToDestroy();
}

void UPICORequestSpatialAnchors_AsyncAction::HandleLoadAnchorEntityComplete(EPICOResult Result, const TArray<FAnchorLoadResult>& AnchorLoadResults)
{
	if (PXR_SUCCESS(Result))
	{
		OnSuccess.Broadcast(Result, AnchorLoadResults);
	}
	else
	{
		OnFailure.Broadcast(Result);
	}

	SetReadyToDestroy();
}
