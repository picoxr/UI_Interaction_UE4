//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#include "PXR_SystemAPI.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

TMap<EDeviceControlEnum,FPICOSetDeviceActionDelegate> UPICOXRSystemAPI::SetDeviceActionDelegates;
TMap<FAppManagerStruct,FPICOAppManagerDelegate> UPICOXRSystemAPI::AppManagerDelegates;
FPICOSetAutoConnectWifiDelegate UPICOXRSystemAPI::SetAutoConnectWifiDelegate;
FPICOClearAutoConnectWifiDelegate UPICOXRSystemAPI::ClearAutoConnectWifiDelegate;
TMap<EHomeEventEnum,FPICOSetHomeKeyDelegate> UPICOXRSystemAPI::SetHomeKeyDelegates;
TMap<EHomeEventEnum,FPICOSetHomeKeyAllDelegate> UPICOXRSystemAPI::SetHomeKeyAllDelegates;
TMap<bool,FPICODisablePowerKeyDelegate> UPICOXRSystemAPI::DisablePowerKeyDelegates;
FPICOSetScreenOffDelayDelegate UPICOXRSystemAPI::SetScreenOffDelayDelegate;
FPICOWriteConfigFileToDataLocalDelegate UPICOXRSystemAPI::WriteConfigDelegate;
FPICOResetAllKeyToDefaultDelegate UPICOXRSystemAPI::ResetAllKeyDelegate;
FPICOSetWDJsonDelegate UPICOXRSystemAPI::SetWDJsonDelegate;
FPICOSetWDModelsDelegate UPICOXRSystemAPI::SetWDModelsDelegate;

FPICOEnableLargeSpaceDelegate UPICOXRSystemAPI::EnableLargeSpaceDelegate;
FPICOSwitchLargeSpaceStatusDelegate UPICOXRSystemAPI::SwitchLargeSpaceStatusDelegate;
FPICOExportMapsDelegate UPICOXRSystemAPI::ExportMapsDelegate;
FPICOImportMapsDelegate UPICOXRSystemAPI::ImportMapsDelegate;
FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate UPICOXRSystemAPI::ControlSetAutoConnectWIFIWithErrorCodeDelegate;
FPICOGetSwitchSystemFunctionStatusDelegate UPICOXRSystemAPI::GetSwitchSystemFunctionStatusDelegate;
FPICOCastInitDelegate UPICOXRSystemAPI::PICOCastInitDelegate;
FPICOSetControllerPairTimeDelegate UPICOXRSystemAPI::SetControllerPairTimeDelegate;
FPICOGetControllerPairTimeDelegate UPICOXRSystemAPI::GetControllerPairTimeDelegate;
// Sets default values for this component's properties
UPICOXRSystemAPI::UPICOXRSystemAPI()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPICOXRSystemAPI::BeginPlay()
{
	Super::BeginPlay();
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "BindSystemAPIService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UnBindSystemAPIService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

// Called every frame
void UPICOXRSystemAPI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UPICOXRSystemAPI::PXR_GetDeviceInfo(ESystemInfoEnum InfoEnum)
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

void UPICOXRSystemAPI::PXR_SetDeviceAction(EDeviceControlEnum DeviceControlEnum,FPICOSetDeviceActionDelegate SetDeviceActionDelegate)
{
	SetDeviceActionDelegates.Add(DeviceControlEnum,SetDeviceActionDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetDeviceAction", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(DeviceControlEnum));
	}
#endif
}

void UPICOXRSystemAPI::PXR_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext,	FPICOAppManagerDelegate AppManagerDelegate)
{	
	FAppManagerStruct AppManagerStruct;
	AppManagerStruct.PackageControl = PackageControlEnum;
	AppManagerStruct.AppPath = Path;
	AppManagerDelegates.Add(AppManagerStruct,AppManagerDelegate);
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

void UPICOXRSystemAPI::PXR_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext,FPICOSetAutoConnectWifiDelegate InSetAutoConnectWifiDelegate)
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

void UPICOXRSystemAPI::PXR_ClearAutoConnectWifi(FPICOClearAutoConnectWifiDelegate InClearAutoConnectWifiDelegate)
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

