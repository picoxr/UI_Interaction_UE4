// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EyeTracker/Public/IEyeTracker.h"
#include "Containers/Ticker.h"
#include "GameFramework/PlayerController.h"
#include "PicoBlueprintFunctionLibrary.h"


#define EyeTrackingMode 6

struct FEyeTrackingGazeRay
{
	FVector Direction;				//Vector in world space with the gaze direction.
	bool IsValid;					//IsValid is true when there is available gaze data.
	FVector Origin;				//The middle of the eyes in world space.
};

enum FEyePoseStatus
{
	kGazePointValid = (1 << 0),
	kGazeVectorValid = (1 << 1),
	kEyeOpennessValid = (1 << 2),
	kEyePupilDilationValid = (1 << 3),
	kEyePositionGuideValid = (1 << 4)
};

class FPicoEyeTracker : public IEyeTracker, public FTickerObjectBase
{
public:
	FPicoEyeTracker();
	virtual ~FPicoEyeTracker();
	virtual bool Tick(float DeltaTime) override;

	static FPicoEyeTracker* GetInstance()
	{
		if (gEyeTracker == nullptr)
		{
			gEyeTracker = new FPicoEyeTracker();
		}
		return gEyeTracker;
	}

	void Destory()
	{
		if (nullptr == gEyeTracker)
		{
			delete gEyeTracker;
			gEyeTracker = nullptr;
		}
	}

	/**
	 * Specifies player being eye-tracked. This is not necessary for all devices, but is necessary for some to determine viewport properties, etc..
	 * Implementing class should cache this locally as it doesn't need to be called every tick.
	 */
	virtual void SetEyeTrackedPlayer(APlayerController* PlayerController) override;

	/**
	 * Returns gaze data for the given player controller.
	 * @return true if returning valid data, false if gaze data was unavailable
	*/
	virtual bool GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const override;

	/**
	 * Returns stereo gaze data for the given player controller (contains data for each eye individually).
	 * @return true if returning valid data, false if stereo gaze data was unavailable
	 */
	virtual bool GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const override;

	/** Returns information about the status of the current device. */
	virtual EEyeTrackerStatus GetEyeTrackerStatus() const override;


	/** Returns true if the current device can provide per-eye gaze data, false otherwise. */
	virtual bool IsStereoGazeDataAvailable() const override;


	bool OpenEyeTracking();

	bool GetEyeTrackingData(FPicoEyeTrackingData &TrackingData);

	bool GetEyeTrackingDataFromDevice(FPicoEyeTrackingData &TrackingData);

	bool GetEyeTrackingGazeRay(FEyeTrackingGazeRay &EyeTrackingGazeRay)const;

	bool GetEyeDirectionToFoveationRendering(FVector &OutDirection)const;

	bool isEyeGazeDirectionValid(int32& Status)  const { return  0 != (Status & FEyePoseStatus::kGazeVectorValid); }

	bool isEyeGazePointValid(int32_t& Status)      const { return  0 != (Status & FEyePoseStatus::kGazePointValid); }



	TWeakObjectPtr<APlayerController> ActivePlayerController;
	FPicoEyeTrackingData TrackerData;
	bool bEyeTrackingRun;
	static FPicoEyeTracker* gEyeTracker;

};