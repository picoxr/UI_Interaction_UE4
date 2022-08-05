//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#include "PXR_SystemAPI.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

TMap<EDeviceControlEnum,FPicoSetDeviceActionDelegate> UPicoXRSystemAPI::SetDeviceActionDelegates;
TMap<FAppManagerStruct,FPicoAppManagerDelegate> UPicoXRSystemAPI::AppManagerDelegates;
FPicoSetAutoConnectWifiDelegate UPicoXRSystemAPI::SetAutoConnectWifiDelegate;
FPicoClearAutoConnectWifiDelegate UPicoXRSystemAPI::ClearAutoConnectWifiDelegate;
TMap<EHomeEventEnum,FPicoSetHomeKeyDelegate> UPicoXRSystemAPI::SetHomeKeyDelegates;
TMap<EHomeEventEnum,FPicoSetHomeKeyAllDelegate> UPicoXRSystemAPI::SetHomeKeyAllDelegates;
TMap<bool,FPicoDisablePowerKeyDelegate> UPicoXRSystemAPI::DisablePowerKeyDelegates;
FPicoSetScreenOffDelayDelegate UPicoXRSystemAPI::SetScreenOffDelayDelegate;
FPicoWriteConfigFileToDataLocalDelegate UPicoXRSystemAPI::WriteConfigDelegate;
FPicoResetAllKeyToDefaultDelegate UPicoXRSystemAPI::ResetAllKeyDelegate;
FPicoSetWDJsonDelegate UPicoXRSystemAPI::SetWDJsonDelegate;
FPicoSetWDModelsDelegate UPicoXRSystemAPI::SetWDModelsDelegate;

FPicoEnableLargeSpaceDelegate UPicoXRSystemAPI::EnableLargeSpaceDelegate;
FPicoSwitchLargeSpaceStatusDelegate UPicoXRSystemAPI::SwitchLargeSpaceStatusDelegate;
FPicoExportMapsDelegate UPicoXRSystemAPI::ExportMapsDelegate;
FPicoImportMapsDelegate UPicoXRSystemAPI::ImportMapsDelegate;
FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate UPicoXRSystemAPI::ControlSetAutoConnectWIFIWithErrorCodeDelegate;
// Sets default values for this component's properties
UPicoXRSystemAPI::UPicoXRSystemAPI()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPicoXRSystemAPI::BeginPlay()
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

void UPicoXRSystemAPI::EndPlay(const EEndPlayReason::Type EndPlayReason)
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
void UPicoXRSystemAPI::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UPicoXRSystemAPI::PXR_GetDeviceInfo(ESystemInfoEnum InfoEnum)
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

void UPicoXRSystemAPI::PXR_SetDeviceAction(EDeviceControlEnum DeviceControlEnum,FPicoSetDeviceActionDelegate SetDeviceActionDelegate)
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

void UPicoXRSystemAPI::PXR_AppManager(EPackageControlEnum PackageControlEnum, FString Path, int32 Ext,	FPicoAppManagerDelegate AppManagerDelegate)
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

void UPicoXRSystemAPI::PXR_SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext,FPicoSetAutoConnectWifiDelegate InSetAutoConnectWifiDelegate)
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

void UPicoXRSystemAPI::PXR_ClearAutoConnectWifi(FPicoClearAutoConnectWifiDelegate InClearAutoConnectWifiDelegate)
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

void UPicoXRSystemAPI::PXR_SetHomeKey(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum,FPicoSetHomeKeyDelegate SetHomeKeyDelegate)
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

void UPicoXRSystemAPI::PXR_SetHomeKeyAll(EHomeEventEnum EventEnum, EHomeFunctionEnum FunctionEnum, int32 TimeSetup,FString Package, FString ClassName, FPicoSetHomeKeyAllDelegate SetHomeKeyAllDelegate)
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

void UPicoXRSystemAPI::PXR_DisablePowerKey(bool bIsSingleTap, bool bEnable,FPicoDisablePowerKeyDelegate InDisablePowerKeyDelegate)
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

void UPicoXRSystemAPI::PXR_SetSleepDelay(EScreenOffDelayTimeEnum TimeEnum,	FPicoSetScreenOffDelayDelegate InSetScreenOffDelayDelegate)
{

	SetScreenOffDelayDelegate = InSetScreenOffDelayDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSleepDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(TimeEnum));
	}
#endif
}

void UPicoXRSystemAPI::PXR_SetScreenOffDelay(ESleepDelayTimeEnum TimeEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetScreenOffDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(TimeEnum));
	}
#endif
}

void UPicoXRSystemAPI::PXR_SwitchSystemFunction(ESystemFunctionSwitchEnum SystemFunction, ESwitchEnum SwitchEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SystemFunction", "(III)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(SystemFunction), static_cast<int32>(SwitchEnum), Ext);
	}
#endif
}

