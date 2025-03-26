// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "PXR_HMDModule.h"
#include "PXR_HMDSettings.h"
#include "CoreMinimal.h"
#include "PXR_Splash.h"
#include "IStereoLayers.h"
#include "XRRenderBridge.h"
#include "PXR_StereoLayer.h"
#include "SceneViewExtension.h"
#include "PXR_EventManager.h"
#include "XRTrackingSystemBase.h"
#include "XRRenderTargetManager.h"
#include "HeadMountedDisplayBase.h"
#include "SceneUtils.h"
#include "PXR_GameFrame.h"
#include "StereoLayerManager.h"
#include "PXR_DelayDeleteLayer.h"
#include "PXR_FoveatedRendering.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPICOPollEventDelegate, PxrEventDataBuffer* /*EventData*/);
DECLARE_MULTICAST_DELEGATE(FPICOPollFutureFromHMDDelegate);

class FPICOXRRenderBridge;
class UPICOContentResourceFinder;

#ifdef PICO_CUSTOM_ENGINE
enum FHomeResetTypes
{
	HomeResetOrientation = 0x1,
	HomeResetPosition = 0x2,
	HomeResetOrientationAndPosition = 0x3
};
#endif

struct FPICOXRFrustum
{
	float FovLeft;
	float FovRight;
	float FovUp;
	float FovDown;
	float Near;
	float Far;

	FPICOXRFrustum()
	{
		FovUp    = 0.88119f;
		FovDown  = -0.88119f;
		FovLeft  = -0.88119f;
		FovRight = 0.88119f;
		Near     = 0.0508f;
		Far      = 100;
	}
	FString ToString() const
	{
		return
			TEXT(" FPICOXRFrustum Left : ") + FString::SanitizeFloat(FovLeft) +
			TEXT(" FPICOXRFrustum Right : ") + FString::SanitizeFloat(FovRight) +
			TEXT(" FPICOXRFrustum Up : ") + FString::SanitizeFloat(FovUp) +
			TEXT(" FPICOXRFrustum Down : ") + FString::SanitizeFloat(FovDown) +
			TEXT(" FPICOXRFrustum H : ") + FString::SanitizeFloat(FovRight - FovLeft) +
			TEXT(" FPICOXRFrustum V : ") + FString::SanitizeFloat(FovUp - FovDown )+
			TEXT(" FPICOXRFrustum Near : ") + FString::SanitizeFloat(Near) +
            TEXT(" FPICOXRFrustum Far : ") + FString::SanitizeFloat(Far) ;
	}
};

struct FCurrentFrameValue
{
	FVector CurrentPosition;
	FQuat CurrentOrientation;
	FVector AngularVelocity;
	FVector Acceleration;
	FVector AngularAcceleration;
	FVector Velocity;
	float IPD;
	int32 ViewNumber;
	float WorldToMetersScale;
	FTransform TrackingToWorld;		// for overlay
	FCurrentFrameValue()
	{
		IPD                 = 0.063f;
		ViewNumber          = 0;
		WorldToMetersScale  = 100.0f;
		CurrentPosition     = FVector::ZeroVector;
		CurrentOrientation  = FQuat::Identity;
		AngularVelocity     = FVector::ZeroVector;
		Acceleration        = FVector::ZeroVector;
		AngularAcceleration = FVector::ZeroVector;
		Velocity            = FVector::ZeroVector;
		TrackingToWorld     = FTransform::Identity;
	}
	FString ToString() const
	{
		return
			TEXT(" CurrentPosition : ") + CurrentPosition.ToString() +
            TEXT(" CurrentOrientation : ") + CurrentOrientation.ToString() +
			TEXT(" AngularVelocity : ") + AngularVelocity.ToString() +
			TEXT(" Acceleration : ") + Acceleration.ToString() +
			TEXT(" AngularAcceleration : ") + AngularAcceleration.ToString() +
			TEXT(" Velocity : ") + Velocity.ToString() +
            TEXT(" IPD: ") + FString::SanitizeFloat(IPD) +
            TEXT(" ViewNumber : ") + FString::FromInt(ViewNumber) +
			TEXT(" WorldToMetersScale : ") + FString::SanitizeFloat(WorldToMetersScale);
	}
};

