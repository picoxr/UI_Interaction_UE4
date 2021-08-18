// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "InputDevice.h"
#include "../Launch/Resources/Version.h"
#include "XRMotionControllerBase.h"
#include "PicoMobileControllerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogPicoMobileController, Log, All);

/** Total number of controllers in a set */
#define CONTROLLERS_PER_PLAYER	2

struct FPicoMobileControllerButtonEvent
{
	bool ButtonState;
	bool ButtonDown;
	bool ButtonUp;
	bool ButtonLongPress;
	bool ButtonShortPress;
};

struct FPicoMobileControllerButtonState
{
	FVector2D TouchValue;
	FPicoMobileControllerButtonEvent Home;
	FPicoMobileControllerButtonEvent APP;
	FPicoMobileControllerButtonEvent TouchPad;
	FPicoMobileControllerButtonEvent VolumeUp;
	FPicoMobileControllerButtonEvent VolumeDown;
	FPicoMobileControllerButtonEvent Trigger;
	int32 Battery;

	bool TouchPadUpEvent;
	bool TouchPadDownEvent;
	bool TouchPadLeftEvent;
	bool TouchPadRightEvent;

	bool TouchPadUpClickEvent;
	bool TouchPadDownClickEvent;
	bool TouchPadLeftClickEvent;
	bool TouchPadRightClickEvent;
};


class FPicoMobileController : public IInputDevice, public FXRMotionControllerBase
{
public:

	FPicoMobileController(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);
	virtual ~FPicoMobileController();

public:

	struct EPicoMobileControllerButton
	{
		enum Type
		{
			Home,
			Back,
			Touchpad,
			VolumeUp,
			VolumeDown,
			Trigger,

			TouchUp,
			TouchDown,
			TouchLeft,
			TouchRight,
			TouchClickUp,
			TouchClickDown,
			TouchClickLeft,
			TouchClickRight,
			//ShortPress
			Home_ShortPress,
			Back_ShortPress,
			Touchpad_ShortPress,
			VolumeUp_ShortPress,
			VolumeDown_ShortPress,
			Trigger_ShortPress,

			//LongPress
			Home_LongPress,
			Back_LongPress,
			Touchpad_LongPress,
			VolumeUp_LongPress,
			VolumeDown_LongPress,
			Trigger_LongPress,
			/** Max number of controller buttons.  Must be < 256 */
			TotalButtonCount
		};
	};

public: // Helper Functions
	void AddKeysToEngine();
	void SetKeyMapping();
	inline void ProcessControllerButtons();
	inline void	ProcessControllerAxis();
	bool IsAvailable() const;

public: // arm model 
	void SetUseController();
	void SetUseWrist();
	void SetUseElbow();
	void SetUseShoulder();
	void SwitchArmJoint();
	int32 GetArmJointIndex();

public:	// IInputDevice
	virtual void Tick(float DeltaTime);
	virtual void SendControllerEvents();
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar);
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value);
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values);

public: // IMotionController
	static FName DeviceTypeName;
	virtual FName GetMotionControllerDeviceTypeName() const override
	{
		return DeviceTypeName;
	}

	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const;
	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const;

	float GetWorldToMetersScale() const;
	void ConvertVector(FVector& vector, float WorldToMetersScale) const;
	void UpdateButtonEvent();
private:
#if PLATFORM_ANDROID
	PicoMobileControllerState* pvrControllerState;
#endif
	FGamepadKeyNames::Type Buttons[EPicoMobileControllerButton::TotalButtonCount];
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
	FPicoMobileControllerButtonState Hand;
	int32 ControllerRotationMode;
};