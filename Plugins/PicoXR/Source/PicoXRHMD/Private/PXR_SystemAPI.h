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
	HOME_SINGLE_CLICK,
	HOME_DOUBLE_CLICK,
	HOME_LONG_PRESS,
	HOME_SINGLE_CLICK_RIGHT_CTL,
	HOME_DOUBLE_CLICK_RIGHT_CTL,
	HOME_LONG_PRESS_RIGHT_CTL,
	HOME_SINGLE_CLICK_LEFT_CTL,
	HOME_DOUBLE_CLICK_LEFT_CTL,
	HOME_LONG_PRESS_LEFT_CTL,
	HOME_SINGLE_CLICK_HMD,
	HOME_DOUBLE_CLICK_HMD,
	HOME_LONG_PRESS_HMD
};

UENUM(BlueprintType)
enum class EHomeFunctionEnum :uint8
{
	VALUE_HOME_GO_TO_SETTING     UMETA(DisplayName = "Open Setting"),
	VALUE_HOME_BACK              UMETA(DisplayName = "Back"),
	VALUE_HOME_RECENTER          UMETA(DisplayName = "Recenter"),
	VALUE_HOME_OPEN_APP          UMETA(DisplayName = "Open App"),
	VALUE_HOME_DISABLE           UMETA(DisplayName = "Disable"),
	VALUE_HOME_GO_TO_HOME        UMETA(DisplayName = "Go to Home"),
	VALUE_HOME_SEND_BROADCAST    UMETA(DisplayName = "Send Broadcast"),
	VALUE_HOME_CLEAN_MEMORY      UMETA(DisplayName = "Clean Memory"),
	VALUE_HOME_QUICK_SETTING     UMETA(DisplayName = "Quick Setting"),
	VALUE_HOME_SCREEN_CAP        UMETA(DisplayName = "Screen Cap"),
	VALUE_HOME_SCREEN_RECORD     UMETA(DisplayName = "Screen Record")

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
	SFS_USB                          UMETA(DisplayName = "USB Debug"),
	SFS_AUTOSLEEP                    UMETA(DisplayName = "Auto Sleep"),
	SFS_SCREENON_CHARGING            UMETA(DisplayName = "ScreenOn Charging"),
	SFS_OTG_CHARGING                 UMETA(DisplayName = "OTG Charging"),
	SFS_RETURN_MENU_IN_2DMODE        UMETA(DisplayName = "Show Back Menu in 2D mode"),
	SFS_COMBINATION_KEY              UMETA(DisplayName = "Combination Key"),
	SFS_CALIBRATION_WITH_POWER_ON    UMETA(DisplayName = "Calibration wiht power on"),
	SFS_SYSTEM_UPDATE                UMETA(DisplayName = "System Update"),
	SFS_CAST_SERVICE                 UMETA(DisplayName = "Cast Service"),
	SFS_EYE_PROTECTION               UMETA(DisplayName = "Eye Protection"),
	SFS_SECURITY_ZONE_PERMANENTLY    UMETA(DisplayName = "Security Zone Permanently"),
	SFS_GLOBAL_CALIBRATION           UMETA(DisplayName = "Global Calibration"),
	SFS_Auto_Calibration             UMETA(DisplayName = "Auto Calibration"),
	SFS_USB_BOOT                     UMETA(DisplayName = "USB Boot"),
	SFS_VOLUME_UI                    UMETA(DisplayName = "Volume Global UI Prompt Switch"),
	SFS_CONTROLLER_UI                UMETA(DisplayName = "Controller Connection Global UI Prompt switch"),
	SFS_NAVGATION_SWITCH             UMETA(DisplayName = "Open/Close the Navigation"),
	SFS_SHORTCUT_SHOW_RECORD_UI      UMETA(DisplayName = "Show Record UI"),
	SFS_SHORTCUT_SHOW_FIT_UI         UMETA(DisplayName = "Show Fit UI"),
	SFS_SHORTCUT_SHOW_CAST_UI        UMETA(DisplayName = "Show Cast UI"),
	SFS_SHORTCUT_SHOW_CAPTURE_UI     UMETA(DisplayName = "Show Capture UI"),
	SFS_STOP_MEM_INFO_SERVICE        UMETA(DisplayName = "Stop Mem Infor Service"),
	SFS_START_APP_BOOT_COMPLETED     UMETA(DisplayName = "Start App Boot Completed"),
	SFS_USB_FORCE_HOST               UMETA(DisplayName = "Usb Force Host"),
	SFS_SET_DEFAULT_SAFETY_ZONE      UMETA(DisplayName = "Set Default Safety Zone"),
	SFS_ALLOW_RESET_BOUNDARY         UMETA(DisplayName = "Allow Reset Boundary"),
	SFS_BOUNDARY_CONFIRMATION_SCREEN UMETA(DisplayName = "Boundary Confirmation Screen"),
	SFS_LONG_PRESS_HOME_TO_RECENTER  UMETA(DisplayName = "Long Press Home To Recenter"),
	SFS_POWER_CTRL_WIFI_ENABLE       UMETA(DisplayName = "Power Ctrl Wifi Enable"),
	SFS_WIFI_DISABLE                 UMETA(DisplayName = "Wifi Disable"),
	SFS_SIX_DOF_SWITCH               UMETA(DisplayName = "Six Dof Switch"),
	SFS_INVERSE_DISPERSION           UMETA(DisplayName = "Inverse Dispersion")
};

