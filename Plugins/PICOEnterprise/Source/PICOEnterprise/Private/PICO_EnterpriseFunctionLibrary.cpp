// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PICO_EnterpriseFunctionLibrary.h"

#include "IXRTrackingSystem.h"
#include "PICO_EnterpriseInterfaceWrapper.h"

DEFINE_LOG_CATEGORY_STATIC(PxrSystemAPI, Log, All);

TMap<EDeviceControlEnum, FPICOSetDeviceActionDelegate> UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates;
TMap<FAppManagerStruct, FPICOAppManagerDelegate> UPICOEnterpriseFunctionLibrary::AppManagerDelegates;
FPICOSetAutoConnectWifiDelegate UPICOEnterpriseFunctionLibrary::SetAutoConnectWifiDelegate;
FPICOClearAutoConnectWifiDelegate UPICOEnterpriseFunctionLibrary::ClearAutoConnectWifiDelegate;
TMap<EHomeEventEnum, FPICOSetHomeKeyDelegate> UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates;
TMap<EHomeEventEnum, FPICOSetHomeKeyAllDelegate> UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates;
TMap<bool, FPICODisablePowerKeyDelegate> UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates;
FPICOSetScreenOffDelayDelegate UPICOEnterpriseFunctionLibrary::SetScreenOffDelayDelegate;
FPICOWriteConfigFileToDataLocalDelegate UPICOEnterpriseFunctionLibrary::WriteConfigDelegate;
FPICOResetAllKeyToDefaultDelegate UPICOEnterpriseFunctionLibrary::ResetAllKeyDelegate;
FPICOSetWDJsonDelegate UPICOEnterpriseFunctionLibrary::SetWDJsonDelegate;
FPICOSetWDModelsDelegate UPICOEnterpriseFunctionLibrary::SetWDModelsDelegate;

FPICOEnableLargeSpaceDelegate UPICOEnterpriseFunctionLibrary::EnableLargeSpaceDelegate;
FPICOSwitchLargeSpaceStatusDelegate UPICOEnterpriseFunctionLibrary::SwitchLargeSpaceStatusDelegate;
FPICOExportMapsDelegate UPICOEnterpriseFunctionLibrary::ExportMapsDelegate;
FPICOImportMapsDelegate UPICOEnterpriseFunctionLibrary::ImportMapsDelegate;
FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate UPICOEnterpriseFunctionLibrary::ControlSetAutoConnectWIFIWithErrorCodeDelegate;
FPICOGetSwitchSystemFunctionStatusDelegate UPICOEnterpriseFunctionLibrary::GetSwitchSystemFunctionStatusDelegate;
FPICOCastInitDelegate UPICOEnterpriseFunctionLibrary::PICOCastInitDelegate;
FPICOSetControllerPairTimeDelegate UPICOEnterpriseFunctionLibrary::SetControllerPairTimeDelegate;
FPICOGetControllerPairTimeDelegate UPICOEnterpriseFunctionLibrary::GetControllerPairTimeDelegate;
FPICOSetSystemCountryCodeDelegate UPICOEnterpriseFunctionLibrary::SetSystemCountryCodeDelegate;
FPICOSetIPDDelegate UPICOEnterpriseFunctionLibrary::SetIPDDelegate;
FPICOSetArUcoMarkerDelegate UPICOEnterpriseFunctionLibrary::SetArUcoMarkerDelegate;
FPICOSetArUcoMarkerFDelegate UPICOEnterpriseFunctionLibrary::SetArUcoMarkerFDelegate;
FPICOFileCopyDelegate UPICOEnterpriseFunctionLibrary::FileCopyDelegate;
FPICOIsMapInEffectDelegate UPICOEnterpriseFunctionLibrary::IsMapInEffectDelegate;
FPICOImportMapByPathDelegate UPICOEnterpriseFunctionLibrary::ImportMapByPathDelegate;
UObject* UPICOEnterpriseFunctionLibrary::MarkerWorldContext = nullptr;
UObject* UPICOEnterpriseFunctionLibrary::MarkerFWorldContext = nullptr;

FPICOBindTobServiceDelegate UPICOEnterpriseFunctionLibrary::PICOBindTobServiceDelegate;
void UPICOEnterpriseFunctionLibrary::PE_BindTobService(FPICOBindTobServiceDelegate InPICOBindTobServiceDelegate)
{
	PICOBindTobServiceDelegate = InPICOBindTobServiceDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "BindTobService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCBindTobService(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::PICOBindTobServiceDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::PICOBindTobServiceDelegate.ExecuteIfBound(false);
	}
}
#endif

void UPICOEnterpriseFunctionLibrary::PE_UnBindTobService()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UnBindTobService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, ESwitchEnum SwitchEnum, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetControllerKeyState", "(III)I", false);
		Result = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)ControllerKeyEnum, (int)SwitchEnum, Ext);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetDeviceInfo(ESystemInfoEnum InfoEnum)
{
	FString Result = FString("");
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetDeviceInfo", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(InfoEnum));
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return  Result;
}

void UPICOEnterpriseFunctionLibrary::PE_SetDeviceAction(EDeviceControlEnum DeviceControlEnum, FPICOSetDeviceActionDelegate SetDeviceActionDelegate)
{
	SetDeviceActionDelegates.Add(DeviceControlEnum, SetDeviceActionDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetDeviceAction", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(DeviceControlEnum));
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext, FPICOAppManagerDelegate AppManagerDelegate)
{
	FAppManagerStruct AppManagerStruct;
	AppManagerStruct.PackageControl = PackageControlEnum;
	AppManagerStruct.AppPath = Path;
	AppManagerDelegates.Add(AppManagerStruct, AppManagerDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Path = Env->NewStringUTF(TCHAR_TO_UTF8(*Path));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "APPManger", "(ILjava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(PackageControlEnum), jstring_Path, Ext);
		Env->DeleteLocalRef(jstring_Path);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext, FPICOSetAutoConnectWifiDelegate InSetAutoConnectWifiDelegate)
{
	SetAutoConnectWifiDelegate = InSetAutoConnectWifiDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_WifiName = Env->NewStringUTF(TCHAR_TO_UTF8(*WifiName));
		jstring jstring_WifiPSD = Env->NewStringUTF(TCHAR_TO_UTF8(*WifiPSD));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetAutoConnectWIFI", "(Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jstring_WifiName, jstring_WifiPSD, Ext);
		Env->DeleteLocalRef(jstring_WifiName);
		Env->DeleteLocalRef(jstring_WifiPSD);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ClearAutoConnectWifi(FPICOClearAutoConnectWifiDelegate InClearAutoConnectWifiDelegate)
{
	ClearAutoConnectWifiDelegate = InClearAutoConnectWifiDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ClearAutoConnectWIFI", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, FPICOSetHomeKeyDelegate SetHomeKeyDelegate)
{
	SetHomeKeyDelegates.Add(EventEnum, SetHomeKeyDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHomeKey", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(EventEnum), static_cast<int32>(FunctionEnum));
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup, FString Package, FString ClassName, FPICOSetHomeKeyAllDelegate SetHomeKeyAllDelegate)
{
	SetHomeKeyAllDelegates.Add(EventEnum, SetHomeKeyAllDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Package = Env->NewStringUTF(TCHAR_TO_UTF8(*Package));
		jstring jstring_ClassName = Env->NewStringUTF(TCHAR_TO_UTF8(*ClassName));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHomeKeyAll", "(IIILjava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(EventEnum), static_cast<int32>(FunctionEnum), TimeSetup, jstring_Package, jstring_ClassName);
		Env->DeleteLocalRef(jstring_Package);
		Env->DeleteLocalRef(jstring_ClassName);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_DisablePowerKey(bool bIsSingleTap, bool bEnable, FPICODisablePowerKeyDelegate InDisablePowerKeyDelegate)
{

	DisablePowerKeyDelegates.Add(bIsSingleTap, InDisablePowerKeyDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisablePowerKey", "(ZZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, bIsSingleTap, bEnable);
	}
#endif
}

bool UPICOEnterpriseFunctionLibrary::PE_SetSystemAutoSleepTime(ESleepDelayTimeEnum TimeEnum)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSystemAutoSleepTime", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(TimeEnum));
	}
#endif
	return Result == 0;
}

void UPICOEnterpriseFunctionLibrary::PE_SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum, FPICOSetScreenOffDelayDelegate InSetScreenOffDelayDelegate)
{
	SetScreenOffDelayDelegate = InSetScreenOffDelayDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetScreenOffDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(TimeEnum));
	}
#endif
}

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::SwitchSystemFunctionDelegate;
void UPICOEnterpriseFunctionLibrary::PE_SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext, FPICOEnterpriseIntDelegate Delegate)
{
	SwitchSystemFunctionDelegate = Delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SwitchSystemFunction", "(III)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(SystemFunction), static_cast<int32>(SwitchEnum), Ext);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSwitchSystemFunctionCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SwitchSystemFunctionDelegate.ExecuteIfBound(Result);
}
#endif

void UPICOEnterpriseFunctionLibrary::PE_SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetUsbConfigurationOption", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(UsbConfigModeEnum), Ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ScreenOn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ScreenOff()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOff", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_AcquireWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AcquireWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ReleaseWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ReleaseWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_WriteConfigFileToDataLocal(FString Path, FString Content, FPICOWriteConfigFileToDataLocalDelegate InWriteConfigDelegate)
{
	WriteConfigDelegate = InWriteConfigDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Path = Env->NewStringUTF(TCHAR_TO_UTF8(*Path));
		jstring jstring_Content = Env->NewStringUTF(TCHAR_TO_UTF8(*Content));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "WriteConfigFileToDataLocal", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jstring_Path, jstring_Content);
		Env->DeleteLocalRef(jstring_Path);
		Env->DeleteLocalRef(jstring_Content);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ResetAllKeyToDefault(FPICOResetAllKeyToDefaultDelegate InResetAllKeyDelegate)
{
	ResetAllKeyDelegate = InResetAllKeyDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ResetAllKeyToDefault", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCResetAllKeyToDefaultCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	UPICOEnterpriseFunctionLibrary::ResetAllKeyDelegate.ExecuteIfBound(Result == JNI_TRUE);
}
#endif

void UPICOEnterpriseFunctionLibrary::PE_EnableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_DisableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_EnableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_DisableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_EnableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_DisableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetCurrentBrightness()
{
	int32 currentBrightness = -1;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetCurrentBrightness", "()I", false);
		currentBrightness = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return currentBrightness;
}

bool UPICOEnterpriseFunctionLibrary::PE_SetScreenBrightness(int Brightness, int Ext)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetScreenBrightness", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Brightness, Ext);
	}
#endif
	return Result == 0;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetCurrentVolume()
{
	int32 currentVolume = -1;
#if PLATFORM_ANDROID

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetCurrentVolume", "()I", false);
		currentVolume = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return currentVolume;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetMaxVolume()
{
	int32 maxVolume = -1;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetMaxVolumeNumber", "()I", false);
		maxVolume = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return maxVolume;
}

void UPICOEnterpriseFunctionLibrary::PE_SetVolume(int32 Volume)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetVolume", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, Volume);

	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_VolumeUp()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeUp", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif	
}

void UPICOEnterpriseFunctionLibrary::PE_VolumeDown()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeDown", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}


FString UPICOEnterpriseFunctionLibrary::PE_GetDeviceSN()
{
	ESystemInfoEnum systemInfo = ESystemInfoEnum::EQUIPMENT_SN;
	FString result = FString("");
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetDeviceInfo", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(systemInfo));
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return result;
}

