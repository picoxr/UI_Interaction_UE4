// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMR/Public/PXR_SpatialMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_SpatialMeshComponent() {}
// Cross Module References
	MRMESH_API UClass* Z_Construct_UClass_UMRMeshComponent();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOSpatialMeshComponent();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOSpatialMeshComponent_NoRegister();
	PICOXRMR_API UEnum* Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel();
	UPackage* Z_Construct_UPackage__Script_PICOXRMR();
// End Cross Module References
	DEFINE_FUNCTION(UPICOSpatialMeshComponent::execGetSemanticByIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOSemanticLabel*)Z_Param__Result=P_THIS->GetSemanticByIndex(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPICOSpatialMeshComponent::StaticRegisterNativesUPICOSpatialMeshComponent()
	{
		UClass* Class = UPICOSpatialMeshComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetSemanticByIndex", &UPICOSpatialMeshComponent::execGetSemanticByIndex },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics
	{
		struct PICOSpatialMeshComponent_eventGetSemanticByIndex_Parms
		{
			int32 Index;
			EPICOSemanticLabel ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOSpatialMeshComponent_eventGetSemanticByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOSpatialMeshComponent_eventGetSemanticByIndex_Parms, ReturnValue), Z_Construct_UEnum_PICOXRMR_EPICOSemanticLabel, METADATA_PARAMS(0, nullptr) }; // 1135071056
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRMR" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOSpatialMeshComponent, nullptr, "GetSemanticByIndex", nullptr, nullptr, Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PICOSpatialMeshComponent_eventGetSemanticByIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::PICOSpatialMeshComponent_eventGetSemanticByIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOSpatialMeshComponent);
	UClass* Z_Construct_UClass_UPICOSpatialMeshComponent_NoRegister()
	{
		return UPICOSpatialMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPICOSpatialMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMRMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOSpatialMeshComponent_GetSemanticByIndex, "GetSemanticByIndex" }, // 3187856718
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Rendering" },
		{ "HideCategories", "Object LOD Physics Mobility VirtualTexture Trigger" },
		{ "IncludePath", "PXR_SpatialMeshComponent.h" },
		{ "ModuleRelativePath", "Public/PXR_SpatialMeshComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOSpatialMeshComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::ClassParams = {
		&UPICOSpatialMeshComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00A000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOSpatialMeshComponent()
	{
		if (!Z_Registration_Info_UClass_UPICOSpatialMeshComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOSpatialMeshComponent.OuterSingleton, Z_Construct_UClass_UPICOSpatialMeshComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOSpatialMeshComponent.OuterSingleton;
	}
	template<> PICOXRMR_API UClass* StaticClass<UPICOSpatialMeshComponent>()
	{
		return UPICOSpatialMeshComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOSpatialMeshComponent);
	UPICOSpatialMeshComponent::~UPICOSpatialMeshComponent() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOSpatialMeshComponent, UPICOSpatialMeshComponent::StaticClass, TEXT("UPICOSpatialMeshComponent"), &Z_Registration_Info_UClass_UPICOSpatialMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOSpatialMeshComponent), 3141416066U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshComponent_h_2149982381(TEXT("/Script/PICOXRMR"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
