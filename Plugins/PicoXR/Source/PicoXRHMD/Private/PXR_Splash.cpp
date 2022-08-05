//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Splash.h"
#include "PXR_HMD.h"
#include "Misc/ScopeLock.h"
#include "RenderingThread.h"
#include "Engine/Classes/Kismet//StereoLayerFunctionLibrary.h"
#include "Runtime/HeadMountedDisplay/Public/XRThreadUtils.h"
#include "PXR_HMDFunctionLibrary.h"
#include "PXR_Log.h"

FPicoXRSplash::FPicoXRSplash( FPicoXRHMD* InPicoXRHMD)
	:bInitialized(false)
	,PicoXRHMD(InPicoXRHMD)
	,bTickerStarted(false)
    ,bShown(false)
{
	PXR_LOGI(PxrUnreal, "Splash FPicoXRSplash() Construct!");
}

FPicoXRSplash::~FPicoXRSplash()
{
	UnInitialize();
	check(!Ticker.IsValid());	
}

void FPicoXRSplash::SplashTick_RenderThread(float DeltaTime)
{
	check(IsInRenderingThread())
	const double TimeInSeconds = FPlatformTime::Seconds();
	const double DeltaTimeInSeconds = TimeInSeconds - LastTimeInSeconds;

	if (DeltaTimeInSeconds > 2.f * SystemDisplayInterval && Layers_RenderThread_DeltaRotation.Num() > 0)
	{
		FScopeLock ScopeLock(&RenderThreadLock);
		//TODO:Splash rotation
		LastTimeInSeconds = TimeInSeconds;
	}

	RenderFrame_RenderThread(FRHICommandListExecutor::GetImmediateCommandList());
}

void FPicoXRSplash::Initialize()
{
	check(IsInGameThread());
	if (!bInitialized)
	{
		Frame = PicoXRHMD->MakeNewGameFrame();

		SystemDisplayInterval = 1.0f / UPicoXRHMDFunctionLibrary::PXR_GetCurrentDisplayFrequency();
		LoadSettings();
		bInitialized = true;
	}
}

void FPicoXRSplash::LoadSettings()
{
	PicoSettings = GetMutableDefault<UPicoXRSettings>();
	check(PicoSettings);
	ClearSplashes();
	for(const FPicoSplashDesc& SplashDesc : PicoSettings->SplashDescs)
	{
		if (SplashDesc.TexturePath !=nullptr)
		{
			AddSplash(SplashDesc);
		}
		else
		{
			UE_LOG(LogHMD, Log, TEXT("Pxr_UE FPicoXRSplash::LoadSettings()  the TexturePath is null"));
		}		
	}

	UStereoLayerFunctionLibrary::EnableAutoLoadingSplashScreen(PicoSettings->bSplashScreenAutoShow);
	if (PicoSettings->bSplashScreenAutoShow)
	{
		if (!PostLoadLevelDelegate.IsValid())
		{
			PostLoadLevelDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddSP(this, &FPicoXRSplash::OnPostLoadMap);
		}
	}
	else
	{
		if (PostLoadLevelDelegate.IsValid())
		{
			FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(PostLoadLevelDelegate);
			PostLoadLevelDelegate.Reset();
		}
	}


}

void FPicoXRSplash::UnInitialize()
{
	check(IsInGameThread());
	if (bInitialized)
	{
		ExecuteOnRenderThread([this]()
		{
			if (Ticker)
			{
				Ticker->Unregister();
				Ticker = nullptr;
			}
			ExecuteOnRHIThread([this]()
            {
                SplashLayers.Reset();
            });
		});
		SplashLayersMap.Reset();
		bInitialized = false;
	}
}

void FPicoXRSplash::OnPreLoadMap(const FString&)
{
	if (PicoSettings->bSplashScreenAutoShow)
	{
		PXR_LOGI(PxrUnreal, "Splash OnPreLoadMap!");
		if (!bShown)
		{
			Show();
		}	
	}	
}

void FPicoXRSplash::OnPostLoadMap(UWorld*)
{
	if (!bSplashShouldShow)
	{
		PXR_LOGI(PxrUnreal, "Splash OnPostLoadMap!");
		HideLoadingScreen();
	}
}

void FPicoXRSplash::StartTicker()
{
	check(IsInGameThread());
	if (!Ticker.IsValid())
	{
		Ticker = MakeShareable(new FTicker(this));
		ExecuteOnRenderThread([this]()
        {
			LastTimeInSeconds = FPlatformTime::Seconds();
            Ticker->Register();		
			bTickerStarted = true;
			PXR_LOGI(PxrUnreal, "Splash StartTicker!");
        });	
	}
}

