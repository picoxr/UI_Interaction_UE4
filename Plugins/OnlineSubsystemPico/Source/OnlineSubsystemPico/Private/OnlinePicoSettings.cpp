// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlinePicoSettings.h"

#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializerMacros.h"
#include "Serialization/JsonSerializer.h"

#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"

DEFINE_LOG_CATEGORY(PicoSettings);

UOnlinePicoSettings::UOnlinePicoSettings(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer),
    bIsForeign(false),
    bIsGlobal(false)
{
    DefaultPlatformService = TEXT("Pico");
    AndroidPlatformService = TEXT("Pico");
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
    default:
        break;
    }
    LoadSettings();
    Super::UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOnlinePicoSettings, bIsForeign)), GetDefaultConfigFilename());
    Super::UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOnlinePicoSettings, bIsGlobal)), GetDefaultConfigFilename());

}

void UOnlinePicoSettings::GetOnlinePicoSettings(bool& OutbIsEnable, ERegionType& OutRegionType, FString& OutAppID, FString& OutAccessToken, bool& OutbEnableHighlight)
{
    UOnlinePicoSettings* OnlinePicoSettings = GetMutableDefault<UOnlinePicoSettings>();
    OutbIsEnable = OnlinePicoSettings->bEnabled;
    OutRegionType = OnlinePicoSettings->RegionType;
    OutAppID = OnlinePicoSettings->AppID;
    OutAccessToken = OnlinePicoSettings->AccessToken;
    OutbEnableHighlight = OnlinePicoSettings->bEnableHighlight;
}

void UOnlinePicoSettings::LoadSettings()
{
    // Get values from config files.
    GConfig->GetBool(TEXT("OnlineSubsystemPico"), TEXT("bEnabled"), bEnabled, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    FString GetRegionType;
    GConfig->GetString(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("RegionType"), GetRegionType, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    if (GetRegionType == TEXT("China"))
    {
        RegionType = ERegionType::China;
    }
    else
    {
        RegionType = ERegionType::NonChina;
    }
    GConfig->GetString(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("AppID"), AppID, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    GConfig->GetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), AndroidPlatformService, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");
    GConfig->GetString(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("AccessToken"), AccessToken, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
#if WITH_EDITOR
    bool bShouldForceSaveSettings = ValidateSettings();
    SaveWindowsDebugSetting();
    UE_LOG(PicoSettings, Log, TEXT("DefaultEngine.ini->bEnabled = %s"), bEnabled ? TEXT("True") : TEXT("False"));
    UE_LOG(PicoSettings, Log, TEXT("DefaultEngine.ini->AppId = %s"), *AppID);
    UE_LOG(PicoSettings, Log, TEXT("DefaultEngine.ini->bEnableHighlight = %s"), bEnableHighlight ? TEXT("True") : TEXT("False"));
    UE_LOG(PicoSettings, Log, TEXT("DefaultEngine.ini->DefaultPlatformService = %s"), *DefaultPlatformService);
    UE_LOG(PicoSettings, Log, TEXT("AndroidEngine.ini->DefaultPlatformService = %s"), *AndroidPlatformService);
#endif //WITH_EDITOR
}

#if WITH_EDITOR
void UOnlinePicoSettings::SaveSettings()
{
    // Copy values to config files, using DefaultPlatformService value for both, to ensure they're always the same.
    GConfig->SetBool(TEXT("OnlineSubsystemPico"), TEXT("bEnabled"), bEnabled, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    if (bEnabled)
    {
        GConfig->SetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), *DefaultPlatformService, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
        GConfig->SetString(TEXT("OnlineSubsystem"), TEXT("DefaultPlatformService"), *AndroidPlatformService, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");
    }


    GConfig->Flush(false, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    GConfig->Flush(false, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

    UE_LOG(PicoSettings, Log, TEXT("Finished saving values to config files."));
}

bool UOnlinePicoSettings::ValidateSettings()
{
    if (bEnabled)
    {
        return true;
    }
    return false;
}

bool UOnlinePicoSettings::SaveWindowsDebugSetting()
{
    TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject());
    TSharedPtr<FJsonObject> GeneralObj = MakeShareable(new FJsonObject());
    FString RegionStr;
    if (RegionType == ERegionType::China)
    {
        RegionStr = TEXT("cn");
    }
    else
    {
        RegionStr = TEXT("i18n");
    }
    GeneralObj->SetStringField(TEXT("region"), RegionStr);
    RootObject->SetObjectField(TEXT("general"), GeneralObj);
    TSharedPtr<FJsonObject> AccountObj = MakeShareable(new FJsonObject());
    AccountObj->SetStringField(TEXT("access_token"), AccessToken);
    RootObject->SetObjectField(TEXT("account"), AccountObj);
    TSharedPtr<FJsonObject> PackageObj = MakeShareable(new FJsonObject());
    FString PackageName;
    FString PackageVersionName;
    int32 PackageVersionCode = 1;
    GConfig->GetString(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("PackageName"), PackageName, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    GConfig->GetString(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("VersionDisplayName"), PackageVersionName, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    GConfig->GetInt(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("StoreVersion"), PackageVersionCode, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    if (PackageName.IsEmpty())
    {
        PackageName = "com.company.default";
    }
    if (PackageVersionName.IsEmpty())
    {
        PackageVersionName = "1.0";
    }
    PackageObj->SetStringField(TEXT("package_name"), PackageName);
    PackageObj->SetStringField(TEXT("package_version_name"), PackageVersionName);
    PackageObj->SetNumberField(TEXT("package_version_code"), PackageVersionCode);
    RootObject->SetObjectField(TEXT("package"), PackageObj);
    FString BaseDir = IPluginManager::Get().FindPlugin("OnlineSubsystemPico")->GetBaseDir();
    FString ConfigFilePath = BaseDir + TEXT("/WindowsDebug/PicoWindowConfig.json");
    FString Json;
    TSharedRef<TJsonWriter<> > JsonWriter = TJsonWriterFactory<>::Create(&Json, 0);
    if (FJsonSerializer::Serialize(RootObject.ToSharedRef(), JsonWriter))
    {
        FFileHelper::SaveStringToFile(Json, *ConfigFilePath);
        return true;
    }
    return false;
}

void UOnlinePicoSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    GConfig->Flush(true, FPaths::ProjectDir() + "Config/DefaultEngine.ini");
    GConfig->Flush(true, FPaths::ProjectDir() + "Config/Android/AndroidEngine.ini");

    // Save updated settings to config files
    SaveSettings();
    SaveWindowsDebugSetting();
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif