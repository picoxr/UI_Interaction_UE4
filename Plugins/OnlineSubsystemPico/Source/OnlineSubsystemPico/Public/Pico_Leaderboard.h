#pragma once
#include "OnlineStats.h"

class Pico_OnlineLeaderboardWrite : public FOnlineLeaderboardWrite
{
private:
public:
	TArray<FString> PicoLeaderboardNames;
	Pico_OnlineLeaderboardWrite(const TArray<FString> InLeaderboardNames)
	{
		for (const auto& LeaderboardName : InLeaderboardNames)
		{
			PicoLeaderboardNames.Add(LeaderboardName);
			LeaderboardNames.Add(FName(LeaderboardName));
		}
	}
	Pico_OnlineLeaderboardWrite()
	{
		
	}
};


class Pico_OnlineLeaderboardRead : public FOnlineLeaderboardRead
{
public:
	FString PicoLeaderboardName;
	int PicoPageIndex;
	int PicoPageSize;
	Pico_OnlineLeaderboardRead(const FString& InLeaderboardName, int PageIndex, int PageSize)
	{
		PicoLeaderboardName = InLeaderboardName;
		// LeaderboardName = FName(InLeaderboardName);
		PicoPageIndex = PageIndex;
		PicoPageSize = PageSize;
	}
};