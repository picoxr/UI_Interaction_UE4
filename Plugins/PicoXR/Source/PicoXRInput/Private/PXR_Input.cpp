//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Input.h"
#include "PXR_InputState.h"
#include "PXR_HMD.h"
#include "CoreMinimal.h"
#include "PXR_Log.h"
#include "IXRTrackingSystem.h"

#if PLATFORM_ANDROID
#include "Misc/CoreDelegates.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "PxrInput.h"
#endif

#define LOCTEXT_NAMESPACE "PicoXRInput"

FVector FPicoXRInput::OriginOffsetL = FVector::ZeroVector;
FVector FPicoXRInput::OriginOffsetR = FVector::ZeroVector;

FPicoXRInput::FPicoXRInput()
	:PicoXRHMD(nullptr)
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
	,ControllerType(EPicoInputType::Unknown)
	,CurrentVersion(0)
{
	PicoXRHMD = GetPicoXRHMD();
#if PLATFORM_ANDROID
	Settings = GetMutableDefault<UPicoXRSettings>();
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
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);	
}

FPicoXRInput::~FPicoXRInput()
{
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
}

void FPicoXRInput::Tick(float DeltaTime)
{
}

void FPicoXRInput::SendControllerEvents()
{
#if PLATFORM_ANDROID
	if (PicoXRHMD)
	{
		PicoXRHMD->PollEvent();
		PicoXRHMD->OnGameFrameBegin_GameThread();
	}
	ProcessButtonEvent();
	ProcessButtonAxis();
#endif
}

void FPicoXRInput::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FPicoXRInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return false;
}

void FPicoXRInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
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

void FPicoXRInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values)
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

FName FPicoXRInput::GetMotionControllerDeviceTypeName() const
{
	return FName(TEXT("PicoXRInput"));
}

