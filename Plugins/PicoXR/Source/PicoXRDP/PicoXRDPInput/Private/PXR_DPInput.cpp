//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_DPInput.h"
#include "PXR_DPInputState.h"
#include "CoreMinimal.h"
#include "IXRTrackingSystem.h"
#include "PXR_Log.h"

#define LOCTEXT_NAMESPACE "PicoXRDPInput"

FVector FPicoXRDPInput::OriginOffsetL = FVector::ZeroVector;
FVector FPicoXRDPInput::OriginOffsetR = FVector::ZeroVector;

FPicoXRDPInput::FPicoXRDPInput()
	:MessageHandler(new FGenericApplicationMessageHandler())
	, LeftConnectState(false)
	, RightConnectState(false)
	, LeftControllerPower(0)
	, RightControllerPower(0)
	, LeftControllerTouchPoint(FVector2D::ZeroVector)
	, RightControllerTouchPoint(FVector2D::ZeroVector)
	, LeftControllerTriggerValue(0.0f)
	, RightControllerTriggerValue(0.0f)
	, LeftControllerGripValue(0.0f)
	, RightControllerGripValue(0.0f)
	, MainControllerHandle(-1)
	, SourcePosition(FVector::ZeroVector)
	, SourceOrientation(FQuat::Identity)
	, ControllerType(EPicoInputType::Unknown)
{
	SetKeyMapping();
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
	if (PicoXRHMD == nullptr)
	{
		static FName SystemName(TEXT("PicoDP"));
		if (GEngine)
		{
			if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
			{
				PicoXRHMD = static_cast<FPicoDirectPreviewHMD*>(GEngine->XRSystem.Get());
				if (PicoXRHMD)
				{
					PXR_LOGD(PxrUnreal,"PXR_DP PicoXRHMD OK on input!");
				}
			}
		}
	}
}

FPicoXRDPInput::~FPicoXRDPInput()
{
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
}

void FPicoXRDPInput::Tick(float DeltaTime)
{
	if (PicoXRHMD)
	{
		LeftConnectState = PicoXRHMD->CurrentDirectPreview->GetControllerConnectstatus(0);
		RightConnectState = PicoXRHMD->CurrentDirectPreview->GetControllerConnectstatus(1);
	}
}

void FPicoXRDPInput::SendControllerEvents()
{
	ProcessButtonEvent();
	ProcessButtonAxis();
}

void FPicoXRDPInput::SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FPicoXRDPInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return false;
}

void FPicoXRDPInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
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

void FPicoXRDPInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values)
{
#if PLATFORM_ANDROID
	if (values.LeftLarge > 0)
	{
		Pxr_SetControllerVibration(0, values.LeftLarge, 10);
	}
	if (values.RightLarge > 0)
	{
		Pxr_SetControllerVibration(1, values.RightLarge, 10);
	}
#endif
}

FName FPicoXRDPInput::GetMotionControllerDeviceTypeName() const
{
	return FName(TEXT("PicoXRDPInput"));
}

bool FPicoXRDPInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const
{
	if (PicoXRHMD && PicoXRHMD->CurrentDirectPreview)
	{
		if (DeviceHand == EControllerHand::Left)
		{
			PicoXRHMD->CurrentDirectPreview->GetControllerPositionAndRotation(0, WorldToMetersScale, OutPosition, OutOrientation);
			return true;
		}
		if (DeviceHand == EControllerHand::Right)
		{
			PicoXRHMD->CurrentDirectPreview->GetControllerPositionAndRotation(1, WorldToMetersScale, OutPosition, OutOrientation);
			return true;
		}
	}
	return false;
}

void FPicoXRDPInput::GetPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const
{
	FVector PredictedLocation; FRotator PredictedRotation;
	PredictedLocation = FVector::ZeroVector;
	PredictedRotation = FRotator::ZeroRotator;
	float WorldToMetersScale = 100.0f;
	if (IsInGameThread() && GWorld != nullptr)
	{
		WorldToMetersScale = GWorld->GetWorldSettings()->WorldToMeters;
	}
	if (LeftConnectState && DeviceHand == EControllerHand::Left)
	{
		GetControllerSensorData(DeviceHand, WorldToMetersScale, PredictedTime, PredictedRotation, PredictedLocation);
	}
	else if (RightConnectState && DeviceHand == EControllerHand::Right)
	{
		GetControllerSensorData(DeviceHand, WorldToMetersScale, PredictedTime, PredictedRotation, PredictedLocation);
	}
	OutPosition = PredictedLocation;
	OutOrientation = PredictedRotation;
}

ETrackingStatus FPicoXRDPInput::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const
{
	if (ControllerIndex == 0 && (DeviceHand == EControllerHand::Left || DeviceHand == EControllerHand::Right || DeviceHand == EControllerHand::AnyHand))
	{
		return ETrackingStatus::Tracked;
	}
	return ETrackingStatus::NotTracked;
}

void FPicoXRDPInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values)
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

void FPicoXRDPInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const
{
	MinFrequency = 0.f;
	MaxFrequency = 1.f;
}

