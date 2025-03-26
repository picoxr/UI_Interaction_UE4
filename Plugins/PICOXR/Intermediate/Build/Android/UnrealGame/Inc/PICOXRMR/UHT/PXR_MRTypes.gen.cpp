// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMR/Public/PXR_MRTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MRTypes() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOResult();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSceneType();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FAnchorLoadResult();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FFutureMessage();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorLoadInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox2D();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox3D();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOExtent2Df();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOExtent3Df();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOMRSceneInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSceneLoadInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialHandle();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialMeshInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialUUID();
	UPackage* Z_Construct_UPackage__Script_PICOXRMR();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOResult;
	static UEnum* EPICOResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOResult, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOResult"));
		}
		return Z_Registration_Info_UEnum_EPICOResult.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOResult>()
	{
		return EPICOResult_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enumerators[] = {
		{ "EPICOResult::PXR_Success", (int64)EPICOResult::PXR_Success },
		{ "EPICOResult::PXR_TimeoutExpired", (int64)EPICOResult::PXR_TimeoutExpired },
		{ "EPICOResult::PXR_Spatial_Mesh_Data_No_Update", (int64)EPICOResult::PXR_Spatial_Mesh_Data_No_Update },
		{ "EPICOResult::PXR_Scene_Capture_Process_Successful", (int64)EPICOResult::PXR_Scene_Capture_Process_Successful },
		{ "EPICOResult::PXR_Error_Spatial_Mesh_Volumes_Update_Failed", (int64)EPICOResult::PXR_Error_Spatial_Mesh_Volumes_Update_Failed },
		{ "EPICOResult::PXR_Error_ValidationFailure", (int64)EPICOResult::PXR_Error_ValidationFailure },
		{ "EPICOResult::PXR_Error_RuntimeFailure", (int64)EPICOResult::PXR_Error_RuntimeFailure },
		{ "EPICOResult::PXR_Error_OutOfMemory", (int64)EPICOResult::PXR_Error_OutOfMemory },
		{ "EPICOResult::PXR_Error_APIVersionUnsupported", (int64)EPICOResult::PXR_Error_APIVersionUnsupported },
		{ "EPICOResult::PXR_Error_InitializationFailed", (int64)EPICOResult::PXR_Error_InitializationFailed },
		{ "EPICOResult::PXR_Error_FunctionUnsupported", (int64)EPICOResult::PXR_Error_FunctionUnsupported },
		{ "EPICOResult::PXR_Error_FeatureUnsupported", (int64)EPICOResult::PXR_Error_FeatureUnsupported },
		{ "EPICOResult::PXR_Error_LimitReached", (int64)EPICOResult::PXR_Error_LimitReached },
		{ "EPICOResult::PXR_Error_SizeInsufficient", (int64)EPICOResult::PXR_Error_SizeInsufficient },
		{ "EPICOResult::PXR_Error_HandleInvalid", (int64)EPICOResult::PXR_Error_HandleInvalid },
		{ "EPICOResult::PXR_Error_Pose_Invalid", (int64)EPICOResult::PXR_Error_Pose_Invalid },
		{ "EPICOResult::PXR_Error_SpatialLocalizationRunning", (int64)EPICOResult::PXR_Error_SpatialLocalizationRunning },
		{ "EPICOResult::PXR_Error_SpatialLocalizationNotRunning", (int64)EPICOResult::PXR_Error_SpatialLocalizationNotRunning },
		{ "EPICOResult::PXR_Error_SpatialMapCreated", (int64)EPICOResult::PXR_Error_SpatialMapCreated },
		{ "EPICOResult::PXR_Error_SpatialMapNotCreated", (int64)EPICOResult::PXR_Error_SpatialMapNotCreated },
		{ "EPICOResult::PXR_Error_SpatialSensingServiceUnavailable", (int64)EPICOResult::PXR_Error_SpatialSensingServiceUnavailable },
		{ "EPICOResult::PXR_Error_ComponentNotSupported", (int64)EPICOResult::PXR_Error_ComponentNotSupported },
		{ "EPICOResult::PXR_Error_ComponentConflict", (int64)EPICOResult::PXR_Error_ComponentConflict },
		{ "EPICOResult::PXR_Error_ComponentNotAdded", (int64)EPICOResult::PXR_Error_ComponentNotAdded },
		{ "EPICOResult::PXR_Error_ComponentAdded", (int64)EPICOResult::PXR_Error_ComponentAdded },
		{ "EPICOResult::PXR_Error_AnchorEntityNotFound", (int64)EPICOResult::PXR_Error_AnchorEntityNotFound },
		{ "EPICOResult::PXR_Error_Tracking_State_Invalid", (int64)EPICOResult::PXR_Error_Tracking_State_Invalid },
		{ "EPICOResult::PXR_Error_Space_Locating", (int64)EPICOResult::PXR_Error_Space_Locating },
		{ "EPICOResult::PXR_Error_Anchor_Sharing_Network_Timeout", (int64)EPICOResult::PXR_Error_Anchor_Sharing_Network_Timeout },
		{ "EPICOResult::PXR_Error_Anchor_Sharing_Authentication_Failure", (int64)EPICOResult::PXR_Error_Anchor_Sharing_Authentication_Failure },
		{ "EPICOResult::PXR_Error_Anchor_Sharing_Network_Failure", (int64)EPICOResult::PXR_Error_Anchor_Sharing_Network_Failure },
		{ "EPICOResult::PXR_Error_Anchor_Sharing_Localization_Fail", (int64)EPICOResult::PXR_Error_Anchor_Sharing_Localization_Fail },
		{ "EPICOResult::PXR_Error_Anchor_Sharing_Map_Insufficient", (int64)EPICOResult::PXR_Error_Anchor_Sharing_Map_Insufficient },
		{ "EPICOResult::PXR_Error_Permission_Insufficient", (int64)EPICOResult::PXR_Error_Permission_Insufficient },
		{ "EPICOResult::PXR_Error_Unknow", (int64)EPICOResult::PXR_Error_Unknow },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "PXR_Error_Anchor_Sharing_Authentication_Failure.Name", "EPICOResult::PXR_Error_Anchor_Sharing_Authentication_Failure" },
		{ "PXR_Error_Anchor_Sharing_Localization_Fail.Name", "EPICOResult::PXR_Error_Anchor_Sharing_Localization_Fail" },
		{ "PXR_Error_Anchor_Sharing_Map_Insufficient.Name", "EPICOResult::PXR_Error_Anchor_Sharing_Map_Insufficient" },
		{ "PXR_Error_Anchor_Sharing_Network_Failure.Name", "EPICOResult::PXR_Error_Anchor_Sharing_Network_Failure" },
		{ "PXR_Error_Anchor_Sharing_Network_Timeout.Name", "EPICOResult::PXR_Error_Anchor_Sharing_Network_Timeout" },
		{ "PXR_Error_AnchorEntityNotFound.Name", "EPICOResult::PXR_Error_AnchorEntityNotFound" },
		{ "PXR_Error_APIVersionUnsupported.Name", "EPICOResult::PXR_Error_APIVersionUnsupported" },
		{ "PXR_Error_ComponentAdded.Name", "EPICOResult::PXR_Error_ComponentAdded" },
		{ "PXR_Error_ComponentConflict.Name", "EPICOResult::PXR_Error_ComponentConflict" },
		{ "PXR_Error_ComponentNotAdded.Name", "EPICOResult::PXR_Error_ComponentNotAdded" },
		{ "PXR_Error_ComponentNotSupported.Name", "EPICOResult::PXR_Error_ComponentNotSupported" },
		{ "PXR_Error_FeatureUnsupported.Name", "EPICOResult::PXR_Error_FeatureUnsupported" },
		{ "PXR_Error_FunctionUnsupported.Name", "EPICOResult::PXR_Error_FunctionUnsupported" },
		{ "PXR_Error_HandleInvalid.Name", "EPICOResult::PXR_Error_HandleInvalid" },
		{ "PXR_Error_InitializationFailed.Name", "EPICOResult::PXR_Error_InitializationFailed" },
		{ "PXR_Error_LimitReached.Name", "EPICOResult::PXR_Error_LimitReached" },
		{ "PXR_Error_OutOfMemory.Name", "EPICOResult::PXR_Error_OutOfMemory" },
		{ "PXR_Error_Permission_Insufficient.Name", "EPICOResult::PXR_Error_Permission_Insufficient" },
		{ "PXR_Error_Pose_Invalid.Name", "EPICOResult::PXR_Error_Pose_Invalid" },
		{ "PXR_Error_RuntimeFailure.Name", "EPICOResult::PXR_Error_RuntimeFailure" },
		{ "PXR_Error_SizeInsufficient.Name", "EPICOResult::PXR_Error_SizeInsufficient" },
		{ "PXR_Error_Space_Locating.Name", "EPICOResult::PXR_Error_Space_Locating" },
		{ "PXR_Error_Spatial_Mesh_Volumes_Update_Failed.Name", "EPICOResult::PXR_Error_Spatial_Mesh_Volumes_Update_Failed" },
		{ "PXR_Error_SpatialLocalizationNotRunning.Name", "EPICOResult::PXR_Error_SpatialLocalizationNotRunning" },
		{ "PXR_Error_SpatialLocalizationRunning.Name", "EPICOResult::PXR_Error_SpatialLocalizationRunning" },
		{ "PXR_Error_SpatialMapCreated.Name", "EPICOResult::PXR_Error_SpatialMapCreated" },
		{ "PXR_Error_SpatialMapNotCreated.Name", "EPICOResult::PXR_Error_SpatialMapNotCreated" },
		{ "PXR_Error_SpatialSensingServiceUnavailable.Name", "EPICOResult::PXR_Error_SpatialSensingServiceUnavailable" },
		{ "PXR_Error_Tracking_State_Invalid.Name", "EPICOResult::PXR_Error_Tracking_State_Invalid" },
		{ "PXR_Error_Unknow.Name", "EPICOResult::PXR_Error_Unknow" },
		{ "PXR_Error_ValidationFailure.Name", "EPICOResult::PXR_Error_ValidationFailure" },
		{ "PXR_Scene_Capture_Process_Successful.Name", "EPICOResult::PXR_Scene_Capture_Process_Successful" },
		{ "PXR_Spatial_Mesh_Data_No_Update.Name", "EPICOResult::PXR_Spatial_Mesh_Data_No_Update" },
		{ "PXR_Success.Name", "EPICOResult::PXR_Success" },
		{ "PXR_TimeoutExpired.Name", "EPICOResult::PXR_TimeoutExpired" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOResult",
		"EPICOResult",
		Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOResult()
	{
		if (!Z_Registration_Info_UEnum_EPICOResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOResult.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOResult.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialTrackingState;
	static UEnum* EPICOSpatialTrackingState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialTrackingState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialTrackingState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialTrackingState"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialTrackingState.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialTrackingState>()
	{
		return EPICOSpatialTrackingState_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enumerators[] = {
		{ "EPICOSpatialTrackingState::SpatialTrackingState_Invalid", (int64)EPICOSpatialTrackingState::SpatialTrackingState_Invalid },
		{ "EPICOSpatialTrackingState::SpatialTrackingState_Valid", (int64)EPICOSpatialTrackingState::SpatialTrackingState_Valid },
		{ "EPICOSpatialTrackingState::SpatialTrackingState_Limited", (int64)EPICOSpatialTrackingState::SpatialTrackingState_Limited },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "SpatialTrackingState_Invalid.Name", "EPICOSpatialTrackingState::SpatialTrackingState_Invalid" },
		{ "SpatialTrackingState_Limited.Name", "EPICOSpatialTrackingState::SpatialTrackingState_Limited" },
		{ "SpatialTrackingState_Valid.Name", "EPICOSpatialTrackingState::SpatialTrackingState_Valid" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialTrackingState",
		"EPICOSpatialTrackingState",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialTrackingState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialTrackingState.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialTrackingState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage;
	static UEnum* EPICOSpatialTrackingStateMessage_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialTrackingStateMessage"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialTrackingStateMessage>()
	{
		return EPICOSpatialTrackingStateMessage_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enumerators[] = {
		{ "EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_Unknown", (int64)EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_Unknown },
		{ "EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_InternalError", (int64)EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_InternalError },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "SpatialTrackingStateMessage_InternalError.Name", "EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_InternalError" },
		{ "SpatialTrackingStateMessage_Unknown.Name", "EPICOSpatialTrackingStateMessage::SpatialTrackingStateMessage_Unknown" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialTrackingStateMessage",
		"EPICOSpatialTrackingStateMessage",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialTrackingStateMessage_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag;
	static UEnum* EPICOAnchorComponentTypeFlag_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOAnchorComponentTypeFlag"));
		}
		return Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOAnchorComponentTypeFlag>()
	{
		return EPICOAnchorComponentTypeFlag_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enumerators[] = {
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_None", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_None },
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_Pose", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_Pose },
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_Persistence", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_Persistence },
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_SceneLabel", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_SceneLabel },
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_Plane", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_Plane },
		{ "EPICOAnchorComponentTypeFlag::ComponentFlag_Volume", (int64)EPICOAnchorComponentTypeFlag::ComponentFlag_Volume },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ComponentFlag_None.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_None" },
		{ "ComponentFlag_Persistence.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_Persistence" },
		{ "ComponentFlag_Plane.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_Plane" },
		{ "ComponentFlag_Pose.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_Pose" },
		{ "ComponentFlag_SceneLabel.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_SceneLabel" },
		{ "ComponentFlag_Volume.Name", "EPICOAnchorComponentTypeFlag::ComponentFlag_Volume" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOAnchorComponentTypeFlag",
		"EPICOAnchorComponentTypeFlag",
		Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag()
	{
		if (!Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOAnchorComponentTypeFlag_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags;
	static UEnum* EPICOSpatialSceneDataTypeFlags_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialSceneDataTypeFlags"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialSceneDataTypeFlags>()
	{
		return EPICOSpatialSceneDataTypeFlags_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enumerators[] = {
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_None", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_None },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Unknown", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Unknown },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Floor", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Floor },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Ceiling", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Ceiling },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Wall", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Wall },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Door", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Door },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Window", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Window },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Opening", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Opening },
		{ "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Object", (int64)EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Object },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "SpatialSceneDataTypeFlag_Ceiling.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Ceiling" },
		{ "SpatialSceneDataTypeFlag_Door.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Door" },
		{ "SpatialSceneDataTypeFlag_Floor.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Floor" },
		{ "SpatialSceneDataTypeFlag_None.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_None" },
		{ "SpatialSceneDataTypeFlag_Object.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Object" },
		{ "SpatialSceneDataTypeFlag_Opening.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Opening" },
		{ "SpatialSceneDataTypeFlag_Unknown.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Unknown" },
		{ "SpatialSceneDataTypeFlag_Wall.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Wall" },
		{ "SpatialSceneDataTypeFlag_Window.Name", "EPICOSpatialSceneDataTypeFlags::SpatialSceneDataTypeFlag_Window" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialSceneDataTypeFlags",
		"EPICOSpatialSceneDataTypeFlags",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneDataTypeFlags_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOAnchorSceneLabel;
	static UEnum* EPICOAnchorSceneLabel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOAnchorSceneLabel"));
		}
		return Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOAnchorSceneLabel>()
	{
		return EPICOAnchorSceneLabel_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enumerators[] = {
		{ "EPICOAnchorSceneLabel::SceneLabel_Unknown", (int64)EPICOAnchorSceneLabel::SceneLabel_Unknown },
		{ "EPICOAnchorSceneLabel::SceneLabel_Floor", (int64)EPICOAnchorSceneLabel::SceneLabel_Floor },
		{ "EPICOAnchorSceneLabel::SceneLabel_Ceiling", (int64)EPICOAnchorSceneLabel::SceneLabel_Ceiling },
		{ "EPICOAnchorSceneLabel::SceneLabel_Wall", (int64)EPICOAnchorSceneLabel::SceneLabel_Wall },
		{ "EPICOAnchorSceneLabel::SceneLabel_Door", (int64)EPICOAnchorSceneLabel::SceneLabel_Door },
		{ "EPICOAnchorSceneLabel::SceneLabel_Window", (int64)EPICOAnchorSceneLabel::SceneLabel_Window },
		{ "EPICOAnchorSceneLabel::SceneLabel_Opening", (int64)EPICOAnchorSceneLabel::SceneLabel_Opening },
		{ "EPICOAnchorSceneLabel::SceneLabel_Table", (int64)EPICOAnchorSceneLabel::SceneLabel_Table },
		{ "EPICOAnchorSceneLabel::SceneLabel_Sofa", (int64)EPICOAnchorSceneLabel::SceneLabel_Sofa },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "SceneLabel_Ceiling.Name", "EPICOAnchorSceneLabel::SceneLabel_Ceiling" },
		{ "SceneLabel_Door.Name", "EPICOAnchorSceneLabel::SceneLabel_Door" },
		{ "SceneLabel_Floor.Name", "EPICOAnchorSceneLabel::SceneLabel_Floor" },
		{ "SceneLabel_Opening.Name", "EPICOAnchorSceneLabel::SceneLabel_Opening" },
		{ "SceneLabel_Sofa.Name", "EPICOAnchorSceneLabel::SceneLabel_Sofa" },
		{ "SceneLabel_Table.Name", "EPICOAnchorSceneLabel::SceneLabel_Table" },
		{ "SceneLabel_Unknown.Name", "EPICOAnchorSceneLabel::SceneLabel_Unknown" },
		{ "SceneLabel_Wall.Name", "EPICOAnchorSceneLabel::SceneLabel_Wall" },
		{ "SceneLabel_Window.Name", "EPICOAnchorSceneLabel::SceneLabel_Window" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOAnchorSceneLabel",
		"EPICOAnchorSceneLabel",
		Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel()
	{
		if (!Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOAnchorSceneLabel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOAnchorSceneLabel.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOPersistLocation;
	static UEnum* EPICOPersistLocation_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOPersistLocation.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOPersistLocation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOPersistLocation"));
		}
		return Z_Registration_Info_UEnum_EPICOPersistLocation.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOPersistLocation>()
	{
		return EPICOPersistLocation_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enumerators[] = {
		{ "EPICOPersistLocation::PersistLocation_Local", (int64)EPICOPersistLocation::PersistLocation_Local },
		{ "EPICOPersistLocation::PersistLocation_Shared", (int64)EPICOPersistLocation::PersistLocation_Shared },
		{ "EPICOPersistLocation::PersistLocation_Max", (int64)EPICOPersistLocation::PersistLocation_Max },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "PersistLocation_Local.Name", "EPICOPersistLocation::PersistLocation_Local" },
		{ "PersistLocation_Max.Hidden", "" },
		{ "PersistLocation_Max.Name", "EPICOPersistLocation::PersistLocation_Max" },
		{ "PersistLocation_Shared.Name", "EPICOPersistLocation::PersistLocation_Shared" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOPersistLocation",
		"EPICOPersistLocation",
		Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation()
	{
		if (!Z_Registration_Info_UEnum_EPICOPersistLocation.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOPersistLocation.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOPersistLocation.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOLoadFilterType;
	static UEnum* EPICOLoadFilterType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOLoadFilterType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOLoadFilterType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOLoadFilterType"));
		}
		return Z_Registration_Info_UEnum_EPICOLoadFilterType.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOLoadFilterType>()
	{
		return EPICOLoadFilterType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enumerators[] = {
		{ "EPICOLoadFilterType::LoadFilterType_None", (int64)EPICOLoadFilterType::LoadFilterType_None },
		{ "EPICOLoadFilterType::LoadFilterType_UUID", (int64)EPICOLoadFilterType::LoadFilterType_UUID },
		{ "EPICOLoadFilterType::LoadFilterType_SpatialSceneData", (int64)EPICOLoadFilterType::LoadFilterType_SpatialSceneData },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "LoadFilterType_None.Hidden", "" },
		{ "LoadFilterType_None.Name", "EPICOLoadFilterType::LoadFilterType_None" },
		{ "LoadFilterType_SpatialSceneData.Name", "EPICOLoadFilterType::LoadFilterType_SpatialSceneData" },
		{ "LoadFilterType_UUID.Name", "EPICOLoadFilterType::LoadFilterType_UUID" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOLoadFilterType",
		"EPICOLoadFilterType",
		Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType()
	{
		if (!Z_Registration_Info_UEnum_EPICOLoadFilterType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOLoadFilterType.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOLoadFilterType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOLoadFilterType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus;
	static UEnum* EPICOSpatialSceneCaptureStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialSceneCaptureStatus"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialSceneCaptureStatus>()
	{
		return EPICOSpatialSceneCaptureStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enumerators[] = {
		{ "EPICOSpatialSceneCaptureStatus::SpatialSceneCaptureStatus_NotDefined", (int64)EPICOSpatialSceneCaptureStatus::SpatialSceneCaptureStatus_NotDefined },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "SpatialSceneCaptureStatus_NotDefined.Name", "EPICOSpatialSceneCaptureStatus::SpatialSceneCaptureStatus_NotDefined" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialSceneCaptureStatus",
		"EPICOSpatialSceneCaptureStatus",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialSceneCaptureStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOSpatialHandle;
class UScriptStruct* FPICOSpatialHandle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOSpatialHandle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOSpatialHandle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOSpatialHandle, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOSpatialHandle"));
	}
	return Z_Registration_Info_UScriptStruct_PICOSpatialHandle.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOSpatialHandle>()
{
	return FPICOSpatialHandle::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOSpatialHandle>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOSpatialHandle",
		nullptr,
		0,
		sizeof(FPICOSpatialHandle),
		alignof(FPICOSpatialHandle),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialHandle()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOSpatialHandle.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOSpatialHandle.InnerSingleton, Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOSpatialHandle.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FutureMessage;
class UScriptStruct* FFutureMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FutureMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FutureMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFutureMessage, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("FutureMessage"));
	}
	return Z_Registration_Info_UScriptStruct_FutureMessage.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FFutureMessage>()
{
	return FFutureMessage::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FFutureMessage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFutureMessage_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFutureMessage_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFutureMessage>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFutureMessage_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"FutureMessage",
		nullptr,
		0,
		sizeof(FFutureMessage),
		alignof(FFutureMessage),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFutureMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFutureMessage_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFutureMessage()
	{
		if (!Z_Registration_Info_UScriptStruct_FutureMessage.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FutureMessage.InnerSingleton, Z_Construct_UScriptStruct_FFutureMessage_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_FutureMessage.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOSpatialUUID;
class UScriptStruct* FPICOSpatialUUID::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOSpatialUUID.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOSpatialUUID.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOSpatialUUID, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOSpatialUUID"));
	}
	return Z_Registration_Info_UScriptStruct_PICOSpatialUUID.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOSpatialUUID>()
{
	return FPICOSpatialUUID::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOSpatialUUID>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOSpatialUUID",
		nullptr,
		0,
		sizeof(FPICOSpatialUUID),
		alignof(FPICOSpatialUUID),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialUUID()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOSpatialUUID.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOSpatialUUID.InnerSingleton, Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOSpatialUUID.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo;
class UScriptStruct* FPICOAnchorPlaneBoundaryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOAnchorPlaneBoundaryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOAnchorPlaneBoundaryInfo>()
{
	return FPICOAnchorPlaneBoundaryInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOAnchorPlaneBoundaryInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Center_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorPlaneBoundaryInfo, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Center_MetaData), Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Center_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Extent_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorPlaneBoundaryInfo, Extent), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Extent_MetaData), Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Extent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewProp_Extent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOAnchorPlaneBoundaryInfo",
		Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::PropPointers),
		sizeof(FPICOAnchorPlaneBoundaryInfo),
		alignof(FPICOAnchorPlaneBoundaryInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo;
class UScriptStruct* FPICOAnchorPlanePolygonInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOAnchorPlanePolygonInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOAnchorPlanePolygonInfo>()
{
	return FPICOAnchorPlanePolygonInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerticesNum_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_VerticesNum;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOAnchorPlanePolygonInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_VerticesNum_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_VerticesNum = { "VerticesNum", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorPlanePolygonInfo, VerticesNum), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_VerticesNum_MetaData), Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_VerticesNum_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorPlanePolygonInfo, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices_MetaData), Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_VerticesNum,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewProp_Vertices,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOAnchorPlanePolygonInfo",
		Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::PropPointers),
		sizeof(FPICOAnchorPlanePolygonInfo),
		alignof(FPICOAnchorPlanePolygonInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo;
class UScriptStruct* FPICOAnchorVolumeInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOAnchorVolumeInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOAnchorVolumeInfo>()
{
	return FPICOAnchorVolumeInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOAnchorVolumeInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Center_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorVolumeInfo, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Center_MetaData), Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Center_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Extent_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorVolumeInfo, Extent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Extent_MetaData), Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Extent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewProp_Extent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOAnchorVolumeInfo",
		Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::PropPointers),
		sizeof(FPICOAnchorVolumeInfo),
		alignof(FPICOAnchorVolumeInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSemanticLabel;
	static UEnum* EPICOSemanticLabel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSemanticLabel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSemanticLabel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSemanticLabel"));
		}
		return Z_Registration_Info_UEnum_EPICOSemanticLabel.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSemanticLabel>()
	{
		return EPICOSemanticLabel_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enumerators[] = {
		{ "EPICOSemanticLabel::Unknown", (int64)EPICOSemanticLabel::Unknown },
		{ "EPICOSemanticLabel::Floor", (int64)EPICOSemanticLabel::Floor },
		{ "EPICOSemanticLabel::Ceiling", (int64)EPICOSemanticLabel::Ceiling },
		{ "EPICOSemanticLabel::Wall", (int64)EPICOSemanticLabel::Wall },
		{ "EPICOSemanticLabel::Door", (int64)EPICOSemanticLabel::Door },
		{ "EPICOSemanticLabel::Window", (int64)EPICOSemanticLabel::Window },
		{ "EPICOSemanticLabel::Opening", (int64)EPICOSemanticLabel::Opening },
		{ "EPICOSemanticLabel::Table", (int64)EPICOSemanticLabel::Table },
		{ "EPICOSemanticLabel::Sofa", (int64)EPICOSemanticLabel::Sofa },
		{ "EPICOSemanticLabel::Chair", (int64)EPICOSemanticLabel::Chair },
		{ "EPICOSemanticLabel::Human", (int64)EPICOSemanticLabel::Human },
		{ "EPICOSemanticLabel::Curtain", (int64)EPICOSemanticLabel::Curtain },
		{ "EPICOSemanticLabel::Cabinet", (int64)EPICOSemanticLabel::Cabinet },
		{ "EPICOSemanticLabel::Bed", (int64)EPICOSemanticLabel::Bed },
		{ "EPICOSemanticLabel::Screen", (int64)EPICOSemanticLabel::Screen },
		{ "EPICOSemanticLabel::VirtualWall", (int64)EPICOSemanticLabel::VirtualWall },
		{ "EPICOSemanticLabel::Count", (int64)EPICOSemanticLabel::Count },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enum_MetaDataParams[] = {
		{ "Bed.Name", "EPICOSemanticLabel::Bed" },
		{ "BlueprintType", "true" },
		{ "Cabinet.Name", "EPICOSemanticLabel::Cabinet" },
		{ "Ceiling.Name", "EPICOSemanticLabel::Ceiling" },
		{ "Chair.Name", "EPICOSemanticLabel::Chair" },
		{ "Count.Hidden", "" },
		{ "Count.Name", "EPICOSemanticLabel::Count" },
		{ "Curtain.Name", "EPICOSemanticLabel::Curtain" },
		{ "Door.Name", "EPICOSemanticLabel::Door" },
		{ "Floor.Name", "EPICOSemanticLabel::Floor" },
		{ "Human.Name", "EPICOSemanticLabel::Human" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "Opening.Name", "EPICOSemanticLabel::Opening" },
		{ "Screen.Name", "EPICOSemanticLabel::Screen" },
		{ "Sofa.Name", "EPICOSemanticLabel::Sofa" },
		{ "Table.Name", "EPICOSemanticLabel::Table" },
		{ "Unknown.Name", "EPICOSemanticLabel::Unknown" },
		{ "VirtualWall.Name", "EPICOSemanticLabel::VirtualWall" },
		{ "Wall.Name", "EPICOSemanticLabel::Wall" },
		{ "Window.Name", "EPICOSemanticLabel::Window" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSemanticLabel",
		"EPICOSemanticLabel",
		Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel()
	{
		if (!Z_Registration_Info_UEnum_EPICOSemanticLabel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSemanticLabel.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSemanticLabel.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo;
class UScriptStruct* FPICOAnchorLoadInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOAnchorLoadInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOAnchorLoadInfo>()
{
	return FPICOAnchorLoadInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_PersistLocation_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PersistLocation_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PersistLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUIDFilter_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUIDFilter_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UUIDFilter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOAnchorLoadInfo>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation = { "PersistLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorLoadInfo, PersistLocation), Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation_MetaData), Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation_MetaData) }; // 404773881
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter_Inner = { "UUIDFilter", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(0, nullptr) }; // 4199512061
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter = { "UUIDFilter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOAnchorLoadInfo, UUIDFilter), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter_MetaData), Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter_MetaData) }; // 4199512061
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_PersistLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewProp_UUIDFilter,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOAnchorLoadInfo",
		Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::PropPointers),
		sizeof(FPICOAnchorLoadInfo),
		alignof(FPICOAnchorLoadInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOAnchorLoadInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo;
class UScriptStruct* FPICOSceneLoadInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOSceneLoadInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOSceneLoadInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOSceneLoadInfo>()
{
	return FPICOSceneLoadInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_SemanticFilter_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SemanticFilter_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SemanticFilter_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SemanticFilter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOSceneLoadInfo>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_Inner = { "SemanticFilter", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(0, nullptr) }; // 1135071056
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter = { "SemanticFilter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSceneLoadInfo, SemanticFilter), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_MetaData), Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_MetaData) }; // 1135071056
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewProp_SemanticFilter,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOSceneLoadInfo",
		Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::PropPointers),
		sizeof(FPICOSceneLoadInfo),
		alignof(FPICOSceneLoadInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOSceneLoadInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnchorLoadResult;
class UScriptStruct* FAnchorLoadResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnchorLoadResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnchorLoadResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnchorLoadResult, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("AnchorLoadResult"));
	}
	return Z_Registration_Info_UScriptStruct_AnchorLoadResult.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FAnchorLoadResult>()
{
	return FAnchorLoadResult::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnchorLoadResult_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorUUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnchorUUID;
		static const UECodeGen_Private::FBytePropertyParams NewProp_PersistLocation_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PersistLocation_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PersistLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnchorLoadResult>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_AnchorUUID_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_AnchorUUID = { "AnchorUUID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnchorLoadResult, AnchorUUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_AnchorUUID_MetaData), Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_AnchorUUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation_MetaData[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation = { "PersistLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnchorLoadResult, PersistLocation), Z_Construct_UEnum_PICOXRMR_EPICOPersistLocation, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation_MetaData), Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation_MetaData) }; // 404773881
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_AnchorUUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewProp_PersistLocation,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"AnchorLoadResult",
		Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::PropPointers),
		sizeof(FAnchorLoadResult),
		alignof(FAnchorLoadResult),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAnchorLoadResult()
	{
		if (!Z_Registration_Info_UScriptStruct_AnchorLoadResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnchorLoadResult.InnerSingleton, Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnchorLoadResult.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialMeshConfig;
	static UEnum* EPICOSpatialMeshConfig_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialMeshConfig"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialMeshConfig>()
	{
		return EPICOSpatialMeshConfig_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enumerators[] = {
		{ "EPICOSpatialMeshConfig::Spatial_Mesh_Config_None", (int64)EPICOSpatialMeshConfig::Spatial_Mesh_Config_None },
		{ "EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic", (int64)EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic },
		{ "EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic_Align_With_Vertex", (int64)EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic_Align_With_Vertex },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Categories", "PICO|MR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "Spatial_Mesh_Config_None.Name", "EPICOSpatialMeshConfig::Spatial_Mesh_Config_None" },
		{ "Spatial_Mesh_Config_Semantic.Name", "EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic" },
		{ "Spatial_Mesh_Config_Semantic_Align_With_Vertex.Name", "EPICOSpatialMeshConfig::Spatial_Mesh_Config_Semantic_Align_With_Vertex" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialMeshConfig",
		"EPICOSpatialMeshConfig",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshConfig_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshConfig.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType;
	static UEnum* EPICOSpatialEntityComponentType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialEntityComponentType"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialEntityComponentType>()
	{
		return EPICOSpatialEntityComponentType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enumerators[] = {
		{ "EPICOSpatialEntityComponentType::Location", (int64)EPICOSpatialEntityComponentType::Location },
		{ "EPICOSpatialEntityComponentType::Semantic", (int64)EPICOSpatialEntityComponentType::Semantic },
		{ "EPICOSpatialEntityComponentType::Boundary_2D", (int64)EPICOSpatialEntityComponentType::Boundary_2D },
		{ "EPICOSpatialEntityComponentType::Polygon", (int64)EPICOSpatialEntityComponentType::Polygon },
		{ "EPICOSpatialEntityComponentType::Boundary_3D", (int64)EPICOSpatialEntityComponentType::Boundary_3D },
		{ "EPICOSpatialEntityComponentType::Triangle_Mesh", (int64)EPICOSpatialEntityComponentType::Triangle_Mesh },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boundary_2D.Name", "EPICOSpatialEntityComponentType::Boundary_2D" },
		{ "Boundary_3D.Name", "EPICOSpatialEntityComponentType::Boundary_3D" },
		{ "Location.Name", "EPICOSpatialEntityComponentType::Location" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "Polygon.Name", "EPICOSpatialEntityComponentType::Polygon" },
		{ "Semantic.Name", "EPICOSpatialEntityComponentType::Semantic" },
		{ "Triangle_Mesh.Name", "EPICOSpatialEntityComponentType::Triangle_Mesh" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialEntityComponentType",
		"EPICOSpatialEntityComponentType",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialEntityComponentType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSceneType;
	static UEnum* EPICOSceneType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSceneType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSceneType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSceneType, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSceneType"));
		}
		return Z_Registration_Info_UEnum_EPICOSceneType.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSceneType>()
	{
		return EPICOSceneType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enumerators[] = {
		{ "EPICOSceneType::BoundingBox2D", (int64)EPICOSceneType::BoundingBox2D },
		{ "EPICOSceneType::BoundingPolygon", (int64)EPICOSceneType::BoundingPolygon },
		{ "EPICOSceneType::BoundingBox3D", (int64)EPICOSceneType::BoundingBox3D },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BoundingBox2D.Name", "EPICOSceneType::BoundingBox2D" },
		{ "BoundingBox3D.Name", "EPICOSceneType::BoundingBox3D" },
		{ "BoundingPolygon.Name", "EPICOSceneType::BoundingPolygon" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSceneType",
		"EPICOSceneType",
		Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSceneType()
	{
		if (!Z_Registration_Info_UEnum_EPICOSceneType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSceneType.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSceneType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSceneType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialMeshState;
	static UEnum* EPICOSpatialMeshState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialMeshState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("EPICOSpatialMeshState"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshState.OuterSingleton;
	}
	template<> PICOXRMR_API UEnum* StaticEnum<EPICOSpatialMeshState>()
	{
		return EPICOSpatialMeshState_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enumerators[] = {
		{ "EPICOSpatialMeshState::Added", (int64)EPICOSpatialMeshState::Added },
		{ "EPICOSpatialMeshState::Stable", (int64)EPICOSpatialMeshState::Stable },
		{ "EPICOSpatialMeshState::Updated", (int64)EPICOSpatialMeshState::Updated },
		{ "EPICOSpatialMeshState::Removed", (int64)EPICOSpatialMeshState::Removed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enum_MetaDataParams[] = {
		{ "Added.Name", "EPICOSpatialMeshState::Added" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
		{ "Removed.Name", "EPICOSpatialMeshState::Removed" },
		{ "Stable.Name", "EPICOSpatialMeshState::Stable" },
		{ "Updated.Name", "EPICOSpatialMeshState::Updated" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		"EPICOSpatialMeshState",
		"EPICOSpatialMeshState",
		Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialMeshState.InnerSingleton, Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOExtent3Df;
class UScriptStruct* FPICOExtent3Df::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOExtent3Df.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOExtent3Df.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOExtent3Df, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOExtent3Df"));
	}
	return Z_Registration_Info_UScriptStruct_PICOExtent3Df.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOExtent3Df>()
{
	return FPICOExtent3Df::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOExtent3Df_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOExtent3Df>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Width_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOExtent3Df, Width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Width_MetaData), Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOExtent3Df, Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Height_MetaData), Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Height_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Depth_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOExtent3Df, Depth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Depth_MetaData), Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Depth_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewProp_Depth,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOExtent3Df",
		Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::PropPointers),
		sizeof(FPICOExtent3Df),
		alignof(FPICOExtent3Df),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOExtent3Df()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOExtent3Df.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOExtent3Df.InnerSingleton, Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOExtent3Df.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOExtent2Df;
class UScriptStruct* FPICOExtent2Df::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOExtent2Df.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOExtent2Df.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOExtent2Df, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOExtent2Df"));
	}
	return Z_Registration_Info_UScriptStruct_PICOExtent2Df.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOExtent2Df>()
{
	return FPICOExtent2Df::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOExtent2Df_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOExtent2Df>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Width_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOExtent2Df, Width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Width_MetaData), Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOExtent2Df, Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Height_MetaData), Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Height_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewProp_Height,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOExtent2Df",
		Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::PropPointers),
		sizeof(FPICOExtent2Df),
		alignof(FPICOExtent2Df),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOExtent2Df()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOExtent2Df.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOExtent2Df.InnerSingleton, Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOExtent2Df.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOBoundingBox3D;
class UScriptStruct* FPICOBoundingBox3D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOBoundingBox3D, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOBoundingBox3D"));
	}
	return Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOBoundingBox3D>()
{
	return FPICOBoundingBox3D::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOBoundingBox3D>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Center_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOBoundingBox3D, Center), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Center_MetaData), Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Center_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Extent_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOBoundingBox3D, Extent), Z_Construct_UScriptStruct_FPICOExtent3Df, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Extent_MetaData), Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Extent_MetaData) }; // 1463059947
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewProp_Extent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOBoundingBox3D",
		Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::PropPointers),
		sizeof(FPICOBoundingBox3D),
		alignof(FPICOBoundingBox3D),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox3D()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.InnerSingleton, Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOBoundingBox3D.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOBoundingBox2D;
class UScriptStruct* FPICOBoundingBox2D::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOBoundingBox2D, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOBoundingBox2D"));
	}
	return Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOBoundingBox2D>()
{
	return FPICOBoundingBox2D::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Center_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Center;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Extent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOBoundingBox2D>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Center_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Center = { "Center", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOBoundingBox2D, Center), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Center_MetaData), Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Center_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Extent_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOBoundingBox2D, Extent), Z_Construct_UScriptStruct_FPICOExtent2Df, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Extent_MetaData), Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Extent_MetaData) }; // 479496683
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Center,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewProp_Extent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOBoundingBox2D",
		Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::PropPointers),
		sizeof(FPICOBoundingBox2D),
		alignof(FPICOBoundingBox2D),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox2D()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.InnerSingleton, Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOBoundingBox2D.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo;
class UScriptStruct* FPICOSpatialMeshInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOSpatialMeshInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOSpatialMeshInfo>()
{
	return FPICOSpatialMeshInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUID;
		static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshPose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoundingBox_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoundingBox;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Semantics_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Semantics_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Semantics_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Semantics;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UpdateTime_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_UpdateTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOSpatialMeshInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UUID_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The UUID of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The UUID of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UUID = { "UUID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, UUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UUID_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The State of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The State of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, State), Z_Construct_UEnum_PICOXRMR_EPICOSpatialMeshState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State_MetaData) }; // 761296771
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_MeshPose_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Transform of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Transform of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_MeshPose = { "MeshPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, MeshPose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_MeshPose_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_MeshPose_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_BoundingBox_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The BoundingBox of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The BoundingBox of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_BoundingBox = { "BoundingBox", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, BoundingBox), Z_Construct_UScriptStruct_FPICOBoundingBox3D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_BoundingBox_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_BoundingBox_MetaData) }; // 112941079
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Vertices Array of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Vertices Array of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices_Inner = { "Indices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices_MetaData[] = {
		{ "Category", "PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Indices Array of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Indices Array of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices = { "Indices", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, Indices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_Inner = { "Semantics", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(0, nullptr) }; // 1135071056
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_MetaData[] = {
		{ "Category", "PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Semantics Array of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Semantics Array of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics = { "Semantics", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, Semantics), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_MetaData) }; // 1135071056
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UpdateTime_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Update Time of the Mesh */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Update Time of the Mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UpdateTime = { "UpdateTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOSpatialMeshInfo, UpdateTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UpdateTime_MetaData), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UpdateTime_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_MeshPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_BoundingBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Vertices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Indices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_Semantics,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewProp_UpdateTime,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOSpatialMeshInfo",
		Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::PropPointers),
		sizeof(FPICOSpatialMeshInfo),
		alignof(FPICOSpatialMeshInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialMeshInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOMRSceneInfo;
class UScriptStruct* FPICOMRSceneInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOMRSceneInfo, (UObject*)Z_Construct_UPackage__Script_PICOXRMR(), TEXT("PICOMRSceneInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.OuterSingleton;
}
template<> PICOXRMR_API UScriptStruct* StaticStruct<FPICOMRSceneInfo>()
{
	return FPICOMRSceneInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScenePose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScenePose;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Semantic_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Semantic_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Semantic;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SceneType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SceneType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SceneType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOMRSceneInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_UUID_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The UUID of the Scene */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The UUID of the Scene" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_UUID = { "UUID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOMRSceneInfo, UUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_UUID_MetaData), Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_UUID_MetaData) }; // 4199512061
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_ScenePose_MetaData[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Transform of the Scene */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Transform of the Scene" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_ScenePose = { "ScenePose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOMRSceneInfo, ScenePose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_ScenePose_MetaData), Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_ScenePose_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic_MetaData[] = {
		{ "Category", "PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Semantics of the Scene */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Semantics of the Scene" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic = { "Semantic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOMRSceneInfo, Semantic), Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic_MetaData), Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic_MetaData) }; // 1135071056
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType_MetaData[] = {
		{ "Category", "PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The SceneType of the Scene */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The SceneType of the Scene" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType = { "SceneType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOMRSceneInfo, SceneType), Z_Construct_UEnum_PICOXRMR_EPICOSceneType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType_MetaData), Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType_MetaData) }; // 1216638432
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_UUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_ScenePose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_Semantic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewProp_SceneType,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
		nullptr,
		&NewStructOps,
		"PICOMRSceneInfo",
		Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::PropPointers),
		sizeof(FPICOMRSceneInfo),
		alignof(FPICOMRSceneInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOMRSceneInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.InnerSingleton, Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOMRSceneInfo.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::EnumInfo[] = {
		{ EPICOResult_StaticEnum, TEXT("EPICOResult"), &Z_Registration_Info_UEnum_EPICOResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1390192157U) },
		{ EPICOSpatialTrackingState_StaticEnum, TEXT("EPICOSpatialTrackingState"), &Z_Registration_Info_UEnum_EPICOSpatialTrackingState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1432727928U) },
		{ EPICOSpatialTrackingStateMessage_StaticEnum, TEXT("EPICOSpatialTrackingStateMessage"), &Z_Registration_Info_UEnum_EPICOSpatialTrackingStateMessage, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3994494969U) },
		{ EPICOAnchorComponentTypeFlag_StaticEnum, TEXT("EPICOAnchorComponentTypeFlag"), &Z_Registration_Info_UEnum_EPICOAnchorComponentTypeFlag, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2080849069U) },
		{ EPICOSpatialSceneDataTypeFlags_StaticEnum, TEXT("EPICOSpatialSceneDataTypeFlags"), &Z_Registration_Info_UEnum_EPICOSpatialSceneDataTypeFlags, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 501162487U) },
		{ EPICOAnchorSceneLabel_StaticEnum, TEXT("EPICOAnchorSceneLabel"), &Z_Registration_Info_UEnum_EPICOAnchorSceneLabel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4130675835U) },
		{ EPICOPersistLocation_StaticEnum, TEXT("EPICOPersistLocation"), &Z_Registration_Info_UEnum_EPICOPersistLocation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 404773881U) },
		{ EPICOLoadFilterType_StaticEnum, TEXT("EPICOLoadFilterType"), &Z_Registration_Info_UEnum_EPICOLoadFilterType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2793570523U) },
		{ EPICOSpatialSceneCaptureStatus_StaticEnum, TEXT("EPICOSpatialSceneCaptureStatus"), &Z_Registration_Info_UEnum_EPICOSpatialSceneCaptureStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 714584076U) },
		{ EPICOSemanticLabel_StaticEnum, TEXT("EPICOSemanticLabel"), &Z_Registration_Info_UEnum_EPICOSemanticLabel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1135071056U) },
		{ EPICOSpatialMeshConfig_StaticEnum, TEXT("EPICOSpatialMeshConfig"), &Z_Registration_Info_UEnum_EPICOSpatialMeshConfig, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4073674936U) },
		{ EPICOSpatialEntityComponentType_StaticEnum, TEXT("EPICOSpatialEntityComponentType"), &Z_Registration_Info_UEnum_EPICOSpatialEntityComponentType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2394128802U) },
		{ EPICOSceneType_StaticEnum, TEXT("EPICOSceneType"), &Z_Registration_Info_UEnum_EPICOSceneType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1216638432U) },
		{ EPICOSpatialMeshState_StaticEnum, TEXT("EPICOSpatialMeshState"), &Z_Registration_Info_UEnum_EPICOSpatialMeshState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 761296771U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::ScriptStructInfo[] = {
		{ FPICOSpatialHandle::StaticStruct, Z_Construct_UScriptStruct_FPICOSpatialHandle_Statics::NewStructOps, TEXT("PICOSpatialHandle"), &Z_Registration_Info_UScriptStruct_PICOSpatialHandle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOSpatialHandle), 82442488U) },
		{ FFutureMessage::StaticStruct, Z_Construct_UScriptStruct_FFutureMessage_Statics::NewStructOps, TEXT("FutureMessage"), &Z_Registration_Info_UScriptStruct_FutureMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFutureMessage), 683919615U) },
		{ FPICOSpatialUUID::StaticStruct, Z_Construct_UScriptStruct_FPICOSpatialUUID_Statics::NewStructOps, TEXT("PICOSpatialUUID"), &Z_Registration_Info_UScriptStruct_PICOSpatialUUID, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOSpatialUUID), 4199512061U) },
		{ FPICOAnchorPlaneBoundaryInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOAnchorPlaneBoundaryInfo_Statics::NewStructOps, TEXT("PICOAnchorPlaneBoundaryInfo"), &Z_Registration_Info_UScriptStruct_PICOAnchorPlaneBoundaryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOAnchorPlaneBoundaryInfo), 1817909206U) },
		{ FPICOAnchorPlanePolygonInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOAnchorPlanePolygonInfo_Statics::NewStructOps, TEXT("PICOAnchorPlanePolygonInfo"), &Z_Registration_Info_UScriptStruct_PICOAnchorPlanePolygonInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOAnchorPlanePolygonInfo), 932747879U) },
		{ FPICOAnchorVolumeInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOAnchorVolumeInfo_Statics::NewStructOps, TEXT("PICOAnchorVolumeInfo"), &Z_Registration_Info_UScriptStruct_PICOAnchorVolumeInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOAnchorVolumeInfo), 267170816U) },
		{ FPICOAnchorLoadInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOAnchorLoadInfo_Statics::NewStructOps, TEXT("PICOAnchorLoadInfo"), &Z_Registration_Info_UScriptStruct_PICOAnchorLoadInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOAnchorLoadInfo), 1014800311U) },
		{ FPICOSceneLoadInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOSceneLoadInfo_Statics::NewStructOps, TEXT("PICOSceneLoadInfo"), &Z_Registration_Info_UScriptStruct_PICOSceneLoadInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOSceneLoadInfo), 2322881145U) },
		{ FAnchorLoadResult::StaticStruct, Z_Construct_UScriptStruct_FAnchorLoadResult_Statics::NewStructOps, TEXT("AnchorLoadResult"), &Z_Registration_Info_UScriptStruct_AnchorLoadResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnchorLoadResult), 598985502U) },
		{ FPICOExtent3Df::StaticStruct, Z_Construct_UScriptStruct_FPICOExtent3Df_Statics::NewStructOps, TEXT("PICOExtent3Df"), &Z_Registration_Info_UScriptStruct_PICOExtent3Df, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOExtent3Df), 1463059947U) },
		{ FPICOExtent2Df::StaticStruct, Z_Construct_UScriptStruct_FPICOExtent2Df_Statics::NewStructOps, TEXT("PICOExtent2Df"), &Z_Registration_Info_UScriptStruct_PICOExtent2Df, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOExtent2Df), 479496683U) },
		{ FPICOBoundingBox3D::StaticStruct, Z_Construct_UScriptStruct_FPICOBoundingBox3D_Statics::NewStructOps, TEXT("PICOBoundingBox3D"), &Z_Registration_Info_UScriptStruct_PICOBoundingBox3D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOBoundingBox3D), 112941079U) },
		{ FPICOBoundingBox2D::StaticStruct, Z_Construct_UScriptStruct_FPICOBoundingBox2D_Statics::NewStructOps, TEXT("PICOBoundingBox2D"), &Z_Registration_Info_UScriptStruct_PICOBoundingBox2D, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOBoundingBox2D), 3672283929U) },
		{ FPICOSpatialMeshInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOSpatialMeshInfo_Statics::NewStructOps, TEXT("PICOSpatialMeshInfo"), &Z_Registration_Info_UScriptStruct_PICOSpatialMeshInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOSpatialMeshInfo), 1430625674U) },
		{ FPICOMRSceneInfo::StaticStruct, Z_Construct_UScriptStruct_FPICOMRSceneInfo_Statics::NewStructOps, TEXT("PICOMRSceneInfo"), &Z_Registration_Info_UScriptStruct_PICOMRSceneInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOMRSceneInfo), 3745358769U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_1612103080(TEXT("/Script/PICOXRMR"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
