// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
    void* WindowsLibraryHandle;
    void* Lib1Handel;
    void* Lib2Handel;
    void* Lib3Handel;
    void* Lib4Handel;
};