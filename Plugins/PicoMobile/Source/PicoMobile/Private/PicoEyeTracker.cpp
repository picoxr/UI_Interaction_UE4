// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoEyeTracker.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "PicoMobileSettings.h"
#include "PicoImport.h"

DEFINE_LOG_CATEGORY_STATIC(PicoEyeTracker, Log, All);

FPicoEyeTracker* FPicoEyeTracker::gEyeTracker = nullptr;

FPicoEyeTracker::FPicoEyeTracker():
	ActivePlayerController(nullptr),
	TrackerData(FPicoEyeTrackingData()),
	bEyeTrackingRun(false)
{

}

FPicoEyeTracker::~FPicoEyeTracker()
{

}

bool FPicoEyeTracker::Tick(float DeltaTime)
{
#if PLATFORM_ANDROID
	if (bEyeTrackingRun)
	{
		GetEyeTrackingDataFromDevice(TrackerData);
	}
#endif
	return true;
}


void FPicoEyeTracker::SetEyeTrackedPlayer(APlayerController* PlayerController)
{
	if (PlayerController != nullptr)
	{
		ActivePlayerController = PlayerController;
	}
	else if (GEngine != nullptr && GEngine->GameViewport != nullptr)
	{
		ActivePlayerController = GEngine->GetFirstLocalPlayerController(GEngine->GameViewport->GetWorld());
	}

}


bool FPicoEyeTracker::GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const
{
	//TODO: return  GazeData
	//OutGazeData.GazeDirection = ;
	//OutGazeData.GazeOrigin = ;
	//OutGazeData.FixationPoint = ;
	//OutGazeData.ConfidenceValue = ;
	return false;
}

bool FPicoEyeTracker::GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const
{
	//TODO: return Left/Right GazeData
	//if (GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	//{
	//	OutGazeData.LeftEyeOrigin = ;
	//	OutGazeData.LeftEyeDirection = ;
	//	OutGazeData.RightEyeOrigin = ;
	//	OutGazeData.RightEyeDirection = ;
	//	OutGazeData.FixationPoint = ;
	//	return true;
	//}
	return false;
}

EEyeTrackerStatus FPicoEyeTracker::GetEyeTrackerStatus() const
{
	if (bEyeTrackingRun)
	{
		if (TrackerData.leftEyeOpenness == 1 ||TrackerData.rightEyeOpenness == 1)
		{
			return EEyeTrackerStatus::Tracking;
		}
		else
		{
			return EEyeTrackerStatus::NotTracking;
		}
		
	}
	return EEyeTrackerStatus::NotConnected;
}

bool FPicoEyeTracker::IsStereoGazeDataAvailable() const
{
	return false;
}

bool FPicoEyeTracker::OpenEyeTracking()
{
	bool retValue = false;
#if PLATFORM_ANDROID
	if (GetDefault<UPicoMobileSettings>()->bEnableEyeTracking)
	{
		if (PicoImport::PvrGetTrackingMode() & 4)
		{
			if (PicoImport::PvrSetTrackingMode(EyeTrackingMode))
			{
				UE_LOG(PicoEyeTracker, Log, TEXT("Pvr_UE DISFT Enable Eye Tracking Succeed!"));
				bEyeTrackingRun = true;
				retValue = true;
			}
			else
			{
				UE_LOG(PicoEyeTracker, Log, TEXT("Pvr_UE DISFT Enable Eye Tracking Failed!"));
			}
		}
		else
		{
			UE_LOG(PicoEyeTracker, Log, TEXT("Pvr_UE DISFT Devices is not support EyeTracking!"));
		}	
	}
	else
	{
		UE_LOG(PicoEyeTracker, Log, TEXT("Pvr_UE DISFT Do not Open EyeTracking!"));
	}
#endif
	return retValue;
}

bool FPicoEyeTracker::GetEyeTrackingData(FPicoEyeTrackingData &OutTrackingData)
{
	if (bEyeTrackingRun)
	{
		OutTrackingData = TrackerData;
		return true;
	}
	return false;
}

