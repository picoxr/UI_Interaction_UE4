// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/PICOPlatformSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePICOPlatformSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlineSubsystemPicoManager_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPICOPlatformSubsystem();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPICOPlatformSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	void UPICOPlatformSubsystem::StaticRegisterNativesUPICOPlatformSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOPlatformSubsystem);
	UClass* Z_Construct_UClass_UPICOPlatformSubsystem_NoRegister()
	{
		return UPICOPlatformSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UPICOPlatformSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PicoManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PicoManager;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOPlatformSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOPlatformSubsystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOPlatformSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PICOPlatformSubsystem.h" },
		{ "ModuleRelativePath", "Public/PICOPlatformSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOPlatformSubsystem_Statics::NewProp_PicoManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/PICOPlatformSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPICOPlatformSubsystem_Statics::NewProp_PicoManager = { "PicoManager", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOPlatformSubsystem, PicoManager), Z_Construct_UClass_UOnlineSubsystemPicoManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOPlatformSubsystem_Statics::NewProp_PicoManager_MetaData), Z_Construct_UClass_UPICOPlatformSubsystem_Statics::NewProp_PicoManager_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPICOPlatformSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOPlatformSubsystem_Statics::NewProp_PicoManager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOPlatformSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOPlatformSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOPlatformSubsystem_Statics::ClassParams = {
		&UPICOPlatformSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPICOPlatformSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPICOPlatformSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOPlatformSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOPlatformSubsystem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOPlatformSubsystem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPICOPlatformSubsystem()
	{
		if (!Z_Registration_Info_UClass_UPICOPlatformSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOPlatformSubsystem.OuterSingleton, Z_Construct_UClass_UPICOPlatformSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOPlatformSubsystem.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPICOPlatformSubsystem>()
	{
		return UPICOPlatformSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOPlatformSubsystem);
	UPICOPlatformSubsystem::~UPICOPlatformSubsystem() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_PICOPlatformSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_PICOPlatformSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOPlatformSubsystem, UPICOPlatformSubsystem::StaticClass, TEXT("UPICOPlatformSubsystem"), &Z_Registration_Info_UClass_UPICOPlatformSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOPlatformSubsystem), 2115574395U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_PICOPlatformSubsystem_h_1043320208(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_PICOPlatformSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_PICOPlatformSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
