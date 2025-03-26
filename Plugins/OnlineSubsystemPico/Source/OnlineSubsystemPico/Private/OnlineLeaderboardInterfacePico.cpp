// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlineLeaderboardInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineIdentityPico.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSessionSettings.h"
#include "Misc/FileHelper.h"

FOnlineLeaderboardPico::FOnlineLeaderboardPico(class FOnlineSubsystemPico& InSubsystem)
	: PicoSubsystem(InSubsystem)
{
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineLeaderboardPico::ReadLeaderboards(const TArray<FUniqueNetIdRef>& Players, FOnlineLeaderboardReadRef& ReadObject)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineLeaderboardPico::ReadLeaderboards(const TArray<FUniqueNetIdRef>& Players, FOnlineLeaderboardReadRef& ReadObject)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineLeaderboardPico::ReadLeaderboards(const TArray< TSharedRef<const FUniqueNetId> >& Players, FOnlineLeaderboardReadRef& ReadObject)
#endif
{
	bool bOnlyLoggedInUser = false;
	if (Players.Num() > 0)
	{
		auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
		if (Players.Num() == 1 && LoggedInPlayerId.IsValid() && *Players[0] == *LoggedInPlayerId)
		{
			bOnlyLoggedInUser = true;
		}
		else
		{
			SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("ReadLeaderboards Filtering by player ids other than the logged in player is not supported.  Ignoring the 'Players' parameter")));
		}
	}
	return ReadPicoLeaderboards(/* Only Friends */ false, bOnlyLoggedInUser, ReadObject);
};

bool FOnlineLeaderboardPico::ReadLeaderboardsForFriends(int32 LocalUserNum, FOnlineLeaderboardReadRef& ReadObject)
{
	return ReadPicoLeaderboards(/* Only Friends */ true, /* Only Logged In User */ false, ReadObject);
}

bool FOnlineLeaderboardPico::ReadLeaderboardsAroundRank(int32 Rank, uint32 Range, FOnlineLeaderboardReadRef& ReadObject)
{
	// todo
	return false;
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineLeaderboardPico::ReadLeaderboardsAroundUser(FUniqueNetIdRef Player, uint32 Range, FOnlineLeaderboardReadRef& ReadObject)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineLeaderboardPico::ReadLeaderboardsAroundUser(FUniqueNetIdRef Player, uint32 Range, FOnlineLeaderboardReadRef& ReadObject)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineLeaderboardPico::ReadLeaderboardsAroundUser(TSharedRef<const FUniqueNetId> Player, uint32 Range, FOnlineLeaderboardReadRef& ReadObject)
#endif
{
	// todo
	return false;
}

bool FOnlineLeaderboardPico::ReadPicoLeaderboards(bool bOnlyFriends, bool bOnlyLoggedInUser, FOnlineLeaderboardReadRef& ReadObject)
{
	int PageIndex = 0;
	int PageSize = 100;
	FString LeaderboardName;
	const bool UseUEObject = !ReadObject->LeaderboardName.IsNone();
	if (UseUEObject)
	{
		PageSize = MAX_REQUEST_SIZE;
		// PageIndex = ReadIndex;
		LeaderboardName = ReadObject->LeaderboardName.ToString();
		SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("ReadPicoLeaderboards native ptr: PageIndex: %d, PageSize: %d, LeaderboardName: %s")
			, PageSize, PageIndex
			, *LeaderboardName));
	}
	else
	{
		const TSharedRef<Pico_OnlineLeaderboardRead, ESPMode::ThreadSafe> PicoReadObject = StaticCastSharedRef<Pico_OnlineLeaderboardRead>(ReadObject);
		const TSharedPtr<Pico_OnlineLeaderboardRead, ESPMode::ThreadSafe> PicoReadObjectPtr = PicoReadObject;
		if (PicoReadObjectPtr.IsValid())
		{
			LeaderboardName = PicoReadObject->PicoLeaderboardName;
			PageIndex = PicoReadObject->PicoPageIndex;
			PageSize = PicoReadObject->PicoPageSize;
			SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("ReadPicoLeaderboards pico: PageIndex: %d, PageSize: %d, LeaderboardName: %s")
			, PageSize, PageIndex
			, *LeaderboardName));
		}
	}
	const ppfLeaderboardFilterType FilterType = (bOnlyFriends) ? ppfLeaderboard_FilterFriends : ppfLeaderboard_FilterNone;
	ppfLeaderboardStartAt StartAt = ppfLeaderboard_StartAtTop;
	// If only getting the logged in user, then only return back one result
	if (bOnlyLoggedInUser)
	{
		StartAt = ppfLeaderboard_StartAtCenteredOnViewer;
	}
	SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("ReadPicoLeaderboards PageSize: %d, PageIndex: %d, FilterType: %s, StartAt: %s, LeaderboardName: %s")
			, PageSize, PageIndex
			, *FString(FilterTypeNames[FilterType])
			, *FString(StartAtNames[StartAt])
			, *LeaderboardName));
	ReadObject->ReadState = EOnlineAsyncTaskState::InProgress;
	PicoSubsystem.AddAsyncTask(
		ppf_Leaderboard_GetEntries(TCHAR_TO_ANSI(*LeaderboardName), PageSize, PageIndex, FilterType, StartAt),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, ReadObject, bOnlyFriends, bOnlyLoggedInUser](ppfMessageHandle Message, bool bIsError)
		{
			OnReadLeaderboardsComplete(Message, bIsError, bOnlyFriends, bOnlyLoggedInUser, ReadObject);
		}));
	
	return true;
}

