// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoBlueprintFunctionLibrary.h"	
#include "PicoMobileSettings.h"		   
#include "PicoImport.h"
#include "PicoJava.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "IImageWrapperModule.h"
#include "Modules/ModuleManager.h"
#include "IImageWrapper.h"
#include "Engine/Classes/Kismet/StereoLayerFunctionLibrary.h"
#include "../Launch/Resources/Version.h"
#include "Materials/Material.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "PicoMobile.h"
#include "PicoEyeTracker.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "Runtime/HeadMountedDisplay/Public/XRThreadUtils.h"
#endif


#define DEVICE_CV 1
#define DEVICE_GOBLIN 0

// Instantiate delegate
FPicoLogInOutCallbackDelegate UPicoBlueprintFunctionLibrary::PicoLogInOutCallback;
FPicoGetUserInfoCallbackDelegate UPicoBlueprintFunctionLibrary::PicoGetUserInfoCallback;
FPicoPayOrderCallbackDelegate UPicoBlueprintFunctionLibrary::PicoPayOrderCallback;
FPicoQueryOrderCallbackDelegate UPicoBlueprintFunctionLibrary::PicoQueryOrderCallback;
FPicoPaymentExceptionCallbackDelegate UPicoBlueprintFunctionLibrary::PicoPaymentExceptionCallback;
FPicoEntitlementVerifyCallbackDelegate UPicoBlueprintFunctionLibrary::PicoEntitlementVerifyCallback;
FPicoIPDChangedDelegate UPicoBlueprintFunctionLibrary::PicoIPDChangedCallback;

static FPicoMobileHMD* GetPicoHMD()
{
	if (GEngine->XRSystem.IsValid() && GEngine->XRSystem->GetSystemName() == FName("FPicoVRHMD"))
	{

		return static_cast<FPicoMobileHMD*>(GEngine->XRSystem.Get());
	}
	UE_LOG(LogTemp, Error, TEXT("Pvr_UE UPicoBlueprintFunctionLibrary GetPicoHMD null"));
	return nullptr;
}

FQuat UPicoBlueprintFunctionLibrary::PicoGetCurrentOrientation()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::GCurrentPoseGT.Orientation;
#else
	return FQuat(0, 0, 0, 0);
#endif
}

FVector UPicoBlueprintFunctionLibrary::PicoGetCurrentPosition()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::GCurrentPoseGT.Position;
#else
	return FVector(0, 0, 0);
#endif
}



void UPicoBlueprintFunctionLibrary::PicoIs6Dof(bool& is6dof)
{
#if PLATFORM_ANDROID
	if (GetDefault <UPicoMobileSettings>()->bDisableHmd6DofModule)
	{
		is6dof = false;
		return;
	}
	else
	{
		int32 whether6dof = -1;
		PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::ABILITY6DOF, whether6dof);
		if (whether6dof == 1)
		{
			is6dof = true;
			return;
		}
		else
		{
			is6dof = false;
			return;
		}
	}
#endif
	return;
}

void UPicoBlueprintFunctionLibrary::PicoGetControllerType(int32& ControllerType)
{
	ControllerType = 0;
#if PLATFORM_ANDROID
	ControllerType = FPicoJava::GetControllerType();
#endif	
}

//
//void UPicoBlueprintFunctionLibrary::PicoInitPSensor()
//{
//#if PLATFORM_ANDROID
//	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
//	{
//		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "InitPSensor", "()V", false);
//		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
//	}
//#endif
//}

void UPicoBlueprintFunctionLibrary::PicoGetPSensorState(int32& SensorState)
{
	int32 state = -1;
	if (GetDefault <UPicoMobileSettings>()->bEnablePSensor) 
	{
#if PLATFORM_ANDROID
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UEPvr_GetPsensorState", "()I", false);
			state = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, Method);	
		}
#endif
	}
	if (state == 0)
	{
		SensorState = 0;
	} 
	else if (state == -1)
	{
		SensorState = -1;
	}
	else
	{
		SensorState = 1;
	}

}

//void UPicoBlueprintFunctionLibrary::PicoUnRegisterPSensor()
//{
//#if PLATFORM_ANDROID
//	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
//	{
//		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "UnRegisterPSensor", "()V", false);
//		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
//	}
//#endif
//
//}

bool UPicoBlueprintFunctionLibrary::ResetSensor()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::ResetSensor(DEVICE_GOBLIN);
#else
	return false;
#endif
}
float UPicoBlueprintFunctionLibrary::PicoGetFov()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::GFov;
#else
	return 0.0f;
#endif
}
float UPicoBlueprintFunctionLibrary::PicoGetVFov()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::GVFov;
#else
	return 0.0f;
#endif
}
float UPicoBlueprintFunctionLibrary::PicoGetHFov()
{
#if PLATFORM_ANDROID
	return PicoSDK::Sensor::GHFov;
#else
	return 0.0f;
#endif
}
bool UPicoBlueprintFunctionLibrary::PicoSetIPD(float ipd)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::Render::SetIPD(ipd);
#endif
	return ret;
}
bool UPicoBlueprintFunctionLibrary::PicoGetIPD(float& ipd)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::Render::GetIPD(ipd);
#endif
	return ret;
}
bool UPicoBlueprintFunctionLibrary::PicoGetTrackingIPDEnabled()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::Render::GetTrackingIPDEnabled();
#endif
	return ret;
}
bool UPicoBlueprintFunctionLibrary::PicoSetTrackingIPDEnabled(bool enable)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::Render::SetTrackingIPDEnabled(enable);
#endif
	return ret;
}
bool UPicoBlueprintFunctionLibrary::PicoGetEyeTrackingAutoIPD(float &autoIPD)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::Render::GetEyeTrackingAutoIPD(autoIPD);
#endif
	return ret;
}

int32 UPicoBlueprintFunctionLibrary::PicoGetCurrentBrightness()
{
#if PLATFORM_ANDROID
	return FPicoJava::GetCurrentBrightness();
#else
	return 0;
#endif
}

bool UPicoBlueprintFunctionLibrary::PicoSetBrightness(int32 Brightness)
{
#if PLATFORM_ANDROID
	return FPicoJava::SetBrightness(Brightness);
#else
	return false;
#endif
}

bool UPicoBlueprintFunctionLibrary::PicoGetGpuUtilization(float &GpuUtilization)
{
	bool Succee = false;
	float Utilization = -1;
#if PLATFORM_ANDROID
	if (PicoImport::PvrGetGpuUtilization != nullptr)
	{
		Utilization = PicoImport::PvrGetGpuUtilization();
		Succee = true;
	}
#endif
	GpuUtilization = Utilization;
	return Succee;
}

int32 UPicoBlueprintFunctionLibrary::PicoGetCurrentVolume()
{
#if PLATFORM_ANDROID
	return FPicoJava::GetCurrentVolume();
#else
	return 0;
#endif
}

int32 UPicoBlueprintFunctionLibrary::PicoGetMaxVolumeNumber()
{
#if PLATFORM_ANDROID
	return FPicoJava::GetMaxVolumeNumber();
#else
	return 0;
#endif
}

void UPicoBlueprintFunctionLibrary::PicoSetVolume(int32 Volume)
{
#if PLATFORM_ANDROID
	return FPicoJava::SetVolume(Volume);
#endif
}