/**
 * PICOXR Head Mounted Display
 */
class FPICOXRHMD : public FHeadMountedDisplayBase, public FXRRenderTargetManager, public FSceneViewExtensionBase , public IStereoLayers
{
public:
	/** IXRTrackingSystem interface */
	virtual FName GetSystemName() const override;
	virtual bool EnumerateTrackedDevices(TArray<int32>& OutDevices, EXRTrackedDeviceType Type = EXRTrackedDeviceType::Any) override;
	virtual void ResetOrientationAndPosition(float yaw = 0.f) override;
	virtual void ResetOrientation(float Yaw = 0.f) override;
	virtual void ResetPosition() override;
	virtual void SetBaseRotation(const FRotator& BaseRot) override;
	virtual FRotator GetBaseRotation() const override;
	virtual void SetBaseOrientation(const FQuat& BaseOrient) override;
	virtual FQuat GetBaseOrientation() const override;
	virtual bool GetCurrentPose(int32 DeviceId, FQuat& CurrentOrientation, FVector& CurrentPosition) override;
	virtual class IHeadMountedDisplay* GetHMDDevice() override { return this;};
	virtual class TSharedPtr< class IStereoRendering, ESPMode::ThreadSafe > GetStereoRenderingDevice() override;
	virtual float GetWorldToMetersScale() const override;
	virtual void OnBeginRendering_GameThread() override;
	virtual void OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily) override;
	virtual bool OnStartGameFrame(FWorldContext& WorldContext) override;
	virtual bool OnEndGameFrame(FWorldContext& WorldContext) override;
	virtual class IXRLoadingScreen* CreateLoadingScreen() override { return GetSplash().Get(); }
	virtual void OnBeginPlay(FWorldContext& InWorldContext) override;
	virtual void OnEndPlay(FWorldContext& InWorldContext) override;
	virtual void GetMotionControllerData(UObject* WorldContext, const EControllerHand Hand, FXRMotionControllerData& MotionControllerData) override;
	virtual int32 GetXRSystemFlags() const override;

	/** IHeadMountedDisplay interface */
	virtual void SetInterpupillaryDistance(float NewInterpupillaryDistance) override;
	virtual float GetInterpupillaryDistance() const override;
	virtual bool IsHMDConnected() override;
	virtual bool IsHMDEnabled() const override;
	virtual void EnableHMD(bool allow = true) override;
	virtual bool GetHMDMonitorInfo(MonitorInfo &MonitorDesc) override;
	virtual void GetFieldOfView(float& OutHFOVInDegrees, float& OutVFOVInDegrees) const override;
	virtual bool IsChromaAbCorrectionEnabled() const override;
	virtual FIntPoint GetIdealRenderTargetSize() const override;
	virtual void GetEyeRenderParams_RenderThread(const FHeadMountedDisplayPassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const override;
	virtual EHMDWornState::Type GetHMDWornState() override;
	virtual float GetPixelDenity() const override;
	virtual void SetPixelDensity(const float NewPixelDensity) override;

	/** FXRTrackingSystemBase interface */
	virtual bool GetRelativeEyePose(int32 InDeviceId, int32 ViewIndex,FQuat& OutOrientation, FVector& OutPosition) override;
	virtual	bool GetTrackingSensorProperties(int32 InDeviceId, FQuat& OutOrientation, FVector& OutPosition, FXRSensorProperties& OutSensorProperties) override;
	virtual void SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin) override;
	virtual EHMDTrackingOrigin::Type GetTrackingOrigin() const override;
	virtual bool DoesSupportPositionalTracking() const override;
	virtual bool IsHeadTrackingAllowed() const override;
	
	/** FHMDSceneViewExtension interface */
	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override;
	/** FHeadMountedDisplayBase interface */
	virtual bool GetHMDDistortionEnabled(EShadingPath ShadingPath) const override { return false; }

	/** IStereoRendering interface */
	virtual bool IsStereoEnabled() const override;
	virtual bool EnableStereo(bool stereo = true) override;
	virtual void AdjustViewRect(int32 ViewIndex, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const  override;
	virtual FMatrix GetStereoProjectionMatrix(int32 ViewIndex) const override;
	virtual void SetFinalViewRect(FRHICommandListImmediate& RHICmdList, const int32 ViewIndex, const FIntRect& FinalViewRect) override;
	virtual int32 AcquireColorTexture() override final;


	virtual IStereoRenderTargetManager* GetRenderTargetManager() override { return this; }
	//virtual void RenderTexture_RenderThread(class FRHICommandListImmediate& RHICmdList, class FRHITexture2D* BackBuffer, class FRHITexture2D* SrcTexture, FVector2D WindowSize) const override;
	virtual void RenderTexture_RenderThread(class FRHICommandListImmediate& RHICmdList, class FRHITexture* BackBuffer, class FRHITexture* SrcTexture, FVector2D WindowSize) const override;

	/** ISceneViewExtension interface */
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override;
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void PreRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;
	virtual void PreRenderView_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView) override;
	virtual void PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;
	virtual void PostRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override;
