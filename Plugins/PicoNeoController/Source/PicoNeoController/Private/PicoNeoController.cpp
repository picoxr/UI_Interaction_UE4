// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoNeoController.h"
#include "PicoNeoControllerPrivatePCH.h"
#include "PicoNeoControllerKey.h"
#include "PicoMobile/Private/PicoMobileSettings.h"

#define LOCTEXT_NAMESPACE "PicoNeoInput"

DEFINE_LOG_CATEGORY_STATIC(PicoNeoController, Log, All);

class FPicoNeoControllerPlugin : public IPicoNeoControllerPlugin
{
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override
	{
		return TSharedPtr< class IInputDevice >(new FPicoNeoController(InMessageHandler));
	}
};
IMPLEMENT_MODULE(FPicoNeoControllerPlugin, PicoNeoController)

FPicoNeoController::FPicoNeoController(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
	: 
	RockerXYLeftValue(FVector2D::ZeroVector),
	RockerXYRightValue(FVector2D::ZeroVector),
	MessageHandler(InMessageHandler),
	ControllerRotationMode(0)
{
#if PLATFORM_ANDROID
	pJni = FPicoNeoControllerJni::GetInstance();
	deviceType = pJni->GetNeoDeviceType();
	ControllerRotationMode = pJni->GetControllerRotationMode();
#endif
	AddKeysToEngine();
	SetKeyMapping();
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
}

FPicoNeoController::~FPicoNeoController()
{
#if PLATFORM_ANDROID
	FPicoNeoControllerJni::GetInstance()->Destory();
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
#endif
}

// IInputDevice

void FPicoNeoController::Tick(float DeltaTime)
{
}

void FPicoNeoController::SendControllerEvents()
{
	if (IsAvailable())
	{
		UpdateButtonEvent(NeoLeftHand, NeoRightHand);
		ProcessControllerButtons();
		ProcessControllerAxis();
	}
}
void FPicoNeoController::DispatchButtonEvent(int* TempButton, FPicoNeoControllerButtonState &Hand)
{
	if (TempButton[0] == 0 && TempButton[5] == 0)
	{
		Hand.RockerValue = FVector2D::ZeroVector;
	}
	else
	{
		Hand.RockerValue.X = (static_cast<float>(TempButton[0]) / 255 - 0.5f) * 2;
		Hand.RockerValue.Y = (static_cast<float>(TempButton[5]) / 255 - 0.5f) * 2;
	}

		Hand.Home.ButtonState = static_cast<bool>(TempButton[10]);
		Hand.Home.ButtonDown = static_cast<bool>(TempButton[11]);
		Hand.Home.ButtonUp = static_cast<bool>(TempButton[12]);
		Hand.Home.ButtonLongPress = static_cast<bool>(TempButton[13]);
		Hand.Home.ButtonShortPress = static_cast<bool>(TempButton[14]);

		Hand.APP.ButtonState = static_cast<bool>(TempButton[15]);
		Hand.APP.ButtonDown = static_cast<bool>(TempButton[16]);
		Hand.APP.ButtonUp = static_cast<bool>(TempButton[17]);
		Hand.APP.ButtonLongPress = static_cast<bool>(TempButton[18]);
		Hand.APP.ButtonShortPress = static_cast<bool>(TempButton[19]);

		Hand.Rocker.ButtonState = static_cast<bool>(TempButton[20]);
		Hand.Rocker.ButtonDown = static_cast<bool>(TempButton[21]);
		Hand.Rocker.ButtonUp = static_cast<bool>(TempButton[22]);
		Hand.Rocker.ButtonLongPress = static_cast<bool>(TempButton[23]);
		Hand.Rocker.ButtonShortPress = static_cast<bool>(TempButton[24]);

		Hand.VolumeUp.ButtonState = static_cast<bool>(TempButton[25]);
		Hand.VolumeUp.ButtonDown = static_cast<bool>(TempButton[26]);
		Hand.VolumeUp.ButtonUp = static_cast<bool>(TempButton[27]);
		Hand.VolumeUp.ButtonLongPress = static_cast<bool>(TempButton[28]);
		Hand.VolumeUp.ButtonShortPress = static_cast<bool>(TempButton[29]);

		Hand.VolumeDown.ButtonState = static_cast<bool>(TempButton[30]);
		Hand.VolumeDown.ButtonDown = static_cast<bool>(TempButton[31]);
		Hand.VolumeDown.ButtonUp = static_cast<bool>(TempButton[32]);
		Hand.VolumeDown.ButtonLongPress = static_cast<bool>(TempButton[33]);
		Hand.VolumeDown.ButtonShortPress = static_cast<bool>(TempButton[34]);

		Hand.Trigger.ButtonState = static_cast<bool>(TempButton[35]);
		Hand.Trigger.ButtonDown = static_cast<bool>(TempButton[36]);
		Hand.Trigger.ButtonUp = static_cast<bool>(TempButton[37]);
		Hand.Trigger.ButtonLongPress = static_cast<bool>(TempButton[38]);
		Hand.Trigger.ButtonShortPress = static_cast<bool>(TempButton[39]);

		Hand.Battery = TempButton[40];

		Hand.XorA.ButtonState = static_cast<bool>(TempButton[45]);
		Hand.XorA.ButtonDown = static_cast<bool>(TempButton[46]);
		Hand.XorA.ButtonUp = static_cast<bool>(TempButton[47]);
		Hand.XorA.ButtonLongPress = static_cast<bool>(TempButton[48]);
		Hand.XorA.ButtonShortPress = static_cast<bool>(TempButton[49]);

		Hand.YorB.ButtonState = static_cast<bool>(TempButton[50]);
		Hand.YorB.ButtonDown = static_cast<bool>(TempButton[51]);
		Hand.YorB.ButtonUp = static_cast<bool>(TempButton[52]);
		Hand.YorB.ButtonLongPress = static_cast<bool>(TempButton[53]);
		Hand.YorB.ButtonShortPress = static_cast<bool>(TempButton[54]);

		Hand.LeftGrip.ButtonState = static_cast<bool>(TempButton[55]);
		Hand.LeftGrip.ButtonDown = static_cast<bool>(TempButton[56]);
		Hand.LeftGrip.ButtonUp = static_cast<bool>(TempButton[57]);
		Hand.LeftGrip.ButtonLongPress = static_cast<bool>(TempButton[58]);
		Hand.LeftGrip.ButtonShortPress = static_cast<bool>(TempButton[59]);

		Hand.RightGrip.ButtonState = static_cast<bool>(TempButton[60]);
		Hand.RightGrip.ButtonDown = static_cast<bool>(TempButton[61]);
		Hand.RightGrip.ButtonUp = static_cast<bool>(TempButton[62]);
		Hand.RightGrip.ButtonLongPress = static_cast<bool>(TempButton[63]);
		Hand.RightGrip.ButtonShortPress = static_cast<bool>(TempButton[64]);

		switch (TempButton[65])
		{
		case 0:
			Hand.RockerUpEvent = false;
			Hand.RockerDownEvent = false;
			Hand.RockerLeftEvent = false;
			Hand.RockerRightEvent = false;
			break;
		case 1:
			Hand.RockerUpEvent = true;
			Hand.RockerDownEvent = false;
			Hand.RockerLeftEvent = false;
			Hand.RockerRightEvent = false;
			break;
		case 2:
			Hand.RockerUpEvent = false;
			Hand.RockerDownEvent = true;
			Hand.RockerLeftEvent = false;
			Hand.RockerRightEvent = false;
			break;
		case 3:
			Hand.RockerUpEvent = false;
			Hand.RockerDownEvent = false;
			Hand.RockerLeftEvent = true;
			Hand.RockerRightEvent = false;
			break;
		case 4:
			Hand.RockerUpEvent = false;
			Hand.RockerDownEvent = false;
			Hand.RockerLeftEvent = false;
			Hand.RockerRightEvent = true;
			break;
		default:
			break;
		}
		switch (TempButton[66])
		{
		case 0:
			Hand.RockerUpClickEvent = false;
			Hand.RockerDownClickEvent = false;
			Hand.RockerLeftClickEvent = false;
			Hand.RockerRightClickEvent = false;
			break;
		case 1:
			Hand.RockerUpClickEvent = true;
			Hand.RockerDownClickEvent = false;
			Hand.RockerLeftClickEvent = false;
			Hand.RockerRightClickEvent = false;
			break;
		case 2:
			Hand.RockerUpClickEvent = false;
			Hand.RockerDownClickEvent = true;
			Hand.RockerLeftClickEvent = false;
			Hand.RockerRightClickEvent = false;
			break;
		case 3:
			Hand.RockerUpClickEvent = false;
			Hand.RockerDownClickEvent = false;
			Hand.RockerLeftClickEvent = true;
			Hand.RockerRightClickEvent = false;
			break;
		case 4:
			Hand.RockerUpClickEvent = false;
			Hand.RockerDownClickEvent = false;
			Hand.RockerLeftClickEvent = false;
			Hand.RockerRightClickEvent = true;
			break;
		default:
			break;
	}

}

void FPicoNeoController::DispatchTouchEvent(int32 Hand)
{
	int TouchState[15] = { 0 };
#if PLATFORM_ANDROID
	if(Hand == 0 && pJni->GetMainControllerConnectState() == 1)
	{
		pJni->GetControllerTouchEvent(Hand,TouchState);
	}
	if(Hand == 1 && pJni->GetSubControllerConnectState() == 1)
	{
		pJni->GetControllerTouchEvent(Hand,TouchState);
	}
#endif
	if (Hand == 0)
	{
		LeftTouch.AorX.TouchState = static_cast<bool>(TouchState[0]);
		LeftTouch.AorX.TouchPressed = static_cast<bool>(TouchState[1]);
		LeftTouch.AorX.TouchReleased = static_cast<bool>(TouchState[2]);

		LeftTouch.BorY.TouchState = static_cast<bool>(TouchState[3]);
		LeftTouch.BorY.TouchPressed = static_cast<bool>(TouchState[4]);
		LeftTouch.BorY.TouchReleased = static_cast<bool>(TouchState[5]);

		LeftTouch.Rocker.TouchState = static_cast<bool>(TouchState[6]);
		LeftTouch.Rocker.TouchPressed = static_cast<bool>(TouchState[7]);
		LeftTouch.Rocker.TouchReleased = static_cast<bool>(TouchState[8]);

		LeftTouch.Trigger.TouchState = static_cast<bool>(TouchState[9]);
		LeftTouch.Trigger.TouchPressed = static_cast<bool>(TouchState[10]);
		LeftTouch.Trigger.TouchReleased = static_cast<bool>(TouchState[11]);

		LeftTouch.Thumbrest.TouchState = static_cast<bool>(TouchState[12]);
		LeftTouch.Thumbrest.TouchPressed = static_cast<bool>(TouchState[13]);
		LeftTouch.Thumbrest.TouchReleased = static_cast<bool>(TouchState[14]);
	}else if (Hand == 1)
	{
		RightTouch.AorX.TouchState = static_cast<bool>(TouchState[0]);
		RightTouch.AorX.TouchPressed = static_cast<bool>(TouchState[1]);
		RightTouch.AorX.TouchReleased = static_cast<bool>(TouchState[2]);

		RightTouch.BorY.TouchState = static_cast<bool>(TouchState[3]);
		RightTouch.BorY.TouchPressed = static_cast<bool>(TouchState[4]);
		RightTouch.BorY.TouchReleased = static_cast<bool>(TouchState[5]);

		RightTouch.Rocker.TouchState = static_cast<bool>(TouchState[6]);
		RightTouch.Rocker.TouchPressed = static_cast<bool>(TouchState[7]);
		RightTouch.Rocker.TouchReleased = static_cast<bool>(TouchState[8]);

		RightTouch.Trigger.TouchState = static_cast<bool>(TouchState[9]);
		RightTouch.Trigger.TouchPressed = static_cast<bool>(TouchState[10]);
		RightTouch.Trigger.TouchReleased = static_cast<bool>(TouchState[11]);

		RightTouch.Thumbrest.TouchState = static_cast<bool>(TouchState[12]);
		RightTouch.Thumbrest.TouchPressed = static_cast<bool>(TouchState[13]);
		RightTouch.Thumbrest.TouchReleased = static_cast<bool>(TouchState[14]);
	}		
}

void FPicoNeoController::UpdateButtonEvent(FPicoNeoControllerButtonState &LeftHand, FPicoNeoControllerButtonState &RightHand)
{
#if PLATFORM_ANDROID
	int TempButtonLeft[67] = { 0 };
	int TempButtonRight[67] = { 0 };
	pJni->GetControllerButtonEvent(TempButtonLeft, TempButtonRight);
	if(pJni->GetServiceConnectState() == 1 && pJni->GetMainControllerConnectState() == 1)
	{
		DispatchButtonEvent(TempButtonLeft, LeftHand);
		DispatchTouchEvent(0);
	}else
	{
		memset(TempButtonLeft,0,sizeof(TempButtonLeft));
		DispatchButtonEvent(TempButtonLeft, LeftHand);
		DispatchTouchEvent(0);
	}
	if(pJni->GetServiceConnectState() == 1 && pJni->GetSubControllerConnectState() == 1)
	{
		DispatchButtonEvent(TempButtonRight, RightHand);
		DispatchTouchEvent(1);
	}else
	{
		memset(TempButtonRight,0,sizeof(TempButtonRight));
		DispatchButtonEvent(TempButtonRight, RightHand);
		DispatchTouchEvent(1);
	}	
#endif
}

void FPicoNeoController::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool FPicoNeoController::Exec(UWorld * InWorld, const TCHAR * Cmd, FOutputDevice & Ar)
{
	return false;
}

void FPicoNeoController::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
#if PLATFORM_ANDROID
	pJni->ShakeMainController();
	pJni->ShakeSubController();
#endif
}

