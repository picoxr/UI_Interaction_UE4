// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobile.h"
#include "PicoImport.h"
#include "PicoMobileSettings.h"
#include "PicoJava.h"
#include "PicoEyeTracker.h"
#include "PicoCustomPresent.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "PostProcess/PostProcessHMD.h"
#include "RendererPrivate.h"
#include "../Launch/Resources/Version.h"
#include "XRThreadUtils.h"
#if WITH_EDITOR
#include "PicoSettingsCustomization.h"
#include "PropertyEditorModule.h"
#include "ISettingsModule.h"
#endif

DEFINE_LOG_CATEGORY_STATIC(LogPicoHMD, Log, All);

#define LOCTEXT_NAMESPACE "FPicoMobilePlugin"


///////////////////////
// FPicoMobilePlugin //
///////////////////////

class FPicoMobilePlugin : public IPicoMobilePlugin
{
	virtual TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > CreateTrackingSystem() override;

	FString GetModuleKeyName() const override
	{
		return FString(TEXT("PicoMobile"));
	}

	virtual void StartupModule() override
	{
		IHeadMountedDisplayModule::StartupModule();
#if WITH_EDITOR
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.RegisterCustomClassLayout(
            UPicoMobileSettings::StaticClass()->GetFName(),
            FOnGetDetailCustomizationInstance::CreateStatic(&FPicoSettingsCustomization::MakeInstance)
        );
		PropertyModule.NotifyCustomizationModuleChanged();

		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
		if (SettingsModule != nullptr)
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "PicoMobile",
				LOCTEXT("PicoMobileSettingsName", "PicoMobile"),
				LOCTEXT("PicoMobileSettingsDescription", "Configure the PicoMobile plug-in."),
				GetMutableDefault<UPicoMobileSettings>()
			);
		}
#endif
	}

	virtual void ShutdownModule() override
	{
		IHeadMountedDisplayModule::ShutdownModule();
#if WITH_EDITOR
		// unregister settings
		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

		if (SettingsModule != nullptr)
		{
			SettingsModule->UnregisterSettings("Project", "Plugins", "PicoMobile");
		}
#endif

	}

	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}

};

IMPLEMENT_MODULE(FPicoMobilePlugin, PicoMobile)

TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > FPicoMobilePlugin::CreateTrackingSystem()
{
	TSharedPtr< FPicoMobileHMD, ESPMode::ThreadSafe > PicoMobileHMD = FSceneViewExtensions::NewExtension<FPicoMobileHMD>();
	if (PicoMobileHMD)
	{
		return PicoMobileHMD;
	}
	return nullptr;
}


////////////////////
// FPicoMobileHMD //
////////////////////

FPicoMobileHMD::FPicoMobileHMD(const FAutoRegister& AutoRegister) :
#if ENGINE_MINOR_VERSION >= 22
	FHeadMountedDisplayBase(nullptr),
#endif
	FSceneViewExtensionBase(AutoRegister),
	bIsRenderThreadInit(false),
	bIsStereoEnabled(true),
	CurHmdOrientation(FQuat::Identity),
	LastHmdOrientation(FQuat::Identity),
	DeltaControlRotation(FRotator::ZeroRotator),
	DeltaControlOrientation(FQuat::Identity),
	LastSensorTime(-1.0),
	bUsesArrayTexture(false),
	FixedFrameRate(62.0),
	UseFixedFrameRate(false),
	EyeTracker(nullptr),
	PixelDensity(1.0f),
	NextPicoLayerId(1),
	isFixOverlay(false),
	InitCamPos(FVector::ZeroVector),
	PreCamPos(FVector::ZeroVector),
	DebugTexture(nullptr),
	CustomPresent(nullptr),
	DebugRenderNumber(0),
	PicoSettings(nullptr)
{
	PicoSettings = GetMutableDefault<UPicoMobileSettings>();
	EyeTracker = FPicoEyeTracker::GetInstance();
	Startup();

#if PLATFORM_ANDROID
	// SDK Version
	FString sdkVersion = FString(PicoImport::PvrGetSDKVersion());
	UE_LOG(LogPicoHMD, Log, TEXT("SDK Version: %s; Plugin Version: 1.2.6.1"), *sdkVersion);
#endif
}

FPicoMobileHMD::~FPicoMobileHMD()
{
	EyeTracker->Destory();
	Shutdown();
}

// IXRSystemIdentifier

FName FPicoMobileHMD::GetSystemName() const
{
	static FName DefaultName(TEXT("FPicoVRHMD"));
	return DefaultName;
}

// IXRTrackingSystem

bool FPicoMobileHMD::DoesSupportPositionalTracking() const
{
	return !(PicoSettings->bDisableHmd6DofModule);
}

bool FPicoMobileHMD::EnumerateTrackedDevices(TArray<int32>& OutDevices, EXRTrackedDeviceType Type)
{
	if (Type == EXRTrackedDeviceType::Any || Type == EXRTrackedDeviceType::HeadMountedDisplay)
	{
		OutDevices.Add(IXRTrackingSystem::HMDDeviceId);
		return true;
	}
	return false;
}


bool FPicoMobileHMD::GetCurrentPose(int32 DeviceId, FQuat & OutOrientation, FVector & OutPosition)
{
	if (DeviceId != HMDDeviceId)
	{
		return false;
	}
#if PLATFORM_ANDROID
	if (!IsInitialized() && EyeTracker->ActivePlayerController != NULL)
	{
		OutOrientation = FQuat::Identity;
		OutPosition = FVector::ZeroVector;
	}
	else
	{
		if (IsInGameThread())
		{
			OutPosition = PicoSDK::Sensor::GCurrentPoseGT.Position;
			OutOrientation = PicoSDK::Sensor::GCurrentPoseGT.Orientation;
		}
		else if (IsInRenderingThread())
		{
			if (PicoSDK::Sensor::GGameFrameEnded)
			{
				PicoSDK::Sensor::GGameFrameEnded = false;
				PicoSDK::Sensor::GetMainSensorState();
			}
			OutPosition = PicoSDK::Sensor::GCurrentPoseRT.Position;
			OutOrientation = PicoSDK::Sensor::GCurrentPoseRT.Orientation;
		}
	}	
	return true;
#endif	
	return false;
}

