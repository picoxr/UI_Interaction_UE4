// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "PXR_HMD.h"
#include "PXR_HMDRenderBridge.h"
#include "PXR_Settings.h"
#include "PostProcess/RenderingCompositionGraph.h"
#include "XRThreadUtils.h"
#include "PXR_Input.h"
#include "IHeadMountedDisplayVulkanExtensions.h"
#include "PXR_Log.h"
#include "PXR_StereoLayer.h"
#include "PXR_HMDFunctionLibrary.h"

#if PLATFORM_ANDROID
#include "HardwareInfo.h"
#include "OpenGLDrvPrivate.h"
#include "OpenGLResources.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PXR_Utils.h"
#include "PxrInput.h"
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#endif

float FPicoXRHMD::IpdValue = 0.f;
int32 FPicoXRHMD::SubmitViewNumber = -1;
FQuat FPicoXRHMD::SubmitOrientation = FQuat::Identity;
FVector FPicoXRHMD::SubmitPosition = FVector::ZeroVector;
FTransform FPicoXRHMD::SubmitTrackingToWorld = FTransform::Identity;
bool  FPicoXRHMD::GIsMapPost = false;
int32 FPicoXRHMD::GMapInitFrame = 0;
FName FPicoXRHMD::GetSystemName() const
{
    static FName DefaultName(TEXT("PicoXRHMD"));
    return DefaultName;
}

bool FPicoXRHMD::EnumerateTrackedDevices(TArray<int32>& OutDevices, EXRTrackedDeviceType Type /*= EXRTrackedDeviceType::Any*/)
{
	if (Type == EXRTrackedDeviceType::Any || Type == EXRTrackedDeviceType::HeadMountedDisplay)
	{
		OutDevices.Add(HMDDeviceId);
		return true;
	}
	return false;
}

void FPicoXRHMD::SetInterpupillaryDistance(float NewIPD)
{
	//TODO:SetIPD(NewIPD);
}

float FPicoXRHMD::GetInterpupillaryDistance() const
{
	return UPxr_GetIPD();
}

bool FPicoXRHMD::GetRelativeEyePose(int32 InDeviceId, EStereoscopicPass InEye, FQuat& OutOrientation, FVector& OutPosition)
{
	OutOrientation = FQuat::Identity;
	OutPosition = FVector::ZeroVector;
	if (InDeviceId == HMDDeviceId && (InEye == eSSP_LEFT_EYE || InEye == eSSP_RIGHT_EYE))
	{
		OutPosition = FVector(0, (InEye == eSSP_LEFT_EYE ? -.5 : .5) * GetInterpupillaryDistance() * GetWorldToMetersScale(), 0);
		return true;
	}
	return false;
}

void FPicoXRHMD::ResetOrientationAndPosition(float Yaw /*= 0.f*/)
{
	ResetOrientation(Yaw);
	ResetPosition();
}

void FPicoXRHMD::ResetOrientation(float Yaw /*= 0.f*/)
{
#if PLATFORM_ANDROID
 	Pxr_ResetSensor(PxrResetSensorOption::PXR_RESET_ORIENTATION);
#endif
}

void FPicoXRHMD::ResetPosition()
{
#if PLATFORM_ANDROID
 	Pxr_ResetSensor(PxrResetSensorOption::PXR_RESET_POSITION);
#endif
}

bool FPicoXRHMD::GetCurrentPose(int32 DeviceId, FQuat& CurrentOrientation, FVector& CurrentPosition)
{
	if (DeviceId != HMDDeviceId)
	{
		return false;
	}
#if PLATFORM_ANDROID
	if (IsInRenderingThread())
	{
		if (bIsEndGameFrame)
		{
			bIsEndGameFrame = false;
			UpdateSensorValue();
		}
		CurrentOrientation = CurrentFrameValue_RenderThread.CurrentOrientation;
		CurrentPosition = CurrentFrameValue_RenderThread.CurrentPosition;
	}
	else if (IsInGameThread())
	{
		CurrentOrientation = CurrentFrameValue_GameThread.CurrentOrientation;
		CurrentPosition = CurrentFrameValue_GameThread.CurrentPosition;
	}
 	PXR_LOGV(PxrUnreal,"CurrentPose(%f,%f,%f) (%f,%f,%f,%f)",CurrentPosition.X,CurrentPosition.Y,CurrentPosition.Z,CurrentOrientation.X,CurrentOrientation.Y,CurrentOrientation.Z,CurrentOrientation.W);
#endif
 	return true;
}

void FPicoXRHMD::UPxr_GetAngularAcceleration(FVector& AngularAcceleration)
{
#if PLATFORM_ANDROID
	AngularAcceleration = CurrentFrameValue_RenderThread.AngularAcceleration;
#endif
}

void FPicoXRHMD::UPxr_GetVelocity(FVector& Velocity)
{
#if PLATFORM_ANDROID
	Velocity = CurrentFrameValue_RenderThread.Velocity;
#endif
}

void FPicoXRHMD::UPxr_GetAcceleration(FVector& Acceleration)
{
#if PLATFORM_ANDROID
	Acceleration = CurrentFrameValue_RenderThread.Acceleration;
#endif
}

void FPicoXRHMD::UPxr_GetAngularVelocity(FVector& AngularVelocity)
{
#if PLATFORM_ANDROID
	AngularVelocity = CurrentFrameValue_RenderThread.AngularVelocity;
#endif
}

FString FPicoXRHMD::UPxr_GetDeviceModel()
{
	return DeviceModel;
}

void FPicoXRHMD::SetBaseRotation(const FRotator& BaseRot)
{
}

FRotator FPicoXRHMD::GetBaseRotation() const
{
	return FRotator::ZeroRotator;
}

void FPicoXRHMD::SetBaseOrientation(const FQuat& BaseOrient)
{
}

FQuat FPicoXRHMD::GetBaseOrientation() const
{
	return FQuat::Identity;
}

void FPicoXRHMD::SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin)
{
#if PLATFORM_ANDROID
    switch (NewOrigin)
    {
	    case EHMDTrackingOrigin::Eye:
	    	{
				Pxr_SetTrackingOrigin(PxrTrackingOrigin::PXR_EYE_LEVEL);
	    		PXR_LOGD(PxrUnreal,"SetTrackingOrigin:EHMDTrackingOrigin::Eye");
	    		TrackingOrigin = NewOrigin;
	    		break;
	    	}
		case EHMDTrackingOrigin::Floor:
	    	{
				Pxr_SetTrackingOrigin(PxrTrackingOrigin::PXR_FLOOR_LEVEL);
	    		PXR_LOGD(PxrUnreal,"SetTrackingOrigin:EHMDTrackingOrigin::Floor");
	    		TrackingOrigin = NewOrigin;
	    		break;
	    	}
    	case EHMDTrackingOrigin::Stage:
	    	{
				Pxr_SetTrackingOrigin(PxrTrackingOrigin::PXR_STAGE_LEVEL);
	    		PXR_LOGD(PxrUnreal,"SetTrackingOrigin:EHMDTrackingOrigin::Stage");
	    		TrackingOrigin = NewOrigin;
	    		break;
	    	}
    	default:
    		break;
    }
#endif
}

EHMDTrackingOrigin::Type FPicoXRHMD::GetTrackingOrigin() const
{
	return TrackingOrigin;
}

class TSharedPtr< class IStereoRendering, ESPMode::ThreadSafe > FPicoXRHMD::GetStereoRenderingDevice()
{
	return SharedThis(this);
}

float FPicoXRHMD::GetWorldToMetersScale() const
{
 	if (IsInGameThread() && GWorld != nullptr)
 	{
 		return GWorld->GetWorldSettings()->WorldToMeters;
 	}
 	return 100.0f;
}

bool FPicoXRHMD::DoesSupportPositionalTracking() const
{
	return !PicoXRSetting->bIsHMD3Dof;
}

bool FPicoXRHMD::IsHMDEnabled() const
{
	return true;
}

void FPicoXRHMD::EnableHMD(bool Allow /*= true*/)
{
}

bool FPicoXRHMD::GetHMDMonitorInfo(MonitorInfo &MonitorDesc)
{
	check(IsInGameThread());
	MonitorDesc.MonitorName = FString("PicoXR Window");
	MonitorDesc.MonitorId = 0;
	MonitorDesc.DesktopX = MonitorDesc.DesktopY = 0;
	MonitorDesc.ResolutionX = MonitorDesc.ResolutionY = 0;
	MonitorDesc.WindowSizeX = MonitorDesc.WindowSizeY = 0;

	MonitorDesc.ResolutionX = MonitorDesc.WindowSizeX = RTSize.X;
	MonitorDesc.ResolutionY = MonitorDesc.WindowSizeY = RTSize.Y;

	return true;
}

