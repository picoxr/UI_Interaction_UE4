// Copyright Epic Games, Inc. All Rights Reserved.

#include "PXR_DelayDeleteLayer.h"
#include "XRThreadUtils.h"
#include "PXR_Log.h"
#if PLATFORM_ANDROID
#include "PxrApi.h"
#endif

uint32 GPICOHMDLayerDeletionFrameNumber = 0;
const uint32 NUM_FRAMES_TO_WAIT_FOR_LAYER_DELETE = 3;
const uint32 NUM_FRAMES_TO_WAIT_FOR_PXR_LAYER_DELETE = 7;

void FDelayDeleteLayerManager::AddLayerToDeferredDeletionQueue(const FPICOLayerPtr& ptr)
{
	DelayDeleteLayerEntry Entry;
	Entry.Layer = ptr;
	Entry.FrameEnqueued = GPICOHMDLayerDeletionFrameNumber;
	Entry.EntryType = DelayDeleteLayerEntry::DelayDeleteLayerEntryType::Layer;
	DeferredDeletionArray.Add(Entry);
}

void FDelayDeleteLayerManager::AddPxrLayerToDeferredDeletionQueue(const uint32 layerID)
{
	DelayDeleteLayerEntry Entry;
	Entry.PxrLayerId = layerID;
	Entry.FrameEnqueued = GPICOHMDLayerDeletionFrameNumber;
	Entry.EntryType = DelayDeleteLayerEntry::DelayDeleteLayerEntryType::PxrLayer;
	DeferredDeletionArray.Add(Entry);
}

void FDelayDeleteLayerManager::HandleLayerDeferredDeletionQueue_RenderThread(bool bDeleteImmediately)
{
	for (int32 Index = DeferredDeletionArray.Num() - 1; Index >= 0; --Index)
	{
		DelayDeleteLayerEntry* Entry = &DeferredDeletionArray[Index];
		if (Entry->EntryType == DelayDeleteLayerEntry::DelayDeleteLayerEntryType::Layer)
		{
			if (bDeleteImmediately || GPICOHMDLayerDeletionFrameNumber > Entry->FrameEnqueued + NUM_FRAMES_TO_WAIT_FOR_LAYER_DELETE)
			{
				DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
			}
		}
		else if (Entry->EntryType == DelayDeleteLayerEntry::DelayDeleteLayerEntryType::PxrLayer)
		{
			if (bDeleteImmediately || GPICOHMDLayerDeletionFrameNumber > Entry->FrameEnqueued + NUM_FRAMES_TO_WAIT_FOR_PXR_LAYER_DELETE)
			{
				ExecuteOnRHIThread_DoNotWait([PxrLayerId = Entry->PxrLayerId]()
				{
					PXR_LOGV(PxrUnreal, "Destroying layer %d", PxrLayerId);
#if PLATFORM_ANDROID
					Pxr_DestroyLayer(PxrLayerId);
#endif
				});
				DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
			}
		}

	}

	++GPICOHMDLayerDeletionFrameNumber;
}