// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "PXR_Settings.h"
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
	bUseHWsRGBEncoding(false),
	bUseRecommendedMSAA(false),
	bEnableFoveation(false),
	FoveationLevel(EFoveationLevel::Low),
	bEnableEyeTracking(false),
	bEnableEyeTrackingMarker(false),
	bUseAdvanceInterface(false),
	bUseContentProtect(false),
	bSplashScreenAutoShow(false),
	refreshRate(ERefreshRate::Default)
{	
}

void UPicoXRSettings::PostInitProperties()
{
	Super::PostInitProperties();
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
#endif 


