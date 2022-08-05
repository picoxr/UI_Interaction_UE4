// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRHMD/Public/PXR_HMDTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_HMDTypes() {}
// Cross Module References
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPicoSplashDesc();
	UPackage* Z_Construct_UPackage__Script_PicoXRHMD();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
// End Cross Module References
class UScriptStruct* FPicoSplashDesc::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PICOXRHMD_API uint32 Get_Z_Construct_UScriptStruct_FPicoSplashDesc_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPicoSplashDesc, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("PicoSplashDesc"), sizeof(FPicoSplashDesc), Get_Z_Construct_UScriptStruct_FPicoSplashDesc_Hash());
	}
	return Singleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPicoSplashDesc>()
{
	return FPicoSplashDesc::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPicoSplashDesc(FPicoSplashDesc::StaticStruct, TEXT("/Script/PicoXRHMD"), TEXT("PicoSplashDesc"), false, nullptr, nullptr);
static struct FScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoSplashDesc
{
	FScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoSplashDesc()
	{
		UScriptStruct::DeferCppStructOps<FPicoSplashDesc>(FName(TEXT("PicoSplashDesc")));
	}
} ScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoSplashDesc;
	struct Z_Construct_UScriptStruct_FPicoSplashDesc_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TexturePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TexturePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransformInMeters_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TransformInMeters;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QuadSizeInMeters_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_QuadSizeInMeters;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeltaRotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DeltaRotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextureOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TextureOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextureScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TextureScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNoAlphaChannel_MetaData[];
#endif
		static void NewProp_bNoAlphaChannel_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNoAlphaChannel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPicoSplashDesc>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TexturePath_MetaData[] = {
		{ "AllowedClasses", "Texture" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "Texture show" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TexturePath = { "TexturePath", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, TexturePath), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TexturePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TexturePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TransformInMeters_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "Transform the center (meters)." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TransformInMeters = { "TransformInMeters", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, TransformInMeters), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TransformInMeters_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TransformInMeters_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_QuadSizeInMeters_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "The meter is the basic unit." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_QuadSizeInMeters = { "QuadSizeInMeters", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, QuadSizeInMeters), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_QuadSizeInMeters_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_QuadSizeInMeters_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_DeltaRotation_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "Add a rotation increment for each render frame." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_DeltaRotation = { "DeltaRotation", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, DeltaRotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_DeltaRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_DeltaRotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureOffset_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "The upper left corner is the starting point of the texture offset." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureOffset = { "TextureOffset", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, TextureOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureScale_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "Texture scale (the default size is recommended)." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureScale = { "TextureScale", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoSplashDesc, TextureScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "ToolTip", "Whether to use alpha channel." },
	};
#endif
	void Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel_SetBit(void* Obj)
	{
		((FPicoSplashDesc*)Obj)->bNoAlphaChannel = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel = { "bNoAlphaChannel", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPicoSplashDesc), &Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TexturePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TransformInMeters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_QuadSizeInMeters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_DeltaRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_TextureScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::NewProp_bNoAlphaChannel,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
		nullptr,
		&NewStructOps,
		"PicoSplashDesc",
		sizeof(FPicoSplashDesc),
		alignof(FPicoSplashDesc),
		Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPicoSplashDesc()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPicoSplashDesc_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PicoSplashDesc"), sizeof(FPicoSplashDesc), Get_Z_Construct_UScriptStruct_FPicoSplashDesc_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPicoSplashDesc_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPicoSplashDesc_Hash() { return 3310616330U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
