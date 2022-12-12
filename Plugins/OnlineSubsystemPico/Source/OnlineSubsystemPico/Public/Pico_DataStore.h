// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "Pico_DataStore.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DataStore, Log, All);
/**
 * 
 */
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_DataStore : public UObject
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	TMap<FString, FString> DataStoreMap;

	int32 NumKey;

	TArray<FString> KeyArray;

public:
	void InitParams(ppfDataStore* InppfDataStoreHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	int32 Contains(FString Key);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	FString GetKey(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	int32 GetNumKeys();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	FString GetValue(FString Key);
};