UENUM(BlueprintType)
enum class EUSBConfigModeEnum :uint8
{
	MTP,
	CHARGE
};

UENUM(BlueprintType)
enum class EInstallOTAReturnCode : uint8
{
	SUCCESS = 0,
	FAIL = 1,

	LOWVERSIONOFOTA = 21
};

UENUM(BlueprintType)
enum class ECastReturnCode : uint8
{
	FAIL = 0,
	SUCCESS = 1,
};

UENUM(BlueprintType)
enum class ECastInitResult : uint8
{
	DISCONNECT = 0,
	CONNECT = 1,
	NO_MIC_PERMISSION = 2
};

UENUM(BlueprintType)
enum class EPICOCastAuthorization : uint8
{
	ASK_EVERY_TIME = 0,
	ALWAYS_ALLOW = 1,
	NOT_ACCEPTED = 2
};

UENUM(BlueprintType)
enum class EPICOCastOptionOrStatusEnum : uint8
{
	OPTION_RESOLUTION_LEVEL = 0     UMETA(DisplayName = "Resolution"),
	OPTION_BITRATE_LEVEL = 1        UMETA(DisplayName = "Bit Rate"),
	OPTION_AUDIO_ENABLE = 2         UMETA(DisplayName = "Audio Enable"),

	PICO_CAST_STATUS = 3            UMETA(DisplayName = "Cast Status"),
};

UENUM(BlueprintType)
enum class EPICOCastOptionValueEnum : uint8
{
	OPTION_VALUE_RESOLUTION_HIGH,
	OPTION_VALUE_RESOLUTION_MIDDLE,
	OPTION_VALUE_RESOLUTION_AUTO,
	OPTION_VALUE_RESOLUTION_HIGH_2K,
	OPTION_VALUE_RESOLUTION_HIGH_4K,
	OPTION_VALUE_BITRATE_HIGH,
	OPTION_VALUE_BITRATE_MIDDLE,
	OPTION_VALUE_BITRATE_LOW,
	OPTION_VALUE_AUDIO_ON,
	OPTION_VALUE_AUDIO_OFF,
	STATUS_VALUE_STATE_STARTED,
	STATUS_VALUE_STATE_STOPPED,
	STATUS_VALUE_ERROR
};

UENUM(BlueprintType)
enum class EPICOCastUrlTypeEnum : uint8
{
	NORMAL_URL        UMETA(ToolTip = "If the authorization window is not set, the authorization window will pop up."),
	NO_CONFIRM_URL    UMETA(ToolTip = "A confirmation window will not pop up on the browser side. After entering the address, the screen will start directly."),
	RTMP_URL          UMETA(ToolTip = "Return the rtmp live stream address -- the all-in-one computer will not pop up the authorization window.")
};

UENUM(BlueprintType)
enum class EKeyState : uint8
{
	DISABLE = 0,
	ENABLE = 1
};

