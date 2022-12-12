// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_User.h"
#include "Pico_Leaderboards.generated.h"

/// @file Pico_Leaderboards.h

DECLARE_LOG_CATEGORY_EXTERN(PicoLeaderboards, Log, All);

class UPico_Leaderboard;
class UPico_LeaderboardEntry;
class UPico_LeaderboardEntryArray;
class UPico_LeaderboardArray;
class UPico_User;


/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGet, bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardArray*, LeaderboardList);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetEntries, bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray*, LeaderboardEntryList);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetEntriesAfterRank, bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray*, LeaderboardEntryList);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetEntriesByIds, bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray*, LeaderboardEntryList);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FWriteEntry, bool, bIsError, const FString&, ErrorMessage, bool, WriteResult);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FWriteEntryWithSupplementaryMetric, bool, bIsError, const FString&, ErrorMessage, bool, WriteResult); // todo WriteResult

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Leaderboards Leaderboards
 *  This is the Leaderboards group
 *  @{
 */

/// @brief PicoLeaderboardsInterface class.
class ONLINESUBSYSTEMPICO_API FPicoLeaderboardsInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoLeaderboardsInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoLeaderboardsInterface();

    FGet GetDelegate;
    FGetEntries GetEntriesDelegate;
    FGetEntriesAfterRank GetEntriesAfterRankDelegate;
    FGetEntriesByIds GetEntriesByIdsDelegate;
    FWriteEntry WriteEntryDelegate;
    FWriteEntryWithSupplementaryMetric WriteEntryWithSupplementaryMetricDelegate;

    /// <summary>Gets a specified leaderboard.</summary>
	/// <param name="leaderboardName">Leaderboard name.</param>
	/// <param name="InGetDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    bool Get(const FString& LeaderboardName, FGet InGetDelegate);

    /// <summary>Gets a list of leaderboard entries.</summary>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page.</param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="filter">Restricts the scope of entries to return:
    /// * `NONE`: returns all entries of the specified leaderboard
    /// * `FRIENDS`: returns the entries of the friends of the current logged-in user
    /// * `USER_IDS`(do not pass this value): returns the entries of specified users
    /// </param>
	/// <param name="startAt">Defines where to start returning challenge entries, the enumerations are:
    /// * `0`: Top (return entries from top 1)
    /// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed
    /// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be
    /// displayed on the second page)
    /// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,
    /// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,
    /// and top 10 will be displayed on the second page)
    /// </param>
	/// <param name="InGetEntriesDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool GetEntries(const FString& LeaderboardName, int PageIdx, int PageSize, ppfLeaderboardFilterType Filter, ppfLeaderboardStartAt StartAt, FGetEntries InGetEntriesDelegate);
    
   	/// <summary>Gets the leaderboard entries after a specified ranking.</summary>
	/// <param name="LeaderboardName">Leaderboard name.</param>
	/// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="PageSize">The number of entries to return on each page.</param>
	/// <param name="AfterRank">Defines after which rank to return entries.</param>
	/// <param name="InGetEntriesAfterRankDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool GetEntriesAfterRank(const FString& LeaderboardName, int PageIdx, int PageSize, unsigned long long AfterRank, FGetEntriesAfterRank InGetEntriesAfterRankDelegate);

	/// <summary>Gets the leaderboard entries for a specified user.</summary>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page.</param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="startAt">Defines where to start returning challenge entries, the enumerations are:
    /// * `0`: Top (return entries from top 1)
    /// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed
    /// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be
    /// displayed on the second page)
    /// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,
    /// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,
    /// and top 10 will be displayed on the second page)
    /// </param>
	/// <param name="userIDs">User ID.</param>
	/// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool GetEntriesByIds(const FString& LeaderboardName, int PageIdx, int PageSize, ppfLeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Writes a user's score to the leaderboard.</summary>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the user's score.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// * `true`: make a force update
    /// * `false`: no force update
	/// <param name="InWriteEntryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool WriteEntry(const FString& LeaderboardName, const int64& Score, const FString& ExtraData, bool ForceUpdate, FWriteEntry InWriteEntryDelegate);

    /// <summary>Adds custom contents when writing a user's score to a leaderboard.</summary>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="supplementaryMetric">Custom contents, such as a video.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the custom contents.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// * `true`: make a force update
    /// * `false`: no force update
	/// <param name="InWriteEntryWithSupplementaryMetricDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool WriteEntryWithSupplementaryMetric(const FString& LeaderboardName, const int64& Score, const int64& SupplementaryMetric, const FString& ExtraData, bool ForceUpdate, FWriteEntryWithSupplementaryMetric InWriteEntryWithSupplementaryMetricDelegate);

};
/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_Leaderboards BP_Leaderboards
 *  This is the BP_Leaderboards group
 *  @{
 */

/// @brief OnlinePicoLeaderboards Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoLeaderboardsFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()


public:

    /// <summary>Gets a specified leaderboard.</summary>
	/// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
	/// <param name="InGetDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void Get(UObject* WorldContextObject, const FString& LeaderboardName, FGet InGetDelegate);

    /// <summary>Gets a list of leaderboard entries.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page.</param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="filter">Restricts the scope of entries to return:
    /// * `NONE`: returns all entries of the specified leaderboard
    /// * `FRIENDS`: returns the entries of the friends of the current logged-in user
    /// * `USER_IDS`(do not pass this value): returns the entries of specified users
    /// </param>
	/// <param name="startAt">Defines where to start returning challenge entries, the enumerations are:
    /// * `0`: Top (return entries from top 1)
    /// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed
    /// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be
    /// displayed on the second page)
    /// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,
    /// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,
    /// and top 10 will be displayed on the second page)
    /// </param>
	/// <param name="InGetEntriesDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntries(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, ELeaderboardFilterType Filter, ELeaderboardStartAt StartAt, FGetEntries InGetEntriesDelegate);
    
   	/// <summary>Gets the leaderboard entries after a specified ranking.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page.</param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="AfterRank">Defines after which rank to return entries.</param>
	/// <param name="InGetEntriesAfterRankDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntriesAfterRank(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, const FString& AfterRank, FGetEntriesAfterRank InGetEntriesAfterRankDelegate);

	/// <summary>Gets the leaderboard entries for specified user(s).</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page.</param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="startAt">Defines where to start returning challenge entries, the enumerations are:
    /// * `0`: Top (return entries from top 1)
    /// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed
    /// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be
    /// displayed on the second page)
    /// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.
    /// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,
    /// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,
    /// and top 10 will be displayed on the second page)
    /// </param>
	/// <param name="userIDs">User ID(s).</param>
	/// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntriesByIds(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, ELeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Writes a user's score to the leaderboard.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the user's score.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// * `true`: make a force update
    /// * `false`: no force update
	/// <param name="InWriteEntryDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void WriteEntry(UObject* WorldContextObject, const FString& LeaderboardName, const FString& Score, const FString& ExtraData, bool ForceUpdate, FWriteEntry InWriteEntryDelegate);

    /// <summary>Adds custom contents when writing a user's score to a leaderboard.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="supplementaryMetric">Custom contents, such as a video.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the custom contents.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// * `true`: make a force update
    /// * `false`: no force update
	/// <param name="InWriteEntryWithSupplementaryMetricDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void WriteEntryWithSupplementaryMetric(UObject* WorldContextObject, const FString& LeaderboardName, const FString& Score, const FString& SupplementaryMetric, const FString& ExtraData, bool ForceUpdate, FWriteEntryWithSupplementaryMetric InWriteEntryWithSupplementaryMetricDelegate);
    
};