void FPicoXRHMD::GetFieldOfView(float& OutHFOVInDegrees, float& OutVFOVInDegrees) const
{
	FPicoXRFrustum Frustum = LeftFrustum;
	const float LeftHFOVInDegrees = FMath::RadiansToDegrees(Frustum.FovRight - Frustum.FovLeft);
	const float LeftVFOVInDegrees = FMath::RadiansToDegrees(Frustum.FovUp - Frustum.FovDown);
	Frustum = RightFrustum;
	const float RightHFOVInDegrees = FMath::RadiansToDegrees(Frustum.FovRight - Frustum.FovLeft);
	const float RightVFOVInDegrees = (Frustum.FovUp - Frustum.FovDown);
	OutHFOVInDegrees = (LeftHFOVInDegrees+RightHFOVInDegrees)/2;
	OutVFOVInDegrees = (LeftVFOVInDegrees+RightVFOVInDegrees)/2;
}

bool FPicoXRHMD::IsChromaAbCorrectionEnabled() const
{
	return false;
}

FIntPoint FPicoXRHMD::GetIdealRenderTargetSize() const
{
	FIntPoint IdealRenderTargetSize;
 	IdealRenderTargetSize.X = FMath::CeilToInt(RTSize.X* PixelDensity / (bIsMobileMultiViewEnabled ? 2 : 1));
 	IdealRenderTargetSize.Y = FMath::CeilToInt(RTSize.Y * PixelDensity);

	FIntPoint MaxRenderTextureSize = FIntPoint(8192, 4096);
	if (DeviceModel.Contains("G2") && PicoXRSetting->bEnableFoveation)
	{
		PXR_LOGD(PxrUnreal, "The max RenderTexture size is (4160,2080) if the Device is G2/G2 4K !");
		MaxRenderTextureSize.X = 4160;
		MaxRenderTextureSize.Y = 2080;
	}

	const uint32 DividableBy = 4;
	const uint32 Mask = ~(DividableBy - 1);
	IdealRenderTargetSize.X = (IdealRenderTargetSize.X + DividableBy - 1) & Mask;
	IdealRenderTargetSize.Y = (IdealRenderTargetSize.Y + DividableBy - 1) & Mask;
	IdealRenderTargetSize.X = IdealRenderTargetSize.X > MaxRenderTextureSize.X ? MaxRenderTextureSize.X : IdealRenderTargetSize.X;
	IdealRenderTargetSize.Y = IdealRenderTargetSize.Y > MaxRenderTextureSize.Y ? MaxRenderTextureSize.Y : IdealRenderTargetSize.Y;

	PXR_LOGD(PxrUnreal,"GetIdealRenderTargetSize  RenderTextureSize:%d,%d", IdealRenderTargetSize.X , IdealRenderTargetSize.Y);
	return IdealRenderTargetSize;
}

void FPicoXRHMD::OnBeginRendering_GameThread()
{
	if (!bIsBindDelegate)
	{
		FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddRaw(this, &FPicoXRHMD::ApplicationPauseDelegate);
		FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddRaw(this, &FPicoXRHMD::ApplicationResumeDelegate);
		bIsBindDelegate = true;
	}
}

bool FPicoXRHMD::OnStartGameFrame(FWorldContext& WorldContext)
{
	PollEvent();
	RefreshTrackingToWorldTransform(WorldContext);
#if PLATFORM_ANDROID
 	if (FPicoXRHMD::GIsMapPost)
 	{
 		if (FPicoXRHMD::GMapInitFrame == 5)
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
 			FPicoXRHMD::GIsMapPost = false;
 			FPicoXRHMD::GMapInitFrame = 1;
 		}
 		else
 		{
 			PreCamPos = CurrentFrameValue_GameThread.CurrentPosition;
 			FPicoXRHMD::GMapInitFrame++;
 		}
 	}
    CurrentFrameValue_RenderThread.WorldToMetersScale = GetWorldToMetersScale();

	LastFrameValue_GameThread = CurrentFrameValue_GameThread;
	CurrentFrameValue_GameThread = LastFrameValue_RenderThread;
#endif
	return true;
}

bool FPicoXRHMD::OnEndGameFrame(FWorldContext& WorldContext)
{
#if PLATFORM_ANDROID
	CurrentFrameValue_GameThread.TrackingToWorld = ComputeTrackingToWorldTransform(WorldContext);
	ExecuteOnRenderThread_DoNotWait([this]()
	{
		LastFrameValue_RenderThread = CurrentFrameValue_RenderThread;
		CurrentFrameValue_RenderThread = CurrentFrameValue_GameThread;
		this->bIsEndGameFrame = true;
	});
#endif
	return true;
}

bool FPicoXRHMD::IsStereoEnabled() const
{
	return true;
}

bool FPicoXRHMD::EnableStereo(bool Stereo /*= true*/)
{
	return true;
}

void FPicoXRHMD::AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
	const FIntPoint RenderTargetSize = GetIdealRenderTargetSize();
	if(!bIsMobileMultiViewEnabled)
	{
		SizeX = RenderTargetSize.X / 2;
	}else
	{
		SizeX = RenderTargetSize.X;
	}
	SizeY = RenderTargetSize.Y;
	if (StereoPass == eSSP_RIGHT_EYE && !bIsMobileMultiViewEnabled)
	{
		X += SizeX;
	}
	PXR_LOGD(PxrUnreal,"AdjustViewRect StereoPass:%d ,X: %d,Y: %d ,SizeX: %d,SizeY: %d)", (int)StereoPass, X, Y, SizeX, SizeY);
}

FMatrix FPicoXRHMD::GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType) const
{
	FPicoXRFrustum Frustum = (StereoPassType == eSSP_LEFT_EYE) ? LeftFrustum : RightFrustum;
	const float ProjectionCenterOffset = 0;// 0.151976421f;
	const float PassProjectionOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionCenterOffset : -ProjectionCenterOffset;
	//float ZNear = Frustum.Near;
	const float ZNear = GNearClippingPlane;
	Frustum.FovUp = tan(Frustum.FovUp);
	Frustum.FovDown = tan(Frustum.FovDown);
	Frustum.FovLeft = tan(Frustum.FovLeft);
	Frustum.FovRight = tan(Frustum.FovRight);
	float SumRL = (Frustum.FovRight + Frustum.FovLeft);
	float SumTB = (Frustum.FovUp + Frustum.FovDown);
	float InvRL = (1.0f / (Frustum.FovRight - Frustum.FovLeft));
	float InvTB = (1.0f / (Frustum.FovUp - Frustum.FovDown));
	FMatrix ProjectionMatrix = FMatrix(
		FPlane((2.0f * InvRL), 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, (2.0f * InvTB), 0.0f, 0.0f),
		FPlane((SumRL * -InvRL), (SumTB * -InvTB), 0.0f, 1.0f),
		FPlane(0.0f, 0.0f, ZNear, 0.0f)) * FTranslationMatrix(FVector(PassProjectionOffset, 0, 0));
	return ProjectionMatrix;
}

void FPicoXRHMD::GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const
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

FPicoXRHMD::FPicoXRHMD(const FAutoRegister&AutoRegister)
	: FHeadMountedDisplayBase(nullptr)
	, FSceneViewExtensionBase(AutoRegister)
	, CurrentLayerId(0)
	, InitCamPos(FVector::ZeroVector)
	, PreCamPos(FVector::ZeroVector)
	,CurrentFrameValue_RenderThread(FCurrentFrameValue())
	, bIsMobileMultiViewEnabled(false)
	, PixelDensity(1)
	, RTSize(FIntPoint(4096, 2048))
	, MobileMSAAValue(0)
	, LastFrameValue_RenderThread(FCurrentFrameValue())
	, CurrentFrameValue_GameThread(FCurrentFrameValue())
	, LastFrameValue_GameThread(FCurrentFrameValue())
	, NeckOffset(FVector::ZeroVector)
	, RenderBridge(nullptr)
	, PicoXRSetting(nullptr)
	, bIsBindDelegate(false)
	, bIsEndGameFrame(false)
	, TrackingOrigin(EHMDTrackingOrigin::Eye)
	, PlayerController(nullptr)
	, FrameState(EFrameState::NeedToBeginFrame)
	, PicoSplash(nullptr)
{
	EventManager = UPicoXREventManager::GetInstance();
	PicoXRSetting = GetMutableDefault<UPicoXRSettings>();
#if PLATFORM_ANDROID
	DeviceModel = FAndroidMisc::GetDeviceModel();
#endif
}

FPicoXRHMD::~FPicoXRHMD()
{
	Shutdown();
}