void FPicoXRSplash::StopTicker()
{
	ExecuteOnRenderThread([this]()
	{
		if (Ticker.IsValid())
		{
            Ticker->Unregister();
            Ticker = nullptr;
			bTickerStarted = false;
			bShown = false;
			PXR_LOGI(PxrUnreal, "Splash StopTicker!");
        }
	});	
	ReleaseTextures();
}

void FPicoXRSplash::Show()
{
	check(IsInGameThread());
	ReleaseTextures();
	{
		for (int32 SplashLayerIndex = 0; SplashLayerIndex < SplashLayers.Num(); ++SplashLayerIndex)
		{
			FPicoSplashLayer& SplashLayer =  SplashLayers[SplashLayerIndex];;
			if (SplashLayer.Desc.TexturePath.IsValid())
			{
				LoadTexture(SplashLayer);
			}
			if (SplashLayer.Desc.LoadingTexture && SplashLayer.Desc.LoadingTexture->IsValidLowLevel())
			{
				SplashLayer.Desc.LoadingTexture->UpdateResource();
			}
		}
		FlushRenderingCommands();
	}
	for (int32 SplashLayerIndex = 0; SplashLayerIndex < SplashLayers.Num(); ++SplashLayerIndex)
	{
		FPicoSplashLayer& SplashLayer = SplashLayers[SplashLayerIndex];
		if (SplashLayer.Desc.LoadingTexture->IsValidLowLevel())
		{
			if (SplashLayer.Desc.LoadingTexture->Resource && SplashLayer.Desc.LoadingTexture->Resource->TextureRHI)
			{
				SplashLayer.Desc.LoadedTexture = SplashLayer.Desc.LoadingTexture->Resource->TextureRHI;
			}
			else
			{
				UE_LOG(LogHMD, Log, TEXT("Splash, %s - no Resource"), *SplashLayer.Desc.LoadingTexture->GetDesc());
			}
		}
		
		if (SplashLayer.Desc.LoadedTexture)
		{
			const int32 LayerID = PicoXRHMD->NextLayerId++;
			SplashLayer.Layer = MakeShareable(new FPicoXRStereoLayer(PicoXRHMD,LayerID,StereoLayerDescFromPicoSplashDesc(SplashLayer.Desc)));
		}
		SplashLayer.Layer->bSplashLayer = true;
	}

	SplashLayersMap.Empty( SplashLayers.Num());
	for (int32 SplashLayerIndex = 0; SplashLayerIndex < SplashLayers.Num(); ++SplashLayerIndex)
	{
		SplashLayers[SplashLayerIndex].Layer->MarkCreateLayer();
		SplashLayersMap.Add(SplashLayers[SplashLayerIndex].Layer->GetLayerID(),SplashLayers[SplashLayerIndex].Layer);
	}

	if (SplashLayersMap.Num()>0)
	{
		StartTicker();
		bShown = true;
	}
}

void FPicoXRSplash::Hide()
{
	check(IsInGameThread());
	PXR_LOGI(PxrUnreal, "Splash Hide!");
	bShown = false;
	StopTicker();
}

void FPicoXRSplash::AutoShow(bool AutoShowSplash)
{
	check(IsInGameThread());
	PicoSettings->bSplashScreenAutoShow =AutoShowSplash;
}

void FPicoXRSplash::AddSplash(const FPicoSplashDesc& Desc)
{
	check(IsInGameThread());
	PXR_LOGI(PxrUnreal, "Splash AddSplash!");
	FScopeLock ScopeLock(&RenderThreadLock);
	SplashLayers.Add(FPicoSplashLayer(Desc));
}

void FPicoXRSplash::ShowLoadingScreen()
{
	PXR_LOGI(PxrUnreal, "Splash ShowLoadingScreen!");
	bSplashShouldShow = true;
	bSplashNeedUpdate = true;
}

void FPicoXRSplash::HideLoadingScreen()
{
	PXR_LOGI(PxrUnreal, "Splash HideLoadingScreen!");
	bSplashShouldShow = false;
	bSplashNeedUpdate = bShown;
}

void FPicoXRSplash::ClearSplashes()
{
	check(IsInGameThread());
	FScopeLock ScopeLock(&RenderThreadLock);
	SplashLayers.Reset();
}

void FPicoXRSplash::AddSplash(const FSplashDesc& Splash)
{
	FPicoSplashDesc SplashDesc;
	SplashDesc.TransformInMeters = Splash.Transform;
	SplashDesc.QuadSizeInMeters = Splash.QuadSize;
	SplashDesc.DeltaRotation = Splash.DeltaRotation;
	SplashDesc.bNoAlphaChannel = Splash.bIgnoreAlpha;
	SplashDesc.bIsDynamic = Splash.bIsDynamic || Splash.bIsExternal;
	SplashDesc.TextureOffset = Splash.UVRect.Min;
	SplashDesc.TextureScale = Splash.UVRect.Max;
	SplashDesc.LoadedTexture = Splash.Texture;
	AddSplash(SplashDesc);
}

