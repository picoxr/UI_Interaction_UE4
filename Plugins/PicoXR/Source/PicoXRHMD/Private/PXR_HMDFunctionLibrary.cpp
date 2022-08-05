//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDFunctionLibrary.h"
#include <list>
#include "PXR_HMD.h"
#include "PXR_Log.h"
#include "PXR_Settings.h"
#include "PXR_BoundarySystem.h"

FPicoXRIPDChangedDelegate UPicoXRHMDFunctionLibrary::PicoXRIPDChangedCallback;
FPicoXRHMD* UPicoXRHMDFunctionLibrary::PicoXRHMD = nullptr;
UPicoXRHMDFunctionLibrary::UPicoXRHMDFunctionLibrary()
{
}

FPicoXRHMD* UPicoXRHMDFunctionLibrary::GetPicoXRHMD()
{
    if (!PicoXRHMD)
    {
        static FName SystemName(TEXT("PicoXRHMD"));
        if (GEngine)
        {
            if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
            {
                PicoXRHMD =  static_cast<FPicoXRHMD*>(GEngine->XRSystem.Get());  
            }
            if (PicoXRHMD == nullptr)
            {
                PXR_LOGI(PxrUnreal, "GetPicoXRHMD Failed!");
            }
        } 
    }
    return PicoXRHMD;
}

