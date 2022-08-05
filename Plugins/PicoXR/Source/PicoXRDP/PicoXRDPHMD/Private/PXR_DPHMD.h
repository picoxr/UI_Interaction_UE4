//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "IPXR_DPPlugin.h"
#include "HardwareInfo.h"
#if STEAMVR_SUPPORTED_PLATFORMS

#include "HeadMountedDisplay.h"
#include "HeadMountedDisplayBase.h"
#include "IStereoLayers.h"
#include "StereoLayerManager.h"
#include "XRRenderTargetManager.h"
#include "XRRenderBridge.h"
#include "XRSwapChain.h"
#include "IHeadMountedDisplayVulkanExtensions.h"
#include "SceneViewExtension.h"

#include "PXR_DP.h"

class IRendererModule;

struct FPicoXRFrustumDP
{
	float FovLeft;
	float FovRight;
	float FovUp;
	float FovDown;
	float Near;
	float Far;

	FPicoXRFrustumDP()
	{
		FovUp = 0.829031f;
		FovDown = -0.829031;
		FovLeft = -0.829031;
		FovRight = 0.829031;
		Near = 0.0508f;
		Far = 100;
	}
	FString ToString() const
	{
		return
			TEXT(" FPicoXRFrustum Left : ") + FString::SanitizeFloat(FovLeft) +
			TEXT(" FPicoXRFrustum Right : ") + FString::SanitizeFloat(FovRight) +
			TEXT(" FPicoXRFrustum Up : ") + FString::SanitizeFloat(FovUp) +
			TEXT(" FPicoXRFrustum Down : ") + FString::SanitizeFloat(FovDown) +
			TEXT(" FPicoXRFrustum H : ") + FString::SanitizeFloat(FovRight - FovLeft) +
			TEXT(" FPicoXRFrustum V : ") + FString::SanitizeFloat(FovUp - FovDown) +
			TEXT(" FPicoXRFrustum Near : ") + FString::SanitizeFloat(Near) +
			TEXT(" FPicoXRFrustum Far : ") + FString::SanitizeFloat(Far);
	}
};

/** Stores vectors, in clockwise order, to define soft and hard bounds for Chaperone */
struct FBoundingQuad
{
	FVector Corners[4];
};

//@todo steamvr: remove GetProcAddress() workaround once we have updated to Steamworks 1.33 or higher
typedef bool(VR_CALLTYPE* pVRIsHmdPresent)();
typedef void* (VR_CALLTYPE* pVRGetGenericInterface)(const char* pchInterfaceVersion, vr::HmdError* peError);

/**
 * Struct for managing stereo layer data.
 */
struct FPicoDPLayer
{
	typedef IStereoLayers::FLayerDesc FLayerDesc;
	FLayerDesc	          LayerDesc;
	vr::VROverlayHandle_t OverlayHandle;
	bool				  bUpdateTexture;

	FPicoDPLayer(const FLayerDesc& InLayerDesc)
		: LayerDesc(InLayerDesc)
		, OverlayHandle(vr::k_ulOverlayHandleInvalid)
		, bUpdateTexture(false)
	{}

	// Required by TStereoLayerManager:
	void SetLayerId(uint32 InId) { LayerDesc.SetLayerId(InId); }
	uint32 GetLayerId() const { return LayerDesc.GetLayerId(); }
	friend bool GetLayerDescMember(const FPicoDPLayer& Layer, FLayerDesc& OutLayerDesc);
	friend void SetLayerDescMember(FPicoDPLayer& Layer, const FLayerDesc& InLayerDesc);
	friend void MarkLayerTextureForUpdate(FPicoDPLayer& Layer);
};

/**
 * PicoDP Head Mounted Display public FPicoDPAssetManager,
 */
class FPicoDirectPreviewHMD : public FHeadMountedDisplayBase, public FXRRenderTargetManager, public TStereoLayerManager<FPicoDPLayer>, public FSceneViewExtensionBase
{
public:
	static const FName SystemName;