void FPicoNeoController::SetChannelValues(int32 ControllerId, const FForceFeedbackValues & values)
{
}

// IMotionController
FName FPicoNeoController::DeviceTypeName(TEXT("PicoNeoController"));
FName FPicoNeoController::GetMotionControllerDeviceTypeName() const
{
	return DeviceTypeName;
}


bool FPicoNeoController::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const
{
#if PLATFORM_ANDROID
	if (IsAvailable())
	{
		FQuat tempQuat = FQuat::Identity;
		switch (DeviceHand)
		{
		case EControllerHand::Special_1:
			pJni->GetMainControllerOrientation(tempQuat);
			if (ControllerRotationMode == 0)
			{
				FRotator TempRotator = FRotator(-34,0,0);
				FQuat DealtQuat = FQuat(TempRotator);
				OutOrientation = FRotator(tempQuat * DealtQuat);	
			}else
			{
				OutOrientation = tempQuat.Rotator();
			}
			pJni->GetMainControllerPosition(OutPosition);
			ConvertVector(OutPosition, WorldToMetersScale);
			break;

		case EControllerHand::Special_2:
			pJni->GetSubControllerOrientation(tempQuat);
			if (ControllerRotationMode == 0)
			{
				FRotator TempRotator = FRotator(-34,0,0);
				FQuat DealtQuat = FQuat(TempRotator);
				OutOrientation = FRotator(tempQuat * DealtQuat);	
			}else
			{
				OutOrientation = tempQuat.Rotator();
			}
			pJni->GetSubControllerPosition(OutPosition);
			ConvertVector(OutPosition, WorldToMetersScale);
			break;

		case EControllerHand::Left:
			pJni->GetMainControllerOrientation(tempQuat);
			if (ControllerRotationMode == 0)
			{
				FRotator TempRotator = FRotator(-34,0,0);
				FQuat DealtQuat = FQuat(TempRotator);
				OutOrientation = FRotator(tempQuat * DealtQuat);	
			}else
			{
				OutOrientation = tempQuat.Rotator();
			}
			pJni->GetMainControllerPosition(OutPosition);
			ConvertVector(OutPosition, WorldToMetersScale);
			break;

		case EControllerHand::Right:
			pJni->GetSubControllerOrientation(tempQuat);
			if (ControllerRotationMode == 0)
			{
				FRotator TempRotator = FRotator(-34,0,0);
				FQuat DealtQuat = FQuat(TempRotator);
				OutOrientation = FRotator(tempQuat * DealtQuat);	
			}else
			{
				OutOrientation = tempQuat.Rotator();
			}
			pJni->GetSubControllerPosition(OutPosition);
			ConvertVector(OutPosition, WorldToMetersScale);
			break;
		default:
			break;
		}
		return true;
	}
#endif
	return false;
}