void UPICOXRSystemAPI::PXR_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum,FPICOSetHomeKeyDelegate SetHomeKeyDelegate)
{
	SetHomeKeyDelegates.Add(EventEnum,SetHomeKeyDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHomeKey", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(EventEnum), static_cast<int32>(FunctionEnum));
	}
#endif
}

void UPICOXRSystemAPI::PXR_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup,FString Package, FString ClassName, FPICOSetHomeKeyAllDelegate SetHomeKeyAllDelegate)
{
	SetHomeKeyAllDelegates.Add(EventEnum,SetHomeKeyAllDelegate);
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

void UPICOXRSystemAPI::PXR_DisablePowerKey(bool bIsSingleTap, bool bEnable,FPICODisablePowerKeyDelegate InDisablePowerKeyDelegate)
{
	
	DisablePowerKeyDelegates.Add(bIsSingleTap,InDisablePowerKeyDelegate);
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisablePowerKey", "(ZZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, bIsSingleTap, bEnable);
	}
#endif
}

void UPICOXRSystemAPI::PXR_SetSleepDelay(ESleepDelayTimeEnum TimeEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSleepDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(TimeEnum));
	}
#endif
}

void UPICOXRSystemAPI::PXR_SetScreenOffDelay(EScreenOffDelayTimeEnum TimeEnum,	FPICOSetScreenOffDelayDelegate InSetScreenOffDelayDelegate)
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

void UPICOXRSystemAPI::PXR_SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SystemFunction", "(III)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(SystemFunction), static_cast<int32>(SwitchEnum), Ext);
	}
#endif
}

void UPICOXRSystemAPI::PXR_SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetUsbConfigurationOption", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(UsbConfigModeEnum), Ext);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ScreenOn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ScreenOff()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOff", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_AcquireWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AcquireWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ReleaseWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ReleaseWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_WriteConfigFileToDataLocal(FString Path, FString Content, FPICOWriteConfigFileToDataLocalDelegate InWriteConfigDelegate)
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

void UPICOXRSystemAPI::PXR_ResetAllKeyToDefault(FPICOResetAllKeyToDefaultDelegate InResetAllKeyDelegate)
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

void UPICOXRSystemAPI::PXR_EnableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_DisableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_EnableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_DisableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_EnableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_DisableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int32 UPICOXRSystemAPI::PXR_GetCurrentBrightness()
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

void UPICOXRSystemAPI::PXR_SetBrightness(int32 Brightness)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetBrightness", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, Brightness);
	}
#endif
}

int32 UPICOXRSystemAPI::PXR_GetCurrentVolume()
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

int32 UPICOXRSystemAPI::PXR_GetMaxVolume()
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

void UPICOXRSystemAPI::PXR_SetVolume(int32 Volume)
{
#if PLATFORM_ANDROID
	if (JNIEnv *Env =FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetVolume", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env,FJavaWrapper::GameActivityThis,Method,Volume);

	}
#endif
}

void UPICOXRSystemAPI::PXR_VolumeUp()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeUp", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif	
}

void UPICOXRSystemAPI::PXR_VolumeDown()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env=FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeDown", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}


FString UPICOXRSystemAPI::PXR_GetDeviceSN()
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

void UPICOXRSystemAPI::PXR_FreezeScreen(bool freeze)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "FreezeScreen", "(Z)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, freeze);
	}
#endif
}

void UPICOXRSystemAPI::PXR_KillAppsByPidOrPackageName(TArray<int> pids, TArray<FString> packageNames, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		int num = pids.Num();
		jintArray jPids = Env->NewIntArray(num);
		jint* jPidsArray = Env->GetIntArrayElements(jPids, 0);
		for (int32 i=0;i<num;i++)
		{
			jPidsArray[i] = pids[i];
		}
		auto PackageNamesArray = NewScopedJavaObject(Env, (jobjectArray)Env->NewObjectArray(packageNames.Num(), FJavaWrapper::JavaStringClass, nullptr));
		for (uint32 Param = 0; Param < packageNames.Num(); Param++)
		{
			auto StringValue = FJavaHelper::ToJavaString(Env, packageNames[Param]);
			Env->SetObjectArrayElement(*PackageNamesArray, Param, *StringValue);
        } 
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "KillAppsByPidOrPackageName", "([I;[Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,Method,jPids,*PackageNamesArray,ext);
	}
