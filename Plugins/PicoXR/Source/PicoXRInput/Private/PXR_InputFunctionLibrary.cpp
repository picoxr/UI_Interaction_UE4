//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_InputFunctionLibrary.h"
#include "PXR_Input.h"
#include "PXR_Log.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "PxrInput.h"
#endif

FPicoXRInput* GetPicoXRInput()
{
    TArray<IMotionController*> MotionControllers = IModularFeatures::Get().GetModularFeatureImplementations<IMotionController>(IMotionController::GetModularFeatureName());
    for (auto MotionController : MotionControllers)
    {
        if (MotionController != nullptr && MotionController->GetMotionControllerDeviceTypeName() == FName(TEXT("PicoXRInput")))
        {
            return static_cast<FPicoXRInput*>(MotionController);
        }
    }
    return nullptr;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerPower(EPicoXRControllerType ControllerType, int32& Power)
{
    FPicoXRInput* PicoXRInputInstence = GetPicoXRInput();
    if (PicoXRInputInstence)
    {
        Power = PicoXRInputInstence->UPxr_GetControllerPower((uint8_t)ControllerType);
        return true;
    }
    return false;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerConnectionState(EPicoXRControllerType ControllerType, bool& Status)
{
    FPicoXRInput* Input =  GetPicoXRInput();
    if (Input)
    {
        if (ControllerType ==EPicoXRControllerType::LeftHand || ControllerType == EPicoXRControllerType::RightHand)
        {
            Status = Input->UPxr_GetControllerConnectState(static_cast<int32>(ControllerType));
		}
		else if (ControllerType == EPicoXRControllerType::G2Hand)
		{
			Status = Input->UPxr_GetControllerConnectState(0);
		}
		else
		{
			return false;
		}
        return true;
    }  
#if PLATFORM_WINDOWS
	Status = true;
#endif
	return false;
}

bool UPicoXRInputFunctionLibrary::PXR_GetMainControllerHandle( EPicoXRHandedness& Handedness)
{
    bool Ret = false;
    FPicoXRInput* Input =  GetPicoXRInput();
    if (Input)
    {
        int32 MainHandle = 0;
        Ret = Input->UPxr_GetControllerMainInputHandle(MainHandle);
        Handedness = MainHandle == 0? EPicoXRHandedness::LeftHand: EPicoXRHandedness::RightHand;
        return Ret;
    }
    return Ret;
}

bool UPicoXRInputFunctionLibrary::PXR_SetMainControllerHandle(EPicoXRHandedness Handedness)
{
	FPicoXRInput *PxrInput = GetPicoXRInput();
	if (PxrInput)
	{
		PxrInput->UPxr_SetControllerMainInputHandle(int32(Handedness));
		return true;
	}
	return false;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerAngularVelocity(EPicoXRControllerType ControllerType,
                                                                          FVector& AngularVelocity)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPicoXRControllerType::LeftHand) 
    {
        Hand = EPicoXRControllerHandness::LeftController;
    } 
    else 
    {
        Hand = EPicoXRControllerHandness::RightController;
    }

    float HeadSensorData[7] = {0};
    Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.angularVelocity.x;
    Data[1] = Tracking.localControllerPose.angularVelocity.y;
    Data[2] = Tracking.localControllerPose.angularVelocity.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerAngularVelocityState %f,%f,%f",Data[0],Data[1],Data[2]);
    AngularVelocity = FVector(Data[0],Data[1],Data[2]);
    AngularVelocity = FVector(-AngularVelocity.Z , AngularVelocity.X , AngularVelocity.Y);
    return true;
#endif
    return false;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerAcceleration(EPicoXRControllerType ControllerType,FVector& Acceleration)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPicoXRControllerType::LeftHand) {
        Hand = EPicoXRControllerHandness::LeftController;
    } else {
        Hand = EPicoXRControllerHandness::RightController;
    }
	float HeadSensorData[7] = { 0 };
	Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.angularAcceleration.x;
    Data[1] = Tracking.localControllerPose.angularAcceleration.y;
    Data[2] = Tracking.localControllerPose.angularAcceleration.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerAccelerationState %f,%f,%f",Data[0],Data[1],Data[2]);
    Acceleration = FVector(Data[0],Data[1],Data[2]);
    Acceleration = FVector(-Acceleration.Z , Acceleration.X , Acceleration.Y);
    return true;
#endif
    return false;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerLinearVelocity(EPicoXRControllerType ControllerType,
    FVector& LinearVelocity)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPicoXRControllerType::LeftHand) {
        Hand = EPicoXRControllerHandness::LeftController;
    } else {
        Hand = EPicoXRControllerHandness::RightController;
    }
	float HeadSensorData[7] = { 0 };
	Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.linearVelocity.x;
    Data[1] = Tracking.localControllerPose.linearVelocity.y;
    Data[2] = Tracking.localControllerPose.linearVelocity.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerLinearVelocityState %f,%f,%f",Data[0],Data[1],Data[2]);
    LinearVelocity = FVector(Data[0],Data[1],Data[2]);
    LinearVelocity = FVector(-LinearVelocity.Z , LinearVelocity.X , LinearVelocity.Y);
    return true;
