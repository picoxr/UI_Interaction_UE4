// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMR/Public/PXR_SpatialMeshActor.h"
#include "PICOXRMR/Public/PXR_MRTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_SpatialMeshActor() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionEnabled();
	PICOXRMR_API UClass* Z_Construct_UClass_APXRSpatialMeshActor();
	PICOXRMR_API UClass* Z_Construct_UClass_APXRSpatialMeshActor_NoRegister();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOSpatialMeshComponent_NoRegister();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOResult();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialMeshInfo();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialUUID();
	UPackage* Z_Construct_UPackage__Script_PICOXRMR();
// End Cross Module References
	DEFINE_FUNCTION(APXRSpatialMeshActor::execHandleMeshDataUpdatedEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleMeshDataUpdatedEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execHandleRequestSpatialMeshContentsEvent)
	{
		P_GET_ENUM(EPICOResult,Z_Param_Result);
		P_GET_TARRAY_REF(FPICOSpatialMeshInfo,Z_Param_Out_MeshInfos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleRequestSpatialMeshContentsEvent(EPICOResult(Z_Param_Result),Z_Param_Out_MeshInfos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execClearMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ClearMesh();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execSetMeshVisibility)
	{
		P_GET_UBOOL(Z_Param_visibility);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMeshVisibility(Z_Param_visibility);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execPauseDraw)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PauseDraw();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execStartDraw)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->StartDraw();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APXRSpatialMeshActor::execSetSemanticToColors)
	{
		P_GET_TMAP_REF(EPICOSemanticLabel,FLinearColor,Z_Param_Out_In_SemanticToColors);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSemanticToColors(Z_Param_Out_In_SemanticToColors);
		P_NATIVE_END;
	}
	void APXRSpatialMeshActor::StaticRegisterNativesAPXRSpatialMeshActor()
	{
		UClass* Class = APXRSpatialMeshActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClearMesh", &APXRSpatialMeshActor::execClearMesh },
			{ "HandleMeshDataUpdatedEvent", &APXRSpatialMeshActor::execHandleMeshDataUpdatedEvent },
			{ "HandleRequestSpatialMeshContentsEvent", &APXRSpatialMeshActor::execHandleRequestSpatialMeshContentsEvent },
			{ "PauseDraw", &APXRSpatialMeshActor::execPauseDraw },
			{ "SetMeshVisibility", &APXRSpatialMeshActor::execSetMeshVisibility },
			{ "SetSemanticToColors", &APXRSpatialMeshActor::execSetSemanticToColors },
			{ "StartDraw", &APXRSpatialMeshActor::execStartDraw },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics
	{
		struct PXRSpatialMeshActor_eventClearMesh_Parms
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
	void Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PXRSpatialMeshActor_eventClearMesh_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PXRSpatialMeshActor_eventClearMesh_Parms), &Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "ClearMesh", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PXRSpatialMeshActor_eventClearMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::PXRSpatialMeshActor_eventClearMesh_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "HandleMeshDataUpdatedEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics
	{
		struct PXRSpatialMeshActor_eventHandleRequestSpatialMeshContentsEvent_Parms
		{
			EPICOResult Result;
			TArray<FPICOSpatialMeshInfo> MeshInfos;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshInfos_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshInfos_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_MeshInfos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXRSpatialMeshActor_eventHandleRequestSpatialMeshContentsEvent_Parms, Result), Z_Construct_UEnum_PICOXRMR_EPICOResult, METADATA_PARAMS(0, nullptr) }; // 1390192157
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos_Inner = { "MeshInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPICOSpatialMeshInfo, METADATA_PARAMS(0, nullptr) }; // 1430625674
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos = { "MeshInfos", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXRSpatialMeshActor_eventHandleRequestSpatialMeshContentsEvent_Parms, MeshInfos), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos_MetaData), Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos_MetaData) }; // 1430625674
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::NewProp_MeshInfos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "HandleRequestSpatialMeshContentsEvent", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PXRSpatialMeshActor_eventHandleRequestSpatialMeshContentsEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::PXRSpatialMeshActor_eventHandleRequestSpatialMeshContentsEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics
	{
		struct PXRSpatialMeshActor_eventPauseDraw_Parms
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
	void Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PXRSpatialMeshActor_eventPauseDraw_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PXRSpatialMeshActor_eventPauseDraw_Parms), &Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "PauseDraw", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PXRSpatialMeshActor_eventPauseDraw_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::PXRSpatialMeshActor_eventPauseDraw_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics
	{
		struct PXRSpatialMeshActor_eventSetMeshVisibility_Parms
		{
			bool visibility;
		};
		static void NewProp_visibility_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_visibility;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::NewProp_visibility_SetBit(void* Obj)
	{
		((PXRSpatialMeshActor_eventSetMeshVisibility_Parms*)Obj)->visibility = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::NewProp_visibility = { "visibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PXRSpatialMeshActor_eventSetMeshVisibility_Parms), &Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::NewProp_visibility_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::NewProp_visibility,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "SetMeshVisibility", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PXRSpatialMeshActor_eventSetMeshVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::PXRSpatialMeshActor_eventSetMeshVisibility_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics
	{
		struct PXRSpatialMeshActor_eventSetSemanticToColors_Parms
		{
			TMap<EPICOSemanticLabel,FLinearColor> In_SemanticToColors;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_In_SemanticToColors_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_In_SemanticToColors_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_In_SemanticToColors_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_In_SemanticToColors_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_In_SemanticToColors;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_ValueProp = { "In_SemanticToColors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_Key_KeyProp = { "In_SemanticToColors_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(0, nullptr) }; // 1135071056
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors = { "In_SemanticToColors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXRSpatialMeshActor_eventSetSemanticToColors_Parms, In_SemanticToColors), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_MetaData), Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_MetaData) }; // 1135071056
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::NewProp_In_SemanticToColors,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "SetSemanticToColors", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PXRSpatialMeshActor_eventSetSemanticToColors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::PXRSpatialMeshActor_eventSetSemanticToColors_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics
	{
		struct PXRSpatialMeshActor_eventStartDraw_Parms
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
	void Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PXRSpatialMeshActor_eventStartDraw_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PXRSpatialMeshActor_eventStartDraw_Parms), &Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXRSpatialMeshActor, nullptr, "StartDraw", nullptr, nullptr, Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PropPointers), sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PXRSpatialMeshActor_eventStartDraw_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::PXRSpatialMeshActor_eventStartDraw_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APXRSpatialMeshActor);
	UClass* Z_Construct_UClass_APXRSpatialMeshActor_NoRegister()
	{
		return APXRSpatialMeshActor::StaticClass();
	}
	struct Z_Construct_UClass_APXRSpatialMeshActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawOnBeginPlay_MetaData[];
#endif
		static void NewProp_bDrawOnBeginPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawOnBeginPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpatialMeshMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpatialMeshMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSpatialMeshVisible_MetaData[];
#endif
		static void NewProp_bSpatialMeshVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpatialMeshVisible;
		static const UECodeGen_Private::FStructPropertyParams NewProp_SemanticToColors_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SemanticToColors_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SemanticToColors_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SemanticToColors_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_SemanticToColors;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EntityToMeshMap_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_EntityToMeshMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntityToMeshMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_EntityToMeshMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpatialMeshInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpatialMeshInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APXRSpatialMeshActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APXRSpatialMeshActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_ClearMesh, "ClearMesh" }, // 462495093
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_HandleMeshDataUpdatedEvent, "HandleMeshDataUpdatedEvent" }, // 2676728581
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_HandleRequestSpatialMeshContentsEvent, "HandleRequestSpatialMeshContentsEvent" }, // 3659735841
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_PauseDraw, "PauseDraw" }, // 3401366303
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_SetMeshVisibility, "SetMeshVisibility" }, // 1857850583
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_SetSemanticToColors, "SetSemanticToColors" }, // 3757678919
		{ &Z_Construct_UFunction_APXRSpatialMeshActor_StartDraw, "StartDraw" }, // 753645067
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "PICO XR SpatialMesh Actor" },
		{ "IncludePath", "PXR_SpatialMeshActor.h" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay_MetaData[] = {
		{ "Category", "PXR MR Spatial Mesh" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	void Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay_SetBit(void* Obj)
	{
		((APXRSpatialMeshActor*)Obj)->bDrawOnBeginPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay = { "bDrawOnBeginPlay", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APXRSpatialMeshActor), &Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshMaterial_MetaData[] = {
		{ "Category", "PXR MR Spatial Mesh" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshMaterial = { "SpatialMeshMaterial", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXRSpatialMeshActor, SpatialMeshMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshMaterial_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_CollisionType_MetaData[] = {
		{ "Category", "PXR MR Spatial Mesh" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_CollisionType = { "CollisionType", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXRSpatialMeshActor, CollisionType), Z_Construct_UEnum_Engine_ECollisionEnabled, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_CollisionType_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_CollisionType_MetaData) }; // 3760430637
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible_MetaData[] = {
		{ "Category", "PXR MR Spatial Mesh" },
		{ "ExposeOnSpawn", "TRUE" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	void Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible_SetBit(void* Obj)
	{
		((APXRSpatialMeshActor*)Obj)->bSpatialMeshVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible = { "bSpatialMeshVisible", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APXRSpatialMeshActor), &Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_ValueProp = { "SemanticToColors", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_Key_KeyProp = { "SemanticToColors_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(0, nullptr) }; // 1135071056
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_MetaData[] = {
		{ "Category", "PXR MR Spatial Mesh" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors = { "SemanticToColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXRSpatialMeshActor, SemanticToColors), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_MetaData) }; // 1135071056
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_ValueProp = { "EntityToMeshMap", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UPICOSpatialMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_Key_KeyProp = { "EntityToMeshMap_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPICOSpatialUUID, METADATA_PARAMS(0, nullptr) }; // 4199512061
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap = { "EntityToMeshMap", nullptr, (EPropertyFlags)0x0020088000002008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXRSpatialMeshActor, EntityToMeshMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_MetaData) }; // 4199512061
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshInstance = { "SpatialMeshInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXRSpatialMeshActor, SpatialMeshInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshInstance_MetaData), Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshInstance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APXRSpatialMeshActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bDrawOnBeginPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_CollisionType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_bSpatialMeshVisible,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SemanticToColors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_EntityToMeshMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXRSpatialMeshActor_Statics::NewProp_SpatialMeshInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APXRSpatialMeshActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APXRSpatialMeshActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APXRSpatialMeshActor_Statics::ClassParams = {
		&APXRSpatialMeshActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APXRSpatialMeshActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::Class_MetaDataParams), Z_Construct_UClass_APXRSpatialMeshActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXRSpatialMeshActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APXRSpatialMeshActor()
	{
		if (!Z_Registration_Info_UClass_APXRSpatialMeshActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APXRSpatialMeshActor.OuterSingleton, Z_Construct_UClass_APXRSpatialMeshActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APXRSpatialMeshActor.OuterSingleton;
	}
	template<> PICOXRMR_API UClass* StaticClass<APXRSpatialMeshActor>()
	{
		return APXRSpatialMeshActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APXRSpatialMeshActor);
	APXRSpatialMeshActor::~APXRSpatialMeshActor() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APXRSpatialMeshActor, APXRSpatialMeshActor::StaticClass, TEXT("APXRSpatialMeshActor"), &Z_Registration_Info_UClass_APXRSpatialMeshActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APXRSpatialMeshActor), 1421481704U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_2644105365(TEXT("/Script/PICOXRMR"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
