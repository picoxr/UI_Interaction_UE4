// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "IStereoLayers.h"
#include "Engine/Engine.h"
#include "OpenGLDrvPrivate.h"
#include "OpenGLResources.h"

class FPicoVRStereoLayer : public TSharedFromThis<FPicoVRStereoLayer, ESPMode::ThreadSafe>
{
public:
	FPicoVRStereoLayer(uint32 InId, const IStereoLayers::FLayerDesc& InDesc);
	~FPicoVRStereoLayer();

	TSharedPtr<FPicoVRStereoLayer, ESPMode::ThreadSafe> Clone() const;

	uint32 GetId() const { return Id; }
	void SetDesc(const IStereoLayers::FLayerDesc& InDesc);
	const IStereoLayers::FLayerDesc& GetDesc() const { return Desc; }

	GLuint GetRTexID() { return *(GLuint*)Desc.Texture->GetTexture2D()->GetNativeResource(); };
	GLuint GetLTexID() { return Desc.LeftTexture == nullptr ? *(GLuint*)Desc.Texture->GetTexture2D()->GetNativeResource() : *(GLuint*)Desc.LeftTexture->GetTexture2D()->GetNativeResource(); };
	FMatrix GetLayerMV(FQuat CamOri, FVector CamPos, bool& fixedOverLay );
	FVector GetLayerLocation() { return Desc.Transform.GetLocation(); };
	FQuat GetLayerOrientation() { return Desc.Transform.GetRotation(); };
	FVector GetLayerScale() { return Desc.Transform.GetScale3D(); };

protected:
	uint32 Id;
	IStereoLayers::FLayerDesc Desc;
};

typedef TSharedPtr<FPicoVRStereoLayer, ESPMode::ThreadSafe> FPicoVRStereoLayerPtr;
