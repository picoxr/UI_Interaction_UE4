//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.


#include "PXR_MRCFunctionLibrary.h"
#include "PXR_MRCModule.h"

bool UPicoXRMRCFunctionLibrary::IsMrcEnabled()
{
	if (FPicoXRMRCModule::IsAvailable())
	{
		return FPicoXRMRCModule::Get().IsMrcEnabled();
	}
	return false;
}

bool UPicoXRMRCFunctionLibrary::GetInGameThirdCameraRT(UTextureRenderTarget2D* & Background_RT, UTextureRenderTarget2D*& Forgound_RT)
{
	if (FPicoXRMRCModule::IsAvailable())
	{
		return FPicoXRMRCModule::Get().GetMRCRT(Background_RT,Forgound_RT);
	}
	return false;
}

void UPicoXRMRCFunctionLibrary::SimulateEnableMRC(bool enable)
{
	if (FPicoXRMRCModule::IsAvailable())
	{
		FPicoXRMRCModule::Get().bSimulateEnableMRC=enable;
	}
}