void FOnlineLeaderboardPico::OnReadLeaderboardsComplete(ppfMessageHandle Message, bool bIsError, bool bOnlyFriends, bool bOnlyLoggedInUser,
                                                        const FOnlineLeaderboardReadRef& ReadObject)
{
	const bool UseUEObject = !ReadObject->LeaderboardName.IsNone();
	if (bIsError)
	{
		// if (UseUEObject)
		// {
		// 	ReadIndex = 0;
		// }
		ReadObject->ReadState = EOnlineAsyncTaskState::Failed;
		auto Error = ppf_Message_GetError(Message);
		FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
		ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
		SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnReadLeaderboardsComplete ErrorMessage: %s"), *FString(ErrorMessage)));
		TriggerOnLeaderboardReadCompleteDelegates(false);
		return;
	}
	
	const ppfLeaderboardEntryArrayHandle LeaderboardArray = ppf_Message_GetLeaderboardEntryArray(Message);
	const auto LeaderboardArraySize = ppf_LeaderboardEntryArray_GetSize(LeaderboardArray);
	EOnlineKeyValuePairDataType::Type ScoreType = EOnlineKeyValuePairDataType::Int64;
	for (auto Metadata : ReadObject->ColumnMetadata)
	{
		if (Metadata.ColumnName == ReadObject->SortedColumn)
		{
			ScoreType = Metadata.DataType;
			break;
		}
	}
	IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
	SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete LeaderboardArraySize: %zu"), LeaderboardArraySize));
	for (size_t i = 0; i < LeaderboardArraySize; i++)
	{
		auto LeaderboardEntry = ppf_LeaderboardEntryArray_GetElement(LeaderboardArray, i);
		auto User = ppf_LeaderboardEntry_GetUser(LeaderboardEntry);
		auto UserID = ppf_User_GetID(User);
		FString NickName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(User));
		auto Rank = ppf_LeaderboardEntry_GetRank(LeaderboardEntry);
		auto Score = ppf_LeaderboardEntry_GetScore(LeaderboardEntry);
		
		auto Row = FOnlineStatsRow(NickName, MakeShareable(new FUniqueNetIdPico(UserID)));//FUniqueNetIdPico(NickName).AsShared());
		if (Row.PlayerId.IsValid())
		{
			SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete Row[PlayerID: %s, Rank: %d, Score: %lld]"), *Row.PlayerId->ToString(), Rank, Score));
		}
		else
		{
			SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete Row[PlayerID: invalid, Rank: %d, Score: %lld]"), Rank, Score));
		}
		Row.Rank = Rank;
		FVariantData ScoreData = [ScoreType, Score]
		{
			switch (ScoreType)
			{
			case EOnlineKeyValuePairDataType::Int32:
				// prevent overflowing by capping to the max rather than truncate to preserve
				// order of the score
				if (Score > INT32_MAX)
				{
					return FVariantData(INT32_MAX);
				}
				else if (Score < INT32_MIN)
				{
					return FVariantData(INT32_MIN);
				}
				else
				{
					return FVariantData(static_cast<int32>(Score));
				}
				break;
			case EOnlineKeyValuePairDataType::UInt32:
				// prevent overflowing by capping to the max rather than truncate to preserve
				// order of the score
				if (Score > UINT32_MAX)
				{
					return FVariantData(UINT32_MAX);
				}
				else if (Score < 0)
				{
					return FVariantData(static_cast<uint32>(0));
				}
				else
				{
					return FVariantData(static_cast<uint32>(Score));
				}
				break;
			default:
				return FVariantData(Score);
				break;
			}
		}();

		Row.Columns.Add(ReadObject->SortedColumn, MoveTemp(ScoreData));
		ReadObject->Rows.Add(Row);
	}

	// if (UseUEObject)
	// {
	// 	ReadIndex++;
	// 	const size_t TotalSize = ppf_LeaderboardEntryArray_GetTotalCount(LeaderboardArray);
	// 	SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete TotalSize: %zu"), TotalSize));
	// 	if (ReadIndex * MAX_REQUEST_SIZE >= TotalSize)
	// 	{
	// 		SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete ReadIndex * MAX_REQUEST_SIZE >= TotalSize")));
	// 		ReadIndex = 0;
	// 		ReadObject->ReadState = EOnlineAsyncTaskState::Done;
	// 		TriggerOnLeaderboardReadCompleteDelegates(true);
	// 	}
	// 	else
	// 	{
	// 		SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnReadLeaderboardsComplete ReadIndex: %d"), ReadIndex));
	// 		ReadPicoLeaderboards(bOnlyFriends, bOnlyLoggedInUser, ReadObject); // todo
	// 	}
	// }
	// else
	{
		ReadObject->ReadState = EOnlineAsyncTaskState::Done;
		TriggerOnLeaderboardReadCompleteDelegates(true);
	}
}