	/** IXRTrackingSystem interface */
	virtual FName GetSystemName() const override
	{
		return SystemName;
	}
#if ENGINE_MINOR_VERSION >25
	virtual int32 GetXRSystemFlags() const
	{
		return EXRSystemFlags::IsHeadMounted;
	}
#endif
	virtual FString GetVersionString() const override;

	virtual class IHeadMountedDisplay* GetHMDDevice() override
	{
		return this;
	}

	virtual class TSharedPtr< class IStereoRendering, ESPMode::ThreadSafe > GetStereoRenderingDevice() override
	{
		return SharedThis(this);
	}

	virtual bool OnStartGameFrame(FWorldContext& WorldContext) override;
	virtual bool DoesSupportPositionalTracking() const override;
	virtual bool HasValidTrackingPosition() override;
	virtual bool EnumerateTrackedDevices(TArray<int32>& TrackedIds, EXRTrackedDeviceType DeviceType = EXRTrackedDeviceType::Any) override;

	virtual bool GetTrackingSensorProperties(int32 InDeviceId, FQuat& OutOrientation, FVector& OutOrigin, FXRSensorProperties& OutSensorProperties) override;
#if ENGINE_MINOR_VERSION >25
	virtual FString GetTrackedDevicePropertySerialNumber(int32 DeviceId) override;
#endif
	virtual bool GetCurrentPose(int32 DeviceId, FQuat& CurrentOrientation, FVector& CurrentPosition) override;
	virtual bool GetRelativeEyePose(int32 DeviceId, EStereoscopicPass Eye, FQuat& OutOrientation, FVector& OutPosition) override;
	virtual bool IsTracking(int32 DeviceId) override;

	virtual void ResetOrientationAndPosition(float yaw = 0.f) override;
	virtual void ResetOrientation(float Yaw = 0.f) override;
	virtual void ResetPosition() override;

	virtual void SetBaseRotation(const FRotator& BaseRot) override;
	virtual FRotator GetBaseRotation() const override;
	virtual void SetBaseOrientation(const FQuat& BaseOrient) override;
	virtual FQuat GetBaseOrientation() const override;
	virtual void SetBasePosition(const FVector& BasePosition) override;
	virtual FVector GetBasePosition() const override;
	virtual void OnBeginPlay(FWorldContext& InWorldContext) override;
	virtual void OnEndPlay(FWorldContext& InWorldContext) override;
	virtual void RecordAnalytics() override;

	virtual void SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin) override;
	virtual EHMDTrackingOrigin::Type GetTrackingOrigin() const override;
	virtual bool GetFloorToEyeTrackingTransform(FTransform& OutFloorToEye) const override;
#if ENGINE_MINOR_VERSION >26
	virtual FVector2D GetPlayAreaBounds(EHMDTrackingOrigin::Type Origin) const override;
#endif



public:
	/** IHeadMountedDisplay interface */
	virtual bool IsHMDConnected() override;
	virtual bool IsHMDEnabled() const override;
	virtual EHMDWornState::Type GetHMDWornState() override;
	virtual void EnableHMD(bool allow = true) override;
	virtual bool GetHMDMonitorInfo(MonitorInfo&) override;

	virtual void GetFieldOfView(float& OutHFOVInDegrees, float& OutVFOVInDegrees) const override;

	virtual void SetInterpupillaryDistance(float NewInterpupillaryDistance) override;
	virtual float GetInterpupillaryDistance() const override;

	virtual bool IsChromaAbCorrectionEnabled() const override;

	virtual void UpdateScreenSettings(const FViewport* InViewport) override {}

	virtual bool GetHMDDistortionEnabled(EShadingPath ShadingPath) const override;

	virtual void OnBeginRendering_GameThread() override;
	virtual void OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily) override;

	virtual float GetPixelDenity() const override { return 1; }
	virtual void SetPixelDensity(const float NewDensity) override { PixelDensity = 1; }
	virtual FIntPoint GetIdealRenderTargetSize() const override { return IdealRenderTargetSize; }

	//Pico Direct Preview++++++++++++++++++++++
	/** IStereoRendering interface */
	virtual bool IsStereoEnabled() const override;
	virtual bool EnableStereo(bool stereo = true) override;
	virtual void AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const override;
	virtual void CalculateStereoViewOffset(const EStereoscopicPass StereoPassType, FRotator& ViewRotation, const float MetersToWorld, FVector& ViewLocation) override;
	FPicoXRFrustumDP LeftFrustum;
	FPicoXRFrustumDP RightFrustum;
	virtual FMatrix GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType) const override;
	virtual void RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FRHITexture2D* SrcTexture, FVector2D WindowSize) const override;
	virtual void GetEyeRenderParams_RenderThread(const FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const override;
	virtual IStereoRenderTargetManager* GetRenderTargetManager() override { return this; }

	/** FXRRenderTargetManager interface */
	virtual FXRRenderBridge* GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget) override;
	virtual bool ShouldUseSeparateRenderTarget() const override
	{
		check(IsInGameThread());
		return IsStereoEnabled();
	}
	virtual void CalculateRenderTargetSize(const class FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY) override;
	virtual bool NeedReAllocateViewportRenderTarget(const class FViewport& Viewport) override;
	//virtual bool AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
