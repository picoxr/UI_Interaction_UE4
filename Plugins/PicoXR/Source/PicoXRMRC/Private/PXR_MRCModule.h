//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "IPXR_MRCModule.h"
#include "PXR_Log.h"

#if PLATFORM_ANDROID
#include "PxrTypes.h"
#endif // PLATFORM_ANDROID

const int MRCSupportVersion = 0x2000300;

class UTextureRenderTarget2D;
class FPICOXRHMD;
class UPXRInGameThirdCamState;
class APICOXRMRC_CastingCameraActor;
struct FPXRTrackedCamera;

struct FRawCameraDataFromXML
{
	float x,y,z,w,px,py,pz,fov,width,height;
	bool refreshed;
	FRawCameraDataFromXML()
	{
		x = y = z = w = px = py = pz =fov= width = height = 0;
		refreshed = false;
	}
};

class FPICOXRMRCModule : public IPICOXRMRCModule
{
public:

	FPICOXRMRCModule();
	~FPICOXRMRCModule();

	static inline FPICOXRMRCModule& Get()
	{
		return FModuleManager::GetModuleChecked< FPICOXRMRCModule >("PICOXRMRC");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static class FPICOXRHMD* PICOXRHMD;
	static FPICOXRHMD* GetPICOXRHMD();

public:
	/** Check whether MRC is enabled by PICOHomeAPP */
	bool IsMrcEnabled();

	bool IsMrcActivated();

	/** Obtain calibration data */
	bool GetMRCCalibrationData(FPXRTrackedCamera & CameraState);

	bool GetMRCRT(UTextureRenderTarget2D* &Background_RT,UTextureRenderTarget2D* &Forground_RT);

	void EnableForeground(bool enable);

	bool bSimulateEnableMRC;

	UPXRInGameThirdCamState* GetMRCState();

private:
	UPXRInGameThirdCamState* InGameThirdCamState;
	APICOXRMRC_CastingCameraActor* InGameThirdCam;
	UWorld* CurrentWorld;
	FDelegateHandle WorldAddedDelegate;
	FDelegateHandle WorldDestroyedDelegate;
	FDelegateHandle WorldLoadDelegate;
	FRawCameraDataFromXML RawCameraDateFromXML;
#if PLATFORM_ANDROID
    PxrPosef MRCPose;
#endif
	//Only call once at fist enter app
	void InitMRC();
	void OpenInGameCam();
	void CloseInGameCam();
	void ResetInGameThirdCamState();
	void OnWorldCreated(UWorld* NewWorld);
	void OnWorldDestroyed(UWorld* NewWorld);
	bool ReadCameraRawDataFromXML();

	bool bCpture2DActorActivated;
#if PLATFORM_ANDROID
	FDelegateHandle InitialWorldAddedDelegate;
	FDelegateHandle InitialWorldLoadDelegate;
	FDelegateHandle PreWorldTickDelegate;

	void SwitchCaptureActive();
	void OnWorldTick(UWorld* World, ELevelTick Tick, float Delta);
	void OnInitialWorldCreated(UWorld* NewWorld);
#endif
};