void UPicoBlueprintFunctionLibrary::PicoVolumeUp()
{
#if PLATFORM_ANDROID
	return FPicoJava::VolumeUp();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoVolumeDown()
{
#if PLATFORM_ANDROID
	return FPicoJava::VolumeDown();
#endif
}

int32 UPicoBlueprintFunctionLibrary::PicoGetHandness()
{
#if PLATFORM_ANDROID
	return FPicoJava::GetHandness();
#else
	return 2;
#endif
}

void UPicoBlueprintFunctionLibrary::PicoGetDeviceSN(FString & SN)
{
#if PLATFORM_ANDROID
	SN = FPicoJava::GetDeviceSN();
#endif
}

void UPicoBlueprintFunctionLibrary::SetCPUAndGPULevels(int CPULevel,int GPULevel)
{
#if PLATFORM_ANDROID
	PicoImport::PvrSetCPUGPULevels(CPULevel, GPULevel);
#endif
}


bool UPicoBlueprintFunctionLibrary::PicoControllerHomekey()
{
	bool enable = false;
#if PLATFORM_ANDROID
	enable = GetDefault <UPicoMobileSettings>()->bEnableHomeKey;
#endif
		return enable;
}


void UPicoBlueprintFunctionLibrary::PicoGetDeviceModel(FString & Model)
{		
#if PLATFORM_ANDROID
	Model = FAndroidMisc::GetDeviceModel();
#endif
}

EPicoSimulationType UPicoBlueprintFunctionLibrary::PicoIsCurrentDeviceValid()
{
#if PLATFORM_ANDROID
	if (GetDefault <UPicoMobileSettings>()->EntitlementCheckSimulation)
	{
		int32 num = GetDefault <UPicoMobileSettings>()->DeviceSN.Num();
		if (num == 0)
		{
			return EPicoSimulationType::Null;
		}
		else
		{
			for (int i = 0; i < num; i++)
			{
				if (GetDefault <UPicoMobileSettings>()->DeviceSN[i] == FPicoJava::GetDeviceSN())
				{
					return EPicoSimulationType::Valid;
				}
			}
			return EPicoSimulationType::Invalid;
		}
	}
	else
	{
		return EPicoSimulationType::Invalid;
	}
#endif
	return EPicoSimulationType::Invalid;
}

int32 UPicoBlueprintFunctionLibrary::PicoAppEntitlementCheck(FString appID)
{
#if PLATFORM_ANDROID
	FString publicKey = "";
	return FPicoJava::VerifyAPP(appID, publicKey);
#endif
	return -1;
}

bool UPicoBlueprintFunctionLibrary::PicoKeyEntitlementCheck(FString publicKey)
{
#if PLATFORM_ANDROID
	FString appID = "";
	//return FPicoJava::VerifyAPP(appID, publicKey);
#endif
	return false;
}

void UPicoBlueprintFunctionLibrary::PicoEntitlementVerifySetCallbackDelegates(FPicoEntitlementVerifyCallbackDelegate OnPicoEntitlementVerifyCallback)
{
#if PLATFORM_ANDROID
	PicoEntitlementVerifyCallback = OnPicoEntitlementVerifyCallback;
	if (GetDefault <UPicoMobileSettings>()->bStartTimeEntitlementCheck)
	{
		if(PicoSDK::GVerifyCallbackCode != 1)
		{
			PicoEntitlementVerifyCallback.Execute(PicoSDK::GVerifyCallbackCode);
		}
	}
	
#endif
}

void UPicoBlueprintFunctionLibrary::PicoIPDChangedDelegates(FPicoIPDChangedDelegate OnPicoIPDChanged)
{
#if PLATFORM_ANDROID
	PicoIPDChangedCallback = OnPicoIPDChanged;
#endif
}

void UPicoBlueprintFunctionLibrary::PicoLoginSDK()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentLogin();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentLogin()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentLogin();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoLogoutSDK()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentLogout();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentLogout()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentLogout();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoSDKGetUserInfo()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentGetUserInfo();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentGetUserInfo()
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentGetUserInfo();
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentPayWithCoin(const FPicoCoinOrderInfo& Order)
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentPayWithCoin(Order.OrderNumber, Order.OrderTitle, Order.ProductDetail, Order.NotifyUrl, Order.PicoCoinCount);
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentPayWithPayCode(const FPicoPayCodeOrderInfo& Order)
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentPayWithPayCode(Order.OrderNumber, Order.OrderTitle, Order.ProductDetail, Order.NotifyUrl, Order.PicoPayCode);
#endif
}

void UPicoBlueprintFunctionLibrary::PicoPaymentQueryOrder(const FString& OrderNumber)
{
#if PLATFORM_ANDROID
	FPicoJava::PaymentQueryOrder(OrderNumber);
#endif
}
extern FString GExternalFilePath;
FString UPicoBlueprintFunctionLibrary::GetRootPath() 
{
	FString PathStr = "";
#if PLATFORM_ANDROID
	TArray<FString> Folders;
	GExternalFilePath.ParseIntoArray(Folders, TEXT("/"));
	for (FString Folder : Folders)
	{
		PathStr += FString("/..");
	}

#endif
	//UE_LOG(LogTemp, Log, TEXT("Pvr_UE LoadMesh RootPathe %s "), *PathStr);
	return PathStr;
}

bool UPicoBlueprintFunctionLibrary::PicoEnableFoveation(bool enable)
{
#if PLATFORM_ANDROID
	if (PicoSDK::Render::SystemFoveationLevel != -1)
	{
		return false;
	}
	PicoSDK::Render::EnableFoveation(enable);
	return true;
#endif
	return false;

}

bool UPicoBlueprintFunctionLibrary::PicoGetFoveationLevel(PicoFoveationLevel& level)
{
#if PLATFORM_ANDROID
	level = (PicoFoveationLevel)PicoSDK::Render::GetFoveationLevel();
	return true;
#endif
	return false;
	
}

bool UPicoBlueprintFunctionLibrary::PicoSetFoveationLevel(PicoFoveationLevel level)
{
	bool ret = false;
#if PLATFORM_ANDROID
	if (PicoSDK::Render::SystemFoveationLevel != -1)
	{
		return false;
	}
	PicoSDK::Render::SetFoveationLevel((int32)level);
	ret = true;
#endif
	return ret;
}

bool UPicoBlueprintFunctionLibrary::PicoSetFoveationParameter(FVector2D foveationGainValue, float foveationAreaValue, float foveationMinimumValue)
{
#if PLATFORM_ANDROID
	if (PicoSDK::Render::SystemFoveationLevel != -1)
	{
		return false;
	}
	PicoSDK::Render::SetFoveationParamters(foveationGainValue.X, foveationGainValue.Y, foveationAreaValue, foveationMinimumValue);
	return true;
#endif
	return false;
}

bool UPicoBlueprintFunctionLibrary::PicoGetCurrentDisplayFrequency(float &CurrentDisplayFrequency)
{
	CurrentDisplayFrequency = 60.0f;
#if PLATFORM_ANDROID
	CurrentDisplayFrequency = PicoSDK::Render::DisplayRate;	
#endif
	return true;
}
//boundary
bool UPicoBlueprintFunctionLibrary::PicoGetBoundaryConfigured()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::SeeThrough::GetBoundaryConfigured();
#endif
	return ret;
}

bool UPicoBlueprintFunctionLibrary::PicoGetBoundaryEnabled()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoSDK::SeeThrough::GetBoundaryEnabled();
#endif
	return ret;
}

void UPicoBlueprintFunctionLibrary::PicoSetBoundaryVisible(bool enable)
{
	
#if PLATFORM_ANDROID
	PicoSDK::SeeThrough::SetBoundaryVisible(enable);
#endif
}

bool UPicoBlueprintFunctionLibrary::PicoBoundaryTestNode(EPicoNodeType node, bool isPlayArea, bool &isTriggering, float &closestDistance, FVector &ppos, FVector &npos)
{
	bool ret = false;
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		ret = PicoSDK::SeeThrough::BoundaryTestNode((int32)node, isPlayArea, isTriggering, closestDistance, ppos.X, ppos.Y, ppos.Z, npos.X, npos.Y, npos.Z);
	}
#endif
	return ret;
}

bool UPicoBlueprintFunctionLibrary::PicoBoundaryTestPoint(FVector pos, bool isPlayArea, bool &isTriggering, float &closestDistance, FVector &ppos, FVector &npos)
{
	bool ret = false;
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		ret = PicoSDK::SeeThrough::BoundaryTestPoint(pos.X, pos.Y, pos.Z, isPlayArea, isTriggering, closestDistance, ppos.X, ppos.Y, ppos.Z, npos.X, npos.Y, npos.Z);
	}
#endif
	return ret;
}

int32 UPicoBlueprintFunctionLibrary::PicoBoundaryGetGeometry(TArray<FVector> &outPointsVec, bool isPlayArea)
{
	int32 ret = 0;
#if PLATFORM_ANDROID
	ret = PicoSDK::SeeThrough::BoundaryGetGeometry(outPointsVec, isPlayArea);
#endif
	return ret;
}
void UPicoBlueprintFunctionLibrary::PicoGetBoundaryDimensions(FVector &dimensions, bool isPlayArea)
{

#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		PicoSDK::SeeThrough::GetBoundaryDimensions(dimensions, isPlayArea);
	}
#endif
	
}
bool UPicoBlueprintFunctionLibrary::PicoGetBoundaryVisible()
{
	bool ret = false;
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		ret = PicoSDK::SeeThrough::GetBoundaryVisible();
	}
#endif
	return ret;
}


