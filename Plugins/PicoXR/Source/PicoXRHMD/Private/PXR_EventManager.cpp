//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

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