/** @} */ // end of BP_Leaderboards
/** @} */ // end of BlueprintFunction


//
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardEntry : public UObject
{

    GENERATED_BODY()
    
public:
    void InitParams(ppfLeaderboardEntryHandle ppfLeaderboardEntryHandle);

private:
    uint64_t ID = 0;
    FString DisplayScore = FString();
    int Rank = 0;
    long Score = 0;
    FPicoSupplementaryMetric SupplementaryMetricOptional;
    unsigned long long Timestamp = 0;
    UPico_User* User = nullptr;
    TArray<uint8> ExtraData;
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetID();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetDisplayScore();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    int32 GetRank();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    int64 GetScore();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FPicoSupplementaryMetric GetSupplementaryMetricOptional();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetTimestamp();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FDateTime GetTimestampDateTime();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    UPico_User* GetUser();
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetExtraDataString();

};
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Leaderboard : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfLeaderboard* ppfLeaderboardHandle);

private:
    FString ApiName = FString();
    uint64_t ID = 0;
    FPicoDestination DestinationOptional;
public:

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FString GetApiName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FString GetID();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FPicoDestination GetDestinationOptional();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardEntryArray : public UObject
{
    GENERATED_BODY()
private:
    TArray<UPico_LeaderboardEntry*> LeaderboardEntryArray;
    FString NextPageParam = FString();
    int32 Size = 0;
    bool bHasNextPage;
	int32 TotalSize = 0;
public:
    void InitParams(ppfLeaderboardEntryArrayHandle InppfLeaderboardEntryArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    UPico_LeaderboardEntry* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    int32 GetSize();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
	int32 GetTotalSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    bool HasNextPage();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardArray : public UObject
{

    GENERATED_BODY()
private:
    TArray<UPico_Leaderboard*> LeaderboardArray;
    FString NextPageParam = FString();
    int32 Size = 0;
    bool bHasNextPage;

public:
    void InitParams(ppfLeaderboardArrayHandle InppfLeaderboardArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
        UPico_Leaderboard* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
        FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
        int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
        bool HasNextPage();
};
