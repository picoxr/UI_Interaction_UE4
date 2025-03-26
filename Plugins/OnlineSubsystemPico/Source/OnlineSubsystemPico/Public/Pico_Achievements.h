// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
    /// <param name="InAddCountDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
    /// </param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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
    /// <param name="InAddFieldsCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool AddFields(const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsCallback);

    /// <summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.</summary>
    /// <param name="Name">The API name of the achievement to unlock.</param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InUnlockCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool Unlock(const FString& Name, const FString& ExtraData, FUnlock InUnlockCallback);

    /// <summary>Gets the information about all achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="InGetAllDefinitionsCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool GetAllDefinitions(int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsCallback);

    /// <summary>Gets the user's progress on all achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="InGetAllProgressCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool GetAllProgress(int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressCallback);

    /// <summary>Gets the information about specified achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetDefinitionsByNameCallback">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool GetDefinitionsByName(const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameCallback);

    /// <summary>Gets the user's progress on specified achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetProgressByNameCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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
    /// <param name="InAddCountCallback">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
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
    /// <param name="InAddFieldsCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoAddFields(UObject* WorldContextObject, const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsCallback);

    /// <summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Name">The API name of the achievement to unlock.</param>
    /// <param name="ExtraData">Custom extension fields that can be used to record key information when unlocking achievements.</param>
    /// <param name="InUnlockCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoUnlock(UObject* WorldContextObject, const FString& Name, const FString& ExtraData, FUnlock InUnlockCallback);

    /// <summary>Gets the information about all achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="InGetAllDefinitionsCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetAllDefinitions(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsCallback);

    /// <summary>Gets the user's progress on all achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="PageIndex">The start index of the pages.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="InGetAllProgressCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetAllProgress(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressCallback);

    /// <summary>Gets the information about specified achievements,
    /// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetDefinitionsByNameCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetDefinitionsByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameCallback);

    /// <summary>Gets the user's progress on specified achievements,
    /// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,
    /// depending on the type, the progress made towards unlocking them, and more.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="NameArray">The API names of the achievements.</param>
    /// <param name="InGetProgressByNameCallback">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Achievements")
    static void PicoGetProgressByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetProgressByName InGetProgressByNameCallback);

    // get next achievement definition page

    // get next achievement progress page
};

/** @} */ // end of BP_Achievements
/** @} */ // end of BlueprintFunction


/// @brief UPico_AchievementUpdate class.
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

    /** @brief Achievement name. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Update")
    FString GetName();

    /** @brief Whether the achievement is unlocked in this time. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Update")
    bool GetJustUnlocked();
};

/// @brief UPico_AchievementProgress class.
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
    ppfID ID = 0;
    unsigned long long UnlockTime = 0;
    TArray<uint8> ExtraData;
public:

    /** @brief The progress of a bitfield achievement. `1` represents a completed bit. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetBitfield();

    /** @brief The progress of a count achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    int64 GetCount();

    /** @brief Whether the achievement is unlocked */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    bool GetIsUnlocked();

    /** @brief Achievement name. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetName();

    /** @brief The time when the achievement is unlocked (as string). */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetUnlockTime();
    
    /** @brief The time when the achievement is unlocked. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FDateTime GetUnlockDateTime();

    /** @brief Achievement ID. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetID();

    /** @brief  Additional info, no more than 2KB.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    TArray<uint8> GetExtraData();

    /** @brief  Additional info(as string), no more than 2KB.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress")
    FString GetExtraDataString();
};

/// @brief UPico_AchievementDefinition class.
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
    ppfID ID = 0;
    FString UnlockedDescription = FString();
    EAchievementWritePolicy WritePolicy = EAchievementWritePolicy::Unknown;
    FString LockedImageURL = FString();
    FString UnlockedImageURL = FString();
public:

    /** @brief The API name of the achievement. An API name serves as the unique identifier of an achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetName();

    /** @brief The requirement that users should meet for unlocking a bitfield achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetBitfieldLength();

    /** @brief The requirement that users should meet for unlocking a count achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    int64 GetTarget();

    /** @brief The type of the achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    EAchievementType GetType();
    
    /** @brief The description of the achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetDescription();
    
    /** @brief The display name of the achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetTitle();
    
    /** @brief Whether the achievement is archived. Archived achievements are invisible to users. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    bool GetIsArchived();
    
    /** @brief Whether the achievement is a hidden achievement. If so, it can be visible after being unlocked only. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    bool GetIsSecret();
    
    /** @brief The ID of the achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetID();
    
    /** @brief The description displayed to users after they unlock the achievement. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetUnlockedDescription();
    
    /** @brief The data-writing policy of the achievement, which indicates whether the client or server are allowed to update the achievement's progress. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    EAchievementWritePolicy GetWritePolicy();
    
    /** @brief The URL of the image displayed when the achievement is still locked. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetLockedImageURL();
    
    /** @brief The URL of the image displayed when the achievement is unlocked. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition")
    FString GetUnlockedImageURL();
};

/// @brief UPico_AchievementProgressArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementProgressArray : public UObject
{
    GENERATED_BODY()
private:
    UPROPERTY()
    TArray<UPico_AchievementProgress*> AchievementProgressArray;
    int32 Size = 0;
    int32 TotalSize = 0;
    bool bHasNextPage;
public:
    void InitParams(ppfAchievementProgressArrayHandle InppfAchievementProgressArrayHandle);

    /** @brief Get AchievementProgressArray element form Index.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    UPico_AchievementProgress* GetElement(int32 Index);
    

    /** @brief Get the size of AchievementProgressArray .*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    int32 GetSize();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    int32 GetTotalSize();

    /** @brief Get whether the list has the next page.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Progress Array")
    bool HasNextPage();
};

/// @brief UPico_AchievementDefinitionArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_AchievementDefinitionArray : public UObject
{

    GENERATED_BODY()
private:
    UPROPERTY()
    TArray<UPico_AchievementDefinition*> AchievementDefinitionArray;
    int32 Size = 0;
    int32 TotalSize = 0;
    bool bHasNextPage;

public:
    void InitParams(ppfAchievementDefinitionArrayHandle InppfAchievementDefinitionArrayHandle);

    /** @brief Get AchievementDefinitionArray element form Index.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
    UPico_AchievementDefinition* GetElement(int32 Index);

    /** @brief Get the size of AchievementDefinitionArray .*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
    int32 GetSize();
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
    int32 GetTotalSize();

    /** @brief Get whether the list has the next page.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Achievements|Achievement Definition Array")
    bool HasNextPage();
};