bool UPicoBlueprintFunctionLibrary::PicoGetBoundarySeeThroughData(UTexture2D* &cameraImage, EPicoCamType cameraType)
{
#if PLATFORM_ANDROID
	PicoSDK::SeeThrough::StartCameraFrame();
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		if (cameraType == EPicoCamType::Left)
		{
			if (!PicoSDK::SeeThrough::camTextureLeft)
			{
			    PicoSDK::SeeThrough::camTextureLeft = UTexture2D::CreateTransient(UPicoBlueprintFunctionLibrary::ImageSize.X, UPicoBlueprintFunctionLibrary::ImageSize.Y, EPixelFormat::PF_R8G8B8A8);
				check(PicoSDK::SeeThrough::camTextureLeft);
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = PicoSDK::SeeThrough::camTextureLeft->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource *>(PicoSDK::SeeThrough::camTextureLeft->CreateResource());
#endif
				PicoSDK::SeeThrough::camTextureLeft->UpdateResource();
				ExecuteOnRenderThread([Resource]()
	            {
	                Resource->InitRHI();
	                ExecuteOnRHIThread([Resource]()
	                {
	                    PicoSDK::SeeThrough::LeftTextureID = *reinterpret_cast<uint32*>(Resource->GetTexture2DRHI()->GetNativeResource());
	                });
	            });
				delete Resource;
				Resource = nullptr;
			}

			if (PicoSDK::SeeThrough::camTextureLeft->GetSizeX() != UPicoBlueprintFunctionLibrary::ImageSize.X || PicoSDK::SeeThrough::camTextureLeft->GetSizeY() != UPicoBlueprintFunctionLibrary::ImageSize.Y)
			{
				PicoSDK::SeeThrough::camTextureLeft->ReleaseResource();
				
				PicoSDK::SeeThrough::camTextureLeft = UTexture2D::CreateTransient(UPicoBlueprintFunctionLibrary::ImageSize.X, UPicoBlueprintFunctionLibrary::ImageSize.Y, EPixelFormat::PF_R8G8B8A8);;
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = PicoSDK::SeeThrough::camTextureLeft->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource*>(PicoSDK::SeeThrough::camTextureLeft->CreateResource());
#endif		
				PicoSDK::SeeThrough::camTextureLeft->UpdateResource();
				ExecuteOnRenderThread([Resource]()
                {
                    Resource->InitRHI();
                    ExecuteOnRHIThread([Resource]()
                    {
                        PicoSDK::SeeThrough::LeftTextureID = *reinterpret_cast<uint32*>(Resource->GetTexture2DRHI()->GetNativeResource());
                    });
                });
				delete Resource;
				Resource = nullptr;
			}

			ExecuteOnRenderThread([]()
			{
				ExecuteOnRHIThread([]()
				{
					PicoSDK::Render::RenderEventWithData(EVENT_CAMERAFRAME_LEFT, PicoSDK::SeeThrough::LeftTextureID);
				});
			});
			cameraImage = PicoSDK::SeeThrough::camTextureLeft;
			return true;
		}
		else
		{
			if (!PicoSDK::SeeThrough::camTextureRight)
			{
				PicoSDK::SeeThrough::camTextureRight = UTexture2D::CreateTransient(UPicoBlueprintFunctionLibrary::ImageSize.X, UPicoBlueprintFunctionLibrary::ImageSize.Y, EPixelFormat::PF_R8G8B8A8);
				check(PicoSDK::SeeThrough::camTextureRight);
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = PicoSDK::SeeThrough::camTextureRight->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource*>(PicoSDK::SeeThrough::camTextureRight->CreateResource());
#endif	
				PicoSDK::SeeThrough::camTextureRight->UpdateResource();
				ExecuteOnRenderThread([Resource]()
                {
                    Resource->InitRHI();
                    ExecuteOnRHIThread([Resource]()
                    {
                        PicoSDK::SeeThrough::RightTextureID = *reinterpret_cast<uint32*>(Resource->GetTexture2DRHI()->GetNativeResource());
                    });
                });
				delete Resource;
				Resource = nullptr;
			}
			if (PicoSDK::SeeThrough::camTextureRight->GetSizeX() != UPicoBlueprintFunctionLibrary::ImageSize.X || PicoSDK::SeeThrough::camTextureRight->GetSizeY() != UPicoBlueprintFunctionLibrary::ImageSize.Y)
			{
				PicoSDK::SeeThrough::camTextureRight->ReleaseResource();
				PicoSDK::SeeThrough::camTextureRight = UTexture2D::CreateTransient(UPicoBlueprintFunctionLibrary::ImageSize.X, UPicoBlueprintFunctionLibrary::ImageSize.Y, EPixelFormat::PF_R8G8B8A8);;
#if ENGINE_MINOR_VERSION > 25
				FTextureResource* Resource = PicoSDK::SeeThrough::camTextureRight->CreateResource();
#else	
				FTexture2DResource* Resource = static_cast<FTexture2DResource*>(PicoSDK::SeeThrough::camTextureRight->CreateResource());
#endif
				PicoSDK::SeeThrough::camTextureRight->UpdateResource();
				ExecuteOnRenderThread([Resource]()
                {
                    Resource->InitRHI();
                    ExecuteOnRHIThread([Resource]()
                    {
                        PicoSDK::SeeThrough::RightTextureID = *reinterpret_cast<uint32*>(Resource->GetTexture2DRHI()->GetNativeResource());
                    });
                });
				delete Resource;
				Resource = nullptr;
			}
			

			ExecuteOnRenderThread([]()
			{
				ExecuteOnRHIThread([]()
				{
					PicoSDK::Render::RenderEventWithData(EVENT_CAMERAFRAME_RIGHT, PicoSDK::SeeThrough::RightTextureID);
				});
			});
			cameraImage = PicoSDK::SeeThrough::camTextureRight;
			return true;
		}
	}
#endif
	return false;
}

FIntPoint UPicoBlueprintFunctionLibrary::ImageSize = FIntPoint(640,640);

bool UPicoBlueprintFunctionLibrary::PicoSetBoundaryCameraImageSize(FIntPoint imageSize)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ImageSize = imageSize;
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD->IsInitialized())
	{
		 PicoSDK::SeeThrough::SetCameraImageRect(ImageSize);
		 ret = true;
	}
#endif

	return ret;
}

#pragma region Eyetracking

