// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRMRC/Public/PXR_MRCFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MRCFunctionLibrary() {}
// Cross Module References
	PICOXRMRC_API UClass* Z_Construct_UClass_UPicoXRMRCFunctionLibrary_NoRegister();
	PICOXRMRC_API UClass* Z_Construct_UClass_UPicoXRMRCFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_PicoXRMRC();
// End Cross Module References
	void UPicoXRMRCFunctionLibrary::StaticRegisterNativesUPicoXRMRCFunctionLibrary()
	{
	}
	UClass* Z_Construct_UClass_UPicoXRMRCFunctionLibrary_NoRegister()
	{
		return UPicoXRMRCFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRMRC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_MRCFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_MRCFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoXRMRCFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::ClassParams = {
		&UPicoXRMRCFunctionLibrary::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPicoXRMRCFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPicoXRMRCFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPicoXRMRCFunctionLibrary, 2017479994);
	template<> PICOXRMRC_API UClass* StaticClass<UPicoXRMRCFunctionLibrary>()
	{
		return UPicoXRMRCFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPicoXRMRCFunctionLibrary(Z_Construct_UClass_UPicoXRMRCFunctionLibrary, &UPicoXRMRCFunctionLibrary::StaticClass, TEXT("/Script/PicoXRMRC"), TEXT("UPicoXRMRCFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoXRMRCFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
