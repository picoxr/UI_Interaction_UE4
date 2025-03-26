// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_MotionTracking.h"
#include "PXR_MotionTrackingModule.h"
#include "PXR_HMDPrivate.h"
#include "PXR_HMD.h"
#include "PXR_InputFunctionLibrary.h"
#include "PXR_PluginWrapper.h"
#include "Logging/MessageLog.h"
#include "PXR_MotionTrackingUtility.h"
#include "PXR_Utils.h"
#include "PXR_Log.h"
#include "Async/Async.h"


#define LOCTEXT_NAMESPACE "PICOXRMotionTracking"

bool PICOXRMotionTracking::GetFaceTrackingSupported(bool& Supported, TArray<EPXRFaceTrackingMode>& SupportedModes)
{
	bool bResult = false;
	bool supported = false;
	int modesCount = 0;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetFaceTrackingSupported(&supported, &modesCount, nullptr));
	Supported = supported;
	if (modesCount > 0)
	{
		SupportedModes.Reset(modesCount);
		PxrFaceTrackingMode* modes = new PxrFaceTrackingMode[5];
		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetFaceTrackingSupported(&supported, &modesCount, modes));
		for (int i = 0; i < modesCount; i++)
		{
			SupportedModes.Emplace(EPXRFaceTrackingMode(modes[i]));
		}
		delete[] modes;
	}
	return bResult;
}

bool PICOXRMotionTracking::GetFaceTrackingState(bool& IsTracking, FPXRFaceTrackingState& TrackingState)
{
	bool bResult = false;
	bool isTracking = false;
	PxrFaceTrackingState state;
	state.apiVersion = PXR_FACE_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetFaceTrackingState(&isTracking, &state));
	IsTracking = isTracking;
	TrackingState.CurrentTrackingMode = EPXRFaceTrackingMode(state.currentTrackingMode);
	TrackingState.TrackingStateCode = EPXRTrackingStateCode(state.code);
	return bResult;
}

bool PICOXRMotionTracking::StartFaceTracking(const FPXRFaceTrackingStartInfo& StartInfo)
{
	bool bResult = false;
	PxrFaceTrackingStartInfo info;
	info.apiVersion = PXR_FACE_TRACKING_API_VERSION;
	info.mode = PxrFaceTrackingMode(StartInfo.StartMode);
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartFaceTracking(&info));
	return bResult;
}

bool PICOXRMotionTracking::StopFaceTracking(const FPXRFaceTrackingStopInfo& StopInfo)
{
	bool bResult = false;
	PxrFaceTrackingStopInfo info;
	info.apiVersion = PXR_FACE_TRACKING_API_VERSION;
	info.pause = StopInfo.Pause;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StopFaceTracking(&info));
	return bResult;
}

bool PICOXRMotionTracking::GetFaceTrackingData(const FPXRFaceTrackingDataGetInfo& GetInfo, FPXRFaceTrackingData& OutFaceTrackingData)
{
	bool bResult = false;

	PxrFaceTrackingDataGetInfo getInfo;
	getInfo.apiVersion = PXR_FACE_TRACKING_API_VERSION;
	getInfo.displayTime = GetInfo.DisplayTime;
	getInfo.flags = PXR_FACE_DEFAULT;

	PxrFaceTrackingData data;
	data.apiVersion = PXR_FACE_TRACKING_API_VERSION;
	data.blendShapeWeight = OutFaceTrackingData.BlendShapeWeights.GetData();

	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetFaceTrackingData1(&getInfo, &data));

	OutFaceTrackingData.TimeStamp = data.timestamp;
	OutFaceTrackingData.LaughingProb = data.laughingProb;
	OutFaceTrackingData.EyeValid = data.eyeValid;
	OutFaceTrackingData.FaceValid = data.faceValid;

	return bResult;
}

