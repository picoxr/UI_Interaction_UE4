// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_Utils.h"

#include "PXR_HMDModule.h"
#include "PXR_Plugin_Types.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

UPICOContentResourceFinder::UPICOContentResourceFinder(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UMaterial> StaticUnderlayMaterial(TEXT("Material'/PICOXR/Materials/UnderlayMaterial.UnderlayMaterial'"));
	StereoLayerDepthMat = StaticUnderlayMaterial.Object;
}


int32 FPICOXRVersionHelper::CurrentSystemVersion = 0;

bool FPICOXRVersionHelper::GetRuntimeAPIVersion(int32& InCurrentSystemVersion)
{
#if PLATFORM_ANDROID
	if (CurrentSystemVersion)
	{
		InCurrentSystemVersion = CurrentSystemVersion;
		return true;
	}
	else
	{
		const bool bResult =FPICOXRHMDModule::GetPluginWrapper().GetConfigInt(PXR_API_VERSION, &CurrentSystemVersion) ? false : true;
		InCurrentSystemVersion=CurrentSystemVersion;
		return bResult;
	}
#endif
	return false;
}

bool FPICOXRVersionHelper::IsThisVersionOrGreater(int32 CheckingVersion)
{
	if (CurrentSystemVersion)
	{
		return CurrentSystemVersion >= CheckingVersion;
	}
	else
	{
		int32 TempSystemVersion=0;
		if(GetRuntimeAPIVersion(TempSystemVersion))
		{
			return TempSystemVersion >= CheckingVersion;
		}
		return false;
	}
}
