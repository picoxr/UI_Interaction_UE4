//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Splash.h"
#include "PXR_HMD.h"
#include "Misc/ScopeLock.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Runtime/HeadMountedDisplay/Public/XRThreadUtils.h"
#include "PXR_Log.h"

FPXRSplash::FPXRSplash(FPICOXRHMD* InPICOXRHMD)
	: SplashTicker(nullptr)
	, bInitialized(false)
	, PICOXRHMD(InPICOXRHMD)
	, CustomRenderBridge(InPICOXRHMD->GetCustomRenderBridge())
	, PICOSettings(nullptr)
	, PXRFrame(nullptr)
	, bIsShown(false)
	, bSplashNeedUpdateActiveState(false)
	, bSplashShouldToShow(false)
	, FramesOutstanding(0)
{
	AddedPXRSplashLayers.Reset();
	PXRLayers_RenderThread_Entry.Reset();
	PXRLayers_RenderThread.Reset();
	PXRLayers_RHIThread.Reset();

	{
		IStereoLayers::FLayerDesc LayerDesc;
		LayerDesc.QuadSize = FVector2D(0.01f, 0.01f);
		LayerDesc.Priority = 0;
		LayerDesc.PositionType = IStereoLayers::TrackerLocked;
		LayerDesc.Texture = GBlackTexture->TextureRHI;
		BlackLayer = MakeShareable(new FPICOXRStereoLayer(InPICOXRHMD, InPICOXRHMD->NextLayerId++, LayerDesc));
		BlackLayer->bSplashLayer = true;
		BlackLayer->bSplashBlackProjectionLayer = true;
		uint32 SizeX = 1;
		uint32 SizeY = 1;
		if (LayerDesc.Texture.IsValid())
		{
			FRHITexture2D* Texture2D = LayerDesc.Texture->GetTexture2D();
			if (Texture2D)
			{
				SizeX = Texture2D->GetSizeX();
				SizeY = Texture2D->GetSizeY();
			}
		}
		BlackLayer->SetProjectionLayerParams(SizeX, SizeY, InPICOXRHMD->IsMultiviewEnable() ? 2 : 1, 1, 1, InPICOXRHMD->GetRHIString());
	}

	PXR_LOGI(PxrUnreal, "Splash FPXRSplash() Construct!");
}

FPXRSplash::~FPXRSplash()
{
	check(!SplashTicker.IsValid());
	PXR_LOGI(PxrUnreal, "Splash FPXRSplash() Destruct!");
}

void FPXRSplash::ShowLoadingScreen()
{
	PXR_LOGI(PxrUnreal, "Splash ShowLoadingScreen!");
	bSplashShouldToShow = true;
	bSplashNeedUpdateActiveState = !bIsShown;
}

void FPXRSplash::HideLoadingScreen()
{
	PXR_LOGI(PxrUnreal, "Splash HideLoadingScreen!");
	bSplashShouldToShow = false;
	bSplashNeedUpdateActiveState = bIsShown;
}

void FPXRSplash::ClearSplashes()
{
	check(IsInGameThread());
	FScopeLock ScopeLock(&RenderThreadLock);
	AddedPXRSplashLayers.Reset();
}

void FPXRSplash::AddSplash(const FSplashDesc& InSplashDesc)
{
	FPXRSplashDesc PXRSplashDesc;
	PXRSplashDesc.SplashTransform = InSplashDesc.Transform;
	PXRSplashDesc.SplashQuadSize = InSplashDesc.QuadSize;
	PXRSplashDesc.bNoAlpha = InSplashDesc.bIgnoreAlpha;
	PXRSplashDesc.bIsLiveUpdate = InSplashDesc.bIsDynamic || InSplashDesc.bIsExternal;
	PXRSplashDesc.SplashTextureOffset = InSplashDesc.UVRect.Min;
	PXRSplashDesc.SplashTextureScale = InSplashDesc.UVRect.Max;
	PXRSplashDesc.LoadedTextureRef = InSplashDesc.Texture;
	AddPXRSplashLayers(PXRSplashDesc);
}

void FPXRSplash::InitSplash()
{
	check(IsInGameThread());
	if (!bInitialized)
	{
		PXRFrame = PICOXRHMD->MakeNewGameFrame();
		AddSplashFromPXRSettings();
		bInitialized = true;
	}
}

