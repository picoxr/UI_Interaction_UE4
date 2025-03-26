// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "PXR_Plugin_Types.h"
#include "PXR_InputFunctionLibrary.h"
#include "PXR_MotionTrackingTypes.generated.h"

UENUM(BlueprintType)
enum class EPXRTrackingStateCode : uint8
{
	PXR_MT_SUCCESS				 = 0,
	PXR_MT_FAILURE				 = (uint8)-1,
	PXR_MT_MODE_NONE			 = (uint8)-2,
	PXR_MT_DEVICE_NOT_SUPPORT	 = (uint8)-3,
	PXR_MT_SERVICE_NEED_START	 = (uint8)-4,
	PXR_MT_ET_PERMISSION_DENIED  = (uint8)-5,
	PXR_MT_FT_PERMISSION_DENIED  = (uint8)-6,
	PXR_MT_MIC_PERMISSION_DENIED = (uint8)-7,
	PXR_MT_SYSTEM_DENIED		 = (uint8)-8,
	PXR_MT_UNKNOW_ERROR			 = (uint8)-9
};

UENUM(BlueprintType)
enum class EPXRBodyTrackingStatusCode : uint8
{
	PXR_BODYTRACKING_INVALID = 0,
	PXR_BODYTRACKING_VALID = 1,
	PXR_BODYTRACKING_LIMITED = 2
};

UENUM(BlueprintType)
enum class EPXRBodyTrackingErrorCode : uint8
{
	PXR_BT_ERROR_INNER_EXCEPTION = 0,
	PXR_BT_ERROR_TRACKER_NOT_CALIBRATED = 1,
	PXR_BT_ERROR_TRACKER_NUM_NOT_ENOUGH = 2,
	PXR_BT_ERROR_TRACKER_STATE_NOT_SATISFIED = 3,
	PXR_BT_ERROR_TRACKER_PERSISTENT_INVISIBILITY = 4,
	PXR_BT_ERROR_TRACKER_DATA_ERROR = 5,
	PXR_BT_ERROR_USER_CHANGE = 6,
	PXR_BT_ERROR_TRACKING_POSE_ERROR = 7,
};


UENUM(BlueprintType)
enum class EPXRFaceBlendShape : uint8
{
	BrowInnerUp = 3,
	BrowDown_R = 4,
	BrowDown_L = 16,
	BrowOuterUp_L = 30,
	BrowOuterUp_R = 36,
	CheekSquint_L = 29,
	CheekSquint_R = 37,
	CheekPuff = 43,
	EyeLookDown_L = 0,
	EyeLookIn_L = 2,
	EyeLookIn_R = 11,
	EyeLookDown_R = 12,
	EyeSquint_L = 26,
	EyeBlink_L = 28,
	EyeLookUp_L = 31,
	EyeLookUp_R = 35,
	EyeBlink_R = 38,
	EyeSquint_R = 41,
	EyeLookOut_L = 44,
	EyeLookOut_R = 45,
	EyeWide_R = 46,
	EyeWide_L = 47,
	JawOpen = 7,
	JawRight = 15,
	JawForward = 25,
	JawLeft = 32,
	MouthClose = 5,
	MouthLowerDown_R = 6,
	MouthUpperUp_R = 8,
	MouthShrugUpper = 9,
	MouthFunnel = 10,
	MouthRollUpper = 14,
	MouthShrugLower = 17,
	MouthRollLower = 18,
	MouthSmile_L = 19,
	MouthPress_L = 20,
	MouthSmile_R = 21,
	MouthPress_R = 22,
	MouthDimple_R = 23,
	MouthLeft = 24,
	MouthFrown_L = 27,
	MouthStretch_L = 33,
	MouthPucker = 34,
	MouthUpperUp_L = 39,
	MouthFrown_R = 40,
	MouthStretch_R = 42,
	MouthRight = 48,
	MouthDimple_L = 49,
	MouthLowerDown_L = 50,
	NoseSneer_L = 1,
	NoseSneer_R = 13,
	TongueOut = 51,
	PP = 52,
	CH = 53,
	o = 54,
	O = 55,
	I = 56,
	u = 57,
	RR = 58,
	XX = 59,
	aa = 60,
	i = 61,
	FF = 62,
	U = 63,
	TH = 64,
	kk = 65,
	SS = 66,
	e = 67,
	DD = 68,
	E = 69,
	nn = 70,
	sil = 71,
	COUNT = 72
};

UENUM(BlueprintType)
enum class EPXRFaceTrackingMode : uint8
{
	PXR_FTM_NONE		  = (uint8)-1,
	PXR_FTM_FACE		  = 0,
	PXR_FTM_LIPS		  = 1,
	PXR_FTM_FACE_LIPS_VIS = 2,
	PXR_FTM_FACE_LIPS_BS  = 3
};

