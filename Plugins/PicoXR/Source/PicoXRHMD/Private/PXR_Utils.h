// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialInterface.h"
#include "PXR_Utils.generated.h"

UCLASS()
class UPICOContentResourceFinder : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
		UMaterial* StereoLayerDepthMat;
};

class FPICOXRUtils 
{
public:
	static FQuat ConvertXRQuatToUnrealQuat(FQuat InQuat);

	static FVector ConvertXRVectorToUnrealVector(FVector InVector, float Scale);

	static FQuat ConvertUnrealQuatToXRQuat(FQuat InQuat);

	static FVector ConvertUnrealVectorToXRVector(FVector InVector, float Scale);

};

inline FQuat FPICOXRUtils::ConvertXRQuatToUnrealQuat(FQuat InQuat)
{
	return FQuat(-InQuat.Z, InQuat.X, InQuat.Y, -InQuat.W);
}

inline FVector FPICOXRUtils::ConvertXRVectorToUnrealVector(FVector InVector, float Scale)
{
	return FVector(-InVector.Z * Scale, InVector.X * Scale, InVector.Y * Scale);
}

inline FQuat FPICOXRUtils::ConvertUnrealQuatToXRQuat(FQuat InQuat)
{
	return  FQuat{ InQuat.Y, InQuat.Z, -InQuat.X, -InQuat.W };
}

inline FVector FPICOXRUtils::ConvertUnrealVectorToXRVector(FVector InVector, float Scale)
{
	if (InVector.IsZero())
		return FVector{ 0.0f, 0.0f, 0.0f };

	return FVector{ InVector.Y / Scale, InVector.Z / Scale, -InVector.X / Scale };
}

class PICOXRHMD_API FPICOXRVersionHelper
{
public:
	static bool GetRuntimeAPIVersion(int32 &InCurrentSystemVersion);
	static bool IsThisVersionOrGreater(int32 CheckingVersion);

private:
	static int32 CurrentSystemVersion;
};