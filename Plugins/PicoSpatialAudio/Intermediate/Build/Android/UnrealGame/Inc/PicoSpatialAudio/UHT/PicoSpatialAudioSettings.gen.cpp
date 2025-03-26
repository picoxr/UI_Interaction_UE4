// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoSpatialAudio/Public/PicoSpatialAudioSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoSpatialAudioSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatialAudioSettings();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatialAudioSettings_NoRegister();
	PICOSPATIALAUDIO_API UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode();
	UPackage* Z_Construct_UPackage__Script_PicoSpatialAudio();
// End Cross Module References
	void UPicoSpatialAudioSettings::StaticRegisterNativesUPicoSpatialAudioSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoSpatialAudioSettings);
	UClass* Z_Construct_UClass_UPicoSpatialAudioSettings_NoRegister()
	{
		return UPicoSpatialAudioSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPicoSpatialAudioSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutputSubmix_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutputSubmix;
		static const UECodeGen_Private::FBytePropertyParams NewProp_RenderingMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderingMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RenderingMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "PicoSpatialAudioSettings.h" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_OutputSubmix_MetaData[] = {
		{ "AllowedClasses", "SoundSubmix" },
		{ "Category", "Audio Routing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reference to submix where reverb plugin audio is routed.\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to submix where reverb plugin audio is routed." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_OutputSubmix = { "OutputSubmix", nullptr, (EPropertyFlags)0x0010000000044001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSettings, OutputSubmix), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_OutputSubmix_MetaData), Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_OutputSubmix_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode_MetaData[] = {
		{ "Category", "Rendering Quality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Global Rendering Quality for Pico Spatial Audio\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Global Rendering Quality for Pico Spatial Audio" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode = { "RenderingMode", nullptr, (EPropertyFlags)0x0010000000044001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSettings, RenderingMode), Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode_MetaData), Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode_MetaData) }; // 3759791498
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_OutputSubmix,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::NewProp_RenderingMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoSpatialAudioSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::ClassParams = {
		&UPicoSpatialAudioSettings::StaticClass,
		"Plugin",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPicoSpatialAudioSettings()
	{
		if (!Z_Registration_Info_UClass_UPicoSpatialAudioSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoSpatialAudioSettings.OuterSingleton, Z_Construct_UClass_UPicoSpatialAudioSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoSpatialAudioSettings.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UClass* StaticClass<UPicoSpatialAudioSettings>()
	{
		return UPicoSpatialAudioSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoSpatialAudioSettings);
	UPicoSpatialAudioSettings::~UPicoSpatialAudioSettings() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoSpatialAudioSettings, UPicoSpatialAudioSettings::StaticClass, TEXT("UPicoSpatialAudioSettings"), &Z_Registration_Info_UClass_UPicoSpatialAudioSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoSpatialAudioSettings), 1722131559U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSettings_h_3949039143(TEXT("/Script/PicoSpatialAudio"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
