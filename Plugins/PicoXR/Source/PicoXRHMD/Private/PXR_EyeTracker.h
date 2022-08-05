//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "PXR_HMDFunctionLibrary.h"
#include "Containers/Ticker.h"
#include "EyeTracker/Public/IEyeTracker.h"

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

struct FPicoXREyeTrackingGazeRay
{
	FVector Direction;			//Vector in world space with the gaze direction.
	bool IsValid;				//IsValid is true when there is available gaze data.
	FVector Origin;				//The middle of the eyes in world space.
};

class FPicoXREyeTracker : public IEyeTracker, public FTickerObjectBase
{
public:
	FPicoXREyeTracker();
	virtual ~FPicoXREyeTracker();
	virtual bool Tick(float DeltaTime) override;

	static TSharedPtr<FPicoXREyeTracker> GetInstance()
	{
		if (EyeTrackerPtr == nullptr)
		{
			EyeTrackerPtr = MakeShareable(new FPicoXREyeTracker());
		}
		return EyeTrackerPtr;
	}

	virtual bool GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const override;
	virtual bool GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const override;
	virtual EEyeTrackerStatus GetEyeTrackerStatus() const override;
	virtual bool IsStereoGazeDataAvailable() const override;
	virtual void SetEyeTrackedPlayer(APlayerController* PlayerController) override;

	void DrawDebug(AHUD* HUD, UCanvas* Canvas, const FDebugDisplayInfo& DisplayInfo, float& YL, float& YPos);
	bool OpenEyeTracking(bool enable);
	bool UPxr_GetEyeTrackingData(FPicoXREyeTrackingData &TrackingData);
	bool GetEyeTrackingDataFromDevice(FPicoXREyeTrackingData &TrackingData);
	bool GetEyeTrackingGazeRay(FPicoXREyeTrackingGazeRay &EyeTrackingGazeRay)const;
	bool GetEyeDirectionToFoveationRendering(FVector &OutDirection)const;

private:
	TWeakObjectPtr<APlayerController> ActivePlayerController;
	FPicoXREyeTrackingData TrackerData;
	bool bEyeTrackingRun;
	static TSharedPtr<FPicoXREyeTracker> EyeTrackerPtr;
};