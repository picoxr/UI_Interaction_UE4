// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "PXR_HMDPrivate.h"
#include "IHeadMountedDisplayVulkanExtensions.h"

#if PICO_HMD_SUPPORTED_PLATFORMS
//-------------------------------------------------------------------------------------------------
// FVulkanExtensions
//-------------------------------------------------------------------------------------------------

class FVulkanExtensions : public IHeadMountedDisplayVulkanExtensions, public TSharedFromThis<FVulkanExtensions, ESPMode::ThreadSafe>
{
public:
	FVulkanExtensions() {}
	virtual ~FVulkanExtensions() {}

	// IHeadMountedDisplayVulkanExtensions
	virtual bool GetVulkanInstanceExtensionsRequired(TArray<const ANSICHAR*>& Out) override;
	virtual bool GetVulkanDeviceExtensionsRequired(struct VkPhysicalDevice_T *pPhysicalDevice, TArray<const ANSICHAR*>& Out) override;
};
#endif //PICO_HMD_SUPPORTED_PLATFORMS