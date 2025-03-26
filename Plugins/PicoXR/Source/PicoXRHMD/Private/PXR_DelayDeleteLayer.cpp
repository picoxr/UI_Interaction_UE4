// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_DelayDeleteLayer.h"
#include "XRThreadUtils.h"
#include "PXR_Log.h"
#include "PXR_HMDModule.h"

uint32 GPICOHMDLayerDeletionFrameNumber = 0;
const uint32 NUM_FRAMES_TO_WAIT_FOR_LAYER_DELETE = 3;
const uint32 NUM_FRAMES_TO_WAIT_FOR_PXR_LAYER_DELETE = 7;

void FDelayDeleteLayerManager::AddLayerToDeferredDeletionQueue(const FPICOLayerPtr& ptr)
{
	DelayDeleteLayerEntry Entry;
	Entry.Layer = ptr;
	if (ptr.IsValid())
	{
		Entry.ID = ptr->GetID();
	}
	Entry.FrameEnqueued = GPICOHMDLayerDeletionFrameNumber;
	Entry.EntryType = DelayDeleteLayerEntry::DelayDeleteLayerEntryType::Layer;
	DeferredDeletionArray.Add(Entry);
}

void FDelayDeleteLayerManager::AddPxrLayerToDeferredDeletionQueue(const uint32 ID, const uint32 layerID)
{
	DelayDeleteLayerEntry Entry;
	Entry.ID = ID;
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
				PXR_LOGI(PxrUnreal, "Destroying UELayerID:%d", Entry->ID);
				DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
			}
		}
		else if (Entry->EntryType == DelayDeleteLayerEntry::DelayDeleteLayerEntryType::PxrLayer)
		{
			if (bDeleteImmediately || GPICOHMDLayerDeletionFrameNumber > Entry->FrameEnqueued + NUM_FRAMES_TO_WAIT_FOR_PXR_LAYER_DELETE)
			{
				ExecuteOnRHIThread_DoNotWait([ID = Entry->ID, PxrLayerId = Entry->PxrLayerId]()
				{
					PXR_LOGI(PxrUnreal, "Destroying ID:%d, PxrLayerID:%d", ID, PxrLayerId);
#if PLATFORM_ANDROID
					FPICOXRHMDModule::GetPluginWrapper().DestroyLayer(PxrLayerId);
#endif
				});
				DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
			}
		}

	}

	++GPICOHMDLayerDeletionFrameNumber;
}