// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "OnlinePicoSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class ONLINESUBSYSTEMPICO_API UOnlinePicoSettings : public UObject
{
	GENERATED_UCLASS_BODY()
public:

	// Payment
	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "Enable Payment Module"))
		bool bEnablePaymentModule;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "Is Foreign"))
		bool bIsForeign;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "MerchantID"))
		FString Payment_MerchantID;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "AppID"))
		FString Payment_AppID;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "AppKey"))
		FString Payment_AppKey;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "Scope"))
		FString Payment_Scope;

	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "PayKey"))
		FString Payment_PayKey;

	//EntitlementCheck
	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "User Entitlement Check", ToolTip = "If selected, you will need to enter the APPID that is obtained from Pico Developer Platform after uploading the app for an entitlement check upon the app launch."))
		bool bStartTimeEntitlementCheck;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bStartTimeEntitlementCheck", DisplayName = "App ID"))
		FString EntitlementCheckAppID;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "Entitlement Check Simulation", ToolTip = "If true, Development devices will simulate Entitlement Check, you should enter a valid device SN codes list. The SN code can be obtain in Settings-General-Device serial number or input 'adb devices ' in cmd"))
		bool bEntitlementCheckSimulation;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bEntitlementCheckSimulation", DisplayName = "Device SN Code List"))
		TArray<FString> DeviceSN;
	
	virtual void PostInitProperties() override;
	
};
