//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_DPHMD.h"
#include "PXR_DPPrivate.h"
#include "PXR_Log.h"

#include "Misc/App.h"
#include "Misc/CoreDelegates.h"
#include "Misc/EngineVersion.h"
#include "RendererPrivate.h"
#include "ScenePrivate.h"
#include "Slate/SceneViewport.h"
#include "PostProcess/PostProcessHMD.h"
#include "Engine/GameEngine.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/WorldSettings.h"
#include "IHeadMountedDisplayVulkanExtensions.h"
#include "HeadMountedDisplayFunctionLibrary.h"

#include "EngineAnalytics.h"
#include "Runtime/Analytics/Analytics/Public/Interfaces/IAnalyticsProvider.h"

#include "Engine/Canvas.h"
#include "CanvasItem.h"
#include "XRThreadUtils.h"
#include "Runtime/Windows/D3D11RHI/Private/D3D11RHIPrivate.h"

#if WITH_EDITOR
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE( a ) ( sizeof( ( a ) ) / sizeof( ( a )[ 0 ] ) )
#endif

DEFINE_LOG_CATEGORY(LogPicoDP);
/** Helper function for acquiring the appropriate FSceneViewport */
FSceneViewport* FindSceneViewport()
{
	if (!GIsEditor)
	{
		UGameEngine* GameEngine = Cast<UGameEngine>(GEngine);
		return GameEngine->SceneViewport.Get();
	}
#if WITH_EDITOR
	else
	{
		UEditorEngine* EditorEngine = CastChecked<UEditorEngine>(GEngine);
		FSceneViewport* PIEViewport = (FSceneViewport*)EditorEngine->GetPIEViewport();
		if (PIEViewport != nullptr && PIEViewport->IsStereoRenderingAllowed())
		{
			// PIE is setup for stereo rendering
			return PIEViewport;
		}
		else
		{
			// Check to see if the active editor viewport is drawing in stereo mode
			// @todo vreditor: Should work with even non-active viewport!
			FSceneViewport* EditorViewport = (FSceneViewport*)EditorEngine->GetActiveViewport();
			if (EditorViewport != nullptr && EditorViewport->IsStereoRenderingAllowed())
			{
				return EditorViewport;
			}
		}
	}
#endif
	return nullptr;
}
//---------------------------------------------------
// PicoDP Plugin Implementation
//---------------------------------------------------

class FPicoDPPlugin : public IPicoDPPlugin
{
	/** IHeadMountedDisplayModule implementation */
	virtual TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > CreateTrackingSystem() override;

	FString GetModuleKeyName() const
	{
		return FString(TEXT("PicoDP"));
	}

public:
	FPicoDPPlugin()
	{
	}
	virtual void StartupModule() override
	{
		IHeadMountedDisplayModule::StartupModule();
	}

	virtual void ShutdownModule() override
	{
		IHeadMountedDisplayModule::ShutdownModule();
	}

	bool Initialize()
	{
		PXR_LOGD(PxrUnreal,"PXR_DP Initialize!");
		return true;
	}


	virtual bool IsHMDConnected() override
	{
		return  true;
	}

#if PLATFORM_WINDOWS
	enum class D3DApiLevel
	{
		Undefined,
		Direct3D11,
		Direct3D12
	};

	static inline D3DApiLevel GetD3DApiLevel()
	{
		FString RHIString;
		{
			FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
			FString RHILookup = NAME_RHI.ToString() + TEXT("=");
			
			PXR_LOGD(PxrUnreal,"PXR_DP RHIString:%s", *RHIString);
			if (!FParse::Value(*HardwareDetails, *RHILookup, RHIString))
			{
				// RHI might not be up yet. Let's check the command-line and see if DX12 was specified.
				// This will get hit on startup since we don't have RHI details during stereo device bringup. 
				// This is not a final fix; we should probably move the stereo device init to later on in startup.
				bool bForceD3D12 = FParse::Param(FCommandLine::Get(), TEXT("d3d12")) || FParse::Param(FCommandLine::Get(), TEXT("dx12"));
				return bForceD3D12 ? D3DApiLevel::Direct3D12 : D3DApiLevel::Direct3D11;
			}
		}

		if (RHIString == TEXT("D3D11"))
		{
			return D3DApiLevel::Direct3D11;
		}
		if (RHIString == TEXT("D3D12"))
		{
			return D3DApiLevel::Direct3D12;
		}

		return D3DApiLevel::Undefined;
	}

#endif
private:
	TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > VulkanExtensions;
};
IMPLEMENT_MODULE(FPicoDPPlugin, PicoXRDPHMD)

TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > FPicoDPPlugin::CreateTrackingSystem()
{
	PXR_LOGD(PxrUnreal,"PXR_DP Start CreateTrackingSystem!");
#if STEAMVR_SUPPORTED_PLATFORMS

	TSharedPtr< FPicoDirectPreviewHMD, ESPMode::ThreadSafe > PicoDPHMD = FSceneViewExtensions::NewExtension<FPicoDirectPreviewHMD>(this);
	if (PicoDPHMD)
	{
		return PicoDPHMD;
	}
#endif//STEAMVR_SUPPORTED_PLATFORMS
	return nullptr;
}


//---------------------------------------------------
// PicoDP IHeadMountedDisplay Implementation
//---------------------------------------------------

#if STEAMVR_SUPPORTED_PLATFORMS


bool FPicoDirectPreviewHMD::IsHMDConnected()
{
	return PicoDPPlugin->IsHMDConnected();
}

bool FPicoDirectPreviewHMD::IsHMDEnabled() const
{
	return bHmdEnabled;
}

EHMDWornState::Type FPicoDirectPreviewHMD::GetHMDWornState()
{
	return HmdWornState;
}

void FPicoDirectPreviewHMD::EnableHMD(bool enable)
{
	bHmdEnabled = enable;

	if (!bHmdEnabled)
	{
		EnableStereo(false);
	}
}

bool FPicoDirectPreviewHMD::GetHMDMonitorInfo(MonitorInfo& MonitorDesc)
{
	MonitorDesc.MonitorName = "";
	MonitorDesc.MonitorId = 0;
	MonitorDesc.DesktopX = MonitorDesc.DesktopY = MonitorDesc.ResolutionX = MonitorDesc.ResolutionY = 0;
	return false;
}

void FPicoDirectPreviewHMD::GetFieldOfView(float& OutHFOVInDegrees, float& OutVFOVInDegrees) const
{
	OutHFOVInDegrees = 0.0f;
	OutVFOVInDegrees = 0.0f;
}

bool FPicoDirectPreviewHMD::DoesSupportPositionalTracking() const
{
	return true;
}

bool FPicoDirectPreviewHMD::HasValidTrackingPosition()
{
	return true;
}

bool FPicoDirectPreviewHMD::GetTrackingSensorProperties(int32 SensorId, FQuat& OutOrientation, FVector& OutOrigin, FXRSensorProperties& OutSensorProperties)
{
	OutOrigin = FVector::ZeroVector;
	OutOrientation = FQuat::Identity;
	OutSensorProperties = FXRSensorProperties();
	return true;
}
#if ENGINE_MINOR_VERSION >25
FString FPicoDirectPreviewHMD::GetTrackedDevicePropertySerialNumber(int32 DeviceId)
{
	return FString();
}
#endif
void FPicoDirectPreviewHMD::SetInterpupillaryDistance(float NewInterpupillaryDistance)
{
}

float FPicoDirectPreviewHMD::GetInterpupillaryDistance() const
{
	return 0.064f;
}

bool FPicoDirectPreviewHMD::GetCurrentPose(int32 DeviceId, FQuat& CurrentOrientation, FVector& CurrentPosition)
{
	FQuat tempCurrentOrientation = FQuat::Identity;

	if (CurrentDirectPreview)
	{
		CurrentDirectPreview->GetPositionAndRotation(CurrentPosition, tempCurrentOrientation);
		CurrentPosition = FVector(-CurrentPosition.Z, CurrentPosition.X, CurrentPosition.Y) * 100;
		CurrentOrientation.X = tempCurrentOrientation.Z;
		CurrentOrientation.Y = -tempCurrentOrientation.X;
		CurrentOrientation.Z = -tempCurrentOrientation.Y;
		CurrentOrientation.W = tempCurrentOrientation.W;
		//Todo:Prevent crashes caused by invalid Unnormalized data
		CurrentOrientation.Normalize();
	}
	return true;
}