bool PICOXRMotionTracking::GetEyeTrackingSupported(bool& Supported, TArray<EPXREyeTrackingMode>& SupportedModes)
{
	bool bResult = false;
	bool supported = false;
	int modesCount = 0;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&supported, &modesCount, nullptr));
	Supported = supported;
	if (modesCount > 0)
	{
		SupportedModes.Reset(modesCount);
		PxrEyeTrackingMode* modes = new PxrEyeTrackingMode[modesCount];
		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&supported, &modesCount, modes));
		for (int i = 0; i < modesCount; i++)
		{
			SupportedModes.Emplace(EPXREyeTrackingMode(modes[i]));
		}
		delete[] modes;
	}
	return bResult;
}

bool PICOXRMotionTracking::GetEyeTrackingState(bool& IsTracking, FPXREyeTrackingState& TrackingState)
{
	bool bResult = false;
	bool isTracking = false;
	PxrEyeTrackingState state;
	state.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingState(&isTracking, &state));
	IsTracking = isTracking;
	TrackingState.CurrentTrackingMode = EPXREyeTrackingMode(state.currentTrackingMode);
	TrackingState.TrackingStateCode = EPXRTrackingStateCode(state.code);
	return bResult;
}

bool PICOXRMotionTracking::StartEyeTracking(const FPXREyeTrackingStartInfo& StartInfo)
{
	bool bResult = false;
	PxrEyeTrackingStartInfo info;
	info.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	info.mode = PxrEyeTrackingMode((int8)StartInfo.StartMode);
	info.needCalibration = StartInfo.NeedCalibration;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartEyeTracking1(&info));
	return bResult;
}

bool PICOXRMotionTracking::StopEyeTracking(const FPXREyeTrackingStopInfo& StopInfo)
{
	bool bResult = false;
	PxrEyeTrackingStopInfo info;
	info.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StopEyeTracking1(&info));
	return bResult;
}

bool PICOXRMotionTracking::GetEyeTrackingData(float WorldToMetersScale, const FPXREyeTrackingDataGetInfo& GetInfo, FPXREyeTrackingData& OutEyeTrackingData)
{
	bool bResult = false;

	PxrEyeTrackingDataGetInfo getInfo;
	getInfo.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	getInfo.displayTime = GetInfo.DisplayTime;
	getInfo.flags = PXR_EYE_DEFAULT;
	if (GetInfo.QueryOrientation) getInfo.flags |= PXR_EYE_POSITION;
	if (GetInfo.QueryPosition)	  getInfo.flags |= PXR_EYE_ORIENTATION;

	PxrEyeTrackingData1 data;
	FMemory::Memzero(&data, sizeof(data));
	data.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeTrackingData1(&getInfo, &data));
	if (bResult)
	{
		for (uint8 i = 0u; i < static_cast<uint8>(PxrPerEyeUsage::eyeCount); i++)
		{
			const auto& EyeData = data.eyeDatas[i];
			OutEyeTrackingData.PerEyeDatas[i].EyeType = (EPICOEye)i;
			OutEyeTrackingData.PerEyeDatas[i].Position = ToFVector(EyeData.pose.position) * WorldToMetersScale;
			OutEyeTrackingData.PerEyeDatas[i].Orientation = ToFQuat(EyeData.pose.orientation).Rotator();
			OutEyeTrackingData.PerEyeDatas[i].bIsPoseValid = EyeData.isPoseValid;
			OutEyeTrackingData.PerEyeDatas[i].Openness = EyeData.openness;
			OutEyeTrackingData.PerEyeDatas[i].bIsOpennessValid = EyeData.isOpennessValid;
		}
	}
	return bResult;
}

bool PICOXRMotionTracking::GetEyeOpenness(float& LeftEyeOpenness, float& RightEyeOpenness)
{
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeOpenness(&LeftEyeOpenness, &RightEyeOpenness));
	return bResult;
}

