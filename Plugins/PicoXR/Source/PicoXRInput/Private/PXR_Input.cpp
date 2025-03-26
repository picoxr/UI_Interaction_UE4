// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_Input.h"
#include "PXR_HMDPrivate.h"
#include "PXR_InputState.h"
#include "PXR_HMD.h"
#include "CoreMinimal.h"
#include "PXR_Log.h"
#include "IXRTrackingSystem.h"
#include "MotionControllerComponent.h"
#include "PXR_HandComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PXR_InputFunctionLibrary.h"
#include "Features/IModularFeatures.h"
#include "Misc/CoreDelegates.h"
#include "PXR_Utils.h"

#define LOCTEXT_NAMESPACE "PICOXRInput"

FVector FPICOXRInput::OriginOffsetL = FVector::ZeroVector;
FVector FPICOXRInput::OriginOffsetR = FVector::ZeroVector;

FPICOXRInput::FPICOXRInput()
	:bHandTrackingAvailable(false)
    ,PICOXRHMD(nullptr)
	,MessageHandler(new FGenericApplicationMessageHandler())
	,LeftConnectState(false)
	,RightConnectState(false)
	,LeftControllerPower(0)
	,RightControllerPower(0)
	,LeftControllerTouchPoint(FVector2D::ZeroVector)
	,RightControllerTouchPoint(FVector2D::ZeroVector)
	,LeftControllerTriggerValue(0.0f)
	,RightControllerTriggerValue(0.0f)
	,LeftControllerGripValue(0.0f)
	,RightControllerGripValue(0.0f)
	,MainControllerHandle(-1)
	,ControllerType(PxrControllerType::PXR_NO_DEVICE)
	,CurrentVersion(0)
	,CurrentFramePredictedTime(0.0f)
{
	PICOXRHMD = GetPICOXRHMD();

#if PLATFORM_WINDOWS && WITH_EDITOR
	IModularFeatures::Get().RegisterModularFeature(IPXR_HandTracker::GetModularFeatureName(), static_cast<IPXR_HandTracker*>(this));
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Pinch] = FPICOKeyNames::PICOHand_Left_Pinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Pinch] = FPICOKeyNames::PICOHand_Right_Pinch;
#elif PLATFORM_ANDROID
	Settings = GetMutableDefault<UPICOXRSettings>();
	UpdateConnectState();
	FPICOXRHMDModule::GetPluginWrapper().GetControllerMainInputHandle(&MainControllerHandle);
	if (Settings)
	{
		FPICOXRHMDModule::GetPluginWrapper().SetControllerEnableKey(Settings->bEnableHomeKey, PxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME);
	}
	FPICOXRVersionHelper::GetRuntimeAPIVersion(CurrentVersion);

	SetKeyMapping();
	IModularFeatures::Get().RegisterModularFeature(IMotionController::GetModularFeatureName(), static_cast<IMotionController*>(this));
	IModularFeatures::Get().RegisterModularFeature(IPXR_HandTracker::GetModularFeatureName(), static_cast<IPXR_HandTracker*>(this));
	if (UPICOXRInputFunctionLibrary::IsHandTrackingEnabled())
	{
		bHandTrackingAvailable = true;
		PXR_LOGD(PxrUnreal, "FPICOXRInput::HandTracking is available!");
	}
	//enables low power mode by default
	if (Settings&&Settings->bEnableBodyTracking)
	{
		PXR_LOGD(PxrUnreal, "FPICOXRInput::BodyTracking is available!");
		UPICOXRInputFunctionLibrary::PXR_SetBodyTrackingEnable(1);
		PXR_LOGD(PxrUnreal, "FPICOXRInput::SetBodyTrackingMode: 1 !");
	}
#endif

}

FPICOXRInput::~FPICOXRInput()
{
	IModularFeatures::Get().UnregisterModularFeature(IMotionController::GetModularFeatureName(), static_cast<IMotionController*>(this));
	IModularFeatures::Get().UnregisterModularFeature(IPXR_HandTracker::GetModularFeatureName(), static_cast<IPXR_HandTracker*>(this));
}

void FPICOXRInput::PreInit()
{
	RegisterKeys();
	PXR_LOGD(PxrUnreal, "PICOXRInput pre-init called");
}

void FPICOXRInput::Tick(float DeltaTime)
{
}

void FPICOXRInput::SendControllerEvents()
{
#if PLATFORM_WINDOWS && WITH_EDITOR
	if (UPICOXRInputFunctionLibrary::IsHandTrackingEnabled())
	{
		bHandTrackingAvailable = true;
	}
	const FInputDeviceId DeviceId = IPlatformInputDeviceMapper::Get().GetDefaultInputDevice();
	FPlatformUserId PlatformUser = IPlatformInputDeviceMapper::Get().GetUserForInputDevice(DeviceId);
	if (bHandTrackingAvailable)
	{
		int32 HandButtonState[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOHandButton::ButtonCount];
		for (int Hand = 0; Hand < 2; Hand++)
		{
			const EPICOXRHandType DeviceHand = static_cast<EPICOXRHandType>(Hand + 1);
			const int32 PinchIndex = (int32)EPICOHandButton::Pinch;
			HandButtonState[Hand][PinchIndex] = GetPinchStrength(DeviceHand) >= 1.0f ? 1 : 0;
			if (HandButtonState[Hand][PinchIndex] == 1 && HandButtonState[Hand][PinchIndex] != LastHandButtonState[Hand][PinchIndex])
			{
				MessageHandler->OnControllerButtonPressed(HandButtons[Hand][PinchIndex], PlatformUser, DeviceId, false);
			}
			else if (HandButtonState[Hand][PinchIndex] == 0 && HandButtonState[Hand][PinchIndex] != LastHandButtonState[Hand][PinchIndex])
			{
				MessageHandler->OnControllerButtonReleased(HandButtons[Hand][PinchIndex], PlatformUser, DeviceId, false);
			}
			LastHandButtonState[Hand][PinchIndex] = HandButtonState[Hand][PinchIndex];
		}
	}
#elif PLATFORM_ANDROID
	if (PICOXRHMD)
	{
		PICOXRHMD->PollEvent();
		PICOXRHMD->OnGameFrameBegin_GameThread();
	}
	ProcessButtonEvent();
	ProcessButtonAxis();
#endif
	UpdateHandState();
}

void FPICOXRInput::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FPICOXRInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return false;
}

void FPICOXRInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();
	FPlatformUserId InPlatformUser = FGenericPlatformMisc::GetPlatformUserForUserIndex(ControllerId);
	FInputDeviceId InDeviceId = INPUTDEVICEID_NONE;
	DeviceMapper.RemapControllerIdToPlatformUserAndDevice(ControllerId, InPlatformUser, InDeviceId);
	
	switch (ChannelType)
	{
		case FForceFeedbackChannelType::LEFT_LARGE:
		case FForceFeedbackChannelType::LEFT_SMALL:
		{
#if PLATFORM_ANDROID
			FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(0, Value, 10);
#endif
			break;
		}
		case FForceFeedbackChannelType::RIGHT_LARGE:
		case FForceFeedbackChannelType::RIGHT_SMALL:
		{
#if PLATFORM_ANDROID
			FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(1, Value, 10);
#endif
			break;
		}
		default:
			break;
	}
}

void FPICOXRInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values)
{
	IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();
	FPlatformUserId InPlatformUser = FGenericPlatformMisc::GetPlatformUserForUserIndex(ControllerId);
	FInputDeviceId InDeviceId = INPUTDEVICEID_NONE;
	DeviceMapper.RemapControllerIdToPlatformUserAndDevice(ControllerId, InPlatformUser, InDeviceId);
	if (values.LeftLarge > 0)
	{
#if PLATFORM_ANDROID
		FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(0, values.LeftLarge, 10);
#endif
	}
	if (values.RightLarge >0)
	{
#if PLATFORM_ANDROID
		FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(1, values.RightLarge, 10);
#endif
	}
}

FQuat FPICOXRInput::GetBoneRotation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		FTransform OutTransform;
		float OutRadius;
		if (GetKeypointState(DeviceHand, BoneId, OutTransform, OutRadius))
		{
			OutTransform.NormalizeRotation();
			return OutTransform.GetRotation();
		}
	}

	return FQuat();
}

FVector FPICOXRInput::GetBoneLocation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		FTransform OutTransform;
		float OutRadius;
		if (GetKeypointState(DeviceHand, BoneId, OutTransform, OutRadius))
		{
			// Convert to UE world space
			const FTransform& TrackingToWoldTransform = GEngine->XRSystem.Get()->GetTrackingToWorldTransform();
			OutTransform *= TrackingToWoldTransform;
			return OutTransform.GetLocation();
		}
	}
	return FVector();
}

float FPICOXRInput::GetBoneRadii(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		FTransform OutTransform;
		float OutRadius;
		if (GetKeypointState(DeviceHand, BoneId, OutTransform, OutRadius))
		{
			return OutRadius;
		}
	}
	return 0.f;
}

bool FPICOXRInput::IsBoneOrientationValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.SpaceLocationFlags[static_cast<uint8>(BoneId)] & StaticCast<uint64>(XrSpaceLocationFlags::XR_SPACE_LOCATION_ORIENTATION_VALID_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsBonePositionValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.SpaceLocationFlags[static_cast<uint8>(BoneId)] & StaticCast<uint64>(XrSpaceLocationFlags::XR_SPACE_LOCATION_POSITION_VALID_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsBoneOrientationTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.SpaceLocationFlags[static_cast<uint8>(BoneId)] & StaticCast<uint64>(XrSpaceLocationFlags::XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsBonePositionTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.SpaceLocationFlags[static_cast<uint8>(BoneId)] & StaticCast<uint64>(XrSpaceLocationFlags::XR_SPACE_LOCATION_POSITION_TRACKED_BIT)) != 0);
	}
	return false;
}

FTransform FPICOXRInput::GetHandRootPose(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		FTransform OutTransform;
		float OutRadius;
		if (GetKeypointState(DeviceHand, EPICOXRHandJoint::Wrist, OutTransform, OutRadius))
		{
			OutTransform.NormalizeRotation();
			return OutTransform;
		}
	}
	return FTransform();
}

float FPICOXRInput::GetHandScale(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return HandState.HandScale;
	}

	return 1.0f;
}

EPICOXRHandTrackingConfidence FPICOXRInput::GetTrackingConfidence(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return HandState.ReceivedJointPoses ? EPICOXRHandTrackingConfidence::High : EPICOXRHandTrackingConfidence::Low;
	}
	return EPICOXRHandTrackingConfidence::Low;
}

FTransform FPICOXRInput::GetRayPose(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		if (HandState.ReceivedJointPoses)
		{
			return HandState.AimPose;
		}
	}
	return FTransform();
}

bool FPICOXRInput::IsComputed(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_COMPUTED_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsRayValid(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_VALID_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsPinchValid(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_RAY_TOUCHED_BIT)) != 0);
	}
	return false;
}

float FPICOXRInput::GetPinchStrength(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return FMath::Clamp(HandState.TouchStrengthRay,0.f,1.15f);
	}

	return 0.0f;
}

bool FPICOXRInput::GetFingerIsPinching(const EPICOXRHandType DeviceHand, EPICOXRHandFinger Finger)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		switch (Finger)
		{
		case EPICOXRHandFinger::None: break;
		case EPICOXRHandFinger::Index:
			{
				return (static_cast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_INDEX_PINCHING_BIT) & HandState.Status) ? true : false;
			}
			break;
		case EPICOXRHandFinger::Middle:
			{
				return (static_cast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_MIDDLE_PINCHING_BIT) & HandState.Status) ? true : false;
			}
			break;
		case EPICOXRHandFinger::Ring:
			{
				return (static_cast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_RING_PINCHING_BIT) & HandState.Status) ? true : false;
			}
			break;
		case EPICOXRHandFinger::Pinky:
			{
				return (static_cast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_LITTLE_PINCHING_BIT) & HandState.Status) ? true : false;
			}
			break;
		default:
			;
		}
	}
	return false;
}

float FPICOXRInput::GetFingerPinchStrength(const EPICOXRHandType DeviceHand, EPICOXRHandFinger Finger)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();

		switch (Finger)
		{
		case EPICOXRHandFinger::None: break;
		case EPICOXRHandFinger::Index:
			{
				return FMath::Clamp(HandState.PinchStrengthIndex,0.f,1.f);
			}
			break;
		case EPICOXRHandFinger::Middle:
			{
				return FMath::Clamp(HandState.PinchStrengthMiddle,0.f,1.f);
			}
			break;
		case EPICOXRHandFinger::Ring:
			{
				return FMath::Clamp(HandState.PinchStrengthRing,0.f,1.f);
			}
			break;
		case EPICOXRHandFinger::Pinky:
			{
				return FMath::Clamp(HandState.PinchStrengthLittle,0.f,1.f);
			}
			break;
		default: ;
		}
	}

	return 0.0f;
}

EPICOXRActiveInputDevice FPICOXRInput::GetActiveInputDevice()
{
#if PLATFORM_WINDOWS && WITH_EDITOR
	return IsHandTrackingStateValid()?EPICOXRActiveInputDevice::HandTrackingActive:EPICOXRActiveInputDevice::ControllerActive;
#elif PLATFORM_ANDROID
	if (CurrentVersion  >= 0x2000307)
	{
		PxrActiveInputDeviceType type ;
		FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerActiveInputType(&type);
		return (EPICOXRActiveInputDevice)type;
	}
#endif
	return EPICOXRActiveInputDevice::NoneActive;
}

bool FPICOXRInput::IsHandTrackingStateValid() const
{
	bool State = false;

#if PLATFORM_WINDOWS && WITH_EDITOR
	if (FPICOXRHMDModule::Get().PreInit())
	{
		FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerSettingState(&State);
	}
#elif PLATFORM_ANDROID&&PLATFORM_64BITS
	if (CurrentVersion  >= 0x2000306)
	{
		FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerSettingState(&State);
	}
#endif
	return State;
}

