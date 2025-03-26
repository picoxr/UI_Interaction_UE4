// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoSpatialAudio/Private/PxrAudioSpatializerReverb.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePxrAudioSpatializerReverb() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USoundEffectSubmixPreset();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_NoRegister();
	PICOSPATIALAUDIO_API UScriptStruct* Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings();
	UPackage* Z_Construct_UPackage__Script_PicoSpatialAudio();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings;
class UScriptStruct* FPxrAudioSpatializerReverbPluginSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings, (UObject*)Z_Construct_UPackage__Script_PicoSpatialAudio(), TEXT("PxrAudioSpatializerReverbPluginSettings"));
	}
	return Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.OuterSingleton;
}
template<> PICOSPATIALAUDIO_API UScriptStruct* StaticStruct<FPxrAudioSpatializerReverbPluginSettings>()
{
	return FPxrAudioSpatializerReverbPluginSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/PxrAudioSpatializerReverb.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPxrAudioSpatializerReverbPluginSettings>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
		nullptr,
		&NewStructOps,
		"PxrAudioSpatializerReverbPluginSettings",
		nullptr,
		0,
		sizeof(FPxrAudioSpatializerReverbPluginSettings),
		alignof(FPxrAudioSpatializerReverbPluginSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.InnerSingleton, Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings.InnerSingleton;
	}
	DEFINE_FUNCTION(UPxrAudioSpatializerReverbPluginPreset::execSetSettings)
	{
		P_GET_STRUCT_REF(FPxrAudioSpatializerReverbPluginSettings,Z_Param_Out_InSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSettings(Z_Param_Out_InSettings);
		P_NATIVE_END;
	}
	void UPxrAudioSpatializerReverbPluginPreset::StaticRegisterNativesUPxrAudioSpatializerReverbPluginPreset()
	{
		UClass* Class = UPxrAudioSpatializerReverbPluginPreset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetSettings", &UPxrAudioSpatializerReverbPluginPreset::execSetSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics
	{
		struct PxrAudioSpatializerReverbPluginPreset_eventSetSettings_Parms
		{
			FPxrAudioSpatializerReverbPluginSettings InSettings;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::NewProp_InSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::NewProp_InSettings = { "InSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PxrAudioSpatializerReverbPluginPreset_eventSetSettings_Parms, InSettings), Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::NewProp_InSettings_MetaData), Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::NewProp_InSettings_MetaData) }; // 1948942113
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::NewProp_InSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/PxrAudioSpatializerReverb.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset, nullptr, "SetSettings", nullptr, nullptr, Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PxrAudioSpatializerReverbPluginPreset_eventSetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::PxrAudioSpatializerReverbPluginPreset_eventSetSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPxrAudioSpatializerReverbPluginPreset);
	UClass* Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_NoRegister()
	{
		return UPxrAudioSpatializerReverbPluginPreset::StaticClass();
	}
	struct Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USoundEffectSubmixPreset,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPxrAudioSpatializerReverbPluginPreset_SetSettings, "SetSettings" }, // 2444778087
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "PxrAudioSpatializerReverb.h" },
		{ "ModuleRelativePath", "Private/PxrAudioSpatializerReverb.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::NewProp_Settings_MetaData[] = {
		{ "ModuleRelativePath", "Private/PxrAudioSpatializerReverb.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPxrAudioSpatializerReverbPluginPreset, Settings), Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::NewProp_Settings_MetaData), Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::NewProp_Settings_MetaData) }; // 1948942113
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::NewProp_Settings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPxrAudioSpatializerReverbPluginPreset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::ClassParams = {
		&UPxrAudioSpatializerReverbPluginPreset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::PropPointers),
		0,
		0x001010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::Class_MetaDataParams), Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset()
	{
		if (!Z_Registration_Info_UClass_UPxrAudioSpatializerReverbPluginPreset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPxrAudioSpatializerReverbPluginPreset.OuterSingleton, Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPxrAudioSpatializerReverbPluginPreset.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UClass* StaticClass<UPxrAudioSpatializerReverbPluginPreset>()
	{
		return UPxrAudioSpatializerReverbPluginPreset::StaticClass();
	}
	UPxrAudioSpatializerReverbPluginPreset::UPxrAudioSpatializerReverbPluginPreset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPxrAudioSpatializerReverbPluginPreset);
	UPxrAudioSpatializerReverbPluginPreset::~UPxrAudioSpatializerReverbPluginPreset() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ScriptStructInfo[] = {
		{ FPxrAudioSpatializerReverbPluginSettings::StaticStruct, Z_Construct_UScriptStruct_FPxrAudioSpatializerReverbPluginSettings_Statics::NewStructOps, TEXT("PxrAudioSpatializerReverbPluginSettings"), &Z_Registration_Info_UScriptStruct_PxrAudioSpatializerReverbPluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPxrAudioSpatializerReverbPluginSettings), 1948942113U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPxrAudioSpatializerReverbPluginPreset, UPxrAudioSpatializerReverbPluginPreset::StaticClass, TEXT("UPxrAudioSpatializerReverbPluginPreset"), &Z_Registration_Info_UClass_UPxrAudioSpatializerReverbPluginPreset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPxrAudioSpatializerReverbPluginPreset), 2816219644U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_3493799718(TEXT("/Script/PicoSpatialAudio"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PxrAudioSpatializerReverb_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