void FPXRSplash::ShutDownSplash()
{
	check(IsInGameThread());

	if (bInitialized)
	{
		ExecuteOnRenderThread([this]()
			{
				if (SplashTicker)
				{
					SplashTicker->Unregister();
					SplashTicker = nullptr;
				}

				ExecuteOnRHIThread([this]()
					{
						AddedPXRSplashLayers.Reset();
						PXRLayers_RenderThread_Entry.Reset();
						PXRLayers_RenderThread.Reset();
						PXRLayers_RHIThread.Reset();
					});
			});

		if (PostLoadLevelDelegate.IsValid())
		{
			FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(PostLoadLevelDelegate);
			PostLoadLevelDelegate.Reset();
		}

		bInitialized = false;
	}
}

void FPXRSplash::SplashTick_RenderThread(float DeltaTime)
{
	check(IsInRenderingThread());

#if PLATFORM_ANDROID
	if (!Pxr_IsRunning())
	{
		PXR_LOGV(PxrUnreal, "Splash Pxr_IsRunning == false!");
		return;
	}
#endif

	if (FramesOutstanding > 0)
	{
		PXR_LOGV(PxrUnreal, "Splash skipping frame; too many frames outstanding");
		return;
	}

	RenderSplashFrame_RenderThread(FRHICommandListExecutor::GetImmediateCommandList());
}

void FPXRSplash::AddSplashFromPXRSettings()
{
	PICOSettings = GetMutableDefault<UPICOXRSettings>();
	check(PICOSettings);
	ClearSplashes();
	for (const FPXRSplashDesc& SplashDesc : PICOSettings->SplashDescs)
	{
		if (SplashDesc.SplashTexturePath.IsValid())
		{
			AddPXRSplashLayers(SplashDesc);
		}
		else
		{
			PXR_LOGI(PxrUnreal, "Splash AddSplashFromPXRSettings() the TexturePath is null!");
		}
	}

	if (!PostLoadLevelDelegate.IsValid())
	{
		PostLoadLevelDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddSP(this, &FPXRSplash::OnPostLoadMap);
	}
}

void FPXRSplash::OnPreLoadMap(const FString& MapName)
{
	if (PICOSettings->bSplashScreenAutoShow)
	{
		PXR_LOGI(PxrUnreal, "Splash OnPreLoadMap:%s", PLATFORM_CHAR(*MapName));
		if (!bIsShown)
		{
			ToShow();
		}
	}
}

void FPXRSplash::OnPostLoadMap(UWorld*)
{
	if (PICOSettings->bSplashScreenAutoShow)
	{
		PXR_LOGI(PxrUnreal, "Splash OnPostLoadMap!");
		if (!bSplashShouldToShow)
		{
			HideLoadingScreen();
		}
	}
}

void FPXRSplash::BeginTicker()
{
	check(IsInGameThread());
	if (!SplashTicker.IsValid())
	{
		SplashTicker = MakeShareable(new FSplashTicker_RenderThread(this));
		ExecuteOnRenderThread([this]()
			{
				SplashTicker->Register();
				PXR_LOGI(PxrUnreal, "Splash StartTicker!");
			});
	}
}

void FPXRSplash::EndTicker()
{
	ExecuteOnRenderThread([this]()
		{
			if (SplashTicker.IsValid())
			{
				SplashTicker->Unregister();
				SplashTicker = nullptr;
				PXR_LOGI(PxrUnreal, "Splash StopTicker!");
			}
		});
}

