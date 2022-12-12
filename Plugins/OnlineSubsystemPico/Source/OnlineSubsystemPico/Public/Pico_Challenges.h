// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_Leaderboards.h"
#include "Pico_User.h"
#include "Pico_Challenges.generated.h"

/// @file Pico_Challenges.h

// class UPico_Leaderboard;
class UPico_Challenge;
class UPico_ChallengeEntry;
class UPico_ChallengeEntryArray;
class UPico_ChallengeArray;
// enum FPico_ChallengeOptions;


USTRUCT(BlueprintType, meta = (DisplayName = "ChallengeOptions"))
struct FPico_ChallengeOptions
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") int32 StartDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") int32 EndDate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") FString LeaderboardName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") bool bIncludeActiveChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") bool bIncludeFutureChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") bool bIncludePastChallenges;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") EChallengeVisibility Visibility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pico Platform|Challenges|Challenge Options") EChallengeViewerFilter ViewerFilter;
};



DECLARE_LOG_CATEGORY_EXTERN(PicoChallenges, Log, All);

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeGet, bool, bIsError, const FString&, ErrorMessage, UPico_Challenge*,
                                     Challenge);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeGetEntries, bool, bIsError, const FString&, ErrorMessage,
                                     UPico_ChallengeEntryArray*, ChallengeEntryList);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeGetEntriesAfterRank, bool, bIsError, const FString&, ErrorMessage,
                                     UPico_ChallengeEntryArray*, ChallengeEntryList);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeGetEntriesByIds, bool, bIsError, const FString&, ErrorMessage,
                                     UPico_ChallengeEntryArray*, ChallengeEntryList);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeGetList, bool, bIsError, const FString&, ErrorMessage,
                                     UPico_ChallengeArray*, ChallengeList);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeInvite, bool, bIsError, const FString&, ErrorMessage,
                                     UPico_Challenge*, Challenge);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeLeave, bool, bIsError, const FString&, ErrorMessage, UPico_Challenge*,
                                     Challenge);

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FChallengeJoin, bool, bIsError, const FString&, ErrorMessage, UPico_Challenge*,
                                     Challenge);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Challenges Challenges
 *  This is the Challenges group
 *  @{
 */

/// @brief PicoChallengesInterface class.
class ONLINESUBSYSTEMPICO_API FPicoChallengesInterface
{
private:
	FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoChallengesInterface(FOnlineSubsystemPico& InSubsystem);
	~FPicoChallengesInterface();

	FChallengeGet GetDelegate;
	FChallengeGetEntries GetEntriesDelegate;
	FChallengeGetEntriesAfterRank GetEntriesAfterRankDelegate;
	FChallengeGetEntriesByIds GetEntriesByIdsDelegate;
	FChallengeGetList GetListDelegate;
	FChallengeJoin JoinDelegate;
	FChallengeLeave LeaveDelegate;
	FChallengeInvite InviteDelegate;

    /// <summary>Gets a specified challenge by ID.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InGetDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool Get(const FString& ChallengeID, FChallengeGet InGetDelegate);

    /// <summary>Gets a list of challenge entries.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="Filter">Restricts the scope of entries to return:
    /// * `NONE`: returns all entries of the specified leaderboard
    /// * `FRIENDS`: returns the entries of the friends of the current logged-in user
    /// * `USER_IDS`(do not pass this value): returns the entries of specified users
    /// </param>
    /// <param name="StartAt">Defines where to start returning challenge entries, the enumerations are:
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
	bool GetEntries(const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardFilterType Filter,
	                ELeaderboardStartAt StartAt, FChallengeGetEntries InGetEntriesDelegate);

    /// <summary>Gets the challenge entries after a specified ranking.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
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
	bool GetEntriesAfterRank(ppfID ChallengeID, int PageIdx, int PageSize, unsigned long long AfterRank,
	                         FChallengeGetEntriesAfterRank InGetEntriesAfterRankDelegate);

    /// <summary>Gets the challenge entries for specified user(s).</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="StartAt">Defines where to start returning challenge entries, the enumerations are:
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
    /// <param name="UserIDs">User ID(s).</param>
    /// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	bool GetEntriesByIds(const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardStartAt StartAt,
	                     const TArray<FString>& UserIDs, FChallengeGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Gets a list of challenges.</summary>
    /// <param name="ChallengeOptions">Restricts the scope of challenges to return. You can define the start date and
    /// end date of challenges, the leaderboard the challenges belong to, etc.
    /// </param>
    /// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="InGetListDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	bool GetList(FPico_ChallengeOptions ChallengeOptions, int PageIdx, int PageSize, FChallengeGetList InGetListDelegate);

    /// <summary>Lets the current user join a challenge.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InJoinDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	bool Join(const FString& ChallengeID, FChallengeJoin InJoinDelegate);

    /// <summary>Lets the current user leave a challenge.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InLeaveDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	bool Leave(const FString& ChallengeID, FChallengeLeave InLeaveDelegate);

    /// <summary>Invites user(s) to join a challenge.</summary>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="UserIDs">User ID(s).</param>
    /// <param name="Delegate>Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	bool Invite(const FString& ChallengeID, const TArray<FString>& UserIDs, FChallengeInvite Delegate);

};

/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_Challenges BP_Challenges
 *  This is the BP_Challenges group
 *  @{
 */

/// @brief OnlinePicoChallenges Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoChallengesFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

    /// <summary>Gets a specified challenge by ID.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InGetDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void Get(UObject* WorldContextObject, const FString& ChallengeID, FChallengeGet InGetDelegate);

    /// <summary>Gets a list of challenge entries.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="Filter">Restricts the scope of entries to return:
    /// * `NONE`: returns all entries of the specified leaderboard
    /// * `FRIENDS`: returns the entries of the friends of the current logged-in user
    /// * `USER_IDS`(do not pass this value): returns the entries of specified users
    /// </param>
    /// <param name="StartAt">Defines where to start returning challenge entries, the enumerations are:
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
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void GetEntries(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize,
	                       ELeaderboardFilterType Filter, ELeaderboardStartAt StartAt,
	                       FChallengeGetEntries InGetEntriesDelegate);

    /// <summary>Gets the challenge entries after a specified ranking.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
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
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void GetEntriesAfterRank(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize,
	                                const FString& AfterRank,
	                                FChallengeGetEntriesAfterRank InGetEntriesAfterRankDelegate);

    /// <summary>Gets the challenge entries for specified user(s).</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="PageIdx">Defines which page of entries to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of entries to return on each page.</param>
    /// <param name="StartAt">Defines where to start returning challenge entries, the enumerations are:
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
    /// <param name="UserIDs">User ID(s).</param>
    /// <param name="InGetEntriesByIdsDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void GetEntriesByIds(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize,
	                            ELeaderboardStartAt StartAt, const TArray<FString>& UserIDs,
	                            FChallengeGetEntriesByIds InGetEntriesByIdsDelegate);

    /// <summary>Gets a list of challenges.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeOptions">Restricts the scope of challenges to return. You can define the start date and
    /// end date of challenges, the leaderboard the challenges belong to, etc.
    /// <param name="PageIdx">Defines which page of challenges to return. The value = (The target page No.)-1.
    /// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>
    /// <param name="PageSize">The number of challenges to return on each page.</param>
    /// <param name="InGetListDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void GetList(UObject* WorldContextObject, FPico_ChallengeOptions ChallengeOptions, int PageIdx, int PageSize,
	                    FChallengeGetList InGetListDelegate);

    /// <summary>Lets the current user join a challenge.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InJoinDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void Join(UObject* WorldContextObject, const FString& ChallengeID, FChallengeJoin InJoinDelegate);

    /// <summary>Lets the current user leave a challenge.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="InLeaveDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void Leave(UObject* WorldContextObject, const FString& ChallengeID, FChallengeLeave InLeaveDelegate);

    /// <summary>Invites user(s) to join a challenge.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="ChallengeID">Challenge ID.</param>
    /// <param name="UserIDs">User ID(s).</param>
    /// <param name="Delegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Challenges")
	static void Invite(UObject* WorldContextObject, const FString& ChallengeID, const TArray<FString>& UserIDs, 
	                          FChallengeInvite Delegate);
};

