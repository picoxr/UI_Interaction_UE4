// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

namespace PXRUtility
{
	template <typename T>
	T* FindComponentByName(AActor* Actor, const FName& ComponentName)
	{
		if (IsValid(Actor) && (ComponentName != NAME_None))
		{
			TArray<T*> ComponentsOfType;
			Actor->GetComponents<T>(ComponentsOfType);
			T** FoundComponent = ComponentsOfType.FindByPredicate([Name = ComponentName.ToString()](T* Component) { return Component->GetName().Equals(Name); });

			if (FoundComponent != nullptr)
			{
				return *FoundComponent;
			}
		}

		return nullptr;
	}
}
