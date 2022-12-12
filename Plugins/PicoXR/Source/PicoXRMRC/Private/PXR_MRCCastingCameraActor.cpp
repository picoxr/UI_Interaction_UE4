//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_MRCCastingCameraActor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "PXR_MRCState.h"
#include "VRNotificationsComponent.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Runtime/Launch/Resources/Version.h"
#include "PXR_HMD.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "XRThreadUtils.h"
#include "UObject/ConstructorHelpers.h"

#if PICO_MRC_SUPPORTED_PLATFORMS
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#endif

APICOXRMRC_CastingCameraActor::APICOXRMRC_CastingCameraActor(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	,BackgroundRenderTarget(nullptr)
	,ForegroundRenderTarget(nullptr)
	,bEnableForeground(true)
	,ForegroundMaxDistance(300.f)
	,bHasInitializedInGameCamOnce(false)
	,MRState(nullptr)
	,M_MRC(nullptr)
	,MI_Background(nullptr)
	,MI_Foreground(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	
	ForegroundCaptureActor = NULL;

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> BGRef(TEXT("TextureRenderTarget2D'/PICOXR/Textures/MRCRT_BG.MRCRT_BG'"));
	BackgroundRenderTarget = BGRef.Object;
	check(BackgroundRenderTarget != nullptr);
	BackgroundRenderTarget->RenderTargetFormat = RTF_RGBA8_SRGB;

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> FGRef(TEXT("TextureRenderTarget2D'/PICOXR/Textures/MRCRT_FG.MRCRT_FG'"));
	ForegroundRenderTarget = FGRef.Object;
	check(ForegroundRenderTarget != nullptr);
	ForegroundRenderTarget->RenderTargetFormat = RTF_RGBA8_SRGB;
}

void APICOXRMRC_CastingCameraActor::InitializeStates(UPXRInGameThirdCamState* MRStateIn)
{
	MRState = MRStateIn;
}

void APICOXRMRC_CastingCameraActor::BeginPlay()
{
	Super::BeginPlay();
	PXR_LOGI(LogMRC, "In-Game Camera BeginPlay!");
	InitializeInGameCam();
}

void APICOXRMRC_CastingCameraActor::EndPlay(EEndPlayReason::Type Reason)
{
	DestroyForeroundCaptureActor();
	Super::EndPlay(Reason);
}

void APICOXRMRC_CastingCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bHasInitializedInGameCamOnce)
	{
		SetMRCTrackingReference();
		UpdateInGameCamPose();
		UpdateCamMatrixAndDepth();
			
		if (bEnableForeground&&!ForegroundCaptureActor)
		{
			SpawnForegroundCaptureActor();
		}
		else if(!bEnableForeground&&ForegroundCaptureActor)
		{
			DestroyForeroundCaptureActor();
			if (!GetCaptureComponent2D()->IsVisible())
			{
				GetCaptureComponent2D()->SetVisibility(true);
			}
		}
		
		if (ForegroundCaptureActor && GetCaptureComponent2D()->IsVisible())
		{
			ForegroundCaptureActor->GetCaptureComponent2D()->TextureTarget = ForegroundRenderTarget;
			GetCaptureComponent2D()->SetVisibility(false);
			ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(true);
			
		}
		else if (ForegroundCaptureActor && ForegroundCaptureActor->GetCaptureComponent2D()->IsVisible())
		{
			GetCaptureComponent2D()->TextureTarget = BackgroundRenderTarget;
			ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(false);
			GetCaptureComponent2D()->SetVisibility(true);
		}
		else if (!ForegroundCaptureActor && !GetCaptureComponent2D()->IsVisible())
		{
			GetCaptureComponent2D()->SetVisibility(true);
		}

	}
}

void APICOXRMRC_CastingCameraActor::BeginDestroy()
{
	Super::BeginDestroy();
}

void APICOXRMRC_CastingCameraActor::SpawnForegroundCaptureActor()
{
	if (bEnableForeground&&!ForegroundCaptureActor)
	{
		PXR_LOGI(LogMRC, "Begin Spawn Forground MRC Capture Actor!");
		ForegroundCaptureActor = GetWorld()->SpawnActor<ASceneCapture2D>();
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=26
		ForegroundCaptureActor->GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
#else
		ForegroundCaptureActor->GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
#if ENGINE_MAJOR_VERSION ==4 && ENGINE_MINOR_VERSION ==25
		ForegroundCaptureActor->GetCaptureComponent2D()->bDisableFlipCopyGLES = true;
#endif
#endif
		ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(false);
		ForegroundCaptureActor->GetCaptureComponent2D()->MaxViewDistanceOverride = ForegroundMaxDistance;
		float x = MRState->TrackedCamera.Width;
		float y = MRState->TrackedCamera.Height;
		ForegroundCaptureActor->GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FOV * (x / y);
		ForegroundCaptureActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		PXR_LOGI(LogMRC, "Spawn Forground MRC Capture Actor Over!");
	}
}

