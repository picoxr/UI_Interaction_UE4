//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_MRCModule.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Engine/TextureRenderTarget2D.h"
#include "HardwareInfo.h"
#include "XRThreadUtils.h"
#include "PXR_MRCState.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "PXR_MRCCastingCameraActor.h"
#include "PXR_HMD.h"

#if PICO_MRC_SUPPORTED_PLATFORMS
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#endif

#define LOCTEXT_NAMESPACE "FPICOXRMRCModule"

FPICOXRHMD* FPICOXRMRCModule::PICOXRHMD = nullptr;

FPICOXRMRCModule::FPICOXRMRCModule()
	:bSimulateEnableMRC(false)
	, InGameThirdCamState(nullptr)
	, WorldAddedDelegate()
	, WorldDestroyedDelegate()
	, WorldLoadDelegate()
#if PLATFORM_ANDROID
	, bCpture2DActorActivated(false)
#endif

{
	PXR_LOGI(LogMRC, "PICOXRMRCModule Constructed!");
}

FPICOXRMRCModule::~FPICOXRMRCModule()
{
}

void FPICOXRMRCModule::StartupModule()
{
	PXR_LOGI(LogMRC, "PICOXRMRCModule startup!");
#if PLATFORM_ANDROID 
	PICOXRHMD = GetPICOXRHMD();
	if (GEngine)
	{
		InitialWorldAddedDelegate = GEngine->OnWorldAdded().AddRaw(this, &FPICOXRMRCModule::OnInitialWorldCreated);
	}
	InitialWorldLoadDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FPICOXRMRCModule::OnInitialWorldCreated);
#endif 
}

void FPICOXRMRCModule::ShutdownModule()
{
}

FPICOXRHMD* FPICOXRMRCModule::GetPICOXRHMD()
{
	if (!PICOXRHMD)
	{
		static FName SystemName(TEXT("PICOXRHMD"));
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
			{
				PICOXRHMD = static_cast<FPICOXRHMD*>(GEngine->XRSystem.Get());
			}
			if (PICOXRHMD == nullptr)
			{
				PXR_LOGI(LogMRC, "GetPICOXRHMD Failed!");
			}
		}
	}
	return PICOXRHMD;
}

bool FPICOXRMRCModule::IsMrcEnabled()
{
#if PLATFORM_ANDROID
	if (PICOXRHMD)
	{
		return PICOXRHMD->MRCEnabled || bSimulateEnableMRC;
	}
#endif
	return false;
}

bool FPICOXRMRCModule::IsMrcActivated()
{
	if (IsMrcEnabled() && bCpture2DActorActivated && InGameThirdCam && InGameThirdCam->HasInitializedOnce())
	{
		return true;
	}
	return false;
}

bool FPICOXRMRCModule::GetMRCCalibrationData(FPXRTrackedCamera& CameraState)
{
	if (RawCameraDateFromXML.refreshed)
	{
#if PLATFORM_ANDROID
		Pxr_GetMrcPose(&MRCPose);
		PXR_LOGV(LogMRC, "Pxr_GetMrcPose x:%f y:%f z:%f w:%f px:%f py:%f pz:%f",
			MRCPose.orientation.x, MRCPose.orientation.y, MRCPose.orientation.z, MRCPose.orientation.w, MRCPose.position.x, MRCPose.position.y, MRCPose.position.z);

			CameraState.Width = RawCameraDateFromXML.width;
			CameraState.Height = RawCameraDateFromXML.height;
			CameraState.FOV = RawCameraDateFromXML.fov;
			//Right hand to left hand
			CameraState.CalibratedOffset = FVector(-MRCPose.position.z * 100, MRCPose.position.x * 100, MRCPose.position.y * 100);
			CameraState.CalibratedRotation = FQuat(-MRCPose.orientation.z, MRCPose.orientation.x, MRCPose.orientation.y, -MRCPose.orientation.w).Rotator();
			PXR_LOGV(LogMRC, "Location:%s,Rotation:%s", PLATFORM_CHAR(*CameraState.CalibratedOffset.ToString()), PLATFORM_CHAR(*CameraState.CalibratedRotation.ToString()));
#endif		
			return true;
	}
	else
	{
		PXR_LOGV(LogMRC, "RawCameraDateFromXML is not refreshed,use default data!");
		CameraState.FOV = 90;
		CameraState.Width = 1920;
		CameraState.Height = 1080;
		CameraState.CalibratedOffset = FVector(180, 0, 0);
		CameraState.CalibratedRotation = FRotator(0, 180, 0);
	}
	return false;
}

bool FPICOXRMRCModule::GetMRCRT(UTextureRenderTarget2D*& Background_RT, UTextureRenderTarget2D*& Forground_RT)
{
#if PLATFORM_ANDROID
	if (InGameThirdCam)
	{
		if (InGameThirdCam->BackgroundRenderTarget)
		{
			Background_RT = InGameThirdCam->BackgroundRenderTarget;
			if (InGameThirdCam->ForegroundCaptureActor)
			{
				Forground_RT = InGameThirdCam->ForegroundRenderTarget;
			}
			else
			{
				Forground_RT = NULL;
			}
			return true;
		}
	}
#endif
	return false;
}