bool UPicoBlueprintFunctionLibrary::PicoGetEyeTrackingGazeRay(FVector& Origin, FVector& Direction)
{
	FEyeTrackingGazeRay outEyeTrackingGazeRay;
	memset(&outEyeTrackingGazeRay, 0, sizeof(outEyeTrackingGazeRay));
#if PLATFORM_ANDROID
	if ((PicoImport::PvrGetTrackingMode() & 4) && GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	{
		FPicoEyeTracker *EyeTracker = FPicoEyeTracker::GetInstance();
		if (EyeTracker->GetEyeTrackingGazeRay(outEyeTrackingGazeRay))
		{
			Direction = outEyeTrackingGazeRay.Direction;
			Origin = outEyeTrackingGazeRay.Origin;
			return true;
		}
	}
#endif
	return false;
}

void UPicoBlueprintFunctionLibrary::PicoEnableEyeTrackingMarker(bool Enable)
{
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	PicoHMD->EnableEyeMarker(Enable);
}

bool UPicoBlueprintFunctionLibrary::PicoGetEyeTrackingData(FPicoEyeTrackingData &PicoEyeTrackingData)
{
#if PLATFORM_ANDROID
	if ((PicoImport::PvrGetTrackingMode() & 4) && GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	{
		FPicoEyeTracker *EyeTracker = FPicoEyeTracker::GetInstance();
		if (EyeTracker->GetEyeTrackingData(PicoEyeTrackingData))
		{
			FVector TempVector = FVector::ZeroVector;
			TempVector = PicoEyeTrackingData.leftEyeGazePoint;
			PicoEyeTrackingData.leftEyeGazePoint.X = -TempVector.Z;
			PicoEyeTrackingData.leftEyeGazePoint.Y = TempVector.X;
			PicoEyeTrackingData.leftEyeGazePoint.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.rightEyeGazePoint;
			PicoEyeTrackingData.rightEyeGazePoint.X = -TempVector.Z;
			PicoEyeTrackingData.rightEyeGazePoint.Y = TempVector.X;
			PicoEyeTrackingData.rightEyeGazePoint.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.combinedEyeGazePoint;
			PicoEyeTrackingData.combinedEyeGazePoint.X = -TempVector.Z;
			PicoEyeTrackingData.combinedEyeGazePoint.Y = TempVector.X;
			PicoEyeTrackingData.combinedEyeGazePoint.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.leftEyeGazeVector;
			PicoEyeTrackingData.leftEyeGazeVector.X = -TempVector.Z;
			PicoEyeTrackingData.leftEyeGazeVector.Y = TempVector.X;
			PicoEyeTrackingData.leftEyeGazeVector.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.rightEyeGazeVector;
			PicoEyeTrackingData.rightEyeGazeVector.X = -TempVector.Z;
			PicoEyeTrackingData.rightEyeGazeVector.Y = TempVector.X;
			PicoEyeTrackingData.rightEyeGazeVector.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.combinedEyeGazeVector;
			PicoEyeTrackingData.combinedEyeGazeVector.X = -TempVector.Z;
			PicoEyeTrackingData.combinedEyeGazeVector.Y = TempVector.X;
			PicoEyeTrackingData.combinedEyeGazeVector.Y = TempVector.Y;

		  /*TempVector = PicoEyeTrackingData.leftEyePositionGuide;
			PicoEyeTrackingData.leftEyePositionGuide.X = -TempVector.Z;
			PicoEyeTrackingData.leftEyePositionGuide.Y = TempVector.X;
			PicoEyeTrackingData.leftEyePositionGuide.Y = TempVector.Y;

			TempVector = PicoEyeTrackingData.rightEyePositionGuide;
			PicoEyeTrackingData.rightEyePositionGuide.X = -TempVector.Z;
			PicoEyeTrackingData.rightEyePositionGuide.Y = TempVector.X;
			PicoEyeTrackingData.rightEyePositionGuide.Y = TempVector.Y;*/

			TempVector = PicoEyeTrackingData.foveatedGazeDirection;
			PicoEyeTrackingData.foveatedGazeDirection.X = -TempVector.Z;
			PicoEyeTrackingData.foveatedGazeDirection.Y = TempVector.X;
			PicoEyeTrackingData.foveatedGazeDirection.Y = TempVector.Y;

			return true;
		}
	}
#endif
	return false;
}

bool UPicoBlueprintFunctionLibrary::PicoGetEyeTrackingPos(FVector & EyeTrackingPos)
{
#if PLATFORM_ANDROID
	if ((PicoImport::PvrGetTrackingMode() & 4) && GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	{
		FPicoEyeTracker *EyeTracker = FPicoEyeTracker::GetInstance();
		if (EyeTracker->GetEyeDirectionToFoveationRendering(EyeTrackingPos))
		{
			return true;
		}
	}
#endif
	return false;
}


/*bool UPicoBlueprintFunctionLibrary::PicoGetEyeDirection(FVector &OutEyeDirection)
{
	bool Success = false;
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (nullptr == PicoHMD ||false == GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	{
		return Success;
	}

	Success = PicoHMD->GetRelativeEyeDirection(PicoHMD->HMDDeviceId , OutEyeDirection);
	
	//UE_LOG(LogTemp, Log, TEXT("OutEyeDirection1  (%f , %f , %f) "), OutEyeDirection.X, OutEyeDirection.Y, OutEyeDirection.Z);

	FQuat HMD_Orientation;
	FVector HMD_Position;

	// rotate eye gaze by HMD rotation
	bool ret = PicoHMD->GetCurrentPose(PicoHMD->HMDDeviceId, HMD_Orientation, HMD_Position);
	if (Success && ret)
	{
		OutEyeDirection = HMD_Orientation * OutEyeDirection;
		//UE_LOG(LogTemp, Log, TEXT("OutEyeDirection2  (%f , %f , %f) "), OutEyeDirection.X, OutEyeDirection.Y, OutEyeDirection.Z);
		return true;
	}
	return false;
}

void UPicoBlueprintFunctionLibrary::PicoGetEyeOrientationAndPosition(FVector& OutPosition, FQuat& OutOrientation, FRotator& OutRotation, bool& Success)
{
	Success = false;
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();

	if (nullptr == PicoHMD || false == PicoHMD->isEyeTrackingEnabled())
	{
		return;
	}

	// doesn't care about eye parameter....
	Success = PicoHMD->GetRelativeEyePose(PicoHMD->HMDDeviceId, EStereoscopicPass::eSSP_LEFT_EYE, OutOrientation, OutPosition);

	//UE_LOG(LogTemp, Log, TEXT("OutOrientation1  (%f , %f , %f , %f) "), OutOrientation.X, OutOrientation.Y, OutOrientation.Z, OutOrientation.W);
	//UE_LOG(LogTemp, Log, TEXT("OutPosition1  (%f , %f , %f) "), OutPosition.X, OutPosition.Y, OutPosition.Z);
	FQuat HMD_Orientation;
	FVector HMD_Position;

	if (Success && (Success = PicoHMD->GetCurrentPose(PicoHMD->HMDDeviceId, HMD_Orientation, HMD_Position)))
	{
		OutPosition = HMD_Orientation * OutPosition + HMD_Position;
		OutOrientation = HMD_Orientation * OutOrientation;
		OutRotation = OutOrientation.Rotator();
		//UE_LOG(LogTemp, Log, TEXT("OutRotation2  (%f , %f , %f) "), OutRotation.Roll, OutRotation.Pitch, OutRotation.Yaw);
		//UE_LOG(LogTemp, Log, TEXT("OutOrientation2  (%f , %f , %f , %f) "), OutOrientation.X, OutOrientation.Y, OutOrientation.Z, OutOrientation.W);
		//UE_LOG(LogTemp, Log, TEXT("OutPosition2  (%f , %f , %f) "), OutPosition.X, OutPosition.Y, OutPosition.Z);
}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("PicoGetEyeOrientationAndPosition Failed "));
	}

#endif
	return;
}



void UPicoBlueprintFunctionLibrary::PicoGetEyeOpenness(EPicoVRHMD_Eye WhichEye, float& Openness, bool& Success)
{
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	Success = false;

	if (nullptr == PicoHMD || false == PicoHMD->isEyeTrackingEnabled())
	{
		return;
	}
	FEyeTrackingData eps;
	if (PicoHMD->GetEyeTrackingDataFromDevice(eps))
	{
		// Return either eye or averaged value
		Openness = WhichEye == EPicoVRHMD_Eye::LeftEye ? eps.leftEyeOpenness :
			(WhichEye == EPicoVRHMD_Eye::RightEye ? eps.rightEyeOpenness : (eps.leftEyeOpenness + eps.rightEyeOpenness)*0.5f);

		Success = true;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("PicoGetEyeOpenness Failed!"));
	}

#endif
	return;

}

void UPicoBlueprintFunctionLibrary::PicoGetPupilDialation(EPicoVRHMD_Eye WhichEye, float& Dialation, bool& Success)
{
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	Success = false;

	if (nullptr == PicoHMD || false == PicoHMD->isEyeTrackingEnabled())
	{
		return;
	}

	FEyeTrackingData eps;
	if (PicoHMD->GetEyeTrackingDataFromDevice(eps))
	{	
		// Return either eye or averaged value
		Dialation = WhichEye == EPicoVRHMD_Eye::LeftEye ? eps.leftEyePupilDilation :
			(WhichEye == EPicoVRHMD_Eye::RightEye ? eps.rightEyePupilDilation : (eps.leftEyePupilDilation + eps.rightEyePupilDilation)*0.5f);

		Success = true;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("PicoGetPupilDialation Failed! "));
	}
#endif
	return;
}

void UPicoBlueprintFunctionLibrary::PicoIsEyetrackingEnabled(bool& IsEnabled)
{
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	IsEnabled = (nullptr != PicoHMD && PicoHMD->isEyeTrackingEnabled()) ? true : false;
#endif
}*/

#pragma endregion Eyetracking



#pragma region SplashScreen

void UPicoBlueprintFunctionLibrary::PicoAddSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters /*= FVector2D(1.0f, 1.0f)*/, bool bAutoShow)
{
#if PLATFORM_ANDROID
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD != nullptr)
	{
		FPicoVRSplash* Splash = PicoHMD->GetSplash();
		if (Splash)
		{
			FPicoSplashDesc Desc;
			Desc.LoadingTexture = Texture;
			Desc.QuadSizeInMeters = SizeInMeters;
			Desc.TransformInMeters = FTransform(Rotation, TranslationInMeters);
			Splash->SetSplashLayerDec(Desc);
			Splash->SetAutoShow(bAutoShow);
		}
	}
#endif
}

void UPicoBlueprintFunctionLibrary::PicoClearSplashScreens()
{
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD != nullptr)
	{
		FPicoVRSplash* Splash = PicoHMD->GetSplash();
		if (Splash)
		{
			Splash->ClearSplashScreen();
			Splash->SetAutoShow(false);
		}
	}

}