void UPICOEnterpriseFunctionLibrary::PE_FreezeScreen(bool freeze)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "FreezeScreen", "(Z)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, freeze);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_KillAppsByPidOrPackageName(TArray<int> pids, TArray<FString> packageNames, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		int num = pids.Num();
		jintArray jPids = Env->NewIntArray(num);
		jint* jPidsArray = Env->GetIntArrayElements(jPids, 0);
		for (int32 i = 0; i < num; i++)
		{
			jPidsArray[i] = pids[i];
		}
		auto PackageNamesArray = NewScopedJavaObject(Env, (jobjectArray)Env->NewObjectArray(packageNames.Num(), FJavaWrapper::JavaStringClass, nullptr));
		for (uint32 Param = 0; Param < packageNames.Num(); Param++)
		{
			auto StringValue = FJavaHelper::ToJavaString(Env, packageNames[Param]);
			Env->SetObjectArrayElement(*PackageNamesArray, Param, *StringValue);
		}
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "KillAppsByPidOrPackageName", "([I[Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jPids, *PackageNamesArray, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_KillBackgroundAppsWithWhiteList(TArray<FString> packageNames, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto PackageNamesArray = NewScopedJavaObject(Env, (jobjectArray)Env->NewObjectArray(packageNames.Num(), FJavaWrapper::JavaStringClass, nullptr));
		for (uint32 Param = 0; Param < packageNames.Num(); Param++)
		{
			auto StringValue = FJavaHelper::ToJavaString(Env, packageNames[Param]);
			Env->SetObjectArrayElement(*PackageNamesArray, Param, *StringValue);
		}
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "KillBackgroundAppsWithWhiteList", "([Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *PackageNamesArray, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_OpenMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OpenMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

bool UPICOEnterpriseFunctionLibrary::PE_IsMiracastOn()
{
	bool result = false;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "IsMiracastOn", "()Z", false);
		result = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return result;
}

void UPICOEnterpriseFunctionLibrary::PE_CloseMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CloseMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_StartScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_StopScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StopScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ConnectWifiDisplay(const FWifiDisplayModel& Model)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto     deviceAddress = FJavaHelper::ToJavaString(Env, Model.deviceAddress);
		auto	 deviceName = FJavaHelper::ToJavaString(Env, Model.deviceName);
		auto     isAvailable = Model.isAvailable;
		auto     canConnect = Model.canConnect;
		auto     isRemembered = Model.isRemembered;
		auto	 statusCode = Model.statusCode;
		auto	 status = FJavaHelper::ToJavaString(Env, Model.status);
		auto	 description = FJavaHelper::ToJavaString(Env, Model.description);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ConnectWifiDisplay",
			"(Ljava/lang/String;Ljava/lang/String;ZZZILjava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *deviceAddress, *deviceName, isAvailable, canConnect, isRemembered, statusCode, *status, *description);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_DisConnectWifiDisplay()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisConnectWifiDisplay", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ForgetWifiDisplay(FString Address)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jaddress = FJavaHelper::ToJavaString(Env, Address);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ForgetWifiDisplay", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jaddress);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_RenameWifiDisplay(FString Address, FString NewName)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "RenameWifiDisplay", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method
			, *FJavaHelper::ToJavaString(Env, Address)
			, *FJavaHelper::ToJavaString(Env, NewName));
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_UpdateWifiDisplays()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UpdateWifiDisplays", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_GetConnectedWD(FWifiDisplayModel& Model)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetConnectedWD", "()Ljava/lang/String;", false);
		FString result = "";
		result = FJavaHelper::FStringFromLocalRef(Env, (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method));
		if (!result.IsEmpty())
		{
			TArray<FString> substring;
			result.ParseIntoArray(substring, TEXT("="), true);
			substring.RemoveAt(0);
			for (int i = 0; i < substring.Num(); i++)
			{
				if (substring[i].Contains(TEXT("'")))
				{
					substring[i].Split(TEXT("'"), nullptr, &substring[i]);
					substring[i].Split(TEXT("'"), &substring[i], nullptr);
				}
				else
				{
					substring[i].Split(TEXT(","), &substring[i], nullptr);
				}
			}
			Model.deviceAddress = substring[0];
			Model.deviceName = substring[1];
			Model.isAvailable = substring[2] == "true" ? true : false;
			Model.canConnect = substring[3] == "true" ? true : false;
			Model.isRemembered = substring[4] == "true" ? true : false;
			Model.statusCode = FCString::Atoi(*substring[5]);
			Model.status = substring[6];
			Model.description = substring[7];
		}
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetWDJson(FPICOSetWDJsonDelegate InSetWDJsonDelegate)
{
	SetWDJsonDelegate = InSetWDJsonDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetWDJson", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetWDModels(FPICOSetWDModelsDelegate InSetWDModelsDelegate)
{
	SetWDModelsDelegate = InSetWDModelsDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetWDModels", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}


void UPICOEnterpriseFunctionLibrary::PE_SwitchLargeSpaceScene(FPICOEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext)
{
	EnableLargeSpaceDelegate = InEnableLargeSpaceDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SwitchLargeSpaceScene", "(ZI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, open, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_GetSwitchLargeSpaceStatus(FPICOSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate, int ext)
{
	SwitchLargeSpaceStatusDelegate = InSwitchLargeSpaceStatusDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSwitchLargeSpaceStatus", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
}

bool UPICOEnterpriseFunctionLibrary::PE_SaveLargeSpaceMaps(int ext)
{
	bool result = false;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SaveLargeSpaceMaps", "(I)Z", false);
		result = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
	return result;
}

void UPICOEnterpriseFunctionLibrary::PE_ExportMaps(FPICOExportMapsDelegate InExportMapsDelegate, int ext)
{
	ExportMapsDelegate = InExportMapsDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ExportMaps", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ImportMaps(FPICOImportMapsDelegate InImportMapsDelegate, int ext)
{
	ImportMapsDelegate = InImportMapsDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ImportMaps", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_GetCpuUsages(TArray<float>& OutData)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetCpuUsages", "()[F", false);
		auto FloatValuesArray = NewScopedJavaObject(Env, (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method));
		jfloat* FloatValues = Env->GetFloatArrayElements(*FloatValuesArray, 0);
		jsize NumProducts = Env->GetArrayLength(*FloatValuesArray);
		OutData.Empty();
		for (int i = 0; i < NumProducts; i++)
		{
			OutData.Add(FloatValues[i]);
		}
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_GetDeviceTemperatures(int inType, int inSource, TArray<float>& OutData)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetDeviceTemperatures", "(II)[F", false);
		auto FloatValuesArray = NewScopedJavaObject(Env, (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, inType, inSource));
		jfloat* FloatValues = Env->GetFloatArrayElements(*FloatValuesArray, 0);
		jsize NumProducts = Env->GetArrayLength(*FloatValuesArray);
		OutData.Empty();
		for (int i = 0; i < NumProducts; i++)
		{
			OutData.Add(FloatValues[i]);
		}
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_Capture()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Capture", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_Record()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Record", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ControlSetAutoConnectWIFIWithErrorCode(FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate, FString ssid, FString pwd, int ext)
{
	ControlSetAutoConnectWIFIWithErrorCodeDelegate = InControlSetAutoConnectWIFIWithErrorCodeDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jSsid = FJavaHelper::ToJavaString(Env, ssid);
		auto jPwd = FJavaHelper::ToJavaString(Env, pwd);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ControlSetAutoConnectWIFIWithErrorCode", "(Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jSsid, *jPwd, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_AppKeepAlive(FString appPackageName, bool keepAlive, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jAppPackageName = FJavaHelper::ToJavaString(Env, appPackageName);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AppKeepAlive", "(Ljava/lang/String;ZI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jAppPackageName, keepAlive, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_TimingStartup(int year, int month, int day, int hour, int minute, bool open)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "TimingStartup", "(IIIIIZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, year, month, day, hour, minute, open);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_TimingShutdown(int year, int month, int day, int hour, int minute, bool open)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "TimingShutdown", "(IIIIIZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, year, month, day, hour, minute, open);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_StartVrSettingsItem(int vrSettingsEnum, bool hideOtherItem, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartVrSettingsItem", "(IZI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, vrSettingsEnum, hideOtherItem, ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SwitchVolumeToHomeAndEnter(ESwitchEnum switchEnum, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SwitchVolumeToHomeAndEnter", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)switchEnum, ext);
	}
#endif
}

ESwitchEnum UPICOEnterpriseFunctionLibrary::PE_IsVolumeChangeToHomeAndEnter()
{
	int i = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "IsVolumeChangeToHomeAndEnter", "()I", false);
		i = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return ESwitchEnum(i);
}

EInstallOTAReturnCode UPICOEnterpriseFunctionLibrary::PE_InstallOTAPackage(const FString& OtaPackagePath, int32 Ext)
{
	EInstallOTAReturnCode Result = EInstallOTAReturnCode::SUCCESS;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jOtaPackagePath = FJavaHelper::ToJavaString(Env, OtaPackagePath);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "InstallOTAPackage", "(Ljava/lang/String;I)I", false);
		int32 ResultCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jOtaPackagePath, Ext);
		Result = (EInstallOTAReturnCode)ResultCode;
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetAutoConnectWiFiConfig(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetAutoConnectWiFiConfig", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetTimingStartupStatus(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetTimingStartupStatus", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetTimingShutdownStatus(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetTimingShutdownStatus", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

EKeyState UPICOEnterpriseFunctionLibrary::PE_GetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, int32 Ext)
{
	EKeyState State = EKeyState::DISABLE;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerKeyState", "(II)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)ControllerKeyEnum, Ext);
		State = (EKeyState)ReturnCode;
	}
#endif
	return State;
}

ESwitchEnum UPICOEnterpriseFunctionLibrary::PE_GetPowerOffWithUSBCable(int32 Ext)
{
	ESwitchEnum Result = ESwitchEnum::S_OFF;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetPowerOffWithUSBCable", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (ESwitchEnum)ReturnCode;
	}
#endif
	return Result;
}

EScreenOffDelayTimeEnum UPICOEnterpriseFunctionLibrary::PE_GetScreenOffDelay(int32 Ext)
{
	EScreenOffDelayTimeEnum Result = EScreenOffDelayTimeEnum::NEVER;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenOffDelay", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (EScreenOffDelayTimeEnum)ReturnCode;
	}
#endif
	return Result;
}

ESleepDelayTimeEnum UPICOEnterpriseFunctionLibrary::PE_GetSleepDelay(int32 Ext)
{
	ESleepDelayTimeEnum Result = ESleepDelayTimeEnum::NEVER;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSleepDelay", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (ESleepDelayTimeEnum)ReturnCode;
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetPowerKeyStatus(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetPowerKeyStatus", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

EKeyState UPICOEnterpriseFunctionLibrary::PE_GetEnterKeyStatus(int32 Ext)
{
	EKeyState State = EKeyState::DISABLE;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetEnterKeyStatus", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		State = (EKeyState)ReturnCode;
	}
#endif
	return State;
}

EKeyState UPICOEnterpriseFunctionLibrary::PE_GetVolumeKeyStatus(int32 Ext)
{
	EKeyState State = EKeyState::DISABLE;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetVolumeKeyStatus", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		State = (EKeyState)ReturnCode;
	}
#endif
	return State;
}

EKeyState UPICOEnterpriseFunctionLibrary::PE_GetBackKeyStatus(int32 Ext)
{
	EKeyState State = EKeyState::DISABLE;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetBackKeyStatus", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		State = (EKeyState)ReturnCode;
	}
#endif
	return State;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetHomeKeyStatus(EHomeEventEnum HomeEventEnum, int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetHomeKeyStatus", "(II)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)HomeEventEnum, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetUsbConfigurationOption(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetUsbConfigurationOption", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetCurrentLauncher(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetCurrentLauncher", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_GetSwitchSystemFunctionStatus(FPICOGetSwitchSystemFunctionStatusDelegate InGetSwitchSystemFunctionStatusDelegate, ESystemFunctionSwitchEnum SystemFunctionSwitchEnum, int32 Ext)
{
	GetSwitchSystemFunctionStatusDelegate = InGetSwitchSystemFunctionStatusDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSwitchSystemFunctionStatus", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)SystemFunctionSwitchEnum, Ext);
	}
#endif
}

ECastReturnCode UPICOEnterpriseFunctionLibrary::PE_PICOCastInit(FPICOCastInitDelegate InPICOCastInitDelegate, int32 Ext)
{
	PICOCastInitDelegate = InPICOCastInitDelegate;
	ECastReturnCode Result = ECastReturnCode::FAIL;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastInit", "(I)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (ECastReturnCode)ReturnCode;
	}
#endif
	return Result;
}

ECastReturnCode UPICOEnterpriseFunctionLibrary::PE_PICOCastSetShowAuthorization(EPICOCastAuthorization Authorization, int32 Ext)
{
	ECastReturnCode Result = ECastReturnCode::SUCCESS;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastSetShowAuthorization", "(II)I", false);
		int32 ReturnCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)Authorization, Ext);
		Result = (ECastReturnCode)ReturnCode;
	}
#endif
	return Result;
}

EPICOCastAuthorization UPICOEnterpriseFunctionLibrary::PE_PICOCastGetShowAuthorization(int32 Ext)
{
	EPICOCastAuthorization Result = EPICOCastAuthorization::ASK_EVERY_TIME;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastGetShowAuthorization", "(I)I", false);
		int32 ResultCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (EPICOCastAuthorization)ResultCode;
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_PICOCastGetUrl(EPICOCastUrlTypeEnum UrlType, int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastGetUrl", "(II)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)UrlType, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

ECastReturnCode UPICOEnterpriseFunctionLibrary::PE_PICOCastStopCast(int32 Ext)
{
	ECastReturnCode Result = ECastReturnCode::SUCCESS;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastStopCast", "(I)I", false);
		int32 ResultCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		Result = (ECastReturnCode)ResultCode;
	}
#endif
	return Result;
}

ECastReturnCode UPICOEnterpriseFunctionLibrary::PE_PICOCastSetOption(EPICOCastOptionOrStatusEnum OptionEnum, EPICOCastOptionValueEnum ValueEnum, int32 Ext)
{
	ECastReturnCode Result = ECastReturnCode::SUCCESS;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastSetOption", "(III)I", false);
		int32 ResultCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)OptionEnum, (int)ValueEnum, Ext);
		Result = (ECastReturnCode)ResultCode;
	}