#ifdef PICO_CUSTOM_ENGINE
	virtual void PostRenderBasePassMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView) override;
	virtual void PostSceneColorRenderingMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView) override;
#endif
	virtual int32 GetPriority() const override { return -1; }

#ifdef PICO_CUSTOM_ENGINE
	virtual bool LateLatchingEnabled() const override;
	virtual void PreLateLatchingViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;
#endif

	/** IStereoRenderTargetManager interface */
	virtual bool ShouldUseSeparateRenderTarget() const override { return true; }
#ifdef PICO_CUSTOM_ENGINE
	virtual bool NeedReAllocateMotionVectorTexture(const TRefCountPtr<IPooledRenderTarget>& MotionVectorTarget, const TRefCountPtr<IPooledRenderTarget>& MotionVectorDepthTarget) override;
	virtual bool AllocateMotionVectorTexture(uint32 Index, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize, FTexture2DRHIRef& OutDepthTexture, FIntPoint& OutDepthTextureSize) override;
#endif	
	virtual bool AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
	virtual bool NeedReAllocateShadingRateTexture(const TRefCountPtr<IPooledRenderTarget>& FoveationTarget) override;
	virtual bool AllocateShadingRateTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize) override;

  /** FXRRenderTargetManager interface */
	virtual void CalculateRenderTargetSize(const class FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY)override;
	virtual bool NeedReAllocateViewportRenderTarget(const FViewport& Viewport) override;
	virtual FXRRenderBridge* GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget) override;

	virtual IStereoLayers* GetStereoLayers() override { return this; }
	virtual uint32 CreateLayer(const IStereoLayers::FLayerDesc& InLayerDesc) override;
	virtual void DestroyLayer(uint32 LayerId) override;
	virtual void SetLayerDesc(uint32 LayerId, const IStereoLayers::FLayerDesc& InLayerDesc) override;
	virtual bool GetLayerDesc(uint32 LayerId, IStereoLayers::FLayerDesc& OutLayerDesc) override;
	virtual void MarkTextureForUpdate(uint32 LayerId) override;
	virtual void UpdateSplashScreen() override;
	virtual FLayerDesc GetDebugCanvasLayerDesc(FTextureRHIRef Texture) override;
	virtual void GetAllocatedTexture(uint32 LayerId, FTextureRHIRef &Texture, FTextureRHIRef &LeftTexture) override;
	virtual bool ShouldCopyDebugLayersToSpectatorScreen() const override { return true; }
	virtual bool IsStandaloneStereoOnlyDevice() const override { return true; }

	FPICOXRHMD(const FAutoRegister&);
	virtual ~FPICOXRHMD();
	void BeginXR();
	void EndXR();
	class FPICOXRInput* GetPICOXRInput();
	float UPxr_GetIPD() const;

	FPICOXRSplashPtr GetSplash() const {return  PICOSplash;};

	bool Startup();
	void Shutdown();
	bool InitializeSession();
	void DoSessionShutdown();
	void ShutdownSession();
	bool InitDevice();
	void ReleaseDevice();
	void LoadFromSettings();
	FPICOXRRenderBridge* GetCustomRenderBridge() const { return RenderBridge; }

	void UPxr_GetAngularAcceleration(FVector& AngularAcceleration);
	void UPxr_GetVelocity(FVector& Velocity);
	void UPxr_GetAcceleration(FVector& Acceleration);
	void UPxr_GetAngularVelocity(FVector& AngularVelocity);
	int32 UPxr_SetFieldOfView(EPICOXREyeType Eye, float FovLeftInDegrees, float FovRightInDegrees, float FovUpInDegrees, float FovDownInDegrees);

	FString UPxr_GetDeviceModel();
	void ClearTexture_RHIThread(FRHITexture2D* SrcTexture);
	void SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers = false);
	uint32 CreateMRCStereoLayer(FTextureRHIRef BackgroundRTTexture, FTextureRHIRef ForegroundRTTexture);
	void DestroyMRCLayer();

	FString GetRHIString();
