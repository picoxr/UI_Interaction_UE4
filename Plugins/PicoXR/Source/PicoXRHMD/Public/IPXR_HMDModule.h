//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

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
