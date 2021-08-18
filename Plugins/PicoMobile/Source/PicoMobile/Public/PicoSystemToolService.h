// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PicoSystemToolService.generated.h"

UENUM(BlueprintType)
enum class ESystemInfoEnum  :uint8
{
	ELECTRIC_QUANTITY, 
    PUI_VERSION, 
    EQUIPMENT_MODEL, 
    EQUIPMENT_SN,    
    CUSTOMER_SN,
    INTERNAL_STORAGE_SPACE_OF_THE_DEVICE,
    DEVICE_BLUETOOTH_STATUS,
    BLUETOOTH_NAME_CONNECTED,
    BLUETOOTH_MAC_ADDRESS,
    DEVICE_WIFI_STATUS,
    WIFI_NAME_CONNECTED,
    WLAN_MAC_ADDRESS,
    DEVICE_IP
};

UENUM(BlueprintType)
enum class EDeviceControlEnum :uint8
{
	DEVICE_CONTROL_REBOOT UMETA(DisplayName = "Device Reboot"),
    DEVICE_CONTROL_SHUTDOWN UMETA(DisplayName = "Device ShutDown")
};

UENUM(BlueprintType)
enum class EPackageControlEnum :uint8
{
	PACKAGE_SILENCE_INSTALL  UMETA(DisplayName = "Install Package"),
    PACKAGE_SILENCE_UNINSTALL  UMETA(DisplayName = "Uninstall Package")
};

UENUM(BlueprintType)
enum class ESwitchEnum :uint8
{
	S_ON  UMETA(DisplayName = "On"),
    S_OFF  UMETA(DisplayName = "Off")
};
UENUM(BlueprintType)
enum class EHomeEventEnum :uint8
{
	HOME_SINGLE_CLICK UMETA(DisplayName = "Single Click"),
    HOME_DOUBLE_CLICK  UMETA(DisplayName = "Double Click"),
    HOMR_LONG_PRESS  UMETA(DisplayName = "Long Press")
};


UENUM(BlueprintType)
enum class EHomeFunctionEnum :uint8
{
	VALUE_HOME_GO_TO_SETTING UMETA(DisplayName = "Open Setting"),
    VALUE_HOME_BACK  UMETA(DisplayName = "Back"),
    VALUE_HOME_RECENTER  UMETA(DisplayName = "Recenter"),
    VALUE_HOME_OPEN_APP  UMETA(DisplayName = "Open APP"),
    VALUE_HOME_DISABLE   UMETA(DisplayName = "Disable"),
    VALUE_HOME_GO_TO_HOME  UMETA(DisplayName = "Open Launcher"),
    VALUE_HOME_SEND_BROADCAST  UMETA(DisplayName = "Send Broadcast"),
    VALUE_HOME_CLEAN_MEMORY UMETA(DisplayName = "Clear Memory")
};

UENUM(BlueprintType)
enum class EScreenOffDelayTimeEnum :uint8
{
	THREE UMETA(DisplayName = "3 Seconds"),
    TEN   UMETA(DisplayName = "10 Seconds"),
    THIRTY  UMETA(DisplayName = "30 Seconds"),
    SIXTY  UMETA(DisplayName = "1 Minute"),
    THREE_HUNDRED  UMETA(DisplayName = "5 Minutes"),
    SIX_HUNDRED  UMETA(DisplayName = "10 Minutes"),
    NEVER UMETA(DisplayName = "Never")
};


UENUM(BlueprintType)
enum class ESleepDelayTimeEnum :uint8
{
	FIFTEEN  UMETA(DisplayName = "15 Seconds"),
    THIRTY UMETA(DisplayName = "30 Seconds"),
    SIXTY  UMETA(DisplayName = "1 Minute"),
    THREE_HUNDRED  UMETA(DisplayName = "5 Minutes"),
    SIX_HUNDRED  UMETA(DisplayName = "10 Minutes"),
    ONE_THOUSAND_AND_EIGHT_HUNDRED  UMETA(DisplayName = "30 Minutes"),
    NEVER UMETA(DisplayName = "Never")
};