bool FPicoXRInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const
{
	double predictedDisplayTimeMs = 0.0;
	FVector SourcePosition = FVector::ZeroVector;
	FQuat SourceOrientation = FQuat::Identity;
	FPXRGameFrame* CurrentFrame = nullptr;
	if (IsInRenderingThread() && PicoXRHMD)
	{
		CurrentFrame = PicoXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PicoXRHMD)
	{
		CurrentFrame = PicoXRHMD->NextGameFrameToRender.Get();
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

bool FPicoXRInput::GetPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const
{
	FVector PredictedLocation; FRotator PredictedRotation;
	PredictedLocation = FVector::ZeroVector;
	PredictedRotation = FRotator::ZeroRotator;
	float WorldToMetersScale = 100.0f;
	FVector SourcePosition = FVector::ZeroVector;
	FQuat SourceOrientation = FQuat::Identity;
	FPXRGameFrame* CurrentFrame = nullptr;
	if (IsInRenderingThread() && PicoXRHMD)
	{
		CurrentFrame = PicoXRHMD->GameFrame_RenderThread.Get();
	}
	else if (IsInGameThread() && PicoXRHMD)
	{
		CurrentFrame = PicoXRHMD->NextGameFrameToRender.Get();
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

ETrackingStatus FPicoXRInput::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const
{
	if (ControllerIndex == 0 && (DeviceHand == EControllerHand::Left || DeviceHand == EControllerHand::Right || DeviceHand == EControllerHand::AnyHand))
	{
		return ETrackingStatus::Tracked;
	}
	return ETrackingStatus::NotTracked;
}

void FPicoXRInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values)
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

void FPicoXRInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const
{
	MinFrequency = 0.f;
	MaxFrequency = 1.f;
}

float FPicoXRInput::GetHapticAmplitudeScale() const
{
	return 1.0f;
}

FPicoXRHMD* FPicoXRInput::GetPicoXRHMD()
{
	if (PicoXRHMD == nullptr)
	{
		static FName SystemName(TEXT("PicoXRHMD"));
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
			{
				PicoXRHMD = static_cast<FPicoXRHMD*>(GEngine->XRSystem.Get());
			}
		}
	}
	return PicoXRHMD;
}

int32 FPicoXRInput::UPxr_GetControllerPower(int32 Handness)
{
	if (ControllerType == G2)
	{
		return LeftControllerPower;
	}
	else if(ControllerType == Neo2 || ControllerType == Neo3)
	{
		return  Handness == 0 ? LeftControllerPower : RightControllerPower;
	}
	else
	{
		return  Handness == 0 ? LeftControllerPower : RightControllerPower;
	}
	return 0;
}

bool FPicoXRInput::UPxr_GetControllerConnectState(int32 Handness)
{
	return  Handness == 0 ? LeftConnectState : RightConnectState;
}

bool FPicoXRInput::UPxr_GetControllerMainInputHandle(int32& Handness)
{
	if (MainControllerHandle != -1)
	{
		Handness = MainControllerHandle;
		return true;
	}
	return  false;
}

bool FPicoXRInput::UPxr_SetControllerMainInputHandle(int32 InHandness)
{
#if PLATFORM_ANDROID
	Pxr_SetControllerMainInputHandle(InHandness);
	MainControllerHandle = InHandness;
	return true;
#endif
	return false;
}

void FPicoXRInput::SetKeyMapping()
{
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerX] = FPicoKeyNames::PicoTouch_Left_Thumbstick_X;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerY] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Y;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::Home] = FPicoKeyNames::PicoTouch_Left_Home_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::App] = FPicoKeyNames::PicoTouch_Left_Menu_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::Rocker] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::VolumeUp] = FPicoKeyNames::PicoTouch_Left_VolumeUp_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::VolumeDown] = FPicoKeyNames::PicoTouch_Left_VolumeDown_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::Trigger] = FPicoKeyNames::PicoTouch_Left_Trigger_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::AorX] = FPicoKeyNames::PicoTouch_Left_X_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::BorY] = FPicoKeyNames::PicoTouch_Left_Y_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::Grip] = FPicoKeyNames::PicoTouch_Left_Grip_Click;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerUp] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Up;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerDown] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Down;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerLeft] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Left;
	Buttons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoButton::RockerRight] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Right;

	
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerX] = FPicoKeyNames::PicoTouch_Right_Thumbstick_X;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerY] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Y;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::Home] = FPicoKeyNames::PicoTouch_Right_Home_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::App] = FPicoKeyNames::PicoTouch_Right_System_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::Rocker] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::VolumeUp] = FPicoKeyNames::PicoTouch_Right_VolumeUp_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::VolumeDown] = FPicoKeyNames::PicoTouch_Right_VolumeDown_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::Trigger] = FPicoKeyNames::PicoTouch_Right_Trigger_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::AorX] = FPicoKeyNames::PicoTouch_Right_A_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::BorY] = FPicoKeyNames::PicoTouch_Right_B_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::Grip] = FPicoKeyNames::PicoTouch_Right_Grip_Click;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerUp] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Up;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerDown] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Down;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerLeft] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Left;
	Buttons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoButton::RockerRight] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Right;

	TouchButtons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoTouchButton::AorX] = FPicoKeyNames::PicoTouch_Left_X_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoTouchButton::BorY] = FPicoKeyNames::PicoTouch_Left_Y_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoTouchButton::Rocker] = FPicoKeyNames::PicoTouch_Left_Thumbstick_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoTouchButton::Trigger] = FPicoKeyNames::PicoTouch_Left_Trigger_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::LeftController][(int32)EPicoTouchButton::Thumbrest] = FPicoKeyNames::PicoTouch_Left_Thumbrest_Touch;
	
	TouchButtons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoTouchButton::AorX] = FPicoKeyNames::PicoTouch_Right_A_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoTouchButton::BorY] = FPicoKeyNames::PicoTouch_Right_B_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoTouchButton::Rocker] = FPicoKeyNames::PicoTouch_Right_Thumbstick_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoTouchButton::Trigger] = FPicoKeyNames::PicoTouch_Right_Trigger_Touch;
	TouchButtons[(int32)EPicoXRControllerHandness::RightController][(int32)EPicoTouchButton::Thumbrest] = FPicoKeyNames::PicoTouch_Right_Thumbrest_Touch;
	
}

