// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "Engine/TextureRenderTarget2D.h"
#if PLATFORM_ANDROID
#include <jni.h>
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif
#include "PICO_EnterpriseFunctionLibrary.generated.h"

/// @file PICO_EnterpriseFunctionLibrary.h

/// @cond

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
	CHARGING_STATUS,
	DEVICE_KEY,
	//设备本身蓝牙信息
	//返回值格式：Name|Address
	//返回值示例：PICO 4|08:16:D5:70:20:11
	BLUETOOTH_INFO_DEVICE,
	//已连接的蓝牙设备信息
	//返回值格式：[蓝牙设备1名称|蓝牙设备1地址, 蓝牙设备2名称|蓝牙设备2地址, . . .]
	//返回值示例：[PICO 4|08:16:D5:70:20:11, PICO Neo 3|21:23:D5:7A:2C:DE]
	BLUETOOTH_INFO_CONNECTED,
	//相机温度单位摄氏度
	CAMERA_TEMPERATURE_CELSIUS,
	//相机温度单位华氏度
	CAMERA_TEMPERATURE_FAHRENHEIT,
	LARGESPACE_MAP_INFO //大空间地图信息
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
	SFS_USB											UMETA(DisplayName = "USB Debug"),
	SFS_AUTOSLEEP									UMETA(DisplayName = "Auto Sleep"),
	SFS_SCREENON_CHARGING							UMETA(DisplayName = "ScreenOn Charging"),
	SFS_OTG_CHARGING								UMETA(DisplayName = "OTG Charging"),
	SFS_RETURN_MENU_IN_2DMODE						UMETA(DisplayName = "Show Back Menu in 2D mode"),
	SFS_COMBINATION_KEY								UMETA(DisplayName = "Combination Key"),
	SFS_CALIBRATION_WITH_POWER_ON					UMETA(DisplayName = "Calibration wiht power on"),
	SFS_SYSTEM_UPDATE								UMETA(DisplayName = "System Update"),
	SFS_CAST_SERVICE								UMETA(DisplayName = "Cast Service"),
	SFS_EYE_PROTECTION								UMETA(DisplayName = "Eye Protection"),
	SFS_SECURITY_ZONE_PERMANENTLY					UMETA(DisplayName = "Security Zone Permanently"),
	SFS_GLOBAL_CALIBRATION							UMETA(DisplayName = "Global Calibration"),
	SFS_Auto_Calibration							UMETA(DisplayName = "Auto Calibration"),
	SFS_USB_BOOT									UMETA(DisplayName = "USB Boot"),
	SFS_VOLUME_UI									UMETA(DisplayName = "Volume Global UI Prompt Switch"),
	SFS_CONTROLLER_UI								UMETA(DisplayName = "Controller Connection Global UI Prompt switch"),
	SFS_NAVGATION_SWITCH							UMETA(DisplayName = "Open/Close the Navigation"),
	SFS_SHORTCUT_SHOW_RECORD_UI						UMETA(DisplayName = "Show Record UI"),
	SFS_SHORTCUT_SHOW_FIT_UI						UMETA(DisplayName = "Show Fit UI"),
	SFS_SHORTCUT_SHOW_CAST_UI						UMETA(DisplayName = "Show Cast UI"),
	SFS_SHORTCUT_SHOW_CAPTURE_UI					UMETA(DisplayName = "Show Capture UI"),
	SFS_STOP_MEM_INFO_SERVICE						UMETA(DisplayName = "Stop Mem Infor Service"),
	SFS_START_APP_BOOT_COMPLETED					UMETA(DisplayName = "Start App Boot Completed"),
	SFS_USB_FORCE_HOST								UMETA(DisplayName = "Usb Force Host"),
	SFS_SET_DEFAULT_SAFETY_ZONE						UMETA(DisplayName = "Set Default Safety Zone"),
	SFS_ALLOW_RESET_BOUNDARY						UMETA(DisplayName = "Allow Reset Boundary"),
	SFS_BOUNDARY_CONFIRMATION_SCREEN				UMETA(DisplayName = "Boundary Confirmation Screen"),
	SFS_LONG_PRESS_HOME_TO_RECENTER					UMETA(DisplayName = "Long Press Home To Recenter"),
	SFS_POWER_CTRL_WIFI_ENABLE						UMETA(DisplayName = "Power Ctrl Wifi Enable"),
	SFS_WIFI_DISABLE								UMETA(DisplayName = "Wifi Disable"),
	SFS_SIX_DOF_SWITCH								UMETA(DisplayName = "Six Dof Switch"),
	SFS_INVERSE_DISPERSION							UMETA(DisplayName = "Inverse Dispersion"),
	SFS_LOGCAT										UMETA(DisplayName = "Logcat"),
	SFS_PSENSOR										UMETA(DisplayName = "PSensor"),
	SFS_SYSTEM_UPDATE_OTA							UMETA(DisplayName = "System Update OTA"),
	SFS_SYSTEM_UPDATE_APP							UMETA(DisplayName = "System Update App"),
	SFS_SHORTCUT_SHOW_WLAN_UI						UMETA(DisplayName = "Shortcut Show Wlan UI"),
	SFS_SHORTCUT_SHOW_BOUNDARY_UI					UMETA(DisplayName = "Shortcut Show Boundary UI"),
	SFS_SHORTCUT_SHOW_BLUETOOTH_UI					UMETA(DisplayName = "Shortcut Show Bluetooth UI"),
	SFS_SHORTCUT_SHOW_CLEAN_TASK_UI					UMETA(DisplayName = "Shortcut Show Clean Task UI"),
	SFS_SHORTCUT_SHOW_IPD_ADJUSTMENT_UI				UMETA(DisplayName = "Shortcut Show IPD Adjustment UI"),
	SFS_SHORTCUT_SHOW_POWER_UI						UMETA(DisplayName = "Shortcut Show Power UI"),
	SFS_SHORTCUT_SHOW_EDIT_UI						UMETA(DisplayName = "Shortcut Show Edit UI"),
	SFS_BASIC_SETTING_APP_LIBRARY_UI				UMETA(DisplayName = "Basic Setting App Library UI"),
	SFS_BASIC_SETTING_SHORTCUT_UI					UMETA(DisplayName = "Basic Setting Shortcut UI"),
	SFS_LED_FLASHING_WHEN_SCREEN_OFF				UMETA(DisplayName = "LED Flashing When Screen Off"),
	SFS_BASIC_SETTING_CUSTOMIZE_SETTING_UI			UMETA(DisplayName = "Basic Setting Customize Setting UI"),
	SFS_BASIC_SETTING_SHOW_APP_QUIT_CONFIRM_DIALOG  UMETA(DisplayName = "Basic Setting Show App Quit Confirm Dialog"),
	SFS_BASIC_SETTING_KILL_BACKGROUND_VR_APP		UMETA(DisplayName = "Basic Setting Kill Background VR App"),
	SFS_BASIC_SETTING_SHOW_CAST_NOTIFICATION		UMETA(DisplayName = "Basic Setting Show Cast Notification"),
	SFS_AUTOMATIC_IPD								UMETA(DisplayName = "Automatic IPD"),
	SFS_QUICK_SEETHROUGH_MODE						UMETA(DisplayName = "Quick Seethrough Mode"),
	SFS_HIGN_REFERSH_MODE							UMETA(DisplayName = "High Refersh Mode"),
	SFS_SEETHROUGH_APP_KEEP_RUNNING					UMETA(DisplayName = "SeeThrough App Keep Running"),
	SFS_OUTDOOR_TRACKING_ENHANCEMENT				UMETA(DisplayName = "Outdoor Tracking Enhancement"),
	SFS_AUTOIPD_AUTO_COMFIRM						UMETA(DisplayName = "AutoIPD Auto Comfirm"),
	SFS_LAUNCH_AUTOIPD_IF_GLASSES_WEARED			UMETA(DisplayName = "Launch AutoIPD if Glasses Weared"),
	SFS_GESTURE_RECOGNITION_HOME_ENABLE				UMETA(DisplayName = "Gesture Recognition Home Enable"),
	SFS_GESTURE_RECOGNITION_RESET_ENABLE			UMETA(DisplayName = "Gesture Recognition Reset Enable"),
	SFS_AUTO_COPY_FILES_FROM_USB_DEVICE				UMETA(DisplayName = "Auto Copy Files from USB Device"),
	//60~63
	SFS_WIFI_P2P_AUTO_CONNECT						UMETA(DisplayName = "Wifi P2P auto connect"),
	SFS_LOCK_SCREEN_FILE_COPY_ENABLE				UMETA(DisplayName = "Lock screen file copy enable"),
	SFS_TRACKING_ENABLE_DYNAMIC_MARKER				UMETA(DisplayName = "Tracking enable dynamic marker"),
	SFS_ENABLE_3DOF_CONTROLLER_TRACKING				UMETA(DisplayName = "Enable 3dof controller tracking"),
	//64~75
	SFS_SYSTEM_VIBRATION_ENABLED,
	SFS_BLUE_TOOTH,
	SFS_ENHANCED_VIDEO_QUALITY,
	SFS_GESTURE_RECOGNITION,
	SFS_BRIGHTNESS_AUTO_ADJUST,
	SFS_HIGH_CURRENT_OTG_MODE,
	SFS_BACKGROUND_APP_PLAY_AUDIO,
	SFS_NO_DISTURB_MODE,
	SFS_MONOCULAR_SCREENCAST,
	SFS_MONOCULAR_SCREEN_CAPTURE,
	SFS_STABILIZATION_FOR_RECORDING,
	SFS_HIDE_2D_APP_WHEN_GO_TO_HOME,
	//76~87
	SFS_CONTROLLER_VIBRATE,
	SFS_REFRESH_MODE,
	SFS_SMART_AUDIO,
	SFS_EYE_TRACK,
	SFS_FACE_SIMULATE,
	SFS_ENABLE_MIC_WHEN_RECORD,
	SFS_KEEP_RECORD_WHEN_SCREEN_OFF,
	SFS_CONTROLLER_TIP_VIBRATE,
	SFS_CONTROLLER_SEE_THROUGH,
	SFS_LOW_BORDER_HEIGHT,
	SFS_FAST_MOVE_TIP,
	SFS_WIRELESS_USB_ADB,

	//88~81
	//系统自动更新
	SFS_SYSTEM_AUTO_UPDATE,
	//usb共享网络开关
	SFS_USB_TETHERING,
	/**
	 * VR应用中实时响应头戴返回键
	 * 开关打开：头戴返回键按下发出DOWN事件，抬起发出UP事件
	 * 开关关闭：头戴返回键按下不发出DOWN事件，抬起同时发出DOWN/UP事件
	 */
	SFS_REAL_TIME_RESPONSE_HMD_BACK_KEY_IN_VR_APP,
	//优先使用Marker点找回地图
	SFS_RETRIEVE_MAP_BY_MARKER_FIRST
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

UENUM(BlueprintType)
enum class ESkipInitSetting : uint8
{
	INIT_SETTING_NONE = 0,
	INIT_SETTING_HANDLE_CONNECTION_TEACHING = 1,
	INIT_SETTING_TRIGGER_KEY_TEACHING = 2,
	INIT_SETTING_SELECT_LANGUAGE = 4,
	INIT_SETTING_SELECT_COUNTRY = 8,
	INIT_SETTING_WIFI_SETTING = 16,
	INIT_SETTING_QUICK_SETTING = 32
};

UENUM(BlueprintType)
enum class EScreencastAudioOutput : uint8
{
	AUDIO_SINK = 0,
	AUDIO_TARGET = 1,
	AUDIO_SINK_TARGET = 2
};

UENUM(BlueprintType)
enum class ECustomizeSettingsTab : uint8
{
	CUSTOMIZE_SETTINGS_TAB_WLAN = 0,
	CUSTOMIZE_SETTINGS_TAB_CONTROLLER = 1,
	CUSTOMIZE_SETTINGS_TAB_BLUETOOTH = 2,
	CUSTOMIZE_SETTINGS_TAB_DISPLAY = 3,
	CUSTOMIZE_SETTINGS_TAB_LAB = 4,
	CUSTOMIZE_SETTINGS_TAB_GENERAL_LOCKSCREEN = 5,
	CUSTOMIZE_SETTINGS_TAB_GENERAL_FACTORY_RESET = 6
};

UENUM(BlueprintType)
enum class EPoseErrorType : uint8
{
	BRIGHT_LIGHT_ERROR = 0,
	LOW_LIGHT_ERROR = 1,
	LOW_FEATURE_COUNT_ERROR = 2,
	CAMERA_CALIBRATION_ERROR = 3,
	RELOCATION_IN_PROGRESS = 4,
	INITILIZATION_IN_PROGRESS = 5,
	NO_CAMERA_ERROR = 6,
	NO_IMU_ERROR = 7,
	IMU_JITTER_ERROR = 8,
	UNKNOWN_ERROR = 9
};

USTRUCT(BlueprintType)
struct FWifiDisplayModel
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString  deviceAddress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString  deviceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	bool isAvailable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	bool canConnect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	bool isRemembered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int statusCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
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

USTRUCT(BlueprintType)
struct FCastMediaFormat
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 Bitrate = 0;
};

USTRUCT(BlueprintType)
struct FMarkerResultCallback
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 ValidFlag = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 MarkerType = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 MarkerID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector MarkerTranslation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FQuat MarkerOrientation = FQuat::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	float Timestamp = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<int32> Reserve;
};

USTRUCT(BlueprintType)
struct FMarkerFResultCallback
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 ValidFlag = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 MarkerType = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 MarkerID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector MarkerTranslation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FQuat MarkerOrientation = FQuat::Identity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	float Timestamp = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<float> Reserve;
};

USTRUCT(BlueprintType)
struct FSixDofData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int64 Timestamp = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector Translation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FQuat Orientation = FQuat::Identity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	uint8 Type = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	uint8 Confidence = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<EPoseErrorType> PoseErrorType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	float PlaneHeight = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	uint8 PlaneStatus = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	uint8 RelocationStatus = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<uint8> Reserved;
};

USTRUCT(BlueprintType)
struct FVSTCameraFrameItem
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	uint8 CameraId = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 Width = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 Height = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 Format = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 ExposureDuration = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int64 Timestamp = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int64 QTimerTimestamp = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int64 FrameNumber = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	int32 DataSize = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<uint8> Data;
};

USTRUCT(BlueprintType)
struct FAlgoResult
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FSixDofData Pose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FSixDofData RelocationPose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector LinearVelocity = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector LinearAcceleration = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector AngularVelocity = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector AngularAcceleration = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<uint8> Reserved;
};

USTRUCT(BlueprintType)
struct FVSTCameraFrameData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVSTCameraFrameItem FrameItem;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	bool bIsRGB = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FMatrix RGBTSWMatrix = FMatrix::Identity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	bool bIsAntiDistortion = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FAlgoResult SixDofPose;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	TArray<uint8> Reserved;
};

USTRUCT(BlueprintType)
struct FRGBCameraParams
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector2D InternalF = FVector2D::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector2D InternalC = FVector2D::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FVector ExternalTranslation = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FQuat ExternalOrientation = FQuat::Identity;
};

USTRUCT(BlueprintType)
struct FIntent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString PackageName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString ClassName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PICO|Enterprise")
	FString Action;
};

UENUM(BlueprintType)
enum class ESystemKey : uint8
{
	ENTER_KEY = 0,
	BACK_KEY = 1,
	VOLUME_KEY = 2,
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOBindTobServiceDelegate, bool, Result);
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
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetSystemCountryCodeDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetIPDDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetArUcoMarkerDelegate, const TArray<FMarkerResultCallback>&, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOSetArUcoMarkerFDelegate, const TArray<FMarkerFResultCallback>&, Result);
DECLARE_DYNAMIC_DELEGATE_FiveParams(FPICOFileCopyDelegate, bool, bStart, bool, bProcess, float, Process, bool, bFinish, int32, ErrorCode);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOIsMapInEffectDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOImportMapByPathDelegate, int32, Result);
//590
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOEnterpriseIntDelegate, int32, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPICOEnterpriseStringDelegate, FString, Result);

DECLARE_DYNAMIC_DELEGATE_TwoParams(FPICOOnUpdateStatusChangedDelegate, int32, StatusCode, float, Percent);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPICOOnUpdateCompleteDelegate, int32, ErrorCode, FString, ErrorMsg);

/// @endcond

/** @defgroup PE_Enterprise PE_Enterprise
 *  This is the PE_Enterprise group
 *  @{
 */

/// @cond

