//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Input.h"
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

#if PLATFORM_ANDROID
#include "Misc/CoreDelegates.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "PxrInput.h"
#endif
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
	,ControllerType(EPICOInputType::Unknown)
	,CurrentVersion(0)
{
	PICOXRHMD = GetPICOXRHMD();
#if PLATFORM_ANDROID
	Settings = GetMutableDefault<UPICOXRSettings>();
	UpdateConnectState();
	Pxr_GetControllerMainInputHandle(&MainControllerHandle);
	if (Settings)
	{
		Pxr_SetControllerEnableKey(Settings->bEnableHomeKey, PxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME);
	}
	Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
#endif
	RegisterKeys();
	SetKeyMapping();
	IModularFeatures::Get().RegisterModularFeature(IMotionController::GetModularFeatureName(), static_cast<IMotionController*>(this));
	IModularFeatures::Get().RegisterModularFeature(IPXR_HandTracker::GetModularFeatureName(), static_cast<IPXR_HandTracker*>(this));
	if (UPICOXRInputFunctionLibrary::IsHandTrackingEnabled())
	{
		bHandTrackingAvailable = true;
	}
}

FPICOXRInput::~FPICOXRInput()
{
	IModularFeatures::Get().UnregisterModularFeature(IMotionController::GetModularFeatureName(), static_cast<IMotionController*>(this));
	IModularFeatures::Get().UnregisterModularFeature(IPXR_HandTracker::GetModularFeatureName(), static_cast<IPXR_HandTracker*>(this));
}

void FPICOXRInput::Tick(float DeltaTime)
{
}

void FPICOXRInput::SendControllerEvents()
{
#if PLATFORM_ANDROID
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
#if PLATFORM_ANDROID
	switch (ChannelType)
	{
		case FForceFeedbackChannelType::LEFT_LARGE:
		case FForceFeedbackChannelType::LEFT_SMALL:
		{
			Pxr_SetControllerVibration(0, Value, 10);
			break;
		}
		case FForceFeedbackChannelType::RIGHT_LARGE:
		case FForceFeedbackChannelType::RIGHT_SMALL:
		{
			Pxr_SetControllerVibration(1, Value, 10);
			break;
		}
		default:
			break;
	}
#endif
}

void FPICOXRInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values)
{
#if PLATFORM_ANDROID
	if (values.LeftLarge > 0)
	{
		Pxr_SetControllerVibration(0, values.LeftLarge, 10);
	}
	if (values.RightLarge >0)
	{
		Pxr_SetControllerVibration(1, values.RightLarge, 10);
	}
#endif
}

FQuat FPICOXRInput::GetBoneRotation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		FTransform OutTransform;
		float OutRadius;
		if (GetKeypointState(DeviceHand, BoneId, OutTransform, OutRadius))
		{
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
			if (DeviceHand == EPICOXRHandType::HandLeft)
			{
				const FQuat CalibratedOrientation = OutTransform.GetRotation() * LeftRootFixupOrientation* LeftRootFixupOrientation2;
				OutTransform.SetRotation(CalibratedOrientation);
			}
			else if (DeviceHand == EPICOXRHandType::HandRight)
			{
				const FQuat CalibratedOrientation = OutTransform.GetRotation() * RightRootFixupOrientation* RightRootFixupOrientation2;
				OutTransform.SetRotation(CalibratedOrientation);
			}

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

FTransform FPICOXRInput::GetPointerPose(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		if (HandState.ReceivedJointPoses)
		{
			FQuat CalibratedOrientation;
			FTransform OutTransform;
			if (DeviceHand == EPICOXRHandType::HandLeft)
			{
				CalibratedOrientation = HandState.AimPose.GetRotation()* LeftRootFixupOrientation3;
			}
			else if (DeviceHand == EPICOXRHandType::HandRight)
			{
				CalibratedOrientation = HandState.AimPose.GetRotation()* RightRootFixupOrientation3;
			}
			OutTransform.SetRotation(CalibratedOrientation);
			OutTransform.SetLocation(HandState.AimPose.GetLocation());
			return OutTransform;
		}
	}
	return FTransform();
}

bool FPICOXRInput::IsHandTracked(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_COMPUTED_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsAimValid(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_VALID_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsAimRayTouchedValid(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_RAY_TOUCHED_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsSystemGestureInProgress(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_SYSTEM_GESTURE_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsDominantHand(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_DOMINANT_HAND_BIT)) != 0);
	}
	return false;
}