void FPicoMobileHMD::SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin)
{
#if PLATFORM_ANDROID
	if (NewOrigin == EHMDTrackingOrigin::Eye) {
		PicoImport::PvrSetTrackingOrigin(0);
		PicoSDK::Sensor::TrackingOrigin = 0;
	}
	else
	{
		PicoImport::PvrSetTrackingOrigin(1);
		PicoSDK::Sensor::TrackingOrigin = 1;
	}
#endif
}

EHMDTrackingOrigin::Type FPicoMobileHMD::GetTrackingOrigin() const
{
#if PLATFORM_ANDROID
	if (PicoSDK::Sensor::TrackingOrigin == 0) {
		return EHMDTrackingOrigin::Eye;
	}
	else {
		return EHMDTrackingOrigin::Floor;
	}
#endif
	return EHMDTrackingOrigin::Eye;
}

bool FPicoMobileHMD::GetRelativeEyePose(int32 DeviceId, EStereoscopicPass Eye, FQuat & OutOrientation, FVector & OutPosition)
{
	OutOrientation = FQuat::Identity;
	OutPosition = FVector::ZeroVector;
#if PLATFORM_ANDROID
	if (DeviceId == IXRTrackingSystem::HMDDeviceId && (Eye == eSSP_LEFT_EYE || Eye == eSSP_RIGHT_EYE))
	{
		OutPosition = FVector(0, (Eye == EStereoscopicPass::eSSP_LEFT_EYE ? -.5 : .5) * GetInterpupillaryDistance() * GetWorldToMetersScale(), 0);
		return true;
	}
	else
#endif
	{
		return false;
	}
}

void FPicoMobileHMD::ResetOrientationAndPosition(float yaw)
{
#if PLATFORM_ANDROID
	PicoSDK::Sensor::OptionalResetSensor(PicoSDK::Sensor::GMainSensorIndex, 1, 1);
#endif
}

void FPicoMobileHMD::ResetOrientation(float Yaw)
{
#if PLATFORM_ANDROID
	PicoSDK::Sensor::OptionalResetSensor(PicoSDK::Sensor::GMainSensorIndex, 1, 0);
#endif
}

void FPicoMobileHMD::ResetPosition()
{
#if PLATFORM_ANDROID
	PicoSDK::Sensor::OptionalResetSensor(PicoSDK::Sensor::GMainSensorIndex, 0, 1);
#endif
}

void FPicoMobileHMD::SetBaseRotation(const FRotator & BaseRot)
{
	SetBaseOrientation(FRotator(0.0f, BaseRot.Yaw, 0.0f).Quaternion());
}

FRotator FPicoMobileHMD::GetBaseRotation() const
{
	return GetBaseOrientation().Rotator();
}

void FPicoMobileHMD::SetBaseOrientation(const FQuat & BaseOrient)
{
	BaseOrientation = BaseOrient;
}

FQuat FPicoMobileHMD::GetBaseOrientation() const
{
	return BaseOrientation;
}

IHeadMountedDisplay * FPicoMobileHMD::GetHMDDevice()
{
	return this;
}

TSharedPtr<class IStereoRendering, ESPMode::ThreadSafe> FPicoMobileHMD::GetStereoRenderingDevice()
{
	return SharedThis(this);
}

bool FPicoMobileHMD::OnStartGameFrame(FWorldContext& WorldContext)
{
	EyeTracker->ActivePlayerController = GEngine->GetFirstLocalPlayerController(WorldContext.World());
#if PLATFORM_ANDROID
	if (PicoSDK::GIsMapPost)
	{
		if (PicoSDK::GMapInitFrame == 5)
		{
			if (MapToInitPos.Num() > 0 && MapToInitPos.Contains(WorldContext.World()->GetMapName()))
			{
				InitCamPos = *MapToInitPos.Find(WorldContext.World()->GetMapName());
			}
			else
			{
				InitCamPos = GEngine->GetFirstLocalPlayerController(WorldContext.World())->PlayerCameraManager->GetCameraLocation();
				InitCamPos = InitCamPos - PreCamPos;
				MapToInitPos.Add(WorldContext.World()->GetMapName(), InitCamPos);
			}
			PicoSDK::GIsMapPost = false;
			PicoSDK::GMapInitFrame = 1;
		}
		else
		{
			PreCamPos = PicoSDK::Sensor::GCurrentPoseGT.Position;
			PicoSDK::GMapInitFrame++;
		}
	}

	if (!bIsStereoEnabled)
	{
		EnableStereo(true);
	}
	PicoSDK::Sensor::GoldCurrentPoseGT = PicoSDK::Sensor::GCurrentPoseGT;
	PicoSDK::Sensor::GCurrentPoseGT = PicoSDK::Sensor::GoldCurrentPoseRT;
#endif
	return true;
}

bool FPicoMobileHMD::OnEndGameFrame(FWorldContext& WorldContext)
{
#if PLATFORM_ANDROID
	ExecuteOnRenderThread_DoNotWait([this]()
    {
        PicoSDK::Sensor::GoldCurrentPoseRT = PicoSDK::Sensor::GCurrentPoseRT;
        PicoSDK::Sensor::GCurrentPoseRT = PicoSDK::Sensor::GCurrentPoseGT;
        PicoSDK::Sensor::GGameFrameEnded = true;
    });
#endif
	return false;
}

void FPicoMobileHMD::OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily)
{
#if PLATFORM_ANDROID
	if (!IsInitialized())
	{
		SubmitUnrealInfo();
		if (!PicoSettings->bDisableHmd6DofModule)
		{
			PicoSDK::Sensor::Enable6Dof(true);
		}
		if (PicoSplash->IsFirstLoadMap())
		{
			PicoSplash->SetisFirstLoadMap(false);
		}
		ExecuteOnRHIThread([this]()
		{
			InitializRenderThread();
		});			
	}
	if (IsInitialized())
	{
		// Update SeeThrough boundary State
		PicoSDK::SeeThrough::SeeThroughState = PicoSDK::SeeThrough::GetSeeThroughState();
	}
#endif
}

