// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobileControllerBFlib.h"
#include "PicoMobileController.h"
#include "PicoMobileControllerState.h"

#if PLATFORM_ANDROID
FPicoMobileController* GetPicoMobileController()
{
	FPicoMobileController* pPicoMobileController;
	TArray<IMotionController*> MotionControllers = IModularFeatures::Get().GetModularFeatureImplementations<IMotionController>(IMotionController::GetModularFeatureName());
	for (auto MotionController : MotionControllers)
	{
		if (MotionController != nullptr)
		{
			pPicoMobileController = static_cast<FPicoMobileController*>(MotionController);
			if (pPicoMobileController != nullptr)
				return pPicoMobileController;
		}
	}

	return nullptr;
}
#endif

FDelegateWithoutParam UPicoMobileControllerBFlib::PicoControllerConnected;
FDelegateWithoutParam UPicoMobileControllerBFlib::PicoControllerDisconnected;

bool UPicoMobileControllerBFlib::IsPicoControllerAvailable()
{
#if PLATFORM_ANDROID
	return PicoMobileControllerState::GetInstance()->GetHBConnectState();
#endif
	return false;
}

int32 UPicoMobileControllerBFlib::GetDeviceType()
{
	int32 deviceType = 0;
#if PLATFORM_ANDROID
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jmethodID id_apl_GetDeviceType = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "apl_GetDeviceType", "()I", false);
	deviceType = StaticCast<int32>(FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, id_apl_GetDeviceType));
#endif
	return deviceType;
}

void UPicoMobileControllerBFlib::GetPicoControllerOrientationAndPosition(
	FRotator& OutOrientation,
	FVector& OutPosition
)
{
#if PLATFORM_ANDROID
	FPicoMobileController* pPicoMobileController = GetPicoMobileController();
	if (pPicoMobileController)
	{	
		pPicoMobileController->GetControllerOrientationAndPosition(
			0,
			EControllerHand::Left,
			OutOrientation,
			OutPosition,
			GWorld->GetWorldSettings()->WorldToMeters
		);
	}
#endif
}

int32 UPicoMobileControllerBFlib::PicoGetControllerBatteryLevel()
{
#if PLATFORM_ANDROID
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jmethodID GetControllerBatteryLevel;
	GetControllerBatteryLevel = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getControllerBatteryLevel", "()I", false);
	return (int32)FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GameActivityThis, GetControllerBatteryLevel);
#endif
	return -1;
}

void UPicoMobileControllerBFlib::PicoSetGazeType(EGazeBehavior NewGazeType)
{
#if PLATFORM_ANDROID
	PicoMobileControllerState::GetInstance()->SetHBGazeType((int32)NewGazeType);
#endif
}

void UPicoMobileControllerBFlib::PicoGetGazeType(EGazeBehavior& OutGazeType)
{
#if PLATFORM_ANDROID
	int32 ret = -1;
	ret = PicoMobileControllerState::GetInstance()->GetHBGazeType();
	switch (ret)
	{
	case 0:
		OutGazeType = EGazeBehavior::Never;
		break;
	case 1:
		OutGazeType = EGazeBehavior::DuringMotion;
		break;
	case 2:
		OutGazeType = EGazeBehavior::Always;
		break;
	}
#endif
}

void UPicoMobileControllerBFlib::PicoSetElbowHeight(float NewHeight)
{
	//FMath::Clamp(NewHeight, 0.0f, 0.2f)
#if PLATFORM_ANDROID
	PicoMobileControllerState::GetInstance()->SetHBElbowHeight(FMath::Clamp(NewHeight, 0.0f, 0.2f));
#endif

}

void UPicoMobileControllerBFlib::PicoGetElbowHeight(float& OutHeight)
{
#if PLATFORM_ANDROID
	FVector parm = FVector::ZeroVector;
	PicoMobileControllerState::GetInstance()->GetHBArmModelParm(parm);
	OutHeight = parm.X;
#endif

}