bool FPICOXRInput::IsMenuPressed(const EPICOXRHandType DeviceHand)
{
	if (DeviceHand != EPICOXRHandType::None)
	{
		const FPICOXRHandState& HandState = (DeviceHand == EPICOXRHandType::HandLeft) ? GetLeftHandState() : GetRightHandState();
		return ((HandState.Status & StaticCast<uint64>(XrHandTrackingAimFlags::XR_HAND_TRACKING_AIM_MENU_PRESSED_BIT)) != 0);
	}
	return false;
}

float FPICOXRInput::GetClickStrength(const EPICOXRHandType DeviceHand)
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
#if PLATFORM_ANDROID
	if (CurrentVersion  >= 0x2000307)
	{
		PxrActiveInputDeviceType type ;
		Pxr_GetHandTrackerActiveInputType(&type);
		return (EPICOXRActiveInputDevice)type;
	}
#endif
	return EPICOXRActiveInputDevice::NoneActive;
}

bool FPICOXRInput::IsHandTrackingStateValid() const
{
	bool State = false;
#if PLATFORM_ANDROID&&PLATFORM_64BITS
	if (CurrentVersion  >= 0x2000306)
	{
		Pxr_GetHandTrackerSettingState(&State);
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

bool FPICOXRInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const
{
	double predictedDisplayTimeMs = 0.0;
	FVector SourcePosition = FVector::ZeroVector;
	FQuat SourceOrientation = FQuat::Identity;
	FPXRGameFrame* CurrentFrame = nullptr;
	if (IsInRenderingThread() && PICOXRHMD)
	{
		CurrentFrame = PICOXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PICOXRHMD)
	{
		CurrentFrame = PICOXRHMD->NextGameFrameToRender_GameThread.Get();
	}
	if (CurrentFrame)
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
#if PLATFORM_ANDROID
	if (ControllerType == G2)
	{
		if (LeftConnectState)
		{
			GetControllerSensorData(EControllerHand::Left, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
	}
	else if (ControllerType == Neo2 || ControllerType == Neo3)
	{
		if (LeftConnectState && DeviceHand == EControllerHand::Left)
		{
			GetControllerSensorData(DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
		else if (RightConnectState && DeviceHand == EControllerHand::Right)
		{
			GetControllerSensorData(DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
}
	else
	{
		if (LeftConnectState && DeviceHand == EControllerHand::Left)
		{
			GetControllerSensorData(DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
		else if (RightConnectState && DeviceHand == EControllerHand::Right)
		{
			GetControllerSensorData(DeviceHand, WorldToMetersScale, predictedDisplayTimeMs, SourcePosition, SourceOrientation, OutOrientation, OutPosition);
			return true;
		}
	}
#endif
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
	if (IsInRenderingThread() && PICOXRHMD)
	{
		CurrentFrame = PICOXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PICOXRHMD)
	{
		CurrentFrame = PICOXRHMD->NextGameFrameToRender_GameThread.Get();
	}
	if (CurrentFrame)
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
		GetControllerSensorData(DeviceHand, WorldToMetersScale, PredictedTime, SourcePosition, SourceOrientation, PredictedRotation, PredictedLocation);
	}
	else if (RightConnectState && DeviceHand == EControllerHand::Right)
	{
		GetControllerSensorData(DeviceHand, WorldToMetersScale, PredictedTime, SourcePosition, SourceOrientation, PredictedRotation, PredictedLocation);
	}
	OutPosition = PredictedLocation;
	OutOrientation = PredictedRotation;
	return true;
}

ETrackingStatus FPICOXRInput::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const
{
	if (ControllerIndex == 0 && (DeviceHand == EControllerHand::Left || DeviceHand == EControllerHand::Right || DeviceHand == EControllerHand::AnyHand))
	{
		return ETrackingStatus::Tracked;
	}
	return ETrackingStatus::NotTracked;
}

void FPICOXRInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values)
{
#if PLATFORM_ANDROID
	switch (Hand)
	{
		case 0:
		{
			Pxr_SetControllerVibration(0, Values.Amplitude * GetHapticAmplitudeScale(), 2000);
			break;
		}
		case 1:
		{
			Pxr_SetControllerVibration(1, Values.Amplitude * GetHapticAmplitudeScale(), 2000);
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
	if (ControllerType == G2)
	{
		return LeftControllerPower;
	}
	else if (ControllerType == Neo2 || ControllerType == Neo3)
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
	Pxr_SetControllerMainInputHandle(InHandness);
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
	
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Index] = FPICOKeyNames::PICOHand_Left_IndexPinch;
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Middle] = FPICOKeyNames::PICOHand_Left_MiddlePinch;
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Pinky] = FPICOKeyNames::PICOHand_Left_PinkyPinch;
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::Ring] = FPICOKeyNames::PICOHand_Left_RingPinch;
	HandButtons[(int32)EPICOXRControllerHandness::LeftController][(int32)EPICOHandButton::ThumbClick] = FPICOKeyNames::PICOHand_Left_ThumbClick;
	
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Index] = FPICOKeyNames::PICOHand_Right_IndexPinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Middle] = FPICOKeyNames::PICOHand_Right_MiddlePinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Pinky] = FPICOKeyNames::PICOHand_Right_PinkyPinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::Ring] = FPICOKeyNames::PICOHand_Right_RingPinch;
	HandButtons[(int32)EPICOXRControllerHandness::RightController][(int32)EPICOHandButton::ThumbClick] = FPICOKeyNames::PICOHand_Right_ThumbClick;
	
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
#if PLATFORM_ANDROID
	if (LeftConnectState)
	{
		PxrControllerInputState state;
		Pxr_GetControllerInputState(EPICOXRControllerHandness::LeftController, &state);
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
					MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][i], 0, false);
				}
				else if (LeftControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][i], 0, false);
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
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][7], 0, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][7], 0, false);
			}
			LastLeftControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][11], 0, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][11], 0, false);
			}
			LastLeftControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (LeftControllerTriggerValue > 0.67f && LastLeftControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][7], 0, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && LeftControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][7], 0, false);
			}
			LastLeftControllerButtonState[7] = LeftControllerTriggerValue > 0.67f ? 1 : 0;

			if (LeftControllerGripValue > 0.67f && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][11], 0, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && LeftControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][11], 0, false);
			}
			LastLeftControllerButtonState[11] = LeftControllerGripValue > 0.67f ? 1 : 0;
		}

		LeftControllerPower = (LeftControllerEvent[8] < 6 ? LeftControllerEvent[8] : LeftControllerPower);

		//Rocker Up/Down/Left/Right
		if(ControllerType != G2)
		{
			if(LeftControllerTouchPoint.Y > 0.7f && LastLeftControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][12], 0, false);
			}
			else if(LeftControllerTouchPoint.Y <= 0.7f && LastLeftControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][12], 0, false);
			}
			LastLeftControllerButtonState[12] = LeftControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.Y < -0.7f && LastLeftControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][13], 0, false);
			}
			else if (LeftControllerTouchPoint.Y >= -0.7f && LastLeftControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][13], 0, false);
			}
			LastLeftControllerButtonState[13] = LeftControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X < -0.7f && LastLeftControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][14], 0, false);
			}
			else if (LeftControllerTouchPoint.X >= -0.7f && LastLeftControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][14], 0, false);
			}
			LastLeftControllerButtonState[14] = LeftControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X > 0.7f && LastLeftControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::LeftController][15], 0, false);
			}
			else if (LeftControllerTouchPoint.X <= 0.7f && LastLeftControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::LeftController][15], 0, false);
			}
			LastLeftControllerButtonState[15] = LeftControllerTouchPoint.X > 0.7f ? 1 : 0;
		}

		if (ControllerType == Neo3)
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
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::LeftController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::LeftController][i], 0, false);
				}
				LastLeftTouchButtonState[i]=TouchArray[i];
			}
			
		}
		if (ControllerType != Neo3 && ControllerType != Neo2 && ControllerType != G2)
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
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::LeftController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::LeftController][i], 0, false);
				}
				LastLeftTouchButtonState[i]=TouchArray[i];
			}
		}
	}
	if (RightConnectState)
	{
		PxrControllerInputState state;
		Pxr_GetControllerInputState(EPICOXRControllerHandness::RightController, &state);
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
					MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][i], 0, false);
				}
				else if (RightControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][i], 0, false);
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
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][7], 0, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][7], 0, false);
			}
			LastRightControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][11], 0, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][11], 0, false);
			}
			LastRightControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (RightControllerTriggerValue > 0.67f && LastRightControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][7], 0, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && RightControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][7], 0, false);
			}
			LastRightControllerButtonState[7] = RightControllerTriggerValue > 0.67f ? 1 : 0;

			if (RightControllerGripValue > 0.67f && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][11], 0, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && RightControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][11], 0, false);
			}
			LastRightControllerButtonState[11] = RightControllerGripValue > 0.67f ? 1 : 0;
		}

		RightControllerPower = (RightControllerEvent[8] < 6 ? RightControllerEvent[8] : RightControllerPower);

		//Rocker Up/Down/Left/Right
		if (ControllerType != G2)
		{
			if (RightControllerTouchPoint.Y > 0.7f && LastRightControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][12], 0, false);
			}
			else if (RightControllerTouchPoint.Y <= 0.7f && LastRightControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][12], 0, false);
			}
			LastRightControllerButtonState[12] = RightControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (RightControllerTouchPoint.Y < -0.7f && LastRightControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][13], 0, false);
			}
			else if (RightControllerTouchPoint.Y >= -0.7f && LastRightControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][13], 0, false);
			}
			LastRightControllerButtonState[13] = RightControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X < -0.7f && LastRightControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][14], 0, false);
			}
			else if (RightControllerTouchPoint.X >= -0.7f && LastRightControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][14], 0, false);
			}
			LastRightControllerButtonState[14] = RightControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X > 0.7f && LastRightControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPICOXRControllerHandness::RightController][15], 0, false);
			}
			else if (RightControllerTouchPoint.X <= 0.7f && LastRightControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPICOXRControllerHandness::RightController][15], 0, false);
			}
			LastRightControllerButtonState[15] = RightControllerTouchPoint.X > 0.7f ? 1 : 0;
		}

		if (ControllerType == Neo3)
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
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::RightController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::RightController][i], 0, false);
				}
				LastRightTouchButtonState[i]=TouchArray[i];
			}
		}
		if (ControllerType != Neo3 && ControllerType != Neo2 && ControllerType != G2)
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
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPICOXRControllerHandness::RightController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPICOXRControllerHandness::RightController][i], 0, false);
				}
				LastRightTouchButtonState[i]=TouchArray[i];
			}
		}
	}