void FPXRSplash::ToShow()
{
	check(IsInGameThread());
	ReleaseAllTextures();

	for (int32 i = 0; i < AddedPXRSplashLayers.Num(); ++i)
	{
		FPXRSplashLayer& SplashLayer = AddedPXRSplashLayers[i];
		if (SplashLayer.Desc.SplashTexturePath.IsValid())
		{
			LoadTexture(SplashLayer);
		}
		if (SplashLayer.Desc.LoadingTextureFromPath && SplashLayer.Desc.LoadingTextureFromPath->IsValidLowLevel())
		{
			SplashLayer.Desc.LoadingTextureFromPath->UpdateResource();
		}
	}
	FlushRenderingCommands();

	for (int32 i = 0; i < AddedPXRSplashLayers.Num(); ++i)
	{
		FPXRSplashLayer& SplashLayer = AddedPXRSplashLayers[i];
		if (SplashLayer.Desc.LoadingTextureFromPath->IsValidLowLevel())
		{
			if (SplashLayer.Desc.LoadingTextureFromPath->Resource && SplashLayer.Desc.LoadingTextureFromPath->Resource->TextureRHI)
			{
				SplashLayer.Desc.LoadedTextureRef = SplashLayer.Desc.LoadingTextureFromPath->Resource->TextureRHI;
			}
			else
			{
				PXR_LOGI(PxrUnreal, "Splash %s - no Resource!", PLATFORM_CHAR(*SplashLayer.Desc.LoadingTextureFromPath->GetDesc()));
			}
		}

		if (SplashLayer.Desc.LoadedTextureRef)
		{
			const int32 PXRLayerID = PICOXRHMD->NextLayerId++;
			SplashLayer.Layer = MakeShareable(new FPICOXRStereoLayer(PICOXRHMD, PXRLayerID, CreateStereoLayerDescFromPXRSplashDesc(SplashLayer.Desc)));
			SplashLayer.Layer->bSplashLayer = true;
		}
	}

	{
		FScopeLock ScopeLock(&RenderThreadLock);
		PXRLayers_RenderThread_Entry.Reset();
		for (int32 i = 0; i < AddedPXRSplashLayers.Num(); i++)
		{
			const FPXRSplashLayer& SplashLayer = AddedPXRSplashLayers[i];

			if (SplashLayer.Layer.IsValid())
			{
				FPICOLayerPtr ClonedLayer = SplashLayer.Layer->CloneMyself();
				PXRLayers_RenderThread_Entry.Add(ClonedLayer);
			}
		}
		if (PXRLayers_RenderThread_Entry.Num() > 0)
		{
			PXRLayers_RenderThread_Entry.Add(BlackLayer->CloneMyself());
		}
		PXRLayers_RenderThread_Entry.Sort(FPICOLayerPtr_SortById());
	}

	if (PXRLayers_RenderThread_Entry.Num() > 0)
	{
		BeginTicker();
		bIsShown = true;
	}
	else
	{
		PXR_LOGI(PxrUnreal, "No splash layers show!");
	}
}

void FPXRSplash::ToHide()
{
	check(IsInGameThread());
	PXR_LOGI(PxrUnreal, "Splash Hide!");
	bIsShown = false;
	EndTicker();
	ReleaseAllTextures();
}

void FPXRSplash::AutoShow(bool AutoShowSplash)
{
	check(IsInGameThread());
	PICOSettings->bSplashScreenAutoShow = AutoShowSplash;
}

void FPXRSplash::AddPXRSplashLayers(const FPXRSplashDesc& Desc)
{
	check(IsInGameThread());
	PXR_LOGI(PxrUnreal, "Splash AddSplash!");
	FScopeLock ScopeLock(&RenderThreadLock);
	AddedPXRSplashLayers.Add(FPXRSplashLayer(Desc));
}

void FPXRSplash::SwitchActiveSplash_GameThread()
{
	if (bSplashNeedUpdateActiveState)
	{
		if (bSplashShouldToShow)
		{
			if (!bIsShown)
			{
				ToShow();
			}
		}
		else
		{
			if (bIsShown)
			{
				ToHide();
			}
		}
		bSplashNeedUpdateActiveState = false;
	}
}

void FPXRSplash::ReleaseAllTextures()
{
	FScopeLock ScopeLock(&RenderThreadLock);
	for (int32 i = 0; i < AddedPXRSplashLayers.Num(); ++i)
	{
		if (AddedPXRSplashLayers[i].Desc.SplashTexturePath.IsValid())
		{
			ReleaseTexture(AddedPXRSplashLayers[i]);
		}
	}
}

void FPXRSplash::ReleaseTexture(FPXRSplashLayer& InSplashLayer)
{
	check(IsInGameThread());
	InSplashLayer.Desc.LoadingTextureFromPath = nullptr;
	InSplashLayer.Desc.LoadedTextureRef = nullptr;
	InSplashLayer.Layer.Reset();
}