#ifdef PICO_CUSTOM_ENGINE
	bool IsSupportsSpaceWarp() const;
#endif
	void OnPreLoadMap(const FString& MapName);
	FDelegateHandle PreLoadLevelDelegate;
	bool bNeedDrawBlackEye;
	void WaitFrame();
	void LateUpdatePose();
	void OnGameFrameBegin_GameThread();
	void OnGameFrameEnd_GameThread();
	void OnRenderFrameBegin_GameThread();
	void OnRenderFrameEnd_RenderThread(FRDGBuilder& RDGBuilder);
	void OnRHIFrameBegin_RenderThread();
	void OnRHIFrameEnd_RHIThread();
	FSettingsPtr CreateNewSettings() const;
	FPXRGameFramePtr MakeNewGameFrame() const;
	void UpdateStereoRenderingParams();
	bool UpdateHMDBatteryLevelFromJava(int32& BatteryLevel);
	bool UpdateHMDBatteryLevelFromPollEvent(int32& BatteryLevel);
	bool SetCurrentCoordinateType(EPICOXRCoordinateType InCoordinateType);
	
	// Game thread
	FSettingsPtr GameSettings;
	uint32 NextGameFrameNumber;
	uint32 WaitedFrameNumber;
	FPXRGameFramePtr GameFrame_GameThread;
	FPXRGameFramePtr NextGameFrameToRender_GameThread;
	FPXRGameFramePtr LastGameFrameToRender_GameThread;
	TMap<uint32, FPICOLayerPtr> PXRLayerMap;
	FPICOLayerPtr CurrentMRCLayer;
	// Render thread
	FSettingsPtr GameSettings_RenderThread;
	FPXRGameFramePtr GameFrame_RenderThread;
	TArray<FPICOLayerPtr> PXRLayers_RenderThread;
	FPICOLayerPtr PXREyeLayer_RenderThread;
	// RHI thread
	FSettingsPtr GameSettings_RHIThread;
	FPXRGameFramePtr GameFrame_RHIThread;
	TArray<FPICOLayerPtr> PXRLayers_RHIThread;
	double CurrentFramePredictedTime = 0;
	bool bWaitFrameVersion = false;
	float CachedWorldToMetersScale = 100.0f;


	UPICOXREventManager* EventManager;
	uint32 NextLayerId;
	bool MRCEnabled=false;
	
	UPROPERTY()
	class AMRCSceneCapture2DPICO* MRCCamera = nullptr;

	bool bNeedReAllocateFoveationTexture_RenderThread = false;
	bool bNeedReAllocateViewportRenderTarget = false;
#ifdef PICO_CUSTOM_ENGINE
	bool bNeedReAllocateMotionVectorTexture_RenderThread = false;
	bool bIsMobileToneMapping=false;
#endif
	bool inputFocusState = true;
#if !UE_VERSION_OLDER_THAN(5, 3, 0)
	TSharedPtr<FPICOXRFoveatedRenderingImageGenerator, ESPMode::ThreadSafe> FoveationImageGenerator;
