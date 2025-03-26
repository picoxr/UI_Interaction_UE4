// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Public/PICO_MRCSceneCapture2D.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePICO_MRCSceneCapture2D() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_AMRCSceneCapture2DPICO();
	PICOXRHMD_API UClass* Z_Construct_UClass_AMRCSceneCapture2DPICO_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	void AMRCSceneCapture2DPICO::StaticRegisterNativesAMRCSceneCapture2DPICO()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRCSceneCapture2DPICO);
	UClass* Z_Construct_UClass_AMRCSceneCapture2DPICO_NoRegister()
	{
		return AMRCSceneCapture2DPICO::StaticClass();
	}
	struct Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundRT_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BackgroundRT;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForegroundRT_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ForegroundRT;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASceneCapture2D,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "PICOXRComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Material Attachment Actor Collision Attachment Actor" },
		{ "IncludePath", "PICO_MRCSceneCapture2D.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/PICO_MRCSceneCapture2D.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_StaticMeshComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PICO_MRCSceneCapture2D.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_StaticMeshComponent = { "StaticMeshComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRCSceneCapture2DPICO, StaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_StaticMeshComponent_MetaData), Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_StaticMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_BackgroundRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/PICO_MRCSceneCapture2D.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_BackgroundRT = { "BackgroundRT", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRCSceneCapture2DPICO, BackgroundRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_BackgroundRT_MetaData), Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_BackgroundRT_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_ForegroundRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/PICO_MRCSceneCapture2D.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_ForegroundRT = { "ForegroundRT", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRCSceneCapture2DPICO, ForegroundRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_ForegroundRT_MetaData), Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_ForegroundRT_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_StaticMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_BackgroundRT,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::NewProp_ForegroundRT,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRCSceneCapture2DPICO>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::ClassParams = {
		&AMRCSceneCapture2DPICO::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMRCSceneCapture2DPICO()
	{
		if (!Z_Registration_Info_UClass_AMRCSceneCapture2DPICO.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRCSceneCapture2DPICO.OuterSingleton, Z_Construct_UClass_AMRCSceneCapture2DPICO_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMRCSceneCapture2DPICO.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<AMRCSceneCapture2DPICO>()
	{
		return AMRCSceneCapture2DPICO::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMRCSceneCapture2DPICO);
	AMRCSceneCapture2DPICO::~AMRCSceneCapture2DPICO() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PICO_MRCSceneCapture2D_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PICO_MRCSceneCapture2D_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMRCSceneCapture2DPICO, AMRCSceneCapture2DPICO::StaticClass, TEXT("AMRCSceneCapture2DPICO"), &Z_Registration_Info_UClass_AMRCSceneCapture2DPICO, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRCSceneCapture2DPICO), 555141050U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PICO_MRCSceneCapture2D_h_3653318603(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PICO_MRCSceneCapture2D_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PICO_MRCSceneCapture2D_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