void FPicoXRHMD::BeginXR()
{
#if PLATFORM_ANDROID
    //Frustum
    Pxr_GetFrustum(PXR_EYE_LEFT, &LeftFrustum.FovLeft, &LeftFrustum.FovRight, &LeftFrustum.FovUp, &LeftFrustum.FovDown,&LeftFrustum.Near,&LeftFrustum.Far);
    Pxr_GetFrustum(PXR_EYE_RIGHT, &RightFrustum.FovLeft, &RightFrustum.FovRight, &RightFrustum.FovUp, &RightFrustum.FovDown,&RightFrustum.Near,&RightFrustum.Far);

 	LeftFrustum.FovLeft = FMath::Atan(LeftFrustum.FovLeft/LeftFrustum.Near);
 	LeftFrustum.FovRight = FMath::Atan(LeftFrustum.FovRight/LeftFrustum.Near);
 	LeftFrustum.FovUp = FMath::Atan(LeftFrustum.FovUp/LeftFrustum.Near);
 	LeftFrustum.FovDown = FMath::Atan(LeftFrustum.FovDown/LeftFrustum.Near);

 	RightFrustum.FovLeft = FMath::Atan(RightFrustum.FovLeft/RightFrustum.Near);
 	RightFrustum.FovRight = FMath::Atan(RightFrustum.FovRight/RightFrustum.Near);
 	RightFrustum.FovUp = FMath::Atan(RightFrustum.FovUp/RightFrustum.Near);
 	RightFrustum.FovDown = FMath::Atan(RightFrustum.FovDown/RightFrustum.Near);

 	//NeckOffset
 	UpdateNeckOffset();
 	IpdValue = Pxr_GetIPD();
 	PXR_LOGI(PxrUnreal,"Startup Get ipd = %f",IpdValue);

 	ExecuteOnRenderThread([this]()
 	{
 		ExecuteOnRHIThread([this]()
        {
 			if (!Pxr_IsRunning())
            {
				if (true)
                {
					SetRefreshRate();
					Pxr_BeginXr();
                }
                else
                {
                    PXR_LOGF(PxrUnreal,"BeginVR: Pxr_CanBeginVR return false");
                }
            }
        });
    });
	Pxr_SetControllerEnableKey(PicoXRSetting->bEnableHomeKey, PxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME);
    uint32_t device;
	Pxr_GetControllerMainInputHandle(&device);
#endif
}

void FPicoXRHMD::EndXR()
{
#if PLATFORM_ANDROID
	Pxr_SetControllerEnableKey(false, PxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME);
	if (IsInGameThread())
	{
		ExecuteOnRenderThread([this]()
        {
			ExecuteOnRHIThread([this]()
	        {
				Pxr_EndXr();
	        });
        });
	}
#endif
}

FPicoXRInput* FPicoXRHMD::GetPicoXRInput()
{
	TArray<IMotionController*> MotionControllers = IModularFeatures::Get().GetModularFeatureImplementations<IMotionController>(IMotionController::GetModularFeatureName());
	for (auto MotionController : MotionControllers)
	{
		if (MotionController != nullptr && MotionController->GetMotionControllerDeviceTypeName() == FName(TEXT("PicoXRInput")))
		{
			return static_cast<FPicoXRInput*>(MotionController);
		}else
		{
			PXR_LOGE(PxrUnreal,"GetPicoXRInput failed");
		}
	}
	return nullptr;
}

void FPicoXRHMD::BeginFrame_RHIThread()
{
#if PLATFORM_ANDROID
 	if (Pxr_IsRunning() && FrameState == EFrameState::NeedToBeginFrame)
 	{
 		RefreshLayers_RHIThread();
 		Pxr_BeginFrame();
 		TMap<uint32,FPicoLayerPtr> XSplashLayers = PicoSplash->SplashLayersMap;
        if (XSplashLayers.Num()>0)
        {
 			for (auto SplashLayer : XSplashLayers)
 			{
 				SplashLayer.Value->IncrementSwapChainIndex_RHIThread(RenderBridge);
 			}
        }
#if ENGINE_MINOR_VERSION==24
		if (Layers_RenderThread.Num() > 0)
		{
			if (!PicoSplash->IsShown())
			{
				for (auto Layer : Layers_RenderThread)
				{
					Layer->IncrementSwapChainIndex_RHIThread(RenderBridge);
				}
			}
			else
			{
				if (Layers_RenderThread[0].IsValid())
				{
					Layers_RenderThread[0]->IncrementSwapChainIndex_RHIThread(RenderBridge);
				}
			}
		}
#else
 		TMap<uint32,FPicoLayerPtr> XLayers = LayerMap;
 		if (XLayers.Num()>0)
		{
 			if (!PicoSplash->IsShown())
 			{
 				for (auto Layer : XLayers)
 				{
 					Layer.Value->IncrementSwapChainIndex_RHIThread(RenderBridge);
 				}
 			}
 			else
 			{
 				if (LayerMap[0].IsValid())
 					{
 						LayerMap[0]->IncrementSwapChainIndex_RHIThread(RenderBridge);
 					}
 			}
 		}
#endif
 		FrameState = EFrameState::NeedToEndFrame;
 	}
#endif
}

void FPicoXRHMD::SplashShow(FRHICommandListImmediate& RHICmdList)
{
	#if PLATFORM_ANDROID
	if (PicoSplash->IsShown())
		{
			if (PicoSplash->SplashLayersMap.Num() > 0)
			{
				if (RHIString != TEXT("Vulkan")) {
					FRHITexture2D* SrcTexture = LayerMap[0]->GetSwapChain()->GetTexture2D();
					ClearTexture_RHIThread(SrcTexture);
				}
				TArray<FPicoLayerPtr> XLayers;
				XLayers.Empty(PicoSplash->SplashLayersMap.Num());
				for(auto Splash:PicoSplash->SplashLayersMap)
				{
					Splash.Value->RefreshLayers_RenderThread(RenderBridge, RHICmdList);
					XLayers.Emplace(Splash.Value->Clone());
				}
				XLayers.Sort(FPicoXRStereoLayerPtr_ComparePriority());
				for (auto SplashLayer:XLayers)
				{
					if (static_cast<int32>(SplashLayer->GetLayerState()) > 1)
					{
						SplashLayer->SubmitCompositionLayerRenderMatrix_RHIThread(PlayerController, SubmitOrientation, SubmitPosition, SubmitTrackingToWorld);
					}
				}
			}
		}

#endif
}

void FPicoXRHMD::EndFrame_RHIThread()
{
#if PLATFORM_ANDROID
    if (Pxr_IsRunning() && FrameState == EFrameState::NeedToEndFrame)
    {
#if ENGINE_MINOR_VERSION==24
		if (!PicoSplash->IsShown())
		{
			for (auto Layer : Layers_RenderThread)
			{
				Layer->SubmitCompositionLayerRenderMatrix_RHIThread(PlayerController, SubmitOrientation, SubmitPosition, SubmitTrackingToWorld);
			}
		}
#else
		if (!PicoSplash->IsShown())
		{
			TArray<FPicoLayerPtr> XLayers;
			XLayers.Empty(LayerMap.Num());
			for (auto Pair : LayerMap)
			{
				XLayers.Emplace(Pair.Value->Clone());
			}
			XLayers.Sort(FPicoXRStereoLayerPtr_ComparePriority());

			for (auto Layer : XLayers)
			{
				Layer->SubmitCompositionLayerRenderMatrix_RHIThread(PlayerController, SubmitOrientation, SubmitPosition, SubmitTrackingToWorld);
			}
		}
#endif
    	
        PxrLayerProjection layerProjection = {};
        layerProjection.header.layerId = 0;
        layerProjection.header.layerFlags = 0;
        layerProjection.header.sensorFrameIndex = SubmitViewNumber;
    	if (!PicoSplash->IsShown())
    	{
        layerProjection.header.colorScale[0] = GColorScale.R;
        layerProjection.header.colorScale[1] = GColorScale.G;
        layerProjection.header.colorScale[2] = GColorScale.B;
        layerProjection.header.colorScale[3] = GColorScale.A;

    	layerProjection.header.colorBias[0] = GColorOffset.R;
    	layerProjection.header.colorBias[1] = GColorOffset.G;
    	layerProjection.header.colorBias[2] = GColorOffset.B;
    	layerProjection.header.colorBias[3] = GColorOffset.A;
		}
    	else
    	{
    		layerProjection.header.colorScale[0] = 0.0f;
    		layerProjection.header.colorScale[1] = 0.0f;
    		layerProjection.header.colorScale[2] = 0.0f;
    		layerProjection.header.colorScale[3] = 0.0f;
    		layerProjection.header.colorBias[0] = 0.0f;
    		layerProjection.header.colorBias[1]  = 0.0f;
    		layerProjection.header.colorBias[2] = 0.0f;
    		layerProjection.header.colorBias[3]  = 0.0f;
    	}


        Pxr_SubmitLayer((PxrLayerHeader*)&layerProjection);
        Pxr_EndFrame();
        FrameState = EFrameState::NeedToBeginFrame;
    }
#endif
}

