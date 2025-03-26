// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "PXR_HMDPrivate.h"
#include "IHeadMountedDisplay.h"
#include "PXR_VulkanExtensions.h"
#include "PXR_PluginWrapper.h"

//-------------------------------------------------------------------------------------------------
// FPICOXRHMDModule
//-------------------------------------------------------------------------------------------------
class FPICOXRHMDModule : public IPICOXRHMDModule
{
public:
	FPICOXRHMDModule();
	static inline FPICOXRHMDModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FPICOXRHMDModule >("PICOXRHMD");
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
	virtual bool PreInit() override;
	virtual FString GetDeviceSystemName() override;
    virtual TSharedPtr< class IXRTrackingSystem, ESPMode::ThreadSafe > CreateTrackingSystem() override;
    virtual TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > GetVulkanExtensions() override;
	virtual bool IsStandaloneStereoOnlyDevice() override;

public:

	bool IsPXRPluginAvailable() const
	{
#if PICO_HMD_SUPPORTED_PLATFORMS
		return PVRPluginHandle != nullptr;
#else
		return false;
#endif

	}

#if PICO_HMD_SUPPORTED_PLATFORMS
public:
	PICOXRHMD_API static void* GetPVRPluginHandle();
	PICOXRHMD_API static inline PICOPluginWrapper& GetPluginWrapper() { return PluginWrapper; }
protected:
	static PICOPluginWrapper PluginWrapper;

	bool bPreInit;
	bool bPreInitCalled;
	void* PVRPluginHandle;
	TWeakPtr< IHeadMountedDisplay, ESPMode::ThreadSafe > HeadMountedDisplay;
	TSharedPtr< IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe > VulkanExtensions;
#endif
};