ETrackingStatus FPicoNeoController::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const
{
#if PLATFORM_ANDROID
	if (1 == pJni->GetMainControllerConnectState()
		|| 1 == pJni->GetSubControllerConnectState())
	{
		return ETrackingStatus::Tracked;
	}
#endif
	return ETrackingStatus::NotTracked;
}

#if ENGINE_MINOR_VERSION > 25
#define InputAxis FKeyDetails::Axis1D
#else
#define InputAxis FKeyDetails::FloatAxis
#endif
// Helper Functions

void FPicoNeoController::AddKeysToEngine()
{
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Home, LOCTEXT("PicoNeoController_Main_Home", "PicoNeoController (Main) Home"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_App, LOCTEXT("PicoNeoController_Main_App", "PicoNeoController (Main) App"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Touchpad, LOCTEXT("PicoNeoController_Main_Touchpad", "PicoNeoController (Main) Touchpad"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up, LOCTEXT("PicoNeoController_Main_Volume_Up", "PicoNeoController (Main) Volume Up"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down, LOCTEXT("PicoNeoController_Main_Volume_Down", "PicoNeoController (Main) Volume Down"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Trigger, LOCTEXT("PicoNeoController_Main_Trigger", "PicoNeoController (Main) Trigger"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TriggerAxis, LOCTEXT("PicoNeoController_Main_TriggerAxis", "PicoNeoController (Main) TriggerAxis"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchX, LOCTEXT("PicoNeoController_Main_TouchX", "PicoNeoController (Main) TouchX"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchY, LOCTEXT("PicoNeoController_Main_TouchY", "PicoNeoController (Main) TouchY"), FKeyDetails::GamepadKey | InputAxis));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchUp, LOCTEXT("PicoNeoController_Main_TouchUp", "PicoNeoController (Main) TouchUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchDown, LOCTEXT("PicoNeoController_Main_TouchDown", "PicoNeoController (Main) TouchDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchLeft, LOCTEXT("PicoNeoController_Main_TouchLeft", "PicoNeoController (Main) TouchLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchRight, LOCTEXT("PicoNeoController_Main_TouchRight", "PicoNeoController (Main) TouchRight"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchClickUp, LOCTEXT("PicoNeoController_Main_TouchClickUp", "PicoNeoController (Main) TouchClickUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchClickDown, LOCTEXT("PicoNeoController_Main_TouchClickDown", "PicoNeoController (Main) TouchClickDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchClickLeft, LOCTEXT("PicoNeoController_Main_TouchClickLeft", "PicoNeoController (Main) TouchClickLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_TouchClickRight, LOCTEXT("PicoNeoController_Main_TouchClickRight", "PicoNeoController (Main) TouchClickRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Home, LOCTEXT("PicoNeoController_L_Home", "PicoNeoController (L) Home"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_App, LOCTEXT("PicoNeoController_L_App", "PicoNeoController (L) App"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerC, LOCTEXT("PicoNeoController_L_RockerC", "PicoNeoController (L) RockerC"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_X, LOCTEXT("PicoNeoController_L_X", "PicoNeoController (L) X"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Y, LOCTEXT("PicoNeoController_L_Y", "PicoNeoController (L) Y"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Trigger, LOCTEXT("PicoNeoController_L_Trigger", "PicoNeoController (L) Trigger"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_TriggerAxis, LOCTEXT("PicoNeoController_L_TriggerAxis", "PicoNeoController (L) TriggerAxis"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerX, LOCTEXT("PicoNeoController_L_RockerX", "PicoNeoController (L) RockerX"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerY, LOCTEXT("PicoNeoController_L_RockerY", "PicoNeoController (L) RockerY"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_LGrip, LOCTEXT("PicoNeoController_L_LGrip", "PicoNeoController (L) LGrip"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RGrip, LOCTEXT("PicoNeoController_L_RGrip", "PicoNeoController (L) RGrip"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerUp, LOCTEXT("PicoNeoController_L_RockerUp", "PicoNeoController (L) RockerUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerDown, LOCTEXT("PicoNeoController_L_RockerDown", "PicoNeoController (L) RockerDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerLeft, LOCTEXT("PicoNeoController_L_RockerLeft", "PicoNeoController (L) RockerLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerRight, LOCTEXT("PicoNeoController_L_RockerRight", "PicoNeoController (L) RockerRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerClickUp, LOCTEXT("PicoNeoController_L_RockerClickUp", "PicoNeoController (L) RockerClickUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerClickDown, LOCTEXT("PicoNeoController_L_RockerClickDown", "PicoNeoController (L) RockerClickDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerClickLeft, LOCTEXT("PicoNeoController_L_RockerClickLeft", "PicoNeoController (L) RockerClickLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerClickRight, LOCTEXT("PicoNeoController_L_RockerClickRight", "PicoNeoController (L) RockerClickRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Home, LOCTEXT("PicoNeoController_Sub_Home", "PicoNeoController (Sub) Home"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_App, LOCTEXT("PicoNeoController_Sub_App", "PicoNeoController (Sub) App"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad, LOCTEXT("PicoNeoController_Sub_Touchpad", "PicoNeoController (Sub) Touchpad"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up, LOCTEXT("PicoNeoController_Sub_Volume_Up", "PicoNeoController (Sub) Volume Up"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down, LOCTEXT("PicoNeoController_Sub_Volume_Down", "PicoNeoController (Sub) Volume Down"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Trigger, LOCTEXT("PicoNeoController_Sub_Trigger", "PicoNeoController (Sub) Trigger"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TriggerAxis, LOCTEXT("PicoNeoController_Sub_TriggerAxis", "PicoNeoController (Sub) TriggerAxis"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchX, LOCTEXT("PicoNeoController_Sub_TouchX", "PicoNeoController (Sub) TouchX"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchY, LOCTEXT("PicoNeoController_Sub_TouchY", "PicoNeoController (Sub) TouchY"), FKeyDetails::GamepadKey | InputAxis));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchUp, LOCTEXT("PicoNeoController_Sub_TouchUp", "PicoNeoController (Sub) TouchUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchDown, LOCTEXT("PicoNeoController_Sub_TouchDown", "PicoNeoController (Sub) TouchDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchLeft, LOCTEXT("PicoNeoController_Sub_TouchLeft", "PicoNeoController (Sub) TouchLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchRight, LOCTEXT("PicoNeoController_Sub_TouchRight", "PicoNeoController (Sub) TouchRight"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickUp, LOCTEXT("PicoNeoController_Sub_TouchClickUp", "PicoNeoController (Sub) TouchClickUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickDown, LOCTEXT("PicoNeoController_Sub_TouchClickDown", "PicoNeoController (Sub) TouchClickDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickLeft, LOCTEXT("PicoNeoController_Sub_TouchClickLeft", "PicoNeoController (Sub) TouchClickLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_TouchClickRight, LOCTEXT("PicoNeoController_Sub_TouchClickRight", "PicoNeoController (Sub) TouchClickRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Home, LOCTEXT("PicoNeoController_R_Home", "PicoNeoController (R) Home"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_App, LOCTEXT("PicoNeoController_R_App", "PicoNeoController (R) App"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerC, LOCTEXT("PicoNeoController_R_RockerC", "PicoNeoController (R) RockerC"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_A, LOCTEXT("PicoNeoController_R_A", "PicoNeoController (R) A"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_B, LOCTEXT("PicoNeoController_R_B", "PicoNeoController (R) B"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Trigger, LOCTEXT("PicoNeoController_R_Trigger", "PicoNeoController (R) Trigger"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_TriggerAxis, LOCTEXT("PicoNeoController_R_TriggerAxis", "PicoNeoController (R) TriggerAxis"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerX, LOCTEXT("PicoNeoController_R_RockerX", "PicoNeoController (R) RockerX"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerY, LOCTEXT("PicoNeoController_R_RockerY", "PicoNeoController (R) RockerY"), FKeyDetails::GamepadKey | InputAxis));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_LGrip, LOCTEXT("PicoNeoController_R_LGrip", "PicoNeoController (R) LGrip"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RGrip, LOCTEXT("PicoNeoController_R_RGrip", "PicoNeoController (R) RGrip"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerUp, LOCTEXT("PicoNeoController_R_RockerUp", "PicoNeoController (R) RockerUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerDown, LOCTEXT("PicoNeoController_R_RockerDown", "PicoNeoController (R) RockerDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerLeft, LOCTEXT("PicoNeoController_R_RockerLeft", "PicoNeoController (R) RockerLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerRight, LOCTEXT("PicoNeoController_R_RockerRight", "PicoNeoController (R) RockerRight"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerClickUp, LOCTEXT("PicoNeoController_R_RockerClickUp", "PicoNeoController (R) RockerClickUp"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerClickDown, LOCTEXT("PicoNeoController_R_RockerClickDown", "PicoNeoController (R) RockerClickDown"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerClickLeft, LOCTEXT("PicoNeoController_R_RockerClickLeft", "PicoNeoController (R) RockerClickLeft"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerClickRight, LOCTEXT("PicoNeoController_R_RockerClickRight", "PicoNeoController (R) RockerClickRight"), FKeyDetails::GamepadKey));

	//ShortPressed
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Home_ShortPressed, LOCTEXT("PicoNeoController_Main_Home_ShortPressed", "PicoNeoController (Main) Home_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_App_ShortPressed, LOCTEXT("PicoNeoController_Main_App_ShortPressed", "PicoNeoController (Main) App_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Touchpad_ShortPressed, LOCTEXT("PicoNeoController_Main_Touchpad_ShortPressed", "PicoNeoController (Main) Touchpad_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up_ShortPressed, LOCTEXT("PicoNeoController_Main_Volume_Up_ShortPressed", "PicoNeoController (Main) Volume Up_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down_ShortPressed, LOCTEXT("PicoNeoController_Main_Volume_Down_ShortPressed", "PicoNeoController (Main) Volume Down_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Trigger_ShortPressed, LOCTEXT("PicoNeoController_Main_Trigger_ShortPressed", "PicoNeoController (Main) Trigger_ShortPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Home_ShortPressed, LOCTEXT("PicoNeoController_L_Home_ShortPressed", "PicoNeoController (L) Home_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_App_ShortPressed, LOCTEXT("PicoNeoController_L_App_ShortPressed", "PicoNeoController (L) App_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerC_ShortPressed, LOCTEXT("PicoNeoController_L_RockerC_ShortPressed", "PicoNeoController (L) RockerC_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_X_ShortPressed, LOCTEXT("PicoNeoController_L_X_ShortPressed", "PicoNeoController (L) X_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Y_ShortPressed, LOCTEXT("PicoNeoController_L_Y_ShortPressed", "PicoNeoController (L) Y_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_LGrip_ShortPressed, LOCTEXT("PicoNeoController_L_LGrip_ShortPressed", "PicoNeoController (L) LGrip_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RGrip_ShortPressed, LOCTEXT("PicoNeoController_L_RGrip_ShortPressed", "PicoNeoController (L) RGrip_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Trigger_ShortPressed, LOCTEXT("PicoNeoController_L_Trigger_ShortPressed", "PicoNeoController (L) Trigger_ShortPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Home_ShortPressed, LOCTEXT("PicoNeoController_Sub_Home_ShortPressed", "PicoNeoController (Sub) Home_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_App_ShortPressed, LOCTEXT("PicoNeoController_Sub_App_ShortPressed", "PicoNeoController (Sub) App_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad_ShortPressed, LOCTEXT("PicoNeoController_Sub_Touchpad_ShortPressed", "PicoNeoController (Sub) Touchpad_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up_ShortPressed, LOCTEXT("PicoNeoController_Sub_Volume_Up_ShortPressed", "PicoNeoController (Sub) Volume Up_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down_ShortPressed, LOCTEXT("PicoNeoController_Sub_Volume_Down_ShortPressed", "PicoNeoController (Sub) Volume Down_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Trigger_ShortPressed, LOCTEXT("PicoNeoController_Sub_Trigger_ShortPressed", "PicoNeoController (Sub) Trigger_ShortPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Home_ShortPressed, LOCTEXT("PicoNeoController_R_Home_ShortPressed", "PicoNeoController (R) Home_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_App_ShortPressed, LOCTEXT("PicoNeoController_R_App_ShortPressed", "PicoNeoController (R) App_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerC_ShortPressed, LOCTEXT("PicoNeoController_R_RockerC_ShortPressed", "PicoNeoController (R) RockerC_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_A_ShortPressed, LOCTEXT("PicoNeoController_R_A_ShortPressed", "PicoNeoController (R) A_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_B_ShortPressed, LOCTEXT("PicoNeoController_R_B_ShortPressed", "PicoNeoController (R) B_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Trigger_ShortPressed, LOCTEXT("PicoNeoController_R_Trigger_ShortPressed", "PicoNeoController (R) Trigger_ShortPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_LGrip_ShortPressed, LOCTEXT("PicoNeoController_R_LGrip_ShortPressed", "PicoNeoController (R) LGrip_ShortPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RGrip_ShortPressed, LOCTEXT("PicoNeoController_R_RGrip_ShortPressed", "PicoNeoController (R) RGrip_ShortPressed"), FKeyDetails::GamepadKey));

	//LongPressed
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Home_LongPressed, LOCTEXT("PicoNeoController_Main_Home_LongPressed", "PicoNeoController (Main) Home_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_App_LongPressed, LOCTEXT("PicoNeoController_Main_App_LongPressed", "PicoNeoController (Main) App_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Touchpad_LongPressed, LOCTEXT("PicoNeoController_Main_Touchpad_LongPressed", "PicoNeoController (Main) Touchpad_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Up_LongPressed, LOCTEXT("PicoNeoController_Main_Volume_Up_LongPressed", "PicoNeoController (Main) Volume Up_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Volume_Down_LongPressed, LOCTEXT("PicoNeoController_Main_Volume_Down_LongPressed", "PicoNeoController (Main) Volume Down_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Main_Trigger_LongPressed, LOCTEXT("PicoNeoController_Main_Trigger_LongPressed", "PicoNeoController (Main) Trigger_LongPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Home_LongPressed, LOCTEXT("PicoNeoController_L_Home_LongPressed", "PicoNeoController (L) Home_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_App_LongPressed, LOCTEXT("PicoNeoController_L_App_LongPressed", "PicoNeoController (L) App_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RockerC_LongPressed, LOCTEXT("PicoNeoController_L_RockerC_LongPressed", "PicoNeoController (L) RockerC_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_X_LongPressed, LOCTEXT("PicoNeoController_L_X_LongPressed", "PicoNeoController (L) X_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Y_LongPressed, LOCTEXT("PicoNeoController_L_Y_LongPressed", "PicoNeoController (L) Y_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_LGrip_LongPressed, LOCTEXT("PicoNeoController_L_LGrip_LongPressed", "PicoNeoController (L) LGrip_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_RGrip_LongPressed, LOCTEXT("PicoNeoController_L_RGrip_LongPressed", "PicoNeoController (L) RGrip_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Trigger_LongPressed, LOCTEXT("PicoNeoController_L_Trigger_LongPressed", "PicoNeoController (L) Trigger_LongPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Home_LongPressed, LOCTEXT("PicoNeoController_Sub_Home_LongPressed", "PicoNeoController (Sub) Home_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_App_LongPressed, LOCTEXT("PicoNeoController_Sub_App_LongPressed", "PicoNeoController (Sub) App_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Touchpad_LongPressed, LOCTEXT("PicoNeoController_Sub_Touchpad_LongPressed", "PicoNeoController (Sub) Touchpad_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Up_LongPressed, LOCTEXT("PicoNeoController_Sub_Volume_Up_LongPressed", "PicoNeoController (Sub) Volume Up_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Volume_Down_LongPressed, LOCTEXT("PicoNeoController_Sub_Volume_Down_LongPressed", "PicoNeoController (Sub) Volume Down_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_Sub_Trigger_LongPressed, LOCTEXT("PicoNeoController_Sub_Trigger_LongPressed", "PicoNeoController (Sub) Trigger_LongPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Home_LongPressed, LOCTEXT("PicoNeoController_R_Home_LongPressed", "PicoNeoController (R) Home_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_App_LongPressed, LOCTEXT("PicoNeoController_R_App_LongPressed", "PicoNeoController (R) App_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RockerC_LongPressed, LOCTEXT("PicoNeoController_R_RockerC_LongPressed", "PicoNeoController (R) RockerC_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_A_LongPressed, LOCTEXT("PicoNeoController_R_A_LongPressed", "PicoNeoController (R) A_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_B_LongPressed, LOCTEXT("PicoNeoController_R_B_LongPressed", "PicoNeoController (R) B_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Trigger_LongPressed, LOCTEXT("PicoNeoController_R_Trigger_LongPressed", "PicoNeoController (R) Trigger_LongPressed"), FKeyDetails::GamepadKey));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_LGrip_LongPressed, LOCTEXT("PicoNeoController_R_LGrip_LongPressed", "PicoNeoController (R) LGrip_LongPressed"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_RGrip_LongPressed, LOCTEXT("PicoNeoController_R_RGrip_LongPressed", "PicoNeoController (R) RGrip_LongPressed"), FKeyDetails::GamepadKey));

	//Add for Neo3
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Rocker_CapTouch, LOCTEXT("PicoNeoController_L_Rocker_CapTouch", "PicoNeoController (L) Rocker_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_X_CapTouch, LOCTEXT("PicoNeoController_L_X_CapTouch", "PicoNeoController (L) X_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Y_CapTouch, LOCTEXT("PicoNeoController_L_Y_CapTouch", "PicoNeoController (L) Y_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Thumbrest, LOCTEXT("PicoNeoController_L_Thumbrest", "PicoNeoController (L) Thumbrest"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Trigger_CapTouch, LOCTEXT("PicoNeoController_L_Trigger_CapTouch", "PicoNeoController (L) Trigger_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_L_Grip_Axis, LOCTEXT("PicoNeoController_L_Grip_Axis", "PicoNeoController (L) Grip_Axis"),  FKeyDetails::GamepadKey | InputAxis));

	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Rocker_CapTouch, LOCTEXT("PicoNeoController_R_Rocker_CapTouch", "PicoNeoController (R) Rocker_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_A_CapTouch, LOCTEXT("PicoNeoController_R_A_CapTouch", "PicoNeoController (R) A_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_B_CapTouch, LOCTEXT("PicoNeoController_R_B_CapTouch", "PicoNeoController (R) B_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Thumbrest, LOCTEXT("PicoNeoController_R_Thumbrest", "PicoNeoController (R) Thumbrest"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Trigger_CapTouch, LOCTEXT("PicoNeoController_R_Trigger_CapTouch", "PicoNeoController (R) Trigger_CapTouch"), FKeyDetails::GamepadKey));
	EKeys::AddKey(FKeyDetails(FPicoNeoControllerKey::PicoNeoController_R_Grip_Axis, LOCTEXT("PicoNeoController_R_Grip_Axis", "PicoNeoController (R) Grip_Axis"),  FKeyDetails::GamepadKey | InputAxis));
	
}

void FPicoNeoController::SetKeyMapping()
{

	for (int32 controllerIndex = 0; controllerIndex < (int32)EPicoNeoControllerMark::TotalControllerCount; ++controllerIndex)
	{
		for (int32 buttonIndex = 0; buttonIndex < (int32)EPicoNeoControllerButton::TotalButtonCount; ++buttonIndex)
		{
			VRStandardButtons[controllerIndex][buttonIndex] = "";
		}
	}
	if (0 == deviceType)
	{
		//Simple
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home] = FPicoNeoKeyNames::PicoNeoController_Main_Home;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App] = FPicoNeoKeyNames::PicoNeoController_Main_App;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad] = FPicoNeoKeyNames::PicoNeoController_Main_Touchpad;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger] = FPicoNeoKeyNames::PicoNeoController_Main_Trigger;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home] = FPicoNeoKeyNames::PicoNeoController_Sub_Home;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App] = FPicoNeoKeyNames::PicoNeoController_Sub_App;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad] = FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger] = FPicoNeoKeyNames::PicoNeoController_Sub_Trigger;

		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerUp] = FPicoNeoKeyNames::PicoNeoController_Main_TouchUp;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerDown] = FPicoNeoKeyNames::PicoNeoController_Main_TouchDown;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerLeft] = FPicoNeoKeyNames::PicoNeoController_Main_TouchLeft;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerRight] = FPicoNeoKeyNames::PicoNeoController_Main_TouchRight;

		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickUp] = FPicoNeoKeyNames::PicoNeoController_Main_TouchClickUp;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickDown] = FPicoNeoKeyNames::PicoNeoController_Main_TouchClickDown;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickLeft] = FPicoNeoKeyNames::PicoNeoController_Main_TouchClickLeft;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickRight] = FPicoNeoKeyNames::PicoNeoController_Main_TouchClickRight;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerUp] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchUp;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerDown] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchDown;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerLeft] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchLeft;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerRight] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchRight;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickUp] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickUp;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickDown] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickDown;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickLeft] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickLeft;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickRight] = FPicoNeoKeyNames::PicoNeoController_Sub_TouchClickRight;
		//ShortPress
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_Home_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_App_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_Touchpad_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_Trigger_ShortPress;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Home_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_App_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Trigger_ShortPress;
		//LongPress
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_Home_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_App_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_Touchpad_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_Trigger_LongPress;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Home_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_App_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Touchpad_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Trigger_LongPress;
	}
	else
	{
		//Simple
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home] = FPicoNeoKeyNames::PicoNeoController_L_Home;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App] = FPicoNeoKeyNames::PicoNeoController_L_App;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad] = FPicoNeoKeyNames::PicoNeoController_L_RockerC;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger] = FPicoNeoKeyNames::PicoNeoController_L_Trigger;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home] = FPicoNeoKeyNames::PicoNeoController_R_Home;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App] = FPicoNeoKeyNames::PicoNeoController_R_App;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad] = FPicoNeoKeyNames::PicoNeoController_R_RockerC;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger] = FPicoNeoKeyNames::PicoNeoController_R_Trigger;

		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerUp] = FPicoNeoKeyNames::PicoNeoController_L_RockerUp;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerDown] = FPicoNeoKeyNames::PicoNeoController_L_RockerDown;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerLeft] = FPicoNeoKeyNames::PicoNeoController_L_RockerLeft;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerRight] = FPicoNeoKeyNames::PicoNeoController_L_RockerRight;

		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickUp] = FPicoNeoKeyNames::PicoNeoController_L_RockerClickUp;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickDown] = FPicoNeoKeyNames::PicoNeoController_L_RockerClickDown;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickLeft] = FPicoNeoKeyNames::PicoNeoController_L_RockerClickLeft;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickRight] = FPicoNeoKeyNames::PicoNeoController_L_RockerClickRight;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerUp] = FPicoNeoKeyNames::PicoNeoController_R_RockerUp;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerDown] = FPicoNeoKeyNames::PicoNeoController_R_RockerDown;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerLeft] = FPicoNeoKeyNames::PicoNeoController_R_RockerLeft;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerRight] = FPicoNeoKeyNames::PicoNeoController_R_RockerRight;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickUp] = FPicoNeoKeyNames::PicoNeoController_R_RockerClickUp;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickDown] = FPicoNeoKeyNames::PicoNeoController_R_RockerClickDown;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickLeft] = FPicoNeoKeyNames::PicoNeoController_R_RockerClickLeft;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickRight] = FPicoNeoKeyNames::PicoNeoController_R_RockerClickRight;

		//ShortPress
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_Home_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_App_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_RockerC_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_Trigger_ShortPress;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_Home_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_App_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_RockerC_ShortPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_Trigger_ShortPress;

		//LongPress
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_Home_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_App_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_RockerC_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_Trigger_LongPress;

		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_Home_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_App_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_RockerC_LongPress;
		Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_Trigger_LongPress;

	}
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX] = FPicoNeoKeyNames::PicoNeoController_L_X;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY] = FPicoNeoKeyNames::PicoNeoController_L_Y;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip] = FPicoNeoKeyNames::PicoNeoController_L_LGrip;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip] = FPicoNeoKeyNames::PicoNeoController_L_RGrip;

	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX] = FPicoNeoKeyNames::PicoNeoController_R_A;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY] = FPicoNeoKeyNames::PicoNeoController_R_B;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip] = FPicoNeoKeyNames::PicoNeoController_R_LGrip;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip] = FPicoNeoKeyNames::PicoNeoController_R_RGrip;

	//ShortPress
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_X_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_Y_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_LGrip_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = FPicoNeoKeyNames::PicoNeoController_L_RGrip_ShortPress;

	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_A_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_B_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_LGrip_ShortPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = FPicoNeoKeyNames::PicoNeoController_R_RGrip_ShortPress;

	//LongPress
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Up_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = FPicoNeoKeyNames::PicoNeoController_Main_Volume_Down_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_X_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_Y_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_LGrip_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_LongPress] = FPicoNeoKeyNames::PicoNeoController_L_RGrip_LongPress;

	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Up_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = FPicoNeoKeyNames::PicoNeoController_Sub_Volume_Down_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_A_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_B_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_LGrip_LongPress;
	Buttons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_LongPress] = FPicoNeoKeyNames::PicoNeoController_R_RGrip_LongPress;