void FPICOXRMRCModule::EnableForeground(bool enable)
{
	if (IsMrcActivated() && InGameThirdCam)
	{
		InGameThirdCam->bEnableForeground = enable;
	}
}

UPXRInGameThirdCamState* FPICOXRMRCModule::GetMRCState()
{
	return InGameThirdCamState;
}

void FPICOXRMRCModule::InitMRC()
{
	PXR_LOGI(LogMRC, "InitMixedRealityCapture");
	InGameThirdCamState = NewObject<UPXRInGameThirdCamState>((UObject*)GetTransientPackage(), FName("PICOXRMRC_State"), RF_MarkAsRootSet);

	ResetInGameThirdCamState();
	ReadCameraRawDataFromXML();
	
	WorldAddedDelegate = GEngine->OnWorldAdded().AddRaw(this, &FPICOXRMRCModule::OnWorldCreated);
	WorldDestroyedDelegate = GEngine->OnWorldDestroyed().AddRaw(this, &FPICOXRMRCModule::OnWorldDestroyed);
	WorldLoadDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FPICOXRMRCModule::OnWorldCreated);
}

void FPICOXRMRCModule::OpenInGameCam()
{
	PXR_LOGI(LogMRC, "Setup In Game Capture!");
	// Don't do anything if we don't have a UWorld or if we are not casting
	if (CurrentWorld == nullptr)
	{
		return;
	}
	// Don't add another actor if there's already a MRC camera actor
	for (TActorIterator<APICOXRMRC_CastingCameraActor> ActorIt(CurrentWorld); ActorIt; ++ActorIt)
	{
		if (!ActorIt->IsPendingKillOrUnreachable() && ActorIt->IsValidLowLevel())
		{
			InGameThirdCam = *ActorIt;
			return;
		}
	}
	// Spawn an MRC camera actor if one wasn't already there
	InGameThirdCam = CurrentWorld->SpawnActorDeferred<APICOXRMRC_CastingCameraActor>(APICOXRMRC_CastingCameraActor::StaticClass(), FTransform::Identity);
	InGameThirdCam->InitializeStates(InGameThirdCamState);
	UGameplayStatics::FinishSpawningActor(InGameThirdCam, FTransform::Identity);

}

void FPICOXRMRCModule::CloseInGameCam()
{
	PXR_LOGI(LogMRC, "Close In Game Capture");
	// Destory actor and close the camera when we turn MRC off
	if (InGameThirdCam != nullptr && InGameThirdCam->GetWorld() != nullptr)
	{
		InGameThirdCam->Destroy();
		InGameThirdCam = nullptr;
	}
}

void FPICOXRMRCModule::ResetInGameThirdCamState()
{
	PXR_LOGI(LogMRC, "ResetInGameThirdCamState");
	if (InGameThirdCamState)
	{
		InGameThirdCamState->TrackedCamera = FPXRTrackedCamera();
		InGameThirdCamState->FinalTransform = FTransform();
		InGameThirdCamState->ZOffset = 0;
		InGameThirdCamState->CurrentTrackingReference = nullptr;
		InGameThirdCamState->bUseCustomTrans = false;
		InGameThirdCamState->CustomTrans = FTransform();
	}
}

void FPICOXRMRCModule::OnWorldCreated(UWorld* NewWorld)
{
	ResetInGameThirdCamState();
#if PLATFORM_ANDROID
	PXR_LOGI(LogMRC, "OnWorldCreated Delegates!");
	CurrentWorld = NewWorld;
	SwitchCaptureActive();

	PreWorldTickDelegate = FWorldDelegates::OnWorldPreActorTick.AddRaw(this, &FPICOXRMRCModule::OnWorldTick);

#endif
}

void FPICOXRMRCModule::OnWorldDestroyed(UWorld* NewWorld)
{
	CurrentWorld = nullptr;
#if PLATFORM_ANDROID
	bCpture2DActorActivated = false;
	if (PreWorldTickDelegate.IsValid())
	{
		FWorldDelegates::OnWorldPreActorTick.Remove(PreWorldTickDelegate);
		PreWorldTickDelegate.Reset();
	}

#endif
}

