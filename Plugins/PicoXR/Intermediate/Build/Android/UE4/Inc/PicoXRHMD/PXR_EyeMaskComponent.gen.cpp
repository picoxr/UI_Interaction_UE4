// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRHMD/Private/PXR_EyeMaskComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_EyeMaskComponent() {}
// Cross Module References
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXREyeMaskComponent_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXREyeMaskComponent();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent();
	UPackage* Z_Construct_UPackage__Script_PicoXRHMD();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	void UPicoXREyeMaskComponent::StaticRegisterNativesUPicoXREyeMaskComponent()
	{
	}
	UClass* Z_Construct_UClass_UPicoXREyeMaskComponent_NoRegister()
	{
		return UPicoXREyeMaskComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPicoXREyeMaskComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UseDebugMesh_MetaData[];
#endif
		static void NewProp_UseDebugMesh_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_UseDebugMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UseEyeSpecifiedMesh_MetaData[];
#endif
		static void NewProp_UseEyeSpecifiedMesh_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_UseEyeSpecifiedMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UProceduralMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "PXRComponent" },
		{ "HideCategories", "Object LOD Mobility Trigger" },
		{ "IncludePath", "PXR_EyeMaskComponent.h" },
		{ "ModuleRelativePath", "Private/PXR_EyeMaskComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "Default" },
		{ "Comment", "// This is used for debug.  Setting a color instead of black will help developer to see if it is working.\n" },
		{ "ModuleRelativePath", "Private/PXR_EyeMaskComponent.h" },
		{ "ToolTip", "This is used for debug.  Setting a color instead of black will help developer to see if it is working." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREyeMaskComponent, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_Color_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh_MetaData[] = {
		{ "Category", "Default" },
		{ "Comment", "// This is used for debug.  On Editor or some device didn't have RenderMask, set UseDebugMesh true to show a debug mesh.\n" },
		{ "ModuleRelativePath", "Private/PXR_EyeMaskComponent.h" },
		{ "ToolTip", "This is used for debug.  On Editor or some device didn't have RenderMask, set UseDebugMesh true to show a debug mesh." },
	};
#endif
	void Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh_SetBit(void* Obj)
	{
		((UPicoXREyeMaskComponent*)Obj)->UseDebugMesh = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh = { "UseDebugMesh", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPicoXREyeMaskComponent), &Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh_MetaData[] = {
		{ "Category", "Default" },
		{ "Comment", "// This is work if UseDebugMesh is true.  This will indicate the left and right eye's mesh, and make them more obviously.\n" },
		{ "ModuleRelativePath", "Private/PXR_EyeMaskComponent.h" },
		{ "ToolTip", "This is work if UseDebugMesh is true.  This will indicate the left and right eye's mesh, and make them more obviously." },
	};
#endif
	void Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh_SetBit(void* Obj)
	{
		((UPicoXREyeMaskComponent*)Obj)->UseEyeSpecifiedMesh = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh = { "UseEyeSpecifiedMesh", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPicoXREyeMaskComponent), &Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseDebugMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::NewProp_UseEyeSpecifiedMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoXREyeMaskComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::ClassParams = {
		&UPicoXREyeMaskComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::PropPointers),
		0,
		0x00A000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPicoXREyeMaskComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPicoXREyeMaskComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPicoXREyeMaskComponent, 4235974319);
	template<> PICOXRHMD_API UClass* StaticClass<UPicoXREyeMaskComponent>()
	{
		return UPicoXREyeMaskComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPicoXREyeMaskComponent(Z_Construct_UClass_UPicoXREyeMaskComponent, &UPicoXREyeMaskComponent::StaticClass, TEXT("/Script/PicoXRHMD"), TEXT("UPicoXREyeMaskComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoXREyeMaskComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