void UPicoXRSystemAPI::PXR_SetUsbConfigurationOption(EUSBConfigModeEnum UsbConfigModeEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetUsbConfigurationOption", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, static_cast<int32>(UsbConfigModeEnum), Ext);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ScreenOn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ScreenOff()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOff", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_AcquireWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AcquireWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ReleaseWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ReleaseWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_WriteConfigFileToDataLocal(FString Path, FString Content, FPicoWriteConfigFileToDataLocalDelegate InWriteConfigDelegate)
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

void UPicoXRSystemAPI::PXR_ResetAllKeyToDefault(FPicoResetAllKeyToDefaultDelegate InResetAllKeyDelegate)
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

void UPicoXRSystemAPI::PXR_EnableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_DisableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_EnableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_DisableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_EnableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_DisableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

int32 UPicoXRSystemAPI::PXR_GetCurrentBrightness()
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

void UPicoXRSystemAPI::PXR_SetBrightness(int32 Brightness)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetBrightness", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, Brightness);
	}
#endif
}

int32 UPicoXRSystemAPI::PXR_GetCurrentVolume()
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

int32 UPicoXRSystemAPI::PXR_GetMaxVolume()
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

void UPicoXRSystemAPI::PXR_SetVolume(int32 Volume)
{
#if PLATFORM_ANDROID
	if (JNIEnv *Env =FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetVolume", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env,FJavaWrapper::GameActivityThis,Method,Volume);

	}
#endif
}

void UPicoXRSystemAPI::PXR_VolumeUp()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeUp", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif	
}

void UPicoXRSystemAPI::PXR_VolumeDown()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env=FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "VolumeDown", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}


FString UPicoXRSystemAPI::PXR_GetDeviceSN()
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

void UPicoXRSystemAPI::PXR_FreezeScreen(bool freeze)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "FreezeScreen", "(Z)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, freeze);
	}
#endif
}

void UPicoXRSystemAPI::PXR_KillAppsByPidOrPackageName(TArray<int> pids, TArray<FString> packageNames, int ext)
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

void UPicoXRSystemAPI::PXR_KillBackgroundAppsWithWhiteList(TArray<FString> packageNames, int ext)
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

void UPicoXRSystemAPI::PXR_OpenMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OpenMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

bool UPicoXRSystemAPI::PXR_IsMiracastOn()
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

void UPicoXRSystemAPI::PXR_CloseMiracast()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "CloseMiracast", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_StartScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StartScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_StopScan()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "StopScan", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ConnectWifiDisplay(const FWifiDisplayModel &Model)
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

void UPicoXRSystemAPI::PXR_DisConnectWifiDisplay()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisConnectWifiDisplay", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ForgetWifiDisplay(FString Address)
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

void UPicoXRSystemAPI::PXR_RenameWifiDisplay(FString Address, FString NewName)
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

void UPicoXRSystemAPI::PXR_UpdateWifiDisplays()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UpdateWifiDisplays", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_GetConnectedWD(FWifiDisplayModel& Model)
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

void UPicoXRSystemAPI::PXR_SetWDJson(FPicoSetWDJsonDelegate InSetWDJsonDelegate)
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

void UPicoXRSystemAPI::PXR_SetWDModels(FPicoSetWDModelsDelegate InSetWDModelsDelegate)
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


void UPicoXRSystemAPI::PXR_SwitchLargeSpaceScene(FPicoEnableLargeSpaceDelegate InEnableLargeSpaceDelegate, bool open, int ext)
{
	EnableLargeSpaceDelegate = InEnableLargeSpaceDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SwitchLargeSpaceScene", "(ZI)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, open, ext);
	}
#endif
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSwitchLargeSpaceStatus", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
	}
#endif
}

void UPicoXRSystemAPI::PXR_GetSwitchLargeSpaceStatus(FPicoSwitchLargeSpaceStatusDelegate InSwitchLargeSpaceStatusDelegate, int ext)
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

bool UPicoXRSystemAPI::PXR_SaveLargeSpaceMaps(int ext)
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

void UPicoXRSystemAPI::PXR_ExportMaps(FPicoExportMapsDelegate InExportMapsDelegate, int ext)
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

void UPicoXRSystemAPI::PXR_ImportMaps(FPicoImportMapsDelegate InImportMapsDelegate, int ext)
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

void UPicoXRSystemAPI::PXR_GetCpuUsages(TArray<float>& OutData)
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

void UPicoXRSystemAPI::PXR_GetDeviceTemperatures(int inType, int inSource, TArray<float>& OutData)
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

void UPicoXRSystemAPI::PXR_Capture()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Capture", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_Record()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Record", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UPicoXRSystemAPI::PXR_ControlSetAutoConnectWIFIWithErrorCode(FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate InControlSetAutoConnectWIFIWithErrorCodeDelegate, FString ssid, FString pwd, int ext)
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

