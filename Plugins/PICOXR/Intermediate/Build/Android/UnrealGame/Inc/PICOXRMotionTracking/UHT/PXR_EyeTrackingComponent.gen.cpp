// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMotionTracking/Public/PXR_EyeTrackingComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_EyeTrackingComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPoseableMeshComponent_NoRegister();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPXR_EyeTrackingComponent();
	PICOXRMOTIONTRACKING_API UClass* Z_Construct_UClass_UPXR_EyeTrackingComponent_NoRegister();
	PICOXRMOTIONTRACKING_API UEnum* Z_Construct_UEnum_PICOXRMotionTracking_EPICOEye();
	UPackage* Z_Construct_UPackage__Script_PICOXRMotionTracking();
// End Cross Module References
	DEFINE_FUNCTION(UPXR_EyeTrackingComponent::execResetEyeRotationValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetEyeRotationValues();
		P_NATIVE_END;
	}
	void UPXR_EyeTrackingComponent::StaticRegisterNativesUPXR_EyeTrackingComponent()
	{
		UClass* Class = UPXR_EyeTrackingComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetEyeRotationValues", &UPXR_EyeTrackingComponent::execResetEyeRotationValues },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPXR_EyeTrackingComponent, nullptr, "ResetEyeRotationValues", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPXR_EyeTrackingComponent);
	UClass* Z_Construct_UClass_UPXR_EyeTrackingComponent_NoRegister()
	{
		return UPXR_EyeTrackingComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ETTargetMeshComponentName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_ETTargetMeshComponentName;
		static const UECodeGen_Private::FNamePropertyParams NewProp_EyeToBoneMapping_ValueProp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EyeToBoneMapping_Key_KeyProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EyeToBoneMapping_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EyeToBoneMapping_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_EyeToBoneMapping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUpdatePosition_MetaData[];
#endif
		static void NewProp_bUpdatePosition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdatePosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateRotation_MetaData[];
#endif
		static void NewProp_bUpdateRotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConfidenceThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ConfidenceThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCanEyeDataInvalid_MetaData[];
#endif
		static void NewProp_bCanEyeDataInvalid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanEyeDataInvalid;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ETTargetMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ETTargetMeshComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMotionTracking,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPXR_EyeTrackingComponent_ResetEyeRotationValues, "ResetEyeRotationValues" }, // 3025175795
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusHMD" },
		{ "DisplayName", "PICO Eye Tracking Component" },
		{ "IncludePath", "PXR_EyeTrackingComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponentName_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponentName = { "ETTargetMeshComponentName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_EyeTrackingComponent, ETTargetMeshComponentName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponentName_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponentName_MetaData) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_ValueProp = { "EyeToBoneMapping", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_Key_KeyProp = { "EyeToBoneMapping_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_PICOXRMotionTracking_EPICOEye, METADATA_PARAMS(0, nullptr) }; // 1423056054
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping = { "EyeToBoneMapping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_EyeTrackingComponent, EyeToBoneMapping), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_MetaData) }; // 1423056054
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition_SetBit(void* Obj)
	{
		((UPXR_EyeTrackingComponent*)Obj)->bUpdatePosition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition = { "bUpdatePosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPXR_EyeTrackingComponent), &Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation_SetBit(void* Obj)
	{
		((UPXR_EyeTrackingComponent*)Obj)->bUpdateRotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation = { "bUpdateRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPXR_EyeTrackingComponent), &Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ConfidenceThreshold_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ConfidenceThreshold = { "ConfidenceThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_EyeTrackingComponent, ConfidenceThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ConfidenceThreshold_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ConfidenceThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid_MetaData[] = {
		{ "Category", "PXR|EyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid_SetBit(void* Obj)
	{
		((UPXR_EyeTrackingComponent*)Obj)->bCanEyeDataInvalid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid = { "bCanEyeDataInvalid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPXR_EyeTrackingComponent), &Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PXR_EyeTrackingComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponent = { "ETTargetMeshComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPXR_EyeTrackingComponent, ETTargetMeshComponent), Z_Construct_UClass_UPoseableMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponent_MetaData), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponentName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_Key_KeyProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_EyeToBoneMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdatePosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bUpdateRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ConfidenceThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_bCanEyeDataInvalid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::NewProp_ETTargetMeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPXR_EyeTrackingComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::ClassParams = {
		&UPXR_EyeTrackingComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPXR_EyeTrackingComponent()
	{
		if (!Z_Registration_Info_UClass_UPXR_EyeTrackingComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPXR_EyeTrackingComponent.OuterSingleton, Z_Construct_UClass_UPXR_EyeTrackingComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPXR_EyeTrackingComponent.OuterSingleton;
	}
	template<> PICOXRMOTIONTRACKING_API UClass* StaticClass<UPXR_EyeTrackingComponent>()
	{
		return UPXR_EyeTrackingComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPXR_EyeTrackingComponent);
	UPXR_EyeTrackingComponent::~UPXR_EyeTrackingComponent() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_EyeTrackingComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_EyeTrackingComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPXR_EyeTrackingComponent, UPXR_EyeTrackingComponent::StaticClass, TEXT("UPXR_EyeTrackingComponent"), &Z_Registration_Info_UClass_UPXR_EyeTrackingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPXR_EyeTrackingComponent), 3517447867U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_EyeTrackingComponent_h_678640803(TEXT("/Script/PICOXRMotionTracking"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_EyeTrackingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_EyeTrackingComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