bool FPicoEyeTracker::GetEyeTrackingDataFromDevice(FPicoEyeTrackingData &TrackingData)
{
	if (bEyeTrackingRun)
	{
#if PLATFORM_ANDROID
		return PicoImport::PvrGetEyeTrackingData(
			TrackingData.leftEyePoseStatus, TrackingData.rightEyePoseStatus, TrackingData.combinedEyePoseStatus,
			TrackingData.leftEyeGazePoint.X, TrackingData.leftEyeGazePoint.Y, TrackingData.leftEyeGazePoint.Z,
			TrackingData.rightEyeGazePoint.X, TrackingData.rightEyeGazePoint.Y, TrackingData.rightEyeGazePoint.Z,
			TrackingData.combinedEyeGazePoint.X, TrackingData.combinedEyeGazePoint.Y, TrackingData.combinedEyeGazePoint.Z,
		
			TrackingData.leftEyeGazeVector.X, TrackingData.leftEyeGazeVector.Y, TrackingData.leftEyeGazeVector.Z,
			TrackingData.rightEyeGazeVector.X, TrackingData.rightEyeGazeVector.Y, TrackingData.rightEyeGazeVector.Z,
			TrackingData.combinedEyeGazeVector.X, TrackingData.combinedEyeGazeVector.Y, TrackingData.combinedEyeGazeVector.Z,
			TrackingData.leftEyeOpenness, TrackingData.rightEyeOpenness,
			TrackingData.leftEyePupilDilation, TrackingData.rightEyePupilDilation,
			TrackingData.leftEyePositionGuide.X, TrackingData.leftEyePositionGuide.Y, TrackingData.leftEyePositionGuide.Z,
			TrackingData.rightEyePositionGuide.X, TrackingData.rightEyePositionGuide.Y, TrackingData.rightEyePositionGuide.Z,
			TrackingData.foveatedGazeDirection.X, TrackingData.foveatedGazeDirection.Y, TrackingData.foveatedGazeDirection.Z,
			TrackingData.foveatedGazeTrackingState
		);
#endif
	}
	return false;
}

bool FPicoEyeTracker::GetEyeTrackingGazeRay(FEyeTrackingGazeRay &EyeTrackingGazeRay)const
{
#if PLATFORM_ANDROID
	EyeTrackingGazeRay.Direction = TrackerData.combinedEyeGazeVector;
	EyeTrackingGazeRay.Origin = TrackerData.combinedEyeGazePoint;

	EyeTrackingGazeRay.IsValid = (TrackerData.combinedEyePoseStatus & (int)FEyePoseStatus::kGazePointValid) != 0 && (TrackerData.combinedEyePoseStatus & (int)FEyePoseStatus::kGazeVectorValid) != 0;
	if (EyeTrackingGazeRay.IsValid)
	{
		FVector HeadLocation = FVector::ZeroVector;
		FRotator HeadRotation = FRotator::ZeroRotator;
		if ( ActivePlayerController!= nullptr)
		{
			HeadLocation = ActivePlayerController->PlayerCameraManager->GetCameraLocation();
			HeadRotation = ActivePlayerController->PlayerCameraManager->GetCameraRotation();
			/*UE_LOG(PicoEyeTracker, Log, TEXT("PlayerCameraManager Location(%f,%f,%f)"), HeadLocation.X, HeadLocation.Y, HeadLocation.Z);
			UE_LOG(PicoEyeTracker, Log, TEXT("PlayerCameraManager Rotation(%f,%f,%f)"), HeadRotation.Roll, HeadRotation.Pitch, HeadRotation.Yaw);*/
		}
		else
		{
			HeadLocation = PicoSDK::Sensor::GCurrentPoseGT.Position;
			HeadRotation = PicoSDK::Sensor::GCurrentPoseGT.Orientation.Rotator();
		}
		FMatrix CamMatrix = FScaleRotationTranslationMatrix(FVector::OneVector, HeadRotation, HeadLocation);
		FMatrix EyeMatrix = FScaleRotationTranslationMatrix(FVector::OneVector, FVector(-EyeTrackingGazeRay.Direction.Z, EyeTrackingGazeRay.Direction.X, EyeTrackingGazeRay.Direction.Y).ToOrientationRotator(), FVector(-EyeTrackingGazeRay.Origin.Z, EyeTrackingGazeRay.Origin.X, EyeTrackingGazeRay.Origin.Y));
		FMatrix EyeMatrix2 =  EyeMatrix * CamMatrix ;
		EyeTrackingGazeRay.Origin = EyeMatrix2.GetOrigin();
		EyeTrackingGazeRay.Direction = EyeMatrix2.ToQuat().GetForwardVector();
		/*UE_LOG(PicoEyeTracker, Log, TEXT("EyeTrackingGazeRay.Origin(%f,%f,%f)"), EyeTrackingGazeRay.Origin.X, EyeTrackingGazeRay.Origin.Y, EyeTrackingGazeRay.Origin.Z);
		UE_LOG(PicoEyeTracker, Log, TEXT("EyeTrackingGazeRay.Direction(%f,%f,%f)"), EyeTrackingGazeRay.Direction.X, EyeTrackingGazeRay.Direction.Y, EyeTrackingGazeRay.Direction.Z);*/
		return true;
	}
#endif
	return false;
}