// IHeadMountedDisplay
EHMDWornState::Type FPicoMobileHMD::GetHMDWornState()
{
#if PLATFORM_ANDROID
	int32 pSensorStatus = -1;
	pSensorStatus = FPicoJava::Pvr_GetPsensorState();

	if (0 == pSensorStatus)
	{
		return EHMDWornState::Worn;
	}
	else if (1 <= pSensorStatus)
	{
		return EHMDWornState::NotWorn;
	}
	else
	{
		return EHMDWornState::Unknown;
	}
#endif
	return EHMDWornState::Unknown;
}

void FPicoMobileHMD::EnableHMD(bool enable)
{
}

bool FPicoMobileHMD::GetHMDMonitorInfo(MonitorInfo& MonitorDesc)
{
#if PLATFORM_ANDROID
	MonitorDesc.MonitorName = "";
	MonitorDesc.MonitorId = 0;
	MonitorDesc.DesktopX = MonitorDesc.DesktopY = MonitorDesc.ResolutionX = MonitorDesc.ResolutionY = 0;

	MonitorDesc.ResolutionX = PicoSDK::Render::GTextureSize.X;
	MonitorDesc.ResolutionY = PicoSDK::Render::GTextureSize.Y;

	return true;
#endif
	return false;
}

void FPicoMobileHMD::GetFieldOfView(float& OutHFOVInDegrees, float& OutVFOVInDegrees) const
{
#if PLATFORM_ANDROID
	OutVFOVInDegrees =  PicoSDK::Sensor::GVFov;
	OutHFOVInDegrees =  PicoSDK::Sensor::GHFov;
#endif
}

void FPicoMobileHMD::GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const
{
	if (Context.View.StereoPass == eSSP_LEFT_EYE)
	{
		EyeToSrcUVOffsetValue.X = 0.0f;
		EyeToSrcUVOffsetValue.Y = 0.0f;

		EyeToSrcUVScaleValue.X = 0.5f;
		EyeToSrcUVScaleValue.Y = 1.0f;
	}
	else
	{
		EyeToSrcUVOffsetValue.X = 0.5f;
		EyeToSrcUVOffsetValue.Y = 0.0f;

		EyeToSrcUVScaleValue.X = 0.5f;
		EyeToSrcUVScaleValue.Y = 1.0f;
	}
}

void FPicoMobileHMD::SetInterpupillaryDistance(float NewInterpupillaryDistance)
{
#if PLATFORM_ANDROID
	bool success = PicoSDK::Render::SetIPD(NewInterpupillaryDistance);
	UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT SetIPD %d %f"),(int32)success, NewInterpupillaryDistance);
#endif
}

float FPicoMobileHMD::GetInterpupillaryDistance() const
{
	float iPDValue = 0.063f;
#if PLATFORM_ANDROID
	if (!PicoSDK::Render::GetIPD(iPDValue)) 
	{
		UE_LOG(LogPicoHMD,Log,TEXT("GetIPD failed!"));
	}
#endif
	return iPDValue;
}


bool FPicoMobileHMD::GetHMDDistortionEnabled(EShadingPath ShadingPath) const
{
	return false;
}


bool FPicoMobileHMD::IsChromaAbCorrectionEnabled() const
{
	return false;
}

float FPicoMobileHMD::GetPixelDenity() const
{
	return PixelDensity;
}

void FPicoMobileHMD::SetPixelDensity(const float NewPixelDensity)
{
	PixelDensity = NewPixelDensity;
	SetPicoRenderTargetSize();
}

bool FPicoMobileHMD::SetPicoRenderTargetSize()
{
#if PLATFORM_ANDROID
	UE_LOG(LogPicoHMD, Log, TEXT("RTScale = %f"), PixelDensity);
	FIntPoint IdealRTSize = GetIdealRenderTargetSize();
	if (bUsesArrayTexture)
	{
		PicoSDK::Render::GTextureSize.X = FMath::CeilToInt(static_cast<float>(IdealRTSize.X) * PixelDensity / 2);
	}
	else
	{
		PicoSDK::Render::GTextureSize.X = FMath::CeilToInt(static_cast<float>(IdealRTSize.X) * PixelDensity);
	}
	PicoSDK::Render::GTextureSize.Y = FMath::CeilToInt(static_cast<float>(IdealRTSize.Y) * PixelDensity);
	NormalizeRTSize();
	return true;
#endif 
	return false;
}

void FPicoMobileHMD::NormalizeRTSize()
{
#if PLATFORM_ANDROID
	FIntPoint maxRenderTextureSize = FIntPoint(8192,4096);
	const FString DeviceModelStr = FAndroidMisc::GetDeviceModel();
	if (DeviceModelStr.Contains("G2") && !bUsesArrayTexture && PicoSettings->bEnableFoveationRendering)
	{
		UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE DISFT the max RenderTexture size is (4160,2080) if the Device is G2/G2 4K !"));
		maxRenderTextureSize.X = 4160;
		maxRenderTextureSize.Y = 2080;
	}
	const uint32 DividableBy = 4;
	const uint32 Mask = ~(DividableBy - 1);
	PicoSDK::Render::GTextureSize.X = (PicoSDK::Render::GTextureSize.X + DividableBy - 1) & Mask;
	PicoSDK::Render::GTextureSize.Y = (PicoSDK::Render::GTextureSize.Y + DividableBy - 1) & Mask;
	PicoSDK::Render::GTextureSize.X = PicoSDK::Render::GTextureSize.X > maxRenderTextureSize.X ? maxRenderTextureSize.X : PicoSDK::Render::GTextureSize.X;
	PicoSDK::Render::GTextureSize.Y = PicoSDK::Render::GTextureSize.Y > maxRenderTextureSize.Y ? maxRenderTextureSize.Y : PicoSDK::Render::GTextureSize.Y;
	PicoImport::PvrSubmitRenderTargetSize(PicoSDK::Render::GTextureSize.X, PicoSDK::Render::GTextureSize.Y);
	UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE DISFT NormalizeRTSize:GTextureSize %d,%d"), PicoSDK::Render::GTextureSize.X, PicoSDK::Render::GTextureSize.Y);
#endif
}