#endif
	return Result;
}

EPICOCastOptionValueEnum UPICOEnterpriseFunctionLibrary::PE_PICOCastGetOptionOrStatus(EPICOCastOptionOrStatusEnum OptionEnum, int32 Ext)
{
	EPICOCastOptionValueEnum Result = EPICOCastOptionValueEnum::OPTION_VALUE_RESOLUTION_AUTO;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "PICOCastGetOptionOrStatus", "(II)I", false);
		int32 ResultCode = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)OptionEnum, Ext);
		Result = (EPICOCastOptionValueEnum)ResultCode;
	}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_SetControllerPairTime(FPICOSetControllerPairTimeDelegate InSetControllerPairTimeDelegate, EControllerPairTimeEnum TimeEnum, int32 Ext)
{
	SetControllerPairTimeDelegate = InSetControllerPairTimeDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetControllerPairTime", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)TimeEnum, Ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_GetControllerPairTime(FPICOGetControllerPairTimeDelegate InGetControllerPairTimeDelegate, int32 Ext)
{
	GetControllerPairTimeDelegate = InGetControllerPairTimeDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerPairTime", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetSystemLanguage(const FString& SystemLanguage, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_SystemLanguage = FJavaHelper::ToJavaString(Env, SystemLanguage);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSystemLanguage", "(Ljava/lang/String;I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_SystemLanguage, Ext);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetSystemLanguage(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSystemLanguage", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_ConfigWifi(const FString& Ssid, const FString& Pwd, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_Ssid = FJavaHelper::ToJavaString(Env, Ssid);
		auto jstring_Pwd = FJavaHelper::ToJavaString(Env, Pwd);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ConfigWifi", "(Ljava/lang/String;Ljava/lang/String;I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_Ssid, *jstring_Pwd, Ext);
	}
#endif
	return Result;
}

TArray<FString> UPICOEnterpriseFunctionLibrary::PE_GetConfiguredWifi(int32 Ext)
{
	TArray<FString> Results;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetConfiguredWifi", "(I)[Ljava/lang/String;", false);
		jobjectArray JavaStringArray = (jobjectArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		jsize NumProducts = Env->GetArrayLength(JavaStringArray);
		for (int32 Index = 0; Index < NumProducts; ++Index)
		{
			jstring Result = (jstring)(Env->GetObjectArrayElement(JavaStringArray, Index));
			const char* JavaChars = Env->GetStringUTFChars(Result, 0);
			Results.Add(FString(UTF8_TO_TCHAR(JavaChars)));
			Env->ReleaseStringUTFChars(Result, JavaChars);
			Env->DeleteLocalRef(Result);
		}
	}
#endif
	return Results;
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetSystemCountryCode(FPICOSetSystemCountryCodeDelegate InSetSystemCountryCodeDelegate, const FString& CountryCode, int32 Ext)
{
	SetSystemCountryCodeDelegate = InSetSystemCountryCodeDelegate;
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_CountryCode = FJavaHelper::ToJavaString(Env, CountryCode);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSystemCountryCode", "(Ljava/lang/String;I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_CountryCode, Ext);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetSystemCountryCode(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSystemCountryCode", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetSkipInitSettingPage(int32 Flag, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSkipInitSettingPage", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Flag, Ext);
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetSkipInitSettingPage(int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSkipInitSettingPage", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_IsInitSettingComplete(int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "IsInitSettingComplete", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_StartActivity(const FString& PackageName, const FString& ClassName, const FString& Action, const FString& Extra, const TArray<FString>& Categories, const TArray<int32>& Flags, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartActivity", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[II)I", false);

		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Action);
		auto jstring_Extra = FJavaHelper::ToJavaString(Env, Extra);
		auto jstring_Default = FJavaHelper::ToJavaString(Env, TEXT(""));

		int32 CategorySize = Categories.Num();
		jobjectArray jarray_Categories = Env->NewObjectArray(CategorySize, Env->FindClass("java/lang/String"), *jstring_Default);
		for (int32 Index = 0; Index < CategorySize; ++Index)
		{
			auto jstring_Category = FJavaHelper::ToJavaString(Env, Categories[Index]);
			Env->SetObjectArrayElement(jarray_Categories, Index, *jstring_Category);
		}

		int32 FlagSize = Flags.Num();
		jintArray jarray_Flags = Env->NewIntArray(FlagSize);
		jint jint_Flags[FlagSize];
		for (int32 Index = 0; Index < FlagSize; ++Index)
		{
			jint_Flags[Index] = Flags[Index];
		}
		Env->SetIntArrayRegion(jarray_Flags, 0, FlagSize, jint_Flags);

		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName, *jstring_ClassName, *jstring_Action, *jstring_Extra, jarray_Categories, jarray_Flags, Ext);

		Env->DeleteLocalRef(jarray_Categories);
		Env->DeleteLocalRef(jarray_Flags);
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_CustomizeAppLibrary(const TArray<FString>& PackageNames, ESwitchEnum SwitchEnum, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CustomizeAppLibrary", "([Ljava/lang/String;II)I", false);

		auto jstring_Default = FJavaHelper::ToJavaString(Env, TEXT(""));
		int32 PackageNamesSize = PackageNames.Num();
		jobjectArray jarray_PackageNames = Env->NewObjectArray(PackageNamesSize, Env->FindClass("java/lang/String"), *jstring_Default);
		for (int32 Index = 0; Index < PackageNamesSize; ++Index)
		{
			auto jstring_PackageName = FJavaHelper::ToJavaString(Env, PackageNames[Index]);
			Env->SetObjectArrayElement(jarray_PackageNames, Index, *jstring_PackageName);
		}
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, jarray_PackageNames, (int)SwitchEnum, Ext);
		Env->DeleteLocalRef(jarray_PackageNames);
	}
#endif
	return Result;
}

TArray<int32> UPICOEnterpriseFunctionLibrary::PE_GetControllerBattery(int32 Ext)
{
	TArray<int32> Results;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerBattery", "(I)[I", false);
		jintArray JavaIntArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaIntArray != nullptr)
		{
			jint* JavaInts = Env->GetIntArrayElements(JavaIntArray, 0);
			if (JavaInts)
			{
				jsize IntsLen = Env->GetArrayLength(JavaIntArray);
				Results.Empty(IntsLen);
				for (int32 Idx = 0; Idx < IntsLen; Idx++)
				{
					Results.Add(JavaInts[Idx]);
				}
				Env->ReleaseIntArrayElements(JavaIntArray, JavaInts, 0);
			}
			Env->DeleteLocalRef(JavaIntArray);
		}
	}
#endif
	return Results;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetControllerConnectState(int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerConnectState", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetAppLibraryHideList(int32 Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetAppLibraryHideList", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetScreenCastAudioOutput(EScreencastAudioOutput ScreencastAudioOutput, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetScreenCastAudioOutput", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)ScreencastAudioOutput, Ext);
	}
#endif
	return Result;
}

EScreencastAudioOutput UPICOEnterpriseFunctionLibrary::PE_GetScreenCastAudioOutput(int32 Ext)
{
	EScreencastAudioOutput Result = EScreencastAudioOutput::AUDIO_SINK;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenCastAudioOutput", "(I)I", false);
		Result = (EScreencastAudioOutput)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
	UE_LOG(PxrSystemAPI, Warning, TEXT("Result: %d"), (int)Result);
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_CustomizeSettingsTabStatus(ECustomizeSettingsTab CustomizeSettingsTab, ESwitchEnum SwitchEnum, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CustomizeSettingsTabStatus", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)CustomizeSettingsTab, (int)SwitchEnum, Ext);
	}
#endif
	return Result;
}

ESwitchEnum UPICOEnterpriseFunctionLibrary::PE_GetCustomizeSettingsTabStatus(ECustomizeSettingsTab CustomizeSettingsTab, int32 Ext)
{
	ESwitchEnum Result = ESwitchEnum::S_ON;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetCustomizeSettingsTabStatus", "(II)I", false);
		Result = (ESwitchEnum)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)CustomizeSettingsTab, Ext);
	}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_SetIPD(FPICOSetIPDDelegate InSetIPDDelegate, float IPD)
{
	SetIPDDelegate = InSetIPDDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetIPD", "(F)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, IPD);
	}
#endif
}