void FPXRSplash::LoadTexture(FPXRSplashLayer& InSplashLayer)
{
	check(IsInGameThread());
	ReleaseTexture(InSplashLayer);
	InSplashLayer.Desc.LoadingTextureFromPath = Cast<UTexture>(InSplashLayer.Desc.SplashTexturePath.TryLoad());
	InSplashLayer.Desc.LoadedTextureRef = nullptr;
	InSplashLayer.Layer.Reset();
}

void FPXRSplash::RenderSplashFrame_RenderThread(FRHICommandListImmediate& RHICmdList)
{
	check(IsInRenderingThread());
	FScopeLock ScopeLock(&RenderThreadLock);
	FPXRGameFramePtr SplashFrame = PXRFrame->CloneMyself();
	SplashFrame->FrameNumber = PICOXRHMD->NextGameFrameNumber;
	SplashFrame->predictedDisplayTimeMs = PICOXRHMD->CurrentFramePredictedTime + 1000.0f / PICOXRHMD->DisplayRefreshRate;
	SplashFrame->ShowFlags.Rendering = true;
	TArray<FPICOLayerPtr> SplashEntryLayers = PXRLayers_RenderThread_Entry;
#if PLATFORM_ANDROID
	if (Pxr_IsRunning() && PICOXRHMD->WaitedFrameNumber < SplashFrame->FrameNumber)
	{
		PXR_LOGV(PxrUnreal, "Splash WaitToBeginFrame %u", SplashFrame->FrameNumber);
		if (PICOXRHMD->bWaitFrameVersion)
		{
			Pxr_WaitFrame();
			Pxr_GetPredictedDisplayTime(&(PICOXRHMD->CurrentFramePredictedTime));
			PXR_LOGV(PxrUnreal, "Splash Pxr_GetPredictedDisplayTime after Pxr_WaitFrame:%f", PICOXRHMD->CurrentFramePredictedTime);
		}
		PICOXRHMD->WaitedFrameNumber = SplashFrame->FrameNumber;
		PICOXRHMD->NextGameFrameNumber = SplashFrame->FrameNumber + 1;
		FPlatformAtomics::InterlockedIncrement(&FramesOutstanding);
	}
	else
	{
		SplashFrame->ShowFlags.Rendering = false;
	}
#endif

	if (SplashFrame->ShowFlags.Rendering)
	{
		PICOXRHMD->UpdateSensorValue(SplashFrame.Get());
	}

	{
		int32 EntryLayer_i = 0;
		int32 Layer_j_RenderThread = 0;

		while (EntryLayer_i < SplashEntryLayers.Num() && Layer_j_RenderThread < PXRLayers_RenderThread.Num())
		{
			uint32 LayerIdX = SplashEntryLayers[EntryLayer_i]->GetID();
			uint32 LayerIdY = PXRLayers_RenderThread[Layer_j_RenderThread]->GetID();

			if (LayerIdX < LayerIdY)
			{
				SplashEntryLayers[EntryLayer_i++]->InitPXRLayer_RenderThread(CustomRenderBridge, &PICOXRHMD->DelayDeletion, RHICmdList);
			}
			else if (LayerIdX > LayerIdY)
			{
				PICOXRHMD->DelayDeletion.AddLayerToDeferredDeletionQueue(PXRLayers_RenderThread[Layer_j_RenderThread++]);
			}
			else
			{
				SplashEntryLayers[EntryLayer_i++]->InitPXRLayer_RenderThread(CustomRenderBridge, &PICOXRHMD->DelayDeletion, RHICmdList, PXRLayers_RenderThread[Layer_j_RenderThread++].Get());
			}
		}

		while (EntryLayer_i < SplashEntryLayers.Num())
		{
			SplashEntryLayers[EntryLayer_i++]->InitPXRLayer_RenderThread(CustomRenderBridge, &PICOXRHMD->DelayDeletion, RHICmdList);
		}

		while (Layer_j_RenderThread < PXRLayers_RenderThread.Num())
		{
			PICOXRHMD->DelayDeletion.AddLayerToDeferredDeletionQueue(PXRLayers_RenderThread[Layer_j_RenderThread++]);
		}
	}

	PXRLayers_RenderThread = SplashEntryLayers;

	for (auto Splash : PXRLayers_RenderThread)
	{
		if (!Splash->bSplashBlackProjectionLayer)
		{
			Splash->PXRLayersCopy_RenderThread(CustomRenderBridge, RHICmdList);
		}
	}

	CustomRenderBridge->SubmitGPUCommands_RenderThread(RHICmdList);

	for (int32 i = 0; i < SplashEntryLayers.Num(); i++)
	{
		SplashEntryLayers[i] = SplashEntryLayers[i]->CloneMyself();
	}

	ExecuteOnRHIThread_DoNotWait([this, SplashFrame, SplashEntryLayers]()
		{
			PXRLayers_RHIThread = SplashEntryLayers;
			if (SplashFrame->ShowFlags.Rendering)
			{
				PXR_LOGV(PxrUnreal, "Splash BeginFrame %u", SplashFrame->FrameNumber);
#if PLATFORM_ANDROID
				if (Pxr_IsRunning())
				{
					Pxr_BeginFrame();
					if (!PICOXRHMD->bWaitFrameVersion)
					{
						Pxr_GetPredictedDisplayTime(&(PICOXRHMD->CurrentFramePredictedTime));
						PXR_LOGV(PxrUnreal, "Splash Pxr_GetPredictedDisplayTime after Pxr_BeginFrame:%f", PICOXRHMD->CurrentFramePredictedTime);
					}
					for (int32 LayerIndex = 0; LayerIndex < PXRLayers_RHIThread.Num(); LayerIndex++)
					{
						PXRLayers_RHIThread[LayerIndex]->IncrementSwapChainIndex_RHIThread(CustomRenderBridge);
					}
				}
				else
				{
					PXR_LOGE(PxrUnreal, "Splash Pxr Is Not Running!!!");
				}
#endif
				FPlatformAtomics::InterlockedDecrement(&FramesOutstanding);
			}

			PXRLayers_RHIThread.Sort(FPICOLayerPtr_SortByPriority());

			if (SplashFrame->ShowFlags.Rendering)
			{
				PXR_LOGV(PxrUnreal, "Splash EndFrame %u", SplashFrame->FrameNumber);
#if PLATFORM_ANDROID
				if (Pxr_IsRunning())
				{
					for (int32 LayerIndex = 0; LayerIndex < PXRLayers_RHIThread.Num(); LayerIndex++)
					{
						PXRLayers_RHIThread[LayerIndex]->SubmitLayer_RHIThread(SplashFrame.Get());
					}
					Pxr_EndFrame();
				}
				else
				{
					PXR_LOGE(PxrUnreal, "Splash Pxr Is Not Running!!!");
				}
#endif
			}
		});
}

