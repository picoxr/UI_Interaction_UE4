//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once

#define STEAMVR_SUPPORTED_PLATFORMS (PLATFORM_MAC || (PLATFORM_LINUX && PLATFORM_CPU_X86_FAMILY && PLATFORM_64BITS) || (PLATFORM_WINDOWS && WINVER > 0x0502))

#include "Modules/ModuleManager.h"
#include "IHeadMountedDisplayModule.h"
#include "IHeadMountedDisplay.h"
#include "Logging/LogMacros.h"
#if STEAMVR_SUPPORTED_PLATFORMS
#include "openvr.h"
#endif // STEAMVR_SUPPORTED_PLATFORMS

/** Up to 8 motion controller devices supported (two VR motion controllers per Unreal controller, one for either the left or right hand.) */
#define MAX_STEAMVR_CONTROLLER_PAIRS 4

DECLARE_LOG_CATEGORY_EXTERN(LogPicoDP, Log, All);

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class IPicoDPPlugin : public IHeadMountedDisplayModule
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IPicoDPPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoDPPlugin >( "PicoDP" );
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PicoDP" );
	}

#if STEAMVR_SUPPORTED_PLATFORMS
	/**
	 * Initializes the plugin, in case of VR system restart
	 */
	virtual bool Initialize() = 0;

#endif // STEAMVR_SUPPORTED_PLATFORMS

private:
};