void FPicoDirectPreviewHMD::SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin)
{
}

EHMDTrackingOrigin::Type FPicoDirectPreviewHMD::GetTrackingOrigin() const
{
	return EHMDTrackingOrigin::Floor;
}

bool FPicoDirectPreviewHMD::GetFloorToEyeTrackingTransform(FTransform& OutStandingToSeatedTransform) const
{
	bool bSuccess = false;
	return bSuccess;
}
#if ENGINE_MINOR_VERSION >26
FVector2D FPicoDirectPreviewHMD::GetPlayAreaBounds(EHMDTrackingOrigin::Type Origin) const
{
	FVector2D Bounds;
	if (Origin == EHMDTrackingOrigin::Stage)
	{
		return Bounds;
	}

	return FVector2D::ZeroVector;
}
#endif
void FPicoDirectPreviewHMD::RecordAnalytics()
{
}

float FPicoDirectPreviewHMD::GetWorldToMetersScale() const
{
	return 100.0f;
}


bool FPicoDirectPreviewHMD::EnumerateTrackedDevices(TArray<int32>& TrackedIds, EXRTrackedDeviceType DeviceType)
{
	TrackedIds.Empty();
	if (DeviceType == EXRTrackedDeviceType::Any || DeviceType == EXRTrackedDeviceType::HeadMountedDisplay)
	{
		TrackedIds.Add(IXRTrackingSystem::HMDDeviceId);
		return true;
	}
	return false;
}


bool FPicoDirectPreviewHMD::IsTracking(int32 DeviceId)
{
	return true;
}

bool FPicoDirectPreviewHMD::IsChromaAbCorrectionEnabled() const
{
	return false;
}

void FPicoDirectPreviewHMD::OnBeginPlay(FWorldContext& InWorldContext)
{
	PXR_LOGD(PxrUnreal,"PXR_DP OnBeginPlay!");
	if (CurrentDirectPreview)
	{
		PXR_LOGD(PxrUnreal,"PXR_DP GetRemoteID!");
		CurrentDirectPreview->GetRemoteID();
	}

	UHeadMountedDisplayFunctionLibrary::SetSpectatorScreenMode(ESpectatorScreenMode::SingleEye);


	GEngine->bUseFixedFrameRate = true;
	GEngine->FixedFrameRate = 72;
}

void FPicoDirectPreviewHMD::OnEndPlay(FWorldContext& InWorldContext)
{
	if (!GEnableVREditorHacks)
	{
		EnableStereo(false);
	}

	GEngine->bUseFixedFrameRate = false;
	GEngine->FixedFrameRate = 30;
}

const FName FPicoDirectPreviewHMD::SystemName(TEXT("PicoDP"));

FString FPicoDirectPreviewHMD::GetVersionString() const
{
	return FString();
}

bool FPicoDirectPreviewHMD::OnStartGameFrame(FWorldContext& WorldContext)
{
	if (bStereoEnabled != bStereoDesired)
	{
		bStereoEnabled = EnableStereo(bStereoDesired);
	}
	return true;
}

void FPicoDirectPreviewHMD::ResetOrientationAndPosition(float yaw)
{
	ResetOrientation(yaw);
	ResetPosition();
}

void FPicoDirectPreviewHMD::ResetOrientation(float Yaw)
{
	BaseOrientation = FQuat::Identity;
}
void FPicoDirectPreviewHMD::ResetPosition()
{
	BaseOffset = FVector();
}

void FPicoDirectPreviewHMD::SetBaseRotation(const FRotator& BaseRot)
{
	BaseOrientation = BaseRot.Quaternion();
}
FRotator FPicoDirectPreviewHMD::GetBaseRotation() const
{
	return FRotator::ZeroRotator;
}

void FPicoDirectPreviewHMD::SetBaseOrientation(const FQuat& BaseOrient)
{
	BaseOrientation = BaseOrient;
}

FQuat FPicoDirectPreviewHMD::GetBaseOrientation() const
{
	return BaseOrientation;
}

void FPicoDirectPreviewHMD::SetBasePosition(const FVector& BasePosition)
{
	BaseOffset = BasePosition;
}

FVector FPicoDirectPreviewHMD::GetBasePosition() const
{
	return BaseOffset;
}

bool FPicoDirectPreviewHMD::IsStereoEnabled() const
{
	return  bStereoEnabled && bHmdEnabled;
}

bool FPicoDirectPreviewHMD::EnableStereo(bool bStereo)
{
	if (bStereoEnabled == bStereo)
	{
		return false;
	}

	if ((!bStereo))
	{
		return false;
	}

	bStereoDesired = (IsHMDEnabled()) ? bStereo : false;

	// Set the viewport to match that of the HMD display
	FSceneViewport* SceneVP = FindSceneViewport();
	if (SceneVP)
	{
		TSharedPtr<SWindow> Window = SceneVP->FindWindow();
		if (Window.IsValid() && SceneVP->GetViewportWidget().IsValid())
		{
			// Set MirrorWindow state on the Window
			Window->SetMirrorWindow(bStereo);

			if (bStereo)
			{
				uint32 Width, Height;

				Width = WindowMirrorBoundsWidth;
				Height = WindowMirrorBoundsHeight;

				bStereoEnabled = bStereoDesired;
				SceneVP->SetViewportSize(Width, Height);
			}
			else
			{
				//flush all commands that might call GetStereoProjectionMatrix or other functions that rely on bStereoEnabled 
				FlushRenderingCommands();

				// Note: Setting before resize to ensure we don't try to allocate a new vr rt.
				bStereoEnabled = bStereoDesired;

				FRHIViewport* const ViewportRHI = SceneVP->GetViewportRHI();
				if (ViewportRHI != nullptr)
				{
					ViewportRHI->SetCustomPresent(nullptr);
				}

				FVector2D size = SceneVP->FindWindow()->GetSizeInScreen();
				SceneVP->SetViewportSize(size.X, size.Y);
				Window->SetViewportSizeDrivenByWindow(true);
			}
		}
	}

	// Uncap fps to enable FPS higher than 62
	GEngine->bForceDisableFrameRateSmoothing = bStereoEnabled;

	return bStereoEnabled;
}

void FPicoDirectPreviewHMD::AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
	SizeX = FMath::CeilToInt(IdealRenderTargetSize.X * PixelDensity);
	SizeY = FMath::CeilToInt(IdealRenderTargetSize.Y * PixelDensity);

	SizeX = SizeX / 2;
	if (StereoPass == eSSP_RIGHT_EYE)
	{
		X += SizeX;
	}
}

bool FPicoDirectPreviewHMD::GetRelativeEyePose(int32 DeviceId, EStereoscopicPass Eye, FQuat& OutOrientation, FVector& OutPosition)
{
	OutOrientation = FQuat::Identity;
	OutPosition = FVector::ZeroVector;
	if (DeviceId == IXRTrackingSystem::HMDDeviceId && (Eye == eSSP_LEFT_EYE || Eye == eSSP_RIGHT_EYE))
	{
		OutPosition = FVector(0, (Eye == EStereoscopicPass::eSSP_LEFT_EYE ? -.5 : .5) * 0.064f * GetWorldToMetersScale(), 0);
		return true;
	}
	else
	{
		return false;
	}
}

void FPicoDirectPreviewHMD::CalculateStereoViewOffset(const enum EStereoscopicPass StereoPassType, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation)
{
	// Needed to transform world locked stereo layers
	PlayerLocation = ViewLocation;

	// Forward to the base implementation (that in turn will call the DefaultXRCamera implementation)
	FHeadMountedDisplayBase::CalculateStereoViewOffset(StereoPassType, ViewRotation, WorldToMeters, ViewLocation);
}

