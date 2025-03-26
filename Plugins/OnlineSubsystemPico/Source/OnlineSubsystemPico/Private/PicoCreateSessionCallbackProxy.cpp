// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "PicoCreateSessionCallbackProxy.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MAJOR_VERSION > 4
#include "Online/CoreOnline.h"
#elif ENGINE_MINOR_VERSION > 24
#include "UObject/CoreOnline.h"
#endif

#include "Online.h"
#include "OnlineSessionInterfacePico.h"
#include "../Plugins/Online/OnlineSubsystem/Source/Public/OnlineSessionSettings.h"

UPicoCreateSessionCallbackProxy::UPicoCreateSessionCallbackProxy(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , CreateCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateCompleted))
    , StartCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartCompleted))
    , NumPublicConnections(1)
{
}

UPicoCreateSessionCallbackProxy* UPicoCreateSessionCallbackProxy::CreateSession(int32 PublicConnections, FString PicoMatchmakingPool)
{
    UPicoCreateSessionCallbackProxy* Proxy = NewObject<UPicoCreateSessionCallbackProxy>();
    Proxy->SetFlags(RF_StrongRefOnFrame);
    Proxy->NumPublicConnections = PublicConnections;
    Proxy->PicoPool = MoveTemp(PicoMatchmakingPool);
    return Proxy;
}

void UPicoCreateSessionCallbackProxy::Activate()
{
    auto PicoSessionInterface = Online::GetSessionInterface(PICO_SUBSYSTEM);

    if (PicoSessionInterface.IsValid())
    {
        CreateCompleteDelegateHandle = PicoSessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegate);

        FOnlineSessionSettings Settings;
        Settings.NumPublicConnections = NumPublicConnections;
        Settings.bShouldAdvertise = true;
        Settings.bAllowJoinInProgress = true;
        Settings.bUsesPresence = true;
        Settings.bAllowJoinViaPresence = true;

        if (!PicoPool.IsEmpty())
        {
            Settings.Set(SETTING_PICO_POOL, PicoPool, EOnlineDataAdvertisementType::ViaOnlineService);
        }

        PicoSessionInterface->CreateSession(0, NAME_GameSession, Settings);
    }
    else
    {
        UE_LOG_ONLINE_SESSION(Error, TEXT("Pico platform service not available. Skipping CreateSession."));
        OnFailure.Broadcast();
    }
}

void UPicoCreateSessionCallbackProxy::OnCreateCompleted(FName SessionName, bool bWasSuccessful)
{
    auto PicoSessionInterface = Online::GetSessionInterface(PICO_SUBSYSTEM);

    if (PicoSessionInterface.IsValid())
    {
        PicoSessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegateHandle);

        if (bWasSuccessful)
        {
            StartCompleteDelegateHandle = PicoSessionInterface->AddOnStartSessionCompleteDelegate_Handle(StartCompleteDelegate);
            PicoSessionInterface->StartSession(NAME_GameSession);

            // OnStartCompleted will get called, nothing more to do now
            return;
        }
    }

    if (!bWasSuccessful)
    {
        OnFailure.Broadcast();
    }
}

void UPicoCreateSessionCallbackProxy::OnStartCompleted(FName SessionName, bool bWasSuccessful)
{
    auto PicoSessionInterface = Online::GetSessionInterface(PICO_SUBSYSTEM);

    if (PicoSessionInterface.IsValid())
    {
        PicoSessionInterface->ClearOnStartSessionCompleteDelegate_Handle(StartCompleteDelegateHandle);
    }

    if (bWasSuccessful)
    {
        OnSuccess.Broadcast();
    }
    else
    {
        OnFailure.Broadcast();
    }
}