bool PICOXRMotionTracking::GetEyePupilInfo(FPXREyePupilInfo& EyePupilInfo)
{
	PxrEyePupilInfo PxrPupilInfo;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyePupilInfo(&PxrPupilInfo));
	if (bResult)
	{
		EyePupilInfo.LeftEyePupilDiameter = PxrPupilInfo.leftEyePupilDiameter;
		EyePupilInfo.LeftEyePupilPosition.X = PxrPupilInfo.leftEyePupilPosition[0];
		EyePupilInfo.LeftEyePupilPosition.Y = PxrPupilInfo.leftEyePupilPosition[1];

		EyePupilInfo.RightEyePupilDiameter = PxrPupilInfo.rightEyePupilDiameter;
		EyePupilInfo.RightEyePupilPosition.X = PxrPupilInfo.rightEyePupilPosition[0];
		EyePupilInfo.RightEyePupilPosition.Y = PxrPupilInfo.rightEyePupilPosition[1];
	}
	return bResult;
}

bool PICOXRMotionTracking::GetPerEyePose(int64& Timestamp, FTransform& LeftEyePose, FTransform& RightEyePose)
{
	int64_t PoseTimestamp = 0;
	PxrPosef Left, Right;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetPerEyePose(&PoseTimestamp, &Left, &Right));
	if (bResult)
	{
		Timestamp = static_cast<int64>(PoseTimestamp);

		LeftEyePose.SetLocation(ToFVector(Left.position));
		LeftEyePose.SetRotation(ToFQuat(Left.orientation));

		RightEyePose.SetLocation(ToFVector(Right.position));
		RightEyePose.SetRotation(ToFQuat(Right.orientation));
	}
	return bResult;
}

bool PICOXRMotionTracking::GetEyeBlink(int64& Timestamp, bool& bLeftBlink, bool& bRightBlink)
{
	int64_t BlinkTimestamp = 0;
	bool bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetEyeBlink(&BlinkTimestamp, &bLeftBlink, &bRightBlink));
	Timestamp = static_cast<int64>(BlinkTimestamp);
	return bResult;
}

bool PICOXRMotionTracking::WantBodyTrackingService()
{
	bool bResult = false;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().WantBodyTrackingService());
	return bResult;
}

bool PICOXRMotionTracking::GetBodyTrackingSupported(bool& Supported)
{
	bool bResult = false;
	bool supported = false;
	int modesCount = 0;
	Supported = supported;
	PxrBodyTrackingMode modes = PxrBodyTrackingMode::PXR_BTM_DISABLE;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetBodyTrackingSupported(&supported, &modesCount, &modes));

	return bResult;
}

bool PICOXRMotionTracking::GetBodyTrackingState(bool& IsTracking, FPXRBodyTrackingState& TrackingState)
{
	bool bResult = false;
	bool isTracking = false;
	PxrBodyTrackingState state={};
	TrackingState=FPXRBodyTrackingState();
	state.apiVersion = PXR_BODY_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetBodyTrackingState(&isTracking, &state));
	IsTracking = isTracking;
	TrackingState.CurrentTrackingMode = static_cast<EPXRBodyTrackingMode>(state.currentTrackingMode);
	TrackingState.TrackingStateCode = static_cast<EPXRTrackingStateCode>(state.code);
	TrackingState.TrackingStatusCode =static_cast<EPXRBodyTrackingStatusCode>(state.StateCode);
	TrackingState.TrackingErrorCode =static_cast<EPXRBodyTrackingErrorCode>(state.ErrorCode);
	TrackingState.ConnectedBandCount=state.connectedBandCount;
	for (int index=0;index<state.connectedBandCount;index++)
	{
		TrackingState.ConnectedFitnessBand.Add(state.fitnessBand[index]);
	}
	
	return bResult;
}

