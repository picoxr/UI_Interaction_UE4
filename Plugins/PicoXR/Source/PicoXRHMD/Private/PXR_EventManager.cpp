//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_EventManager.h"

static UPICOXREventManager* EventManagerInstance = nullptr;
UPICOXREventManager* UPICOXREventManager::GetInstance() 
{
	if (EventManagerInstance == nullptr)
    {
		EventManagerInstance = NewObject<UPICOXREventManager>();
		EventManagerInstance->AddToRoot();
	}
	return EventManagerInstance;
}