FQuat UPicoXRHMDFunctionLibrary::PXR_GetCurrentOrientation()
{
    FVector Position;
    FQuat Orientation;
    GetPicoXRHMD()->GetCurrentPose(IXRTrackingSystem::HMDDeviceId,Orientation,Position);
    return  Orientation;
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetCurrentPosition()
{
    FVector Position;
    FQuat Orientation;
    GetPicoXRHMD()->GetCurrentPose(IXRTrackingSystem::HMDDeviceId,Orientation,Position);
    return  Position;
}

bool UPicoXRHMDFunctionLibrary::PXR_DoesSupportPositionalTracking()
{  
    return  GetPicoXRHMD()->DoesSupportPositionalTracking();
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetAngularVelocity()
{
    FVector AngularVelocity;
    GetPicoXRHMD()->UPxr_GetAngularVelocity(AngularVelocity);
    return AngularVelocity;
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetAcceleration()
{
    FVector Acceleration;
    GetPicoXRHMD()->UPxr_GetAcceleration(Acceleration);
    return Acceleration;
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetVelocity()
{
    FVector Velocity;
    GetPicoXRHMD()->UPxr_GetVelocity(Velocity);
    return Velocity;
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetAngularAcceleration()
{
    FVector AngularAcceleration;
    GetPicoXRHMD()->UPxr_GetAngularAcceleration(AngularAcceleration);
    return AngularAcceleration;
}

EHMDWornState::Type UPicoXRHMDFunctionLibrary::PXR_GetHMDWornState()
{  
    return GetPicoXRHMD()->GetHMDWornState();
}

bool UPicoXRHMDFunctionLibrary::PXR_ResetHMDSensor()
{
    GetPicoXRHMD()->ResetOrientationAndPosition(0);
    return true;
}

bool UPicoXRHMDFunctionLibrary::PXR_GetFieldOfView(float& HFOVInDegrees, float& VFOVInDegrees)
{
    GetPicoXRHMD()->GetFieldOfView(HFOVInDegrees,VFOVInDegrees);
    return true;
}

float UPicoXRHMDFunctionLibrary::PXR_GetIPD()
{
    return GetPicoXRHMD()->UPxr_GetIPD();
}

void UPicoXRHMDFunctionLibrary::PXR_IPDChangedDelegates(FPicoXRIPDChangedDelegate OnPicoXRIPDChanged)
{
#if PLATFORM_ANDROID
	PicoXRIPDChangedCallback = OnPicoXRIPDChanged;
#endif
}

FString UPicoXRHMDFunctionLibrary::PXR_GetDeviceModel()
{
    return GetPicoXRHMD()->UPxr_GetDeviceModel();
}

float UPicoXRHMDFunctionLibrary::PXR_GetCurrentDisplayFrequency()
{
    float frequency = 1.0f;
#if PLATFORM_ANDROID
    Pxr_GetConfigFloat(PxrConfigType::PXR_DISPLAY_REFRESH_RATE, &frequency);
#endif
    return  frequency;
}

void UPicoXRHMDFunctionLibrary::PXR_SetCPUAndGPULevels(int32 CPULevel, int32 GPULevel)
{
#if PLATFORM_ANDROID
    Pxr_SetPerformanceLevels(PxrPerfSettings::PXR_PERF_SETTINGS_CPU,CPULevel);
    Pxr_SetPerformanceLevels(PxrPerfSettings::PXR_PERF_SETTINGS_GPU,GPULevel);
#endif
}

void UPicoXRHMDFunctionLibrary::PXR_GetCPUAndGPULevels(int32& CPULevel, int32& GPULevel)
{
#if PLATFORM_ANDROID
    int32 cpuLevel, gpuLevel = -1;
    Pxr_GetPerformanceLevels(PXR_PERF_SETTINGS_CPU, &cpuLevel);
    Pxr_GetPerformanceLevels(PXR_PERF_SETTINGS_GPU, &gpuLevel);

    CPULevel = cpuLevel;
    GPULevel = gpuLevel;
#endif
}

float UPicoXRHMDFunctionLibrary::PXR_GetSystemDisplayFrequency()
{
	float frequency = 0.f;
#if PLATFORM_ANDROID
	Pxr_GetConfigFloat(PxrConfigType::PXR_GET_DISPLAY_RATE, &frequency);
#endif
	return  frequency;
}

void UPicoXRHMDFunctionLibrary::PXR_SetSystemDisplayFrequency(float Rate)
{
#if PLATFORM_ANDROID
    Pxr_SetDisplayRefreshRate(Rate);
#endif
}

void UPicoXRHMDFunctionLibrary::PXR_SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
{
#if PLATFORM_ANDROID
    GetPicoXRHMD()->UPxr_SetColorScaleAndOffset(ColorScale,ColorOffset,bApplyToAllLayers);
#endif
}

bool UPicoXRHMDFunctionLibrary::GetFocusState()
{
    const FPicoXRHMD* const picoXRHMD = GetPicoXRHMD();
    if (picoXRHMD != nullptr && picoXRHMD->IsHMDEnabled())
    {
        return picoXRHMD->inputFocusState;
    }
    return false;
}

UPicoXRBoundarySystem* UPicoXRHMDFunctionLibrary::GetBoundarySystemInterface()
{
    return UPicoXRBoundarySystem::GetInstance();
}

bool UPicoXRHMDFunctionLibrary::PXR_GetBoundaryConfigured()
{
    return GetBoundarySystemInterface()->UPxr_GetConfigured();
}

bool UPicoXRHMDFunctionLibrary::PXR_GetBoundaryEnabled()
{
    return GetBoundarySystemInterface()->UPxr_GetEnabled();
}

void UPicoXRHMDFunctionLibrary::PXR_SetBoundaryVisible(bool NewVisible)
{
    GetBoundarySystemInterface()->UPxr_SetVisible(NewVisible);
}

bool UPicoXRHMDFunctionLibrary::PXR_GetBoundaryVisible()
{
    return GetBoundarySystemInterface()->UPxr_GetVisible();
}

bool UPicoXRHMDFunctionLibrary::PXR_BoundaryTestNode(EPicoXRNodeType DeviceType,
    EPicoXRBoundaryType BoundaryType, bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint,
    FVector& ClosestPointNormal)
{
    return GetBoundarySystemInterface()->UPxr_TestNode(static_cast<int32>(DeviceType),BoundaryType == EPicoXRBoundaryType::PlayArea,IsTriggering,ClosestDistance,ClosestPoint,ClosestPointNormal);
}

bool UPicoXRHMDFunctionLibrary::PXR_BoundaryTestPoint(FVector Point, EPicoXRBoundaryType BoundaryType,
    bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint, FVector& ClosestPointNormal)
{
    return GetBoundarySystemInterface()->UPxr_TestPoint(Point,BoundaryType == EPicoXRBoundaryType::PlayArea,IsTriggering,ClosestDistance,ClosestPoint,ClosestPointNormal);
}

TArray<FVector> UPicoXRHMDFunctionLibrary::PXR_GetBoundaryGeometry(EPicoXRBoundaryType BoundaryType)
{
   return GetBoundarySystemInterface()->UPxr_GetGeometry(BoundaryType == EPicoXRBoundaryType::PlayArea);
}

FVector UPicoXRHMDFunctionLibrary::PXR_GetBoundaryDimensions(EPicoXRBoundaryType BoundaryType)
{
    return GetBoundarySystemInterface()->UPxr_GetDimensions(BoundaryType == EPicoXRBoundaryType::PlayArea);
}

bool UPicoXRHMDFunctionLibrary::PXR_GetBoundarySeeThroughData(EPicoXRCameraType CameraType, UTexture2D*& CameraImage)
{
    return GetBoundarySystemInterface()->UPxr_GetSeeThroughData(static_cast<int32>(CameraType),CameraImage);
}

bool UPicoXRHMDFunctionLibrary::PXR_SetBoundaryCameraImageSize(FIntPoint ImageSize)
{
    return GetBoundarySystemInterface()->UPxr_SetCameraImageSize(ImageSize);
}

int UPicoXRHMDFunctionLibrary::PXR_SetSeeThroughBackground(bool Value)
{
    return GetBoundarySystemInterface()->UPxr_SetSeeThroughBackground(Value);
}

void UPicoXRHMDFunctionLibrary::PXR_GetDialogState(EPicoXRBoundaryState& State)
{
    int result = 1;
#if PLATFORM_ANDROID
    result=Pxr_GetDialogState();
    switch (result)
    {
    case -2:
        State = EPicoXRBoundaryState::LostNoDialog;
        break;
	case -1:
        State = EPicoXRBoundaryState::NothingDialog;
		break;
    default:
        State = EPicoXRBoundaryState((uint8)result);
        break;
     }
#endif
}

void UPicoXRHMDFunctionLibrary::PXR_EnableFoveation(bool Enable)
{
#if PLATFORM_ANDROID
    GetPicoXRHMD()->UPxr_EnableFoveation(Enable);
#endif
}

bool UPicoXRHMDFunctionLibrary::PXR_GetFoveationLevel(EPicoXRFoveationLevel &FoveationLevel)
{
    int32 Foveation = -1;
    if (GetMutableDefault<UPicoXRSettings>()->bEnableFoveation)
    {
#if PLATFORM_ANDROID
    Foveation = (int32)Pxr_GetFoveationLevel();
#endif
    switch (Foveation)
      {
    case 0:
        FoveationLevel = EPicoXRFoveationLevel::Low;
        return true;
    case 1:
        FoveationLevel = EPicoXRFoveationLevel::Medium;
        return true;
    case 2:
        FoveationLevel = EPicoXRFoveationLevel::High;
        return true;
    case 3:
        FoveationLevel = EPicoXRFoveationLevel::TopHigh;
        return true;
     default:
         return false;
         break;
      }
    }
    else
    {
        PXR_LOGI(PxrUnreal, "Foveation disabled!");
        return false;
    }
}

bool UPicoXRHMDFunctionLibrary::PXR_SetFoveationLevel(EPicoXRFoveationLevel InLevel)
{ 
    if (GetMutableDefault<UPicoXRSettings>()->bEnableFoveation)
    {
#if PLATFORM_ANDROID
		PxrFoveationLevel Level = static_cast<PxrFoveationLevel>(InLevel);
		if (Pxr_SetFoveationLevel(Level) == 0)
		{
			return true;
		}
#endif
        return false;
    }
    else 
	{
		PXR_LOGI(PxrUnreal, "Foveation disabled!");
        return false;
    }
}

bool UPicoXRHMDFunctionLibrary::PXR_SetFoveationParameter(FVector2D FoveationGainValue, float FoveationAreaValue, float FoveationMinimumValue)
{
#if PLATFORM_ANDROID
    if (GetMutableDefault<UPicoXRSettings>()->bEnableFoveation)
    {
        PxrFoveationParams FoveationParams;
        FoveationParams.foveationGainX = FoveationGainValue.X;
        FoveationParams.foveationGainY = FoveationGainValue.Y;
        FoveationParams.foveationArea = FoveationAreaValue;
        FoveationParams.foveationMinimum = FoveationMinimumValue;
        if (Pxr_SetFoveationParams(FoveationParams)==0)
        {
			return true;
        }
        return false;
    }
    else
	{
		PXR_LOGI(PxrUnreal, "Foveation disabled!");
		return false;
    }
#endif
    return false;
}

bool UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingGazeRay(FVector& Origin, FVector& Direction)
{
    bool ReturnValue = false;
    if (GetMutableDefault<UPicoXRSettings>()->bEnableEyeTracking )
    { 
        const TSharedPtr<FPicoXREyeTracker> EyeTracker =GetPicoXRHMD()->UPxr_GetEyeTracker();
        FPicoXREyeTrackingGazeRay EyeTrackingGazeRay;
        ReturnValue = EyeTracker->GetEyeTrackingGazeRay(EyeTrackingGazeRay);
        Origin = EyeTrackingGazeRay.Origin;
        Direction = EyeTrackingGazeRay.Direction;
    }
    return ReturnValue;
}

FPicoXREyeTrackingData UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingData()
{
    FPicoXREyeTrackingData EyeTrackingData ;
    if (GetMutableDefault<UPicoXRSettings>()->bEnableEyeTracking )
    {
        const TSharedPtr<FPicoXREyeTracker> EyeTracker =GetPicoXRHMD()->UPxr_GetEyeTracker();
        EyeTracker->UPxr_GetEyeTrackingData(EyeTrackingData);
    }
    return EyeTrackingData;
}

void UPicoXRHMDFunctionLibrary::PXR_EnableEyeTrackingMarker(bool Enable)
{
#if PLATFORM_ANDROID
	UPicoXRSettings *picoSettings = GetMutableDefault<UPicoXRSettings>();
	if (picoSettings)
	{
		picoSettings->bEnableEyeTrackingMarker = Enable;
	}
#endif
}

bool UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingPos(FVector &EyeTrackingPos)
{
#if PLATFORM_ANDROID
	if (GetMutableDefault<UPicoXRSettings>()->bEnableEyeTracking)
	{
		const TSharedPtr<FPicoXREyeTracker> eyeTracker = GetPicoXRHMD()->UPxr_GetEyeTracker();
		if (eyeTracker)
		{
			if (eyeTracker->GetEyeDirectionToFoveationRendering(EyeTrackingPos))
				return true;
		}
	}
#endif
	return false;
}

bool UPicoXRHMDFunctionLibrary::PXR_EnableFaceTracking(bool enable)
{
#if PLATFORM_ANDROID
	const TSharedPtr<FPicoXREyeTracker> eyeTracker = GetPicoXRHMD()->UPxr_GetEyeTracker();
	if (eyeTracker)
	{
		if (eyeTracker->OpenEyeTracking(enable))
            return true;
	}
#endif
	return false;
}

bool UPicoXRHMDFunctionLibrary::PXR_AddSplashScreen(UTexture2D* Texture, FVector TranslationInMeters,
    FRotator Rotation, FVector2D SizeInMeters, bool bClearBeforeAdd)
{
		FPicoXRSplashPtr Splash = GetPicoXRHMD()->GetSplash();
		if (Splash)
		{
			if (bClearBeforeAdd)
			{
				Splash->ClearSplashes();
			}
			FPicoSplashDesc Desc;
            if (Texture !=nullptr)
            {
                Desc.LoadingTexture = Texture;
                Desc.QuadSizeInMeters = SizeInMeters;
                Desc.TransformInMeters = FTransform(Rotation, TranslationInMeters);
                Desc.TexturePath = Texture->GetPathName();
                Splash->AddSplash(Desc);
                return true;
            }
		    else
		    {
		        UE_LOG(LogHMD, Log, TEXT("Pxr_UE PXR_AddSplashScreen  the Texture is null"));
		        return false;
		    }
		}
	return false;
}

void UPicoXRHMDFunctionLibrary::PXR_ClearLoadingSplashScreens()
{
	FPicoXRSplashPtr Splash = GetPicoXRHMD()->GetSplash();
	if (Splash)
	{
		Splash->ClearSplashes();
	}
}

void UPicoXRHMDFunctionLibrary::PXR_EnableAutoShowSplashScreen(bool Enable)
{
	FPicoXRSplashPtr Splash = GetPicoXRHMD()->GetSplash();
	if (Splash)
	{
		Splash->AutoShow(Enable);
	}
}

int UPicoXRHMDFunctionLibrary::PXR_SetSensorLostCustomMode(bool Value)
{
#if PLATFORM_ANDROID
    return Pxr_SetSensorLostCustomMode(Value);
#endif
    return 0;
}

int UPicoXRHMDFunctionLibrary::PXR_SetSensorLostCMST(bool Value)
{
#if PLATFORM_ANDROID
    return Pxr_SetSensorLostCMST(Value);
#endif
    return 0;
}

void UPicoXRHMDFunctionLibrary::PXR_GetVFov(float & VFOVInDegrees)
{
	float drop;
	GetPicoXRHMD()->GetFieldOfView(drop, VFOVInDegrees);
}

void UPicoXRHMDFunctionLibrary::PXR_GetHFov(float & HFOVInDegrees)
{
	float drop;
	GetPicoXRHMD()->GetFieldOfView(HFOVInDegrees, drop);
}

bool UPicoXRHMDFunctionLibrary::PXR_GetDisplayFrequenciesAvailable(int& Count, TArray<float>& AvailableRates)
{
    bool result = false;
#if PLATFORM_ANDROID
    float* temp = nullptr;
    uint32_t* number = (uint32_t*)(&Count);
    if (!Pxr_GetDisplayRefreshRatesAvailable(number, &temp))
    {
        if (!Count) { return result; }
        AvailableRates.Init(0, Count);
        FMemory::Memcpy(AvailableRates.GetData(), temp, sizeof(float) * Count);
        result = true;
    }

#endif
    return result;
}

bool UPicoXRHMDFunctionLibrary::PXR_SetExtraLatencyMode(int Mode)
{
#if PLATFORM_ANDROID
    return Pxr_SetExtraLatencyMode(Mode);
#endif
    return false;
}

UPicoXREventManager* UPicoXRHMDFunctionLibrary::PXR_GetEventManager()
{
    return UPicoXREventManager::GetInstance();
}

void UPicoXRHMDFunctionLibrary::PXR_GetPredictedMainSensorState(FPxrSensorState& sensorState, int& sensorFrameIndex) {
#if PLATFORM_ANDROID

    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000201) {
        double predictTimeMs = 0.0;
        Pxr_GetPredictedDisplayTime(&predictTimeMs);
        PxrSensorState2 sensorState2;
        Pxr_GetPredictedMainSensorState2(predictTimeMs, &sensorState2, &sensorFrameIndex);
        sensorState.status = sensorState2.status;
        sensorState.poseQuat.X = sensorState2.pose.orientation.x;
        sensorState.poseQuat.Y = sensorState2.pose.orientation.y;
        sensorState.poseQuat.Z = sensorState2.pose.orientation.z;
        sensorState.poseQuat.W = sensorState2.pose.orientation.w;
        sensorState.poseVector.X = sensorState2.pose.position.x;
        sensorState.poseVector.Y = sensorState2.pose.position.y;
        sensorState.poseVector.Z = sensorState2.pose.position.z;
        sensorState.globalPoseQuat.X = sensorState2.globalPose.orientation.x;
        sensorState.globalPoseQuat.Y = sensorState2.globalPose.orientation.y;
        sensorState.globalPoseQuat.Z = sensorState2.globalPose.orientation.z;
        sensorState.globalPoseQuat.W = sensorState2.globalPose.orientation.w;
        sensorState.globalPoseVector.X = sensorState2.globalPose.position.x;
        sensorState.globalPoseVector.Y = sensorState2.globalPose.position.y;
        sensorState.globalPoseVector.Z = sensorState2.globalPose.position.z;
        sensorState.angularVelocity.X = sensorState2.angularVelocity.x;
        sensorState.angularVelocity.Y = sensorState2.angularVelocity.y;
        sensorState.angularVelocity.Z = sensorState2.angularVelocity.z;
        sensorState.linearVelocity.X = sensorState2.linearVelocity.x;
        sensorState.linearVelocity.Y = sensorState2.linearVelocity.y;
        sensorState.linearVelocity.Z = sensorState2.linearVelocity.z;
        sensorState.angularAcceleration.X = sensorState2.angularAcceleration.x;
        sensorState.angularAcceleration.Y = sensorState2.angularAcceleration.y;
        sensorState.angularAcceleration.Z = sensorState2.angularAcceleration.z;
        sensorState.linearAcceleration.X = sensorState2.linearAcceleration.x;
        sensorState.linearAcceleration.Y = sensorState2.linearAcceleration.y;
        sensorState.linearAcceleration.Z = sensorState2.linearAcceleration.z;
        sensorState.poseTimeStampNs = sensorState2.poseTimeStampNs;
    }
#endif
}

void UPicoXRHMDFunctionLibrary::PXR_SetLargeSpaceEnable(bool bEnable,int ext)
{
    UPicoXRSettings *Settings=GetMutableDefault<UPicoXRSettings>();
    if (Settings && Settings->bUseAdvanceInterface)
	{
		if (GetPicoXRHMD())
		{
			GetPicoXRHMD()->bUserEnableLargeSpace = bEnable;
#if PLATFORM_ANDROID
			if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
			{
				static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetSwitchLargeSpaceStatus", "(I)V", false);
				FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, ext);
            }
#endif
        }
    }
    else
    {
		PXR_LOGW(PxrUnreal, "Set large space enable faild,make sure the bUseAdvanceInterface property has checked on Proejctings->Plugins->PicoXR Settings!");
    }
}
