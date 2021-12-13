// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "OnlinePicoFunctionLibrary.h"
#include "OnlinePicoSettings.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

TSharedPtr<OnlinePicoPaymentManager> UOnlinePicoFunctionLibrary::PaymentManager = nullptr;
FOnlinePicoVerifyAppDelegate UOnlinePicoFunctionLibrary::VerifyAppDelegate;
int32 UOnlinePicoFunctionLibrary::VerifyAppCode = 1;

UOnlinePicoFunctionLibrary::UOnlinePicoFunctionLibrary()
{
    if (GetMutableDefault<UOnlinePicoSettings>()->bEnablePaymentModule)
    {
        PaymentManager = MakeShareable(new OnlinePicoPaymentManager);
    }
}

void UOnlinePicoFunctionLibrary::PicoLoginSDK(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoLoginSDK(LogInDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentLogin(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentLogin(LogInDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoLogoutSDK(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoLogoutSDK(LogOutDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentLogout(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentLogout(LogOutDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoSDKGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoSDKGetUserInfo(UserInfoDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentGetUserInfo(UserInfoDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentPayWithCoin(FOnlinePicoCoinOrderInfo Order,
    FOnlinePicoPaymentPayOrderDelegate PayOrderWithCoinDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentPayWithCoin(Order, PayOrderWithCoinDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentPayWithPayCode(FOnlinePicoPayCodeOrderInfo Order,
    FOnlinePicoPaymentPayOrderDelegate PayOrderWithCodeDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentPayWithPayCode(Order, PayOrderWithCodeDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoPaymentQueryOrder(FString OrderNumber,
    FOnlinePicoPaymentQueryOrderDelegate QueryOrderDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentQueryOrder(OrderNumber, QueryOrderDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoBindPaymentExceptionDelegate(FOnlinePicoPaymentExceptionDelegate ExceptionDelegate)
{
    if (PaymentManager.IsValid())
    {
        PaymentManager->PicoPaymentBindExceptionDelegate(ExceptionDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoEntitlementVerifyAppDelegate(FOnlinePicoVerifyAppDelegate OnVerifyAppCallback)
{
#if PLATFORM_ANDROID
    VerifyAppDelegate = OnVerifyAppCallback;
    if (GetDefault <UOnlinePicoSettings>()->bStartTimeEntitlementCheck)
    {
        if (VerifyAppCode != 1)
        {
            VerifyAppDelegate.Execute(VerifyAppCode);
        }
    }
#endif
}

void UOnlinePicoFunctionLibrary::PicoEntitlementVerifyCheck()
{
    if (GetDefault <UOnlinePicoSettings>()->bStartTimeEntitlementCheck)
    {
        if (GetDefault <UOnlinePicoSettings>()->bEntitlementCheckSimulation)
        {
            FString DeviceSN = PicoGetDeviceSN();
            if (GetDefault <UOnlinePicoSettings>()->DeviceSN.Num() > 0)
            {
                for (int i = 0; i < GetDefault <UOnlinePicoSettings>()->DeviceSN.Num(); i++)
                {
                    if (GetDefault <UOnlinePicoSettings>()->DeviceSN[i] == DeviceSN)
                    {
                        return;
					}
				}
            }
        }

        FString PublicKey = "";
        FString AppID = GetDefault <UOnlinePicoSettings>()->EntitlementCheckAppID;
        if (AppID == "")
        {
            UE_LOG(LogTemp,Warning,TEXT("APPID is required for Entitlement Check. Create / Find your APP ID on https://developer.pico-interactive.com/developer/overview."));
        }
#if PLATFORM_ANDROID
        if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
        {
            jstring j_appID = Env->NewStringUTF(TCHAR_TO_UTF8(*AppID));
            jstring j_publicKey = Env->NewStringUTF(TCHAR_TO_UTF8(*PublicKey));
            static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_VerifyApp", "(Ljava/lang/String;Ljava/lang/String;)I", false);
            if (Method)
            {
                FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method, j_appID, j_publicKey);
            }
            Env->DeleteLocalRef(j_appID);
            Env->DeleteLocalRef(j_publicKey);
        }
#endif
    }
    else
    {
        UE_LOG(LogTemp, Warning,TEXT("EntitlementCheck is highly recommended which can protect the copyright of app. You can enable it when App start-up in the Inspector of \"Edit->Plugins->PicoMobile->Platform\" and Enter your APPID. If you want to call the APIs as needed, please refer to the development Document."));
    }
}

FString UOnlinePicoFunctionLibrary::PicoGetDeviceSN()
{
    FString DeviceSN = "";
#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "OnlineGetDeviceSN", "()Ljava/lang/String;", false);
        jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
        if (JavaString != NULL)
        {
            const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
            DeviceSN = FString(UTF8_TO_TCHAR(JavaChars));
            Env->ReleaseStringUTFChars(JavaString, JavaChars);
            Env->DeleteLocalRef(JavaString);
        }
    }
#endif
    return DeviceSN;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_JavaToCVerifyCallback(JNIEnv * env, jclass clazz, int32 code)
{
    UOnlinePicoFunctionLibrary::VerifyAppCode = code;
    if (UOnlinePicoFunctionLibrary::VerifyAppDelegate.IsBound())
    {
        UOnlinePicoFunctionLibrary::VerifyAppDelegate.Execute(code);
    }
}
#endif