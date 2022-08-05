//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "XRSwapChain.h"

class FPicoXRHMD;

class FPicoXRSwapChain : public FXRSwapChain
{
public:
	FPicoXRSwapChain(TArray<FTextureRHIRef>&& InRHITextureSwapChain, const FTextureRHIRef & InRHITexture,FPicoXRHMD* InXRHMD);
	virtual ~FPicoXRSwapChain() {}
protected:
	FPicoXRHMD* PicoXRHMD;
};

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_OpenGL(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPicoXRHMD* InXRHMD, uint32 MSAAValue);
#else
FXRSwapChainPtr CreateSwapChain_OpenGL(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPicoXRHMD* InHMD, uint32 MASSValue);
#endif

#if ENGINE_MINOR_VERSION>25
FXRSwapChainPtr CreateSwapChain_Vulkan(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, FPicoXRHMD* InXRHMD, uint32 MSAAValue);
#else
FXRSwapChainPtr CreateSwapChain_Vulkan(uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, FPicoXRHMD* InHMD, uint32 MASSValue);
#endif