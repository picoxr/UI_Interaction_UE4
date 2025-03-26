// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once
#include "OnlinePicoSettings.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(PicoSettings, Log, All);

UENUM(BlueprintType)
enum class ERegionType :uint8
{
    China,
    NonChina
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

    FString DefaultPlatformService;

    FString AndroidPlatformService;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "bEnabled"))
    bool bEnabled = true;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "AppID"))
    FString AppID;

    UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "Highlight"))
    bool bEnableHighlight = false;

    UPROPERTY(Config, EditAnywhere, Category = WindowsDebug, Meta = (DisplayName = "AccessToken", ToolTip = "Get the access token from development platform"))
    FString AccessToken;

    UPROPERTY(Config, EditAnywhere, Category = WindowsDebug, Meta = (DisplayName = "Region", ToolTip = "Only used in windows debug"))
    ERegionType RegionType;

    virtual void PostInitProperties() override;

    // Gets the config file settings in-game.
    UFUNCTION(BlueprintPure, Category = "OVRPlatformBP|OnlineSubsystemOculus")
    static void GetOnlinePicoSettings(bool& OutbIsEnable, ERegionType& OutRegionType, FString& OutAppID, FString& OutAccessToken, bool& OutbEnableHighlight);

    void LoadSettings();

#if WITH_EDITOR
    void SaveSettings();
    bool ValidateSettings();

    bool SaveWindowsDebugSetting();

    // Called when any property is changed externally.
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif //WITH_EDITOR
};