//void UPicoBlueprintFunctionLibrary::PicoShowSplashScreen()
//{
//	FPicoMobileHMD* PicoHMD = GetPicoHMD();
//	if (PicoHMD != nullptr)
//	{
//		FPicoVRSplash* Splash = PicoHMD->GetSplash();
//		if (Splash)
//		{
//			Splash->Show();
//		}
//	}
//
//}
//
//void UPicoBlueprintFunctionLibrary::PicoHideSplashScreen()
//{
//	FPicoMobileHMD* PicoHMD = GetPicoHMD();
//	if (PicoHMD != nullptr)
//	{
//		FPicoVRSplash* Splash = PicoHMD->GetSplash();
//		if (Splash)
//		{
//			Splash->Hide();
//		}
//	}
//}

void UPicoBlueprintFunctionLibrary::PicoEnableAutoShowSplashScreen(bool bAutoShowEnabled)
{
	FPicoMobileHMD* PicoHMD = GetPicoHMD();
	if (PicoHMD != nullptr)
	{
		FPicoVRSplash* Splash = PicoHMD->GetSplash();
		if (Splash)
		{
			Splash->SetAutoShow(bAutoShowEnabled);	
		}
	}
	UStereoLayerFunctionLibrary::EnableAutoLoadingSplashScreen(bAutoShowEnabled);
}

#pragma  endregion SplashScreen


void UPicoBlueprintFunctionLibrary::LoadMesh(FString FilePathAndName, TArray<FVector> &Vertices, TArray<int32> &Triangles, TArray<FVector> &Normals, TArray<FVector2D> &UV, FString &Name,bool &Succeed)
{
	FString LoadedString;
	TArray<FString> LineArray = {};
	TArray<FString> VArry = {};
	TArray<FString> VTArry = {};
	TArray<FString> VNArry = {};
	TArray<FString> GArry = {};
	TArray<FString> FTempArry = {};
	TArray<FVector> VTempArry = {};
	TArray<FVector2D> VTTempArry = {};
	TArray<FVector> VNTempArry = {};
	TArray<FString> FArry = {};
	TArray<FString> FDataArry = {};
	TArray<int32> IntArry = {};
	int32 faceDataCount = 0;
	TArray<int32>triangles = {};
	TArray<FVector>FaceData = {};

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FilePathAndName = GetRootPath() + FilePathAndName;
	if (PlatformFile.FileExists(*FilePathAndName))
	{
		//UE_LOG(LogTemp, Log, TEXT("Pvr_UE LoadMesh File %s Succeed"),*FilePathAndName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE LoadMesh File %s Faild"), *FilePathAndName);
		Succeed = false;
		return;
	}
	FFileHelper::LoadFileToString(LoadedString, *FilePathAndName);
	LoadedString.ParseIntoArrayLines(LineArray, true);
	for (int i = 0; i < LineArray.Num(); i++)
	{
		if (LineArray[i].StartsWith("v "))
		{
			LineArray[i].ParseIntoArray(VArry, TEXT(" "), true);
			FVector Temp = FVector::ZeroVector;
			for (int index = 0; index < VArry.Num(); index++)
			{
				switch (index % 4)
				{
				case 0:
					break;
				case 1:
					Temp.X = FCString::Atof(*VArry[index]);
					break;
				case 2:
					Temp.Y = FCString::Atof(*VArry[index]);
					break;
				case 3:
					Temp.Z = -FCString::Atof(*VArry[index]);
					VTempArry.Add(Temp);
					break;
				default:
					break;;
				}
			}
		}
		else if (LineArray[i].StartsWith("vt"))
		{
			FVector2D Temp = FVector2D::ZeroVector;
			LineArray[i].ParseIntoArray(VTArry, TEXT(" "), true);
			for (int index = 0; index < VTArry.Num(); index++)
			{
				switch (index % 3)
				{
				case 0:
					break;
				case 1:
					Temp.X = FCString::Atof(*VTArry[index]);
					break;
				case 2:
					Temp.Y = -FCString::Atof(*VTArry[index]);
					VTTempArry.Add(Temp);
					break;
				default:
					break;
				}
			}
		}
		else if (LineArray[i].StartsWith("vn"))
		{
			FVector Temp = FVector::ZeroVector;
			LineArray[i].ParseIntoArray(VNArry, TEXT(" "), true);
			for (int index = 0; index < VNArry.Num(); index++)
			{
				switch (index % 4)
				{
				case 0:
					break;
				case 1:
					Temp.X = FCString::Atof(*VNArry[index]);
					break;
				case 2:
					Temp.Y = FCString::Atof(*VNArry[index]);
					break;
				case 3:
					Temp.Z = -FCString::Atof(*VNArry[index]);
					VNTempArry.Add(Temp);
					break;
				}
			}
		}
		else if (LineArray[i].StartsWith("g "))//name
		{
			LineArray[i].ParseIntoArray(GArry, TEXT(" "), true);
		}

		else if (LineArray[i].StartsWith("f "))
		{
			int32 j = 1;
			int32 Info = 0;
			IntArry = {};
			LineArray[i].ParseIntoArray(FArry, TEXT(" "), true);
			for (int index = 0; index < FArry.Num(); index++)
			{
				if (index != 0)
				{
					j++;
					FTempArry.Add(FArry[index]);
					IntArry.Add(faceDataCount);
					faceDataCount++;
				}
			}
			Info += j;
			j = 1;
			while (j + 2 < Info)
			{
				triangles.Add(IntArry[0]);
				triangles.Add(IntArry[j]);
				triangles.Add(IntArry[j + 1]);
				j++;
			}
		}
	}

	for (int i = 0; i < FTempArry.Num(); i++)
	{
		FVector Temp = FVector::ZeroVector;
		FTempArry[i].ParseIntoArray(FDataArry, TEXT("/"), true);
		for (int index = 0; index < FDataArry.Num(); index++)
		{
			switch (index % 3)
			{
			case 0:
				Temp.X = FCString::Atof(*FDataArry[index]);
				break;
			case 1:
				Temp.Y = FCString::Atof(*FDataArry[index]);
				break;
			case 2:
				Temp.Z = FCString::Atof(*FDataArry[index]);
				//UE_LOG(LogTemp, Log, TEXT("FVector %f,%f,%f"), Temp.X,Temp.Y,Temp.Z);
				FaceData.Add(Temp);
				break;
			default:
				break;;
			}
		}
	}

	TArray<FVector> newVerts = {};
	TArray<FVector> newNormals = {};
	TArray<FVector2D> newUVs = {};

	for (int i = 0; i < FaceData.Num(); i++)
	{
		newVerts.Add(FVector::ZeroVector);
		newNormals.Add(FVector::ZeroVector);
		newUVs.Add(FVector2D::ZeroVector);
	}

	for (int i = 0; i < FaceData.Num(); i++)
	{
		newVerts[i] = VTempArry[FaceData[i].X - 1];
		if (FaceData[i].Y >= 1)
		{
			newUVs[i] = VTTempArry[FaceData[i].Y - 1];
		}
		if (FaceData[i].Z >= 1)
		{
			newNormals[i] = VNTempArry[FaceData[i].Z - 1];
		}
	}


	Vertices = newVerts;
	Normals = newNormals;
	UV = newUVs;
	Name = GArry[1];
	Triangles = triangles;
	Succeed = true;
}


void UPicoBlueprintFunctionLibrary::LoadTexture(FString FilePathAndName, UTexture2D* &Texture, bool &Succeed)
{
	UTexture2D* OutTex = NULL;
	IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> imageWrapper;
	if (FilePathAndName.EndsWith("png"))
	{
		imageWrapper = imageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	}else if (FilePathAndName.EndsWith("jpg"))
	{
		imageWrapper = imageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
	}
	 
	TArray<uint8> OutArray;
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FilePathAndName = GetRootPath() + FilePathAndName;
	if (PlatformFile.FileExists(*FilePathAndName))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Pvr_UE LoadTexture File %s Succeed"), *FilePathAndName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE LoadTexture File %s Faild"), *FilePathAndName);
		Succeed = false;
		return;
	}
	if (FFileHelper::LoadFileToArray(OutArray, *FilePathAndName))
	{
		if (imageWrapper.IsValid() &&imageWrapper->SetCompressed(OutArray.GetData(), OutArray.Num()))
		{
			int32 SourceBitDepth = imageWrapper->GetBitDepth();
#if ENGINE_MINOR_VERSION > 24 
			TArray<uint8> uncompressedRGBA;
#else
			const TArray<uint8>* uncompressedRGBA = NULL;
#endif
			if (imageWrapper->GetRaw(ERGBFormat::RGBA, SourceBitDepth, uncompressedRGBA))
			{
#if ENGINE_MINOR_VERSION > 24 
				TArray<FColor> uncompressedFColor = uint8ToFColor(uncompressedRGBA);
#else
				const TArray<FColor> uncompressedFColor = uint8ToFColor(*uncompressedRGBA);
#endif

				OutTex = TextureFromImage(
					imageWrapper->GetWidth(),
					imageWrapper->GetHeight(),
					uncompressedFColor,
					true);
			}
		}
	}
	else
	{
		Succeed = false;
		return;
	}
	Succeed = true;
	Texture = OutTex;

}

