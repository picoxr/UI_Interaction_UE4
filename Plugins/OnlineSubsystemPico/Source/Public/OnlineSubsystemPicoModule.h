// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

#ifndef PICO_SUBSYSTEM
#define PICO_SUBSYSTEM FName(TEXT("Pico"))
#endif

/**
 * Online subsystem module class  (Pico Implementation)
 * Code related to the loading of the Pico module
 */
class FOnlineSubsystemPicoModule : public IModuleInterface
{
private:

	/** Class responsible for creating instance(s) of the subsystem */
	class FOnlineFactoryPico* PicoFactory;

public:

	FOnlineSubsystemPicoModule() :
		PicoFactory(nullptr)
	{}

	virtual ~FOnlineSubsystemPicoModule() {}

	// IModuleInterface

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}

	virtual bool SupportsAutomaticShutdown() override
	{
		return false;
	}
};
