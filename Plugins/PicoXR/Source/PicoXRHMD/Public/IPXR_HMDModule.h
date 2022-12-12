//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IHeadMountedDisplayModule.h"

class IPICOXRHMDModule : public IHeadMountedDisplayModule
{
public:

	static inline IPICOXRHMDModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPICOXRHMDModule >("PICOXRHMD");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PICOXRHMD");
	}
};
