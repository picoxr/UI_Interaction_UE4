//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDRenderBridge.h"
#include "PXR_HMD.h"
#include "PXR_Log.h"

#if PLATFORM_ANDROID
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#include "VulkanPendingState.h"
#include "VulkanContext.h"
#endif

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
#if ENGINE_MINOR_VERSION>25
	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType ResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue)override
#else
	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType ResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, uint32 TargetableTextureFlags, uint32 MSAAValue)override
#endif
	{
#if PLATFORM_ANDROID
		VkImageSubresourceRange SubresourceRangeAll = { VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS };
		FVulkanCommandListContext& ImmediateContext = GVulkanRHI->GetDevice()->GetImmediateContext();
		FVulkanCmdBuffer* CmdBuffer = ImmediateContext.GetCommandBufferManager()->GetActiveCmdBuffer();

		if (TargetableTextureFlags & TexCreate_RenderTargetable)
		{
			GVulkanRHI->VulkanSetImageLayout(CmdBuffer->GetHandle(), (VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, SubresourceRangeAll);
		}
#if ENGINE_MINOR_VERSION > 25
		else if (TargetableTextureFlags & TexCreate_Foveation)
		{
			GVulkanRHI->VulkanSetImageLayout(CmdBuffer->GetHandle(), (VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT, SubresourceRangeAll);
		}
#endif
		switch (ResourceType)
		{
		case RRT_Texture2D:
			return GVulkanRHI->RHICreateTexture2DFromResource((EPixelFormat)Format, SizeX, SizeY, NumMips, NumSamples, (VkImage)(InTexture), TargetableTextureFlags).GetReference();

		case RRT_Texture2DArray:
			return GVulkanRHI->RHICreateTexture2DArrayFromResource((EPixelFormat)Format, SizeX, SizeY, 2, NumMips, NumSamples, (VkImage)(InTexture), TargetableTextureFlags).GetReference();

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

		Pxr_CreateVulkanSystem(&vulkanBinding);
#endif
	}
};

FPICOXRRenderBridge* CreateRenderBridge_Vulkan(FPICOXRHMD* HMD)
{
	return new FPICOXRRenderBridge_Vulkan(HMD);
}