void FPicoMobileHMD::LimitFrameRate()
{
#if PLATFORM_ANDROID
	if (GEngine->bUseFixedFrameRate)
	{
		if (GEngine->FixedFrameRate > PicoSDK::Render::DisplayRate)
		{
			GEngine->FixedFrameRate = PicoSDK::Render::DisplayRate;
		}
	}
	if (GEngine->bSmoothFrameRate)
	{
		if (GEngine->SmoothedFrameRateRange.GetUpperBound().IsOpen())
		{
			GEngine->bUseFixedFrameRate = true;
			GEngine->FixedFrameRate = PicoSDK::Render::DisplayRate;
		}
		else
		{	
			if (GEngine->SmoothedFrameRateRange.GetUpperBoundValue() > PicoSDK::Render::DisplayRate)
			{
				GEngine->SmoothedFrameRateRange.SetUpperBoundValue(PicoSDK::Render::DisplayRate);
			}
		}
	}
	if (!GEngine->bSmoothFrameRate && !GEngine->bUseFixedFrameRate)
	{
		GEngine->SetMaxFPS(PicoSDK::Render::DisplayRate);
	}
#endif
}

void FPicoMobileHMD::DoAppCheck()
{
#if PLATFORM_ANDROID
	//AppCheck
	if (PicoSettings->bStartTimeEntitlementCheck)
	{
		if (PicoSettings->EntitlementCheckSimulation)
		{
			const int32 num = PicoSettings->DeviceSN.Num();
			if (num > 0)
			{
				for (int i = 0; i < num; i++)
				{
					if (PicoSettings->DeviceSN[i] == FPicoJava::GetDeviceSN())
					{
						return;
					}
				}	
			}
		}
		if(PicoSettings->EntitlementCheckAppID == "")
		{
			UE_LOG(LogTemp,Error,TEXT("APPID is required for Entitlement Check. Create / Find your APP ID on https://developer.pico-interactive.com/developer/overview."));
		}
		FString PublicKey = "";
		FPicoJava::VerifyAPP(PicoSettings->EntitlementCheckAppID, PublicKey);
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("EntitlementCheck is highly recommended which can protect the copyright of app. You can enable it when App start-up in the Inspector of \"Edit->Plugins->PicoMobile->Platform\" and Enter your APPID. If you want to call the APIs as needed, please refer to the development Document."));
	}
#endif
}

bool FPicoMobileHMD::GetMultiViewState()
{
	bool bEnableMultiView = false;
	auto MobileMultiViewCVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.MobileMultiView"));
	bEnableMultiView = GSupportsMobileMultiView && MobileMultiViewCVar && MobileMultiViewCVar->GetValueOnAnyThread() != 0;
#if ENGINE_MINOR_VERSION <25
	auto MobileMultiViewDirectCVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.MobileMultiView.Direct"));
	bEnableMultiView = bEnableMultiView && MobileMultiViewDirectCVar && MobileMultiViewDirectCVar->GetValueOnAnyThread() != 0;
#endif
	return bEnableMultiView;
}

FIntPoint FPicoMobileHMD::GetIdealRenderTargetSize() const
{
	FIntPoint DefaultRTSize = FIntPoint(2048,1024);
#if PLATFORM_ANDROID
	PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::EYE_TEXTURE_RESOLUTION0, DefaultRTSize.X);
	PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::EYE_TEXTURE_RESOLUTION1, DefaultRTSize.Y);
	DefaultRTSize.X = DefaultRTSize.X * 2;
#endif
	return DefaultRTSize;
}

// IStereoRendering

bool FPicoMobileHMD::IsStereoEnabled() const
{
	return bIsStereoEnabled;
}

bool FPicoMobileHMD::EnableStereo(bool stereo)
{
	check(IsInGameThread());

	bIsStereoEnabled = true;

	return bIsStereoEnabled;
}

void FPicoMobileHMD::AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
#if PLATFORM_ANDROID
	if (bUsesArrayTexture)
	{
		SizeX = PicoSDK::Render::GTextureSize.X ;
	}
	else
	{
		SizeX = PicoSDK::Render::GTextureSize.X / 2;
	}
	SizeY = PicoSDK::Render::GTextureSize.Y;
	if (StereoPass == eSSP_RIGHT_EYE)
	{
		X += SizeX;
	}
	//UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE AdjustViewRect() : (StereoPass:%d ,X: %d,Y: %d ,SizeX: %d,SizeY: %d)"), (int)StereoPass, X, Y,SizeX, SizeY);

#endif
}

