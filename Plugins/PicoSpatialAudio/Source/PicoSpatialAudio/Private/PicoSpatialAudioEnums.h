//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class EPxrAudioSpatializer_RenderingMode : uint8
{
	Low_Quality = 0 UMETA(DisplayName = "Low Quality"),
	///< 1st order ambisonics
	Medium_Quality = 1 UMETA(DisplayName = "Medium Quality"),
	///< 3rd order ambisonics
	High_Quality = 2 UMETA(DisplayName = "High Quality"),
	///< 5th order ambisonics
	Ambisonic_First_Order UMETA(DisplayName = "Ambisonic First Order"),
	Ambisonic_Second_Order UMETA(DisplayName = "Ambisonic Second Order"),
	Ambisonic_Third_Order UMETA(DisplayName = "Ambisonic Third Order"),
	Ambisonic_Fourth_Order UMETA(DisplayName = "Ambisonic Forth Order"),
	Ambisonic_Fifth_Order UMETA(DisplayName = "Ambisonic Fifth Order"),
	Ambisonic_Sixth_Order UMETA(DisplayName = "Ambisonic Sixth Order"),
	Ambisonic_Seventh_Order UMETA(DisplayName = "Ambisonic Seventh Order")
};

UENUM(BlueprintType)
enum class EPxrAudioSpatializer_SourceAttenuationMode : uint8
{
	None = 0 UMETA(DisplayName = "None", ToolTip = "Renderer doesn't attenuate source volume based on source-listener distance"),
	Fixed = 1 UMETA(DisplayName = "Fixed", ToolTip = "Same as None"),
	InverseSquare = 2 UMETA(DisplayName = "Inverse Square", ToolTip = "Calculate source attenuation according to Inverse-Square Law"),
	Customized = 3 UMETA(DisplayName = "Customized", TooTip = "Calculate source attenuation using external callback function")
};

UENUM(BlueprintType)
enum class EPxrAudioSpatializer_SceneMaterialPreset : uint8
{
	AcousticTile = 0 UMETA(DisplayName = "AcousticTile"),
	Brick = 1 UMETA(DisplayName = "Brick"),
	BrickPainted UMETA(DisplayName = "Brick Painted"),
	Carpet UMETA(DisplayName = "Carpet"),
	CarpetHeavy UMETA(DisplayName = "Carpet Heavy"),
	CarpetHeavyPadded UMETA(DisplayName = "Carpet Heavy Padded"),
	CeramicTile UMETA(DisplayName = "Ceramic Tile"),
	Concrete UMETA(DisplayName = "Concrete"),
	ConcreteRough UMETA(DisplayName = "Concrete Rough"),
	ConcreteBlock UMETA(DisplayName = "Concrete Block"),
	ConcreteBlockPainted UMETA(DisplayName = "Concrete Block Painted"),
	Curtain UMETA(DisplayName = "Curtain"),
	Foliage UMETA(DisplayName = "Foliage"),
	Glass UMETA(DisplayName = "Glass"),
	GlassHeavy UMETA(DisplayName = "Glass Heavy"),
	Grass UMETA(DisplayName = "Grass"),
	Gravel UMETA(DisplayName = "Gravel"),
	GypsumBoard UMETA(DisplayName = "Gypsum Board"),
	PlasterOnBrick UMETA(DisplayName = "Plaster On Brick"),
	PlasterOnConcreteBlock UMETA(DisplayName = "Plaster On Concrete Block"),
	Soil UMETA(DisplayName = "Soil"),
	SoundProof UMETA(DisplayName = "Sound Proof"),
	Snow UMETA(DisplayName = "Snow"),
	Steel UMETA(DisplayName = "Steel"),
	Water UMETA(DisplayName = "Water"),
	WoodThin UMETA(DisplayName = "Wood Thin"),
	WoodThick UMETA(DisplayName = "Wood Thick"),
	WoodFloor UMETA(DisplayName = "Wood Floor"),
	WoodOnConcrete UMETA(DisplayName = "Wood On Concrete"),
	Custom UMETA(DisplayName = "Custom")
};