TArray<FColor> UPicoBlueprintFunctionLibrary::uint8ToFColor(const TArray<uint8> origin)
{
	TArray<FColor> uncompressedFColor;
	uint8 auxOrigin;
	FColor auxDst;

	for (int i = 0; i < origin.Num(); i++) {
		auxOrigin = origin[i];
		auxDst.R = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.G = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.B = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.A = auxOrigin;
		uncompressedFColor.Add(auxDst);
	}

	return  uncompressedFColor;
}

UTexture2D* UPicoBlueprintFunctionLibrary::TextureFromImage(const int32 SrcWidth, const int32 SrcHeight, const TArray<FColor> &SrcData, const bool UseAlpha)
{
	UTexture2D* MyScreenshot = UTexture2D::CreateTransient(SrcWidth, SrcHeight, PF_B8G8R8A8);
	uint8* MipData = static_cast<uint8*>(MyScreenshot->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE));

	uint8* DestPtr;
	const FColor* SrcPtr;
	for (int32 y = 0; y < SrcHeight; y++)
	{
		DestPtr = &MipData[(SrcHeight - 1 - y) * SrcWidth * sizeof(FColor)];
		SrcPtr = const_cast<FColor*>(&SrcData[(SrcHeight - 1 - y) * SrcWidth]);
		for (int32 x = 0; x < SrcWidth; x++)
		{
			*DestPtr++ = SrcPtr->B;
			*DestPtr++ = SrcPtr->G;
			*DestPtr++ = SrcPtr->R;
			if (UseAlpha)
			{
				*DestPtr++ = SrcPtr->A;
			}
			else
			{
				*DestPtr++ = 0xFF;
			}
			SrcPtr++;
		}
	}
	MyScreenshot->PlatformData->Mips[0].BulkData.Unlock();
	MyScreenshot->UpdateResource();

	return MyScreenshot;
}

#pragma region LoadObject

bool UPicoBlueprintFunctionLibrary::PicoLoadControllerAssets(
	UObject* WorldContextObject, EPicoControllerType ControllerType, TArray<UStaticMesh*> &ControllerMesh,
	UStaticMesh* &ControllerRayMesh, FPicoControllerButtonTexture& ButtonTextures, TArray<UTexture2D*> & BatteryTextures,
	UMaterialInstanceDynamic* &ControllerDynamicMaterial, UMaterialInstanceDynamic* &BatteryDynamicMaterial, 
	TArray<UMaterialInstance*>& RayMaterial, UMaterial* &TouchPointMaterial, UMaterialInstanceDynamic* &OtherDynamicMaterial)
{
	TArray<FString>ControllerMeshPath;
	TArray<FString>ControllerButtonTexturePath;
	FString ControllerMaterialPath;
	FString BatteryMaterialPath = TEXT("/PicoMobile/Material/Mat_power");
	TArray<FString> ControllerRayMaterialPath;
	FString ControllerRayMeshPath = TEXT("/PicoMobile/Mesh/Mesh_Ray");
	FString OtherDynamicMaterialPath = TEXT("");
	TArray<FString>BatteryTexturePath = {
		TEXT("/PicoMobile/Texture/ControllerPowerTexture/Power0"),
		TEXT("/PicoMobile/Texture/ControllerPowerTexture/Power1"),
		TEXT("/PicoMobile/Texture/ControllerPowerTexture/Power2"),
		TEXT("/PicoMobile/Texture/ControllerPowerTexture/Power3"),
		TEXT("/PicoMobile/Texture/ControllerPowerTexture/Power4")
	};
	FString TouchPointMaterialPath = TEXT("/PicoMobile/Material/Mat_TouchPoint");


	switch (ControllerType)
	{
	case EPicoControllerType::Goblin:
		ControllerMeshPath = { TEXT("/PicoMobileController/G1/Mesh/Mesh_G1") };
		ControllerButtonTexturePath =
		{
			TEXT("/PicoMobileController/G1/Texture/G1_Back"),
			TEXT("/PicoMobileController/G1/Texture/G1_Home"),
			TEXT("/PicoMobileController/G1/Texture/G1_Normal"),
			TEXT("/PicoMobileController/G1/Texture/G1_Touchpad"),
			TEXT("/PicoMobileController/G1/Texture/G1_VolumeDown"),
			TEXT("/PicoMobileController/G1/Texture/G1_VolumeUp")
		};
		ControllerMaterialPath = TEXT("/PicoMobileController/G1/Material/M_MotionControllerG1");
		ControllerRayMaterialPath = { TEXT("/PicoMobileController/G1/Material/Mat_Ray_G1") };
		
		break;
	case EPicoControllerType::Goblin2:
		ControllerMeshPath = { TEXT("/PicoMobileController/G2/Mesh/Mesh_G2") };
		ControllerButtonTexturePath =
		{
			TEXT("/PicoMobileController/G2/Texture/G2_Back"),
			TEXT("/PicoMobileController/G2/Texture/G2_Home"),
			TEXT("/PicoMobileController/G2/Texture/G2_Normal"),
			TEXT("/PicoMobileController/G2/Texture/G2_Touchpad"),
			TEXT("/PicoMobileController/G2/Texture/G2_VolumeDown"),
			TEXT("/PicoMobileController/G2/Texture/G2_VolumeUp"),
			TEXT("/PicoMobileController/G2/Texture/G2_Trigger")
		};
		ControllerMaterialPath = TEXT("/PicoMobileController/G2/Material/M_MotionControllerG2");
		ControllerRayMaterialPath = { TEXT("/PicoMobileController/G2/Material/Mat_Ray_G2") };
		break;
	case EPicoControllerType::Neo:
		ControllerMeshPath = { TEXT("/PicoNeoController/CV/Meshs/Mesh_Neo") };
		ControllerButtonTexturePath =
		{
			TEXT("/PicoNeoController/CV/Textures/Neo_Back"),
			TEXT("/PicoNeoController/CV/Textures/Neo_Home"),
			TEXT("/PicoNeoController/CV/Textures/Neo_Normal"),
			TEXT("/PicoNeoController/CV/Textures/Neo_Touchpad"),
			TEXT("/PicoNeoController/CV/Textures/Neo_Trigger"),
			TEXT("/PicoNeoController/CV/Textures/Neo_VolumeDown"),
			TEXT("/PicoNeoController/CV/Textures/Neo_VolumeUp")
		};
		ControllerMaterialPath = TEXT("/PicoNeoController/CV/Materials/M_MotionControllerNeo");
		ControllerRayMaterialPath = {TEXT("/PicoNeoController/CV/Materials/Mat_Ray_CV_Main"),
									 TEXT("/PicoNeoController/CV/Materials/Mat_Ray_CV_Sub") };
		break;
	case EPicoControllerType::Neo2:
		ControllerMeshPath = { TEXT("/PicoNeoController/CV2/Meshes/ppController_NEO2_Left"), 
							   TEXT("/PicoNeoController/CV2/Meshes/ppController_NEO2_Right") };
		ControllerButtonTexturePath =
		{
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Back"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_A"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_B"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_X"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Y"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Normal"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Grap"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Home"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_L_tag"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_R_tag"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Rocker"),
			TEXT("/PicoNeoController/CV2/Textures/Neo2_Trigger"),
		};
		ControllerMaterialPath = TEXT("/PicoNeoController/CV2/Materials/M_MotionControllerNeo2");
		ControllerRayMaterialPath = { TEXT("/PicoNeoController/CV/Materials/Mat_Ray_CV_Main") };
		OtherDynamicMaterialPath = TEXT("/PicoNeoController/CV2/Materials/M_ppController_Neo2_R_tag");
		break;
	case EPicoControllerType::Neo3:
		ControllerMeshPath = { TEXT("/PicoNeoController/CV3/Meshes/ppController_NEO3_L"), 
                               TEXT("/PicoNeoController/CV3/Meshes/ppController_NEO3_R") };
		ControllerButtonTexturePath =
		{
			TEXT("/PicoNeoController/CV3/Textures/Neo3_Back"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_A"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_B"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_X"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Y"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Normal"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Grip"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Home"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Rocker"),
            TEXT("/PicoNeoController/CV3/Textures/Neo3_Trigger"),
        };
		ControllerMaterialPath = TEXT("/PicoNeoController/CV3/Materials/M_MotionControllerNeo3");
		ControllerRayMaterialPath = { TEXT("/PicoNeoController/CV/Materials/Mat_Ray_CV_Main") };
		OtherDynamicMaterialPath = TEXT("/PicoNeoController/CV2/Materials/M_ppController_Neo2_R_tag");
		break;
	
	default:
		return false;
	}
	if (!LoadControllerButtonTextures(ControllerType,ControllerButtonTexturePath,ButtonTextures))
	{
		return false;
	}
	UStaticMesh* Controller0;
	 if (!LoadStaticMeshFromContent(ControllerMeshPath[0], Controller0))
	 {
		 return false;
	 }
	 ControllerMesh.Add(Controller0);
	 if (ControllerMeshPath.Num()>1)
	 {
		 UStaticMesh* Controller1;
		 if (!LoadStaticMeshFromContent(ControllerMeshPath[1], Controller1))
		 {
			 return false;
		 }
		 ControllerMesh.Add(Controller1);
	 }
	 if (!LoadStaticMeshFromContent(ControllerRayMeshPath,ControllerRayMesh))
	 {
		 return false;
	 }
	 UTexture2D* BatteryTexture;
	 for (int32 i = 0;i< BatteryTexturePath.Num();i++)
	 {
		 BatteryTexture = nullptr;
		 if (LoadTextureFromContent(BatteryTexturePath[i], BatteryTexture))
		 {
			 if (BatteryTexture)
			 {
				 BatteryTextures.Add(BatteryTexture);
				 continue;
			 }
		 }
		 return false;
	 }

	 UMaterial* ControllerMaterial;
	 if (!LoadMaterialFromContent(ControllerMaterialPath, ControllerMaterial))
	 {
		 return false;
	 }
	// ControllerDynamicMaterial = UMaterialInstanceDynamic::Create(ControllerMaterial, this);
	 ControllerDynamicMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance( WorldContextObject, ControllerMaterial, NAME_None);

	 UMaterial* BatteryMaterial;
	 if (!LoadMaterialFromContent(BatteryMaterialPath, BatteryMaterial))
	 {
		 return false;
	 }

	 BatteryDynamicMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(WorldContextObject, BatteryMaterial, NAME_None);


	 UMaterialInstance* Ray;
	 if (!LoadMaterialInstanceFromContent(ControllerRayMaterialPath[0], Ray))
	 {
		 return false;
	 }
	 else
	 {
		 RayMaterial.Add(Ray);
	 }

	 if (ControllerRayMaterialPath.Num() > 1)
	 {
		 UMaterialInstance* Ray2;
		 if (!LoadMaterialInstanceFromContent(ControllerRayMaterialPath[1], Ray2))
		 {
			 return false;
		 }
		 else
		 {
			 RayMaterial.Add(Ray2);
		 }
	 }

	 
	 if (!LoadMaterialFromContent(TouchPointMaterialPath, TouchPointMaterial))
	 {
		 return false;
	 }
	 if (!OtherDynamicMaterialPath.IsEmpty()) 
	 {
		 UMaterial* OtherMaterial;
		 if (!LoadMaterialFromContent(OtherDynamicMaterialPath, OtherMaterial))
		 {
			 return false;
		 }
		 OtherDynamicMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(WorldContextObject, OtherMaterial, NAME_None);
	 }
	
	return true;
}

