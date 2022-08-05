//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDRenderBridge.h"
#include "PXR_HMD.h"
#include "PXR_HMDSwapChain.h"
#include "PXR_Log.h"

#include "Runtime/RenderCore/Public/Shader.h"
#include "Runtime/RenderCore/Public/RendererInterface.h"
#include "ScreenRendering.h"
#include "PipelineStateCache.h"
#include "ClearQuad.h"
#include "CommonRenderResources.h"
#include "HardwareInfo.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "PXR_Shaders.h"
#if PLATFORM_ANDROID
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#endif

FPicoXRRenderBridge::FPicoXRRenderBridge(FPicoXRHMD* HMD) : FXRRenderBridge(),PicoXRHMD(HMD)
{
    // grab a pointer to the renderer module for displaying our mirror window
    static const FName RendererModuleName("Renderer");
    RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
}

bool FPicoXRRenderBridge::NeedsNativePresent()
{
	return false;
}

bool FPicoXRRenderBridge::Present(int32& InOutSyncInterval)
{
	PicoXRHMD->OnRHIFrameEnd_RHIThread();
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	// frame rate log
	static int32 FrameCount = 0;
	static double BeginTime = 0.0f;
	if (FrameCount == 0)
	{
		BeginTime = FPlatformTime::Seconds();
	}
	FrameCount++;
	double NewTime = FPlatformTime::Seconds();
	double DeltaTime = NewTime - BeginTime;
	if (DeltaTime > 1.0f)
	{
#if PLATFORM_ANDROID
		int32 fps;
		Pxr_GetConfigInt(PXR_RENDER_FPS, &fps);
		PXR_LOGI(PxrUnreal, " Current FPS : %d ", fps);
#endif
		BeginTime = NewTime;
		FrameCount = 0;
	}
#endif
	InOutSyncInterval = 0; // VSync off
	return false;
}

void FPicoXRRenderBridge::GetVulkanGraphics()
{
#if PLATFORM_ANDROID
    PXR_LOGI(PxrUnreal, "GetVulkanGraphics");
    FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);
    FVulkanDevice* Device = DynamicRHI->GetDevice();
    FVulkanQueue* Queue = Device->GetGraphicsQueue();

    PxrVulkanBinding vulkanBinding = {};
    vulkanBinding.instance = DynamicRHI->GetInstance();
    vulkanBinding.physicalDevice = Device->GetPhysicalHandle();
    vulkanBinding.device = Device->GetInstanceHandle();
    vulkanBinding.queueFamilyIndex = Queue->GetFamilyIndex();
    vulkanBinding.queueIndex = 0;

    Pxr_CreateVulkanSystem(&vulkanBinding);
#endif
}

int FPicoXRRenderBridge::GetSystemRecommendedMSAA() const
{
	int msaa = 1;
#if PLATFORM_ANDROID
	Pxr_GetConfigInt(PXR_MSAA_LEVEL_RECOMMENDED, &msaa);
#endif
	return msaa;
}

void FPicoXRRenderBridge::TransferImage_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture* DstTexture, FRHITexture* SrcTexture, FIntRect DstRect, FIntRect SrcRect, bool bPremultiply, bool bNoAlpha,bool bIsMRCLayer, bool bReverse, bool sRGBSource) const
{
    check(IsInRenderingThread());

    FIntPoint SrcSize;
    FIntPoint DstSize;
    if (SrcTexture->GetTexture2D() && DstTexture->GetTexture2D()) {
        SrcSize = FIntPoint(SrcTexture->GetTexture2D()->GetSizeX(), SrcTexture->GetTexture2D()->GetSizeY());
        DstSize = FIntPoint(DstTexture->GetTexture2D()->GetSizeX(), DstTexture->GetTexture2D()->GetSizeY());
    } else {
        PXR_LOGD(PxrUnreal, "TransferImage Texture Is None");
        return;
    }

    if (SrcRect.IsEmpty()) {
        SrcRect = FIntRect(FIntPoint::ZeroValue, SrcSize);
    }

    if (DstRect.IsEmpty()) {
        DstRect = FIntRect(FIntPoint::ZeroValue, DstSize);
    }

    const uint32 viewportWidth = DstRect.Width();
    const uint32 viewportHeight = DstRect.Height();
    float U = SrcRect.Min.X / (float) SrcSize.X;
    float V = SrcRect.Min.Y / (float) SrcSize.Y;
    float USize = SrcRect.Width() / (float) SrcSize.X;
    float VSize = SrcRect.Height() / (float) SrcSize.Y;

    FRHITexture* SrcTextureRHI = SrcTexture;
#if ENGINE_MINOR_VERSION > 25
    RHICmdList.Transition(FRHITransitionInfo(SrcTextureRHI, ERHIAccess::Unknown, ERHIAccess::SRVGraphics));
#else
    RHICmdList.TransitionResources(EResourceTransitionAccess::EReadable, &SrcTextureRHI, 1);
#endif
    FGraphicsPipelineStateInitializer GraphicsPSOInit;

    if (bNoAlpha) {
        GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
    } else {
        GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_SourceAlpha, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
    }

    GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
    GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
    GraphicsPSOInit.PrimitiveType = PT_TriangleList;

    const auto FeatureLevel = GMaxRHIFeatureLevel;
    auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
    TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
    GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
#if ENGINE_MINOR_VERSION > 24
    GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
#else
    GraphicsPSOInit.BoundShaderState.VertexShaderRHI = GETSAFERHISHADER_VERTEX(*VertexShader);
#endif

    if (DstTexture->GetTexture2D())
    {
        sRGBSource &= ( ( SrcTexture->GetFlags() & TexCreate_SRGB ) != 0);
        uint32 NumMips = SrcTexture->GetNumMips();

        for (uint32 MipIndex = 0; MipIndex < NumMips; MipIndex++)
        {
            FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::Load_Store);
            RPInfo.ColorRenderTargets[0].MipIndex = MipIndex;

            RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyTexture"));
            {
                const uint32 ViewportWidth = viewportWidth >> MipIndex;
                const uint32 ViewportHeight = viewportHeight >> MipIndex;
                const FIntPoint TargetSize(viewportWidth, viewportHeight);

                if (bNoAlpha)
                {
                    RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);
                    DrawClearQuad(RHICmdList, FLinearColor::Black);
                }

                RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
                FRHISamplerState* SamplerState = DstRect.Size() == SrcRect.Size() ? TStaticSamplerState<SF_Point>::GetRHI() : TStaticSamplerState<SF_Bilinear>::GetRHI();
#if ENGINE_MINOR_VERSION > 24
                if (!sRGBSource)
                {
                    if (bIsMRCLayer)
                    {
						TShaderMapRef<FMRCPSMipLevel> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
                    }
                    else
					{
                        TShaderMapRef<FScreenPSMipLevel> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
                    }

                } else {
                    if (bIsMRCLayer)
					{
						TShaderMapRef<FMRCPSsRGBSourceMipLevel> PixelShader(ShaderMap);             
                        GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
                    }
                    else
					{
                        TShaderMapRef<FScreenPSsRGBSourceMipLevel> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
                    }
                }

                RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Min.X + ViewportWidth, DstRect.Min.Y + ViewportHeight, 1.0f);
#else
                if (!sRGBSource)
                {
                    if (bIsMRCLayer)
                    {
						TShaderMapRef<FMRCPS> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI);
                    }
                    else
                    {
						TShaderMapRef<FScreenPS> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI);
                    }
                } else {
                    if (bIsMRCLayer)
                    {
						TShaderMapRef<FMRCPSsRGBSource> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI);
                    }
                    else
                    {
						TShaderMapRef<FScreenPSsRGBSource> PixelShader(ShaderMap);
						GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
						SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
						PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI);
                    }
                }

                RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);