void FPicoXRSplash::UpdateLoadingScreen_GameThread()
{
	if (bSplashNeedUpdate)
	{
		if (bSplashShouldShow)
		{
			Show();
		}
		else
		{
			Hide();
		}

		bSplashNeedUpdate = false;
	}
}

void FPicoXRSplash::ReleaseTextures()
{
	FScopeLock ScopeLock(&RenderThreadLock);
	for (int32 SplashLayerIndex = 0; SplashLayerIndex < SplashLayers.Num(); ++SplashLayerIndex)
	{
		if (SplashLayers[SplashLayerIndex].Desc.TexturePath.IsValid())
		{
			ReleaseTexture(SplashLayers[SplashLayerIndex]);
		}
	}
}

void FPicoXRSplash::ReleaseTexture(FPicoSplashLayer& InSplashLayer)
{
	check(IsInGameThread());
	InSplashLayer.Desc.LoadingTexture = nullptr;
	InSplashLayer.Desc.LoadedTexture = nullptr;
	InSplashLayer.Layer.Reset();
}

void FPicoXRSplash::LoadTexture(FPicoSplashLayer& InSplashLayer)
{
	check(IsInGameThread());
	if (InSplashLayer.Desc.LoadingTexture && InSplashLayer.Desc.LoadingTexture->IsValidLowLevel())
	{
		InSplashLayer.Desc.LoadingTexture = nullptr;
	}
	InSplashLayer.Desc.LoadedTexture = nullptr;
	InSplashLayer.Layer.Reset();
	InSplashLayer.Desc.LoadingTexture = Cast<UTexture>(InSplashLayer.Desc.TexturePath.TryLoad());
	InSplashLayer.Desc.LoadedTexture = nullptr;
	InSplashLayer.Layer.Reset();
}

void FPicoXRSplash::RenderFrame_RenderThread(FRHICommandListImmediate& RHICmdList)
{
	check(IsInRenderingThread());
	FScopeLock ScopeLock(&RenderThreadLock);
	FPXRGameFramePtr XFrame = Frame->Clone();
	XFrame->FrameNumber = PicoXRHMD->NextFrameIndex;
	XFrame->ShowFlags.Rendering = true;
#if PLATFORM_ANDROID
	if (Pxr_IsRunning() && PicoXRHMD->WaitFrameIndex < XFrame->FrameNumber)
	{
		PXR_LOGV(PxrUnreal, "Splash WaitToBeginFrame %u", XFrame->FrameNumber);
		int CurrentVersion = 0;
		Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
		if (PicoXRHMD->bWaitFrameVersion)
		{
			Pxr_WaitFrame();
		}
		PicoXRHMD->WaitFrameIndex = XFrame->FrameNumber;
		PicoXRHMD->NextFrameIndex = XFrame->FrameNumber + 1;
	}
	else
	{
		XFrame->ShowFlags.Rendering = false;
	}
#endif
	PicoXRHMD->SplashShow(RHICmdList);

	ExecuteOnRHIThread([this,XFrame]()
		{
			if (XFrame->ShowFlags.Rendering)
			{
				PXR_LOGV(PxrUnreal, "Splash BeginFrame %u", XFrame->FrameNumber);
				PicoXRHMD->BeginFrame_RHIThread();
			}
		});
	
	ExecuteOnRHIThread([this, XFrame]()
		{
			if (XFrame->ShowFlags.Rendering)
			{
				PXR_LOGV(PxrUnreal, "Splash EndFrame %u", XFrame->FrameNumber);
				PicoXRHMD->EndFrame_RHIThread();
			}		
		});
}

IStereoLayers::FLayerDesc FPicoXRSplash::StereoLayerDescFromPicoSplashDesc(FPicoSplashDesc PicoDesc)
{
	IStereoLayers::FLayerDesc LayerDesc;
#if ENGINE_MINOR_VERSION > 24
	LayerDesc.SetShape<FQuadLayer>();
#else
	LayerDesc.ShapeType = IStereoLayers::QuadLayer;
#endif
	LayerDesc.Transform = PicoDesc.TransformInMeters;
	LayerDesc.QuadSize = PicoDesc.QuadSizeInMeters;
	LayerDesc.UVRect = FBox2D(PicoDesc.TextureOffset, PicoDesc.TextureOffset + PicoDesc.TextureScale);
	LayerDesc.Priority = INT32_MAX - (int32)(PicoDesc.TransformInMeters.GetTranslation().X * 1000.f);
	LayerDesc.PositionType = IStereoLayers::FaceLocked;
	LayerDesc.Texture = PicoDesc.LoadedTexture;
	LayerDesc.Flags = IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO |
		(PicoDesc.bNoAlphaChannel ? IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL : 0) |
		(PicoDesc.bIsDynamic ? IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE : 0);
	return LayerDesc;
}
