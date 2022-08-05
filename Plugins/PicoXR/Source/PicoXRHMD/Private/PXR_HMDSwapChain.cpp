//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDSwapChain.h"
#include "OpenGLDrv.h"
#include "PXR_Log.h"
#include "PXR_HMD.h"

#if PLATFORM_ANDROID
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#endif

uint64_t LayerImages[2][3];

FPicoXRSwapChain::FPicoXRSwapChain(TArray<FTextureRHIRef>&& InRHITextureSwapChain, const FTextureRHIRef & InRHITexture,FPicoXRHMD* InXRHMD) :
	FXRSwapChain(MoveTemp(InRHITextureSwapChain), InRHITexture),
	PicoXRHMD(InXRHMD)
{
}

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_OpenGL(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPicoXRHMD* InXRHMD, uint32 MSAAValue)
#else
FXRSwapChainPtr CreateSwapChain_OpenGL(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPicoXRHMD* InXRHMD, uint32 MSAAValue)
#endif
{
	PXR_LOGI(PxrUnreal, "CreateSwapChain_OpenGL Format:%d,SizeX:%d,SizeY:%d,ArraySize:%d,NumMips:%d,NumSamples:%d,Flags:%d,TargetableTextureFlags:%d,MSAAValue:%d", Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, MSAAValue);
#if PLATFORM_ANDROID
    PxrLayerParam layerParam = {};
    layerParam.layerShape = PXR_LAYER_PROJECTION;
    layerParam.layerLayout = PXR_LAYER_LAYOUT_DOUBLE_WIDE;
    layerParam.width = SizeX;
    layerParam.height = SizeY;
    layerParam.faceCount = 1;
    layerParam.mipmapCount = NumMips;
    layerParam.sampleCount = NumSamples;
    layerParam.arraySize = ArraySize;
    layerParam.format = IsMobileColorsRGB() ? GL_SRGB8_ALPHA8 : GL_RGBA8;
    if (ArraySize == 2) {
        layerParam.layerLayout = PXR_LAYER_LAYOUT_ARRAY;
        Pxr_EnableMultiview(true);
    }

    if (Pxr_IsInitialized()) {
        Pxr_CreateLayer(&layerParam);
    } else {
        PXR_LOGE(PxrUnreal, "Pxr_IsInitialized return false");
    }

    uint32_t imageCounts = 0;
    Pxr_GetLayerImageCount(0, PXR_EYE_LEFT, &imageCounts);
    for (int j = 0; j < imageCounts; j++)
    {
        Pxr_GetLayerImage(0, PXR_EYE_LEFT, j, &LayerImages[0][j]);
        PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage LayerImages[0][%d]=u_%u", j, (uint32_t)LayerImages[0][j]);
    }

    TArray<uint32> TextureResources;
    for (int i = 0; i < imageCounts; i++) {
        TextureResources.Add((uint32)LayerImages[0][i]);
    }

	TArray<FTextureRHIRef> TextureChains;
	FOpenGLDynamicRHI* DynamicRHI = static_cast<FOpenGLDynamicRHI*>(GDynamicRHI);
	FTextureRHIRef ChainTarget = nullptr;

	if (ArraySize == 1) {
		ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, SizeX, SizeY, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black , TextureResources[0], TargetableTextureFlags));
		for (const auto& TextureResource : TextureResources)
		{
			TextureChains.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, SizeX, SizeY, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, TextureResource, TargetableTextureFlags)));
		}
	} else if (ArraySize == 2) {
		ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, SizeX, SizeY, ArraySize,NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, TextureResources[0], TargetableTextureFlags));
		for (const auto& TextureResource : TextureResources)
		{
			TextureChains.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, SizeX, SizeY, ArraySize, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, TextureResource, TargetableTextureFlags)));
		}
	}

	return CreateXRSwapChain<FPicoXRSwapChain>(MoveTemp(TextureChains), ChainTarget, InXRHMD);
#endif
	return FXRSwapChainPtr();
}

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_Vulkan(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags,FPicoXRHMD* InXRHMD, uint32 MSAAValue)
#else
FXRSwapChainPtr CreateSwapChain_Vulkan(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPicoXRHMD* InXRHMD, uint32 MSAAValue)
#endif
{
	PXR_LOGI(PxrUnreal,"CreateSwapChain_Vulkan Format:%d,SizeX:%d,SizeY:%d,ArraySize:%d,NumMips:%d,NumSamples:%d,Flags:%d,TargetableTextureFlags:%d,MSAAValue:%d", Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags,MSAAValue);
#if PLATFORM_ANDROID

    PxrLayerParam layerParam = {};
    layerParam.layerShape = PXR_LAYER_PROJECTION;
    layerParam.layerLayout = PXR_LAYER_LAYOUT_DOUBLE_WIDE;
    layerParam.width = SizeX;
    layerParam.height = SizeY;
    layerParam.faceCount = 1;
    layerParam.mipmapCount = NumMips;
    layerParam.sampleCount = NumSamples;
    layerParam.arraySize = ArraySize;
    layerParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
    if (ArraySize == 2) {
        layerParam.layerLayout = PXR_LAYER_LAYOUT_ARRAY;
        Pxr_EnableMultiview(true);
    }

    if (Pxr_IsInitialized()) {
        Pxr_CreateLayer(&layerParam);
    } else {
        PXR_LOGE(PxrUnreal,"Pxr_IsInitialized return false");
    }

    uint32_t imageCounts = 0;
    Pxr_GetLayerImageCount(0, PXR_EYE_LEFT, &imageCounts);
    for (int j = 0; j < imageCounts; j++)
    {
        Pxr_GetLayerImage(0, PXR_EYE_LEFT, j, &LayerImages[0][j]);
    }

    TArray<VkImage> TextureResources;
    for (int i = 0; i < imageCounts; i++) {
        PXR_LOGI(PxrUnreal, "TextureArray[d%d] = %p", i, LayerImages[0][i]);
        TextureResources.Add((VkImage)LayerImages[0][i]);
    }

    TArray<FTextureRHIRef> TextureChain;
    FTextureRHIRef ChainTarget;
    FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);

    if (IsMobileColorsRGB())
    {
        TargetableTextureFlags |= TexCreate_SRGB;
    }

    if (ArraySize == 1) {
        for (const auto& TexutreResource : TextureResources) {
            TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, SizeX, SizeY, NumMips, NumSamples, TexutreResource, TargetableTextureFlags)));
            PXR_LOGI(PxrUnreal,"TextureChain.size = %d", TextureChain.Num());
        }

        if (ENGINE_MINOR_VERSION < 25) {
            ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, SizeX, SizeY, NumMips, NumSamples, TextureResources[0], TargetableTextureFlags));
        } else {
            ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
        }
    } else if (ArraySize == 2) {
        for (const auto& TexutreResource : TextureResources) {
            TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, SizeX, SizeY, ArraySize, NumMips, NumSamples, TexutreResource, TargetableTextureFlags)));
            PXR_LOGI(PxrUnreal, "MultiView TextureChain.size = %d", TextureChain.Num());
        }

        if (ENGINE_MINOR_VERSION < 25) {
            ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, SizeX, SizeY, ArraySize, NumMips, NumSamples, TextureResources[0], TargetableTextureFlags));
        } else {
            ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
        }
    }

    return CreateXRSwapChain<FPicoXRSwapChain>(MoveTemp(TextureChain), ChainTarget, InXRHMD);
#endif
	return FXRSwapChainPtr();
}
