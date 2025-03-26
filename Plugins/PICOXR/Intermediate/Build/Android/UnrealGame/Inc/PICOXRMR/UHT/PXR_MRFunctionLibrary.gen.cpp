// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMR/Public/PXR_MRFunctionLibrary.h"
#include "PICOXRMR/Public/PXR_MRTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MRFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOMRState();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOAnchorComponent_NoRegister();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOXRMRFunctionLibrary();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOXRMRFunctionLibrary_NoRegister();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOResult();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FAnchorLoadResult();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox2D();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOBoundingBox3D();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialHandle();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialUUID();
	UPackage* Z_Construct_UPackage__Script_PICOXRMR();
// End Cross Module References
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_ResetSpatialMeshInfosState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRMRFunctionLibrary::PXR_ResetSpatialMeshInfosState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSceneCaptureServiceState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOMRState*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSceneCaptureServiceState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSpatialAnchorServiceState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOMRState*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSpatialAnchorServiceState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSpatialMeshScanningState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOMRState*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSpatialMeshScanningState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSpatialMeshLodSetting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOSpatialMeshLod*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSpatialMeshLodSetting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_ChangeSpatialMeshLodSetting)
	{
		P_GET_ENUM(EPICOSpatialMeshLod,Z_Param_SpatialMeshLod);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_ChangeSpatialMeshLodSetting(EPICOSpatialMeshLod(Z_Param_SpatialMeshLod));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_CreateSceneBoundingPolygon)
	{
		P_GET_OBJECT(AActor,Z_Param_BoundActor);
		P_GET_UBOOL(Z_Param_bNeverCreateCollision);
		P_GET_UBOOL(Z_Param_bFlipPolygon);
		P_GET_UBOOL(Z_Param_UseWireframe);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Vertices);
		P_GET_OBJECT(UMaterialInterface,Z_Param_DefaultMeshMaterial);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_CreateSceneBoundingPolygon(Z_Param_BoundActor,Z_Param_bNeverCreateCollision,Z_Param_bFlipPolygon,Z_Param_UseWireframe,Z_Param_Out_Transform,Z_Param_Out_Vertices,Z_Param_DefaultMeshMaterial);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_CloseSceneCaptureService)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_CloseSceneCaptureService();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_CloseSpatialAnchorService)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_CloseSpatialAnchorService();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_CloseSpatialMeshScanning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_CloseSpatialMeshScanning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_FromStringToUUID)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AnchorUUIDString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPICOSpatialUUID*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_FromStringToUUID(Z_Param_AnchorUUIDString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_FromUUIDToString)
	{
		P_GET_STRUCT_REF(FPICOSpatialUUID,Z_Param_Out_AnchorUUID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_FromUUIDToString(Z_Param_Out_AnchorUUID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_FromAnchorToString)
	{
		P_GET_STRUCT_REF(FPICOSpatialHandle,Z_Param_Out_AnchorHandle);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_FromAnchorToString(Z_Param_Out_AnchorHandle);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_SpawnActorFromLoadResult)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContext);
		P_GET_STRUCT_REF(FAnchorLoadResult,Z_Param_Out_LoadResult);
		P_GET_OBJECT(UClass,Z_Param_ActorClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_SpawnActorFromLoadResult(Z_Param_WorldContext,Z_Param_Out_LoadResult,Z_Param_ActorClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_IsAnchorValidForComponent)
	{
		P_GET_OBJECT(UPICOAnchorComponent,Z_Param_AnchorComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_IsAnchorValidForComponent(Z_Param_AnchorComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_IsAnchorValidForActor)
	{
		P_GET_OBJECT(AActor,Z_Param_BoundActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_IsAnchorValidForActor(Z_Param_BoundActor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_DestroyAnchorByActor)
	{
		P_GET_OBJECT(AActor,Z_Param_BoundActor);
		P_GET_ENUM_REF(EPICOResult,Z_Param_Out_OutResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_DestroyAnchorByActor(Z_Param_BoundActor,(EPICOResult&)(Z_Param_Out_OutResult));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_DestroyAnchorByComponent)
	{
		P_GET_OBJECT(UPICOAnchorComponent,Z_Param_AnchorComponent);
		P_GET_ENUM_REF(EPICOResult,Z_Param_Out_OutResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_DestroyAnchorByComponent(Z_Param_AnchorComponent,(EPICOResult&)(Z_Param_Out_OutResult));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetAnchorPoseByComponent)
	{
		P_GET_OBJECT(UPICOAnchorComponent,Z_Param_AnchorComponent);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTransform);
		P_GET_ENUM_REF(EPICOResult,Z_Param_Out_OutResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetAnchorPoseByComponent(Z_Param_AnchorComponent,Z_Param_Out_OutTransform,(EPICOResult&)(Z_Param_Out_OutResult));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetAnchorPoseByActor)
	{
		P_GET_OBJECT(AActor,Z_Param_BoundActor);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_OutTransform);
		P_GET_ENUM_REF(EPICOResult,Z_Param_Out_OutResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetAnchorPoseByActor(Z_Param_BoundActor,Z_Param_Out_OutTransform,(EPICOResult&)(Z_Param_Out_OutResult));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingBox3D)
	{
		P_GET_STRUCT_REF(FPICOSpatialUUID,Z_Param_Out_UUID);
		P_GET_STRUCT_REF(FPICOBoundingBox3D,Z_Param_Out_OutBoundingBox3D);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingBox3D(Z_Param_Out_UUID,Z_Param_Out_OutBoundingBox3D);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingPolygon)
	{
		P_GET_STRUCT_REF(FPICOSpatialUUID,Z_Param_Out_UUID);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_OutPolygonVertices);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingPolygon(Z_Param_Out_UUID,Z_Param_Out_OutPolygonVertices);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingBox2D)
	{
		P_GET_STRUCT_REF(FPICOSpatialUUID,Z_Param_Out_UUID);
		P_GET_STRUCT_REF(FPICOBoundingBox2D,Z_Param_Out_OutBoundingBox2D);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetSceneBoundingBox2D(Z_Param_Out_UUID,Z_Param_Out_OutBoundingBox2D);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRMRFunctionLibrary::execPXR_GetAnchorEntityUuid)
	{
		P_GET_OBJECT(AActor,Z_Param_BoundActor);
		P_GET_STRUCT_REF(FPICOSpatialUUID,Z_Param_Out_OutAnchorUUID);
		P_GET_ENUM_REF(EPICOResult,Z_Param_Out_OutResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRMRFunctionLibrary::PXR_GetAnchorEntityUuid(Z_Param_BoundActor,Z_Param_Out_OutAnchorUUID,(EPICOResult&)(Z_Param_Out_OutResult));
		P_NATIVE_END;
	}
	void UPICOXRMRFunctionLibrary::StaticRegisterNativesUPICOXRMRFunctionLibrary()
	{
		UClass* Class = UPICOXRMRFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PXR_ChangeSpatialMeshLodSetting", &UPICOXRMRFunctionLibrary::execPXR_ChangeSpatialMeshLodSetting },
			{ "PXR_CloseSceneCaptureService", &UPICOXRMRFunctionLibrary::execPXR_CloseSceneCaptureService },
			{ "PXR_CloseSpatialAnchorService", &UPICOXRMRFunctionLibrary::execPXR_CloseSpatialAnchorService },
			{ "PXR_CloseSpatialMeshScanning", &UPICOXRMRFunctionLibrary::execPXR_CloseSpatialMeshScanning },
			{ "PXR_CreateSceneBoundingPolygon", &UPICOXRMRFunctionLibrary::execPXR_CreateSceneBoundingPolygon },
			{ "PXR_DestroyAnchorByActor", &UPICOXRMRFunctionLibrary::execPXR_DestroyAnchorByActor },
			{ "PXR_DestroyAnchorByComponent", &UPICOXRMRFunctionLibrary::execPXR_DestroyAnchorByComponent },
			{ "PXR_FromAnchorToString", &UPICOXRMRFunctionLibrary::execPXR_FromAnchorToString },
			{ "PXR_FromStringToUUID", &UPICOXRMRFunctionLibrary::execPXR_FromStringToUUID },
			{ "PXR_FromUUIDToString", &UPICOXRMRFunctionLibrary::execPXR_FromUUIDToString },
			{ "PXR_GetAnchorEntityUuid", &UPICOXRMRFunctionLibrary::execPXR_GetAnchorEntityUuid },
			{ "PXR_GetAnchorPoseByActor", &UPICOXRMRFunctionLibrary::execPXR_GetAnchorPoseByActor },
			{ "PXR_GetAnchorPoseByComponent", &UPICOXRMRFunctionLibrary::execPXR_GetAnchorPoseByComponent },
			{ "PXR_GetSceneBoundingBox2D", &UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingBox2D },
			{ "PXR_GetSceneBoundingBox3D", &UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingBox3D },
			{ "PXR_GetSceneBoundingPolygon", &UPICOXRMRFunctionLibrary::execPXR_GetSceneBoundingPolygon },
			{ "PXR_GetSceneCaptureServiceState", &UPICOXRMRFunctionLibrary::execPXR_GetSceneCaptureServiceState },
			{ "PXR_GetSpatialAnchorServiceState", &UPICOXRMRFunctionLibrary::execPXR_GetSpatialAnchorServiceState },
			{ "PXR_GetSpatialMeshLodSetting", &UPICOXRMRFunctionLibrary::execPXR_GetSpatialMeshLodSetting },
			{ "PXR_GetSpatialMeshScanningState", &UPICOXRMRFunctionLibrary::execPXR_GetSpatialMeshScanningState },
			{ "PXR_IsAnchorValidForActor", &UPICOXRMRFunctionLibrary::execPXR_IsAnchorValidForActor },
			{ "PXR_IsAnchorValidForComponent", &UPICOXRMRFunctionLibrary::execPXR_IsAnchorValidForComponent },
			{ "PXR_ResetSpatialMeshInfosState", &UPICOXRMRFunctionLibrary::execPXR_ResetSpatialMeshInfosState },
			{ "PXR_SpawnActorFromLoadResult", &UPICOXRMRFunctionLibrary::execPXR_SpawnActorFromLoadResult },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms
		{
			EPICOSpatialMeshLod SpatialMeshLod;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_SpatialMeshLod_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SpatialMeshLod;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_SpatialMeshLod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_SpatialMeshLod = { "SpatialMeshLod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms, SpatialMeshLod), Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod, METADATA_PARAMS(0, nullptr) }; // 1769800351
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_SpatialMeshLod_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_SpatialMeshLod,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Changes Spatial Mesh's Lod Setting.\n/// </summary>\n/// <param name=\"SpatialMeshLod\">Specifies the Lod for which you want to set.</param>\x09\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nChanges Spatial Mesh's Lod Setting.\n</summary>\n<param name=\"SpatialMeshLod\">Specifies the Lod for which you want to set.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_ChangeSpatialMeshLodSetting", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::PICOXRMRFunctionLibrary_eventPXR_ChangeSpatialMeshLodSetting_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_CloseSceneCaptureService_Parms
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
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CloseSceneCaptureService_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CloseSceneCaptureService_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Closes Scene Capture service.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nCloses Scene Capture service.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_CloseSceneCaptureService", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSceneCaptureService_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSceneCaptureService_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_CloseSpatialAnchorService_Parms
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
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CloseSpatialAnchorService_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CloseSpatialAnchorService_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Closes Spatial Anchor service.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nCloses Spatial Anchor service.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_CloseSpatialAnchorService", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSpatialAnchorService_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSpatialAnchorService_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_CloseSpatialMeshScanning_Parms
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
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CloseSpatialMeshScanning_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CloseSpatialMeshScanning_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Closes Spatial Mesh scanning.\n/// </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nCloses Spatial Mesh scanning.\n</summary>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_CloseSpatialMeshScanning", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSpatialMeshScanning_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::PICOXRMRFunctionLibrary_eventPXR_CloseSpatialMeshScanning_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms
		{
			AActor* BoundActor;
			bool bNeverCreateCollision;
			bool bFlipPolygon;
			bool UseWireframe;
			FTransform Transform;
			TArray<FVector> Vertices;
			UMaterialInterface* DefaultMeshMaterial;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundActor;
		static void NewProp_bNeverCreateCollision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNeverCreateCollision;
		static void NewProp_bFlipPolygon_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipPolygon;
		static void NewProp_UseWireframe_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseWireframe;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMeshMaterial;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_BoundActor = { "BoundActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms, BoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bNeverCreateCollision_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms*)Obj)->bNeverCreateCollision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bNeverCreateCollision = { "bNeverCreateCollision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bNeverCreateCollision_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bFlipPolygon_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms*)Obj)->bFlipPolygon = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bFlipPolygon = { "bFlipPolygon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bFlipPolygon_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_UseWireframe_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms*)Obj)->UseWireframe = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_UseWireframe = { "UseWireframe", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_UseWireframe_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Transform_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Transform_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_DefaultMeshMaterial = { "DefaultMeshMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms, DefaultMeshMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_BoundActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bNeverCreateCollision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_bFlipPolygon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_UseWireframe,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_Vertices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_DefaultMeshMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n///  Creates Scene Bounding Polygon.\n/// </summary>\n/// <param name=\"BoundActor\">Specifies the actor bound by polygon.</param>\n/// <param name=\"bNeverCreateCollision\">True if never create collision, false otherwise.</param>\n/// <param name=\"bFlipPolygon\"> True if you want to flip polygon, false otherwise. It is recommend to be ture in Floor type, otherwise the orientation is down, which may affect rendering and collision.</param>\x09\n/// <param name=\"UseWireframe\">True if you want to use Wireframe, false otherwise.</param>\n/// <param name=\"Transform\">The transform of polygon.</param>\n/// <param name=\"Vertices\">The set of vertices.</param>\n/// <param name=\"DefaultMeshMaterial\"> Default mesh material.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\n Creates Scene Bounding Polygon.\n</summary>\n<param name=\"BoundActor\">Specifies the actor bound by polygon.</param>\n<param name=\"bNeverCreateCollision\">True if never create collision, false otherwise.</param>\n<param name=\"bFlipPolygon\"> True if you want to flip polygon, false otherwise. It is recommend to be ture in Floor type, otherwise the orientation is down, which may affect rendering and collision.</param>\n<param name=\"UseWireframe\">True if you want to use Wireframe, false otherwise.</param>\n<param name=\"Transform\">The transform of polygon.</param>\n<param name=\"Vertices\">The set of vertices.</param>\n<param name=\"DefaultMeshMaterial\"> Default mesh material.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_CreateSceneBoundingPolygon", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::PICOXRMRFunctionLibrary_eventPXR_CreateSceneBoundingPolygon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms
		{
			AActor* BoundActor;
			EPICOResult OutResult;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundActor;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutResult_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_BoundActor = { "BoundActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms, BoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_OutResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms, OutResult), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_BoundActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_OutResult_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_OutResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Destroy anchor entity by Actor.\n/// </summary>\n/// <param name=\"BoundActor\">Specifies the Actor for the anchor you want to destroy.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDestroy anchor entity by Actor.\n</summary>\n<param name=\"BoundActor\">Specifies the Actor for the anchor you want to destroy.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_DestroyAnchorByActor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms
		{
			UPICOAnchorComponent* AnchorComponent;
			EPICOResult OutResult;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorComponent;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutResult_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_AnchorComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_AnchorComponent = { "AnchorComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms, AnchorComponent), Z_Construct_UClass_UPICOAnchorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_AnchorComponent_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_AnchorComponent_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_OutResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms, OutResult), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_AnchorComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_OutResult_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_OutResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Destroy anchor entity by AnchorComponent.\n/// </summary>\n/// <param name=\"AnchorComponent\">Specifies the AnchorComponent for the anchor you want to destroy.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDestroy anchor entity by AnchorComponent.\n</summary>\n<param name=\"AnchorComponent\">Specifies the AnchorComponent for the anchor you want to destroy.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_DestroyAnchorByComponent", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_DestroyAnchorByComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_FromAnchorToString_Parms
		{
			FPICOSpatialHandle AnchorHandle;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorHandle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnchorHandle;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_AnchorHandle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_AnchorHandle = { "AnchorHandle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromAnchorToString_Parms, AnchorHandle), Z_Construct_UScriptStruct_FPICOSpatialHandle, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_AnchorHandle_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_AnchorHandle_MetaData) }; // 82442488
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromAnchorToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_AnchorHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// From AnchorHandle To FString.\n/// </summary>\n/// <param name=\"AnchorHandle\">Specifies the AnchorHandle for which you want to convert.</param>\n/// <returns>FString of AnchorHandle.\n/// </returns>\x09\n" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "ToString (Anchor Handle)" },
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nFrom AnchorHandle To FString.\n</summary>\n<param name=\"AnchorHandle\">Specifies the AnchorHandle for which you want to convert.</param>\n<returns>FString of AnchorHandle.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_FromAnchorToString", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PICOXRMRFunctionLibrary_eventPXR_FromAnchorToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::PICOXRMRFunctionLibrary_eventPXR_FromAnchorToString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_FromStringToUUID_Parms
		{
			FString AnchorUUIDString;
			FPICOSpatialUUID ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorUUIDString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AnchorUUIDString;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_AnchorUUIDString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_AnchorUUIDString = { "AnchorUUIDString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromStringToUUID_Parms, AnchorUUIDString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_AnchorUUIDString_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_AnchorUUIDString_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromStringToUUID_Parms, ReturnValue), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(0, nullptr) }; // 4199512061
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_AnchorUUIDString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// From FString To UUID.\n/// </summary>\n/// <param name=\"AnchorUUIDString\">Specifies the AnchorUUIDString for which you want to convert.</param>\n/// <returns>UUID.\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nFrom FString To UUID.\n</summary>\n<param name=\"AnchorUUIDString\">Specifies the AnchorUUIDString for which you want to convert.</param>\n<returns>UUID.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_FromStringToUUID", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PICOXRMRFunctionLibrary_eventPXR_FromStringToUUID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::PICOXRMRFunctionLibrary_eventPXR_FromStringToUUID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_FromUUIDToString_Parms
		{
			FPICOSpatialUUID AnchorUUID;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorUUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnchorUUID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_AnchorUUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_AnchorUUID = { "AnchorUUID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromUUIDToString_Parms, AnchorUUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_AnchorUUID_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_AnchorUUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_FromUUIDToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_AnchorUUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// From UUID To FString.\n/// </summary>\n/// <param name=\"AnchorUUID\">Specifies the AnchorUUID for which you want to convert.</param>\n/// <returns>FString of UUID.\n/// </returns>\x09\n" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "ToString (Anchor UUID)" },
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nFrom UUID To FString.\n</summary>\n<param name=\"AnchorUUID\">Specifies the AnchorUUID for which you want to convert.</param>\n<returns>FString of UUID.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_FromUUIDToString", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PICOXRMRFunctionLibrary_eventPXR_FromUUIDToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::PICOXRMRFunctionLibrary_eventPXR_FromUUIDToString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms
		{
			AActor* BoundActor;
			FPICOSpatialUUID OutAnchorUUID;
			EPICOResult OutResult;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundActor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutAnchorUUID;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutResult_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_BoundActor = { "BoundActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms, BoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutAnchorUUID = { "OutAnchorUUID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms, OutAnchorUUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(0, nullptr) }; // 4199512061
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms, OutResult), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_BoundActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutAnchorUUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutResult_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_OutResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the universally unique identifier (UUID) of an anchor entity.\n/// </summary>\n/// <param name=\"BoundActor\">The bound actor of the anchor entity to get UUID for.</param>\n/// <param name=\"OutAnchorUUID\">Returns the UUID of the anchor entity.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the universally unique identifier (UUID) of an anchor entity.\n</summary>\n<param name=\"BoundActor\">The bound actor of the anchor entity to get UUID for.</param>\n<param name=\"OutAnchorUUID\">Returns the UUID of the anchor entity.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetAnchorEntityUuid", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorEntityUuid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms
		{
			AActor* BoundActor;
			FTransform OutTransform;
			EPICOResult OutResult;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundActor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransform;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutResult_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_BoundActor = { "BoundActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms, BoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutTransform = { "OutTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms, OutTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms, OutResult), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_BoundActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutResult_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_OutResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the pose of an actor's anchor entit by Actor.\n/// </summary>\n/// <param name=\"BoundActor\">Specifies the Actor for which you want to get anchor entity pose information.</param>\n/// <param name=\"OutTransform\">\n/// * `Location`: The location of the anchor entity.\n/// * `Rotation`: The rotation of the anchor entity.\n/// * `Scale`: The scale of the anchor entity. `1` by default.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the pose of an actor's anchor entit by Actor.\n</summary>\n<param name=\"BoundActor\">Specifies the Actor for which you want to get anchor entity pose information.</param>\n<param name=\"OutTransform\">\n* `Location`: The location of the anchor entity.\n* `Rotation`: The rotation of the anchor entity.\n* `Scale`: The scale of the anchor entity. `1` by default.\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetAnchorPoseByActor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms
		{
			UPICOAnchorComponent* AnchorComponent;
			FTransform OutTransform;
			EPICOResult OutResult;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorComponent;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransform;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutResult_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_AnchorComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_AnchorComponent = { "AnchorComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms, AnchorComponent), Z_Construct_UClass_UPICOAnchorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_AnchorComponent_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_AnchorComponent_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutTransform = { "OutTransform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms, OutTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms, OutResult), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_AnchorComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutResult_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_OutResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the pose of an actor's anchor entity by AnchorComponent.\n/// </summary>\n/// <param name=\"AnchorComponent\">Specifies the AnchorComponent for which you want to get anchor entity pose information.</param>\n/// <param name=\"OutTransform\">\n/// * `Location`: The location of the anchor entity.\n/// * `Rotation`: The rotation of the anchor entity.\n/// * `Scale`: The scale of the anchor entity. `1` by default.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the pose of an actor's anchor entity by AnchorComponent.\n</summary>\n<param name=\"AnchorComponent\">Specifies the AnchorComponent for which you want to get anchor entity pose information.</param>\n<param name=\"OutTransform\">\n* `Location`: The location of the anchor entity.\n* `Rotation`: The rotation of the anchor entity.\n* `Scale`: The scale of the anchor entity. `1` by default.\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetAnchorPoseByComponent", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_GetAnchorPoseByComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms
		{
			FPICOSpatialUUID UUID;
			FPICOBoundingBox2D OutBoundingBox2D;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutBoundingBox2D;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_UUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_UUID = { "UUID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms, UUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_UUID_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_UUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_OutBoundingBox2D = { "OutBoundingBox2D", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms, OutBoundingBox2D), Z_Construct_UScriptStruct_FPICOBoundingBox2D, METADATA_PARAMS(0, nullptr) }; // 3672283929
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_UUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_OutBoundingBox2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the information about the Bounding Box 2D for a SceneCapture.\n/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n/// </summary>\n/// <param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n/// <param name=\"OutBoundingBox2D\">\n/// * `Center`: Returns the offset of the boundary's position relative to the world position.\n/// * `Extent`: Returns the width and height of the boundary.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li> `true` - success</li>\n/// <li> `false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the information about the Bounding Box 2D for a SceneCapture.\nBefore calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n</summary>\n<param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n<param name=\"OutBoundingBox2D\">\n* `Center`: Returns the offset of the boundary's position relative to the world position.\n* `Extent`: Returns the width and height of the boundary.\n</param>\n<returns>Bool:\n<ul>\n<li> `true` - success</li>\n<li> `false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSceneBoundingBox2D", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox2D_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms
		{
			FPICOSpatialUUID UUID;
			FPICOBoundingBox3D OutBoundingBox3D;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutBoundingBox3D;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_UUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_UUID = { "UUID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms, UUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_UUID_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_UUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_OutBoundingBox3D = { "OutBoundingBox3D", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms, OutBoundingBox3D), Z_Construct_UScriptStruct_FPICOBoundingBox3D, METADATA_PARAMS(0, nullptr) }; // 112941079
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_UUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_OutBoundingBox3D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the information about the Bounding Box 3D for an SceneCapture.\n/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n/// </summary>\n/// <param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n/// <param name=\"OutBoundingBox3D\">\n/// * `Center`: Returns the offset of the boundary's position relative to the world position.\n/// * `Extent`: Returns the width, height and depth of the boundary.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li> `true` - success</li>\n/// <li> `false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the information about the Bounding Box 3D for an SceneCapture.\nBefore calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n</summary>\n<param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n<param name=\"OutBoundingBox3D\">\n* `Center`: Returns the offset of the boundary's position relative to the world position.\n* `Extent`: Returns the width, height and depth of the boundary.\n</param>\n<returns>Bool:\n<ul>\n<li> `true` - success</li>\n<li> `false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSceneBoundingBox3D", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingBox3D_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms
		{
			FPICOSpatialUUID UUID;
			TArray<FVector> OutPolygonVertices;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UUID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UUID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutPolygonVertices_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutPolygonVertices;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_UUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_UUID = { "UUID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms, UUID), Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_UUID_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_UUID_MetaData) }; // 4199512061
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_OutPolygonVertices_Inner = { "OutPolygonVertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_OutPolygonVertices = { "OutPolygonVertices", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms, OutPolygonVertices), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_UUID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_OutPolygonVertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_OutPolygonVertices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the information about the polygon (irregular plane) for an anchor entity.\n/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n/// </summary>\n/// <param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n/// <param name=\"OutPolygonVertices\">\n/// * `Vertices`: The positions of the polygon's vertices on the X, Y, and Z axis.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the information about the polygon (irregular plane) for an anchor entity.\nBefore calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.\n</summary>\n<param name=\"UUID\"> Specifies the uuid of the SceneCapture. </param>\n<param name=\"OutPolygonVertices\">\n* `Vertices`: The positions of the polygon's vertices on the X, Y, and Z axis.\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSceneBoundingPolygon", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneBoundingPolygon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSceneCaptureServiceState_Parms
		{
			EPICOMRState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSceneCaptureServiceState_Parms, ReturnValue), Z_Construct_UEnum_PICOXRHMD_EPICOMRState, METADATA_PARAMS(0, nullptr) }; // 3874922584
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Get Scene Capture service state.\n/// </summary>\n/// <returns>State of Scene Capture service:\n///\x09- Initialized: After checking the Scene Capture feature in ProjectSettings, the initialization will be completed during the app startup process.\n///\x09- Running: This state is set after the Scene Capture service has been successfully started.\n///\x09- Stopped: This state is set after the Scene Capture service has been successfully shut down.\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGet Scene Capture service state.\n</summary>\n<returns>State of Scene Capture service:\n      - Initialized: After checking the Scene Capture feature in ProjectSettings, the initialization will be completed during the app startup process.\n      - Running: This state is set after the Scene Capture service has been successfully started.\n      - Stopped: This state is set after the Scene Capture service has been successfully shut down.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSceneCaptureServiceState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneCaptureServiceState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSceneCaptureServiceState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSpatialAnchorServiceState_Parms
		{
			EPICOMRState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSpatialAnchorServiceState_Parms, ReturnValue), Z_Construct_UEnum_PICOXRHMD_EPICOMRState, METADATA_PARAMS(0, nullptr) }; // 3874922584
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Get Spatial Anchor service state.\n/// </summary>\n/// <returns>State of Spatial Anchor service:\n///\x09- Initialized: After checking the Spatial Anchor feature in ProjectSettings, the initialization will be completed during the app startup process.\n///\x09- Running: This state is set after the Spatial Anchor service has been successfully started.\n///\x09- Stopped: This state is set after the Spatial Anchor service has been successfully shut down.\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGet Spatial Anchor service state.\n</summary>\n<returns>State of Spatial Anchor service:\n      - Initialized: After checking the Spatial Anchor feature in ProjectSettings, the initialization will be completed during the app startup process.\n      - Running: This state is set after the Spatial Anchor service has been successfully started.\n      - Stopped: This state is set after the Spatial Anchor service has been successfully shut down.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSpatialAnchorServiceState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialAnchorServiceState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialAnchorServiceState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshLodSetting_Parms
		{
			EPICOSpatialMeshLod ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshLodSetting_Parms, ReturnValue), Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod, METADATA_PARAMS(0, nullptr) }; // 1769800351
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets Spatial Mesh Lod Setting.\n/// </summary>\n/// <returns>Spatial Mesh Lod.\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets Spatial Mesh Lod Setting.\n</summary>\n<returns>Spatial Mesh Lod.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSpatialMeshLodSetting", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshLodSetting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshLodSetting_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshScanningState_Parms
		{
			EPICOMRState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshScanningState_Parms, ReturnValue), Z_Construct_UEnum_PICOXRHMD_EPICOMRState, METADATA_PARAMS(0, nullptr) }; // 3874922584
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets Spatial Mesh scanning state.\n/// </summary>\n/// <returns>State of Spatial Mesh scanning:\n///\x09- Initialized: After checking the Spacial Mesh feature in ProjectSettings, the initialization will be completed during the app startup process.\n///\x09- Running: This state is set after the Spatial Mesh scanning has been successfully started.\n///\x09- Stopped: This state is set after the Spatial Mesh scanning has been successfully shut down.\n/// </returns>\x09\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets Spatial Mesh scanning state.\n</summary>\n<returns>State of Spatial Mesh scanning:\n      - Initialized: After checking the Spacial Mesh feature in ProjectSettings, the initialization will be completed during the app startup process.\n      - Running: This state is set after the Spatial Mesh scanning has been successfully started.\n      - Stopped: This state is set after the Spatial Mesh scanning has been successfully shut down.\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_GetSpatialMeshScanningState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshScanningState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::PICOXRMRFunctionLibrary_eventPXR_GetSpatialMeshScanningState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms
		{
			AActor* BoundActor;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundActor;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_BoundActor = { "BoundActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms, BoundActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_BoundActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Checks if an Actor's anchor is valid.\n/// </summary>\n/// <param name=\"BoundActor\">Specifies the Actor for the anchor you want to check.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - valid</li>\n/// <li>`false` - invalid</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nChecks if an Actor's anchor is valid.\n</summary>\n<param name=\"BoundActor\">Specifies the Actor for the anchor you want to check.</param>\n<returns>Bool:\n<ul>\n<li>`true` - valid</li>\n<li>`false` - invalid</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_IsAnchorValidForActor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForActor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms
		{
			UPICOAnchorComponent* AnchorComponent;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnchorComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorComponent;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_AnchorComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_AnchorComponent = { "AnchorComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms, AnchorComponent), Z_Construct_UClass_UPICOAnchorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_AnchorComponent_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_AnchorComponent_MetaData) };
	void Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms), &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_AnchorComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Checks if an AnchorComponent's anchor is valid.\n/// </summary>\n/// <param name=\"AnchorComponent\">Specifies the AnchorComponent for the anchor you want to check.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - valid</li>\n/// <li>`false` - invalid</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nChecks if an AnchorComponent's anchor is valid.\n</summary>\n<param name=\"AnchorComponent\">Specifies the AnchorComponent for the anchor you want to check.</param>\n<returns>Bool:\n<ul>\n<li>`true` - valid</li>\n<li>`false` - invalid</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_IsAnchorValidForComponent", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::PICOXRMRFunctionLibrary_eventPXR_IsAnchorValidForComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Reset Spatial Mesh Infos State.\n/// </summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nReset Spatial Mesh Infos State.\n</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_ResetSpatialMeshInfosState", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics
	{
		struct PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms
		{
			UObject* WorldContext;
			FAnchorLoadResult LoadResult;
			UClass* ActorClass;
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LoadResult;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ActorClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_LoadResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_LoadResult = { "LoadResult", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms, LoadResult), Z_Construct_UScriptStruct_FAnchorLoadResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_LoadResult_MetaData), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_LoadResult_MetaData) }; // 598985502
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms, ActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_WorldContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_LoadResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_ActorClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Spawns an actor from the specified anchor load result.\n/// </summary>\n/// <param name=\"WorldContext\">The world context in which the actor will be spawned.</param>\n/// <param name=\"LoadResult\">The anchor load result containing information for spawning, including the anchor's handle, UUID, and location.</param>\n/// <param name=\"ActorClass\"> The class of the actor to be spawned.</param>\n/// <returns>The spawned actor, or nullptr if spawning fails.\n/// </returns>\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nSpawns an actor from the specified anchor load result.\n</summary>\n<param name=\"WorldContext\">The world context in which the actor will be spawned.</param>\n<param name=\"LoadResult\">The anchor load result containing information for spawning, including the anchor's handle, UUID, and location.</param>\n<param name=\"ActorClass\"> The class of the actor to be spawned.</param>\n<returns>The spawned actor, or nullptr if spawning fails.\n</returns>" },
#endif
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContext" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRMRFunctionLibrary, nullptr, "PXR_SpawnActorFromLoadResult", nullptr, nullptr, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::PICOXRMRFunctionLibrary_eventPXR_SpawnActorFromLoadResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRMRFunctionLibrary);
	UClass* Z_Construct_UClass_UPICOXRMRFunctionLibrary_NoRegister()
	{
		return UPICOXRMRFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ChangeSpatialMeshLodSetting, "PXR_ChangeSpatialMeshLodSetting" }, // 3589538590
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSceneCaptureService, "PXR_CloseSceneCaptureService" }, // 3879155843
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialAnchorService, "PXR_CloseSpatialAnchorService" }, // 786740304
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CloseSpatialMeshScanning, "PXR_CloseSpatialMeshScanning" }, // 3517132620
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_CreateSceneBoundingPolygon, "PXR_CreateSceneBoundingPolygon" }, // 3358578759
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByActor, "PXR_DestroyAnchorByActor" }, // 1915057029
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_DestroyAnchorByComponent, "PXR_DestroyAnchorByComponent" }, // 324463690
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromAnchorToString, "PXR_FromAnchorToString" }, // 1251778904
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromStringToUUID, "PXR_FromStringToUUID" }, // 1178860351
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_FromUUIDToString, "PXR_FromUUIDToString" }, // 154128886
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorEntityUuid, "PXR_GetAnchorEntityUuid" }, // 2627417073
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByActor, "PXR_GetAnchorPoseByActor" }, // 3937055440
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetAnchorPoseByComponent, "PXR_GetAnchorPoseByComponent" }, // 3548728591
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox2D, "PXR_GetSceneBoundingBox2D" }, // 1826621503
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingBox3D, "PXR_GetSceneBoundingBox3D" }, // 4061223392
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneBoundingPolygon, "PXR_GetSceneBoundingPolygon" }, // 724206384
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSceneCaptureServiceState, "PXR_GetSceneCaptureServiceState" }, // 15483697
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialAnchorServiceState, "PXR_GetSpatialAnchorServiceState" }, // 2923710724
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshLodSetting, "PXR_GetSpatialMeshLodSetting" }, // 1183420515
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_GetSpatialMeshScanningState, "PXR_GetSpatialMeshScanningState" }, // 2740100490
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForActor, "PXR_IsAnchorValidForActor" }, // 1937994892
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_IsAnchorValidForComponent, "PXR_IsAnchorValidForComponent" }, // 3579358868
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_ResetSpatialMeshInfosState, "PXR_ResetSpatialMeshInfosState" }, // 2633787712
		{ &Z_Construct_UFunction_UPICOXRMRFunctionLibrary_PXR_SpawnActorFromLoadResult, "PXR_SpawnActorFromLoadResult" }, // 1628575848
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_MRFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_MRFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRMRFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::ClassParams = {
		&UPICOXRMRFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOXRMRFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UPICOXRMRFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRMRFunctionLibrary.OuterSingleton, Z_Construct_UClass_UPICOXRMRFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRMRFunctionLibrary.OuterSingleton;
	}
	template<> PICOXRMR_API UClass* StaticClass<UPICOXRMRFunctionLibrary>()
	{
		return UPICOXRMRFunctionLibrary::StaticClass();
	}
	UPICOXRMRFunctionLibrary::UPICOXRMRFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRMRFunctionLibrary);
	UPICOXRMRFunctionLibrary::~UPICOXRMRFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRMRFunctionLibrary, UPICOXRMRFunctionLibrary::StaticClass, TEXT("UPICOXRMRFunctionLibrary"), &Z_Registration_Info_UClass_UPICOXRMRFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRMRFunctionLibrary), 3543834477U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRFunctionLibrary_h_1910528465(TEXT("/Script/PICOXRMR"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