float FPicoXRDPInput::GetHapticAmplitudeScale() const
{
	return 1.0f;
}

int32 FPicoXRDPInput::UPxr_GetControllerPower(int32 Handness)
{
	if (ControllerType == G2)
	{
		return LeftControllerPower;
	}
	else if (ControllerType == Neo2 || ControllerType == Neo3)
	{
		return  Handness == 0 ? LeftControllerPower : RightControllerPower;
	}
	return 0;
}

bool FPicoXRDPInput::UPxr_GetControllerConnectState(int32 Handness)
{
	return  Handness == 0 ? LeftConnectState : RightConnectState;
}

bool FPicoXRDPInput::UPxr_GetControllerMainInputHandle(int32& Handness)
{
	if (MainControllerHandle != -1)
	{
		Handness = MainControllerHandle;
		return true;
	}
	return  false;
}

bool FPicoXRDPInput::UPxr_SetControllerMainInputHandle(int32 InHandness)
{
#if PLATFORM_ANDROID
	Pxr_SetControllerMainInputHandle(InHandness);
	MainControllerHandle = InHandness;
	return true;
#endif
	return false;
}

void FPicoXRDPInput::SetKeyMapping()
{
#if WITH_EDITOR
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
#endif
	

}

void FPicoXRDPInput::ProcessButtonEvent()
{
	using namespace pxr::connector;
	if (LeftConnectState)
	{
		uint16 currentStatus = PicoXRHMD->CurrentDirectPreview->GetControllerButtonStatus(0);
		int LeftControllerEvent[12] = {0};
		LeftControllerEvent[2] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kSystemButtonClick;
		LeftControllerEvent[3] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kMenuButtonClick;
		LeftControllerEvent[4] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kJoystickClick;
		LeftControllerEvent[9] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kXAClick;
		LeftControllerEvent[10] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kYBClick;

		for (int32 i = 2; i < EPicoButton::ButtonCount; i++)
		{
			if (LeftControllerEvent[i] != LastLeftControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastLeftControllerButtonState[i] = LeftControllerEvent[i];
				if (LeftControllerEvent[i] > 0)
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
				else if (LeftControllerEvent[i] == 0)
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::LeftController][i], 0, false);
				}
			}
		}

		//AxisValue
		PicoXRHMD->CurrentDirectPreview->GetControllerAxisValue(0, LeftControllerTouchPoint.X, LeftControllerTouchPoint.Y, LeftControllerTriggerValue, LeftControllerGripValue);


		//Trigger Grip Button
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


		//Rocker Up/Down/Left/Right
		if (LeftControllerTouchPoint.Y > 0.7f && LastLeftControllerButtonState[12] == 0)
		{
			MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::LeftController][12], 0, false);
		}
		else if (LeftControllerTouchPoint.Y <= 0.7f && LastLeftControllerButtonState[12] > 0)
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

		int TouchArray[5] = {0};
		TouchArray[0] = currentStatus==(uint16)ETouchButtonStatus::XATouch?1:0;
		TouchArray[1] = currentStatus==(uint16)ETouchButtonStatus::YBTouch?1:0;
		TouchArray[2] = currentStatus==(uint16)ETouchButtonStatus::JoystickTouch?1:0;
		TouchArray[3] = currentStatus==(uint16)ETouchButtonStatus::TriggerTouch?1:0;
		TouchArray[4] = currentStatus==(uint16)ETouchButtonStatus::KBlankTouch?1:0;
		
		for (int32 i = 0; i < EPicoTouchButton::ButtonCount; i++)
		{
			if (TouchArray[i] == 1&&TouchArray[i]!=LastLeftTouchButtonState[i])
			{
				MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0,  false);
			}
			else if (TouchArray[i] == 0&&TouchArray[i]!=LastLeftTouchButtonState[i])
			{
				MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::LeftController][i], 0, false);
			}

			LastLeftTouchButtonState[i]=TouchArray[i];
		}
	}
	if (RightConnectState)
	{
		uint16 currentStatus = PicoXRHMD->CurrentDirectPreview->GetControllerButtonStatus(1);
		int RightControllerEvent[12] = {0};
		RightControllerEvent[2] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kSystemButtonClick;
		RightControllerEvent[3] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kMenuButtonClick;
		RightControllerEvent[4] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kJoystickClick;
		RightControllerEvent[9] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kXAClick;
		RightControllerEvent[10] = currentStatus & (uint16)ControllerAccessory::ButtonStatus::kYBClick;

		for (int32 i = 2; i < EPicoButton::ButtonCount; i++)
		{
			if (RightControllerEvent[i] != LastRightControllerButtonState[i] && i != 7 && i != 8 && i < 11)
			{
				LastRightControllerButtonState[i] = RightControllerEvent[i];
				if (RightControllerEvent[i] > 0)
				{
					MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
				else if (RightControllerEvent[i] == 0)
				{
					MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][i], 0, false);
				}
			}
		}

		PicoXRHMD->CurrentDirectPreview->GetControllerAxisValue(1, RightControllerTouchPoint.X, RightControllerTouchPoint.Y, RightControllerTriggerValue, RightControllerGripValue);

		//Trigger Grip Button
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

		//Rocker Up/Down/Left/Right
		if (RightControllerTouchPoint.Y > 0.7f && LastRightControllerButtonState[12] == 0)
		{
			MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][12], 0, false);
		}
		else if (RightControllerTouchPoint.Y <= 0.7f && LastRightControllerButtonState[12] > 0)
		{
			MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][12], 0,false);
		}
		LastRightControllerButtonState[12] = RightControllerTouchPoint.Y > 0.7f ? 1 : 0;

		if (RightControllerTouchPoint.Y < -0.7f && LastRightControllerButtonState[13] == 0)
		{
			MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][13], 0, false);
		}
		else if (RightControllerTouchPoint.Y >= -0.7f && LastRightControllerButtonState[13] > 0)
		{
			MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][13], 0,false);
		}
		LastRightControllerButtonState[13] = RightControllerTouchPoint.Y < -0.7f ? 1 : 0;

		if (RightControllerTouchPoint.X < -0.7f && LastRightControllerButtonState[14] == 0)
		{
			MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][14], 0, false);
		}
		else if (RightControllerTouchPoint.X >= -0.7f && LastRightControllerButtonState[14] > 0)
		{
			MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][14], 0,false);
		}
		LastRightControllerButtonState[14] = RightControllerTouchPoint.X < -0.7f ? 1 : 0;

		if (RightControllerTouchPoint.X > 0.7f && LastRightControllerButtonState[15] == 0)
		{
			MessageHandler->OnControllerButtonPressed(Buttons[EPicoXRControllerHandness::RightController][15], 0, false);
		}
		else if (RightControllerTouchPoint.X <= 0.7f && LastRightControllerButtonState[15] > 0)
		{
			MessageHandler->OnControllerButtonReleased(Buttons[EPicoXRControllerHandness::RightController][15], 0,false);
		}
		LastRightControllerButtonState[15] = RightControllerTouchPoint.X > 0.7f ? 1 : 0;
		
		int TouchArray[5] = {0};
		TouchArray[0] = currentStatus==(uint16)ETouchButtonStatus::XATouch?1:0;
		TouchArray[1] = currentStatus==(uint16)ETouchButtonStatus::YBTouch?1:0;
		TouchArray[2] = currentStatus==(uint16)ETouchButtonStatus::JoystickTouch?1:0;
		TouchArray[3] = currentStatus==(uint16)ETouchButtonStatus::TriggerTouch?1:0;
		TouchArray[4] = currentStatus==(uint16)ETouchButtonStatus::KBlankTouch?1:0;
		
		for (int32 i = 0; i < EPicoTouchButton::ButtonCount; i++)
		{
			if (TouchArray[i] == 1&&TouchArray[i]!=LastRightTouchButtonState[i])
			{
				MessageHandler->OnControllerButtonPressed(TouchButtons[EPicoXRControllerHandness::RightController][i], 0,  false);
			}
			else if (TouchArray[i] == 0&&TouchArray[i]!=LastRightTouchButtonState[i])
			{
				MessageHandler->OnControllerButtonReleased(TouchButtons[EPicoXRControllerHandness::RightController][i], 0, false);
			}

			LastRightTouchButtonState[i]=TouchArray[i];
		}
		
	}
}

