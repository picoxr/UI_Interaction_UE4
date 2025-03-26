// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "OnlineSubsystemPicoModule.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "OnlinePicoSettings.h"
#include "Misc/ConfigCacheIni.h"

#if WITH_EDITOR
#include "PropertyEditorModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "OnlinePicoSettingsCustomization.h"
#endif
#include "Misc/CoreDelegates.h"

#define LOCTEXT_NAMESPACE "OnlinePicoModule"

IMPLEMENT_MODULE(FOnlineSubsystemPicoModule, OnlineSubsystemPico);

/**
 * Class responsible for creating instance(s) of the subsystem
 */
class FOnlineFactoryPico : public IOnlineFactory
{
private:

    /** Singleton instance of the Pico OSS */
    FOnlineSubsystemPicoPtr OnlineSub;

public:

    FOnlineFactoryPico() {}
    virtual ~FOnlineFactoryPico() {}

    IOnlineSubsystemPtr CreateSubsystem(FName InstanceName) override
    {
        if (!OnlineSub.IsValid())
        {
            OnlineSub = MakeShared<FOnlineSubsystemPico, ESPMode::ThreadSafe>(InstanceName);
        }
        if (OnlineSub->IsEnabled())
        {
            if (!OnlineSub->IsInitialized())
            {
                if (!OnlineSub->Init())
                {
                    UE_LOG_ONLINE(Warning, TEXT("Pico SDK failed to initialize"));
                    OnlineSub = nullptr;
                }
            }
            else
            {
                UE_LOG_ONLINE(Log, TEXT("Pico SDK already initialized!"));
            }
        }
        else
        {
            UE_LOG_ONLINE(Warning, TEXT("Pico SDK disabled!"));
            OnlineSub->Shutdown();
            OnlineSub = nullptr;
        }
        return OnlineSub;
    }
};

void FOnlineSubsystemPicoModule::StartupModule()
{
#if PLATFORM_WINDOWS
    FString BaseDir = IPluginManager::Get().FindPlugin("OnlineSubsystemPico")->GetBaseDir();
    Lib1Handel = FPlatformProcess::GetDllHandle(*(BaseDir + "/Binaries/ThirdParty/PPFLibrary/Win64/openh264-4.dll"));
    Lib2Handel = FPlatformProcess::GetDllHandle(*(BaseDir + "/Binaries/ThirdParty/PPFLibrary/Win64/RTCFFmpeg.dll"));
    Lib3Handel = FPlatformProcess::GetDllHandle(*(BaseDir + "/Binaries/ThirdParty/PPFLibrary/Win64/VolcEngineRTC.dll"));
    Lib4Handel = FPlatformProcess::GetDllHandle(*(BaseDir + "/Binaries/ThirdParty/PPFLibrary/Win64/pthreadVC2.dll"));
    WindowsLibraryHandle = FPlatformProcess::GetDllHandle(*(BaseDir + "/Binaries/ThirdParty/PPFLibrary/Win64/platformsdk.dll"));
#endif

    PicoFactory = new FOnlineFactoryPico();
    PicoFactory->CreateSubsystem(FName(TEXT("Pico")));
    // Create and register our singleton factory with the main online subsystem for easy access
    FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
    OnlineSubsystemModule.RegisterPlatformService(PICO_SUBSYSTEM, PicoFactory);
    FCoreDelegates::OnFEngineLoopInitComplete.AddRaw(this, &FOnlineSubsystemPicoModule::RegisterSettings);
}

void FOnlineSubsystemPicoModule::ShutdownModule()
{
    UE_LOG_ONLINE(Log, TEXT("Pico Module Shutdown"));

    FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
    OnlineSubsystemModule.UnregisterPlatformService(PICO_SUBSYSTEM);
    delete PicoFactory;
    PicoFactory = nullptr;
    UnregisterSettings();

#if PLATFORM_WINDOWS
    FPlatformProcess::FreeDllHandle(WindowsLibraryHandle);
    WindowsLibraryHandle = nullptr;

    if (Lib1Handel)
    {
        FPlatformProcess::FreeDllHandle(Lib1Handel);
        Lib1Handel = nullptr;
    }
    if (Lib2Handel)
    {
        FPlatformProcess::FreeDllHandle(Lib2Handel);
        Lib2Handel = nullptr;
    }
    if (Lib3Handel)
    {
        FPlatformProcess::FreeDllHandle(Lib3Handel);
        Lib3Handel = nullptr;
    }
    if (Lib4Handel)
    {
        FPlatformProcess::FreeDllHandle(Lib4Handel);
        Lib4Handel = nullptr;
    }
#endif
}

void FOnlineSubsystemPicoModule::RegisterSettings()
{
#if WITH_EDITOR

    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    PropertyModule.RegisterCustomClassLayout(
        UOnlinePicoSettings::StaticClass()->GetFName(),
        FOnGetDetailCustomizationInstance::CreateStatic(&FOnlinePicoSettingsCustomization::MakeInstance)
    );
    PropertyModule.NotifyCustomizationModuleChanged();
    // register settings
    ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

    if (SettingsModule != nullptr)
    {
        ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "OnlinePicoSetting",
            LOCTEXT("OnlinePicoSettingsName", "OnlinePico Settings"),
            LOCTEXT("OnlinePicoSettingsDescription", "Configure the OnlineSubsystemPico plugin."),
            GetMutableDefault<UOnlinePicoSettings>()
        );
    }
#endif
}

void FOnlineSubsystemPicoModule::UnregisterSettings()
{
#if WITH_EDITOR
    ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

    if (SettingsModule != nullptr)
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "OnlinePicoSetting");
    }
#endif
}
#undef LOCTEXT_NAMESPACE