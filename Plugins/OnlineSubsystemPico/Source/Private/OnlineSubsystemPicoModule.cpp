// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "OnlineSubsystemPicoModule.h"

#include "Misc/ConfigCacheIni.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemModule.h"
#include "OnlineSubsystemPico.h"


IMPLEMENT_MODULE(FOnlineSubsystemPicoModule, OnlineSubsystemPico);

/**
 * Class responsible for creating instance(s) of the subsystem
 */
class FOnlineFactoryPico : public IOnlineFactory
{
private:

	/** Singleton instance of the Pico OnlineSubsystem */
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
				// Shutdown already called in Init() when this failed
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
	// Create and register our singleton factory with the main online subsystem for easy access
	FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OnlineSubsystemModule.RegisterPlatformService(PICO_SUBSYSTEM, PicoFactory);
}

void FOnlineSubsystemPicoModule::ShutdownModule()
{
	UE_LOG_ONLINE(Log, TEXT("Pico Shutdown!"));
	FOnlineSubsystemModule& OnlineSubsystemModule = FModuleManager::GetModuleChecked<FOnlineSubsystemModule>("OnlineSubsystem");
	OnlineSubsystemModule.UnregisterPlatformService(PICO_SUBSYSTEM);
	
	delete PicoFactory;
	PicoFactory = nullptr;
}