#if ENGINE_MINOR_VERSION >25
	virtual bool AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
#else
	virtual bool AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, uint32 Flags, uint32 TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
#endif
	virtual bool ShouldCopyDebugLayersToSpectatorScreen() const override { return true; }
	//Pico Direct Preview-----------------------
	// ISceneViewExtension interface
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override {};
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override {}
	virtual void PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily) override {};
	virtual void PostRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override;
	//Pico Direct Preview ！！！
#if ENGINE_MINOR_VERSION >26
	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override;
#endif
	FDP CurrentDirectPreview = NULL;
	// SpectatorScreen
	//Pico Direct Preview++++++++++++++++++++++++
private:
	void CreateSpectatorScreenController();
public:
	virtual FIntRect GetFullFlatEyeRect_RenderThread(FTexture2DRHIRef EyeTexture) const override;
	virtual void CopyTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* SrcTexture, FIntRect SrcRect, FRHITexture2D* DstTexture, FIntRect DstRect, bool bClearBlack, bool bNoAlpha) const override;
	virtual void TransferImage_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* SrcTexture, FIntRect SrcRect, FRHITexture2D* DstTexture, FIntRect DstRect, bool bLeft, bool bNoAlpha) const;
	//Pico Direct Preview-------------------
	class BridgeBaseImpl : public FXRRenderBridge
	{
	public:
		BridgeBaseImpl(FPicoDirectPreviewHMD* plugin)
			: Plugin(plugin)
			, bInitialized(false)
			, bUseExplicitTimingMode(false)
		{}

		// Render bridge virtual interface
		virtual bool Present(int& SyncInterval) override;
		virtual void PostPresent() override;
		virtual bool NeedsNativePresent() override;

		// Non-virtual public interface
		bool IsInitialized() const { return bInitialized; }

		bool IsUsingExplicitTimingMode() const
		{
			return bUseExplicitTimingMode;
		}

		FXRSwapChainPtr GetSwapChain() { return SwapChain; }
		FXRSwapChainPtr GetDepthSwapChain() { return DepthSwapChain; }

		/** Schedules BeginRendering_RHI on the RHI thread when in explicit timing mode */
		void BeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList);

		/** Called only when we're in explicit timing mode, which needs to be paired with a call to PostPresentHandoff */
		void BeginRendering_RHI();

		void CreateSwapChain(const FTextureRHIRef& BindingTexture, TArray<FTextureRHIRef>&& SwapChainTextures);

		// Virtual interface implemented by subclasses
		virtual void Reset() = 0;

	private:
		virtual void FinishRendering() = 0;

	protected:
		
		FPicoDirectPreviewHMD* Plugin;
		FXRSwapChainPtr			SwapChain;
		FXRSwapChainPtr			DepthSwapChain;

		bool					bInitialized;

		/** If we use explicit timing mode, we must have matching calls to BeginRendering_RHI and PostPresentHandoff */
		bool					bUseExplicitTimingMode;

	};