bool FPICOXRInput::GetKeypointState(EPICOXRHandType Hand, EPICOXRHandJoint Keypoint, FTransform& OutTransform, float& OutRadius) const
{
	check(static_cast<int32>(Keypoint) < XR_HAND_JOINT_COUNT_MAX);
	if (!bHandTrackingAvailable)
	{
		return false;
	}
	bool gotTransform = false;
	{
		const FPICOXRHandState& HandState = (Hand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		gotTransform = HandState.GetTransform(Keypoint, OutTransform);
		OutRadius = HandState.Radii[static_cast<uint8>(Keypoint)];
	}

	return gotTransform;
}

FName FPICOXRInput::GetHandTrackerDeviceTypeName() const
{
	return FName(TEXT("PICOHandTracking"));
}

FName FPICOXRInput::GetMotionControllerDeviceTypeName() const
{
	return FName(TEXT("PICOXRInput"));
}

bool FPICOXRInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const FName MotionSource, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const
{
	EControllerHand DeviceHand;
	GetHandEnumForSourceName(MotionSource, DeviceHand);

	IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();
	FPlatformUserId InPlatformUser = FGenericPlatformMisc::GetPlatformUserForUserIndex(ControllerIndex);
	FInputDeviceId InDeviceId = INPUTDEVICEID_NONE;
	DeviceMapper.RemapControllerIdToPlatformUserAndDevice(ControllerIndex, InPlatformUser, InDeviceId);
	
	double predictedDisplayTimeMs = 0.0;
	FVector SourcePosition = FVector::ZeroVector;
	FQuat SourceOrientation = FQuat::Identity;
	FPXRGameFrame* CurrentFrame = nullptr;
	FGameSettings* CurrentSettings = nullptr;
	if (IsInRenderingThread() && PICOXRHMD)
	{
		CurrentSettings = PICOXRHMD->GameSettings_RenderThread.Get();
		CurrentFrame = PICOXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PICOXRHMD)
	{
		CurrentSettings = PICOXRHMD->GameSettings.Get();
		CurrentFrame = PICOXRHMD->NextGameFrameToRender_GameThread.Get();
	}

	if (CurrentFrame && CurrentSettings)
	{
		predictedDisplayTimeMs = CurrentFrame->predictedDisplayTimeMs;
		SourcePosition = CurrentFrame->Position;
		SourceOrientation = CurrentFrame->Orientation;
		PXR_LOGV(PxrUnreal, "GetControllerOrientationAndPosition FrameNumber:%d,predictedDisplayTimeMs:%f", CurrentFrame->FrameNumber, predictedDisplayTimeMs);
	}
	else
	{
		return false;
	}

	if (ControllerType == PxrControllerType::PXR_HB2_Controller)
	{
		if (LeftConnectState)
		{
			GetControllerSensorData(CurrentSettings, EControllerHand::Left, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
	}
	else if (ControllerType == PxrControllerType::PXR_CV2_Controller || ControllerType == PxrControllerType::PXR_CV3_Optics_Controller)
	{
		if (LeftConnectState && DeviceHand == EControllerHand::Left)
		{
			GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
		else if (RightConnectState && DeviceHand == EControllerHand::Right)
		{
			GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
	}
	else
	{
		if (LeftConnectState && DeviceHand == EControllerHand::Left)
		{
			GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
		else if (RightConnectState && DeviceHand == EControllerHand::Right)
		{
			GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
	}
	return false;
}

bool FPICOXRInput::GetPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const
{
	FVector PredictedLocation;
	FRotator PredictedRotation;
	PredictedLocation = FVector::ZeroVector;
	PredictedRotation = FRotator::ZeroRotator;
	float WorldToMetersScale = 100.0f;
	FVector SourcePosition = FVector::ZeroVector;
	FQuat SourceOrientation = FQuat::Identity;
	FPXRGameFrame* CurrentFrame = nullptr;
	FGameSettings* CurrentSettings = nullptr;

	if (IsInRenderingThread() && PICOXRHMD)
	{
		CurrentSettings = PICOXRHMD->GameSettings_RenderThread.Get();
		CurrentFrame = PICOXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PICOXRHMD)
	{
		CurrentSettings = PICOXRHMD->GameSettings.Get();
		CurrentFrame = PICOXRHMD->NextGameFrameToRender_GameThread.Get();
	}

	if (CurrentFrame && CurrentSettings)
	{
		SourcePosition = CurrentFrame->Position;
		SourceOrientation = CurrentFrame->Orientation;
		WorldToMetersScale = CurrentFrame->WorldToMetersScale;
	}
	else
	{
		return false;
	}

	if (LeftConnectState && DeviceHand == EControllerHand::Left)
	{
		GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, PredictedTime, SourcePosition, SourceOrientation, PredictedRotation, PredictedLocation);
	}
	else if (RightConnectState && DeviceHand == EControllerHand::Right)
	{
		GetControllerSensorData(CurrentSettings, DeviceHand, WorldToMetersScale, PredictedTime, SourcePosition, SourceOrientation, PredictedRotation, PredictedLocation);
	}
	OutPosition = PredictedLocation;
	OutOrientation = PredictedRotation;
	return true;
}

ETrackingStatus FPICOXRInput::GetControllerTrackingStatus(const int32 ControllerIndex, const FName MotionSource) const
{
	EControllerHand DeviceHand;
	GetHandEnumForSourceName(MotionSource, DeviceHand);

	IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();
	FPlatformUserId InPlatformUser = FGenericPlatformMisc::GetPlatformUserForUserIndex(ControllerIndex);
	FInputDeviceId InDeviceId = INPUTDEVICEID_NONE;
	DeviceMapper.RemapControllerIdToPlatformUserAndDevice(ControllerIndex, InPlatformUser, InDeviceId);
	
	if (ControllerIndex == 0 && (DeviceHand == EControllerHand::Left || DeviceHand == EControllerHand::Right || DeviceHand == EControllerHand::AnyHand))
	{
		return ETrackingStatus::Tracked;
	}
	return ETrackingStatus::NotTracked;
}

void FPICOXRInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values)
{
	IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();
	FPlatformUserId InPlatformUser = FGenericPlatformMisc::GetPlatformUserForUserIndex(ControllerId);
	FInputDeviceId InDeviceId = INPUTDEVICEID_NONE;
	DeviceMapper.RemapControllerIdToPlatformUserAndDevice(ControllerId, InPlatformUser, InDeviceId);
	
#if PLATFORM_ANDROID
	switch (Hand)
	{
		case 0:
		{
			FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(0, Values.Amplitude * GetHapticAmplitudeScale(), 2000);
			break;
		}
		case 1:
		{
			FPICOXRHMDModule::GetPluginWrapper().SetControllerVibration(1, Values.Amplitude * GetHapticAmplitudeScale(), 2000);
			break;
		}
		default:
		break;
	}
#endif
}

void FPICOXRInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const
{
	MinFrequency = 0.f;
	MaxFrequency = 1.f;
}

float FPICOXRInput::GetHapticAmplitudeScale() const
{
	return 1.0f;
}

FPICOXRHMD* FPICOXRInput::GetPICOXRHMD()
{
	if (PICOXRHMD == nullptr)
	{
		static FName SystemName(TEXT("PICOXRHMD"));
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
			{
				PICOXRHMD = static_cast<FPICOXRHMD*>(GEngine->XRSystem.Get());
			}
		}
	}
	return PICOXRHMD;
}

int32 FPICOXRInput::UPxr_GetControllerPower(int32 Handness)
{
	if (ControllerType == PxrControllerType::PXR_HB2_Controller)
	{
		return LeftControllerPower;
	}
	else if (ControllerType == PxrControllerType::PXR_CV2_Controller || ControllerType == PxrControllerType::PXR_CV3_Optics_Controller)
	{
		return Handness == 0 ? LeftControllerPower : RightControllerPower;
	}
	else
	{
		return Handness == 0 ? LeftControllerPower : RightControllerPower;
	}
	return 0;
}

bool FPICOXRInput::UPxr_GetControllerConnectState(int32 Handness)
{
	return Handness == 0 ? LeftConnectState : RightConnectState;
}

bool FPICOXRInput::UPxr_GetControllerMainInputHandle(int32& Handness)
{
	if (MainControllerHandle != -1)
	{
		Handness = MainControllerHandle;
		return true;
	}
	return false;
}

bool FPICOXRInput::UPxr_SetControllerMainInputHandle(int32 InHandness)
{
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().SetControllerMainInputHandle(InHandness);
	MainControllerHandle = InHandness;
	return true;
#endif
	return false;
}

void FPICOXRInput::SetKeyMapping()
{
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerX] = FPICOKeyNames::PICOTouch_Left_Thumbstick_X;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerY] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Y;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::Home] = FPICOKeyNames::PICOTouch_Left_Home_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::App] = FPICOKeyNames::PICOTouch_Left_Menu_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::Rocker] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::VolumeUp] = FPICOKeyNames::PICOTouch_Left_VolumeUp_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::VolumeDown] = FPICOKeyNames::PICOTouch_Left_VolumeDown_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::Trigger] = FPICOKeyNames::PICOTouch_Left_Trigger_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::AorX] = FPICOKeyNames::PICOTouch_Left_X_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::BorY] = FPICOKeyNames::PICOTouch_Left_Y_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::Grip] = FPICOKeyNames::PICOTouch_Left_Grip_Click;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerUp] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Up;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerDown] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Down;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerLeft] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Left;
	Buttons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOButton::RockerRight] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Right;


	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerX] = FPICOKeyNames::PICOTouch_Right_Thumbstick_X;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerY] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Y;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::Home] = FPICOKeyNames::PICOTouch_Right_Home_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::App] = FPICOKeyNames::PICOTouch_Right_System_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::Rocker] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::VolumeUp] = FPICOKeyNames::PICOTouch_Right_VolumeUp_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::VolumeDown] = FPICOKeyNames::PICOTouch_Right_VolumeDown_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::Trigger] = FPICOKeyNames::PICOTouch_Right_Trigger_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::AorX] = FPICOKeyNames::PICOTouch_Right_A_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::BorY] = FPICOKeyNames::PICOTouch_Right_B_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::Grip] = FPICOKeyNames::PICOTouch_Right_Grip_Click;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerUp] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Up;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerDown] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Down;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerLeft] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Left;
	Buttons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOButton::RockerRight] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Right;
	
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Pinch] = FPICOKeyNames::PICOHand_Left_Pinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Pinch] = FPICOKeyNames::PICOHand_Right_Pinch;
	
	TouchButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOTouchButton::AorX] = FPICOKeyNames::PICOTouch_Left_X_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOTouchButton::BorY] = FPICOKeyNames::PICOTouch_Left_Y_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOTouchButton::Rocker] = FPICOKeyNames::PICOTouch_Left_Thumbstick_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOTouchButton::Trigger] = FPICOKeyNames::PICOTouch_Left_Trigger_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOTouchButton::Thumbrest] = FPICOKeyNames::PICOTouch_Left_Thumbrest_Touch;

	TouchButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOTouchButton::AorX] = FPICOKeyNames::PICOTouch_Right_A_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOTouchButton::BorY] = FPICOKeyNames::PICOTouch_Right_B_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOTouchButton::Rocker] = FPICOKeyNames::PICOTouch_Right_Thumbstick_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOTouchButton::Trigger] = FPICOKeyNames::PICOTouch_Right_Trigger_Touch;
	TouchButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOTouchButton::Thumbrest] = FPICOKeyNames::PICOTouch_Right_Thumbrest_Touch;
}