void FPicoXRHMD::RefreshLayers_RHIThread()
{
    TMap<uint32,FPicoLayerPtr> XLayers = LayerMap;
    for (auto Layer : XLayers)
    {
        EPicoXRLayerState LayerState = Layer.Value->GetLayerState();
        if (LayerState == EPicoXRLayerState::NeedToCreate) {
            Layer.Value->CreateLayer(RenderBridge);
        } else if (LayerState == EPicoXRLayerState::NeedToDestroy) {
            Layer.Value->DestroyLayer();
        } else if (LayerState == EPicoXRLayerState::NeedToReCreate) {
            Layer.Value->ReCreateLayer(RenderBridge);
        }
    }

    TMap<uint32,FPicoLayerPtr> XSplashLayers = PicoSplash->SplashLayersMap;
    for (auto Layer : XSplashLayers)
    {
        EPicoXRLayerState LayerState = Layer.Value->GetLayerState();
        if (LayerState == EPicoXRLayerState::NeedToCreate) {
            Layer.Value->CreateLayer(RenderBridge);
        } else if (LayerState == EPicoXRLayerState::NeedToDestroy) {
            Layer.Value->DestroyLayer();
            PicoSplash->SplashLayersMap.FindAndRemoveChecked(Layer.Key);
        } else if (LayerState == EPicoXRLayerState::NeedToReCreate) {
            Layer.Value->ReCreateLayer(RenderBridge);
        }
    }
}

void FPicoXRHMD::FinishRenderFrame_RenderThread(FRHICommandListImmediate& RHICmdList)
{
    TMap<uint32, FPicoLayerPtr> XLayers = LayerMap;
    for (auto Layer : XLayers)
    {
        Layer.Value->RefreshLayers_RenderThread(RenderBridge, RHICmdList);
    }
}

void FPicoXRHMD::SetFrameState(EFrameState NewState)
{
    FrameState = NewState;
}

EFrameState FPicoXRHMD::GetFrameState()
{
 	return FrameState;
}

bool FPicoXRHMD::Startup()
{
#if PLATFORM_ANDROID
    PXR_LOGI(PxrUnreal, "Startup");
	PxrInitParamData initParamData;
	initParamData.activity = (void*)FAndroidApplication::GetGameActivityThis();
	initParamData.vm =(void*) GJavaVM;
	if(PicoXRSetting->bIsHMD3Dof)
 	{
		initParamData.headdof = 0;
 	}
	else
	{
		initParamData.headdof = 1;
	}
 	if(PicoXRSetting->bIsController3Dof)
 	{
		initParamData.controllerdof = 0;
 	}
 	else
 	{
		initParamData.controllerdof = 1;
 	}
	Pxr_SetInitializeData(&initParamData);
	Pxr_SetPlatformOption(PxrPlatformOption::PXR_UNREAL);
	//GraphicOption
 	const FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
 	const FString RHILookup = NAME_RHI.ToString() + TEXT("=");
 	if (!FParse::Value(*HardwareDetails, *RHILookup, RHIString))
 	{
 		return false;
 	}

    if (RHIString == TEXT("OpenGL")) {
        PXR_LOGI(PxrUnreal, "RHIString OpenGL");
        Pxr_SetGraphicOption(PxrGraphicOption::PXR_OPENGL_ES);
        RenderBridge = CreateRenderBridge_OpenGL(this);
        Pxr_Initialize();
    } else if (RHIString == TEXT("Vulkan")) {
        PXR_LOGI(PxrUnreal, "RHIString Vulkan");
        Pxr_SetGraphicOption(PxrGraphicOption::PXR_VULKAN);
        RenderBridge = CreateRenderBridge_Vulkan(this);
        Pxr_Initialize();
        RenderBridge->GetVulkanGraphics();
    } else {
        PXR_LOGF(PxrUnreal, "%s is not currently supported by the PicoXR runtime", PLATFORM_CHAR(*RHIString));
        return false;
    }

    Pxr_SetColorSpace(IsMobileColorsRGB() ? PXR_COLOR_SPACE_SRGB : PXR_COLOR_SPACE_LINEAR);

    //Config MobileMultiView
    const auto CVarMobileMultiView = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.MobileMultiView"));
    bIsMobileMultiViewEnabled = (CVarMobileMultiView && CVarMobileMultiView->GetValueOnAnyThread() != 0);
    GSupportsMobileMultiView = Pxr_GetFeatureSupported(PXR_FEATURE_MULTIVIEW);
    bIsMobileMultiViewEnabled = GSupportsMobileMultiView && bIsMobileMultiViewEnabled;

#if PLATFORM_ANDROID
    PXR_LOGI(PxrUnreal, "bIsMobileMultiViewEnabled = %d", bIsMobileMultiViewEnabled);
    EnableContentProtect(PicoXRSetting->bUseContentProtect);
    FString UnrealSDKVersion = "UE4_2.0.2.3_";
	FString UnrealVersion = FString::FromInt(ENGINE_MINOR_VERSION);
	UnrealSDKVersion = UnrealSDKVersion + UnrealVersion;
    PXR_LOGI(PxrUnreal, "PxrUnreal xrVersion: %s", PLATFORM_CHAR(*UnrealSDKVersion));
	Pxr_SetConfigString(PXR_ENGINE_VERSION,PLATFORM_CHAR(*UnrealSDKVersion));
    SetTrackingOrigin(EHMDTrackingOrigin::Eye);
	Pxr_EnableMultiview(bIsMobileMultiViewEnabled);
    if (PicoXRSetting->bEnableFoveation) {
        PxrFoveationLevel FoveationLevel = static_cast<PxrFoveationLevel>((int32)PicoXRSetting->FoveationLevel);
        PXR_LOGI(PxrUnreal, "FoveationLevel=%d", FoveationLevel);
        Pxr_SetFoveationLevel(FoveationLevel);
    }

    //Config about OpenGL Context NoError
    bool bUseNoErrorContext = false;

#if PLATFORM_ANDROID && USE_ANDROID_EGL_NO_ERROR_CONTEXT
#if ENGINE_MINOR_VERSION > 23
    if (AndroidEGL::GetInstance()->GetSupportsNoErrorContext())
#endif
    {
        bUseNoErrorContext = true;
    }
#endif

    PXR_LOGI(PxrUnreal, "bUseNoErrorContext = %d", bUseNoErrorContext);
    if (bUseNoErrorContext) {
        Pxr_SetConfigInt(PXR_UNREAL_OPENGL_NOERROR, 1);
    } else {
        Pxr_SetConfigInt(PXR_UNREAL_OPENGL_NOERROR, 0);
    }
#endif
	//Config RenderTexture Size
	static const auto CVarPixelDensity = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
	SetPixelDensity(FMath::Clamp(CVarPixelDensity->GetFloat(), 0.5f, 2.0f));
    int RenderTextureX = 0;
    int RenderTextureY = 0;
    Pxr_GetConfigInt(PXR_RENDER_TEXTURE_WIDTH, &RenderTextureX);
    Pxr_GetConfigInt(PXR_RENDER_TEXTURE_HEIGHT, &RenderTextureY);
 	RTSize.X = RenderTextureX * 2;
 	RTSize.Y = RenderTextureY;
 	PXR_LOGI(PxrUnreal,"GetConfig RenderTextureSize:(%d,%d)",RTSize.X,RTSize.Y);
	//MSAA
	if (PicoXRSetting->bUseRecommendedMSAA)
	{
		MobileMSAAValue = RenderBridge->GetSystemRecommendedMSAA();
	}
	else
	{
		MobileMSAAValue=IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.MobileMSAA"))->GetValueOnAnyThread();
	}

    PXR_LOGI(PxrUnreal, "Set MSAA = %d", MobileMSAAValue);

    if (RHIString == TEXT("OpenGL")) {
        int32 MaxMSAASamplesSupported = 0;
        #if ENGINE_MINOR_VERSION > 24
            MaxMSAASamplesSupported = FOpenGL::GetMaxMSAASamplesTileMem();
        #else
            MaxMSAASamplesSupported = FAndroidOpenGL::MaxMSAASamplesTileMem;
        #endif
        MobileMSAAValue = MobileMSAAValue > MaxMSAASamplesSupported ? MaxMSAASamplesSupported : MobileMSAAValue;
    }

	static IConsoleVariable* CVarMobileMSAA = IConsoleManager::Get().FindConsoleVariable(TEXT("r.MobileMSAA"));
	if (CVarMobileMSAA)
	{
		CVarMobileMSAA->Set(MobileMSAAValue);
	}
	PXR_LOGI(PxrUnreal, "Final MSAA = %d", MobileMSAAValue);
 	if (PicoXRSetting->bEnableEyeTracking)
	{
		EyeTracker = MakeShared<FPicoXREyeTracker>();
	}
 	IStereoLayers::FLayerDesc EyeLayerDesc;
 	EyeLayerDesc.Priority = INT_MIN;
 	EyeLayerDesc.Flags = LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
 	const uint32 EyeLayerId = CreateLayer(EyeLayerDesc);
 	check(EyeLayerId == 0);

 	PicoSplash = MakeShareable(new FPicoXRSplash(this));
 	return true;
#endif
 	return false;
}

