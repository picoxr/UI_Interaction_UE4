//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "Modules/ModuleManager.h"
#include "IInputDeviceModule.h"

class IPICOXRInputModule : public IInputDeviceModule
{
public:
	static inline IPICOXRInputModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IPICOXRInputModule >( "PICOXRInput" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "PICOXRInput" );
	}
};

