// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.
#include "IOpenGLDynamicRHI.h"
#include "PXR_HMDRenderBridge.h"
#include "PXR_HMD.h"

class FPICOXRRenderBridge_OpenGL : public FPICOXRRenderBridge
{
public:
	FPICOXRRenderBridge_OpenGL(FPICOXRHMD* HMD) : FPICOXRRenderBridge(HMD)
	{
		RHIString = HMD->GetRHIString();
	}

	virtual FTextureRHIRef CreateTexture_RenderThread(ERHIResourceType RHIResourceType, uint64 InTexture, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue) override
	{
		IOpenGLDynamicRHI* DynamicRHI = static_cast<IOpenGLDynamicRHI*>(GDynamicRHI);
		switch (RHIResourceType)
		{
		case RRT_Texture2D:
			return DynamicRHI->RHICreateTexture2DFromResource((EPixelFormat)Format, SizeX, SizeY, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (GLuint)InTexture, TargetableTextureFlags).GetReference();

		case RRT_Texture2DArray:
			return DynamicRHI->RHICreateTexture2DArrayFromResource((EPixelFormat)Format, SizeX, SizeY, 2, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (GLuint)InTexture, TargetableTextureFlags).GetReference();

		case RRT_TextureCube:
			return DynamicRHI->RHICreateTextureCubeFromResource((EPixelFormat)Format, SizeX, false, 1, NumMips, NumSamples, MSAAValue, FClearValueBinding::Black, (GLuint)InTexture, TargetableTextureFlags).GetReference();

		default:
			return nullptr;
		}
	}
};

FPICOXRRenderBridge* CreateRenderBridge_OpenGL(FPICOXRHMD* HMD)
{
	return new FPICOXRRenderBridge_OpenGL(HMD);
}
