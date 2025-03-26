// Fill out your copyright notice in the Description page of Project Settings.


#include "PICO_MRCSceneCapture2D.h"
#include "SceneCaptureComponent2D.h"
#include "UObject/ConstructorHelpers.h"
#include "PXR_HMD.h"
#include "PXR_Log.h"
#include "Components/StaticMeshComponent.h"
#include "TextureResource.h"
#include "Engine/StaticMesh.h"

AMRCSceneCapture2DPICO::AMRCSceneCapture2DPICO(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, HMDPICO(nullptr)
	, Width(0)
	, Height(0)
	, Fov(0.0f)
	, FlipFlop(true)
{
	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> BGRef(TEXT("/Script/Engine.TextureRenderTarget2D'/PICOXR/Textures/MRCRT_BG.MRCRT_BG'"));
	BackgroundRT = BGRef.Object;
	check(BackgroundRT != nullptr);
	BackgroundRT->RenderTargetFormat = RTF_RGBA8_SRGB;
	BackgroundRT->bAutoGenerateMips = false;

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> FGRef(TEXT("/Script/Engine.TextureRenderTarget2D'/PICOXR/Textures/MRCRT_FG.MRCRT_FG'"));
	ForegroundRT = FGRef.Object;
	check(ForegroundRT != nullptr);
	ForegroundRT->RenderTargetFormat = RTF_RGBA8_SRGB;
	ForegroundRT->bAutoGenerateMips = false;
	
	GetCaptureComponent2D()->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	bAllowTickBeforeBeginPlay = false;

	UStaticMesh* StaticMeshAsset = LoadObject<UStaticMesh>(NULL, TEXT("/Script/Engine.StaticMesh'/Engine/EditorMeshes/MatineeCam_SM.MatineeCam_SM'"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	if (StaticMeshComponent && StaticMeshAsset)
	{
		AddOwnedComponent(StaticMeshComponent);
		StaticMeshComponent->SetupAttachment(RootComponent);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMeshComponent->SetStaticMesh(StaticMeshAsset);
		StaticMeshComponent->SetRelativeScale3D(FVector(0.3, 0.3, 0.3));
		StaticMeshComponent->SetOwnerNoSee(true);
	}
}

void AMRCSceneCapture2DPICO::BeginPlay()
{
	Super::BeginPlay();

	static FName SystemName(TEXT("PICOXRHMD"));
	if (GEngine)
	{
		if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
		{
			HMDPICO = static_cast<FPICOXRHMD*>(GEngine->XRSystem.Get());
		}
	}

	if (HMDPICO == nullptr)
	{
		SetActorTickEnabled(false);
		return;
	}

	if (FPICOXRHMDModule::GetPluginWrapper().GetExternalCameraInfo)
	{
		ExternalCameraInfo CameraInfo = {};
		FPICOXRHMDModule::GetPluginWrapper().GetExternalCameraInfo(&CameraInfo);

		Width = CameraInfo.width;
		Height = CameraInfo.height;
		Fov = CameraInfo.fov;

		PXR_LOGI(LogMRC, "GetExternalCameraInfo Width:%d,Height:%d,Fov:%f", Width, Height, Fov);
	}

	if (!Width || !Height || !Fov)
	{
		SetActorTickEnabled(false);
		return;
	}
	else
	{
		BackgroundRT->ResizeTarget(Width, Height);
		ForegroundRT->ResizeTarget(Width, Height);

		InitializeRTRenderResource(BackgroundRT);
		InitializeRTRenderResource(ForegroundRT);

		HMDPICO->CreateMRCStereoLayer(BackgroundRT->GetResource()->TextureRHI, ForegroundRT->GetResource()->TextureRHI);

		PXR_LOGI(LogMRC, "CreateMRCStereoLayer");
		GetCaptureComponent2D()->FOVAngle = Fov * ((float)Width / (float)Height);
	}
}

void AMRCSceneCapture2DPICO::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (HMDPICO)
	{
		HMDPICO->DestroyMRCLayer();
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

void AMRCSceneCapture2DPICO::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FTransform MRCCameraPose = FTransform::Identity;
	if (GetExternalCameraPose(MRCCameraPose))
	{
		SetActorTransform(MRCCameraPose);
	}
	else
	{
		if (GetCaptureComponent2D()->IsVisible())
		{
			GetCaptureComponent2D()->SetVisibility(false);
		}
		return;
	}

	if (FlipFlop)
	{
		UpdateCamMatrixAndDepth(false);
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
		GetCaptureComponent2D()->TextureTarget = BackgroundRT;
		FlipFlop = false;
	}
	else
	{
		UpdateCamMatrixAndDepth(true);
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
		GetCaptureComponent2D()->TextureTarget = ForegroundRT;
		FlipFlop = true;
	}

	if (!GetCaptureComponent2D()->IsVisible())
	{
		GetCaptureComponent2D()->SetVisibility(true);
	}
}

void AMRCSceneCapture2DPICO::InitializeRTRenderResource(UTextureRenderTarget2D* RT)
{
	FTextureRenderTargetResource* RenderTargetResource = RT->GameThread_GetRenderTargetResource();

	{
		ENQUEUE_RENDER_COMMAND(FlushDeferredResourceUpdateCommand)(
			[RenderTargetResource](FRHICommandListImmediate& RHICmdList)
			{
				RenderTargetResource->FlushDeferredResourceUpdate(RHICmdList);
			});
		FlushRenderingCommands();

		RT->UpdateResourceImmediate(false);

		ENQUEUE_RENDER_COMMAND(ResetSceneTextureExtentHistory)(
			[RenderTargetResource](FRHICommandListImmediate& RHICmdList)
			{
				RenderTargetResource->ResetSceneTextureExtentsHistory();
			});
		FlushRenderingCommands();
	}
}

void AMRCSceneCapture2DPICO::UpdateCamMatrixAndDepth(bool bIsForeground)
{
	FTransform HMDPose = FTransform::Identity;
	if (HMDPICO)
	{
		FQuat HMDOrientation = FQuat::Identity;
		FVector HMDPosition = FVector::ZeroVector;
		FTransform TrackingToWorld = HMDPICO->GetTrackingToWorldTransform();
		HMDPICO->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, HMDOrientation, HMDPosition);
		HMDPose = FTransform(HMDOrientation, HMDPosition) * TrackingToWorld;
	}

	FVector HeadToCamera = HMDPose.GetLocation() - GetActorLocation();
	float Distance = FVector::DotProduct(GetActorForwardVector().GetSafeNormal2D(), HeadToCamera);
	float ForegroundMaxDistance = FMath::Max(Distance, GMinClipZ);

	if (bIsForeground)
	{
		GetCaptureComponent2D()->MaxViewDistanceOverride = ForegroundMaxDistance;
	}
	else
	{
		GetCaptureComponent2D()->MaxViewDistanceOverride = -1;
	}

	if (bIsForeground)
	{
		float YMultiplier = (float)Width / (float)Height;
		float FOV = GetCaptureComponent2D()->FOVAngle * (float)PI / 360.0f;
		GetCaptureComponent2D()->bUseCustomProjectionMatrix = true;
		MakeProjectionMatrix(YMultiplier, FOV, ForegroundMaxDistance, GetCaptureComponent2D()->CustomProjectionMatrix);
	}
	else
	{
		GetCaptureComponent2D()->bUseCustomProjectionMatrix = false;
		GetCaptureComponent2D()->CustomProjectionMatrix.SetIdentity();
	}
}

FORCEINLINE FQuat ToFQuatMRC(const PxrQuaternionf& InQuat)
{
	return FQuat(-InQuat.z, InQuat.x, InQuat.y, -InQuat.w);
}

FORCEINLINE FVector ToFVectorMRC(const PxrVector3f& InVec, float Scale)
{
	return FVector(-InVec.z * Scale, InVec.x * Scale, InVec.y * Scale);
}

bool AMRCSceneCapture2DPICO::GetExternalCameraPose(FTransform& Pose)
{
	if (FPICOXRHMDModule::GetPluginWrapper().GetExternalCameraPose && HMDPICO)
	{
		PxrTrackingOrigin TrackingOrigin = {};
		FPICOXRHMDModule::GetPluginWrapper().GetTrackingOrigin(&TrackingOrigin);
		if (FPICOXRHMDModule::GetPluginWrapper().GetExternalCameraPose)
		{
			PxrPosef pose = {};
			FPICOXRHMDModule::GetPluginWrapper().GetExternalCameraPose(TrackingOrigin, &pose);

	
			const FQuat Orientation = ToFQuatMRC(pose.orientation);
			const FVector Position = ToFVectorMRC(pose.position, HMDPICO->GetWorldToMetersScale());

			FTransform TrackingToWorld = HMDPICO->GetTrackingToWorldTransform();
			Pose = FTransform(Orientation, Position) * TrackingToWorld;

			PXR_LOGV(LogMRC, "GetExternalCameraPose:%s", *Pose.ToString());
			return true;
		}
	}
	return false;
}