FMatrix FPicoMobileHMD::GetStereoProjectionMatrix(const EStereoscopicPass StereoPassType) const
{	
#if PLATFORM_ANDROID
	const float ProjectionCenterOffset = 0;// 0.151976421f;
	const float PassProjectionOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionCenterOffset : -ProjectionCenterOffset;
	const float HalfHFov = FMath::DegreesToRadians(PicoSDK::Sensor::GHFov) / 2.f;
	const float HalfVFov = FMath::DegreesToRadians(PicoSDK::Sensor::GVFov) / 2.f;
	const float Right = FPlatformMath::Tan(HalfHFov);
	const float Left = -FPlatformMath::Tan(HalfHFov);
	const float Bottom = -FPlatformMath::Tan(HalfVFov);
	const float Top = FPlatformMath::Tan(HalfVFov);

	float SumRL = (Right + Left);
	float SumTB = (Top + Bottom);
	float InvRL = (1.0f / (Right - Left));
	float InvTB = (1.0f / (Top - Bottom));
	const float InNearZ = GNearClippingPlane;
	return FMatrix(
		FPlane((2.0f * InvRL), 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, (2.0f * InvTB), 0.0f, 0.0f),
		FPlane((SumRL * InvRL), (SumTB * InvTB), 0.0f, 1.0f),
		FPlane(0.0f, 0.0f, InNearZ, 0.0f))
		* FTranslationMatrix(FVector(PassProjectionOffset, 0, 0));
#else 
	const float ProjectionCenterOffset = 0;// 0.151976421f;
	const float PassProjectionOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionCenterOffset : -ProjectionCenterOffset;
	const float HalfFov = FMath::DegreesToRadians(102.0f) / 2.f;
	const float InWidth = 1280.f;
	const float InHeight = 1280.f;
	const float XS = 1.0f / tan(HalfFov);
	const float YS = InWidth / tan(HalfFov) / InHeight;

	const float InNearZ = GNearClippingPlane;
	return FMatrix(
		FPlane(XS, 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, YS, 0.0f, 0.0f),
		FPlane(0.0f, 0.0f, 0.0f, 1.0f),
		FPlane(0.0f, 0.0f, InNearZ, 0.0f))* FTranslationMatrix(FVector(PassProjectionOffset, 0, 0));	
#endif
}

uint32 FPicoMobileHMD::CreateLayer(const IStereoLayers::FLayerDesc & InLayerDesc)
{
	check(IsInGameThread());
	uint32 LayerId = NextPicoLayerId++;
	if (InLayerDesc.Texture != NULL)
	{
		UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT Add a Layer ID is %d "), LayerId);
		LayerSortIndex.Add(LayerId, -InLayerDesc.Priority);
		LayerSortIndex.ValueSort(TGreater<int32>());
		PicoLayerMap.Add(LayerId, MakeShareable(new FPicoVRStereoLayer(LayerId, InLayerDesc)));
	}
	
	return LayerId;
}

void FPicoMobileHMD::DestroyLayer(uint32 LayerId)
{
	check(IsInGameThread());
	LayerSortIndex.Remove(LayerId);
	PicoLayerMap.Remove(LayerId);
}

void FPicoMobileHMD::SetLayerDesc(uint32 LayerId, const IStereoLayers::FLayerDesc & InLayerDesc)
{
	/*check(IsInGameThread());

	FPicoVRStereoLayerPtr* LayerFound = PicoLayerMap.Find(LayerId);
	if (LayerFound)
	{
		FPicoVRStereoLayer* PicoLayer = new FPicoVRStereoLayer(**LayerFound);
		PicoLayer->SetDesc(InLayerDesc);
		*LayerFound = MakeShareable(PicoLayer);
	}*/
}

bool FPicoMobileHMD::GetLayerDesc(uint32 LayerId, IStereoLayers::FLayerDesc & OutLayerDesc)
{
	/*check(IsInGameThread());
	FPicoVRStereoLayerPtr* LayerFound = PicoLayerMap.Find(LayerId);

	if (LayerFound)
	{
		OutLayerDesc = (*LayerFound)->GetDesc();
		return true;
	}*/

	return false;
}

void FPicoMobileHMD::UpdateSplashScreen()
{
	return;
}
IStereoLayers::FLayerDesc FPicoMobileHMD::GetDebugCanvasLayerDesc(FTextureRHIRef Texture)
{
	DebugTexture = Texture;
#if ENGINE_MINOR_VERSION > 24 
	IStereoLayers::FLayerDesc StereoLayerDesc(FCylinderLayer(180.f, 488.f / 4, 100.f));
#else
	IStereoLayers::FLayerDesc StereoLayerDesc;
	StereoLayerDesc.CylinderHeight = 180.f;
	StereoLayerDesc.CylinderOverlayArc = 488.f / 4;
	StereoLayerDesc.CylinderRadius = 100.f;
	StereoLayerDesc.ShapeType = IStereoLayers::ELayerShape::CylinderLayer;
#endif
	StereoLayerDesc.Transform = FTransform(FVector(0.f, 0, 0)); //100/0/0 for quads
	StereoLayerDesc.QuadSize = FVector2D(180.f, 180.f);
	StereoLayerDesc.PositionType = IStereoLayers::ELayerType::FaceLocked;
	StereoLayerDesc.LayerSize = Texture->GetTexture2D()->GetSizeXY();
	StereoLayerDesc.Flags = IStereoLayers::ELayerFlags::LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
	StereoLayerDesc.Flags |= IStereoLayers::ELayerFlags::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO;
	DebugRenderNumber = 0;
	//UE_LOG(LogTemp, Log, TEXT("Pvr_UE GetDebugCanvasLayerDesc textureid is %d"), *(GLuint*)Texture->GetTexture2D()->GetNativeResource());
	return StereoLayerDesc;
}

// ISceneViewExtension
void FPicoMobileHMD::SetupViewFamily(FSceneViewFamily& InViewFamily) 
{
#if WITH_EDITOR
	InViewFamily.EngineShowFlags.SetScreenPercentage(false);
#endif
}

void FPicoMobileHMD::SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView){}

void FPicoMobileHMD::BeginRenderViewFamily(FSceneViewFamily& InViewFamily) {}

void FPicoMobileHMD::PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily){}

void FPicoMobileHMD::PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView){}

void FPicoMobileHMD::PostRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily)
{
	check(IsInRenderingThread()|| IsInRHIThread());
#if PLATFORM_ANDROID
	PicoSDK::SeeThrough::SetReinPosition();
#endif

}

FXRRenderBridge * FPicoMobileHMD::GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget)
{	
	check(IsInGameThread());
	check(CustomPresent);	
	if (CustomPresent->IsInitialized())
	{
		return CustomPresent;
	}
	return nullptr;
}

// IStereoRenderTargetManager
bool FPicoMobileHMD::ShouldUseSeparateRenderTarget() const
{
	return true;// IsStereoEnabled();
}

