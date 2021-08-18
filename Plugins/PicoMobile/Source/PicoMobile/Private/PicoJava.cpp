// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoJava.h"
#include "PicoImport.h"

#if PLATFORM_ANDROID

static int32 AndroidThunkCpp_verifyAPP(FString appID, FString publicKey)
{
	int32 ret = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{

		jstring j_appID = Env->NewStringUTF(TCHAR_TO_UTF8(*appID));
		jstring j_publicKey = Env->NewStringUTF(TCHAR_TO_UTF8(*publicKey));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_verifyAPP", "(Ljava/lang/String;Ljava/lang/String;)I", false);
		ret = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, j_appID, j_publicKey);
		Env->DeleteLocalRef(j_appID);
		Env->DeleteLocalRef(j_publicKey);
	}
	return ret;
}

static inline void AndroidThunkCpp_HideLoading()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HideLoading", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline void AndroidThunkCpp_SetHeadSensorData(float *headSensor)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetHeadSensorData", "([F)V", false);
		if (Method != nullptr)
		{
			jfloatArray jfArray = Env->NewFloatArray(7);
			Env->SetFloatArrayRegion(jfArray, 0, 7, headSensor);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, jfArray);
		}
	}
}

static int32 GetLeftControllerConnectState()
{
	int32 connectState = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerConnectState", "()I", false);
		connectState = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return connectState;
}

static int32 GetRightControllerConnectState()
{
	int32 connectState = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerConnectState", "()I", false);
		connectState = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return connectState;
}

static void GetLeftControllerFixedSensorState(float& x, float& y, float& z, float& w, float& px, float& py, float& pz)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getLeftControllerFixedSensorState", "()[F", false);
		jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
		x = jfp[0];
		y = jfp[1];
		z = jfp[2];
		w = jfp[3];
		px = jfp[4];
		py = jfp[5];
		pz = jfp[6];
		Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
		Env->DeleteLocalRef(jfArray);
	}
}

static void GetRightControllerFixedSensorState(float& x, float& y, float& z, float& w, float& px, float& py, float& pz)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getRightControllerFixedSensorState", "()[F", false);
		jfloatArray jfArray = (jfloatArray)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		jfloat *jfp = Env->GetFloatArrayElements(jfArray, JNI_FALSE);
		x = jfp[0];
		y = jfp[1];
		z = jfp[2];
		w = jfp[3];
		px = jfp[4];
		py = jfp[5];
		pz = jfp[6];
		Env->ReleaseFloatArrayElements(jfArray, jfp, JNI_ABORT);
		Env->DeleteLocalRef(jfArray);
	}
}

static int32 GetLeftControllerTrigger()
{
	int32 TriggerPress = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getMainControllerTriggerNum", "()I", false);
		TriggerPress = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	if (TriggerPress <= 0)
	{
		return 0;
	}
	else
	{
		return 8;
	}
}

static int32 GetRightControllerTrigger()
{
	int32 TriggerPress = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getSubControllerTriggerNum", "()I", false);
		TriggerPress = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	if (TriggerPress <= 0)
	{
		return 0;
	}
	else
	{
		return 8;
	}
}

int32 FPicoJava::GetControllerSensorStatus(int32 Handness)
{
	int32 SensorStatus = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getControllerSensorStatus", "(I)I", false);
		SensorStatus = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, Handness);
		//UE_LOG(LogTemp,Log,TEXT("110900: GetControllerSensorStatus handness: %d, State: %d"),Handness,SensorStatus);
	}
	return SensorStatus;
}

static inline jclass AndroidThunkCpp_GetRawClass()
{
	jclass ret = nullptr;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetRawClass", "()Lcom/psmart/vrlib/VrActivity;", false);
		ret = (jclass)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return ret;
}

static inline int32 AndroidThunkCpp_GetCurrentBrightness()
{
	int32 currentBrightness = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetCurrentBrightness", "()I", false);
		currentBrightness = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return currentBrightness;
}

static inline bool AndroidThunkCpp_SetBrightness(int32 brightness)
{
	bool ret = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_SetBrightness", "(I)Z", false);
		ret = (bool)FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method,brightness);
	}
	return ret;
}

