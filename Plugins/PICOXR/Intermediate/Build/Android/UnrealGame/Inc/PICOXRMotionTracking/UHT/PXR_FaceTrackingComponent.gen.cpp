// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMotionTracking/Public/PXR_FaceTrackingComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_FaceTrackingComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_USkinnedMeshComponent_NoRegister();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPXR_FaceTrackingComponent();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPXR_FaceTrackingComponent_NoRegister();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceBlendShape();
	UPackage* Z_Construct_UPackage__Script_PICOXRMotionTracking();
// End Cross Module References
	DEFINE_FUNCTION(UPXR_FaceTrackingComponent::execClearBlendShapeValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearBlendShapeValues();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPXR_FaceTrackingComponent::execGetBlendShapeValue)
	{
		P_GET_ENUM(EPXRFaceBlendShape,Z_Param_BlendShape);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetBlendShapeValue(EPXRFaceBlendShape(Z_Param_BlendShape));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPXR_FaceTrackingComponent::execSetBlendShapeValue)
	{
		P_GET_ENUM(EPXRFaceBlendShape,Z_Param_BlendShape);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetBlendShapeValue(EPXRFaceBlendShape(Z_Param_BlendShape),Z_Param_Value);
		P_NATIVE_END;
	}
	void UPXR_FaceTrackingComponent::StaticRegisterNativesUPXR_FaceTrackingComponent()
	{
		UClass* Class = UPXR_FaceTrackingComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClearBlendShapeValues", &UPXR_FaceTrackingComponent::execClearBlendShapeValues },
			{ "GetBlendShapeValue", &UPXR_FaceTrackingComponent::execGetBlendShapeValue },
			{ "SetBlendShapeValue", &UPXR_FaceTrackingComponent::execSetBlendShapeValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPXR_FaceTrackingComponent, nullptr, "ClearBlendShapeValues", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics
	{
		struct PXR_FaceTrackingComponent_eventGetBlendShapeValue_Parms
		{
			EPXRFaceBlendShape BlendShape;
			float ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_BlendShape_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BlendShape;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_BlendShape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_BlendShape = { "BlendShape", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXR_FaceTrackingComponent_eventGetBlendShapeValue_Parms, BlendShape), Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceBlendShape, METADATA_PARAMS(0, nullptr) }; // 880534043
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXR_FaceTrackingComponent_eventGetBlendShapeValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_BlendShape_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_BlendShape,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPXR_FaceTrackingComponent, nullptr, "GetBlendShapeValue", nullptr, nullptr, Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PXR_FaceTrackingComponent_eventGetBlendShapeValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::PXR_FaceTrackingComponent_eventGetBlendShapeValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics
	{
		struct PXR_FaceTrackingComponent_eventSetBlendShapeValue_Parms
		{
			EPXRFaceBlendShape BlendShape;
			float Value;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_BlendShape_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BlendShape;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_BlendShape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_BlendShape = { "BlendShape", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXR_FaceTrackingComponent_eventSetBlendShapeValue_Parms, BlendShape), Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceBlendShape, METADATA_PARAMS(0, nullptr) }; // 880534043
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PXR_FaceTrackingComponent_eventSetBlendShapeValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_BlendShape_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_BlendShape,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Components|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPXR_FaceTrackingComponent, nullptr, "SetBlendShapeValue", nullptr, nullptr, Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PXR_FaceTrackingComponent_eventSetBlendShapeValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::PXR_FaceTrackingComponent_eventSetBlendShapeValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPXR_FaceTrackingComponent);
	UClass* Z_Construct_UClass_UPXR_FaceTrackingComponent_NoRegister()
	{
		return UPXR_FaceTrackingComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FTTargetMeshComponentName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_FTTargetMeshComponentName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InvalidFaceDataResetTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InvalidFaceDataResetTime;
		static const UECodeGen_Private::FNamePropertyParams NewProp_BlendShapeNameMapping_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BlendShapeNameMapping_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BlendShapeNameMapping_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BlendShapeNameMapping_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_BlendShapeNameMapping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateFaceTracking_MetaData[];
#endif
		static void NewProp_bUpdateFaceTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateFaceTracking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FTTargetMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FTTargetMeshComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMotionTracking,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPXR_FaceTrackingComponent_ClearBlendShapeValues, "ClearBlendShapeValues" }, // 2661444644
		{ &Z_Construct_UFunction_UPXR_FaceTrackingComponent_GetBlendShapeValue, "GetBlendShapeValue" }, // 2928901390
		{ &Z_Construct_UFunction_UPXR_FaceTrackingComponent_SetBlendShapeValue, "SetBlendShapeValue" }, // 2150859062
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "PXRHMD" },
		{ "DisplayName", "PICO Face Tracking Component" },
		{ "IncludePath", "PXR_FaceTrackingComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponentName_MetaData[] = {
		{ "Category", "PXR|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponentName = { "FTTargetMeshComponentName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_FaceTrackingComponent, FTTargetMeshComponentName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponentName_MetaData), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponentName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime_MetaData[] = {
		{ "Category", "PXR|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime = { "InvalidFaceDataResetTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_FaceTrackingComponent, InvalidFaceDataResetTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime_MetaData), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_ValueProp = { "BlendShapeNameMapping", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_Key_KeyProp = { "BlendShapeNameMapping_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMotionTracking_EPXRFaceBlendShape, METADATA_PARAMS(0, nullptr) }; // 880534043
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_MetaData[] = {
		{ "Category", "PXR|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping = { "BlendShapeNameMapping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_FaceTrackingComponent, BlendShapeNameMapping), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_MetaData), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_MetaData) }; // 880534043
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking_MetaData[] = {
		{ "Category", "PXR|FaceTracking" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking_SetBit(void* Obj)
	{
		((UPXR_FaceTrackingComponent*)Obj)->bUpdateFaceTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking = { "bUpdateFaceTracking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPXR_FaceTrackingComponent), &Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking_MetaData), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PXR_FaceTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponent = { "FTTargetMeshComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_FaceTrackingComponent, FTTargetMeshComponent), Z_Construct_UClass_USkinnedMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponent_MetaData), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponentName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_BlendShapeNameMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_bUpdateFaceTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::NewProp_FTTargetMeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPXR_FaceTrackingComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::ClassParams = {
		&UPXR_FaceTrackingComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPXR_FaceTrackingComponent()
	{
		if (!Z_Registration_Info_UClass_UPXR_FaceTrackingComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPXR_FaceTrackingComponent.OuterSingleton, Z_Construct_UClass_UPXR_FaceTrackingComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPXR_FaceTrackingComponent.OuterSingleton;
	}
	template<> PICOXRMOTIONTRACKING_API UClass* StaticClass<UPXR_FaceTrackingComponent>()
	{
		return UPXR_FaceTrackingComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPXR_FaceTrackingComponent);
	UPXR_FaceTrackingComponent::~UPXR_FaceTrackingComponent() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_FaceTrackingComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_FaceTrackingComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPXR_FaceTrackingComponent, UPXR_FaceTrackingComponent::StaticClass, TEXT("UPXR_FaceTrackingComponent"), &Z_Registration_Info_UClass_UPXR_FaceTrackingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPXR_FaceTrackingComponent), 457614577U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_FaceTrackingComponent_h_4105203399(TEXT("/Script/PICOXRMotionTracking"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_FaceTrackingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_FaceTrackingComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
