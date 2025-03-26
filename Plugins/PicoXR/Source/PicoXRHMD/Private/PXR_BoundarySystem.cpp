// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_BoundarySystem.h"
#include "IXRTrackingSystem.h"
#include "PXR_Utils.h"
#include "XRThreadUtils.h"
#include "Engine/Engine.h"
#include "PXR_HMDModule.h"

UPICOXRBoundarySystem* UPICOXRBoundarySystem::BoundaryInstance = nullptr;
UPICOXRBoundarySystem* UPICOXRBoundarySystem::GetInstance()
{
	if (BoundaryInstance == nullptr)
	{
		BoundaryInstance = NewObject<UPICOXRBoundarySystem>();
		BoundaryInstance->AddToRoot();
	}
	return BoundaryInstance;
}

UPICOXRBoundarySystem::UPICOXRBoundarySystem()
	:CurrentImageSize(FIntPoint(640,640))
	,CameraTextureLeft(nullptr)
	,CameraTextureRight(nullptr)
	,LeftTextureID(-1)
	,RightTextureID(-1)
{
}

UPICOXRBoundarySystem::~UPICOXRBoundarySystem()
{
}

bool UPICOXRBoundarySystem::UPxr_GetConfigured()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = FPICOXRHMDModule::GetPluginWrapper().GetBoundaryConfigured();
	return ReturnValue;
#endif
	return  false;
}

bool UPICOXRBoundarySystem::UPxr_GetEnabled()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = FPICOXRHMDModule::GetPluginWrapper().GetBoundaryEnabled();
	return ReturnValue;
#endif
	return  false;
}

void UPICOXRBoundarySystem::UPxr_SetVisible(bool NewVisible)
{
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().SetBoundaryVisible(NewVisible);
#endif
}

bool UPICOXRBoundarySystem::UPxr_GetVisible()
{
	bool ReturnValue = false;
#if PLATFORM_ANDROID
	ReturnValue = FPICOXRHMDModule::GetPluginWrapper().GetBoundaryVisible();
#endif
	return  ReturnValue;
}

bool UPICOXRBoundarySystem::UPxr_TestNode(int DeviceType, bool bIsPlayArea, bool& IsTriggering, float& ClosestDistance,
	FVector& ClosestPoint, FVector& ClosestPointNormal)
{
#if PLATFORM_ANDROID
	bool ret = true;
	PxrBoundaryTestNode node = static_cast<PxrBoundaryTestNode>(DeviceType);
	PxrBoundaryTriggerInfo Info;

	if (!FPICOXRHMDModule::GetPluginWrapper().TestNodeIsInBoundary(node, bIsPlayArea, &Info))
	{
		IsTriggering = Info.isTriggering;
		ClosestDistance = Info.closestDistance;
		ClosestPoint = FVector(Info.closestPoint.x, Info.closestPoint.y, Info.closestPoint.z);
		ClosestPointNormal = FVector(Info.closestPointNormal.x, Info.closestPointNormal.y, Info.closestPointNormal.z);
		ret = Info.valid;

		ClosestPoint = FPICOXRUtils::ConvertXRVectorToUnrealVector(ClosestPoint, GEngine->XRSystem->GetWorldToMetersScale());
		ClosestPointNormal = FPICOXRUtils::ConvertXRVectorToUnrealVector(ClosestPointNormal, GEngine->XRSystem->GetWorldToMetersScale());
		return true;
	}
#endif
	return false;
}

bool UPICOXRBoundarySystem::UPxr_TestPoint(FVector Point, bool bIsPlayArea, bool& IsTriggering, float& ClosestDistance,
	FVector& ClosestPoint, FVector& ClosestPointNormal)
{
#if PLATFORM_ANDROID
	Point = FPICOXRUtils::ConvertUnrealVectorToXRVector(Point, GEngine->XRSystem->GetWorldToMetersScale());
	PxrBoundaryTriggerInfo Info;
	bool ret = true;
	PxrVector3f newPoint;
	newPoint.x = Point.X;
	newPoint.y = Point.Y;
	newPoint.z = Point.Z;

	if (!FPICOXRHMDModule::GetPluginWrapper().TestPointIsInBoundary(&newPoint, bIsPlayArea, &Info))
	{
		IsTriggering = Info.isTriggering;
		ClosestDistance = Info.closestDistance;
		ClosestPoint = FVector(Info.closestPoint.x, Info.closestPoint.y, Info.closestPoint.z);
		ClosestPointNormal = FVector(Info.closestPointNormal.x, Info.closestPointNormal.y, Info.closestPointNormal.z);
		ret = Info.valid;

		ClosestPoint = FPICOXRUtils::ConvertXRVectorToUnrealVector(ClosestPoint, GEngine->XRSystem->GetWorldToMetersScale());
		ClosestPointNormal = FPICOXRUtils::ConvertXRVectorToUnrealVector(ClosestPointNormal, GEngine->XRSystem->GetWorldToMetersScale());
		return true;
}
#endif
	return false;
}

TArray<FVector> UPICOXRBoundarySystem::UPxr_GetGeometry(bool bIsPlayArea)
{
	TArray<FVector> BoundaryGeometry; 
#if PLATFORM_ANDROID
	uint32_t pointsCountOutput = 0;
	PxrVector3f* outPointsFirst = nullptr;
	FPICOXRHMDModule::GetPluginWrapper().GetBoundaryGeometry(bIsPlayArea, 0, &pointsCountOutput, outPointsFirst);
	if (pointsCountOutput <= 0)
	{
		return BoundaryGeometry;
	}

	PxrVector3f* Data = new PxrVector3f[pointsCountOutput];
	if (FPICOXRHMDModule::GetPluginWrapper().GetBoundaryGeometry(bIsPlayArea, pointsCountOutput, &pointsCountOutput, Data) == 0)
	{
		for (uint32_t i = 0; i < pointsCountOutput; i++)
		{
			FVector TempVector = FVector(Data[i].x, Data[i].y, Data[i].z);
			TempVector = FPICOXRUtils::ConvertXRVectorToUnrealVector(TempVector, GEngine->XRSystem->GetWorldToMetersScale());
			BoundaryGeometry.Add(TempVector);
		}
	}
	delete[]Data;
#endif
	return BoundaryGeometry;
}

FVector UPICOXRBoundarySystem::UPxr_GetDimensions(bool bIsPlayArea)
{
	FVector Dimensions = FVector::ZeroVector;
#if PLATFORM_ANDROID
	PxrVector3f NewDimensions;
	FPICOXRHMDModule::GetPluginWrapper().GetBoundaryDimensions(bIsPlayArea, &NewDimensions);
	Dimensions.X = NewDimensions.x;
	Dimensions.Y = NewDimensions.y;
	Dimensions.Z = NewDimensions.z;
	Dimensions = FPICOXRUtils::ConvertXRVectorToUnrealVector(Dimensions, GEngine->XRSystem->GetWorldToMetersScale());
#endif
	return Dimensions;
}

int UPICOXRBoundarySystem::UPxr_SetSeeThroughBackground(bool Value)
{
#if PLATFORM_ANDROID
	return FPICOXRHMDModule::GetPluginWrapper().SetSeeThroughBackground(Value);
#endif
	return 0;
}

