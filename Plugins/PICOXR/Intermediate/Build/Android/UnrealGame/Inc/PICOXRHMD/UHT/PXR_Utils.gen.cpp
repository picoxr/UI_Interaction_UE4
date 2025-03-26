// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Private/PXR_Utils.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_Utils() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOContentResourceFinder();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOContentResourceFinder_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	void UPICOContentResourceFinder::StaticRegisterNativesUPICOContentResourceFinder()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOContentResourceFinder);
	UClass* Z_Construct_UClass_UPICOContentResourceFinder_NoRegister()
	{
		return UPICOContentResourceFinder::StaticClass();
	}
	struct Z_Construct_UClass_UPICOContentResourceFinder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StereoLayerDepthMat_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StereoLayerDepthMat;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOContentResourceFinder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOContentResourceFinder_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOContentResourceFinder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_Utils.h" },
		{ "ModuleRelativePath", "Private/PXR_Utils.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOContentResourceFinder_Statics::NewProp_StereoLayerDepthMat_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_Utils.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPICOContentResourceFinder_Statics::NewProp_StereoLayerDepthMat = { "StereoLayerDepthMat", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOContentResourceFinder, StereoLayerDepthMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOContentResourceFinder_Statics::NewProp_StereoLayerDepthMat_MetaData), Z_Construct_UClass_UPICOContentResourceFinder_Statics::NewProp_StereoLayerDepthMat_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPICOContentResourceFinder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOContentResourceFinder_Statics::NewProp_StereoLayerDepthMat,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOContentResourceFinder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOContentResourceFinder>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOContentResourceFinder_Statics::ClassParams = {
		&UPICOContentResourceFinder::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPICOContentResourceFinder_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPICOContentResourceFinder_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOContentResourceFinder_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOContentResourceFinder_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOContentResourceFinder_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPICOContentResourceFinder()
	{
		if (!Z_Registration_Info_UClass_UPICOContentResourceFinder.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOContentResourceFinder.OuterSingleton, Z_Construct_UClass_UPICOContentResourceFinder_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOContentResourceFinder.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<UPICOContentResourceFinder>()
	{
		return UPICOContentResourceFinder::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOContentResourceFinder);
	UPICOContentResourceFinder::~UPICOContentResourceFinder() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_Utils_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_Utils_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOContentResourceFinder, UPICOContentResourceFinder::StaticClass, TEXT("UPICOContentResourceFinder"), &Z_Registration_Info_UClass_UPICOContentResourceFinder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOContentResourceFinder), 359246845U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_Utils_h_397223728(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_Utils_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_Utils_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
