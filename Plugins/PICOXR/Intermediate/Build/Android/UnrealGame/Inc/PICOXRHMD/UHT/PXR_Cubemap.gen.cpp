// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Public/PXR_Cubemap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_Cubemap() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_APXR_Cubemap();
	PICOXRHMD_API UClass* Z_Construct_UClass_APXR_Cubemap_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	DEFINE_FUNCTION(APXR_Cubemap::execPXR_CubemapHandler)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PXR_CubemapHandler();
		P_NATIVE_END;
	}
	void APXR_Cubemap::StaticRegisterNativesAPXR_Cubemap()
	{
		UClass* Class = APXR_Cubemap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PXR_CubemapHandler", &APXR_Cubemap::execPXR_CubemapHandler },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_Cubemap.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APXR_Cubemap, nullptr, "PXR_CubemapHandler", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics::Function_MetaDataParams), Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APXR_Cubemap);
	UClass* Z_Construct_UClass_APXR_Cubemap_NoRegister()
	{
		return APXR_Cubemap::StaticClass();
	}
	struct Z_Construct_UClass_APXR_Cubemap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CaptureComponents;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APXR_Cubemap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APXR_Cubemap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APXR_Cubemap_PXR_CubemapHandler, "PXR_CubemapHandler" }, // 1962092348
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXR_Cubemap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_Cubemap.h" },
		{ "ModuleRelativePath", "Public/PXR_Cubemap.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents_Inner = { "CaptureComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PXR_Cubemap.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents = { "CaptureComponents", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APXR_Cubemap, CaptureComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents_MetaData), Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APXR_Cubemap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APXR_Cubemap_Statics::NewProp_CaptureComponents,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APXR_Cubemap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APXR_Cubemap>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APXR_Cubemap_Statics::ClassParams = {
		&APXR_Cubemap::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APXR_Cubemap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::Class_MetaDataParams), Z_Construct_UClass_APXR_Cubemap_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APXR_Cubemap_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APXR_Cubemap()
	{
		if (!Z_Registration_Info_UClass_APXR_Cubemap.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APXR_Cubemap.OuterSingleton, Z_Construct_UClass_APXR_Cubemap_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APXR_Cubemap.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<APXR_Cubemap>()
	{
		return APXR_Cubemap::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APXR_Cubemap);
	APXR_Cubemap::~APXR_Cubemap() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_Cubemap_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_Cubemap_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APXR_Cubemap, APXR_Cubemap::StaticClass, TEXT("APXR_Cubemap"), &Z_Registration_Info_UClass_APXR_Cubemap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APXR_Cubemap), 1623468812U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_Cubemap_h_552459855(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_Cubemap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_Cubemap_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