#endif
}

void UPICOXRSystemAPI::PXR_KillBackgroundAppsWithWhiteList(TArray<FString> packageNames, int ext)
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

void UPICOXRSystemAPI::PXR_OpenMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OpenMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

bool UPICOXRSystemAPI::PXR_IsMiracastOn()
{
	bool result=false;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "IsMiracastOn", "()Z", false);
		result=(bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return result;
}

void UPICOXRSystemAPI::PXR_CloseMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CloseMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_StartScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_StopScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StopScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ConnectWifiDisplay(const FWifiDisplayModel &Model)
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
		auto	 status= FJavaHelper::ToJavaString(Env, Model.status);
		auto	 description= FJavaHelper::ToJavaString(Env, Model.description);
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ConnectWifiDisplay", 
			"(Ljava/lang/String;Ljava/lang/String;ZZZILjava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,*deviceAddress,*deviceName,isAvailable,canConnect,isRemembered,statusCode,*status,*description);
	}
#endif
}

void UPICOXRSystemAPI::PXR_DisConnectWifiDisplay()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisConnectWifiDisplay", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ForgetWifiDisplay(FString Address)
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

void UPICOXRSystemAPI::PXR_RenameWifiDisplay(FString Address, FString NewName)
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

void UPICOXRSystemAPI::PXR_UpdateWifiDisplays()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UpdateWifiDisplays", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_GetConnectedWD(FWifiDisplayModel& Model)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetConnectedWD", "()Ljava/lang/String;", false);
		FString result = "";
		result= FJavaHelper::FStringFromLocalRef(Env, (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method));
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

void UPICOXRSystemAPI::PXR_SetWDJson(FPICOSetWDJsonDelegate InSetWDJsonDelegate)
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

void UPICOXRSystemAPI::PXR_SetWDModels(FPICOSetWDModelsDelegate InSetWDModelsDelegate)
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


void UPICOXRSystemAPI::PXR_SwitchLargeSpaceScene(FPICOEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext)
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

void UPICOXRSystemAPI::PXR_GetSwitchLargeSpaceStatus(FPICOSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate, int ext)
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

bool UPICOXRSystemAPI::PXR_SaveLargeSpaceMaps(int ext)
{
	bool result=false;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SaveLargeSpaceMaps", "(I)Z", false);
		result=(bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
	return result;
}

void UPICOXRSystemAPI::PXR_ExportMaps(FPICOExportMapsDelegate InExportMapsDelegate, int ext)
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

void UPICOXRSystemAPI::PXR_ImportMaps(FPICOImportMapsDelegate InImportMapsDelegate, int ext)
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

void UPICOXRSystemAPI::PXR_GetCpuUsages(TArray<float>& OutData)
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
			UE_LOG(LogHMD, Log, TEXT("Data[%d]:%f"), i, FloatValues[i]);
			OutData.Add(FloatValues[i]);
		}
	}
#endif
}

void UPICOXRSystemAPI::PXR_GetDeviceTemperatures(int inType, int inSource, TArray<float>& OutData)
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
			UE_LOG(LogHMD, Log, TEXT("Data[%d]:%f"), i, FloatValues[i]);
			OutData.Add(FloatValues[i]);
		}
	}
#endif
}

void UPICOXRSystemAPI::PXR_Capture()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Capture", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_Record()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Record", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPICOXRSystemAPI::PXR_ControlSetAutoConnectWIFIWithErrorCode(FPICOControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate, FString ssid, FString pwd, int ext)
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

void UPICOXRSystemAPI::PXR_AppKeepAlive(FString appPackageName, bool keepAlive, int ext)
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

void UPICOXRSystemAPI::PXR_TimingStartup(int year, int month, int day, int hour, int minute, bool open)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "TimingStartup", "(IIIIIZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,  year,  month,  day,  hour,  minute,  open);
	}
#endif
}

