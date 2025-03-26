// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PICOPlatformSubsystem.generated.h"

/**
 * 
 */
class UOnlineSubsystemPicoManager;

UCLASS()
class ONLINESUBSYSTEMPICO_API UPICOPlatformSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPICOPlatformSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	UPROPERTY()
	UOnlineSubsystemPicoManager* PicoManager;

public:

	UOnlineSubsystemPicoManager* ConstructPicoManager();
	
};