/** @} */ // end of BP_Challenges
/** @} */ // end of BlueprintFunction


UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Challenge : public UObject
{
	GENERATED_BODY()

public:
	void InitParams(ppfChallenge* ppfChallengeHandle);

private:
	ppfChallengeCreationType CreationType;
	unsigned long long EndDate = 0;
	unsigned long long StartDate = 0;
	uint64_t ID = 0;
	FString Title = FString();
	ppfChallengeVisibility Visibility;
	UPico_UserArray* InvitedUsersOptional;
	UPico_UserArray* ParticipantsOptional;
	UPico_Leaderboard* Leaderboard;

public:
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	EChallengeCreationType GetCreationType();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FDateTime GetEndDateTime();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FDateTime GetStartDateTime();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FString GetEndDate();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FString GetStartDate();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FString GetID();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	FString GetTitle();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	EChallengeVisibility GetVisibility();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	UPico_UserArray* GetInvitedUsersOptional();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	UPico_Leaderboard* GetLeaderboard();
	
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge")
	UPico_UserArray* GetParticipantsOptional();
};

//
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_ChallengeEntry : public UObject
{
	GENERATED_BODY()

public:
	void InitParams(ppfChallengeEntryHandle ppfChallengeEntryHandle);

private:
	FString DisplayScore = FString();
	TArray<uint8> ExtraData;
	uint64_t ID = 0;
	int Rank;
	long Score;
	unsigned long long Timestamp;
	UPico_User* User;

public:
	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	FString GetDisplayScore();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	TArray<uint8> GetExtraData();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	FString GetExtraDataString();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	FString GetID();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	int32 GetRank();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	int64 GetScore();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	FDateTime GetTimestamp();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry")
	UPico_User* GetUser();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_ChallengeEntryArray : public UObject
{
	GENERATED_BODY()
private:
	TArray<UPico_ChallengeEntry*> ChallengeEntryArray;
	int32 Size = 0;
	bool bHasNextPage;
public:
	void InitParams(ppfChallengeEntryArrayHandle InppfChallengeEntryArrayHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry Array")
	UPico_ChallengeEntry* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry Array")
	int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Entry Array")
	bool HasNextPage();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_ChallengeArray : public UObject
{
	GENERATED_BODY()
private:
	TArray<UPico_Challenge*> ChallengeArray;
	int32 Size = 0;
	bool bHasNextPage;

public:
	void InitParams(ppfChallengeArrayHandle InppfChallengeArrayHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Array")
	UPico_Challenge* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Array")
	int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|Challenges|Challenge Array")
	bool HasNextPage();
};

