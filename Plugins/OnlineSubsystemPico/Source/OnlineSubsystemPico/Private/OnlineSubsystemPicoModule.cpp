// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "OnlineSubsystemPicoModule.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "Core.h"
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
#define LOCTEXT_NAMESPACE "FOnlinePicoModule"

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
//	UE_LOG_ONLINE(Log, TEXT("Pico Module Startup"));
//	FString BaseDir = IPluginManager::Get().FindPlugin("OnlineSubsystemPico")->GetBaseDir();
//	FString LibraryPath;
//	FString BuildDir = FPaths::ProjectDir() + TEXT("Build/");
//	FString Projectdir = FPaths::ProjectDir();
//	if (!FPaths::DirectoryExists(BuildDir))
//	{
//		if (FPaths::DirectoryExists(FPaths::ProjectDir()))
//		{
//			UE_LOG_ONLINE(Log, TEXT("No Build Dir!, &s"), *Projectdir);
//		}
//		UE_LOG_ONLINE(Log, TEXT("No Build Dir!"));
//	}
//	else
//	{
//		FString LibsPath = BuildDir + TEXT("libs/armeabi-v7a/");
//		if (!FPaths::DirectoryExists(LibsPath))
//		{
//			UE_LOG_ONLINE(Log, TEXT("No Lib Dir!"));
//		}
//	}
//#if PLATFORM_ANDROID
//	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/OnlineSubsystemPico/lib/armeabi-v7a/libpxrplatformloader.so"));
//	if (FPaths::FileExists(LibraryPath))
//	{
//		ExampleLibraryHandle = FPlatformProcess::GetDllHandle(*LibraryPath);
//	}
//	else
//	{
//		UE_LOG_ONLINE(Log, TEXT("Open So Failed!"));
//	}
//#endif
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
	//if (ExampleLibraryHandle)
	//{
 //       FOnlineSubsystemModule& PSS = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
 //       PSS.UnregisterPlatformService(PICO_SUBSYSTEM);
 //       FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
 //       ExampleLibraryHandle = nullptr;
 //       delete PicoFactory;
 //       PicoFactory = nullptr;
	//}

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
