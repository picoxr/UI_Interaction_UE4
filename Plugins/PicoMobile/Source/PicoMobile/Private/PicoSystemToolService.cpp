// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.
#include "PicoSystemToolService.h"
#include "PicoJava.h"

TMap<EDeviceControlEnum,FPicoSetDeviceActionDelegate> UPicoSystemToolService::SetDeviceActionDelegates;
TMap<FAppManagerStruct,FPicoAppManagerDelegate> UPicoSystemToolService::AppManagerDelegates;
FPicoSetAutoConnectWifiDelegate UPicoSystemToolService::SetAutoConnectWifiDelegate;
FPicoClearAutoConnectWifiDelegate UPicoSystemToolService::ClearAutoConnectWifiDelegate;
TMap<EHomeEventEnum,FPicoSetHomeKeyDelegate> UPicoSystemToolService::SetHomeKeyDelegates;
TMap<EHomeEventEnum,FPicoSetHomeKeyAllDelegate> UPicoSystemToolService::SetHomeKeyAllDelegates;
TMap<bool,FPicoDisablePowerKeyDelegate> UPicoSystemToolService::DisablePowerKeyDelegates;
FPicoSetScreenOffDelayDelegate UPicoSystemToolService::SetScreenOffDelayDelegate;
FPicoWriteConfigFileToDataLocalDelegate UPicoSystemToolService::WriteConfigDelegate;
FPicoResetAllKeyToDefaultDelegate UPicoSystemToolService::ResetAllKeyDelegate;

// Sets default values for this component's properties
UPicoSystemToolService::UPicoSystemToolService()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPicoSystemToolService::BeginPlay()
{
	Super::BeginPlay();
	FPicoSystemToolService::BindToBService();	
}

void UPicoSystemToolService::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	FPicoSystemToolService::UnBindToBService();
}

// Called every frame
void UPicoSystemToolService::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UPicoSystemToolService::GetDeviceInfo(ESystemInfoEnum InfoEnum)
{
	return  FPicoSystemToolService::GetDeviceInfo(static_cast<int32>(InfoEnum));
}

void UPicoSystemToolService::SetDeviceAction(EDeviceControlEnum DeviceControlEnum,FPicoSetDeviceActionDelegate SetDeviceActionDelegate)
{
	SetDeviceActionDelegates.Add(DeviceControlEnum,SetDeviceActionDelegate);
	FPicoSystemToolService::SetDeviceAction(static_cast<int32>(DeviceControlEnum));
}

void UPicoSystemToolService::AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext,	FPicoAppManagerDelegate AppManagerDelegate)
{	
	FAppManagerStruct AppManagerStruct;
	AppManagerStruct.PackageControl = PackageControlEnum;
	AppManagerStruct.AppPath = Path;
	AppManagerDelegates.Add(AppManagerStruct,AppManagerDelegate);
	FPicoSystemToolService::ControlAppManger(static_cast<int32>(PackageControlEnum),Path,Ext);
}

void UPicoSystemToolService::SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext,FPicoSetAutoConnectWifiDelegate InSetAutoConnectWifiDelegate)
{
	SetAutoConnectWifiDelegate = InSetAutoConnectWifiDelegate;
	FPicoSystemToolService::SetAutoConnectWifi(WifiName,WifiPSD,Ext);
}

void UPicoSystemToolService::ClearAutoConnectWifi(FPicoClearAutoConnectWifiDelegate InClearAutoConnectWifiDelegate)
{
	ClearAutoConnectWifiDelegate = InClearAutoConnectWifiDelegate;
	FPicoSystemToolService::ClearAutoConnectWifi();	
}

void UPicoSystemToolService::SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum,FPicoSetHomeKeyDelegate SetHomeKeyDelegate)
{
	SetHomeKeyDelegates.Add(EventEnum,SetHomeKeyDelegate);
	FPicoSystemToolService::SetHomeKey(static_cast<int32>(EventEnum),static_cast<int32>(FunctionEnum));
}

void UPicoSystemToolService::SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup,FString Package, FString ClassName, FPicoSetHomeKeyAllDelegate SetHomeKeyAllDelegate)
{
	SetHomeKeyAllDelegates.Add(EventEnum,SetHomeKeyAllDelegate);
	FPicoSystemToolService::SetHomeKeyAll(static_cast<int32>(EventEnum),static_cast<int32>(FunctionEnum),TimeSetup,Package,ClassName);
}

void UPicoSystemToolService::DisablePowerKey(bool bIsSingleTap, bool bEnable,FPicoDisablePowerKeyDelegate InDisablePowerKeyDelegate)
{
	DisablePowerKeyDelegates.Add(bIsSingleTap,InDisablePowerKeyDelegate);
	FPicoSystemToolService::DisablePowerKey(bIsSingleTap,bEnable);
}

void UPicoSystemToolService::SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum,	FPicoSetScreenOffDelayDelegate InSetScreenOffDelayDelegate)
{
	SetScreenOffDelayDelegate = InSetScreenOffDelayDelegate;
	FPicoSystemToolService::SetScreenOffDelay(static_cast<int32>(TimeEnum));
}

