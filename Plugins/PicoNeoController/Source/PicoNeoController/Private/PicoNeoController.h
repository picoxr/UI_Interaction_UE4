// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "InputDevice.h"
#include "../Launch/Resources/Version.h"
#include "XRMotionControllerBase.h"
#include "PicoNeoControllerJni.h"


struct FPicoNeoControllerButtonEvent
{
	bool ButtonState;
	bool ButtonDown;
	bool ButtonUp;
	bool ButtonLongPress;
	bool ButtonShortPress;
};

struct FPicoNeoControllerButtonState
{
	FVector2D RockerValue;
	FPicoNeoControllerButtonEvent Home;
	FPicoNeoControllerButtonEvent APP;
	FPicoNeoControllerButtonEvent Rocker;
	FPicoNeoControllerButtonEvent VolumeUp;
	FPicoNeoControllerButtonEvent VolumeDown;
	FPicoNeoControllerButtonEvent Trigger;
	int32 Battery;
	FPicoNeoControllerButtonEvent XorA;
	FPicoNeoControllerButtonEvent YorB;
	FPicoNeoControllerButtonEvent LeftGrip;
	FPicoNeoControllerButtonEvent RightGrip;
	
	bool RockerUpEvent;
	bool RockerDownEvent;
	bool RockerLeftEvent;
	bool RockerRightEvent;

	bool RockerUpClickEvent;
	bool RockerDownClickEvent;
	bool RockerLeftClickEvent;
	bool RockerRightClickEvent;
};

struct FPicoNeoControllerTouchType
{
	bool TouchState;
	bool TouchPressed;
	bool TouchReleased;
};

struct FPicoNeoControllerTouchEvent
{
	FPicoNeoControllerTouchType AorX;
	FPicoNeoControllerTouchType BorY;
	FPicoNeoControllerTouchType Rocker;
	FPicoNeoControllerTouchType Trigger;
	FPicoNeoControllerTouchType Thumbrest;
};
class FPicoNeoController : public IInputDevice, public FXRMotionControllerBase
{
public:
	FPicoNeoController(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);
	virtual ~FPicoNeoController();

	struct EPicoNeoControllerButton
	{
		enum Type
		{
			//Simple
			Home,
			App,
			Touchpad,
			VolumeUp,
			VolumeDown,
			AorX,
			BorY,
			LGrip,
			RGrip,
			Trigger,
			
			RockerUp,
			RockerDown,
			RockerLeft,
			RockerRight,
			RockerClickUp,
			RockerClickDown,
			RockerClickLeft,
			RockerClickRight,

			//ShortPressed
			Home_ShortPress,
			App_ShortPress,
			Touchpad_ShortPress,
			VolumeUp_ShortPress,
			VolumeDown_ShortPress,
			AorX_ShortPress,
			BorY_ShortPress,
			LGrip_ShortPress,
			RGrip_ShortPress,
			Trigger_ShortPress,

			//LongPressed
			Home_LongPress,
			App_LongPress,
			Touchpad_LongPress,
			VolumeUp_LongPress,
			VolumeDown_LongPress,
			AorX_LongPress,
			BorY_LongPress,
			LGrip_LongPress,
			RGrip_LongPress,
			Trigger_LongPress,

			/** Max number of controller buttons.  Must be < 256 */
			TotalButtonCount
		};
	};

	struct EPicoNeoControllerMark
	{
		enum Type
		{
			MainOrLeft,
			SubOrRight,

			TotalControllerCount
		};
	};

	// IInputDevice
	virtual void Tick(float DeltaTime)override;
	virtual void SendControllerEvents()override;
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)override;
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)override;
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values)override;

	// IMotionController
	static FName DeviceTypeName;
	virtual FName GetMotionControllerDeviceTypeName() const override;

	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const override;

	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const override;

	// Helper Functions
	void AddKeysToEngine();
	void SetKeyMapping();

	inline void ProcessControllerButtons();
	inline void	ProcessControllerAxis();

	float GetWorldToMetersScale() const;
	void ConvertVector(FVector& vector, float WorldToMetersScale) const;
	FRotator ConvertUnityQuaternionToUnrealRotator(FQuat quat) const;
	bool IsAvailable() const;
	void UpdateButtonEvent(FPicoNeoControllerButtonState& LeftHand, FPicoNeoControllerButtonState& RightHand);
	void DispatchButtonEvent(int* TempButton, FPicoNeoControllerButtonState &Hand);
	void DispatchTouchEvent(int32 Hand);

private:
#if PLATFORM_ANDROID
	FPicoNeoControllerJni* pJni;
#endif
	int32 deviceType;

	FVector2D RockerXYLeftValue;
	FVector2D RockerXYRightValue;

	FName Buttons[(int32)EPicoNeoControllerMark::TotalControllerCount][(int32)EPicoNeoControllerButton::TotalButtonCount];
	FName VRStandardButtons[(int32)EPicoNeoControllerMark::TotalControllerCount][(int32)EPicoNeoControllerButton::TotalButtonCount];
	FName Buttons_Touch[2][5];
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
	FPicoNeoControllerButtonState NeoLeftHand;
	FPicoNeoControllerButtonState NeoRightHand;
	FPicoNeoControllerTouchEvent LeftTouch;
	FPicoNeoControllerTouchEvent RightTouch;
	int32 ControllerRotationMode;
};