// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "IXRLoadingScreen.h"
#include "TickableObjectRenderThread.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "PXR_StereoLayer.h"
#include "PXR_HMDTypes.h"

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
			Splash->Tick_RenderThread(DeltaTime);
		}
		virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FPicoVRSplash, STATGROUP_Tickables); }
		virtual bool IsTickable() const override { return true; }

	protected:
		FPicoXRSplash* Splash;
	};

public:
	FPicoXRSplash( FPicoXRHMD* InPicoXRHMD);
	virtual ~FPicoXRSplash();
	
	void Tick_RenderThread(float DeltaTime);

	void Startup();
	void LoadSettings();
	void Shutdown();

	void OnPreLoadMap(const FString&);
	void OnPostLoadMap(UWorld*);

	void StartTicker();
	void StopTicker();
	
	void Show();
	void Hide();

	void AutoShow(bool AutoShowSplash);
	void AddSplash(const FPicoSplashDesc& Splash);
	
    virtual void ShowLoadingScreen() override;
	virtual void HideLoadingScreen() override;
	virtual void ClearSplashes() override;
	virtual void AddSplash(const FSplashDesc& Splash) override;
	virtual bool IsShown() const override { return bIsShown; }
	TArray<FPicoSplashLayer> SplashLayers;
	TMap<uint32,FPicoLayerPtr> SplashLayersMap;
protected:
	void UnloadTextures();
	void UnloadTexture(FPicoSplashLayer& InSplashLayer);
	void LoadTexture(FPicoSplashLayer& InSplashLayer);
	IStereoLayers::FLayerDesc StereoLayerDescFromPicoSplashDesc(FPicoSplashDesc PicoDesc);
	TSharedPtr<FTicker> Ticker;
	FCriticalSection RenderThreadLock;

	bool bInitialized;
	bool bRenderThreadIsRunning;
	bool bIsShown;
	bool bAutoShow;
	
	FPicoXRHMD* PicoXRHMD;
};
typedef TSharedPtr<FPicoXRSplash> FPicoXRSplashPtr;