void FPicoMobileHMD::CalculateRenderTargetSize(const class FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY)
{
	check(IsInGameThread());
#if PLATFORM_ANDROID
	InOutSizeX = PicoSDK::Render::GTextureSize.X;
	InOutSizeY = PicoSDK::Render::GTextureSize.Y;
#endif
}

bool FPicoMobileHMD::NeedReAllocateViewportRenderTarget(const FViewport& Viewport)
{
	check(IsInGameThread());

	const uint32 InSizeX = Viewport.GetSizeXY().X;
	const uint32 InSizeY = Viewport.GetSizeXY().Y;

	FIntPoint RTSize;
	RTSize.X = Viewport.GetRenderTargetTexture()->GetSizeX();
	RTSize.Y = Viewport.GetRenderTargetTexture()->GetSizeY();

	uint32 NewSizeX = InSizeX, NewSizeY = InSizeY;
	CalculateRenderTargetSize(Viewport, NewSizeX, NewSizeY);
	if (NewSizeX != RTSize.X || NewSizeY != RTSize.Y)
	{
		return true;
	}
	return false;
}

// FXRTrackingSystemBase
float FPicoMobileHMD::GetWorldToMetersScale() const
{
	if (IsInGameThread() && GWorld != nullptr)
	{
		return GWorld->GetWorldSettings()->WorldToMeters;
	}

	// Default value, assume Unreal units are in centimeters
	return 100.0f;
}

bool FPicoMobileHMD::IsInitialized() const
{
	return bIsRenderThreadInit;
}

void FPicoMobileHMD::InitializRenderThread() 
{
#if PLATFORM_ANDROID
	PicoSDK::Render::RenderThreadInit();
	PicoSDK::Sensor::SensorInit();
	PicoSDK::Sensor::StartSensor(PicoSDK::Sensor::GMainSensorIndex);
	EyeTracker->OpenEyeTracking();
	FPicoJava::HideLoading();
	bIsRenderThreadInit = true;
	AdjustFoveationLevel();
#endif
}
void FPicoMobileHMD::SendResumeEvent()
{
#if PLATFORM_ANDROID
	if (IsInitialized())
	{
		FPlatformProcess::Sleep(1.0f);
		PicoSDK::Sensor::StartSensor(PicoSDK::Sensor::GMainSensorIndex);
		PicoSDK::SendResumeEvent();
		EyeTracker->OpenEyeTracking();
		AdjustFoveationLevel();
	}
#endif

}
void FPicoMobileHMD::SendPauseEvent()
{
#if PLATFORM_ANDROID
	if (IsInitialized()) 
	{
		EyeTracker->bEyeTrackingRun = false;
		PicoSDK::SendPauseEvent();
		PicoSDK::Sensor::StopSensor(PicoSDK::Sensor::GMainSensorIndex);
	}
#endif
}
void FPicoMobileHMD::SendFoveationParam(GLuint RtID)
{
#if PLATFORM_ANDROID
	//Foveation
	FVector EyeDirection = FVector::ZeroVector;
	if (PicoSettings->bEnableEyeTracking)
	{
		EyeTracker->GetEyeDirectionToFoveationRendering(EyeDirection);
	}
	PicoSDK::Render::SetFoveationResource(RtID, PicoSDK::Render::PreviousId, EyeDirection);
	PicoSDK::Render::PreviousId = RtID;
	PicoSDK::Render::SendFoveationEvent();
#endif
}

void FPicoMobileHMD::AdjustFoveationLevel()
{
#if PLATFORM_ANDROID
	FString Value = FPicoJava::GetSystemProperty("pvrsist.foveation.level");
	UE_LOG(LogTemp,Log,TEXT("GetSystemProperty pvrsist.foveation.level  %s"),*Value);
	if (Value == "")
	{
		Value = "-1";
	}
	PicoSDK::Render::SystemFoveationLevel = FCString::Atoi(*Value);
	if (PicoSDK::Render::SystemFoveationLevel != -1)
	{
		PicoSettings->bEnableFoveationRendering = true;
		PicoSettings->FoveationLevel = static_cast<EFoveationLevel::Type>(PicoSDK::Render::SystemFoveationLevel);
	}else
	{
		PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::EnableFoveationRenderBySystem, PicoSDK::Render::SystemFoveationLevel);
		UE_LOG(LogTemp,Log,TEXT("GetIntConfig about Foveation =  %d"), PicoSDK::Render::SystemFoveationLevel);
	}
	if (PicoSDK::Render::SystemFoveationLevel != -1)
	{
		PicoSettings->bEnableFoveationRendering = true;
		PicoSettings->FoveationLevel = static_cast<EFoveationLevel::Type>(PicoSDK::Render::SystemFoveationLevel);
	}
	
	PicoSDK::Render::FoveationRendering = PicoSettings->bEnableFoveationRendering;
	if (PicoSDK::Render::FoveationRendering)
	{
		PicoSDK::Render::SetFoveationLevel((int32)PicoSettings->FoveationLevel);
	}else
	{
		PicoImport::PvrSetFoveationLevel(-1);
	}
#endif
}

void FPicoMobileHMD::LimitBoundaryFrameRate()
{
#if PLATFORM_ANDROID
	check(IsInRenderingThread()|| IsInRHIThread());

	// SeeThrough boundary
	PicoSDK::SeeThrough::SeeThroughState = PicoSDK::SeeThrough::GetSeeThroughState();
	if (PicoSDK::SeeThrough::SeeThroughState == 2 && PicoImport::PvrGetFrameRateLimit())
	{
		if (!(GEngine->bUseFixedFrameRate && GEngine->FixedFrameRate == 30.101f))
		{
			if (GEngine->bUseFixedFrameRate && GEngine->FixedFrameRate != 30.101f)
			{
				UseFixedFrameRate = true;
				FixedFrameRate = GEngine->FixedFrameRate;
				GEngine->FixedFrameRate = 30.101f;
			}
			else
			{
				GEngine->bUseFixedFrameRate = true;
				GEngine->FixedFrameRate = 30.101f;
				UseFixedFrameRate = false;
			}
		}	
	}
	else
	{
		if (GEngine->bUseFixedFrameRate && GEngine->FixedFrameRate == 30.101f)
		{
			GEngine->bUseFixedFrameRate = UseFixedFrameRate;
			GEngine->FixedFrameRate = FixedFrameRate;
		}
	}

#endif
}