void FPICOXRInput::ProcessButtonEvent()
{
	const FInputDeviceId DeviceId=IPlatformInputDeviceMapper::Get().GetDefaultInputDevice();
	FPlatformUserId PlatformUser = IPlatformInputDeviceMapper::Get().GetUserForInputDevice(DeviceId);
	

	if (LeftConnectState)
	{
		PxrControllerInputState state={};
#if PLATFORM_ANDROID
		FPICOXRHMDModule::GetPluginWrapper().GetControllerInputState(EPICOXRControllerHandness::LeftController, &state);
#endif
        int LeftControllerEvent[12] = {0};
        LeftControllerEvent[2] = state.homeValue;
        LeftControllerEvent[3] = state.backValue;
        LeftControllerEvent[4] = state.touchpadValue;
        LeftControllerEvent[5] = state.volumeUp;
        LeftControllerEvent[6] = state.volumeDown;
        LeftControllerEvent[8] = state.batteryValue;
        LeftControllerEvent[9] = state.AXValue;
        LeftControllerEvent[10] = state.BYValue;

		for (int32 i = 2; i < EPICOButton::ButtonCount; i++)
		{
			if (LeftControllerEvent[i]!= LastLeftControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastLeftControllerButtonState[i] = LeftControllerEvent[i];
				if (LeftControllerEvent[i] > 0 )
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
				else if (LeftControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
			}	
		}

		//AxisValue
		LeftControllerTouchPoint.X = state.Joystick.x;
		LeftControllerTouchPoint.Y = state.Joystick.y;
		LeftControllerTriggerValue = state.triggerValue;
		LeftControllerGripValue = state.gripValue;

		//Trigger Grip Button
		if (CurrentVersion >= 0x2000304)
		{
			if (state.triggerclickValue == 1 && LastLeftControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][7], PlatformUser,DeviceId, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][7], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][11], PlatformUser,DeviceId, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][11], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (LeftControllerTriggerValue > 0.67f && LastLeftControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][7], PlatformUser,DeviceId, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && LeftControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][7], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[7] = LeftControllerTriggerValue > 0.67f ? 1 : 0;

			if (LeftControllerGripValue > 0.67f && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][11], PlatformUser,DeviceId, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && LeftControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][11], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[11] = LeftControllerGripValue > 0.67f ? 1 : 0;
		}

		LeftControllerPower = (LeftControllerEvent[8] < 6 ? LeftControllerEvent[8] : LeftControllerPower);

		//Rocker Up/Down/Left/Right
		if (ControllerType == PxrControllerType::PXR_G3_Controller)
		{
			if ((LeftControllerTouchPoint.Y > 0.5f && LeftControllerEvent[4] > 0) && LastLeftControllerButtonState[12] == 0)
			{
				LastLeftControllerButtonState[12] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][12], PlatformUser,DeviceId,  false);
			}
			else if ((LeftControllerTouchPoint.Y <= 0.5f || LeftControllerEvent[4] == 0) && LastLeftControllerButtonState[12] > 0)
			{
				LastLeftControllerButtonState[12] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][12], PlatformUser,DeviceId,  false);
			}

			if ((LeftControllerTouchPoint.Y < -0.5f && LeftControllerEvent[4] > 0) && LastLeftControllerButtonState[13] == 0)
			{
				LastLeftControllerButtonState[13] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][13], PlatformUser,DeviceId,  false);
			}
			else if ((LeftControllerTouchPoint.Y >= -0.5f || LeftControllerEvent[4] == 0) && LastLeftControllerButtonState[13] > 0)
			{
				LastLeftControllerButtonState[13] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][13], PlatformUser,DeviceId,  false);
			}

			if ((LeftControllerTouchPoint.X < -0.5f && LeftControllerEvent[4] > 0) && LastLeftControllerButtonState[14] == 0)
			{
				LastLeftControllerButtonState[14] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][14], PlatformUser,DeviceId,  false);
			}
			else if ((LeftControllerTouchPoint.X >= -0.5f || LeftControllerEvent[4] == 0) && LastLeftControllerButtonState[14] > 0)
			{
				LastLeftControllerButtonState[14] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][14], PlatformUser,DeviceId,  false);
			}

			if ((LeftControllerTouchPoint.X > 0.5f && LeftControllerEvent[4] > 0) && LastLeftControllerButtonState[15] == 0)
			{
				LastLeftControllerButtonState[15] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][15], PlatformUser,DeviceId,  false);
			}
			else if ((LeftControllerTouchPoint.X <= 0.5f || LeftControllerEvent[4] == 0) && LastLeftControllerButtonState[15] > 0)
			{
				LastLeftControllerButtonState[15] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][15], PlatformUser,DeviceId,  false);
			}
		}
		else if(ControllerType != PxrControllerType::PXR_HB2_Controller)
		{
			if(LeftControllerTouchPoint.Y > 0.7f && LastLeftControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][12], PlatformUser,DeviceId, false);
			}
			else if(LeftControllerTouchPoint.Y <= 0.7f && LastLeftControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][12], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[12] = LeftControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.Y < -0.7f && LastLeftControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][13], PlatformUser,DeviceId, false);
			}
			else if (LeftControllerTouchPoint.Y >= -0.7f && LastLeftControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][13], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[13] = LeftControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X < -0.7f && LastLeftControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][14], PlatformUser,DeviceId, false);
			}
			else if (LeftControllerTouchPoint.X >= -0.7f && LastLeftControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][14], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[14] = LeftControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X > 0.7f && LastLeftControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][15], PlatformUser,DeviceId, false);
			}
			else if (LeftControllerTouchPoint.X <= 0.7f && LastLeftControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][15], PlatformUser,DeviceId, false);
			}
			LastLeftControllerButtonState[15] = LeftControllerTouchPoint.X > 0.7f ? 1 : 0;
		}

		if (ControllerType == PxrControllerType::PXR_CV3_Optics_Controller)
		{
			int32 TouchArray[5] = {0};
			TouchArray[0] = state.AXTouchValue;
			TouchArray[1] = state.BYTouchValue;
			TouchArray[2] = state.rockerTouchValue;
			TouchArray[3] = state.triggerTouchValue;
			TouchArray[4] = state.thumbrestTouchValue;
			for (int32 i = 0;i<EPICOTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
				LastLeftTouchButtonState[i]=TouchArray[i];
			}
			
		}
		if (ControllerType != PxrControllerType::PXR_CV3_Optics_Controller && ControllerType != PxrControllerType::PXR_CV2_Controller && ControllerType != PxrControllerType::PXR_HB2_Controller)
		{
			int32 TouchArray[5] = {0};
			TouchArray[0] = state.AXTouchValue;
			TouchArray[1] = state.BYTouchValue;
			TouchArray[2] = state.rockerTouchValue;
			TouchArray[3] = state.triggerTouchValue;
			TouchArray[4] = state.thumbrestTouchValue;
			for (int32 i = 0;i<EPICOTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::LeftController][i], PlatformUser,DeviceId, false);
				}
				LastLeftTouchButtonState[i]=TouchArray[i];
			}
		}
	}
	if (RightConnectState)
	{
		PxrControllerInputState state={};
#if PLATFORM_ANDROID
		FPICOXRHMDModule::GetPluginWrapper().GetControllerInputState(EPICOXRControllerHandness::RightController, &state);
#endif
        int RightControllerEvent[12] = {0};
        RightControllerEvent[2] = state.homeValue;
        RightControllerEvent[3] = state.backValue;
        RightControllerEvent[4] = state.touchpadValue;
        RightControllerEvent[5] = state.volumeUp;
        RightControllerEvent[6] = state.volumeDown;
        RightControllerEvent[8] = state.batteryValue;
        RightControllerEvent[9] = state.AXValue;
        RightControllerEvent[10] = state.BYValue;

		for (int32 i = 2; i < EPICOButton::ButtonCount; i++)
		{
			if (RightControllerEvent[i] != LastRightControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastRightControllerButtonState[i] = RightControllerEvent[i];
				if (RightControllerEvent[i] > 0 )
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
				else if (RightControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
			}	
		}

		RightControllerTouchPoint.X = state.Joystick.x;
		RightControllerTouchPoint.Y = state.Joystick.y;
		RightControllerTriggerValue = state.triggerValue;
		RightControllerGripValue = state.gripValue;

		//Trigger Grip Button
		if (CurrentVersion >= 0x2000304)
		{
			if (state.triggerclickValue == 1 && LastRightControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][7], PlatformUser,DeviceId, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][7], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][11], PlatformUser,DeviceId, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][11], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (RightControllerTriggerValue > 0.67f && LastRightControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][7], PlatformUser,DeviceId, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && RightControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][7], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[7] = RightControllerTriggerValue > 0.67f ? 1 : 0;

			if (RightControllerGripValue > 0.67f && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][11], PlatformUser,DeviceId, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && RightControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][11], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[11] = RightControllerGripValue > 0.67f ? 1 : 0;
		}

		RightControllerPower = (RightControllerEvent[8] < 6 ? RightControllerEvent[8] : RightControllerPower);

		//Rocker Up/Down/Left/Right
		if (ControllerType == PxrControllerType::PXR_G3_Controller)
		{
			if ((RightControllerTouchPoint.Y > 0.5f && RightControllerEvent[4] > 0) && LastRightControllerButtonState[12] == 0)
			{
				LastRightControllerButtonState[12] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][12], PlatformUser,DeviceId,  false);
			}
			else if ((RightControllerTouchPoint.Y <= 0.5f || RightControllerEvent[4] == 0) && LastRightControllerButtonState[12] > 0)
			{
				LastRightControllerButtonState[12] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][12], PlatformUser,DeviceId,  false);
			}

			if ((RightControllerTouchPoint.Y < -0.5f && RightControllerEvent[4] > 0) && LastRightControllerButtonState[13] == 0)
			{
				LastRightControllerButtonState[13] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][13], PlatformUser,DeviceId,  false);
			}
			else if ((RightControllerTouchPoint.Y >= -0.5f || RightControllerEvent[4] == 0) && LastRightControllerButtonState[13] > 0)
			{
				LastRightControllerButtonState[13] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][13], PlatformUser,DeviceId,  false);
			}

			if ((RightControllerTouchPoint.X < -0.5f && RightControllerEvent[4] > 0) && LastRightControllerButtonState[14] == 0)
			{
				LastRightControllerButtonState[14] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][14], PlatformUser,DeviceId,  false);
			}
			else if ((RightControllerTouchPoint.X >= -0.5f || RightControllerEvent[4] == 0) && LastRightControllerButtonState[14] > 0)
			{
				LastRightControllerButtonState[14] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][14], PlatformUser,DeviceId,  false);
			}

			if ((RightControllerTouchPoint.X > 0.5f && RightControllerEvent[4] > 0) && LastRightControllerButtonState[15] == 0)
			{
				LastRightControllerButtonState[15] = 1;
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][15], PlatformUser,DeviceId,  false);
			}
			else if ((RightControllerTouchPoint.X <= 0.5f || RightControllerEvent[4] == 0) && LastRightControllerButtonState[15] > 0)
			{
				LastRightControllerButtonState[15] = 0;
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][15], PlatformUser,DeviceId,  false);
			}
		}
		else if (ControllerType != PxrControllerType::PXR_HB2_Controller)
		{
			if (RightControllerTouchPoint.Y > 0.7f && LastRightControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][12], PlatformUser,DeviceId, false);
			}
			else if (RightControllerTouchPoint.Y <= 0.7f && LastRightControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][12], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[12] = RightControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (RightControllerTouchPoint.Y < -0.7f && LastRightControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][13], PlatformUser,DeviceId, false);
			}
			else if (RightControllerTouchPoint.Y >= -0.7f && LastRightControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][13], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[13] = RightControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X < -0.7f && LastRightControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][14], PlatformUser,DeviceId, false);
			}
			else if (RightControllerTouchPoint.X >= -0.7f && LastRightControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][14], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[14] = RightControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X > 0.7f && LastRightControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][15], PlatformUser,DeviceId, false);
			}
			else if (RightControllerTouchPoint.X <= 0.7f && LastRightControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][15], PlatformUser,DeviceId, false);
			}
			LastRightControllerButtonState[15] = RightControllerTouchPoint.X > 0.7f ? 1 : 0;
		}

		if (ControllerType == PxrControllerType::PXR_CV3_Optics_Controller)
		{
			int32 TouchArray[5] = { 0 };
			TouchArray[0] = state.AXTouchValue;
			TouchArray[1] = state.BYTouchValue;
			TouchArray[2] = state.rockerTouchValue;
			TouchArray[3] = state.triggerTouchValue;
			TouchArray[4] = state.thumbrestTouchValue;
			for (int32 i = 0; i < EPICOTouchButton::ButtonCount; i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
				LastRightTouchButtonState[i]=TouchArray[i];
			}
		}
		if (ControllerType != PxrControllerType::PXR_CV3_Optics_Controller && ControllerType != PxrControllerType::PXR_CV2_Controller && ControllerType != PxrControllerType::PXR_HB2_Controller)
		{
			int32 TouchArray[5] = {0};
			TouchArray[0] = state.AXTouchValue;
			TouchArray[1] = state.BYTouchValue;
			TouchArray[2] = state.rockerTouchValue;
			TouchArray[3] = state.triggerTouchValue;
			TouchArray[4] = state.thumbrestTouchValue;
			for (int32 i = 0;i<EPICOTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::RightController][i], PlatformUser,DeviceId, false);
				}
				LastRightTouchButtonState[i]=TouchArray[i];
			}
		}
	}

	if (bHandTrackingAvailable)
	{
		int32 HandButtonState[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOHandButton::ButtonCount];
		for (int Hand =0;Hand<2;Hand++)
		{
			const EPICOXRHandType DeviceHand = static_cast<EPICOXRHandType>(Hand+1);
			const int32 PinchIndex=(int32)EPICOHandButton::Pinch;
			HandButtonState[Hand][PinchIndex]=GetPinchStrength(DeviceHand)>=1.0f?1:0;
			if (HandButtonState[Hand][PinchIndex]==1&&HandButtonState[Hand][PinchIndex]!=LastHandButtonState[Hand][PinchIndex])
			{
				MessageHandler->OnControllerButtonPressed(HandButtons[Hand][PinchIndex], PlatformUser,DeviceId, false);
			}
			else if (HandButtonState[Hand][PinchIndex]==0&&HandButtonState[Hand][PinchIndex]!=LastHandButtonState[Hand][PinchIndex])
			{
				MessageHandler->OnControllerButtonReleased(HandButtons[Hand][PinchIndex], PlatformUser,DeviceId, false);
			}
			LastHandButtonState[Hand][PinchIndex]=HandButtonState[Hand][PinchIndex];
		}
	}
}