void FPicoXRHMD::PollEvent()
{
#if PLATFORM_ANDROID
	int32 EventCount = 0;
	PxrEventDataBuffer* EventData[PXR_MAX_EVENT_COUNT];
	bool Ret = Pxr_PollEvent(PXR_MAX_EVENT_COUNT, &EventCount, EventData);
	if (Ret)
	{
		PXR_LOGD(PxrUnreal,"PollEvent EventCount :%d",EventCount);
		ProcessEvent(EventCount, EventData);
	}
#endif
}

#if PLATFORM_ANDROID
void FPicoXRHMD::ProcessEvent(int32 EventCount, PxrEventDataBuffer** EventData)
{
	if (EventCount ==0 || !EventData)
	{
		return;
	}
	for (int i = 0; i < EventCount; i++)
	{
		PxrEventDataBuffer* Event = EventData[i];
		PXR_LOGD(PxrUnreal,"ProcessEvent EventCount:%d,EventType[%d]:%d",EventCount,i,Event->type);
		switch(Event->type)
		{
		case PXR_TYPE_EVENT_DATA_SESSION_STATE_READY:
		{
			BeginXR();
			break;
		}
		case PXR_TYPE_EVENT_DATA_SESSION_STATE_STOPPING:
		{
			EndXR();
			break;
		}
		case PXR_TYPE_EVENT_DATA_SEETHROUGH_STATE_CHANGED:
		{
			const PxrEventDataSeethroughStateChanged SeeThroughData = *reinterpret_cast<const PxrEventDataSeethroughStateChanged*>(Event);
			OnSeeThroughStateChange(SeeThroughData.state);
			break;
		}
		case PXR_TYPE_EVENT_FOVEATION_LEVEL_CHANGED:
		{
			const PxrEventDataFoveationLevelChanged FoveationData = *reinterpret_cast<const PxrEventDataFoveationLevelChanged*>(Event);
			OnFoveationLevelChange(FoveationData.level);
			break;
		}
		case PXR_TYPE_EVENT_FRUSTUM_STATE_CHANGED:
		{
			const PxrEventDataFrustumChanged FrustumData = *reinterpret_cast<const PxrEventDataFrustumChanged*>(Event);
			OnFrustumStateChange();
			break;
		}
		case PXR_TYPE_EVENT_RENDER_TEXTURE_CHANGED:
		{
			const PxrEventDataRenderTextureChanged RenderTextureChanged = *reinterpret_cast<const PxrEventDataRenderTextureChanged*>(Event);
			OnRenderTextureChange(RenderTextureChanged.width,RenderTextureChanged.height);
			break;
		}
		case PXR_TYPE_EVENT_TARGET_FRAME_RATE_STATE_CHANGED:
		{
			const PxrEventDataTargetFrameRateChanged FrameRateChanged = *reinterpret_cast<const PxrEventDataTargetFrameRateChanged*>(Event);
			OnTargetFrameRateChange(FrameRateChanged.frameRate);
			break;
		}

		case PXR_TYPE_EVENT_DATA_CONTROLLER:
		{
			const PxrEventDataControllerChanged Controller = *reinterpret_cast<const PxrEventDataControllerChanged*>(Event);
			ProcessControllerEvent(Controller);
			break;
		}

		case PXR_TYPE_EVENT_HARDIPD_STATE_CHANGED:
		{
			const PxrEventDataHardIPDStateChanged IPDState = *reinterpret_cast<const PxrEventDataHardIPDStateChanged*>(Event);
			IpdValue = IPDState.ipd;
			PXR_LOGD(PxrUnreal,"ProcessEvent PXR_TYPE_EVENT_HARDIPD_STATE_CHANGED IPD:%f",IPDState.ipd);
			EventManager->IpdChangedDelegate.Broadcast(IPDState.ipd);
			UPicoXRHMDFunctionLibrary::PicoXRIPDChangedCallback.ExecuteIfBound(IPDState.ipd);
			break;
		}
		case PXR_TYPE_EVENT_DATA_HMD_KEY:
		{
			const PxrEventDataHmdKey HomeKey = *reinterpret_cast<const PxrEventDataHmdKey*>(Event);
			EventManager->LongHomePressedDelegate.Broadcast();
			break;
		}
		case PXR_TYPE_EVENT_DATA_MRC_STATUS:
		{
			const PxrEventDataMrcStatusChanged MRC = *reinterpret_cast<const PxrEventDataMrcStatusChanged*>(Event);
			MRCEnabled = MRC.mrc_status == 0 ? true : false;
			break;
		}
		case PXR_TYPE_EVENT_DATA_REFRESH_RATE_CHANGED:
		{
			const PxrEventDataRefreshRateChanged RateState = *reinterpret_cast<const PxrEventDataRefreshRateChanged*>(Event);
			PXR_LOGD(PxrUnreal, "ProcessEvent PXR_TYPE_EVENT_DATA_REFRESH_RATE_CHANGED Rate:%f", RateState.refrashRate);
			EventManager->RefreshRateChangedDelegate.Broadcast(RateState.refrashRate);
			break;
		}
		default:
			break;
		}
	}
}

void FPicoXRHMD::ProcessControllerEvent(const PxrEventDataControllerChanged EventData)
{
	PXR_LOGD(PxrUnreal,"ProcessControllerEvent eventtype:%d,Handness:%d,State:%d",EventData.eventtype,EventData.controller,EventData.status);
	FPicoXRInput* PicoInput = GetPicoXRInput();
	switch (EventData.eventtype)
	{
	case PXR_DEVICE_CONNECTCHANGED:
		{
			PXR_LOGD(PxrUnreal,"ProcessControllerEvent PXR_DEVICE_CONNECTCHANGED  controller:%d,State:%d",EventData.controller,EventData.status);
			PicoInput->OnControllerConnectChangedDelegate(EventData.controller, EventData.status);
			EventManager->DeviceConnectChangedDelegate.Broadcast(EventData.controller, EventData.status);
			break;
		}
	case PXR_DEVICE_MAIN_CHANGED:
		{
		    PXR_LOGD(PxrUnreal, "ProcessControllerEvent PXR_DEVICE_MAIN_CHANGED controller:%d", EventData.controller);
		    PicoInput->OnControllerMainChangedDelegate(EventData.controller);
		    EventManager->DeviceMainChangedDelegate.Broadcast(EventData.controller);
			break;
		}
	default:
		break;
	}
}
#endif

void FPicoXRHMD::OnSeeThroughStateChange(int32 SeeThroughState)
{
    if (SeeThroughState == 2)
    {
    	if (RHIString != TEXT("Vulkan")) {
    		ExecuteOnRenderThread([this]()
            {
                FRHITexture2D* SrcTexture = LayerMap[0]->GetSwapChain()->GetTexture2D();
                ClearTexture_RHIThread(SrcTexture);
            });
    	}
	}
}

void FPicoXRHMD::OnFoveationLevelChange(int32 NewFoveationLevel)
{
#if PLATFORM_ANDROID
	if (!PicoXRSetting->bEnableFoveation)
	{
		PicoXRSetting->bEnableFoveation = true;
		PicoXRSetting->FoveationLevel = static_cast<EFoveationLevel::Type>(NewFoveationLevel);
	}
	PxrFoveationLevel FoveationLevel = static_cast<PxrFoveationLevel>(NewFoveationLevel);
	Pxr_SetFoveationLevel(FoveationLevel);
#endif
}

void FPicoXRHMD::OnFrustumStateChange()
{
#if PLATFORM_ANDROID
    Pxr_GetFrustum(PXR_EYE_LEFT, &LeftFrustum.FovLeft, &LeftFrustum.FovRight, &LeftFrustum.FovUp, &LeftFrustum.FovDown,&LeftFrustum.Near,&LeftFrustum.Far);
    Pxr_GetFrustum(PXR_EYE_RIGHT, &RightFrustum.FovLeft, &RightFrustum.FovRight, &RightFrustum.FovUp, &RightFrustum.FovDown,&RightFrustum.Near,&RightFrustum.Far);
 	LeftFrustum.FovLeft = FMath::Atan(LeftFrustum.FovLeft/LeftFrustum.Near);
 	LeftFrustum.FovRight = FMath::Atan(LeftFrustum.FovRight/LeftFrustum.Near);
 	LeftFrustum.FovUp = FMath::Atan(LeftFrustum.FovUp/LeftFrustum.Near);
 	LeftFrustum.FovDown = FMath::Atan(LeftFrustum.FovDown/LeftFrustum.Near);

 	RightFrustum.FovLeft = FMath::Atan(RightFrustum.FovLeft/RightFrustum.Near);
 	RightFrustum.FovRight = FMath::Atan(RightFrustum.FovRight/RightFrustum.Near);
 	RightFrustum.FovUp = FMath::Atan(RightFrustum.FovUp/RightFrustum.Near);
 	RightFrustum.FovDown = FMath::Atan(RightFrustum.FovDown/RightFrustum.Near);
#endif
}