#if ENGINE_MINOR_VERSION <= 23
	if (GetDefault <UPicoMobileSettings>()->bEnableVRStandardInput)
	{
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX] = FGamepadKeyNames::MotionController_Left_FaceButton1;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY] = FGamepadKeyNames::MotionController_Left_FaceButton2;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip] = FGamepadKeyNames::MotionController_Left_Grip1;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerUp] = FGamepadKeyNames::MotionController_Left_Thumbstick_Up;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerDown] = FGamepadKeyNames::MotionController_Left_Thumbstick_Down;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerLeft] = FGamepadKeyNames::MotionController_Left_Thumbstick_Left;
		VRStandardButtons[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerRight] = FGamepadKeyNames::MotionController_Left_Thumbstick_Right;

		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX] = FGamepadKeyNames::MotionController_Right_FaceButton1;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY] = FGamepadKeyNames::MotionController_Right_FaceButton2;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip] = FGamepadKeyNames::MotionController_Right_Grip1;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerUp] = FGamepadKeyNames::MotionController_Right_Thumbstick_Up;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerDown] = FGamepadKeyNames::MotionController_Right_Thumbstick_Down;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerLeft] = FGamepadKeyNames::MotionController_Right_Thumbstick_Left;
		VRStandardButtons[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerRight] = FGamepadKeyNames::MotionController_Right_Thumbstick_Right;
	}
