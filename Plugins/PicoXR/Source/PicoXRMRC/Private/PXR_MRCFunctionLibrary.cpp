//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.


#include "PXR_MRCFunctionLibrary.h"
#include "PXR_MRCModule.h"

bool UPICOXRMRCFunctionLibrary::IsMrcActivated()
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		return FPICOXRMRCModule::Get().IsMrcActivated();
	}
	return false;
}

bool UPICOXRMRCFunctionLibrary::GetInGameThirdCameraRT(UTextureRenderTarget2D* & Background_RT, UTextureRenderTarget2D*& Forgound_RT)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		return FPICOXRMRCModule::Get().GetMRCRT(Background_RT,Forgound_RT);
	}
	return false;
}

void UPICOXRMRCFunctionLibrary::SimulateEnableMRC(bool enable)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		FPICOXRMRCModule::Get().bSimulateEnableMRC=enable;
	}
}

void UPICOXRMRCFunctionLibrary::EnableForegroundMRC(bool enable)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		FPICOXRMRCModule::Get().EnableForeground(enable);
	}
}

void UPICOXRMRCFunctionLibrary::SetMRCTrackingReference(USceneComponent* TrackingReference)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		if (FPICOXRMRCModule::Get().GetMRCState())
		{
			FPICOXRMRCModule::Get().GetMRCState()->CurrentTrackingReference = TrackingReference;
		}
	}
}

void UPICOXRMRCFunctionLibrary::SetMRCUseCustomTrans(const FTransform& CustomTrans, bool UseCutomTrans)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		if (FPICOXRMRCModule::Get().GetMRCState())
		{
			FPICOXRMRCModule::Get().GetMRCState()->bUseCustomTrans = UseCutomTrans;
			FPICOXRMRCModule::Get().GetMRCState()->CustomTrans = CustomTrans;
		}
	}
}

void UPICOXRMRCFunctionLibrary::GetMRCRelativePose(FTransform& CustomTrans)
{
	if (FPICOXRMRCModule::IsAvailable())
	{
		if (FPICOXRMRCModule::Get().GetMRCState())
		{
			CustomTrans = FPICOXRMRCModule::Get().GetMRCState()->FinalTransform;
		}
	}
}
