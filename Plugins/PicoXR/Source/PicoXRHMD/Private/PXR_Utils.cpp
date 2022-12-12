//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_Utils.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

UPICOContentResourceFinder::UPICOContentResourceFinder(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UMaterial> StaticUnderlayMaterial(TEXT("Material'/PICOXR/Materials/UnderlayMaterial.UnderlayMaterial'"));
	StereoLayerDepthMat = StaticUnderlayMaterial.Object;
}