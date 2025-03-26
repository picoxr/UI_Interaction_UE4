//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PicoSpatialAudioEnums.h"
#include "PicoSpatialAudioSettings.generated.h"

/**
 * 
 */
UCLASS(config = Plugin, defaultconfig)
class PICOSPATIALAUDIO_API UPicoSpatialAudioSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPicoSpatialAudioSettings();

	// Reference to submix where reverb plugin audio is routed.
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "Audio Routing", meta = (AllowedClasses = "SoundSubmix"))
	FSoftObjectPath OutputSubmix;

	// Global Rendering Quality for Pico Spatial Audio
	UPROPERTY(GlobalConfig, EditAnywhere, Category = "Rendering Quality")
	EPxrAudioSpatializer_RenderingMode RenderingMode;
};