IStereoLayers::FLayerDesc FPXRSplash::CreateStereoLayerDescFromPXRSplashDesc(FPXRSplashDesc PXRSplashDesc)
{
	IStereoLayers::FLayerDesc LayerDesc;
	if (PXRSplashDesc.LoadedTextureRef->GetTextureCube() != nullptr)
	{
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >= 25
		LayerDesc.SetShape<FCubemapLayer>();
#else
		LayerDesc.ShapeType = IStereoLayers::CubemapLayer;
#endif
	}
	else
	{
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >= 25
		LayerDesc.SetShape<FQuadLayer>();
#else
		LayerDesc.ShapeType = IStereoLayers::QuadLayer;
#endif
	}

	LayerDesc.Transform = PXRSplashDesc.SplashTransform;
	LayerDesc.QuadSize = PXRSplashDesc.SplashQuadSize;
	LayerDesc.UVRect = FBox2D(PXRSplashDesc.SplashTextureOffset, PXRSplashDesc.SplashTextureOffset + PXRSplashDesc.SplashTextureScale);
	LayerDesc.Priority = INT32_MAX - (int32)(PXRSplashDesc.SplashTransform.GetTranslation().X * 1000.f);
	LayerDesc.PositionType = IStereoLayers::TrackerLocked;
	LayerDesc.Texture = PXRSplashDesc.LoadedTextureRef;
	LayerDesc.Flags = IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO |
		(PXRSplashDesc.bNoAlpha ? IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL : 0) |
		(PXRSplashDesc.bIsLiveUpdate ? IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE : 0);
	return LayerDesc;
}
