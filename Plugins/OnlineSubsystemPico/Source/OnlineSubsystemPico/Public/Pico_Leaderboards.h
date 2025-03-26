// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_User.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FWriteEntryWithSupplementaryMetric, bool, bIsError, const FString&, ErrorMessage, bool, WriteResult);

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
    /// <param name="InGetDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardArray *, LeaderboardList).</param>
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool Get(const FString& LeaderboardName, FGet InGetDelegate);

    /// <summary>Gets a list of leaderboard entries.</summary>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page. The value ranges from 1 to 100.</param>
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
    /// <param name="InGetEntriesDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool GetEntries(const FString& LeaderboardName, int PageIdx, int PageSize, ppfLeaderboardFilterType Filter, ppfLeaderboardStartAt StartAt, FGetEntries InGetEntriesDelegate);
    
   	/// <summary>Gets the leaderboard entries after a specified ranking.</summary>
	/// <param name="LeaderboardName">Leaderboard name.</param>
	/// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="PageSize">The number of entries to return on each page. The value ranges from 1 to 100.</param>
	/// <param name="AfterRank">Defines after which rank to return entries.</param>
    /// <param name="InGetEntriesAfterRankDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool GetEntriesAfterRank(const FString& LeaderboardName, int PageIdx, int PageSize, unsigned long long AfterRank, FGetEntriesAfterRank InGetEntriesAfterRankDelegate);

	/// <summary>Gets the leaderboard entries for a specified user.</summary>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page. The value ranges from 1 to 100.</param>
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
    /// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
	/// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool GetEntriesByIds(const FString& LeaderboardName, int PageIdx, int PageSize, ppfLeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Writes a user's score to the leaderboard.</summary>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the user's score.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// <br>* `true`: make a force update
    /// <br>* `false`: no force update </param>
    /// <param name="InWriteEntryDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns> 
    bool WriteEntry(const FString& LeaderboardName, const int64& Score, const FString& ExtraData, bool ForceUpdate, FWriteEntry InWriteEntryDelegate);

    /// <summary>Adds custom contents when writing a user's score to a leaderboard.</summary>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="supplementaryMetric">Custom contents, such as a video.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the custom contents.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update:
    /// <br> * `true`: make a force update
    /// <br> * `false`: no force update </param>
    /// <param name="InWriteEntryWithSupplementaryMetricDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
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
    /// <param name="InGetDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardArray *, LeaderboardList).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void Get(UObject* WorldContextObject, const FString& LeaderboardName, FGet InGetDelegate);

    /// <summary>Gets a list of leaderboard entries.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page. The value ranges from 1 to 100.</param>
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
    /// <param name="InGetEntriesDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntries(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, ELeaderboardFilterType Filter, ELeaderboardStartAt StartAt, FGetEntries InGetEntriesDelegate);
    
   	/// <summary>Gets the leaderboard entries after a specified ranking.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page. The value ranges from 1 to 100. </param>
	/// <param name="pageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
	/// <param name="AfterRank">Defines after which rank to return entries.</param>
    /// <param name="InGetEntriesAfterRankDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntriesAfterRank(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, const FString& AfterRank, FGetEntriesAfterRank InGetEntriesAfterRankDelegate);

	/// <summary>Gets the leaderboard entries for specified user(s).</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="pageSize">The number of entries to return on each page. The value ranges from 1 to 100. </param>
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
    /// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void GetEntriesByIds(UObject* WorldContextObject, const FString& LeaderboardName, int PageIdx, int PageSize, ELeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Writes a user's score to the leaderboard.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the user's score.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update. </param>
    /// <param name="InWriteEntryDelegate">Will be executed when the request has been completed. 
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void WriteEntry(UObject* WorldContextObject, const FString& LeaderboardName, const FString& Score, const FString& ExtraData, bool ForceUpdate, FWriteEntry InWriteEntryDelegate);

    /// <summary>Adds custom contents when writing a user's score to a leaderboard.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="leaderboardName">Leaderboard name.</param>
    /// <param name="score">The user's score.</param>
    /// <param name="supplementaryMetric">Custom contents, such as a video.</param>
    /// <param name="extraData">Custom extension fields that can be used to record key information when writing the custom contents.</param>
    /// <param name="forceUpdate">Whether to force a leaderboard update. </param>
    /// <param name="InWriteEntryWithSupplementaryMetricDelegate">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboards")
    static void WriteEntryWithSupplementaryMetric(UObject* WorldContextObject, const FString& LeaderboardName, const FString& Score, const FString& SupplementaryMetric, const FString& ExtraData, bool ForceUpdate, FWriteEntryWithSupplementaryMetric InWriteEntryWithSupplementaryMetricDelegate);
    
};