void FPicoXRInput::ProcessButtonEvent()
{
#if PLATFORM_ANDROID
	if (LeftConnectState)
	{
		PxrControllerInputState state;
		Pxr_GetControllerInputState(EPicoXRControllerHandness::LeftController, &state);
        int LeftControllerEvent[12] = {0};
        LeftControllerEvent[2] = state.homeValue;
        LeftControllerEvent[3] = state.backValue;
        LeftControllerEvent[4] = state.touchpadValue;
        LeftControllerEvent[5] = state.volumeUp;
        LeftControllerEvent[6] = state.volumeDown;
        LeftControllerEvent[8] = state.batteryValue;
        LeftControllerEvent[9] = state.AXValue;
        LeftControllerEvent[10] = state.BYValue;

		for (int32 i = 2; i < EPicoButton::ButtonCount; i++)
		{
			if (LeftControllerEvent[i]!= LastLeftControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastLeftControllerButtonState[i] = LeftControllerEvent[i];
				if (LeftControllerEvent[i] > 0 )
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
				else if (LeftControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][i], 0, false);
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
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][7], 0, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][7], 0, false);
			}
			LastLeftControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][11], 0, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][11], 0, false);
			}
			LastLeftControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (LeftControllerTriggerValue > 0.67f && LastLeftControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][7], 0, false);
			}
			else if (LastLeftControllerButtonState[7] > 0 && LeftControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][7], 0, false);
			}
			LastLeftControllerButtonState[7] = LeftControllerTriggerValue > 0.67f ? 1 : 0;

			if (LeftControllerGripValue > 0.67f && LastLeftControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][11], 0, false);
			}
			else if (LastLeftControllerButtonState[11] > 0 && LeftControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][11], 0, false);
			}
			LastLeftControllerButtonState[11] = LeftControllerGripValue > 0.67f ? 1 : 0;
		}

		LeftControllerPower = (LeftControllerEvent[8] < 6 ? LeftControllerEvent[8] : LeftControllerPower);

		//Rocker Up/Down/Left/Right
		if(ControllerType != G2)
		{
			if(LeftControllerTouchPoint.Y > 0.7f && LastLeftControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][12], 0, false);
			}
			else if(LeftControllerTouchPoint.Y <= 0.7f && LastLeftControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][12], 0, false);
			}
			LastLeftControllerButtonState[12] = LeftControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.Y < -0.7f && LastLeftControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][13], 0, false);
			}
			else if (LeftControllerTouchPoint.Y >= -0.7f && LastLeftControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][13], 0, false);
			}
			LastLeftControllerButtonState[13] = LeftControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X < -0.7f && LastLeftControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][14], 0, false);
			}
			else if (LeftControllerTouchPoint.X >= -0.7f && LastLeftControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][14], 0, false);
			}
			LastLeftControllerButtonState[14] = LeftControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (LeftControllerTouchPoint.X > 0.7f && LastLeftControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][15], 0, false);
			}
			else if (LeftControllerTouchPoint.X <= 0.7f && LastLeftControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][15], 0, false);
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
			for (int32 i = 0;i<EPicoTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0, false);
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
			for (int32 i = 0;i<EPicoTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
				LastLeftTouchButtonState[i]=TouchArray[i];
			}
		}
	}
	if (RightConnectState)
	{
		PxrControllerInputState state;
		Pxr_GetControllerInputState(EPicoXRControllerHandness::RightController, &state);
        int RightControllerEvent[12] = {0};
        RightControllerEvent[2] = state.homeValue;
        RightControllerEvent[3] = state.backValue;
        RightControllerEvent[4] = state.touchpadValue;
        RightControllerEvent[5] = state.volumeUp;
        RightControllerEvent[6] = state.volumeDown;
        RightControllerEvent[8] = state.batteryValue;
        RightControllerEvent[9] = state.AXValue;
        RightControllerEvent[10] = state.BYValue;

		for (int32 i = 2; i < EPicoButton::ButtonCount; i++)
		{
			if (RightControllerEvent[i] != LastRightControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastRightControllerButtonState[i] = RightControllerEvent[i];
				if (RightControllerEvent[i] > 0 )
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
				else if (RightControllerEvent[i] == 0 )
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][i], 0, false);
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
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][7], 0, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && state.triggerclickValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][7], 0, false);
			}
			LastRightControllerButtonState[7] = state.triggerclickValue;

			if (state.sideValue == 1 && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][11], 0, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && state.sideValue == 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][11], 0, false);
			}
			LastRightControllerButtonState[11] = state.sideValue;
		}
		else
		{
			if (RightControllerTriggerValue > 0.67f && LastRightControllerButtonState[7] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][7], 0, false);
			}
			else if (LastRightControllerButtonState[7] > 0 && RightControllerTriggerValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][7], 0, false);
			}
			LastRightControllerButtonState[7] = RightControllerTriggerValue > 0.67f ? 1 : 0;

			if (RightControllerGripValue > 0.67f && LastRightControllerButtonState[11] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][11], 0, false);
			}
			else if (LastRightControllerButtonState[11] > 0 && RightControllerGripValue <= 0.67f)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][11], 0, false);
			}
			LastRightControllerButtonState[11] = RightControllerGripValue > 0.67f ? 1 : 0;
		}

		RightControllerPower = (RightControllerEvent[8] < 6 ? RightControllerEvent[8] : RightControllerPower);

		//Rocker Up/Down/Left/Right
		if (ControllerType != G2)
		{
			if (RightControllerTouchPoint.Y > 0.7f && LastRightControllerButtonState[12] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][12], 0, false);
			}
			else if (RightControllerTouchPoint.Y <= 0.7f && LastRightControllerButtonState[12] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][12], 0, false);
			}
			LastRightControllerButtonState[12] = RightControllerTouchPoint.Y > 0.7f ? 1 : 0;

			if (RightControllerTouchPoint.Y < -0.7f && LastRightControllerButtonState[13] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][13], 0, false);
			}
			else if (RightControllerTouchPoint.Y >= -0.7f && LastRightControllerButtonState[13] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][13], 0, false);
			}
			LastRightControllerButtonState[13] = RightControllerTouchPoint.Y < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X < -0.7f && LastRightControllerButtonState[14] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][14], 0, false);
			}
			else if (RightControllerTouchPoint.X >= -0.7f && LastRightControllerButtonState[14] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][14], 0, false);
			}
			LastRightControllerButtonState[14] = RightControllerTouchPoint.X < -0.7f ? 1 : 0;

			if (RightControllerTouchPoint.X > 0.7f && LastRightControllerButtonState[15] == 0)
			{
				MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][15], 0, false);
			}
			else if (RightControllerTouchPoint.X <= 0.7f && LastRightControllerButtonState[15] > 0)
			{
				MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][15], 0, false);
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
			for (int32 i = 0; i < EPicoTouchButton::ButtonCount; i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::RightController][i], 0, false);
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
			for (int32 i = 0;i<EPicoTouchButton::ButtonCount;i++)
			{
				if (TouchArray[i] == 1&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
				else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
				{
					MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
				LastRightTouchButtonState[i]=TouchArray[i];
			}
		}
	}