static inline int32 AndroidThunkCpp_GetCurrentVolume()
{
	int32 currentVolume = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetCurrentVolume", "()I", false);
		currentVolume = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return currentVolume;
}

static inline int32 AndroidThunkCpp_GetMaxVolumeNumber()
{
	int32 maxVolume = -1;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetMaxVolumeNumber", "()I", false);
		maxVolume = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return maxVolume;
}

static inline void AndroidThunkCpp_SetVolume(int32 volume)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_SetVolume", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, volume);
	}
}

static inline void AndroidThunkCpp_VolumeUp()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_VolumeUp", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline void AndroidThunkCpp_VolumeDown()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_VolumeDown", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline int32 AndroidThunkCpp_GetHandness()
{
	int32 handness = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetHandness", "()I", false);
		handness = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return handness;
}

static inline void AndroidThunkCpp_Payment_Login()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_Login", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline void AndroidThunkCpp_Payment_Logout()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_Logout", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline void AndroidThunkCpp_Payment_GetUserInfo()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_GetUserInfo", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

static inline void AndroidThunkCpp_Payment_PayWithCoin(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const int32& pico_coin_count)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*order_number));
		jstring j_order_title = Env->NewStringUTF(TCHAR_TO_UTF8(*order_title));
		jstring j_product_detail = Env->NewStringUTF(TCHAR_TO_UTF8(*product_detail));
		jstring j_notify_url = Env->NewStringUTF(TCHAR_TO_UTF8(*notify_url));
		int32 j_coin_count = pico_coin_count;

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_PayWithCoin", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number, j_order_title, j_product_detail, j_notify_url, j_coin_count);
		
		Env->DeleteLocalRef(j_order_number);
		Env->DeleteLocalRef(j_order_title);
		Env->DeleteLocalRef(j_product_detail);
		Env->DeleteLocalRef(j_notify_url);
	}
}

static inline void AndroidThunkCpp_Payment_PayWithPayCode(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const FString& pay_code)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*order_number));
		jstring j_order_title = Env->NewStringUTF(TCHAR_TO_UTF8(*order_title));
		jstring j_product_detail = Env->NewStringUTF(TCHAR_TO_UTF8(*product_detail));
		jstring j_notify_url = Env->NewStringUTF(TCHAR_TO_UTF8(*notify_url));
		jstring j_pay_code = Env->NewStringUTF(TCHAR_TO_UTF8(*pay_code));

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_PayWithPayCode", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number, j_order_title, j_product_detail, j_notify_url, j_pay_code);

		Env->DeleteLocalRef(j_order_number);
		Env->DeleteLocalRef(j_order_title);
		Env->DeleteLocalRef(j_product_detail);
		Env->DeleteLocalRef(j_notify_url);
		Env->DeleteLocalRef(j_pay_code);
	}
}

static inline void AndroidThunkCpp_Payment_QueryOrder(const FString& order_number)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*order_number));

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_Payment_QueryOrder", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number);

		Env->DeleteLocalRef(j_order_number);
	}
}

static inline int32 AndroidThunkCpp_GetPsensorState()
{
	int32 handness = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetPsensorState", "()I", false);
		handness = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return handness;
}

static inline FString AndroidThunkCpp_GetDeviceSN()
{
	FString ret = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetDeviceSN", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			ret = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
	return ret;
}

//===========================================================

int32 FPicoJava::VerifyAPP(FString appID, FString publicKey)
{
	return AndroidThunkCpp_verifyAPP(appID, publicKey);
}

void FPicoJava::HideLoading()
{
	AndroidThunkCpp_HideLoading();
}

void FPicoJava::SetHeadSensorData(float x, float y, float z, float w, float px, float py, float pz)
{
	float headSensor[7] = { x, y, z, w, px, py, pz };
	AndroidThunkCpp_SetHeadSensorData(headSensor);
}

int32 FPicoJava::GetLeftConConnectState()
{
	return GetLeftControllerConnectState();
}

int32 FPicoJava::GetRightConConnectState()
{
	return GetRightControllerConnectState();
}

void FPicoJava::GetLeftControllerSensorData(float& x, float& y, float& z, float& w, float& px, float& py, float& pz)
{
	GetLeftControllerFixedSensorState(x, y, z, w, px, py, pz);
}

