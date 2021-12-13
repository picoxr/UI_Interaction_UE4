// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "OnlinePicoPaymentManager.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

FOnlinePicoPaymentLogInOrOutDelegate OnlinePicoPaymentManager::LogInDelegate;
FOnlinePicoPaymentLogInOrOutDelegate OnlinePicoPaymentManager::LogOutDelegate;
FOnlinePicoPaymentGetUserInfoDelegate OnlinePicoPaymentManager::UserInfoDelegate;
FOnlinePicoPaymentPayOrderDelegate OnlinePicoPaymentManager::PayOrderDelegate;
FOnlinePicoPaymentQueryOrderDelegate OnlinePicoPaymentManager::QueryOrderDelegate;
FOnlinePicoPaymentExceptionDelegate OnlinePicoPaymentManager::ExceptionDelegate;

OnlinePicoPaymentManager::OnlinePicoPaymentManager()
{
}

OnlinePicoPaymentManager::~OnlinePicoPaymentManager()
{
}

void OnlinePicoPaymentManager::PicoLoginSDK(FOnlinePicoPaymentLogInOrOutDelegate InLogInDelegate)
{
	OnlinePicoPaymentManager::LogInDelegate = InLogInDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_Login", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoLogoutSDK(FOnlinePicoPaymentLogInOrOutDelegate InLogOutDelegate)
{
	LogOutDelegate = InLogOutDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_Logout", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentLogin(FOnlinePicoPaymentLogInOrOutDelegate InLogInDelegate)
{
	LogInDelegate = InLogInDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_Login", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentLogout(FOnlinePicoPaymentLogInOrOutDelegate InLogOutDelegate)
{
	LogOutDelegate = InLogOutDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_Logout", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoSDKGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate InUserInfoDelegate)
{
	UserInfoDelegate = InUserInfoDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_GetUserInfo", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate InUserInfoDelegate)
{
	UserInfoDelegate = InUserInfoDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_GetUserInfo", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentPayWithCoin(FOnlinePicoCoinOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate InPayOrderDelegate)
{
	PayOrderDelegate = InPayOrderDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.OrderNumber));
		jstring j_order_title = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.OrderTitle));
		jstring j_product_detail = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.ProductDetail));
		jstring j_notify_url = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.NotifyUrl));
		int32 j_coin_count = Order.PicoCoinCount;

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_PayWithCoin", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number, j_order_title, j_product_detail, j_notify_url, j_coin_count);

		Env->DeleteLocalRef(j_order_number);
		Env->DeleteLocalRef(j_order_title);
		Env->DeleteLocalRef(j_product_detail);
		Env->DeleteLocalRef(j_notify_url);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentPayWithPayCode(FOnlinePicoPayCodeOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate InPayOrderDelegate)
{
	PayOrderDelegate = InPayOrderDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.OrderNumber));
		jstring j_order_title = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.OrderTitle));
		jstring j_product_detail = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.ProductDetail));
		jstring j_notify_url = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.NotifyUrl));
		jstring j_pay_code = Env->NewStringUTF(TCHAR_TO_UTF8(*Order.PicoPayCode));

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_PayWithPayCode", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number, j_order_title, j_product_detail, j_notify_url, j_pay_code);

		Env->DeleteLocalRef(j_order_number);
		Env->DeleteLocalRef(j_order_title);
		Env->DeleteLocalRef(j_product_detail);
		Env->DeleteLocalRef(j_notify_url);
		Env->DeleteLocalRef(j_pay_code);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentQueryOrder(FString OrderNumber, FOnlinePicoPaymentQueryOrderDelegate InQueryOrderDelegate)
{
	QueryOrderDelegate = InQueryOrderDelegate;
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring j_order_number = Env->NewStringUTF(TCHAR_TO_UTF8(*OrderNumber));

		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "Payment_QueryOrder", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, j_order_number);

		Env->DeleteLocalRef(j_order_number);
	}
#endif
}

void OnlinePicoPaymentManager::PicoPaymentBindExceptionDelegate(FOnlinePicoPaymentExceptionDelegate InExceptionDelegate)
{
	ExceptionDelegate = InExceptionDelegate;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoLogInCallback(JNIEnv * env, jclass clazz, jboolean isSuccess, jstring reason)
{
	bool _isSuccess = (bool)isSuccess;
	FString _reason;
	if (reason != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(reason, 0);
		_reason = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(reason, JavaChars);
	}

	if (OnlinePicoPaymentManager::LogInDelegate.IsBound())
	{
		OnlinePicoPaymentManager::LogInDelegate.Execute(_isSuccess, _reason);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoLogOutCallback(JNIEnv * env, jclass clazz, jboolean isSuccess, jstring reason)
{
	bool _isSuccess = (bool)isSuccess;
	FString _reason;
	if (reason != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(reason, 0);
		_reason = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(reason, JavaChars);
	}

	if (OnlinePicoPaymentManager::LogOutDelegate.IsBound())
	{
		OnlinePicoPaymentManager::LogOutDelegate.Execute(_isSuccess, _reason);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoGetUserInfoCompleteCallback(JNIEnv * env, jclass clazz, jstring info)
{
	FString _info;
	if (info != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(info, 0);
		_info = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(info, JavaChars);
	}

	if (OnlinePicoPaymentManager::UserInfoDelegate.IsBound())
	{
		OnlinePicoPaymentManager::UserInfoDelegate.Execute(_info);
	}

}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoPaymentExceptionCallback(JNIEnv * env, jclass clazz, jstring exception)
{
	FString _exception;
	if (exception != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(exception, 0);
		_exception = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(exception, JavaChars);
	}

	if (OnlinePicoPaymentManager::ExceptionDelegate.IsBound())
	{
		OnlinePicoPaymentManager::ExceptionDelegate.Execute(_exception);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoPayOrderCallback(JNIEnv * env, jclass clazz, jstring code, jstring msg)
{
	FString _code, _msg;
	if (code != NULL && msg != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(code, 0);
		_code = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(code, JavaChars);

		JavaChars = env->GetStringUTFChars(msg, 0);
		_msg = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(msg, JavaChars);
	}

	if (OnlinePicoPaymentManager::PayOrderDelegate.IsBound())
	{
		OnlinePicoPaymentManager::PayOrderDelegate.Execute(_code, _msg);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoQueryOrdersCallback(JNIEnv * env, jclass clazz, jstring code, jstring msg)
{
	FString _code, _msg;
	if (code != NULL && msg != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(code, 0);
		_code = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(code, JavaChars);

		JavaChars = env->GetStringUTFChars(msg, 0);
		_msg = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(msg, JavaChars);
	}

	if (OnlinePicoPaymentManager::QueryOrderDelegate.IsBound())
	{
		OnlinePicoPaymentManager::QueryOrderDelegate.Execute(_code, _msg);
	}
}
#endif