// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "../Launch/Resources/Version.h"
#include "IPicoMobilePlugin.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

class FPicoJava
{
public:
	static int32 VerifyAPP(FString appID, FString publicKey);
	static void HideLoading();
	static void SetHeadSensorData(float x, float y, float z, float w, float px, float py, float pz);
	static int32 GetLeftConConnectState();
	static int32 GetRightConConnectState();
	static void GetLeftControllerSensorData(float& x, float& y, float& z, float& w, float& px, float& py, float& pz);
	static void GetRightControllerSensorData(float& x, float& y, float& z, float& w, float& px, float& py, float& pz);
	static int32 GetLeftControllerTriggerToBoundary();
	static int32 GetRightControllerTriggerToBoundary();
	static int32 GetControllerSensorStatus(int32 Handness);
	static jclass GetRawClass();

	static int32 GetCurrentBrightness();
	static bool SetBrightness(int32 brightness);

	static int32 GetCurrentVolume();
	static int32 GetMaxVolumeNumber();
	static void SetVolume(int32 volume);
	static void VolumeUp();
	static void VolumeDown();

	static int32 GetHandness();
	static int32 GetControllerType();

	static int32 Pvr_GetPsensorState();

	static FString GetDeviceSN();
	static void PaymentLogin();
	static void PaymentLogout();
	static void PaymentGetUserInfo();
	static void PaymentPayWithCoin(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const int32& pico_coin_count);
	static void PaymentPayWithPayCode(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const FString& pay_code);
	static void PaymentQueryOrder(const FString& order_number);

	static FString GetObjectOrArray(FString id,int32 type);
	static FString GetSystemProperty(FString Kay);
};
#endif

class FPicoSystemToolService
{
public:
	static void BindToBService();
	static void UnBindToBService();
	static FString GetDeviceInfo(int32 Type);
	static void SetDeviceAction(int32 DeviceControlEnum);
	static void ControlAppManger(int32 PackageControlEnum,FString Path,int32 Ext);
	static void SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext);
	static void ClearAutoConnectWifi();
	static void SetHomeKey(int32 EventEnum, int32 FunctionEnum);
	static void SetHomeKeyAll(int32 EventEnum, int32 FunctionEnum, int32 TimeSetup, FString Package, FString ClassName);
	static void DisablePowerKey(bool bIsSingleTap, bool bEnable);
	static void SetSleepDelay(int32 TimeEnum);
	static void SetScreenOffDelay(int32 TimeEnum);
	static void SwitchSystemFunction(int32 SystemFunction, int32 SwitchEnum, int32 Ext);
	static void SetUsbConfigurationOption(int32 UsbConfigModeEnum, int32 Ext);
	static void ScreenOn();
	static void ScreenOff();
	static void AcquireWakeLock();
	static void ReleaseWakeLock();
	static void WriteConfigFileToDataLocal(FString Path, FString Content);
	static void ResetAllKeyToDefault();
	static void EnableEnterKey();
	static void DisableEnterKey();
	static void EnableVolumeKey();
	static void DisableVolumeKey();
	static void EnableBackKey();
	static void DisableBackKey();

};