int32 UPICOEnterpriseFunctionLibrary::PE_SetPICOCastMediaFormat(const FCastMediaFormat& CastMediaFormat, int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetPICOCastMediaFormat", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, CastMediaFormat.Bitrate, Ext);
	}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_SetArUcoMarker(UObject* InWorldContext, FPICOSetArUcoMarkerDelegate InSetArUcoMarkerDelegate)
{
	SetArUcoMarkerDelegate = InSetArUcoMarkerDelegate;
	MarkerWorldContext = InWorldContext;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetArUcoMarker", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_SetArUcoMarkerF(UObject* InWorldContext, FPICOSetArUcoMarkerFDelegate InSetArUcoMarkerFDelegate)
{
	SetArUcoMarkerFDelegate = InSetArUcoMarkerFDelegate;
	MarkerFWorldContext = InWorldContext;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetArUcoMarkerF", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

bool UPICOEnterpriseFunctionLibrary::PE_InitEnterpriseService(FString& Token)
{
	Token.Empty();
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetToken", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Token = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Token.Len() > 0;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GetHeadTrackingConfidence()
{
	return FInterfaceWrapper::GetInstance()->PE_GetHeadTrackingConfidence();
}

bool UPICOEnterpriseFunctionLibrary::PE_OpenVSTCamera()
{
	return FInterfaceWrapper::GetInstance()->PE_OpenVSTCamera();
}

bool UPICOEnterpriseFunctionLibrary::PE_CloseVSTCamera()
{
	return FInterfaceWrapper::GetInstance()->PE_CloseVSTCamera();
}

void FromFrameItemExtToFrameData(FVSTCameraFrameData& FrameData, const frame_item_ext_t& FrameItemExt)
{
	FrameData.FrameItem.CameraId = FrameItemExt.frame.camera_id;
	FrameData.FrameItem.Width = FrameItemExt.frame.width;
	FrameData.FrameItem.Height = FrameItemExt.frame.height;
	FrameData.FrameItem.Format = FrameItemExt.frame.format;
	FrameData.FrameItem.ExposureDuration = FrameItemExt.frame.exposure_duration;
	FrameData.FrameItem.Timestamp = FrameItemExt.frame.timestamp;
	FrameData.FrameItem.QTimerTimestamp = FrameItemExt.frame.qtimer_timestamp;
	FrameData.FrameItem.FrameNumber = FrameItemExt.frame.framenumber;
	FrameData.FrameItem.DataSize = FrameItemExt.frame.datasize;
	FrameData.FrameItem.Data.SetNum(FrameData.FrameItem.DataSize);
	FMemory::Memcpy(FrameData.FrameItem.Data.GetData(), FrameItemExt.frame.data, sizeof(uint8) * FrameData.FrameItem.DataSize);

	FrameData.bIsRGB = FrameItemExt.is_rgb;
	for (int32 X = 0; X < 4; X++)
	{
		for (int32 Y = 0; Y < 4; Y++)
		{
			FrameData.RGBTSWMatrix.M[X][Y] = static_cast<float>(FrameItemExt.rgb_tsw_matrix[X * 4 + Y]);
		}
	}
	FrameData.bIsAntiDistortion = FrameItemExt.is_anti_distortion;

	FrameData.SixDofPose.Pose.Timestamp = FrameItemExt.six_dof_pose.pose.timestamp;
	FrameData.SixDofPose.Pose.Translation = FVector(FrameItemExt.six_dof_pose.pose.x, FrameItemExt.six_dof_pose.pose.y, FrameItemExt.six_dof_pose.pose.z);
	FrameData.SixDofPose.Pose.Orientation = FQuat(FrameItemExt.six_dof_pose.pose.rx, FrameItemExt.six_dof_pose.pose.ry, FrameItemExt.six_dof_pose.pose.rz, FrameItemExt.six_dof_pose.pose.rw);
	FrameData.SixDofPose.Pose.Type = FrameItemExt.six_dof_pose.pose.type;
	FrameData.SixDofPose.Pose.Confidence = FrameItemExt.six_dof_pose.pose.confidence;
	FrameData.SixDofPose.Pose.PoseErrorType.Empty();
	int64 SixDofPoseError = FrameItemExt.six_dof_pose.pose.error;
	for (uint8 Index = 0; Index <= (uint8)EPoseErrorType::UNKNOWN_ERROR; ++Index)
	{
		int64 BitValue = 1LL << Index;
		if (BitValue & SixDofPoseError)
		{
			FrameData.SixDofPose.Pose.PoseErrorType.Add((EPoseErrorType)Index);
		}
	}
	FrameData.SixDofPose.Pose.PlaneHeight = FrameItemExt.six_dof_pose.pose.plane_height;
	FrameData.SixDofPose.Pose.PlaneStatus = FrameItemExt.six_dof_pose.pose.plane_status;
	FrameData.SixDofPose.Pose.RelocationStatus = FrameItemExt.six_dof_pose.pose.relocation_status;
	FrameData.SixDofPose.Pose.Reserved.SetNum(24);
	FMemory::Memcpy(FrameData.SixDofPose.Pose.Reserved.GetData(), FrameItemExt.six_dof_pose.pose.reserved, sizeof(FrameItemExt.six_dof_pose.pose.reserved));

	FrameData.SixDofPose.RelocationPose.Timestamp = FrameItemExt.six_dof_pose.relocation_pose.timestamp;
	FrameData.SixDofPose.RelocationPose.Translation = FVector(FrameItemExt.six_dof_pose.relocation_pose.x, FrameItemExt.six_dof_pose.relocation_pose.y, FrameItemExt.six_dof_pose.relocation_pose.z);
	FrameData.SixDofPose.RelocationPose.Orientation = FQuat(FrameItemExt.six_dof_pose.relocation_pose.rx, FrameItemExt.six_dof_pose.relocation_pose.ry, FrameItemExt.six_dof_pose.relocation_pose.rz, FrameItemExt.six_dof_pose.relocation_pose.rw);
	FrameData.SixDofPose.RelocationPose.Type = FrameItemExt.six_dof_pose.relocation_pose.type;
	FrameData.SixDofPose.RelocationPose.Confidence = FrameItemExt.six_dof_pose.relocation_pose.confidence;
	FrameData.SixDofPose.RelocationPose.PoseErrorType.Empty();
	int64 SixDofRelocationPoseError = FrameItemExt.six_dof_pose.relocation_pose.error;
	for (uint8 Index = 0; Index <= (uint8)EPoseErrorType::UNKNOWN_ERROR; ++Index)
	{
		int64 BitValue = 1LL << Index;
		if (BitValue & SixDofRelocationPoseError)
		{
			FrameData.SixDofPose.RelocationPose.PoseErrorType.Add((EPoseErrorType)Index);
		}
	}
	FrameData.SixDofPose.RelocationPose.PlaneHeight = FrameItemExt.six_dof_pose.relocation_pose.plane_height;
	FrameData.SixDofPose.RelocationPose.PlaneStatus = FrameItemExt.six_dof_pose.relocation_pose.plane_status;
	FrameData.SixDofPose.RelocationPose.RelocationStatus = FrameItemExt.six_dof_pose.relocation_pose.relocation_status;
	FrameData.SixDofPose.RelocationPose.Reserved.SetNum(24);
	FMemory::Memcpy(FrameData.SixDofPose.RelocationPose.Reserved.GetData(), FrameItemExt.six_dof_pose.relocation_pose.reserved, sizeof(FrameItemExt.six_dof_pose.relocation_pose.reserved));

	FrameData.SixDofPose.LinearVelocity = FVector(FrameItemExt.six_dof_pose.vx, FrameItemExt.six_dof_pose.vy, FrameItemExt.six_dof_pose.vz);
	FrameData.SixDofPose.LinearAcceleration = FVector(FrameItemExt.six_dof_pose.ax, FrameItemExt.six_dof_pose.ay, FrameItemExt.six_dof_pose.az);
	FrameData.SixDofPose.AngularVelocity = FVector(FrameItemExt.six_dof_pose.wx, FrameItemExt.six_dof_pose.wy, FrameItemExt.six_dof_pose.wz);
	FrameData.SixDofPose.AngularAcceleration = FVector(FrameItemExt.six_dof_pose.w_ax, FrameItemExt.six_dof_pose.w_ay, FrameItemExt.six_dof_pose.w_az);

	FrameData.SixDofPose.Reserved.SetNum(48);
	FMemory::Memcpy(FrameData.SixDofPose.Reserved.GetData(), FrameItemExt.six_dof_pose.reserved, sizeof(FrameItemExt.six_dof_pose.reserved));

	FrameData.Reserved.SetNum(64);
	FMemory::Memcpy(FrameData.Reserved.GetData(), FrameItemExt.reserved, sizeof(FrameItemExt.reserved));
}

bool UPICOEnterpriseFunctionLibrary::PE_AcquireVSTCameraFrame(FVSTCameraFrameData& FrameData)
{
	frame_item_ext_t FrameItemExt;
	if (!FInterfaceWrapper::GetInstance()->PE_AcquireVSTCameraFrame(FrameItemExt))
	{
		return false;
	}

	FromFrameItemExtToFrameData(FrameData, FrameItemExt);
	return true;
}

bool UPICOEnterpriseFunctionLibrary::PE_AcquireVSTCameraFrameAntiDistortion(const FString& Token, int32 Width, int32 Height, FVSTCameraFrameData& FrameData)
{
	frame_item_ext_t FrameItemExt;
	if (!FInterfaceWrapper::GetInstance()->PE_AcquireVSTCameraFrameAntiDistortion(TCHAR_TO_ANSI(*Token), Width, Height, FrameItemExt))
	{
		return false;
	}

	FromFrameItemExtToFrameData(FrameData, FrameItemExt);
	return true;
}

bool UPICOEnterpriseFunctionLibrary::PE_GetCameraParameters(const FString& Token, FRGBCameraParams& Params)
{
	rgb_camera_params RGBCameraParams;
	if (!FInterfaceWrapper::GetInstance()->PE_GetCameraParameters(TCHAR_TO_ANSI(*Token), RGBCameraParams))
	{
		return false;
	}

	Params.InternalF = FVector2D(RGBCameraParams.fx, RGBCameraParams.fy);
	Params.InternalC = FVector2D(RGBCameraParams.cx, RGBCameraParams.cy);
	Params.ExternalTranslation = FVector(RGBCameraParams.x, RGBCameraParams.y, RGBCameraParams.z);
	Params.ExternalOrientation = FQuat(RGBCameraParams.rx, RGBCameraParams.ry, RGBCameraParams.rz, RGBCameraParams.rw);
	return true;
}

int32 UPICOEnterpriseFunctionLibrary::PE_GotoSeeThroughFloorSetting(int32 Ext)
{
	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GotoSeeThroughFloorSetting", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
	}
#endif
	return Result;
}

int32 UPICOEnterpriseFunctionLibrary::PE_FileCopy(const FString& SourcePath, const FString& TargetPath, FPICOFileCopyDelegate InFileCopyDelegate)
{
	FileCopyDelegate = InFileCopyDelegate;

	int32 Result = 0;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "FileCopy", "(Ljava/lang/String;Ljava/lang/String;)I", false);
		auto jstring_SourcePath = FJavaHelper::ToJavaString(Env, SourcePath);
		auto jstring_TargetPath = FJavaHelper::ToJavaString(Env, TargetPath);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_SourcePath, *jstring_TargetPath);
	}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_IsMapInEffect(const FString& MapPath, FPICOIsMapInEffectDelegate InIsMapInEffectDelegate, int32 Ext)
{
	IsMapInEffectDelegate = InIsMapInEffectDelegate;

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isMapInEffect", "(Ljava/lang/String;I)V", false);
		auto jstring_MapPath = FJavaHelper::ToJavaString(Env, MapPath);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_MapPath, Ext);
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ImportMapByPath(const FString& MapPath, FPICOImportMapByPathDelegate InImportMapByPathDelegate, int32 Ext)
{
	ImportMapByPathDelegate = InImportMapByPathDelegate;

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ImportMapByPath", "(Ljava/lang/String;I)V", false);
		auto jstring_MapPath = FJavaHelper::ToJavaString(Env, MapPath);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_MapPath, Ext);
	}
#endif
}

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::SetWifiP2PDeviceNameDelegate;
void UPICOEnterpriseFunctionLibrary::PE_SetWifiP2PDeviceName(const FString& DeviceName, int Ext, FPICOEnterpriseIntDelegate Delegate)
{
	SetWifiP2PDeviceNameDelegate = Delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_DeviceName = FJavaHelper::ToJavaString(Env, DeviceName);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetWifiP2PDeviceName", "(Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_DeviceName, Ext);
	}
#endif
}

FString UPICOEnterpriseFunctionLibrary::PE_GetWifiP2PDeviceName(int Ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetWifiP2PDeviceName", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
}
	}
#endif
	return Result;
}

bool UPICOEnterpriseFunctionLibrary::PE_SetSystemKeyUsability(ESystemKey key, int Ext)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSystemKeyUsability", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)key, Ext);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_SetLauncher(FString PackageName)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, PackageName);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetLauncher", "(Ljava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_OpenTimingStartup(int hour, int minute, int repeat)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OpenTimingStartup", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, hour, minute, repeat);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_CloseTimingStartup()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CloseTimingStartup", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_OpenTimingShutdown(int hour, int minute, int repeat)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OpenTimingShutdown", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, hour, minute, repeat);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_CloseTimingShutdown()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CloseTimingShutdown", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result == 0;
}

bool UPICOEnterpriseFunctionLibrary::PE_SetTimeZone(FString TimeZone)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_TimeZone = FJavaHelper::ToJavaString(Env, TimeZone);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetTimeZone", "(Ljava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_TimeZone);
	}
#endif
	return Result == 0;
}

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::AppCopyrightVerifyDelegate;
void UPICOEnterpriseFunctionLibrary::PE_AppCopyrightVerify(FString PackageName, FPICOEnterpriseIntDelegate Delegate)
{
	AppCopyrightVerifyDelegate = Delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, PackageName);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AppCopyrightVerify", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName);
}
#endif
}

