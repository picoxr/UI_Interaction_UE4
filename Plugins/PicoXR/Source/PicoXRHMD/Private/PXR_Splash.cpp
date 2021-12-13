// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "PXR_Splash.h"
#include "PXR_HMD.h"
#include "PXR_Settings.h"
#include "Misc/ScopeLock.h"
#include "RenderingThread.h"
#include "Engine/Classes/Kismet//StereoLayerFunctionLibrary.h"
#include "Runtime/HeadMountedDisplay/Public/XRThreadUtils.h"

FPicoXRSplash::FPicoXRSplash( FPicoXRHMD* InPicoXRHMD)
	:bInitialized(false)
	,bRenderThreadIsRunning(true)
	,bIsShown(false)
	,bAutoShow(false)
	,PicoXRHMD(InPicoXRHMD)
{
	Startup();
}

FPicoXRSplash::~FPicoXRSplash()
{
	Shutdown();
	check(!Ticker.IsValid());	
}

void FPicoXRSplash::Tick_RenderThread(float DeltaTime)
{
	FScopeLock ScopeLock(&RenderThreadLock);
	if (SplashLayersMap.Num()>0)
	{
		ExecuteOnRHIThread([this]()
        {
			PicoXRHMD->BeginFrame_RHIThread();	
        });
		
		PicoXRHMD->SplashShow(FRHICommandListExecutor::GetImmediateCommandList());
		
		ExecuteOnRHIThread([this]()
        {
            PicoXRHMD->EndFrame_RHIThread();
        });
	}
}

void FPicoXRSplash::Startup()
{
	check(IsInGameThread());
	if (!bInitialized)
	{
		LoadSettings();
		bInitialized = true;
	}
}

void FPicoXRSplash::LoadSettings()
{
	UPicoXRSettings* PicoSettings = GetMutableDefault<UPicoXRSettings>();
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
			UE_LOG(LogHMD, Warning, TEXT("Pxr_UE FPicoXRSplash::LoadSettings()  the TexturePath is null"));
		}		
	}
	bAutoShow = PicoSettings->bSplashScreenAutoShow;
}

void FPicoXRSplash::Shutdown()
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
	bRenderThreadIsRunning = false;
	if (bAutoShow)
	{
		if (!bIsShown)
		{
			Show();
		}	
	}	
}

void FPicoXRSplash::OnPostLoadMap(UWorld*)
{
	if (bIsShown)
	{
		Hide();
	}
	bRenderThreadIsRunning = true;
}

void FPicoXRSplash::StartTicker()
{
	check(IsInGameThread());
	if (!Ticker.IsValid())
	{
		Ticker = MakeShareable(new FTicker(this));
		ExecuteOnRenderThread([this]()
        {
            Ticker->Register();		
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
        }
	});	
	UnloadTextures();
}

void FPicoXRSplash::Show()
{
	check(IsInGameThread());
	UnloadTextures();
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
				UE_LOG(LogHMD, Warning, TEXT("Splash, %s - no Resource"), *SplashLayer.Desc.LoadingTexture->GetDesc());
			}
		}
		
		if (SplashLayer.Desc.LoadedTexture)
		{
			const int32 LayerID = PicoXRHMD->CurrentLayerId++;
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
	if (!bRenderThreadIsRunning)
	{
		StartTicker();
	}
	bIsShown = true;
}

void FPicoXRSplash::Hide()
{
	check(IsInGameThread());
	bIsShown = false;
	for (auto Layer: SplashLayersMap)
	{
		Layer.Value->MarkDestroyLayer();
	}
	if (!bRenderThreadIsRunning)
	{
		StopTicker();
	}

}

void FPicoXRSplash::AutoShow(bool AutoShowSplash)
{
	check(IsInGameThread());
	bAutoShow=AutoShowSplash;
	GetMutableDefault<UPicoXRSettings>()->bSplashScreenAutoShow = AutoShowSplash;
	UStereoLayerFunctionLibrary::EnableAutoLoadingSplashScreen(AutoShowSplash);
}

void FPicoXRSplash::AddSplash(const FPicoSplashDesc& Desc)
{
	check(IsInGameThread());
	FScopeLock ScopeLock(&RenderThreadLock);
	SplashLayers.Add(FPicoSplashLayer(Desc));
}

void FPicoXRSplash::ShowLoadingScreen()
{
	if (!bIsShown)
	{
		Show();
	}
}

void FPicoXRSplash::HideLoadingScreen()
{
	if (bIsShown)
	{
		Hide();
	}
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

void FPicoXRSplash::UnloadTextures()
{
	FScopeLock ScopeLock(&RenderThreadLock);
	for (int32 SplashLayerIndex = 0; SplashLayerIndex < SplashLayers.Num(); ++SplashLayerIndex)
	{
		if (SplashLayers[SplashLayerIndex].Desc.TexturePath.IsValid())
		{
			UnloadTexture(SplashLayers[SplashLayerIndex]);
		}
	}
}

void FPicoXRSplash::UnloadTexture(FPicoSplashLayer& InSplashLayer)
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
	LayerDesc.Flags = IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO | IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL | IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
	return LayerDesc;
}