UENUM(BlueprintType)
enum class EPXRMotionTrackerConfidence : uint8
{
	PXR_STATIC_ACCURATE = 0 UMETA(DisplayName = "Static, accurate tracking"),
	PXR_6DOF_ACCURATE = 1 UMETA(DisplayName = "6DoF data, tracking accurate"),
	PXR_3DOF_NOT_ACCURATE = 2 UMETA(DisplayName = "3DoF data, tracking is not accurate"),
	PXR_6DOF_NOT_ACCURATE = 3 UMETA(DisplayName = "6DoF data, tracking is not accurate")
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRFaceTrackingState
{
	GENERATED_BODY()
public:
	FPXRFaceTrackingState();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		EPXRFaceTrackingMode CurrentTrackingMode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		EPXRTrackingStateCode TrackingStateCode;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRFaceTrackingStartInfo
{
	GENERATED_BODY()
public:
	FPXRFaceTrackingStartInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FaceTracking")
		EPXRFaceTrackingMode StartMode;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRFaceTrackingStopInfo
{
	GENERATED_BODY()
public:
	FPXRFaceTrackingStopInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FaceTracking")
		bool Pause;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRFaceTrackingDataGetInfo
{
	GENERATED_BODY()
public:
	FPXRFaceTrackingDataGetInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|FaceTracking")
		int64 DisplayTime;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRFaceTrackingData
{
	GENERATED_BODY()
public:
	FPXRFaceTrackingData();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		TArray<float> BlendShapeWeights;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		int64 TimeStamp;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		float LaughingProb;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		bool EyeValid;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|FaceTracking")
		bool FaceValid;
};

UENUM(BlueprintType)
enum class EPICOEye : uint8
{
	Left   = 0,
	Right  = 1,
	Center = 2,
	COUNT  = 3,
};

UENUM(BlueprintType)
enum class EPXREyeTrackingMode : uint8
{
	PXR_ETM_BOTH = 0,
	PXR_ETM_NONE = (uint8)-1,
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyeTrackingState
{
	GENERATED_BODY()
public:
	FPXREyeTrackingState();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		EPXREyeTrackingMode CurrentTrackingMode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		EPXRTrackingStateCode TrackingStateCode;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyeTrackingStartInfo
{
	GENERATED_BODY()
public:
	FPXREyeTrackingStartInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
		bool NeedCalibration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
		EPXREyeTrackingMode StartMode;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyeTrackingStopInfo
{
	GENERATED_BODY()
public:
	FPXREyeTrackingStopInfo() {}
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyeTrackingDataGetInfo
{
	GENERATED_BODY()
public:
	FPXREyeTrackingDataGetInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
		int64 DisplayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
		bool QueryPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|EyeTracking")
		bool QueryOrientation;
};



USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRPerEyeData
{
	GENERATED_BODY()
public:
	FPXRPerEyeData();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		EPICOEye EyeType;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		FVector Position;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		FRotator Orientation;
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		bool bIsPoseValid;
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		float Openness;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		bool bIsOpennessValid;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyeTrackingData
{
	GENERATED_BODY()
public:
	FPXREyeTrackingData();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
		TArray<FPXRPerEyeData> PerEyeDatas;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXREyePupilInfo
{
	GENERATED_BODY()
public:
	FPXREyePupilInfo():
		LeftEyePupilDiameter(0.0f),
		RightEyePupilDiameter(0.0f),
		LeftEyePupilPosition(FVector2D::ZeroVector),
		RightEyePupilPosition(FVector2D::ZeroVector)
	{}

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
	float LeftEyePupilDiameter;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
	float RightEyePupilDiameter;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
	FVector2D LeftEyePupilPosition;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|EyeTracking")
	FVector2D RightEyePupilPosition;
};

UENUM(BlueprintType)
enum class EPXRBodyTrackingMode : uint8
{
	PXR_BTM_DISABLE = 0,
	PXR_BTM_WITH_SWIFT = 1,
	PXR_BTM_WITHOUT_SWIFT = 2,
};

UENUM(BlueprintType)
enum class EPXRBodyTrackingGetDataFlags : uint8
{
	PXR_BODY_NONE = 0,
	PXR_BODY_POSE = 1 << 0,
	PXR_BODY_ACTION = 1 << 1,
	PXR_BODY_VELO_ACC = 1 << 2,
};
	
#define FITNESS_BAND_NUM_MAX 12
USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRBodyTrackingState
{
	GENERATED_BODY()

public:
	FPXRBodyTrackingState();

	//Reserved variables, not available to blueprints at this time
	EPXRBodyTrackingMode CurrentTrackingMode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	EPXRTrackingStateCode TrackingStateCode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	EPXRBodyTrackingStatusCode TrackingStatusCode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	EPXRBodyTrackingErrorCode TrackingErrorCode;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	int32 ConnectedBandCount;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	TArray<int32>  ConnectedFitnessBand;
};



USTRUCT(BlueprintType)
struct FPXRBodyTrackingBoneLength
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float headLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float neckLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float torsoLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float hipLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float upperLegLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float lowerLegLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float footLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float shoulderLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float upperArmLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float lowerArmLen;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTrackingData")
	float handLen;

	FPXRBodyTrackingBoneLength()
		: headLen(0.f),
		  neckLen(0.f),
		  torsoLen(0.f),
		  hipLen(0.f),
		  upperLegLen(0.f),
		  lowerLegLen(0.f),
		  footLen(0.f),
		  shoulderLen(0.f),
		  upperArmLen(0.f),
		  lowerArmLen(0.f),
		  handLen(0.f)
	{
	}
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRBodyTrackingStartInfo
{
	GENERATED_BODY()

public:
	FPXRBodyTrackingStartInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTracking")
	EBodyTrackingMode BodyTrackingMode = EBodyTrackingMode::BODY_TRACKING_MODE_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTracking")
	FPXRBodyTrackingBoneLength BoneLength = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTracking")
	int32 OtherMode = -1;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRBodyTrackingStopInfo
{
	GENERATED_BODY()

public:
	FPXRBodyTrackingStopInfo()
	{
	}
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRBodyTrackingDataGetInfo
{
	GENERATED_BODY()

public:
	FPXRBodyTrackingDataGetInfo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTracking")
	int64 DisplayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|BodyTracking")
	TArray<EPXRBodyTrackingGetDataFlags> DataFlags;
};

#define BODY_TRACKING_DATA_ROLE_NUM_MAX 24

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRBodyTrackingData
{
	GENERATED_BODY()

public:
	FPXRBodyTrackingData();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|BodyTracking")
	TArray<FPxrBodyTrackingTransform> RoleDatas;
};

#define BODY_TRACKERS_NUM_MAX 6
#define BODY_TRACKER_SN_LENGTH_MAX 24
#define BODY_TRACKER_EXT_PASS_DATA_MAX 15

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRMotionConnectState
{
	GENERATED_BODY()

	FPXRMotionConnectState();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 TrackerSum;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	TArray<FString> TrackersSNArray;
};

UENUM(BlueprintType)
enum class EPXRMotionTrackerType: uint8
{
	PXR_UNKNOWN = 0 UMETA(DisplayName = "UNKNOWN"),
	PXR_MOTION_TRACKER_1 = 1 UMETA(DisplayName = "PICO MOTION TRACKER 1"),
	PXR_MOTION_TRACKER_2 = 2 UMETA(DisplayName = "PICO MOTION TRACKER 2"),
};

UENUM(BlueprintType)
enum class EPXRMotionTrackerMode: uint8
{
	PXR_BODY_TRACKING = 0 UMETA(DisplayName = "BODY_TRACKING_MODE"),
	PXR_OBJECT_TRACKING = 1 UMETA(DisplayName = "OBJCET_TRACKING_MODE"),
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRMotionTrackerLocation
{
	GENERATED_BODY()

	FPXRMotionTrackerLocation();
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FTransform Pose;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FVector AngularVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FVector LinearVelocity;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FVector AngularAcceleration;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FVector LinearAcceleration;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRMotionTrackerLocations
{
	GENERATED_BODY()

	FPXRMotionTrackerLocations();

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FString TrackerSN;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FPXRMotionTrackerLocation LocalPose;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FPXRMotionTrackerLocation GlobalPose;
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerInfo
{
	GENERATED_BODY()
	
	FPXRExtDevTrackerInfo();
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FString TrackerSN;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 chargerStatus;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 batteryVolume;


	bool operator==(const FPXRExtDevTrackerInfo& Other) const
	{
		return (   TrackerSN == Other.TrackerSN
				&& chargerStatus == Other.chargerStatus
				&& batteryVolume == Other.batteryVolume);
	}
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerConnectState
{
	GENERATED_BODY()

	FPXRExtDevTrackerConnectState();
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 ExtNumber;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	TArray<FPXRExtDevTrackerInfo> ExtDevTrackerInfos;

};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerMotorVibrate
{
	GENERATED_BODY()
	
	FPXRExtDevTrackerMotorVibrate();
	
	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	FString TrackerSN;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	int32 Level;
	
	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	int32 Frequency;
	
	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	int32 Duration;

};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerPassData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	FString TrackerSN;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MotionTracker")
	TArray<int32> PassData;

	FPXRExtDevTrackerPassData();
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerKey
{
	GENERATED_BODY()
	
	FPXRExtDevTrackerKey();

	FPXRExtDevTrackerKey(const PxrExtDevTrackerKey& Other);
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Home;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 App;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 A_X;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 B_Y;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Grip;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Rocker;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Trigger;

	
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerTouch
{
	GENERATED_BODY()
	
	FPXRExtDevTrackerTouch();
	
	FPXRExtDevTrackerTouch(const PxrExtDevTrackerTouch& Other);
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 A_X;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 B_Y;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Rocker;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Trigger;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Thumbrest;
	
};

USTRUCT(BlueprintType)
struct PICOXRMOTIONTRACKING_API FPXRExtDevTrackerKeyData
{
	GENERATED_BODY()

	FPXRExtDevTrackerKeyData();

	FPXRExtDevTrackerKeyData(const PxrExtDevTrackerKeyData& Other);
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 ExtDevID;
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FPXRExtDevTrackerKey Key;
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	FPXRExtDevTrackerTouch Touch;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Trigger;
	
	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Grip;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Rocker_X;

	UPROPERTY(BlueprintReadOnly, Category = "PXR|MotionTracker")
	int32 Rocker_Y;
	
};