bool PICOXRMotionTracking::StartBodyTracking(const FPXRBodyTrackingStartInfo& StartInfo)
{
	bool bResult = false;
	PxrBodyTrackingStartInfo info = {};
	info.apiVersion = PXR_EYE_TRACKING_API_VERSION;
	info.mode =PxrBodyTrackingMode::PXR_BTM_WITH_SWIFT;
	info.BodyJointSet = StartInfo.OtherMode == -1 ? static_cast<int>(StartInfo.BodyTrackingMode) : StartInfo.OtherMode;
	info.BoneLength.HeadLen = StartInfo.BoneLength.headLen;
	info.BoneLength.NeckLen = StartInfo.BoneLength.neckLen;
	info.BoneLength.TorsoLen = StartInfo.BoneLength.torsoLen;
	info.BoneLength.HipLen = StartInfo.BoneLength.hipLen;
	info.BoneLength.UpperLegLen = StartInfo.BoneLength.upperLegLen;
	info.BoneLength.LowerLegLen = StartInfo.BoneLength.lowerLegLen;
	info.BoneLength.FootLen = StartInfo.BoneLength.footLen;
	info.BoneLength.ShoulderLen = StartInfo.BoneLength.shoulderLen;
	info.BoneLength.UpperArmLen = StartInfo.BoneLength.upperArmLen;
	info.BoneLength.LowerArmLen = StartInfo.BoneLength.lowerArmLen;
	info.BoneLength.HandLen = StartInfo.BoneLength.handLen;

	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartBodyTracking(&info));
	return bResult;
}

bool PICOXRMotionTracking::StopBodyTracking(const FPXRBodyTrackingStopInfo& StopInfo)
{
	bool bResult = false;
	PxrBodyTrackingStopInfo info={};
	info.apiVersion = PXR_BODY_TRACKING_API_VERSION;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StopBodyTracking(&info));
	return bResult;
}

