// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif
class OnlinePlatformInterfacePico
{
public:

	static FString GetAppID();

	static FString GetOpenID();
	
	static void Achievement_Init();
	
	static uint64 Achievement_AddCount(FString AchievementId,uint64 Count);

	static uint64 Achievement_AddFields(FString AchievementId,FString AchievementFields);

	static uint64 Achievement_GetAllDefinitions(FString AppId);

	static uint64 Achievement_GetAllProgress();

	static uint64 Achievement_Unlock(FString AchievementId);

	static uint64 Achievement_GetDefinitionsByName(TArray<FString>AchievementIds);

	static uint64 Achievements_GetAllDefinitionsByUrl(FString Message);
	
	static uint64 Achievements_GetAllProgressByUrl(FString Message);
	
#if PLATFORM_ANDROID
	static jclass PopMessage();

	static uint64 GetMessageId(jclass Message);

	static bool GetMessageIsError(jclass Message);

	static uint64 GetMessageHandleType(jclass Message);

	static int32 AchievementDefinitionArray_GetSize(jclass Message);
	
	static jclass AchievementDefinitionArray_GetElement(jclass Message,int32 Index);

	static FString AchievementDefinitionArray_GetNextUrl(jclass Message);

	static bool AchievementDefinitionArray_HasNextPage(jclass Message);

	static FString AchievementDefinition_GetName(jclass Message);

	static int32 AchievementDefinition_GetBitfieldLength(jclass Message);

	static uint64 AchievementDefinition_GetTarget(jclass Message);

	static int32 AchievementDefinition_GetType(jclass Message);
	
	static FString AchievementDefinition_GetTitle(jclass Message);

	static FString AchievementDefinition_GetDescription(jclass Message);
	
	static bool AchievementDefinition_GetIsSecret(jclass Message);

	static FString AchievementDefinition_GetUnlockedDescription(jclass Message);

	static FString AchievementDefinition_GetUnlockedImage(jclass Message);

	static FString AchievementDefinition_GetLockedImage(jclass Message);	

	static int32 AchievementProgressArray_GetSize(jclass Message);
	
	static jclass AchievementProgressArray_GetElement(jclass Message,int32 Index);

	static FString AchievementProgressArray_GetNextUrl(jclass Message);

	static bool AchievementProgressArray_HasNextPage(jclass Message);
	
	static FString AchievementProgress_GetBitfield(jclass Message);

	static uint64 AchievementProgress_GetCount(jclass Message);

	static bool AchievementProgress_GetIsUnlocked(jclass Message);

	static FString AchievementProgress_GetName(jclass Message);

	static bool AchievementUpdate_GetJustUnlocked(jclass Message);

	static uint64 AchievementProgress_GetUnlockTime(jclass Message);

	static FString AchievementUpdate_GetName(jclass Message);
#endif
	
};