void FPICOXRInput::ProcessButtonAxis()
{
	const FInputDeviceId DeviceId=IPlatformInputDeviceMapper::Get().GetDefaultInputDevice();
	FPlatformUserId PlatformUser = IPlatformInputDeviceMapper::Get().GetUserForInputDevice(DeviceId);
	
	if (LeftConnectState)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Thumbstick_X, PlatformUser,DeviceId, LeftControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Thumbstick_Y, PlatformUser,DeviceId,LeftControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Trigger_Axis, PlatformUser,DeviceId, LeftControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Grip_Axis, PlatformUser,DeviceId, LeftControllerGripValue);
	}
	if (RightConnectState)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Thumbstick_X, PlatformUser,DeviceId, RightControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Thumbstick_Y, PlatformUser,DeviceId, RightControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Trigger_Axis, PlatformUser,DeviceId, RightControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Grip_Axis, PlatformUser,DeviceId, RightControllerGripValue);
	}
	if (bHandTrackingAvailable)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_PinchStrength,PlatformUser,DeviceId, GetPinchStrength(EPICOXRHandType::HandLeft));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_PinchStrength, PlatformUser,DeviceId, GetPinchStrength(EPICOXRHandType::HandRight));
	}
}

void FPICOXRInput::UpdateConnectState()
{
	PxrControllerCapability cap={};
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().GetControllerCapabilities(PXR_CONTROLLER_LEFT, &cap);
	ControllerType = cap.type;
	if (ControllerType == PxrControllerType::PXR_HB2_Controller)
	{
		LeftConnectState = FPICOXRHMDModule::GetPluginWrapper().GetControllerConnectStatus(0) == 0 ? false : true;
		RightConnectState = false;
	}
	else
	{
		LeftConnectState = FPICOXRHMDModule::GetPluginWrapper().GetControllerConnectStatus(0) == 0 ? false : true;
		RightConnectState = FPICOXRHMDModule::GetPluginWrapper().GetControllerConnectStatus(1) == 0 ? false : true;
	}
#endif
	PXR_LOGD(PxrUnreal, "FPICOXRInput::UpdateConnectState ControllerType  %d, LeftConnectState %d, RightConnectState %d", ControllerType, LeftConnectState, RightConnectState);
}

