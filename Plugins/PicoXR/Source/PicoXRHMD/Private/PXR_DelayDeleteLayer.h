// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "PXR_StereoLayer.h"

class FDelayDeleteLayerManager
{
public:
	void AddLayerToDeferredDeletionQueue(const FPICOLayerPtr& ptr);
	void AddPxrLayerToDeferredDeletionQueue(const uint32 layerID);
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
		uint32 PxrLayerId;
		
		uint32 FrameEnqueued;
		DelayDeleteLayerEntryType EntryType;
	};

	TArray<DelayDeleteLayerEntry> DeferredDeletionArray;
};