bool UPICOEnterpriseFunctionLibrary::PE_GotoEnvironmentTextureCheck()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GotoEnvironmentTextureCheck", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result == 0;
}

int UPICOEnterpriseFunctionLibrary::PE_SetSystemDate(int year, int month, int day)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSystemDate", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, year, month, day);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetSystemTime(int hourOfDay, int minute, int second)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSystemTime", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, hourOfDay, minute, second);
	}
#endif
	return Result;
}

TArray<FString> UPICOEnterpriseFunctionLibrary::PE_GetRunningAppProcesses()
{
	TArray<FString> Results;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getRunningAppProcesses", "()[Ljava/lang/String;", false);
		jobjectArray JavaStringArray = (jobjectArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaStringArray)
		{
			jsize NumProducts = Env->GetArrayLength(JavaStringArray);
			for (int32 Index = 0; Index < NumProducts; ++Index)
			{
				jstring Result = (jstring)(Env->GetObjectArrayElement(JavaStringArray, Index));
				const char* JavaChars = Env->GetStringUTFChars(Result, 0);
				Results.Add(FString(UTF8_TO_TCHAR(JavaChars)));
				Env->ReleaseStringUTFChars(Result, JavaChars);
				Env->DeleteLocalRef(Result);
			}
		}
	}
#endif
	return Results;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetFocusedApp()
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getFocusedApp", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
}
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_CreateVirtualDisplay(FString displayName, int64 surface, int width, int height, int densityDpi, int flags)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jobject* value = reinterpret_cast<jobject*>(surface);
		auto jstring_displayName = FJavaHelper::ToJavaString(Env, displayName);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "createVirtualDisplay", "(Ljava/lang/String;Ljava/lang/Object;IIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_displayName, *value, width, height, densityDpi, flags);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetVirtualDisplaySurface(int displayId, int64 surface)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jobject* value = reinterpret_cast<jobject*>(surface);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setVirtualDisplaySurface", "(ILjava/lang/Object;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId, *value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_ResizeVirtualDisplay(int displayId, int width, int height, int densityDpi)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "resizeVirtualDisplay", "(IIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId, width, height, densityDpi);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_InjectEventXY(int displayId, int action, int source, float x, float y)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "injectEvent", "(IIIFF)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId, action, source, x, y);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_InjectEventKeyCode(int displayId, int action, int source, int keycode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "injectEvent", "(IIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId, action, source, keycode);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_StartApp(int displayId, FIntent Intent)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, Intent.PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, Intent.ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Intent.Action);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startApp", "(ILjava/lang/String;ILjava/lang/String;ILjava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId, *jstring_PackageName, *jstring_ClassName, *jstring_Action);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_ReleaseVirtualDisplay(int displayId)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "releaseVirtualDisplay", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, displayId);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetVirtualEnvironment(FString envPath)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_envPath = FJavaHelper::ToJavaString(Env, envPath);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setVirtualEnvironment", "(Ljava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_envPath);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetVirtualEnvironment()
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getVirtualEnvironment", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_StartService(FIntent Intent)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, Intent.PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, Intent.ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Intent.Action);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startService", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName, *jstring_ClassName, *jstring_Action);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_StartForegroundService(FIntent Intent)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, Intent.PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, Intent.ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Intent.Action);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startForegroundService", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName, *jstring_ClassName, *jstring_Action);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return Result;
}


int UPICOEnterpriseFunctionLibrary::PE_SendBroadcast(FIntent Intent)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, Intent.PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, Intent.ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Intent.Action);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "sendBroadcast", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName, *jstring_ClassName, *jstring_Action);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SendOrderedBroadcast(FIntent Intent, FString ReceiverPermission)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_PackageName = FJavaHelper::ToJavaString(Env, Intent.PackageName);
		auto jstring_ClassName = FJavaHelper::ToJavaString(Env, Intent.ClassName);
		auto jstring_Action = FJavaHelper::ToJavaString(Env, Intent.Action);
		auto jstring_ReceiverPermission = FJavaHelper::ToJavaString(Env, ReceiverPermission);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "sendOrderedBroadcast", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_PackageName, *jstring_ClassName, *jstring_Action, *jstring_ReceiverPermission);
}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_KeepAliveBackground(int keepAlivePid, int flags, int level)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "keepAliveBackground", "(III)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, keepAlivePid, flags, level);
}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_OpenIPDDetectionPage()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "openIPDDetectionPage", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetFloorHeight(float height)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setFloorHeight", "(F)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, height);
}
#endif
	return Result;
}

float UPICOEnterpriseFunctionLibrary::PE_GetFloorHeight()
{
	float Result = 0.0f;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getFloorHeight", "()F", false);
		Result = FJavaWrapper::CallFloatMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetTimingStartupStatusTwo(int ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "pbsGetTimingStartupStatusTwo", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
}
#endif
	return Result;
}

FString UPICOEnterpriseFunctionLibrary::PE_GetTimingShutDownStatusTwo(int ext)
{
	FString Result;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "pbsGetTimingShutDownStatusTwo", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			Result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
}
#endif
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_GetLargeSpaceBoundsInfo(TArray<FVector>& OutData)
{
#if PLATFORM_ANDROID
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getLargeSpaceBoundsInfo", "()[F", false);
			auto FloatValuesArray = NewScopedJavaObject(Env, (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method));
			jfloat* FloatValues = Env->GetFloatArrayElements(*FloatValuesArray, 0);
			jsize NumProducts = Env->GetArrayLength(*FloatValuesArray);
			OutData.Empty();
			for (int i = 0; i < NumProducts; i = i + 3)
			{
				OutData.Add(FVector(FloatValues[i], FloatValues[i + 1], FloatValues[i + 2]));
			}
}
#endif
}

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::OpenLargeSpaceQuickModeDelegate;
void UPICOEnterpriseFunctionLibrary::PE_OpenLargeSpaceQuickMode(int length, int width, int originType, bool openVst, float distance, int timeout, FPICOEnterpriseIntDelegate delegate)
{
	OpenLargeSpaceQuickModeDelegate = delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "openLargeSpaceQuickMode", "(IIIZFI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, length, width, originType, openVst, distance, timeout);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCopenLargeSpaceQuickModeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::OpenLargeSpaceQuickModeDelegate.ExecuteIfBound(Result);
}
#endif

void UPICOEnterpriseFunctionLibrary::PE_CloseLargeSpaceQuickMode()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "closeLargeSpaceQuickMode", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::SetOriginOfLargeSpaceQuickModeDelegate;
void UPICOEnterpriseFunctionLibrary::PE_SetOriginOfLargeSpaceQuickMode(int originType, bool openVst, float distance, int timeout, FPICOEnterpriseIntDelegate delegate)
{
	SetOriginOfLargeSpaceQuickModeDelegate = delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setOriginOfLargeSpaceQuickMode", "(IZFI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, originType, openVst, distance, timeout);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCsetOriginOfLargeSpaceQuickModeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetOriginOfLargeSpaceQuickModeDelegate.ExecuteIfBound(Result);
}
#endif

FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::SetBoundaryOfLargeSpaceQuickModeDelegate;
void UPICOEnterpriseFunctionLibrary::PE_SetBoundaryOfLargeSpaceQuickMode(int length, int width, FPICOEnterpriseIntDelegate delegate)
{
	SetBoundaryOfLargeSpaceQuickModeDelegate = delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setBoundaryOfLargeSpaceQuickMode", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, length, width);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCsetBoundaryOfLargeSpaceQuickModeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetBoundaryOfLargeSpaceQuickModeDelegate.ExecuteIfBound(Result);
}
#endif

void UPICOEnterpriseFunctionLibrary::PE_GetLargeSpaceQuickModeInfo(TArray<int>& infor)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getLargeSpaceQuickModeInfo", "()[I", false);
		auto IntValuesArray = NewScopedJavaObject(Env, (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method));
		if (!IntValuesArray)
		{
			return;
		}
		jint* IntValues = Env->GetIntArrayElements(*IntValuesArray, 0);
		jsize Size = Env->GetArrayLength(*IntValuesArray);
		infor.Reset(Size);
		for (int i = 0; i < Size; i++)
		{
			infor.Add(IntValues[i]);
		}
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_StartLeftControllerPair()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startLeftControllerPair", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_MakeLeftControllerUnPair()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "makeLeftControllerUnPair", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_StartRightControllerPair()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startRightControllerPair", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_MakeRightControllerUnPair()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "makeRightControllerUnPair", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_StopControllerPair()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "stopControllerPair", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetControllerPreferHand(bool isLeft)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setControllerPreferHand", "(Z)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, isLeft);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetControllerVibrateAmplitude(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setControllerVibrateAmplitude", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetPowerManageMode(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setPowerManageMode", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_StartRoomMark()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startRoomMark", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_ClearRoomMark()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearRoomMark", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_ClearEyeTrackData()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearEyeTrackData", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetEyeTrackRate(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setEyeTrackRate", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetTrackFrequency(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setTrackFrequency", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_StartSetSecureBorder()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startSetSecureBorder", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetDistanceSensitivity(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setDistanceSensitivity", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetSpeedSensitivity(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSpeedSensitivity", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetMotionTrackerPredictionCoefficient(float predictionCoefficient)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setMotionTrackerPredictionCoefficient", "(F)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, predictionCoefficient);
	}
#endif
	return Result;
}

float UPICOEnterpriseFunctionLibrary::PE_GetMotionTrackerPredictionCoefficient()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMotionTrackerPredictionCoefficient", "()F", false);
		return FJavaWrapper::CallFloatMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return 0;
}