bool PICOXRMotionTracking::GetBodyTrackingData(float WorldToMetersScale, const FPXRBodyTrackingDataGetInfo& GetInfo, FPXRBodyTrackingData& BodyTrackingData)
{
	bool bResult = false;
	if (FPICOXRVersionHelper::IsThisVersionOrGreater(0x2000308))
	{
		PxrBodyTrackingGetDataInfo getInfo = {};
		getInfo.apiVersion = PXR_BODY_TRACKING_API_VERSION;

		getInfo.displayTime = GetInfo.DisplayTime;
		uint8 GetDataMask =static_cast<uint8>(EPXRBodyTrackingGetDataFlags::PXR_BODY_NONE);
		for (int32 index = 0; index < GetInfo.DataFlags.Num(); index++)
		{
			GetDataMask |= static_cast<uint8>(GetInfo.DataFlags[index]);
			getInfo.flags =static_cast<PxrBodyTrackingGetDataFlags>(GetDataMask);
		}
		PXR_LOGV(PxrUnreal, "GetBodyTrackingData flags %d", getInfo.flags);

		PxrBodyTrackingData bodydata = {};
		FMemory::Memzero(&bodydata, sizeof(bodydata));
		bodydata.apiVersion = PXR_BODY_TRACKING_API_VERSION;
		bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetBodyTrackingData(&getInfo, &bodydata));
		PXR_LOGV(PxrUnreal, "GetBodyTrackingData bResult %d", bResult);

		if (bResult)
		{
			for (int i = 0; i < 24; i++)
			{
				FPxrBodyTrackingTransform element = FPxrBodyTrackingTransform();
				element.TimeStamp = static_cast<int64>(bodydata.roleData[i].localPose.TimeStamp);
				element.bone = static_cast<EPxrBodyTrackerRole>(i);
				element.LocalPose.SetLocation(FVector(
					-static_cast<float>(bodydata.roleData[i].localPose.PosZ) * WorldToMetersScale,
					static_cast<float>(bodydata.roleData[i].localPose.PosX) * WorldToMetersScale,
					static_cast<float>(bodydata.roleData[i].localPose.PosY) * WorldToMetersScale));
				element.LocalPose.SetRotation(FQuat(
					-static_cast<float>(bodydata.roleData[i].localPose.RotQz),
					static_cast<float>(bodydata.roleData[i].localPose.RotQx),
					static_cast<float>(bodydata.roleData[i].localPose.RotQy),
					-static_cast<float>(bodydata.roleData[i].localPose.RotQw)));
				element.GlobalPose.SetLocation(FVector(
					-static_cast<float>(bodydata.roleData[i].globalPose.PosZ) * WorldToMetersScale,
					static_cast<float>(bodydata.roleData[i].globalPose.PosX) * WorldToMetersScale,
					static_cast<float>(bodydata.roleData[i].globalPose.PosY) * WorldToMetersScale));
				element.GlobalPose.SetRotation(FQuat(
					-static_cast<float>(bodydata.roleData[i].globalPose.RotQz),
					static_cast<float>(bodydata.roleData[i].globalPose.RotQx),
					static_cast<float>(bodydata.roleData[i].globalPose.RotQy),
					-static_cast<float>(bodydata.roleData[i].globalPose.RotQw)));
				element.velo = FVector(-static_cast<float>(bodydata.roleData[i].velo[2]), static_cast<float>(bodydata.roleData[i].velo[0]), static_cast<float>(bodydata.roleData[i].velo[1]));
				element.acce = FVector(-static_cast<float>(bodydata.roleData[i].acce[2]), static_cast<float>(bodydata.roleData[i].acce[0]), static_cast<float>(bodydata.roleData[i].acce[1]));
				element.wvelo = FVector(-static_cast<float>(bodydata.roleData[i].wvelo[2]), static_cast<float>(bodydata.roleData[i].wvelo[0]), static_cast<float>(bodydata.roleData[i].wvelo[1]));
				element.wacce = FVector(-static_cast<float>(bodydata.roleData[i].wacce[2]), static_cast<float>(bodydata.roleData[i].wacce[0]), static_cast<float>(bodydata.roleData[i].wacce[1]));
				int Action = static_cast<int>(bodydata.roleData[i].bodyAction);
				if ((Action & PxrBodyActionList::PxrTouchGround) && (Action & PxrBodyActionList::PxrKeepStatic))
				{
					element.bodyAction = EPxrBodyActionList::TouchGroundAndKeepStatic;
				}
				else if (Action & PxrBodyActionList::PxrFootDownAction)
				{
					element.bodyAction = EPxrBodyActionList::FootDownAction;
				}
				else if (Action & PxrBodyActionList::PxrTouchGround)
				{
					element.bodyAction = EPxrBodyActionList::TouchGround;
				}
				else if (Action & PxrBodyActionList::PxrKeepStatic)
				{
					element.bodyAction = EPxrBodyActionList::KeepStatic;
				}
				else if (Action & PxrBodyActionList::PxrTouchGroundToe)
				{
					element.bodyAction = EPxrBodyActionList::TouchGroundToe;
				}
				else
				{
					element.bodyAction = EPxrBodyActionList::NoneAction;
				}

				BodyTrackingData.RoleDatas[i] = element;
				PXR_LOGV(PxrUnreal, "GetBodyTrackingData LocalPose index:%d:Location %s,Rotation %s", i,
				         *BodyTrackingData.RoleDatas[i].LocalPose.GetLocation().ToString(),
				         *BodyTrackingData.RoleDatas[i].LocalPose.GetRotation().ToString());

				PXR_LOGV(PxrUnreal, "GetBodyTrackingData GlobalPose index:%d:Location %s,Rotation %s", i,
				         *BodyTrackingData.RoleDatas[i].GlobalPose.GetLocation().ToString(),
				         *BodyTrackingData.RoleDatas[i].GlobalPose.GetRotation().ToString());
			}
		}
	}
	return bResult;
}

bool PICOXRMotionTracking::StartMotionTrackerCalibApp(FString CalibFlagString, int CalibMode)
{
	bool bResult = false;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().StartBodyTrackingCalibApp(TCHAR_TO_ANSI(*CalibFlagString),CalibMode));
	return bResult;
}

FString PICOXRMotionTracking::GetAndroidPackageName()
{
	FString result = FString("");
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "GetAndroidPackageName", "()Ljava/lang/String;", false);
		jstring JavaString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, Method);
		if (JavaString != NULL)
		{
			const char* JavaChars = Env->GetStringUTFChars(JavaString, 0);
			result = FString(UTF8_TO_TCHAR(JavaChars));
			Env->ReleaseStringUTFChars(JavaString, JavaChars);
			Env->DeleteLocalRef(JavaString);
		}
	}
#endif
	return result;
}

