// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Classes/PicoNetDriver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoNetDriver() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoNetDriver();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoNetDriver_NoRegister();
	ONLINESUBSYSTEMUTILS_API UClass* Z_Construct_UClass_UIpNetDriver();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	void UPicoNetDriver::StaticRegisterNativesUPicoNetDriver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoNetDriver);
	UClass* Z_Construct_UClass_UPicoNetDriver_NoRegister()
	{
		return UPicoNetDriver::StaticClass();
	}
	struct Z_Construct_UClass_UPicoNetDriver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoNetDriver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UIpNetDriver,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoNetDriver_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoNetDriver_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "PicoNetDriver.h" },
		{ "ModuleRelativePath", "Classes/PicoNetDriver.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoNetDriver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoNetDriver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoNetDriver_Statics::ClassParams = {
		&UPicoNetDriver::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoNetDriver_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoNetDriver_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPicoNetDriver()
	{
		if (!Z_Registration_Info_UClass_UPicoNetDriver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoNetDriver.OuterSingleton, Z_Construct_UClass_UPicoNetDriver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoNetDriver.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPicoNetDriver>()
	{
		return UPicoNetDriver::StaticClass();
	}
	UPicoNetDriver::UPicoNetDriver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoNetDriver);
	UPicoNetDriver::~UPicoNetDriver() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetDriver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetDriver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoNetDriver, UPicoNetDriver::StaticClass, TEXT("UPicoNetDriver"), &Z_Registration_Info_UClass_UPicoNetDriver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoNetDriver), 3437926976U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetDriver_h_901398129(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetDriver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetDriver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