void UPICOXRSystemAPI::PXR_TimingShutdown(int year, int month, int day, int hour, int minute, bool open)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "TimingShutdown", "(IIIIIZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, year, month, day, hour, minute, open);
	}
#endif
}

void UPICOXRSystemAPI::PXR_StartVrSettingsItem(int vrSettingsEnum, bool hideOtherItem, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartVrSettingsItem", "(IZI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,  vrSettingsEnum,  hideOtherItem,  ext);
	}
#endif
}

void UPICOXRSystemAPI::PXR_SwitchVolumeToHomeAndEnter(ESwitchEnum switchEnum, int ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SwitchVolumeToHomeAndEnter", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, (int)switchEnum, ext);
	}
#endif
}

ESwitchEnum UPICOXRSystemAPI::PXR_IsVolumeChangeToHomeAndEnter()
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

EInstallOTAReturnCode UPICOXRSystemAPI::PXR_InstallOTAPackage(const FString& OtaPackagePath, int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetAutoConnectWiFiConfig(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetTimingStartupStatus(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetTimingShutdownStatus(int32 Ext)
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

EKeyState UPICOXRSystemAPI::PXR_GetControllerKeyState(EControllerKeyEnum ControllerKeyEnum, int32 Ext)
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

ESwitchEnum UPICOXRSystemAPI::PXR_GetPowerOffWithUSBCable(int32 Ext)
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

EScreenOffDelayTimeEnum UPICOXRSystemAPI::PXR_GetScreenOffDelay(int32 Ext)
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

ESleepDelayTimeEnum UPICOXRSystemAPI::PXR_GetSleepDelay(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetPowerKeyStatus(int32 Ext)
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

EKeyState UPICOXRSystemAPI::PXR_GetEnterKeyStatus(int32 Ext)
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

EKeyState UPICOXRSystemAPI::PXR_GetVolumeKeyStatus(int32 Ext)
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

EKeyState UPICOXRSystemAPI::PXR_GetBackKeyStatus(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetHomeKeyStatus(EHomeEventEnum HomeEventEnum, int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetUsbConfigurationOption(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_GetCurrentLauncher(int32 Ext)
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

void UPICOXRSystemAPI::PXR_GetSwitchSystemFunctionStatus(FPICOGetSwitchSystemFunctionStatusDelegate InGetSwitchSystemFunctionStatusDelegate, ESystemFunctionSwitchEnum SystemFunctionSwitchEnum, int32 Ext)
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

ECastReturnCode UPICOXRSystemAPI::PXR_PICOCastInit(FPICOCastInitDelegate InPICOCastInitDelegate, int32 Ext)
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

ECastReturnCode UPICOXRSystemAPI::PXR_PICOCastSetShowAuthorization(EPICOCastAuthorization Authorization, int32 Ext)
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

EPICOCastAuthorization UPICOXRSystemAPI::PXR_PICOCastGetShowAuthorization(int32 Ext)
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

FString UPICOXRSystemAPI::PXR_PICOCastGetUrl(EPICOCastUrlTypeEnum UrlType, int32 Ext)
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

ECastReturnCode UPICOXRSystemAPI::PXR_PICOCastStopCast(int32 Ext)
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

ECastReturnCode UPICOXRSystemAPI::PXR_PICOCastSetOption(EPICOCastOptionOrStatusEnum OptionEnum, EPICOCastOptionValueEnum ValueEnum, int32 Ext)
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

EPICOCastOptionValueEnum UPICOXRSystemAPI::PXR_PICOCastGetOptionOrStatus(EPICOCastOptionOrStatusEnum OptionEnum, int32 Ext)
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

void UPICOXRSystemAPI::PXR_SetControllerPairTime(FPICOSetControllerPairTimeDelegate InSetControllerPairTimeDelegate, EControllerPairTimeEnum TimeEnum, int32 Ext)
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

void UPICOXRSystemAPI::PXR_GetControllerPairTime(FPICOGetControllerPairTimeDelegate InGetControllerPairTimeDelegate, int32 Ext)
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

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetDeviceActionCallBack(JNIEnv * env, jclass clazz,int EventType, int Result)
{
	if (EventType == 0)
	{
		if (UPICOXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT))
		{
			UPICOXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT)->ExecuteIfBound(Result);
			UPICOXRSystemAPI::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_REBOOT);
		}
	}else if (EventType == 1)
	{
		if (UPICOXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN))
		{
			UPICOXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN)->ExecuteIfBound(Result);
			UPICOXRSystemAPI::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAPPMangerCallBack(JNIEnv * env, jclass clazz,int EventType, jstring AppPath, int Result)
{
	FAppManagerStruct ManagerStruct;
	ManagerStruct.AppPath = FJavaHelper::FStringFromParam(env, AppPath);
	ManagerStruct.PackageControl = static_cast<EPackageControlEnum>(EventType);
	if(UPICOXRSystemAPI::AppManagerDelegates.Find(ManagerStruct))
	{
		UPICOXRSystemAPI::AppManagerDelegates.Find(ManagerStruct)->ExecuteIfBound(Result);
		UPICOXRSystemAPI::AppManagerDelegates.Remove(ManagerStruct);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::SetAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPICOXRSystemAPI::SetAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCClearAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::ClearAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPICOXRSystemAPI::ClearAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPICOXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPICOXRSystemAPI::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPICOXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPICOXRSystemAPI::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyAllCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPICOXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPICOXRSystemAPI::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPICOXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPICOXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPICOXRSystemAPI::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCDisablePowerKeyCallBack(JNIEnv * env, jclass clazz,jboolean isSingleTap, int Result)
{
	if(isSingleTap == JNI_TRUE)
	{
		if(UPICOXRSystemAPI::DisablePowerKeyDelegates.Find(true))
		{
			UPICOXRSystemAPI::DisablePowerKeyDelegates.Find(true)->ExecuteIfBound(Result);
			UPICOXRSystemAPI::DisablePowerKeyDelegates.Remove(true);
		}
	}else
	{
		if(UPICOXRSystemAPI::DisablePowerKeyDelegates.Find(false))
		{
			UPICOXRSystemAPI::DisablePowerKeyDelegates.Find(false)->ExecuteIfBound(Result);
			UPICOXRSystemAPI::DisablePowerKeyDelegates.Remove(false);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetScreenOffDelayCallBack(JNIEnv * env, jclass clazz,int Result)
{
	UPICOXRSystemAPI::SetScreenOffDelayDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCWriteConfigFileToDataLocalCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::WriteConfigDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOXRSystemAPI::WriteConfigDelegate.ExecuteIfBound(false);
	}
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetWDJsonCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPICOXRSystemAPI::SetWDJsonDelegate.ExecuteIfBound(result);
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetWDModelsCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	TArray<FWifiDisplayModel> models;
	models.Empty();
	TArray<FString> modelsString;
	result.ParseIntoArray(modelsString, TEXT("SPC"), true);
	for (int j=0;j< modelsString.Num();j++)
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

	UPICOXRSystemAPI::SetWDModelsDelegate.ExecuteIfBound(models);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSwitchLargeSpaceSceneCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::EnableLargeSpaceDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOXRSystemAPI::EnableLargeSpaceDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCLargeSpaceStatusCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPICOXRSystemAPI::SwitchLargeSpaceStatusDelegate.ExecuteIfBound(result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCExportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::ExportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOXRSystemAPI::ExportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCImportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPICOXRSystemAPI::ImportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPICOXRSystemAPI::ImportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCControlSetAutoConnectWIFIWithErrorCodeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOXRSystemAPI::ControlSetAutoConnectWIFIWithErrorCodeDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCGetSwitchSystemFunctionStatusCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOXRSystemAPI::GetSwitchSystemFunctionStatusDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCPICOCastInitCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOXRSystemAPI::PICOCastInitDelegate.ExecuteIfBound((ECastInitResult)Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetControllerPairTimeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOXRSystemAPI::SetControllerPairTimeDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCGetControllerPairTimeCallback(JNIEnv * env, jclass clazz, int Result)
{
	UPICOXRSystemAPI::GetControllerPairTimeDelegate.ExecuteIfBound((EControllerPairTimeEnum)Result);
}

#endif