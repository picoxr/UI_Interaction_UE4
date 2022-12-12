//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_BoundarySystem.h"
#include "IXRTrackingSystem.h"
#include "PXR_Utils.h"
#include "XRThreadUtils.h"
#include "Engine/Engine.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "XRTrackingSystemBase.h"
#include "XRThreadUtils.h"
#include "PxrTypes.h"
#endif

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
	:bIsStartCamera(false)
	,CurrentImageSize(FIntPoint(640,640))
	,CameraTextureLeft(nullptr)
	,CameraTextureRight(nullptr)
	,LeftTextureID(-1)
	,RightTextureID(-1)
{
}

UPICOXRBoundarySystem::~UPICOXRBoundarySystem()
{
#if PLATFORM_ANDROID
	if (bIsStartCamera)
	{
		Pxr_StartCameraPreview(0);
	}
#endif
}

bool UPICOXRBoundarySystem::UPxr_GetConfigured()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryConfigured();
	return ReturnValue;
#endif
	return  false;
}

bool UPICOXRBoundarySystem::UPxr_GetEnabled()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryEnabled();
	return ReturnValue;
#endif
	return  false;
}

void UPICOXRBoundarySystem::UPxr_SetVisible(bool NewVisible)
{
#if PLATFORM_ANDROID
	Pxr_SetBoundaryVisible(NewVisible);
#endif
}

bool UPICOXRBoundarySystem::UPxr_GetVisible()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryVisible();
	return ReturnValue;
#endif
	return  false;
}

bool UPICOXRBoundarySystem::UPxr_TestNode(int DeviceType, bool bIsPlayArea, bool& IsTriggering, float& ClosestDistance,
	FVector& ClosestPoint, FVector& ClosestPointNormal)
{
#if PLATFORM_ANDROID
	bool ret = true;
	PxrBoundaryTestNode node = static_cast<PxrBoundaryTestNode>(DeviceType);
	PxrBoundaryTriggerInfo Info;

	if (!Pxr_TestNodeIsInBoundary(node, bIsPlayArea, &Info))
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

	if (!Pxr_TestPointIsInBoundary(&newPoint, bIsPlayArea, &Info))
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
	uint32_t pointsCountOutput = -1;
	PxrVector3f * outPointsFirst = nullptr;
	if (Pxr_GetBoundaryGeometry(bIsPlayArea,0,&pointsCountOutput,outPointsFirst) == 0)
	{
		if (pointsCountOutput <= 0)
		{
			return BoundaryGeometry;
		}

		PxrVector3f * Data = new PxrVector3f[pointsCountOutput];
		if (Pxr_GetBoundaryGeometry(bIsPlayArea, pointsCountOutput, &pointsCountOutput, Data) == 0)
		{
			for (uint32_t i = 0; i < pointsCountOutput; i++)
			{
				FVector TempVector = FVector(Data[i].x,Data[i].y,Data[i].z);
				TempVector = FPICOXRUtils::ConvertXRVectorToUnrealVector(TempVector, GEngine->XRSystem->GetWorldToMetersScale());
				BoundaryGeometry.Add(TempVector);
			}
		}
		delete[]Data;
	}	
#endif
	return BoundaryGeometry;
}

FVector UPICOXRBoundarySystem::UPxr_GetDimensions(bool bIsPlayArea)
{
	FVector Dimensions = FVector::ZeroVector;
#if PLATFORM_ANDROID
	PxrVector3f NewDimensions;
	Pxr_GetBoundaryDimensions(bIsPlayArea, &NewDimensions);
	Dimensions.X = NewDimensions.x;
	Dimensions.Y = NewDimensions.y;
	Dimensions.Z = NewDimensions.z;
	Dimensions = FPICOXRUtils::ConvertXRVectorToUnrealVector(Dimensions, GEngine->XRSystem->GetWorldToMetersScale());
#endif
	return Dimensions;
}

