//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "RHI.h"
#include "RenderResource.h"
#include "ShaderParameters.h"
#include "Shader.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"

/**
* A pixel shader for rendering a textured screen element.
*/
class FPICOCubemapPS : public FGlobalShader
{
	DECLARE_EXPORTED_SHADER_TYPE(FPICOCubemapPS, Global, PICOXRHMD_API);
public:

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

	FPICOCubemapPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :
		FGlobalShader(Initializer)
	{
		InTexture.Bind(Initializer.ParameterMap, TEXT("InTextureCube"), SPF_Mandatory);
		InTextureSampler.Bind(Initializer.ParameterMap, TEXT("InTextureSampler"));
		InFaceIndexParameter.Bind(Initializer.ParameterMap, TEXT("CubeFaceIndex"));
	}
	FPICOCubemapPS() {}

	void SetParameters(FRHICommandList& RHICmdList, const FTexture* Texture, int FaceIndex)
	{
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=25
		SetTextureParameter(RHICmdList, RHICmdList.GetBoundPixelShader(), InTexture, InTextureSampler, Texture);
		SetShaderValue(RHICmdList, RHICmdList.GetBoundPixelShader(), InFaceIndexParameter, FaceIndex);
#else
		SetTextureParameter(RHICmdList, GetPixelShader(), InTexture, InTextureSampler, Texture);
		SetShaderValue(RHICmdList, GetPixelShader(), InFaceIndexParameter, FaceIndex);
#endif
	}

	void SetParameters(FRHICommandList& RHICmdList, FRHISamplerState* SamplerStateRHI, FRHITexture* TextureRHI, int FaceIndex)
	{
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=25
		SetTextureParameter(RHICmdList, RHICmdList.GetBoundPixelShader(), InTexture, InTextureSampler, SamplerStateRHI, TextureRHI);
		SetShaderValue(RHICmdList, RHICmdList.GetBoundPixelShader(), InFaceIndexParameter, FaceIndex);
#else
		SetTextureParameter(RHICmdList, GetPixelShader(), InTexture, InTextureSampler, SamplerStateRHI, TextureRHI);
		SetShaderValue(RHICmdList, GetPixelShader(), InFaceIndexParameter, FaceIndex);
#endif
	}

private:
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=25
	LAYOUT_FIELD(FShaderResourceParameter, InTexture);
	LAYOUT_FIELD(FShaderResourceParameter, InTextureSampler);
	LAYOUT_FIELD(FShaderParameter, InFaceIndexParameter);
#else
	FShaderResourceParameter InTexture;
	FShaderResourceParameter InTextureSampler;
	FShaderParameter InFaceIndexParameter;
#endif
};