#endif
}

void FPicoXRInput::ProcessButtonAxis()
{
	if (LeftConnectState)
	{
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Left_Thumbstick_X, 0, LeftControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Left_Thumbstick_Y, 0, LeftControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Left_Trigger_Axis, 0,LeftControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Left_Grip_Axis, 0, LeftControllerGripValue);
	}
	if (RightConnectState)
	{
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Right_Thumbstick_X, 0, RightControllerTouchPoint.X);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Right_Thumbstick_Y, 0, RightControllerTouchPoint.Y);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Right_Trigger_Axis, 0, RightControllerTriggerValue);
		MessageHandler->OnControllerAnalog(FPicoKeyNames::PicoTouch_Right_Grip_Axis, 0, RightControllerGripValue);
	}
}

void FPicoXRInput::UpdateConnectState()
{
#if PLATFORM_ANDROID
	PxrControllerCapability cap;
	Pxr_GetControllerCapabilities(PXR_CONTROLLER_LEFT, &cap);
	ControllerType = static_cast<EPicoInputType>(cap.type);
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
	PXR_LOGD(PxrUnreal,"FPicoXRInput::UpdateConnectState ControllerType  %d, LeftConnectState %d, RightConnectState %d",ControllerType,LeftConnectState,RightConnectState);
}