void FPicoJava::GetRightControllerSensorData(float& x, float& y, float& z, float& w, float& px, float& py, float& pz)
{
	GetRightControllerFixedSensorState(x, y, z, w, px, py, pz);
}

int32 FPicoJava::GetLeftControllerTriggerToBoundary()
{
	return GetLeftControllerTrigger();
}

int32 FPicoJava::GetRightControllerTriggerToBoundary()
{
	return GetRightControllerTrigger();
}

jclass FPicoJava::GetRawClass()
{
	return AndroidThunkCpp_GetRawClass();
}

int32 FPicoJava::GetCurrentBrightness()
{
	return AndroidThunkCpp_GetCurrentBrightness();
}

bool FPicoJava::SetBrightness(int32 brightness)
{
	return AndroidThunkCpp_SetBrightness(brightness);
}

int32 FPicoJava::GetCurrentVolume()
{
	return AndroidThunkCpp_GetCurrentVolume();
}

int32 FPicoJava::GetMaxVolumeNumber()
{
	return AndroidThunkCpp_GetMaxVolumeNumber();
}

void FPicoJava::SetVolume(int32 volume)
{
	AndroidThunkCpp_SetVolume(volume);
}

void FPicoJava::VolumeUp()
{
	AndroidThunkCpp_VolumeUp();
}

void FPicoJava::VolumeDown()
{
	AndroidThunkCpp_VolumeDown();
}

int32 FPicoJava::GetHandness()
{
	return AndroidThunkCpp_GetHandness();
}

int32 FPicoJava::GetControllerType()
{
	int32 ControllerType = 0;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetControllerType", "()I", false);
		ControllerType = (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
	return ControllerType;
}

int32 FPicoJava::Pvr_GetPsensorState()
{
	return AndroidThunkCpp_GetPsensorState();
}

FString FPicoJava::GetDeviceSN()
{
	return AndroidThunkCpp_GetDeviceSN();
}


void FPicoJava::PaymentLogin()
{
	AndroidThunkCpp_Payment_Login();
}

void FPicoJava::PaymentLogout()
{
	AndroidThunkCpp_Payment_Logout();
}

void FPicoJava::PaymentGetUserInfo()
{
	AndroidThunkCpp_Payment_GetUserInfo();
}

void FPicoJava::PaymentPayWithCoin(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const int32& pico_coin_count)
{
	AndroidThunkCpp_Payment_PayWithCoin(order_number, order_title, product_detail, notify_url,pico_coin_count);
}

void FPicoJava::PaymentPayWithPayCode(const FString& order_number, const FString& order_title, const FString& product_detail, const FString& notify_url, const FString& pay_code)
{
	AndroidThunkCpp_Payment_PayWithPayCode(order_number, order_title, product_detail, notify_url, pay_code);
}

void FPicoJava::PaymentQueryOrder(const FString& order_number)
{
	AndroidThunkCpp_Payment_QueryOrder(order_number);
}

FString  FPicoJava::GetObjectOrArray(FString id,int32 type)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring Id = Env->NewStringUTF(TCHAR_TO_UTF8(*id));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetObjectOrArray", "(Ljava/lang/String;I)Ljava/lang/String;", false);
		FString PackageName = FJavaHelper::FStringFromLocalRef(Env,(jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, Id, type) );
		Env->DeleteLocalRef(Id);
		return PackageName;
	}
	return TEXT("");
}

FString FPicoJava::GetSystemProperty(FString Kay)
{
	FString PropertyValue = "";
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_Key = Env->NewStringUTF(TCHAR_TO_UTF8(*Kay));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSystemProperty", "(Ljava/lang/String;)Ljava/lang/String;", false);
		PropertyValue = FJavaHelper::FStringFromLocalRef(Env,(jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method, j_Key));
		Env->DeleteLocalRef(j_Key);
	}
	return PropertyValue;
}

#endif

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void JNICALL Java_com_psmart_vrlib_HomeKeyReceiverNative_nativePicoHomeReset(JNIEnv * jni, jclass clazz)
{
	PicoSDK::Sensor::OptionalResetSensor(PicoSDK::Sensor::GMainSensorIndex, 1, 1);
}
#endif


