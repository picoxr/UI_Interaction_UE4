//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "XRRenderBridge.h"
#include "XRSwapChain.h"
#include "RHI.h"
#include "RendererInterface.h"
#include "IStereoLayers.h"
#include "XRRenderBridge.h"

class FPicoXRHMD;
class FPicoXRRenderBridge : public FXRRenderBridge
{
public:
    FPicoXRRenderBridge(FPicoXRHMD* HMD);
    /** FRHICustomPresent */
    virtual bool NeedsNativePresent() override;
    virtual bool Present(int32& InOutSyncInterval)override;
#if ENGINE_MINOR_VERSION >25
    virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags,uint32 MSAAValue) = 0;
#else
    virtual FXRSwapChainPtr CreateSwapChain(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags,uint32 MSAAValue) = 0;
#endif
    virtual void GetVulkanGraphics();
    virtual int GetSystemRecommendedMSAA() const;
    void TransferImage_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture* DstTexture, FRHITexture* SrcTexture, FIntRect DstRect=FIntRect(), FIntRect SrcRect = FIntRect(), bool bPremultiply=false, bool bNoAlpha=false, bool bIsMRCLayer = false, bool bReverse=false, bool sRGBSource=false) const;

    FPicoXRHMD* PicoXRHMD;
    FXRSwapChainPtr SwapChain;
    FString RHIString;
    IRendererModule* RendererModule;
};
FPicoXRRenderBridge* CreateRenderBridge_OpenGL(FPicoXRHMD* HMD);
FPicoXRRenderBridge* CreateRenderBridge_Vulkan(FPicoXRHMD* HMD);

