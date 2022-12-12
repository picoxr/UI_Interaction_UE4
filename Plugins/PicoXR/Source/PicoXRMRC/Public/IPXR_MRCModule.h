//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once
#include "Modules/ModuleManager.h"

#define PICO_MRC_SUPPORTED_PLATFORMS PLATFORM_ANDROID

class IPICOXRMRCModule : public IModuleInterface
{

public:

	static inline IPICOXRMRCModule& Get()
	{
		return FModuleManager::GetModuleChecked< IPICOXRMRCModule >("PICOXRMRC");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PICOXRMRC");
	}
};