#if PLATFORM_WINDOWS
	class D3D11Bridge : public BridgeBaseImpl
	{
	public:
		D3D11Bridge(FPicoDirectPreviewHMD* plugin);
		/// <summary>
		/// Brush the RT to the runtime of steam
		virtual void FinishRendering() override;

		virtual void UpdateViewport(const FViewport& Viewport, FRHIViewport* InViewportRHI) override;
		virtual void Reset() override;
		TRefCountPtr<ID3D11Texture2D> intexture;

	};

#endif // PLATFORM_WINDOWS

public:
	/** Constructor */
	FPicoDirectPreviewHMD(const FAutoRegister&, IPicoDPPlugin*);

	/** Destructor */
	virtual ~FPicoDirectPreviewHMD();

	/** @return	True if the API was initialized OK */
	bool IsInitialized() const;

protected:

	virtual float GetWorldToMetersScale() const override;


private:

	/**
	 * Starts up the OpenVR API. Returns true if initialization was successful, false if not.
	 */
	bool Startup();

	/**
	 * Shuts down the OpenVR API
	 */
	void Shutdown();

public:
	static FORCEINLINE FMatrix ToFMatrix(const vr::HmdMatrix34_t& tm)
	{
		// Rows and columns are swapped between vr::HmdMatrix34_t and FMatrix
		return FMatrix(
			FPlane(tm.m[0][0], tm.m[1][0], tm.m[2][0], 0.0f),
			FPlane(tm.m[0][1], tm.m[1][1], tm.m[2][1], 0.0f),
			FPlane(tm.m[0][2], tm.m[1][2], tm.m[2][2], 0.0f),
			FPlane(tm.m[0][3], tm.m[1][3], tm.m[2][3], 1.0f));
	}

	static FORCEINLINE FMatrix ToFMatrix(const vr::HmdMatrix44_t& tm)
	{
		// Rows and columns are swapped between vr::HmdMatrix44_t and FMatrix
		return FMatrix(
			FPlane(tm.m[0][0], tm.m[1][0], tm.m[2][0], tm.m[3][0]),
			FPlane(tm.m[0][1], tm.m[1][1], tm.m[2][1], tm.m[3][1]),
			FPlane(tm.m[0][2], tm.m[1][2], tm.m[2][2], tm.m[3][2]),
			FPlane(tm.m[0][3], tm.m[1][3], tm.m[2][3], tm.m[3][3]));
	}

	static FORCEINLINE vr::HmdMatrix34_t ToHmdMatrix34(const FMatrix& tm)
	{
		// Rows and columns are swapped between vr::HmdMatrix34_t and FMatrix
		vr::HmdMatrix34_t out;

		out.m[0][0] = tm.M[0][0];
		out.m[1][0] = tm.M[0][1];
		out.m[2][0] = tm.M[0][2];

		out.m[0][1] = tm.M[1][0];
		out.m[1][1] = tm.M[1][1];
		out.m[2][1] = tm.M[1][2];

		out.m[0][2] = tm.M[2][0];
		out.m[1][2] = tm.M[2][1];
		out.m[2][2] = tm.M[2][2];

		out.m[0][3] = tm.M[3][0];
		out.m[1][3] = tm.M[3][1];
		out.m[2][3] = tm.M[3][2];

		return out;
	}

	static FORCEINLINE vr::HmdMatrix44_t ToHmdMatrix44(const FMatrix& tm)
	{
		// Rows and columns are swapped between vr::HmdMatrix44_t and FMatrix
		vr::HmdMatrix44_t out;

		out.m[0][0] = tm.M[0][0];
		out.m[1][0] = tm.M[0][1];
		out.m[2][0] = tm.M[0][2];
		out.m[3][0] = tm.M[0][3];

		out.m[0][1] = tm.M[1][0];
		out.m[1][1] = tm.M[1][1];
		out.m[2][1] = tm.M[1][2];
		out.m[3][1] = tm.M[1][3];

		out.m[0][2] = tm.M[2][0];
		out.m[1][2] = tm.M[2][1];
		out.m[2][2] = tm.M[2][2];
		out.m[3][2] = tm.M[2][3];

		out.m[0][3] = tm.M[3][0];
		out.m[1][3] = tm.M[3][1];
		out.m[2][3] = tm.M[3][2];
		out.m[3][3] = tm.M[3][3];

		return out;
	}