#endif

	Buttons_Touch[0][0] = FPicoNeoKeyNames::PicoNeoController_L_X_CapTouch;
	Buttons_Touch[0][1] = FPicoNeoKeyNames::PicoNeoController_L_Y_CapTouch;
	Buttons_Touch[0][2] = FPicoNeoKeyNames::PicoNeoController_L_Rocker_CapTouch;
	Buttons_Touch[0][3] = FPicoNeoKeyNames::PicoNeoController_L_Trigger_CapTouch;
	Buttons_Touch[0][4] = FPicoNeoKeyNames::PicoNeoController_L_Thumbrest;

	Buttons_Touch[1][0] = FPicoNeoKeyNames::PicoNeoController_R_A_CapTouch;
	Buttons_Touch[1][1] = FPicoNeoKeyNames::PicoNeoController_R_B_CapTouch;
	Buttons_Touch[1][2] = FPicoNeoKeyNames::PicoNeoController_R_Rocker_CapTouch;
	Buttons_Touch[1][3] = FPicoNeoKeyNames::PicoNeoController_R_Trigger_CapTouch;
	Buttons_Touch[1][4] = FPicoNeoKeyNames::PicoNeoController_R_Thumbrest;

}


inline void FPicoNeoController::ProcessControllerButtons()
{
#if PLATFORM_ANDROID
	bool CurrentButtonDownStates[(int32)EPicoNeoControllerMark::TotalControllerCount][(int32)EPicoNeoControllerButton::TotalButtonCount];
	bool CurrentButtonUpStates[(int32)EPicoNeoControllerMark::TotalControllerCount][(int32)EPicoNeoControllerButton::TotalButtonCount];

	for (int32 controllerIndex = 0; controllerIndex < (int32)EPicoNeoControllerMark::TotalControllerCount; ++controllerIndex)
	{
		for (int32 buttonIndex = 0; buttonIndex < (int32)EPicoNeoControllerButton::TotalButtonCount; ++buttonIndex)
		{
			CurrentButtonDownStates[controllerIndex][buttonIndex] = false;
			CurrentButtonUpStates[controllerIndex][buttonIndex] = false;
		}
	}
	//CurrentButtonDownStates
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home] = NeoLeftHand.Home.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App] = NeoLeftHand.APP.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad] = NeoLeftHand.Rocker.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp] = NeoLeftHand.VolumeUp.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown] = NeoLeftHand.VolumeDown.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX] = NeoLeftHand.XorA.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY] = NeoLeftHand.YorB.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip] = NeoLeftHand.LeftGrip.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip] = NeoLeftHand.RightGrip.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger] = NeoLeftHand.Trigger.ButtonDown;

	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerUp] = NeoLeftHand.RockerUpEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerDown] = NeoLeftHand.RockerDownEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerLeft] = NeoLeftHand.RockerLeftEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerRight] = NeoLeftHand.RockerRightEvent;

	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickUp] = NeoLeftHand.RockerUpClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickDown] = NeoLeftHand.RockerDownClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickLeft] = NeoLeftHand.RockerLeftClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RockerClickRight] = NeoLeftHand.RockerRightClickEvent;


	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home] = NeoRightHand.Home.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App] = NeoRightHand.APP.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad] = NeoRightHand.Rocker.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp] = NeoRightHand.VolumeUp.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown] = NeoRightHand.VolumeDown.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX] = NeoRightHand.XorA.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY] = NeoRightHand.YorB.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip] = NeoRightHand.LeftGrip.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip] = NeoRightHand.RightGrip.ButtonDown;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger] = NeoRightHand.Trigger.ButtonDown;

	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerUp] = NeoRightHand.RockerUpEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerDown] = NeoRightHand.RockerDownEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerLeft] = NeoRightHand.RockerLeftEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerRight] = NeoRightHand.RockerRightEvent;

	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickUp] = NeoRightHand.RockerUpClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickDown] = NeoRightHand.RockerDownClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickLeft] = NeoRightHand.RockerLeftClickEvent;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RockerClickRight] = NeoRightHand.RockerRightClickEvent;

	//ShortPress
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_ShortPress] = NeoLeftHand.Home.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_ShortPress] = NeoLeftHand.APP.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = NeoLeftHand.Rocker.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = NeoLeftHand.VolumeUp.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = NeoLeftHand.VolumeDown.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_ShortPress] = NeoLeftHand.XorA.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_ShortPress] = NeoLeftHand.YorB.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = NeoLeftHand.LeftGrip.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = NeoLeftHand.RightGrip.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = NeoLeftHand.Trigger.ButtonShortPress;

	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_ShortPress] = NeoRightHand.Home.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_ShortPress] = NeoRightHand.APP.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = NeoRightHand.Rocker.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = NeoRightHand.VolumeUp.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = NeoRightHand.VolumeDown.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_ShortPress] = NeoRightHand.XorA.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_ShortPress] = NeoRightHand.YorB.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = NeoRightHand.LeftGrip.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = NeoRightHand.RightGrip.ButtonShortPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = NeoRightHand.Trigger.ButtonShortPress;

	//LongPress
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_LongPress] = NeoLeftHand.Home.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_LongPress] = NeoLeftHand.APP.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = NeoLeftHand.Rocker.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = NeoLeftHand.VolumeUp.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = NeoLeftHand.VolumeDown.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_LongPress] = NeoLeftHand.XorA.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_LongPress] = NeoLeftHand.YorB.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_LongPress] = NeoLeftHand.LeftGrip.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_LongPress] = NeoLeftHand.RightGrip.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_LongPress] = NeoLeftHand.Trigger.ButtonLongPress;


	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_LongPress] = NeoRightHand.Home.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_LongPress] = NeoRightHand.APP.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = NeoRightHand.Rocker.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = NeoRightHand.VolumeUp.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = NeoRightHand.VolumeDown.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_LongPress] = NeoRightHand.XorA.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_LongPress] = NeoRightHand.YorB.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_LongPress] = NeoRightHand.LeftGrip.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_LongPress] = NeoRightHand.RightGrip.ButtonLongPress;
	CurrentButtonDownStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_LongPress] = NeoRightHand.Trigger.ButtonLongPress;

	//CurrentButtonUpStates
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home] = NeoLeftHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App] = NeoLeftHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad] = NeoLeftHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp] = NeoLeftHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown] = NeoLeftHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX] = NeoLeftHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY] = NeoLeftHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip] = NeoLeftHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip] = NeoLeftHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger] = NeoLeftHand.Trigger.ButtonUp;


	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home] = NeoRightHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App] = NeoRightHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad] = NeoRightHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp] = NeoRightHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown] = NeoRightHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX] = NeoRightHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY] = NeoRightHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip] = NeoRightHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip] = NeoRightHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger] = NeoRightHand.Trigger.ButtonUp;

	//ShortPress
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_ShortPress] = NeoLeftHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_ShortPress] = NeoLeftHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = NeoLeftHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = NeoLeftHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = NeoLeftHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_ShortPress] = NeoLeftHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_ShortPress] = NeoLeftHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = NeoLeftHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = NeoLeftHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = NeoLeftHand.Trigger.ButtonUp;


	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_ShortPress] = NeoRightHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_ShortPress] = NeoRightHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_ShortPress] = NeoRightHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_ShortPress] = NeoRightHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_ShortPress] = NeoRightHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_ShortPress] = NeoRightHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_ShortPress] = NeoRightHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_ShortPress] = NeoRightHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_ShortPress] = NeoRightHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_ShortPress] = NeoRightHand.Trigger.ButtonUp;

	//LongPress
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Home_LongPress] = NeoLeftHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::App_LongPress] = NeoLeftHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = NeoLeftHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = NeoLeftHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = NeoLeftHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::AorX_LongPress] = NeoLeftHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::BorY_LongPress] = NeoLeftHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::LGrip_LongPress] = NeoLeftHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::RGrip_LongPress] = NeoLeftHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::MainOrLeft][(int32)EPicoNeoControllerButton::Trigger_LongPress] = NeoLeftHand.Trigger.ButtonUp;


	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Home_LongPress] = NeoRightHand.Home.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::App_LongPress] = NeoRightHand.APP.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Touchpad_LongPress] = NeoRightHand.Rocker.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeUp_LongPress] = NeoRightHand.VolumeUp.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::VolumeDown_LongPress] = NeoRightHand.VolumeDown.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::AorX_LongPress] = NeoRightHand.XorA.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::BorY_LongPress] = NeoRightHand.YorB.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::LGrip_LongPress] = NeoRightHand.LeftGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::RGrip_LongPress] = NeoRightHand.RightGrip.ButtonUp;
	CurrentButtonUpStates[(int32)EPicoNeoControllerMark::SubOrRight][(int32)EPicoNeoControllerButton::Trigger_LongPress] = NeoRightHand.Trigger.ButtonUp;

	for (int32 controllerIndex = 0; controllerIndex < (int32)EPicoNeoControllerMark::TotalControllerCount; controllerIndex++)
	{
		if (controllerIndex == 0 && !pJni->GetMainControllerConnectState())
		{
		  continue;
		}
		if (controllerIndex == 1 && !pJni->GetSubControllerConnectState())
		{
			continue;
		}
		for (int32 buttonIndex = 0; buttonIndex < (int32)EPicoNeoControllerButton::TotalButtonCount; buttonIndex++)
		{
			if (CurrentButtonDownStates[controllerIndex][buttonIndex])
			{
				MessageHandler->OnControllerButtonPressed(Buttons[controllerIndex][buttonIndex], 0, false);

				if (VRStandardButtons[controllerIndex][buttonIndex] != "")
				{
					MessageHandler->OnControllerButtonPressed(VRStandardButtons[controllerIndex][buttonIndex], 0, false);
				}
			}
			if (CurrentButtonUpStates[controllerIndex][buttonIndex])
			{
				MessageHandler->OnControllerButtonReleased(Buttons[controllerIndex][buttonIndex], 0, false);
				if (VRStandardButtons[controllerIndex][buttonIndex] != "")
				{
					MessageHandler->OnControllerButtonReleased(VRStandardButtons[controllerIndex][buttonIndex], 0, false);
				}
			}
		}
	}

	bool ButtonTouchPressedStates[2][5] = {{false},{false}};
	bool ButtonTouchReleasedStates[2][5] = {{false},{false}};

	ButtonTouchPressedStates[0][0] = LeftTouch.AorX.TouchPressed;
	ButtonTouchPressedStates[0][1] = LeftTouch.BorY.TouchPressed;
	ButtonTouchPressedStates[0][2] = LeftTouch.Rocker.TouchPressed;
	ButtonTouchPressedStates[0][3] = LeftTouch.Trigger.TouchPressed;
	ButtonTouchPressedStates[0][4] = LeftTouch.Thumbrest.TouchPressed;

	ButtonTouchPressedStates[1][0] = RightTouch.AorX.TouchPressed;
	ButtonTouchPressedStates[1][1] = RightTouch.BorY.TouchPressed;
	ButtonTouchPressedStates[1][2] = RightTouch.Rocker.TouchPressed;
	ButtonTouchPressedStates[1][3] = RightTouch.Trigger.TouchPressed;
	ButtonTouchPressedStates[1][4] = RightTouch.Thumbrest.TouchPressed;

	ButtonTouchReleasedStates[0][0] = LeftTouch.AorX.TouchReleased;
	ButtonTouchReleasedStates[0][1] = LeftTouch.BorY.TouchReleased;
	ButtonTouchReleasedStates[0][2] = LeftTouch.Rocker.TouchReleased;
	ButtonTouchReleasedStates[0][3] = LeftTouch.Trigger.TouchReleased;
	ButtonTouchReleasedStates[0][4] = LeftTouch.Thumbrest.TouchReleased;

	ButtonTouchReleasedStates[1][0] = RightTouch.AorX.TouchReleased;
	ButtonTouchReleasedStates[1][1] = RightTouch.BorY.TouchReleased;
	ButtonTouchReleasedStates[1][2] = RightTouch.Rocker.TouchReleased;
	ButtonTouchReleasedStates[1][3] = RightTouch.Trigger.TouchReleased;
	ButtonTouchReleasedStates[1][4] = RightTouch.Thumbrest.TouchReleased;
	for (int32 i = 0;i<2;i++)
	{
		for (int32 j = 0;j<5;j++)
		{
			if (ButtonTouchPressedStates[i][j])
			{
				MessageHandler->OnControllerButtonPressed(Buttons_Touch[i][j], 0, false);
			}
			if (ButtonTouchReleasedStates[i][j])
			{
				MessageHandler->OnControllerButtonReleased(Buttons_Touch[i][j], 0, false);
			}
		}
	}	