#endif
	if (bHandTrackingAvailable)
	{
		int32 HandButtonState[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOHandButton::ButtonCount];
		for (int Hand =0;Hand<2;Hand++)
		{
			const EPICOXRHandType DeviceHand = static_cast<EPICOXRHandType>(Hand+1);
			for (int Key=0;Key<4;Key++)
			{
				const EPICOXRHandFinger Finger =static_cast<EPICOXRHandFinger>(Key+1);
				HandButtonState[Hand][Key]=GetFingerIsPinching(DeviceHand,Finger)?1:0;
				if(HandButtonState[Hand][Key]==1&&HandButtonState[Hand][Key]!=LastHandButtonState[Hand][Key])
				{
					MessageHandler->OnControllerButtonPressed(HandButtons[Hand][Key], 0, false);
				}
				else if (HandButtonState[Hand][Key]==0&&HandButtonState[Hand][Key]!=LastHandButtonState[Hand][Key])
				{
					MessageHandler->OnControllerButtonReleased(HandButtons[Hand][Key], 0, false);
				}
				LastHandButtonState[Hand][Key]=HandButtonState[Hand][Key];
			}
			HandButtonState[Hand][4]=GetClickStrength(DeviceHand)>=1.0f?1:0;
			if (HandButtonState[Hand][4]==1&&HandButtonState[Hand][4]!=LastHandButtonState[Hand][4])
			{
				MessageHandler->OnControllerButtonPressed(HandButtons[Hand][4], 0, false);
			}
			else if (HandButtonState[Hand][4]==0&&HandButtonState[Hand][4]!=LastHandButtonState[Hand][4])
			{
				MessageHandler->OnControllerButtonReleased(HandButtons[Hand][4], 0, false);
			}
			LastHandButtonState[Hand][4]=HandButtonState[Hand][4];
		}
	}
}