bool FPICOXRMRCModule::ReadCameraRawDataFromXML()
{
	FString XmlConfigPath = FPaths::Combine(FPaths::ProjectPersistentDownloadDir(), TEXT("mrc.xml"));
	PXR_LOGI(LogMRC, "ReadCameraRawDataFromXML:%s", PLATFORM_CHAR(*XmlConfigPath));
	if (FPaths::FileExists(XmlConfigPath))
	{
#if PLATFORM_ANDROID
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			jstring j_str = Env->NewStringUTF(TCHAR_TO_UTF8(*XmlConfigPath));
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "MRCGetCalibrationData", "(Ljava/lang/String;)[F", false);
			auto FloatValuesArray = NewScopedJavaObject(Env, (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, j_str));
			jfloat* FloatValues = Env->GetFloatArrayElements(*FloatValuesArray, 0);
			for (int i = 0; i < 10; i++)
			{
				PXR_LOGI(LogMRC, "Result[%d]:%f", i, FloatValues[i]);
			}
			RawCameraDateFromXML.width = FloatValues[0]; RawCameraDateFromXML.height = FloatValues[1]; RawCameraDateFromXML.fov = FloatValues[2];
			RawCameraDateFromXML.px = FloatValues[3]; RawCameraDateFromXML.py = FloatValues[4]; RawCameraDateFromXML.pz = FloatValues[5];
			RawCameraDateFromXML.x = FloatValues[6]; RawCameraDateFromXML.y = FloatValues[7]; RawCameraDateFromXML.z = FloatValues[8]; RawCameraDateFromXML.w = FloatValues[9];
			Env->ReleaseFloatArrayElements(*FloatValuesArray, FloatValues, 0);

			PxrPosef Newpose;
			Newpose.position.x = RawCameraDateFromXML.px;
			Newpose.position.y = RawCameraDateFromXML.py;
			Newpose.position.z = RawCameraDateFromXML.pz;
			Newpose.orientation.x = RawCameraDateFromXML.x;
			Newpose.orientation.y = RawCameraDateFromXML.y;
			Newpose.orientation.z = RawCameraDateFromXML.z;
			Newpose.orientation.w = RawCameraDateFromXML.w;
			int CurrentVersion = 0;
			Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
			if (CurrentVersion >= 0x2000306)
			{
				PXR_LOGI(LogMRC, "CurrentVersion:%d SetIsSupportMovingMrc to true!", CurrentVersion);
				Pxr_SetIsSupportMovingMrc(true);
	}
			Pxr_SetMrcPose(&Newpose);
			Pxr_SetConfigUint64(PxrConfigType::PXR_MRC_TEXTURE_WIDTH, RawCameraDateFromXML.width);
			Pxr_SetConfigUint64(PxrConfigType::PXR_MRC_TEXTURE_HEIGHT, RawCameraDateFromXML.height);
			RawCameraDateFromXML.refreshed = true;
			return true;
		}
#endif
		RawCameraDateFromXML.refreshed = false;
		return false;
	}
	else
	{
		PXR_LOGI(LogMRC, "Xml config file not found!");
		RawCameraDateFromXML.refreshed = false;
		return false;
	}
	RawCameraDateFromXML.refreshed = false;
	return false;
}

#if PLATFORM_ANDROID
void FPICOXRMRCModule::SwitchCaptureActive()
{
	if (IsMrcEnabled())
	{
		if (!bCpture2DActorActivated)
		{
			PXR_LOGI(LogMRC, "Activating MRC Capture");
			OpenInGameCam();
			bCpture2DActorActivated = true;
		}
	}
	else
	{
		if (bCpture2DActorActivated)
		{
			PXR_LOGI(LogMRC, "Deactivating MRC Capture");
			CloseInGameCam();
			if (PICOXRHMD && PICOXRHMD->CurrentMRCLayer)
			{
				PXR_LOGI(LogMRC, "Destroy All MRCLayers One Time!");
				PICOXRHMD->DestroyMRCLayer();
			}
			bCpture2DActorActivated = false;
		}

	}

}

void FPICOXRMRCModule::OnWorldTick(UWorld* World, ELevelTick Tick, float Delta)
{
	// Poll MRC activation state
	if (CurrentWorld && World == CurrentWorld)
	{
		SwitchCaptureActive();
	}
}

void FPICOXRMRCModule::OnInitialWorldCreated(UWorld* NewWorld)
{
	// Remove the initial world load handlers 
	if (InitialWorldAddedDelegate.IsValid())
	{
		GEngine->OnWorldAdded().Remove(InitialWorldAddedDelegate);
		InitialWorldAddedDelegate.Reset();
	}
	if (InitialWorldLoadDelegate.IsValid())
	{
		FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(InitialWorldLoadDelegate);
		InitialWorldLoadDelegate.Reset();
	}

	PXR_LOGI(LogMRC, "OnInitialWorldCreated");
#if PLATFORM_ANDROID
	int CurrentVersion = 0;
	Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
	PXR_LOGI(LogMRC, "Current Version:%d,MRC Support Version:%d", CurrentVersion, MRCSupportVersion);
	if (CurrentVersion < MRCSupportVersion)
	{
		PXR_LOGI(LogMRC, "Current version not support MRC!");
		return;
	}
#endif
	InitMRC();
	//The first time you enter the application, you need to take the initiative to call OnWorldCreated()
	OnWorldCreated(NewWorld);
}
#endif

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPICOXRMRCModule, PICOXRMRC)