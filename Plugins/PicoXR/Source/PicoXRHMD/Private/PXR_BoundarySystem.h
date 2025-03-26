// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "UObject/Object.h"
#include "PXR_BoundarySystem.generated.h"

UCLASS()
class UPICOXRBoundarySystem : public UObject
{
	GENERATED_BODY()
public:
	static UPICOXRBoundarySystem* GetInstance();

	static UPICOXRBoundarySystem* BoundaryInstance;

	UPICOXRBoundarySystem();

	~UPICOXRBoundarySystem();

	bool UPxr_GetConfigured();

	bool UPxr_GetEnabled();
	
	void UPxr_SetVisible(bool NewVisible);

	bool UPxr_GetVisible();

	bool UPxr_TestNode(int DeviceType, bool BoundaryType, bool &IsTriggering, float &ClosestDistance, FVector &ClosestPoint, FVector &ClosestPointNormal);

	bool UPxr_TestPoint(FVector Point, bool BoundaryType, bool &IsTriggering, float &ClosestDistance, FVector &ClosestPoint, FVector &ClosestPointNormal);

	TArray<FVector> UPxr_GetGeometry(bool BoundaryType);

	FVector UPxr_GetDimensions(bool BoundaryType);

	int UPxr_SetSeeThroughBackground(bool value);

private:
	FIntPoint CurrentImageSize;
	UTexture2D* CameraTextureLeft;
	UTexture2D* CameraTextureRight;
	int32_t LeftTextureID;
	int32_t RightTextureID;
};
