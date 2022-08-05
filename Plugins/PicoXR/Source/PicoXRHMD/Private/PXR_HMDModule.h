//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "IHeadMountedDisplay.h"
#include "IHeadMountedDisplayVulkanExtensions.h"
#include "IPXR_HMDModule.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "PXR_HMDRenderBridge.h"
#include "PXR_Log.h"

//-------------------------------------------------------------------------------------------------
// FPicoXRHMDModule
//-------------------------------------------------------------------------------------------------
class FPicoXRHMDModule : public IPicoXRHMDModule
{
public:
	FPicoXRHMDModule();
	static inline FPicoXRHMDModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FPicoXRHMDModule >("PicoXRHMD");
	}

	// IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void RegisterSettings();
	void UnregisterSettings();

	// IHeadMountedDisplayModule
	virtual FString GetModuleKeyName() const override;
	virtual void GetModuleAliases(TArray<FString>& AliasesOut) const override;
	virtual bool IsHMDConnected() override;
    virtual TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > CreateTrackingSystem() override;
    virtual TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > GetVulkanExtensions() override;
#if ENGINE_MINOR_VERSION>26
	virtual bool IsStandaloneStereoOnlyDevice() override;
#endif
private:
    TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > VulkanExtensions;
};

class FVulkanExtensions : public IHeadMountedDisplayVulkanExtensions
{
public:
    FVulkanExtensions() {}
    virtual ~FVulkanExtensions() {}

    /** IHeadMountedDisplayVulkanExtensions */
    virtual bool GetVulkanInstanceExtensionsRequired(TArray<const ANSICHAR*>& Out) override;
    virtual bool GetVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* pPhysicalDevice, TArray<const ANSICHAR*>& Out) override;
};