UENUM(BlueprintType)
enum class ESystemFunctionSwitchEnum :uint8
{
	SFS_USB  UMETA(DisplayName = "USB Debug"),
    SFS_AUTOSLEEP  UMETA(DisplayName = "Auto Sleep"),
    SFS_SCREENON_CHARGING  UMETA(DisplayName = "ScreenOn Charging"),
    SFS_OTG_CHARGING  UMETA(DisplayName = "OTG Charging"),
    SFS_RETURN_MENU_IN_2DMODE  UMETA(DisplayName = "Show Back Menu in 2D mode"),
    SFS_COMBINATION_KEY  UMETA(DisplayName = "Combination Key"),
    SFS_CALIBRATION_WITH_POWER_ON  UMETA(DisplayName = "Calibration wiht power on"),
    SFS_SYSTEM_UPDATE  UMETA(DisplayName = "System Update"),
    SFS_CAST_SERVICE  UMETA(DisplayName = "Cast Service"),
    SFS_EYE_PROTECTION  UMETA(DisplayName = "Eye Protection"),
    SFS_SECURITY_ZONE_PERMANENTLY  UMETA(DisplayName = "Security Zone Permanently"),
    SFS_GLOBAL_CALIBRATION  UMETA(DisplayName = "Global Calibration"),
    SFS_Auto_Calibration  UMETA(DisplayName = "Auto Calibration"),
    SFS_USB_BOOT  UMETA(DisplayName = "USB Boot"),
};

UENUM(BlueprintType)
enum class EUSBConfigModeEnum :uint8
{
	MTP,
    CHARGE
};


USTRUCT()
struct FAppManagerStruct
{
	GENERATED_BODY()
	EPackageControlEnum PackageControl;
	FString AppPath;

	FORCEINLINE friend bool operator==(const FAppManagerStruct& Lhs, const FAppManagerStruct& Rhs)
	{
		return (Lhs.PackageControl == Rhs.PackageControl) && (Lhs.AppPath == Rhs.AppPath);
	}
};

FORCEINLINE uint32 GetTypeHash(const FAppManagerStruct& Key)
{
	return HashCombine(GetTypeHash(Key.PackageControl), GetTypeHash(Key.AppPath));
}
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetDeviceActionDelegate, int32,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoAppManagerDelegate,int32,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetAutoConnectWifiDelegate, bool,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoClearAutoConnectWifiDelegate, bool,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetHomeKeyDelegate,bool,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetHomeKeyAllDelegate,bool,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoDisablePowerKeyDelegate,int32,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetScreenOffDelayDelegate,int32,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoWriteConfigFileToDataLocalDelegate,bool,Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoResetAllKeyToDefaultDelegate,bool,Result);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PICOMOBILE_API UPicoSystemToolService : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPicoSystemToolService();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	FString GetDeviceInfo(ESystemInfoEnum InfoEnum);

	static TMap<EDeviceControlEnum,FPicoSetDeviceActionDelegate> SetDeviceActionDelegates;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetDeviceAction(EDeviceControlEnum DeviceControlEnum,FPicoSetDeviceActionDelegate SetDeviceActionDelegate);

	static TMap<FAppManagerStruct,FPicoAppManagerDelegate> AppManagerDelegates;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void AppManager(EPackageControlEnum PackageControlEnum,FString Path,int32 Ext,FPicoAppManagerDelegate AppManagerDelegate);//Can not know how to design delegate

	static FPicoSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext,FPicoSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate);

	static FPicoClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void ClearAutoConnectWifi(FPicoClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate);

	static TMap<EHomeEventEnum,FPicoSetHomeKeyDelegate> SetHomeKeyDelegates;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum,FPicoSetHomeKeyDelegate SetHomeKeyDelegate);

	static TMap<EHomeEventEnum,FPicoSetHomeKeyAllDelegate> SetHomeKeyAllDelegates;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup, FString Package, FString ClassName,FPicoSetHomeKeyAllDelegate SetHomeKeyAllDelegate);

	static TMap<bool,FPicoDisablePowerKeyDelegate> DisablePowerKeyDelegates;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void DisablePowerKey(bool bIsSingleTap, bool bEnable,FPicoDisablePowerKeyDelegate DisablePowerKeyDelegate);

	static FPicoSetScreenOffDelayDelegate SetScreenOffDelayDelegate;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
    void SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum,FPicoSetScreenOffDelayDelegate SetScreenOffDelayDelegate);
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetSleepDelay(ESleepDelayTimeEnum TimeEnum);

	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext);
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	void SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext);

	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void ScreenOn();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void ScreenOff();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void AcquireWakeLock();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void ReleaseWakeLock();

	static FPicoWriteConfigFileToDataLocalDelegate WriteConfigDelegate;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void WriteConfigFileToDataLocal(FString Path, FString Content,FPicoWriteConfigFileToDataLocalDelegate InWriteConfigDelegate);

	static FPicoResetAllKeyToDefaultDelegate ResetAllKeyDelegate;
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void ResetAllKeyToDefault(FPicoResetAllKeyToDefaultDelegate InResetAllKeyDelegate);
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void EnableEnterKey();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void DisableEnterKey();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void EnableVolumeKey();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void DisableVolumeKey();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void EnableBackKey();
	
	UFUNCTION(BlueprintCallable,Category="PicoSystemAPI")
	static void DisableBackKey();
};