FMatrix FPicoDirectPreviewHMD::GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType) const
{
	check(IsStereoEnabled() || IsHeadTrackingEnforced());
	
	FPicoXRFrustumDP Frustum = (StereoPassType == eSSP_LEFT_EYE) ? LeftFrustum : RightFrustum;
	const float ProjectionCenterOffset = 0;// 0.151976421f;
	const float PassProjectionOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionCenterOffset : -ProjectionCenterOffset;
	// correct far and near planes for reversed-Z projection matrix
	const float WorldScale = GetWorldToMetersScale() * (1.0 / 100.0f); // physical scale is 100 UUs/meter
	float ZNear = GNearClippingPlane * WorldScale;
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

void FPicoDirectPreviewHMD::GetEyeRenderParams_RenderThread(const FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const
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

bool FPicoDirectPreviewHMD::GetHMDDistortionEnabled(EShadingPath /* ShadingPath */) const
{
	return false;
}

void FPicoDirectPreviewHMD::OnBeginRendering_GameThread()
{
	check(IsInGameThread());
	SpectatorScreenController->BeginRenderViewFamily();
}

void FPicoDirectPreviewHMD::OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily)
{
	check(IsInRenderingThread());
	//UpdatePoses();

	check(pBridge);
	pBridge->BeginRendering_RenderThread(RHICmdList);

	check(SpectatorScreenController);
	SpectatorScreenController->UpdateSpectatorScreenMode_RenderThread();

	// Update PlayerOrientation used by StereoLayers positioning
	const FSceneView* MainView = ViewFamily.Views[0];
	const FQuat ViewOrientation = MainView->ViewRotation.Quaternion();
	PlayerOrientation = ViewOrientation * MainView->BaseHmdOrientation.Inverse();
}

FXRRenderBridge* FPicoDirectPreviewHMD::GetActiveRenderBridge_GameThread(bool /* bUseSeparateRenderTarget */)
{
	check(IsInGameThread());

	return pBridge;
}

void FPicoDirectPreviewHMD::CalculateRenderTargetSize(const class FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY)
{
	check(IsInGameThread());

	if (!IsStereoEnabled())
	{
		return;
	}

	InOutSizeX = FMath::CeilToInt(IdealRenderTargetSize.X * PixelDensity);
	InOutSizeY = FMath::CeilToInt(IdealRenderTargetSize.Y * PixelDensity);

	check(InOutSizeX != 0 && InOutSizeY != 0);
}

bool FPicoDirectPreviewHMD::NeedReAllocateViewportRenderTarget(const FViewport& Viewport)
{
	check(IsInGameThread());

	if (IsStereoEnabled())
	{
		const uint32 InSizeX = Viewport.GetSizeXY().X;
		const uint32 InSizeY = Viewport.GetSizeXY().Y;
		const FIntPoint RenderTargetSize = Viewport.GetRenderTargetTextureSizeXY();
		uint32 NewSizeX = InSizeX, NewSizeY = InSizeY;
		CalculateRenderTargetSize(Viewport, NewSizeX, NewSizeY);
		if (NewSizeX != RenderTargetSize.X || NewSizeY != RenderTargetSize.Y)
		{
			return true;
		}
	}
	return false;
}
static const uint32 PicoDPSwapChainLength = 1;
#if ENGINE_MINOR_VERSION > 25
bool FPicoDirectPreviewHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
#else
bool FPicoDirectPreviewHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, uint32 Flags, uint32 TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples /*= 1*/)
#endif
{
	PXR_LOGD(PxrUnreal,"PXR_DP AllocatedRT!");
	if (!IsStereoEnabled())
	{
		return false;
	}

	TArray<FTextureRHIRef> SwapChainTextures;
	FTextureRHIRef BindingTexture;

	if (pBridge != nullptr && pBridge->GetSwapChain() != nullptr && pBridge->GetSwapChain()->GetTexture2D() != nullptr && pBridge->GetSwapChain()->GetTexture2D()->GetSizeX() == SizeX && pBridge->GetSwapChain()->GetTexture2D()->GetSizeY() == SizeY)
	{
		OutTargetableTexture = (FTexture2DRHIRef&)pBridge->GetSwapChain()->GetTextureRef();
		OutShaderResourceTexture = OutTargetableTexture;
		return true;
	}

	for (uint32 SwapChainIter = 0; SwapChainIter < PicoDPSwapChainLength; ++SwapChainIter)
	{
		FRHIResourceCreateInfo CreateInfo;
		FTexture2DRHIRef TargetableTexture, ShaderResourceTexture;
#if ENGINE_MINOR_VERSION > 25
		PXR_LOGD(PxrUnreal,"PXR_DP SizeX:%d,SizeY:%d,InTexFlags:%d,CreateFlags:%d,NumSample:%d", SizeX, SizeY, Flags, TargetableTextureFlags, NumSamples);
#endif
		//TargetableTexture = ShaderResourceTexture = RHICreateTexture2D(SizeX, SizeY, PF_R8G8B8A8, 1, 1, TexCreate_Shared | TexCreate_RenderTargetable, CreateInfo);

		RHICreateTargetableShaderResource2D(SizeX, SizeY, PF_R8G8B8A8, 1, TexCreate_None, TexCreate_RenderTargetable | TexCreate_Shared, false, CreateInfo, TargetableTexture, ShaderResourceTexture, NumSamples);

		check(TargetableTexture == ShaderResourceTexture);

		SwapChainTextures.Add((FTextureRHIRef&)TargetableTexture);

		if (BindingTexture == nullptr)
		{
			BindingTexture = GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TargetableTexture);
		}
	}

	pBridge->CreateSwapChain(BindingTexture, MoveTemp(SwapChainTextures));

	// These are the same.
	OutTargetableTexture = (FTexture2DRHIRef&)BindingTexture;
	OutShaderResourceTexture = (FTexture2DRHIRef&)BindingTexture;

	return true;
}

