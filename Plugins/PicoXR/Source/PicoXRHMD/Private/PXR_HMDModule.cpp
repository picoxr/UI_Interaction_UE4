//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDModule.h"
#include "PXR_HMD.h"
#include "PXR_Settings.h"
#include "HardwareInfo.h"

#if PLATFORM_ANDROID
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#include "Android/AndroidPlatformMisc.h"
#endif

#if WITH_EDITOR
#include "PropertyEditorModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif

#define LOCTEXT_NAMESPACE "FPicoXRModule"

//-------------------------------------------------------------------------------------------------
// FPicoXRHMDModule
//-------------------------------------------------------------------------------------------------
FPicoXRHMDModule::FPicoXRHMDModule()
{
}

void FPicoXRHMDModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "PicoXRSetting",
		LOCTEXT("PicoXRSettingsName", "PicoXR Settings"),
		LOCTEXT("PicoXRSettingsDescription", "Configure the PicoXR plug-in."),
		GetMutableDefault<UPicoXRSettings>());
		UPicoXRSettings* const Settings= GetMutableDefault<UPicoXRSettings>();
		Settings->HandlesRGBHWSupport();
	}
#endif
}

void FPicoXRHMDModule::UnregisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "PicoXRSetting");
	}
#endif
}

void FPicoXRHMDModule::StartupModule()
{
	IHeadMountedDisplayModule::StartupModule();
	FCoreDelegates::OnFEngineLoopInitComplete.AddRaw(this,&FPicoXRHMDModule::RegisterSettings);
	FString PluginShaderDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("PicoXR/Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/PicoXR"), PluginShaderDir);
}

void FPicoXRHMDModule::ShutdownModule()
{
	IHeadMountedDisplayModule::ShutdownModule();
	UnregisterSettings();
}

FString FPicoXRHMDModule::GetModuleKeyName() const
{
	return FString(TEXT("PicoXRHMD"));
}

void FPicoXRHMDModule::GetModuleAliases(TArray<FString>& AliasesOut) const
{	
}

bool FPicoXRHMDModule::IsHMDConnected()
{
	return true;
}

TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > FPicoXRHMDModule::CreateTrackingSystem()
{
    PXR_LOGI(PxrUnreal, "CreateTrackingSystem");
	TSharedPtr< FPicoXRHMD, ESPMode::ThreadSafe > PicoMobileHMD = FSceneViewExtensions::NewExtension<FPicoXRHMD>();
	if (PicoMobileHMD && PicoMobileHMD->Initialize())
	{
		return PicoMobileHMD;
	}
	return nullptr;
}

IMPLEMENT_MODULE(FPicoXRHMDModule, PicoXRHMD)

TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > FPicoXRHMDModule::GetVulkanExtensions()
{
    PXR_LOGI(PxrUnreal, "GetVulkanExtensions");
	if (!VulkanExtensions.IsValid())
	{
		PXR_LOGD(PxrUnreal,"FPicoXRHMDModule new FVulkanExtensions");
		VulkanExtensions = MakeShareable(new FVulkanExtensions());
	}
	return VulkanExtensions;
}

#if ENGINE_MINOR_VERSION>26
bool FPicoXRHMDModule::IsStandaloneStereoOnlyDevice()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceMake() == FString("Pico");
#else
	return false;
#endif
}
#endif

bool FVulkanExtensions::GetVulkanInstanceExtensionsRequired(TArray<const ANSICHAR*>& Out)
{
#if PLATFORM_ANDROID
    PXR_LOGI(PxrUnreal, "GetVulkanInstanceExtensionsRequired");
	TArray<VkExtensionProperties> Properties;
	{
		uint32_t PropertyCount;
		VulkanRHI::vkEnumerateInstanceExtensionProperties(nullptr, &PropertyCount, nullptr);
		Properties.SetNum(PropertyCount);
		VulkanRHI::vkEnumerateInstanceExtensionProperties(nullptr, &PropertyCount, Properties.GetData());
	}

	TArray<const char*> Extensions;
	{
		uint32_t ExtensionCount = 0;
		Extensions.SetNum(ExtensionCount);
	}

	int32 ExtensionsFound = 0;
	for (int32 ExtensionIndex = 0; ExtensionIndex < Extensions.Num(); ExtensionIndex++)
	{
		for (int32 PropertyIndex = 0; PropertyIndex < Properties.Num(); PropertyIndex++)
		{
			const char* PropertyExtensionName = Properties[PropertyIndex].extensionName;

			if (!FCStringAnsi::Strcmp(PropertyExtensionName, Extensions[ExtensionIndex]))
			{
				Out.Add(Extensions[ExtensionIndex]);
				ExtensionsFound++;
				break;
			}
		}
	}
	return ExtensionsFound == Extensions.Num();
#endif
	return true;
}

bool FVulkanExtensions::GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, TArray<const ANSICHAR*>& Out)
{
#if PLATFORM_ANDROID
    PXR_LOGI(PxrUnreal, "GetVulkanDeviceExtensionsRequired");
	TArray<VkExtensionProperties> Properties;
	{
		uint32_t PropertyCount;
		VulkanRHI::vkEnumerateDeviceExtensionProperties((VkPhysicalDevice)pPhysicalDevice, nullptr, &PropertyCount, nullptr);
		Properties.SetNum(PropertyCount);
		VulkanRHI::vkEnumerateDeviceExtensionProperties((VkPhysicalDevice)pPhysicalDevice, nullptr, &PropertyCount, Properties.GetData());
	}
	
	TArray<const char*> Extensions;
	{
		uint32_t ExtensionCount = 0;
		Extensions.SetNum(ExtensionCount);
	}

	int32 ExtensionsFound = 0;
	for (int32 ExtensionIndex = 0; ExtensionIndex < Extensions.Num(); ExtensionIndex++)
	{
		for (int32 PropertyIndex = 0; PropertyIndex < Properties.Num(); PropertyIndex++)
		{
			const char* PropertyExtensionName = Properties[PropertyIndex].extensionName;

			if (!FCStringAnsi::Strcmp(PropertyExtensionName, Extensions[ExtensionIndex]))
			{
				Out.Add(Extensions[ExtensionIndex]);
				ExtensionsFound++;
				break;
			}
		}
	}
	return ExtensionsFound == Extensions.Num();
#endif
	return true;
}
#undef  LOCTEXT_NAMESPACE