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

APicoXRMRC_CastingCameraActor::APicoXRMRC_CastingCameraActor(const FObjectInitializer& ObjectInitializer)
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

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> BGRef(TEXT("TextureRenderTarget2D'/PicoXR/Textures/MRCRT_BG.MRCRT_BG'"));
	BackgroundRenderTarget = BGRef.Object;
	check(BackgroundRenderTarget != nullptr);
	BackgroundRenderTarget->RenderTargetFormat = RTF_RGBA8_SRGB;

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> FGRef(TEXT("TextureRenderTarget2D'/PicoXR/Textures/MRCRT_FG.MRCRT_FG'"));
	ForegroundRenderTarget = FGRef.Object;
	check(ForegroundRenderTarget != nullptr);
	ForegroundRenderTarget->RenderTargetFormat = RTF_RGBA8_SRGB;
}

void APicoXRMRC_CastingCameraActor::InitializeStates(UPXRInGameThirdCamState* MRStateIn)
{
	MRState = MRStateIn;
}

void APicoXRMRC_CastingCameraActor::BeginPlay()
{
	Super::BeginPlay();
	PXR_LOGI(LogMRC, "In-Game Camera BeginPlay!");
	
	if (FPicoXRMRCModule::Get().SpawnTimes > 1)
	{
		InitializeInGameCam();
	}
	else
	{
		FTimerHandle BeginCalibrateHandle;
		GetWorldTimerManager().SetTimer(BeginCalibrateHandle, this, &APicoXRMRC_CastingCameraActor::InitializeInGameCam, 0.1, false);
	}
}

void APicoXRMRC_CastingCameraActor::EndPlay(EEndPlayReason::Type Reason)
{
	DestroyForeroundCaptureActor();
	Super::EndPlay(Reason);
}

void APicoXRMRC_CastingCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bHasInitializedInGameCamOnce)
	{
		//UpdateInGameCamPose();
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

	}
}

void APicoXRMRC_CastingCameraActor::BeginDestroy()
{
	Super::BeginDestroy();
}

