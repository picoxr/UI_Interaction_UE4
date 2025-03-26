// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "PICOPlatformSubsystem.h"
#include "OnlineSubsystemPicoManager.h"

UPICOPlatformSubsystem::UPICOPlatformSubsystem()
    : UGameInstanceSubsystem()
{

}

void UPICOPlatformSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

void UPICOPlatformSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

UOnlineSubsystemPicoManager* UPICOPlatformSubsystem::ConstructPicoManager()
{
    if (PicoManager)
    {
        return PicoManager;
    }
    else
    {
        return PicoManager = NewObject<UOnlineSubsystemPicoManager>(this);
    }
}