UCLASS()
class PICOENTERPRISE_API UPICOEnterpriseFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FPICOBindTobServiceDelegate PICOBindTobServiceDelegate;
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_BindTobService(FPICOBindTobServiceDelegate PICOBindTobServiceDelegate);

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_UnBindTobService();

	// Only C++ callable functions
	static int32 PE_SetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, ESwitchEnum SwitchEnum, int32 Ext);

	// Blueprintcallable functions

/// @endcond

	/// <summary>Gets the requested type of device information.
	/// @note All the PICO XR System APIs are only for Enterprise headsets.
	/// </summary>
	/// <param name="Info">(In) Enum, the type of device information to retrieve. Options are as follows:
	/// <ul>
	/// <li>ELECTRIC_QUANTITY: Battery level</li>
	/// <li>PUI_VERSION: PUI version</li>
	/// <li>EQUIPMENT_MODEL: Device model</li>
	/// <li>EQUIPMENT_SN: Device SN</li>
	/// <li>CUSTOMER_SN: Customer SN</li>
	/// <li>INTERNAL_STORAGE_SPACE_OF_THE_DEVICE: Storage space of the device</li>
	/// <li>DEVICE_BLUETOOTH_STATUS: Bluetooth status</li>
	/// <li>BLUETOOTH_NAME_CONNECTED: Name of bluetooth connection</li>
	/// <li>BLUETOOTH_MAC_ADDRESS: Mac address of bluetooth</li>
	/// <li>DEVICE_WIFI_STATUS: WIFI connection status</li>
	/// <li>WIFI_NAME_CONNECTED: Name of connected WiFi</li>
	/// <li>WLAN_MAC_ADDRESS: Mac address of WLAN</li>
	/// <li>DEVICE_IP: Device IP</li>
	/// <li>CHARGING_STATUS: Charging status (2-charged; 3-uncharged)</li>
	/// </ul>
	/// </param>
	/// <returns>FString: The requested type of device information.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetDeviceInfo(ESystemInfoEnum InfoEnum);

	static TMap<EDeviceControlEnum, FPICOSetDeviceActionDelegate> SetDeviceActionDelegates;
	/// <summary>
	/// Shuts down or reboots the device.
	/// @note This is a protected API. You need to add `<meta-data android:name="pico_advance_interface" android:value="0"/>`
	/// to the app's AndroidManifest.xml file for calling this API, after which the app is unable to be published on the PICO Store.
	/// </summary>
	/// <param name="DeviceControlEnum">Device action. Enumerations:
	/// * `DEVICE_CONTROL_REBOOT`
	/// * `DEVICE_CONTROL_SHUTDOWN`
	/// </param>
	/// <param name="SetDeviceActionDelegate">(In) Delegate, bind the callback event to get the result. The callback event parameters are: Int,
	/// * `1`: failed to shut down or reboot the device
	/// * `2`: no permission to perform this operation
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetDeviceAction(EDeviceControlEnum DeviceControlEnum, FPICOSetDeviceActionDelegate SetDeviceActionDelegate);

	static TMap<FAppManagerStruct, FPICOAppManagerDelegate> AppManagerDelegates;
	/// <summary>
	/// Installs or uninstalls app silently.
	/// @note This is a protected API. You need to add `<meta-data android:name="pico_advance_interface" android:value="0"/>`
	/// to the app's AndroidManifest.xml file for calling this API, after which the app is unable to be published on the PICO Store.
	/// </summary>
	/// <param name="PackageControlEnum">The action. Enumerations:
	/// * `PACKAGE_SILENCE_INSTALL`: silent installation
	/// * `PACKAGE_SILENCE_UNINSTALL`: silent uninstallation
	/// </param>
	/// <param name="Path">The path to the app package for silent installation or the name of the app package for silent uninstallation.</param>
	/// <param name="AppManagerDelegate">(In) Delegate, bind the callback event to get the result. The callback event parameters are: Int,
	/// * `0`: success
	/// * `1`: failure
	/// * `2`: no permission to perform this operation
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext, FPICOAppManagerDelegate AppManagerDelegate);//Can not know how to design delegate

	static FPICOSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate;
	/// <summary>Connects to a specified Wi-Fi.</summary>
	/// <param name="WifiName">(In) FString, the ID of specified Wi-Fi.</param>
	/// <param name="WifiPSD">(In) FString, the password of specified Wi-Fi.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <param name="SetAutoConnectWifiDelegate">(In) Delegate, bind the callback event to get the setup result. The callback event parameters are: Bool,
	/// <ul>
	/// <li>`true` - success;</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext, FPICOSetAutoConnectWifiDelegate SetAutoConnectWifiDelegate);

	static FPICOClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate;
	/// <summary>Disables auto connecting to the specified Wi-Fi.</summary>
	/// <param name="ClearAutoConnectWifiDelegate">(In) Delegate, bind the callback event to get the result. The callback event parameters are: Bool,
	/// <ul>
	/// <li>`true` - success;</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ClearAutoConnectWifi(FPICOClearAutoConnectWifiDelegate ClearAutoConnectWifiDelegate);

	static TMap<EHomeEventEnum, FPICOSetHomeKeyDelegate> SetHomeKeyDelegates;
	/// <summary>Customizes the function of the Home key. Note: This will redefine the Home key and affect the function of the Home key defined by the system. Please use this function with discretion.</summary>
	/// <param name="EventEnum">(In) EHomeEventEnum, the Home key event. The possible values are: 
	/// <ul>
	/// <li>`HOME_SINGLE_CLICK` - Single click the Home key</li>
	/// <li>`HOME_DOUBLE_CLICK` - Double click the Home key</li>
	/// <li>`HOME_LONG_PRESS` - Hold down the Home key</li>
	/// <li>`HOME_SINGLE_CLICK_RIGHT_CTL` - Single click the Home key with the right controller</li>
	/// <li>`HOME_DOUBLE_CLICK_RIGHT_CTL` - Double click the Home key with the right controller</li>
	/// <li>`HOME_LONG_PRESS_RIGHT_CTL` - Hold down the Home key with the right controller</li>
	/// <li>`HOME_SINGLE_CLICK_LEFT_CTL` - Single click the Home key with the left controller</li>
	/// <li>`HOME_DOUBLE_CLICK_LEFT_CTL` - Double click the Home key with the left controller</li>
	/// <li>`HOME_LONG_PRESS_LEFT_CTL` - Hold down the Home key with the left controller</li>
	/// <li>`HOME_SINGLE_CLICK_HMD` - Single click the Home key with the HMD</li>
	/// <li>`HOME_DOUBLE_CLICK_HMD` - Double click the Home key with the HMD</li>
	/// <li>`HOME_LONG_PRESS_HMD` - Hold down the Home key with the HMD</li>
	/// </ul>
	/// </param>
	/// <param name="FunctionEnum">(In) EHomeFunctionEnum, the function of the Home key event. The possible values are: 
	/// <ul>
	/// <li>`VALUE_HOME_GO_TO_SETTING` - Go to Settings</li>
	/// <li>`VALUE_HOME_BACK` - Return</li>
	/// <li>`VALUE_HOME_RECENTER` - Re-center</li>
	/// <li>`VALUE_HOME_OPEN_APP` - Open the target App</li>
	/// <li>`VALUE_HOME_DISABLE` - Disable the Home key</li>
	/// <li>`VALUE_HOME_GO_TO_HOME` - Go to Launcher</li>
	/// <li>`VALUE_HOME_SEND_BROADCAST` - Send a broadcast when the Home key is clicked</li>
	/// <li>`VALUE_HOME_CLEAN_MEMORY` - Clear the background system memory</li>
	/// <li>`VALUE_HOME_QUICK_SETTING` - Launch the shortcut settings</li>
	/// <li>`VALUE_HOME_SCREEN_CAP` - Launch screen capture</li>
	/// <li>`VALUE_HOME_SCREEN_RECORD` - Launch screen record</li>
	/// </ul>
	/// </param>
	/// <param name="SetHomeKeyDelegate">(In) Delegate, bind the callback event to get the Home key setup result. The callback event parameters are: Bool,
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, FPICOSetHomeKeyDelegate SetHomeKeyDelegate);

	static TMap<EHomeEventEnum, FPICOSetHomeKeyAllDelegate> SetHomeKeyAllDelegates;
	/// <summary>Customizes the function of the Home key.
	/// @note This will redefine the Home key and affect the function of the Home key defined by the system. Please use this function with discretion.
	/// </summary>
	/// <param name="EventEnum">(In) EHomeEventEnum, Home key event: 
	/// <ul>
	/// <li>`HOME_SINGLE_CLICK` - Single click the Home key</li>
	/// <li>`HOME_DOUBLE_CLICK` - Double click the Home key</li>
	/// <li>`HOME_LONG_PRESS` - Hold down the Home key</li>
	/// <li>`HOME_SINGLE_CLICK_RIGHT_CTL` - Single click the Home key with the right controller</li>
	/// <li>`HOME_DOUBLE_CLICK_RIGHT_CTL` - Double click the Home key with the right controller</li>
	/// <li>`HOME_LONG_PRESS_RIGHT_CTL` - Hold down the Home key with the right controller</li>
	/// <li>`HOME_SINGLE_CLICK_LEFT_CTL` - Single click the Home key with the left controller</li>
	/// <li>`HOME_DOUBLE_CLICK_LEFT_CTL` - Double click the Home key with the left controller</li>
	/// <li>`HOME_LONG_PRESS_LEFT_CTL` - Hold down the Home key with the left controller</li>
	/// <li>`HOME_SINGLE_CLICK_HMD` - Single click the Home key with the HMD</li>
	/// <li>`HOME_DOUBLE_CLICK_HMD` - Double click the Home key with the HMD</li>
	/// <li>`HOME_LONG_PRESS_HMD` - Hold down the Home key with the HMD</li>
	/// </ul>
	/// </param>
	/// <param name="FunctionEnum">(In) EHomeFunctionEnum, the function of the Home key event: 
	/// <ul>
	/// <li>`VALUE_HOME_GO_TO_SETTING` - Go to Settings</li>
	/// <li>`VALUE_HOME_BACK` - Return</li>
	/// <li>`VALUE_HOME_RECENTER` - Re-center</li>
	/// <li>`VALUE_HOME_OPEN_APP` - Open the target App</li>
	/// <li>`VALUE_HOME_DISABLE` - Disable the Home key</li>
	/// <li>`VALUE_HOME_GO_TO_HOME` - Go to Launcher</li>
	/// <li>`VALUE_HOME_SEND_BROADCAST` - Send a broadcast when the Home key is clicked</li>
	/// <li>`VALUE_HOME_CLEAN_MEMORY` - Clear the background system memory</li>
	/// <li>`VALUE_HOME_QUICK_SETTING` - Launch the shortcut settings</li>
	/// <li>`VALUE_HOME_SCREEN_CAP` - Launch screen capture</li>
	/// <li>`VALUE_HOME_SCREEN_RECORD` - Launch screen record</li>
	/// </ul>
	/// </param>
	/// <param name="TimeSetup">(In) Int, only `HOME_DOUBLE_CLICK` and `HOME_LONG_PRESS` (deprecated) require this time setup. If it is `HOME_SINGLE_CLICK`, use `0`.</param>
	/// <param name="Package">(In) FString, specify the app package name when the function is set as `VALUE_HOME_OPEN_APP` (deprecated).</param>
	/// <param name="ClassName">(In) FString, specify the class name when the function is set as `VALUE_HOME_OPEN_APP` (deprecated).</param>
	/// <param name="SetHomeKeyAllDelegate">(In) Delegate, bind the callback event to get the setup result. The callback event parameters are: Bool,
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup, FString Package, FString ClassName, FPICOSetHomeKeyAllDelegate SetHomeKeyAllDelegate);

	static TMap<bool, FPICODisablePowerKeyDelegate> DisablePowerKeyDelegates;
	/// <summary>Sets the Power key event.</summary>
	/// <param name="isSingleTap">(In) Bool, whether to trigger the Power key event through single click. The possible values are: 
	/// <ul>
	/// <li>`true` - Single click to trigger</li>
	/// <li>`false` - Double click to trigger</li>
	/// </ul>
	/// </param>
	/// <param name="Enable">(In) Bool, whether to enable the Power key. The possible values are: 
	/// <ul>
	/// <li>`true` - Enable the Power key</li>
	/// <li>`false` - Disable the Power key</li>
	/// </ul>
	/// </param>
	/// <param name="DisablePowerKeyDelegate">(In) Delegate, bind the callback event to get the result. The callback event parameters are: Int,
	/// <ul>
	/// <li>`0` - Success</li>
	/// <li>`1` - Failure</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_DisablePowerKey(bool bIsSingleTap, bool bEnable, FPICODisablePowerKeyDelegate DisablePowerKeyDelegate);

	static FPICOSetScreenOffDelayDelegate SetScreenOffDelayDelegate;
	/// <summary>Sets the time the system sleeps when the device is not in use.</summary>
	/// <param name="TimeEnum">(In) Enum (ESleepDelayTimeEnum), system sleep timeout. The possible values are: 
	/// <ul>
	/// <li>`FIFTEEN` - 15 seconds</li>
	/// <li>`THIRTY` - 30 seconds</li>
	/// <li>`SIXTY` - 1 minute</li>
	/// <li>`THREE_HUNDRED` - 5 minutes</li>
	/// <li>`SIX_HUNDRED` - 10 minutes</li>
	/// <li>`ONE_THOUSAND_AND_EIGHT_HUNDRED` - 30 minutes</li>
	/// <li>`NEVER` - Never sleep</li>
	/// </ul>
	/// </param>
	/// <returns>(Out) bool, Result</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SetSystemAutoSleepTime(ESleepDelayTimeEnum TimeEnum);

	/// <summary>Sets the time the screen turns off when the device is not in use.</summary>
	/// <param name="TimeEnum">(In) Enum (EScreenOffDelayTimeEnum), screen off timeout. The possible values are: 
	/// <ul>
	/// <li>`THREE` - 3 seconds</li>
	/// <li>`TEN` - 10 seconds</li>
	/// <li>`THIRTY` - 30 seconds</li>
	/// <li>`SIXTY` - 1 minute</li>
	/// <li>`THREE_HUNDRED` - 5 minutes</li>
	/// <li>`SIX_HUNDRED` - 10 minutes</li>
	/// <li>`NEVER` - Never turn off the screen</li>
	/// </ul>
	/// </param>
	/// <param name="SetScreenOffDelayDelegate">(In) Delegate, bind the callback event to get the setup result. The callback event parameters are: Int,
	/// <ul>
	/// <li>`0` - success;</li>
	/// <li>`1` - failure;</li>
	/// <li>`10` - the time set is too large</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum, FPICOSetScreenOffDelayDelegate SetScreenOffDelayDelegate);

	static FPICOEnterpriseIntDelegate SwitchSystemFunctionDelegate;
	/// <summary>Switches a specified system function on/off.</summary>
	/// <param name="SystemFunction">(In) Enum (ESystemFunctionSwitchEnum), the system function to switch on/off. Possible values include:
	/// <ul>
	/// <li>`SFS_USB` - "USB Debug": USB debugging switch</li>
	/// <li>`SFS_AUTOSLEEP` - "Auto Sleep": Auto sleep switch</li>
	/// <li>`SFS_SCREENON_CHARGING` - "ScreenOn Charging": Screen-on charging switch</li>
	/// <li>`SFS_OTG_CHARGING` - "OTG Charging": OTG charging switch</li>
	/// <li>`SFS_RETURN_MENU_IN_2DMODE` - "Show Back Menu in 2D mode": Show Back Menu in 2D mode switch</li>
	/// <li>`SFS_COMBINATION_KEY` - "Combination Key": Combination key switch</li>
	/// <li>`SFS_CALIBRATION_WITH_POWER_ON` - "Calibration with power on": Calibration with power on switch</li>
	/// <li>`SFS_SYSTEM_UPDATE` - "System Update": System update switch</li>
	/// <li>`SFS_CAST_SERVICE` - "Cast Service": Cast service switch. This property does not take effect when the industry solution switch is on.</li>
	/// <li>`SFS_EYE_PROTECTION` - "Eye Protection": Eye protection switch</li>
	/// <li>`SFS_SECURITY_ZONE_PERMANENTLY` - "Security Zone Permanently": Security zone permanently on/off switch</li>
	/// <li>`SFS_Auto_Calibration` - "Auto Calibration": Auto calibration switch</li>
	/// <li>`SFS_USB_BOOT` - "USB Boot": USB Boot switch</li>
	/// <li>`SFS_VOLUME_UI` - "Volume UI": global volume UI</li>
	/// <li>`SFS_CONTROLLER_UI` - "Controller UI": Global controller connected UI</li>
	/// <li>`SFS_NAVGATION_SWITCH` - "Navigation Switch": Navigation bar</li>
	/// <li>`SFS_SHORTCUT_SHOW_RECORD_UI` - "Shortcut Show Record UI": Screen recording button UI</li>
	/// <li>`SFS_SHORTCUT_SHOW_FIT_UI` - "Shortcut Show Fit UI": PICO fit UI</li>
	/// <li>`SFS_SHORTCUT_SHOW_CAST_UI` - "Shortcut Show Cast UI": Screencast button UI</li>
	/// <li>`SFS_SHORTCUT_SHOW_CAPTURE_UI` - "Shortcut Show Capture UI": Screenshot button UI</li>
	/// <li>`SFS_USB_FORCE_HOST` - "USB Force Host": Set the Neo3 device as the host device</li>
	/// <li>`SFS_SET_DEFAULT_SAFETY_ZONE` - "Set Default Safety Zone": Set a default play area for a Neo3 device</li>
	/// <li>`SFS_ALLOW_RESET_BOUNDARY` - "Allow Reset Boundary": Allow to reset customized boundary</li>
	/// <li>`SFS_BOUNDARY_CONFIRMATION_SCREEN` - "Boundary Confirmation Screen": Whether to display the boundary confirmation screen</li>
	/// <li>`SFS_LONG_PRESS_HOME_TO_RECENTER` - "Long Press Home to Recenter": Long press the Home key to recenter</li>
	/// <li>`SFS_POWER_CTRL_WIFI_ENABLE` - "Power Ctrl Wifi Enable": Neo3 device stays connected to the network when the device sleeps/turns off</li>
	/// <li>`SFS_WIFI_DISABLE` - "Wifi Disable": Disable Wi-Fi for Neo3 device</li>
	/// <li>`SFS_SIX_DOF_SWITCH` - "Six DOF Switch": 6DoF position tracking</li>
	/// <li>`SFS_INVERSE_DISPERSION` - "Inverse Dispersion": Anti-dispersion</li>
	/// <li>`SFS_LOGCAT` - "Logcat": Log switch (log directory: /data/logs)</li>
	/// <li>`SFS_PSENSOR` - "PSensor": PSensor switch</li>
	/// <li>`SFS_SYSTEM_UPDATE_OTA` - "System Update OTA": OTA system update switch</li>
	/// <li>`SFS_SYSTEM_UPDATE_APP` - "System Update App": App system update switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_WLAN_UI` - "Shortcut Show Wlan UI": WLAN shortcut UI switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_BOUNDARY_UI` - "Shortcut Show Boundary UI": Boundary UI shortcut switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_BLUETOOTH_UI` - "Shortcut Show Bluetooth UI": Bluetooth UI shortcut switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_CLEAN_TASK_UI` - "Shortcut Show Clean Task UI": Clean Task UI shortcut switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_IPD_ADJUSTMENT_UI` - "Shortcut Show IPD Adjustment UI": IPD Adjustment UI shortcut switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_POWER_UI` - "Shortcut Show Power UI": Power UI shortcut switch</li>
	/// <li>`SFS_SHORTCUT_SHOW_EDIT_UI` - "Shortcut Show Edit UI": Edit UI shortcut switch</li>
	/// <li>`SFS_BASIC_SETTING_APP_LIBRARY_UI` - "Basic Setting App Library UI": App Library UI in Basic Settings switch</li>
	/// <li>`SFS_BASIC_SETTING_SHORTCUT_UI` - "Basic Setting Shortcut UI": Shortcut UI in Basic Settings switch</li>
	/// <li>`SFS_LED_FLASHING_WHEN_SCREEN_OFF` - "LED Flashing When Screen Off": LED flash when screen is off switch</li>
	/// <li>`SFS_BASIC_SETTING_CUSTOMIZE_SETTING_UI`: customize settings item to show or hide in basic settings
	/// <li>`SFS_BASIC_SETTING_SHOW_APP_QUIT_CONFIRM_DIALOG`: whether to show the app-quit dialog box when switching to a new app
	/// <li>`SFS_BASIC_SETTING_KILL_BACKGROUND_VR_APP`: whether to kill background VR apps (`1`: kill, and this is the default setting; `2`: do not kill)
	/// <li>`SFS_BASIC_SETTING_SHOW_CAST_NOTIFICATION`: whether to show a blue icon when casting the screen. The icon is displayed by default, and you can set the value to `0` to hide it.
	/// <li>`SFS_AUTOMATIC_IPD`: auto IPD switch (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.7.0 or later)
	/// <li>`SFS_QUICK_SEETHROUGH_MODE`: quick seethrough mode switch (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.7.0 or later)
	/// <li>`SFS_HIGN_REFERSH_MODE`: high refresh mode switch (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.7.0 or later)
	/// <li> `SFS_SEETHROUGH_APP_KEEP_RUNNING`: whether the application continues to run normally in see-through mode. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_OUTDOOR_TRACKING_ENHANCEMENT`: enhances tracking and positioning performance in outdoor environments. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_AUTOIPD_AUTO_COMFIRM`: enables an automatic IPD adjustment process that doesn't require manual intervention from the user. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_LAUNCH_AUTOIPD_IF_GLASSES_WEARED`: whether to automatically adjust IPD when glasses are worn. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_GESTURE_RECOGNITION_HOME_ENABLE`: whether to enable gesture recognition for the home function on or off. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_GESTURE_RECOGNITION_RESET_ENABLE`: whether to enable gesture recognition for the reset function on or off. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// <li> `SFS_AUTO_COPY_FILES_FROM_USB_DEVICE`: whether to automatically import resources from an OTG (On-The-Go) USB device. (supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.8.0 or later)
	/// </ul>
	/// </param>
	/// <param name="SwitchEnum">(In) Enum (ESwitchEnum), to switch the system function on/off. Possible values include:
	/// <ul>
	/// <li>`S_ON` - "On": Switch on</li>
	/// <li>`S_OFF` - "Off": Switch off</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext, FPICOEnterpriseIntDelegate Delegate);

	/// <summary>Sets USB configuration (MTP, charging).</summary>
	/// <param name="UsbConfigModeEnum">(In) Enum (EUSBConfigModeEnum), USB config mode. Possible values include:
	/// <ul>
	/// <li>`MTP` - Media Transfer Protocol mode. The MTP mode allows the transfer of media files.</li>
	/// <li>`CHARGE` - Charging mode. The Changing mode does not allow file transfer.</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext);

	/// <summary>Switches the screen on.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ScreenOn();

	/// <summary>Switches the screen off.
	/// @note Power management permission check is required for calling this function for the first time.
	/// </summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ScreenOff();

	/// <summary>
	/// Acquires the wake lock.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_AcquireWakeLock();

	/// <summary>
	/// Releases the wake lock.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ReleaseWakeLock();

	static FPICOWriteConfigFileToDataLocalDelegate WriteConfigDelegate;
	/// <summary>Writes the configuration file to /data/local/tmp path.
	/// @note This function is only applicable to enterprise devices.
	/// </summary>
	/// <param name="Path">(In) String, the path that the configuration file is saved to.</param>
	/// <param name="Content">(In) String, the content to write into the configuration file.</param>
	/// <param name="InWriteConfigDelegate">(In) Delegate, bind the callback event to get the result. Callback event params: Bool,
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_WriteConfigFileToDataLocal(FString Path, FString Content, FPICOWriteConfigFileToDataLocalDelegate InWriteConfigDelegate);

	static FPICOResetAllKeyToDefaultDelegate ResetAllKeyDelegate;
	/// <summary>Restores system default key configurations.</summary>
	/// <param name="InResetAllKeyDelegate">(In) Delegate, bind the callback event to get the result.
	/// Callback event params:
	/// <ul>
	/// <li>`Bool`:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ResetAllKeyToDefault(FPICOResetAllKeyToDefaultDelegate InResetAllKeyDelegate);

	/// <summary>Enables the Enter key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_EnableEnterKey();

	/// <summary>Disables the Enter key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_DisableEnterKey();

	/// <summary>Enables the Volume key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_EnableVolumeKey();

	/// <summary>Disables the Volume key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_DisableVolumeKey();

	/// <summary>Enables the Back key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_EnableBackKey();

	/// <summary>Enables the Back key on headset.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_DisableBackKey();

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetCurrentBrightness();

	/// <summary>Sets the brightness for the screen.
	/// @note System permission is required if this function is called for the first time.
	/// </summary>
	/// <param name="Brightness">(In) Int, target brightness, value range: [0, 255]</param>
	/// <param name="Ext">(In) Int, Reserved bit</param>
	/// <returns>(Out) bool, Result</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SetScreenBrightness(int Brightness, int Ext);

	/// <summary>Gets the current brightness of the screen.</summary>
	/// <returns>(Out) Int, the current brightness, value range: [0, 255]</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetCurrentVolume();

	/// <summary>Gets the maximum volume allowed for the device.</summary>
	/// <returns>(Out) Int, the maximum volume allowed.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetMaxVolume();

	/// <summary>Sets a volume for the device.</summary>
	/// <param name="Volume">(In) Int, target volume, value range: [1, 15]</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetVolume(int32 Volume);

	
	/// <summary>Increases the volume of the device.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_VolumeUp();

	/// <summary>Decreases a volume for the device.</summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_VolumeDown();

	/// <summary>Gets the device's SN code.</summary>
	/// <returns>String, the device's SN code.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetDeviceSN();

	/// <summary>Sets a volume for the device.</summary>
	/// <param name="Volume">(In) Int, target volume, value range: [1, 15]</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_FreezeScreen(bool freeze);

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_KillAppsByPidOrPackageName(TArray<int> pids, TArray<FString> packageNames, int ext);

	/// <summary>Force quits background app(s) except for those in the allowlist.</summary>
	/// <param name="PackageNames">(In) FString Array, an array of package name(s) in the allowlist. These app(s) will not be force quit.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to 0 by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_KillBackgroundAppsWithWhiteList(TArray<FString> packageNames, int ext);

	/// <summary>
	/// Turns on the screencast function.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_OpenMiracast();

	/// <summary>
	/// Gets the status of the screencast function.
	/// </summary>
	/// <returns>The status of the screencast function:
	/// * `true`: on
	/// * `false`: off
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_IsMiracastOn();

	/// <summary>
	/// Turns off the screencast function.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_CloseMiracast();

	/// <summary>
	/// Starts looking for devices that can be used for screen casting.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_StartScan();

	/// <summary>
	/// Stops looking for devices that can be used for screen casting.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_StopScan();

	/// <summary>
	/// Casts the screen to the specified device.
	/// </summary>
	/// <param name="Model">A model array structure containing the following fields:
	/// * `deviceAddress`
	/// * `deviceName`
	/// * `isAvailable` (`true`-device available; `false`-device not available)
	/// * `canConnect`
	/// * `isRemembered`
	/// * `statusCode`
	/// * `status`
	/// * `description`
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ConnectWifiDisplay(const FWifiDisplayModel& Model);

	/// <summary>
	/// Stops casting the screen to the current device.
	/// </summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_DisConnectWifiDisplay();

	/// <summary>
	/// Forgets the device that have been connected for screencast.
	/// </summary>
	/// <param name="address">Device address.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ForgetWifiDisplay(FString Address);

	/// <summary>
	/// Renames the device connected for screencast. The name is only for local storage.
	/// </summary>
	/// <param name="Address">The MAC address of the device.</param>
	/// <param name="NewName">The new device name.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_RenameWifiDisplay(FString Address, FString NewName);

	/// <summary>
	/// Manually updates the list of devices for screencast.
	/// </summary>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_UpdateWifiDisplays();

	/// <summary>
	/// Gets the information of the currently connected device.
	/// </summary>
	/// <param name="Model">The information of the currently connected device.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetConnectedWD(FWifiDisplayModel& Model);

	static FPICOSetWDJsonDelegate SetWDJsonDelegate;
	/// <summary>
	/// Sets the callback for the scanning result, which returns the JSON string that contains the devices previously connected for screencast and the devices currently found for screencast.
	/// </summary>
	/// <param name="InSetWDJsonDelegate">A JSON string that contains the currently scanned device. </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetWDJson(FPICOSetWDJsonDelegate InSetWDJsonDelegate);

	static FPICOSetWDModelsDelegate SetWDModelsDelegate;
	/// <summary>
	/// Sets the callback for the scanning result. </summary>
	/// <param name="InSetWDModelsDelegate"> Contains the devices previously connected for screencast and the devices currently found for screencast. </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetWDModels(FPICOSetWDModelsDelegate InSetWDModelsDelegate);

	static FPICOEnableLargeSpaceDelegate EnableLargeSpaceDelegate;
	/// <summary>Enables/disables large space at system level. Component PicoXR System API is required. Bind a callback event to acquire switch result.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="InEnableLargeSpaceDelegate">(In) Delegate, bind the callback event for getting the result.
	/// Callback event params: Bool, 
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <param name="Open">(In) Bool, whether to enable large space:
	/// <ul>
	/// <li>`true` - enable large space</li>
	/// <li>`false` - disable large space</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SwitchLargeSpaceScene(FPICOEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext = 0);

	static FPICOSwitchLargeSpaceStatusDelegate SwitchLargeSpaceStatusDelegate;
	/// <summary> Gets the status of the large space scene.
	/// @note Supported by 6Dof devices.
	/// </summary>
	/// <param name="InSwitchLargeSpaceStatusDelegate">(In) Delegate, bind the callback event for getting the result.
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetSwitchLargeSpaceStatus(FPICOSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate, int ext = 0);

	/// <summary>Saves large space maps. Component PicoXR System API is required.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SaveLargeSpaceMaps(int ext = 0);

	static FPICOExportMapsDelegate ExportMapsDelegate;
	/// <summary>Exports the map file. The exported file is saved to `internal storage/maps/export`.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="InExportMapsDelegate">(In) Delegate, bind the callback event for getting the result.
	/// Callback event params: FString:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ExportMaps(FPICOExportMapsDelegate InExportMapsDelegate, int ext = 0);

	static FPICOImportMapsDelegate ImportMapsDelegate;
	/// <summary>Imports a map file. The file should be copied to `internal storage/maps/` beforehand, and then execute the import method.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="InImportMapsDelegate">(In) Delegate, bind the callback event to get the result.
	/// Callback event params: FString:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ImportMaps(FPICOImportMapsDelegate InImportMapsDelegate, int ext = 0);

	/// <summary>Gets the CPU usage of the current device.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="OutData">(Out) Float, the current CPU usage of the device.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetCpuUsages(TArray<float>& OutData);

	/// <summary>Gets the temperature (℃) of the current device.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="Type">(In) Int, the requested type of device temperature.
	/// <ul>
	/// <li>`0`: CPU temperature (DEVICE_TEMPERATURE_CPU)</li>
	/// <li>`1`: GPU temperature (DEVICE_TEMPERATURE_GPU)</li>
	/// <li>`2`: Battery temperature (DEVICE_TEMPERATURE_BATTERY)</li>
	/// <li>`3`: Surface temperature (DEVICE_TEMPERATURE_SKIN)</li>
	/// </ul></param>
	/// <param name="Source">(In) Int, the requested source of device temperature.
	/// <ul>
	/// <li>`0`: current temperature (TEMPERATURE_CURRENT)</li>
	/// <li>`1`: temperature threshold for throttling (TEMPERATURE_THROTTLING)</li>
	/// <li>`2`: temperature threshold for shutdown (TEMPERATURE_SHUTDOWN)</li>
	/// <li>`3`: temperature threshold for throttling (TEMPERATURE_THROTTLING_BELOW_VR_MIN). If the actual temperature is higher than the threshold, the lowest clock frequency for VR mode will not be met.</li>
	/// </ul></param>
	/// <param name="OutData">(Out) Float, an array of requested device temperature(s) (℃).</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetDeviceTemperatures(int inType, int inSource, TArray<float>& OutData);

	/// <summary>Captures the current screen.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_Capture();

	/// <summary>Records the screen. Call this function again to stop recording.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_Record();

	static FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate ControlSetAutoConnectWIFIWithErrorCodeDelegate;
	/// <summary>Connects the device to a specified WIFI.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="InControlSetAutoConnectWIFIWithErrorCodeDelegate">(In) Dynamic proxy, can be bound to a custom event to output the "Result" parameter.</param>
	/// <param name="Ssid">(In) String, the WIFI name.</param>
	/// <param name="Pwd">(In) String, the WIFI password.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <param name="Result">(Out) Int, the error code for whether the WIFI connection is successful.
	/// <ul>
	/// <li>`0`: SUCCESS_CODE (connected)</li>
	/// <li>`1`: WIFI_CONNECT_PASSWORD_ERROR (password error) (TEMPERATURE_THROTTLING)</li>
	/// <li>`2`:WIFI_CONNECT_UNKNOWN_ERROR (unknown error)</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ControlSetAutoConnectWIFIWithErrorCode(FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate, FString ssid, FString pwd, int ext);

	/// <summary>Keeps an app active, i.e. raising the priority of the app, thereby in general situations, the system will not force quit the app.</summary>
	/// <param name="Target">(In) Object, connects to the Pico XRSystem API component.</param>
	/// <param name="AppPackageName">(In) String, the app package name.</param>
	/// <param name="KeepAlive">(In) Int, whether to keep the app active (i.e., whether to raise the priority of the app)
	/// <ul>
	/// <li>`true`: Yes</li>
	/// <li>`false`: No</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_AppKeepAlive(FString appPackageName, bool keepAlive, int ext);

	/// <summary>Sets a timer to turn on the PICO VR headset, including its specific time value and whether to enable the timer.</summary>
	/// <param name="Year">(In) Int, the year of the timer set.</param>
	/// <param name="Month">(In) Int, the month of the timer set.</param>
	/// <param name="Day">(In) Int, the day of the timer set.</param>
	/// <param name="Hour">(In) Int, the hour of the timer set.</param>
	/// <param name="Minute">(In) Int, the minute of the timer set.</param>
	/// <param name="Open">(In) Bool, whether to enable the timer:
	/// <ul>
	/// <li>`true`: enable</li>
	/// <li>`false`: disable</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_TimingStartup(int year, int month, int day, int hour, int minute, bool open);

	/// <summary>Sets a timer to shut down the PICO VR headset, including its specific time value and whether to enable the timer.</summary>
	/// <param name="Year">(In) Int, the year of the timer set.</param>
	/// <param name="Month">(In) Int, the month of the timer set.</param>
	/// <param name="Day">(In) Int, the day of the timer set.</param>
	/// <param name="Hour">(In) Int, the hour of the timer set.</param>
	/// <param name="Minute">(In) Int, the minute of the timer set.</param>
	/// <param name="Open">(In) Bool, whether to enable the timer:
	/// <ul>
	/// <li>`true`: enable</li>
	/// <li>`false`: disable</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_TimingShutdown(int year, int month, int day, int hour, int minute, bool open);

	/// <summary>Launches the specified settings page of the PICO VR headset.</summary>
	/// <param name="VrSettingsEnum">(In) Enum, defines which specific settings page to launch:
	/// <ul>
	/// <li>`0`: WIFI</li>
	/// <li>`1`: Bluetooth</li>
	/// <li>`2`: Controller</li>
	/// <li>`3`: Lab</li>
	/// <li>`4`: Brightness</li>
	/// <li>`5`: General</li>
	/// <li>`6`: Notification</li>
	/// </ul>
	/// </param>
	/// <param name="HideOtherItem">(In) Bool, defines whether to hide other pages:
	/// <ul>
	/// <li>`true`: Yes</li>
	/// <li>`false`: No</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_StartVrSettingsItem(int vrSettingsEnum, bool hideOtherItem, int ext);

	/// <summary>Modifies the function of the volume buttons. For example, you can change "Volume -" to "Home", "Volume +" to "Confirm", or revert to the volume buttons, if required.</summary>
	/// <param name="SwitchEnum">(In) Enum, defines whether to change the function of the volume button:
	/// <ul>
	/// <li>`on`: change</li>
	/// <li>`off`: do not change</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SwitchVolumeToHomeAndEnter(ESwitchEnum switchEnum, int ext);

	/// <summary>Gets the function of the current volume button. For example, to determine if the current volume button is modified to "Home" or "Confirm" button.</summary>
	/// <returns>Bool, the current status of the volume button:
	/// <ul>
	/// <li>`on`: changed</li>
	/// <li>`off`: not changed</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ESwitchEnum PE_IsVolumeChangeToHomeAndEnter();

	/// <summary>Upgrades the OTA.</summary>
	/// <param name="OtaPackagePath">(In) String, the location of the OTA package.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the status of the OTA upgrade:
	/// <ul>
	/// <li>`0`: success</li>
	/// <li>`1`: failure</li>
	/// <li>`2`: OTA package version is outdated</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EInstallOTAReturnCode PE_InstallOTAPackage(const FString& OtaPackagePath, int32 Ext);

	/// <summary>Gets the configuration of the Wi-Fi network that the device automatically connects to.</summary>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>String, the SSID and password of the Wi-Fi network.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetAutoConnectWiFiConfig(int32 Ext);

	/// <summary>Gets the scheduled auto startup settings for the device.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>
	/// <ul>
	/// <li>`open`: Bool, the status of scheduled auto startup:
	/// <ul>
	/// <li>`true`: enabled</li>
	/// <li>`false`: disabled</li>
	/// </ul>
	/// </li>
	/// <li>`time`: String, the time when the device auto starts up. Returned when `open` is `true`.</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetTimingStartupStatus(int32 Ext);

	/// <summary>Gets the scheduled auto shutdown settings for the device.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>
	/// <ul>
	/// <li>`open`: Bool, the status of scheduled auto shutdown:
	/// <ul>
	/// <li>`true`: enabled</li>
	/// <li>`false`: disabled</li>
	/// </ul>
	/// </li>
	/// <li>`time`: String, the time when the device auto shuts down. Only returned when `open` is `true`.</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetTimingShutdownStatus(int32 Ext);

	/// <summary>Gets the status of a specified controller key.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="ControllerKeyEnum">(In) Enum, the enumerations of controller key:
	/// <ul>
	/// <li>`CONTROLLER KEY JOYSTICK`</li>
	/// <li>`CONTROLLER KEY MENU`</li>
	/// <li>`CONTROLLER KEY TRIGGER`</li>
	/// <li>`CONTROLLER KEY RIGHT A`</li>
	/// <li>`CONTROLLER KEY RIGHT B`</li>
	/// <li>`CONTROLLER KEY LEFT X`</li>
	/// <li>`CONTROLLER_KEY_LEFT_Y`</li>
	/// <li>`CONTROLLER_KEY_LEFT_GRIP`</li>
	/// <li>`CONTROLLER_KEY_RIGHT_GRIP`</li>
	/// </ul>
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the key's status:
	/// <ul>
	/// <li>`0`: disabled</li>
	/// <li>`1`: enabled</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EKeyState PE_GetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, int32 Ext);

	/// <summary>Gets the status of the switch for setting whether to power off the USB cable when the device is shut down.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Enum, the switch's status:
	/// <ul>
	/// <li>`PBS_SwitchEnum#S_ON`: on</li>
	/// <li>`PBS_SwitchEnum#S_OFF`: off</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ESwitchEnum PE_GetPowerOffWithUSBCable(int32 Ext);

	/// <summary>Gets the current screen off time.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the current screen off time in seconds.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EScreenOffDelayTimeEnum PE_GetScreenOffDelay(int32 Ext);

	/// <summary>Gets the current system sleep off time.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the current system sleep off time in seconds.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ESleepDelayTimeEnum PE_GetSleepDelay(int32 Ext);

	/// <summary>Gets the Power key's settings.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>A dictionary with the following keys:
	/// <ul>
	/// <li>`null`: Not set</li>
	/// <li>`singleTap`: Whether a single-tap event has been set</li>
	/// <li>`longTap`: Whether a long-press event has been set</li>
	/// <li>`longPressTime`: The time after which the long-press event takes place. Returned when `longTap` is `true`.</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetPowerKeyStatus(int32 Ext);

	/// <summary>Gets the Enter key's status.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the key's status:
	/// <ul>
	/// <li>`0`: disabled</li>
	/// <li>`1`: enabled</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EKeyState PE_GetEnterKeyStatus(int32 Ext);

	/// <summary>Gets the Volume key's status.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the key's status:
	/// <ul>
	/// <li>`0`: disabled</li>
	/// <li>`1`: enabled</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EKeyState PE_GetVolumeKeyStatus(int32 Ext);

	/// <summary>Gets the Back key's status.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Int, the key's status:
	/// <ul>
	/// <li>`0`: disabled</li>
	/// <li>`1`: enabled</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EKeyState PE_GetBackKeyStatus(int32 Ext);

	/// <summary>Gets the event setting for the Home key.</summary>
	/// <param name="Target">(In) Object, set to `self` by default.</param>
	/// <param name="HomeEventEnum">(In) Enum, the event type for the Home key. Possible values:
	/// <br>`SINGLE_CLICK`: single-click event
	/// <br>`DOUBLE_CLICK`: double-click event
	/// <br>`LONG_PRESS`: long-press event
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>The return value varies based on the event type:
	/// <ul>
	/// <li>For `SINGLE_CLICK` and `DOUBLE_CLICK`, the event(s) you set will be returned.</li>
	/// <li>For `LONG_PRESS`, the time and event you set will be returned. If you have not set a time for a long-press event, the time value will be `null`.</li>
	/// <li>If you have not set any event for the specified event type, the response will return `null`.</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetHomeKeyStatus(EHomeEventEnum HomeEventEnum, int32 Ext);

	/// <summary>Gets the configured USB mode.</summary>
	/// <param name="">Reserved parameter, set to `0` by default.</param>
	/// <returns>
	/// - `MTP`: MTP mode
	/// - `CHARGE`: charging mode
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetUsbConfigurationOption(int32 Ext);

	/// <summary>Gets the current launcher.</summary>
	/// <returns>String, the package name or class name of the current launcher.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetCurrentLauncher(int32 Ext);

	static FPICOGetSwitchSystemFunctionStatusDelegate GetSwitchSystemFunctionStatusDelegate;
	/// <summary>Gets the status of a specified system function switch.</summary>
	/// <param name="SystemFunctionSwitchEnum">(In) The system function switch:
	/// <ul>
	/// <li>`USB Debug`</li>
	/// <li>`Auto Sleep`</li>
	/// <li>`ScreenOn Charging`</li>
	/// <li>`OTG Charging`</li>
	/// <li>`Show Back Menu in 2D Mode`</li>
	/// <li>`Combination Key`</li>
	/// <li>`Calibration with power on`</li>
	/// <li>`System Update`</li>
	/// <li>`Cast Service`</li>
	/// <li>`Eye Protection`</li>
	/// <li>`Security Zone Permantly`</li>
	/// <li>`Global Calibration`</li>
	/// <li>`Auto Calibration`</li>
	/// <li>`USB Boot`</li>
	/// <li>`Volume Global UI Prompt Switch`</li>
	/// <li>`Controller Connection Global UI Prompt Switch`</li>
	/// <li>`Open/Close the Navigation`</li>
	/// <li>`Show Record UI`</li>
	/// <li>`Show Fit UI`</li>
	/// <li>`Show Cast UI`</li>
	/// <li>`Show Capture UI`</li>
	/// <li>`Stop Mem Infor Service`</li>
	/// <li>`Start App Boot Completed`</li>
	/// <li>`Usb Force Host`</li>
	/// <li>`Set Default Safty Zone`</li>
	/// <li>`Allow Reset Boundary`</li>
	/// <li>`Boundary Confirmation Screen`</li>
	/// <li>`Long Press Home For Recenter`</li>
	/// <li>`Power Ctrl Wifi Enable`</li>
	/// <li>`Wifi Disable`</li>
	/// <li>`Six Dof Switch`</li>
	/// <li>`Inverse Dispersion`</li>
	/// <li>`Logcat`</li>
	/// <li>`PSensor`</li>
	/// <li>`System Update OTA`</li>
	/// <li>`System Update App`</li>
	/// <li>`Shortcut Show Wlan UI`</li>
	/// <li>`Shortcut Show Boundary UI`</li>
	/// <li>`Shortcut Show Bluetooth UI`</li>
	/// <li>`Shortcut Show Clean Task UI`</li>
	/// <li>`Shortcut Show IPD Adjustment UI`</li>
	/// <li>`Shortcut Show Power UI`</li>
	/// <li>`Shortcut Show Edit UI`</li>
	/// <li>`Basic Setting App Library UI`</li>
	/// <li>`Basic Setting Shortcut UI`</li>
	/// </ul>
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetSwitchSystemFunctionStatus(FPICOGetSwitchSystemFunctionStatusDelegate InGetSwitchSystemFunctionStatusDelegate, ESystemFunctionSwitchEnum SystemFunctionSwitchEnum, int32 Ext);

	static FPICOCastInitDelegate PICOCastInitDelegate;
	/// <summary>Initializes the screencast service.</summary>
	/// <param name="InPICOCastInitDelegate">(In) The callback:
	/// <ul>
	/// <li>`0`: disconnect</li>
	/// <li>`1`: connect</li>
	/// <li>`2`: no mic permission</li>
	/// </ul>
	/// </param>
	/// <returns>Int:
	/// <ul>
	/// <li>`0`: failure</li>
	/// <li>`1`: success</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ECastReturnCode PE_PICOCastInit(FPICOCastInitDelegate InPICOCastInitDelegate, int32 Ext);

	/// <summary>Sets whether to show the screencast authorization window.</summary>
	/// <param name="Authorization">(In) The authorization setting:
	/// <ul>
	/// <li>`0`: ask every time (default)</li>
	/// <li>`1`: always allow</li>
	/// <li>`2`: not accepted</li>
	/// </ul>
	/// </param>
	/// <returns>Int, the status of the operation:
	/// <ul>
	/// <li>`0`: failure</li>
	/// <li>`1`: success</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ECastReturnCode PE_PICOCastSetShowAuthorization(EPICOCastAuthorization Authorization, int32 Ext);

	/// <summary>Gets the setting of whether to show the screencast authorization window.</summary>
	/// <returns>Int, the current authorization setting:
	/// <ul>
	/// <li>`0`: ask every time (default)</li>
	/// <li>`1`: always allow</li>
	/// <li>`2`: not accepted</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EPICOCastAuthorization PE_PICOCastGetShowAuthorization(int32 Ext);

	/// <summary>Gets the URL for screencast.</summary>
	/// <param name="UrlType">(In) Enum, the type of URL:
	/// <ul>
	/// <li>`NormalURL`: Normal URL. The screencast authorization window will show if it is not set.</li>
	/// <li>`NoConfirmURL`: Non-confirm URL. The screencast authorization window will not show in the browser. Screencast will start once you enter the URL.</li>
	/// <li>`RtmpURL`: Returns the RTMP live streaming URL. The screencast authorization window will not appear on the VR headset's screen.</li>
	/// </ul>
	/// </param>
	/// <returns>String, the URL for screencast.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_PICOCastGetUrl(EPICOCastUrlTypeEnum UrlType, int32 Ext);

	/// <summary>Stops screencast.</summary>
	/// <returns>Int, the status of stopping screencast:
	/// <ul>
	/// <li>`0`: failure</li>
	/// <li>`1`: success</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ECastReturnCode PE_PICOCastStopCast(int32 Ext);

	/// <summary>Sets screencast-related properties.</summary>
	/// <param name="OptionEnum">(In) The enumerations of the property to set:
	/// <br>- `OPTION_RESOLUTION_LEVEL`: resolution level
	/// <br>- `OPTION_BITRATE_LEVEL`: bitrate level
	/// <br>- `OPTION_AUDIO_ENABLE`: whether to enable the audio</param>
	/// <param name="ValueEnum">(In) The values that can be set for each property:
	/// <br>- For `OPTION_RESOLUTION_LEVEL`:
	/// <br>  - `OPTION_VALUE_RESOLUTION_HIGH`
	/// <br>  - `OPTION_VALUE_RESOLUTION_MIDDLE`
	/// <br>  - `OPTION_VALUE_RESOLUTION_AUTO`
	/// <br>  - `OPTION_VALUE_RESOLUTION_HIGH_2K`
	/// <br>  - `OPTION_VALUE_RESOLUTION_HIGH_4K`
	/// <br>- For `OPTION_BITRATE_LEVEL`:
	/// <br>  - `OPTION_VALUE_BITRATE_HIGH`
	/// <br>  - `OPTION_VALUE_BITRATE_MIDDLE`
	/// <br>  - `OPTION_VALUE_BITRATE_LOW`
	/// <br>- For `OPTION_AUDIO_ENABLE`:
	/// <br>  - `OPTION_VALUE_AUDIO_ON`
	/// <br>  - `OPTION_VALUE_AUDIO_OFF`</param>
	/// <returns>Int
	/// <ul>
	/// <li>`0`: failure</li>
	/// <li>`1`: success</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ECastReturnCode PE_PICOCastSetOption(EPICOCastOptionOrStatusEnum OptionEnum, EPICOCastOptionValueEnum ValueEnum, int32 Ext);

	/// <summary>Gets the screencast-related property setting for the current device.</summary>
	/// <param name="OptionEnum">(In) The enumerations of the screencast property to get setting for:
	/// <br>- `OPTION_RESOLUTION_LEVEL`: resolution level
	/// <br>- `OPTION_BITRATE_LEVEL`: bitrate level
	/// <br>- `OPTION_AUDIO_ENABLE`: whether the audio is enabled
	/// <br>- `PICOCAST_STATUS`: returns the current screemcast status</param>
	/// <returns>String, the setting of the selected property:
	/// <ul>
	/// <li>For `OPTION_RESOLUTION_LEVEL`:
	///   <ul>
	///     <li>`OPTION_VALUE_RESOLUTION_HIGH`</li>
	///     <li>`OPTION_VALUE_RESOLUTION_MIDDLE`</li>
	///     <li>`OPTION_VALUE_RESOLUTION_AUTO`</li>
	///     <li>`OPTION_VALUE_RESOLUTION_HIGH_2K`</li>
	///     <li>`OPTION_VALUE_RESOLUTION_HIGH_4K`</li>
	///   </ul>
	/// </li>
	/// <li>For `OPTION_BITRATE_LEVEL`:
	///   <ul>
	///     <li>`OPTION_VALUE_BITRATE_HIGH`</li>
	///     <li>`OPTION_VALUE_BITRATE_MIDDLE`</li>
	///     <li>`OPTION_VALUE_BITRATE_LOW`</li>
	///   </ul>
	/// </li>
	/// <li>For `OPTION_AUDIO_ENABLE`:
	///   <ul>
	///     <li>`OPTION_VALUE_AUDIO_ON`</li>
	///     <li>`OPTION_VALUE_AUDIO_OFF`</li>
	///   </ul>
	/// </li>
	/// <li>`PICOCAST_STATUS`:
	///   <ul>
	///     <li>`STATUS_VALUE_STATE_STARTED`</li>
	///     <li>`STATUS_VALUE_STATE_STOPPED`</li>
	///     <li>`STATUS_VALUE_ERROR`</li>
	///   </ul>
	/// </li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EPICOCastOptionValueEnum PE_PICOCastGetOptionOrStatus(EPICOCastOptionOrStatusEnum OptionEnum, int32 Ext);

	static FPICOSetControllerPairTimeDelegate SetControllerPairTimeDelegate;
	/// <summary>Customizes the duration of the controller in pairing mode.</summary>
	/// <param name="TimeEnum">(In) Enum, pairing mode duration:
	/// <br>- `SIX`: 6 seconds
	/// <br>- `FIFTEEN`: 15 seconds
	/// <br>- `SIXTY`: 60 seconds
	/// <br>- `ONE_HUNDRED_AND_TWENTY`: 2 minutes
	/// <br>- `SIX_HUNDRED`: 10 minutes
	/// <br>- `NEVER`: No pairing mode duration</param>
	/// <param name="InSetControllerPairTimeDelegate">(In) Delegate, bind the callback event to get the result:
	/// <br>Callback event parameters: Int, `0` - failure; `1` - success</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetControllerPairTime(FPICOSetControllerPairTimeDelegate InSetControllerPairTimeDelegate, EControllerPairTimeEnum TimeEnum, int32 Ext);

	static FPICOGetControllerPairTimeDelegate GetControllerPairTimeDelegate;
	/// <summary>
	/// Gets the duration of the controller in pairing mode.
	/// </summary>
	/// <param name="InGetControllerPairTimeDelegate">(In) Delegate, bind the callback event to get the result:
	/// Callback event parameters: Int, `0` - failure; `1` - success</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>Result: EControllerPairTimeEnum
	/// - `SIX`: 6 seconds
	/// - `FIFTEEN`: 15 seconds
	/// - `SIXTY`: 60 seconds
	/// - `ONE_HUNDRED_AND_TWENTY`: 2 minutes
	/// - `SIX_HUNDRED`: 10 minutes
	/// - `NEVER`: No pairing mode duration</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetControllerPairTime(FPICOGetControllerPairTimeDelegate InGetControllerPairTimeDelegate, int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series devices) Customizes the language on the device.
	/// </summary>
	/// <param name="SystemLanguage">(In) FString, supported language codes (The system language is co-determined by both the language code and the device's country code).</param>
	/// <param name="Ext">(In) Int, reserved parameter.
	/// - `0`: Default
	/// - `1`: Reboot nativeshell and 2D apps on the system will exit.</param>
	/// <returns>
	/// - `0`: Success
	/// - `1`: Failure
	/// - `22`: The language is not supported.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_SetSystemLanguage(const FString& SystemLanguage, int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Gets the current language on the device.
	/// </summary>
	/// <param name="Ext">(In) Int, reserved parameter, pass 0 by default.</param>
	/// <returns>
	/// System language: FString, the language set on the device.
	/// - "fi": Suomi (Finnish)
	/// - "el": Ελληνικά (Greek)
	/// - "ru": Русский (Russian)
	/// - "en": English (United States)/English (United Kingdom)
	/// - "zh": 中文 (简体)(Chinese, Simplified)/中文 (繁體)(Chinese, Traditional (Taiwan))/中文 (香港)(Chinese, Traditional (Hongkong))
	/// - "pt": Português (Portugal/Brasil)
	/// - "fr": Français (French)
	/// - "cs": Čeština (Czech)
	/// - "tr": Türkçe (Turkish)
	/// - "pl": Polski (Polish)
	/// - "th": ไทย (Thai)
	/// - "sv": Svenska (Swedish)
	/// - "ja": 日本語 (Japanese)
	/// - "nl": Nederlands (Dutch)
	/// - "da": Dansk (Dansh)
	/// - "nb": Norsk bokmål (Norwegian Bokmål)
	/// - "ms": Melayu (Malay)
	/// - "de": Deutsch (German)
	/// - "es": Español (España) (Spanish)/Estados Unidos (Spanish(Latin American))
	/// - "ko": 한국어 (Korean)
	/// - "ro": Română (Romanian)
	/// - "it": Italiano (Italian)
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetSystemLanguage(int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Set the default connected Wi-Fi.
	/// </summary>
	/// <param name="Ssid">(In) FString, the ID of specified Wi-Fi.</param>
	/// <param name="Pwd">(In) FString, the password of specified Wi-Fi.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to 0 by default.</param>
	/// <returns>
	/// - 0: Success
	/// - 1: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_ConfigWifi(const FString& Ssid, const FString& Pwd, int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Gets the name of the connected WiFi(s).
	/// </summary>
	/// <param name="Ext">(In) Int, reserved parameter, set to 0 by default.</param>
	/// <returns>FString array, an array of Wifi names</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static TArray<FString> PE_GetConfiguredWifi(int32 Ext);

	static FPICOSetSystemCountryCodeDelegate SetSystemCountryCodeDelegate;
	/// <summary>
	/// (Only supported by PICO 4 Series) Customizes the country on the device.
	/// </summary>
	/// <param name="CountryCode">(In) FString, the country code.
	/// <br>- `GB`: United Kingdom
	/// <br>- `FR`: France
	/// <br>- `DE`: Germany
	/// <br>- `IL`: Israel
	/// <br>- `IT`: Italy
	/// <br>- `JP`: Japan
	/// <br>- `KR`: Korea
	/// <br>- `NL`: Netherlands
	/// <br>- `SG`: Singapore
	/// <br>- `ES`: Spain
	/// <br>- `TR`: Turkey
	/// <br>- `MY`: Malaysia
	/// <br>- `AT`: Austria
	/// <br>- `BE`: Belgium
	/// <br>- `BG`: Bulgaria
	/// <br>- `HR`: Croatia
	/// <br>- `CZ`: Czechia
	/// <br>- `DK`: Denmark
	/// <br>- `EE`: Estonia
	/// <br>- `FI`: Finland
	/// <br>- `GR`: Greek
	/// <br>- `HU`: Hungary
	/// <br>- `IE`: Ireland
	/// <br>- `LV`: Latvia
	/// <br>- `LT`: Lithuania
	/// <br>- `LU`: Luxembourg
	/// <br>- `MT`: Malta
	/// <br>- `PL`: Poland
	/// <br>- `PT`: Portugal
	/// <br>- `RO`: Romania
	/// <br>- `SK`: Slovakia
	/// <br>- `SI`: Slovenia
	/// <br>- `SE`: Sweden
	/// <br>- `LI`: Liechtenstein
	/// <br>- `IS`: Iceland
	/// <br>- `NO`: Norway
	/// <br>- `CH`: Switzerland
	/// <br>- `AD`: Andorra
	/// <br>- `SM`: San Marino
	/// <br>- `VA`: Vatican City
	/// <br>- `MC`: Monaco
	/// <br>- `US`: United States
	/// <br>- `CA`: Canada
	/// <br>- `NZ`: New Zealand
	/// <br>- `AU`: Australia</param>
	/// <param name="InSetSystemCountryCodeDelegate">Delegate, bind the callback event to get the result:
	/// <br>Callback event parameters: Int; `0` - success, `1` - failure</param>
	/// <param name="Ext">Int, reserved parameter, pass `0` by default.</param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_SetSystemCountryCode(FPICOSetSystemCountryCodeDelegate InSetSystemCountryCodeDelegate, const FString& CountryCode, int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Gets the country code of the country set on the device.
	/// </summary>
	/// <param name="Ext">(In) Int, reserved parameter, pass 0 by default.</param>
	/// <returns>Country Code: FString, the country code of the country set on the device.
	/// <br>- `GB`: United Kingdom
	/// <br>- `FR`: France
	/// <br>- `DE`: Germany
	/// <br>- `IL`: Israel
	/// <br>- `IT`: Italy
	/// <br>- `JP`: Japan
	/// <br>- `KR`: Korea
	/// <br>- `NL`: Netherlands
	/// <br>- `SG`: Singapore
	/// <br>- `ES`: Spain
	/// <br>- `TR`: Turkey
	/// <br>- `MY`: Malaysia
	/// <br>- `AT`: Austria
	/// <br>- `BE`: Belgium
	/// <br>- `BG`: Bulgaria
	/// <br>- `HR`: Croatia
	/// <br>- `CZ`: Czechia
	/// <br>- `DK`: Denmark
	/// <br>- `EE`: Estonia
	/// <br>- `FI`: Finland
	/// <br>- `GR`: Greek
	/// <br>- `HU`: Hungary
	/// <br>- `IE`: Ireland
	/// <br>- `LV`: Latvia
	/// <br>- `LT`: Lithuania
	/// <br>- `LU`: Luxembourg
	/// <br>- `MT`: Malta
	/// <br>- `PL`: Poland
	/// <br>- `PT`: Portugal
	/// <br>- `RO`: Romania
	/// <br>- `SK`: Slovakia
	/// <br>- `SI`: Slovenia
	/// <br>- `SE`: Sweden
	/// <br>- `LI`: Liechtenstein
	/// <br>- `IS`: Iceland
	/// <br>- `NO`: Norway
	/// <br>- `CH`: Switzerland
	/// <br>- `AD`: Andorra
	/// <br>- `SM`: San Marino
	/// <br>- `VA`: Vatican City
	/// <br>- `MC`: Monaco
	/// <br>- `US`: United States
	/// <br>- `CA`: Canada
	/// <br>- `NZ`: New Zealand
	/// <br>- `AU`: Australia</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetSystemCountryCode(int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Sets to skip specific initial settings.
	/// </summary>
	/// <param name="Flag">(In) Int; The first 6 elements are valid, 7-32 reserved.
	/// <br>- For each element: `1` - show, `0` - hide
	/// <br>- `INIT_SETTING_HANDLE_CONNECTION_TEACHING`: Controller connection teaching.
	/// <br>- `INIT_SETTING_TRIGGER_KEY_TEACHING`: Trigger key teaching.
	/// <br>- `INIT_SETTING_SELECT_LANGUAGE`: Select the system language.
	/// <br>- `INIT_SETTING_SELECT_COUNTRY`: Select the country (only supported outside China).
	/// <br>- `INIT_SETTING_WIFI_SETTING`: WiFi settings.
	/// <br>- `INIT_SETTING_QUICK_SETTING`: Quick settings.</param>
	/// <returns>
	/// - 0: Success
	/// - 1: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_SetSkipInitSettingPage(int32 Flag, int32 Ext);

	/// <summary>
	/// (Only supported by PICO 4 Series) Gets what initial settings are skipped.
	/// </summary>
	/// <param name="Ext">(In) Int, reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// - Flag: Int, the flags set in `SetSkipInitSettingPage`
	/// - `1` :show
	/// - `0`: hide
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetSkipInitSettingPage(int32 Ext);

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_IsInitSettingComplete(int32 Ext);

	/// <summary>
	/// (Supported by PICO Neo3 series and PICO4) Launches another app.
	/// </summary>
	/// <param name="PackageName">(In) The app's package name</param>
	/// <param name="ClassName">(In) The app class name</param>
	/// <param name="Action">(In) The action to start an app</param>
	/// <param name="Extra">(In) FString, the basic types of standard fields that can be used as extra data. See [here](https://developer.android.com/reference/android/content/Intent#standard-extra-data) for details.</param>
	/// <param name="Categories">(In) FString Array, Standard categories that can be used to further clarify an Intent. Add a new category to the intent. See [here](https://developer.android.com/reference/android/content/Intent#addCategory(java.lang.String)) for details.</param>
	/// <param name="Flags">(In) Add additional flags to the intent. See [here](https://developer.android.com/reference/android/content/Intent#flags) for details.</param>
	/// <param name="Ext">(In) Int, reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// - 0: Success
	/// - 1: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_StartActivity(const FString& PackageName, const FString& ClassName, const FString& Action, const FString& Extra, const TArray<FString>& Categories, const TArray<int32>& Flags, int32 Ext);

	/// <summary>
	/// Shows or hides specified apps in the app library.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="PackageNames">(In) String, the package names of your applications. Separated by comma.</param>
	/// <param name="Switch">(In) The switch value:
	/// - `on`
	/// - `off`</param>
	/// <returns>
	/// A list with the following values:
	/// - 0: Success
	/// - 1: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_CustomizeAppLibrary(const TArray<FString>& PackageNames, ESwitchEnum SwitchEnum, int32 Ext);

	/// <summary>
	/// Gets the current battery level of controllers.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="Ext">(In) Reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// An integer array with the following values:
	/// - array[0]: Left controller battery level
	/// - array[1]: Right controller battery level
	/// - -1: Success
	/// - 1-5: Battery level
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static TArray<int32> PE_GetControllerBattery(int32 Ext);

	/// <summary>
	/// Gets the connection state of controllers.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="Ext">(In) Reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// An integer value representing the connection state of the controllers:
	/// - 0: Both controllers are not connected
	/// - 1: Only the left controller is connected
	/// - 2: Only the right controller is connected
	/// - 3: Both controllers are connected
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetControllerConnectState(int32 Ext);

	/// <summary>
	/// Gets the hidden applications in your app library.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="Ext">(In) Int, reserved parameter, set to `0` by default.</param>
	/// <returns>
	/// The package names of the hidden applications. Separated by comma.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetAppLibraryHideList(int32 Ext);

	/// <summary>
	/// Sets the device that outputs audio during screen casting. This API is only for miracast.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="ScreencastAudioOutput">(In) Enum, the audio output end:
	/// - `AUDIO SINK`: the HMD
	/// - `AUDIO TARGET`: the receiver
	/// - `AUDIO SINK TARGET`: both the HMD and the receiver</param>
	/// <param name="Ext">(In) Reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// - `0`: Success
	/// - `1`: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_SetScreenCastAudioOutput(EScreencastAudioOutput ScreencastAudioOutput, int32 Ext);

	/// <summary>
	/// Gets the device that outputs audio during screen casting. This API is only for miracast.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="Ext">(In) Reserved parameter, pass `0` by default.</param>
	/// <returns>
	/// The audio output end:
	/// - `AUDIO SINK`: the HMD
	/// - `AUDIO TARGET`: the receiver
	/// - `AUDIO SINK TARGET`: both the HMD and the receiver
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static EScreencastAudioOutput PE_GetScreenCastAudioOutput(int32 Ext);

	/// <summary>
	/// Displays or hides the specified tab or option on the Settings pane.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="CustomizeSettingsTab">(In) Enum, specifies the tab or option to display or hide.</param>
	/// <param name="Switch">(In) Enum, specifies whether to display or hide the tab or option.</param>
	/// <returns>
	/// - 0: Success
	/// - 1: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_CustomizeSettingsTabStatus(ECustomizeSettingsTab CustomizeSettingsTab, ESwitchEnum SwitchEnum, int32 Ext);

	/// <summary>
	/// Gets the status set for the specified tab or option on the Settings pane.
	/// </summary>
	/// <param name="Target">(In) Set to `self` by default.</param>
	/// <param name="CustomizeSettingsTab">(In) Enum, specifies the tab or option to get status for:</param>
	/// <returns>
	/// The status of the specified tab or option:
	/// - `On`: display
	/// - `Off`: hide
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static ESwitchEnum PE_GetCustomizeSettingsTabStatus(ECustomizeSettingsTab CustomizeSettingsTab, int32 Ext);

	static FPICOSetIPDDelegate SetIPDDelegate;
	/// <summary>
	/// Sets an interpupillary distance (IPD).
	/// @note Supported by PICO 4 Enterprise with system version 5.7.0 or later.
	/// </summary>
	/// <param name="IPD"> (In) The IPD to set. Valid value range: [62,72]. The units are in millimeters. </param>
	/// <param name="InSetIPDDelegate">(In) Delegate, bind the callback event to get the result. The callback event parameters are: Int,
	/// * `0`: success
	/// * `1`: failure
	/// * `23`: the `ipd` value is out of the valid range
	/// </param>
	/// <returns>None</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetIPD(FPICOSetIPDDelegate InSetIPDDelegate, float IPD);

	/// <summary>
	/// Sets screencast-related parameters.
	/// @note Supported by PICO Neo3 series and PICO 4 Enterprise with system version 5.7.0 or later.
	/// </summary>
	/// <param name="CastMediaFormat"> The mediaFormat object to set. Currently, only support settings the bitrate. </param>
	/// <param name="Ext">Int,
	/// * `0`: Maintain the current state of screencast
	/// * `1`: Start the screencast service
	/// * `2`: Stop the screencast service
	/// </param>
	/// <returns>Int,
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_SetPICOCastMediaFormat(const FCastMediaFormat& CastMediaFormat, int32 Ext);

	static FPICOSetArUcoMarkerDelegate SetArUcoMarkerDelegate;
	static UObject* MarkerWorldContext;
	/// <summary>
	/// Sets the ArUco marker delegate. This function allows you to register a callback function when an ArUco marker is detected.
	/// </summary>
	/// <param name="InWorldContext">UObject. The world context object.</param>
	/// <param name="InSetArUcoMarkerDelegate">FPICOSetArUcoMarkerDelegate. The delegate function to set AR-Uco markers.
	/// The callback event parameters are:
	/// - ValidFlag (int32): A flag indicating the recognition status (0 for invalid, 1 for valid).
	/// - MarkerType (int32): The type of AR-Uco marker (1 for static, 0 for dynamic).
	/// - MarkerID (int32): The unique identifier of the marker.
	/// - MarkerTranslation (FVector): The translation of the marker.
	/// - MarkerOrientation (FQuat): The orientation of the marker.
	/// - Timestamp (float): The timestamp of the image detection.
	/// - Reserve (TArray<int32>): Reserved parameter.
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise", meta = (WorldContext = "InWorldContext"))
	static void PE_SetArUcoMarker(UObject* InWorldContext, FPICOSetArUcoMarkerDelegate InSetArUcoMarkerDelegate);
	
	static FPICOSetArUcoMarkerFDelegate SetArUcoMarkerFDelegate;
	static UObject* MarkerFWorldContext;
	/// <summary>
	/// Sets the ArUco marker delegate. This function allows you to register a callback function when an ArUco marker is detected.
	/// </summary>
	/// <param name="InWorldContext">UObject. The world context object.</param>
	/// <param name="InSetArUcoMarkerDelegate">FPICOSetArUcoMarkerDelegate. The delegate function to set AR-Uco markers.
	/// The callback event parameters are:
	/// - ValidFlag (int32): A flag indicating the recognition status (0 for invalid, 1 for valid).
	/// - MarkerType (int32): The type of AR-Uco marker (1 for static, 0 for dynamic).
	/// - MarkerID (int32): The unique identifier of the marker.
	/// - MarkerTranslation (FVector): The translation of the marker.
	/// - MarkerOrientation (FQuat): The orientation of the marker.
	/// - Timestamp (float): The timestamp of the image detection.
	/// - Reserve (TArray<float>): Reserved parameter.
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise", meta = (WorldContext = "InWorldContext"))
	static void PE_SetArUcoMarkerF(UObject* InWorldContext, FPICOSetArUcoMarkerFDelegate InSetArUcoMarkerFDelegate);

	/// <summary>
	/// Initializes the enterprise service. Must be called before calling other enterprise APIs.
	/// </summary>
	/// <param name="Token">(In) Authentication token from the See-Through service.</param>
	/// <returns>Bool: Whether the enterprise service has been initialized:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_InitEnterpriseService(FString& Token);
	
	/// <summary>
	/// Gets the current confidence level of head tracking.
	/// </summary>
	/// <returns>
	/// * `0`: Low level (bad)
	/// * `1`: High level (good)
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GetHeadTrackingConfidence();
	
	/// <summary>
	/// Enables the see-through camera.
	/// </summary>
	/// <returns>Whether the see-through camera has been enabled:
	/// * `true`: success
	/// * `false`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_OpenVSTCamera();

	/// <summary>
	/// Disable the see-through camera.
	/// </summary>
	/// <returns>Whether the see-through camera has been disabled:
	/// * `true`: success
	/// * `false`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_CloseVSTCamera();

	/// <summary>
	/// Acquires the see-through camera frame with distortion.
	/// </summary>
	/// <param name="FrameData">(out) FVSTCameraFrameData structure.</param>
	/// <returns>
	/// - `true`: Success
	/// - `false`: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_AcquireVSTCameraFrame(FVSTCameraFrameData& FrameData);

	/// <summary>
	/// Acquires the see-through camera frame with anti-distortion correction.
	/// </summary>
	/// <param name="Token">(In) Authentication token from the See-Through service.</param>
	/// <param name="Width">(In) Desired frame width, should be less than or equal to 2328 pixels.</param>
	/// <param name="Height">(In) Desired frame height, should be less than or equal to 1748 pixels.</param>
	/// <param name="FrameData">(Out) FVSTCameraFrameData structure. </param>
	/// <returns>
	/// - `true`: Success
	/// - `false`: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_AcquireVSTCameraFrameAntiDistortion(const FString& Token, int32 Width, int32 Height, FVSTCameraFrameData& FrameData);

	/// <summary>
	/// Retrieves camera parameters, including its intrinsic properties and external position and orientation.
	/// </summary>
	/// <param name="Token">(In) Authentication token from the See-Through service. </param>
	/// <param name="Params">(Out) Camera parameters, including intrinsic properties and external position and orientation.</param>
	/// <returns>
	/// - `true`: Success
	/// - `false`: Failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_GetCameraParameters(const FString& Token, FRGBCameraParams& Params);
	
	/// <summary>
	/// Launches the floor settings under see-through mode.
	/// @note Supported by PICO devices with 6-DoF tracking and system version 5.8.0 or later.
	/// </summary>
	/// <param name="Ext">(In) Int, reserved parameter.</param>
	/// <returns>
	/// <ul>
	/// <li>`0` - Success</li>
	/// <li>`1` - Failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_GotoSeeThroughFloorSetting(int32 Ext);

	static FPICOFileCopyDelegate FileCopyDelegate;
	/// <summary>
	/// Copies a file from the source path to the target path.
	/// @note Supported by PICO 4 Enterprise, PICO Neo3 Pro, and PICO G3 with system version 5.8.0 or later.
	/// </summary>
	/// <param name="SourcePath">(In) String. The source path of the file to be copied.</param>
	/// <param name="TargetPath">(In) The target path where the file will be copied to.</param>
	/// <param name="InFileCopyDelegate">(In) Delegate for file-copying operations. The callback parameters are:
	/// - `bStart`: Whether the copying has started.
	/// - `bProcess`: Whether copying is in progress.
	/// - `Process`: Float type. The phase of the copying progress.
	/// - `bFinish`: Whether the copying has completed.
	/// - `ErrorCode`: Int. The status codes:
	///		- `0`: Copy successful
	///		- `101`: USB drive not connected
	///		- `103`: Insufficient storage space on the target device
	///		- `104`: Copy failed
	/// </param>
	/// <returns> Int:
	/// - 0: Success. Waiting to start copying
	/// - 101: USB drive not connected
	/// - 102: Source file does not exist
	/// - 106: Parameter is null
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int32 PE_FileCopy(const FString& SourcePath, const FString& TargetPath, FPICOFileCopyDelegate InFileCopyDelegate);

	static FPICOIsMapInEffectDelegate IsMapInEffectDelegate;
	/// <summary>
	/// Checks if a map is currently in effect.
	/// @note Supported by PICO 4 Enterprise and PICO Neo3 Pro with system version 5.8.0 or later.
	/// </summary>
	/// <param name="MapPath">(In) String. The path of the map to check.</param>
	/// <param name="InIsMapInEffectDelegate">(In) Int. Delegate for checking map status. The callback parameters are:
	/// - `0`: Success
	/// - `1`: Failure
	/// - `101`: File does not exist
	/// - `102`: File decompression failed
	/// - `103`: Map file is damaged
	/// - `104`:  Localization tracking is turned off
	/// - `106`: Error in obtaining current map information
	/// - `107`: The 'MapPath' parameter is empty
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter.</param>
	/// <returns>
	/// None
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_IsMapInEffect(const FString& MapPath, FPICOIsMapInEffectDelegate InIsMapInEffectDelegate, int32 Ext);

	static FPICOImportMapByPathDelegate ImportMapByPathDelegate;
	/// <summary>
	/// Imports a map specified by its path. Supports zipped files.
	/// @note Supported by PICO devices with 6-DoF tracking and system version 5.8.0 or later.
	/// </summary>
	/// <param name="MapPath">(In) String. The path of the map to import.</param>
	/// <param name="InImportMapByPathDelegate">(In) Delegate for map import operations. The callback parameters are:
	/// - `0`: Success
	/// - `1`: Failure
	/// - `101`: File does not exist
	/// - `102`: File decompression failed
	/// - `103`: Map file is damaged
	/// - `104`:  Localization tracking is turned off
	/// - `106`: Error in obtaining current map information
	/// - `107`: The 'MapPath' parameter is empty
	/// </param>
	/// <param name="Ext">(In) Int, reserved parameter.</param>
	/// <returns>
	/// None
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ImportMapByPath(const FString& MapPath, FPICOImportMapByPathDelegate InImportMapByPathDelegate, int32 Ext);

	static FPICOEnterpriseIntDelegate SetWifiP2PDeviceNameDelegate;
	/// <summary>Sets a name for the WiFi P2P device.</summary>
	/// <param name="DeviceName">Device name. The maximum length is 30.</param>
	/// <param name="ext">Extension. Pass `0`.</param>	
	/// <param name="Delegate">Result callback:
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: `DeviceName` param is null
	/// * `102`: the length of `DeviceName` param exceeds the maximum length allowed
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetWifiP2PDeviceName(const FString& DeviceName, int Ext, FPICOEnterpriseIntDelegate Delegate);

	/// <summary>Gets the WiFi P2P device's name.</summary>
	/// <param name="Ext">Extension. Pass `0`.</param>
	/// <returns>The device's name.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetWifiP2PDeviceName(int Ext);

	/// <summary>Sets the usability of a specified system key.</summary>
	/// <param name="key">Specify the system key. Enumerations:
	/// * `ENTER_KEY`: the Enter key
	/// * `BACK_KEY`: the Back key
	/// * `VOLUME_KEY`: the Volume key
	/// </param>
	/// <param name="Ext">Specify the usability of the key:
	/// * `S_ON`: enable the key
	/// * `S_OFF`: disable the key
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SetSystemKeyUsability(ESystemKey key, int Ext);

	/// <summary>Sets a third-party app as the launcher.</summary>
	/// <param name="PackageName">Specify the package name of the app.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SetLauncher(FString PackageName);

	/// <summary>Sets up timing startup for the device.
	/// @note Only available for PICO 4 Enterprise, PICO G3, and PICO Neo3.
	/// </summary>
	/// <param name="hour">Specifies the hour.</param>
	/// <param name="minute">Specifies the minute.</param>
	/// <param name="repeat">Specifies the repeat mode:
	/// * `0`: only once
	/// * The first seven bits: represent which day of the week (Monday to Sunday) is selected for repeated startup. For example, 0x03 indicates executing repeated startup on Monday and Tuesday. 
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_OpenTimingStartup(int hour, int minute, int repeat);

	/// <summary>Disables scheduled auto startup for the device.
	/// @note Only supported by PICO Neo3 series, PICO 4 Enterprise, and PICO G3.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_CloseTimingStartup();

	/// <summary>Sets up timing shutdown for the device.
	/// @note Only available for PICO 4 Enterprise, PICO G3, and PICO Neo3.
	/// </summary>
	/// <param name="hour">Specifies the hour.</param>
	/// <param name="minute">Specifies the minute.</param>
	/// <param name="repeat">Specifies the repeat mode:
	/// * `0`: only once
	/// * The first seven bits: represent which day of the week (Monday to Sunday) is selected for repeated shutdown. For example, 0x03 indicates executing repeated shutdown on Monday and Tuesday.
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_OpenTimingShutdown(int hour, int minute, int repeat);

	/// <summary>Disables scheduled auto shutdown for the device.
	/// @note Only supported by PICO Neo3 series, PICO 4 Enterprise, and PICO G3.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_CloseTimingShutdown();

	/// <summary>Sets a time zone.</summary>
	/// <param name="TimeZone">Specify the time zone. You can get the time zones supported by the current device through `TimeZone.getAvailableIDs()`.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the `timeZone` param is null
	/// * `102`: the specified time zone is not supported
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_SetTimeZone(FString TimeZone);

	static FPICOEnterpriseIntDelegate AppCopyrightVerifyDelegate;	
	/// <summary>Checks whether the user has the entitlement to use the app.
	/// @note Only supported by PICO 4 Enterprise with system version 5.9.0 or later.
	/// </summary>
	/// <param name="PackageName">Specify the package name of the app.</param>
	/// <param name="Delegate">
	/// Below is the result callback:
	/// * `1`: failed to call the API
	/// One of the following is returned when the user has the entitlement to use the app:
	/// * `100`: the queried app is not in the entitlement check list
	/// * `101`: no internet connection and no cached data of the app
	/// * `102`: the user has the entitlement to use the app
	/// * `103`: internet exception, the local cache has found that the user has the entitlement to use the app
	/// One of the following is returned when the user doesn't have the entitlement to use the app:
	/// * `-102`: the user doesn't have the entitlement to use the app
	/// * `-103`: internet exception, and the user doesn't have the entitlement to use the app according to the local cached data
	/// * `-104`: the app's signature doesn't match the signature returned by the server
	/// * `-105`: internet exception, the local cache has found a mismatch between the app signature and the one returned by the server
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_AppCopyrightVerify(FString PackageName, FPICOEnterpriseIntDelegate Delegate);

	/// <summary>Goes to the environment texture check page.
	/// @note Only supported by 6DoF devices including PICO Neo3 with the enterprise mode enabled, PICO Neo3 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `-1`: not supported by the device
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static bool PE_GotoEnvironmentTextureCheck();

	/// <summary>Sets a system date.</summary>
	/// <param name="year">Specifies the year.</param>
	/// <param name="month">Specifies the month.</param>
	/// <param name="day">Specifies the day</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: failure, the button to automatically get the date is switched on
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetSystemDate(int year, int month, int day);

	/// <summary>Sets a system time.</summary>
	/// <param name="hourOfDay">Specifies the hour of the day.</param>
	/// <param name="minute">Specifies the minute.</param>
	/// <param name="second">Specifies the second.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: failure, the button to automatically get the date is switched on
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetSystemTime(int hourOfDay, int minute, int second);

	/// <summary>Gets the app(s) that are running.</summary>
	/// <returns>
	/// `ActivityManager.RunningAppProcessInfo[]`: Information about the running app(s).
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static TArray<FString> PE_GetRunningAppProcesses();

	/// <summary>Gets the foreground app.</summary>
	/// <returns>
	/// `ComponentName`: Information about the foreground app.
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetFocusedApp();

	/// <summary>Creates a virtual display.</summary>
	/// <param name="displayName">Specifies the name of the virtual display.</param>
	/// <param name="surface">Specifies the surface on which the virtual content is displayed.</param>
	/// <param name="width">Specifies the width of the virtual display.</param>
	/// <param name="height">Specifies the height of the virtual display.</param>
	/// <param name="densityDpi">Specifies the density of the virtual display in dpi. This value must be greater than `0`.</param>
	/// <param name="flags">A combination of virtual display flags:
	/// * `VIRTUAL_DISPLAY_FLAG_PUBLIC`: When this flag is set, the virtual display is public.
	/// * `VIRTUAL_DISPLAY_FLAG_PRESENTATION`: When this flag is set, the virtual display is registered as a presentation display.
	/// * `VIRTUAL_DISPLAY_FLAG_SECURE`: When this flag is set, the virtual display is considered secure.
	/// * `VIRTUAL_DISPLAY_FLAG_OWN_CONTENT_ONLY`: Only show this display's own content; do not mirror the content of another display.
	/// * `VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR`: Allows content to be mirrored on private displays when no content is being shown.
	/// </param>
	/// <returns>
	/// Returns the `displayID` for success, and `-101` for failure.
	/// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_CreateVirtualDisplay(FString displayName, int64 surface, int width, int height, int densityDpi, int flags);

	/// <summary>Sets a surface for the virtual display.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>
	/// <param name="surface">Specifies the surface to display virtual content.</param>          
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns>  	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetVirtualDisplaySurface(int displayId, int64 surface);

	/// <summary>Resizes the virtual display.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>
	/// <param name="width">Specifies a new width for the virtual display in pixels.</param>      
	/// <param name="height">Specifies a new height for the virtual display in pixels.</param>
	/// <param name="densityDpi">Specifies the density of the virtual display in dpi. This value must be greater than `0`.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ResizeVirtualDisplay(int displayId, int width, int height, int densityDpi);

	/// <summary>Injects the input event.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>
	/// <param name="action">Specifies the kind of action being performed, such as `ACTION_DOWN`.</param>      
	/// <param name="source">Specifies the state of any meta / modifier keys that were in effect when the event was generated.</param>
	/// <param name="x">Specifies the X coordinate of this event.</param>
	/// <param name="y">Specifies the Y coordinate of this event.</param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_InjectEventXY(int displayId, int action, int source, float x, float y);

	/// <summary>Injects the input event.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>
	/// <param name="action">Action code: either `ACTION_DOWN`, `ACTION_UP`, or `ACTION_MULTIPLE`.</param>      
	/// <param name="source">The source of the event.</param>
	/// <param name="keycode">The key code.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_InjectEventKeyCode(int displayId, int action, int source, int keycode);

	/// <summary>Starts an app on the virtual display.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>
	/// <param name="Intent">Specifies the intent of `startActivity`. The intent type is provied by Unity.</param>        
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartApp(int displayId, FIntent Intent);

	/// <summary>Destroys a virtual display.</summary>
	/// <param name="displayId">Specifies the ID of the virtual display.</param>     
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `101`: the specified virtual display does not exist
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ReleaseVirtualDisplay(int displayId);

	/// <summary>Sets a virtual environment.</summary>
	/// <param name="envPath">Specifies the path of the virtual environment file. If you pass `null`, the system's built-in virtual environment will be restored.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetVirtualEnvironment(FString envPath);

	/// <summary>Gets the current virtual environment.</summary>
	/// <returns>
	/// The current virtual environment, and `null` indicates the system's built-in virtual environment.
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetVirtualEnvironment();

	/// <summary>Starts a service.</summary>
	/// <param name="Intent">Specifies the service to start.</param>
	/// <returns>
	/// If the service is starting or already running, it returns the `ComponentName` of the actual service that has been started. Otherwise, if the service does not exist, it returns `null`.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_StartService(FIntent Intent);

	/// <summary>Starts a foreground service.</summary>
	/// <param name="Intent">Specifies the service to start.</param>
	/// <returns>
	/// If the service is starting or already running, it returns the `ComponentName` of the actual service that has been started. Otherwise, if the service does not exist, it returns `null`.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_StartForegroundService(FIntent Intent);

	/// <summary>Sends broadcast.</summary>
	/// <param name="Intent">Specifies the broadcast to send.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SendBroadcast(FIntent Intent);

	/// <summary>Sends ordered broadcast.</summary>
	/// <param name="Intent">Specifies the broadcast to send.</param>
	/// <param name="ReceiverPermission">(Optional) The broadcast receiver must hold the specified permissions in order to receive your broadcast. If it is null, no permissions are required.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SendOrderedBroadcast(FIntent Intent, FString ReceiverPermission);

	/// <summary>Keeps a process alive by raising its priority level.</summary>
	/// <param name="keepAlivePid">Specifies the PID of the process to keep alive.</param>
	/// <param name="flags">Specifies the flag. The API will perform relevant operation according to the flag value. Below are available values and corresponding operations:
	/// * `2`: raise priority level for the current process.
	/// * `1`: raise priority level for all the processes under the package of the current process.
	/// * `0`: cancelling the high priority level of flag `1` or `2`.
	/// </param>
	/// <param name="level">Specifies the priority level that the process is raised to. `1` indicates a high priority level in which adj is raised to 149.
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_KeepAliveBackground(int keepAlivePid, int flags, int level);

	/// <summary>Opens the IPD detection page.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_OpenIPDDetectionPage();

	/// <summary>Sets the height of the floor.
	/// @note Only available for 6DoF devices.
	/// </summary>
	/// <param name="height">Specifies the height of the floor in meters.</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// * `-2`: not supported by the device
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetFloorHeight(float height);

	/// <summary>Gets the height of the floor.
	/// @note Only available for 6DoF devices.
	/// </summary>
	/// <returns>The height of the floor in meters.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static float PE_GetFloorHeight();

	/// <summary>Gets timing startup settings for the device.
	/// @note Only available for PICO 4 Enterprise, PICO Neo3 Enterprise, PICO G3 with OS version 5.4.0 or later, and PICO Neo3 Pro with OS version 4.8.0/4.8.1 or later.
	/// </summary>
	/// <param name="ext">This parameter is only reserved for future use.</param>
	/// <returns>
	/// * `open`: Whether timing startup is open: `true` (opened); `false` (not opened).
	/// * `curTime`: The time for the next startup.
	/// * `time`: The time scheduled for startup.
	/// * `repeatMode`: The repeat mode.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetTimingStartupStatusTwo(int ext);

	/// <summary>Gets timing shutdown settings for the device.
	/// @note Only available for PICO 4 Enterprise, PICO Neo3 Enterprise, PICO G3 with OS version 5.4.0 or later, and PICO Neo3 Pro with OS version 4.8.0/4.8.1 or later.
	/// </summary>
	/// <param name="ext">This parameter is only reserved for future use.</param>
	/// <returns>
	/// * `open`: Whether timing shutdown is open: `true` (opened); `false` (not opened).
	/// * `curTime`: The time for next shutdown.
	/// * `time`: The time scheduled for shutdown.
	/// * `repeatMode`: The repeat mode.
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static FString PE_GetTimingShutDownStatusTwo(int ext);

	/// <summary>Gets the information about the bounds of the large space.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>`Point3D[]`: Information about the bounds of the large space.</returns>  	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetLargeSpaceBoundsInfo(TArray<FVector>& Points);
	
	static FPICOEnterpriseIntDelegate OpenLargeSpaceQuickModeDelegate;
	/// <summary>Enables the large space quick mode to quickly set a large space with specified settings.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="length">Specifies the length of the large space in meters. Value range: [3,10].</param>
	/// <param name="width">Specifies the width of the large space in meters. Value range: [3,10].</param>
	/// <param name="originType">Specifies how to set the origin:
	/// * `0`: auto set
	/// * `1`: set by scanning the marker
	/// </param>
	/// <param name="openVst">Specifies whether to open the video seethrough mode for setting the origin by scanning the marker.</param>   
	/// <param name="distance">Specifies the distance between the origin and the marker after scanning the marker. The minimum distance is 0.5 meters.</param>   
	/// <param name="timeout">Specifies the timeout duration for scanning the marker in a non-video-seethrough mode, in milliseconds. The default value is `10000`.</param>   
	/// <param name="delegate">The callback result:
	/// * `0`: success
	/// * `1`: failure
	/// * `-3`: parameter exceeds the valid value range
	/// * `104`: position tracking disabled
	/// * `201`: quick mode enabled
	/// * `203`: setting origin in this way is not supported
	/// * `204`: scanning marker timeout
	/// </param>   
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_OpenLargeSpaceQuickMode(int length, int width, int originType, bool openVst, float distance, int timeout, FPICOEnterpriseIntDelegate delegate);

	/// <summary>Disables the large space quick mode.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_CloseLargeSpaceQuickMode();

	static FPICOEnterpriseIntDelegate SetOriginOfLargeSpaceQuickModeDelegate;
	/// <summary>Sets the origin and positive orientation of the large space quick mode.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="originType">Specifies how to set the origin:
	/// * `0`: auto set
	/// * `1`: set by scanning the marker
	/// </param>
	/// <param name="openVst">Specifies whether to open the video seethrough mode for setting the origin by scanning the marker.</param>   
	/// <param name="distance">Specifies the distance between the origin and the marker after scanning the marker. The minimum distance is 0.5 meters.</param>   
	/// <param name="timeout">Specifies the timeout duration for scanning the marker in a non-video-seethrough mode, in milliseconds. The default value is `10000`.</param>   
	/// <param name="delegate">The callback result:
	/// * `0`: success
	/// * `1`: failure
	/// * `-3`: parameter exceeds the valid value range
	/// * `104`: position tracking disabled
	/// * `202`: quick mode disabled
	/// * `203`: setting origin in this way is not supported
	/// * `204`: scanning marker timeout
	/// </param> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetOriginOfLargeSpaceQuickMode(int originType, bool openVst, float distance, int timeout, FPICOEnterpriseIntDelegate delegate);

	static FPICOEnterpriseIntDelegate SetBoundaryOfLargeSpaceQuickModeDelegate;
	/// <summary>Sets ths size of the boundary for large space quick mode.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="length">Specifies the length of the boundary in meters. Value range: [3,10].</param>
	/// <param name="width">Specifies the width of the boundary in meters. Value range: [3,10].</param>
	/// <param name="delegate">The callback result:
	/// * `0`: success
	/// * `1`: failure
	/// * `-3`: parameter exceeds the valid value range
	/// * `104`: position tracking disabled
	/// * `202`: quick mode disabled
	/// </param>  	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetBoundaryOfLargeSpaceQuickMode(int length, int width, FPICOEnterpriseIntDelegate delegate);

	/// <summary>Gets the information about the large space quick mode.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>
	/// Information about the large space quick mode (`LargeSpaceQuickModeInfo`), including the following:
	/// * `status`: Whether the quick mode is enabled or disabled
	/// * `length`: The length of the boundary
	/// * `Width`: The width of the boundary
	/// * `originType`: The way to set the origin: `-1` (not set); `0` (default); `1` (by scanning the marker)
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_GetLargeSpaceQuickModeInfo(TArray<int>& infor);

	/// <summary>Pairs the left controller.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartLeftControllerPair();

	/// <summary>Unpairs the left controller.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_MakeLeftControllerUnPair();
	
	/// <summary>Pairs the right controller.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartRightControllerPair();

	/// <summary>Unpairs the right controller.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_MakeRightControllerUnPair();

	/// <summary>Stops pairing controllers.</summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StopControllerPair();

	/// <summary>Sets the preferred controller according to hand preferences.</summary>
	/// <param name="isLeft">Specifies the preferred controller:
	/// * `true`: left controller
	/// * `false`: right controller                
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetControllerPreferHand(bool isLeft);

	/// <summary>Sets a vibration amplitude for controllers.</summary>
	/// <param name="value">Specifies the amplitude. Value range: [0.6].</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetControllerVibrateAmplitude(int value);

	/// <summary>Sets the power mode.</summary>
	/// <param name="value">Specifies the power mode:
	/// * `0`: power-saving mode
	/// * `1`: standard mode
	/// * `2`: performance mode
	/// </param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>  
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetPowerManageMode(int value);

	/// <summary>Starts the Room Capture app.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>   
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartRoomMark();

	/// <summary>Clears room capture data.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ClearRoomMark();

	/// <summary>Clears eye tracking data.
	/// @note Only supported by devices with the eye tracking capability.
	/// </summary>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ClearEyeTrackData();

	/// <summary>Sets a frame rate for eye tracking.
	/// @note Only supported by devices with the eye tracking capability.
	/// </summary>
	/// <param name="value">Specifies the frame rate: 
	/// * `60`
	/// * `90`
	/// </param>     
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetEyeTrackRate(int value);

	/// <summary>Sets the tracking frequency.
	/// @note Only supported by6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="value">Specifies the tracking frequency in Hz:
	/// * `0`: auto
	/// * `50`
	/// * `60`
	/// </param>   
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetTrackFrequency(int value);

	/// <summary>Starts setting the boundary.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary> 
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartSetSecureBorder();

	/// <summary>Sets distance sensitivity for the boundary.
	/// @note Only supported by 6 DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="value">Specifies the sensitivity value. Value range: [150, 800].</param>   
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetDistanceSensitivity(int value);

	/// <summary>Sets speed sensitivity for the boundary.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="value">Specifies the speed sensitivity. Value range: [0,100].</param>   
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetSpeedSensitivity(int value);

	/// <summary>Sets the prediction coefficient for PICO Motion Tracker.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary>
	/// <param name="predictionCoefficient">Specifies the prediction coefficient. Value range: [0.0, 1.0].</param>   
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetMotionTrackerPredictionCoefficient(float predictionCoefficient);

	/// <summary>Gets the prediction coefficient of PICO Motion Tracker.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary> 
	/// <returns>The prediction coefficient.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static float PE_GetMotionTrackerPredictionCoefficient();

	/// <summary>Starts the PICO Motion Tracker app to perform calibration.
	/// @note Only supported by 6DoF devices, including PICO Neo3 Pro, PICO Neo3 Enterprise, and PICO 4 Enterprise.
	/// </summary> 
	/// <param name="failMode">Specifies the operation to execute when calibration fails:
	/// * `0`: default operation (neither auto restart nor auto close the app)
	/// * `1`: auto restart the app
	/// * `2`: auto close the app
	/// </param>
	/// <param name="avatarMode">Specifies the display effect of the calibration avatar pop-up after a successful calibration:
	/// * `0`: default
	/// * `-1`: do not display the pop-up
	/// * [1, 60]: the display duration of the pop-up, in seconds. It will automatically hide when exceeding the set duration.
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_StartMotionTrackerApp(int failMode, int avatarMode);

	/// <summary>Sets the source of the single-eye image.</summary> 
	/// <param name="isLeft">Specifies an eye as the single-eye image source:
	/// * `true`: left eye
	/// * `false`: right eye
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetSingleEyeSource(bool isLeft);

	/// <summary>Sets the visual effect of the view.</summary> 
	/// <param name="mode">Specifies the view mode:
	/// * `0`: wide-angle
	/// * `1`: standard
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetViewVisual(int mode);

	/// <summary>Sets whether to accept external screen casting.</summary> 
	/// <param name="mode">Specifies the mode:
	/// * `0`: ask every time
	/// * `1`: allow
	/// * `2`: reject
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetAcceptCastMode(int mode);

	/// <summary>Shares the screen to the external device.</summary> 
	/// <param name="mode">Specifies the mode:
	/// * `0`: ask every time
	/// * `1`: allow
	/// * `2`: reject
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetScreenCastMode(int mode);

	/// <summary>Set the aspect ratio for screen recording and screen capture.</summary> 
	/// <param name="mode">Specifies the ratio:
	/// * `0`:  1:1
	/// * `1`: 16:9
	/// * `2`: 9:16
	/// </param>    
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetScreenRecordShotRatio(int mode);

	/// <summary>Set the resolution for screen recording and screen capture.</summary> 
	/// <param name="width">Specifies the width.</param> 
	/// <param name="height">Specifies the height.</param> 
	/// The supported width and height values depend on the device's current aspect ratio.
	/// | Aspect Ratio | Supported Width & Height |
	/// |---|---|
	/// | 1:1 | 1920*1920 |
	/// | 16:9 | 1920*1080, 1280*720 |
	/// | 9:16 | 1080*1920, 720*1280 |
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetScreenResolution(int width, int height);

	/// <summary>Sets the frame rate for screen recording.</summary> 
	/// <param name="value">Specifies the frame rate. Valid values are: `24`, `30`, `36`.</param> 
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns>   
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetScreenRecordFrameRate(int value);

	/// <summary>Shows the global message dialog box.</summary>
	/// <param name="icon">Specifies the icon of the dialog box. You can pass `null` to use the default icon.</param>
	/// <param name="title">Specifies the title of the dialog box, with no length limit, truncated at the end if too long.</param>    
	/// <param name="body">Specifies the content of the dialog box, with no length limit, truncated at the end if too long.</param>
	/// <param name="time">The display duration is  (1-100)*1000, unit: milliseconds. 
	/// * `-1`: continuously display
	/// * `0`: collapse
	/// </param>
	/// <param name="gap">The spacing between the icon and title, in pixels. The default spacing is `0` if not specified. Value range: [0, 200].</param>
	/// <param name="position">Display position adjustment: Relative to the default position, move up or down. Down is positive, up is negative, in pixels. The default position is `0`. Value range: [-800, 800].</param>
	/// <returns>
	/// * `0`: success
	/// * `1`: failure
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ShowGlobalMessageDialog(UTexture2D* icon, FString title, FString body, int64 time, int gap, int position);
	
	/// <summary>Hides the global message dialog box.</summary> 	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_HideGlobalMessageDialog();

	/// <summary>Shows the global dialog box for status notification. The style of the dialog box is different from that of the big and small dialog boxes in `showGlobalBigStatusDialog` and `showGlobalSmallStatusDialog`.
	/// </summary> 
	/// <param name="icon">Specifies the icon of the dialog box. You can pass `null` to use the default icon.</param>
	/// <param name="title">Specifies the title of the dialog box, with no length limit, truncated at the end if too long.</param> 
	/// <param name="time">The display duration is  (1-100)*1000, unit: milliseconds. 
	/// * `-1`: continuously display
	/// * `0`: collapse
	/// </param> 
	/// <param name="position">Display position adjustment: Relative to the default position, move up or down. Down is positive, up is negative, in pixels. The default position is `0`. Value range: [0, 1600].</param> 
	/// <param name="bgColor">Specifies the background color of the dialog box. For example, Color.parseColor("#887766"). Pass `0` to use the default color.</param> 
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ShowGlobalTipsDialog(UTexture2D* icon, FString title, int64 time, int position, int bgColor);

	/// <summary>Hides the global tips dialog box.</summary> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_HideGlobalTipsDialog();

	/// <summary>Shows the big global dialog box for status notification. You can fill in content to be the body of the big dialog box.</summary> 
	/// <param name="icon">Specifies the icon of the dialog box. You can pass `null` to use the default icon.</param>
	/// <param name="title">Specifies the title of the dialog box, with no length limit, truncated at the end if too long.</param> 
	/// <param name="body">Specifies the content of the dialog box, with no length limit, truncated at the end if too long.</param>
	/// <param name="time">The display duration is  (1-100)*1000, unit: milliseconds. 
	/// * `-1`: continuously display
	/// * `0`: collapse
	/// </param> 
	/// <param name="gap">The spacing between the icon and title, in pixels. The default spacing is `0` if not specified. Value range: [0, 200].</param>
	/// <param name="position">Display position adjustment: Relative to the default position, move up or down. Down is positive, up is negative, in pixels. The default position is `0`. Value range: [-800, 800].
	/// </param> 
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ShowGlobalBigStatusDialog(UTexture2D* icon, FString title, FString body, int64 time, int gap, int position);

	/// <summary>Hides the big global dialog box for status notification.</summary> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_HideGlobalBigStatusDialog();

	/// <summary>Shows the small global dialog box for status notification. You cannot fill in content in the small box.</summary> 
	/// <param name="icon">Specifies the icon of the dialog box. You can pass `null` to use the default icon.</param>
	/// <param name="title">Specifies the title of the dialog box. If the title is too long, it will scroll for playback.</param> 
	/// <param name="time">The display duration is  (1-100)*1000, unit: milliseconds. 
	/// * `-1`: continuously display
	/// * `0`: collapse
	/// </param>
	/// <param name="gap">The spacing between the icon and title, in pixels. The default spacing is `0` if not specified. Value range: [0, 200].</param>
	/// <param name="position">Display position adjustment: Relative to the default position, move up or down. Down is positive, up is negative, in pixels. The default position is `0`. Value range: [-800, 800].</param> 
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ShowGlobalSmallStatusDialog(UTexture2D* icon, FString title, int64 time, int gap, int position);
	
	/// <summary>Hides the small global dialog box for status notification.</summary> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_HideGlobalSmallStatusDialog();

	/// <summary>Shows a specified type of global dialog box.</summary> 
	/// <param name="type">Specifies the type of dialog box to display:
	/// * `MESSAGE_DIALOG`: message notification
	/// * `STATUS_TIPS`: tips display
	/// * `STATUS_BIG_DIALOG`:  big dialog box for status notification
	/// * `STATUS_SMALL_DIALOG`: small dialog box for status notification
	/// </param>
	/// <param name="icon">Specifies the icon of the dialog box. You can pass `null` to use the default icon.</param>
	/// <param name="title">Specifies the title of the dialog box, with no length limit, truncated at the end if too long.</param> 
	/// <param name="body">Specifies the content of the dialog box, with no length limit, truncated at the end if too long.</param>
	/// <param name="time">The display duration is  (1-100)*1000, unit: milliseconds. 
	/// * `-1`: continuously display
	/// * `0`: collapse
	/// </param>        
	/// <param name="gap">The spacing between the icon and title, in pixels. The default spacing is `0` if not specified. Value range: [0, 200].</param>
	/// <param name="position">Display position adjustment: Relative to the default position, move up or down. Down is positive, up is negative, in pixels. The default position is `0`.
	/// * Value range for `STATUS_TIPS`: [0, 1600]
	/// * Value range for the rest: [-800, 800]
	/// </param>
	/// <param name="bgColor">Specifies the background color of the dialog box. For example, Color.parseColor("#887766"). Pass `0` to use the default color.</param>  
	/// <returns>
	/// * `0`: success
	/// * `1`: failure       
	/// </returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_ShowGlobalDialogByType(FString type, UTexture2D* icon, FString title, FString body, int64 time, int gap, int position, int bgColor);

	/// <summary>Hides a specified type of global dialog box.</summary> 
	/// <param name="type">Specifies the type of dialog box to hide:
	/// * `MESSAGE_DIALOG`: message notification
	/// * `STATUS_TIPS`: tips display
	/// * `STATUS_BIG_DIALOG`:  big dialog box for status notification
	/// * `STATUS_SMALL_DIALOG`: small dialog box for status notification
	/// </param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_HideGlobalDialogByType(FString type);

	static FPICOOnUpdateStatusChangedDelegate OnUpdateStatusChangedDelegate;
	static FPICOOnUpdateCompleteDelegate OnUpdateCompleteDelegate;
	/// <summary>Updates the device's system online.
	/// @note Only supported by PICO 4 Ultra Enterprise.</summary>
	/// <param name="UpdateCompleteDelegate">The callback of update status, progress, and result.</param>
	/// <returns>
	/// - `0`: success
	/// - `1`: failure
	/// - `2`: permission verification failed
	/// - `-1`: the API is deprecated
	/// - `-2`: not supported by the device
	/// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_OnlineSystemUpdate(const FPICOOnUpdateStatusChangedDelegate& UpdateStatusChangedDelegate, const FPICOOnUpdateCompleteDelegate& UpdateCompleteDelegate);
	
	static FPICOOnUpdateStatusChangedDelegate OnfflineUpdateStatusChangedDelegate;
	static FPICOOnUpdateCompleteDelegate OnfflineUpdateCompleteDelegate;
	/// <summary>Updates the device's system offline.
	/// @note Only supported by PICO 4 Ultra Enterprise.</summary>
	/// <param name="OtaFilePath">Path of Ota file.</param>
	/// <param name="AutoReboot">Whether to automatically reboot after the upgrade is completed.</param>
	/// <param name="ShowProgress">Whether to show the progress in the upgrade.</param>	
	/// <param name="UpdateStatusChangedDelegate"> The call back of update status.</param>
	/// <param name=" UpdateCompleteDelegate">The callback of update result.</param>
	/// <returns>
	/// - `0`: success
	/// - `1`: failure
	/// - `2`: permission verification failed
	/// - `-1`: the API is deprecated
	/// - `-2`: not supported by the device
	/// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_OfflineSystemUpdate(FString OtaFilePath, bool AutoReboot, bool ShowProgress, const FPICOOnUpdateStatusChangedDelegate& UpdateStatusChangedDelegate, const FPICOOnUpdateCompleteDelegate& UpdateCompleteDelegate);
	
	/// <summary>Recenters the forward direction of the headset's origin. This API has the same functionality as a long press of the Home button.</summary>
	/// <returns>
	/// - `0`: success
	/// - `1`: failure
	/// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_Recenter();

	static FPICOEnterpriseStringDelegate EnterpriseStringDelegate;
	/// <summary>Scans the QR code.
	/// @note Only supported by PICO 4 Enterprise and PICO 4 Ultra Enterprise.</summary>
	/// <param name="Delegate">Returns the callback for the scan result:
	/// - `-2`: not supported by the device
	/// - null: scanning the QR code failed
	/// - others: the information about the QR code scanned
	/// </param>	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ScanQRCode(const FPICOEnterpriseStringDelegate& Delegate);

	/// <summary>
	/// <Gets the vibration amplitude of controllers.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>The vibration amplitude that ranges from 0 to 6. The greater the value, the stronger the amplitude. Returning -2 indicates that the device does not support this API.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetControllerVibrateAmplitude();

	/// <summary>
	/// Sets a functionality for the volume button of the HMD.
	/// @note Only supported by PICO 4 Enterprise and PICO 4 Ultra.
	/// </summary>
	/// <param name="func">Specifies the functionality:
	/// - `0`: default (i.e., use the functionality set in system settings)
	/// - `1`: for adjusting the volume
	/// - `2`: for adjusting the IPD
	/// </param>
	/// <returns>
	/// - `0`: success
	/// - `1`: failure
	/// - `-2`: the device does not support this API
	/// - `-3`: the value specified for the parameter is invalid
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetHMDVolumeKeyFunc(int func);

	/// <summary>
	/// Gets the functionality of the volume button of the HMD.
	/// @note Only supported by PICO 4 Enterprise and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// - `0`: default (i.e., use the functionality set in system settings)
	/// - `1`: for adjusting the volume
	/// - `2`: for adjusting the IPD
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetHMDVolumeKeyFunc();

	/// <summary>
	/// Gets the device's power management mode.
	//// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// - For PICO 4 Ultra: `0` (power-saving mode); `1` (ensure the display quality first); `3` (ensure that multiple windows can work normally first)
	/// - For other device models: `0` (power-saving mode); `1` (standard mode); `2` (performance mode)
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetPowerManageMode();

	/// <summary>
	/// Gets the frame rate of eye tracking.
	/// @note Only supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.
	/// </summary>
	/// <returns>
	/// - `60`: 60Hz
	/// - `90`: 90Hz
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetEyeTrackRate();

	/// <summary>
	/// Gets the tracking frequency for camera and seethrough.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// - `0`: auto-adjusted frequency
	/// - `50`: 50Hz
	/// - `60`: 60Hz
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetTrackFrequency();

	/// <summary>
	/// Gets the device's distance sensing sensitivity.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, and PICO 4 Ultra.
	/// </summary>
	/// <returns>A sensitivity value that ranges from 150 to 800. The greater value, the higher the sensitivity. Returning -2 indicates that the device does not support this API.</returns> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetDistanceSensitivity();

	/// <summary>
	/// Gets the device's speed sensing sensitivity.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// A sensitivity value that ranges from 0 to 100. The greater the value, the higher the sensitivity.
	/// `-1`: the speed sensing switch is toggled off
	/// `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetSpeedSensitivity();

	/// <summary>
	/// Set the device's collision alert sensitivity.
	/// @note Only supported by PICO 4 Ultra.
	/// </summary>
	/// <param name="value">Specifies the sensitivity value. Value range: [0.0, 1.0]. The greater the value, the higher the sensitivity.</param>
	/// <returns>
	/// - `0`: success
	/// - `1`: failure
	/// - `-2`: the device does not support this API
	/// - `-3`: the specified value is out of the valid range
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_SetMRCollisionAlertSensitivity(float value);

	/// <summary>
	/// Gest the device's collision alert sensitivity.
	//// @note Only supported by PICO 4 Ultra.
	/// </summary>
	/// <returns>The sensitivity value that ranges from 0.0 to 1.0. Returning `-2` indicates that the device does not support this API.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static float PE_GetMRCollisionAlertSensitivity();

	/// <summary>
	/// Gets the eye that serves as the source of the monocular image.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	///</summary>
	/// <returns>
	/// - `0`: the left eye
	/// - `1`: the right eye
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetSingleEyeSource();

	/// <summary>
	//// Gets the device's view mode.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra. 
	/// </summary> 
	/// <returns>
	/// - `0`: wide-angle mode
	/// - `1`: standard mode
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetViewVisual();

	/// <summary>
	/// Gets whether the device accepts screen sharing from the external device.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// - `0`: ask every time
	/// - `1`: always allow
	/// - `2`: always reject
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetAcceptCastMode();

	/// <summary>
	/// Gets whether the device allows the sharing of its screen to the external device.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>
	/// - `0`: ask every time
	/// - `1`: always allow
	/// - `2`: always reject
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetScreenCastMode();

	/// <summary>
	/// Gets the aspect ratio for screen recording and screenshots.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>The aspect ratio:
	/// - `0` (1:1)
	/// - `1` (16:9)
	/// - `2` (9:16)
	/// - `-2` (the device does not support this API)
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetScreenRecordShotRatio();

	/// <summary>
	/// Gets the resolution for screen recording and screenshots.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, PICO G3, and PICO 4 Ultra.
	/// </summary>
	/// <returns>The resolution. The format is [width, height]. Returning [-2, -2] indicates that the device does not support this API.</returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static TArray<int32> PE_GetScreenResolution();

	/// <summary>
	/// Gets the frame rate for screen recording.
	/// @note Only supported by PICO Neo3 Pro/Pro Eye/Enterprise, PICO 4 Enterprise, and PICO G3.
	/// </summary>
	/// <returns>The frame rate:
	/// - `24`: 24fps
	/// - `30`: 30fps
	/// - `36`: 36fps
	/// - `-2`: the device does not support this API
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static int PE_GetScreenRecordFrameRate();

	/// <summary>Sets up the WiFi that the device connects to.</summary>
	/// <param name="SSID">Specified the SSID of the WiFi.</param>
	/// <param name="Password">Specifies the password of the WiFi.</param>
	/// <param name="ConnectWifiDelegate">The callback of connection status.</param>
	static FPICOEnterpriseIntDelegate ConnectWifiDelegate;
	/// <summary>Sets up the WiFi that the device connects to.</summary>
	/// <param name="SSID">Specified the SSID of the WiFi.</param>
	/// <param name="Password">Specifies the password of the WiFi.</param>
	/// <param name="ConnectWifiDelegate">The callback of connection status.</param>
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ConnectWifi(FString SSID, FString Password, const FPICOEnterpriseIntDelegate& ConnectWifiDelegate);

	/// <summary>Sets up WifiConfiguration and connects the device to this WiFi.</summary>
	/// <param name="SSID">Specifies the SSID of the WiFi.</param> 
	/// <param name="Password">Specifies the password of the WiFi.</param> 
	/// <param name="staticIP">Specifies the static IP address.</param> 
	/// <param name="subnet_mask">Specifies the subnet mask.</param> 
	/// <param name="gateway">Specifies the gateway.</param> 
	/// <param name="dns">Specifies the DNS.</param> 
	/// <param name="OutSSID">Returns the SSID of the WiFi connected.</param>
	/// <param name="OutPassword">Returns the password of the WiFi connected.</param> 
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_SetStaticIpConfiguration(FString SSID, FString Password, FString staticIP, FString subnet_mask, FString gateway, const TArray<FString>& dns, FString& OutSSID, FString& OutPassword);

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ToUnrealPose(FVector& UnrealTranslation, FQuat& UnrealOrientation, const FVector& RMUVector, const FQuat& RMUOrientation);
	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_ToRGBCameraPose(FVector& CameraTranslation, FQuat& CameraOrientation, const FRGBCameraParams& CameraParameters, const FVector& HeadTranslation, const FQuat& HeadOrientation);

	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_UpdateRenderTargetFromRGB(const TArray<uint8>& RawData, int32 Width, int32 Height, UTextureRenderTarget2D* RenderTarget2D, uint8 OverrideAlpha = 255);
	
	UFUNCTION(BlueprintCallable, Category = "PICO|Enterprise")
	static void PE_UpdateRenderTargetFromYUVNV21(const TArray<uint8>& RawData, int32 Width, int32 Height, UTextureRenderTarget2D* RenderTarget2D, uint8 OverrideAlpha = 255);
};