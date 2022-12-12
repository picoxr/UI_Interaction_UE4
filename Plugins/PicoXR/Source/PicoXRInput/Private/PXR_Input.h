//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "GenericPlatform/IInputInterface.h"
#include "XRMotionControllerBase.h"
#include "IInputDevice.h"
#include "IHapticDevice.h"
#include "IPXR_HandTracker.h"
#include "PXR_Settings.h"
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
		Index,
		Middle,
		Ring,
	    Pinky,
		ThumbClick,
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

enum EPICOInputType:uint8
{
	Unknown = 0,
	G2 = 3,
	Neo2 = 4,
	Neo3 = 5,
};

static const FQuat LeftRootFixupOrientation = FQuat(0.0f, FMath::Sin(-PI / 4), 0.0f, FMath::Cos(PI / 4));
static const FQuat LeftRootFixupOrientation2 = FQuat(FMath::Sin(-PI / 4),0.0f , 0.0f, FMath::Cos(PI / 4));
static const FQuat LeftRootFixupOrientation3 = FQuat(0.0f,0.0f,FMath::Sin(-PI / 4), FMath::Cos(PI / 4));

static const FQuat RightRootFixupOrientation = FQuat(0.0f, FMath::Sin(PI / 4), 0.0f, FMath::Cos(PI / 4));
static const FQuat RightRootFixupOrientation2 = FQuat(FMath::Sin(-PI / 4),0.0f , 0.0f, FMath::Cos(PI / 4));
static const FQuat RightRootFixupOrientation3 = FQuat(0.0f,0.0f,FMath::Sin(-PI / 4), FMath::Cos(PI / 4));


class FPICOXRHMD;
class UPICOXRHandComponent;

class FPICOXRInput : public IInputDevice, public IPXR_HandTracker, public FXRMotionControllerBase, public IHapticDevice, public TSharedFromThis<FPICOXRInput>
{
public:
	FPICOXRInput();
	virtual ~FPICOXRInput();

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
	virtual FTransform GetPointerPose(const EPICOXRHandType DeviceHand) override;
	virtual bool IsHandTracked(const EPICOXRHandType DeviceHand) override;
	virtual bool IsAimValid(const EPICOXRHandType DeviceHand) override;
	virtual bool IsAimRayTouchedValid(const EPICOXRHandType DeviceHand) override;
	virtual bool IsSystemGestureInProgress(const EPICOXRHandType DeviceHand) override;
	virtual bool IsDominantHand(const EPICOXRHandType DeviceHand) override;
	virtual bool IsMenuPressed(const EPICOXRHandType DeviceHand) override;
	virtual float GetClickStrength(const EPICOXRHandType DeviceHand) override;
	virtual bool GetFingerIsPinching(const EPICOXRHandType DeviceHand,const EPICOXRHandFinger Finger) override;
	virtual float GetFingerPinchStrength(const EPICOXRHandType DeviceHand, const EPICOXRHandFinger Finger) override;
	virtual EPICOXRActiveInputDevice GetActiveInputDevice() override;
	
	virtual bool IsHandTrackingStateValid() const override;
	virtual bool GetKeypointState(EPICOXRHandType Hand, EPICOXRHandJoint Keypoint, FTransform& OutTransform, float& OutRadius) const override;
	virtual FName GetHandTrackerDeviceTypeName() const override;
	virtual void UpdateHandState() override;

	// IMotionController overrides
	virtual FName GetMotionControllerDeviceTypeName() const override;
	virtual bool GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const override;
	virtual ETrackingStatus GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const override;

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
	
	FPICOXRHandState HandStates[2];
	EPICOXRHandType SkeletonType;
	bool bHandTrackingAvailable;
	
	void RegisterKeys();
	void SetKeyMapping();
	void ProcessButtonEvent();
	void ProcessButtonAxis();
	void UpdateConnectState();
	void GetControllerSensorData(EControllerHand DeviceHand, float WorldToMetersScale, double inPredictedTime, FVector SourcePosition, FQuat SourceOrientation, FRotator& OutOrientation, FVector& OutPosition) const;

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
	EPICOInputType ControllerType;
	UPICOXRSettings* Settings;
	int CurrentVersion;
};
