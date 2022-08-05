//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"

class FPicoXRUtils 
{
public:
	static FQuat ConvertXRQuatToUnrealQuat(FQuat InQuat);

	static FVector ConvertXRVectorToUnrealVector(FVector InVector, float Scale);

	static FQuat ConvertUnrealQuatToXRQuat(FQuat InQuat);

	static FVector ConvertUnrealVectorToXRVector(FVector InVector, float Scale);

};

inline FQuat FPicoXRUtils::ConvertXRQuatToUnrealQuat(FQuat InQuat)
{
	return FQuat(-InQuat.Z, InQuat.X, InQuat.Y, -InQuat.W);
}

inline FVector FPicoXRUtils::ConvertXRVectorToUnrealVector(FVector InVector, float Scale)
{
	return FVector(-InVector.Z * Scale, InVector.X * Scale, InVector.Y * Scale);
}

inline FQuat FPicoXRUtils::ConvertUnrealQuatToXRQuat(FQuat InQuat)
{
	return  FQuat{ InQuat.Y, InQuat.Z, -InQuat.X, -InQuat.W };
}

inline FVector FPicoXRUtils::ConvertUnrealVectorToXRVector(FVector InVector, float Scale)
{
	if (InVector.IsZero())
		return FVector{ 0.0f, 0.0f, 0.0f };

	return FVector{ InVector.Y / Scale, InVector.Z / Scale, -InVector.X / Scale };
}