void FPicoMobileHMD::EnableEyeMarker(bool enable)
{
	PicoSettings->bEnableEyeTrackingMarker = enable;
}

void FPicoMobileHMD::ConnectToAndroid()
{
#if PLATFORM_ANDROID
	PicoImport::PvrSetInitActivity(FAndroidApplication::GetGameActivityThis(), FPicoJava::GetRawClass());
#endif
}

void FPicoMobileHMD::SubmitUnrealInfo()
{
#if PLATFORM_ANDROID
	// to notificate so Unreal Version
	UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE DISFT Unreal Version: %d "), (int)(ENGINE_MINOR_VERSION));
	PicoSDK::Render::PvrSetUnrealParam((int32)UnrealParamKeys::UNREAL_VERSION, (int32)ENGINE_MINOR_VERSION);
	
	// to notificate so builf type
#if UE_BUILD_DEBUG 
	UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE UE_BUILD_DEBUG 0 "));
	PicoSDK::Render::PvrSetUnrealParam((int32)UnrealParamKeys::BUILD_TYPE, 0);
#endif
#if UE_BUILD_DEVELOPMENT
	UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE UE_BUILD_DEVELOPMENT 1 "));
	PicoSDK::Render::PvrSetUnrealParam((int32)UnrealParamKeys::BUILD_TYPE, 1);
#endif
#if UE_BUILD_SHIPPING
	UE_LOG(LogPicoHMD, Log, TEXT("Pvr_UE UE_BUILD_SHIPPING 2 "));
	PicoSDK::Render::PvrSetUnrealParam((int32)UnrealParamKeys::BUILD_TYPE, 2);
#endif
#endif
}

bool FPicoMobileHMD::Startup()
{
#if PLATFORM_ANDROID
	bool ret = PicoImport::Init();// Import so
	check(ret);

	IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.MobileContentScaleFactor"));
	CVar->Set(0.0f);

	ConnectToAndroid();// Init activity

	FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddRaw(this, &FPicoMobileHMD::ApplicationPauseDelegate);
	FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddRaw(this, &FPicoMobileHMD::ApplicationResumeDelegate);

	
	if (GetMultiViewState())
	{
		bUsesArrayTexture = true;
	}
	static const auto PixelDensityCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
	SetPixelDensity(FMath::Clamp(PixelDensityCVar->GetFloat(), 0.1f, 2.0f));
	

	//PicoSDK::Render::GetTextureSize(PicoSDK::Render::GTextureSize);
	PicoSDK::Render::GetFOV(PicoSDK::Sensor::GFov);
	PicoSDK::Render::GetFOV(PicoSDK::Sensor::GVFov,PicoSDK::Sensor::GHFov);
	PicoSDK::Sensor::GetNeckOffset();
	PicoSDK::Sensor::GetWorldToMetersScale();
	PicoSDK::Render::CurrentIPD = PicoImport::PvrGetIPD();
	SetTrackingOrigin(EHMDTrackingOrigin::Eye);

	IConsoleVariable* CVSyns = IConsoleManager::Get().FindConsoleVariable(TEXT("r.VSync"));
	CVSyns->Set(0.0f);
	IConsoleVariable* CFCFVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FinishCurrentFrame"));
	CFCFVar->Set(0.0f);
	PicoSDK::Render::GetDisplayRefreshRate(PicoSDK::Render::DisplayRate);
	LimitFrameRate();
	PicoSDK::Render::EnableFoveation(true);
	PicoSDK::Render::EnableMultiView(bUsesArrayTexture);
	CustomPresent = new FPicoCustomPresent(this);
	PicoSplash = MakeShareable(new FPicoVRSplash(this));
	PicoSplash->Startup();
	DoAppCheck();
	return ret;
#endif
	
	return false;
}

void FPicoMobileHMD::Shutdown()
{
#if PLATFORM_ANDROID
	PicoSDK::SeeThrough::EndCameraFrame();
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "resetHomeKey","()V",false);
	FJavaWrapper::CallVoidMethod(Env,FJavaWrapper::GameActivityThis,Method);
	if (IsInRenderingThread()|| IsInRHIThread())
	{
		if (IsInitialized())
		{
			PicoSDK::Sensor::StopSensor(PicoSDK::Sensor::GMainSensorIndex);
			PicoSDK::Render::RenderThreadShutdown();
			check(GJavaVM);
			GJavaVM->DetachCurrentThread();
		}
		PicoImport::Uninit();
	}
	else
	{
		ExecuteOnRenderThread([this]()
		{
			if (this->IsInitialized())
			{
				PicoSDK::Sensor::StopSensor(PicoSDK::Sensor::GMainSensorIndex);
				PicoSDK::Render::RenderThreadShutdown();
				check(GJavaVM);
				GJavaVM->DetachCurrentThread();
			}
			PicoImport::Uninit();
		});
	}
	if (PicoSplash)
	{
		PicoSplash->Shutdown();
		PicoSplash = nullptr;
	}
	if (CustomPresent)
	{
		CustomPresent->ShutDown();
		CustomPresent = nullptr;
	}
#endif
}

void FPicoMobileHMD::ApplicationPauseDelegate()
{
#if PLATFORM_ANDROID
	if (IsInitialized())
	{
		ExecuteOnRenderThread([this]()
		{
			ExecuteOnRHIThread([this]()
			{
				this->SendPauseEvent();
			});
		});
	}
#endif
}

void FPicoMobileHMD::ApplicationResumeDelegate()
{
#if PLATFORM_ANDROID	
	PicoSDK::Render::CurrentIPD = PicoImport::PvrGetIPD();
	if (IsInitialized())
	{
		ExecuteOnRenderThread([this]()
		{
			ExecuteOnRHIThread([this]()
			{
				this->SendResumeEvent();
			});	
		});	
	}
#endif
}

