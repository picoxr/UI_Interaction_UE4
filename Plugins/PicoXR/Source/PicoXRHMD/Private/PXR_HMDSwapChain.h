//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "XRSwapChain.h"

class FPICOXRHMD;

class FPICOXRSwapChain : public FXRSwapChain
{
public:
	FPICOXRSwapChain(TArray<FTextureRHIRef>&& InRHITextureSwapChain, const FTextureRHIRef & InRHITexture,FPICOXRHMD* InXRHMD);
	virtual ~FPICOXRSwapChain() {}
protected:
	FPICOXRHMD* PICOXRHMD;
};

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_OpenGL(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPICOXRHMD* InXRHMD, uint32 MSAAValue);
#else
FXRSwapChainPtr CreateSwapChain_OpenGL(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPICOXRHMD* InHMD, uint32 MASSValue);
#endif

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_Vulkan(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPICOXRHMD* InXRHMD, uint32 MSAAValue);
#else
FXRSwapChainPtr CreateSwapChain_Vulkan(uint32 LayerID, TArray<uint64>& NativeTextures, uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPICOXRHMD* InHMD, uint32 MASSValue);
#endif