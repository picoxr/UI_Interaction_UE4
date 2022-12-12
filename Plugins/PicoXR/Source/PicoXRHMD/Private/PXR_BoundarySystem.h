//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

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

	bool UPxr_GetSeeThroughData(int CameraType,UTexture2D* &CameraImage);

	bool UPxr_SetCameraImageSize(FIntPoint ImageSize);

	int UPxr_SetSeeThroughBackground(bool value);

private:
	bool bIsStartCamera;
	FIntPoint CurrentImageSize;
	UTexture2D* CameraTextureLeft;
	UTexture2D* CameraTextureRight;
	int32_t LeftTextureID;
	int32_t RightTextureID;
};