void UPicoSystemToolService::SetSleepDelay(ESleepDelayTimeEnum TimeEnum)
{
	FPicoSystemToolService::SetSleepDelay(static_cast<int32>(TimeEnum));
}

void UPicoSystemToolService::SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext)
{
	FPicoSystemToolService::SwitchSystemFunction(static_cast<int32>(SystemFunction),static_cast<int32>(SwitchEnum),Ext);
}

void UPicoSystemToolService::SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext)
{
	FPicoSystemToolService::SetUsbConfigurationOption(static_cast<int32>(UsbConfigModeEnum),Ext);
}

void UPicoSystemToolService::ScreenOn()
{
	FPicoSystemToolService::ScreenOn();
}

void UPicoSystemToolService::ScreenOff()
{
	FPicoSystemToolService::ScreenOff();
}

void UPicoSystemToolService::AcquireWakeLock()
{
	FPicoSystemToolService::AcquireWakeLock();
}

void UPicoSystemToolService::ReleaseWakeLock()
{
	FPicoSystemToolService::ReleaseWakeLock();
}

void UPicoSystemToolService::WriteConfigFileToDataLocal(FString Path, FString Content,FPicoWriteConfigFileToDataLocalDelegate InWriteConfigDelegate)
{
	WriteConfigDelegate = InWriteConfigDelegate;
	FPicoSystemToolService::WriteConfigFileToDataLocal(Path,Content);
}

void UPicoSystemToolService::ResetAllKeyToDefault(FPicoResetAllKeyToDefaultDelegate InResetAllKeyDelegate)
{
	ResetAllKeyDelegate = InResetAllKeyDelegate;
	FPicoSystemToolService::ResetAllKeyToDefault();
}

void UPicoSystemToolService::EnableEnterKey()
{
	FPicoSystemToolService::EnableEnterKey();
}

void UPicoSystemToolService::DisableEnterKey()
{
	FPicoSystemToolService::DisableEnterKey();
}

void UPicoSystemToolService::EnableVolumeKey()
{
	FPicoSystemToolService::EnableVolumeKey();
}

void UPicoSystemToolService::DisableVolumeKey()
{
	FPicoSystemToolService::DisableVolumeKey();
}

void UPicoSystemToolService::EnableBackKey()
{
	FPicoSystemToolService::EnableBackKey();
}

void UPicoSystemToolService::DisableBackKey()
{
	FPicoSystemToolService::DisableBackKey();
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetDeviceActionCallBack(JNIEnv * env, jclass clazz,int EventType, int Result)
{
	if (EventType == 0)
	{
		if (UPicoSystemToolService::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT))
		{
			UPicoSystemToolService::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT)->ExecuteIfBound(Result);
			UPicoSystemToolService::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_REBOOT);
		}
	}else if (EventType == 1)
	{
		if (UPicoSystemToolService::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN))
		{
			UPicoSystemToolService::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN)->ExecuteIfBound(Result);
			UPicoSystemToolService::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAPPMangerCallBack(JNIEnv * env, jclass clazz,int EventType, jstring AppPath, int Result)
{
	FAppManagerStruct ManagerStruct;
	ManagerStruct.AppPath = FJavaHelper::FStringFromParam(env, AppPath);
	ManagerStruct.PackageControl = static_cast<EPackageControlEnum>(EventType);
	if(UPicoSystemToolService::AppManagerDelegates.Find(ManagerStruct))
	{
		UPicoSystemToolService::AppManagerDelegates.Find(ManagerStruct)->ExecuteIfBound(Result);
		UPicoSystemToolService::AppManagerDelegates.Remove(ManagerStruct);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoSystemToolService::SetAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoSystemToolService::SetAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCClearAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoSystemToolService::ClearAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoSystemToolService::ClearAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPicoSystemToolService::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoSystemToolService::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPicoSystemToolService::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPicoSystemToolService::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoSystemToolService::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPicoSystemToolService::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyAllCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPicoSystemToolService::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoSystemToolService::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPicoSystemToolService::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPicoSystemToolService::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoSystemToolService::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPicoSystemToolService::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCDisablePowerKeyCallBack(JNIEnv * env, jclass clazz,jboolean isSingleTap, int Result)
{
	if(isSingleTap == JNI_TRUE)
	{
		if(UPicoSystemToolService::DisablePowerKeyDelegates.Find(true))
		{
			UPicoSystemToolService::DisablePowerKeyDelegates.Find(true)->ExecuteIfBound(Result);
			UPicoSystemToolService::DisablePowerKeyDelegates.Remove(true);
		}
	}else
	{
		if(UPicoSystemToolService::DisablePowerKeyDelegates.Find(false))
		{
			UPicoSystemToolService::DisablePowerKeyDelegates.Find(false)->ExecuteIfBound(Result);
			UPicoSystemToolService::DisablePowerKeyDelegates.Remove(false);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCWriteConfigFileToDataLocalCallback(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoSystemToolService::WriteConfigDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoSystemToolService::WriteConfigDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCResetAllKeyToDefaultCallback(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoSystemToolService::ResetAllKeyDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoSystemToolService::ResetAllKeyDelegate.ExecuteIfBound(false);
	}
}
#endif