void FPicoXRHMD::OnRenderTextureChange(int32 Width, int32 Height)
{
 	RTSize.X = Width * 2;
 	RTSize.Y = Height;
 	PXR_LOGI(PxrUnreal,"OnRenderTextureChange RenderTextureSize:(%d,%d)",RTSize.X,RTSize.Y);
}

void FPicoXRHMD::OnTargetFrameRateChange(int32 NewFrameRate)
{
 	GEngine->SetMaxFPS(NewFrameRate);
}

void FPicoXRHMD::Shutdown()
{
	LayerMap.Reset();
 	FCoreUObjectDelegates::PreLoadMap.RemoveAll(this);
 	FCoreUObjectDelegates::PostLoadMapWithWorld.RemoveAll(this);
#if PLATFORM_ANDROID
	Pxr_Shutdown();
#endif
}

void FPicoXRHMD::ApplicationPauseDelegate()
{
	PXR_LOGI(PxrUnreal,"FPicoXRHMD::ApplicationPauseDelegate");
	PollEvent();
}

void FPicoXRHMD::ApplicationResumeDelegate()
{
	PXR_LOGI(PxrUnreal,"FPicoXRHMD::ApplicationResumeDelegate");
	if (EventManager)
	{
		EventManager->ResumeDelegate.Broadcast();
	}
}

void FPicoXRHMD::UPxr_EnableFoveation(bool enable)
{
	if (PicoXRSetting)
	{
		PicoXRSetting->bEnableFoveation = enable;
	}
}

void FPicoXRHMD::OnPreLoadMap(const FString& MapName)
{
    ExecuteOnRenderThread_DoNotWait([this]()
    {
        if (RHIString != TEXT("Vulkan")) {
            FRHITexture2D* SrcTexture = LayerMap[0]->GetSwapChain()->GetTexture2D();
            ClearTexture_RHIThread(SrcTexture);
        }
         ExecuteOnRHIThread_DoNotWait([this]()
         {
         	 if (FrameState == EFrameState::NeedToEndFrame)
         	 {
                 EndFrame_RHIThread();
             }
		 });
    });

 	PicoSplash->OnPreLoadMap(MapName);
}

void FPicoXRHMD::OnPostLoadMap(UWorld* InWorld)
{
 	PicoSplash->OnPostLoadMap(InWorld);
}

FPicoLayerPtr FPicoXRHMD::GetEyeLayerPtr()
{
	if (LayerMap.Num()>0 && LayerMap[0])
	{
		return LayerMap[0];
	}
 	return nullptr;
}

TSharedPtr<FPicoXREyeTracker> FPicoXRHMD::UPxr_GetEyeTracker()
{
 	return EyeTracker;
}

void FPicoXRHMD::UpdateNeckOffset()
{
	if (PicoXRSetting->bIsHMD3Dof && PicoXRSetting->bEnableNeckModel)
	{
		if (PicoXRSetting->bUseCustomNeckParameter)
		{
			NeckOffset = PicoXRSetting->NeckOffset;
		}
		else
		{
			NeckOffset = FVector(0.0805f,0, 0.075f);
#if PLATFORM_ANDROID
			Pxr_GetConfigFloat(PXR_NECK_MODEL_X, &NeckOffset.Y);
			Pxr_GetConfigFloat(PXR_NECK_MODEL_Y, &NeckOffset.Z);
			Pxr_GetConfigFloat(PXR_NECK_MODEL_Z, &NeckOffset.X);
#endif
			PicoXRSetting->NeckOffset = NeckOffset;
		}
		PXR_LOGD(PxrUnreal, "Enable Neck module NeckOffset.X is %f NeckOffset.Y is %f NeckOffset.Z is %f", NeckOffset.X, NeckOffset.Y, NeckOffset.Z);
	}
}

void FPicoXRHMD::UpdateSensorValue()
{
    PXR_LOGD(PxrUnreal, "UpdateSensorValue");
#if PLATFORM_ANDROID
    //Position Orientation
    FPicoXRInput* PicoInput = GetPicoXRInput();
    FVector SourcePosition = FVector::ZeroVector;
	FVector LinearAcceleration = FVector::ZeroVector;
	FVector AngularAcceleration = FVector::ZeroVector;
	FVector AngularVelocity = FVector::ZeroVector;
	FVector LinearVelocity = FVector::ZeroVector;
    FQuat SourceOrientation = FQuat::Identity;
    int32 ViewNumber = 0;
    int eyeCount = 1;
    PxrPosef pose;
    double predictedDisplayTimeMs = 0.0;
    Pxr_GetPredictedDisplayTime(&predictedDisplayTimeMs);
    PxrSensorState sensorState = {};
    Pxr_GetPredictedMainSensorStateWithEyePose(predictedDisplayTimeMs, &sensorState, &ViewNumber, eyeCount, &pose);

    SourcePosition.X = sensorState.pose.position.x;
    SourcePosition.Y = sensorState.pose.position.y;
    SourcePosition.Z = sensorState.pose.position.z;

    SourceOrientation.X = sensorState.pose.orientation.x;
    SourceOrientation.Y = sensorState.pose.orientation.y;
    SourceOrientation.Z = sensorState.pose.orientation.z;
    SourceOrientation.W = sensorState.pose.orientation.w;
	LinearAcceleration.X = sensorState.linearAcceleration.x;
	LinearAcceleration.Y = sensorState.linearAcceleration.y;
	LinearAcceleration.Z = sensorState.linearAcceleration.z;

	AngularAcceleration.X = sensorState.angularAcceleration.x;
	AngularAcceleration.Y = sensorState.angularAcceleration.y;
	AngularAcceleration.Z = sensorState.angularAcceleration.z;

	AngularVelocity.X = sensorState.angularVelocity.x;
	AngularVelocity.Y = sensorState.angularVelocity.y;
	AngularVelocity.Z = sensorState.angularVelocity.z;

	LinearVelocity.X = sensorState.linearVelocity.x;
	LinearVelocity.Y = sensorState.linearVelocity.y;
	LinearVelocity.Z = sensorState.linearVelocity.z;

	PicoInput->SetHeadPosition(SourcePosition);
	PicoInput->SetHeadOrientation(SourceOrientation);
	FVector Position = FPicoXRUtils::ConvertXRVectorToUnrealVector(SourcePosition, CurrentFrameValue_RenderThread.WorldToMetersScale);

	FQuat Orientation = FPicoXRUtils::ConvertXRQuatToUnrealQuat(SourceOrientation);
	// Position
	if (PicoXRSetting->bIsHMD3Dof)//head 3Dof
	{
		if (PicoXRSetting->bEnableNeckModel)
		{
			CurrentFrameValue_RenderThread.CurrentPosition = Orientation * NeckOffset - NeckOffset.Z * FVector::UpVector;
		}
		else
		{
			CurrentFrameValue_RenderThread.CurrentPosition = FVector::ZeroVector;
		}
		//FloorLevel need add Position y
		if (TrackingOrigin == EHMDTrackingOrigin::Floor)
		{
			CurrentFrameValue_RenderThread.CurrentPosition.Z += SourcePosition.Y * CurrentFrameValue_RenderThread.WorldToMetersScale;
		}
	}
	else//head 6Dof
	{
		CurrentFrameValue_RenderThread.CurrentPosition = Position;
	}
	// Orientation
	CurrentFrameValue_RenderThread.CurrentOrientation = Orientation;
	// ViewNumber
	CurrentFrameValue_RenderThread.ViewNumber = ViewNumber;

 	//velocity
	CurrentFrameValue_RenderThread.Acceleration = LinearAcceleration;
	CurrentFrameValue_RenderThread.AngularAcceleration = AngularAcceleration;
	CurrentFrameValue_RenderThread.AngularVelocity = AngularVelocity;
	CurrentFrameValue_RenderThread.Velocity = LinearVelocity;
#endif
}

