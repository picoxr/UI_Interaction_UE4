// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMotionTracking/Public/PXR_MotionTrackingFunctionLibrary.h"
#include "PICOXRMotionTracking/Public/PXR_MotionTrackingTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MotionTrackingFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_NoRegister();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXREyeTrackingMode();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceTrackingMode();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerConfidence();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerMode();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerType();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRBodyTrackingData();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRBodyTrackingDataGetInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRBodyTrackingStartInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRBodyTrackingState();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRBodyTrackingStopInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRExtDevTrackerConnectState();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRExtDevTrackerKeyData();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRExtDevTrackerMotorVibrate();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRExtDevTrackerPassData();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyePupilInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyeTrackingData();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyeTrackingDataGetInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyeTrackingStartInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyeTrackingState();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXREyeTrackingStopInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRFaceTrackingData();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRFaceTrackingDataGetInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRFaceTrackingStartInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRFaceTrackingState();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRFaceTrackingStopInfo();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRMotionConnectState();
	PICOXRMOTIONTRACKING_API UScriptStruct* Z_Construct_UScriptStruct_FPXRMotionTrackerLocations();
	UPackage* Z_Construct_UPackage__Script_PICOXRMotionTracking();
// End Cross Module References
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerKeyData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_trackerSN);
		P_GET_STRUCT_REF(FPXRExtDevTrackerKeyData,Z_Param_Out_keyData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerKeyData(Z_Param_trackerSN,Z_Param_Out_keyData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerBattery)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_trackerSN);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_out_battery);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_out_charger);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerBattery(Z_Param_trackerSN,Z_Param_Out_out_battery,Z_Param_Out_out_charger);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerByPassData)
	{
		P_GET_TARRAY_REF(FPXRExtDevTrackerPassData,Z_Param_Out_PassDatas);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerByPassData(Z_Param_Out_PassDatas);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerByPassData)
	{
		P_GET_STRUCT_REF(FPXRExtDevTrackerPassData,Z_Param_Out_passData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerByPassData(Z_Param_Out_passData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerPassDataState)
	{
		P_GET_UBOOL(Z_Param_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerPassDataState(Z_Param_State);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerMotorVibrate)
	{
		P_GET_STRUCT_REF(FPXRExtDevTrackerMotorVibrate,Z_Param_Out_motorVibrate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_SetExtDevTrackerMotorVibrate(Z_Param_Out_motorVibrate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerConnectState)
	{
		P_GET_STRUCT_REF(FPXRExtDevTrackerConnectState,Z_Param_Out_connectState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetExtDevTrackerConnectState(Z_Param_Out_connectState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_CheckMotionTrackerModeAndNumber)
	{
		P_GET_ENUM(EPXRMotionTrackerMode,Z_Param_trackerType);
		P_GET_PROPERTY(FIntProperty,Z_Param_TrackerNumber);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRMotionTrackingFunctionLibrary::PXR_CheckMotionTrackerModeAndNumber(EPXRMotionTrackerMode(Z_Param_trackerType),Z_Param_TrackerNumber);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerLocations)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMetersScale);
		P_GET_PROPERTY(FStrProperty,Z_Param_trackerSN);
		P_GET_STRUCT_REF(FPXRMotionTrackerLocations,Z_Param_Out_locations);
		P_GET_ENUM_REF(EPXRMotionTrackerConfidence,Z_Param_Out_Confidence);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerLocations(Z_Param_WorldToMetersScale,Z_Param_trackerSN,Z_Param_Out_locations,(EPXRMotionTrackerConfidence&)(Z_Param_Out_Confidence));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerMode)
	{
		P_GET_ENUM_REF(EPXRMotionTrackerMode,Z_Param_Out_trackerMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerMode((EPXRMotionTrackerMode&)(Z_Param_Out_trackerMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerDeviceType)
	{
		P_GET_ENUM_REF(EPXRMotionTrackerType,Z_Param_Out_trackerType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerDeviceType((EPXRMotionTrackerType&)(Z_Param_Out_trackerType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerConnectStateWithSN)
	{
		P_GET_STRUCT_REF(FPXRMotionConnectState,Z_Param_Out_connectState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetMotionTrackerConnectStateWithSN(Z_Param_Out_connectState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_StartMotionTrackerCalibApp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_StartMotionTrackerCalibApp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingData)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMetersScale);
		P_GET_STRUCT_REF(FPXRBodyTrackingDataGetInfo,Z_Param_Out_GetInfo);
		P_GET_STRUCT_REF(FPXRBodyTrackingData,Z_Param_Out_BodyTrackingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingData(Z_Param_WorldToMetersScale,Z_Param_Out_GetInfo,Z_Param_Out_BodyTrackingData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_StopBodyTracking)
	{
		P_GET_STRUCT_REF(FPXRBodyTrackingStopInfo,Z_Param_Out_StopInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_StopBodyTracking(Z_Param_Out_StopInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_StartBodyTracking)
	{
		P_GET_STRUCT_REF(FPXRBodyTrackingStartInfo,Z_Param_Out_StartInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_StartBodyTracking(Z_Param_Out_StartInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingState)
	{
		P_GET_UBOOL_REF(Z_Param_Out_IsTracking);
		P_GET_STRUCT_REF(FPXRBodyTrackingState,Z_Param_Out_TrackingState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingState(Z_Param_Out_IsTracking,Z_Param_Out_TrackingState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingSupported)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Supported);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_GetBodyTrackingSupported(Z_Param_Out_Supported);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execPXR_WantBodyTrackingService)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::PXR_WantBodyTrackingService();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyeBlink)
	{
		P_GET_PROPERTY_REF(FInt64Property,Z_Param_Out_Timestamp);
		P_GET_UBOOL_REF(Z_Param_Out_bLeftBlink);
		P_GET_UBOOL_REF(Z_Param_Out_bRightBlink);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyeBlink(Z_Param_Out_Timestamp,Z_Param_Out_bLeftBlink,Z_Param_Out_bRightBlink);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetPerEyePose)
	{
		P_GET_PROPERTY_REF(FInt64Property,Z_Param_Out_Timestamp);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_LeftEyePose);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_RightEyePose);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetPerEyePose(Z_Param_Out_Timestamp,Z_Param_Out_LeftEyePose,Z_Param_Out_RightEyePose);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyePupilInfo)
	{
		P_GET_STRUCT_REF(FPXREyePupilInfo,Z_Param_Out_EyePupilInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyePupilInfo(Z_Param_Out_EyePupilInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyeOpenness)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_LeftEyeOpenness);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_RightEyeOpenness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyeOpenness(Z_Param_Out_LeftEyeOpenness,Z_Param_Out_RightEyeOpenness);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingData)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMetersScale);
		P_GET_STRUCT_REF(FPXREyeTrackingDataGetInfo,Z_Param_Out_GetInfo);
		P_GET_STRUCT_REF(FPXREyeTrackingData,Z_Param_Out_OutEyeTrackingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingData(Z_Param_WorldToMetersScale,Z_Param_Out_GetInfo,Z_Param_Out_OutEyeTrackingData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execStopEyeTracking)
	{
		P_GET_STRUCT_REF(FPXREyeTrackingStopInfo,Z_Param_Out_StopInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::StopEyeTracking(Z_Param_Out_StopInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execStartEyeTracking)
	{
		P_GET_STRUCT_REF(FPXREyeTrackingStartInfo,Z_Param_Out_StartInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::StartEyeTracking(Z_Param_Out_StartInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingState)
	{
		P_GET_UBOOL_REF(Z_Param_Out_IsTracking);
		P_GET_STRUCT_REF(FPXREyeTrackingState,Z_Param_Out_TrackingState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingState(Z_Param_Out_IsTracking,Z_Param_Out_TrackingState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingSupported)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Supported);
		P_GET_TARRAY_REF(EPXREyeTrackingMode,Z_Param_Out_SupportedModes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetEyeTrackingSupported(Z_Param_Out_Supported,Z_Param_Out_SupportedModes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingData)
	{
		P_GET_STRUCT_REF(FPXRFaceTrackingDataGetInfo,Z_Param_Out_GetInfo);
		P_GET_STRUCT_REF(FPXRFaceTrackingData,Z_Param_Out_OutFaceTrackingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingData(Z_Param_Out_GetInfo,Z_Param_Out_OutFaceTrackingData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execStopFaceTracking)
	{
		P_GET_STRUCT_REF(FPXRFaceTrackingStopInfo,Z_Param_Out_StopInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::StopFaceTracking(Z_Param_Out_StopInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execStartFaceTracking)
	{
		P_GET_STRUCT_REF(FPXRFaceTrackingStartInfo,Z_Param_Out_StartInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::StartFaceTracking(Z_Param_Out_StartInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingState)
	{
		P_GET_UBOOL_REF(Z_Param_Out_IsTracking);
		P_GET_STRUCT_REF(FPXRFaceTrackingState,Z_Param_Out_TrackingState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingState(Z_Param_Out_IsTracking,Z_Param_Out_TrackingState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingSupported)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Supported);
		P_GET_TARRAY_REF(EPXRFaceTrackingMode,Z_Param_Out_SupportedModes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMotionTrackingFunctionLibrary::GetFaceTrackingSupported(Z_Param_Out_Supported,Z_Param_Out_SupportedModes);
		P_NATIVE_END;
	}
	void UPICOXRMotionTrackingFunctionLibrary::StaticRegisterNativesUPICOXRMotionTrackingFunctionLibrary()
	{
		UClass* Class = UPICOXRMotionTrackingFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetEyeBlink", &UPICOXRMotionTrackingFunctionLibrary::execGetEyeBlink },
			{ "GetEyeOpenness", &UPICOXRMotionTrackingFunctionLibrary::execGetEyeOpenness },
			{ "GetEyePupilInfo", &UPICOXRMotionTrackingFunctionLibrary::execGetEyePupilInfo },
			{ "GetEyeTrackingData", &UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingData },
			{ "GetEyeTrackingState", &UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingState },
			{ "GetEyeTrackingSupported", &UPICOXRMotionTrackingFunctionLibrary::execGetEyeTrackingSupported },
			{ "GetFaceTrackingData", &UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingData },
			{ "GetFaceTrackingState", &UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingState },
			{ "GetFaceTrackingSupported", &UPICOXRMotionTrackingFunctionLibrary::execGetFaceTrackingSupported },
			{ "GetPerEyePose", &UPICOXRMotionTrackingFunctionLibrary::execGetPerEyePose },
			{ "PXR_CheckMotionTrackerModeAndNumber", &UPICOXRMotionTrackingFunctionLibrary::execPXR_CheckMotionTrackerModeAndNumber },
			{ "PXR_GetBodyTrackingData", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingData },
			{ "PXR_GetBodyTrackingState", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingState },
			{ "PXR_GetBodyTrackingSupported", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetBodyTrackingSupported },
			{ "PXR_GetExtDevTrackerBattery", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerBattery },
			{ "PXR_GetExtDevTrackerByPassData", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerByPassData },
			{ "PXR_GetExtDevTrackerConnectState", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerConnectState },
			{ "PXR_GetExtDevTrackerKeyData", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetExtDevTrackerKeyData },
			{ "PXR_GetMotionTrackerConnectStateWithSN", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerConnectStateWithSN },
			{ "PXR_GetMotionTrackerDeviceType", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerDeviceType },
			{ "PXR_GetMotionTrackerLocations", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerLocations },
			{ "PXR_GetMotionTrackerMode", &UPICOXRMotionTrackingFunctionLibrary::execPXR_GetMotionTrackerMode },
			{ "PXR_SetExtDevTrackerByPassData", &UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerByPassData },
			{ "PXR_SetExtDevTrackerMotorVibrate", &UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerMotorVibrate },
			{ "PXR_SetExtDevTrackerPassDataState", &UPICOXRMotionTrackingFunctionLibrary::execPXR_SetExtDevTrackerPassDataState },
			{ "PXR_StartBodyTracking", &UPICOXRMotionTrackingFunctionLibrary::execPXR_StartBodyTracking },
			{ "PXR_StartMotionTrackerCalibApp", &UPICOXRMotionTrackingFunctionLibrary::execPXR_StartMotionTrackerCalibApp },
			{ "PXR_StopBodyTracking", &UPICOXRMotionTrackingFunctionLibrary::execPXR_StopBodyTracking },
			{ "PXR_WantBodyTrackingService", &UPICOXRMotionTrackingFunctionLibrary::execPXR_WantBodyTrackingService },
			{ "StartEyeTracking", &UPICOXRMotionTrackingFunctionLibrary::execStartEyeTracking },
			{ "StartFaceTracking", &UPICOXRMotionTrackingFunctionLibrary::execStartFaceTracking },
			{ "StopEyeTracking", &UPICOXRMotionTrackingFunctionLibrary::execStopEyeTracking },
			{ "StopFaceTracking", &UPICOXRMotionTrackingFunctionLibrary::execStopFaceTracking },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms
		{
			int64 Timestamp;
			bool bLeftBlink;
			bool bRightBlink;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FInt64PropertyParams NewProp_Timestamp;
		static void NewProp_bLeftBlink_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLeftBlink;
		static void NewProp_bRightBlink_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRightBlink;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms, Timestamp), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bLeftBlink_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms*)Obj)->bLeftBlink = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bLeftBlink = { "bLeftBlink", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bLeftBlink_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bRightBlink_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms*)Obj)->bRightBlink = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bRightBlink = { "bRightBlink", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bRightBlink_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_Timestamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bLeftBlink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_bRightBlink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Retrieves the eye blink information.\n/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n/// </summary>\n/// <param name=\"Timestamp\"> Int. The time at which the data was retrieved.</param>\n/// <param name=\"bLeftBlink\">Bool. Indicates whether the left eye is blinked (true) or not (false).</param>\n/// <param name=\"bRightBlink\">Bool. Indicates whether the right eye is blinked (true) or not (false).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nRetrieves the eye blink information.\n@note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n</summary>\n<param name=\"Timestamp\"> Int. The time at which the data was retrieved.</param>\n<param name=\"bLeftBlink\">Bool. Indicates whether the left eye is blinked (true) or not (false).</param>\n<param name=\"bRightBlink\">Bool. Indicates whether the right eye is blinked (true) or not (false).</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyeBlink", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeBlink_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms
		{
			float LeftEyeOpenness;
			float RightEyeOpenness;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LeftEyeOpenness;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RightEyeOpenness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_LeftEyeOpenness = { "LeftEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms, LeftEyeOpenness), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_RightEyeOpenness = { "RightEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms, RightEyeOpenness), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_LeftEyeOpenness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_RightEyeOpenness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the openness of the left and right eyes.\n/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n/// </summary>\n/// <param name=\"LeftEyeOpenness\">The openness of the left eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>\n/// <param name=\"RightEyeOpenness\">The openness of the right eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the openness of the left and right eyes.\n@note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n</summary>\n<param name=\"LeftEyeOpenness\">The openness of the left eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>\n<param name=\"RightEyeOpenness\">The openness of the right eye, which is a float value ranges from `0.0` to `1.0`. `0.0` indicates completely closed, `1.0` indicates completely open.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyeOpenness", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeOpenness_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms
		{
			FPXREyePupilInfo EyePupilInfo;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_EyePupilInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_EyePupilInfo = { "EyePupilInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms, EyePupilInfo), Z_Construct_UScriptStruct_FPXREyePupilInfo, METADATA_PARAMS(0, nullptr) }; // 1393910886
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_EyePupilInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the information about the pupils of both eyes.\n/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n/// </summary>\n/// <param name=\"EyePupilInfo\">Returns the diameters and positions of both pupils.\n/// - LeftEyePupilDiameter: Float. The left eye pupil diameter in pixels.\n///\x09- RightEyePupilDiameter: Float. The right eye pupil diameter in pixels.\n///\x09- LeftEyePupilPosition: FVector2D. The location of the left eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.\n///\x09- RightEyePupilPosition: FVector2D. The location of the right eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the information about the pupils of both eyes.\n@note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n</summary>\n<param name=\"EyePupilInfo\">Returns the diameters and positions of both pupils.\n- LeftEyePupilDiameter: Float. The left eye pupil diameter in pixels.\n      - RightEyePupilDiameter: Float. The right eye pupil diameter in pixels.\n      - LeftEyePupilPosition: FVector2D. The location of the left eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.\n      - RightEyePupilPosition: FVector2D. The location of the right eye pupil on the captured image. The image's coordinate system originates at (0,0) in the top-left corner, with the positive X-axis extending to the right and the positive Y-axis extending downward, measured in pixels.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyePupilInfo", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyePupilInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms
		{
			float WorldToMetersScale;
			FPXREyeTrackingDataGetInfo GetInfo;
			FPXREyeTrackingData OutEyeTrackingData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMetersScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GetInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GetInfo;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutEyeTrackingData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_WorldToMetersScale = { "WorldToMetersScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms, WorldToMetersScale), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_GetInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_GetInfo = { "GetInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms, GetInfo), Z_Construct_UScriptStruct_FPXREyeTrackingDataGetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_GetInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_GetInfo_MetaData) }; // 4040080207
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_OutEyeTrackingData = { "OutEyeTrackingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms, OutEyeTrackingData), Z_Construct_UScriptStruct_FPXREyeTrackingData, METADATA_PARAMS(0, nullptr) }; // 2643476094
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_WorldToMetersScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_GetInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_OutEyeTrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets eye tracking data.\n/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise. To call this API, you need to enable eye tracking first for your project.\n/// </summary>\n/// <param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n/// <param name=\"GetInfo\">Specifies the eye tracking data you want:\n/// - DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.\n/// - QueryPosition: Bool. Whether to query the position data.\n/// - QueryOrientation: Bool. Whether to query the orientation data.\n/// </param>\n/// <param name=\"OutEyeTrackingData\">Returns the desired eye tracking data. The structure containing the following details:\n/// <ul>\n/// <li>`EyeType`: EPICOEye type:\n///\x09\x09- Left: The left eye\n///\x09\x09- Right: The right eye\n///\x09\x09- Center: The midpoint between eyes\n/// </li>\n/// <li>`Position`: FVector, the current position of eyes </li>\n/// <li>`Orientation`: FRotator, the current eye gaze direction </li>\n/// <li>`bIsPoseValid`: Bool, whether the current eye's position data is valid </li>\n/// <li>`Openness`: Float, the openness data of the left eye or right eye </li>\n/// <li>`bIsOpennessValid`: Bool, whether the current eye's openness data is valid </li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets eye tracking data.\n@note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise. To call this API, you need to enable eye tracking first for your project.\n</summary>\n<param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n<param name=\"GetInfo\">Specifies the eye tracking data you want:\n- DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.\n- QueryPosition: Bool. Whether to query the position data.\n- QueryOrientation: Bool. Whether to query the orientation data.\n</param>\n<param name=\"OutEyeTrackingData\">Returns the desired eye tracking data. The structure containing the following details:\n<ul>\n<li>`EyeType`: EPICOEye type:\n              - Left: The left eye\n              - Right: The right eye\n              - Center: The midpoint between eyes\n</li>\n<li>`Position`: FVector, the current position of eyes </li>\n<li>`Orientation`: FRotator, the current eye gaze direction </li>\n<li>`bIsPoseValid`: Bool, whether the current eye's position data is valid </li>\n<li>`Openness`: Float, the openness data of the left eye or right eye </li>\n<li>`bIsOpennessValid`: Bool, whether the current eye's openness data is valid </li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
		{ "WorldToMetersScale", "100.0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyeTrackingData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms
		{
			bool IsTracking;
			FPXREyeTrackingState TrackingState;
			bool ReturnValue;
		};
		static void NewProp_IsTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTracking;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_IsTracking_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms*)Obj)->IsTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_IsTracking = { "IsTracking", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_IsTracking_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_TrackingState = { "TrackingState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms, TrackingState), Z_Construct_UScriptStruct_FPXREyeTrackingState, METADATA_PARAMS(0, nullptr) }; // 1303726738
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_IsTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_TrackingState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the state of eye tracking.\n/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"IsTracking\">Returns a bool that indicates whether eye tracking is working:\n/// * `true`: eye tracking is working\n/// * `false`: eye tracking has been stopped\n/// </param>\n/// <param name=\"TrackingState\">Returns the eye tracking state information, including:\n/// - `CurrentTrackingMode`: The EPXREyeTrackingMode enum\n/// - `TrackingStateCode`:  The EPXRTrackingStateCode enum\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the state of eye tracking.\n@note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n</summary>\n<param name=\"IsTracking\">Returns a bool that indicates whether eye tracking is working:\n* `true`: eye tracking is working\n* `false`: eye tracking has been stopped\n</param>\n<param name=\"TrackingState\">Returns the eye tracking state information, including:\n- `CurrentTrackingMode`: The EPXREyeTrackingMode enum\n- `TrackingStateCode`:  The EPXRTrackingStateCode enum\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyeTrackingState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms
		{
			bool Supported;
			TArray<EPXREyeTrackingMode> SupportedModes;
			bool ReturnValue;
		};
		static void NewProp_Supported_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Supported;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SupportedModes_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SupportedModes_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SupportedModes;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_Supported_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms*)Obj)->Supported = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_Supported = { "Supported", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_Supported_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes_Inner = { "SupportedModes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMotionTracking_EPXREyeTrackingMode, METADATA_PARAMS(0, nullptr) }; // 564402011
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes = { "SupportedModes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms, SupportedModes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 564402011
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_Supported,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_SupportedModes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets whether the current device supports eye tracking.\n/// </summary>\n/// <param name=\"Supported\">\n/// Returns a bool indicating whether eye tracking is supported:\n/// * `true`: Supported\n/// * `false`: Not supported\n/// </param>\n/// <param name=\"SupportedModes\">\n/// Returns the eye tracking modes supported by the current device:\n/// `PXR_ETM_BOTH`: The device supports tracking both eyes, namely binocular-tracking mode\n/// `PXR_ETM_NONE`: The device does not support eye tracking\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets whether the current device supports eye tracking.\n</summary>\n<param name=\"Supported\">\nReturns a bool indicating whether eye tracking is supported:\n* `true`: Supported\n* `false`: Not supported\n</param>\n<param name=\"SupportedModes\">\nReturns the eye tracking modes supported by the current device:\n`PXR_ETM_BOTH`: The device supports tracking both eyes, namely binocular-tracking mode\n`PXR_ETM_NONE`: The device does not support eye tracking\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetEyeTrackingSupported", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetEyeTrackingSupported_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms
		{
			FPXRFaceTrackingDataGetInfo GetInfo;
			FPXRFaceTrackingData OutFaceTrackingData;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GetInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GetInfo;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutFaceTrackingData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_GetInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_GetInfo = { "GetInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms, GetInfo), Z_Construct_UScriptStruct_FPXRFaceTrackingDataGetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_GetInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_GetInfo_MetaData) }; // 3202318393
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_OutFaceTrackingData = { "OutFaceTrackingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms, OutFaceTrackingData), Z_Construct_UScriptStruct_FPXRFaceTrackingData, METADATA_PARAMS(0, nullptr) }; // 3840746215
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_GetInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_OutFaceTrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|FaceTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets face tracking data.\n/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"GetInfo\">Specifies the face tracking data you want.\n/// - DisplayTime: Int. Set as the prediction time. Currently, this parameter is only supported to be set as 0.\n/// </param>\n/// <param name=\"OutFaceTrackingData\">Returns the desired face tracking data:\n/// - `BlendShapeWeights`: See the [EPXRFaceBlendShape](https://developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#ab7d460b) enum for details. \n/// - `TimeStamp`: Int. The time at which the data was retrieved.\n/// - `LaughingProb`: The probability of \"laughing,\" ranging from 0 to 1, where 0 represents no smile, and 1 represents a hearty laugh.\n/// - `EyeValid`: Indicates whether the data for the eye area is valid.\n/// - `FaceValid`: Indicates whether the data for the facial area is valid.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets face tracking data.\n@note Supported by PICO 4 Pro and PICO 4 Enterprise.\n</summary>\n<param name=\"GetInfo\">Specifies the face tracking data you want.\n- DisplayTime: Int. Set as the prediction time. Currently, this parameter is only supported to be set as 0.\n</param>\n<param name=\"OutFaceTrackingData\">Returns the desired face tracking data:\n- `BlendShapeWeights`: See the [EPXRFaceBlendShape](https:developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#ab7d460b) enum for details.\n- `TimeStamp`: Int. The time at which the data was retrieved.\n- `LaughingProb`: The probability of \"laughing,\" ranging from 0 to 1, where 0 represents no smile, and 1 represents a hearty laugh.\n- `EyeValid`: Indicates whether the data for the eye area is valid.\n- `FaceValid`: Indicates whether the data for the facial area is valid.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetFaceTrackingData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms
		{
			bool IsTracking;
			FPXRFaceTrackingState TrackingState;
			bool ReturnValue;
		};
		static void NewProp_IsTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTracking;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_IsTracking_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms*)Obj)->IsTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_IsTracking = { "IsTracking", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_IsTracking_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_TrackingState = { "TrackingState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms, TrackingState), Z_Construct_UScriptStruct_FPXRFaceTrackingState, METADATA_PARAMS(0, nullptr) }; // 2045602633
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_IsTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_TrackingState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|FaceTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the state of face tracking.\n/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"IsTracking\">Returns a bool indicating whether face tracking is working:\n/// * `true`: face tracking is working\n/// * `false`: face tracking has been stopped\n/// </param>\n/// <param name=\"TrackingState\">Returns the face tracking state information, including the face tracking mode and face tracking state code.\n/// - `CurrentTrackingMode`: EPXRFaceTrackingMode enum\n/// \x09- `PXR_FTM_NONE\x09\x09  = (uint8)-1`: Do not enable face tracking\n/// \x09- `PXR_FTM_FACE\x09\x09  = 0`: Image-driven mode\n/// \x09- `PXR_FTM_LIPS\x09\x09  = 1`: Audio-driven mode\n/// \x09- `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode\n/// \x09- `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode\n/// - `TrackingStateCode`: The [EPXRTrackingStateCode](https://developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#94bd97fa) enum\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the state of face tracking.\n@note Supported by PICO 4 Pro and PICO 4 Enterprise.\n</summary>\n<param name=\"IsTracking\">Returns a bool indicating whether face tracking is working:\n* `true`: face tracking is working\n* `false`: face tracking has been stopped\n</param>\n<param name=\"TrackingState\">Returns the face tracking state information, including the face tracking mode and face tracking state code.\n- `CurrentTrackingMode`: EPXRFaceTrackingMode enum\n      - `PXR_FTM_NONE           = (uint8)-1`: Do not enable face tracking\n      - `PXR_FTM_FACE           = 0`: Image-driven mode\n      - `PXR_FTM_LIPS           = 1`: Audio-driven mode\n      - `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode\n      - `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode\n- `TrackingStateCode`: The [EPXRTrackingStateCode](https:developer-cn.pico-interactive.com/en/document/unreal/face-tracking/#94bd97fa) enum\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetFaceTrackingState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms
		{
			bool Supported;
			TArray<EPXRFaceTrackingMode> SupportedModes;
			bool ReturnValue;
		};
		static void NewProp_Supported_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Supported;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SupportedModes_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SupportedModes_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SupportedModes;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_Supported_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms*)Obj)->Supported = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_Supported = { "Supported", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_Supported_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes_Inner = { "SupportedModes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceTrackingMode, METADATA_PARAMS(0, nullptr) }; // 3298663209
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes = { "SupportedModes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms, SupportedModes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3298663209
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_Supported,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_SupportedModes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|FaceTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets whether the current device supports face tracking.\n/// </summary>\n/// <param name=\"Supported\">Indicates whether the device supports face tracking:\n/// * `true`: Support\n/// * `false`: Not support\n/// </param>\n/// <param name=\"SupportedModes\"> The EPXRFaceTrackingMode enum. Returns the face tracking modes supported by the current device.\n/// - `PXR_FTM_NONE\x09\x09  = (uint8)-1`: Do not enable face tracking\n/// - `PXR_FTM_FACE\x09\x09  = 0`: Image-driven mode\n/// - `PXR_FTM_LIPS\x09\x09  = 1`: Audio-driven mode\n/// - `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode\n/// - `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets whether the current device supports face tracking.\n</summary>\n<param name=\"Supported\">Indicates whether the device supports face tracking:\n* `true`: Support\n* `false`: Not support\n</param>\n<param name=\"SupportedModes\"> The EPXRFaceTrackingMode enum. Returns the face tracking modes supported by the current device.\n- `PXR_FTM_NONE                 = (uint8)-1`: Do not enable face tracking\n- `PXR_FTM_FACE                 = 0`: Image-driven mode\n- `PXR_FTM_LIPS                 = 1`: Audio-driven mode\n- `PXR_FTM_FACE_LIPS_VIS = 2`: Hybrid-Viseme mode\n- `PXR_FTM_FACE_LIPS_BS  = 3`: Hybrid-Blendshape mode\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetFaceTrackingSupported", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetFaceTrackingSupported_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms
		{
			int64 Timestamp;
			FTransform LeftEyePose;
			FTransform RightEyePose;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FInt64PropertyParams NewProp_Timestamp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LeftEyePose;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RightEyePose;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms, Timestamp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_LeftEyePose = { "LeftEyePose", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms, LeftEyePose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_RightEyePose = { "RightEyePose", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms, RightEyePose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_Timestamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_LeftEyePose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_RightEyePose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Retrieves the per-eye pose information.\n/// @note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n/// </summary>\n/// <param name=\"Timestamp\">Int. The time at which the data was retrieved.</param>\n/// <param name=\"LeftEyePose\"> FTransform. Indicates the location and rotation of the left eye.</param>\n/// <param name=\"RightEyePose\">FTransform. Indicates the location and rotation of the right eye.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nRetrieves the per-eye pose information.\n@note Only supported by PICO 4 Enterprise. To use this API, you must add `<meta-data android:name=\"pvr.app.et_tob_advance\" android:value=\"true\"/>` to the AndroidManifest.xml file.\n</summary>\n<param name=\"Timestamp\">Int. The time at which the data was retrieved.</param>\n<param name=\"LeftEyePose\"> FTransform. Indicates the location and rotation of the left eye.</param>\n<param name=\"RightEyePose\">FTransform. Indicates the location and rotation of the right eye.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "GetPerEyePose", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::PICOXRMotionTrackingFunctionLibrary_eventGetPerEyePose_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_CheckMotionTrackerModeAndNumber_Parms
		{
			EPXRMotionTrackerMode trackerType;
			int32 TrackerNumber;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_trackerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_trackerType;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TrackerNumber;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_trackerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_trackerType = { "trackerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_CheckMotionTrackerModeAndNumber_Parms, trackerType), Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerMode, METADATA_PARAMS(0, nullptr) }; // 1794183127
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_TrackerNumber = { "TrackerNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_CheckMotionTrackerModeAndNumber_Parms, TrackerNumber), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_trackerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_trackerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::NewProp_TrackerNumber,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Checks the mode and number of motion tracker.\n/// </summary>\n/// <param name=\"trackerType\">Desired tracking mode:\n/// - `BODY TRACKING MODE`: Body tracking mode.\n/// - `OBJECT TRACKING MODE`: Object tracking mode.\n/// </param>\x09\n/// <param name=\"TrackerNumber\">Desired number of tracker, value range:[0,3].\n/// </param>\x09\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Checks the mode and number of motion tracker.\n</summary>\n<param name=\"trackerType\">Desired tracking mode:\n- `BODY TRACKING MODE`: Body tracking mode.\n- `OBJECT TRACKING MODE`: Object tracking mode.\n</param>\n<param name=\"TrackerNumber\">Desired number of tracker, value range:[0,3].\n</param>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_CheckMotionTrackerModeAndNumber", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_CheckMotionTrackerModeAndNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_CheckMotionTrackerModeAndNumber_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms
		{
			float WorldToMetersScale;
			FPXRBodyTrackingDataGetInfo GetInfo;
			FPXRBodyTrackingData BodyTrackingData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMetersScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GetInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GetInfo;
		static const UECodeGen_Private::FStructPropertyParams NewProp_BodyTrackingData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_WorldToMetersScale = { "WorldToMetersScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms, WorldToMetersScale), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_GetInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_GetInfo = { "GetInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms, GetInfo), Z_Construct_UScriptStruct_FPXRBodyTrackingDataGetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_GetInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_GetInfo_MetaData) }; // 1356697000
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_BodyTrackingData = { "BodyTrackingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms, BodyTrackingData), Z_Construct_UScriptStruct_FPXRBodyTrackingData, METADATA_PARAMS(0, nullptr) }; // 1974197305
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_WorldToMetersScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_GetInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_BodyTrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets body tracking data.\n/// </summary>\n/// <param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n/// <param name=\"GetInfo\">Specifies the body tracking data you want:\n/// - DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.\n/// - DataFlags: The EPXRBodyTrackingGetDataFlags enum.\n/// </param>\n/// <param name=\"BodyTrackingData\">Returns the desired body tracking data. The structure containing the following details:\n/// <ul>\n/// <li>`TimeStamp`: Int, the time at which the data was retrieved.</li>\n/// <li>`bone`: EPxrBodyTrackerRole, Bone name. If bone == NONE_ROLE, this bone is not calculated.</li>\n/// <li>`LocalPose`: FTransform, bone local transform. </li>\n/// <li>`GlobalPose`: FTransform, bone global transform.</li>\n/// <li>`velo`: FVector, velocity of x,y,z. </li>\n/// <li>`acce`: FVector, acceleration of x,y,z. </li>\n/// <li>`wvelo`: FVector, angular velocity of x,y,z. </li>\n/// <li>`wacce`: FVector, angular acceleration of x,y,z. </li>\n/// <li>`bodyAction`: EPxrBodyActionList, multiple actions can be supported at the same time by means of BodyActionList, which includes:\n/// - `NoneAction  = 0`, None action.\n/// - `TouchGround = 1`, Touch ground.\n/// - `KeepStatic  = 2`, Keep static.\n/// - `TouchGroundAndKeepStatic=3`, Touch ground and keep static.\n/// - `TouchGroundToe=4`, Touch ground toe.\n/// - `FootDownAction=5`, Foot down action.\n/// </li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets body tracking data.\n</summary>\n<param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n<param name=\"GetInfo\">Specifies the body tracking data you want:\n- DisplayTime: Int. Set as the prediction time. If DisplayTime is set to 0, the prediction time of the current frame will be used as DisplayTime.\n- DataFlags: The EPXRBodyTrackingGetDataFlags enum.\n</param>\n<param name=\"BodyTrackingData\">Returns the desired body tracking data. The structure containing the following details:\n<ul>\n<li>`TimeStamp`: Int, the time at which the data was retrieved.</li>\n<li>`bone`: EPxrBodyTrackerRole, Bone name. If bone == NONE_ROLE, this bone is not calculated.</li>\n<li>`LocalPose`: FTransform, bone local transform. </li>\n<li>`GlobalPose`: FTransform, bone global transform.</li>\n<li>`velo`: FVector, velocity of x,y,z. </li>\n<li>`acce`: FVector, acceleration of x,y,z. </li>\n<li>`wvelo`: FVector, angular velocity of x,y,z. </li>\n<li>`wacce`: FVector, angular acceleration of x,y,z. </li>\n<li>`bodyAction`: EPxrBodyActionList, multiple actions can be supported at the same time by means of BodyActionList, which includes:\n- `NoneAction  = 0`, None action.\n- `TouchGround = 1`, Touch ground.\n- `KeepStatic  = 2`, Keep static.\n- `TouchGroundAndKeepStatic=3`, Touch ground and keep static.\n- `TouchGroundToe=4`, Touch ground toe.\n- `FootDownAction=5`, Foot down action.\n</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
		{ "WorldToMetersScale", "100.0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetBodyTrackingData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms
		{
			bool IsTracking;
			FPXRBodyTrackingState TrackingState;
			bool ReturnValue;
		};
		static void NewProp_IsTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTracking;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_IsTracking_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms*)Obj)->IsTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_IsTracking = { "IsTracking", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_IsTracking_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_TrackingState = { "TrackingState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms, TrackingState), Z_Construct_UScriptStruct_FPXRBodyTrackingState, METADATA_PARAMS(0, nullptr) }; // 769747571
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_IsTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_TrackingState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the state of body tracking.\n/// </summary>\n/// <param name=\"IsTracking\">Returns a bool that indicates whether body tracking is working:\n/// * `true`: Body tracking is working.\n/// * `false`: Body tracking has been stopped.\n/// </param>\n/// <param name=\"TrackingState\">Returns the body tracking state information, including:\n/// - `CurrentTrackingMode`: The EPXRBodyTrackingMode enum.\n/// - `TrackingStateCode`:  The EPXRTrackingStateCode enum.\n/// - `TrackingStatusCode`: The EPXRBodyTrackingStatusCode enum.\n/// - `TrackingErrorCode`: The EPXRBodyTrackingErrorCode enum.\n/// - `Connected Band Count`: Connected count of bands.\n/// - `Connected Fitness Band`: Array of connected bands.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the state of body tracking.\n</summary>\n<param name=\"IsTracking\">Returns a bool that indicates whether body tracking is working:\n* `true`: Body tracking is working.\n* `false`: Body tracking has been stopped.\n</param>\n<param name=\"TrackingState\">Returns the body tracking state information, including:\n- `CurrentTrackingMode`: The EPXRBodyTrackingMode enum.\n- `TrackingStateCode`:  The EPXRTrackingStateCode enum.\n- `TrackingStatusCode`: The EPXRBodyTrackingStatusCode enum.\n- `TrackingErrorCode`: The EPXRBodyTrackingErrorCode enum.\n- `Connected Band Count`: Connected count of bands.\n- `Connected Fitness Band`: Array of connected bands.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetBodyTrackingState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms
		{
			bool Supported;
			bool ReturnValue;
		};
		static void NewProp_Supported_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Supported;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_Supported_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms*)Obj)->Supported = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_Supported = { "Supported", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_Supported_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_Supported,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets whether the current device supports body tracking.\n/// </summary>\n/// <param name=\"Supported\">\n/// Returns a bool indicating whether body tracking is supported:\n/// * `true`: Supported\n/// * `false`: Not supported\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets whether the current device supports body tracking.\n</summary>\n<param name=\"Supported\">\nReturns a bool indicating whether body tracking is supported:\n* `true`: Supported\n* `false`: Not supported\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetBodyTrackingSupported", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetBodyTrackingSupported_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms
		{
			FString trackerSN;
			int32 out_battery;
			int32 out_charger;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_trackerSN;
		static const UECodeGen_Private::FIntPropertyParams NewProp_out_battery;
		static const UECodeGen_Private::FIntPropertyParams NewProp_out_charger;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_trackerSN_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_trackerSN = { "trackerSN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms, trackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_trackerSN_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_trackerSN_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_out_battery = { "out_battery", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms, out_battery), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_out_charger = { "out_charger", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms, out_charger), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_trackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_out_battery,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_out_charger,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the externally developed trackers' battery.\n/// </summary>\n/// <param name=\"trackerSN\">SN of externally developed trackers.</param>\n/// <param name=\"out_battery\">Battery of externally developed trackers, value range: [0-10]</param>\n/// <param name=\"0ut_charger\">Whether the tracker is on charging, `0` for not on charging, `1` for on charging.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the externally developed trackers' battery.\n</summary>\n<param name=\"trackerSN\">SN of externally developed trackers.</param>\n<param name=\"out_battery\">Battery of externally developed trackers, value range: [0-10]</param>\n<param name=\"0ut_charger\">Whether the tracker is on charging, `0` for not on charging, `1` for on charging.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetExtDevTrackerBattery", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerBattery_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms
		{
			TArray<FPXRExtDevTrackerPassData> PassDatas;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_PassDatas_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PassDatas;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_PassDatas_Inner = { "PassDatas", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPXRExtDevTrackerPassData, METADATA_PARAMS(0, nullptr) }; // 2817247323
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_PassDatas = { "PassDatas", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms, PassDatas), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2817247323
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_PassDatas_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_PassDatas,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the externally developed trackers by pass data.\n/// </summary>\n/// <param name=\"PassDatas\">Array of pass data, includes:\n///\x09- `Tracker SN`: SN of externally developed trackers.\n/// - `PassData`: Currently valid pass data array.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the externally developed trackers by pass data.\n</summary>\n<param name=\"PassDatas\">Array of pass data, includes:\n      - `Tracker SN`: SN of externally developed trackers.\n- `PassData`: Currently valid pass data array.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetExtDevTrackerByPassData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerByPassData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms
		{
			FPXRExtDevTrackerConnectState connectState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_connectState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_connectState = { "connectState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms, connectState), Z_Construct_UScriptStruct_FPXRExtDevTrackerConnectState, METADATA_PARAMS(0, nullptr) }; // 1166474629
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_connectState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the connect state of externally developed trackers.\n/// </summary>\n/// <param name=\"connectState\">The connect state of externally developed trackers, which includes:\n/// - `Ext Number`: Connected number of externally developed trackers.\n/// - `ExDevTrackerInfos`: Infomation on externally developed trackers, which includes:\n///   - `Tracker SN`: SN of externally developed trackers.\n///   - `Charger Status`: The charger status, `0` represents in charging, `1` reresents not in charging.\n///   - `Battery Volume`: Battery volume of externally developed trackers, value range:[0,10].\n/// </param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the connect state of externally developed trackers.\n</summary>\n<param name=\"connectState\">The connect state of externally developed trackers, which includes:\n- `Ext Number`: Connected number of externally developed trackers.\n- `ExDevTrackerInfos`: Infomation on externally developed trackers, which includes:\n  - `Tracker SN`: SN of externally developed trackers.\n  - `Charger Status`: The charger status, `0` represents in charging, `1` reresents not in charging.\n  - `Battery Volume`: Battery volume of externally developed trackers, value range:[0,10].\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetExtDevTrackerConnectState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerConnectState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms
		{
			FString trackerSN;
			FPXRExtDevTrackerKeyData keyData;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_trackerSN;
		static const UECodeGen_Private::FStructPropertyParams NewProp_keyData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_trackerSN_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_trackerSN = { "trackerSN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms, trackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_trackerSN_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_trackerSN_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_keyData = { "keyData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms, keyData), Z_Construct_UScriptStruct_FPXRExtDevTrackerKeyData, METADATA_PARAMS(0, nullptr) }; // 268589573
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_trackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_keyData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the key data of externally developed trackers.\n/// </summary>\n/// <param name=\"trackerSN\">SN of externally developed trackers.</param>\n/// <param name=\"KeyData\"> Key data of the trackers including:\n/// - `Ext Dev ID`: ID of the externally developed tracker.\n/// - `key`: `0` for not pressed, `1` for pressed.\n/// - `touch`: `0` for not pressed, `1` for pressed.\n/// - `Trigger`: Value range:[0,255].\n/// - `Grip`: Value range:[0,255].\n/// - `Rocker_x`: Value range:[0,255].\x09\n/// - `TRocker_y`: Value range:[0,255].\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the key data of externally developed trackers.\n</summary>\n<param name=\"trackerSN\">SN of externally developed trackers.</param>\n<param name=\"KeyData\"> Key data of the trackers including:\n- `Ext Dev ID`: ID of the externally developed tracker.\n- `key`: `0` for not pressed, `1` for pressed.\n- `touch`: `0` for not pressed, `1` for pressed.\n- `Trigger`: Value range:[0,255].\n- `Grip`: Value range:[0,255].\n- `Rocker_x`: Value range:[0,255].\n- `TRocker_y`: Value range:[0,255].\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetExtDevTrackerKeyData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetExtDevTrackerKeyData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms
		{
			FPXRMotionConnectState connectState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_connectState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_connectState = { "connectState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms, connectState), Z_Construct_UScriptStruct_FPXRMotionConnectState, METADATA_PARAMS(0, nullptr) }; // 3552028209
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_connectState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the connect state of motion tracker.\n/// </summary>\n/// <param name=\"connectState\">Connect state of the motion tracker, which includes:\n/// - `Tracker Sum`: The count of trackers.\n/// - `Trackers SN Array`: The array of trackers' SN.\n/// </param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the connect state of motion tracker.\n</summary>\n<param name=\"connectState\">Connect state of the motion tracker, which includes:\n- `Tracker Sum`: The count of trackers.\n- `Trackers SN Array`: The array of trackers' SN.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetMotionTrackerConnectStateWithSN", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithSN_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms
		{
			EPXRMotionTrackerType trackerType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_trackerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_trackerType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_trackerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_trackerType = { "trackerType", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms, trackerType), Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerType, METADATA_PARAMS(0, nullptr) }; // 1289755175
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_trackerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_trackerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the device type of motion tracker.\n/// </summary>\n/// <param name=\"trackerType\">Device type of the motion tracker, which includes:\n/// - `PICO MOTION TRACKER 1.0`: Motion Tracker 1.0.\n/// - `PICO MOTION TRACKER 2.0`: Motion Tracker 2.0.\n/// </param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the device type of motion tracker.\n</summary>\n<param name=\"trackerType\">Device type of the motion tracker, which includes:\n- `PICO MOTION TRACKER 1.0`: Motion Tracker 1.0.\n- `PICO MOTION TRACKER 2.0`: Motion Tracker 2.0.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetMotionTrackerDeviceType", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerDeviceType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms
		{
			float WorldToMetersScale;
			FString trackerSN;
			FPXRMotionTrackerLocations locations;
			EPXRMotionTrackerConfidence Confidence;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMetersScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_trackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_trackerSN;
		static const UECodeGen_Private::FStructPropertyParams NewProp_locations;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Confidence_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Confidence;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_WorldToMetersScale = { "WorldToMetersScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms, WorldToMetersScale), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_trackerSN_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_trackerSN = { "trackerSN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms, trackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_trackerSN_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_trackerSN_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_locations = { "locations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms, locations), Z_Construct_UScriptStruct_FPXRMotionTrackerLocations, METADATA_PARAMS(0, nullptr) }; // 2465761200
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_Confidence_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_Confidence = { "Confidence", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms, Confidence), Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerConfidence, METADATA_PARAMS(0, nullptr) }; // 2999187377
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_WorldToMetersScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_trackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_Confidence_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_Confidence,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the location of motion tracker.\n/// </summary>\n/// <param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n/// <param name=\"trackerSN\"> The array of trackers' SN.</param>\n/// <param name=\"locations\">SN location data, which includes:\n/// - TrackerSN: Int. SN of the Tracker corresponding to the data.\n/// - Local Pose: Same frame pose as HMD.\n/// - Global Pose: Pose in the global reference frame of the system. It is not recommended to use without special requirements.\n/// </param>\n/// <param name=\"Confidence\"> The EPXRMotionTrackerConfidence enum:\n/// - `PXR_STATIC_ACCURATE = 0 UMETA`: Static, accurate tracking.\n/// - `PXR_6DOF_ACCURATE = 1 UMETA`: 6DoF data, tracking accurate.\n/// - `PXR_3DOF_NOT_ACCURATE = 2 UMETA`: 3DoF data, tracking is not accurate.\n/// - `PXR_6DOF_NOT_ACCURATE = 3 UMETA`: 6DoF data, tracking is not accurate.\n/// </param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the location of motion tracker.\n</summary>\n<param name=\"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 100 by default. </param>\n<param name=\"trackerSN\"> The array of trackers' SN.</param>\n<param name=\"locations\">SN location data, which includes:\n- TrackerSN: Int. SN of the Tracker corresponding to the data.\n- Local Pose: Same frame pose as HMD.\n- Global Pose: Pose in the global reference frame of the system. It is not recommended to use without special requirements.\n</param>\n<param name=\"Confidence\"> The EPXRMotionTrackerConfidence enum:\n- `PXR_STATIC_ACCURATE = 0 UMETA`: Static, accurate tracking.\n- `PXR_6DOF_ACCURATE = 1 UMETA`: 6DoF data, tracking accurate.\n- `PXR_3DOF_NOT_ACCURATE = 2 UMETA`: 3DoF data, tracking is not accurate.\n- `PXR_6DOF_NOT_ACCURATE = 3 UMETA`: 6DoF data, tracking is not accurate.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
		{ "WorldToMetersScale", "100.0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetMotionTrackerLocations", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerLocations_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms
		{
			EPXRMotionTrackerMode trackerMode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_trackerMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_trackerMode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_trackerMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_trackerMode = { "trackerMode", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms, trackerMode), Z_Construct_UEnum_PICOXRMotionTracking_EPXRMotionTrackerMode, METADATA_PARAMS(0, nullptr) }; // 1794183127
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_trackerMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_trackerMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the mode of motion tracker.\n/// </summary>\n/// <param name=\"trackerMode\">Mode of the motion tracker, which includes:\n/// - `BODY TRACKING MODE`: Body tracking mode.\n/// - `OBJECT TRACKING MODE`: Object tracking mode.\n/// </param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the mode of motion tracker.\n</summary>\n<param name=\"trackerMode\">Mode of the motion tracker, which includes:\n- `BODY TRACKING MODE`: Body tracking mode.\n- `OBJECT TRACKING MODE`: Object tracking mode.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_GetMotionTrackerMode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_GetMotionTrackerMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms
		{
			FPXRExtDevTrackerPassData passData;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_passData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_passData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_passData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_passData = { "passData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms, passData), Z_Construct_UScriptStruct_FPXRExtDevTrackerPassData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_passData_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_passData_MetaData) }; // 2817247323
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_passData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the externally developed trackers by pass data.\n/// </summary>\n/// <param name=\"passData\">Array of pass data, includes:\n///\x09- `Tracker SN`: SN of externally developed trackers.\n/// - `PassData`: Currently valid pass data array.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the externally developed trackers by pass data.\n</summary>\n<param name=\"passData\">Array of pass data, includes:\n      - `Tracker SN`: SN of externally developed trackers.\n- `PassData`: Currently valid pass data array.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_SetExtDevTrackerByPassData", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerByPassData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms
		{
			FPXRExtDevTrackerMotorVibrate motorVibrate;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_motorVibrate_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_motorVibrate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_motorVibrate_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_motorVibrate = { "motorVibrate", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms, motorVibrate), Z_Construct_UScriptStruct_FPXRExtDevTrackerMotorVibrate, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_motorVibrate_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_motorVibrate_MetaData) }; // 1464789446
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_motorVibrate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the viberation of externally developed trackers.\n/// </summary>\n/// <param name=\"motorViberate\">Spread spectrum vibration, the parameter includes:\n///\x09- `Tracker SN`: SN of externally developed trackers.\n/// - `Level`: Motor vibration intensity, stop vibrating if the value is `0`,value range:[0,255].\n/// - `Frequency`: Motor viberation frequency, value range:(40,500).\n/// - `Duration`: Motor vibration time, unit ms, when the value is `-999`, it means that the vibration is constant.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the viberation of externally developed trackers.\n</summary>\n<param name=\"motorViberate\">Spread spectrum vibration, the parameter includes:\n      - `Tracker SN`: SN of externally developed trackers.\n- `Level`: Motor vibration intensity, stop vibrating if the value is `0`,value range:[0,255].\n- `Frequency`: Motor viberation frequency, value range:(40,500).\n- `Duration`: Motor vibration time, unit ms, when the value is `-999`, it means that the vibration is constant.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_SetExtDevTrackerMotorVibrate", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerMotorVibrate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms
		{
			bool State;
			bool ReturnValue;
		};
		static void NewProp_State_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_State;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_State_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms*)Obj)->State = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_State_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MotionTracker" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the pass data state of externally developed trackers.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: enable the pass data</li>\n/// <li>`false`: pass data closed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the pass data state of externally developed trackers.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true`: enable the pass data</li>\n<li>`false`: pass data closed</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_SetExtDevTrackerPassDataState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_SetExtDevTrackerPassDataState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms
		{
			FPXRBodyTrackingStartInfo StartInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StartInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_StartInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_StartInfo = { "StartInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms, StartInfo), Z_Construct_UScriptStruct_FPXRBodyTrackingStartInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_StartInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_StartInfo_MetaData) }; // 452768118
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_StartInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Starts body tracking.\n/// </summary>\n/// <param name=\"StartInfo\">Passes the information for starting body tracking.\n/// - `Body Tracking Mode`: The EBodyTrackingMode enum.\n/// - `Bone Length`: Specifies bone length.\n/// - `Other Mode`: The default value is `-1`, it is reserved for special requirements. Currently, you do not need to pass anything.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStarts body tracking.\n</summary>\n<param name=\"StartInfo\">Passes the information for starting body tracking.\n- `Body Tracking Mode`: The EBodyTrackingMode enum.\n- `Bone Length`: Specifies bone length.\n- `Other Mode`: The default value is `-1`, it is reserved for special requirements. Currently, you do not need to pass anything.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_StartBodyTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StartBodyTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_StartMotionTrackerCalibApp_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_StartMotionTrackerCalibApp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_StartMotionTrackerCalibApp_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Starts motion tracker calibration app.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Starts motion tracker calibration app.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_StartMotionTrackerCalibApp", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StartMotionTrackerCalibApp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StartMotionTrackerCalibApp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms
		{
			FPXRBodyTrackingStopInfo StopInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StopInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StopInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_StopInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_StopInfo = { "StopInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms, StopInfo), Z_Construct_UScriptStruct_FPXRBodyTrackingStopInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_StopInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_StopInfo_MetaData) }; // 1025616829
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_StopInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Stops body tracking.\n/// </summary>\n/// <param name=\"StopInfo\">Passes the information for stopping body tracking. Currently, you do not need to pass anything.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStops body tracking.\n</summary>\n<param name=\"StopInfo\">Passes the information for stopping body tracking. Currently, you do not need to pass anything.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_StopBodyTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_StopBodyTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventPXR_WantBodyTrackingService_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventPXR_WantBodyTrackingService_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventPXR_WantBodyTrackingService_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|BodyTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Starts the motion tracking service.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStarts the motion tracking service.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "PXR_WantBodyTrackingService", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_WantBodyTrackingService_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::PICOXRMotionTrackingFunctionLibrary_eventPXR_WantBodyTrackingService_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms
		{
			FPXREyeTrackingStartInfo StartInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StartInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_StartInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_StartInfo = { "StartInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms, StartInfo), Z_Construct_UScriptStruct_FPXREyeTrackingStartInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_StartInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_StartInfo_MetaData) }; // 931861307
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_StartInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Starts eye tracking.\n/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"StartInfo\">Passes the information for starting eye tracking.\n/// - `NeedCalibration`: Whether your app needs eye tracking calibration\n/// - `StartMode`: EPXREyeTrackingMode enum\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStarts eye tracking.\n@note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n</summary>\n<param name=\"StartInfo\">Passes the information for starting eye tracking.\n- `NeedCalibration`: Whether your app needs eye tracking calibration\n- `StartMode`: EPXREyeTrackingMode enum\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "StartEyeTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStartEyeTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms
		{
			FPXRFaceTrackingStartInfo StartInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StartInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_StartInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_StartInfo = { "StartInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms, StartInfo), Z_Construct_UScriptStruct_FPXRFaceTrackingStartInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_StartInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_StartInfo_MetaData) }; // 208652474
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_StartInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|FaceTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Starts face tracking.\n/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"StartInfo\">Passes the information for starting face tracking. Here you need to choose the face tracking mode. For details, see the above EPXRFaceTrackingMode enum.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStarts face tracking.\n@note Supported by PICO 4 Pro and PICO 4 Enterprise.\n</summary>\n<param name=\"StartInfo\">Passes the information for starting face tracking. Here you need to choose the face tracking mode. For details, see the above EPXRFaceTrackingMode enum.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "StartFaceTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStartFaceTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms
		{
			FPXREyeTrackingStopInfo StopInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StopInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StopInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_StopInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_StopInfo = { "StopInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms, StopInfo), Z_Construct_UScriptStruct_FPXREyeTrackingStopInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_StopInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_StopInfo_MetaData) }; // 3988949509
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_StopInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Stops eye tracking.\n/// @note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"StopInfo\">Passes the information for stopping eye tracking. Currently, you do not need to pass anything.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStops eye tracking.\n@note Supported by PICO Neo3 Pro Eye, PICO 4 Pro, and PICO 4 Enterprise.\n</summary>\n<param name=\"StopInfo\">Passes the information for stopping eye tracking. Currently, you do not need to pass anything.</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "StopEyeTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStopEyeTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics
	{
		struct PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms
		{
			FPXRFaceTrackingStopInfo StopInfo;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StopInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_StopInfo;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_StopInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_StopInfo = { "StopInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms, StopInfo), Z_Construct_UScriptStruct_FPXRFaceTrackingStopInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_StopInfo_MetaData), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_StopInfo_MetaData) }; // 4241565064
	void Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms), &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_StopInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|FaceTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Stops face tracking.\n/// @note Supported by PICO 4 Pro and PICO 4 Enterprise.\n/// </summary>\n/// <param name=\"StopInfo\">Passes the information for stopping face tracking:\n/// `Pause`: Bool. `true` indicates pausing face tracking and `false` indicates directly stopping face tracking.\n/// If you need to switch the face-tracking mode, you can set `Pause` to true and then call `StartFaceTracking` to select another mode, instead of completely stop it.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStops face tracking.\n@note Supported by PICO 4 Pro and PICO 4 Enterprise.\n</summary>\n<param name=\"StopInfo\">Passes the information for stopping face tracking:\n`Pause`: Bool. `true` indicates pausing face tracking and `false` indicates directly stopping face tracking.\nIf you need to switch the face-tracking mode, you can set `Pause` to true and then call `StartFaceTracking` to select another mode, instead of completely stop it.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, nullptr, "StopFaceTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::PICOXRMotionTrackingFunctionLibrary_eventStopFaceTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRMotionTrackingFunctionLibrary);
	UClass* Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_NoRegister()
	{
		return UPICOXRMotionTrackingFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMotionTracking,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeBlink, "GetEyeBlink" }, // 3768283028
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeOpenness, "GetEyeOpenness" }, // 3615275525
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyePupilInfo, "GetEyePupilInfo" }, // 3417238383
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingData, "GetEyeTrackingData" }, // 2808482130
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingState, "GetEyeTrackingState" }, // 4012104850
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetEyeTrackingSupported, "GetEyeTrackingSupported" }, // 3662806981
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingData, "GetFaceTrackingData" }, // 4195780921
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingState, "GetFaceTrackingState" }, // 242734712
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetFaceTrackingSupported, "GetFaceTrackingSupported" }, // 2855194873
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_GetPerEyePose, "GetPerEyePose" }, // 3822371766
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_CheckMotionTrackerModeAndNumber, "PXR_CheckMotionTrackerModeAndNumber" }, // 1217843948
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingData, "PXR_GetBodyTrackingData" }, // 3831977730
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingState, "PXR_GetBodyTrackingState" }, // 2447601286
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetBodyTrackingSupported, "PXR_GetBodyTrackingSupported" }, // 2785421816
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerBattery, "PXR_GetExtDevTrackerBattery" }, // 3626310630
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerByPassData, "PXR_GetExtDevTrackerByPassData" }, // 475133196
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerConnectState, "PXR_GetExtDevTrackerConnectState" }, // 2814129958
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetExtDevTrackerKeyData, "PXR_GetExtDevTrackerKeyData" }, // 3041037659
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerConnectStateWithSN, "PXR_GetMotionTrackerConnectStateWithSN" }, // 1556665351
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerDeviceType, "PXR_GetMotionTrackerDeviceType" }, // 3861238832
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerLocations, "PXR_GetMotionTrackerLocations" }, // 2718725740
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_GetMotionTrackerMode, "PXR_GetMotionTrackerMode" }, // 1362124418
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerByPassData, "PXR_SetExtDevTrackerByPassData" }, // 1883652697
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerMotorVibrate, "PXR_SetExtDevTrackerMotorVibrate" }, // 319863549
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_SetExtDevTrackerPassDataState, "PXR_SetExtDevTrackerPassDataState" }, // 2767798745
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartBodyTracking, "PXR_StartBodyTracking" }, // 3485672295
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StartMotionTrackerCalibApp, "PXR_StartMotionTrackerCalibApp" }, // 2241217400
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_StopBodyTracking, "PXR_StopBodyTracking" }, // 3221556067
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_PXR_WantBodyTrackingService, "PXR_WantBodyTrackingService" }, // 871828363
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartEyeTracking, "StartEyeTracking" }, // 2439257219
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StartFaceTracking, "StartFaceTracking" }, // 3846816181
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopEyeTracking, "StopEyeTracking" }, // 3925202348
		{ &Z_Construct_UFunction_UPICOXRMotionTrackingFunctionLibrary_StopFaceTracking, "StopFaceTracking" }, // 2866519591
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_MotionTrackingFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_MotionTrackingFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRMotionTrackingFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::ClassParams = {
		&UPICOXRMotionTrackingFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UPICOXRMotionTrackingFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRMotionTrackingFunctionLibrary.OuterSingleton, Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRMotionTrackingFunctionLibrary.OuterSingleton;
	}
	template<> PICOXRMOTIONTRACKING_API UClass* StaticClass<UPICOXRMotionTrackingFunctionLibrary>()
	{
		return UPICOXRMotionTrackingFunctionLibrary::StaticClass();
	}
	UPICOXRMotionTrackingFunctionLibrary::UPICOXRMotionTrackingFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRMotionTrackingFunctionLibrary);
	UPICOXRMotionTrackingFunctionLibrary::~UPICOXRMotionTrackingFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary, UPICOXRMotionTrackingFunctionLibrary::StaticClass, TEXT("UPICOXRMotionTrackingFunctionLibrary"), &Z_Registration_Info_UClass_UPICOXRMotionTrackingFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRMotionTrackingFunctionLibrary), 3994732001U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_631649836(TEXT("/Script/PICOXRMotionTracking"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
