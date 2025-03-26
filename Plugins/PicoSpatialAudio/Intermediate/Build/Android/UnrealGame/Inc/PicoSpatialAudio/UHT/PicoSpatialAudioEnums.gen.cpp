// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoSpatialAudio/Private/PicoSpatialAudioEnums.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoSpatialAudioEnums() {}
// Cross Module References
	PICOSPATIALAUDIO_API UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode();
	PICOSPATIALAUDIO_API UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset();
	PICOSPATIALAUDIO_API UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode();
	UPackage* Z_Construct_UPackage__Script_PicoSpatialAudio();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode;
	static UEnum* EPxrAudioSpatializer_RenderingMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode, (UObject*)Z_Construct_UPackage__Script_PicoSpatialAudio(), TEXT("EPxrAudioSpatializer_RenderingMode"));
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_RenderingMode>()
	{
		return EPxrAudioSpatializer_RenderingMode_StaticEnum();
	}
	struct Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enumerators[] = {
		{ "EPxrAudioSpatializer_RenderingMode::Low_Quality", (int64)EPxrAudioSpatializer_RenderingMode::Low_Quality },
		{ "EPxrAudioSpatializer_RenderingMode::Medium_Quality", (int64)EPxrAudioSpatializer_RenderingMode::Medium_Quality },
		{ "EPxrAudioSpatializer_RenderingMode::High_Quality", (int64)EPxrAudioSpatializer_RenderingMode::High_Quality },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order },
		{ "EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order", (int64)EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enum_MetaDataParams[] = {
		{ "Ambisonic_Fifth_Order.DisplayName", "Ambisonic Fifth Order" },
		{ "Ambisonic_Fifth_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order" },
		{ "Ambisonic_First_Order.Comment", "///< 5th order ambisonics\n" },
		{ "Ambisonic_First_Order.DisplayName", "Ambisonic First Order" },
		{ "Ambisonic_First_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order" },
		{ "Ambisonic_First_Order.ToolTip", "< 5th order ambisonics" },
		{ "Ambisonic_Fourth_Order.DisplayName", "Ambisonic Forth Order" },
		{ "Ambisonic_Fourth_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order" },
		{ "Ambisonic_Second_Order.DisplayName", "Ambisonic Second Order" },
		{ "Ambisonic_Second_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order" },
		{ "Ambisonic_Seventh_Order.DisplayName", "Ambisonic Seventh Order" },
		{ "Ambisonic_Seventh_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order" },
		{ "Ambisonic_Sixth_Order.DisplayName", "Ambisonic Sixth Order" },
		{ "Ambisonic_Sixth_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order" },
		{ "Ambisonic_Third_Order.DisplayName", "Ambisonic Third Order" },
		{ "Ambisonic_Third_Order.Name", "EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order" },
		{ "BlueprintType", "true" },
		{ "High_Quality.Comment", "///< 3rd order ambisonics\n" },
		{ "High_Quality.DisplayName", "High Quality" },
		{ "High_Quality.Name", "EPxrAudioSpatializer_RenderingMode::High_Quality" },
		{ "High_Quality.ToolTip", "< 3rd order ambisonics" },
		{ "Low_Quality.DisplayName", "Low Quality" },
		{ "Low_Quality.Name", "EPxrAudioSpatializer_RenderingMode::Low_Quality" },
		{ "Medium_Quality.Comment", "///< 1st order ambisonics\n" },
		{ "Medium_Quality.DisplayName", "Medium Quality" },
		{ "Medium_Quality.Name", "EPxrAudioSpatializer_RenderingMode::Medium_Quality" },
		{ "Medium_Quality.ToolTip", "< 1st order ambisonics" },
		{ "ModuleRelativePath", "Private/PicoSpatialAudioEnums.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
		nullptr,
		"EPxrAudioSpatializer_RenderingMode",
		"EPxrAudioSpatializer_RenderingMode",
		Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.InnerSingleton, Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_RenderingMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode;
	static UEnum* EPxrAudioSpatializer_SourceAttenuationMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode, (UObject*)Z_Construct_UPackage__Script_PicoSpatialAudio(), TEXT("EPxrAudioSpatializer_SourceAttenuationMode"));
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_SourceAttenuationMode>()
	{
		return EPxrAudioSpatializer_SourceAttenuationMode_StaticEnum();
	}
	struct Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enumerators[] = {
		{ "EPxrAudioSpatializer_SourceAttenuationMode::None", (int64)EPxrAudioSpatializer_SourceAttenuationMode::None },
		{ "EPxrAudioSpatializer_SourceAttenuationMode::Fixed", (int64)EPxrAudioSpatializer_SourceAttenuationMode::Fixed },
		{ "EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare", (int64)EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare },
		{ "EPxrAudioSpatializer_SourceAttenuationMode::Customized", (int64)EPxrAudioSpatializer_SourceAttenuationMode::Customized },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Customized.DisplayName", "Customized" },
		{ "Customized.Name", "EPxrAudioSpatializer_SourceAttenuationMode::Customized" },
		{ "Customized.TooTip", "Calculate source attenuation using external callback function" },
		{ "Fixed.DisplayName", "Fixed" },
		{ "Fixed.Name", "EPxrAudioSpatializer_SourceAttenuationMode::Fixed" },
		{ "Fixed.ToolTip", "Same as None" },
		{ "InverseSquare.DisplayName", "Inverse Square" },
		{ "InverseSquare.Name", "EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare" },
		{ "InverseSquare.ToolTip", "Calculate source attenuation according to Inverse-Square Law" },
		{ "ModuleRelativePath", "Private/PicoSpatialAudioEnums.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EPxrAudioSpatializer_SourceAttenuationMode::None" },
		{ "None.ToolTip", "Renderer doesn't attenuate source volume based on source-listener distance" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
		nullptr,
		"EPxrAudioSpatializer_SourceAttenuationMode",
		"EPxrAudioSpatializer_SourceAttenuationMode",
		Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.InnerSingleton, Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SourceAttenuationMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset;
	static UEnum* EPxrAudioSpatializer_SceneMaterialPreset_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset, (UObject*)Z_Construct_UPackage__Script_PicoSpatialAudio(), TEXT("EPxrAudioSpatializer_SceneMaterialPreset"));
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.OuterSingleton;
	}
	template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_SceneMaterialPreset>()
	{
		return EPxrAudioSpatializer_SceneMaterialPreset_StaticEnum();
	}
	struct Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enumerators[] = {
		{ "EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile", (int64)EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Brick", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Brick },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::BrickPainted", (int64)EPxrAudioSpatializer_SceneMaterialPreset::BrickPainted },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Carpet", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Carpet },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavy", (int64)EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavy },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavyPadded", (int64)EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavyPadded },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::CeramicTile", (int64)EPxrAudioSpatializer_SceneMaterialPreset::CeramicTile },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Concrete", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Concrete },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteRough", (int64)EPxrAudioSpatializer_SceneMaterialPreset::ConcreteRough },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlock", (int64)EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlock },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlockPainted", (int64)EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlockPainted },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Curtain", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Curtain },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Foliage", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Foliage },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Glass", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Glass },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::GlassHeavy", (int64)EPxrAudioSpatializer_SceneMaterialPreset::GlassHeavy },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Grass", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Grass },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Gravel", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Gravel },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::GypsumBoard", (int64)EPxrAudioSpatializer_SceneMaterialPreset::GypsumBoard },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnBrick", (int64)EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnBrick },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnConcreteBlock", (int64)EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnConcreteBlock },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Soil", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Soil },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::SoundProof", (int64)EPxrAudioSpatializer_SceneMaterialPreset::SoundProof },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Snow", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Snow },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Steel", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Steel },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Water", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Water },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::WoodThin", (int64)EPxrAudioSpatializer_SceneMaterialPreset::WoodThin },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::WoodThick", (int64)EPxrAudioSpatializer_SceneMaterialPreset::WoodThick },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::WoodFloor", (int64)EPxrAudioSpatializer_SceneMaterialPreset::WoodFloor },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::WoodOnConcrete", (int64)EPxrAudioSpatializer_SceneMaterialPreset::WoodOnConcrete },
		{ "EPxrAudioSpatializer_SceneMaterialPreset::Custom", (int64)EPxrAudioSpatializer_SceneMaterialPreset::Custom },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enum_MetaDataParams[] = {
		{ "AcousticTile.DisplayName", "AcousticTile" },
		{ "AcousticTile.Name", "EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile" },
		{ "BlueprintType", "true" },
		{ "Brick.DisplayName", "Brick" },
		{ "Brick.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Brick" },
		{ "BrickPainted.DisplayName", "Brick Painted" },
		{ "BrickPainted.Name", "EPxrAudioSpatializer_SceneMaterialPreset::BrickPainted" },
		{ "Carpet.DisplayName", "Carpet" },
		{ "Carpet.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Carpet" },
		{ "CarpetHeavy.DisplayName", "Carpet Heavy" },
		{ "CarpetHeavy.Name", "EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavy" },
		{ "CarpetHeavyPadded.DisplayName", "Carpet Heavy Padded" },
		{ "CarpetHeavyPadded.Name", "EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavyPadded" },
		{ "CeramicTile.DisplayName", "Ceramic Tile" },
		{ "CeramicTile.Name", "EPxrAudioSpatializer_SceneMaterialPreset::CeramicTile" },
		{ "Concrete.DisplayName", "Concrete" },
		{ "Concrete.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Concrete" },
		{ "ConcreteBlock.DisplayName", "Concrete Block" },
		{ "ConcreteBlock.Name", "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlock" },
		{ "ConcreteBlockPainted.DisplayName", "Concrete Block Painted" },
		{ "ConcreteBlockPainted.Name", "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlockPainted" },
		{ "ConcreteRough.DisplayName", "Concrete Rough" },
		{ "ConcreteRough.Name", "EPxrAudioSpatializer_SceneMaterialPreset::ConcreteRough" },
		{ "Curtain.DisplayName", "Curtain" },
		{ "Curtain.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Curtain" },
		{ "Custom.DisplayName", "Custom" },
		{ "Custom.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Custom" },
		{ "Foliage.DisplayName", "Foliage" },
		{ "Foliage.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Foliage" },
		{ "Glass.DisplayName", "Glass" },
		{ "Glass.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Glass" },
		{ "GlassHeavy.DisplayName", "Glass Heavy" },
		{ "GlassHeavy.Name", "EPxrAudioSpatializer_SceneMaterialPreset::GlassHeavy" },
		{ "Grass.DisplayName", "Grass" },
		{ "Grass.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Grass" },
		{ "Gravel.DisplayName", "Gravel" },
		{ "Gravel.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Gravel" },
		{ "GypsumBoard.DisplayName", "Gypsum Board" },
		{ "GypsumBoard.Name", "EPxrAudioSpatializer_SceneMaterialPreset::GypsumBoard" },
		{ "ModuleRelativePath", "Private/PicoSpatialAudioEnums.h" },
		{ "PlasterOnBrick.DisplayName", "Plaster On Brick" },
		{ "PlasterOnBrick.Name", "EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnBrick" },
		{ "PlasterOnConcreteBlock.DisplayName", "Plaster On Concrete Block" },
		{ "PlasterOnConcreteBlock.Name", "EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnConcreteBlock" },
		{ "Snow.DisplayName", "Snow" },
		{ "Snow.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Snow" },
		{ "Soil.DisplayName", "Soil" },
		{ "Soil.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Soil" },
		{ "SoundProof.DisplayName", "Sound Proof" },
		{ "SoundProof.Name", "EPxrAudioSpatializer_SceneMaterialPreset::SoundProof" },
		{ "Steel.DisplayName", "Steel" },
		{ "Steel.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Steel" },
		{ "Water.DisplayName", "Water" },
		{ "Water.Name", "EPxrAudioSpatializer_SceneMaterialPreset::Water" },
		{ "WoodFloor.DisplayName", "Wood Floor" },
		{ "WoodFloor.Name", "EPxrAudioSpatializer_SceneMaterialPreset::WoodFloor" },
		{ "WoodOnConcrete.DisplayName", "Wood On Concrete" },
		{ "WoodOnConcrete.Name", "EPxrAudioSpatializer_SceneMaterialPreset::WoodOnConcrete" },
		{ "WoodThick.DisplayName", "Wood Thick" },
		{ "WoodThick.Name", "EPxrAudioSpatializer_SceneMaterialPreset::WoodThick" },
		{ "WoodThin.DisplayName", "Wood Thin" },
		{ "WoodThin.Name", "EPxrAudioSpatializer_SceneMaterialPreset::WoodThin" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PicoSpatialAudio,
		nullptr,
		"EPxrAudioSpatializer_SceneMaterialPreset",
		"EPxrAudioSpatializer_SceneMaterialPreset",
		Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset()
	{
		if (!Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.InnerSingleton, Z_Construct_UEnum_PicoSpatialAudio_EPxrAudioSpatializer_SceneMaterialPreset_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h_Statics::EnumInfo[] = {
		{ EPxrAudioSpatializer_RenderingMode_StaticEnum, TEXT("EPxrAudioSpatializer_RenderingMode"), &Z_Registration_Info_UEnum_EPxrAudioSpatializer_RenderingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3759791498U) },
		{ EPxrAudioSpatializer_SourceAttenuationMode_StaticEnum, TEXT("EPxrAudioSpatializer_SourceAttenuationMode"), &Z_Registration_Info_UEnum_EPxrAudioSpatializer_SourceAttenuationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1344202341U) },
		{ EPxrAudioSpatializer_SceneMaterialPreset_StaticEnum, TEXT("EPxrAudioSpatializer_SceneMaterialPreset"), &Z_Registration_Info_UEnum_EPxrAudioSpatializer_SceneMaterialPreset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3164631813U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h_1913804230(TEXT("/Script/PicoSpatialAudio"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
