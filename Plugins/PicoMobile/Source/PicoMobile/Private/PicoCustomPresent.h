// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "IPicoMobilePlugin.h"
#include "RendererInterface.h"
#include "IStereoLayers.h"
#include "XRRenderBridge.h"
#include "PicoMobile.h"
#include "RHI.h"

class FPicoMobileHMD;

class FPicoCustomPresent :	public FXRRenderBridge
{
public:
	FPicoCustomPresent(class FPicoMobileHMD* PicoMobileHMD);
	// FXRRenderBridge/FRHICustomPresent
	virtual bool NeedsNativePresent() override;
	virtual bool Present(int32& SyncInterval) override;
	virtual ~FPicoCustomPresent() {} 
	bool IsInitialized() {return bInitialized;}
	void SubmitFrame();
	void ShutDown();

protected:
	bool bInitialized = false;
	FPicoMobileHMD* PicoMobileHMD;
public:
	int32 ViewNnumber;
	FPoseData CurrentPose;
	GLuint RtID;
	bool bUsesArrayTexture;
	
};