void FPICOXRInput::GetControllerSensorData(const FGameSettings* InSettings, EControllerHand DeviceHand, float WorldToMetersScale, double inPredictedTime, FVector SourcePosition, FQuat SourceOrientation, FRotator& OutOrientation, FVector& OutPosition) const
{
	FQuat Orientation;
	float HeadSensorData[7] = {(float)SourceOrientation.X, (float)SourceOrientation.Y, (float)SourceOrientation.Z, (float)SourceOrientation.W, (float)SourcePosition.X, (float)SourcePosition.Y, (float)SourcePosition.Z};

	PxrControllerTracking tracking;
	uint32_t hand;

	if (DeviceHand == EControllerHand::Left) 
	{
		hand = EPICOXRControllerHandness::LeftController;
	}
	else 
	{
		hand = EPICOXRControllerHandness::RightController;
	}

	FPose Pose;
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().GetControllerTrackingState(hand, inPredictedTime, HeadSensorData, &tracking);
#endif
	
	switch (InSettings->CoordinateType)
	{
	case EPICOXRCoordinateType::Local:
		{
			PICOXRHMD->ConvertPose_Internal(tracking.localControllerPose.pose, Pose, InSettings, WorldToMetersScale);
		}
		break;
	case EPICOXRCoordinateType::Global_BoundarySystem:
		{
			PICOXRHMD->ConvertPose_Internal(tracking.globalControllerPose.pose, Pose, InSettings, WorldToMetersScale);
		}
		break;
	default:
		{
			PICOXRHMD->ConvertPose_Internal(tracking.localControllerPose.pose, Pose, InSettings, WorldToMetersScale);
		}
		break;
	}
	
	OutPosition = Pose.Position;
	OutOrientation = Pose.Orientation.Rotator();

	if (DeviceHand == EControllerHand::Left)
	{
		OutPosition += (Pose.Orientation * OriginOffsetL) * WorldToMetersScale;
	}
	else if (DeviceHand == EControllerHand::Right)
	{
		OutPosition += (Pose.Orientation * OriginOffsetR) * WorldToMetersScale;
	}

}

void FPICOXRInput::OnControllerMainChangedDelegate(int32 Handness)
{
	PXR_LOGD(PxrUnreal, "FPICOXRInput::OnControllerMainChangedDelegate Handness:%d", Handness);
	UpdateConnectState();
#if PLATFORM_ANDROID
	FPICOXRHMDModule::GetPluginWrapper().GetControllerMainInputHandle(&MainControllerHandle);
#endif
}

