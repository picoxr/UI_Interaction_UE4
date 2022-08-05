//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "GenericPlatform/IInputInterface.h"
#include "XRMotionControllerBase.h"
#include "InputDevice.h"
#include "IHapticDevice.h"
#include "PicoXRDPHMD/Private/PXR_DPHMD.h"

#define ButtonEventNum 12

struct EPicoButton
{
	enum Type
	{
		RockerX,
		RockerY,
		Home,
		App,
		Rocker,
		VolumeUp,
		VolumeDown,
		Trigger,
		Power,
		AorX,
		BorY,
		Grip,
		RockerUp,
		RockerDown,
		RockerLeft,
		RockerRight,
		ButtonCount
	};
};

struct EPicoTouchButton
{
	enum Type
	{
		AorX,
		BorY,
		Rocker,
		Trigger,
		Thumbrest,
        ButtonCount
    };
};

struct EPicoXRControllerHandness
{
	enum Type
	{
		LeftController,
		RightController,
		ControllerCount
	};
};

enum  EPicoInputType:uint8
{
	Unknown = 0,
	G2      = 3,
	Neo2    = 4,
	Neo3    = 5,
};

enum  ETouchButtonStatus:uint16
{
	None = 0,
	XATouch = 2,
	YBTouch = 8,
	JoystickTouch = 32,
	TriggerTouch = 128,
	GripTouch = 512,
	KBlankTouch = 4096
};

//class FPicoXRHMD;
class FPicoXRDPInput :public IInputDevice,public FXRMotionControllerBase,public IHapticDevice,public TSharedFromThis<FPicoXRDPInput>
{
public:
	FPicoXRDPInput();
	virtual ~FPicoXRDPInput();
public: 
	// IInputDevice overrides
	virtual void Tick(float DeltaTime) override;
	virtual void SendControllerEvents() override;
	virtual void SetMessageHandler(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values) override;

	// IMotionController overrides
	virtual FName GetMotionControllerDeviceTypeName() const override;
	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const override;
	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const override;

	// IHapticDevice overrides
	IHapticDevice* GetHapticDevice() override { return (IHapticDevice*)this; }
	virtual void SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values) override;
	virtual void GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const override;
	virtual float GetHapticAmplitudeScale() const override;

	/*FPicoXRHMD* GetPicoXRHMD();*/
	int32 UPxr_GetControllerPower(int32 Handness);
	bool UPxr_GetControllerConnectState(int32 Handness);
	bool UPxr_GetControllerMainInputHandle(int32& Handness);
	bool UPxr_SetControllerMainInputHandle(int32 inHandness);

	UFUNCTION()
    void OnControllerMainChangedDelegate(int32 Handness);
	UFUNCTION()
    void OnControllerConnectChangedDelegate(int32 Handness,int32 State);

	void SetHeadPosition(FVector Position);
	void SetHeadOrientation(FQuat Orientation);
	bool UPxr_GetControllerEnableHomeKey();
	void GetPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const;
	
	static FVector OriginOffsetL;
	static FVector OriginOffsetR;

	static void RegisterKeys();
private:
	
	void SetKeyMapping();
	void ProcessButtonEvent();
	void ProcessButtonAxis();
	void UpdateConnectState();
	void GetControllerSensorData(EControllerHand DeviceHand,  float WorldToMetersScale, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const;

	FPicoDirectPreviewHMD* PicoXRHMD=nullptr;
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
	bool LeftConnectState;
	bool RightConnectState;
	FName Buttons[(int32)EPicoXRControllerHandness::ControllerCount][(int32)EPicoButton::ButtonCount];
	FName TouchButtons[(int32)EPicoXRControllerHandness::ControllerCount][(int32)EPicoTouchButton::ButtonCount];
	int32 LastLeftControllerButtonState[EPicoButton::ButtonCount] = { 0 };
	int32 LastRightControllerButtonState[EPicoButton::ButtonCount] = { 0 };
	int32 LastLeftTouchButtonState[EPicoTouchButton::ButtonCount] = { 0 };
	int32 LastRightTouchButtonState[EPicoTouchButton::ButtonCount] = { 0 };
	int32 LeftControllerPower;
	int32 RightControllerPower;
	bool bLeftButtonPressed = false;
	bool bRightButtonPressed = false;
	FVector2D LeftControllerTouchPoint;
	FVector2D RightControllerTouchPoint;
	float LeftControllerTriggerValue;
	float RightControllerTriggerValue;
	float LeftControllerGripValue;
	float RightControllerGripValue;
	uint32_t MainControllerHandle;
	FVector SourcePosition;
	FQuat SourceOrientation;
	EPicoInputType ControllerType;
};