private:



	bool bHmdEnabled;
	EHMDWornState::Type HmdWornState;
	bool bStereoDesired;
	bool bStereoEnabled;
	bool bOcclusionMeshesBuilt;

	// Current world to meters scale. Should only be used when refreshing poses.
	// Everywhere else, use the current tracking frame's WorldToMetersScale.
	float GameWorldToMetersScale;

	struct FTrackingFrame
	{
		uint32 FrameNumber;

		bool bDeviceIsConnected[vr::k_unMaxTrackedDeviceCount];
		bool bPoseIsValid[vr::k_unMaxTrackedDeviceCount];
		FVector DevicePosition[vr::k_unMaxTrackedDeviceCount];
		FQuat DeviceOrientation[vr::k_unMaxTrackedDeviceCount];
		bool bHaveVisionTracking;

		/** World units (UU) to Meters scale.  Read from the level, and used to transform positional tracking data */
		float WorldToMetersScale;


		FTrackingFrame()
			: FrameNumber(0)
			, bHaveVisionTracking(false)
			, WorldToMetersScale(100.0f)
		{
			const uint32 MaxDevices = vr::k_unMaxTrackedDeviceCount;

			FMemory::Memzero(bDeviceIsConnected, MaxDevices * sizeof(bool));
			FMemory::Memzero(bPoseIsValid, MaxDevices * sizeof(bool));
			FMemory::Memzero(DevicePosition, MaxDevices * sizeof(FVector));


			for (uint32 i = 0; i < vr::k_unMaxTrackedDeviceCount; ++i)
			{
				DeviceOrientation[i] = FQuat::Identity;
			}

		}
	};


	FTrackingFrame GameTrackingFrame;
	FTrackingFrame RenderTrackingFrame;

	const FTrackingFrame& GetTrackingFrame() const;

	/** Coverts a PicoDP-space vector to an Unreal-space vector.  Does not handle scaling, only axes conversion */
	FORCEINLINE static FVector CONVERT_STEAMVECTOR_TO_FVECTOR(const vr::HmdVector3_t InVector)
	{
		return FVector(-InVector.v[2], InVector.v[0], InVector.v[1]);
	}

	FORCEINLINE static FVector RAW_STEAMVECTOR_TO_FVECTOR(const vr::HmdVector3_t InVector)
	{
		return FVector(InVector.v[0], InVector.v[1], InVector.v[2]);
	}

	FHMDViewMesh HiddenAreaMeshes[2];
	FHMDViewMesh VisibleAreaMeshes[2];



	uint32 WindowMirrorBoundsWidth;
	uint32 WindowMirrorBoundsHeight;

	FIntPoint IdealRenderTargetSize;
	float PixelDensity;

	/** How far the HMD has to move before it's considered to be worn */
	float HMDWornMovementThreshold;

	/** used to check how much the HMD has moved for changing the Worn status */
	FVector					HMDStartLocation;

	// HMD base values, specify forward orientation and zero pos offset
	FQuat					BaseOrientation;	// base orientation
	FVector					BaseOffset;

	// State for tracking quit operation
	bool					bIsQuitting;
	double					QuitTimestamp;

	/**  True if the HMD sends an event that the HMD is being interacted with */
	bool					bShouldCheckHMDPosition;

	IRendererModule* RendererModule;
	IPicoDPPlugin* PicoDPPlugin;

	FString DisplayId;

	FQuat PlayerOrientation;
	FVector PlayerLocation;

	TRefCountPtr<BridgeBaseImpl> pBridge;
};

#endif //STEAMVR_SUPPORTED_PLATFORMS