#endif
}

inline void FPicoNeoController::ProcessControllerAxis()
{
#if PLATFORM_ANDROID
	// TouchPad
	FVector2D touchXY = FVector2D::ZeroVector;

	touchXY = NeoLeftHand.RockerValue;
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Main_TouchX, 0, touchXY.X);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Main_TouchY, 0, touchXY.Y);

	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_L_RockerX, 0, touchXY.X);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_L_RockerY, 0, touchXY.Y);

#if ENGINE_MINOR_VERSION <= 23
	if (GetDefault <UPicoMobileSettings>()->bEnableVRStandardInput)
	{
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Left_Thumbstick_X, 0, touchXY.X);
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Left_Thumbstick_Y, 0, touchXY.Y);
	}
#endif

	touchXY = NeoRightHand.RockerValue;
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Sub_TouchX, 0, touchXY.X);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Sub_TouchY, 0, touchXY.Y);

	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_R_RockerX, 0, touchXY.X);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_R_RockerY, 0, touchXY.Y);

#if ENGINE_MINOR_VERSION <= 23
	if (GetDefault <UPicoMobileSettings>()->bEnableVRStandardInput)
	{
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Right_Thumbstick_X, 0, touchXY.X);
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Right_Thumbstick_Y, 0, touchXY.Y);
	}
