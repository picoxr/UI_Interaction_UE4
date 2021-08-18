// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineLeaderboardInterface.h"


/**
*	IOnlineLeaderboard - Interface class for Leader board
*/
class FOnlineLeaderboardPico : public IOnlineLeaderboards
{
private:
	
	/** Reference to the owning subsystem */
	FOnlineSubsystemPico& PicoSubsystem;

	bool ReadPicoLeaderboards(bool bOnlyFriends, bool bOnlyLoggedInUser, FOnlineLeaderboardReadRef& ReadObject);
	void OnReadLeaderboardsComplete(FOnlineMessageHandle Message, bool bIsError, const FOnlineLeaderboardReadRef& ReadObject);

public:

	/**
	* Constructor
	*
	* @param InSubsystem - A reference to the owning subsystem
	*/
	FOnlineLeaderboardPico(FOnlineSubsystemPico& InSubsystem);

	/**
	* Default destructor
	*/
	virtual ~FOnlineLeaderboardPico() = default;

	// Begin IOnlineLeaderboard interface
	virtual bool ReadLeaderboards(const TArray< TSharedRef<const FUniqueNetId> >& Players, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual bool ReadLeaderboardsForFriends(int32 LocalUserNum, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual bool ReadLeaderboardsAroundRank(int32 Rank, uint32 Range, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual bool ReadLeaderboardsAroundUser(TSharedRef<const FUniqueNetId> Player, uint32 Range, FOnlineLeaderboardReadRef& ReadObject) override;
	virtual void FreeStats(FOnlineLeaderboardRead& ReadObject) override;
	virtual bool WriteLeaderboards(const FName& SessionName, const FUniqueNetId& Player, FOnlineLeaderboardWrite& WriteObject) override;
	virtual bool FlushLeaderboards(const FName& SessionName) override;
	virtual bool WriteOnlinePlayerRatings(const FName& SessionName, int32 LeaderboardId, const TArray<FOnlinePlayerScore>& PlayerScores) override;
	// End IOnlineLeaderboard interface
};