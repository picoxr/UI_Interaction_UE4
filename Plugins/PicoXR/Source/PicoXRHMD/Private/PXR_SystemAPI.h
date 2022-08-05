//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PXR_HMD.h"
#include "PXR_SystemAPI.generated.h"

UENUM(BlueprintType)
enum class ESystemInfoEnum :uint8
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
	DEVICE_IP,
	CHARGING_STATUS
};

UENUM(BlueprintType)
enum class EDeviceControlEnum :uint8
{
	DEVICE_CONTROL_REBOOT   UMETA(DisplayName = "Device Reboot"),
	DEVICE_CONTROL_SHUTDOWN UMETA(DisplayName = "Device ShutDown")
};

UENUM(BlueprintType)
enum class EPackageControlEnum :uint8
{
	PACKAGE_SILENCE_INSTALL    UMETA(DisplayName = "Install Package"),
	PACKAGE_SILENCE_UNINSTALL  UMETA(DisplayName = "Uninstall Package")
};

UENUM(BlueprintType)
enum class ESwitchEnum :uint8
{
	S_ON   UMETA(DisplayName = "On"),
	S_OFF  UMETA(DisplayName = "Off")
};
UENUM(BlueprintType)
enum class EHomeEventEnum :uint8
{
	HOME_SINGLE_CLICK  UMETA(DisplayName = "Single Click"),
	HOME_DOUBLE_CLICK  UMETA(DisplayName = "Double Click")
};


UENUM(BlueprintType)
enum class EHomeFunctionEnum :uint8
{
	VALUE_HOME_GO_TO_SETTING  = 0 UMETA(DisplayName = "Open Setting"),
	VALUE_HOME_RECENTER       = 2 UMETA(DisplayName = "Recenter"),
	VALUE_HOME_DISABLE        = 4 UMETA(DisplayName = "Disable"),
	VALUE_HOME_GO_TO_HOME     = 5 UMETA(DisplayName = "Open Launcher")
};

UENUM(BlueprintType)
enum class EScreenOffDelayTimeEnum :uint8
{
	THREE          UMETA(DisplayName = "3 Seconds"),
	TEN            UMETA(DisplayName = "10 Seconds"),
	THIRTY         UMETA(DisplayName = "30 Seconds"),
	SIXTY          UMETA(DisplayName = "1 Minute"),
	THREE_HUNDRED  UMETA(DisplayName = "5 Minutes"),
	SIX_HUNDRED    UMETA(DisplayName = "10 Minutes"),
	NEVER          UMETA(DisplayName = "Never")
};

UENUM(BlueprintType)
enum class ESleepDelayTimeEnum :uint8
{
	FIFTEEN                        UMETA(DisplayName = "15 Seconds"),
	THIRTY                         UMETA(DisplayName = "30 Seconds"),
	SIXTY                          UMETA(DisplayName = "1 Minute"),
	THREE_HUNDRED                  UMETA(DisplayName = "5 Minutes"),
	SIX_HUNDRED                    UMETA(DisplayName = "10 Minutes"),
	ONE_THOUSAND_AND_EIGHT_HUNDRED UMETA(DisplayName = "30 Minutes"),
	NEVER                          UMETA(DisplayName = "Never")
};

UENUM(BlueprintType)
enum class ESystemFunctionSwitchEnum :uint8
{
	SFS_USB                        UMETA(DisplayName = "USB Debug"),
	SFS_AUTOSLEEP                  UMETA(DisplayName = "Auto Sleep"),
	SFS_SCREENON_CHARGING          UMETA(DisplayName = "ScreenOn Charging"),
	SFS_OTG_CHARGING               UMETA(DisplayName = "OTG Charging"),
	SFS_RETURN_MENU_IN_2DMODE      UMETA(DisplayName = "Show Back Menu in 2D mode"),
	SFS_COMBINATION_KEY            UMETA(DisplayName = "Combination Key"),
	SFS_CALIBRATION_WITH_POWER_ON  UMETA(DisplayName = "Calibration wiht power on"),
	SFS_SYSTEM_UPDATE              UMETA(DisplayName = "System Update"),
	SFS_CAST_SERVICE               UMETA(DisplayName = "Cast Service"),
	SFS_EYE_PROTECTION             UMETA(DisplayName = "Eye Protection"),
	SFS_SECURITY_ZONE_PERMANENTLY  UMETA(DisplayName = "Security Zone Permanently"),
	SFS_GLOBAL_CALIBRATION         UMETA(DisplayName = "Global Calibration"),
	SFS_Auto_Calibration           UMETA(DisplayName = "Auto Calibration"),
	SFS_USB_BOOT                   UMETA(DisplayName = "USB Boot"),
	SFS_SHORTCUT_SHOW_RECORD_UI    UMETA(DisplayName = "Show Record UI"), 
	SFS_SHORTCUT_SHOW_FIT_UI       UMETA(DisplayName = "Show Fit UI"),  
	SFS_SHORTCUT_SHOW_CAST_UI      UMETA(DisplayName = "Show Cast UI"), 
	SFS_SHORTCUT_SHOW_CAPTURE_UI   UMETA(DisplayName = "Show Capture UI"), 
	SFS_STOP_MEM_INFO_SERVICE      UMETA(DisplayName = "Stop Mem Infor Service"),  
	SFS_USB_FORCE_HOST             UMETA(DisplayName = "Usb Force Host")
};

UENUM(BlueprintType)
enum class EUSBConfigModeEnum :uint8
{
	MTP,
	CHARGE
};


USTRUCT(BlueprintType)
struct FWifiDisplayModel
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FString  deviceAddress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FString  deviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		bool isAvailable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		bool canConnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		bool isRemembered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		int statusCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FString status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FString description;

	FWifiDisplayModel()
		:deviceAddress("")
		, deviceName("")
		, isAvailable(false)
		, canConnect(false)
		, isRemembered(false)
		, statusCode(0)
		, status("")
		, description("")
	{
	}
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

DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetDeviceActionDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoAppManagerDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetAutoConnectWifiDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoClearAutoConnectWifiDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetHomeKeyDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetHomeKeyAllDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoDisablePowerKeyDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetScreenOffDelayDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoWriteConfigFileToDataLocalDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoResetAllKeyToDefaultDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetWDJsonDelegate, const FString, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSetWDModelsDelegate, const TArray<FWifiDisplayModel>&, Models);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoEnableLargeSpaceDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoSwitchLargeSpaceStatusDelegate, const FString, Result); 
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoExportMapsDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoImportMapsDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate, int32, Result);

UCLASS(ClassGroup = (PXRComponent), meta = (BlueprintSpawnableComponent))
class PICOXRHMD_API UPicoXRSystemAPI : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPicoXRSystemAPI();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		FString PXR_GetDeviceInfo(ESystemInfoEnum InfoEnum);

	static TMap<EDeviceControlEnum, FPicoSetDeviceActionDelegate> SetDeviceActionDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetDeviceAction(EDeviceControlEnum DeviceControlEnum, FPicoSetDeviceActionDelegate SetDeviceActionDelegate);

	static TMap<FAppManagerStruct, FPicoAppManagerDelegate> AppManagerDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext, FPicoAppManagerDelegate AppManagerDelegate);//Can not know how to design delegate

	static FPicoSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext, FPicoSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate);

	static FPicoClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ClearAutoConnectWifi(FPicoClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate);

	static TMap<EHomeEventEnum, FPicoSetHomeKeyDelegate> SetHomeKeyDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, FPicoSetHomeKeyDelegate SetHomeKeyDelegate);

	static TMap<EHomeEventEnum, FPicoSetHomeKeyAllDelegate> SetHomeKeyAllDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup, FString Package, FString ClassName, FPicoSetHomeKeyAllDelegate SetHomeKeyAllDelegate);

	static TMap<bool, FPicoDisablePowerKeyDelegate> DisablePowerKeyDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_DisablePowerKey(bool bIsSingleTap, bool bEnable, FPicoDisablePowerKeyDelegate DisablePowerKeyDelegate);

	static FPicoSetScreenOffDelayDelegate SetScreenOffDelayDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetSleepDelay(EScreenOffDelayTimeEnum TimeEnum, FPicoSetScreenOffDelayDelegate SetScreenOffDelayDelegate);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetScreenOffDelay(ESleepDelayTimeEnum TimeEnum);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	    void PXR_ScreenOn();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_ScreenOff();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_AcquireWakeLock();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_ReleaseWakeLock();

	static FPicoWriteConfigFileToDataLocalDelegate WriteConfigDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_WriteConfigFileToDataLocal(FString Path, FString Content, FPicoWriteConfigFileToDataLocalDelegate InWriteConfigDelegate);

	static FPicoResetAllKeyToDefaultDelegate ResetAllKeyDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_ResetAllKeyToDefault(FPicoResetAllKeyToDefaultDelegate InResetAllKeyDelegate);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_EnableEnterKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_DisableEnterKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_EnableVolumeKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_DisableVolumeKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_EnableBackKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		 void PXR_DisableBackKey();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		int32 PXR_GetCurrentBrightness();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetBrightness(int32 Brightness);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		int32 PXR_GetCurrentVolume();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		int32 PXR_GetMaxVolume();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetVolume(int32 Volume);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_VolumeUp();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_VolumeDown();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		FString PXR_GetDeviceSN();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_FreezeScreen(bool freeze);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_KillAppsByPidOrPackageName(TArray<int> pids, TArray<FString> packageNames, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_KillBackgroundAppsWithWhiteList(TArray<FString> packageNames, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_OpenMiracast();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		bool PXR_IsMiracastOn();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_CloseMiracast();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_StartScan();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_StopScan();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ConnectWifiDisplay(const FWifiDisplayModel& Model);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_DisConnectWifiDisplay();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ForgetWifiDisplay(FString Address);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_RenameWifiDisplay(FString Address, FString NewName);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_UpdateWifiDisplays();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_GetConnectedWD(FWifiDisplayModel& Model);

	static FPicoSetWDJsonDelegate SetWDJsonDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetWDJson(FPicoSetWDJsonDelegate InSetWDJsonDelegate);

	static FPicoSetWDModelsDelegate SetWDModelsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SetWDModels(FPicoSetWDModelsDelegate InSetWDModelsDelegate);

	static FPicoEnableLargeSpaceDelegate EnableLargeSpaceDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_SwitchLargeSpaceScene(FPicoEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext=0);

	static FPicoSwitchLargeSpaceStatusDelegate SwitchLargeSpaceStatusDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_GetSwitchLargeSpaceStatus(FPicoSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate,int ext=0);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		bool PXR_SaveLargeSpaceMaps(int ext=0);

	static FPicoExportMapsDelegate ExportMapsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ExportMaps(FPicoExportMapsDelegate InExportMapsDelegate, int ext = 0);

	static FPicoImportMapsDelegate ImportMapsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ImportMaps(FPicoImportMapsDelegate InImportMapsDelegate, int ext = 0);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_GetCpuUsages(TArray<float> &OutData);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_GetDeviceTemperatures(int inType, int inSource,TArray<float> &OutData);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_Capture();
	
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_Record();

	static FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate ControlSetAutoConnectWIFIWithErrorCodeDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_ControlSetAutoConnectWIFIWithErrorCode(FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate,FString ssid, FString pwd, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
		void PXR_AppKeepAlive(FString appPackageName, bool keepAlive, int ext);
};

