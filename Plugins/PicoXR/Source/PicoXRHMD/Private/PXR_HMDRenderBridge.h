//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "XRRenderBridge.h"
#include "XRSwapChain.h"
#include "RHI.h"
#include "RendererInterface.h"
#include "IStereoLayers.h"
#include "XRRenderBridge.h"

class FPICOXRHMD;
class FPICOXRRenderBridge : public FXRRenderBridge
{
public:
    FPICOXRRenderBridge(FPICOXRHMD* HMD);
    /** FRHICustomPresent */
    virtual bool NeedsNativePresent() override;
    virtual bool Present(int32& InOutSyncInterval)override;
#if ENGINE_MINOR_VERSION >25
	FXRSwapChainPtr CreateSwapChain_RenderThread(uint32 LayerID, ERHIResourceType ResourceType, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue);
#else
	FXRSwapChainPtr CreateSwapChain_RenderThread(uint32 LayerID, ERHIResourceType ResourceType, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, uint32 MSAAValue);
#endif

#if ENGINE_MINOR_VERSION>25
	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType ResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue) = 0;
#else
	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType ResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, uint32 TargetableTextureFlags, uint32 MASSValue) = 0;
#endif
	virtual void GetGraphics() {}
	virtual int GetSystemRecommendedMSAA() const;
	void TransferImage_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture* DstTexture, FRHITexture* SrcTexture, FIntRect DstRect = FIntRect(), FIntRect SrcRect = FIntRect(), bool bAlphaPremultiply = false, bool bNoAlphaWrite = false, bool bNeedGreenClear = false, bool bInvertY = false, bool sRGBSource = false, bool bInvertAlpha = false) const;
	void SubmitGPUCommands_RenderThread(FRHICommandListImmediate& RHICmdList);

    FPICOXRHMD* PICOXRHMD;
    FXRSwapChainPtr SwapChain;
    FString RHIString;
    IRendererModule* RendererModule;
};
FPICOXRRenderBridge* CreateRenderBridge_OpenGL(FPICOXRHMD* HMD);
FPICOXRRenderBridge* CreateRenderBridge_Vulkan(FPICOXRHMD* HMD);

