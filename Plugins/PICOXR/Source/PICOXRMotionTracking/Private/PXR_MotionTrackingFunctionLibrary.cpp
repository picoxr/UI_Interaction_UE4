// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_MotionTrackingFunctionLibrary.h"
#include "PXR_HMDPrivate.h"
#include "PXR_MotionTracking.h"
#include "PXR_HMD.h"
#include "PXR_InputFunctionLibrary.h"

bool UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingSupported(bool& Supported, TArray<EPXRFaceTrackingMode>& SupportedModes)
{
	return PICOXRMotionTracking::GetFaceTrackingSupported(Supported, SupportedModes);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingState(bool& IsTracking, FPXRFaceTrackingState& TrackingState)
{
	return PICOXRMotionTracking::GetFaceTrackingState(IsTracking, TrackingState);
}

bool UPICOXRMotionTrackingFunctionLibrary::StartFaceTracking(const FPXRFaceTrackingStartInfo& StartInfo)
{
	return PICOXRMotionTracking::StartFaceTracking(StartInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::StopFaceTracking(const FPXRFaceTrackingStopInfo& StopInfo)
{
	return PICOXRMotionTracking::StopFaceTracking(StopInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingData(const FPXRFaceTrackingDataGetInfo& GetInfo, FPXRFaceTrackingData& OutFaceTrackingData)
{
	return PICOXRMotionTracking::GetFaceTrackingData(GetInfo, OutFaceTrackingData);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingSupported(bool& Supported, TArray<EPXREyeTrackingMode>& SupportedModes)
{
	return PICOXRMotionTracking::GetEyeTrackingSupported(Supported, SupportedModes);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingState(bool& IsTracking, FPXREyeTrackingState& TrackingState)
{
	return PICOXRMotionTracking::GetEyeTrackingState(IsTracking, TrackingState);
}

bool UPICOXRMotionTrackingFunctionLibrary::StartEyeTracking(const FPXREyeTrackingStartInfo& StartInfo)
{
	return PICOXRMotionTracking::StartEyeTracking(StartInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::StopEyeTracking(const FPXREyeTrackingStopInfo& StopInfo)
{
	return PICOXRMotionTracking::StopEyeTracking(StopInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingData(float WorldToMetersScale, const FPXREyeTrackingDataGetInfo& GetInfo, FPXREyeTrackingData& OutEyeTrackingData)
{
	return PICOXRMotionTracking::GetEyeTrackingData(WorldToMetersScale, GetInfo, OutEyeTrackingData);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyeOpenness(float& LeftEyeOpenness, float& RightEyeOpenness)
{
	return PICOXRMotionTracking::GetEyeOpenness(LeftEyeOpenness, RightEyeOpenness);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyePupilInfo(FPXREyePupilInfo& EyePupilInfo)
{
	return PICOXRMotionTracking::GetEyePupilInfo(EyePupilInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetPerEyePose(int64& Timestamp, FTransform& LeftEyePose, FTransform& RightEyePose)
{
	return PICOXRMotionTracking::GetPerEyePose(Timestamp, LeftEyePose, RightEyePose);
}

bool UPICOXRMotionTrackingFunctionLibrary::GetEyeBlink(int64& Timestamp, bool& bLeftBlink, bool& bRightBlink)
{
	return PICOXRMotionTracking::GetEyeBlink(Timestamp, bLeftBlink, bRightBlink);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_WantBodyTrackingService()
{
	return PICOXRMotionTracking::WantBodyTrackingService();
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingSupported(bool& Supported)
{
	return PICOXRMotionTracking::GetBodyTrackingSupported(Supported);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingState(bool& IsTracking, FPXRBodyTrackingState& TrackingState)
{
	return PICOXRMotionTracking::GetBodyTrackingState(IsTracking,TrackingState);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_StartBodyTracking(const FPXRBodyTrackingStartInfo& StartInfo)
{
	return PICOXRMotionTracking::StartBodyTracking(StartInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_StopBodyTracking(const FPXRBodyTrackingStopInfo& StopInfo)
{
	return PICOXRMotionTracking::StopBodyTracking(StopInfo);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingData(float WorldToMetersScale, const FPXRBodyTrackingDataGetInfo& GetInfo, FPXRBodyTrackingData& BodyTrackingData)
{
	return PICOXRMotionTracking::GetBodyTrackingData(WorldToMetersScale,GetInfo,BodyTrackingData);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_StartMotionTrackerCalibApp()
{
	EPXRMotionTrackerType CurrentType={};

	if (PXR_GetMotionTrackerDeviceType(CurrentType))
	{
		switch (CurrentType) {
		case EPXRMotionTrackerType::PXR_UNKNOWN:
			{
				return false;
			}
			break;
		case EPXRMotionTrackerType::PXR_MOTION_TRACKER_1:
			{
				return PICOXRMotionTracking::StartMotionTrackerCalibApp(PICOXRMotionTracking::GetAndroidPackageName(),0);
			}
			break;
		case EPXRMotionTrackerType::PXR_MOTION_TRACKER_2:
			{
				return PICOXRMotionTracking::StartMotionTrackerCalibApp(PICOXRMotionTracking::GetAndroidPackageName(),1);
			}
			break;
		default: ;
		}
	}
	
	return false;
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerConnectStateWithSN(FPXRMotionConnectState& connectState)
{
	return PICOXRMotionTracking::GetMotionTrackerConnectState(connectState);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerDeviceType(EPXRMotionTrackerType& trackerType)
{
	return PICOXRMotionTracking::GetMotionTrackerType(trackerType);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerMode(EPXRMotionTrackerMode& trackerMode)
{
	return PICOXRMotionTracking::GetMotionTrackerMode(trackerMode);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerLocations(float WorldToMetersScale, const FString& trackerSN, FPXRMotionTrackerLocations& locations,EPXRMotionTrackerConfidence& Confidence)
{
	if (!trackerSN.IsEmpty())
	{
		return PICOXRMotionTracking::GetMotionTrackerLocations(WorldToMetersScale,trackerSN,locations,Confidence);
	}

	return false;
}

void UPICOXRMotionTrackingFunctionLibrary::PXR_CheckMotionTrackerModeAndNumber(EPXRMotionTrackerMode trackerType, int32 TrackerNumber)
{
	PICOXRMotionTracking::CheckMotionTrackerModeAndNumber(trackerType,TrackerNumber);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerConnectState(FPXRExtDevTrackerConnectState& connectState)
{
	return PICOXRMotionTracking::GetExtDevTrackerConnectState(connectState);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerMotorVibrate(const FPXRExtDevTrackerMotorVibrate& motorVibrate)
{
	return PICOXRMotionTracking::SetExtDevTrackerMotorVibrate(motorVibrate);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerPassDataState(bool State)
{
	return PICOXRMotionTracking::SetExtDevTrackerPassDataState(State);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerByPassData(const FPXRExtDevTrackerPassData& passData)
{
	return PICOXRMotionTracking::SetExtDevTrackerByPassData(passData);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerByPassData(TArray<FPXRExtDevTrackerPassData>& PassDatas)
{
	return PICOXRMotionTracking::GetExtDevTrackerByPassData(PassDatas);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerBattery(const FString& trackerSN, int32& out_battery, int32& out_charger)
{
	return PICOXRMotionTracking::GetExtDevTrackerBattery(trackerSN,out_battery,out_charger);
}

bool UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerKeyData(const FString& trackerSN, FPXRExtDevTrackerKeyData& keyData)
{
	return PICOXRMotionTracking::GetExtDevTrackerKeyData(trackerSN,keyData);
}
