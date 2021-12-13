// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Private/OnlinePicoPaymentManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnlinePicoFunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnlinePicoVerifyAppDelegate, const int32&, code);

UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UOnlinePicoFunctionLibrary();

	static TSharedPtr<OnlinePicoPaymentManager> PaymentManager;
	static FOnlinePicoVerifyAppDelegate VerifyAppDelegate;
	static int32 VerifyAppCode;

#pragma region Payment
	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoLoginSDK(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentLogin(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
	
		static void PicoLogoutSDK(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentLogout(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoSDKGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentPayWithCoin(FOnlinePicoCoinOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate PayOrderWithCoinDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentPayWithPayCode(FOnlinePicoPayCodeOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate PayOrderWithCodeDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoPaymentQueryOrder(FString OrderNumber, FOnlinePicoPaymentQueryOrderDelegate QueryOrderDelegate);

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoPayment")
		static void PicoBindPaymentExceptionDelegate(FOnlinePicoPaymentExceptionDelegate ExceptionDelegate);

#pragma endregion Payment

	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
		static void PicoEntitlementVerifyAppDelegate(FOnlinePicoVerifyAppDelegate OnVerifyAppCallback);
	
	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
		static void PicoEntitlementVerifyCheck();
	
	UFUNCTION(BlueprintCallable, Category = "OnlinePico|PicoEntitlement")
		static FString PicoGetDeviceSN();
};
