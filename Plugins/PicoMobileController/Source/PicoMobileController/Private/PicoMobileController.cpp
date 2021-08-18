// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobileController.h"
#include "PicoMobileControllerPrivatePCH.h"
#include "IHeadMountedDisplay.h"
#include "PicoMobileControllerKeys.h"
#include "../Launch/Resources/Version.h"

#define LOCTEXT_NAMESPACE "PicoMobileInput"

class FPicoMobileControllerPlugin : public IPicoMobileControllerPlugin
{
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override
	{
		return TSharedPtr< class IInputDevice >(new FPicoMobileController(InMessageHandler));
	}
};

IMPLEMENT_MODULE(FPicoMobileControllerPlugin, PicoMobileController)

FName FPicoMobileController::DeviceTypeName(TEXT("PicoVRController"));

FPicoMobileController::FPicoMobileController(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
	:MessageHandler(InMessageHandler)
	,ControllerRotationMode(0)
{	
#if PLATFORM_ANDROID
	pvrControllerState = PicoMobileControllerState::GetInstance();
	ControllerRotationMode = pvrControllerState->GetControllerRotationMode();
#endif
	AddKeysToEngine();
	SetKeyMapping();
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
}

FPicoMobileController::~FPicoMobileController()
{
#if PLATFORM_ANDROID
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
	PicoMobileControllerState::GetInstance()->Destory();
#endif
	
}


#if ENGINE_MINOR_VERSION > 25
#define InputAxis FKeyDetails::Axis1D
#else
#define InputAxis FKeyDetails::FloatAxis
#endif
// Helper Functions
void FPicoMobileController::AddKeysToEngine()
{
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Home, LOCTEXT("Pico_Handle_Home", "Pico Handle Home"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Back, LOCTEXT("Pico_Handle_Back", "Pico Handle Back"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Touchpad, LOCTEXT("Pico_Handle_Touchpad", "Pico Handle Touchpad"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeUp, LOCTEXT("Pico_Handle_VolumeUp", "Pico Handle VolumeUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeDown, LOCTEXT("Pico_Handle_VolumeDown", "Pico Handle VolumeDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchX, LOCTEXT("Pico_Handle_TouchX", "Pico Handle TouchX"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchY, LOCTEXT("Pico_Handle_TouchY", "Pico Handle TouchY"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Trigger, LOCTEXT("Pico_Handle_Trigger", "Pico Handle Trigger"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchUp, LOCTEXT("Pico_Handle_TouchUp", "Pico Handle TouchUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchDown, LOCTEXT("Pico_Handle_TouchDown", "Pico Handle TouchDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchLeft, LOCTEXT("Pico_Handle_TouchLeft", "Pico Handle TouchLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchRight, LOCTEXT("Pico_Handle_TouchRight", "Pico Handle TouchRight"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchClickUp, LOCTEXT("Pico_Handle_TouchClickUp", "Pico Handle TouchClickUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchClickDown, LOCTEXT("Pico_Handle_TouchClickDown", "Pico Handle TouchClickDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchClickLeft, LOCTEXT("Pico_Handle_TouchClickLeft", "Pico Handle TouchClickLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_TouchClickRight, LOCTEXT("Pico_Handle_TouchClickRight", "Pico Handle TouchClickRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Home_ShortPress, LOCTEXT("Pico_Handle_Home_ShortPress", "Pico Handle Home_ShortPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Back_ShortPress, LOCTEXT("Pico_Handle_Back_ShortPress", "Pico Handle Back_ShortPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Touchpad_ShortPress, LOCTEXT("Pico_Handle_Touchpad_ShortPress", "Pico Handle Touchpad_ShortPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeUp_ShortPress, LOCTEXT("Pico_Handle_VolumeUp_ShortPress", "Pico Handle VolumeUp_ShortPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeDown_ShortPress, LOCTEXT("Pico_Handle_VolumeDown_ShortPress", "Pico Handle VolumeDown_ShortPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Trigger_ShortPress, LOCTEXT("Pico_Handle_Trigger_ShortPress", "Pico Handle Trigger_ShortPress"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Home_LongPress, LOCTEXT("Pico_Handle_Home_LongPress", "Pico Handle Home_LongPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Back_LongPress, LOCTEXT("Pico_Handle_Back_LongPress", "Pico Handle Back_LongPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Touchpad_LongPress, LOCTEXT("Pico_Handle_Touchpad_LongPress", "Pico Handle Touchpad_LongPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeUp_LongPress, LOCTEXT("Pico_Handle_VolumeUp_LongPress", "Pico Handle VolumeUp_LongPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_VolumeDown_LongPress, LOCTEXT("Pico_Handle_VolumeDown_LongPress", "Pico Handle VolumeDown_LongPress"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoMobileControllerKeys::Pico_Handle_Trigger_LongPress, LOCTEXT("Pico_Handle_Trigger_LongPress", "Pico Handle Trigger_LongPress"), FKeyDetails::GamepadKey));
}

void FPicoMobileController::SetKeyMapping()
{
	Buttons[(int32)EPicoMobileControllerButton::Home] = FPicoMobileKeysNames::Pico_Handle_Home;
	Buttons[(int32)EPicoMobileControllerButton::Back] = FPicoMobileKeysNames::Pico_Handle_Back;
	Buttons[(int32)EPicoMobileControllerButton::Touchpad] = FPicoMobileKeysNames::Pico_Handle_Touchpad;
	Buttons[(int32)EPicoMobileControllerButton::VolumeUp] = FPicoMobileKeysNames::Pico_Handle_VolumeUp;
	Buttons[(int32)EPicoMobileControllerButton::VolumeDown] = FPicoMobileKeysNames::Pico_Handle_VolumeDown;
	Buttons[(int32)EPicoMobileControllerButton::Trigger] = FPicoMobileKeysNames::Pico_Handle_Trigger;

	Buttons[(int32)EPicoMobileControllerButton::TouchUp] = FPicoMobileKeysNames::Pico_Handle_TouchUp;
	Buttons[(int32)EPicoMobileControllerButton::TouchDown] = FPicoMobileKeysNames::Pico_Handle_TouchDown;
	Buttons[(int32)EPicoMobileControllerButton::TouchLeft ] = FPicoMobileKeysNames::Pico_Handle_TouchLeft;
	Buttons[(int32)EPicoMobileControllerButton::TouchRight] = FPicoMobileKeysNames::Pico_Handle_TouchRight;
	Buttons[(int32)EPicoMobileControllerButton::TouchClickUp] = FPicoMobileKeysNames::Pico_Handle_TouchClickUp;
	Buttons[(int32)EPicoMobileControllerButton::TouchClickDown] = FPicoMobileKeysNames::Pico_Handle_TouchClickDown;
	Buttons[(int32)EPicoMobileControllerButton::TouchClickLeft] = FPicoMobileKeysNames::Pico_Handle_TouchClickLeft;
	Buttons[(int32)EPicoMobileControllerButton::TouchClickRight] = FPicoMobileKeysNames::Pico_Handle_TouchClickRight;


	Buttons[(int32)EPicoMobileControllerButton::Home_ShortPress] = FPicoMobileKeysNames::Pico_Handle_Home_ShortPress;
	Buttons[(int32)EPicoMobileControllerButton::Back_ShortPress] = FPicoMobileKeysNames::Pico_Handle_Back_ShortPress;
	Buttons[(int32)EPicoMobileControllerButton::Touchpad_ShortPress] = FPicoMobileKeysNames::Pico_Handle_Touchpad_ShortPress;
	Buttons[(int32)EPicoMobileControllerButton::VolumeUp_ShortPress] = FPicoMobileKeysNames::Pico_Handle_VolumeUp_ShortPress;
	Buttons[(int32)EPicoMobileControllerButton::VolumeDown_ShortPress] = FPicoMobileKeysNames::Pico_Handle_VolumeDown_ShortPress;
	Buttons[(int32)EPicoMobileControllerButton::Trigger_ShortPress] = FPicoMobileKeysNames::Pico_Handle_Trigger_ShortPress;

	Buttons[(int32)EPicoMobileControllerButton::Home_LongPress] = FPicoMobileKeysNames::Pico_Handle_Home_LongPress;
	Buttons[(int32)EPicoMobileControllerButton::Back_LongPress] = FPicoMobileKeysNames::Pico_Handle_Back_LongPress;
	Buttons[(int32)EPicoMobileControllerButton::Touchpad_LongPress] = FPicoMobileKeysNames::Pico_Handle_Touchpad_LongPress;
	Buttons[(int32)EPicoMobileControllerButton::VolumeUp_LongPress] = FPicoMobileKeysNames::Pico_Handle_VolumeUp_LongPress;
	Buttons[(int32)EPicoMobileControllerButton::VolumeDown_LongPress] = FPicoMobileKeysNames::Pico_Handle_VolumeDown_LongPress;
	Buttons[(int32)EPicoMobileControllerButton::Trigger_LongPress] = FPicoMobileKeysNames::Pico_Handle_Trigger_LongPress;
}

inline void FPicoMobileController::ProcessControllerButtons()
{
#if PLATFORM_ANDROID
	bool CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TotalButtonCount];
	bool CurrentButtonUpStates[(int32)EPicoMobileControllerButton::TotalButtonCount];

	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Home] = Hand.Home.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Back] = Hand.APP.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Touchpad] = Hand.TouchPad.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeUp] = Hand.VolumeUp.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeDown] = Hand.VolumeDown.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Trigger] = Hand.Trigger.ButtonDown;

	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchUp] = Hand.TouchPadUpEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchDown] = Hand.TouchPadDownEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchLeft] = Hand.TouchPadLeftEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchRight] = Hand.TouchPadRightEvent;

	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchClickUp] = Hand.TouchPadUpClickEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchClickDown] = Hand.TouchPadDownClickEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchClickLeft] = Hand.TouchPadLeftClickEvent;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::TouchClickRight] = Hand.TouchPadRightClickEvent;

	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Home_ShortPress] = Hand.Home.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Back_ShortPress] = Hand.APP.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Touchpad_ShortPress] = Hand.TouchPad.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeUp_ShortPress] = Hand.VolumeUp.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeDown_ShortPress] = Hand.VolumeDown.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Trigger_ShortPress] = Hand.Trigger.ButtonShortPress;

	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Home_LongPress] = Hand.Home.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Back_LongPress] = Hand.APP.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Touchpad_LongPress] = Hand.TouchPad.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeUp_LongPress] = Hand.VolumeUp.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::VolumeDown_LongPress] = Hand.VolumeDown.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoMobileControllerButton::Trigger_LongPress] = Hand.Trigger.ButtonLongPress;

	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Home] = Hand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Back] = Hand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Touchpad] = Hand.TouchPad.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeUp] = Hand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeDown] = Hand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Trigger] = Hand.Trigger.ButtonUp;

	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Home_ShortPress] = Hand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Back_ShortPress] = Hand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Touchpad_ShortPress] = Hand.TouchPad.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeUp_ShortPress] = Hand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeDown_ShortPress] = Hand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Trigger_ShortPress] = Hand.Trigger.ButtonUp;

	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Home_LongPress] = Hand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Back_LongPress] = Hand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Touchpad_LongPress] = Hand.TouchPad.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeUp_LongPress] = Hand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::VolumeDown_LongPress] = Hand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoMobileControllerButton::Trigger_LongPress] = Hand.Trigger.ButtonUp;

	for (int32 buttonIndex = 0; buttonIndex < (int32)EPicoMobileControllerButton::TotalButtonCount; buttonIndex++)
	{
		if (CurrentButtonDownStates[buttonIndex])
		{
			MessageHandler->OnControllerButtonPressed(Buttons[buttonIndex], 0, false);
		}
		if (CurrentButtonUpStates[buttonIndex])
		{
			MessageHandler->OnControllerButtonReleased(Buttons[buttonIndex], 0, false);
		}
	}
