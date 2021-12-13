// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "OnlineSubsystemPicoModule.h"
#include "Misc/ConfigCacheIni.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemModule.h"
#include "OnlineSubsystemPico.h"
#include "OnlinePicoSettings.h"

#if WITH_EDITOR
#include "PropertyEditorModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "OnlinePicoSettingsCustomization.h"
#endif
#define LOCTEXT_NAMESPACE "FOnlinePicoModule"

IMPLEMENT_MODULE(FOnlineSubsystemPicoModule, OnlineSubsystemPico);

class FOnlineFactoryPico : public IOnlineFactory
{
private:

	FOnlineSubsystemPicoPtr OnlineSub;

public:

	FOnlineFactoryPico() {}	
	virtual ~FOnlineFactoryPico() {}

	virtual IOnlineSubsystemPtr CreateSubsystem(FName InstanceName) override
	{
		UE_LOG_ONLINE(Warning, TEXT("Pico CreateSubsystem"));
		if (!OnlineSub.IsValid())
		{
			OnlineSub = MakeShared<FOnlineSubsystemPico, ESPMode::ThreadSafe>(InstanceName);
		}
		if (!OnlineSub->IsInitialized())
		{
			if (!OnlineSub->Init())
			{
				UE_LOG_ONLINE(Warning, TEXT("Pico API failed to initialize!"));
				OnlineSub = nullptr;
			}
		}
		else
		{
			UE_LOG_ONLINE(Log, TEXT("Pico API already initialized!"));
		}

		return OnlineSub;
	}
};

void FOnlineSubsystemPicoModule::StartupModule()
{
	UE_LOG_ONLINE(Log, TEXT("Pico Startup!"));
	PicoFactory = new FOnlineFactoryPico();
	FString InterfaceString;
	GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), InterfaceString, GEngineIni);

	UE_LOG(LogTemp,Log,TEXT("DefaultPlatformService  :%s"),*InterfaceString);
	FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OnlineSubsystemModule.RegisterPlatformService(PICO_SUBSYSTEM, PicoFactory);
	FCoreDelegates::OnFEngineLoopInitComplete.AddRaw(this,&FOnlineSubsystemPicoModule::RegisterSettings);
}

void FOnlineSubsystemPicoModule::ShutdownModule()
{
	UE_LOG_ONLINE(Log, TEXT("Pico Shutdown!"));
	FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OnlineSubsystemModule.UnregisterPlatformService(PICO_SUBSYSTEM);
	
	delete PicoFactory;
	PicoFactory = nullptr;
	UnregisterSettings();
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