#endif

	// Trigger
	float AnalogValue = 0;

	AnalogValue = pJni->GetMainControllerTriggerNum();
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Main_TriggerAxis, 0, AnalogValue);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_L_TriggerAxis, 0, AnalogValue);

#if ENGINE_MINOR_VERSION <= 23
	if (GetDefault <UPicoMobileSettings>()->bEnableVRStandardInput)
	{
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Left_TriggerAxis, 0, AnalogValue);
	}
#endif

	AnalogValue = pJni->GetSubControllerTriggerNum();
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_Sub_TriggerAxis, 0, AnalogValue);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_R_TriggerAxis, 0, AnalogValue);

#if ENGINE_MINOR_VERSION <= 23
	if (GetDefault <UPicoMobileSettings>()->bEnableVRStandardInput)
	{
		MessageHandler->OnControllerAnalog(FGamepadKeyNames::MotionController_Right_TriggerAxis, 0, AnalogValue);
	}
#endif

	// Grip
	float GripValue = 0;
	GripValue = pJni->GetControllerGripValue(0);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_L_Grip_Axis, 0, GripValue);
	GripValue = pJni->GetControllerGripValue(1);
	MessageHandler->OnControllerAnalog(FPicoNeoKeyNames::PicoNeoController_R_Grip_Axis, 0, GripValue);
#endif	
}

float FPicoNeoController::GetWorldToMetersScale() const
{
	if (IsInGameThread() && GWorld != nullptr)
	{
		return GWorld->GetWorldSettings()->WorldToMeters;
	}
	return 100.0f;
}

void FPicoNeoController::ConvertVector(FVector & vector, float WorldToMetersScale) const
{
	FVector tempVector = vector;
	// Positon：OpenGL to Unreal
	vector.X = -tempVector.Z*WorldToMetersScale;
	vector.Y = tempVector.X*WorldToMetersScale;
	vector.Z = tempVector.Y*WorldToMetersScale;
}

bool FPicoNeoController::IsAvailable() const
{
#if PLATFORM_ANDROID
	if (pJni->GetLifeResumed())
	{
		if (pJni->GetMainControllerConnectState() || pJni->GetSubControllerConnectState())
		{
			return true;
		}
	}	
#endif
	return false;
}
