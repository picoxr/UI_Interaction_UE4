// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoCustomPresent.h"
#include "PicoImport.h"
#include "StereoRendering.h"
#include "HAL/RunnableThread.h"
#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidEGL.h"
#include "Android/AndroidApplication.h"
#endif

FPicoCustomPresent::FPicoCustomPresent(class FPicoMobileHMD* PicoMobileHMD)
	:FXRRenderBridge(),
	PicoMobileHMD(PicoMobileHMD)
{
	check(IsInGameThread());
	bInitialized = true;
	ViewNnumber = 0;
	RtID = 0;
	bUsesArrayTexture = false;
}

bool FPicoCustomPresent::NeedsNativePresent()
{
	return true;
}

bool FPicoCustomPresent::Present(int32& SyncInterval)
{
	SyncInterval = 0;
	check(IsInRenderingThread() || IsInRHIThread());
	SubmitFrame();

	return false;
}

void FPicoCustomPresent::ShutDown()
{

}


void FPicoCustomPresent::SubmitFrame()
{
#if PLATFORM_ANDROID

	PicoMobileHMD->SendFoveationParam(RtID);
	//RenderAboutOverlay
	if (PicoSDK::SeeThrough::SeeThroughState != 2)
	{
		PicoMobileHMD->OverlayRendering(CurrentPose);
		PicoMobileHMD->EyeTrackingMarkerRendering();
#if !UE_BUILD_SHIPPING
		PicoMobileHMD->DebugRendering();
#endif
	}

	if (bUsesArrayTexture)
	{
		PicoSDK::Render::RenderEventWithData(EVENT_BOTHEYE_ENDFRAME, RtID);
	}
	else
	{
		PicoSDK::Render::RenderEventWithData(EVENT_LEFTEYE_ENDFRAME, RtID);
	}
	PicoSDK::Render::RenderEventWithData(EVENT_BOUNDARY_LEFT, ViewNnumber);
	if (!bUsesArrayTexture)
	{
		PicoSDK::Render::RenderEventWithData(EVENT_BOUNDARY_RIGHT, ViewNnumber);
	}
	PicoSDK::Render::RenderEventWithData(EVENT_TIMEWARP, ViewNnumber);

#endif
}
