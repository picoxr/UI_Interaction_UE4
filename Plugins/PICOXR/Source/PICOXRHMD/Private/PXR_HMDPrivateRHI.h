// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once

#if PICO_HMD_SUPPORTED_PLATFORMS
//-------------------------------------------------------------------------------------------------
// OpenGL
//-------------------------------------------------------------------------------------------------

#if PICO_HMD_SUPPORTED_PLATFORMS_OPENGL

#endif // PICO_HMD_SUPPORTED_PLATFORMS_OPENGL


//-------------------------------------------------------------------------------------------------
// Vulkan
//-------------------------------------------------------------------------------------------------

#if PICO_HMD_SUPPORTED_PLATFORMS_VULKAN
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#include "VulkanPendingState.h"
#include "VulkanContext.h"
#endif // PICO_HMD_SUPPORTED_PLATFORMS_VULKAN

#endif // PICO_HMD_SUPPORTED_PLATFORMS