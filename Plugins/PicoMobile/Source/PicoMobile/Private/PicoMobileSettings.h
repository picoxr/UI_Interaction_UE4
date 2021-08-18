// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "PicoSplashTypes.h"
#include "PicoMobileSettings.generated.h"

UENUM()
namespace EFoveationLevel
{
	enum Type
	{
		Low = 0,
		Med = 1,
		High = 2,
		TopHigh=3
	};
}

UCLASS(config = Engine, defaultconfig)
class PICOMOBILE_API UPicoMobileSettings
	: public UObject
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Enable PSensor?", ToolTip = "If you want to get PSensor state, Please enable it!"))
	bool bEnablePSensor;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Enable FoveationRendering?", ToolTip = "If you want to get FoveationRendering, Please enable it!"))
	bool bEnableFoveationRendering;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (EditCondition = "bEnableFoveationRendering", DisplayName = "Foveation Level"))
	TEnumAsByte<EFoveationLevel::Type> FoveationLevel;

	UPROPERTY(Config, EditAnywhere, Category = Controller, Meta = (DisplayName = "Enable HomeKey?"))
	bool bEnableHomeKey;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Only Controller Rotation Tracking"))
	bool bDisableController6DofModule;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Only HMD Rotation Tracking"))
	bool bDisableHmd6DofModule;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (EditCondition = "bDisableHmd6DofModule", DisplayName = "Enable Neck Model"))
	bool bEnableNeckModel;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (EditCondition = "bDisableHmd6DofModule", DisplayName = "Use Custom NeckParameter"))
	bool bUseCustomNeckParameter;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (EditCondition = "bUseCustomNeckParameter", DisplayName = "NeckOffset"))
	FVector neckOffset;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Enable VR Standard Input Event",ToolTip = "EnableMotionControllerInputEvent"))
	bool bEnableVRStandardInput;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Enable EyeTracking", ToolTip = "Only Neo2 Eye Supports!"))
	bool bEnableEyeTracking;

	//UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (EditCondition = "bEnableEyeTracking", DisplayName = "Enable EyeTracking Marker", ToolTip = "Only Neo2 Eye Supports!"))
	bool bEnableEyeTrackingMarker;

	UPROPERTY(Config, EditAnywhere, Category = "PicoMobile", Meta = (DisplayName = "Use Pico Advance Interface"))
	bool bUseAdvanceInterface;

	// payment
	UPROPERTY(Config, EditAnywhere, Category = Payment, Meta = (DisplayName = "Is Foreign"))
	bool bIsForeign;

	UPROPERTY(Config, EditAnywhere, Category= Payment, Meta = (DisplayName = "MerchantID"))
	FString merchantID;

	UPROPERTY(Config, EditAnywhere, Category= Payment, Meta = (DisplayName = "AppID"))
	FString appID;

	UPROPERTY(Config, EditAnywhere, Category= Payment, Meta = (DisplayName = "AppKey"))
	FString appKey;

	UPROPERTY(Config, EditAnywhere, Category= Payment, Meta = (DisplayName = "PayKey"))
	FString payKey;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (DisplayName = "User Entitlement Check", ToolTip = "If selected, you will need to enter the APPID that is obtained from Pico Developer Platform after uploading the app for an entitlement check upon the app launch."))
	bool bStartTimeEntitlementCheck;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bStartTimeEntitlementCheck", DisplayName = "App ID"))
	FString EntitlementCheckAppID;
	
	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bStartTimeEntitlementCheck",DisplayName = "Entitlement Check Simulation", ToolTip = "If true, Development devices will simulate Entitlement Check, you should enter a valid device SN codes list. The SN code can be obtain in Settings-General-Device serial number or input 'adb devices ' in cmd"))
	bool EntitlementCheckSimulation;

	UPROPERTY(Config, EditAnywhere, Category = Platform, Meta = (EditCondition = "bStartTimeEntitlementCheck", DisplayName = "Device SN Code List"))
	TArray<FString> DeviceSN;

	UPROPERTY(config, EditAnywhere, Category = SplashScreen)
	bool bEnableAutoShow;

	UPROPERTY(Config, EditAnywhere, Category = SplashScreen, Meta = (DisplayName = "SplashDescs"))
		FPicoSplashDesc SplashDescs;
	
	virtual void PostInitProperties() override;
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

};