void FOnlineLeaderboardPico::FreeStats(FOnlineLeaderboardRead& ReadObject)
{
	// todo
}

bool FOnlineLeaderboardPico::WriteLeaderboards(const FName& SessionName, const FUniqueNetId& Player,
                                               FOnlineLeaderboardWrite& WriteObject)
{
	auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
	if (!(LoggedInPlayerId.IsValid() && Player == *LoggedInPlayerId))
	{
		SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards logged in player is invalid or input player is not the logged in player")));
		return false;
	}

	auto StatData = WriteObject.FindStatByName(WriteObject.RatedStat);
	if (StatData == nullptr)
	{
		SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards Could not find RatedStat: %s"), *WriteObject.RatedStat.ToString()));
		return false;
	}

	long long Score;
	switch (StatData->GetType())
	{
	case EOnlineKeyValuePairDataType::Int32:
		{
			int32 Value;
			StatData->GetValue(Value);
			Score = Value;
			break;
		}
	case EOnlineKeyValuePairDataType::UInt32:
		{
			uint32 Value;
			StatData->GetValue(Value);
			Score = Value;
			break;
		}
	case EOnlineKeyValuePairDataType::Int64:
		{
			int64 Value;
			StatData->GetValue(Value);
			Score = Value;
			break;
		}
	case EOnlineKeyValuePairDataType::UInt64:
	case EOnlineKeyValuePairDataType::Double:
	case EOnlineKeyValuePairDataType::Float:
	default:
		{
			SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards Invalid Stat type to save to the leaderboard: %s"), EOnlineKeyValuePairDataType::ToString(StatData->GetType())));
			return false;
		}
	}
	SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("WriteLeaderboards begin WriteEntry LeaderboardNames.Num(): %d"), WriteObject.LeaderboardNames.Num()));
	if (WriteObject.LeaderboardNames.Num() > 0)
	{
		for (const auto& LeaderboardName : WriteObject.LeaderboardNames)
		{
			SaveLog(ELogVerbosity::Type::Log, FString::Printf(
			TEXT("WriteLeaderboards WriteEntry LeaderboardName: %s, Score: %lld, UpdateMethod: %d, ForceUpdate: %s, WriteObject.RatedStat: %s")
						, *LeaderboardName.ToString()
						, Score
						, WriteObject.UpdateMethod
						, WriteObject.UpdateMethod == ELeaderboardUpdateMethod::Force ? TEXT("true") : TEXT("false")
						, *WriteObject.RatedStat.ToString()
			));
		
			PicoSubsystem.AddAsyncTask(
				ppf_Leaderboard_WriteEntry(
					TCHAR_TO_ANSI(*LeaderboardName.ToString()), Score, /* extra_data */ nullptr, 0,
					(WriteObject.UpdateMethod == ELeaderboardUpdateMethod::Force)),
				FPicoMessageOnCompleteDelegate::CreateLambda([this](ppfMessageHandle Message, bool bIsError)
				{
					if (bIsError)
					{
						auto Error = ppf_Message_GetError(Message);
                        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
						SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards ErrorMessage: %s"), *FString(ErrorMessage)));
					}
				}));
		}
	}
	else
	{
		SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("WriteLeaderboards try static_cast to Pico_OnlineLeaderboardWrite")));
		Pico_OnlineLeaderboardWrite* PicoWriteObject = static_cast<Pico_OnlineLeaderboardWrite*>(&WriteObject);
		if (PicoWriteObject == nullptr)
		{
			SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards try static_cast to Pico_OnlineLeaderboardWrite fail")));
			return false;
		}
		SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("WriteLeaderboards begin WriteEntry PicoLeaderboardNames.Num(): %d"), PicoWriteObject->PicoLeaderboardNames.Num()));
		for (const auto& LeaderboardName : PicoWriteObject->PicoLeaderboardNames)
		{
			SaveLog(ELogVerbosity::Type::Log, FString::Printf(
			TEXT("WriteLeaderboards WriteEntry LeaderboardName: %s, Score: %lld, UpdateMethod: %d, ForceUpdate: %s, PicoWriteObject->RatedStat: %s")
						, *LeaderboardName
						, Score
						, PicoWriteObject->UpdateMethod
						, PicoWriteObject->UpdateMethod == ELeaderboardUpdateMethod::Force ? TEXT("true") : TEXT("false")
						, *PicoWriteObject->RatedStat.ToString()
			));
		
			PicoSubsystem.AddAsyncTask(
				ppf_Leaderboard_WriteEntry(
					TCHAR_TO_ANSI(*LeaderboardName), Score, /* extra_data */ nullptr, 0,
					(PicoWriteObject->UpdateMethod == ELeaderboardUpdateMethod::Force)),
				FPicoMessageOnCompleteDelegate::CreateLambda([this](ppfMessageHandle Message, bool bIsError)
				{
					if (bIsError)
					{
						auto Error = ppf_Message_GetError(Message);
                        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
						SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("WriteLeaderboards ErrorMessage: %s"), *FString(ErrorMessage)));
					}
				}));
		}
	}
	return true;
};