void FPICOXRInput::OnControllerConnectChangedDelegate(int32 Handness, int32 State)
{
	PXR_LOGD(PxrUnreal, "FPICOXRInput::OnControllerConnectChangedDelegate Handness:%d,State:%d", Handness, State);
	UpdateConnectState();
}

bool FPICOXRInput::UPxr_GetControllerEnableHomeKey()
{
	bool enable = false;
#if PLATFORM_ANDROID
	if (Settings)
	{
		enable = Settings->bEnableHomeKey;
	}
#endif
	return enable;
}

const FPICOXRInput::FPICOXRHandState& FPICOXRInput::GetLeftHandState() const
{
	return HandStates[0];
}

const FPICOXRInput::FPICOXRHandState& FPICOXRInput::GetRightHandState() const
{
	return HandStates[1];
}

void FPICOXRInput::UpdateHandState()
{
	check(IsInGameThread())

#if PLATFORM_WINDOWS && WITH_EDITOR
	if (UPICOXRInputFunctionLibrary::IsHandTrackingEnabled())
	{
		const float EditorWorldToMetersScale = GWorld->GetWorldSettings()->WorldToMeters;
		for (int hand = 0; hand < 2; ++hand)
		{
			FPICOXRHandState& HandState = HandStates[hand];

			if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerJointLocationsWithPT(hand, CurrentFramePredictedTime, &HandState.HandJointLocations) != 0) { return; }
			if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerAimStateWithPT(hand,CurrentFramePredictedTime,&HandState.AimState)!=0){return;}

		
			HandState.ReceivedJointPoses = static_cast<bool>(HandState.HandJointLocations.isActive);
			if (HandState.ReceivedJointPoses)
			{
				HandState.Status = HandState.AimState.Status;

				HandState.PinchStrengthIndex = HandState.AimState.pinchStrengthIndex;
				HandState.PinchStrengthMiddle = HandState.AimState.pinchStrengthMiddle;
				HandState.PinchStrengthRing = HandState.AimState.pinchStrengthRing;
				HandState.PinchStrengthLittle = HandState.AimState.pinchStrengthLittle;
				HandState.TouchStrengthRay = HandState.AimState.ClickStrength;
			
				const FVector AimLocation = PxrBoneVectorToFVector(HandState.AimState.aimPose.position, EditorWorldToMetersScale);
				const FQuat AimRotation=PxrBoneQuatToFQuat(HandState.AimState.aimPose.orientation);
				HandState.AimPose.SetLocation(AimLocation);
				HandState.AimPose.SetRotation(AimRotation);
				
				HandState.ReceivedJointPoses = static_cast<bool>(HandState.HandJointLocations.isActive);
				//Todo:For Now Set to 1.0
				//HandState.HandScale = HandState.HandJointLocations.HandScale;
				HandState.HandScale=1.0;
				for (int keyIndex = 0; keyIndex < XR_HAND_JOINT_COUNT_MAX; ++keyIndex)
				{
					const PxrHandJointsLocation& JoinLocation = HandState.HandJointLocations.jointLocations[keyIndex];
					const FVector Location = PxrBoneVectorToFVector(JoinLocation.pose.position, EditorWorldToMetersScale);
					FQuat Rotation = PxrBoneQuatToFQuat(JoinLocation.pose.orientation);

					if (!Location.ContainsNaN() && !Rotation.ContainsNaN() && Rotation.IsNormalized())
					{
						HandState.KeypointTransforms[keyIndex].SetLocation(Location);
						HandState.KeypointTransforms[keyIndex].SetRotation(Rotation);
					}
					HandState.Radii[keyIndex] = JoinLocation.radius * EditorWorldToMetersScale;
					HandState.SpaceLocationFlags[keyIndex] = JoinLocation.locationFlags;
				}
			}
		}
	}
	
#elif PLATFORM_ANDROID&&PLATFORM_64BITS
	if (!bHandTrackingAvailable || CurrentVersion < 0x2000309 || PICOXRHMD == nullptr || !PICOXRHMD->NextGameFrameToRender_GameThread.IsValid())
	{
		return;
	}
	const FPXRGameFrame* CurrentFrame = PICOXRHMD->NextGameFrameToRender_GameThread.Get();
	EPICOXRCoordinateType CoordinateType = EPICOXRCoordinateType::Local;

	if (CurrentFrame)
	{
		CurrentFramePredictedTime = CurrentFrame->predictedDisplayTimeMs;
	}
	const FGameSettings* CurrentSettings = PICOXRHMD->GameSettings.Get();
	if (CurrentSettings)
	{
		CoordinateType = CurrentSettings->CoordinateType;
	}

	const float WorldToMetersScale = PICOXRHMD->GetWorldToMetersScale();

	//Update HandState
	for (int hand = 0; hand < 2; ++hand)
	{
		FPICOXRHandState& HandState = HandStates[hand];
		switch (CoordinateType)
		{
			case EPICOXRCoordinateType::Local:
				{
					if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerAimStateWithPT(hand,CurrentFramePredictedTime,&HandState.AimState)!=0){return;}
					if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerJointLocationsWithPT(hand,CurrentFramePredictedTime,&HandState.HandJointLocations)!=0){return;}
				}
				break;
			case EPICOXRCoordinateType::Global_BoundarySystem:
				{
					if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerAimStateWithPTFG(hand,CurrentFramePredictedTime,&HandState.AimState)!=0){return;}
					if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerJointLocationsWithPTFG(hand,CurrentFramePredictedTime,&HandState.HandJointLocations)!=0){return;}
				}
				break;
			default:
				return;
		}
		
		HandState.ReceivedJointPoses = static_cast<bool>(HandState.HandJointLocations.isActive);
		if (HandState.ReceivedJointPoses)
		{
			HandState.Status = HandState.AimState.Status;
			HandState.PinchStrengthIndex = HandState.AimState.pinchStrengthIndex;
			HandState.PinchStrengthMiddle = HandState.AimState.pinchStrengthMiddle;
			HandState.PinchStrengthRing = HandState.AimState.pinchStrengthRing;
			HandState.PinchStrengthLittle = HandState.AimState.pinchStrengthLittle;
			HandState.TouchStrengthRay = HandState.AimState.ClickStrength;

			FPose AimPose = FPose();
			PICOXRHMD->ConvertPose_Internal(HandState.AimState.aimPose, AimPose, CurrentSettings, WorldToMetersScale);
			if (!AimPose.Position.ContainsNaN() && !AimPose.Orientation.ContainsNaN() && AimPose.Orientation.IsNormalized())
			{
				HandState.AimPose.SetLocation(AimPose.Position);
				HandState.AimPose.SetRotation(AimPose.Orientation);
			}

			HandState.ReceivedJointPoses = static_cast<bool>(HandState.HandJointLocations.isActive);
			if (FPICOXRHMDModule::GetPluginWrapper().GetHandTrackerHandScale(hand,&HandState.HandScale)!=0)
			{
				HandState.HandScale=1.0;
				PXR_LOGE(PxrUnreal,"GetHandTrackerHandScale Failed!!! Set HandScale=1.0");
			}
			for (int keyIndex = 0; keyIndex < XR_HAND_JOINT_COUNT_MAX; ++keyIndex)
			{
				const PxrHandJointsLocation& JoinLocation = HandState.HandJointLocations.jointLocations[keyIndex];
				FPose JoinPose = FPose();
				PICOXRHMD->ConvertPose_Internal(JoinLocation.pose, JoinPose, CurrentSettings, WorldToMetersScale);
				if (!JoinPose.Position.ContainsNaN() && !JoinPose.Orientation.ContainsNaN() && JoinPose.Orientation.IsNormalized())
				{
					HandState.KeypointTransforms[keyIndex].SetLocation(JoinPose.Position);
					HandState.KeypointTransforms[keyIndex].SetRotation(JoinPose.Orientation);
				}
				HandState.Radii[keyIndex] = JoinLocation.radius * WorldToMetersScale;
				HandState.SpaceLocationFlags[keyIndex] = JoinLocation.locationFlags;
			}
		}
	}
