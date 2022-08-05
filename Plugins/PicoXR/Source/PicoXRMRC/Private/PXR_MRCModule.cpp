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

#define LOCTEXT_NAMESPACE "FPicoXRMRCModule"

FPicoXRHMD* FPicoXRMRCModule::PicoXRHMD = nullptr;

FPicoXRMRCModule::FPicoXRMRCModule()
	:bSimulateEnableMRC(false)
	, SpawnTimes(0)
	, InGameThirdCamState(nullptr)
	, WorldAddedDelegate()
	, WorldDestroyedDelegate()
	, WorldLoadDelegate()
#if PLATFORM_ANDROID
	, bCpture2DActorActivated(false)
#endif

{
	PXR_LOGI(LogMRC, "PicoXRMRCModule Constructed!");
}

FPicoXRMRCModule::~FPicoXRMRCModule()
{
}

void FPicoXRMRCModule::StartupModule()
{
	PXR_LOGI(LogMRC, "PicoXRMRCModule startup!");
#if PLATFORM_ANDROID 
	PicoXRHMD = GetPicoXRHMD();
	if (GEngine)
	{
		InitialWorldAddedDelegate = GEngine->OnWorldAdded().AddRaw(this, &FPicoXRMRCModule::OnInitialWorldCreated);
	}
	InitialWorldLoadDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FPicoXRMRCModule::OnInitialWorldCreated);
#endif 
}

void FPicoXRMRCModule::ShutdownModule()
{
}

FPicoXRHMD* FPicoXRMRCModule::GetPicoXRHMD()
{
	if (!PicoXRHMD)
	{
		static FName SystemName(TEXT("PicoXRHMD"));
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
			{
				PicoXRHMD = static_cast<FPicoXRHMD*>(GEngine->XRSystem.Get());
			}
			if (PicoXRHMD == nullptr)
			{
				PXR_LOGI(LogMRC, "GetPicoXRHMD Failed!");
			}
		}
	}
	return PicoXRHMD;
}

bool FPicoXRMRCModule::IsMrcEnabled()
{
#if PLATFORM_ANDROID
	if (PicoXRHMD)
	{
		return PicoXRHMD->MRCEnabled || bSimulateEnableMRC;
	}
#endif
	return false;
}

bool FPicoXRMRCModule::GetMRCCalibrationData(FPXRTrackedCamera& CameraState)
{
	if (RawCameraDateFromXML.refreshed)
	{
#if PLATFORM_ANDROID
		Pxr_GetMrcPose(&MRCPose);
		PXR_LOGI(LogMRC, "Pxr_GetMrcPose x:%f y:%f z:%f w:%f px:%f py:%f pz:%f",
			MRCPose.orientation.x, MRCPose.orientation.y, MRCPose.orientation.z, MRCPose.orientation.w, MRCPose.position.x, MRCPose.position.y, MRCPose.position.z);

			CameraState.Width = RawCameraDateFromXML.width;
			CameraState.Height = RawCameraDateFromXML.height;
			CameraState.FOV = RawCameraDateFromXML.fov;
			//Right hand to left hand
			CameraState.CalibratedOffset = FVector(-MRCPose.position.z * 100, MRCPose.position.x * 100, MRCPose.position.y * 100);
			CameraState.CalibratedRotation = FRotator(FQuat(-MRCPose.orientation.z, MRCPose.orientation.x, MRCPose.orientation.y, -MRCPose.orientation.w));
			CameraState.CalibratedRotation.Pitch *= -1;
			CameraState.CalibratedRotation.Roll *= -1;
			PXR_LOGI(LogMRC, "Location:%s,Rotation:%s", PLATFORM_CHAR(*CameraState.CalibratedOffset.ToString()), PLATFORM_CHAR(*CameraState.CalibratedRotation.ToString()));
#endif		
			return true;
	}
	else
	{
		PXR_LOGI(LogMRC, "RawCameraDateFromXML is not refreshed,use default data!");
		CameraState.FOV = 90;
		CameraState.Width = 1920;
		CameraState.Height = 1080;
		CameraState.CalibratedOffset = FVector(180, 0, 0);
		CameraState.CalibratedRotation = FRotator(0, 180, 0);
	}
	return false;
}

bool FPicoXRMRCModule::GetMRCRT(UTextureRenderTarget2D*& Background_RT, UTextureRenderTarget2D*& Forground_RT)
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
		return false;
	}
#endif
	return false;
}

void FPicoXRMRCModule::EnableForeground(bool enable)
{
	if (InGameThirdCam)
	{
		InGameThirdCam->bEnableForeground = enable;
	}
}