#endif
}

inline void FPicoMobileController::ProcessControllerAxis()
{
#if PLATFORM_ANDROID
	MessageHandler->OnControllerAnalog(FPicoMobileKeysNames::Pico_Handle_TouchX, 0, Hand.TouchValue.X);
	MessageHandler->OnControllerAnalog(FPicoMobileKeysNames::Pico_Handle_TouchY, 0, Hand.TouchValue.Y);
#endif
}

bool FPicoMobileController::IsAvailable() const
{
#if PLATFORM_ANDROID
	if (pvrControllerState->GetHBConnectState() == 1)
	{
		return true;
	}
#endif
	return false;
}


void FPicoMobileController::Tick(float DeltaTime){}

void FPicoMobileController::SendControllerEvents()
{
	if (IsAvailable())
	{
		UpdateButtonEvent();
		ProcessControllerButtons();
		ProcessControllerAxis();
	}	
}
void FPicoMobileController::UpdateButtonEvent()
{
#if PLATFORM_ANDROID
	
		int TempButton[47] = { 0 };
		pvrControllerState->GetControllerButtonEvent(TempButton);
		if (TempButton[0] == 0 && TempButton[5] == 0)
		{
			Hand.TouchValue = FVector2D::ZeroVector;
		}
		else
		{
			Hand.TouchValue.X = (((float)TempButton[0]) / 255 - 0.5f) * 2;
			Hand.TouchValue.Y = (((float)TempButton[5]) / 255 - 0.5f) * 2;
		}
		Hand.Home.ButtonState = TempButton[10];
		Hand.Home.ButtonDown = TempButton[11];
		Hand.Home.ButtonUp = TempButton[12];
		Hand.Home.ButtonLongPress = TempButton[13];
		Hand.Home.ButtonShortPress = TempButton[14];

		Hand.APP.ButtonState = TempButton[15];
		Hand.APP.ButtonDown = TempButton[16];
		Hand.APP.ButtonUp = TempButton[17];
		Hand.APP.ButtonLongPress = TempButton[18];
		Hand.APP.ButtonShortPress = TempButton[19];

		Hand.TouchPad.ButtonState = TempButton[20];
		Hand.TouchPad.ButtonDown = TempButton[21];
		Hand.TouchPad.ButtonUp = TempButton[22];
		Hand.TouchPad.ButtonLongPress = TempButton[23];
		Hand.TouchPad.ButtonShortPress = TempButton[24];

		Hand.VolumeUp.ButtonState = TempButton[25];
		Hand.VolumeUp.ButtonDown = TempButton[26];
		Hand.VolumeUp.ButtonUp = TempButton[27];
		Hand.VolumeUp.ButtonLongPress = TempButton[28];
		Hand.VolumeUp.ButtonShortPress = TempButton[29];

		Hand.VolumeDown.ButtonState = TempButton[30];
		Hand.VolumeDown.ButtonDown = TempButton[31];
		Hand.VolumeDown.ButtonUp = TempButton[32];
		Hand.VolumeDown.ButtonLongPress = TempButton[33];
		Hand.VolumeDown.ButtonShortPress = TempButton[34];

		Hand.Trigger.ButtonState = TempButton[35];
		Hand.Trigger.ButtonDown = TempButton[36];
		Hand.Trigger.ButtonUp = TempButton[37];
		Hand.Trigger.ButtonLongPress = TempButton[38];
		Hand.Trigger.ButtonShortPress = TempButton[39];

		Hand.Battery = TempButton[40];

		switch (TempButton[45])
		{
		case 0:
			Hand.TouchPadUpEvent = false;
			Hand.TouchPadDownEvent = false;
			Hand.TouchPadLeftEvent = false;
			Hand.TouchPadRightEvent = false;
			break;
		case 1:
			Hand.TouchPadUpEvent = true;
			Hand.TouchPadDownEvent = false;
			Hand.TouchPadLeftEvent = false;
			Hand.TouchPadRightEvent = false;
			break;
		case 2:
			Hand.TouchPadUpEvent = false;
			Hand.TouchPadDownEvent = true;
			Hand.TouchPadLeftEvent = false;
			Hand.TouchPadRightEvent = false;
			break;
		case 3:
			Hand.TouchPadUpEvent = false;
			Hand.TouchPadDownEvent = false;
			Hand.TouchPadLeftEvent = true;
			Hand.TouchPadRightEvent = false;
			break;
		case 4:
			Hand.TouchPadUpEvent = false;
			Hand.TouchPadDownEvent = false;
			Hand.TouchPadLeftEvent = false;
			Hand.TouchPadRightEvent = true;
			break;
		default:
			break;
		}

		switch (TempButton[46])
		{
		case 0:
			Hand.TouchPadUpClickEvent = false;
			Hand.TouchPadDownClickEvent = false;
			Hand.TouchPadLeftClickEvent = false;
			Hand.TouchPadRightClickEvent = false;
			break;
		case 1:
			Hand.TouchPadUpClickEvent = true;
			Hand.TouchPadDownClickEvent = false;
			Hand.TouchPadLeftClickEvent = false;
			Hand.TouchPadRightClickEvent = false;
			break;
		case 2:
			Hand.TouchPadUpClickEvent = false;
			Hand.TouchPadDownClickEvent = true;
			Hand.TouchPadLeftClickEvent = false;
			Hand.TouchPadRightClickEvent = false;
			break;
		case 3:
			Hand.TouchPadUpClickEvent = false;
			Hand.TouchPadDownClickEvent = false;
			Hand.TouchPadLeftClickEvent = true;
			Hand.TouchPadRightClickEvent = false;
			break;
		case 4:
			Hand.TouchPadUpClickEvent = false;
			Hand.TouchPadDownClickEvent = false;
			Hand.TouchPadLeftClickEvent = false;
			Hand.TouchPadRightClickEvent = true;
			break;
		default:
			break;
		}
#endif
}

