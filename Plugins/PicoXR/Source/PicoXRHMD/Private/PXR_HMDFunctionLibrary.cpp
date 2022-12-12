//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_HMDFunctionLibrary.h"
#include <list>
#include "PXR_HMD.h"
#include "PXR_Log.h"
#include "PXR_Settings.h"
#include "PXR_BoundarySystem.h"

FPICOXRIPDChangedDelegate UPICOXRHMDFunctionLibrary::PICOXRIPDChangedCallback;
FPICOXRHMD* UPICOXRHMDFunctionLibrary::PICOXRHMD = nullptr;
UPICOXRHMDFunctionLibrary::UPICOXRHMDFunctionLibrary()
{
}

FPICOXRHMD* UPICOXRHMDFunctionLibrary::GetPICOXRHMD()
{
    if (!PICOXRHMD)
    {
        static FName SystemName(TEXT("PICOXRHMD"));
        if (GEngine)
        {
            if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
            {
                PICOXRHMD =  static_cast<FPICOXRHMD*>(GEngine->XRSystem.Get());  
            }
            if (PICOXRHMD == nullptr)
            {
                PXR_LOGI(PxrUnreal, "GetPICOXRHMD Failed!");
            }
        } 
    }
    return PICOXRHMD;
}

FQuat UPICOXRHMDFunctionLibrary::PXR_GetCurrentOrientation()
{
    FVector Position;
    FQuat Orientation;
    GetPICOXRHMD()->GetCurrentPose(IXRTrackingSystem::HMDDeviceId,Orientation,Position);
    return  Orientation;
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetCurrentPosition()
{
    FVector Position;
    FQuat Orientation;
    GetPICOXRHMD()->GetCurrentPose(IXRTrackingSystem::HMDDeviceId,Orientation,Position);
    return  Position;
}

bool UPICOXRHMDFunctionLibrary::PXR_DoesSupportPositionalTracking()
{  
    return  GetPICOXRHMD()->DoesSupportPositionalTracking();
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetAngularVelocity()
{
    FVector AngularVelocity;
    GetPICOXRHMD()->UPxr_GetAngularVelocity(AngularVelocity);
    return AngularVelocity;
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetAcceleration()
{
    FVector Acceleration;
    GetPICOXRHMD()->UPxr_GetAcceleration(Acceleration);
    return Acceleration;
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetVelocity()
{
    FVector Velocity;
    GetPICOXRHMD()->UPxr_GetVelocity(Velocity);
    return Velocity;
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetAngularAcceleration()
{
    FVector AngularAcceleration;
    GetPICOXRHMD()->UPxr_GetAngularAcceleration(AngularAcceleration);
    return AngularAcceleration;
}

EHMDWornState::Type UPICOXRHMDFunctionLibrary::PXR_GetHMDWornState()
{  
    return GetPICOXRHMD()->GetHMDWornState();
}

bool UPICOXRHMDFunctionLibrary::PXR_ResetHMDSensor()
{
    GetPICOXRHMD()->ResetOrientationAndPosition(0);
    return true;
}

bool UPICOXRHMDFunctionLibrary::PXR_GetFieldOfView(float& HFOVInDegrees, float& VFOVInDegrees)
{
    GetPICOXRHMD()->GetFieldOfView(HFOVInDegrees,VFOVInDegrees);
    return true;
}

float UPICOXRHMDFunctionLibrary::PXR_GetIPD()
{
    return GetPICOXRHMD()->UPxr_GetIPD();
}

void UPICOXRHMDFunctionLibrary::PXR_IPDChangedDelegates(FPICOXRIPDChangedDelegate OnPICOXRIPDChanged)
{
#if PLATFORM_ANDROID
	PICOXRIPDChangedCallback = OnPICOXRIPDChanged;
#endif
}

FString UPICOXRHMDFunctionLibrary::PXR_GetDeviceModel()
{
    return GetPICOXRHMD()->UPxr_GetDeviceModel();
}

float UPICOXRHMDFunctionLibrary::PXR_GetCurrentDisplayFrequency()
{
    float frequency = 1.0f;
#if PLATFORM_ANDROID
    Pxr_GetConfigFloat(PxrConfigType::PXR_DISPLAY_REFRESH_RATE, &frequency);
#endif
    return  frequency;
}

void UPICOXRHMDFunctionLibrary::PXR_SetCPUAndGPULevels(int32 CPULevel, int32 GPULevel)
{
#if PLATFORM_ANDROID
    Pxr_SetPerformanceLevels(PxrPerfSettings::PXR_PERF_SETTINGS_CPU,CPULevel);
    Pxr_SetPerformanceLevels(PxrPerfSettings::PXR_PERF_SETTINGS_GPU,GPULevel);
#endif
}

void UPICOXRHMDFunctionLibrary::PXR_GetCPUAndGPULevels(int32& CPULevel, int32& GPULevel)
{
#if PLATFORM_ANDROID
    int32 cpuLevel, gpuLevel = -1;
    Pxr_GetPerformanceLevels(PXR_PERF_SETTINGS_CPU, &cpuLevel);
    Pxr_GetPerformanceLevels(PXR_PERF_SETTINGS_GPU, &gpuLevel);

    CPULevel = cpuLevel;
    GPULevel = gpuLevel;
#endif
}

float UPICOXRHMDFunctionLibrary::PXR_GetSystemDisplayFrequency()
{
	float frequency = 0.f;
#if PLATFORM_ANDROID
	Pxr_GetConfigFloat(PxrConfigType::PXR_GET_DISPLAY_RATE, &frequency);
#endif
	return  frequency;
}

void UPICOXRHMDFunctionLibrary::PXR_SetSystemDisplayFrequency(float Rate)
{
#if PLATFORM_ANDROID
    Pxr_SetDisplayRefreshRate(Rate);
#endif
}

void UPICOXRHMDFunctionLibrary::PXR_SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
{
#if PLATFORM_ANDROID
    GetPICOXRHMD()->UPxr_SetColorScaleAndOffset(ColorScale,ColorOffset,bApplyToAllLayers);
#endif
}

bool UPICOXRHMDFunctionLibrary::GetFocusState()
{
    const FPICOXRHMD* const PICOXRHMDInstance = GetPICOXRHMD();
    if (PICOXRHMDInstance != nullptr && PICOXRHMDInstance->IsHMDEnabled())
    {
        return PICOXRHMDInstance->inputFocusState;
    }
    return false;
}

UPICOXRBoundarySystem* UPICOXRHMDFunctionLibrary::GetBoundarySystemInterface()
{
    return UPICOXRBoundarySystem::GetInstance();
}

bool UPICOXRHMDFunctionLibrary::PXR_GetBoundaryConfigured()
{
    return GetBoundarySystemInterface()->UPxr_GetConfigured();
}

bool UPICOXRHMDFunctionLibrary::PXR_GetBoundaryEnabled()
{
    return GetBoundarySystemInterface()->UPxr_GetEnabled();
}

void UPICOXRHMDFunctionLibrary::PXR_SetBoundaryVisible(bool NewVisible)
{
    GetBoundarySystemInterface()->UPxr_SetVisible(NewVisible);
}

bool UPICOXRHMDFunctionLibrary::PXR_GetBoundaryVisible()
{
    return GetBoundarySystemInterface()->UPxr_GetVisible();
}

bool UPICOXRHMDFunctionLibrary::PXR_BoundaryTestNode(EPICOXRNodeType DeviceType,
    EPICOXRBoundaryType BoundaryType, bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint,
    FVector& ClosestPointNormal)
{
    return GetBoundarySystemInterface()->UPxr_TestNode(static_cast<int32>(DeviceType),BoundaryType == EPICOXRBoundaryType::PlayArea,IsTriggering,ClosestDistance,ClosestPoint,ClosestPointNormal);
}

bool UPICOXRHMDFunctionLibrary::PXR_BoundaryTestPoint(FVector Point, EPICOXRBoundaryType BoundaryType,
    bool& IsTriggering, float& ClosestDistance, FVector& ClosestPoint, FVector& ClosestPointNormal)
{
    return GetBoundarySystemInterface()->UPxr_TestPoint(Point,BoundaryType == EPICOXRBoundaryType::PlayArea,IsTriggering,ClosestDistance,ClosestPoint,ClosestPointNormal);
}

TArray<FVector> UPICOXRHMDFunctionLibrary::PXR_GetBoundaryGeometry(EPICOXRBoundaryType BoundaryType)
{
   return GetBoundarySystemInterface()->UPxr_GetGeometry(BoundaryType == EPICOXRBoundaryType::PlayArea);
}

FVector UPICOXRHMDFunctionLibrary::PXR_GetBoundaryDimensions(EPICOXRBoundaryType BoundaryType)
{
    return GetBoundarySystemInterface()->UPxr_GetDimensions(BoundaryType == EPICOXRBoundaryType::PlayArea);
}

bool UPICOXRHMDFunctionLibrary::PXR_GetBoundarySeeThroughData(EPICOXRCameraType CameraType, UTexture2D*& CameraImage)
{
    return GetBoundarySystemInterface()->UPxr_GetSeeThroughData(static_cast<int32>(CameraType),CameraImage);
}

bool UPICOXRHMDFunctionLibrary::PXR_SetBoundaryCameraImageSize(FIntPoint ImageSize)
{
    return GetBoundarySystemInterface()->UPxr_SetCameraImageSize(ImageSize);
}

int UPICOXRHMDFunctionLibrary::PXR_SetSeeThroughBackground(bool Value)
{
    return GetBoundarySystemInterface()->UPxr_SetSeeThroughBackground(Value);
}

void UPICOXRHMDFunctionLibrary::PXR_GetDialogState(EPICOXRBoundaryState& State)
{
    int result = 1;
#if PLATFORM_ANDROID
    result=Pxr_GetDialogState();
    switch (result)
    {
    case -2:
        State = EPICOXRBoundaryState::LostNoDialog;
        break;
	case -1:
        State = EPICOXRBoundaryState::NothingDialog;
		break;
    default:
        State = EPICOXRBoundaryState((uint8)result);
        break;
     }
#endif
}

void UPICOXRHMDFunctionLibrary::PXR_EnableFoveation(bool Enable)
{
#if PLATFORM_ANDROID
    GetPICOXRHMD()->UPxr_EnableFoveation(Enable);
#endif
}

bool UPICOXRHMDFunctionLibrary::PXR_GetFoveationLevel(EPICOXRFoveationLevel &FoveationLevel)
{
    int32 Foveation = -1;
    if (GetMutableDefault<UPICOXRSettings>()->bEnableFoveation)
    {
#if PLATFORM_ANDROID
    Foveation = (int32)Pxr_GetFoveationLevel();
#endif
    switch (Foveation)
      {
    case 0:
        FoveationLevel = EPICOXRFoveationLevel::Low;
        return true;
    case 1:
        FoveationLevel = EPICOXRFoveationLevel::Medium;
        return true;
    case 2:
        FoveationLevel = EPICOXRFoveationLevel::High;
        return true;
    case 3:
        FoveationLevel = EPICOXRFoveationLevel::TopHigh;
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

bool UPICOXRHMDFunctionLibrary::PXR_SetFoveationLevel(EPICOXRFoveationLevel InLevel)
{ 
    if (GetMutableDefault<UPICOXRSettings>()->bEnableFoveation)
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

bool UPICOXRHMDFunctionLibrary::PXR_SetFoveationParameter(FVector2D FoveationGainValue, float FoveationAreaValue, float FoveationMinimumValue)
{
#if PLATFORM_ANDROID
    if (GetMutableDefault<UPICOXRSettings>()->bEnableFoveation)
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

bool UPICOXRHMDFunctionLibrary::PXR_GetEyeTrackingGazeRay(FVector& Origin, FVector& Direction)
{
    bool ReturnValue = false;
    if (GetMutableDefault<UPICOXRSettings>()->bEnableEyeTracking )
    { 
        const TSharedPtr<FPICOXREyeTracker> EyeTracker =GetPICOXRHMD()->UPxr_GetEyeTracker();
        FPICOXREyeTrackingGazeRay EyeTrackingGazeRay;
        ReturnValue = EyeTracker->GetEyeTrackingGazeRay(EyeTrackingGazeRay);
        Origin = EyeTrackingGazeRay.Origin;
        Direction = EyeTrackingGazeRay.Direction;
    }
    return ReturnValue;
}

FPICOXREyeTrackingData UPICOXRHMDFunctionLibrary::PXR_GetEyeTrackingData()
{
    FPICOXREyeTrackingData EyeTrackingData ;
    if (GetMutableDefault<UPICOXRSettings>()->bEnableEyeTracking )
    {
        const TSharedPtr<FPICOXREyeTracker> EyeTracker =GetPICOXRHMD()->UPxr_GetEyeTracker();
        EyeTracker->UPxr_GetEyeTrackingData(EyeTrackingData);
    }
    return EyeTrackingData;
}

bool UPICOXRHMDFunctionLibrary::PXR_GetEyeTrackingPos(FVector &EyeTrackingPos)
{
#if PLATFORM_ANDROID
	if (GetMutableDefault<UPICOXRSettings>()->bEnableEyeTracking)
	{
		const TSharedPtr<FPICOXREyeTracker> eyeTracker = GetPICOXRHMD()->UPxr_GetEyeTracker();
		if (eyeTracker)
		{
			if (eyeTracker->GetEyeDirectionToFoveationRendering(EyeTrackingPos))
				return true;
		}
	}
#endif
	return false;
}

bool UPICOXRHMDFunctionLibrary::PXR_GetFaceTrackingData(int64 InTimeStamp, int64& OutTimeStamp, TArray<float>& BlendShapeWeight, TArray<float>& VideoInputValid, float &LaughingProb, TArray<float>& EmotionProb, TArray<float>& Reserved)
{
#if PLATFORM_ANDROID
	if (GetMutableDefault<UPICOXRSettings>()->FaceTrackingMode != EPICOXRFaceTrackingMode::Disable)
	{
		const TSharedPtr<FPICOXREyeTracker> FaceOrTracker = GetPICOXRHMD()->UPxr_GetEyeTracker();
		if (FaceOrTracker)
		{
			return FaceOrTracker->GetFaceTrackingData(InTimeStamp, OutTimeStamp, BlendShapeWeight, VideoInputValid, LaughingProb, EmotionProb, Reserved);
		}
	}
#endif
    return false;
}

bool UPICOXRHMDFunctionLibrary::PXR_EnableEyeTracking(bool enable)
{
#if PLATFORM_ANDROID
	const TSharedPtr<FPICOXREyeTracker> FaceOrEyeTracker = GetPICOXRHMD()->UPxr_GetEyeTracker();
	if (FaceOrEyeTracker)
	{
		return FaceOrEyeTracker->EnableEyeTracking(enable);
	}
#endif
	return false;
}

bool UPICOXRHMDFunctionLibrary::PXR_EnableFaceTracking(EPICOXRFaceTrackingMode FaceTrackingMode)
{
	const TSharedPtr<FPICOXREyeTracker> FaceOrEyeTracker = GetPICOXRHMD()->UPxr_GetEyeTracker();
	if (FaceOrEyeTracker)
	{
		return FaceOrEyeTracker->EnableFaceTracking(FaceTrackingMode);
	}
	return false;
}

int UPICOXRHMDFunctionLibrary::PXR_SetSensorLostCustomMode(bool Value)
{
#if PLATFORM_ANDROID
    return Pxr_SetSensorLostCustomMode(Value);
#endif
    return 0;
}

int UPICOXRHMDFunctionLibrary::PXR_SetSensorLostCMST(bool Value)
{
#if PLATFORM_ANDROID
    return Pxr_SetSensorLostCMST(Value);
#endif
    return 0;
}

void UPICOXRHMDFunctionLibrary::PXR_GetVFov(float & VFOVInDegrees)
{
	float drop;
	GetPICOXRHMD()->GetFieldOfView(drop, VFOVInDegrees);
}

void UPICOXRHMDFunctionLibrary::PXR_GetHFov(float & HFOVInDegrees)
{
	float drop;
	GetPICOXRHMD()->GetFieldOfView(HFOVInDegrees, drop);
}

bool UPICOXRHMDFunctionLibrary::PXR_GetDisplayFrequenciesAvailable(int& Count, TArray<float>& AvailableRates)
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

bool UPICOXRHMDFunctionLibrary::PXR_SetExtraLatencyMode(int Mode)
{
#if PLATFORM_ANDROID
    return Pxr_SetExtraLatencyMode(Mode);
#endif
    return false;
}

UPICOXREventManager* UPICOXRHMDFunctionLibrary::PXR_GetEventManager()
{
    return UPICOXREventManager::GetInstance();
}

void UPICOXRHMDFunctionLibrary::PXR_GetPredictedMainSensorState(FPxrSensorState& sensorState, int& sensorFrameIndex) {
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

bool UPICOXRHMDFunctionLibrary::PXR_QueryDeviceAbilities(EPICOXRDeviceAbilities DeviceAbility)
{
#if PLATFORM_ANDROID
    int CurrentVersion = 0;
    Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
    if (CurrentVersion >= 0x2000304)
    {
        PxrTrackingModeFlags SupportTrackingMode;
        Pxr_GetTrackingMode(&SupportTrackingMode);
        switch (DeviceAbility)
        {
        case EPICOXRDeviceAbilities::TRACKING_MODE_ROTATION_BIT:
            {
                return (PXR_TRACKING_MODE_ROTATION_BIT & SupportTrackingMode)? true:false;
            }
            break;
        case EPICOXRDeviceAbilities::TRACKING_MODE_POSITION_BIT:
            {
                return (PXR_TRACKING_MODE_POSITION_BIT & SupportTrackingMode)? true:false;
            }
            break;
        case EPICOXRDeviceAbilities::TRACKING_MODE_EYE_BIT:
            {
                return (PXR_TRACKING_MODE_EYE_BIT & SupportTrackingMode)? true:false;
            }
            break;
        case EPICOXRDeviceAbilities::TRACKING_MODE_FACE_BIT:
            {
                return (PXR_TRACKING_MODE_FACE_BIT & SupportTrackingMode)? true:false;
            }
            break;
        case EPICOXRDeviceAbilities::TRACKING_MODE_VCMOTOR_BIT:
            {
                return (PXR_TRACKING_MODE_VCMOTOR_BIT & SupportTrackingMode)? true:false;
            }
            break;
        case EPICOXRDeviceAbilities::TRACKING_MODE_HAND_BIT:
            {
                return (PXR_TRACKING_MODE_HAND_BIT & SupportTrackingMode)? true:false;
            }
            break;
        default:
            ;
        }
    }
#endif

    return false;
}

void UPICOXRHMDFunctionLibrary::PXR_SetLateLatchingEnable(bool Value)
{
    IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(TEXT("r.EnableLateLatching"));
    if (Variable)
    {
        Variable->Set(Value ? 1 : 0);
    }
}