bool FOnlineLeaderboardPico::FlushLeaderboards(const FName& SessionName)
{
	TriggerOnLeaderboardFlushCompleteDelegates(SessionName, true);
	return true;
};

bool FOnlineLeaderboardPico::WriteOnlinePlayerRatings(const FName& SessionName, int32 LeaderboardId,
                                                      const TArray<FOnlinePlayerScore>& PlayerScores)
{
	// Not supported
	return false;
};
void FOnlineLeaderboardPico::SaveLog(const ELogVerbosity::Type Verbosity, const FString& Log)
{
	switch (Verbosity)
	{
	case ELogVerbosity::Type::Error:
		UE_LOG_ONLINE_LEADERBOARD(Error, TEXT("PPF_GAME %s"), *Log);
		break;
	case ELogVerbosity::Type::Warning:
		UE_LOG_ONLINE_LEADERBOARD(Warning, TEXT("PPF_GAME %s"), *Log);
		break;
	default:
		UE_LOG_ONLINE_LEADERBOARD(Log, TEXT("PPF_GAME %s"), *Log);
		break;
	}
	
	//FString TextPath = FPaths::ProjectPersistentDownloadDir() + TEXT("Log-Leaderboard.txt");
	//FString WriteLog = FString::Printf(TEXT("%s\n"), *Log);
	//FFileHelper::SaveStringToFile(*WriteLog, *TextPath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}