void FPicoMobileController::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FPicoMobileController::Exec(UWorld * InWorld, const TCHAR * Cmd, FOutputDevice & Ar)
{
	return false;
}

void FPicoMobileController::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value){}

void FPicoMobileController::SetChannelValues(int32 ControllerId, const FForceFeedbackValues & values){}

bool FPicoMobileController::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator & OutOrientation, FVector & OutPosition, float WorldToMetersScale) const
{	
#if PLATFORM_ANDROID
	if (IsAvailable())
	{
		FQuat TempQuat = FQuat::Identity;
		pvrControllerState->GetHBOrientation(TempQuat);	
		if (ControllerRotationMode == 0)
		{
			FRotator TempRotator = FRotator(-34,0,0);
			FQuat DealtQuat = FQuat(TempRotator);
			OutOrientation = FRotator(TempQuat * DealtQuat);	
		}else
		{
			OutOrientation = TempQuat.Rotator();
		}	
		OutPosition = FVector(50, 0, 50);
		pvrControllerState->GetHBPosition(OutPosition);
		ConvertVector(OutPosition, WorldToMetersScale);
		return true;
	}
#endif
	return false;
}

ETrackingStatus FPicoMobileController::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const
{
#if PLATFORM_ANDROID
	if (IsAvailable())
	{
		return ETrackingStatus::Tracked;
	}
#endif
	return ETrackingStatus::NotTracked;
}