bool PICOXRMotionTracking::GetMotionTrackerConnectState(FPXRMotionConnectState& connectState)
{
	bool bResult = false;
	PxrMotionConnectState MotionConnectStat = {};
	connectState=FPXRMotionConnectState();
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetMotionTrackerConnectState(&MotionConnectStat));
	connectState.TrackerSum=MotionConnectStat.trackerSum;
	for (int index=0;index<connectState.TrackerSum;index++)
	{
		connectState.TrackersSNArray.Add(FString(UTF8_TO_TCHAR(MotionConnectStat.trackersSN[index])));
	}
	
	return bResult;
}

bool PICOXRMotionTracking::GetMotionTrackerType(EPXRMotionTrackerType& trackerType)
{
	bool bResult = false;
	PxrMotionTrackerType MotionTrackerType = {};
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetMotionTrackerType(&MotionTrackerType));
	trackerType=static_cast<EPXRMotionTrackerType>(MotionTrackerType);
	return bResult;
}

bool PICOXRMotionTracking::GetMotionTrackerMode(EPXRMotionTrackerMode& trackerMode)
{
	bool bResult = false;
	PxrMotionTrackerMode MotionTrackerMode = {};
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetMotionTrackerMode(&MotionTrackerMode));
	trackerMode=static_cast<EPXRMotionTrackerMode>(MotionTrackerMode);
	return bResult;
}

bool PICOXRMotionTracking::GetMotionTrackerLocations(float WorldToMetersScale, const FString& trackerSN, FPXRMotionTrackerLocations& locations,EPXRMotionTrackerConfidence& Confidence)
{
	bool bResult = false;
	double dPredictTime = 0;
	if (FPICOXRHMDModule::GetPluginWrapper().GetPredictedDisplayTime(&dPredictTime))
	{
		return bResult;
	}

	PxrMotionTrackerLocations MotionTrackerLocations = {};
	int32 ConfidenceInt = 0;
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetMotionTrackerLocationsWithConfidence(dPredictTime,TCHAR_TO_ANSI(*trackerSN),&MotionTrackerLocations,&ConfidenceInt));
	if (bResult)
	{
		Confidence=static_cast<EPXRMotionTrackerConfidence>(ConfidenceInt);
		locations.TrackerSN = FString(UTF8_TO_TCHAR(MotionTrackerLocations.trackerSN));
		locations.LocalPose.Pose.SetLocation(FVector(
			-static_cast<float>(MotionTrackerLocations.localPose.pose.position.z) * WorldToMetersScale,
			static_cast<float>(MotionTrackerLocations.localPose.pose.position.x) * WorldToMetersScale,
			static_cast<float>(MotionTrackerLocations.localPose.pose.position.y) * WorldToMetersScale));
		locations.LocalPose.Pose.SetRotation(FQuat(
			-static_cast<float>(MotionTrackerLocations.localPose.pose.orientation.z),
			static_cast<float>(MotionTrackerLocations.localPose.pose.orientation.x),
			static_cast<float>(MotionTrackerLocations.localPose.pose.orientation.y),
			-static_cast<float>(MotionTrackerLocations.localPose.pose.orientation.w)));
		locations.LocalPose.AngularAcceleration = FVector(-static_cast<float>(MotionTrackerLocations.localPose.angularAcceleration[2]), static_cast<float>(MotionTrackerLocations.localPose.angularAcceleration[0]), static_cast<float>(MotionTrackerLocations.localPose.angularAcceleration[1]));
		locations.LocalPose.AngularVelocity = FVector(-static_cast<float>(MotionTrackerLocations.localPose.angularVelocity[2]), static_cast<float>(MotionTrackerLocations.localPose.angularVelocity[0]), static_cast<float>(MotionTrackerLocations.localPose.angularVelocity[1]));
		locations.LocalPose.LinearAcceleration = FVector(-static_cast<float>(MotionTrackerLocations.localPose.linearAcceleration[2]), static_cast<float>(MotionTrackerLocations.localPose.linearAcceleration[0]), static_cast<float>(MotionTrackerLocations.localPose.linearAcceleration[1]));
		locations.LocalPose.LinearVelocity = FVector(-static_cast<float>(MotionTrackerLocations.localPose.linearVelocity[2]), static_cast<float>(MotionTrackerLocations.localPose.linearVelocity[0]), static_cast<float>(MotionTrackerLocations.localPose.linearVelocity[1]));
		
		locations.GlobalPose.Pose.SetLocation(FVector(
			-static_cast<float>(MotionTrackerLocations.globalPose.pose.position.z) * WorldToMetersScale,
			static_cast<float>(MotionTrackerLocations.globalPose.pose.position.x) * WorldToMetersScale,
			static_cast<float>(MotionTrackerLocations.globalPose.pose.position.y) * WorldToMetersScale));
		locations.GlobalPose.Pose.SetRotation(FQuat(
			-static_cast<float>(MotionTrackerLocations.globalPose.pose.orientation.z),
			static_cast<float>(MotionTrackerLocations.globalPose.pose.orientation.x),
			static_cast<float>(MotionTrackerLocations.globalPose.pose.orientation.y),
			-static_cast<float>(MotionTrackerLocations.globalPose.pose.orientation.w)));
		locations.GlobalPose.AngularAcceleration = FVector(-static_cast<float>(MotionTrackerLocations.globalPose.angularAcceleration[2]), static_cast<float>(MotionTrackerLocations.globalPose.angularAcceleration[0]), static_cast<float>(MotionTrackerLocations.globalPose.angularAcceleration[1]));
		locations.GlobalPose.AngularVelocity = FVector(-static_cast<float>(MotionTrackerLocations.globalPose.angularVelocity[2]), static_cast<float>(MotionTrackerLocations.globalPose.angularVelocity[0]), static_cast<float>(MotionTrackerLocations.globalPose.angularVelocity[1]));
		locations.GlobalPose.LinearAcceleration = FVector(-static_cast<float>(MotionTrackerLocations.globalPose.linearAcceleration[2]), static_cast<float>(MotionTrackerLocations.globalPose.linearAcceleration[0]), static_cast<float>(MotionTrackerLocations.globalPose.linearAcceleration[1]));
		locations.GlobalPose.LinearVelocity = FVector(-static_cast<float>(MotionTrackerLocations.globalPose.linearVelocity[2]), static_cast<float>(MotionTrackerLocations.globalPose.linearVelocity[0]), static_cast<float>(MotionTrackerLocations.globalPose.linearVelocity[1]));
		
	}

	return bResult;
}

