//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "PXR_HMDTypes.h"
#include "PXR_Settings.generated.h"

UENUM()
namespace EFoveationLevel
{
	enum Type
	{
		Low,
		Med,
		High,
		TopHigh
	};
}

UENUM()
namespace ERefreshRate
{
	enum Type
	{
		Default,
		RefreshRate72,
		RefreshRate90,
		RefreshRate120
	};
}

UCLASS(config = Engine, defaultconfig)
class PICOXRHMD_API UPicoXRSettings : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	//Sensor
	UPROPERTY(Config, EditAnywhere, Category = HMD, Meta = (DisplayName = "Enable PSensor?", ToolTip = "If you want to get PSensor state,Please enable it!"))
		bool bEnablePSensor;

	UPROPERTY(Config, EditAnywhere, Category = HMD, Meta = (DisplayName = "HMD Only Tracking Rotation"))
		bool bIsHMD3Dof;

	UPROPERTY(Config, EditAnywhere, Category = HMD, Meta = (EditCondition = "bIsHMD3Dof", DisplayName = "Enable Neck Model"))
		bool bEnableNeckModel;

	UPROPERTY(Config, EditAnywhere, Category = HMD, Meta = (EditCondition = "bEnableNeckModel", DisplayName = "Use Custom NeckParameter"))
		bool bUseCustomNeckParameter;

	UPROPERTY(Config, EditAnywhere, Category = HMD, Meta = (EditCondition = "bUseCustomNeckParameter", DisplayName = "NeckOffset"))
		FVector NeckOffset;	

	//Controller
	UPROPERTY(Config, EditAnywhere, Category = Controller, Meta = (DisplayName = "Receive HomeKey Event"))
		bool bEnableHomeKey;

	UPROPERTY(Config, EditAnywhere, Category = Controller, Meta = (DisplayName = "Controller Only Tracking Rotation"))
		bool bIsController3Dof;

	//Feature
	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Enable LateLatching",ToolTip = "Only support UE4.27 + Vulkan + Multi-View + Disable Occlusion Culling."))
		bool bEnableLateLatching;

	UPROPERTY(Config)
		bool bUseHWsRGBEncoding;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Use Recommended MSAA Level"))
		bool bUseRecommendedMSAA;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Enable Foveation Rendering"))
		bool bEnableFoveation;
	
	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (EditCondition = "bEnableFoveation", DisplayName = "Foveation Level"))
		TEnumAsByte<EFoveationLevel::Type> FoveationLevel;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Enable EyeTracking", ToolTip = "Only Neo2 Eye Supports!"))
		bool bEnableEyeTracking;

	//UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (EditCondition = "EnableEyeTracking", DisplayName = "Enable EyeTracking Marker", ToolTip = "Only Neo2 Eye Supports!"))
		bool bEnableEyeTrackingMarker;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Use Pico Advance Interface"))
		bool bUseAdvanceInterface;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (EditCondition = "bUseAdvanceInterface", DisplayName = "Enable Large Space"))
		bool bEnableLargeSpace;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Use Content Protect"))
		bool bUseContentProtect;

	UPROPERTY(config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Auto Show Splash Screen"))
		bool bSplashScreenAutoShow;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (EditCondition = "bSplashScreenAutoShow", DisplayName = "SplashDescs"))
		TArray<FPicoSplashDesc> SplashDescs;

	UPROPERTY(Config, EditAnywhere, Category = Feature, Meta = (DisplayName = "Display Refresh Rates"))
		TEnumAsByte<ERefreshRate::Type> refreshRate;

	virtual void PostInitProperties() override;
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void HandlesRGBHWSupport();
private:
	void ResetsRGBConfig();
#endif

};