void FPICOXRInput::ProcessButtonAxis()
{
	if (LeftConnectState)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Thumbstick_X, 0, LeftControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Thumbstick_Y, 0, LeftControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Trigger_Axis, 0, LeftControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Left_Grip_Axis, 0, LeftControllerGripValue);
	}
	if (RightConnectState)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Thumbstick_X, 0, RightControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Thumbstick_Y, 0, RightControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Trigger_Axis, 0, RightControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOTouch_Right_Grip_Axis, 0, RightControllerGripValue);
	}
	if (bHandTrackingAvailable)
	{
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_IndexPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandLeft,EPICOXRHandFinger::Index));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_MiddlePinchStrength, 0,GetFingerPinchStrength(EPICOXRHandType::HandLeft,EPICOXRHandFinger::Middle));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_PinkyPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandLeft,EPICOXRHandFinger::Pinky));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_RingPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandLeft,EPICOXRHandFinger::Ring));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Left_ThumbClickStrength, 0, GetClickStrength(EPICOXRHandType::HandLeft));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_IndexPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandRight,EPICOXRHandFinger::Index));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_MiddlePinchStrength, 0,GetFingerPinchStrength(EPICOXRHandType::HandRight,EPICOXRHandFinger::Middle));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_PinkyPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandRight,EPICOXRHandFinger::Pinky));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_RingPinchStrength, 0, GetFingerPinchStrength(EPICOXRHandType::HandRight,EPICOXRHandFinger::Ring));
		MessageHandler->OnControllerAnalog(FPICOKeyNames::PICOHand_Right_ThumbClickStrength, 0, GetClickStrength(EPICOXRHandType::HandRight));
	}
}

