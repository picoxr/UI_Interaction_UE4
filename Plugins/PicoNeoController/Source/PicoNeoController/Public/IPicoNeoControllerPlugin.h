// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"

class IPicoNeoControllerPlugin : public IInputDeviceModule
{

public:
	static inline IPicoNeoControllerPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoNeoControllerPlugin >("PicoNeoController");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PicoNeoController");
	}
};
