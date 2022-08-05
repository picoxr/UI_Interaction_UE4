// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
/**
 * Online subsystem module class  (Pico Implementation)
 * Code related to the loading of the Oculus module
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
private:
    /** Handle to the test dll we will load */
//    void* ExampleLibraryHandle;
};