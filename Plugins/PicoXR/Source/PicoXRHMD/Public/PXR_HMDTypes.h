//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "RHIResources.h"
#include "Engine/Texture2D.h"
#include "UObject/SoftObjectPath.h"
#include "PXR_HMDTypes.generated.h"

USTRUCT()
struct FPXRSplashDesc
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "Texture",ToolTip = "Splash texture to show"))
	FSoftObjectPath		SplashTexturePath;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "The center transform"))
	FTransform			SplashTransform;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "The splash layer quad size"))
	FVector2D			SplashQuadSize;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Splash texture offset relative to the upper left corner"))
	FVector2D			SplashTextureOffset;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Splash texture scale (default=1.0f)"))
	FVector2D			SplashTextureScale;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Ignore the splash texture alpha channel"))
	bool				bNoAlpha;

	UTexture*			LoadingTextureFromPath;
	FTextureRHIRef		LoadedTextureRef;
	bool				bIsLiveUpdate;

	FPXRSplashDesc()
		: SplashTransform(FVector(150.0f, 0.f, 100.f))
		, SplashQuadSize(100.0f, 100.0f)
		, SplashTextureOffset(0.0f, 0.0f)
		, SplashTextureScale(1.0f, 1.0f)
		, bNoAlpha(true)
		, LoadingTextureFromPath(nullptr)
		, LoadedTextureRef(nullptr)
		, bIsLiveUpdate(false)
	{
	}
};

UENUM(BlueprintType)
enum class EPICOXRFaceTrackingMode : uint8
{
	Disable,
	FaceOnly,
	LipsOnly,
	FaceAndLips,
};