/** @} */ // end of BP_Leaderboards
/** @} */ // end of BlueprintFunction


/// @brief UPico_LeaderboardEntry class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardEntry : public UObject
{

    GENERATED_BODY()
    
public:
    void InitParams(ppfLeaderboardEntryHandle ppfLeaderboardEntryHandle);

private:
    ppfID ID = 0;
    FString DisplayScore = FString();
    int Rank = 0;
    long Score = 0;
    FPicoSupplementaryMetric SupplementaryMetricOptional;
    unsigned long long Timestamp = 0;
	UPROPERTY()
    UPico_User* User = nullptr;
    TArray<uint8> ExtraData;
public:

    /** @brief Entry ID. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetID();

    /** @brief The entry's display score. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetDisplayScore();

    /** @brief The entry's ranking on the leaderboard. For example, returns `1` for top1.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    int32 GetRank();

    /** @brief The score used to rank the entry. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    int64 GetScore();

    /** @brief The supplementary metric used for tiebreakers. This field can be null. Need to check whether it is null before use. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FPicoSupplementaryMetric GetSupplementaryMetricOptional();

    /** @brief The time (as string) when the entry was written to the leaderboard. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetTimestamp();

    /** @brief The time when the entry was written to the leaderboard. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FDateTime GetTimestampDateTime();

    /** @brief The user the entry belongs to. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    UPico_User* GetUser();

    /** @brief Additional info, no more than 2KB. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry")
    FString GetExtraDataString();

};

/// @brief UPico_Leaderboard class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Leaderboard : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfLeaderboard* ppfLeaderboardHandle);

private:
    FString ApiName = FString();
    ppfID ID = 0;
    FPicoDestination DestinationOptional;
public:

    /** @brief The unique identifier of the leaderboard, which is configured on the PICO Developer Platform. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FString GetApiName();

    /** @brief Leaderboard ID. */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FString GetID();

    /** @brief Associate a destination to the leaderboard so that users can be directed to a specific location in the app.
     * If the leaderboard for that challenge is associated with a destination, the app will be launched, and the user will be directed to the destination.
     * If the leaderboard for that challenge is not associated with any destination, the app will be launched, and the user will be directed to the Home page.
     */
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard")
    FPicoDestination GetDestinationOptional();
};

/// @brief UPico_LeaderboardEntryArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardEntryArray : public UObject
{
    GENERATED_BODY()
private:
	UPROPERTY()
    TArray<UPico_LeaderboardEntry*> LeaderboardEntryArray;
    int32 Size = 0;
	unsigned long long TotalSize = 0;
    bool bHasNextPage;
	bool bHasPreviousPage;
public:
    void InitParams(ppfLeaderboardEntryArrayHandle InppfLeaderboardEntryArrayHandle);

    /** @brief Get LeaderboardEntryArray element form Index.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    UPico_LeaderboardEntry* GetElement(int32 Index);

    
    /** @brief Get the size of LeaderboardEntryArray .*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    int32 GetSize();
	

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
	int32 GetTotalSize();

    /** @brief Get whether the list has the next page.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    bool HasNextPage();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    bool HasPreviousPage();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Entry Array")
    FString GetDebugString();
};

/// @brief UPico_LeaderboardArray class.
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_LeaderboardArray : public UObject
{

    GENERATED_BODY()
private:
	UPROPERTY()
    TArray<UPico_Leaderboard*> LeaderboardArray;
    int32 Size = 0;
    bool bHasNextPage;
	unsigned long long TotalSize = 0;

public:
    void InitParams(ppfLeaderboardArrayHandle InppfLeaderboardArrayHandle);

    /** @brief Get LeaderboardArray element form Index.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
    UPico_Leaderboard* GetElement(int32 Index);

	/** @brief Get the size of LeaderboardArray .*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
    int32 GetSize();


    /** @brief Get the total size of LeaderboardArray .*/
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
	int32 GetTotalSize();

	/** @brief Get whether the list has the next page.*/
    UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
	bool HasNextPage();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Leaderboards|Leaderboard Definition Array")
	FString GetDebugString();
};
