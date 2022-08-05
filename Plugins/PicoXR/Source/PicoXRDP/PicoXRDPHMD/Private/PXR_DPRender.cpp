//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#include "CoreMinimal.h"
#include "PXR_DPPrivate.h"
#include "XRThreadUtils.h"
#if STEAMVR_SUPPORTED_PLATFORMS

#include "PXR_DPHMD.h"

#include "RendererPrivate.h"
#include "ScenePrivate.h"
#include "PostProcess/PostProcessHMD.h"
#include "PipelineStateCache.h"
#include "ClearQuad.h"
#include "DefaultSpectatorScreenController.h"
#include "ScreenRendering.h"
#include "PXR_Log.h"


#if PLATFORM_WINDOWS
#include "DynamicRHI.h"
#include "D3D11RHI.h"
#include "D3D11RHIPrivate.h"
#include "D3D11RHIBasePrivate.h"
#include "D3D11StateCachePrivate.h"
#include "D3D11Util.h"
#include "D3D11State.h"
#include "D3D11Resources.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <d3d11.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

static TAutoConsoleVariable<int> CVarEnableDepthSubmission(
	TEXT("vr.EnablePicoDPDepthSubmission"),
	0,
	TEXT("By default, depth is not passed through in PicoDP for devices that support depth. Set this flag to 1 to enable depth submission, 0 to disable."),
	ECVF_Default);

void FPicoDirectPreviewHMD::RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FRHITexture2D* SrcTexture, FVector2D WindowSize) const
{
	check(IsInRenderingThread());

	if (bSplashIsShown || !IsBackgroundLayerVisible())
	{
		FRHIRenderPassInfo RPInfo(SrcTexture, ERenderTargetActions::DontLoad_Store);
		RHICmdList.BeginRenderPass(RPInfo, TEXT("Clear"));
		{
			DrawClearQuad(RHICmdList, FLinearColor(0, 0, 0, 0));
		}
		RHICmdList.EndRenderPass();
	}

	check(SpectatorScreenController);
	SpectatorScreenController->RenderSpectatorScreen_RenderThread(RHICmdList, BackBuffer, SrcTexture, WindowSize);
}

void FPicoDirectPreviewHMD::PostRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
{
}
#if ENGINE_MINOR_VERSION >26
bool FPicoDirectPreviewHMD::IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const
{
	return GEngine && GEngine->IsStereoscopic3D(Context.Viewport);
}
#endif


void FPicoDirectPreviewHMD::BridgeBaseImpl::BeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList)
{}

void FPicoDirectPreviewHMD::BridgeBaseImpl::BeginRendering_RHI()
{
	check(!IsRunningRHIInSeparateThread() || IsInRHIThread());
}

void FPicoDirectPreviewHMD::BridgeBaseImpl::CreateSwapChain(const FTextureRHIRef& BindingTexture, TArray<FTextureRHIRef>&& SwapChainTextures)
{
	PXR_LOGD(PxrUnreal,"PXR_DP CreateSwapChain!");
	check(IsInRenderingThread());
	check(SwapChainTextures.Num());
	SwapChain = CreateXRSwapChain(MoveTemp(SwapChainTextures), BindingTexture);
}

bool FPicoDirectPreviewHMD::BridgeBaseImpl::Present(int& SyncInterval)
{
	//This  must return true。
	check(IsRunningRHIInSeparateThread() ? IsInRHIThread() : IsInRenderingThread());

	//necessary, brush the RT to steam
	FinishRendering();

	// Increment swap chain index post-swap.
	SwapChain->IncrementSwapChainIndex_RHIThread();

	SyncInterval = 0;

	return true;
}

bool FPicoDirectPreviewHMD::BridgeBaseImpl::NeedsNativePresent()
{
	//This return value does not affect the PC display
	return true;
}

void FPicoDirectPreviewHMD::BridgeBaseImpl::PostPresent()
{}

#if PLATFORM_WINDOWS
FPicoDirectPreviewHMD::D3D11Bridge::D3D11Bridge(FPicoDirectPreviewHMD* plugin)
	: BridgeBaseImpl(plugin)
{}

//necessary, brush the RT to steam
void FPicoDirectPreviewHMD::D3D11Bridge::FinishRendering()
{	
	FTexture2DRHIRef Texture2DRHI= SwapChain->GetTextureRef()->GetTexture2D();
	if (Texture2DRHI)
	{
		void* NativeResource = Texture2DRHI->GetNativeResource();
		ID3D11Texture2D* D3D11Texture2D = static_cast<ID3D11Texture2D*>(NativeResource);
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid())
			{
				FPicoDirectPreviewHMD* HMD = static_cast<FPicoDirectPreviewHMD*>(GEngine->XRSystem.Get());
				ID3D11Device* D3D11Device = static_cast<ID3D11Device*>(GDynamicRHI->RHIGetNativeDevice());
				ID3D11DeviceContext* D3D11DeviceContext = nullptr;

				D3D11Device->GetImmediateContext(&D3D11DeviceContext);
				if (D3D11DeviceContext)
				{
					if (HMD->CurrentDirectPreview)
					{
						HMD->CurrentDirectPreview->SendMessage();
					}
				}
			}
		}
	}
}


void FPicoDirectPreviewHMD::D3D11Bridge::Reset()
{}

void FPicoDirectPreviewHMD::D3D11Bridge::UpdateViewport(const FViewport& Viewport, FRHIViewport* InViewportRHI)
{}

#endif // PLATFORM_WINDOWS

#endif // STEAMVR_SUPPORTED_PLATFORMS
