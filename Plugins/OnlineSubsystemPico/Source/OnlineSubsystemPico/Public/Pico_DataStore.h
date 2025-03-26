// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "Pico_DataStore.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DataStore, Log, All);
/**
 * 
 */

 /// @brief UPico_DataStore class.
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

	/** @brief With UserId as the key, find its index in the DataStoreMap data structure.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	int32 Contains(FString Key);

	/** @brief Find the user ID in the corresponding KeyArray through the index.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	FString GetKey(int32 Index);

	/** @brief Get the size of DataStoreMap .*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	int32 GetNumKeys();

	/** @brief With UserId as the key, find its value in the DataStoreMap data structure.*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Misc|Data Store")
	FString GetValue(FString Key);
};