#endif
    return false;
}

bool UPicoXRInputFunctionLibrary::PXR_VibrateController(EPicoXRControllerType ControllerType,float Strength, int Time)
{
#if PLATFORM_ANDROID
    if (Pxr_SetControllerVibration((uint32_t)ControllerType, Strength, Time) == 0)
    {
        return true;
    }
#endif
    return false;
}

void UPicoXRInputFunctionLibrary::PXR_GetControllerDeviceType(EPicoXRControllerDeviceType& OutControllerType)
{
	int32 ControllerType = 0;
#if PLATFORM_ANDROID
	PxrControllerCapability Cap;
	Pxr_GetControllerCapabilities(PXR_CONTROLLER_LEFT, &Cap);
	ControllerType = Cap.type;
#endif
#if PLATFORM_WINDOWS
	ControllerType = 5;
#endif
	OutControllerType = static_cast<EPicoXRControllerDeviceType>(ControllerType);
}

void UPicoXRInputFunctionLibrary::PXR_SetControllerArmModelParam(EPicoXRControllerType Controller,
    EPicoXRHandedness Handness, EPicoXRArmModelJoint ArmJoint, EPicoXRGazeBehavior GazeType, float ElbowHeight,
    float ElbowDepth, float PointerTiltAngle)
{
}

void UPicoXRInputFunctionLibrary::PXR_GetControllerArmModelParam(EPicoXRControllerType Controller,
    EPicoXRHandedness& Handness, EPicoXRArmModelJoint& ArmJoint, EPicoXRGazeBehavior& GazeType, float& ElbowHeight,
    float& ElbowDepth, float& PointerTiltAngle)
{
}

bool UPicoXRInputFunctionLibrary::PXR_GetHandedness(EPicoXRHandedness &Handedness)
{
	bool Ret = false;
	FPicoXRInput* PxrInput = GetPicoXRInput();
	if (PxrInput)
	{
		int32 MainHandle = 0;
		Ret = PxrInput->UPxr_GetControllerMainInputHandle(MainHandle);
        Handedness = MainHandle == 0 ? EPicoXRHandedness::LeftHand : EPicoXRHandedness::RightHand;
		return Ret;
	}
	return Ret;
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerEnableHomekey()
{
    FPicoXRInput* PxrInput = GetPicoXRInput();
    if (PxrInput)
    {
       return PxrInput->UPxr_GetControllerEnableHomeKey();
    }
    return false;
}

void UPicoXRInputFunctionLibrary::PXR_SetControllerOriginOffset(EPicoXRControllerType Controller, FVector Offset)
{
    if (Controller == EPicoXRControllerType::LeftHand)
    {
        FPicoXRInput::OriginOffsetL = Offset;
    }
    else if (Controller == EPicoXRControllerType::RightHand)
    {
        FPicoXRInput::OriginOffsetR = Offset;
    }
}

bool UPicoXRInputFunctionLibrary::PXR_GetControllerPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FVector& OutLocation, FRotator& OutRotation)
{
	bool Result = false;
    FVector PredictedLocation; FRotator PredictedRotation;
    PredictedLocation = FVector::ZeroVector;
    PredictedRotation = FRotator::ZeroRotator;
    FPicoXRInput* PxrInput = GetPicoXRInput();
    if (PxrInput)
	{
		Result = PxrInput->GetPredictedLocationAndRotation(DeviceHand, PredictedTime, PredictedRotation, PredictedLocation);
    }
    OutLocation = PredictedLocation;
    OutRotation = PredictedRotation;
	return Result;
}

int UPicoXRInputFunctionLibrary::PXR_SetControllerEnableKey(bool isEnable, EPxrControllerKeyMap Key) {
#if PLATFORM_ANDROID
    PxrControllerKeyMap PxrKey = static_cast<PxrControllerKeyMap>(Key);
    return Pxr_SetControllerEnableKey(isEnable, PxrKey);
#endif
    return 0;
}
