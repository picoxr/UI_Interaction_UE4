// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_SpatialMeshComponent.h"
#include "PXR_MRTypes.h"

UPICOSpatialMeshComponent::UPICOSpatialMeshComponent(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
}

EPICOSemanticLabel UPICOSpatialMeshComponent::GetSemanticByIndex(int32 Index)
{
	return IndexToAnchorSceneLabelMap.Find(Index)?IndexToAnchorSceneLabelMap[Index]:EPICOSemanticLabel::Unknown;
}

void UPICOSpatialMeshComponent::AddAnchorToSceneLabel(int32 Index, EPICOSemanticLabel SceneLabel)
{
	IndexToAnchorSceneLabelMap.Emplace(Index,SceneLabel);
}

void UPICOSpatialMeshComponent::SetUpdateTime(uint64 Time)
{
	LastUpdateTime=Time;
}

int64 UPICOSpatialMeshComponent::GetUpdateTime() const
{
	return static_cast<int64>(LastUpdateTime);
}
