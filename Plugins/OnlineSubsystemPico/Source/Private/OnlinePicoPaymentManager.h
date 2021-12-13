// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "Delegates/Delegate.h"
#include "OnlinePicoPaymentManager.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "OnlinePicoCoinOrderInfo"))
struct FOnlinePicoCoinOrderInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString OrderNumber;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString OrderTitle;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString ProductDetail;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString NotifyUrl;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		int32 PicoCoinCount;
};

USTRUCT(BlueprintType, meta = (DisplayName = "OnlinePicoPayCodeOrderInfo"))
struct FOnlinePicoPayCodeOrderInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString OrderNumber;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString OrderTitle;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString ProductDetail;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString NotifyUrl;

	UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoPayment")
		FString PicoPayCode;
};

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlinePicoPaymentLogInOrOutDelegate, const bool, bIsSucceed, const FString, Reason);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnlinePicoPaymentGetUserInfoDelegate, const FString, Info);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlinePicoPaymentPayOrderDelegate, const FString, Code, const FString, Message);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnlinePicoPaymentQueryOrderDelegate, const FString, Code, const FString, Message);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnlinePicoPaymentExceptionDelegate, const FString, Exception);

class OnlinePicoPaymentManager
{
public:
	OnlinePicoPaymentManager();
	~OnlinePicoPaymentManager();

	static FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate;
	static FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate;
	static FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate;
	static FOnlinePicoPaymentPayOrderDelegate PayOrderDelegate;
	static FOnlinePicoPaymentQueryOrderDelegate QueryOrderDelegate;
	static FOnlinePicoPaymentExceptionDelegate ExceptionDelegate;

	void PicoLoginSDK(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate);

	void PicoLogoutSDK(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate);

	void PicoPaymentLogin(FOnlinePicoPaymentLogInOrOutDelegate LogInDelegate);

	void PicoPaymentLogout(FOnlinePicoPaymentLogInOrOutDelegate LogOutDelegate);

	void PicoSDKGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate);

	void PicoPaymentGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate UserInfoDelegate);

	void PicoPaymentPayWithCoin(FOnlinePicoCoinOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate PayOrderWithCoinDelegate);

	void PicoPaymentPayWithPayCode(FOnlinePicoPayCodeOrderInfo Order, FOnlinePicoPaymentPayOrderDelegate PayOrderWithCodeDelegate);

	void PicoPaymentQueryOrder(FString OrderNumber, FOnlinePicoPaymentQueryOrderDelegate QueryOrderDelegate);

	void PicoPaymentBindExceptionDelegate(FOnlinePicoPaymentExceptionDelegate ExceptionDelegate);
};