void APicoXRMRC_CastingCameraActor::SpawnForegroundCaptureActor()
{
	if (bEnableForeground&&!ForegroundCaptureActor)
	{
		PXR_LOGI(LogMRC, "Begin Spawn Forground MRC Capture Actor!");
		ForegroundCaptureActor = GetWorld()->SpawnActor<ASceneCapture2D>();
		ForegroundCaptureActor->GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
#if ENGINE_MINOR_VERSION == 25
		ForegroundCaptureActor->GetCaptureComponent2D()->bDisableFlipCopyGLES = true;
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

void APicoXRMRC_CastingCameraActor::DestroyForeroundCaptureActor()
{
	if (ForegroundCaptureActor)
	{
		PXR_LOGI(LogMRC, "Destroy Forground MRC Capture Actor!!!");
		ForegroundCaptureActor->Destroy();
		ForegroundCaptureActor = nullptr;
	}
}

void APicoXRMRC_CastingCameraActor::SetMRCTrackingReference()
{
	APlayerController* myController = GetWorld()->GetFirstPlayerController();
	APawn* myPawn = myController->GetPawn();
	TArray<USceneComponent*>ChildComp;
	myPawn->GetRootComponent()->GetChildrenComponents(true, ChildComp);
	USceneComponent* camParent=nullptr;
	for (auto & comp :ChildComp)
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
		this->AttachToComponent(camParent,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	else
	{
		PXR_LOGI(LogMRC, "Set mrc tracking reference to the root component of pawn!");
		this->AttachToComponent(myPawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
}

void APicoXRMRC_CastingCameraActor::UpdateInGameCamPose()
{
	FPicoXRMRCModule::Get().GetMRCCalibrationData(MRState->TrackedCamera);

	if (FPicoXRMRCModule::Get().PicoXRHMD && !bHasInitializedInGameCamOnce)
	{
		MRState->ZOffset = 0;
		FQuat currentQuat; FVector currentPose;
		FPicoXRMRCModule::Get().PicoXRHMD->GetCurrentPose(0, currentQuat, currentPose);
		PXR_LOGI(LogMRC, "HMD Location ZOffset:%f", currentPose.Z);
		MRState->ZOffset += currentPose.Z;//Eye or Floor Level
#if PLATFORM_ANDROID
		float offsetZ = 0;
		Pxr_GetConfigFloat(PXR_MRC_POSITION_Y_OFFSET, &offsetZ);
		PXR_LOGI(LogMRC, "Pxr_GetConfigFloat(PXR_MRC_POSITION_Y_OFFSET,&offsetZ):%f", offsetZ);
		MRState->ZOffset -= offsetZ * 100.0f;//World to local offset z
		MRState->TrackedCamera.CalibratedOffset.Z += MRState->ZOffset;
#endif
	}
	PXR_LOGI(LogMRC, "In-Game ThirdCamera Final Relative Location:%s,Rotation:%s", PLATFORM_CHAR(*MRState->TrackedCamera.CalibratedOffset.ToString()), PLATFORM_CHAR (*MRState->TrackedCamera.CalibratedRotation.ToString()));
	FTransform FinalTransform(MRState->TrackedCamera.CalibratedRotation, MRState->TrackedCamera.CalibratedOffset);
	MRState->FinalTransform = FinalTransform;
	RootComponent->SetRelativeTransform(MRState->FinalTransform);
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

void APicoXRMRC_CastingCameraActor::UpdateCamMatrixAndDepth()
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


void APicoXRMRC_CastingCameraActor::InitializeRTSize()
{
	int ViewWidth = MRState->TrackedCamera.Width;
	int ViewHeight = MRState->TrackedCamera.Height;

	FIntPoint CameraTargetSize = FIntPoint(ViewWidth, ViewHeight);

	BackgroundRenderTarget->ResizeTarget(ViewWidth, ViewHeight);
	
	ForegroundRenderTarget->ResizeTarget(ViewWidth, ViewHeight);	

}

void APicoXRMRC_CastingCameraActor::InitializeInGameCam()
{
	FPicoXRMRCModule::Get().GetMRCCalibrationData(MRState->TrackedCamera);

	SetMRCTrackingReference();

	UpdateInGameCamPose();
	
	if (!bHasInitializedInGameCamOnce)
	{
		InitializeRTSize();
	
		// LDR for gamma correction and post process
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
#if ENGINE_MINOR_VERSION == 25
		GetCaptureComponent2D()->bDisableFlipCopyGLES = true;
#endif
		float x = MRState->TrackedCamera.Width;
		float y = MRState->TrackedCamera.Height;
		GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FOV * (x / y);
		PXR_LOGI(LogMRC, "Final FOV:%f", GetCaptureComponent2D()->FOVAngle);
	
		SpawnForegroundCaptureActor();
		if (FPicoXRMRCModule::IsAvailable()&& FPicoXRMRCModule::Get().GetPicoXRHMD())
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
		    FPicoXRMRCModule::Get().GetPicoXRHMD()->CreateMRCStereoLayer(BG,FG);		
#endif
		    FPicoXRMRCModule::Get().PicoXRHMD->EventManager->LongHomePressedDelegate.AddDynamic(this, &APicoXRMRC_CastingCameraActor::OnHMDRecentered);
		    PXR_LOGI(LogMRC, "LongHomePressedDelegate binded!");
		    FPicoXRMRCModule::Get().PicoXRHMD->EventManager->ResumeDelegate.AddDynamic(this, &APicoXRMRC_CastingCameraActor::OnHMDResume);
		    PXR_LOGI(LogMRC, "HMDResume binded!");
	    }
	}
	bHasInitializedInGameCamOnce = true;
}

void APicoXRMRC_CastingCameraActor::OnHMDRecentered()
{
	InitializeInGameCam();
	PXR_LOGI(LogMRC, "OnHMDRecentered called!");
}

void APicoXRMRC_CastingCameraActor::OnHMDResume()
{
	FTimerHandle ResumeHandle;
	//Delay in obtaining calibration data
	GetWorldTimerManager().SetTimer(ResumeHandle, this, &APicoXRMRC_CastingCameraActor::InitializeInGameCam, 0.1, false);
	PXR_LOGI(LogMRC, "ResumeMRC called!");
}
