//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.


#include "PXR_Cubemap.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "ImageUtils.h"
#include "TimerManager.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"

// Sets default values
APXR_Cubemap::APXR_Cubemap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APXR_Cubemap::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APXR_Cubemap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APXR_Cubemap::SaveCubeMap_PICO()
{
	Location = GetRootComponent()->GetComponentLocation();
	Orientation = GetRootComponent()->GetComponentQuat();

	const FVector ZAxis(0, 0, 1);
	const FVector YAxis(0, 1, 0);

	const FQuat FaceOrientations[] = {
										{ZAxis, PI / 2}, { ZAxis, -PI / 2},// right, left
										{YAxis, -PI / 2}, { YAxis, PI / 2},   // top, bottom
										{ZAxis, 0}, { ZAxis, -PI},// front, back
	};

	for (int i = 0; i < 6; ++i)
	{
		USceneCaptureComponent2D* CaptureComponent = NewObject<USceneCaptureComponent2D>();
		CaptureComponent->SetVisibility(true);
		CaptureComponent->SetHiddenInGame(false);

		CaptureComponent->CaptureStereoPass = EStereoscopicPass::eSSP_FULL;//LEFT_EYE; //??
		CaptureComponent->FOVAngle = 90.f;
		CaptureComponent->bCaptureEveryFrame = true;
		CaptureComponent->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;

		const FName TargetName = MakeUniqueObjectName(this, UTextureRenderTarget2D::StaticClass(), TEXT("SceneCaptureTextureTarget"));
		CaptureComponent->TextureTarget = NewObject<UTextureRenderTarget2D>(this, TargetName);
		CaptureComponent->TextureTarget->InitCustomFormat(CaptureBoxSideRes, CaptureBoxSideRes, CaptureFormat, false);

		CaptureComponents.Add(CaptureComponent);

		CaptureComponent->RegisterComponentWithWorld(GWorld);

		CaptureComponent->SetWorldLocationAndRotation(Location, Orientation * FaceOrientations[i]);

		CaptureComponent->UpdateContent();
	}

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnInfo.bNoFail = true;
	SpawnInfo.ObjectFlags = RF_Transient;
	AStaticMeshActor* InGameActor;
	InGameActor = GetWorld()->SpawnActor<AStaticMeshActor>(SpawnInfo);

	OutputDir = FPaths::ProjectSavedDir() + TEXT("/Cubemaps");
	IFileManager::Get().MakeDirectory(*OutputDir);

	auto CopyRT2D = [=]()
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

		TArray<FColor> OneFaceSurface, WholeCubemapData;
		OneFaceSurface.AddUninitialized(CaptureBoxSideRes * CaptureBoxSideRes);
		WholeCubemapData.AddUninitialized(CaptureBoxSideRes * 6 * CaptureBoxSideRes);

		for (int cubeFaceIdx = 0; cubeFaceIdx < 6; ++cubeFaceIdx)
		{
			auto RenderTarget = CaptureComponents[cubeFaceIdx]->TextureTarget->GameThread_GetRenderTargetResource();
			RenderTarget->ReadPixelsPtr(OneFaceSurface.GetData(), FReadSurfaceDataFlags());

			for (FColor& Color : OneFaceSurface)
			{
				Color.A = 255;
			}

			const uint32 Stride = CaptureBoxSideRes * 6;
			const uint32 XOff = cubeFaceIdx * CaptureBoxSideRes;
			const uint32 StripSizeInBytes = CaptureBoxSideRes * sizeof(FColor);
			for (uint32 y = 0; y < CaptureBoxSideRes; ++y)
			{
				FMemory::Memcpy(WholeCubemapData.GetData() + XOff + y * Stride, OneFaceSurface.GetData() + y * CaptureBoxSideRes, StripSizeInBytes);
			}
		}

		ImageWrapper->SetRaw(WholeCubemapData.GetData(), WholeCubemapData.GetAllocatedSize(), CaptureBoxSideRes * 6, CaptureBoxSideRes, ERGBFormat::BGRA, 8);
#if ENGINE_MINOR_VERSION >24
		const TArray64<uint8>& PNGData = ImageWrapper->GetCompressed(100);
#else
		const TArray<uint8>& PNGData = ImageWrapper->GetCompressed(100);
#endif

		const FString Filename = OutputDir + FString::Printf(TEXT("/Cubemap-%d-%s.png"), CaptureBoxSideRes, *FDateTime::Now().ToString(TEXT("%m.%d-%H.%M.%S")));

		isCatchImageWP = FFileHelper::SaveArrayToFile(PNGData, *Filename);

		for (int i = 0; i < CaptureComponents.Num(); ++i)
		{
			CaptureComponents[i]->UnregisterComponent();
		}
		CaptureComponents.SetNum(0);

	};

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, CopyRT2D, 0.001f, false, 0);

	return isCatchImageWP;
}

void APXR_Cubemap::PXR_CubemapHandler()
{
#if !UE_BUILD_SHIPPING
	SaveCubeMap_PICO();
#endif
}

