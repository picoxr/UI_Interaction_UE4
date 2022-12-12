// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineSubsystemPicoNames.h"
#include "PPF_Platform.h"
#include "Pico_Room.generated.h"
//

DECLARE_LOG_CATEGORY_EXTERN(PicoRoom, Log, All);
class UPico_User;
class UPico_DataStore;
class UPico_UserArray;


UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Room : public UObject
{
    GENERATED_BODY()

private:
    UPROPERTY()
    UPico_DataStore* DataStore = nullptr;

    UPROPERTY()
    UPico_User* Owner = nullptr;

    UPROPERTY()
    UPico_UserArray* Users = nullptr;

    FString Description = FString();

    ppfID ID = 0;

    FString RoomID = FString();

    bool bIsMembershipLocked = false;

    ERoomJoinPolicy RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyUnknown;

    ERoomJoinabilit RoomJoinabilit = ERoomJoinabilit::JoinabilityUnknown;

    int32 MaxUserNum = 0;

    ERoomType RoomType = ERoomType::TypeUnknown;

public:
    void InitParams(ppfRoom* InRoomHandle);
   
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    UPico_DataStore* GetDataStore();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    UPico_User* GetOwner();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    UPico_UserArray* GetUsers();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    FString GetDescription();

    ppfID GetppfID();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    FString GetRoomID();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    bool GetIsMembershipLocked();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    ERoomJoinPolicy GetJoinPolicy();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    ERoomJoinabilit GetJoinability();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    int32 GetMaxUsers();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Room|Room")
    ERoomType GetRoomType();
};
