// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PicoSpatialAudioEnums.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PICOSPATIALAUDIO_PicoSpatialAudioEnums_generated_h
#error "PicoSpatialAudioEnums.generated.h already included, missing '#pragma once' in PicoSpatialAudioEnums.h"
#endif
#define PICOSPATIALAUDIO_PicoSpatialAudioEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PicoSpatialAudio_Source_PicoSpatialAudio_Private_PicoSpatialAudioEnums_h


#define FOREACH_ENUM_EPXRAUDIOSPATIALIZER_RENDERINGMODE(op) \
	op(EPxrAudioSpatializer_RenderingMode::Low_Quality) \
	op(EPxrAudioSpatializer_RenderingMode::Medium_Quality) \
	op(EPxrAudioSpatializer_RenderingMode::High_Quality) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order) \
	op(EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order) 

enum class EPxrAudioSpatializer_RenderingMode : uint8;
template<> struct TIsUEnumClass<EPxrAudioSpatializer_RenderingMode> { enum { Value = true }; };
template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_RenderingMode>();

#define FOREACH_ENUM_EPXRAUDIOSPATIALIZER_SOURCEATTENUATIONMODE(op) \
	op(EPxrAudioSpatializer_SourceAttenuationMode::None) \
	op(EPxrAudioSpatializer_SourceAttenuationMode::Fixed) \
	op(EPxrAudioSpatializer_SourceAttenuationMode::InverseSquare) \
	op(EPxrAudioSpatializer_SourceAttenuationMode::Customized) 

enum class EPxrAudioSpatializer_SourceAttenuationMode : uint8;
template<> struct TIsUEnumClass<EPxrAudioSpatializer_SourceAttenuationMode> { enum { Value = true }; };
template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_SourceAttenuationMode>();

#define FOREACH_ENUM_EPXRAUDIOSPATIALIZER_SCENEMATERIALPRESET(op) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::AcousticTile) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Brick) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::BrickPainted) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Carpet) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavy) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::CarpetHeavyPadded) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::CeramicTile) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Concrete) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::ConcreteRough) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlock) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::ConcreteBlockPainted) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Curtain) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Foliage) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Glass) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::GlassHeavy) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Grass) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Gravel) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::GypsumBoard) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnBrick) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::PlasterOnConcreteBlock) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Soil) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::SoundProof) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Snow) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Steel) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Water) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::WoodThin) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::WoodThick) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::WoodFloor) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::WoodOnConcrete) \
	op(EPxrAudioSpatializer_SceneMaterialPreset::Custom) 

enum class EPxrAudioSpatializer_SceneMaterialPreset : uint8;
template<> struct TIsUEnumClass<EPxrAudioSpatializer_SceneMaterialPreset> { enum { Value = true }; };
template<> PICOSPATIALAUDIO_API UEnum* StaticEnum<EPxrAudioSpatializer_SceneMaterialPreset>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