void UPicoMobileControllerBFlib::PicoSetElbowDepth(float NewDepth)
{
#if PLATFORM_ANDROID
	PicoMobileControllerState::GetInstance()->SetHBElbowDepth(FMath::Clamp(NewDepth, 0.0f, 0.2f));
#endif

}

void UPicoMobileControllerBFlib::PicoGetElbowDepth(float& OutDepth)
{
#if PLATFORM_ANDROID
	FVector parm = FVector::ZeroVector;
	PicoMobileControllerState::GetInstance()->GetHBArmModelParm(parm);
	OutDepth = parm.Y;
#endif

}

void UPicoMobileControllerBFlib::PicoGetPointerTiltAngle(float& OutPointerTiltAngle)
{
#if PLATFORM_ANDROID
	FVector parm = FVector::ZeroVector;
	PicoMobileControllerState::GetInstance()->GetHBArmModelParm(parm);
	OutPointerTiltAngle = parm.Z;
#endif
}

void UPicoMobileControllerBFlib::PicoSetPointerTiltAngle(float NewPointerTiltAngle)
{
#if PLATFORM_ANDROID
	PicoMobileControllerState::GetInstance()->SetHBPointerTiltAngle(FMath::Clamp(NewPointerTiltAngle, 0.0f, 30.0f));
#endif
}

void UPicoMobileControllerBFlib::PicoChooseArmModelJoint(EPicoArmModelJoint chosenArmJoint)
{
#if PLATFORM_ANDROID
	FPicoMobileController* pPicoMobileController = GetPicoMobileController();
	if (pPicoMobileController)
	{
		switch (chosenArmJoint)
		{
		case EPicoArmModelJoint::Controller:
			pPicoMobileController->SetUseController();
			break;
		case EPicoArmModelJoint::Wrist:
			pPicoMobileController->SetUseWrist();
			break;
		case EPicoArmModelJoint::Elbow:
			pPicoMobileController->SetUseElbow();
			break;
		case EPicoArmModelJoint::Shoulder:
			pPicoMobileController->SetUseShoulder();
			break;
		default:
			break;
		}
	}
#endif
}

void UPicoMobileControllerBFlib::PicoGetArmModelJoint(EPicoArmModelJoint& OutArmJoint)
{
#if PLATFORM_ANDROID
	FPicoMobileController* pPicoMobileController = GetPicoMobileController();
	if (pPicoMobileController)
	{
		switch (pPicoMobileController->GetArmJointIndex())
		{
		case 0:
			OutArmJoint = EPicoArmModelJoint::Controller;
			break;
		case 1:
			OutArmJoint = EPicoArmModelJoint::Wrist;
			break;
		case 2:
			OutArmJoint = EPicoArmModelJoint::Elbow;
			break;
		case 3:
			OutArmJoint = EPicoArmModelJoint::Shoulder;
			break;
		default:
			break;
		}
	}
	
#endif
}

void UPicoMobileControllerBFlib::PicoSwitchArmModelJoint()
{
#if PLATFORM_ANDROID
	FPicoMobileController* pPicoMobileController = GetPicoMobileController();
	if (pPicoMobileController)
	{
		pPicoMobileController->SwitchArmJoint();
	}
#endif
}

void UPicoMobileControllerBFlib::PicoSetControllerConnectedStatusChangedDelegate(
	FDelegateWithoutParam OnPicoControllerConnected, 
	FDelegateWithoutParam OnPicoControllerDisconnected)
{
#if PLATFORM_ANDROID
	PicoControllerConnected = OnPicoControllerConnected;
	PicoControllerDisconnected = OnPicoControllerDisconnected;
#endif
}
bool UPicoMobileControllerBFlib::PicoResetG1Controller()
{
	bool ret = false;
#if PLATFORM_ANDROID
	if(FAndroidMisc::GetDeviceModel() == "Pico Goblin")
	{
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			static jmethodID Device = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "resetHbSensorState", "()V", false);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Device);
			ret = true;
		}
	}
#endif
	return ret;
}