void UPicoXRSystemAPI::PXR_AppKeepAlive(FString appPackageName, bool keepAlive, int ext)
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

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetDeviceActionCallBack(JNIEnv * env, jclass clazz,int EventType, int Result)
{
	if (EventType == 0)
	{
		if (UPicoXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT))
		{
			UPicoXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_REBOOT)->ExecuteIfBound(Result);
			UPicoXRSystemAPI::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_REBOOT);
		}
	}else if (EventType == 1)
	{
		if (UPicoXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN))
		{
			UPicoXRSystemAPI::SetDeviceActionDelegates.Find(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN)->ExecuteIfBound(Result);
			UPicoXRSystemAPI::SetDeviceActionDelegates.Remove(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAPPMangerCallBack(JNIEnv * env, jclass clazz,int EventType, jstring AppPath, int Result)
{
	FAppManagerStruct ManagerStruct;
	ManagerStruct.AppPath = FJavaHelper::FStringFromParam(env, AppPath);
	ManagerStruct.PackageControl = static_cast<EPackageControlEnum>(EventType);
	if(UPicoXRSystemAPI::AppManagerDelegates.Find(ManagerStruct))
	{
		UPicoXRSystemAPI::AppManagerDelegates.Find(ManagerStruct)->ExecuteIfBound(Result);
		UPicoXRSystemAPI::AppManagerDelegates.Remove(ManagerStruct);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::SetAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoXRSystemAPI::SetAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCClearAutoConnectWifiCallBack(JNIEnv * env, jclass clazz,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::ClearAutoConnectWifiDelegate.ExecuteIfBound(true);
	}else
	{
		UPicoXRSystemAPI::ClearAutoConnectWifiDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPicoXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPicoXRSystemAPI::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPicoXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoXRSystemAPI::SetHomeKeyDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPicoXRSystemAPI::SetHomeKeyDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetHomeKeyAllCallBack(JNIEnv * env, jclass clazz,int EventType, int FunctionType,jboolean Result)
{
	if(Result == JNI_TRUE)
	{
		if(UPicoXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(true);
			UPicoXRSystemAPI::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}else
	{
		if(UPicoXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType)))
		{
			UPicoXRSystemAPI::SetHomeKeyAllDelegates.Find(static_cast<EHomeEventEnum>(EventType))->ExecuteIfBound(false);
			UPicoXRSystemAPI::SetHomeKeyAllDelegates.Remove(static_cast<EHomeEventEnum>(EventType));
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCDisablePowerKeyCallBack(JNIEnv * env, jclass clazz,jboolean isSingleTap, int Result)
{
	if(isSingleTap == JNI_TRUE)
	{
		if(UPicoXRSystemAPI::DisablePowerKeyDelegates.Find(true))
		{
			UPicoXRSystemAPI::DisablePowerKeyDelegates.Find(true)->ExecuteIfBound(Result);
			UPicoXRSystemAPI::DisablePowerKeyDelegates.Remove(true);
		}
	}else
	{
		if(UPicoXRSystemAPI::DisablePowerKeyDelegates.Find(false))
		{
			UPicoXRSystemAPI::DisablePowerKeyDelegates.Find(false)->ExecuteIfBound(Result);
			UPicoXRSystemAPI::DisablePowerKeyDelegates.Remove(false);
		}
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetScreenOffDelayCallBack(JNIEnv * env, jclass clazz,int Result)
{
	UPicoXRSystemAPI::SetScreenOffDelayDelegate.ExecuteIfBound(Result);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCWriteConfigFileToDataLocalCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::WriteConfigDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPicoXRSystemAPI::WriteConfigDelegate.ExecuteIfBound(false);
	}
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSetWDJsonCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPicoXRSystemAPI::SetWDJsonDelegate.ExecuteIfBound(result);
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

	UPicoXRSystemAPI::SetWDModelsDelegate.ExecuteIfBound(models);
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCSwitchLargeSpaceSceneCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::EnableLargeSpaceDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPicoXRSystemAPI::EnableLargeSpaceDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCLargeSpaceStatusCallback(JNIEnv * env, jclass clazz, jstring Result)
{
	FString result = FJavaHelper::FStringFromLocalRef(env, Result);
	UPicoXRSystemAPI::SwitchLargeSpaceStatusDelegate.ExecuteIfBound(result);

	if (GEngine && GEngine->XRSystem.IsValid())
	{
		static_cast<FPicoXRHMD*>(GEngine->XRSystem.Get())->OnLargeSpaceStatusChanged(result == "1" ? true : false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCExportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::ExportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPicoXRSystemAPI::ExportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCImportMapsCallback(JNIEnv * env, jclass clazz, jboolean Result)
{
	if (Result == JNI_TRUE)
	{
		UPicoXRSystemAPI::ImportMapsDelegate.ExecuteIfBound(true);
	}
	else
	{
		UPicoXRSystemAPI::ImportMapsDelegate.ExecuteIfBound(false);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCControlSetAutoConnectWIFIWithErrorCodeCallback(JNIEnv * env, int Result)
{
	UPicoXRSystemAPI::ControlSetAutoConnectWIFIWithErrorCodeDelegate.ExecuteIfBound(Result);
}

#endif