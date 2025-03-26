// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_HMDRenderBridge.h"
#include "PXR_HMD.h"
#include "PXR_Log.h"
#include "XRThreadUtils.h"

#include "Runtime/RenderCore/Public/Shader.h"
#include "Runtime/RenderCore/Public/RendererInterface.h"
#include "ScreenRendering.h"
#include "PipelineStateCache.h"
#include "ClearQuad.h"
#include "CommonRenderResources.h"
#include "HardwareInfo.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "PXR_Shaders.h"

FPICOXRRenderBridge::FPICOXRRenderBridge(FPICOXRHMD* HMD) : FXRRenderBridge(),PICOXRHMD(HMD)
{
    // grab a pointer to the renderer module for displaying our mirror window
    static const FName RendererModuleName("Renderer");
    RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
}

bool FPICOXRRenderBridge::NeedsNativePresent()
{
	return false;
}

bool FPICOXRRenderBridge::Present(int32& InOutSyncInterval)
{
	PICOXRHMD->OnRHIFrameEnd_RHIThread();
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
		FPICOXRHMDModule::GetPluginWrapper().GetConfigInt(PXR_RENDER_FPS, &fps);
		PXR_LOGI(PxrUnreal, " Current FPS : %d ", fps);
#endif
		BeginTime = NewTime;
		FrameCount = 0;
	}
#endif
	InOutSyncInterval = 0; // VSync off
	return false;
}

FXRSwapChainPtr FPICOXRRenderBridge::CreateSwapChain_RenderThread(uint32 ID, uint32 LayerID, ERHIResourceType RHIResourceType, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue)
{
	check(IsInRenderingThread());
	PXR_LOGI(PxrUnreal, "CreateSwapChain_%s ID:%d, LayerID:%u, Format:%d,SizeX:%d,SizeY:%d,ArraySize:%d,NumMips:%d,NumSamples:%d,Flags:%d,TargetableTextureFlags:%d,MSAAValue:%d", PLATFORM_CHAR(*RHIString), ID, LayerID, Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, MSAAValue);
	FTextureRHIRef RHITexture;
	TArray<FTextureRHIRef> RHITextureSwapChain;
	{
		for (int32 TextureIndex = 0; TextureIndex < NativeTextures.Num(); ++TextureIndex)
		{
			FTextureRHIRef TexRef = CreateTexture_RenderThread(RHIResourceType, NativeTextures[TextureIndex], Format, SizeX, SizeY, NumMips, NumSamples, TargetableTextureFlags, MSAAValue);
			RHITextureSwapChain.Add(TexRef);
		}
	}
	RHITexture = GDynamicRHI->RHICreateAliasedTexture(RHITextureSwapChain[0]);

	return CreateXRSwapChain(MoveTemp(RHITextureSwapChain), RHITexture);
}

int FPICOXRRenderBridge::GetSystemRecommendedMSAA() const
{
	int msaa = 1;
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().GetConfigInt(PXR_MSAA_LEVEL_RECOMMENDED, &msaa);
#endif
	return msaa;
}

