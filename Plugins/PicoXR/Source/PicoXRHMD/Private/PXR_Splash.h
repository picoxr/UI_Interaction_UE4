//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "IXRLoadingScreen.h"
#include "TickableObjectRenderThread.h"
#include "PXR_StereoLayer.h"
#include "PXR_HMDTypes.h"
#include "PXR_Settings.h"
#include "PXR_GameFrame.h"

struct FPXRSplashLayer
{
	FPXRSplashDesc Desc;
	FPICOLayerPtr Layer;

public:
	FPXRSplashLayer(const FPXRSplashDesc& InSplashDesc) : Desc(InSplashDesc) {}
	FPXRSplashLayer(const FPXRSplashLayer& InSplashLayer) : Desc(InSplashLayer.Desc), Layer(InSplashLayer.Layer) {}
};

class FPXRSplash : public IXRLoadingScreen, public TSharedFromThis<FPXRSplash>
{
protected:
	class FSplashTicker_RenderThread : public FTickableObjectRenderThread, public TSharedFromThis<FSplashTicker_RenderThread>
	{
	public:
		FSplashTicker_RenderThread(FPXRSplash* InSplash) : FTickableObjectRenderThread(false, true), PXRSplash(InSplash) {}

		virtual void Tick(float DeltaTime) override
		{
			PXRSplash->SplashTick_RenderThread(DeltaTime);
		}
		virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FPXRSplash, STATGROUP_Tickables); }
		virtual bool IsTickable() const override { return true; }

	protected:
		FPXRSplash* PXRSplash;
	};

public:
	FPXRSplash(FPICOXRHMD* InPICOXRHMD);
	virtual ~FPXRSplash();
	virtual void ShowLoadingScreen() override;
	virtual void HideLoadingScreen() override;
	virtual void ClearSplashes() override;
	virtual void AddSplash(const FSplashDesc& InSplashDesc) override;
	virtual bool IsShown() const override { return bIsShown; }

	void InitSplash();
	void ShutDownSplash();

	void OnPreLoadMap(const FString& MapName);
	void AutoShow(bool AutoShowSplash);
	void AddPXRSplashLayers(const FPXRSplashDesc& Splash);
	void SwitchActiveSplash_GameThread();
	TArray<FPICOLayerPtr> PXRLayers_RHIThread;
	FPICOLayerPtr BlackLayer;

protected:
	void SplashTick_RenderThread(float DeltaTime);
	void AddSplashFromPXRSettings();
	void OnPostLoadMap(UWorld*);
	void BeginTicker();
	void EndTicker();
	void ToShow();
	void ToHide();
	void ReleaseAllTextures();
	void ReleaseTexture(FPXRSplashLayer& InSplashLayer);
	void LoadTexture(FPXRSplashLayer& InSplashLayer);
	void RenderSplashFrame_RenderThread(FRHICommandListImmediate& RHICmdList);
	IStereoLayers::FLayerDesc CreateStereoLayerDescFromPXRSplashDesc(FPXRSplashDesc PXRSplashDesc);

	TSharedPtr<FSplashTicker_RenderThread> SplashTicker;
	FCriticalSection RenderThreadLock;
	bool bInitialized;
	FPICOXRHMD* PICOXRHMD;
	FPICOXRRenderBridge* CustomRenderBridge;
	FDelegateHandle PostLoadLevelDelegate;
	UPICOXRSettings* PICOSettings;
	FPXRGameFramePtr PXRFrame;
	bool bIsShown;
	bool bSplashNeedUpdateActiveState;
	bool bSplashShouldToShow;

	TArray<FPXRSplashLayer> AddedPXRSplashLayers;
	TArray<FPICOLayerPtr> PXRLayers_RenderThread_Entry;
	TArray<FPICOLayerPtr> PXRLayers_RenderThread;

	int32 FramesOutstanding;
};
typedef TSharedPtr<FPXRSplash> FPICOXRSplashPtr;
