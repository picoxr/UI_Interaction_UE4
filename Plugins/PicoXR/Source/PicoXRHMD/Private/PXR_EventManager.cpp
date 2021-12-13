// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "PXR_EventManager.h"

static UPicoXREventManager* EventManagerInstance = nullptr;
UPicoXREventManager* UPicoXREventManager::GetInstance() 
{
	if (EventManagerInstance == nullptr)
    {
		EventManagerInstance = NewObject<UPicoXREventManager>();
		EventManagerInstance->AddToRoot();
	}
	return EventManagerInstance;
}