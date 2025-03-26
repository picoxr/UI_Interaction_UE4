// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineLeaderboardInterface.h"
#include "OnlineIdentityPico.h"
#include "OnlineSubsystemPicoPackage.h"

#define WRITE_LEADERBOARDS_PAGEINDEX FName(TEXT("WRITELEADERBOARDSPAGEINDEX"))
#define WRITE_LEADERBOARDS_PAGESIZE FName(TEXT("WRITELEADERBOARDSPAGESIZE"))

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Leaderboard Leaderboard(OnlineSub)
  *  This is the Leaderboard(OnlineSub) group
  *  @{
  */


  /**
  *	IOnlineLeaderboard - Interface class for Leaderboard
  */
class FOnlineLeaderboardPico : public IOnlineLeaderboards
{
private:

    // Reference to the owning subsystem
    FOnlineSubsystemPico& PicoSubsystem;

    bool ReadPicoLeaderboards(bool bOnlyFriends, bool bOnlyLoggedInUser, FOnlineLeaderboardReadRef& ReadObject);
    void OnReadLeaderboardsComplete(ppfMessageHandle Message, bool bIsError, bool bOnlyFriends, bool bOnlyLoggedInUser, const FOnlineLeaderboardReadRef& ReadObject);

    const char* FilterTypeNames[4] = { "None", "Friends", "Unknown", "UserIds" };
    const char* StartAtNames[4] = { "Top", "CenteredOnViewer", "CenteredOnViewerOrTop", "Unknown" };

    static void SaveLog(const ELogVerbosity::Type Verbosity, const FString& Log);

public:
    const int MAX_REQUEST_SIZE = 100; // single max
    int ReadIndex = 0;

    //Constructor * @param InSubsystem - A reference to the owning subsystem
    FOnlineLeaderboardPico(FOnlineSubsystemPico& InSubsystem);

    // Default destructor
    virtual ~FOnlineLeaderboardPico() = default;

    // Begin IOnlineLeaderboard interface

    /// <summary>Gets the entries of a leaderboard.</summary>
    /// <param name="Players">Defines how the entries are returned:
    /// * If you leave this parameter empty, `StartAt` will be `none`,
    /// indicating that all entries of the leaderboard will be returned, and the rank starts from top 1 to the last.
    /// * If you pass the ID of the current logged-in user, `StartAt` will be `CenteredOnViewer`,
    /// indicating that the current logged-in user's entry will be placed in the middle of the list on the first page. 
    /// </param>
    /// <param name="PicoReadObject">Set the leaderboard name in it.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
/// @cond
#if ENGINE_MAJOR_VERSION > 4
    virtual bool ReadLeaderboards(const TArray< FUniqueNetIdRef >& Players, FOnlineLeaderboardReadRef& ReadObject) override;
#elif ENGINE_MINOR_VERSION > 26
    virtual bool ReadLeaderboards(const TArray< FUniqueNetIdRef >& Players, FOnlineLeaderboardReadRef& ReadObject) override;
#elif ENGINE_MINOR_VERSION > 24
/// @endcond
    virtual bool ReadLeaderboards(const TArray< TSharedRef<const FUniqueNetId> >& Players, FOnlineLeaderboardReadRef& ReadObject) override;
#endif

    /// <summary>Gets the entries of the friends of the current logged-in user on a leaderboard.</summary>
    /// <param name="LocalUserNum">not used</param>
    /// <param name="PicoReadObject">Set the leaderboard name in it.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    virtual bool ReadLeaderboardsForFriends(int32 LocalUserNum, FOnlineLeaderboardReadRef& ReadObject) override;

    // Not supported. Always return false.
    virtual bool ReadLeaderboardsAroundRank(int32 Rank, uint32 Range, FOnlineLeaderboardReadRef& ReadObject) override;

    // Not supported. Always return false.
    virtual bool ReadLeaderboardsAroundUser(TSharedRef<const FUniqueNetId> Player, uint32 Range, FOnlineLeaderboardReadRef& ReadObject) override;

    // Not supported.
    virtual void FreeStats(FOnlineLeaderboardRead& ReadObject) override;

    /// <summary>Writes an entry to a leaderboard for the current logged-in user.</summary>
    ///
    /// <param name="SessionName">not used</param>
    /// <param name="Player">The ID of the current logged-in user to write an entry for.</param>
    /// <param name="PicoWriteObject">Set the leaderboard name and the score in it.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    virtual bool WriteLeaderboards(const FName& SessionName, const FUniqueNetId& Player, FOnlineLeaderboardWrite& WriteObject) override;

    /// <summary>Executes developer-defined functions.</summary>
    ///
    /// <param name="SessionName">The parameter of `LeaderboardFlushCompleteDelegates`.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    virtual bool FlushLeaderboards(const FName& SessionName) override;

    // Not supported. Always return false.
    virtual bool WriteOnlinePlayerRatings(const FName& SessionName, int32 LeaderboardId, const TArray<FOnlinePlayerScore>& PlayerScores) override;
    // End IOnlineLeaderboard interface
};
#if ENGINE_MINOR_VERSION > 26
typedef TSharedPtr<FOnlineLeaderboardPico, ESPMode::ThreadSafe> FOnlineLeaderboardPicoPtr;
#elif ENGINE_MINOR_VERSION > 24
#endif

/** @} */ // end of Leaderboard(OnlineSub)
/** @} */ // end of Function