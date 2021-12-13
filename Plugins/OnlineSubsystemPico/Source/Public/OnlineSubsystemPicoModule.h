// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

#ifndef PICO_SUBSYSTEM
#define PICO_SUBSYSTEM FName(TEXT("Pico"))
#endif

class FOnlineSubsystemPicoModule : public IModuleInterface
{
private:

	class FOnlineFactoryPico* PicoFactory;

public:

	FOnlineSubsystemPicoModule() :PicoFactory(nullptr){}

	virtual ~FOnlineSubsystemPicoModule() {}

	// IModuleInterface

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void RegisterSettings();
	void UnregisterSettings();

	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}

	virtual bool SupportsAutomaticShutdown() override
	{
		return false;
	}
};