bool UPicoBlueprintFunctionLibrary::LoadControllerButtonTextures(EPicoControllerType ControllerType, TArray<FString> Pathes, FPicoControllerButtonTexture& ButtonTextures)
{
	switch (ControllerType)
	{
	case EPicoControllerType::Goblin:
		if (Pathes.Num() ==6)
		{
			if (!LoadTextureFromContent(Pathes[0], ButtonTextures.BackTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[1], ButtonTextures.HomeTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[2], ButtonTextures.NormalTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[3], ButtonTextures.TouchPadTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[4], ButtonTextures.VolumeDownTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[5], ButtonTextures.VolumeUpTexture))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case EPicoControllerType::Goblin2:
		if (Pathes.Num() == 7)
		{
			if (!LoadTextureFromContent(Pathes[0], ButtonTextures.BackTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[1], ButtonTextures.HomeTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[2], ButtonTextures.NormalTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[3], ButtonTextures.TouchPadTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[4], ButtonTextures.VolumeDownTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[5], ButtonTextures.VolumeUpTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[6], ButtonTextures.TriggerTexture))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case EPicoControllerType::Neo:
		if (Pathes.Num() == 7)
		{
			if (!LoadTextureFromContent(Pathes[0], ButtonTextures.BackTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[1], ButtonTextures.HomeTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[2], ButtonTextures.NormalTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[3], ButtonTextures.TouchPadTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[4], ButtonTextures.TriggerTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[5], ButtonTextures.VolumeDownTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[6], ButtonTextures.VolumeUpTexture))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case EPicoControllerType::Neo2:
		if (Pathes.Num() == 12)
		{
			if (!LoadTextureFromContent(Pathes[0], ButtonTextures.BackTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[1], ButtonTextures.ButtonATexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[2], ButtonTextures.ButtonBTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[3], ButtonTextures.ButtonXTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[4], ButtonTextures.ButtonYTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[5], ButtonTextures.NormalTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[6], ButtonTextures.ControllerGrap))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[7], ButtonTextures.HomeTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[8], ButtonTextures.LeftControllerTag))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[9], ButtonTextures.RightControllerTag))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[10], ButtonTextures.RockerTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[11], ButtonTextures.TriggerTexture))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;
	case EPicoControllerType::Neo3:
		if (Pathes.Num() == 10)
		{
			if (!LoadTextureFromContent(Pathes[0], ButtonTextures.BackTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[1], ButtonTextures.ButtonATexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[2], ButtonTextures.ButtonBTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[3], ButtonTextures.ButtonXTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[4], ButtonTextures.ButtonYTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[5], ButtonTextures.NormalTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[6], ButtonTextures.ControllerGrap))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[7], ButtonTextures.HomeTexture))
			{
				return false;
			}
			
			if (!LoadTextureFromContent(Pathes[8], ButtonTextures.RockerTexture))
			{
				return false;
			}
			if (!LoadTextureFromContent(Pathes[9], ButtonTextures.TriggerTexture))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		break;	
	default:
		return false;
	}
	return true;
}

bool UPicoBlueprintFunctionLibrary::LoadTextureFromContent(FString Path, UTexture2D*& Texture)
{
	if (!Path.IsEmpty())
	{
		Texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *Path));
		if (Texture)
		{
			//UE_LOG(LogTemp,Log,TEXT("Load Texture [%s] Succceed"),*Path);
			return true;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Load Texture [%s] Fail"), *Path);
	return false;
}

bool UPicoBlueprintFunctionLibrary::LoadStaticMeshFromContent(FString Path, UStaticMesh*& StaticMesh)
{
	StaticMesh = nullptr;
	if (!Path.IsEmpty())
	{
		StaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL,*Path));
		if (StaticMesh)
		{
			//UE_LOG(LogTemp, Log, TEXT("Load StaticMesh [%s] Success"), *Path);
			return true;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Load StaticMesh [%s] Fail"), *Path);
	return false;
}

bool UPicoBlueprintFunctionLibrary::LoadMaterialFromContent(FString Path, UMaterial*& Material)
{
	Material = nullptr;
	if (!Path.IsEmpty())
	{
		Material = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, *Path));
		if (Material)
		{
			//UE_LOG(LogTemp, Log, TEXT("Load Material [%s] Success"), *Path);
			return true;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Load Material [%s] Fail"), *Path);
	return false;
}

bool UPicoBlueprintFunctionLibrary::LoadMaterialInstanceFromContent(FString Path, UMaterialInstance*& Material)
{
	Material = nullptr;
	if (!Path.IsEmpty())
	{
		Material = Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, *Path));
		if (Material)
		{
			//UE_LOG(LogTemp, Log, TEXT("Load UMaterialInstance [%s] Success"), *Path);
			return true;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Load UMaterialInstance [%s] Fail"), *Path);
	return false;
}

