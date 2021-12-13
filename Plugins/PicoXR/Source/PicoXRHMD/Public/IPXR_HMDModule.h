// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IHeadMountedDisplayModule.h"

class IPicoXRHMDModule : public IHeadMountedDisplayModule
{
public:

	static inline IPicoXRHMDModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoXRHMDModule >("PicoXRHMD");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PicoXRHMD");
	}
};
