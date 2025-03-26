// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Private/PXR_BoundarySystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_BoundarySystem() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRBoundarySystem();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRBoundarySystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	void UPICOXRBoundarySystem::StaticRegisterNativesUPICOXRBoundarySystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRBoundarySystem);
	UClass* Z_Construct_UClass_UPICOXRBoundarySystem_NoRegister()
	{
		return UPICOXRBoundarySystem::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRBoundarySystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRBoundarySystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRBoundarySystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRBoundarySystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_BoundarySystem.h" },
		{ "ModuleRelativePath", "Private/PXR_BoundarySystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRBoundarySystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRBoundarySystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRBoundarySystem_Statics::ClassParams = {
		&UPICOXRBoundarySystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRBoundarySystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRBoundarySystem_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOXRBoundarySystem()
	{
		if (!Z_Registration_Info_UClass_UPICOXRBoundarySystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRBoundarySystem.OuterSingleton, Z_Construct_UClass_UPICOXRBoundarySystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRBoundarySystem.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<UPICOXRBoundarySystem>()
	{
		return UPICOXRBoundarySystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRBoundarySystem);
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_BoundarySystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_BoundarySystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRBoundarySystem, UPICOXRBoundarySystem::StaticClass, TEXT("UPICOXRBoundarySystem"), &Z_Registration_Info_UClass_UPICOXRBoundarySystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRBoundarySystem), 875652031U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_BoundarySystem_h_997329367(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_BoundarySystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_BoundarySystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
