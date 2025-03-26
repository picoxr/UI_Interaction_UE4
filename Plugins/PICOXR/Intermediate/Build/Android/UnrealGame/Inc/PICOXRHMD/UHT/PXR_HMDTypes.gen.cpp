// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Public/PXR_HMDTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_HMDTypes() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOMRState();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPXRSplashDesc();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PXRSplashDesc;
class UScriptStruct* FPXRSplashDesc::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PXRSplashDesc.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PXRSplashDesc.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPXRSplashDesc, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PXRSplashDesc"));
	}
	return Z_Registration_Info_UScriptStruct_PXRSplashDesc.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPXRSplashDesc>()
{
	return FPXRSplashDesc::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPXRSplashDesc_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashTexturePath_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashTexturePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashQuadSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashQuadSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashTextureOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashTextureOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashTextureScale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashTextureScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bNoAlpha_MetaData[];
#endif
		static void NewProp_bNoAlpha_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNoAlpha;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPXRSplashDesc>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTexturePath_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.Texture" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Splash texture to show" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTexturePath = { "SplashTexturePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXRSplashDesc, SplashTexturePath), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTexturePath_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTexturePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTransform_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The center transform" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTransform = { "SplashTransform", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXRSplashDesc, SplashTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTransform_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTransform_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashQuadSize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The splash layer quad size" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashQuadSize = { "SplashQuadSize", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXRSplashDesc, SplashQuadSize), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashQuadSize_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashQuadSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureOffset_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Splash texture offset relative to the upper left corner" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureOffset = { "SplashTextureOffset", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXRSplashDesc, SplashTextureOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureOffset_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureScale_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Splash texture scale (default=1.0f)" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureScale = { "SplashTextureScale", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXRSplashDesc, SplashTextureScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureScale_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ignore the splash texture alpha channel" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha_SetBit(void* Obj)
	{
		((FPXRSplashDesc*)Obj)->bNoAlpha = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha = { "bNoAlpha", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPXRSplashDesc), &Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha_MetaData), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTexturePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashQuadSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_SplashTextureScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewProp_bNoAlpha,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PXRSplashDesc",
		Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::PropPointers),
		sizeof(FPXRSplashDesc),
		alignof(FPXRSplashDesc),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPXRSplashDesc()
	{
		if (!Z_Registration_Info_UScriptStruct_PXRSplashDesc.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PXRSplashDesc.InnerSingleton, Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PXRSplashDesc.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRCoordinateType;
	static UEnum* EPICOXRCoordinateType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCoordinateType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRCoordinateType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRCoordinateType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRCoordinateType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRCoordinateType>()
	{
		return EPICOXRCoordinateType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enumerators[] = {
		{ "EPICOXRCoordinateType::Local", (int64)EPICOXRCoordinateType::Local },
		{ "EPICOXRCoordinateType::Global_BoundarySystem", (int64)EPICOXRCoordinateType::Global_BoundarySystem },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Global_BoundarySystem.DisplayName", "BoundarySystem Coordinate" },
		{ "Global_BoundarySystem.Name", "EPICOXRCoordinateType::Global_BoundarySystem" },
		{ "Local.DisplayName", "Local Coordinate" },
		{ "Local.Name", "EPICOXRCoordinateType::Local" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRCoordinateType",
		"EPICOXRCoordinateType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCoordinateType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRCoordinateType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRCoordinateType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrBodyActionList;
	static UEnum* EPxrBodyActionList_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrBodyActionList.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrBodyActionList.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPxrBodyActionList"));
		}
		return Z_Registration_Info_UEnum_EPxrBodyActionList.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPxrBodyActionList>()
	{
		return EPxrBodyActionList_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enumerators[] = {
		{ "EPxrBodyActionList::NoneAction", (int64)EPxrBodyActionList::NoneAction },
		{ "EPxrBodyActionList::TouchGround", (int64)EPxrBodyActionList::TouchGround },
		{ "EPxrBodyActionList::KeepStatic", (int64)EPxrBodyActionList::KeepStatic },
		{ "EPxrBodyActionList::TouchGroundAndKeepStatic", (int64)EPxrBodyActionList::TouchGroundAndKeepStatic },
		{ "EPxrBodyActionList::TouchGroundToe", (int64)EPxrBodyActionList::TouchGroundToe },
		{ "EPxrBodyActionList::FootDownAction", (int64)EPxrBodyActionList::FootDownAction },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FootDownAction.Name", "EPxrBodyActionList::FootDownAction" },
		{ "KeepStatic.Name", "EPxrBodyActionList::KeepStatic" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "NoneAction.Name", "EPxrBodyActionList::NoneAction" },
		{ "TouchGround.Name", "EPxrBodyActionList::TouchGround" },
		{ "TouchGroundAndKeepStatic.Name", "EPxrBodyActionList::TouchGroundAndKeepStatic" },
		{ "TouchGroundToe.Name", "EPxrBodyActionList::TouchGroundToe" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPxrBodyActionList",
		"EPxrBodyActionList",
		Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList()
	{
		if (!Z_Registration_Info_UEnum_EPxrBodyActionList.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrBodyActionList.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrBodyActionList.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOMRState;
	static UEnum* EPICOMRState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOMRState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOMRState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOMRState, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOMRState"));
		}
		return Z_Registration_Info_UEnum_EPICOMRState.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOMRState>()
	{
		return EPICOMRState_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enumerators[] = {
		{ "EPICOMRState::Initialized", (int64)EPICOMRState::Initialized },
		{ "EPICOMRState::Running", (int64)EPICOMRState::Running },
		{ "EPICOMRState::Stopped", (int64)EPICOMRState::Stopped },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Initialized.Name", "EPICOMRState::Initialized" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
		{ "Running.Name", "EPICOMRState::Running" },
		{ "Stopped.Name", "EPICOMRState::Stopped" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOMRState",
		"EPICOMRState",
		Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOMRState()
	{
		if (!Z_Registration_Info_UEnum_EPICOMRState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOMRState.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOMRState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOMRState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOVSTDisplayStatus;
	static UEnum* EPICOVSTDisplayStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOVSTDisplayStatus"));
		}
		return Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOVSTDisplayStatus>()
	{
		return EPICOVSTDisplayStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enumerators[] = {
		{ "EPICOVSTDisplayStatus::Display_Disabled", (int64)EPICOVSTDisplayStatus::Display_Disabled },
		{ "EPICOVSTDisplayStatus::Display_Enabling", (int64)EPICOVSTDisplayStatus::Display_Enabling },
		{ "EPICOVSTDisplayStatus::Display_Enabled", (int64)EPICOVSTDisplayStatus::Display_Enabled },
		{ "EPICOVSTDisplayStatus::Display_Disabling", (int64)EPICOVSTDisplayStatus::Display_Disabling },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Display_Disabled.Name", "EPICOVSTDisplayStatus::Display_Disabled" },
		{ "Display_Disabling.Name", "EPICOVSTDisplayStatus::Display_Disabling" },
		{ "Display_Enabled.Name", "EPICOVSTDisplayStatus::Display_Enabled" },
		{ "Display_Enabling.Name", "EPICOVSTDisplayStatus::Display_Enabling" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOVSTDisplayStatus",
		"EPICOVSTDisplayStatus",
		Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus()
	{
		if (!Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOVSTDisplayStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOVSTDisplayStatus.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey;
class UScriptStruct* FPXREventDataMotionTrackerKey::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PXREventDataMotionTrackerKey"));
	}
	return Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPXREventDataMotionTrackerKey>()
{
	return FPXREventDataMotionTrackerKey::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TrackerSN;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Code_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Code;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Action;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Repeat_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Repeat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShortPress_MetaData[];
#endif
		static void NewProp_bShortPress_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShortPress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPXREventDataMotionTrackerKey>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_TrackerSN_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_TrackerSN = { "TrackerSN", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataMotionTrackerKey, TrackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_TrackerSN_MetaData), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_TrackerSN_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Code_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Code = { "Code", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataMotionTrackerKey, Code), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Code_MetaData), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Code_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Action_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataMotionTrackerKey, Action), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Action_MetaData), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Action_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Repeat_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Repeat = { "Repeat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataMotionTrackerKey, Repeat), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Repeat_MetaData), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Repeat_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress_SetBit(void* Obj)
	{
		((FPXREventDataMotionTrackerKey*)Obj)->bShortPress = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress = { "bShortPress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPXREventDataMotionTrackerKey), &Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress_MetaData), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_TrackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Code,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Action,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_Repeat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewProp_bShortPress,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PXREventDataMotionTrackerKey",
		Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::PropPointers),
		sizeof(FPXREventDataMotionTrackerKey),
		alignof(FPXREventDataMotionTrackerKey),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey()
	{
		if (!Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.InnerSingleton, Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent;
class UScriptStruct* FPXREventDataExtDevConnectEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PXREventDataExtDevConnectEvent"));
	}
	return Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPXREventDataExtDevConnectEvent>()
{
	return FPXREventDataExtDevConnectEvent::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TrackerSN;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_state_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_state;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPXREventDataExtDevConnectEvent>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_TrackerSN_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_TrackerSN = { "TrackerSN", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataExtDevConnectEvent, TrackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_TrackerSN_MetaData), Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_TrackerSN_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_state_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_state = { "state", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataExtDevConnectEvent, state), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_state_MetaData), Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_state_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_TrackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewProp_state,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PXREventDataExtDevConnectEvent",
		Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::PropPointers),
		sizeof(FPXREventDataExtDevConnectEvent),
		alignof(FPXREventDataExtDevConnectEvent),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent()
	{
		if (!Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.InnerSingleton, Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent;
class UScriptStruct* FPXREventDataExtDevBatteryEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PXREventDataExtDevBatteryEvent"));
	}
	return Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPXREventDataExtDevBatteryEvent>()
{
	return FPXREventDataExtDevBatteryEvent::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackerSN_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TrackerSN;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_battery_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_battery;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_charger_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_charger;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPXREventDataExtDevBatteryEvent>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_TrackerSN_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_TrackerSN = { "TrackerSN", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataExtDevBatteryEvent, TrackerSN), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_TrackerSN_MetaData), Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_TrackerSN_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_battery_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_battery = { "battery", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataExtDevBatteryEvent, battery), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_battery_MetaData), Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_battery_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_charger_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_charger = { "charger", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPXREventDataExtDevBatteryEvent, charger), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_charger_MetaData), Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_charger_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_TrackerSN,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_battery,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewProp_charger,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PXREventDataExtDevBatteryEvent",
		Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::PropPointers),
		sizeof(FPXREventDataExtDevBatteryEvent),
		alignof(FPXREventDataExtDevBatteryEvent),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent()
	{
		if (!Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.InnerSingleton, Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::EnumInfo[] = {
		{ EPICOXRCoordinateType_StaticEnum, TEXT("EPICOXRCoordinateType"), &Z_Registration_Info_UEnum_EPICOXRCoordinateType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2250041083U) },
		{ EPxrBodyActionList_StaticEnum, TEXT("EPxrBodyActionList"), &Z_Registration_Info_UEnum_EPxrBodyActionList, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2274122140U) },
		{ EPICOMRState_StaticEnum, TEXT("EPICOMRState"), &Z_Registration_Info_UEnum_EPICOMRState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3874922584U) },
		{ EPICOVSTDisplayStatus_StaticEnum, TEXT("EPICOVSTDisplayStatus"), &Z_Registration_Info_UEnum_EPICOVSTDisplayStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4108955316U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::ScriptStructInfo[] = {
		{ FPXRSplashDesc::StaticStruct, Z_Construct_UScriptStruct_FPXRSplashDesc_Statics::NewStructOps, TEXT("PXRSplashDesc"), &Z_Registration_Info_UScriptStruct_PXRSplashDesc, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPXRSplashDesc), 1402801677U) },
		{ FPXREventDataMotionTrackerKey::StaticStruct, Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics::NewStructOps, TEXT("PXREventDataMotionTrackerKey"), &Z_Registration_Info_UScriptStruct_PXREventDataMotionTrackerKey, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPXREventDataMotionTrackerKey), 3123027277U) },
		{ FPXREventDataExtDevConnectEvent::StaticStruct, Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics::NewStructOps, TEXT("PXREventDataExtDevConnectEvent"), &Z_Registration_Info_UScriptStruct_PXREventDataExtDevConnectEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPXREventDataExtDevConnectEvent), 3803026532U) },
		{ FPXREventDataExtDevBatteryEvent::StaticStruct, Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics::NewStructOps, TEXT("PXREventDataExtDevBatteryEvent"), &Z_Registration_Info_UScriptStruct_PXREventDataExtDevBatteryEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPXREventDataExtDevBatteryEvent), 2591013390U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_2596300691(TEXT("/Script/PICOXRHMD"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