#endif // !UE_VERSION_OLDER_THAN(5, 3, 0)

	PICOXRHMD_API void PollEvent();
	UPICOContentResourceFinder* GetContentResourceFinder(){return ContentResourceFinder;}
	void AllocateEyeLayer();
	bool IsUsingMobileMultiView() { return bIsUsingMobileMultiView; }

	FDelayDeleteLayerManager DelayDeletion;
	void UpdateSensorValue(const FGameSettings* InSettings, FPXRGameFrame* InFrame);
	double DisplayRefreshRate;

	void SetBaseOffsetInMeters(const FVector& BaseOffset);
	PICOXRHMD_API FVector GetBaseOffsetInMeters() const;

	PICOXRHMD_API FPICOPollEventDelegate& OnPollEventDelegate()
	{
		return PollEventDelegate;
	}

	PICOXRHMD_API FPICOPollFutureFromHMDDelegate& OnPollFutureDelegate()
	{
		return PollFutureDelegate;
	}

	PICOXRHMD_API bool ConvertPose(const PxrPosef& InPose, FPose& OutPose) const;
	PICOXRHMD_API bool ConvertPose(const FPose& InPose, PxrPosef& OutPose) const;
	PICOXRHMD_API static bool ConvertPose_Internal(const PxrPosef& InPose, FPose& OutPose, const FGameSettings* Settings, float WorldToMetersScale = 100.0f);
	PICOXRHMD_API static bool ConvertPose_Internal(const FPose& InPose, PxrPosef& OutPose, const FGameSettings* Settings, float WorldToMetersScale = 100.0f);

	void SetFoveationRenderingMode(EFoveationRenderingMode Mode)
	{
		PICOXRSetting->FoveationRenderingMode = Mode;
	}

protected:
	void Recenter(PxrRecenterTypes RecenterType, float Yaw);
	void InitEyeLayer_RenderThread(FRHICommandListImmediate& RHICmdList);
#ifdef PICO_CUSTOM_ENGINE
	void UpdateFoveationOffsets_RenderThread();
#endif
	union
	{
		struct
		{
			uint64 NeedSetTrackingOrigin : 1;
			uint64 AppIsPaused : 1;
		};
		uint64 Raw;
	} PICOFlags;

private:
	void OnHomeKeyRecentered();

	void MakeAllStereolayerComponentsUpdate();
	void MakeAllStereoLayerComponentsDirty();

#ifdef PICO_CUSTOM_ENGINE
	// Stores TrackingToWorld from previous frame
	FTransform LastTrackingToWorld;
#endif

	void ProcessEvent(int EventCount, PxrEventDataBuffer** EventData);
	void ProcessControllerEvent( const PxrEventDataControllerChanged EventData);
	void OnSeeThroughStateChange(int SeeThroughState);
	void OnFoveationLevelChange(int32 FoveationLevel);
	void OnFrustumStateChange();
	void OnRenderTextureChange(int32 Width,int32 Height);
	void OnTargetFrameRateChange(int32 NewFrameRate);
	void ApplicationPauseDelegate();
	void ApplicationResumeDelegate();
	void EnableContentProtect(bool bEnable );
	void SetRefreshRate();
	int32 CurrentHMDBatteryLevel;
	bool bSeeThroughIsShown;
	bool bIsUsingMobileMultiView;
	EPICOXRCoordinateType CurrentCoordinateType;
	FIntPoint RTSize;
	FPICOXRFrustum LeftFrustum;
	FPICOXRFrustum RightFrustum;
	TRefCountPtr<FPICOXRRenderBridge> RenderBridge;
	class UPICOXRSettings* PICOXRSetting;
	FString RHIString;
	bool bIsEndGameFrame;
	EHMDTrackingOrigin::Type TrackingOrigin;
	static float IpdValue;
	APlayerController* PlayerController;
	FPICOXRSplashPtr PICOSplash;
	FString DeviceModel;
	UPICOContentResourceFinder* ContentResourceFinder;
	bool bShutdownRequestQueued;

	FPICOPollEventDelegate PollEventDelegate;
	FPICOPollFutureFromHMDDelegate PollFutureDelegate;
};

