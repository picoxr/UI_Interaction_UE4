// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "TickableObjectRenderThread.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "PicoVRStereoLayers.h"
#include "PicoSplashTypes.h"


struct FPicoSplashLayer
{
	FPicoSplashDesc Desc;
	FPicoVRStereoLayerPtr Layer;

public:
	FPicoSplashLayer() {}
	FPicoSplashLayer(const FPicoSplashDesc& InDesc) : Desc(InDesc) {}
	FPicoSplashLayer(const FPicoSplashLayer& InSplashLayer) : Desc(InSplashLayer.Desc), Layer(InSplashLayer.Layer) {}
};


class FPicoVRSplash : public TSharedFromThis<FPicoVRSplash>
{
protected:
	class FTicker : public FTickableObjectRenderThread, public TSharedFromThis<FTicker>
	{
	public:
		FTicker(FPicoVRSplash* InSplash) : FTickableObjectRenderThread(false, true), pSplash(InSplash) {}

		virtual void Tick(float DeltaTime) override 
		{
			pSplash->Tick_RenderThread(DeltaTime);
		}
		virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FPicoVRSplash, STATGROUP_Tickables); }
		virtual bool IsTickable() const override { return true; }

	protected:
		FPicoVRSplash* pSplash;
	};

public:
	FPicoVRSplash(class FPicoMobileHMD* InPicoVRHMD);
	virtual ~FPicoVRSplash();
	
	FPicoSplashDesc GetSplashLayerDec();
	void SetSplashLayerDec(FPicoSplashDesc newDec);
	FPicoVRStereoLayerPtr GetSplashLayerPtr();

	void Tick_RenderThread(float DeltaTime);
	bool IsShown() const { return bIsShown; }

	void Startup();
	void LoadSettings();
	void Shutdown();

	void OnPreLoadMap(const FString&);
	void OnPostLoadMap(UWorld*);

	void StopTicker();
	void StartTicker();

	void Show();
	void Hide();

	void SetAutoShow(bool bInAuto);
	
	bool IsAutoShow() const { return bAutoShow; }

	void SetisFirstLoadMap(bool newValue);

	bool IsFirstLoadMap();

	void ClearSplashScreen();
protected:
	void UnloadTextures();
	void LoadTexture(FPicoSplashLayer& InSplashLayer);

	IStereoLayers::FLayerDesc StereoLayerDescFromPicoSplashDesc(FPicoSplashDesc PicoDesc);

protected:
	TSharedPtr<FTicker> Ticker;
	FCriticalSection RenderThreadLock;
	FPicoSplashLayer SplashLayer_Source;

	// All these flags are only modified from the Game thread
	bool bInitialized;
	bool bIsShown;
	bool bAutoShow;
	bool isFirstLoadMap;

	FDelegateHandle PreLoadLevelDelegate;
	FDelegateHandle PostLoadLevelDelegate;

private:
	class FPicoMobileHMD* PicoVRHMD;

	void CheckInGameThread()
	{
#if DO_CHECK
		check(IsInGameThread());
#endif
	}

};
typedef TSharedPtr<FPicoVRSplash> FPicoVRSplashPtr;
