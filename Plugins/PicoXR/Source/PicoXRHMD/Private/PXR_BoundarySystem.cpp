// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

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

UPicoXRBoundarySystem* UPicoXRBoundarySystem::BoundaryInstance = nullptr;
UPicoXRBoundarySystem* UPicoXRBoundarySystem::GetInstance()
{
	if (BoundaryInstance == nullptr)
	{
		BoundaryInstance = NewObject<UPicoXRBoundarySystem>();
		BoundaryInstance->AddToRoot();
	}
	return BoundaryInstance;
}

UPicoXRBoundarySystem::UPicoXRBoundarySystem()
	:bIsStartCamera(false)
	,CurrentImageSize(FIntPoint(640,640))
	,CameraTextureLeft(nullptr)
	,CameraTextureRight(nullptr)
	,LeftTextureID(-1)
	,RightTextureID(-1)
{
}

UPicoXRBoundarySystem::~UPicoXRBoundarySystem()
{
#if PLATFORM_ANDROID
	if (bIsStartCamera)
	{
		Pxr_StartCameraPreview(0);
	}
#endif
}

bool UPicoXRBoundarySystem::UPxr_GetConfigured()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryConfigured();
	return ReturnValue;
#endif
	return  false;
}

bool UPicoXRBoundarySystem::UPxr_GetEnabled()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryEnabled();
	return ReturnValue;
#endif
	return  false;
}

void UPicoXRBoundarySystem::UPxr_SetVisible(bool NewVisible)
{
#if PLATFORM_ANDROID
	Pxr_SetBoundaryVisible(NewVisible);
#endif
}

bool UPicoXRBoundarySystem::UPxr_GetVisible()
{
#if PLATFORM_ANDROID
	bool ReturnValue = false;
	ReturnValue = Pxr_GetBoundaryVisible();
	return ReturnValue;
#endif
	return  false;
}

bool UPicoXRBoundarySystem::UPxr_TestNode(int DeviceType, bool bIsPlayArea, bool& IsTriggering, float& ClosestDistance,
	FVector& ClosestPoint, FVector& ClosestPointNormal)
{
#if PLATFORM_ANDROID
	PxrBoundaryTestNode node;
	if (DeviceType == 0) {
		node = PxrBoundaryTestNode::PXR_BOUNDARY_TEST_NODE_HEAD;
	}
	else if (DeviceType == 1)
	{
		node = PxrBoundaryTestNode::PXR_BOUNDARY_TEST_NODE_LEFT_HAND;
	}
	else if (DeviceType == 2)
	{
		node = PxrBoundaryTestNode::PXR_BOUNDARY_TEST_NODE_RIGHT_HAND;
	}
	else
	{
		node = PxrBoundaryTestNode::PXR_BOUNDARY_TEST_NODE_HEAD;
	}
	PxrBoundaryTriggerInfo Info;
	Info.isTriggering = IsTriggering;
	Info.closestDistance = ClosestDistance;
	PxrVector3f CPoint;
	CPoint.x = ClosestPoint.X;
	CPoint.y = ClosestPoint.Y;
	CPoint.z = ClosestPoint.Z;
	PxrVector3f CPointNormal;
	CPointNormal.x = ClosestPointNormal.X;
	CPointNormal.y = ClosestPointNormal.Y;
	CPointNormal.z = ClosestPointNormal.Z;
	Info.closestPoint = CPoint;
	Info.closestPointNormal = CPointNormal;
	bool ret = true;
	Info.valid = ret;

	Pxr_TestNodeIsInBoundary(node, bIsPlayArea, &Info);
	ClosestPoint = FPicoXRUtils::ConvertXRVectorToUnrealVector(ClosestPoint, GEngine->XRSystem->GetWorldToMetersScale());
	ClosestPointNormal = FPicoXRUtils::ConvertXRVectorToUnrealVector(ClosestPointNormal, GEngine->XRSystem->GetWorldToMetersScale());
	return true;
#endif
	return false;
}

bool UPicoXRBoundarySystem::UPxr_TestPoint(FVector Point, bool bIsPlayArea, bool& IsTriggering, float& ClosestDistance,
	FVector& ClosestPoint, FVector& ClosestPointNormal)
{
#if PLATFORM_ANDROID
	Point = FPicoXRUtils::ConvertUnrealVectorToXRVector(Point,GEngine->XRSystem->GetWorldToMetersScale());

	PxrVector3f newPoint;
	newPoint.x = Point.X;
	newPoint.y = Point.Y;
	newPoint.z = Point.Z;
	PxrBoundaryTriggerInfo Info;
	Info.isTriggering = IsTriggering;
	Info.closestDistance = ClosestDistance;
	PxrVector3f CPoint;
	CPoint.x = ClosestPoint.X;
	CPoint.y = ClosestPoint.Y;
	CPoint.z = ClosestPoint.Z;
	PxrVector3f CPointNormal;
	CPointNormal.x = ClosestPointNormal.X;
	CPointNormal.y = ClosestPointNormal.Y;
	CPointNormal.z = ClosestPointNormal.Z;
	Info.closestPoint = CPoint;
	Info.closestPointNormal = CPointNormal;
	bool ret = false;
	Info.valid = ret;
	Pxr_TestPointIsInBoundary(&newPoint, bIsPlayArea, &Info);
	ClosestPoint = FPicoXRUtils::ConvertXRVectorToUnrealVector(ClosestPoint, GEngine->XRSystem->GetWorldToMetersScale());
	ClosestPointNormal = FPicoXRUtils::ConvertXRVectorToUnrealVector(ClosestPointNormal, GEngine->XRSystem->GetWorldToMetersScale());
	return true;
#endif
	return false;
}

TArray<FVector> UPicoXRBoundarySystem::UPxr_GetGeometry(bool bIsPlayArea)
{
	TArray<FVector> BoundaryGeometry; 
#if PLATFORM_ANDROID
	uint32_t ret = -1;
	float * Data = nullptr;
	if (Pxr_GetBoundaryGeometry2(bIsPlayArea, &Data, &ret) == 0)
	{
		for (uint32_t i = 0; i < ret; i++)
		{
			FVector TempVector = FVector(Data[i * 3], Data[i * 3 + 1], Data[i * 3 + 2]);
			TempVector = FPicoXRUtils::ConvertXRVectorToUnrealVector(TempVector, GEngine->XRSystem->GetWorldToMetersScale());
			BoundaryGeometry.Add(TempVector);
		}
	}	
#endif
	return BoundaryGeometry;
}

FVector UPicoXRBoundarySystem::UPxr_GetDimensions(bool bIsPlayArea)
{
	FVector Dimensions = FVector::ZeroVector;
#if PLATFORM_ANDROID
	PxrVector3f NewDimensions;
	Pxr_GetBoundaryDimensions(bIsPlayArea, &NewDimensions);
	Dimensions.X = NewDimensions.x;
	Dimensions.Y = NewDimensions.y;
	Dimensions.Z = NewDimensions.z;
	Dimensions = FPicoXRUtils::ConvertXRVectorToUnrealVector(Dimensions, GEngine->XRSystem->GetWorldToMetersScale());
#endif
	return Dimensions;
}

bool UPicoXRBoundarySystem::UPxr_GetSeeThroughData(int CameraType, UTexture2D*& CameraImage)
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

bool UPicoXRBoundarySystem::UPxr_SetCameraImageSize(FIntPoint ImageSize)
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

int UPicoXRBoundarySystem::UPxr_SetSeeThroughBackground(bool Value)
{
#if PLATFORM_ANDROID
	return Pxr_SetSeeThroughBackground(Value);
#endif
	return 0;
}

