// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#include "OnlinePicoSettings.h"

UOnlinePicoSettings::UOnlinePicoSettings(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer),
    bIsForeign(false),
    bIsGlobal(false),
    bStartTimeEntitlementCheck(false),
    bEntitlementCheckSimulation(false)
{
}

void UOnlinePicoSettings::PostInitProperties()
{
    Super::PostInitProperties();

    switch (RegionType)
    {
    case ERegionType::China:
    {
        bIsForeign = false;
        bIsGlobal = false;
    }
    break;
    case ERegionType::NonChina:
    {
        bIsForeign = true;
        bIsGlobal = false;
    }
    break;
    case ERegionType::Both:
    {
        bIsForeign = false;
        bIsGlobal = true;
    }
    break;
    default:
        break;
    }

    Super::UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOnlinePicoSettings, bIsForeign)), GetDefaultConfigFilename());
    Super::UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOnlinePicoSettings, bIsGlobal)), GetDefaultConfigFilename());
}