int UPICOEnterpriseFunctionLibrary::PE_StartMotionTrackerApp(int failMode, int avatarMode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startMotionTrackerApp", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, failMode, avatarMode);
}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetSingleEyeSource(bool isLeft)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setSingleEyeSource", "(Z)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, isLeft);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetViewVisual(int mode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setViewVisual", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, mode);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetAcceptCastMode(int mode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setAcceptCastMode", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, mode);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetScreenCastMode(int mode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setScreenCastMode", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, mode);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetScreenRecordShotRatio(int mode)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setScreenRecordShotRatio", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, mode);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetScreenResolution(int width, int height)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setScreenResolution", "(II)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, width, height);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetScreenRecordFrameRate(int value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "setScreenRecordFrameRate", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_ShowGlobalMessageDialog(UTexture2D* icon, FString title, FString body, int64 time, int gap, int position)
{
	int Result = INT_MAX;

	FByteBulkData* RawImageData = nullptr;
	int ImageWidth = 0;
	int ImageHeight = 0;
	int PixelNum = 0;
	const uint8* RawBytes = nullptr;
	if (icon && icon->GetPixelFormat() == EPixelFormat::PF_B8G8R8A8)
	{
		ensure(icon->GetNumMips() > 0);
		FTexture2DMipMap* Mip0 = &icon->GetPlatformData()->Mips[0];
		RawImageData = &Mip0->BulkData;
		ImageWidth = icon->GetSizeX();
		ImageHeight = icon->GetSizeY();
		PixelNum = ImageWidth * ImageHeight;
		RawBytes = static_cast<const uint8*>(RawImageData->Lock(LOCK_READ_ONLY));
	}
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jbyteArray RawBuffer = Env->NewByteArray(PixelNum * 4);
		Env->SetByteArrayRegion(RawBuffer, 0, PixelNum * 4, reinterpret_cast<const jbyte*>(RawBytes));
		auto jstring_title = FJavaHelper::ToJavaString(Env, title);
		auto jstring_body = FJavaHelper::ToJavaString(Env, body);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showGlobalMessageDialog", "([BLjava/lang/String;Ljava/lang/String;JIIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, RawBuffer, *jstring_title, *jstring_body, static_cast<jlong>(time), gap, position, ImageWidth, ImageHeight);
		Env->DeleteLocalRef(RawBuffer);
	}
#endif
	if (PixelNum)
	{
		RawImageData->Unlock();
	}
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_HideGlobalMessageDialog()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hideGlobalMessageDialog", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_ShowGlobalTipsDialog(UTexture2D* icon, FString title, int64 time, int position, int bgColor)
{
	int Result = INT_MAX;
	FByteBulkData* RawImageData = nullptr;
	int ImageWidth = 0;
	int ImageHeight = 0;
	int PixelNum = 0;
	const uint8* RawBytes = nullptr;
	if (icon && icon->GetPixelFormat() == EPixelFormat::PF_B8G8R8A8)
	{
		ensure(icon->GetNumMips() > 0);
		FTexture2DMipMap* Mip0 = &icon->GetPlatformData()->Mips[0];
		RawImageData = &Mip0->BulkData;
		ImageWidth = icon->GetSizeX();
		ImageHeight = icon->GetSizeY();
		PixelNum = ImageWidth * ImageHeight;
		RawBytes = static_cast<const uint8*>(RawImageData->Lock(LOCK_READ_ONLY));
	}
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jbyteArray RawBuffer = Env->NewByteArray(PixelNum * 4);
		Env->SetByteArrayRegion(RawBuffer, 0, PixelNum * 4, reinterpret_cast<const jbyte*>(RawBytes));
		auto jstring_title = FJavaHelper::ToJavaString(Env, title);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showGlobalTipsDialog", "([BLjava/lang/String;JIIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, RawBuffer, *jstring_title, static_cast<jlong>(time), position, bgColor, ImageWidth, ImageHeight);
		Env->DeleteLocalRef(RawBuffer);
	}
#endif
	if (PixelNum)
	{
		RawImageData->Unlock();
	}
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_HideGlobalTipsDialog()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hideGlobalTipsDialog", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_ShowGlobalBigStatusDialog(UTexture2D* icon, FString title, FString body, int64 time, int gap, int position)
{
	int Result = INT_MAX;
	FByteBulkData* RawImageData = nullptr;
	int ImageWidth = 0;
	int ImageHeight = 0;
	int PixelNum = 0;
	const uint8* RawBytes = nullptr;
	if (icon && icon->GetPixelFormat() == EPixelFormat::PF_B8G8R8A8)
	{
		ensure(icon->GetNumMips() > 0);
		FTexture2DMipMap* Mip0 = &icon->GetPlatformData()->Mips[0];
		RawImageData = &Mip0->BulkData;
		ImageWidth = icon->GetSizeX();
		ImageHeight = icon->GetSizeY();
		PixelNum = ImageWidth * ImageHeight;
		RawBytes = static_cast<const uint8*>(RawImageData->Lock(LOCK_READ_ONLY));
	}
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jbyteArray RawBuffer = Env->NewByteArray(PixelNum * 4);
		Env->SetByteArrayRegion(RawBuffer, 0, PixelNum * 4, reinterpret_cast<const jbyte*>(RawBytes));
		auto jstring_title = FJavaHelper::ToJavaString(Env, title);
		auto jstring_body = FJavaHelper::ToJavaString(Env, body);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showGlobalBigStatusDialog", "([BLjava/lang/String;Ljava/lang/String;JIIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, RawBuffer, *jstring_title, *jstring_body, static_cast<jlong>(time), gap, position, ImageWidth, ImageHeight);
		Env->DeleteLocalRef(RawBuffer);
	}
#endif
	if (PixelNum)
	{
		RawImageData->Unlock();
	}
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_HideGlobalBigStatusDialog()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hideGlobalBigStatusDialog", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_ShowGlobalSmallStatusDialog(UTexture2D* icon, FString title, int64 time, int gap, int position)
{
	int Result = INT_MAX;
	FByteBulkData* RawImageData = nullptr;
	int ImageWidth = 0;
	int ImageHeight = 0;
	int PixelNum = 0;
	const uint8* RawBytes = nullptr;
	if (icon && icon->GetPixelFormat() == EPixelFormat::PF_B8G8R8A8)
	{
		ensure(icon->GetNumMips() > 0);
		FTexture2DMipMap* Mip0 = &icon->GetPlatformData()->Mips[0];
		RawImageData = &Mip0->BulkData;
		ImageWidth = icon->GetSizeX();
		ImageHeight = icon->GetSizeY();
		PixelNum = ImageWidth * ImageHeight;
		RawBytes = static_cast<const uint8*>(RawImageData->Lock(LOCK_READ_ONLY));
	}
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jbyteArray RawBuffer = Env->NewByteArray(PixelNum * 4);
		Env->SetByteArrayRegion(RawBuffer, 0, PixelNum * 4, reinterpret_cast<const jbyte*>(RawBytes));
		auto jstring_title = FJavaHelper::ToJavaString(Env, title);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showGlobalSmallStatusDialog", "([BLjava/lang/String;JIIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, RawBuffer, *jstring_title, static_cast<jlong>(time), gap, position, ImageWidth, ImageHeight);
		Env->DeleteLocalRef(RawBuffer);
	}
#endif
	if (PixelNum)
	{
		RawImageData->Unlock();
	}
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_HideGlobalSmallStatusDialog()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hideGlobalSmallStatusDialog", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_ShowGlobalDialogByType(FString type, UTexture2D* icon, FString title, FString body, int64 time, int gap, int position, int bgColor)
{
	int Result = INT_MAX;
	FByteBulkData* RawImageData = nullptr;
	int ImageWidth = 0;
	int ImageHeight = 0;
	int PixelNum = 0;
	const uint8* RawBytes = nullptr;
	if (icon && icon->GetPixelFormat() == EPixelFormat::PF_B8G8R8A8)
	{
		ensure(icon->GetNumMips() > 0);
		FTexture2DMipMap* Mip0 = &icon->GetPlatformData()->Mips[0];
		RawImageData = &Mip0->BulkData;
		ImageWidth = icon->GetSizeX();
		ImageHeight = icon->GetSizeY();
		PixelNum = ImageWidth * ImageHeight;
		RawBytes = static_cast<const uint8*>(RawImageData->Lock(LOCK_READ_ONLY));
	}
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jbyteArray RawBuffer = Env->NewByteArray(PixelNum * 4);
		Env->SetByteArrayRegion(RawBuffer, 0, PixelNum * 4, reinterpret_cast<const jbyte*>(RawBytes));
		auto jstring_type = FJavaHelper::ToJavaString(Env, type);
		auto jstring_title = FJavaHelper::ToJavaString(Env, title);
		auto jstring_body = FJavaHelper::ToJavaString(Env, body);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "showGlobalDialogByType", "(Ljava/lang/String;[BLjava/lang/String;Ljava/lang/String;JIIIII)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_type, RawBuffer, *jstring_title, *jstring_body, static_cast<jlong>(time), gap, position, bgColor, ImageWidth, ImageHeight);
		Env->DeleteLocalRef(RawBuffer);
	}
#endif
	if (PixelNum)
	{
		RawImageData->Unlock();
	}
	return Result;
}

void UPICOEnterpriseFunctionLibrary::PE_HideGlobalDialogByType(FString type)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_type = FJavaHelper::ToJavaString(Env, type);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "hideGlobalDialogByType", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_type);
	}
#endif
}

FPICOOnUpdateStatusChangedDelegate UPICOEnterpriseFunctionLibrary::OnfflineUpdateStatusChangedDelegate;
FPICOOnUpdateCompleteDelegate UPICOEnterpriseFunctionLibrary::OnfflineUpdateCompleteDelegate;
int UPICOEnterpriseFunctionLibrary::PE_OfflineSystemUpdate(FString OtaFilePath, bool AutoReboot, bool ShowProgress, const FPICOOnUpdateStatusChangedDelegate& UpdateStatusChangedDelegate, const FPICOOnUpdateCompleteDelegate& UpdateCompleteDelegate)
{
	OnfflineUpdateStatusChangedDelegate = UpdateStatusChangedDelegate;
	OnfflineUpdateCompleteDelegate = UpdateCompleteDelegate;
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_Path = FJavaHelper::ToJavaString(Env, OtaFilePath);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OfflineSystemUpdate", "(Ljava/lang/String;ZZ)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_Path, AutoReboot, ShowProgress);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_Recenter()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Recenter", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

FPICOEnterpriseStringDelegate UPICOEnterpriseFunctionLibrary::EnterpriseStringDelegate;
void UPICOEnterpriseFunctionLibrary::PE_ScanQRCode(const FPICOEnterpriseStringDelegate& Delegate)
{
	EnterpriseStringDelegate = Delegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScanQRCode", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int UPICOEnterpriseFunctionLibrary::PE_GetControllerVibrateAmplitude()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetControllerVibrateAmplitude", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetHMDVolumeKeyFunc(int func)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHMDVolumeKeyFunc", "(I)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, func);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetHMDVolumeKeyFunc()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetHMDVolumeKeyFunc", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetPowerManageMode()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetPowerManageMode", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetEyeTrackRate()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetEyeTrackRate", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetTrackFrequency()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetTrackFrequency", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetDistanceSensitivity()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetDistanceSensitivity", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetSpeedSensitivity()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSpeedSensitivity", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_SetMRCollisionAlertSensitivity(float value)
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetMRCollisionAlertSensitivity", "(F)I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, value);
	}
#endif
	return Result;
}

