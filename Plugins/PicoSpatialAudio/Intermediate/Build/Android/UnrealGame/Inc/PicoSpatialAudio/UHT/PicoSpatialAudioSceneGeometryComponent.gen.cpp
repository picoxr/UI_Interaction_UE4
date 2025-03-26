// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoSpatialAudio/Public/PicoSpatialAudioSceneGeometryComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoSpatialAudioSceneGeometryComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_NoRegister();
	PICOSPATIALAUDIO_API UClass* Z_Construct_UClass_UPicoSpatialAudioSceneMaterialSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PicoSpatialAudio();
// End Cross Module References
	DEFINE_FUNCTION(UPicoSpatialAudioSceneGeometryComponent::execClearBakedMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearBakedMesh();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoSpatialAudioSceneGeometryComponent::execBakeMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BakeMesh();
		P_NATIVE_END;
	}
	void UPicoSpatialAudioSceneGeometryComponent::StaticRegisterNativesUPicoSpatialAudioSceneGeometryComponent()
	{
		UClass* Class = UPicoSpatialAudioSceneGeometryComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BakeMesh", &UPicoSpatialAudioSceneGeometryComponent::execBakeMesh },
			{ "ClearBakedMesh", &UPicoSpatialAudioSceneGeometryComponent::execClearBakedMesh },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Mesh Baking Utilities" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent, nullptr, "BakeMesh", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Mesh Baking Utilities" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent, nullptr, "ClearBakedMesh", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoSpatialAudioSceneGeometryComponent);
	UClass* Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_NoRegister()
	{
		return UPicoSpatialAudioSceneGeometryComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IncludeChildrenActor_MetaData[];
#endif
		static void NewProp_IncludeChildrenActor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IncludeChildrenActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IncludeChildrenComponent_MetaData[];
#endif
		static void NewProp_IncludeChildrenComponent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IncludeChildrenComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaterialSettings_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialSettings;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GatheredStaticMeshes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GatheredStaticMeshes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GatheredStaticMeshes;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BatchedBakedMeshVerticesBuffer_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BatchedBakedMeshVerticesBuffer_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BatchedBakedMeshVerticesBuffer;
		static const UECodeGen_Private::FIntPropertyParams NewProp_BatchedBakedMeshIndicesBuffer_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BatchedBakedMeshIndicesBuffer_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BatchedBakedMeshIndicesBuffer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_BakeMesh, "BakeMesh" }, // 2484111682
		{ &Z_Construct_UFunction_UPicoSpatialAudioSceneGeometryComponent_ClearBakedMesh, "ClearBakedMesh" }, // 2418961573
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Audio" },
		{ "HideCategories", "Transform Activation Collision Cooking Trigger PhysicsVolume" },
		{ "IncludePath", "PicoSpatialAudioSceneGeometryComponent.h" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component" },
#endif
	};
#endif
	void Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor_SetBit(void* Obj)
	{
		((UPicoSpatialAudioSceneGeometryComponent*)Obj)->IncludeChildrenActor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor = { "IncludeChildrenActor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPicoSpatialAudioSceneGeometryComponent), &Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component" },
#endif
	};
#endif
	void Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent_SetBit(void* Obj)
	{
		((UPicoSpatialAudioSceneGeometryComponent*)Obj)->IncludeChildrenComponent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent = { "IncludeChildrenComponent", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPicoSpatialAudioSceneGeometryComponent), &Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_MaterialSettings_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_MaterialSettings = { "MaterialSettings", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSceneGeometryComponent, MaterialSettings), Z_Construct_UClass_UPicoSpatialAudioSceneMaterialSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_MaterialSettings_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_MaterialSettings_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes_Inner = { "GatheredStaticMeshes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\x09""Add UPROPERTY() to prevent GatheredStaticMeshes being garbage collected at unknown time\n" },
#endif
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add UPROPERTY() to prevent GatheredStaticMeshes being garbage collected at unknown time" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes = { "GatheredStaticMeshes", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSceneGeometryComponent, GatheredStaticMeshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer_Inner = { "BatchedBakedMeshVerticesBuffer", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer_MetaData[] = {
		{ "Category", "Mesh Baking Utilities" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer = { "BatchedBakedMeshVerticesBuffer", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSceneGeometryComponent, BatchedBakedMeshVerticesBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer_Inner = { "BatchedBakedMeshIndicesBuffer", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer_MetaData[] = {
		{ "Category", "Mesh Baking Utilities" },
		{ "ModuleRelativePath", "Public/PicoSpatialAudioSceneGeometryComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer = { "BatchedBakedMeshIndicesBuffer", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoSpatialAudioSceneGeometryComponent, BatchedBakedMeshIndicesBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer_MetaData), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_IncludeChildrenComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_MaterialSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_GatheredStaticMeshes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshVerticesBuffer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::NewProp_BatchedBakedMeshIndicesBuffer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoSpatialAudioSceneGeometryComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::ClassParams = {
		&UPicoSpatialAudioSceneGeometryComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent()
	{
		if (!Z_Registration_Info_UClass_UPicoSpatialAudioSceneGeometryComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoSpatialAudioSceneGeometryComponent.OuterSingleton, Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoSpatialAudioSceneGeometryComponent.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UClass* StaticClass<UPicoSpatialAudioSceneGeometryComponent>()
	{
		return UPicoSpatialAudioSceneGeometryComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoSpatialAudioSceneGeometryComponent);
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSceneGeometryComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSceneGeometryComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoSpatialAudioSceneGeometryComponent, UPicoSpatialAudioSceneGeometryComponent::StaticClass, TEXT("UPicoSpatialAudioSceneGeometryComponent"), &Z_Registration_Info_UClass_UPicoSpatialAudioSceneGeometryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoSpatialAudioSceneGeometryComponent), 3555303052U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSceneGeometryComponent_h_3332116428(TEXT("/Script/PicoSpatialAudio"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSceneGeometryComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Public_PicoSpatialAudioSceneGeometryComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