void FPicoSystemToolService::BindToBService()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "BindToBService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::UnBindToBService()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UnBindToBService", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	
}

FString FPicoSystemToolService::GetDeviceInfo(int32 Type)
{
	FString Result = FString("");
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetDeviceInfo", "(I)Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method,Type);
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

void FPicoSystemToolService::SetDeviceAction(int32 DeviceControlEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetDeviceAction", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,DeviceControlEnum);
	}
#endif
}

void FPicoSystemToolService::ControlAppManger(int32 PackageControlEnum, FString Path, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Path = Env->NewStringUTF(TCHAR_TO_UTF8(*Path));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "APPManger", "(ILjava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,PackageControlEnum,jstring_Path,Ext);
		Env->DeleteLocalRef(jstring_Path);
	}
#endif
}

void FPicoSystemToolService::SetAutoConnectWifi(FString WifiName, FString WifiPSD, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_WifiName = Env->NewStringUTF(TCHAR_TO_UTF8(*WifiName));
		jstring jstring_WifiPSD = Env->NewStringUTF(TCHAR_TO_UTF8(*WifiPSD));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetAutoConnectWIFI", "(Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,jstring_WifiName,jstring_WifiPSD,Ext);
		Env->DeleteLocalRef(jstring_WifiName);
		Env->DeleteLocalRef(jstring_WifiPSD);
	}
#endif
}

void FPicoSystemToolService::ClearAutoConnectWifi()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ClearAutoConnectWIFI", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::SetHomeKey(int32 EventEnum, int32 FunctionEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHomeKey", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,EventEnum,FunctionEnum);
	}
#endif
}

void FPicoSystemToolService::SetHomeKeyAll(int32 EventEnum, int32 FunctionEnum, int32 TimeSetup, FString Package,
	FString ClassName)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Package = Env->NewStringUTF(TCHAR_TO_UTF8(*Package));
		jstring jstring_ClassName = Env->NewStringUTF(TCHAR_TO_UTF8(*ClassName));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetHomeKeyAll", "(IIILjava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,EventEnum,FunctionEnum,TimeSetup,jstring_Package,jstring_ClassName);
		Env->DeleteLocalRef(jstring_Package);
		Env->DeleteLocalRef(jstring_ClassName);
	}
#endif
}

void FPicoSystemToolService::DisablePowerKey(bool bIsSingleTap, bool bEnable)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisablePowerKey", "(ZZ)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,bIsSingleTap,bEnable);
	}
#endif
}

void FPicoSystemToolService::SetSleepDelay(int32 TimeEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetSleepDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,TimeEnum);
	}
#endif
}

void FPicoSystemToolService::SetScreenOffDelay(int32 TimeEnum)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetScreenOffDelay", "(I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,TimeEnum);
	}
#endif
}

void FPicoSystemToolService::SwitchSystemFunction(int32 SystemFunction, int32 SwitchEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SystemFunction", "(III)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,SystemFunction,SwitchEnum,Ext);
	}
#endif
}

void FPicoSystemToolService::SetUsbConfigurationOption(int32 UsbConfigModeEnum, int32 Ext)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "SetUsbConfigurationOption", "(II)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,UsbConfigModeEnum,Ext);
	}
#endif
}

void FPicoSystemToolService::ScreenOn()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOn", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::ScreenOff()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ScreenOff", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::AcquireWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AcquireWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::ReleaseWakeLock()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AcquireWakeLock", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::WriteConfigFileToDataLocal(FString Path, FString Content)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstring_Path = Env->NewStringUTF(TCHAR_TO_UTF8(*Path));
		jstring jstring_Content = Env->NewStringUTF(TCHAR_TO_UTF8(*Content));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "WriteConfigFileToDataLocal", "(Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method,jstring_Path,jstring_Content);
		Env->DeleteLocalRef(jstring_Path);
		Env->DeleteLocalRef(jstring_Content);
	}
#endif
}

void FPicoSystemToolService::ResetAllKeyToDefault()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ResetAllKeyToDefault", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::EnableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::DisableEnterKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableEnterKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::EnableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::DisableVolumeKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableVolumeKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::EnableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "EnableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void FPicoSystemToolService::DisableBackKey()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "DisableBackKey", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}
