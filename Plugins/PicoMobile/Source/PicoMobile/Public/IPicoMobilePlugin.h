// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "IHeadMountedDisplayModule.h"

class IPicoMobilePlugin : public IHeadMountedDisplayModule
{

public:
	static inline IPicoMobilePlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoMobilePlugin >( "PicoMobile" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PicoMobile" );
	}
};