void FPICOXRInput::UpdateConnectState()
{
#if PLATFORM_ANDROID
	PxrControllerCapability cap;
	Pxr_GetControllerCapabilities(PXR_CONTROLLER_LEFT, &cap);
	ControllerType = static_cast<EPICOInputType>(cap.type);
	if (ControllerType == G2)
	{
		LeftConnectState = Pxr_GetControllerConnectStatus(0) == 0 ? false : true;
		RightConnectState = false;
	}
	else
	{
		LeftConnectState = Pxr_GetControllerConnectStatus(0) == 0 ? false : true;
		RightConnectState = Pxr_GetControllerConnectStatus(1) == 0 ? false : true;
	}
#endif
	PXR_LOGD(PxrUnreal, "FPICOXRInput::UpdateConnectState ControllerType  %d, LeftConnectState %d, RightConnectState %d", ControllerType, LeftConnectState, RightConnectState);
}

void FPICOXRInput::GetControllerSensorData(EControllerHand DeviceHand, float WorldToMetersScale, double inPredictedTime, FVector SourcePosition, FQuat SourceOrientation, FRotator& OutOrientation, FVector& OutPosition) const
{
#if PLATFORM_ANDROID
	FQuat Orientation;
	float HeadSensorData[7] = {SourceOrientation.X, SourceOrientation.Y, SourceOrientation.Z, SourceOrientation.W, SourcePosition.X, SourcePosition.Y, SourcePosition.Z};

	PxrControllerTracking tracking;
    uint32_t hand;

    if (DeviceHand == EControllerHand::Left) {
        hand = EPICOXRControllerHandness::LeftController;
    } else {
        hand = EPICOXRControllerHandness::RightController;
    }
	Pxr_GetControllerTrackingState(hand, inPredictedTime, HeadSensorData, &tracking);
	
	Orientation.X = tracking.localControllerPose.pose.orientation.x;
	Orientation.Y = tracking.localControllerPose.pose.orientation.y;
	Orientation.Z = tracking.localControllerPose.pose.orientation.z;
	Orientation.W = tracking.localControllerPose.pose.orientation.w;
	OutPosition.X = tracking.localControllerPose.pose.position.x;
	OutPosition.Y = tracking.localControllerPose.pose.position.y;
	OutPosition.Z = tracking.localControllerPose.pose.position.z;

	OutPosition = FVector(-OutPosition.Z * WorldToMetersScale, OutPosition.X * WorldToMetersScale, OutPosition.Y * WorldToMetersScale);
	Orientation = FQuat(-Orientation.Z, Orientation.X, Orientation.Y, -Orientation.W);
	OutOrientation = Orientation.Rotator();
	if (Settings->bIsController3Dof)//Controller 3Dof
	{
		if (!Settings->bIsHMD3Dof)//HMD 6Dof
		{
			OutPosition.Z += WorldToMetersScale * SourcePosition.Y;
		}else //HMD 3Dof
		{
			if (Settings->bEnableNeckModel)
			{
				if (GEngine->XRSystem->GetTrackingOrigin() == EHMDTrackingOrigin::Floor)
				{
					OutPosition.Z += WorldToMetersScale * SourcePosition.Y;
				}
			}	
		}
	}
	if (DeviceHand == EControllerHand::Left)
	{
		OutPosition += (Orientation * OriginOffsetL) * WorldToMetersScale;
	}
	else if (DeviceHand == EControllerHand::Right)
	{
		OutPosition += (Orientation * OriginOffsetR) * WorldToMetersScale;
	}
#endif
}

