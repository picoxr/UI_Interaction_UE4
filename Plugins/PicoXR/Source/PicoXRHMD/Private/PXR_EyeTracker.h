//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "PXR_HMDFunctionLibrary.h"
#include "Containers/Ticker.h"
#include "EyeTracker/Public/IEyeTracker.h"

#if PLATFORM_ANDROID
#include <PxrTypes.h>
#endif

class FDebugDisplayInfo;
class UCanvas;
class AHUD;

enum FEyePoseStatus
{
	kGazePointValid        = (1 << 0),
    kGazeVectorValid       = (1 << 1),
    kEyeOpennessValid      = (1 << 2),
    kEyePupilDilationValid = (1 << 3),
    kEyePositionGuideValid = (1 << 4)
};

struct FPICOXREyeTrackingGazeRay
{
	FVector Direction;			//Vector in world space with the gaze direction.
	bool IsValid;				//IsValid is true when there is available gaze data.
	FVector Origin;				//The middle of the eyes in world space.
};

class FPICOXREyeTracker : public IEyeTracker, public FTickerObjectBase
{
public:
	FPICOXREyeTracker();
	virtual ~FPICOXREyeTracker();
	virtual bool Tick(float DeltaTime) override;

	static TSharedPtr<FPICOXREyeTracker> GetInstance()
	{
		if (EyeTrackerPtr == nullptr)
		{
			EyeTrackerPtr = MakeShareable(new FPICOXREyeTracker());
		}
		return EyeTrackerPtr;
	}

	virtual bool GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const override;
	virtual bool GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const override;
	virtual EEyeTrackerStatus GetEyeTrackerStatus() const override;
	virtual bool IsStereoGazeDataAvailable() const override;
	virtual void SetEyeTrackedPlayer(APlayerController* PlayerController) override;

	void DrawDebug(AHUD* HUD, UCanvas* Canvas, const FDebugDisplayInfo& DisplayInfo, float& YL, float& YPos);
	bool UPxr_GetEyeTrackingData(FPICOXREyeTrackingData &TrackingData);
	bool GetEyeTrackingDataFromDevice(FPICOXREyeTrackingData &TrackingData);
	bool GetEyeTrackingGazeRay(FPICOXREyeTrackingGazeRay &EyeTrackingGazeRay)const;
	bool GetEyeDirectionToFoveationRendering(FVector &OutDirection)const;
	bool GetFaceTrackingData(int64 inTimeStamp, int64& outTimeStamp, TArray<float>& blendShapeWeight, TArray<float>& videoInputValid, float &laughingProb, TArray<float>& emotionProb, TArray<float>& reserved);
	bool EnableEyeTracking(bool enable);
	bool EnableFaceTracking(EPICOXRFaceTrackingMode mode);

private:
	TWeakObjectPtr<APlayerController> ActivePlayerController;
	FPICOXREyeTrackingData TrackerData;
	bool bEyeTrackingRun;
	bool bFaceTrackingRun;
	static TSharedPtr<FPICOXREyeTracker> EyeTrackerPtr;
	uint32 CurrentTrackingMode = 0x00000002;//PXR_TRACKING_MODE_POSITION_BIT PxrTypes.h
#if PLATFORM_ANDROID
	PxrFTInfo faceTrackingData;
#endif
};