void FPicoXRMRCModule::InitMRC()
{
	PXR_LOGI(LogMRC, "InitMixedRealityCapture");
	InGameThirdCamState = NewObject<UPXRInGameThirdCamState>((UObject*)GetTransientPackage(), FName("PicoXRMRC_State"), RF_MarkAsRootSet);

	ResetInGameThirdCamState();
	ReadCameraRawDataFromXML();
	
	WorldAddedDelegate = GEngine->OnWorldAdded().AddRaw(this, &FPicoXRMRCModule::OnWorldCreated);
	WorldDestroyedDelegate = GEngine->OnWorldDestroyed().AddRaw(this, &FPicoXRMRCModule::OnWorldDestroyed);
	WorldLoadDelegate = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FPicoXRMRCModule::OnWorldCreated);
}

void FPicoXRMRCModule::OpenInGameCam()
{
	PXR_LOGI(LogMRC, "Setup In Game Capture!");
	// Don't do anything if we don't have a UWorld or if we are not casting
	if (CurrentWorld == nullptr)
	{
		return;
	}
	// Don't add another actor if there's already a MRC camera actor
	for (TActorIterator<APicoXRMRC_CastingCameraActor> ActorIt(CurrentWorld); ActorIt; ++ActorIt)
	{
		if (!ActorIt->IsPendingKillOrUnreachable() && ActorIt->IsValidLowLevel())
		{
			InGameThirdCam = *ActorIt;
			return;
		}
	}
	SpawnTimes++;
	// Spawn an MRC camera actor if one wasn't already there
	InGameThirdCam = CurrentWorld->SpawnActorDeferred<APicoXRMRC_CastingCameraActor>(APicoXRMRC_CastingCameraActor::StaticClass(), FTransform::Identity);
	InGameThirdCam->InitializeStates(InGameThirdCamState);
	UGameplayStatics::FinishSpawningActor(InGameThirdCam, FTransform::Identity);

}

void FPicoXRMRCModule::CloseInGameCam()
{
	PXR_LOGI(LogMRC, "Close In Game Capture");
	// Destory actor and close the camera when we turn MRC off
	if (InGameThirdCam != nullptr && InGameThirdCam->GetWorld() != nullptr)
	{
		InGameThirdCam->Destroy();
		InGameThirdCam = nullptr;
	}
}

void FPicoXRMRCModule::ResetInGameThirdCamState()
{
	PXR_LOGI(LogMRC, "ResetInGameThirdCamState");
	InGameThirdCamState->TrackedCamera = FPXRTrackedCamera();
	InGameThirdCamState->FinalTransform = FTransform();
}

void FPicoXRMRCModule::OnWorldCreated(UWorld* NewWorld)
{
#if PLATFORM_ANDROID
	PXR_LOGI(LogMRC, "OnWorldCreated Delegates!");
	CurrentWorld = NewWorld;
	SwitchCaptureActive();

	PreWorldTickDelegate = FWorldDelegates::OnWorldPreActorTick.AddRaw(this, &FPicoXRMRCModule::OnWorldTick);

#endif
}

void FPicoXRMRCModule::OnWorldDestroyed(UWorld* NewWorld)
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

bool FPicoXRMRCModule::ReadCameraRawDataFromXML()
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
void FPicoXRMRCModule::SwitchCaptureActive()
{
	if (IsMrcEnabled())
	{
		if (!bCpture2DActorActivated)
		{
			PXR_LOGI(LogMRC, "Activating MRC Capture");
			bCpture2DActorActivated = true;
			OpenInGameCam();
		}
	}
	else
	{
		if (bCpture2DActorActivated)
		{
			PXR_LOGI(LogMRC, "Deactivating MRC Capture");
			bCpture2DActorActivated = false;
			CloseInGameCam();
			if (PicoXRHMD && PicoXRHMD->CurrentMRCLayer)
			{
				PXR_LOGI(LogMRC, "Destroy All MRCLayers One Time!");
				PicoXRHMD->DestroyAllMRCLayersOneTime();
			}
		}

	}

}

void FPicoXRMRCModule::OnWorldTick(UWorld* World, ELevelTick Tick, float Delta)
{
	// Poll MRC activation state
	if (CurrentWorld && World == CurrentWorld)
	{
		SwitchCaptureActive();
	}
}

void FPicoXRMRCModule::OnInitialWorldCreated(UWorld* NewWorld)
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
	
IMPLEMENT_MODULE(FPicoXRMRCModule, PicoXRMRC)