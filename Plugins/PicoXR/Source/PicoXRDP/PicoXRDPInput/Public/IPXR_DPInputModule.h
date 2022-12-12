//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"

class IPICOXRDPInputModule : public IInputDeviceModule
{
public:
	static inline IPICOXRDPInputModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPICOXRDPInputModule >( "PICOXRDPInput" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PICOXRDPInput" );
	}
};

