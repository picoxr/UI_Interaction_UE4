// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_Achievements.generated.h"

/// @file Pico_Achievements.h

DECLARE_LOG_CATEGORY_EXTERN(PicoAchievements, Log, All);

class UPico_AchievementDefinition;
class UPico_AchievementProgress;
class UPico_AchievementProgressArray;
class UPico_AchievementDefinitionArray;
class UPico_AchievementUpdate;

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FAddCount, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate*, AchievementUpdate);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FAddFields, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate*, AchievementUpdate);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUnlock, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate*, AchievementUpdate);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetAllDefinitions, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetAllProgress, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray*, AchievementProgressArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetDefinitionsByName, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray*, AchievementDefinitionArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetProgressByName, bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray*, AchievementProgressArray);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Achievements Achievements
 *  This is the Achievements group
 *  @{
 */

/// @brief PicoAchievementsInterface class.
class ONLINESUBSYSTEMPICO_API FPicoAchievementsInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoAchievementsInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoAchievementsInterface();

    FAddCount AddCountDelegate;
    FAddFields AddFieldsDelegate;
    FUnlock UnlockDelegate;
    FGetAllDefinitions GetAllDefinitionsDelegate;
    FGetAllProgress GetAllProgressDelegate;
    FGetDefinitionsByName GetDefinitionsByNameDelegate;
    FGetProgressByName GetProgressByNameDelegate;

    /// <summary>Adds a count to a specified count achievement. The count will be added to the current count,
    /// for example, if the current count is 1 and the count you would like to add is 7, the final count will be 8 if the request succeeds.
    /// @note Available to count achievements only.
    /// </summary>
    /// <param name="Name">The API name of the achievement.</param>
    /// <param name="Count">The count you want to add. The largest count supported by this function is the maximum value of a signed 64-bit integer.
    /// If the count is larger than that, it is clamped to that maximum value before being passed to the servers.
    /// </param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InAddCountDelegate">The API requests to do an AddCount operation,
    /// which is processed by the server and returned to the client as a 'success' or 'failure', and possibly other data.
    /// </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool AddCount(const FString& Name, const int64& Count, const FString& ExtraData, FAddCount InAddCountDelegate);

    /// <summary>Unlocks the bit(s) of a specified bitfield achievement. The status of the bit(s) is then unchangeable.
    /// @note Available to bitfield achievements only.
    /// </summary>
    /// <param name="Name">The API name of the achievement to unlock bit(s) for.</param>
    /// <param name="Fields">A string containing either '0' or '1' characters, for example '100011'.
    /// Every '1' will unlock a bit in the corresponding position of a bitfield.
    /// </param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InAddFieldsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool AddFields(const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsCallback);

    /// <summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.</summary>
    /// <param name="Name">The API name of the achievement to unlock.</param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InUnlockCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool Unlock(const FString& Name, const FString& ExtraData, FUnlock InUnlockCallback);

    /// <summary>Gets the information about all achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The size of the page.</param>
    /// <param name="InGetAllDefinitionsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetAllDefinitions(int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsCallback);

    /// <summary>Gets the user's progress on all achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The size of the page.</param>
    /// <param name="InGetAllProgressCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetAllProgress(int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressCallback);

    /// <summary>Gets the information about specified achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetDefinitionsByNameCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetDefinitionsByName(const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameCallback);

    /// <summary>Gets the user's progress on specified achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetProgressByNameCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetProgressByName(const TArray<FString>& NameArray, FGetProgressByName InGetProgressByNameCallback);

};
/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_Achievements BP_Achievements
 *  This is the BP_Achievements group
 *  @{
 */

/// @brief OnlinePicoAchievements Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoAchievementsFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()


public:

    /// <summary>Adds a count to a specified count achievement. The count will be added to the current count,
    /// for example, if the current count is 1 and the count you would like to add is 7, the final count will be 8 if the request succeeds.
    /// @note Available to count achievements only.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Name">The API name of the achievement.</param>
    /// <param name="Count">The count you want to add. The largest count supported by this function is the maximum value of a signed 64-bit integer.
    /// If the count is larger than that, it is clamped to that maximum value before being passed to the servers.
    /// </param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InAddCountCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoAddCount(UObject* WorldContextObject, const FString& Name, const FString& Count, const FString& ExtraData, FAddCount InAddCountCallback);

    /// <summary>Unlocks the bit(s) of a specified bitfield achievement. The status of the bit(s) is then unchangeable.
    /// @note Available to bitfield achievements only.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Name">The API name of the achievement to unlock bit(s) for.</param>
    /// <param name="Fields">A string containing either '0' or '1' characters, for example '100011'.
    /// Every '1' will unlock a bit in the corresponding position of a bitfield.
    /// </param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InAddFieldsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoAddFields(UObject* WorldContextObject, const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsCallback);

    /// <summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Name">The API name of the achievement to unlock.</param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InUnlockCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoUnlock(UObject* WorldContextObject, const FString& Name, const FString& ExtraData, FUnlock InUnlockCallback);

    /// <summary>Gets the information about all achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The size of the page.</param>
    /// <param name="InGetAllDefinitionsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetAllDefinitions(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsCallback);

    /// <summary>Gets the user's progress on all achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The size of the page.</param>
    /// <param name="InGetAllProgressCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetAllProgress(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressCallback);

    /// <summary>Gets the information about specified achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetDefinitionsByNameCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetDefinitionsByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameCallback);

    /// <summary>Gets the user's progress on specified achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetProgressByNameCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetProgressByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetProgressByName InGetProgressByNameCallback);

    // get next achievement definition page

    // get next achievement progress page
};