void FPicoXRHMD::UpdateSplashScreen()
 {
 	if (!GetSplash() || !IsInGameThread())
 	{
 		return;
 	}
 	if (bSplashIsShown)
 	{
 		PXR_LOGD(PxrUnreal, "UpdateSplashScreen Splash->Show()");
 	}
 	else
 	{
 		PXR_LOGD(PxrUnreal, "UpdateSplashScreen Splash->Hide()");
 	}

 }

void FPicoXRHMD::EnableContentProtect(bool bEnable)
{
#if PLATFORM_ANDROID
 	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
 	{
 		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableContentProtect", "(Z)V", false);
 		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, bEnable);
 	}
#endif
}

void FPicoXRHMD::ClearTexture_RHIThread(FRHITexture2D* SrcTexture)
{

	if (RHIString == TEXT("Vulkan"))
	{
		UE_LOG(LogTemp,Log,TEXT("Pico XR Vulkan, Cannot Clear Texture"));
		return;
	}

    check(IsInRenderingThread());

    FRHICommandListImmediate& CommandList = FRHICommandListExecutor::GetImmediateCommandList();
    const FRHIRenderPassInfo RenderPassInfo(SrcTexture, ERenderTargetActions::Clear_Store);
    CommandList.BeginRenderPass(RenderPassInfo, TEXT("ClearTexture"));
    CommandList.EndRenderPass();
    CommandList.SetViewport(0, 0, 0.0f, SrcTexture->GetSizeX(), SrcTexture->GetSizeY(), 1.0f);
#if ENGINE_MINOR_VERSION>25
    CommandList.Transition(FRHITransitionInfo(SrcTexture, ERHIAccess::Unknown, ERHIAccess::SRVMask));
#else
    CommandList.TransitionResource(EResourceTransitionAccess::EReadable, SrcTexture);
#endif
}

float FPicoXRHMD::UPxr_GetIPD() const
{
 	PXR_LOGD(PxrUnreal,"const GetIPD %f", IpdValue);
 	return IpdValue;
}

void FPicoXRHMD::RenderTexture_RenderThread(class FRHICommandListImmediate& RHICmdList, class FRHITexture2D* BackBuffer, class FRHITexture2D* SrcTexture, FVector2D WindowSize) const
{
	ExecuteOnRHIThread([this]()
	{
		FPicoXRHMD::SubmitViewNumber = this->CurrentFrameValue_RenderThread.ViewNumber;
		FPicoXRHMD::SubmitOrientation = this->CurrentFrameValue_RenderThread.CurrentOrientation;
		FPicoXRHMD::SubmitPosition = this->CurrentFrameValue_RenderThread.CurrentPosition;
		FPicoXRHMD::SubmitTrackingToWorld = this->CurrentFrameValue_RenderThread.TrackingToWorld;
	});
}

void FPicoXRHMD::SetupViewFamily(FSceneViewFamily& InViewFamily)
{
#if WITH_EDITOR
	InViewFamily.EngineShowFlags.SetScreenPercentage(false);
#endif
}

void FPicoXRHMD::SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView)
{
	check(IsInGameThread());
}

void FPicoXRHMD::BeginRenderViewFamily(FSceneViewFamily& InViewFamily)
{
}

void FPicoXRHMD::PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
{
}

void FPicoXRHMD::PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily)
{
#if ENGINE_MINOR_VERSION==24
	TArray<FPicoLayerPtr> XLayers;
	XLayers.Empty(LayerMap.Num());
	for (auto Pair : LayerMap)
	{
		XLayers.Emplace(Pair.Value->Clone());
	}
	XLayers.Sort(FPicoXRStereoLayerPtr_ComparePriority());
	ExecuteOnRHIThread_DoNotWait([this, XLayers]()
    {

		 Layers_RenderThread = XLayers;
#else
	ExecuteOnRHIThread_DoNotWait([this]()
	{
#endif
         BeginFrame_RHIThread();
    });
}

void FPicoXRHMD::PostRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily)
{
#if PLATFORM_ANDROID
	if (IsInRenderingThread())
	{
	    if (PicoSplash->IsShown())
		{
			if (Pxr_IsRunning() && FrameState == EFrameState::NeedToEndFrame)
			{
				SplashShow(RHICmdList);
			}
		}
		FinishRenderFrame_RenderThread(RHICmdList);
    }
#endif
}

void FPicoXRHMD::PostRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
{
}

#if ENGINE_MINOR_VERSION > 25
bool FPicoXRHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
#else
bool FPicoXRHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, uint32 Flags, uint32 TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples /*= 1*/)
#endif
{
    PXR_LOGI(PxrUnreal, "AllocateRenderTargetTexture Index=%d, SizeX=%d, SizeY=%d, Format=%d, NumMips=%d, Flags=%d, TargetableTextureFlags=%d, NumSamples=%d",
                        Index, SizeX, SizeY, Format, NumMips, Flags, TargetableTextureFlags, NumSamples);

    check(IsInGameThread());
    check(IsInRenderingThread());

    if (LayerMap[0].IsValid())
    {
        PXR_LOGI(PxrUnreal, "AllocateRenderTargetTexture GetLayerState=%d", LayerMap[0]->GetLayerState());
        if (LayerMap[0]->GetLayerState() == EPicoXRLayerState::NeedToCreate)
        {
            LayerMap[0]->InitializeLayer_RenderThread(RenderBridge,Format, SizeX, SizeY, bIsMobileMultiViewEnabled ? 2 : 1 , NumMips, NumSamples, Flags, TargetableTextureFlags,MobileMSAAValue);
            LayerMap[0]->SetLayerState(EPicoXRLayerState::Ready);
            const FXRSwapChainPtr& SwapChain = LayerMap[0]->GetSwapChain();
            OutTargetableTexture = OutShaderResourceTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
            return true;
        } else if (LayerMap[0]->GetLayerState() == EPicoXRLayerState::NeedToReCreate) {
             LayerMap[0]->SetEyeLayerParam(RenderBridge,Format, SizeX, SizeY, bIsMobileMultiViewEnabled ? 2 : 1 , NumMips, NumSamples, Flags, TargetableTextureFlags,MobileMSAAValue);
             LayerMap[0]->ReCreateLayer(RenderBridge);
             const FXRSwapChainPtr& SwapChain = LayerMap[0]->GetSwapChain();
             OutTargetableTexture = OutShaderResourceTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
             return true;
         } else {
             const FXRSwapChainPtr& SwapChain = LayerMap[0]->GetSwapChain();
             OutTargetableTexture = OutShaderResourceTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
             return true;
         }
    }
    return false;
}

#if ENGINE_MINOR_VERSION <27
bool FPicoXRHMD::NeedReAllocateFoveationTexture(const TRefCountPtr<IPooledRenderTarget>& FoveationTarget)
#else
bool FPicoXRHMD::NeedReAllocateShadingRateTexture(const TRefCountPtr<IPooledRenderTarget>& FoveationTarget)
#endif
{
	check(IsInRenderingThread());
	return bNeedReAllocateFoveationTexture_RenderThread;
}

#if ENGINE_MINOR_VERSION < 27
#if ENGINE_MINOR_VERSION > 25
bool FPicoXRHMD::AllocateFoveationTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize)
#else
bool FPicoXRHMD::AllocateFoveationTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, uint32 InTexFlags, uint32 InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize)
#endif
#else
bool FPicoXRHMD::AllocateShadingRateTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize)
#endif
{
	check(Index == 0);

#if PLATFORM_ANDROID

    if (RHIString == TEXT("OpenGL") || !Pxr_GetFeatureSupported(PXR_FEATURE_FOVEATION)) 
	{
        PXR_LOGI(PxrUnreal, "AllocateFoveationTexture OpenGL Graphics & Feature Foveation is Not Supportted");
        return false;
    }

	
	

    if (LayerMap[0].IsValid())
    {
        const FXRSwapChainPtr& SwapChain = LayerMap[0]->GetFoveationSwapChain();

        if (SwapChain.IsValid())
        {
            PXR_LOGI(PxrUnreal, "AllocateFoveationTexture SwapChain.IsValid");

			FTexture2DRHIRef Texture=nullptr;
			Texture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
            FIntPoint TexSize = Texture->GetSizeXY();

            if (Texture->IsValid() && TexSize.X > 0 && TexSize.Y > 0 )
            {
				if (bNeedReAllocateFoveationTexture_RenderThread)
				{
					bNeedReAllocateFoveationTexture_RenderThread = false;
				}

				if (RenderSizeX % TexSize.X != 0 || RenderSizeY % TexSize.Y != 0)
				{
					PXR_LOGI(PxrUnreal, "%d x %d variable resolution swapchain is not a divider of %d x %d color swapchain, potential edge problems", TexSize.X, TexSize.Y, RenderSizeX, RenderSizeY);
				}
				else
				{
					PXR_LOGI(PxrUnreal, "%d x %d variable resolution swapchain is a divider of %d x %d color swapchain, no edge problems", TexSize.X, TexSize.Y, RenderSizeX, RenderSizeY);
				}

                OutTexture = Texture;
                OutTextureSize = TexSize;
                return true;
            }
        }
    }
#endif
    return false;
}