float UPICOEnterpriseFunctionLibrary::PE_GetMRCollisionAlertSensitivity()
{
	float Result = 0.0f;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetMRCollisionAlertSensitivity", "()F", false);
		Result = FJavaWrapper::CallFloatMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetSingleEyeSource()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSingleEyeSource", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetViewVisual()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetViewVisual", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetAcceptCastMode()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetAcceptCastMode", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetScreenCastMode()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenCastMode", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

int UPICOEnterpriseFunctionLibrary::PE_GetScreenRecordShotRatio()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenRecordShotRatio", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

TArray<int32> UPICOEnterpriseFunctionLibrary::PE_GetScreenResolution()
{
	TArray<int32> Results;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenResolution", "()[I", false);
		jintArray JavaIntArray = (jintArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaIntArray != nullptr)
		{
			jint* JavaInts = Env->GetIntArrayElements(JavaIntArray, 0);
			if (JavaInts)
			{
				jsize IntsLen = Env->GetArrayLength(JavaIntArray);
				Results.Empty(IntsLen);
				for (int32 Idx = 0; Idx < IntsLen; Idx++)
				{
					Results.Add(JavaInts[Idx]);
				}
				Env->ReleaseIntArrayElements(JavaIntArray, JavaInts, 0);
			}
			Env->DeleteLocalRef(JavaIntArray);
		}
}
#endif
	return Results;
}

int UPICOEnterpriseFunctionLibrary::PE_GetScreenRecordFrameRate()
{
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetScreenRecordFrameRate", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCScanQRCodeCallback(JNIEnv * env, jclass clazz, jstring Msg)
{
	UPICOEnterpriseFunctionLibrary::EnterpriseStringDelegate.ExecuteIfBound(FJavaHelper::FStringFromParam(env, Msg));
}
#endif

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCOnOnfflineUpdateStatusChangedCallback(JNIEnv * env, jclass clazz, int statusCode, float percent)
{
	UPICOEnterpriseFunctionLibrary::OnfflineUpdateStatusChangedDelegate.ExecuteIfBound(statusCode, percent);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCOnOnfflineUpdateCompleteCallback(JNIEnv * env, jclass clazz, int errorCode, jstring errorMsg)
{
	UPICOEnterpriseFunctionLibrary::OnfflineUpdateCompleteDelegate.ExecuteIfBound(errorCode, FJavaHelper::FStringFromParam(env, errorMsg));
}
#endif // PLATFORM_ANDROID

FPICOOnUpdateStatusChangedDelegate UPICOEnterpriseFunctionLibrary::OnUpdateStatusChangedDelegate;
FPICOOnUpdateCompleteDelegate UPICOEnterpriseFunctionLibrary::OnUpdateCompleteDelegate;
int UPICOEnterpriseFunctionLibrary::PE_OnlineSystemUpdate(const FPICOOnUpdateStatusChangedDelegate& UpdateStatusChangedDelegate, const FPICOOnUpdateCompleteDelegate& UpdateCompleteDelegate)
{
	OnUpdateStatusChangedDelegate = UpdateStatusChangedDelegate;
	OnUpdateCompleteDelegate = UpdateCompleteDelegate;
	int Result = INT_MAX;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OnlineSystemUpdate", "()I", false);
		Result = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return Result;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCOnUpdateStatusChangedCallback(JNIEnv * env, jclass clazz, int statusCode, float percent)
{
	UPICOEnterpriseFunctionLibrary::OnUpdateStatusChangedDelegate.ExecuteIfBound(statusCode, percent);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCOnUpdateCompleteCallback(JNIEnv * env, jclass clazz, int errorCode, jstring errorMsg)
{
	UPICOEnterpriseFunctionLibrary::OnUpdateCompleteDelegate.ExecuteIfBound(errorCode, FJavaHelper::FStringFromParam(env, errorMsg));
}
#endif // PLATFORM_ANDROID

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCAppCopyrightVerifyCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::AppCopyrightVerifyDelegate.ExecuteIfBound(Result);
}
#endif // PLATFORM_ANDROID

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetWifiP2PDeviceNameCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetWifiP2PDeviceNameDelegate.ExecuteIfBound(Result);
}
#endif // PLATFORM_ANDROID



FPICOEnterpriseIntDelegate UPICOEnterpriseFunctionLibrary::ConnectWifiDelegate;
void UPICOEnterpriseFunctionLibrary::PE_ConnectWifi(FString SSID, FString Password, const FPICOEnterpriseIntDelegate& InConnectWifiDelegate)
{
	ConnectWifiDelegate = InConnectWifiDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jstring_SSID = FJavaHelper::ToJavaString(Env, SSID);
		auto jstring_Password = FJavaHelper::ToJavaString(Env, Password);

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ConnectWifi", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *jstring_SSID, *jstring_Password);
	}
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCConnectWifiCallback(JNIEnv * env, jclass clazz, int Result)
{
	AsyncTask(ENamedThreads::GameThread, [Result]() {
	UPICOEnterpriseFunctionLibrary::ConnectWifiDelegate.ExecuteIfBound(Result);
    });
}
#endif // PLATFORM_ANDROID

void UPICOEnterpriseFunctionLibrary::PE_SetStaticIpConfiguration(FString SSID, FString Password, FString staticIP, FString subnet_mask, FString gateway, const TArray<FString>& DNS, FString& OutSSID, FString& OutPassword)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jSSID = FJavaHelper::ToJavaString(Env, SSID);
		auto jPassword = FJavaHelper::ToJavaString(Env, Password);
		auto jstaticIP = FJavaHelper::ToJavaString(Env, staticIP);
		auto jsubnet_mask = FJavaHelper::ToJavaString(Env, subnet_mask);
		auto jgateway = FJavaHelper::ToJavaString(Env, gateway);
		auto dns = NewScopedJavaObject(Env, (jobjectArray)Env->NewObjectArray(DNS.Num(), FJavaWrapper::JavaStringClass, nullptr));
		for (uint32 Param = 0; Param < DNS.Num(); Param++)
		{
			auto StringValue = FJavaHelper::ToJavaString(Env, DNS[Param]);
			Env->SetObjectArrayElement(*dns, Param, *StringValue);
		}
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetStaticIpConfiguration", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)[Ljava/lang/String;", false);
		jobjectArray JavaStringArray = (jobjectArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, *jSSID, *jPassword, *jstaticIP, *jsubnet_mask, *jgateway, *dns);

		jsize NumProducts = Env->GetArrayLength(JavaStringArray);
		if (NumProducts == 2)
		{
			OutSSID = FJavaHelper::FStringFromLocalRef(Env, (jstring)(Env->GetObjectArrayElement(JavaStringArray, 0)));
			OutPassword = FJavaHelper::FStringFromLocalRef(Env, (jstring)(Env->GetObjectArrayElement(JavaStringArray, 1)));
		}
	}
#endif
}

void UPICOEnterpriseFunctionLibrary::PE_ToUnrealPose(FVector& UnrealTranslation, FQuat& UnrealOrientation, const FVector& RMUVector, const FQuat& RMUOrientation)
{
	UnrealTranslation = FVector(-RMUVector.Z, RMUVector.X, RMUVector.Y);
	UnrealOrientation = FQuat(-RMUOrientation.Z, RMUOrientation.X, RMUOrientation.Y, -RMUOrientation.W);
}

void UPICOEnterpriseFunctionLibrary::PE_ToRGBCameraPose(FVector& CameraTranslation, FQuat& CameraOrientation, const FRGBCameraParams& CameraParameters, const FVector& HeadTranslation, const FQuat& HeadOrientation)
{
	FMatrix HeadMatrix = FQuatRotationTranslationMatrix::Make(HeadOrientation, HeadTranslation);
	FMatrix CameraMatrix = FQuatRotationTranslationMatrix::Make(CameraParameters.ExternalOrientation, CameraParameters.ExternalTranslation);
	FMatrix RGBMatrix = HeadMatrix * CameraMatrix;
	FMatrix RotateX180 = FQuatRotationMatrix::Make(FQuat::MakeFromEuler(FVector(180, 0, 0)));
	RGBMatrix *= RotateX180;
	CameraTranslation = RGBMatrix.GetOrigin();
	CameraOrientation = RGBMatrix.ToQuat();
	PE_ToUnrealPose(CameraTranslation, CameraOrientation, CameraTranslation, CameraOrientation);
}

void UPICOEnterpriseFunctionLibrary::PE_UpdateRenderTargetFromRGB(const TArray<uint8>& RawData, int32 Width, int32 Height, UTextureRenderTarget2D* RenderTarget2D, uint8 OverrideAlpha)
{
	if (!RenderTarget2D || Width * Height * 3 != RawData.Num())
	{
		return;
	}

	EPixelFormat Format = RenderTarget2D->GetFormat();
	if (RenderTarget2D->SizeX != Width || RenderTarget2D->SizeY != Height || Format != EPixelFormat::PF_B8G8R8A8)
	{
		RenderTarget2D->InitCustomFormat(Width, Height, EPixelFormat::PF_B8G8R8A8, false);
	}

	int32 PixelNum = Width * Height;
	TArray<uint8> TargetTextureData;
	TargetTextureData.SetNum(PixelNum * 4);
	for (int32 Index = 0; Index < PixelNum; ++Index)
	{
		int32 TargetIndex = Index * 4;
		int32 SourceIndex = Index * 3;
		TargetTextureData[TargetIndex + 0] = RawData[SourceIndex + 0];
		TargetTextureData[TargetIndex + 1] = RawData[SourceIndex + 1];
		TargetTextureData[TargetIndex + 2] = RawData[SourceIndex + 2];
		TargetTextureData[TargetIndex + 3] = OverrideAlpha;
	}

	FRenderTarget* RenderTarget = RenderTarget2D->GameThread_GetRenderTargetResource();
	FUpdateTextureRegion2D Region = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	ENQUEUE_RENDER_COMMAND(UpdateTextureRegionsData)(
		[=](FRHICommandListImmediate& RHICmdList)
		{
			FTexture2DRHIRef TextureRHI = RenderTarget->GetRenderTargetTexture();
			check(TextureRHI.IsValid());
			RHIUpdateTexture2D(
				TextureRHI,
				0,
				Region,
				Width * 4,
				TargetTextureData.GetData()
			);
		}
	);
}

