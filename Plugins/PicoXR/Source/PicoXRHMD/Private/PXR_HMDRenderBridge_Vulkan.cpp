// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_HMDRenderBridge.h"
#include "PXR_HMDPrivateRHI.h"
#include "PXR_HMD.h"
#include "PXR_Log.h"

class FPICOXRRenderBridge_Vulkan : public FPICOXRRenderBridge
{
public:
	FPICOXRRenderBridge_Vulkan(FPICOXRHMD* HMD) :FPICOXRRenderBridge(HMD)
	{
		RHIString = HMD->GetRHIString();
		PXR_LOGI(PxrUnreal, "FPICOXRRenderBridge_Vulkan GRHISupportsRHIThread = %d, GIsThreadedRendering = %d, GUseRHIThread_InternalUseOnly = %d", GRHISupportsRHIThread, GIsThreadedRendering, GUseRHIThread_InternalUseOnly);
#if PLATFORM_ANDROID
		if (GRHISupportsRHIThread && GIsThreadedRendering && GUseRHIThread_InternalUseOnly)
		{
			int version = 0;
			if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
			{
				static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetPxrRuntimeVersion", "()I", false);
				version = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
			}
			PXR_LOGI(PxrUnreal, "RuntimeVersion:%d", version);
			if (version >= 21)
			{
				SetRHIThreadEnabled(false, false);
			}
		}

		if (IsRunningRHIInSeparateThread()) {
			if (IsRunningRHIInDedicatedThread()) {
				PXR_LOGI(PxrUnreal, "RHIThread is now running on a dedicated thread.");
			}
			else {
				check(IsRunningRHIInTaskThread());
				PXR_LOGI(PxrUnreal, "RHIThread is now running on task threads.");
			}
		}
		else {
			check(!IsRunningRHIInTaskThread() && !IsRunningRHIInDedicatedThread());
			PXR_LOGI(PxrUnreal, "RHIThread is disabled.");
		}
#endif
	}
	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType RHIResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue)override
	{
		FClearValueBinding ColorTextureBinding = FClearValueBinding();
#if PLATFORM_ANDROID
		const VkImageSubresourceRange SubresourceRangeAll = { VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS };

		if (EnumHasAnyFlags(TargetableTextureFlags,TexCreate_RenderTargetable))
		{
			GVulkanRHI->RHISetImageLayout((VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, SubresourceRangeAll);
		}
		else if (EnumHasAnyFlags(TargetableTextureFlags,TexCreate_Foveation))
		{
			GVulkanRHI->RHISetImageLayout((VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT, SubresourceRangeAll);
		}

		switch (RHIResourceType)
		{
		case RRT_Texture2D:
			return GVulkanRHI->RHICreateTexture2DFromResource((EPixelFormat)Format, SizeX, SizeY, NumMips, NumSamples, (VkImage)(InTexture), TargetableTextureFlags).GetReference();

		case RRT_Texture2DArray:
			return GVulkanRHI->RHICreateTexture2DArrayFromResource((EPixelFormat)Format, SizeX, SizeY, 2, NumMips, NumSamples, (VkImage)(InTexture), TargetableTextureFlags,ColorTextureBinding).GetReference();

		case RRT_TextureCube:
			return GVulkanRHI->RHICreateTextureCubeFromResource((EPixelFormat)Format, SizeX, false, 1, NumMips, (VkImage)(InTexture), TargetableTextureFlags).GetReference();

		default:
			return nullptr;
		}
#endif
		return nullptr;
	}

	virtual void GetGraphics() override
	{
#if PLATFORM_ANDROID
		PXR_LOGI(PxrUnreal, "GetVulkanGraphics");
		FVulkanDevice* Device = GVulkanRHI->GetDevice();
		FVulkanQueue* Queue = Device->GetGraphicsQueue();

		PxrVulkanBinding vulkanBinding = {};
		vulkanBinding.instance = GVulkanRHI->GetInstance();
		vulkanBinding.physicalDevice = Device->GetPhysicalHandle();
		vulkanBinding.device = Device->GetInstanceHandle();
		vulkanBinding.queueFamilyIndex = Queue->GetFamilyIndex();
		vulkanBinding.queueIndex = 0;

		FPICOXRHMDModule::GetPluginWrapper().CreateVulkanSystem(&vulkanBinding);
#endif
	}

#ifdef PICO_CUSTOM_ENGINE
	virtual void UpdateFoveationOffsetsUsage_RHIThread(bool bUseOffsets) override
	{

#if PLATFORM_ANDROID
		check(IsInRHIThread() || IsInRenderingThread());
		GVulkanRHI->VulkanSetFragmentDensityMapOffsetUsage(bUseOffsets);
#endif
	}
	virtual void UpdateFoveationOffsets_RHIThread(const FIntPoint& LeftOffset, const FIntPoint& RightOffset) override
	{

#if PLATFORM_ANDROID
		check(IsInRHIThread() || IsInRenderingThread());
		GVulkanRHI->VulkanSetFragmentDensityMapOffsets(LeftOffset, RightOffset);
#endif
	}
#endif
};

FPICOXRRenderBridge* CreateRenderBridge_Vulkan(FPICOXRHMD* HMD)
{
	return new FPICOXRRenderBridge_Vulkan(HMD);
}