void FPicoXRInput::GetControllerSensorData(EControllerHand DeviceHand, float WorldToMetersScale, float PredictedTime, FVector SourcePosition, FQuat SourceOrientation, FRotator& OutOrientation, FVector& OutPosition) const
{
#if PLATFORM_ANDROID
	FQuat Orientation;
	float HeadSensorData[7] = {SourceOrientation.X, SourceOrientation.Y, SourceOrientation.Z, SourceOrientation.W, SourcePosition.X, SourcePosition.Y, SourcePosition.Z};

	PxrControllerTracking tracking;
    uint32_t hand;

    if (DeviceHand == EControllerHand::Left) {
        hand = EPicoXRControllerHandness::LeftController;
    } else {
        hand = EPicoXRControllerHandness::RightController;
    }
	Pxr_GetControllerTrackingState(hand, PredictedTime, HeadSensorData, &tracking);
	
	if (PicoXRHMD && PicoXRHMD->bDeviceHasEnableLargeSpace && PicoXRHMD->bUserEnableLargeSpace)
	{
		Orientation.X = tracking.globalControllerPose.pose.orientation.x;
		Orientation.Y = tracking.globalControllerPose.pose.orientation.y;
		Orientation.Z = tracking.globalControllerPose.pose.orientation.z;
		Orientation.W = tracking.globalControllerPose.pose.orientation.w;
		OutPosition.X = tracking.globalControllerPose.pose.position.x;
		OutPosition.Y = tracking.globalControllerPose.pose.position.y;
		OutPosition.Z = tracking.globalControllerPose.pose.position.z;
	}
	else
	{
		Orientation.X = tracking.localControllerPose.pose.orientation.x;
		Orientation.Y = tracking.localControllerPose.pose.orientation.y;
		Orientation.Z = tracking.localControllerPose.pose.orientation.z;
		Orientation.W = tracking.localControllerPose.pose.orientation.w;
		OutPosition.X = tracking.localControllerPose.pose.position.x;
		OutPosition.Y = tracking.localControllerPose.pose.position.y;
		OutPosition.Z = tracking.localControllerPose.pose.position.z;
	}

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

void FPicoXRInput::OnControllerMainChangedDelegate(int32 Handness)
{
	PXR_LOGD(PxrUnreal,"FPicoXRInput::OnControllerMainChangedDelegate Handness:%d", Handness);
	UpdateConnectState();
#if PLATFORM_ANDROID
	Pxr_GetControllerMainInputHandle(&MainControllerHandle);
#endif
}

void FPicoXRInput::OnControllerConnectChangedDelegate(int32 Handness, int32 State)
{
	PXR_LOGD(PxrUnreal,"FPicoXRInput::OnControllerConnectChangedDelegate Handness:%d,State:%d",Handness,State);
	UpdateConnectState();
}

bool FPicoXRInput::UPxr_GetControllerEnableHomeKey()
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
void FPicoXRInput::RegisterKeys()
{
	EKeys::AddMenuCategoryDisplayInfo("PicoTouch", LOCTEXT("PicoTouchSubCategory", "Pico Touch"), TEXT("GraphEditor.PadEvent_16x"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_X_Click, LOCTEXT("PicoTouch_Left_X_Click", "Pico Touch (L) X Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Y_Click, LOCTEXT("PicoTouch_Left_Y_Click", "Pico Touch (L) Y Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_X_Touch, LOCTEXT("PicoTouch_Left_X_Touch", "Pico Touch (L) X Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Y_Touch, LOCTEXT("PicoTouch_Left_Y_Touch", "Pico Touch (L) Y Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Menu_Click, LOCTEXT("PicoTouch_Left_Menu_Click", "Pico Touch (L) Menu"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Grip_Click, LOCTEXT("PicoTouch_Left_Grip_Click", "Pico Touch (L) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Grip_Axis, LOCTEXT("PicoTouch_Left_Grip_Axis", "Pico Touch (L) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Trigger_Click, LOCTEXT("PicoTouch_Left_Trigger_Click", "Pico Touch (L) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Trigger_Axis, LOCTEXT("PicoTouch_Left_Trigger_Axis", "Pico Touch (L) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Trigger_Touch, LOCTEXT("PicoTouch_Left_Trigger_Touch", "Pico Touch (L) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_X, LOCTEXT("PicoTouch_Left_Thumbstick_X", "Pico Touch (L) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Y, LOCTEXT("PicoTouch_Left_Thumbstick_Y", "Pico Touch (L) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Click, LOCTEXT("PicoTouch_Left_Thumbstick_Click", "Pico Touch (L) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Touch, LOCTEXT("PicoTouch_Left_Thumbstick_Touch", "Pico Touch (L) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Home_Click, LOCTEXT("PicoTouch_Left_Home_Click", "Pico Touch (L) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_VolumeUp_Click, LOCTEXT("PicoTouch_Left_VolumeUp_Click", "Pico Touch (L) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_VolumeDown_Click, LOCTEXT("PicoTouch_Left_VolumeDown_Click", "Pico Touch (L) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbrest_Touch, LOCTEXT("PicoTouch_Left_Thumbrest_Touch", "Pico Touch (L) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Up, LOCTEXT("PicoTouch_Left_Thumbstick_Up", "Pico Touch (L) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Down, LOCTEXT("PicoTouch_Left_Thumbstick_Down", "Pico Touch (L) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Left, LOCTEXT("PicoTouch_Left_Thumbstick_Left", "Pico Touch (L) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Left_Thumbstick_Right, LOCTEXT("PicoTouch_Left_Thumbstick_Right", "Pico Touch (L) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_A_Click, LOCTEXT("PicoTouch_Right_A_Click", "Pico Touch (R) A Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_B_Click, LOCTEXT("PicoTouch_Right_B_Click", "Pico Touch (R) B Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_A_Touch, LOCTEXT("PicoTouch_Right_A_Touch", "Pico Touch (R) A Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_B_Touch, LOCTEXT("PicoTouch_Right_B_Touch", "Pico Touch (R) B Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_System_Click, LOCTEXT("PicoTouch_Right_System_Click", "Pico Touch (R) System"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Grip_Click, LOCTEXT("PicoTouch_Right_Grip_Click", "Pico Touch (R) Grip"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Grip_Axis, LOCTEXT("PicoTouch_Right_Grip_Axis", "Pico Touch (R) Grip Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Trigger_Click, LOCTEXT("PicoTouch_Right_Trigger_Click", "Pico Touch (R) Trigger"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Trigger_Axis, LOCTEXT("PicoTouch_Right_Trigger_Axis", "Pico Touch (R) Trigger Axis"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Trigger_Touch, LOCTEXT("PicoTouch_Right_Trigger_Touch", "Pico Touch (R) Trigger Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_X, LOCTEXT("PicoTouch_Right_Thumbstick_X", "Pico Touch (R) Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Y, LOCTEXT("PicoTouch_Right_Thumbstick_Y", "Pico Touch (R) Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Click, LOCTEXT("PicoTouch_Right_Thumbstick_Click", "Pico Touch (R) Thumbstick"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Touch, LOCTEXT("PicoTouch_Right_Thumbstick_Touch", "Pico Touch (R) Thumbstick Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Home_Click, LOCTEXT("PicoTouch_Right_Home_Click", "Pico Touch (R) Home Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_VolumeUp_Click, LOCTEXT("PicoTouch_Right_VolumeUp_Click", "Pico Touch (R) Volume Up Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_VolumeDown_Click, LOCTEXT("PicoTouch_Right_VolumeDown_Click", "Pico Touch (R) Volume Down Press"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbrest_Touch, LOCTEXT("PicoTouch_Right_Thumbrest_Touch", "Pico Touch (R) Thumbrest Touch"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Up, LOCTEXT("PicoTouch_Right_Thumbstick_Up", "Pico Touch (R) Thumbstick Up"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Down, LOCTEXT("PicoTouch_Right_Thumbstick_Down", "Pico Touch (R) Thumbstick Down"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Left, LOCTEXT("PicoTouch_Right_Thumbstick_Left", "Pico Touch (R) Thumbstick Left"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
	EKeys::AddKey(FKeyDetails(FPicoTouchKey::PicoTouch_Right_Thumbstick_Right, LOCTEXT("PicoTouch_Right_Thumbstick_Right", "Pico Touch (R) Thumbstick Right"), FKeyDetails::GamepadKey | FKeyDetails::NotBlueprintBindableKey, "PicoTouch"));
}
#undef FloatAxis
#undef LOCTEXT_NAMESPACE
