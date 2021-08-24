// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoVRSplash.h"
#include "PicoMobile.h"
#include "PicoImport.h"
#include "PicoMobileSettings.h"
#include "Engine/Classes/Kismet/StereoLayerFunctionLibrary.h"
#include "RenderingThread.h"
#include "Misc/ScopeLock.h"
#include "Runtime/HeadMountedDisplay/Public/XRThreadUtils.h"

FPicoVRSplash::FPicoVRSplash(class FPicoMobileHMD* InPicoVRHMD)
	:bInitialized(false),
	bIsShown(false),
	bAutoShow(false),
	isFirstLoadMap(true),
	PicoVRHMD(InPicoVRHMD)
{
}

FPicoVRSplash::~FPicoVRSplash()
{
	if (PreLoadLevelDelegate.IsValid())
	{
		FCoreUObjectDelegates::PreLoadMap.Remove(PreLoadLevelDelegate);
		PreLoadLevelDelegate.Reset();
	}
	if (PostLoadLevelDelegate.IsValid())
	{
		FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(PostLoadLevelDelegate);
		PostLoadLevelDelegate.Reset();
	}
	check(!Ticker.IsValid());
}

FPicoSplashDesc FPicoVRSplash::GetSplashLayerDec()
{
	return SplashLayer_Source.Desc;
}

void FPicoVRSplash::SetSplashLayerDec(FPicoSplashDesc newDec)
{
	SplashLayer_Source.Desc = newDec;
}

FPicoVRStereoLayerPtr FPicoVRSplash::GetSplashLayerPtr()
{
	return SplashLayer_Source.Layer;
}

void FPicoVRSplash::Tick_RenderThread(float DeltaTime)
{	
	FScopeLock ScopeLock(&RenderThreadLock);
#if PLATFORM_ANDROID
	if (bAutoShow && SplashLayer_Source.Layer)
	{
		FPicoVRStereoLayerPtr Xlayer = SplashLayer_Source.Layer->Clone();
		bool isFixOverlay = false;
		GLuint RTId = Xlayer->GetRTexID();
		FQuat CamRotation = PicoSDK::Sensor::GCurrentPoseRT.Orientation;
		FVector CamLocation = PicoSDK::Sensor::GCurrentPoseRT.Position;
		FMatrix mMVMatrix = Xlayer->GetLayerMV(CamRotation, CamLocation, isFixOverlay);
		float mMVFloat[16];
		int l = 0;
		for (int32 i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mMVFloat[l] = mMVMatrix.M[i][j];
				l++;
			}
		}

		float translationM[3] = { SplashLayer_Source.Desc.TransformInMeters.GetLocation().X ,
                                SplashLayer_Source.Desc.TransformInMeters.GetLocation().Y ,
                                SplashLayer_Source.Desc.TransformInMeters.GetLocation().Z
        };

	
		float rotationM[4] = {	SplashLayer_Source.Desc.TransformInMeters.GetRotation().X ,
                                SplashLayer_Source.Desc.TransformInMeters.GetRotation().Y ,
                                SplashLayer_Source.Desc.TransformInMeters.GetRotation().Z ,
                                SplashLayer_Source.Desc.TransformInMeters.GetRotation().W 
                            };
	
		float scaleM[3] = { SplashLayer_Source.Desc.TransformInMeters.GetScale3D().X ,
                                SplashLayer_Source.Desc.TransformInMeters.GetScale3D().Y ,
                                SplashLayer_Source.Desc.TransformInMeters.GetScale3D().Z
        };

		float rotationC[4] = { CamRotation.X,CamRotation.Y,CamRotation.Z,CamRotation.W };
		float translationC[3] = { CamLocation.X,CamLocation.Y,CamLocation.Z };
		float colorScaleOffset[8] = { 1.0f,1.0f,1.0f,1.0f,0,0,0,0 };
		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, RTId, 1, 14, true, 0, mMVFloat, translationM, rotationM, scaleM, rotationC, translationC, colorScaleOffset);
		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, RTId, 0, 14, true, 0, mMVFloat, translationM, rotationM, scaleM, rotationC, translationC, colorScaleOffset);
	}
	ExecuteOnRHIThread([this]()
	{
		PicoVRHMD->SplashScreenRendering();
	});
#endif
}

void FPicoVRSplash::Startup()
{
	CheckInGameThread();
	if (!bInitialized)
	{
		LoadSettings();
		bInitialized = true;
	}
}

void FPicoVRSplash::LoadSettings()
{
	UPicoMobileSettings* PicoSettings = GetMutableDefault<UPicoMobileSettings>();
	check(PicoSettings);

	SplashLayer_Source.Desc = PicoSettings->SplashDescs;
	bAutoShow = PicoSettings->bEnableAutoShow;
	UStereoLayerFunctionLibrary::EnableAutoLoadingSplashScreen(bAutoShow);
	PreLoadLevelDelegate = FCoreUObjectDelegates::PreLoadMap.AddSP(this, &FPicoVRSplash::OnPreLoadMap);
	PostLoadLevelDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddSP(this, &FPicoVRSplash::OnPostLoadMap);
}

void FPicoVRSplash::Shutdown()
{
	CheckInGameThread();

	if (bInitialized)
	{
		ExecuteOnRenderThread([this]()
		{
			if (Ticker)
			{
				Ticker->Unregister();
				Ticker = nullptr;
			}
		});

		bInitialized = false;
	}
}

void FPicoVRSplash::OnPreLoadMap(const FString&)
{
	if (!isFirstLoadMap)
	{
		if (bAutoShow)
		{
			Show();
		}
		bIsShown = true;
		StartTicker();
	}
}

