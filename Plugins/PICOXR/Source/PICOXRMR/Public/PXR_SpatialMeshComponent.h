// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "MRMeshComponent.h"
#include "PXR_MRTypes.h"
#include "PXR_SpatialMeshComponent.generated.h"

UCLASS(hidecategories = (Object, LOD), meta = (BlueprintSpawnableComponent), ClassGroup = Rendering)
class UPICOSpatialMeshComponent : public UMRMeshComponent
{
	GENERATED_BODY()
public:

	UPICOSpatialMeshComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	EPICOSemanticLabel GetSemanticByIndex(int32 Index);

	void AddAnchorToSceneLabel(int32 Index,EPICOSemanticLabel SceneLabel);

	void SetUpdateTime(uint64 Time);

	int64 GetUpdateTime() const;
	
protected:
	TMap<int32,EPICOSemanticLabel> IndexToAnchorSceneLabelMap; //Index ->SceneLabel
	uint64 LastUpdateTime = 0;
};