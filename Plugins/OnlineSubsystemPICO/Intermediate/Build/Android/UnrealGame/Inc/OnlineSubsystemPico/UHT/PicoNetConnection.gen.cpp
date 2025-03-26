// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Classes/PicoNetConnection.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoNetConnection() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoNetConnection();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoNetConnection_NoRegister();
	ONLINESUBSYSTEMUTILS_API UClass* Z_Construct_UClass_UIpConnection();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	void UPicoNetConnection::StaticRegisterNativesUPicoNetConnection()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoNetConnection);
	UClass* Z_Construct_UClass_UPicoNetConnection_NoRegister()
	{
		return UPicoNetConnection::StaticClass();
	}
	struct Z_Construct_UClass_UPicoNetConnection_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoNetConnection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UIpConnection,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoNetConnection_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoNetConnection_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "IncludePath", "PicoNetConnection.h" },
		{ "ModuleRelativePath", "Classes/PicoNetConnection.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoNetConnection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoNetConnection>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoNetConnection_Statics::ClassParams = {
		&UPicoNetConnection::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoNetConnection_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoNetConnection_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPicoNetConnection()
	{
		if (!Z_Registration_Info_UClass_UPicoNetConnection.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoNetConnection.OuterSingleton, Z_Construct_UClass_UPicoNetConnection_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoNetConnection.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPicoNetConnection>()
	{
		return UPicoNetConnection::StaticClass();
	}
	UPicoNetConnection::UPicoNetConnection(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoNetConnection);
	UPicoNetConnection::~UPicoNetConnection() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetConnection_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetConnection_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoNetConnection, UPicoNetConnection::StaticClass, TEXT("UPicoNetConnection"), &Z_Registration_Info_UClass_UPicoNetConnection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoNetConnection), 4162033165U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetConnection_h_2294734989(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetConnection_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoNetConnection_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
