// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_Sport.generated.h"

/**
 * 
 */

 /// @file Pico_Sport.h

DECLARE_LOG_CATEGORY_EXTERN(PicoSport, Log, All);


DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetDailySummary, bool, bIsError, const FString&, ErrorMessage, UPico_SportDailySummaryArray*, SportDailySummaryArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetSummary, bool, bIsError, const FString&, ErrorMessage, UPico_SportSummary*, SportSummary);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetSportUserInfo, bool, bIsError, const FString&, ErrorMessage, UPico_SportUserInfo*, SportUserInfo);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Sport Sport
  *  This is the Sport group
  *  @{
  */

/// @brief PicoSportInterface class.
class ONLINESUBSYSTEMPICO_API FPicoSportInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoSportInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoSportInterface();

    FGetDailySummary GetDailySummaryDelegate;
    FGetSummary GetSummaryDelegate;
    FGetSportUserInfo GetSportUserInfoDelegate;


    /// <summary>
    /// Gets a summary of the user's daily exercise data for a specified period within the recent 3 months.
    /// For example, if the period you set is between 2022/08/16 and 2022/08/18, the exercise data generated on 08/16, 08/17, and 08/18 will be returned.
    /// </summary>
    /// <param name="BeginTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>
    /// <param name="EndTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the end time of the period.</param>
    /// <param name="InGetDailySummaryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetDailySummary(int64 BeginTime, int64 EndTime, FGetDailySummary InGetDailySummaryDelegate);

    /// <summary>
    /// Gets a summary of the user's exercise data for a specified duration within today. The duration should not exceed 24 hours.
    /// </summary>
    /// <param name="BeginTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>
    /// <param name="EndTime">A DateTime struct(FDateTime(int64 InTicks)GetTicks()) defining the end time of the period.</param>
    /// <param name="InGetSummaryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetSummary(int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate);

    /// <summary>
    /// Gets a user's basic information and exercise plan.
    /// </summary>
    /// <param name="InGetSportUserInfoDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool GetSportUserInfo(FGetSportUserInfo InGetSportUserInfoDelegate);


};

/** @} */
/** @} */

/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

 /** @defgroup BP_Sport BP_Sport
  *  This is the BP_Sport group
  *  @{
  */

/// @brief OnlinePicoSport Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoSportFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /// <summary>
    /// Gets a summary of the user's daily exercise data for a specified period within the recent 3 months.
    /// For example, if the period you set is between 2022/08/16 and 2022/08/18, the exercise data generated on 08/16, 08/17, and 08/18 will be returned.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="BeginTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>
    /// <param name="EndTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the end time of the period.</param>
    /// <param name="InGetDailySummaryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static bool GetDailySummary(UObject* WorldContextObject, int64 BeginTime, int64 EndTime, FGetDailySummary InGetDailySummaryDelegate);

    /// <summary>
    /// Gets a summary of the user's exercise data for a specified duration within today. The duration should not exceed 24 hours.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="BeginTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>
    /// <param name="EndTime">A DateTime struct(FDateTime(int64 InTicks)GetTicks()) defining the end time of the period.</param>
    /// <param name="InGetSummaryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static bool GetSummary(UObject* WorldContextObject, int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate);
    
    /// <summary>
    /// Gets a user's basic information and exercise plan.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetSportUserInfoDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static bool GetSportUserInfo(UObject* WorldContextObject, FGetSportUserInfo InGetSportUserInfoDelegate);
    
    /// <summary>
    /// Convert FDateTime to int64
    /// @note BlueprintPure function.
    /// </summary>
    /// <param name ="InDateTime">Input DateTime.</param>
    /// <returns>int64 result
    /// </returns>
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static int64 ConvertDateTimeToInt64(FDateTime InDateTime);

    /// <summary>
    /// Converts int64 to FDateTime.
    /// @note BlueprintPure function.
    /// </summary>
    /// <param name ="InValue">The int64 input.</param>
    /// <returns>The FDateTime result of the int64 input.
    /// </returns>
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static FDateTime ConvertInt64ToDateTime(int64 InValue);
};

/** @} */ // end of BP_Sport
/** @} */ // end of BlueprintFunction

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SportDailySummary : public UObject
{
    GENERATED_BODY()
public:
    void InitParams(ppfSportDailySummary* ppfSportDailySummaryHandle);

private:
    int64 ID = -1;
    int64 Date = -1;
    int32 DurationInSeconds = -1;
    int32 PlanDurationInMinutes = -1;
    float Calorie = 0;
    float PlanCalorie = 0;

public:

    // Count ID
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int64 GetID();

    // Date
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int64 GetDate();

    // Daily exercise duration (in seconds)
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int32 GetDurationInSeconds();

    // Planned daily exercise duration (in minutes)
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int32 GetPlanDurationInMinutes();

    // Calorie
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    float GetCalorie();

    // Plan calorie
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    float GetPlanCalorie();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SportDailySummaryArray : public UObject
{
    GENERATED_BODY()
public:
    void InitParams(ppfSportDailySummaryArray* ppfSportDailySummaryArrayHandle);

private:
    UPROPERTY()
    TArray<UPico_SportDailySummary*> SportDailySummaryArray;
    int32 Size;

public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary Array")
    int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary Array")
    UPico_SportDailySummary* GetElement(int32 Index);
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SportSummary : public UObject
{
    GENERATED_BODY()
public:
    void InitParams(ppfSportSummary* ppfSportSummaryHandle);

private:
    int64 DurationInSeconds = -1;
    float Calorie = 0;
    int64 StartTime = -1;
    int64 EndTime = -1;

public:

    // Daily exercise duration (in seconds)
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetDurationInSeconds();

    // Calorie
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    float GetCalorie();

    // Start time
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetStartTime();

    // End time
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetEndTime();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_SportUserInfo : public UObject
{
    GENERATED_BODY()
public:
    void InitParams(ppfSportUserInfo* ppfSportUserInfoHandle);

private:
    EUserGender Gender = EUserGender::Unknow;
    int64 Birthday = -1;
    int32 Stature = -1;
    int32 Weight = -1;
    int32 SportLevel = -1;
    int32 DailyDurationInMinutes = -1;
    int32 DaysPerWeek = -1;
    ESportTarget SportTarget = ESportTarget::None;

public:

    // Gender
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    EUserGender GetGender();

    // Birthday
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int64 GetBirthday();

    // Stature(cm)
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetStature();

    // Weight(kg) 
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetWeight();

    // 1-low£»2-medium£»3-high
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetSportLevel();

    // Planned daily exercise duration (in minutes)
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetDailyDurationInMinutes();

    // Planned days for exercise per week
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetDaysPerWeek();

    // Exercise target: "lose weight" or "stay healthy"
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    ESportTarget GetSportTarget();
};