void FPICOXRInput::OnControllerMainChangedDelegate(int32 Handness)
{
	PXR_LOGD(PxrUnreal, "FPICOXRInput::OnControllerMainChangedDelegate Handness:%d", Handness);
	UpdateConnectState();
#if PLATFORM_ANDROID
	Pxr_GetControllerMainInputHandle(&MainControllerHandle);
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

#if ENGINE_MINOR_VERSION >25
#define FloatAxis Axis1D
#else
#define FloatAxis FloatAxis
#endif
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
	if (!bHandTrackingAvailable||CurrentVersion <0x2000306||PICOXRHMD==nullptr)
	{
		return;
	}

	const float WorldToMetersScale = PICOXRHMD->GetWorldToMetersScale();
#if PLATFORM_ANDROID&&PLATFORM_64BITS
	//Update HandState
	for (int hand = 0; hand < 2; ++hand)
	{
		FPICOXRHandState& HandState = HandStates[hand];
		if (Pxr_GetHandTrackerAimState(hand,&HandState.AimState)!=0){return;}
		if (Pxr_GetHandTrackerJointLocations(hand,&HandState.HandJointLocations)!=0){return;}
		HandState.ReceivedJointPoses = HandState.HandJointLocations.isActive;
		if (HandState.ReceivedJointPoses)
		{
			HandState.Status = HandState.AimState.Status;
			HandState.PinchStrengthIndex = HandState.AimState.pinchStrengthIndex;
			HandState.PinchStrengthMiddle = HandState.AimState.pinchStrengthMiddle;
			HandState.PinchStrengthRing = HandState.AimState.pinchStrengthRing;
			HandState.PinchStrengthLittle = HandState.AimState.pinchStrengthLittle;
			HandState.TouchStrengthRay = HandState.AimState.ClickStrength;
			
			const FVector AimLocation = PxrBoneVectorToFVector(HandState.AimState.aimPose.position, WorldToMetersScale);
			const FQuat AimRotation=PxrRootQuatToFQuat(HandState.AimState.aimPose.orientation);
			HandState.AimPose.SetLocation(AimLocation);
			HandState.AimPose.SetRotation(AimRotation);
			
			HandState.ReceivedJointPoses=HandState.HandJointLocations.isActive;
			HandState.HandScale=HandState.HandJointLocations.HandScale;
			for (int keyIndex = 0; keyIndex < XR_HAND_JOINT_COUNT_MAX; ++keyIndex)
			{
				const PxrHandJointsLocation& JoinLocation = HandState.HandJointLocations.jointLocations[keyIndex];
				const FVector Location = PxrBoneVectorToFVector(JoinLocation.pose.position, WorldToMetersScale);
				FQuat Rotation;
				if (keyIndex == static_cast<int32>(EPICOXRHandJoint::Wrist))
				{
					Rotation=PxrRootQuatToFQuat(JoinLocation.pose.orientation);
				}
				else
				{
					Rotation=PxrBoneQuatToFQuat(hand,JoinLocation.pose.orientation);
				}
				if (!Location.ContainsNaN()&&!Rotation.ContainsNaN()&&Rotation.IsNormalized())
				{
					HandState.KeypointTransforms[keyIndex].SetLocation(Location);
					HandState.KeypointTransforms[keyIndex].SetRotation(Rotation);
				}
				HandState.Radii[keyIndex] = JoinLocation.radius * WorldToMetersScale;
				HandState.SpaceLocationFlags[keyIndex]=JoinLocation.locationFlags;
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
		Pxr_SetAppHandTrackingEnabled(Enabled);
	}
#endif
}

void FPICOXRInput::RegisterKeys()
{
	EKeys::AddMenuCategoryDisplayInfo("PICOTouch", LOCTEXT("PICOTouchSubCategory", "PICO Touch"), TEXT("GraphEditor.PadEvent_16x"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_X_Click, LOCTEXT("PICOTouch_Left_X_Click", "PICO Touch (L) X Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Y_Click, LOCTEXT("PICOTouch_Left_Y_Click", "PICO Touch (L) Y Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_X_Touch, LOCTEXT("PICOTouch_Left_X_Touch", "PICO Touch (L) X Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Y_Touch, LOCTEXT("PICOTouch_Left_Y_Touch", "PICO Touch (L) Y Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Menu_Click, LOCTEXT("PICOTouch_Left_Menu_Click", "PICO Touch (L) Menu"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Grip_Click, LOCTEXT("PICOTouch_Left_Grip_Click", "PICO Touch (L) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Grip_Axis, LOCTEXT("PICOTouch_Left_Grip_Axis", "PICO Touch (L) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Click, LOCTEXT("PICOTouch_Left_Trigger_Click", "PICO Touch (L) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Axis, LOCTEXT("PICOTouch_Left_Trigger_Axis", "PICO Touch (L) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Trigger_Touch, LOCTEXT("PICOTouch_Left_Trigger_Touch", "PICO Touch (L) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_X, LOCTEXT("PICOTouch_Left_Thumbstick_X", "PICO Touch (L) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Y, LOCTEXT("PICOTouch_Left_Thumbstick_Y", "PICO Touch (L) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Click, LOCTEXT("PICOTouch_Left_Thumbstick_Click", "PICO Touch (L) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Touch, LOCTEXT("PICOTouch_Left_Thumbstick_Touch", "PICO Touch (L) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Home_Click, LOCTEXT("PICOTouch_Left_Home_Click", "PICO Touch (L) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_VolumeUp_Click, LOCTEXT("PICOTouch_Left_VolumeUp_Click", "PICO Touch (L) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_VolumeDown_Click, LOCTEXT("PICOTouch_Left_VolumeDown_Click", "PICO Touch (L) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbrest_Touch, LOCTEXT("PICOTouch_Left_Thumbrest_Touch", "PICO Touch (L) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Up, LOCTEXT("PICOTouch_Left_Thumbstick_Up", "PICO Touch (L) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Down, LOCTEXT("PICOTouch_Left_Thumbstick_Down", "PICO Touch (L) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Left, LOCTEXT("PICOTouch_Left_Thumbstick_Left", "PICO Touch (L) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Left_Thumbstick_Right, LOCTEXT("PICOTouch_Left_Thumbstick_Right", "PICO Touch (L) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));

	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_A_Click, LOCTEXT("PICOTouch_Right_A_Click", "PICO Touch (R) A Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_B_Click, LOCTEXT("PICOTouch_Right_B_Click", "PICO Touch (R) B Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_A_Touch, LOCTEXT("PICOTouch_Right_A_Touch", "PICO Touch (R) A Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_B_Touch, LOCTEXT("PICOTouch_Right_B_Touch", "PICO Touch (R) B Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_System_Click, LOCTEXT("PICOTouch_Right_System_Click", "PICO Touch (R) System"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Grip_Click, LOCTEXT("PICOTouch_Right_Grip_Click", "PICO Touch (R) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Grip_Axis, LOCTEXT("PICOTouch_Right_Grip_Axis", "PICO Touch (R) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Click, LOCTEXT("PICOTouch_Right_Trigger_Click", "PICO Touch (R) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Axis, LOCTEXT("PICOTouch_Right_Trigger_Axis", "PICO Touch (R) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Trigger_Touch, LOCTEXT("PICOTouch_Right_Trigger_Touch", "PICO Touch (R) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_X, LOCTEXT("PICOTouch_Right_Thumbstick_X", "PICO Touch (R) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Y, LOCTEXT("PICOTouch_Right_Thumbstick_Y", "PICO Touch (R) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Click, LOCTEXT("PICOTouch_Right_Thumbstick_Click", "PICO Touch (R) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Touch, LOCTEXT("PICOTouch_Right_Thumbstick_Touch", "PICO Touch (R) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Home_Click, LOCTEXT("PICOTouch_Right_Home_Click", "PICO Touch (R) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_VolumeUp_Click, LOCTEXT("PICOTouch_Right_VolumeUp_Click", "PICO Touch (R) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_VolumeDown_Click, LOCTEXT("PICOTouch_Right_VolumeDown_Click", "PICO Touch (R) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbrest_Touch, LOCTEXT("PICOTouch_Right_Thumbrest_Touch", "PICO Touch (R) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Up, LOCTEXT("PICOTouch_Right_Thumbstick_Up", "PICO Touch (R) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Down, LOCTEXT("PICOTouch_Right_Thumbstick_Down", "PICO Touch (R) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Left, LOCTEXT("PICOTouch_Right_Thumbstick_Left", "PICO Touch (R) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOTouch_Right_Thumbstick_Right, LOCTEXT("PICOTouch_Right_Thumbstick_Right", "PICO Touch (R) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOTouch"));


    EKeys::AddMenuCategoryDisplayInfo("PICOHand", LOCTEXT("PICOHandSubCategory", "PICO Hand"), TEXT("GraphEditor.PadEvent_16x"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_ThumbClick, LOCTEXT("PICOHand_Left_ThumbClick", "PICO Hand (L) Thumb Click"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_IndexPinch, LOCTEXT("PICOHand_Left_IndexPinch", "PICO Hand (L) Index Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_MiddlePinch, LOCTEXT("PICOHand_Left_MiddlePinch", "PICO Hand (L) Middle Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_RingPinch, LOCTEXT("PICOHand_Left_RingPinch", "PICO Hand (L) Ring Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_PinkyPinch, LOCTEXT("PICOHand_Left_PinkyPinch", "PICO Hand (L) Pinky Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));

	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_ThumbClick, LOCTEXT("PICOHand_Right_ThumbClick", "PICO Hand (R) Thumb Click"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_IndexPinch, LOCTEXT("PICOHand_Right_IndexPinch", "PICO Hand (R) Index Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_MiddlePinch, LOCTEXT("PICOHand_Right_MiddlePinch", "PICO Hand (R) Middle Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_RingPinch, LOCTEXT("PICOHand_Right_RingPinch", "PICO Hand (R) Ring Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_PinkyPinch, LOCTEXT("PICOHand_Right_PinkyPinch", "PICO Hand (R) Pinky Pinch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));

	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_SystemGesture, LOCTEXT("PICOHand_Left_SystemGesture", "PICO Hand (L) System Gesture"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_SystemGesture, LOCTEXT("PICOHand_Right_SystemGesture", "PICO Hand (R) System Gesture"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_ThumbClickStrength, LOCTEXT("PICOHand_Left_ThumbClickStrength", "PICO Hand (L) Thumb Click Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_IndexPinchStrength, LOCTEXT("PICOHand_Left_IndexPinchStrength", "PICO Hand (L) Index Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_MiddlePinchStrength, LOCTEXT("PICOHand_Left_MiddlePinchStrength", "PICO Hand (L) Middle Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_RingPinchStrength, LOCTEXT("PICOHand_Left_RingPinchStrength", "PICO Hand (L) Ring Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Left_PinkyPinchStrength, LOCTEXT("PICOHand_Left_PinkyPinchStrength", "PICO Hand (L) Pinky Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));

	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_ThumbClickStrength, LOCTEXT("PICOHand_Right_ThumbClickStrength", "PICO Hand (R) Thumb Click Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_IndexPinchStrength, LOCTEXT("PICOHand_Right_IndexPinchStrength", "PICO Hand (R) Index Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_MiddlePinchStrength, LOCTEXT("PICOHand_Right_MiddlePinchStrength", "PICO Hand (R) Middle Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_RingPinchStrength, LOCTEXT("PICOHand_Right_RingPinchStrength", "PICO Hand (R) Ring Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
	EKeys::AddKey(FKeyDetails(FPICOTouchKey::PICOHand_Right_PinkyPinchStrength, LOCTEXT("PICOHand_Right_PinkyPinchStrength", "PICO Hand (R) Pinky Pinch Strength"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis, "PICOHand"));
}
#undef FloatAxis
#undef LOCTEXT_NAMESPACE