void FPicoXRDPInput::ProcessButtonAxis()
{
#if WITH_EDITOR
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
#endif
}

void FPicoXRDPInput::UpdateConnectState()
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
}

void FPicoXRDPInput::GetControllerSensorData(EControllerHand DeviceHand, float WorldToMetersScale, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const
{
#if PLATFORM_ANDROID
	FQuat Orientation;
	float HeadSensorData[7] = { SourceOrientation.X, SourceOrientation.Y, SourceOrientation.Z, SourceOrientation.W, SourcePosition.X, SourcePosition.Y, SourcePosition.Z };

	PxrControllerTracking tracking;
	uint32_t hand;

	if (DeviceHand == EControllerHand::Left) {
		hand = EPicoXRControllerHandness::LeftController;
	}
	else {
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
		}
		else //HMD 3Dof
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

void FPicoXRDPInput::OnControllerMainChangedDelegate(int32 Handness)
{
	UpdateConnectState();
#if PLATFORM_ANDROID
	Pxr_GetControllerMainInputHandle(&MainControllerHandle);
#endif
	}

void FPicoXRDPInput::OnControllerConnectChangedDelegate(int32 Handness, int32 State)
{
	UpdateConnectState();
}

void FPicoXRDPInput::SetHeadPosition(FVector Position)
{
	SourcePosition = Position;
}

void FPicoXRDPInput::SetHeadOrientation(FQuat Orientation)
{
	SourceOrientation = Orientation;
}

bool FPicoXRDPInput::UPxr_GetControllerEnableHomeKey()
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
void FPicoXRDPInput::RegisterKeys()
{
#if WITH_EDITOR 
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
#endif
	
}
#undef FloatAxis
#undef LOCTEXT_NAMESPACE
