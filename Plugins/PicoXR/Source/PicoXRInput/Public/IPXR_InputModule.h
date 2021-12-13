// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"

class IPicoXRInputModule : public IInputDeviceModule
{
public:
	static inline IPicoXRInputModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoXRInputModule >( "PicoXRInput" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PicoXRInput" );
	}
};