void PICOXRMotionTracking::CheckMotionTrackerModeAndNumber(EPXRMotionTrackerMode trackerMode, int32 TrackerNumber)
{
	TrackerNumber=FMath::Clamp(TrackerNumber,0,3);
	AsyncTask(ENamedThreads::GameThread, [trackerMode, TrackerNumber]()
	{
		FPICOXRHMDModule::GetPluginWrapper().CheckMotionTrackerModeAndNumber(static_cast<PxrMotionTrackerMode>(trackerMode), TrackerNumber);
	});
}

bool PICOXRMotionTracking::GetExtDevTrackerConnectState(FPXRExtDevTrackerConnectState& connectState)
{
	bool bResult = false;

	PxrExtDevTrackerConnectState ExtDevTrackerConnectState={};
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetExtDevTrackerConnectState(&ExtDevTrackerConnectState));
	if (bResult)
	{
		connectState.ExtNumber = ExtDevTrackerConnectState.extNumber;

		for (int32 index=0;index<ExtDevTrackerConnectState.extNumber;index++)
		{
			if(connectState.ExtDevTrackerInfos.IsValidIndex(index))
			{
				connectState.ExtDevTrackerInfos[index].TrackerSN=FString(UTF8_TO_TCHAR(ExtDevTrackerConnectState.info[index].trackerSN));
				connectState.ExtDevTrackerInfos[index].batteryVolume=ExtDevTrackerConnectState.info[index].batteryVolume;
				connectState.ExtDevTrackerInfos[index].chargerStatus=ExtDevTrackerConnectState.info[index].chargerStatus;
			}
		}
	}
	return bResult;
}

