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

#define LOCTEXT_NAMESPACE "FPICOXRModule"

//-------------------------------------------------------------------------------------------------
// FPICOXRHMDModule
//-------------------------------------------------------------------------------------------------
FPICOXRHMDModule::FPICOXRHMDModule()
{
}

void FPICOXRHMDModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "PICOXRSetting",
		LOCTEXT("PICOXRSettingsName", "PICOXR Settings"),
		LOCTEXT("PICOXRSettingsDescription", "Configure the PICOXR plug-in."),
		GetMutableDefault<UPICOXRSettings>());
		UPICOXRSettings* const Settings= GetMutableDefault<UPICOXRSettings>();
		Settings->HandlesRGBHWSupport();
	}
#endif
}

void FPICOXRHMDModule::UnregisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "PICOXRSetting");
	}
#endif
}

void FPICOXRHMDModule::StartupModule()
{
	IHeadMountedDisplayModule::StartupModule();
	FCoreDelegates::OnFEngineLoopInitComplete.AddRaw(this,&FPICOXRHMDModule::RegisterSettings);
	FString PluginShaderDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("PICOXR/Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/PICOXR"), PluginShaderDir);
}

void FPICOXRHMDModule::ShutdownModule()
{
	IHeadMountedDisplayModule::ShutdownModule();
	UnregisterSettings();
}

FString FPICOXRHMDModule::GetModuleKeyName() const
{
	return FString(TEXT("PICOXRHMD"));
}

void FPICOXRHMDModule::GetModuleAliases(TArray<FString>& AliasesOut) const
{	
}

bool FPICOXRHMDModule::IsHMDConnected()
{
	return true;
}

TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > FPICOXRHMDModule::CreateTrackingSystem()
{
    PXR_LOGI(PxrUnreal, "CreateTrackingSystem");
	TSharedPtr< FPICOXRHMD, ESPMode::ThreadSafe > PICOMobileHMD = FSceneViewExtensions::NewExtension<FPICOXRHMD>();
	if (PICOMobileHMD && PICOMobileHMD->Initialize())
	{
		return PICOMobileHMD;
	}
	return nullptr;
}

IMPLEMENT_MODULE(FPICOXRHMDModule, PICOXRHMD)

TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > FPICOXRHMDModule::GetVulkanExtensions()
{
    PXR_LOGI(PxrUnreal, "GetVulkanExtensions");
	if (!VulkanExtensions.IsValid())
	{
		PXR_LOGD(PxrUnreal,"FPICOXRHMDModule new FVulkanExtensions");
		VulkanExtensions = MakeShareable(new FVulkanExtensions());
	}
	return VulkanExtensions;
}

#if ENGINE_MINOR_VERSION>26
bool FPICOXRHMDModule::IsStandaloneStereoOnlyDevice()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceMake().ToUpper() == FString(TEXT("PICO"));
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