void FPicoMobileController::SetUseController()
{
#if PLATFORM_ANDROID
	pvrControllerState->SetHBArmJoint(0);
#endif
}

void FPicoMobileController::SetUseWrist()
{
#if PLATFORM_ANDROID
	pvrControllerState->SetHBArmJoint(1);
#endif
}

void FPicoMobileController::SetUseElbow()
{
#if PLATFORM_ANDROID
	pvrControllerState->SetHBArmJoint(2);
#endif
}

void FPicoMobileController::SetUseShoulder()
{
#if PLATFORM_ANDROID
	pvrControllerState->SetHBArmJoint(3);
#endif
}

void FPicoMobileController::SwitchArmJoint()
{
#if PLATFORM_ANDROID
	switch (pvrControllerState->GetHBArmJoint())
	{
	case PicoMobileControllerState::ArmJoint::Controller:
		SetUseWrist();
		break;
	case PicoMobileControllerState::ArmJoint::Wrist:
		SetUseElbow();
		break;
	case PicoMobileControllerState::ArmJoint::Elbow:
		SetUseShoulder();
		break;
	case PicoMobileControllerState::ArmJoint::Shoulder:
		SetUseController();
		break;
	default:
		break;
	}
#endif
}

int32 FPicoMobileController::GetArmJointIndex()
{
#if PLATFORM_ANDROID
	return (int32)pvrControllerState->GetHBArmJoint();
#endif
	return 0;
}

float FPicoMobileController::GetWorldToMetersScale() const
{
	if (IsInGameThread() && GWorld != nullptr)
	{
		return GWorld->GetWorldSettings()->WorldToMeters;
	}

	// Default value, assume Unreal units are in centimeters
	return 100.0f;
}

void FPicoMobileController::ConvertVector(FVector & vector, float WorldToMetersScale) const
{
	FVector tempVector = vector;
	// Positon：OpenGL to Unreal
	vector.X = -tempVector.Z*WorldToMetersScale;
	vector.Y = tempVector.X*WorldToMetersScale;
	vector.Z = tempVector.Y*WorldToMetersScale;
}