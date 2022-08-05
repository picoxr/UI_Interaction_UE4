//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

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

