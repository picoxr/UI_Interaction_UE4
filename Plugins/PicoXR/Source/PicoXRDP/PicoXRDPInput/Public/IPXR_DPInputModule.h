//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"

class IPicoXRDPInputModule : public IInputDeviceModule
{
public:
	static inline IPicoXRDPInputModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPicoXRDPInputModule >( "PicoXRDPInput" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PicoXRDPInput" );
	}
};