#endif

                RendererModule->DrawRectangle(
                    RHICmdList,
                    0, 0, ViewportWidth, ViewportHeight,
                    U, V, USize, VSize,
                    TargetSize,
                    FIntPoint(1, 1),
#if ENGINE_MINOR_VERSION > 24
                    VertexShader,
#else
                    *VertexShader,
#endif
                    EDRF_Default);
            }
            RHICmdList.EndRenderPass();
        }
    }
}

class FPicoXRRenderBridge_OpenGL : public FPicoXRRenderBridge
{
public:
	FPicoXRRenderBridge_OpenGL(FPicoXRHMD* HMD)
		:FPicoXRRenderBridge(HMD)
	{
        const FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
        const FString RHILookup = NAME_RHI.ToString() + TEXT("=");
        FParse::Value(*HardwareDetails, *RHILookup, RHIString);
	}
#if ENGINE_MINOR_VERSION > 25
	virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue) override
#else
	virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, uint32 MSAAValue) override
#endif
	{
		return CreateSwapChain_OpenGL(Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, PicoXRHMD, MSAAValue);
	}
};

FPicoXRRenderBridge* CreateRenderBridge_OpenGL(FPicoXRHMD* HMD) { return new FPicoXRRenderBridge_OpenGL(HMD); }

class FPicoXRRenderBridge_Vulkan : public FPicoXRRenderBridge
{
public:
	FPicoXRRenderBridge_Vulkan(FPicoXRHMD* HMD)
		:FPicoXRRenderBridge(HMD)
	{
        PXR_LOGI(PxrUnreal,"FPicoXRRenderBridge_Vulkan GRHISupportsRHIThread = %d, GIsThreadedRendering = %d, GUseRHIThread_InternalUseOnly = %d", GRHISupportsRHIThread, GIsThreadedRendering, GUseRHIThread_InternalUseOnly);
        const FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
        const FString RHILookup = NAME_RHI.ToString() + TEXT("=");
        FParse::Value(*HardwareDetails, *RHILookup, RHIString);

#if PLATFORM_ANDROID
		if (GRHISupportsRHIThread && GIsThreadedRendering && GUseRHIThread_InternalUseOnly)
		{
			//TODO:SetRHIThreadEnabled
			//PXR_LOGI(PxrUnreal,"SetRHIThreadEnabled(false, false)");
			//SetRHIThreadEnabled(false, false);
		}

		if (IsRunningRHIInSeparateThread()) {
			if (IsRunningRHIInDedicatedThread()) {
				PXR_LOGI(PxrUnreal,"RHIThread is now running on a dedicated thread.");
			} else {
				check(IsRunningRHIInTaskThread());
				PXR_LOGI(PxrUnreal, "RHIThread is now running on task threads.");
			}
		} else {
			check(!IsRunningRHIInTaskThread() && !IsRunningRHIInDedicatedThread());
			PXR_LOGI(PxrUnreal, "RHIThread is disabled.");
		}
#endif
	}

#if ENGINE_MINOR_VERSION > 25
	virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue) override
#else
    virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, uint32 MSAAValue) override
#endif
	{
        return CreateSwapChain_Vulkan(Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, PicoXRHMD, MSAAValue);
    }
};

FPicoXRRenderBridge* CreateRenderBridge_Vulkan(FPicoXRHMD* HMD) { return new FPicoXRRenderBridge_Vulkan(HMD); }
