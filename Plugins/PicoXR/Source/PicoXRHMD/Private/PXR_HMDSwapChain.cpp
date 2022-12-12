//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDSwapChain.h"
#include "OpenGLDrv.h"
#include "PXR_Log.h"
#include "PXR_HMD.h"

#if PLATFORM_ANDROID
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#include "VulkanPendingState.h"
#include "VulkanContext.h"
#endif

FPICOXRSwapChain::FPICOXRSwapChain(TArray<FTextureRHIRef>&& InRHITextureSwapChain, const FTextureRHIRef & InRHITexture,FPICOXRHMD* InXRHMD) :
	FXRSwapChain(MoveTemp(InRHITextureSwapChain), InRHITexture),
	PICOXRHMD(InXRHMD)
{
}

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_OpenGL(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPICOXRHMD* InXRHMD, uint32 MSAAValue)
#else
FXRSwapChainPtr CreateSwapChain_OpenGL(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPICOXRHMD* InXRHMD, uint32 MSAAValue)
#endif
{
	PXR_LOGI(PxrUnreal, "CreateSwapChain_OpenGL LayerID:%u, Format:%d,SizeX:%d,SizeY:%d,ArraySize:%d,NumMips:%d,NumSamples:%d,Flags:%d,TargetableTextureFlags:%d,MSAAValue:%d", LayerID, Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, MSAAValue);
	TArray<FTextureRHIRef> TextureChains;
	FOpenGLDynamicRHI* DynamicRHI = static_cast<FOpenGLDynamicRHI*>(GDynamicRHI);
	FTextureRHIRef ChainTarget = nullptr;
	if (ArraySize == 1) {
		ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(EPixelFormat(Format), SizeX, SizeY, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black , (uint32)NativeTextures[0], TargetableTextureFlags));
		for (const auto& TextureResource : NativeTextures)
		{
			TextureChains.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(EPixelFormat(Format), SizeX, SizeY, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (uint32)TextureResource, TargetableTextureFlags)));
		}
	} else if (ArraySize == 2) {
		ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(EPixelFormat(Format), SizeX, SizeY, ArraySize,NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (uint32)NativeTextures[0], TargetableTextureFlags));
		for (const auto& TextureResource : NativeTextures)
		{
			TextureChains.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(EPixelFormat(Format), SizeX, SizeY, ArraySize, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (uint32)TextureResource, TargetableTextureFlags)));
		}
	}
	return CreateXRSwapChain<FPICOXRSwapChain>(MoveTemp(TextureChains), ChainTarget, InXRHMD);
}

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_Vulkan(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags,FPICOXRHMD* InXRHMD, uint32 MSAAValue)
#else
FXRSwapChainPtr CreateSwapChain_Vulkan(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPICOXRHMD* InXRHMD, uint32 MSAAValue)
#endif
{
	PXR_LOGI(PxrUnreal, "CreateSwapChain_Vulkan LayerID:%u, Format:%d,SizeX:%d,SizeY:%d,ArraySize:%d,NumMips:%d,NumSamples:%d,Flags:%d,TargetableTextureFlags:%d,MSAAValue:%d", LayerID, Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, MSAAValue);
#if PLATFORM_ANDROID
	TArray<FTextureRHIRef> TextureChain;
	FTextureRHIRef ChainTarget;
	FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);

	for (const auto& TexutreResource : NativeTextures)
	{
		VkImageSubresourceRange SubresourceRangeAll = { VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS };
		FVulkanCommandListContext& ImmediateContext = DynamicRHI->GetDevice()->GetImmediateContext();
		FVulkanCmdBuffer* CmdBuffer = ImmediateContext.GetCommandBufferManager()->GetActiveCmdBuffer();

		if (TargetableTextureFlags & TexCreate_RenderTargetable)
		{
			GVulkanRHI->VulkanSetImageLayout(CmdBuffer->GetHandle(), (VkImage)TexutreResource, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, SubresourceRangeAll);
		}
#if ENGINE_MINOR_VERSION > 25
		else if (TargetableTextureFlags & TexCreate_Foveation)
		{
			GVulkanRHI->VulkanSetImageLayout(CmdBuffer->GetHandle(), (VkImage)TexutreResource, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT, SubresourceRangeAll);
		}
#endif
	}

	if (ArraySize == 1)
	{
		for (const auto& TexutreResource : NativeTextures)
		{
			TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(EPixelFormat(Format), SizeX, SizeY, NumMips, NumSamples, (VkImage)TexutreResource, TargetableTextureFlags)));
			PXR_LOGI(PxrUnreal, "TextureChain.size = %d", TextureChain.Num());
		}

		if (ENGINE_MINOR_VERSION < 25)
		{
			ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(EPixelFormat(Format), SizeX, SizeY, NumMips, NumSamples, (VkImage)NativeTextures[0], TargetableTextureFlags));
		}
		else
		{
			ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
		}
	}
	else if (ArraySize == 2)
	{
		for (const auto& TexutreResource : NativeTextures)
		{
			TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(EPixelFormat(Format), SizeX, SizeY, ArraySize, NumMips, NumSamples, (VkImage)TexutreResource, TargetableTextureFlags)));
		}

		if (ENGINE_MINOR_VERSION < 25)
		{
			ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(EPixelFormat(Format), SizeX, SizeY, ArraySize, NumMips, NumSamples, (VkImage)NativeTextures[0], TargetableTextureFlags));
		}
		else
		{
			ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
		}
	}
	return CreateXRSwapChain<FPICOXRSwapChain>(MoveTemp(TextureChain), ChainTarget, InXRHMD);
#endif
	return FXRSwapChainPtr();
}