void FPicoMobileHMD::DebugRendering()
{
#if PLATFORM_ANDROID

	if (DebugTexture != nullptr && DebugRenderNumber <= 4)
	{
		float mMVFloat[16] = { 3,0,0,0.5f,
							   0,3,0,-0.5f,
							   0,0,-3,-2,
							   0,0,0,1 };

		float scaleM[3] = {1.0f};
		float rotationM[4] = {0.0f};
		float translationM[3] = { 0.0f };
		float rotationC[4] = { 0.0f };
		float translationC[3] = { 0.0f };
		float colorScaleOffset[8] = { 1.0f,1.0f,1.0f,1.0f,0,0,0,0 };
		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, *(GLuint*)DebugTexture->GetTexture2D()->GetNativeResource(), 1, 15, true, 0,
			mMVFloat, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, *(GLuint*)DebugTexture->GetTexture2D()->GetNativeResource(), 0, 15, true, 0,
			mMVFloat, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
		DebugRenderNumber++;
	}
#endif
}

void FPicoMobileHMD::OverlayRendering(FPoseData& currentPose)
{
#if PLATFORM_ANDROID
	if (IsInitialized()&& LayerSortIndex.Num() > 0 )
	{
		FPicoVRStereoLayerPtr* LayerFound = nullptr;
		int32 layerIndex = 0;
		for (TPair<uint32, int32>& element : LayerSortIndex)
		{
			LayerFound = PicoLayerMap.Find(element.Key);
			if (LayerFound)
			{
				GLuint RTexID = (*LayerFound)->GetRTexID();
				GLuint LTexID = (*LayerFound)->GetLTexID();

				FQuat CamRotation = currentPose.Orientation;
				FVector CamLocation = currentPose.Position + InitCamPos;

				float ipd = GetInterpupillaryDistance();
				float leftOffset = ipd/2;
				float rightOffset = -ipd/2;

				FMatrix leftOffsetMat;
				leftOffsetMat.SetIdentity();
				leftOffsetMat.M[0][3] = leftOffset;

				FMatrix rightOffsetMat;
				rightOffsetMat.SetIdentity();
				rightOffsetMat.M[0][3] = rightOffset;

				FMatrix mMVMatrixLeft = leftOffsetMat * ((*LayerFound)->GetLayerMV(CamRotation, CamLocation, isFixOverlay));
				FMatrix mMVMatrixRight = rightOffsetMat * ((*LayerFound)->GetLayerMV(CamRotation, CamLocation, isFixOverlay));

				float mMVFloatLeft[16];
				int l = 0;
				for (int32 i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						mMVFloatLeft[l] = mMVMatrixLeft.M[i][j];
						l++;
					}
				}
				l = 0;
				float mMVFloatRight[16];
				for (int32 i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						mMVFloatRight[l] = mMVMatrixRight.M[i][j];
						l++;
					}
				}

				float scaleM[3] = { (*LayerFound)->GetLayerLocation().X,(*LayerFound)->GetLayerLocation().Y ,(*LayerFound)->GetLayerLocation().Z };
				float rotationM[4] = { (*LayerFound)->GetLayerOrientation().X,(*LayerFound)->GetLayerOrientation().Y ,(*LayerFound)->GetLayerOrientation().Z ,(*LayerFound)->GetLayerOrientation().W };
				float translationM[3] = { (*LayerFound)->GetLayerScale().X,(*LayerFound)->GetLayerScale().Y ,(*LayerFound)->GetLayerScale().Z };
				float rotationC[4] = { CamRotation.X,CamRotation.Y,CamRotation.Z,CamRotation.W };
				float translationC[3] = { CamLocation.X,CamLocation.Y,CamLocation.Z };

				float colorScaleOffset[8] = { 1.0f,1.0f,1.0f,1.0f,0,0,0,0 };
				layerIndex++;
				//layerType imageType texid eye layerindex fixedoverlay mv 
				PicoImport::PvrSetOverlayModelViewMatrix(0, 0, RTexID, 1, layerIndex, isFixOverlay, 0, mMVFloatRight, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
				PicoImport::PvrSetOverlayModelViewMatrix(0, 0, LTexID, 0, layerIndex, isFixOverlay, 0, mMVFloatLeft, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
			}
		}
	}
#endif
}


void FPicoMobileHMD::EyeTrackingMarkerRendering()
{
#if PLATFORM_ANDROID
	if (PicoSettings->bEnableEyeTracking && PicoSettings->bEnableEyeTrackingMarker)
	{
		auto ReticleTextureId = mTextureSet->GetReticleTextureResource();
		FVector EyeDirect = FVector::ZeroVector;
		EyeTracker->GetEyeDirectionToFoveationRendering(EyeDirect);
		FVector EyeMakerTextureScale = FVector(0.05, 0.05, 0.05);

		float mMVFloat[16] = { EyeMakerTextureScale.X,    0,    0,  EyeDirect.X,
								0,	EyeMakerTextureScale.Y,      0,	 EyeDirect.Y,
								0,      0,    -EyeMakerTextureScale.Z,		-1,
								0, 0 , 0 , 1 };

		float scaleM[3] = { 1.0f };
		float rotationM[4] = { 0.0f };
		float translationM[3] = { 0.0f };
		float rotationC[4] = { 0.0f };
		float translationC[3] = { 0.0f };
		float colorScaleOffset[8] = { 1.0f,1.0f,1.0f,1.0f,0,0,0,0 };

		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, ReticleTextureId, 1, 14, true, 0,mMVFloat, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
		PicoImport::PvrSetOverlayModelViewMatrix(0, 0, ReticleTextureId, 0, 14, true, 0,mMVFloat, scaleM, rotationM, translationM, rotationC, translationC, colorScaleOffset);
	}
#endif
}

#undef LOCTEXT_NAMESPACE