void APICOXRMRC_CastingCameraActor::DestroyForeroundCaptureActor()
{
	if (ForegroundCaptureActor)
	{
		PXR_LOGI(LogMRC, "Destroy Forground MRC Capture Actor!!!");
		if(ForegroundRenderTarget)
		{
			UKismetRenderingLibrary::ClearRenderTarget2D(this,ForegroundRenderTarget, FLinearColor::Green);
		}
		ForegroundCaptureActor->Destroy();
		ForegroundCaptureActor = nullptr;
	}
}

void APICOXRMRC_CastingCameraActor::SetMRCTrackingReference()
{
	if (MRState->CurrentTrackingReference)
	{
		if (MRState->CurrentTrackingReference != this->GetRootComponent()->GetAttachParent())
		{
			PXR_LOGI(LogMRC, "Set mrc tracking reference to MRState->CurrentTrackingReference!");
			this->AttachToComponent(MRState->CurrentTrackingReference, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		}
	}
	else
	{
		APlayerController* myController = GetWorld()->GetFirstPlayerController();
		APawn* myPawn = myController->GetPawn();
		TArray<USceneComponent*>ChildComp;
		myPawn->GetRootComponent()->GetChildrenComponents(true, ChildComp);
		USceneComponent* camParent = nullptr;
		for (auto& comp : ChildComp)
		{
			UCameraComponent* cameraComp = Cast<UCameraComponent>(comp);
			if (cameraComp)
			{
				camParent = cameraComp->GetAttachParent();
				break;
			}
		}
		if (camParent)
		{
			PXR_LOGI(LogMRC, "Set mrc tracking reference to the parent of pawn camera!");
			this->AttachToComponent(camParent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			MRState->CurrentTrackingReference = camParent;
		}
		else
		{
			PXR_LOGI(LogMRC, "Set mrc tracking reference to the root component of pawn!");
			this->AttachToComponent(myPawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			MRState->CurrentTrackingReference = myPawn->GetRootComponent();
		}
	}
}

void APICOXRMRC_CastingCameraActor::UpdateInGameCamPose()
{
	bool UseCustomTrans = MRState->bUseCustomTrans;
	if (UseCustomTrans)
	{
		RootComponent->SetRelativeTransform(MRState->CustomTrans);
	}
	else
	{
		FPICOXRMRCModule::Get().GetMRCCalibrationData(MRState->TrackedCamera);

		if (FPICOXRMRCModule::Get().PICOXRHMD && !bHasInitializedInGameCamOnce)
		{
			MRState->ZOffset = 0;
			FQuat currentQuat; FVector currentPose;
			FPICOXRMRCModule::Get().PICOXRHMD->GetCurrentPose(0, currentQuat, currentPose);
			PXR_LOGI(LogMRC, "HMD Location ZOffset:%f", currentPose.Z);
			MRState->ZOffset += currentPose.Z;//Eye or Floor Level
#if PLATFORM_ANDROID
			float offsetZ = 0;
			Pxr_GetConfigFloat(PXR_MRC_POSITION_Y_OFFSET, &offsetZ);
			PXR_LOGI(LogMRC, "Pxr_GetConfigFloat(PXR_MRC_POSITION_Y_OFFSET,&offsetZ):%f", offsetZ);
			MRState->ZOffset -= offsetZ * 100.0f;//World to local offset z
#endif
	}
		MRState->TrackedCamera.CalibratedOffset.Z += MRState->ZOffset;
		PXR_LOGV(LogMRC, "In-Game ThirdCamera Final Relative Location:%s,Rotation:%s", PLATFORM_CHAR(*MRState->TrackedCamera.CalibratedOffset.ToString()), PLATFORM_CHAR(*MRState->TrackedCamera.CalibratedRotation.ToString()));
		FTransform FinalTransform(MRState->TrackedCamera.CalibratedRotation, MRState->TrackedCamera.CalibratedOffset);
		MRState->FinalTransform = FinalTransform;
		RootComponent->SetRelativeTransform(MRState->FinalTransform);
	}
}

void MakeProjectionMatrix(float YMultiplier, float FOV, float FarClipPlane, FMatrix& ProjectionMatrix)
{
	if (FarClipPlane < GNearClippingPlane)
	{
		FarClipPlane = GNearClippingPlane;
	}

	if ((int32)ERHIZBuffer::IsInverted)
	{
		ProjectionMatrix = FReversedZPerspectiveMatrix(
			FOV,
			FOV,
			1.0f,
			YMultiplier,
			GNearClippingPlane,
			FarClipPlane
		);
	}
	else
	{
		ProjectionMatrix = FPerspectiveMatrix(
			FOV,
			FOV,
			1.0f,
			YMultiplier,
			GNearClippingPlane,
			FarClipPlane
		);
	}
}

void APICOXRMRC_CastingCameraActor::UpdateCamMatrixAndDepth()
{
	float Distance = 0.0f;
	FQuat HeadOrientation;
	FVector HeadPosition;
	HeadPosition = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
	FVector HeadToCamera = HeadPosition - this->GetActorLocation();
	Distance = FVector::DotProduct(this->GetActorForwardVector().GetSafeNormal2D(), HeadToCamera);
	ForegroundMaxDistance = FMath::Max(Distance, GMinClipZ);
	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->MaxViewDistanceOverride = ForegroundMaxDistance;
	}

	float FOV = GetCaptureComponent2D()->FOVAngle * (float)PI / 360.0f;

	int ViewWidth = MRState->TrackedCamera.Width;
	int ViewHeight = MRState->TrackedCamera.Height;
	FIntPoint CameraTargetSize = FIntPoint(ViewWidth, ViewHeight);

	// Use custom projection matrix for far clip plane and to use camera aspect ratio instead of rendertarget aspect ratio
	float YMultiplier = (float)CameraTargetSize.X / (float)CameraTargetSize.Y;
	GetCaptureComponent2D()->bUseCustomProjectionMatrix = true;
	MakeProjectionMatrix(YMultiplier, FOV, GNearClippingPlane, GetCaptureComponent2D()->CustomProjectionMatrix);
	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->bUseCustomProjectionMatrix = true;
		MakeProjectionMatrix(YMultiplier, FOV, ForegroundMaxDistance, ForegroundCaptureActor->GetCaptureComponent2D()->CustomProjectionMatrix);
	}
}


void APICOXRMRC_CastingCameraActor::InitializeRTSize()
{
	int ViewWidth = MRState->TrackedCamera.Width;
	int ViewHeight = MRState->TrackedCamera.Height;

	FIntPoint CameraTargetSize = FIntPoint(ViewWidth, ViewHeight);

	BackgroundRenderTarget->ResizeTarget(ViewWidth, ViewHeight);
	
	ForegroundRenderTarget->ResizeTarget(ViewWidth, ViewHeight);	

}

void APICOXRMRC_CastingCameraActor::InitializeInGameCam()
{
	FPICOXRMRCModule::Get().GetMRCCalibrationData(MRState->TrackedCamera);

	SetMRCTrackingReference();

	UpdateInGameCamPose();
	
	if (!bHasInitializedInGameCamOnce)
	{
		InitializeRTSize();
	
		// LDR for gamma correction and post process
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=26
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
#else
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
#if ENGINE_MAJOR_VERSION ==4 && ENGINE_MINOR_VERSION ==25
		GetCaptureComponent2D()->bDisableFlipCopyGLES = true;
#endif
#endif
		float x = MRState->TrackedCamera.Width;
		float y = MRState->TrackedCamera.Height;
		GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FOV * (x / y);
		PXR_LOGI(LogMRC, "Final FOV:%f", GetCaptureComponent2D()->FOVAngle);
	
		SpawnForegroundCaptureActor();
		if (FPICOXRMRCModule::IsAvailable()&& FPICOXRMRCModule::Get().GetPICOXRHMD())
		{
			FTextureRHIRef BG=nullptr, FG=nullptr;
			ExecuteOnRenderThread([this,&BG,&FG]()
				{
					ExecuteOnRHIThread([this,&BG,&FG]()
						{
							BG = BackgroundRenderTarget->Resource->TextureRHI;
							FG = ForegroundRenderTarget->Resource->TextureRHI;
						});
				});
#if PLATFORM_ANDROID
		    FPICOXRMRCModule::Get().GetPICOXRHMD()->CreateMRCStereoLayer(BG,FG);		
#endif
	    }
	}
	bHasInitializedInGameCamOnce = true;
}