UENUM(BlueprintType)
enum class EControllerKeyEnum : uint8
{
	CONTROLLER_KEY_JOYSTICK,
	CONTROLLER_KEY_MENU,
	CONTROLLER_KEY_TRIGGER,
	CONTROLLER_KEY_RIGHT_A,
	CONTROLLER_KEY_RIGHT_B,
	CONTROLLER_KEY_LEFT_X,
	CONTROLLER_KEY_LEFT_Y,
	CONTROLLER_KEY_LEFT_GRIP,
	CONTROLLER_KEY_RIGHT_GRIP
};

UENUM(BlueprintType)
enum class EControllerPairTimeEnum : uint8
{
	DEFAULT                    UMETA(DisplayName = "Default"),
	FIFTEEN                    UMETA(DisplayName = "15 Seconds"),
	SIXTY                      UMETA(DisplayName = "60 Seconds"),
	ONE_HUNDRED_AND_TWENTY     UMETA(DisplayName = "2 Minutes"),
	SIX_HUNDRED                UMETA(DisplayName = "10 Minutes"),
	NEVER                      UMETA(DisplayName = "Never")
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

DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetDeviceActionDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOAppManagerDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetAutoConnectWifiDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOClearAutoConnectWifiDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetHomeKeyDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetHomeKeyAllDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICODisablePowerKeyDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetScreenOffDelayDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOWriteConfigFileToDataLocalDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOResetAllKeyToDefaultDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetWDJsonDelegate, const FString, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetWDModelsDelegate, const TArray<FWifiDisplayModel>&, Models);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOEnableLargeSpaceDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSwitchLargeSpaceStatusDelegate, const FString, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOExportMapsDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOImportMapsDelegate, bool, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOGetSwitchSystemFunctionStatusDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOCastInitDelegate, ECastInitResult, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetControllerPairTimeDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOGetControllerPairTimeDelegate, EControllerPairTimeEnum, Result);