bool PICOXRMotionTracking::SetExtDevTrackerMotorVibrate(const FPXRExtDevTrackerMotorVibrate& motorVibrate)
{
	bool bResult = false;
	PxrExtDevTrackerMotorVibrate ExtDevTrackerMotorVibrate={};
	FCStringAnsi::Strcpy(ExtDevTrackerMotorVibrate.trackerSN, TCHAR_TO_ANSI(*motorVibrate.TrackerSN));
	ExtDevTrackerMotorVibrate.duration=motorVibrate.Duration;
	ExtDevTrackerMotorVibrate.frequency=motorVibrate.Frequency;
	ExtDevTrackerMotorVibrate.level=motorVibrate.Level;

	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().SetExtDevTrackerMotorVibrate(&ExtDevTrackerMotorVibrate));
	
	return bResult;
}

bool PICOXRMotionTracking::SetExtDevTrackerPassDataState(bool State)
{
	bool bResult =PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().SetExtDevTrackerPassDataState(State));
	return bResult;
}

bool PICOXRMotionTracking::SetExtDevTrackerByPassData(const FPXRExtDevTrackerPassData& passData)
{
	bool bResult = false;
	PxrExtDevTrackerPassData ExtDevTrackerPassData={};
	FCStringAnsi::Strcpy(ExtDevTrackerPassData.trackerSN, TCHAR_TO_ANSI(*passData.TrackerSN));
	int32 MaxCount=FMath::Clamp(passData.PassData.Num(),0,BODY_TRACKER_EXT_PASS_DATA_MAX);
	for (int32 index=0;index<MaxCount;index++)
	{
		ExtDevTrackerPassData.passData[index]=static_cast<uint8_t>(passData.PassData[index]);
	}
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().SetExtDevTrackerByPassData(&ExtDevTrackerPassData));

	return bResult;
}

bool PICOXRMotionTracking::GetExtDevTrackerByPassData(TArray<FPXRExtDevTrackerPassData> &PassDatas)
{
	bool bResult = false;
	int32 length=6;
	int32 realLength;
	TArray<PxrExtDevTrackerPassData> TempPassDatas;
	TempPassDatas.SetNum(length);
	
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetExtDevTrackerByPassData(TempPassDatas.GetData(),length,&realLength));

	if (bResult)
	{
		for (int32 index=0;index<realLength;index++)
		{
			if (TempPassDatas.IsValidIndex(index))
			{
				FPXRExtDevTrackerPassData ExtDevTrackerPassData={};
				for (int32 index2=0;index2<BODY_TRACKER_EXT_PASS_DATA_MAX;index2++)
				{
					if (ExtDevTrackerPassData.PassData.IsValidIndex(index2))
					{
						ExtDevTrackerPassData.PassData[index2]=(TempPassDatas[index].passData[index2]);
					}
				}
				
				ExtDevTrackerPassData.TrackerSN=FString(UTF8_TO_TCHAR(TempPassDatas[index].trackerSN));

				PassDatas.Add(ExtDevTrackerPassData);
			}
		}
	}
	
	return bResult;
}

bool PICOXRMotionTracking::GetExtDevTrackerBattery(const FString& trackerSN, int32& out_battery, int32& out_charger)
{
	bool bResult = false;

	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetExtDevTrackerBattery(TCHAR_TO_ANSI(*trackerSN),&out_battery,&out_charger));

	return bResult;
}

bool PICOXRMotionTracking::GetExtDevTrackerKeyData(const FString& trackerSN, FPXRExtDevTrackerKeyData& keyData)
{
	bool bResult = false;
	PxrExtDevTrackerKeyData ExtDevTrackerKeyData={};
	bResult = PXRP_SUCCESS(FPICOXRHMDModule::GetPluginWrapper().GetExtDevTrackerKeyData(TCHAR_TO_ANSI(*trackerSN),&ExtDevTrackerKeyData));
	if (bResult)
	{
		keyData=FPXRExtDevTrackerKeyData(ExtDevTrackerKeyData);
	}
	
	return bResult;
}
