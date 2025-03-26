// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
    /// <param name="InGetDailySummaryDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportDailySummaryArray *, SportDailySummaryArray).</param>
    /// <remarks></remarks>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool GetDailySummary(int64 BeginTime, int64 EndTime, FGetDailySummary InGetDailySummaryDelegate);

    /// <summary>
    /// Gets a summary of the user's exercise data for a specified duration within today. The duration should not exceed 24 hours.
    /// </summary>
    /// <param name="BeginTime">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>
    /// <param name="EndTime">A DateTime struct(FDateTime(int64 InTicks)GetTicks()) defining the end time of the period.</param>
    /// <param name="InGetSummaryDelegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportSummary *, SportSummary).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool GetSummary(int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate);

    /// <summary>
    /// Gets a user's basic information and exercise plan.
    /// </summary>
    /// <param name="InGetSportUserInfoDelegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportUserInfo *, SportUserInfo).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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
    /// <param name="InGetDailySummaryDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportDailySummaryArray *, SportDailySummaryArray).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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
    /// <param name="InGetSummaryDelegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportSummary *, SportSummary).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Sport")
    static bool GetSummary(UObject* WorldContextObject, int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate);
    
    /// <summary>
    /// Gets a user's basic information and exercise plan.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetSportUserInfoDelegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportUserInfo *, SportUserInfo).</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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

/// @brief UPico_SportDailySummary class.
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

    /** @brief The ID of the summary.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int64 GetID();

    /** @brief The date when the summary was generated.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int64 GetDate();

    /** @brief The sport duration (in seconds).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int32 GetDurationInSeconds();

    /** @brief The planned sport duration (in seconds).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    int32 GetPlanDurationInMinutes();

    /** @brief The actual calorie burnt (in kilo calorie).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    float GetCalorie();

    /** @brief The planned calorie to burn. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary")
    float GetPlanCalorie();
};


/// @brief UPico_SportDailySummaryArray class.
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

    /** @brief Get the size of SportDailySummaryArray .*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary Array")
    int32 GetSize();

    /** @brief Get SportDailySummaryArray element form Index.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Daily Summary Array")
    UPico_SportDailySummary* GetElement(int32 Index);
};


/// @brief UPico_SportSummary class.
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

    /** @brief The sport duration (in seconds).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetDurationInSeconds();

    /** @brief The calorie burnt (in kilo calorie).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    float GetCalorie();

    /** @brief The time when the user started playing sport.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetStartTime();

    /** @brief The time when the user stopped playing sport.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|Sport Summary")
    int64 GetEndTime();
};

/// @brief UPico_SportUserInfo class.
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

    /**@brief The gender of the user (in cm). */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    EUserGender GetGender();

    /**@brief The birthday of the user (in cm). */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int64 GetBirthday();

    /**@brief The height of the user (in cm). */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetStature();

    /**@brief The weight of the user (in kg). */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetWeight();

    /** @brief The sport level that indicates the intensity of the sport.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetSportLevel();

    /** @brief The planned daily sport duration (in minutes).*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetDailyDurationInMinutes();

    /** @brief The planned weekly sport days.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    int32 GetDaysPerWeek();

    /** @brief The sport purpose, such as `keep fit` and `lose weight`. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Sport|User Info")
    ESportTarget GetSportTarget();
};