void FPICOXRRenderBridge::TransferImage_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture* DstTexture, FRHITexture* SrcTexture, FIntRect DstRect, FIntRect SrcRect,
	bool bAlphaPremultiply, bool bNoAlphaWrite, bool bNeedGreenClear, bool bInvertY, bool sRGBSource, bool bInvertAlpha) const
{
    check(IsInRenderingThread());

	FRHITexture2D* DstTexture2D = DstTexture->GetTexture2D();
	FRHITextureCube* DstTextureCube = DstTexture->GetTextureCube();
	FRHITexture2D* SrcTexture2D = SrcTexture->GetTexture2DArray() ? SrcTexture->GetTexture2DArray() : SrcTexture->GetTexture2D();
	FRHITextureCube* SrcTextureCube = SrcTexture->GetTextureCube();

	FIntPoint DstSize;
	FIntPoint SrcSize;

	if (DstTexture2D && SrcTexture2D)
	{
		DstSize = FIntPoint(DstTexture2D->GetSizeX(), DstTexture2D->GetSizeY());
		SrcSize = FIntPoint(SrcTexture2D->GetSizeX(), SrcTexture2D->GetSizeY());
	}
	else if (DstTextureCube && SrcTextureCube)
	{
		DstSize = FIntPoint(DstTextureCube->GetSize(), DstTextureCube->GetSize());
		SrcSize = FIntPoint(SrcTextureCube->GetSize(), SrcTextureCube->GetSize());
	}
	else
	{
		return;
	}

	if (DstRect.IsEmpty())
	{
		DstRect = FIntRect(FIntPoint::ZeroValue, DstSize);
	}

	if (SrcRect.IsEmpty())
	{
		SrcRect = FIntRect(FIntPoint::ZeroValue, SrcSize);
	}

	const uint32 ViewportWidth = DstRect.Width();
	const uint32 ViewportHeight = DstRect.Height();
	const FIntPoint TargetSize(ViewportWidth, ViewportHeight);
	float U = SrcRect.Min.X / (float)SrcSize.X;
	float V = SrcRect.Min.Y / (float)SrcSize.Y;
	float USize = SrcRect.Width() / (float)SrcSize.X;
	float VSize = SrcRect.Height() / (float)SrcSize.Y;

#if PLATFORM_ANDROID
	if (bInvertY)
	{
		V = 1.0f - V;
		VSize = -VSize;
	}
#endif

	FRHITexture* SrcTextureRHI = SrcTexture;
	RHICmdList.Transition(FRHITransitionInfo(DstTexture, ERHIAccess::Unknown, ERHIAccess::RTV));
    FGraphicsPipelineStateInitializer GraphicsPSOInit;

	if (bNeedGreenClear)
	{
		GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_InverseSourceAlpha, BF_SourceAlpha, BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
	}
	else if (bInvertAlpha)
	{
		GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_Zero, BF_InverseSourceAlpha >::GetRHI();
	}
	else if (bAlphaPremultiply)
	{
		if (bNoAlphaWrite)
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
		}
		else
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_SourceAlpha, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
		}
	}
	else
	{
		if (bNoAlphaWrite)
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB>::GetRHI();
		}
		else
		{
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
		}
	}

	GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
	GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

	const auto FeatureLevel = GMaxRHIFeatureLevel;
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
	TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
    GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	
	if (DstTexture2D)
	{
		sRGBSource &= ( (static_cast<int32>(SrcTexture->GetFlags()) & static_cast<int32>(TexCreate_SRGB) ) != 0);
		uint32 NumMips = SrcTexture->GetNumMips();
		for (uint32 MipIndex = 0; MipIndex < NumMips; MipIndex++)
		{
			FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::Load_Store);
			RPInfo.ColorRenderTargets[0].MipIndex = MipIndex;

			RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyTexture"));
			{
				const uint32 MipViewportWidth = ViewportWidth >> MipIndex;
				const uint32 MipViewportHeight = ViewportHeight >> MipIndex;
				const FIntPoint MipTargetSize(MipViewportWidth, MipViewportHeight);

				if (bNoAlphaWrite || bInvertAlpha || bNeedGreenClear)
				{
					RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);
					DrawClearQuad(RHICmdList, bNeedGreenClear ? FLinearColor::Green : (bAlphaPremultiply ? FLinearColor::Black : FLinearColor::White));
				}

				RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				FRHISamplerState* SamplerState = DstRect.Size() == SrcRect.Size() ? TStaticSamplerState<SF_Point>::GetRHI() : TStaticSamplerState<SF_Bilinear>::GetRHI();

				if (!sRGBSource)
				{
					TShaderMapRef<FScreenPSMipLevel> PixelShader(ShaderMap);
					GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
					SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
					FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
					PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, MipIndex);
					RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
				}
				else
				{
					TShaderMapRef<FScreenPSsRGBSourceMipLevel> PixelShader(ShaderMap);
					GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
					SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
					FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
					PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, MipIndex);
					RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
				}
				
				RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Min.X + MipViewportWidth, DstRect.Min.Y + MipViewportHeight, 1.0f);

				RendererModule->DrawRectangle(
					RHICmdList,
					0, 0, MipViewportWidth, MipViewportHeight,
					U, V, USize, VSize,
					MipTargetSize,
					FIntPoint(1, 1),
					VertexShader,
					EDRF_Default);
			}
			RHICmdList.EndRenderPass();
		}
	}
	else
	{
		for (int FaceIndex = 0; FaceIndex < 6; FaceIndex++)
		{
			FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::Load_Store);
			
			RPInfo.ColorRenderTargets[0].ArraySlice = FaceIndex;

			RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyTextureFace"));
			{
				if (bNoAlphaWrite)
				{
					DrawClearQuad(RHICmdList, bAlphaPremultiply ? FLinearColor::Black : FLinearColor::White);
				}

				RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);

				TShaderMapRef<FPICOCubemapPS> PixelShader(ShaderMap);
				GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

				SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit,0);
				FRHISamplerState* SamplerState = DstRect.Size() == SrcRect.Size() ? TStaticSamplerState<SF_Point>::GetRHI() : TStaticSamplerState<SF_Bilinear>::GetRHI();
				PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, FaceIndex);

				RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);

				RendererModule->DrawRectangle(
					RHICmdList,
					0, 0, ViewportWidth, ViewportHeight,
					U, V, USize, VSize,
					TargetSize,
					FIntPoint(1, 1),
					VertexShader,
					EDRF_Default);
			}
			RHICmdList.EndRenderPass();
		}
	}
	RHICmdList.Transition(FRHITransitionInfo(DstTexture, ERHIAccess::RTV, ERHIAccess::SRVMask));
}

void FPICOXRRenderBridge::SubmitGPUCommands_RenderThread(FRHICommandListImmediate& RHICmdList)
{
	check(IsInRenderingThread());
	RHICmdList.SubmitCommandsHint();
}

void FPICOXRRenderBridge::ReleaseResources_RHIThread()
{
	CheckInRHIThread();
}

void FPICOXRRenderBridge::Shutdown()
{
	CheckInGameThread();

	ExecuteOnRenderThread([this]()
		{
			ExecuteOnRHIThread([this]()
				{
					PICOXRHMD = nullptr;
				});
		});
}
