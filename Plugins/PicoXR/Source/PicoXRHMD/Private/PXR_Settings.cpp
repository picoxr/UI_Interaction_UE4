//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Settings.h"
#if WITH_EDITOR
#include "Editor.h"
#endif
#include "Engine/RendererSettings.h"

UPICOXRSettings::UPICOXRSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	bEnablePSensor(false),
	bIsHMD3Dof(false),
	bEnableNeckModel(true),
	bUseCustomNeckParameter(false),
	NeckOffset(FVector::ZeroVector),
	bEnableHomeKey(false),
	bIsController3Dof(false),
	HandTrackingSupport(EPICOXRHandTrackingSupport::ControllersOnly),
	bEnableLateLatching(false),
	bUseHWsRGBEncoding(true),
	bUseRecommendedMSAA(false),
	bEnableFoveation(false),
	FoveationLevel(EFoveationLevel::Low),
	bEnableEyeTracking(false),
	FaceTrackingMode(EPICOXRFaceTrackingMode::Disable),
	bUseAdvanceInterface(false),
	bUseContentProtect(false),
	bSplashScreenAutoShow(true),
	refreshRate(ERefreshRate::Default)
{
#if WITH_EDITOR
	ResetsRGBConfig();
#endif
}

void UPICOXRSettings::PostInitProperties()
{
	Super::PostInitProperties();
	bUseHWsRGBEncoding = true;
}

#if WITH_EDITOR
void UPICOXRSettings::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (!bIsHMD3Dof ) {
		bUseCustomNeckParameter = false;
	}
	if (!bEnableNeckModel) {
		bUseCustomNeckParameter = false;
	}
	Super::UpdateDefaultConfigFile();
	HandlesRGBHWSupport();
}

void UPICOXRSettings::HandlesRGBHWSupport()
{
	URendererSettings* const Settings = GetMutableDefault<URendererSettings>();
	static auto* MobileUseHWsRGBEncodingCVAR = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Mobile.UseHWsRGBEncoding"));

	if (bUseHWsRGBEncoding != Settings->bMobileUseHWsRGBEncoding)
	{
		Settings->bMobileUseHWsRGBEncoding = bUseHWsRGBEncoding;
		Settings->UpdateSinglePropertyInConfigFile(Settings->GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(URendererSettings, bMobileUseHWsRGBEncoding)), GetDefaultConfigFilename());
	}

	if (MobileUseHWsRGBEncodingCVAR && MobileUseHWsRGBEncodingCVAR->GetInt() != (int)bUseHWsRGBEncoding)
	{
		MobileUseHWsRGBEncodingCVAR->Set((int)bUseHWsRGBEncoding);
	}
}

void UPICOXRSettings::ResetsRGBConfig()
{
	// To Prevent sRGB from being turned off by AndroidSetting
	FEditorDelegates::RefreshAllBrowsers.AddUObject(this,&UPICOXRSettings::HandlesRGBHWSupport);
}
#endif




