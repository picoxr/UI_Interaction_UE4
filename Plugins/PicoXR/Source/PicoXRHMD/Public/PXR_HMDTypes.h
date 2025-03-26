// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "RHI.h"
#include "RHIResources.h"
#include "Engine/Texture2D.h"
#include "UObject/SoftObjectPath.h"
#include "PXR_HMDTypes.generated.h"

USTRUCT()
struct FPXRSplashDesc
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (
		AllowedClasses = "/Script/Engine.Texture",
		ToolTip = "Splash texture to show"))
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
enum class EPICOXRCoordinateType  : uint8
{
	Local = 0 UMETA(DisplayName = "Local Coordinate"),
	Global_BoundarySystem =1 UMETA(DisplayName = "BoundarySystem Coordinate"),
};

UENUM(BlueprintType)
enum class EPxrBodyActionList : uint8
{
	NoneAction  = 0,
	TouchGround = 1,
	KeepStatic  = 2,
	TouchGroundAndKeepStatic=3,
	TouchGroundToe=4,
	FootDownAction=5
};

UENUM(BlueprintType)
enum class EPICOMRState:uint8
{
	Initialized = 0,
	Running = 1,
	Stopped = 2,
};

UENUM(BlueprintType)
enum class EPICOVSTDisplayStatus:uint8
{
	Display_Disabled = 0 ,
	Display_Enabling,
	Display_Enabled,
	Display_Disabling
};

USTRUCT(BlueprintType)
struct FPXREventDataMotionTrackerKey
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	FString TrackerSN;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 Code;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 Repeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	bool  bShortPress;
	
	FPXREventDataMotionTrackerKey(): Code(0), Action(0), Repeat(0), bShortPress(false)
	{
		TrackerSN = FString();
	}
};

USTRUCT(BlueprintType)
struct FPXREventDataExtDevConnectEvent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	FString TrackerSN;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 state;
	
	FPXREventDataExtDevConnectEvent(): state(0)
	{
		TrackerSN = FString();
	}
};

USTRUCT(BlueprintType)
struct FPXREventDataExtDevBatteryEvent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	FString TrackerSN;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 battery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	int32 charger;
	
	FPXREventDataExtDevBatteryEvent(): battery(0),charger(0)
	{
		TrackerSN = FString();
	}
};