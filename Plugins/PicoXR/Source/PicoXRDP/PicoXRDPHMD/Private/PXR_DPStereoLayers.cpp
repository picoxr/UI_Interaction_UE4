//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#include "PXR_DPStereoLayers.h"
#include "CoreMinimal.h"
#include "PXR_DPPrivate.h"
#include "StereoLayerManager.h"
#include "PXR_DPHMD.h"
#include "Misc/ScopeLock.h"
#include "DefaultXRCamera.h"
#include "PXR_Log.h"


#if STEAMVR_SUPPORTED_PLATFORMS

//=============================================================================
void SetLayerDescMember(FPicoDPLayer& Layer, const IStereoLayers::FLayerDesc& InLayerDesc)
{
	PXR_LOGD(PxrUnreal,"PXR_DP SetLayerDescMember Layer ID:%d",InLayerDesc.Id);
	if (InLayerDesc.Texture != Layer.LayerDesc.Texture)
	{
		Layer.bUpdateTexture = true;
	}
	Layer.LayerDesc = InLayerDesc;
}

//=============================================================================
bool GetLayerDescMember(const FPicoDPLayer& Layer, IStereoLayers::FLayerDesc& OutLayerDesc)
{
	PXR_LOGD(PxrUnreal,"PXR_DP GetLayerDescMember Layer ID:%d",Layer.GetLayerId());
	OutLayerDesc = Layer.LayerDesc;
	return true;
}

//=============================================================================
void MarkLayerTextureForUpdate(FPicoDPLayer& Layer)
{
	PXR_LOGD(PxrUnreal,"PXR_DP MarkLayerTextureForUpdate Layer ID:%d", Layer.GetLayerId());
	Layer.bUpdateTexture = true;
}



//=============================================================================


#endif //STEAMVR_SUPPORTED_PLATFORMS
