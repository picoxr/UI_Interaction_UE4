//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "RHIResources.h"
#include "Engine/Texture2D.h"
#include "UObject/SoftObjectPath.h"
#include "PXR_HMDTypes.generated.h"

USTRUCT(BlueprintType)
struct FPicoSplashDesc
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "Texture",ToolTip = "Texture show"))
	FSoftObjectPath		TexturePath;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Transform the center (meters)."))
	FTransform			TransformInMeters;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "The meter is the basic unit."))
	FVector2D			QuadSizeInMeters;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Add a rotation increment for each render frame."))
	FQuat				DeltaRotation;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "The upper left corner is the starting point of the texture offset."))
	FVector2D			TextureOffset;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Texture scale (the default size is recommended)."))
	FVector2D			TextureScale;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Whether to use alpha channel."))
	bool				bNoAlphaChannel;

	UTexture*			LoadingTexture;
	FTextureRHIRef		LoadedTexture;
	bool				bIsDynamic;

	FPicoSplashDesc()
		: TransformInMeters(FVector(4.0f, 0.f, 0.f))
		, QuadSizeInMeters(3.f, 3.f)
		, DeltaRotation(FQuat::Identity)
		, TextureOffset(0.0f, 0.0f)
		, TextureScale(1.0f, 1.0f)
		, bNoAlphaChannel(false)
		, LoadingTexture(nullptr)
		, LoadedTexture(nullptr)
		, bIsDynamic(false)
	{
	}

	bool operator==(const FPicoSplashDesc& d) const
	{
		return 
			TexturePath == d.TexturePath &&
			TransformInMeters.Equals(d.TransformInMeters) &&
			QuadSizeInMeters == d.QuadSizeInMeters &&
			DeltaRotation.Equals(d.DeltaRotation) &&
			TextureOffset == d.TextureOffset && TextureScale == d.TextureScale &&
			bNoAlphaChannel == d.bNoAlphaChannel &&
			LoadingTexture == d.LoadingTexture && LoadedTexture == d.LoadedTexture && bIsDynamic == d.bIsDynamic;
	}
};