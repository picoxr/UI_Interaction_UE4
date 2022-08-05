//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Settings.h"
#if WITH_EDITOR
#include "Editor.h"
#endif
#include "Engine/RendererSettings.h"

UPicoXRSettings::UPicoXRSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	bEnablePSensor(false),
	bIsHMD3Dof(false),
	bEnableNeckModel(true),
	bUseCustomNeckParameter(false),
	NeckOffset(FVector::ZeroVector),
	bEnableHomeKey(false),
	bIsController3Dof(false),
	bEnableLateLatching(false),
	bUseHWsRGBEncoding(true),
	bUseRecommendedMSAA(false),
	bEnableFoveation(false),
	FoveationLevel(EFoveationLevel::Low),
	bEnableEyeTracking(false),
	bEnableEyeTrackingMarker(false),
	bUseAdvanceInterface(false),
	bEnableLargeSpace(false),
	bUseContentProtect(false),
	bSplashScreenAutoShow(true),
	refreshRate(ERefreshRate::Default)
{
#if WITH_EDITOR
	ResetsRGBConfig();
#endif
}

void UPicoXRSettings::PostInitProperties()
{
	Super::PostInitProperties();
	bUseHWsRGBEncoding = true;
}

#if WITH_EDITOR
void UPicoXRSettings::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
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

void UPicoXRSettings::HandlesRGBHWSupport()
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

void UPicoXRSettings::ResetsRGBConfig()
{
	// To Prevent sRGB from being turned off by AndroidSetting
	FEditorDelegates::RefreshAllBrowsers.AddUObject(this,&UPicoXRSettings::HandlesRGBHWSupport);
}
#endif