#endif
}

void FPICOXRInput::SetAppHandTrackingEnabled(bool Enabled)
{
#if PLATFORM_ANDROID&&PLATFORM_64BITS
	if (CurrentVersion  >= 0x2000306)
	{
		FPICOXRHMDModule::GetPluginWrapper().SetAppHandTrackingEnabled(Enabled);
	}
#endif
}

void FPICOXRInput::AddNonExistingKey(const TArray<FKey>& ExistAllKeys, const FKeyDetails& KeyDetails)
{
	if (!ExistAllKeys.Contains(KeyDetails.GetKey()))
	{
		EKeys::AddKey(KeyDetails);
	}
}

void FPICOXRInput::RegisterKeys()
{
	const FName NAME_PICOTouchController(TEXT("PICOTouch"));
	if (EKeys::GetMenuCategoryDisplayName(NAME_PICOTouchController).ToString()!="PICO Touch")
	{
		EKeys::AddMenuCategoryDisplayInfo(NAME_PICOTouchController, LOCTEXT("PICOTouchSubCategory", "PICO Touch"), TEXT("GraphEditor.PadEvent_16x"));
	}

	const FName NAME_PICOHandController(TEXT("PICOHand"));
	if (EKeys::GetMenuCategoryDisplayName(NAME_PICOHandController).ToString()!="PICO Hand")
	{
		EKeys::AddMenuCategoryDisplayInfo(NAME_PICOHandController, LOCTEXT("PICOHandSubCategory", "PICO Hand"), TEXT("GraphEditor.PadEvent_16x"));
	}

	TArray<FKey> ExistAllKeys;
	EKeys::GetAllKeys(ExistAllKeys);

	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_X_Click, LOCTEXT("PICOTouch_Left_X_Click", "PICO Touch (L) X Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Y_Click, LOCTEXT("PICOTouch_Left_Y_Click", "PICO Touch (L) Y Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_X_Touch, LOCTEXT("PICOTouch_Left_X_Touch", "PICO Touch (L) X Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Y_Touch, LOCTEXT("PICOTouch_Left_Y_Touch", "PICO Touch (L) Y Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Menu_Click, LOCTEXT("PICOTouch_Left_Menu_Click", "PICO Touch (L) Menu"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Grip_Click, LOCTEXT("PICOTouch_Left_Grip_Click", "PICO Touch (L) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Grip_Axis, LOCTEXT("PICOTouch_Left_Grip_Axis", "PICO Touch (L) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Click, LOCTEXT("PICOTouch_Left_Trigger_Click", "PICO Touch (L) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Axis, LOCTEXT("PICOTouch_Left_Trigger_Axis", "PICO Touch (L) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Touch, LOCTEXT("PICOTouch_Left_Trigger_Touch", "PICO Touch (L) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_X, LOCTEXT("PICOTouch_Left_Thumbstick_X", "PICO Touch (L) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Y, LOCTEXT("PICOTouch_Left_Thumbstick_Y", "PICO Touch (L) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Click, LOCTEXT("PICOTouch_Left_Thumbstick_Click", "PICO Touch (L) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Touch, LOCTEXT("PICOTouch_Left_Thumbstick_Touch", "PICO Touch (L) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Home_Click, LOCTEXT("PICOTouch_Left_Home_Click", "PICO Touch (L) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_VolumeUp_Click, LOCTEXT("PICOTouch_Left_VolumeUp_Click", "PICO Touch (L) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_VolumeDown_Click, LOCTEXT("PICOTouch_Left_VolumeDown_Click", "PICO Touch (L) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbrest_Touch, LOCTEXT("PICOTouch_Left_Thumbrest_Touch", "PICO Touch (L) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Up, LOCTEXT("PICOTouch_Left_Thumbstick_Up", "PICO Touch (L) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Down, LOCTEXT("PICOTouch_Left_Thumbstick_Down", "PICO Touch (L) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Left, LOCTEXT("PICOTouch_Left_Thumbstick_Left", "PICO Touch (L) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Right, LOCTEXT("PICOTouch_Left_Thumbstick_Right", "PICO Touch (L) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_A_Click, LOCTEXT("PICOTouch_Right_A_Click", "PICO Touch (R) A Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_B_Click, LOCTEXT("PICOTouch_Right_B_Click", "PICO Touch (R) B Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_A_Touch, LOCTEXT("PICOTouch_Right_A_Touch", "PICO Touch (R) A Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_B_Touch, LOCTEXT("PICOTouch_Right_B_Touch", "PICO Touch (R) B Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_System_Click, LOCTEXT("PICOTouch_Right_System_Click", "PICO Touch (R) System"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Grip_Click, LOCTEXT("PICOTouch_Right_Grip_Click", "PICO Touch (R) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Grip_Axis, LOCTEXT("PICOTouch_Right_Grip_Axis", "PICO Touch (R) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Click, LOCTEXT("PICOTouch_Right_Trigger_Click", "PICO Touch (R) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Axis, LOCTEXT("PICOTouch_Right_Trigger_Axis", "PICO Touch (R) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Touch, LOCTEXT("PICOTouch_Right_Trigger_Touch", "PICO Touch (R) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_X, LOCTEXT("PICOTouch_Right_Thumbstick_X", "PICO Touch (R) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Y, LOCTEXT("PICOTouch_Right_Thumbstick_Y", "PICO Touch (R) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Click, LOCTEXT("PICOTouch_Right_Thumbstick_Click", "PICO Touch (R) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Touch, LOCTEXT("PICOTouch_Right_Thumbstick_Touch", "PICO Touch (R) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Home_Click, LOCTEXT("PICOTouch_Right_Home_Click", "PICO Touch (R) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_VolumeUp_Click, LOCTEXT("PICOTouch_Right_VolumeUp_Click", "PICO Touch (R) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_VolumeDown_Click, LOCTEXT("PICOTouch_Right_VolumeDown_Click", "PICO Touch (R) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbrest_Touch, LOCTEXT("PICOTouch_Right_Thumbrest_Touch", "PICO Touch (R) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Up, LOCTEXT("PICOTouch_Right_Thumbstick_Up", "PICO Touch (R) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Down, LOCTEXT("PICOTouch_Right_Thumbstick_Down", "PICO Touch (R) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Left, LOCTEXT("PICOTouch_Right_Thumbstick_Left", "PICO Touch (R) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Right, LOCTEXT("PICOTouch_Right_Thumbstick_Right", "PICO Touch (R) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));

	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOHand_Left_Pinch, LOCTEXT("PICOHand_Left_Pinch", "PICO Hand (L) Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOHand_Right_Pinch, LOCTEXT("PICOHand_Right_Pinch", "PICO Hand (R) Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOHand_Left_PinchStrength, LOCTEXT("PICOHand_Left_PinchStrength", "PICO Hand (L) Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D| FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	AddNonExistingKey(ExistAllKeys,FKeyDetails(FPICOTouchKey::PICOHand_Right_PinchStrength, LOCTEXT("PICOHand_Right_PinchStrength", "PICO Hand (R) Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D| FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
}

#undef LOCTEXT_NAMESPACE
