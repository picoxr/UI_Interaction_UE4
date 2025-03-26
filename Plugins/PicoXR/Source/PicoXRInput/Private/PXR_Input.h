// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "GenericPlatform/IInputInterface.h"
#include "XRMotionControllerBase.h"
#include "IInputDevice.h"
#include "IHapticDevice.h"
#include "IPXR_HandTracker.h"
#include "PXR_HMDRuntimeSettings.h"
#include "PXR_HMD.h"

#define ButtonEventNum 12

enum class EPICOXRHandJoint : uint8;

struct EPICOButton
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

struct EPICOHandButton
{
	enum Type
	{
		Pinch,
		ButtonCount
	};
};

struct EPICOTouchButton
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

struct EPICOXRControllerHandness
{
	enum Type
	{
		LeftController,
		RightController,
		ControllerCount
	};
};

class FPICOXRHMD;
class UPICOXRHandComponent;

class FPICOXRInput : public IInputDevice, public IPXR_HandTracker, public FXRMotionControllerBase, public IHapticDevice, public TSharedFromThis<FPICOXRInput>
{
public:
	FPICOXRInput();
	virtual ~FPICOXRInput();

	static void PreInit();

	// IInputDevice overrides
	virtual void Tick(float DeltaTime) override;
	virtual void SendControllerEvents() override;
	virtual void SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override;
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values) override;

	// IPXR_HandTracker overrides
	virtual FQuat GetBoneRotation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual FVector GetBoneLocation(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual float GetBoneRadii(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual bool IsBoneOrientationValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual bool IsBonePositionValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual bool IsBoneOrientationTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual bool IsBonePositionTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint BoneId) override;
	virtual FTransform GetHandRootPose(const EPICOXRHandType DeviceHand) override;
	virtual float GetHandScale(const EPICOXRHandType DeviceHand) override;
	virtual EPICOXRHandTrackingConfidence GetTrackingConfidence(const EPICOXRHandType DeviceHand) override;
	virtual FTransform GetRayPose(const EPICOXRHandType DeviceHand) override;
	virtual bool IsComputed(const EPICOXRHandType DeviceHand) override;
	virtual bool IsRayValid(const EPICOXRHandType DeviceHand) override;
	virtual bool IsPinchValid(const EPICOXRHandType DeviceHand) override;
	virtual float GetPinchStrength(const EPICOXRHandType DeviceHand) override;
	virtual bool GetFingerIsPinching(const EPICOXRHandType DeviceHand,const EPICOXRHandFinger Finger) override;
	virtual float GetFingerPinchStrength(const EPICOXRHandType DeviceHand, const EPICOXRHandFinger Finger) override;
	virtual EPICOXRActiveInputDevice GetActiveInputDevice() override;
	
	virtual bool IsHandTrackingStateValid() const override;
	virtual bool GetKeypointState(EPICOXRHandType Hand, EPICOXRHandJoint Keypoint, FTransform& OutTransform, float& OutRadius) const override;
	virtual FName GetHandTrackerDeviceTypeName() const override;
	virtual void UpdateHandState() override;

	// IMotionController overrides
	virtual FName GetMotionControllerDeviceTypeName() const override;
	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const FName MotionSource, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const override;
	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const FName MotionSource) const override;

	// IHapticDevice overrides
	IHapticDevice* GetHapticDevice() override { return (IHapticDevice*)this; }
	virtual void SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values) override;
	virtual void GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const override;
	virtual float GetHapticAmplitudeScale() const override;

	FPICOXRHMD* GetPICOXRHMD();
	int32 UPxr_GetControllerPower(int32 Handness);
	bool UPxr_GetControllerConnectState(int32 Handness);
	bool UPxr_GetControllerMainInputHandle(int32& Handness);
	bool UPxr_SetControllerMainInputHandle(int32 inHandness);
	
	void OnControllerMainChangedDelegate(int32 Handness);
	
	void OnControllerConnectChangedDelegate(int32 Handness, int32 State);

	bool UPxr_GetControllerEnableHomeKey();
	bool GetPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FRotator& OutOrientation, FVector& OutPosition) const;

	static FVector OriginOffsetL;
	static FVector OriginOffsetR;
	const FPICOXRHandState& GetLeftHandState() const;
	const FPICOXRHandState& GetRightHandState() const;
private:
	//HandTracking
	void SetAppHandTrackingEnabled(bool Enabled);

	static void AddNonExistingKey(const TArray<FKey> &ExistAllKeys,const FKeyDetails& KeyDetails);
	
	FPICOXRHandState HandStates[2];
	EPICOXRHandType SkeletonType;
	bool bHandTrackingAvailable;
	
	static void RegisterKeys();
	void SetKeyMapping();
	void ProcessButtonEvent();
	void ProcessButtonAxis();
	void UpdateConnectState();
	void GetControllerSensorData(const FGameSettings* InSettings, EControllerHand DeviceHand, float WorldToMetersScale, double inPredictedTime, FVector SourcePosition, FQuat SourceOrientation, FRotator& OutOrientation, FVector& OutPosition) const;

	FPICOXRHMD* PICOXRHMD;
	TSharedRef<FGenericApplicationMessageHandler> MessageHandler;
	bool LeftConnectState;
	bool RightConnectState;
	FName Buttons[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOButton::ButtonCount];
	FName TouchButtons[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOTouchButton::ButtonCount];
	FName HandButtons[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOHandButton::ButtonCount];
	int32 LastHandButtonState[(int32)EPICOXRControllerHandness::ControllerCount][(int32)EPICOHandButton::ButtonCount];
	int32 LastLeftControllerButtonState[EPICOButton::ButtonCount] = {0};
	int32 LastRightControllerButtonState[EPICOButton::ButtonCount] = {0};
	int32 LastLeftTouchButtonState[EPICOTouchButton::ButtonCount] = {0};
	int32 LastRightTouchButtonState[EPICOTouchButton::ButtonCount] = {0};
	int32 LeftControllerPower;
	int32 RightControllerPower;
	FVector2D LeftControllerTouchPoint;
	FVector2D RightControllerTouchPoint;
	float LeftControllerTriggerValue;
	float RightControllerTriggerValue;
	float LeftControllerGripValue;
	float RightControllerGripValue;
	uint32_t MainControllerHandle;
	PxrControllerType ControllerType;
	UPICOXRSettings* Settings;
	int CurrentVersion;
	float CurrentFramePredictedTime;
};
