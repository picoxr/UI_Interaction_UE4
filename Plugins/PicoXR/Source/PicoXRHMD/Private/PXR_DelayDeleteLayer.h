// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "PXR_StereoLayer.h"

class FDelayDeleteLayerManager
{
public:
	void AddLayerToDeferredDeletionQueue(const FPICOLayerPtr& ptr);
	void AddPxrLayerToDeferredDeletionQueue(const uint32 ID, const uint32 layerID);
	void HandleLayerDeferredDeletionQueue_RenderThread(bool bDeleteImmediately = false);

private:
	struct DelayDeleteLayerEntry
	{
		enum class DelayDeleteLayerEntryType
		{
			Layer,
			PxrLayer
		};

		FPICOLayerPtr Layer;
		uint32 ID;
		uint32 PxrLayerId;
		
		uint32 FrameEnqueued;
		DelayDeleteLayerEntryType EntryType;
	};

	TArray<DelayDeleteLayerEntry> DeferredDeletionArray;
};