// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_HMDRuntimeSettings.h"
#include "Misc/ConfigUtilities.h"
#if WITH_EDITOR
#include "Editor.h"
#endif
#include "Engine/RendererSettings.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/ConfigUtilities.h"

static TAutoConsoleVariable<int32> CVarWaitFrameAtGameFrameTail(
	TEXT("PICO.WaitFrameAtGameFrameTail"),
	0,
	TEXT("Whether to WaitFrame() at the end of the GameFrame!"),
	ECVF_Default);

UPICOXRSettings::UPICOXRSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	bEnablePSensor(false),
	bIsHMD3Dof(false),
	bEnableHomeKey(false),
	bIsController3Dof(false),
	HandTrackingSupport(EPICOXRHandTrackingSupport::ControllersOnly),
	bAdaptiveHandModel(false),
	bHighFrequencyTracking(false),
	bEnableAutoKeyMapping(true),
	bEnableLateLatching(false),
	bUseHWsRGBEncoding(true),
	bUseRecommendedMSAA(false),
	CoordinateType(EPICOXRCoordinateType::Local),
	bEnableEyeTracking(false),
	bEnableEyeTrackingCalibration(false),
	bEnableFaceTracking(false),
	bEnableBodyTracking(false),
	bUseAdvanceInterface(false),
	bUseContentProtect(false),
	bSplashScreenAutoShow(true),
	refreshRate(ERefreshRate::Default),
	bEnableMRSafeguard(false),
	bEnableVST(false),
	bEnableAnchor(false),
	bEnableMesh(false),
	bSemanticsAlignWithTriangle(false),
	bSemanticsAlignWithVertex(false),
	MeshLod(EPICOSpatialMeshLod::High),
	FoveationRenderingMode(EFoveationRenderingMode::FixedFoveationRendering),
	FoveationLevel(EFoveationLevel::None),
	bEnableEyeTrackingFoveationRendering(false),
	bEnableSuperResolution(false),
	SharpeningSetting(EPICOXRSharpeningType::None),
	SharpeningEnhanceMode(EPICOXRSharpeningEnhanceModeType::None)
{
#if WITH_EDITOR
	ResetsRGBConfig();
#endif
	UE::ConfigUtilities::ApplyCVarSettingsFromIni(TEXT("/Script/PICOXRHMD.PICOXRSettings"), *GEngineIni, ECVF_SetByProjectSetting);
}

void UPICOXRSettings::PostInitProperties()
{
	Super::PostInitProperties();
	bUseHWsRGBEncoding = true;
}

#if WITH_EDITOR
void UPICOXRSettings::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	bUsingOSSplash = FPaths::FileExists(OSSplashScreen.FilePath) ? true : false;

	Super::PostEditChangeProperty(PropertyChangedEvent);
	Super::TryUpdateDefaultConfigFile();
	HandlesRGBHWSupport();

    FString Dst = FPaths::ProjectDir() / TEXT("pico_splash.png");
	
	if (bUsingOSSplash)
	{
		IFileManager::Get().Copy(*Dst, *OSSplashScreen.FilePath, true);
	}
	else
	{
		IFileManager::Get().Delete(*Dst, true);
	}

	static const FName HandTrackingSupportName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, HandTrackingSupport);
	if (PropertyChangedEvent.Property->GetFName() == HandTrackingSupportName)
	{
		if (HandTrackingSupport==EPICOXRHandTrackingSupport::ControllersOnly)
		{
			bAdaptiveHandModel=false;
			bHighFrequencyTracking=false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bAdaptiveHandModel)), GetDefaultConfigFilename());
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bHighFrequencyTracking)), GetDefaultConfigFilename());
		}
	}
	
	static const FName EnableVSTName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableVST);
	if (PropertyChangedEvent.Property->GetFName() == EnableVSTName)
	{
		if (!bEnableVST)
		{
			bEnableAnchor = false;
			bEnableSceneCapture=false;
			bEnableMesh=false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableAnchor)), GetDefaultConfigFilename());
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableSceneCapture)), GetDefaultConfigFilename());
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableMesh)), GetDefaultConfigFilename());
		}
	}
	
	static const FName EnableAnchorName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableAnchor);
	if (PropertyChangedEvent.Property->GetFName() == EnableAnchorName)
	{
		if (bEnableAnchor)
		{
			bEnableVST = true;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableVST)), GetDefaultConfigFilename());
		}
		else
		{
			bEnableCloudAnchor=false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableCloudAnchor)), GetDefaultConfigFilename());
		}
	}

	static const FName EnableSceneCaptureName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableSceneCapture);
	if (PropertyChangedEvent.Property->GetFName() == EnableSceneCaptureName)
	{
		if (bEnableSceneCapture)
		{
			bEnableVST = true;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableVST)), GetDefaultConfigFilename());
		}
	}

	static const FName EnableMeshName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableMesh);
	if (PropertyChangedEvent.Property->GetFName() == EnableMeshName)
	{
		if (bEnableMesh)
		{
			bEnableVST = true;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableVST)), GetDefaultConfigFilename());
		}
	}

	static const FName SuperResolutionName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableSuperResolution);
	if (PropertyChangedEvent.Property->GetFName() == SuperResolutionName)
	{
		if (bEnableSuperResolution)
		{
			SharpeningSetting = EPICOXRSharpeningType::None;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, SharpeningSetting)), GetDefaultConfigFilename());
		}
	}

	static const FName SharpeningName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, SharpeningSetting);
	if (PropertyChangedEvent.Property->GetFName() == SharpeningName)
	{
		if (SharpeningSetting!=EPICOXRSharpeningType::None)
		{
			bEnableSuperResolution = false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableSuperResolution)), GetDefaultConfigFilename());
		}
	}

	static const FName FoveationRenderingModeName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, FoveationRenderingMode);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == FoveationRenderingModeName)
	{
		if (FoveationRenderingMode == EFoveationRenderingMode::EyeTrackingFoveationRendering)
		{
			bEnableEyeTrackingFoveationRendering = true;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableEyeTrackingFoveationRendering)), GetDefaultConfigFilename());
		}
	}

	static const FName EnableEyeTrackingFoveationName = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bEnableEyeTrackingFoveationRendering);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == EnableEyeTrackingFoveationName)
	{
		if (bEnableEyeTrackingFoveationRendering == false)
		{
			FoveationRenderingMode = EFoveationRenderingMode::FixedFoveationRendering;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, FoveationRenderingMode)), GetDefaultConfigFilename());
		}
	}
	static const FName EnableSemanticsAlignWithVertex = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bSemanticsAlignWithVertex);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == EnableSemanticsAlignWithVertex)
	{
		if (bSemanticsAlignWithVertex == true)
		{
			bSemanticsAlignWithTriangle = false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bSemanticsAlignWithTriangle)), GetDefaultConfigFilename());
		}
	}

	static const FName EnableSemanticsAlignWithTriangle = GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bSemanticsAlignWithTriangle);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == EnableSemanticsAlignWithTriangle)
	{
		if (bSemanticsAlignWithTriangle == true)
		{
			bSemanticsAlignWithVertex = false;
			UpdateSinglePropertyInConfigFile(GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UPICOXRSettings, bSemanticsAlignWithVertex)), GetDefaultConfigFilename());
		}
	}
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




