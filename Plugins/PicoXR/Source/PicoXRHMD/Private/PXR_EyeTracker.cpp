//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_EyeTracker.h"
#include "DrawDebugHelpers.h"
#include "PXR_Settings.h"
#include "Engine/Engine.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#endif

FPICOXREyeTracker::FPICOXREyeTracker()
    :bEyeTrackingRun(false)
    ,bFaceTrackingRun(false)
{
    FMemory::Memzero(TrackerData);
#if PLATFORM_ANDROID
	FMemory::Memzero(faceTrackingData);
#endif
}

FPICOXREyeTracker::~FPICOXREyeTracker()
{
}

bool FPICOXREyeTracker::Tick(float DeltaTime)
{
    if (bEyeTrackingRun)
    {
        GetEyeTrackingDataFromDevice(TrackerData);
    }
    return true;
}


bool FPICOXREyeTracker::GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const
{
    //TODO: return  GazeData
    return false;
}

bool FPICOXREyeTracker::GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const
{
    //TODO: return Left/Right GazeData
    return false;
}

EEyeTrackerStatus FPICOXREyeTracker::GetEyeTrackerStatus() const
{
    if (bEyeTrackingRun)
    {
        if (TrackerData.LeftEyeOpenness == 1 ||TrackerData.RightEyeOpenness == 1)
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

bool FPICOXREyeTracker::IsStereoGazeDataAvailable() const
{
    return false;
}

void FPICOXREyeTracker::SetEyeTrackedPlayer(APlayerController* InPlayerController)
{
	if(InPlayerController && InPlayerController != ActivePlayerController)
	{
		ActivePlayerController = InPlayerController;
	}
}

void FPICOXREyeTracker::DrawDebug(AHUD* HUD, UCanvas* Canvas, const FDebugDisplayInfo& DisplayInfo, float& YL,
                                  float& YPos)
{
	FPICOXREyeTrackingGazeRay GazeRay;
	GetEyeTrackingGazeRay(GazeRay);
    DrawDebugSphere(HUD->GetWorld(), GazeRay.Origin, 20.0f, 16, FColor::Red);
}

bool FPICOXREyeTracker::UPxr_GetEyeTrackingData(FPICOXREyeTrackingData& OutTrackingData)
{
    if (bEyeTrackingRun)
    {
        OutTrackingData = TrackerData;
        return true;
    }
    return false;
}

bool FPICOXREyeTracker::GetEyeTrackingDataFromDevice(FPICOXREyeTrackingData& TrackingData)
{
    if (bEyeTrackingRun)
    {
#if  PLATFORM_ANDROID
        PxrEyeTrackingData eyeTrackingData;
        Pxr_GetEyeTrackingData(&eyeTrackingData);

        TrackingData.LeftEyePoseStatus = eyeTrackingData.leftEyePoseStatus;
        TrackingData.RightEyePoseStatus = eyeTrackingData.rightEyePoseStatus;
        TrackingData.CombinedEyePoseStatus = eyeTrackingData.combinedEyePoseStatus;
        TrackingData.LeftEyeGazePoint.X = eyeTrackingData.leftEyeGazePoint[0];
        TrackingData.LeftEyeGazePoint.Y = eyeTrackingData.leftEyeGazePoint[1];
        TrackingData.LeftEyeGazePoint.Z = eyeTrackingData.leftEyeGazePoint[2];
        TrackingData.RightEyeGazePoint.X = eyeTrackingData.rightEyeGazePoint[0];
        TrackingData.RightEyeGazePoint.Y = eyeTrackingData.rightEyeGazePoint[1];
        TrackingData.RightEyeGazePoint.Z = eyeTrackingData.rightEyeGazePoint[2];
        TrackingData.CombinedEyeGazePoint.X = eyeTrackingData.combinedEyeGazePoint[0];
        TrackingData.CombinedEyeGazePoint.Y = eyeTrackingData.combinedEyeGazePoint[1];
        TrackingData.CombinedEyeGazePoint.Z = eyeTrackingData.combinedEyeGazePoint[2];
        TrackingData.LeftEyeGazeVector.X = eyeTrackingData.leftEyeGazeVector[0];
        TrackingData.LeftEyeGazeVector.Y = eyeTrackingData.leftEyeGazeVector[1];
        TrackingData.LeftEyeGazeVector.Z = eyeTrackingData.leftEyeGazeVector[2];
        TrackingData.RightEyeGazeVector.X = eyeTrackingData.rightEyeGazeVector[0];
        TrackingData.RightEyeGazeVector.Y = eyeTrackingData.rightEyeGazeVector[1];
        TrackingData.RightEyeGazeVector.Z = eyeTrackingData.rightEyeGazeVector[2];
        TrackingData.CombinedEyeGazeVector.X = eyeTrackingData.combinedEyeGazeVector[0];
        TrackingData.CombinedEyeGazeVector.Y = eyeTrackingData.combinedEyeGazeVector[1];
        TrackingData.CombinedEyeGazeVector.Z = eyeTrackingData.combinedEyeGazeVector[2];
        TrackingData.LeftEyeOpenness = eyeTrackingData.leftEyeOpenness;
        TrackingData.RightEyeOpenness = eyeTrackingData.rightEyeOpenness;
        TrackingData.LeftEyePupilDilation = eyeTrackingData.leftEyePupilDilation;
        TrackingData.RightEyePupilDilation = eyeTrackingData.rightEyePupilDilation;
        TrackingData.LeftEyePositionGuide.X = eyeTrackingData.leftEyePositionGuide[0];
        TrackingData.LeftEyePositionGuide.Y = eyeTrackingData.leftEyePositionGuide[1];
        TrackingData.LeftEyePositionGuide.Z = eyeTrackingData.leftEyePositionGuide[2];
        TrackingData.RightEyePositionGuide.X = eyeTrackingData.rightEyePositionGuide[0];
        TrackingData.RightEyePositionGuide.Y = eyeTrackingData.rightEyePositionGuide[1];
        TrackingData.RightEyePositionGuide.Z = eyeTrackingData.rightEyePositionGuide[2];
        TrackingData.FoveatedGazeDirection.X = eyeTrackingData.foveatedGazeDirection[0];
        TrackingData.FoveatedGazeDirection.Y = eyeTrackingData.foveatedGazeDirection[1];
        TrackingData.FoveatedGazeDirection.Z = eyeTrackingData.foveatedGazeDirection[2];
        TrackingData.FoveatedGazeTrackingState = eyeTrackingData.foveatedGazeTrackingState;
#endif
    }
	return true;
}

bool FPICOXREyeTracker::GetEyeTrackingGazeRay(FPICOXREyeTrackingGazeRay& EyeTrackingGazeRay) const
{
    EyeTrackingGazeRay.Direction = TrackerData.CombinedEyeGazeVector;
	EyeTrackingGazeRay.Origin = TrackerData.CombinedEyeGazePoint;

	EyeTrackingGazeRay.IsValid = (TrackerData.CombinedEyePoseStatus & kGazePointValid) != 0 && (TrackerData.CombinedEyePoseStatus & kGazeVectorValid) != 0;
	if (EyeTrackingGazeRay.IsValid)
	{
		FVector HeadLocation = FVector::ZeroVector;
		FRotator HeadRotation = FRotator::ZeroRotator;
		if ( ActivePlayerController!= nullptr)
		{
			HeadLocation = ActivePlayerController->PlayerCameraManager->GetCameraLocation();
			HeadRotation = ActivePlayerController->PlayerCameraManager->GetCameraRotation();
		}

        const FMatrix CameraMatrix = FScaleRotationTranslationMatrix(FVector::OneVector, HeadRotation, HeadLocation);
        const FMatrix EyeMatrix = FScaleRotationTranslationMatrix(FVector::OneVector, FVector(-EyeTrackingGazeRay.Direction.Z, EyeTrackingGazeRay.Direction.X, EyeTrackingGazeRay.Direction.Y).ToOrientationRotator(), FVector(-EyeTrackingGazeRay.Origin.Z, EyeTrackingGazeRay.Origin.X, EyeTrackingGazeRay.Origin.Y));
        const FMatrix EyeMatrix2 =  EyeMatrix * CameraMatrix ;
		EyeTrackingGazeRay.Origin = EyeMatrix2.GetOrigin();
		EyeTrackingGazeRay.Direction = EyeMatrix2.ToQuat().GetForwardVector();
		return true;
	}
	return false;
}

bool FPICOXREyeTracker::GetEyeDirectionToFoveationRendering(FVector& OutDirection) const
{
    if (bEyeTrackingRun)
	{
		FPICOXREyeTrackingData TempTrackingData;
		TempTrackingData = TrackerData;
		FVector FocusPoints[2] = { FVector::ZeroVector,FVector::ZeroVector };
		if (bEyeTrackingRun)
		{
			FVector EyeDirections[3] = 
			{
			FVector(TempTrackingData.FoveatedGazeDirection.X,TempTrackingData.FoveatedGazeDirection.Y,-TempTrackingData.FoveatedGazeDirection.Z),
			FVector(TempTrackingData.FoveatedGazeDirection.X,TempTrackingData.FoveatedGazeDirection.Y,-TempTrackingData.FoveatedGazeDirection.Z),
			FVector(TempTrackingData.FoveatedGazeDirection.X,TempTrackingData.FoveatedGazeDirection.Y,-TempTrackingData.FoveatedGazeDirection.Z)
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

bool FPICOXREyeTracker::GetFaceTrackingData(int64 inTimeStamp, int64& outTimeStamp, TArray<float>& blendShapeWeight, TArray<float>& videoInputValid, float &laughingProb, TArray<float>& emotionProb, TArray<float>& reserved)
{
	UPICOXRSettings* Settings = GetMutableDefault<UPICOXRSettings>();
	if (Settings && bFaceTrackingRun)
	{
		int64_t pxrTs = inTimeStamp;
		int pxrFlags = 0;
		int BSN = 72;
#if PLATFORM_ANDROID
		BSN = BLEND_SHAPE_NUMS;
		switch (Settings->FaceTrackingMode)
		{
		case EPICOXRFaceTrackingMode::Disable:
			pxrFlags = GetDataType::PXR_GET_FACE_DATA_DEFAULT;
			break;
		case EPICOXRFaceTrackingMode::FaceOnly:
			pxrFlags = GetDataType::PXR_GET_FACE_DATA;
			break;
		case EPICOXRFaceTrackingMode::LipsOnly:
			pxrFlags = GetDataType::PXR_GET_LIP_DATA;
			break;
		case EPICOXRFaceTrackingMode::FaceAndLips:
			pxrFlags = GetDataType::PXR_GET_FACELIP_DATA;
			break;
		default:
			break;
		}
#endif
		blendShapeWeight.SetNum(BSN);
        videoInputValid.SetNum(10);
        emotionProb.SetNum(10);
		reserved.SetNum(128);
#if PLATFORM_ANDROID
		Pxr_GetFaceTrackingData(pxrTs, pxrFlags, &faceTrackingData);
        outTimeStamp = faceTrackingData.timestamp;
		laughingProb = faceTrackingData.laughingProb;
		FMemory::Memcpy(blendShapeWeight.GetData(), faceTrackingData.blendShapeWeight, sizeof(float) * BSN);
		FMemory::Memcpy(videoInputValid.GetData(), faceTrackingData.videoInputValid, sizeof(float) * 10);
		FMemory::Memcpy(emotionProb.GetData(), faceTrackingData.emotionProb, sizeof(float) * 10);
		FMemory::Memcpy(reserved.GetData(), faceTrackingData.reserved, sizeof(float) * 128);
#endif
		return true;
	}
	return false;
}

bool FPICOXREyeTracker::EnableEyeTracking(bool enable)
{
	UPICOXRSettings* Settings = GetMutableDefault<UPICOXRSettings>();
    if (Settings)
    {
#if PLATFORM_ANDROID  
        uint32 TargetTrackingMode = CurrentTrackingMode;
        if (enable)
        {
            TargetTrackingMode |= PXR_TRACKING_MODE_EYE_BIT;
        }
        else
        {
            TargetTrackingMode &= ~PXR_TRACKING_MODE_EYE_BIT;
        }
        int CurrentVersion = 0;
        Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
        if (CurrentVersion >= 0x2000304)
        {
    		PxrTrackingModeFlags SupportTrackingMode;
    		Pxr_GetTrackingMode(&SupportTrackingMode);
    		if (PXR_TRACKING_MODE_EYE_BIT & SupportTrackingMode)//Detect support EyeTracking
    		{
    			// Open EyeTracking
    			if (Pxr_SetTrackingMode(TargetTrackingMode) == 0)
    			{
    				bEyeTrackingRun = enable;
                    CurrentTrackingMode = TargetTrackingMode;
                    Settings->bEnableEyeTracking = enable;
    				FString EyeTrackingLog=enable? "Enable Succeeded!": "Disable Succeeded!";
    				UE_LOG(LogHMD, Log, TEXT("EyeTracking:%s"),*EyeTrackingLog);
                    return true;
    			}
    		}
        }
        else
        {
    		if (Pxr_SetTrackingMode(TargetTrackingMode) == 0)
    		{
    			bEyeTrackingRun = enable;
                CurrentTrackingMode = TargetTrackingMode;
                Settings->bEnableEyeTracking = enable;
    			FString EyeTrackingLog=enable? "Enable Succeeded!": "Disable Succeeded!";
    			UE_LOG(LogHMD, Log, TEXT("EyeTracking:%s"),*EyeTrackingLog);
                return true;
    		}
        }
#endif
    }
    Settings->bEnableEyeTracking = false;
	FString EyeTrackingLog=enable? "Enable Failed!": "Disable Failed!";
	UE_LOG(LogHMD, Log, TEXT("EyeTracking:%s"),*EyeTrackingLog);
    return false;
}

bool FPICOXREyeTracker::EnableFaceTracking(EPICOXRFaceTrackingMode mode)
{
	UPICOXRSettings* Settings = GetMutableDefault<UPICOXRSettings>();
	if (Settings)
	{
#if PLATFORM_ANDROID
		uint32 TargetTrackingMode = CurrentTrackingMode;
        switch (mode)
        {
        case EPICOXRFaceTrackingMode::Disable:
			TargetTrackingMode &= ~PXR_TRACKING_MODE_FACE_BIT;
			TargetTrackingMode &= ~PXR_TRACKING_MODE_FACE_LIBSYNC;
            break;
        case EPICOXRFaceTrackingMode::FaceOnly:
            TargetTrackingMode |= PXR_TRACKING_MODE_FACE_BIT;
            TargetTrackingMode &= ~PXR_TRACKING_MODE_FACE_LIBSYNC;
            break;
        case EPICOXRFaceTrackingMode::LipsOnly:
            TargetTrackingMode &= ~PXR_TRACKING_MODE_FACE_BIT;
            TargetTrackingMode |= PXR_TRACKING_MODE_FACE_LIBSYNC;
            break;
        case EPICOXRFaceTrackingMode::FaceAndLips:
            TargetTrackingMode |= PXR_TRACKING_MODE_FACE_BIT;
			TargetTrackingMode |= PXR_TRACKING_MODE_FACE_LIBSYNC;
            break;
        default:
            break;
        }
		int CurrentVersion = 0;
		Pxr_GetConfigInt(PxrConfigType::PXR_API_VERSION, &CurrentVersion);
        if (CurrentVersion >= 0x2000305)
        {
            if (Pxr_SetTrackingMode(TargetTrackingMode) == 0)
			{
				if (mode==EPICOXRFaceTrackingMode::Disable)
				{
                    bFaceTrackingRun = false;
                }
                else
                {
                    bFaceTrackingRun = true;
                }
				CurrentTrackingMode = TargetTrackingMode;
				UE_LOG(LogHMD, Log, TEXT("Face Tracking Mode:%u"), CurrentTrackingMode);
                return true;
            }
        }
#endif
	}
	return false;
}