bool UPicoBlueprintFunctionLibrary::PicoLoadControllerResource(TArray<FPicoMeshData> &Meshes, FPicoControllerButtonTexture& ButtonTexture,int32 & ControllerNum)
{
	int32 bNeedLoadController = 0;
	FString JsonValue = "";
	int32 DeviceType = 0;
#if PLATFORM_ANDROID
	bNeedLoadController = PicoSDK::GetLoadControllerState();
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jmethodID id_apl_GetDeviceType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "apl_GetDeviceType", "()I", false);
	if(id_apl_GetDeviceType)
	{
		DeviceType = StaticCast<int32>(FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_apl_GetDeviceType));
	}	
#endif
	if(bNeedLoadController)
	{
#if PLATFORM_ANDROID
		JsonValue = FPicoJava::GetObjectOrArray("config.controller",(int32)PicoResUtilsType::TYPR_OBJECTARRAY);
#endif
		JsonValue =  "{\"controller\":" + JsonValue + "}";
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);
		TSharedPtr<FJsonObject> JsonObject;
		bool bFlag = FJsonSerializer::Deserialize(JsonReader, JsonObject);
		if (bFlag)
		{
			TArray<TSharedPtr<FJsonValue>> data = JsonObject->GetArrayField("controller");
			if (DeviceType>0)
			{
				TSharedPtr<FJsonValue> ControllerJson = data[DeviceType-1];
				FString ModelName = ControllerJson->AsObject()->GetStringField("model_name");
				FString BasePath = ControllerJson->AsObject()->GetStringField("base_path");
				ControllerNum = ControllerJson->AsObject()->GetIntegerField("control_num");
				FString TextureFormat =ControllerJson->AsObject()->GetStringField("tex_format");
				//BasePath = BasePath.Left(BasePath.Len()-ModelName.Len()-1);//测试使用
				FPaths::NormalizeFilename(BasePath);
				TArray<FString>TextureArray = {
					BasePath+"controller"+FString::FromInt(DeviceType)+"_idle."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_app."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_home."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_touch."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_volume_down."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_volume_up."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_trigger."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_a."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_b."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_x."+TextureFormat,
					BasePath+"controller"+FString::FromInt(DeviceType)+"_y."+TextureFormat,
                    BasePath+"controller"+FString::FromInt(DeviceType)+"_grip."+TextureFormat			
				};
				TArray<FString>ControllerArray = {};
				for(int32 i = 0;i<ControllerNum;i++)
				{
					ControllerArray.Add(BasePath+"/controller"+FString::FromInt(DeviceType)+FString::FromInt(i)+".obj");
				}
				LoadControllerMesh(ControllerArray,Meshes);
				LoadControllerTexture(TextureArray,ButtonTexture);		
			}		
		}
		return true;
	}
	return false;
}

bool UPicoBlueprintFunctionLibrary::LoadControllerMesh(TArray<FString> ControllerPathes, TArray<FPicoMeshData>& MeshesDatas)
{
	if (ControllerPathes.Num()>0)
	{
		for (FString ControllerPath:ControllerPathes)
		{
			FPicoMeshData MeshDate;
			LoadMesh(ControllerPath,MeshDate.Vertices,MeshDate.Triangles,MeshDate.Normals,MeshDate.UV,MeshDate.Name,MeshDate.Succeed);
			if (MeshDate.Succeed)
			{
				MeshesDatas.Add(MeshDate);
			}else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool UPicoBlueprintFunctionLibrary::LoadControllerTexture(TArray<FString> TexturePaths,	FPicoControllerButtonTexture& Texture)
{
	bool bSucceed = true;
	LoadTexture(TexturePaths[0],Texture.NormalTexture,bSucceed);
	
	LoadTexture(TexturePaths[1],Texture.BackTexture,bSucceed);
	
	LoadTexture(TexturePaths[2],Texture.HomeTexture,bSucceed);
	
	LoadTexture(TexturePaths[3],Texture.TouchPadTexture,bSucceed);
	
	LoadTexture(TexturePaths[4],Texture.VolumeDownTexture,bSucceed);
	
	LoadTexture(TexturePaths[5],Texture.VolumeUpTexture,bSucceed);
	
	LoadTexture(TexturePaths[6],Texture.TriggerTexture,bSucceed);
	
	LoadTexture(TexturePaths[7],Texture.ButtonATexture,bSucceed);
	
	LoadTexture(TexturePaths[8],Texture.ButtonBTexture,bSucceed);

	LoadTexture(TexturePaths[9],Texture.ButtonXTexture,bSucceed);

	LoadTexture(TexturePaths[10],Texture.ButtonYTexture,bSucceed);

	LoadTexture(TexturePaths[11],Texture.ControllerGrap,bSucceed);

	return true;
}

#pragma endregion LoadObject


void UPicoBlueprintFunctionLibrary::PicoPaymentSetCallbackDelegates(
	FPicoLogInOutCallbackDelegate OnPicoLogInOutCallback,
	FPicoGetUserInfoCallbackDelegate OnPicoGetUserInfoCallback,
	FPicoPayOrderCallbackDelegate OnPicoPayOrderCallback,
	FPicoQueryOrderCallbackDelegate OnPicoQueryOrderCallback,
	FPicoPaymentExceptionCallbackDelegate OnPicoPaymentExceptionCallback
)
{
#if PLATFORM_ANDROID
	PicoLogInOutCallback = OnPicoLogInOutCallback;
	PicoGetUserInfoCallback = OnPicoGetUserInfoCallback;
	PicoPayOrderCallback = OnPicoPayOrderCallback;
	PicoQueryOrderCallback = OnPicoQueryOrderCallback;
	PicoPaymentExceptionCallback = OnPicoPaymentExceptionCallback;
	
#endif
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoLogInOutCallback(JNIEnv * env, jclass clazz, jboolean isSuccess, jstring reason)
{
	bool _isSuccess = (bool)isSuccess;
	FString _reason;
	if (reason != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(reason, 0);
		_reason = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(reason, JavaChars);
	}

	if (UPicoBlueprintFunctionLibrary::PicoLogInOutCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoLogInOutCallback.Execute(_isSuccess,_reason);
	}
}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoGetUserInfoCompleteCallback(JNIEnv * env, jclass clazz, jstring info)
{
	FString _info;
	if (info != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(info, 0);
		_info = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(info, JavaChars);
	}

	if (UPicoBlueprintFunctionLibrary::PicoGetUserInfoCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoGetUserInfoCallback.Execute(_info);
	}

}
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoPaymentExceptionCallback(JNIEnv * env, jclass clazz, jstring exception)
{
	FString _exception;
	if (exception != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(exception, 0);
		_exception = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(exception, JavaChars);
	}

	if (UPicoBlueprintFunctionLibrary::PicoGetUserInfoCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoGetUserInfoCallback.Execute(_exception);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoPayOrderCallback(JNIEnv * env, jclass clazz, jstring code, jstring msg)
{
	FString _code , _msg;
	if (code != NULL && msg != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(code, 0);
		_code = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(code, JavaChars);

		JavaChars = env->GetStringUTFChars(msg, 0);
		_msg = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(msg, JavaChars);
	}

	if (UPicoBlueprintFunctionLibrary::PicoPayOrderCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoPayOrderCallback.Execute(_code,_msg);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoQueryOrdersCallback(JNIEnv * env, jclass clazz, jstring code, jstring msg)
{
	FString _code, _msg;
	if (code != NULL && msg != NULL)
	{
		const char* JavaChars = env->GetStringUTFChars(code, 0);
		_code = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(code, JavaChars);

		JavaChars = env->GetStringUTFChars(msg, 0);
		_msg = FString(UTF8_TO_TCHAR(JavaChars));
		env->ReleaseStringUTFChars(msg, JavaChars);
	}

	if (UPicoBlueprintFunctionLibrary::PicoQueryOrderCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoQueryOrderCallback.Execute(_code, _msg);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoEntitlementVerifyCallback(JNIEnv * env, jclass clazz, int32 code)
{
	PicoSDK::GVerifyCallbackCode = code;
	if (UPicoBlueprintFunctionLibrary::PicoEntitlementVerifyCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoEntitlementVerifyCallback.Execute(code);
	}
}

extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_nativePicoIPDChanged(JNIEnv * env, jclass clazz, float ipd)
{
	PicoSDK::Render::CurrentIPD = ipd;
	if (UPicoBlueprintFunctionLibrary::PicoIPDChangedCallback.IsBound())
	{
		UPicoBlueprintFunctionLibrary::PicoIPDChangedCallback.Execute(ipd);
	}
}
#endif