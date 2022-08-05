// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRMRC/Private/PXR_MRCState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MRCState() {}
// Cross Module References
	PICOXRMRC_API UClass* Z_Construct_UClass_UPXRInGameThirdCamState_NoRegister();
	PICOXRMRC_API UClass* Z_Construct_UClass_UPXRInGameThirdCamState();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_PicoXRMRC();
// End Cross Module References
	void UPXRInGameThirdCamState::StaticRegisterNativesUPXRInGameThirdCamState()
	{
	}
	UClass* Z_Construct_UClass_UPXRInGameThirdCamState_NoRegister()
	{
		return UPXRInGameThirdCamState::StaticClass();
	}
	struct Z_Construct_UClass_UPXRInGameThirdCamState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPXRInGameThirdCamState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRMRC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPXRInGameThirdCamState_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_MRCState.h" },
		{ "ModuleRelativePath", "Private/PXR_MRCState.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPXRInGameThirdCamState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPXRInGameThirdCamState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPXRInGameThirdCamState_Statics::ClassParams = {
		&UPXRInGameThirdCamState::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UPXRInGameThirdCamState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPXRInGameThirdCamState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPXRInGameThirdCamState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPXRInGameThirdCamState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPXRInGameThirdCamState, 5799737);
	template<> PICOXRMRC_API UClass* StaticClass<UPXRInGameThirdCamState>()
	{
		return UPXRInGameThirdCamState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPXRInGameThirdCamState(Z_Construct_UClass_UPXRInGameThirdCamState, &UPXRInGameThirdCamState::StaticClass, TEXT("/Script/PicoXRMRC"), TEXT("UPXRInGameThirdCamState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPXRInGameThirdCamState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
