// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoSpatialAudio/Public/PicoSpatializationSourceDirectivityVisualizer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoSpatializationSourceDirectivityVisualizer() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_NoRegister();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatializationSourceSettings_NoRegister();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PicoSpatialAudio();
// End Cross Module References
	DEFINE_FUNCTION(APicoSpatializationSourceDirectivityVisualizer::execSetMaterial)
	{
		P_GET_OBJECT(UMaterial,Z_Param_InMaterial);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaterial(Z_Param_InMaterial);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APicoSpatializationSourceDirectivityVisualizer::execGetSettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPicoSpatializationSourceSettings**)Z_Param__Result=P_THIS->GetSettings();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APicoSpatializationSourceDirectivityVisualizer::execSetSettings)
	{
		P_GET_OBJECT(UPicoSpatializationSourceSettings,Z_Param_InSettings);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSettings(Z_Param_InSettings);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APicoSpatializationSourceDirectivityVisualizer::execDrawPattern)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DrawPattern();
		P_NATIVE_END;
	}
	void APicoSpatializationSourceDirectivityVisualizer::StaticRegisterNativesAPicoSpatializationSourceDirectivityVisualizer()
	{
		UClass* Class = APicoSpatializationSourceDirectivityVisualizer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DrawPattern", &APicoSpatializationSourceDirectivityVisualizer::execDrawPattern },
			{ "GetSettings", &APicoSpatializationSourceDirectivityVisualizer::execGetSettings },
			{ "SetMaterial", &APicoSpatializationSourceDirectivityVisualizer::execSetMaterial },
			{ "SetSettings", &APicoSpatializationSourceDirectivityVisualizer::execSetSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics::Function_MetaDataParams[] = {
		{ "Category", "PicoSpatialAudio|PolarPatternVisualizer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Draws given directivity pattern as a 2D mesh based on Settings.\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Draws given directivity pattern as a 2D mesh based on Settings." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer, nullptr, "DrawPattern", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics::Function_MetaDataParams), Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics
	{
		struct PicoSpatializationSourceDirectivityVisualizer_eventGetSettings_Parms
		{
			UPicoSpatializationSourceSettings* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoSpatializationSourceDirectivityVisualizer_eventGetSettings_Parms, ReturnValue), Z_Construct_UClass_UPicoSpatializationSourceSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "PicoSpatialAudio|PolarPatternVisualizer" },
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer, nullptr, "GetSettings", nullptr, nullptr, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PicoSpatializationSourceDirectivityVisualizer_eventGetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::PicoSpatializationSourceDirectivityVisualizer_eventGetSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics
	{
		struct PicoSpatializationSourceDirectivityVisualizer_eventSetMaterial_Parms
		{
			UMaterial* InMaterial;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::NewProp_InMaterial = { "InMaterial", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoSpatializationSourceDirectivityVisualizer_eventSetMaterial_Parms, InMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::NewProp_InMaterial,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "PicoSpatialAudio|PolarPatternVisualizer" },
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer, nullptr, "SetMaterial", nullptr, nullptr, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PicoSpatializationSourceDirectivityVisualizer_eventSetMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::PicoSpatializationSourceDirectivityVisualizer_eventSetMaterial_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics
	{
		struct PicoSpatializationSourceDirectivityVisualizer_eventSetSettings_Parms
		{
			UPicoSpatializationSourceSettings* InSettings;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::NewProp_InSettings = { "InSettings", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoSpatializationSourceDirectivityVisualizer_eventSetSettings_Parms, InSettings), Z_Construct_UClass_UPicoSpatializationSourceSettings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::NewProp_InSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "PicoSpatialAudio|PolarPatternVisualizer" },
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer, nullptr, "SetSettings", nullptr, nullptr, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PicoSpatializationSourceDirectivityVisualizer_eventSetSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::PicoSpatializationSourceDirectivityVisualizer_eventSetSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APicoSpatializationSourceDirectivityVisualizer);
	UClass* Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_NoRegister()
	{
		return APicoSpatializationSourceDirectivityVisualizer::StaticClass();
	}
	struct Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Settings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_DrawPattern, "DrawPattern" }, // 216197940
		{ &Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_GetSettings, "GetSettings" }, // 2650812334
		{ &Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetMaterial, "SetMaterial" }, // 348979825
		{ &Z_Construct_UFunction_APicoSpatializationSourceDirectivityVisualizer_SetSettings, "SetSettings" }, // 1745275667
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PicoSpatializationSourceDirectivityVisualizer.h" },
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "APicoSpatializationSourceDirectivityVisualizer" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Mesh,Rendering,Physics,Components|ProceduralMesh" },
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APicoSpatializationSourceDirectivityVisualizer, Mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Material_MetaData[] = {
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APicoSpatializationSourceDirectivityVisualizer, Material), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Material_MetaData), Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Material_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Settings_MetaData[] = {
		{ "ModuleRelativePath", "Public/PicoSpatializationSourceDirectivityVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APicoSpatializationSourceDirectivityVisualizer, Settings), Z_Construct_UClass_UPicoSpatializationSourceSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Settings_MetaData), Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Settings_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Material,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::NewProp_Settings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APicoSpatializationSourceDirectivityVisualizer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::ClassParams = {
		&APicoSpatializationSourceDirectivityVisualizer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::Class_MetaDataParams), Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer()
	{
		if (!Z_Registration_Info_UClass_APicoSpatializationSourceDirectivityVisualizer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APicoSpatializationSourceDirectivityVisualizer.OuterSingleton, Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APicoSpatializationSourceDirectivityVisualizer.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UClass* StaticClass<APicoSpatializationSourceDirectivityVisualizer>()
	{
		return APicoSpatializationSourceDirectivityVisualizer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APicoSpatializationSourceDirectivityVisualizer);
	APicoSpatializationSourceDirectivityVisualizer::~APicoSpatializationSourceDirectivityVisualizer() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatializationSourceDirectivityVisualizer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatializationSourceDirectivityVisualizer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APicoSpatializationSourceDirectivityVisualizer, APicoSpatializationSourceDirectivityVisualizer::StaticClass, TEXT("APicoSpatializationSourceDirectivityVisualizer"), &Z_Registration_Info_UClass_APicoSpatializationSourceDirectivityVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APicoSpatializationSourceDirectivityVisualizer), 3084908357U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatializationSourceDirectivityVisualizer_h_3536900366(TEXT("/Script/PicoSpatialAudio"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatializationSourceDirectivityVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatializationSourceDirectivityVisualizer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