void FPicoVRSplash::OnPostLoadMap(UWorld*)
{
#if PLATFORM_ANDROID
	PicoSDK::GIsMapPost = true;
#endif
	if (bIsShown)
	{
		Hide();
	}
	bIsShown = false;
	StopTicker();

}

void FPicoVRSplash::StopTicker()
{
	CheckInGameThread();
	if (!bIsShown)
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
}

void FPicoVRSplash::StartTicker()
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

void FPicoVRSplash::Show()
{
	if (!IsInGameThread())
	{
		return;
	}

	UnloadTextures();
	{
		FPicoSplashLayer& SplashLayer = SplashLayer_Source;
		if (SplashLayer_Source.Desc.TexturePath.IsValid())
		{
			// load temporary texture (if TexturePath was specified)
			LoadTexture(SplashLayer_Source);
		}
		if (SplashLayer_Source.Desc.LoadingTexture && SplashLayer_Source.Desc.LoadingTexture->IsValidLowLevel())
		{
			SplashLayer_Source.Desc.LoadingTexture->UpdateResource();
		}
		FlushRenderingCommands();
	}
	
	{
		//@DBG BEGIN
		if (SplashLayer_Source.Desc.LoadingTexture->IsValidLowLevel())
		{
			if (SplashLayer_Source.Desc.LoadingTexture->Resource && SplashLayer_Source.Desc.LoadingTexture->Resource->TextureRHI)
			{
				SplashLayer_Source.Desc.LoadedTexture = SplashLayer_Source.Desc.LoadingTexture->Resource->TextureRHI;
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Pvr_UE Splash, %s - no Resource"), *SplashLayer_Source.Desc.LoadingTexture->GetDesc());
			}
		}
		//@DBG END

		if (SplashLayer_Source.Desc.LoadedTexture)
		{
			SplashLayer_Source.Layer = MakeShareable(new FPicoVRStereoLayer(0, StereoLayerDescFromPicoSplashDesc(SplashLayer_Source.Desc)));
		}		
	}
	
}

void FPicoVRSplash::Hide()
{
	CheckInGameThread();
}

void FPicoVRSplash::SetAutoShow(bool bInAuto)
{
	bAutoShow = bInAuto;
}

void FPicoVRSplash::SetisFirstLoadMap(bool newValue)
{
	isFirstLoadMap = newValue;
}

bool FPicoVRSplash::IsFirstLoadMap()
{
	return isFirstLoadMap;
}

void FPicoVRSplash::ClearSplashScreen()
{
	UnloadTextures();
	SplashLayer_Source.Desc.TexturePath = nullptr;
}

void FPicoVRSplash::UnloadTextures()
{
	CheckInGameThread();

	// unload temporary loaded textures
	FScopeLock ScopeLock(&RenderThreadLock);
	if (SplashLayer_Source.Desc.TexturePath.IsValid())
	{
		SplashLayer_Source.Desc.LoadingTexture = nullptr;
		SplashLayer_Source.Desc.LoadedTexture = nullptr;
		SplashLayer_Source.Layer.Reset();
	}
}

void FPicoVRSplash::LoadTexture(FPicoSplashLayer& InSplashLayer)
{
	CheckInGameThread();

	if (InSplashLayer.Desc.LoadingTexture && InSplashLayer.Desc.LoadingTexture->IsValidLowLevel())
	{
		InSplashLayer.Desc.LoadingTexture = nullptr;
	}

	InSplashLayer.Desc.LoadedTexture = nullptr;
	InSplashLayer.Layer.Reset();

	UE_LOG(LogTemp, Log, TEXT("Pvr_UE Loading texture for splash %s..."), *InSplashLayer.Desc.TexturePath.GetAssetName());
	InSplashLayer.Desc.LoadingTexture = Cast<UTexture>(InSplashLayer.Desc.TexturePath.TryLoad());
	if (InSplashLayer.Desc.LoadingTexture != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Pvr_UE ...Success. "));
	}
	InSplashLayer.Desc.LoadedTexture = nullptr;
	InSplashLayer.Layer.Reset();
}

IStereoLayers::FLayerDesc FPicoVRSplash::StereoLayerDescFromPicoSplashDesc(FPicoSplashDesc PicoDesc)
{
	bool bIsCubemap = PicoDesc.LoadedTexture->GetTextureCube() != nullptr;
	IStereoLayers::FLayerDesc LayerDesc;
#if ENGINE_MINOR_VERSION > 24 
	if (bIsCubemap)
	{
		LayerDesc.SetShape<FCubemapLayer>();
	}
#else
	LayerDesc.ShapeType = bIsCubemap ? IStereoLayers::CubemapLayer : IStereoLayers::QuadLayer;
#endif
	LayerDesc.Transform = PicoDesc.TransformInMeters;
	LayerDesc.QuadSize = PicoDesc.QuadSizeInMeters;
	LayerDesc.UVRect = FBox2D(PicoDesc.TextureOffset, PicoDesc.TextureOffset + PicoDesc.TextureScale);
	LayerDesc.Priority = INT32_MAX - (int32)(PicoDesc.TransformInMeters.GetTranslation().X * 1000.f);
	LayerDesc.PositionType = IStereoLayers::FaceLocked;
	LayerDesc.Texture = PicoDesc.LoadedTexture;
	LayerDesc.Flags = IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO | (/*PicoDesc.bNoAlphaChannel*/true ? IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL : 0) | (PicoDesc.bIsDynamic ? IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE : 0);
	return LayerDesc;
}