bool UPICOXRBoundarySystem::UPxr_GetSeeThroughData(int CameraType, UTexture2D*& CameraImage)
{
#if PLATFORM_ANDROID
	if(bIsStartCamera == false)
	{
		ExecuteOnRenderThread([]()
        {         
          ExecuteOnRHIThread([]()
          {
          Pxr_StartCameraPreview(1);
          });
        });
		FPlatformProcess::Sleep(0.1);
		bIsStartCamera = true;
	}
	if (CameraType == 0)
	{
		if (CameraTextureLeft == nullptr)
		{
			CameraTextureLeft = UTexture2D::CreateTransient(CurrentImageSize.X,CurrentImageSize.Y, EPixelFormat::PF_R8G8B8A8);
			check(CameraTextureLeft);
#if ENGINE_MINOR_VERSION > 25
			FTextureResource* Resource = CameraTextureLeft->CreateResource();
#else	
			FTexture2DResource* Resource = static_cast<FTexture2DResource *>(CameraTextureLeft->CreateResource());
#endif
			CameraTextureLeft->UpdateResource();
			ExecuteOnRenderThread([Resource,this]()
	        {
	            Resource->InitRHI();
	            ExecuteOnRHIThread([Resource,this]()
	            {
#if ENGINE_MINOR_VERSION > 25
						LeftTextureID = (*static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource())) - 1;
#else
						LeftTextureID = *static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource());
#endif
	            });
	        });
			delete Resource;
			Resource = nullptr;
		}
		else
		{
			if ((CameraTextureLeft->GetSizeY() != CurrentImageSize.Y)|| (CameraTextureLeft->GetSizeX() != CurrentImageSize.X))
			{
				CameraTextureLeft->ReleaseResource();
				CameraTextureLeft = UTexture2D::CreateTransient(CurrentImageSize.X,CurrentImageSize.Y, EPixelFormat::PF_R8G8B8A8);
				check(CameraTextureLeft);
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = CameraTextureLeft->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource *>(CameraTextureLeft->CreateResource());
#endif
				CameraTextureLeft->UpdateResource();
				ExecuteOnRenderThread([Resource,this]()
                {
                    Resource->InitRHI();
                    ExecuteOnRHIThread([Resource,this]()
                    {
#if ENGINE_MINOR_VERSION > 25
							LeftTextureID = (*static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource())) - 1;
#else
							LeftTextureID = *static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource());
#endif
                    });
                });
				delete Resource;
				Resource = nullptr;
			}
		}
		ExecuteOnRenderThread([this]()
        {
            ExecuteOnRHIThread([this]()
            {
	           uint32_t exposure = 0;
	           int64_t start_of_exposure_ts = 0;
			   bool ret = true;
	           uint32_t SizeX =	CameraTextureLeft->GetSizeX();
	           uint32_t SizeY =	CameraTextureLeft->GetSizeY();
			   PxrSeeThoughData seeThoughData;
			   seeThoughData.leftEyeTextureId = LeftTextureID;
			   seeThoughData.rightEyeTextureId = 0;
			   seeThoughData.width = SizeX;
			   seeThoughData.height = SizeY;
			   seeThoughData.exposure = exposure;
			   seeThoughData.startTimeOfExposure = start_of_exposure_ts;
			   seeThoughData.valid = ret;
			   int result = Pxr_GetSeeThroughData(&seeThoughData);
            });
        });
		CameraImage = CameraTextureLeft;
		return true;
	}else
	{
		if (CameraTextureRight == nullptr)
		{
			CameraTextureRight = UTexture2D::CreateTransient(CurrentImageSize.X,CurrentImageSize.Y, EPixelFormat::PF_R8G8B8A8);
			check(CameraTextureRight);
#if ENGINE_MINOR_VERSION > 25
			FTextureResource* Resource = CameraTextureRight->CreateResource();
#else	
			FTexture2DResource* Resource = static_cast<FTexture2DResource *>(CameraTextureRight->CreateResource());
#endif
			CameraTextureRight->UpdateResource();
			ExecuteOnRenderThread([Resource,this]()
	        {
	            Resource->InitRHI();
	            ExecuteOnRHIThread([Resource,this]()
	            {
#if ENGINE_MINOR_VERSION > 25
						RightTextureID = (*static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource())) - 1;
#else
						RightTextureID = *static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource());
#endif
	            });
	        });
			delete Resource;
			Resource = nullptr;
		}
		else
		{
			if ((CameraTextureRight->GetSizeY() != CurrentImageSize.Y)|| (CameraTextureRight->GetSizeX() != CurrentImageSize.X))
			{
				CameraTextureRight->ReleaseResource();
				CameraTextureRight = UTexture2D::CreateTransient(CurrentImageSize.X,CurrentImageSize.Y, EPixelFormat::PF_R8G8B8A8);
				check(CameraTextureRight);
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = CameraTextureRight->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource *>(CameraTextureRight->CreateResource());
#endif
				CameraTextureRight->UpdateResource();
				ExecuteOnRenderThread([Resource,this]()
                {
                    Resource->InitRHI();
                    ExecuteOnRHIThread([Resource,this]()
                    {
#if ENGINE_MINOR_VERSION > 25
							RightTextureID = (*static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource())) - 1;
#else
							RightTextureID = *static_cast<int32_t*>(Resource->GetTexture2DRHI()->GetNativeResource());
#endif
                    });
                });
				delete Resource;
				Resource = nullptr;
			}
		}
		ExecuteOnRenderThread([this]()
        {
            ExecuteOnRHIThread([this]()
            {
			   uint32_t exposure = 0;
			   int64_t start_of_exposure_ts = 0;
			   bool ret = true;
			   uint32_t SizeX = CameraTextureLeft->GetSizeX();
			   uint32_t SizeY = CameraTextureLeft->GetSizeY();
			   PxrSeeThoughData seeThoughData;
			   seeThoughData.leftEyeTextureId = 0;
			   seeThoughData.rightEyeTextureId = RightTextureID;
			   seeThoughData.width = SizeX;
			   seeThoughData.height = SizeY;
			   seeThoughData.exposure = exposure;
			   seeThoughData.startTimeOfExposure = start_of_exposure_ts;
			   seeThoughData.valid = ret;
			   int result = Pxr_GetSeeThroughData(&seeThoughData);
            });
        });
		CameraImage = CameraTextureRight;
		return true;
	}

#endif
	return  false;
}

bool UPICOXRBoundarySystem::UPxr_SetCameraImageSize(FIntPoint ImageSize)
{
#if PLATFORM_ANDROID
	uint32_t width = (uint32_t)ImageSize.X;
	uint32_t height = (uint32_t)ImageSize.Y;
	Pxr_SetSeeThroughImageExtent(width,height);
	CurrentImageSize = ImageSize;
	return true;
#endif
	return false;
}

int UPICOXRBoundarySystem::UPxr_SetSeeThroughBackground(bool Value)
{
#if PLATFORM_ANDROID
	return Pxr_SetSeeThroughBackground(Value);
#endif
	return 0;
}