bool FPicoEyeTracker::GetEyeDirectionToFoveationRendering(FVector &OutDirection) const
{
	if (bEyeTrackingRun)
	{
		FPicoEyeTrackingData TempTrackingData;
		TempTrackingData = TrackerData;
		FVector FocusPoints[2] = { FVector::ZeroVector,FVector::ZeroVector };
		if (bEyeTrackingRun)
		{
			//TempTrackingData.leftEyeGazeVector = TempTrackingData.rightEyeGazeVector = TempTrackingData.combinedEyeGazeVector;

			FVector EyeDirections[3] = 
			{
			FVector(TempTrackingData.foveatedGazeDirection.X,TempTrackingData.foveatedGazeDirection.Y,-TempTrackingData.foveatedGazeDirection.Z),
			FVector(TempTrackingData.foveatedGazeDirection.X,TempTrackingData.foveatedGazeDirection.Y,-TempTrackingData.foveatedGazeDirection.Z),
			FVector(TempTrackingData.foveatedGazeDirection.X,TempTrackingData.foveatedGazeDirection.Y,-TempTrackingData.foveatedGazeDirection.Z)
			};


			float NearPlanesDistances[2] = { 0.0508f, 0.0508f };

			FVector4 NearPlaneExtents[2] =
			{
				FVector4(-0.0428f, 0.0428f, -0.0428f, 0.0428f),
				FVector4(-0.0428f, 0.0428f, -0.0428f, 0.0428f)
			};

			for (uint32 EyeIndex = 0; EyeIndex < 2; EyeIndex++)
			{
				if (!FMath::IsNearlyZero(EyeDirections[EyeIndex].Z))
				{
					FVector2D Intersection;
					Intersection.X = (NearPlanesDistances[EyeIndex] * EyeDirections[EyeIndex].X) / EyeDirections[EyeIndex].Z;
					Intersection.Y = (NearPlanesDistances[EyeIndex] * EyeDirections[EyeIndex].Y) / EyeDirections[EyeIndex].Z;

					// X in [L,R] -> x in [-1,1] => x == -1 + (X-L)*(1-(-1))/(R-L)
					check(NearPlaneExtents[EyeIndex].X != NearPlaneExtents[EyeIndex].Y);
					FocusPoints[EyeIndex].X = -1.f + 2.f*(Intersection.X - NearPlaneExtents[EyeIndex].X) / (NearPlaneExtents[EyeIndex].Y - NearPlaneExtents[EyeIndex].X);

					// Y in [B,T] -> y in [-1,1] => y == -1 + (Y-B)*(1-(-1))/(T-B)
					check(NearPlaneExtents[EyeIndex].Z != NearPlaneExtents[EyeIndex].W);
					FocusPoints[EyeIndex].Y = -1.f + 2.f*(Intersection.Y - NearPlaneExtents[EyeIndex].Z) / (NearPlaneExtents[EyeIndex].W - NearPlaneExtents[EyeIndex].Z);
				}
			}
		}

		OutDirection.X = FocusPoints[0].X;
		OutDirection.Y = FocusPoints[0].Y;
		return true;
	}
	return false;
	
}