FPicoDirectPreviewHMD::FPicoDirectPreviewHMD(const FAutoRegister& AutoRegister, IPicoDPPlugin* InPicoDPPlugin) :
	FHeadMountedDisplayBase(nullptr),
	FSceneViewExtensionBase(AutoRegister),
	bHmdEnabled(true),
	HmdWornState(EHMDWornState::Unknown),
	bStereoDesired(false),
	bStereoEnabled(false),
	bOcclusionMeshesBuilt(false),
	WindowMirrorBoundsWidth(2160),
	WindowMirrorBoundsHeight(1200),
	PixelDensity(1.0f),
	HMDWornMovementThreshold(50.0f),
	HMDStartLocation(FVector::ZeroVector),
	BaseOrientation(FQuat::Identity),
	BaseOffset(FVector::ZeroVector),
	bIsQuitting(false),
	QuitTimestamp(),
	bShouldCheckHMDPosition(false),
	RendererModule(nullptr),
	PicoDPPlugin(InPicoDPPlugin)
{
	Startup();
}

FPicoDirectPreviewHMD::~FPicoDirectPreviewHMD()
{
	Shutdown();
}

bool FPicoDirectPreviewHMD::IsInitialized() const
{
	return true;
}

bool FPicoDirectPreviewHMD::Startup()
{
	// grab a pointer to the renderer module for displaying our mirror window
	static const FName RendererModuleName("Renderer");
	RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	PXR_LOGD(PxrUnreal,"PXR_DP startup begin");
	// Re-initialize the plugin if we're canceling the shutdown

	IdealRenderTargetSize = FIntPoint(1920, 1920);
	static const auto PixelDensityCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
	if (PixelDensityCVar)
	{
		PixelDensity = 1;
	}
	// enforce finishcurrentframe
	static IConsoleVariable* CFCFVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.finishcurrentframe"));
	CFCFVar->Set(false);

	if (IsPCPlatform(GMaxRHIShaderPlatform))
	{

#if PLATFORM_WINDOWS

		{
			auto level = FPicoDPPlugin::GetD3DApiLevel();

			if (level == FPicoDPPlugin::D3DApiLevel::Direct3D11)
			{
				pBridge = new D3D11Bridge(this);
			}

		}
#endif
		ensure(pBridge != nullptr);
	}
	CreateSpectatorScreenController();
	CurrentDirectPreview = MakeShareable(new DP());
#if WITH_EDITOR
	ULevelEditorPlaySettings* PlaySettingsConfig = GetMutableDefault<ULevelEditorPlaySettings>();
	PlaySettingsConfig->NewWindowHeight = 1920;
	PlaySettingsConfig->NewWindowWidth = 1920;
#endif
	PXR_LOGD(PxrUnreal,"PXR_DP start up finished!");
	return true;
}


void FPicoDirectPreviewHMD::Shutdown()
{

}

const FPicoDirectPreviewHMD::FTrackingFrame& FPicoDirectPreviewHMD::GetTrackingFrame() const
{
	if (IsInRenderingThread())
	{
		return RenderTrackingFrame;
	}
	else
	{
		return GameTrackingFrame;
	}
}

#endif //STEAMVR_SUPPORTED_PLATFORMS

