// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once
#include "OnlinePicoSettings.generated.h"


UENUM()
enum class ERegionType :uint8
{
    China,
    NonChina,
    Both
};

UCLASS(config = Engine, defaultconfig)
class ONLINESUBSYSTEMPICO_API UOnlinePicoSettings : public UObject
{
    GENERATED_UCLASS_BODY()
public:

    // Platform
    UPROPERTY(Config)
        bool bIsForeign;

    UPROPERTY(Config)
        bool bIsGlobal;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "Region"))
        ERegionType RegionType;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "AppID"))
        FString AppID;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "AppKey"))
        FString AppKey;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "Scope"))
        FString Scope;
    //EntitlementCheck
    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "User Entitlement Check", ToolTip = "If selected, you will need to enter the APPID that is obtained from Pico Developer Platform after uploading the app for an entitlement check upon the app launch."))
        bool bStartTimeEntitlementCheck;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bStartTimeEntitlementCheck", DisplayName = "EntitlementCheckAppID"))
        FString EntitlementCheckAppID;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "Entitlement Check Simulation", ToolTip = "If true, Development devices will simulate Entitlement Check, you should enter a valid device SN codes list. The SN code can be obtain in Settings-General-Device serial number or input 'adb devices ' in cmd"))
        bool bEntitlementCheckSimulation;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bEntitlementCheckSimulation", DisplayName = "Device SN Code List"))
        TArray<FString> DeviceSN;

    virtual void PostInitProperties() override;
};