UCLASS(ClassGroup = (PXRComponent), meta = (BlueprintSpawnableComponent))
class PICOXRHMD_API UPICOXRSystemAPI : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPICOXRSystemAPI();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetDeviceInfo(ESystemInfoEnum InfoEnum);

	static TMap<EDeviceControlEnum, FPICOSetDeviceActionDelegate> SetDeviceActionDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetDeviceAction(EDeviceControlEnum DeviceControlEnum, FPICOSetDeviceActionDelegate SetDeviceActionDelegate);

	static TMap<FAppManagerStruct, FPICOAppManagerDelegate> AppManagerDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext, FPICOAppManagerDelegate AppManagerDelegate);//Can not know how to design delegate

	static FPICOSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext, FPICOSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate);

	static FPICOClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_ClearAutoConnectWifi(FPICOClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate);

	static TMap<EHomeEventEnum, FPICOSetHomeKeyDelegate> SetHomeKeyDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, FPICOSetHomeKeyDelegate SetHomeKeyDelegate);

	static TMap<EHomeEventEnum, FPICOSetHomeKeyAllDelegate> SetHomeKeyAllDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup, FString Package, FString ClassName, FPICOSetHomeKeyAllDelegate SetHomeKeyAllDelegate);

	static TMap<bool, FPICODisablePowerKeyDelegate> DisablePowerKeyDelegates;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_DisablePowerKey(bool bIsSingleTap, bool bEnable, FPICODisablePowerKeyDelegate DisablePowerKeyDelegate);

	static FPICOSetScreenOffDelayDelegate SetScreenOffDelayDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetSleepDelay(ESleepDelayTimeEnum TimeEnum);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum,FPICOSetScreenOffDelayDelegate SetScreenOffDelayDelegate);

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

	static FPICOWriteConfigFileToDataLocalDelegate WriteConfigDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_WriteConfigFileToDataLocal(FString Path, FString Content, FPICOWriteConfigFileToDataLocalDelegate InWriteConfigDelegate);

	static FPICOResetAllKeyToDefaultDelegate ResetAllKeyDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_ResetAllKeyToDefault(FPICOResetAllKeyToDefaultDelegate InResetAllKeyDelegate);

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

	static FPICOSetWDJsonDelegate SetWDJsonDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetWDJson(FPICOSetWDJsonDelegate InSetWDJsonDelegate);

	static FPICOSetWDModelsDelegate SetWDModelsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetWDModels(FPICOSetWDModelsDelegate InSetWDModelsDelegate);

	static FPICOEnableLargeSpaceDelegate EnableLargeSpaceDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SwitchLargeSpaceScene(FPICOEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext=0);

	static FPICOSwitchLargeSpaceStatusDelegate SwitchLargeSpaceStatusDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_GetSwitchLargeSpaceStatus(FPICOSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate,int ext=0);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	bool PXR_SaveLargeSpaceMaps(int ext=0);

	static FPICOExportMapsDelegate ExportMapsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_ExportMaps(FPICOExportMapsDelegate InExportMapsDelegate, int ext = 0);

	static FPICOImportMapsDelegate ImportMapsDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_ImportMaps(FPICOImportMapsDelegate InImportMapsDelegate, int ext = 0);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_GetCpuUsages(TArray<float> &OutData);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_GetDeviceTemperatures(int inType, int inSource,TArray<float> &OutData);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_Capture();
	
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_Record();

	static FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate ControlSetAutoConnectWIFIWithErrorCodeDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_ControlSetAutoConnectWIFIWithErrorCode(FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate,FString ssid, FString pwd, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_AppKeepAlive(FString appPackageName, bool keepAlive, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_TimingStartup(int year, int month, int day, int hour, int minute, bool open);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_TimingShutdown(int year, int month, int day, int hour, int minute, bool open);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_StartVrSettingsItem(int vrSettingsEnum, bool hideOtherItem, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SwitchVolumeToHomeAndEnter(ESwitchEnum switchEnum, int ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ESwitchEnum PXR_IsVolumeChangeToHomeAndEnter();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EInstallOTAReturnCode PXR_InstallOTAPackage(const FString& OtaPackagePath, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetAutoConnectWiFiConfig(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetTimingStartupStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetTimingShutdownStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EKeyState PXR_GetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ESwitchEnum PXR_GetPowerOffWithUSBCable(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EScreenOffDelayTimeEnum PXR_GetScreenOffDelay(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ESleepDelayTimeEnum PXR_GetSleepDelay(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetPowerKeyStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EKeyState PXR_GetEnterKeyStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EKeyState PXR_GetVolumeKeyStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EKeyState PXR_GetBackKeyStatus(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetHomeKeyStatus(EHomeEventEnum HomeEventEnum, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetUsbConfigurationOption(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_GetCurrentLauncher(int32 Ext);

	static FPICOGetSwitchSystemFunctionStatusDelegate GetSwitchSystemFunctionStatusDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_GetSwitchSystemFunctionStatus(FPICOGetSwitchSystemFunctionStatusDelegate InGetSwitchSystemFunctionStatusDelegate, ESystemFunctionSwitchEnum SystemFunctionSwitchEnum, int32 Ext);
	
	static FPICOCastInitDelegate PICOCastInitDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ECastReturnCode PXR_PICOCastInit(FPICOCastInitDelegate InPICOCastInitDelegate, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ECastReturnCode PXR_PICOCastSetShowAuthorization(EPICOCastAuthorization Authorization, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EPICOCastAuthorization PXR_PICOCastGetShowAuthorization(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	FString PXR_PICOCastGetUrl(EPICOCastUrlTypeEnum UrlType, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ECastReturnCode PXR_PICOCastStopCast(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	ECastReturnCode PXR_PICOCastSetOption(EPICOCastOptionOrStatusEnum OptionEnum, EPICOCastOptionValueEnum ValueEnum, int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	EPICOCastOptionValueEnum PXR_PICOCastGetOptionOrStatus(EPICOCastOptionOrStatusEnum OptionEnum, int32 Ext);

	static FPICOSetControllerPairTimeDelegate SetControllerPairTimeDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_SetControllerPairTime(FPICOSetControllerPairTimeDelegate InSetControllerPairTimeDelegate, EControllerPairTimeEnum TimeEnum, int32 Ext);

	static FPICOGetControllerPairTimeDelegate GetControllerPairTimeDelegate;
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRSystemAPI")
	void PXR_GetControllerPairTime(FPICOGetControllerPairTimeDelegate InGetControllerPairTimeDelegate, int32 Ext);
};