/** @} */ // end of BP_Achievements
/** @} */ // end of BlueprintFunction


//
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementUpdate : public UObject
{
    GENERATED_BODY()
    
public:
    void InitParams(ppfAchievementUpdateHandle ppfAchievementUpdateHandle);

private:
    FString Name = FString();
    bool JustUnlocked = false;
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Update")
    FString GetName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Update")
    bool GetJustUnlocked();
};
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementProgress : public UObject
{

    GENERATED_BODY()
    
public:
    void InitParams(ppfAchievementProgressHandle ppfAchievementProgressHandle);

private:
    FString Bitfield = FString();
    long long Count = 0;
    bool IsUnlocked = false;
    FString Name = FString();
    uint64_t ID = 0;
    unsigned long long UnlockTime = 0;
    TArray<uint8> ExtraData;
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetBitfield();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    int64 GetCount();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    bool GetIsUnlocked();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetUnlockTime();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FDateTime GetUnlockDateTime();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetID();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    TArray<uint8> GetExtraData();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetExtraDataString();
};
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementDefinition : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfAchievementDefinition* ppfAchievementDefinitionHandle);

private:
    EAchievementType Type = EAchievementType::Unknown;
    unsigned int BitfieldLength = 0;
    FString Name = FString();
    long long Target = 0;
    FString Description = FString();
    FString Title = FString();
    bool IsArchived = false;
    bool IsSecret = false;
    uint64_t ID = 0;
    FString UnlockedDescription = FString();
    EAchievementWritePolicy WritePolicy = EAchievementWritePolicy::Unknown;
    FString LockedImageURL = FString();
    FString UnlockedImageURL = FString();
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetBitfieldLength();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    int64 GetTarget();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    EAchievementType GetType();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetDescription();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetTitle();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    bool GetIsArchived();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    bool GetIsSecret();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetID();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetUnlockedDescription();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    EAchievementWritePolicy GetWritePolicy();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetLockedImageURL();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetUnlockedImageURL();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementProgressArray : public UObject
{
    GENERATED_BODY()
private:
    TArray<UPico_AchievementProgress*> AchievementProgressArray;
    FString NextPageParam = FString();
    int32 Size = 0;
    int32 TotalSize = 0;
    bool bHasNextPage;
public:
    void InitParams(ppfAchievementProgressArrayHandle InppfAchievementProgressArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    UPico_AchievementProgress* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    int32 GetSize();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    int32 GetTotalSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    bool HasNextPage();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementDefinitionArray : public UObject
{

    GENERATED_BODY()
private:
    TArray<UPico_AchievementDefinition*> AchievementDefinitionArray;
    FString NextPageParam = FString();
    int32 Size = 0;
    int32 TotalSize = 0;
    bool bHasNextPage;

public:
    void InitParams(ppfAchievementDefinitionArrayHandle InppfAchievementDefinitionArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
        UPico_AchievementDefinition* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
        FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
        int32 GetSize();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
        int32 GetTotalSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
        bool HasNextPage();
};