void UPICOEnterpriseFunctionLibrary::PE_UpdateRenderTargetFromYUVNV21(const TArray<uint8>& RawData, int32 Width, int32 Height, UTextureRenderTarget2D* RenderTarget2D, uint8 OverrideAlpha)
{
	if (!RenderTarget2D || Width * Height * 3 / 2 != RawData.Num())
	{
		return;
	}

	EPixelFormat Format = RenderTarget2D->GetFormat();
	if (RenderTarget2D->SizeX != Width || RenderTarget2D->SizeY != Height || Format != EPixelFormat::PF_B8G8R8A8)
	{
		RenderTarget2D->InitCustomFormat(Width, Height, EPixelFormat::PF_B8G8R8A8, false);
	}

	int32 PixelNum = Width * Height;
	TArray<uint8> TargetTextureData;
	TargetTextureData.SetNum(PixelNum * 4);

	int32 Index = 0;
	for (int32 i = 0; i < Height; ++i) {
		for (int32 j = 0; j < Width; ++j) {
			int32 y = (0xff & ((int32)RawData[i * Width + j]));
			int32 v = (0xff & ((int32)RawData[PixelNum + (i >> 1) * Width + (j & ~1) + 0]));
			int32 u = (0xff & ((int32)RawData[PixelNum + (i >> 1) * Width + (j & ~1) + 1]));
			y = y < 16 ? 16 : y;

			int32 r = (int)(1.164f * (y - 16) + 1.596f * (v - 128));
			int32 g = (int)(1.164f * (y - 16) - 0.813f * (v - 128) - 0.391f * (u - 128));
			int32 b = (int)(1.164f * (y - 16) + 2.018f * (u - 128));

			r = r < 0 ? 0 : (r > 255 ? 255 : r);
			g = g < 0 ? 0 : (g > 255 ? 255 : g);
			b = b < 0 ? 0 : (b > 255 ? 255 : b);

			TargetTextureData[Index++] = b;
			TargetTextureData[Index++] = g;
			TargetTextureData[Index++] = r;
			TargetTextureData[Index++] = OverrideAlpha;
		}
	}

	FRenderTarget* RenderTarget = RenderTarget2D->GameThread_GetRenderTargetResource();
	FUpdateTextureRegion2D Region = FUpdateTextureRegion2D(0, 0, 0, 0, Width, Height);
	ENQUEUE_RENDER_COMMAND(UpdateTextureRegionsData)(
		[=](FRHICommandListImmediate& RHICmdList)
		{
			FTexture2DRHIRef TextureRHI = RenderTarget->GetRenderTargetTexture();
			check(TextureRHI.IsValid());
			RHIUpdateTexture2D(
				TextureRHI,
				0,
				Region,
				Width * 4,
				TargetTextureData.GetData()
			);
		}
	);
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetDeviceActionCallBack(JNIEnv * env, jclass clazz, int EventType, int Result)
{
	if (EventType == 0)
	{
		if (UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT))
		{
			UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT)->ExecuteIfBound(Result);
			UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_REBOOT);
		}
	}
	else if (EventType == 1)
	{
		if (UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN))
		{
			UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN)->ExecuteIfBound(Result);
			UPICOEnterpriseFunctionLibrary::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCAPPMangerCallBack(JNIEnv * env, jclass clazz, int EventType, jstring AppPath, int Result)
{
	FAppManagerStruct ManagerStruct;
	ManagerStruct.AppPath = FJavaHelper::FStringFromParam(env, AppPath);
	ManagerStruct.PackageControl = static_cast<EPackageControlEnum>(EventType);
	if (UPICOEnterpriseFunctionLibrary::AppManagerDelegates.Find(ManagerStruct))
	{
		UPICOEnterpriseFunctionLibrary::AppManagerDelegates.Find(ManagerStruct)->ExecuteIfBound(Result);
		UPICOEnterpriseFunctionLibrary::AppManagerDelegates.Remove(ManagerStruct);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCAutoConnectWifiCallBack(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::SetAutoConnectWifiDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::SetAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCClearAutoConnectWifiCallBack(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::ClearAutoConnectWifiDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::ClearAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetHomeKeyCallBack(JNIEnv * env, jclass clazz, int EventType, int FunctionType, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		if (UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
	else
	{
		if (UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPICOEnterpriseFunctionLibrary::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetHomeKeyAllCallBack(JNIEnv * env, jclass clazz, int EventType, int FunctionType, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		if (UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
	else
	{
		if (UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPICOEnterpriseFunctionLibrary::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCDisablePowerKeyCallBack(JNIEnv * env, jclass clazz, jboolean isSingleTap, int Result)
{
	if (isSingleTap == JNI_TRUE)
	{
		if (UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Find(true))
		{
			UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Find(true)->ExecuteIfBound(Result);
			UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Remove(true);
		}
	}
	else
	{
		if (UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Find(false))
		{
			UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Find(false)->ExecuteIfBound(Result);
			UPICOEnterpriseFunctionLibrary::DisablePowerKeyDelegates.Remove(false);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetScreenOffDelayCallBack(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetScreenOffDelayDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCWriteConfigFileToDataLocalCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::WriteConfigDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::WriteConfigDelegate.ExecuteIfBound(false);
	}
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetWDJsonCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPICOEnterpriseFunctionLibrary::SetWDJsonDelegate.ExecuteIfBound(result);
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetWDModelsCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	TArray<FWifiDisplayModel> models;
	models.Empty();
	TArray<FString> modelsString;
	result.ParseIntoArray(modelsString, TEXT("SPC"), true);
	for (int j = 0; j < modelsString.Num(); j++)
	{
		TArray<FString> substring;
		substring.Empty();
		modelsString[j].ParseIntoArray(substring, TEXT("="), true);
		substring.RemoveAt(0);
		for (int i = 0; i < substring.Num(); i++)
		{
			if (substring[i].Contains(TEXT("'")))
			{
				substring[i].Split(TEXT("'"), nullptr, &substring[i]);
				substring[i].Split(TEXT("'"), &substring[i], nullptr);
			}
			else
			{
				substring[i].Split(TEXT(","), &substring[i], nullptr);
			}
		}
		FWifiDisplayModel model;
		model.deviceAddress = substring[0];
		model.deviceName = substring[1];
		model.isAvailable = substring[2] == "true" ? true : false;
		model.canConnect = substring[3] == "true" ? true : false;
		model.isRemembered = substring[4] == "true" ? true : false;
		model.statusCode = FCString::Atoi(*substring[5]);
		model.status = substring[6];
		model.description = substring[7];
		models.Add(model);
	}

	UPICOEnterpriseFunctionLibrary::SetWDModelsDelegate.ExecuteIfBound(models);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSwitchLargeSpaceSceneCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::EnableLargeSpaceDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::EnableLargeSpaceDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCLargeSpaceStatusCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPICOEnterpriseFunctionLibrary::SwitchLargeSpaceStatusDelegate.ExecuteIfBound(result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCExportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::ExportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::ExportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCImportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOEnterpriseFunctionLibrary::ImportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOEnterpriseFunctionLibrary::ImportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCControlSetAutoConnectWIFIWithErrorCodeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::ControlSetAutoConnectWIFIWithErrorCodeDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCGetSwitchSystemFunctionStatusCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::GetSwitchSystemFunctionStatusDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCPICOCastInitCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::PICOCastInitDelegate.ExecuteIfBound((ECastInitResult)Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetControllerPairTimeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetControllerPairTimeDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCGetControllerPairTimeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::GetControllerPairTimeDelegate.ExecuteIfBound((EControllerPairTimeEnum)Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetSystemCountryCodeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetSystemCountryCodeDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetIPDCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::SetIPDDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetArUcoMarkerCallback(JNIEnv * env, jclass clazz, jobjectArray MarkArray)
{
	FTransform TrackingToWorld = FTransform::Identity;
	IXRTrackingSystem* TrackingSys = GEngine->XRSystem.Get();
	if (TrackingSys)
	{
		TrackingToWorld = TrackingSys->GetTrackingToWorldTransform();
	}

	TArray<FMarkerResultCallback> Results;
	jsize NumMark = env->GetArrayLength(MarkArray);
	for (int32 Index = 0; Index < NumMark; ++Index)
	{
		FMarkerResultCallback Result;

		jobject MarkObject = env->GetObjectArrayElement(MarkArray, Index);
		jclass MarkClass = env->GetObjectClass(MarkObject);

		FVector Position;
		jfieldID PosXField = env->GetFieldID(MarkClass, "posX", "D");
		Position.X = (float)env->GetDoubleField(MarkObject, PosXField);

		jfieldID PosYField = env->GetFieldID(MarkClass, "posY", "D");
		Position.Y = (float)env->GetDoubleField(MarkObject, PosYField);

		jfieldID PosZField = env->GetFieldID(MarkClass, "posZ", "D");
		Position.Z = (float)env->GetDoubleField(MarkObject, PosZField);

		float TrackingOriginHeight = 0.0f;

		Result.MarkerTranslation = FVector(-Position.Z, Position.X, Position.Y + TrackingOriginHeight);
		if (IsValid(UPICOEnterpriseFunctionLibrary::MarkerWorldContext))
		{
			UWorld* World = GEngine->GetWorldFromContextObject(UPICOEnterpriseFunctionLibrary::MarkerWorldContext, EGetWorldErrorMode::ReturnNull);
			if (!IsValid(World))
			{
				World = GWorld.GetReference();
			}

			if (IsValid(World))
			{
				float WorldScale = World->GetWorldSettings()->WorldToMeters;
				Result.MarkerTranslation *= WorldScale;
			}
		}
		Result.MarkerTranslation = TrackingToWorld.TransformPosition(Result.MarkerTranslation);

		FQuat Orientation;
		jfieldID RotationXField = env->GetFieldID(MarkClass, "rotationX", "D");
		Orientation.X = (float)env->GetDoubleField(MarkObject, RotationXField);

		jfieldID RotationYField = env->GetFieldID(MarkClass, "rotationY", "D");
		Orientation.Y = (float)env->GetDoubleField(MarkObject, RotationYField);

		jfieldID RotationZField = env->GetFieldID(MarkClass, "rotationZ", "D");
		Orientation.Z = (float)env->GetDoubleField(MarkObject, RotationZField);

		jfieldID RotationWField = env->GetFieldID(MarkClass, "rotationW", "D");
		Orientation.W = (float)env->GetDoubleField(MarkObject, RotationWField);

		Result.MarkerOrientation = FQuat(Orientation.Z, -Orientation.X, -Orientation.Y, Orientation.W);
		Result.MarkerOrientation = TrackingToWorld.TransformRotation(Result.MarkerOrientation);

		jfieldID TimestampField = env->GetFieldID(MarkClass, "dTimestamp", "D");
		Result.Timestamp = (float)env->GetDoubleField(MarkObject, TimestampField);

		jfieldID ValidFlagField = env->GetFieldID(MarkClass, "validFlag", "I");
		Result.ValidFlag = (int32)env->GetIntField(MarkObject, ValidFlagField);

		jfieldID MarkerTypeField = env->GetFieldID(MarkClass, "markerType", "I");
		Result.MarkerType = (int32)env->GetIntField(MarkObject, MarkerTypeField);

		jfieldID MarkerIdField = env->GetFieldID(MarkClass, "iMarkerId", "I");
		Result.MarkerID = (int32)env->GetIntField(MarkObject, MarkerIdField);

		jfieldID ReserveField = env->GetFieldID(MarkClass, "reserve", "[I");
		jintArray ReserveIntArray = (jintArray)env->GetObjectField(MarkObject, ReserveField);
		jint* ReserveInts = env->GetIntArrayElements(ReserveIntArray, 0);
		jsize ReserveSize = env->GetArrayLength(ReserveIntArray);
		for (int32 ReserveIndex = 0; ReserveIndex < ReserveSize; ++ReserveIndex)
		{
			Result.Reserve.Add((int32)ReserveInts[ReserveIndex]);
		}

		Results.Add(Result);
	}
	UPICOEnterpriseFunctionLibrary::SetArUcoMarkerDelegate.ExecuteIfBound(Results);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCSetArUcoMarkerFCallback(JNIEnv * env, jclass clazz, jobjectArray MarkArray)
{
	FTransform TrackingToWorld = FTransform::Identity;
	IXRTrackingSystem* TrackingSys = GEngine->XRSystem.Get();
	if (TrackingSys)
	{
		TrackingToWorld = TrackingSys->GetTrackingToWorldTransform();
	}

	TArray<FMarkerFResultCallback> Results;
	jsize NumMark = env->GetArrayLength(MarkArray);
	for (int32 Index = 0; Index < NumMark; ++Index)
	{
		FMarkerFResultCallback Result;

		jobject MarkObject = env->GetObjectArrayElement(MarkArray, Index);
		jclass MarkClass = env->GetObjectClass(MarkObject);

		FVector Position;
		jfieldID PosXField = env->GetFieldID(MarkClass, "posX", "D");
		Position.X = (float)env->GetDoubleField(MarkObject, PosXField);

		jfieldID PosYField = env->GetFieldID(MarkClass, "posY", "D");
		Position.Y = (float)env->GetDoubleField(MarkObject, PosYField);

		jfieldID PosZField = env->GetFieldID(MarkClass, "posZ", "D");
		Position.Z = (float)env->GetDoubleField(MarkObject, PosZField);

		float TrackingOriginHeight = 0.0f;

		Result.MarkerTranslation = FVector(-Position.Z, Position.X, Position.Y + TrackingOriginHeight);
		if (IsValid(UPICOEnterpriseFunctionLibrary::MarkerFWorldContext))
		{
			UWorld* World = GEngine->GetWorldFromContextObject(UPICOEnterpriseFunctionLibrary::MarkerFWorldContext, EGetWorldErrorMode::ReturnNull);
			if (!IsValid(World))
			{
				World = GWorld.GetReference();
			}

			if (IsValid(World))
			{
				float WorldScale = World->GetWorldSettings()->WorldToMeters;
				Result.MarkerTranslation *= WorldScale;
			}
		}
		Result.MarkerTranslation = TrackingToWorld.TransformPosition(Result.MarkerTranslation);

		FQuat Orientation;
		jfieldID RotationXField = env->GetFieldID(MarkClass, "rotationX", "D");
		Orientation.X = (float)env->GetDoubleField(MarkObject, RotationXField);

		jfieldID RotationYField = env->GetFieldID(MarkClass, "rotationY", "D");
		Orientation.Y = (float)env->GetDoubleField(MarkObject, RotationYField);

		jfieldID RotationZField = env->GetFieldID(MarkClass, "rotationZ", "D");
		Orientation.Z = (float)env->GetDoubleField(MarkObject, RotationZField);

		jfieldID RotationWField = env->GetFieldID(MarkClass, "rotationW", "D");
		Orientation.W = (float)env->GetDoubleField(MarkObject, RotationWField);

		Result.MarkerOrientation = FQuat(Orientation.Z, -Orientation.X, -Orientation.Y, Orientation.W);
		Result.MarkerOrientation = TrackingToWorld.TransformRotation(Result.MarkerOrientation);

		jfieldID TimestampField = env->GetFieldID(MarkClass, "dTimestamp", "D");
		Result.Timestamp = (float)env->GetDoubleField(MarkObject, TimestampField);

		jfieldID ValidFlagField = env->GetFieldID(MarkClass, "validFlag", "I");
		Result.ValidFlag = (int32)env->GetIntField(MarkObject, ValidFlagField);

		jfieldID MarkerTypeField = env->GetFieldID(MarkClass, "markerType", "I");
		Result.MarkerType = (int32)env->GetIntField(MarkObject, MarkerTypeField);

		jfieldID MarkerIdField = env->GetFieldID(MarkClass, "iMarkerId", "I");
		Result.MarkerID = (int32)env->GetIntField(MarkObject, MarkerIdField);

		jfieldID ReserveField = env->GetFieldID(MarkClass, "reserve", "[F");
		jfloatArray ReserveFloatArray = (jfloatArray)env->GetObjectField(MarkObject, ReserveField);
		jfloat* ReserveFloats = env->GetFloatArrayElements(ReserveFloatArray, 0);
		jsize ReserveSize = env->GetArrayLength(ReserveFloatArray);
		for (int32 ReserveIndex = 0; ReserveIndex < ReserveSize; ++ReserveIndex)
		{
			Result.Reserve.Add((float)ReserveFloats[ReserveIndex]);
		}

		Results.Add(Result);
	}
	UPICOEnterpriseFunctionLibrary::SetArUcoMarkerFDelegate.ExecuteIfBound(Results);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCFileCopyCallback(JNIEnv * env, jclass clazz, jboolean bStart, jboolean bProcess, jdouble Process, jboolean bFinish, int ErrorCode)
{
	UPICOEnterpriseFunctionLibrary::FileCopyDelegate.ExecuteIfBound(bStart, bProcess, static_cast<float>(Process), bFinish, ErrorCode);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCIsMapInEffectCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::IsMapInEffectDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_unreal_GameActivity_JavaToCImportMapByPathCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOEnterpriseFunctionLibrary::ImportMapByPathDelegate.ExecuteIfBound(Result);
}
#endif
