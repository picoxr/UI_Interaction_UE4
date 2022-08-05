//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "IXRLoadingScreen.h"
#include "TickableObjectRenderThread.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "PXR_StereoLayer.h"
#include "PXR_HMDTypes.h"
#include "PXR_Settings.h"
#include "PXR_GameFrame.h"

struct FPicoSplashLayer
{
	FPicoSplashDesc Desc;
	FPicoLayerPtr Layer;

public:
	FPicoSplashLayer() {}
	FPicoSplashLayer(const FPicoSplashDesc& InDesc) : Desc(InDesc) {}
	FPicoSplashLayer(const FPicoSplashLayer& InSplashLayer) : Desc(InSplashLayer.Desc), Layer(InSplashLayer.Layer) {}
};

class FPicoXRSplash : public IXRLoadingScreen,public TSharedFromThis<FPicoXRSplash>
{
protected:
	class FTicker : public FTickableObjectRenderThread, public TSharedFromThis<FTicker>
	{
	public:
		FTicker(FPicoXRSplash* InSplash) : FTickableObjectRenderThread(false, true), Splash(InSplash) {}

		virtual void Tick(float DeltaTime) override 
		{
			Splash->SplashTick_RenderThread(DeltaTime);
		}
		virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FPicoVRSplash, STATGROUP_Tickables); }
		virtual bool IsTickable() const override { return true; }

	protected:
		FPicoXRSplash* Splash;
	};

public:
	FPicoXRSplash( FPicoXRHMD* InPicoXRHMD);
	virtual ~FPicoXRSplash();
	virtual void ShowLoadingScreen() override;
	virtual void HideLoadingScreen() override;
	virtual void ClearSplashes() override;
	virtual void AddSplash(const FSplashDesc& Splash) override;
	virtual bool IsShown() const override { return bShown; }

	void Initialize();
	void UnInitialize();
	void LoadSettings();
	void SplashTick_RenderThread(float DeltaTime);
	void OnPreLoadMap(const FString&);
	void OnPostLoadMap(UWorld*);
	void StartTicker();
	void StopTicker();
	void Show();
	void Hide();
	void AutoShow(bool AutoShowSplash);
	void AddSplash(const FPicoSplashDesc& Splash);
	
	TArray<FPicoSplashLayer> SplashLayers;
	TMap<uint32,FPicoLayerPtr> SplashLayersMap;

	void UpdateLoadingScreen_GameThread();

protected:
	void ReleaseTextures();
	void ReleaseTexture(FPicoSplashLayer& InSplashLayer);
	void LoadTexture(FPicoSplashLayer& InSplashLayer);
	void RenderFrame_RenderThread(FRHICommandListImmediate& RHICmdList);
	IStereoLayers::FLayerDesc StereoLayerDescFromPicoSplashDesc(FPicoSplashDesc PicoDesc);
	TSharedPtr<FTicker> Ticker;
	FCriticalSection RenderThreadLock;

	bool bInitialized;
	FPicoXRHMD* PicoXRHMD;
	bool bTickerStarted;
	bool bSplashNeedUpdate = false;
	FDelegateHandle PostLoadLevelDelegate;
	UPicoXRSettings* PicoSettings;
	double LastTimeInSeconds;
	TArray<TTuple<FPicoLayerPtr, FQuat>> Layers_RenderThread_DeltaRotation;
	float SystemDisplayInterval;
	FPXRGameFramePtr Frame;
	bool bShown;
	bool bSplashShouldShow = false;
};
typedef TSharedPtr<FPicoXRSplash> FPicoXRSplashPtr;