void FPicoXRHMD::CalculateRenderTargetSize(const class FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY)
{
	InOutSizeX = GetIdealRenderTargetSize().X;
	InOutSizeY = GetIdealRenderTargetSize().Y;
}

bool FPicoXRHMD::NeedReAllocateViewportRenderTarget(const FViewport& Viewport)
{
	check(IsInGameThread());

	const uint32 InSizeX = Viewport.GetSizeXY().X;
	const uint32 InSizeY = Viewport.GetSizeXY().Y;

	FIntPoint mRTSize;
	mRTSize.X = Viewport.GetRenderTargetTexture()->GetSizeX();
	mRTSize.Y = Viewport.GetRenderTargetTexture()->GetSizeY();

	uint32 NewSizeX = InSizeX, NewSizeY = InSizeY;
	CalculateRenderTargetSize(Viewport, NewSizeX, NewSizeY);
	if (NewSizeX != mRTSize.X || NewSizeY != mRTSize.Y)
	{
		PXR_LOGD(PxrUnreal,"NeedReAllocateViewportRenderTarget");
		return true;
	}
	return false;
}

FXRRenderBridge* FPicoXRHMD::GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget)
{
	return RenderBridge;
}

uint32 FPicoXRHMD::CreateLayer(const FLayerDesc& InLayerDesc)
{
    check(IsInGameThread());
    const uint32 LayerId = CurrentLayerId++;
    PXR_LOGD(PxrUnreal, "Layer Create LayerId=%d", LayerId);
    LayerMap.Add(LayerId, MakeShareable(new FPicoXRStereoLayer(this, LayerId, InLayerDesc)));
    LayerMap[LayerId]->MarkCreateLayer();
    return LayerId;
}

void FPicoXRHMD::DestroyLayer(uint32 LayerId)
{
    PXR_LOGD(PxrUnreal, "DestroyLayer LayerId=%d", LayerId);
    if (LayerMap.Find(LayerId))
    {
#if ENGINE_MINOR_VERSION==24
		//Set layer alpha to 0 as hidden state
		for (auto layer:Layers_RenderThread)
		{
			if (layer->GetLayerID()==LayerId)
			{
				layer->MarkDestroyLayer();
			}
		}
#endif
		LayerMap[LayerId]->MarkDestroyLayer();
    }
#if ENGINE_MINOR_VERSION==24
	LayerMap.Remove(LayerId);
#else
	ExecuteOnRenderThread([this, LayerId]()
		{
			ExecuteOnRHIThread([this, LayerId]()
				{
					LayerMap.Remove(LayerId);
				});
		});
#endif

}

void FPicoXRHMD::SetLayerDesc(uint32 LayerId, const FLayerDesc& InLayerDesc)
{
 	check(IsInGameThread());
 	FPicoLayerPtr* LayerFound = LayerMap.Find(LayerId);
 	if (LayerFound)
 	{
 		LayerFound->Get()->SetLayerDesc(InLayerDesc);
 	}
}

bool FPicoXRHMD::GetLayerDesc(uint32 LayerId, IStereoLayers::FLayerDesc& OutLayerDesc)
{
 	check(IsInGameThread());
 	FPicoLayerPtr* LayerFound = LayerMap.Find(LayerId);
 	if (LayerFound)
 	{
 		OutLayerDesc = (*LayerFound)->GetLayerDesc();
 		return true;
 	}
 	return false;
}

void FPicoXRHMD::MarkTextureForUpdate(uint32 LayerId)
{
    check(IsInGameThread());
    FPicoLayerPtr* LayerFound = LayerMap.Find(LayerId);
    if (LayerFound)
    {
        (*LayerFound)->MarkTextureForUpdate();
    }
}

IStereoLayers::FLayerDesc FPicoXRHMD::GetDebugCanvasLayerDesc(FTextureRHIRef Texture)
{
 	IStereoLayers::FLayerDesc StereoLayerDesc;
 	StereoLayerDesc.Priority = INT_MAX;
 	StereoLayerDesc.Transform = FTransform(FVector(180.f, 0, 0));
	float scaleZ = -1.0f;
	if (RHIString == TEXT("Vulkan"))
		scaleZ = 1.0f;
 	StereoLayerDesc.Transform.SetScale3D(FVector(1,1, scaleZ));
 	StereoLayerDesc.QuadSize = FVector2D(180.f, 180.f);
 	StereoLayerDesc.LayerSize = Texture->GetTexture2D()->GetSizeXY();
 	StereoLayerDesc.PositionType = IStereoLayers::ELayerType::FaceLocked;
#if ENGINE_MINOR_VERSION >24
 	StereoLayerDesc.SetShape<FQuadLayer>();
#else
 	StereoLayerDesc.ShapeType = IStereoLayers::ELayerShape::QuadLayer;
#endif
 	StereoLayerDesc.Texture = Texture;
 	StereoLayerDesc.Flags = IStereoLayers::ELayerFlags::LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
 	StereoLayerDesc.Flags |= IStereoLayers::ELayerFlags::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO;
 	return StereoLayerDesc;
}

void FPicoXRHMD::GetAllocatedTexture(uint32 LayerId, FTextureRHIRef& Texture, FTextureRHIRef& LeftTexture)
{
 	Texture = LeftTexture = nullptr;
}

void FPicoXRHMD::OnBeginPlay(FWorldContext& InWorldContext)
{
	if (PicoSplash->IsShown())
	{
		PicoSplash->StopTicker();
	}
	IConsoleVariable* CVSynsVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.VSync"));
	CVSynsVar->Set(0.0f);
	IConsoleVariable* CFCFVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FinishCurrentFrame"));
	CFCFVar->Set(0.0f);
 	PlayerController = InWorldContext.World()->GetFirstPlayerController();
 	if(EyeTracker)
 	{
 		EyeTracker->OpenEyeTracking();
 		EyeTracker->SetEyeTrackedPlayer(PlayerController);
 	}
 	FCoreUObjectDelegates::PreLoadMap.AddRaw(this, &FPicoXRHMD::OnPreLoadMap);
 	FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FPicoXRHMD::OnPostLoadMap);
}

void FPicoXRHMD::OnEndPlay(FWorldContext& InWorldContext)
{
	if (PicoSplash->IsShown())
	{
		PicoSplash->HideLoadingScreen();
	}
}

#if ENGINE_MINOR_VERSION >25
int32 FPicoXRHMD::GetXRSystemFlags() const
{
 	return EXRSystemFlags::IsHeadMounted;
}
#endif

EHMDWornState::Type FPicoXRHMD::GetHMDWornState()
{
	if (PicoXRSetting->bEnablePSensor)
	{
		int32 state = -1;
#if PLATFORM_ANDROID
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetPsensorState", "()I", false);
			state = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
		}
#endif
		if (state == 0)
		{
			return EHMDWornState::Worn;
		}
		else
		{
			return EHMDWornState::NotWorn;
		}
	}
		return EHMDWornState::Unknown;
}

float FPicoXRHMD::GetPixelDenity() const
{
	return PixelDensity;
}

void FPicoXRHMD::SetPixelDensity(const float NewPixelDensity)
{
	PixelDensity = FMath::Clamp(NewPixelDensity, 0.5f, 2.0f);
	PXR_LOGI(PxrUnreal, "SetPixelDensity = %f", PixelDensity);
	static const auto PixelDensityCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
	PixelDensityCVar->Set(PixelDensity);
}

void FPicoXRHMD::SetRefreshRate()
{
#if PLATFORM_ANDROID
	switch (PicoXRSetting->refreshRate)
	{
	case ERefreshRate::Default:
	{
		Pxr_SetDisplayRefreshRate(0.0f);
		break;
	}
	case ERefreshRate::RefreshRate72:
	{
		Pxr_SetDisplayRefreshRate(72.0f);
		break;
	}
	case ERefreshRate::RefreshRate90:
	{
		Pxr_SetDisplayRefreshRate(90.0f);
		break;
	}
	default:
		break;
	}
#endif
}

void FPicoXRHMD::UPxr_SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
{
	PXR_LOGI(PxrUnreal,"PicoXRSetColorScaleAndOffset Scale(RGBA)= %f %f %f %f. Offset = %f %f %f %f,AllLayers = %d",ColorScale.R,ColorScale.G,ColorScale.B,ColorScale.A,ColorOffset.R,ColorOffset.G,ColorOffset.B,ColorOffset.A,bApplyToAllLayers);
	GbApplyToAllLayers = bApplyToAllLayers;
	GColorScale = ColorScale;
	GColorOffset = ColorOffset;
}
