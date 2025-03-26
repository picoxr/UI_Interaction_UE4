// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "Pico_Leaderboards.h"
#include "Pico_User.h"

#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PicoLeaderboards);


// FPicoLeaderboardsInterface
FPicoLeaderboardsInterface::FPicoLeaderboardsInterface(FOnlineSubsystemPico& InSubsystem) :
	PicoSubsystem(InSubsystem)
{
	
}
FPicoLeaderboardsInterface::~FPicoLeaderboardsInterface()
{
	
}

// ppf_Leaderboard_Get
bool FPicoLeaderboardsInterface::Get(const FString& LeaderboardName, FGet InGetDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::Get"));
	ppfRequest RequestId = ppf_Leaderboard_Get(TCHAR_TO_UTF8(*LeaderboardName));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InGetDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("Get return failed:%s"), *ErrorMessage);
				this->GetDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InGetDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoLeaderboards, Log, TEXT("Get Successfully"));
				UPico_LeaderboardArray* Pico_LeaderboardArray = NewObject<UPico_LeaderboardArray>();
				Pico_LeaderboardArray->InitParams(ppf_Message_GetLeaderboardArray(Message));
				this->GetDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardArray);
				InGetDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardArray);
			}
		}));
	return true;
}

// ppf_Leaderboard_GetEntries
bool FPicoLeaderboardsInterface::GetEntries(const FString& LeaderboardName, int PageIdx, int PageSize, 
                                            ppfLeaderboardFilterType Filter, ppfLeaderboardStartAt StartAt,
                                            FGetEntries InGetEntriesDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::AddCount"));
	ppfRequest RequestId = ppf_Leaderboard_GetEntries(TCHAR_TO_UTF8(*LeaderboardName), PageSize, PageIdx, Filter, StartAt);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InGetEntriesDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntries return failed:%s"), *ErrorMessage);
				this->GetEntriesDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InGetEntriesDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntries Successfully"));
				UPico_LeaderboardEntryArray* Pico_LeaderboardEntryArray = NewObject<UPico_LeaderboardEntryArray>();
				Pico_LeaderboardEntryArray->InitParams(ppf_Message_GetLeaderboardEntryArray(Message));
				this->GetEntriesDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
				InGetEntriesDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
			}
		}));
	return true;
}

// ppf_Leaderboard_GetEntriesAfterRank
bool FPicoLeaderboardsInterface::GetEntriesAfterRank(const FString& LeaderboardName, int PageIdx, int PageSize, 
                                                     unsigned long long AfterRank,
                                                     FGetEntriesAfterRank InGetEntriesAfterRankDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::AddCount"));
	ppfRequest RequestId = ppf_Leaderboard_GetEntriesAfterRank(TCHAR_TO_UTF8(*LeaderboardName), PageSize, PageIdx, AfterRank);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InGetEntriesAfterRankDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesAfterRank return failed:%s"), *ErrorMessage);
				this->GetEntriesAfterRankDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InGetEntriesAfterRankDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesAfterRank Successfully"));
				UPico_LeaderboardEntryArray* Pico_LeaderboardEntryArray = NewObject<UPico_LeaderboardEntryArray>();
				Pico_LeaderboardEntryArray->InitParams(ppf_Message_GetLeaderboardEntryArray(Message));
				this->GetEntriesAfterRankDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
				InGetEntriesAfterRankDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
			}
		}));
	return true;
}

// ppf_Leaderboard_GetEntriesByIds
bool FPicoLeaderboardsInterface::GetEntriesByIds(const FString& LeaderboardName, int PageIdx, int PageSize, 
                                                 ppfLeaderboardStartAt StartAt, const TArray<FString>& UserIDsArray,
                                                 FGetEntriesByIds InGetEntriesByIdsDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::GetEntriesByIds"));
	int32 Length = UserIDsArray.Num();
	std::vector<std::string> StringArray;
	for (size_t i = 0; i < UserIDsArray.Num(); i++)
	{
		StringArray.push_back(std::string(TCHAR_TO_UTF8(*(UserIDsArray[i]))));
	}
	std::vector<const char*> UserIds;
	for (size_t i = 0; i < StringArray.size(); i++)
	{
		UserIds.push_back(StringArray[i].c_str());
	}
	
	ppfRequest RequestId = ppf_Leaderboard_GetEntriesByIds(TCHAR_TO_UTF8(*LeaderboardName), PageSize, PageIdx, StartAt, UserIds.data(), UserIDsArray.Num());
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InGetEntriesByIdsDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesByIds return failed:%s"), *ErrorMessage);
				this->GetEntriesByIdsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InGetEntriesByIdsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesByIds Successfully"));
				UPico_LeaderboardEntryArray* Pico_LeaderboardEntryArray = NewObject<UPico_LeaderboardEntryArray>();
				Pico_LeaderboardEntryArray->InitParams(ppf_Message_GetLeaderboardEntryArray(Message));
				this->GetEntriesByIdsDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
				InGetEntriesByIdsDelegate.ExecuteIfBound(false, FString(), Pico_LeaderboardEntryArray);
			}
		}));
	return true;
}

// ppf_Leaderboard_WriteEntry
bool FPicoLeaderboardsInterface::WriteEntry(const FString& LeaderboardName, const int64& Score,
                                            const FString& ExtraData, bool ForceUpdate,
                                            FWriteEntry InWriteEntryDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::WriteEntry"));
	const TCHAR* StrPtr = *ExtraData;
	FTCHARToUTF8 UTF8String(StrPtr);
	int32 Size = UTF8String.Length();
	TArray<uint8> UTF8Data;
	UTF8Data.SetNum(Size);
	memcpy(UTF8Data.GetData(), UTF8String.Get(), Size);
	
	ppfRequest RequestId = ppf_Leaderboard_WriteEntry(TCHAR_TO_UTF8(*LeaderboardName), Score, UTF8Data.GetData(), Size, ForceUpdate);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InWriteEntryDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntry return failed:%s"), *ErrorMessage);
				this->WriteEntryDelegate.ExecuteIfBound(true, ErrorMessage, false);
				InWriteEntryDelegate.ExecuteIfBound(true, ErrorMessage, false);
			}
			else
			{
                UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntry Successfully"));
                bool Result = ppf_LeaderboardUpdateStatus_GetDidUpdate(ppf_Message_GetLeaderboardUpdateStatus(Message));
                this->WriteEntryDelegate.ExecuteIfBound(false, FString(), Result);
                InWriteEntryDelegate.ExecuteIfBound(false, FString(), Result);
			}
		}));
	return true;
}

// ppf_Leaderboard_WriteEntryWithSupplementaryMetric
bool FPicoLeaderboardsInterface::WriteEntryWithSupplementaryMetric(const FString& LeaderboardName, const int64& Score,
                                                                   const int64& SupplementaryMetric,
                                                                   const FString& ExtraData, bool ForceUpdate,
                                                                   FWriteEntryWithSupplementaryMetric
                                                                   InWriteEntryWithSupplementaryMetricDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("FPicoLeaderboardsInterface::WriteEntryWithSupplementaryMetric"));
	const TCHAR* StrPtr = *ExtraData;
	FTCHARToUTF8 UTF8String(StrPtr);
	int32 Size = UTF8String.Length();
	TArray<uint8> UTF8Data;
	UTF8Data.SetNum(Size);
	memcpy(UTF8Data.GetData(), UTF8String.Get(), Size);
	
	ppfRequest RequestId = ppf_Leaderboard_WriteEntryWithSupplementaryMetric(TCHAR_TO_UTF8(*LeaderboardName), Score, SupplementaryMetric, UTF8Data.GetData(), Size, ForceUpdate);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InWriteEntryWithSupplementaryMetricDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
				UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntryWithSupplementaryMetric return failed:%s"), *ErrorMessage);
				this->WriteEntryWithSupplementaryMetricDelegate.ExecuteIfBound(true, ErrorMessage, false);
				InWriteEntryWithSupplementaryMetricDelegate.ExecuteIfBound(true, ErrorMessage, false);
			}
			else
			{
                UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntryWithSupplementaryMetric Successfully"));
                bool Result = ppf_LeaderboardUpdateStatus_GetDidUpdate(ppf_Message_GetLeaderboardUpdateStatus(Message));
                this->WriteEntryWithSupplementaryMetricDelegate.ExecuteIfBound(false, FString(), Result);
                InWriteEntryWithSupplementaryMetricDelegate.ExecuteIfBound(false, FString(), Result);
			}
		}));
	return true;
}


// UOnlinePicoLeaderboardsFunction
void UOnlinePicoLeaderboardsFunction::Get(UObject* WorldContextObject, const FString& LeaderboardName,
                                                 FGet InGetDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::Get"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		Subsystem->GetPicoLeaderboardsInterface()->Get(LeaderboardName, InGetDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("PicoAddCount Failed, PicoLeaderboardsInterface Not Vailed!"));
		InGetDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoLeaderboardsFunction::GetEntries(UObject* WorldContextObject, const FString& LeaderboardName,
                                                        int PageIdx, int PageSize, ELeaderboardFilterType Filter,
                                                        ELeaderboardStartAt StartAt, FGetEntries InGetEntriesDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::PicoAddCount"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		Subsystem->GetPicoLeaderboardsInterface()->GetEntries(LeaderboardName, PageIdx, PageSize, (ppfLeaderboardFilterType)Filter, (ppfLeaderboardStartAt)StartAt, InGetEntriesDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("PicoAddCount Failed, PicoLeaderboardsInterface Not Vailed!"));
		InGetEntriesDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoLeaderboardsFunction::GetEntriesAfterRank(UObject* WorldContextObject,
                                                                 const FString& LeaderboardName, int PageIdx, int PageSize, const FString& AfterRank,
                                                                 FGetEntriesAfterRank InGetEntriesAfterRankDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::GetEntriesAfterRank"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		uint64 afterRank = FCString::Strtoi64(*AfterRank, NULL, 10);
		Subsystem->GetPicoLeaderboardsInterface()->GetEntriesAfterRank(LeaderboardName, PageIdx, PageSize, afterRank, InGetEntriesAfterRankDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesAfterRank Failed, PicoLeaderboardsInterface Not Vailed!"));
		InGetEntriesAfterRankDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoLeaderboardsFunction::GetEntriesByIds(
	UObject* WorldContextObject,
	const FString& LeaderboardName,
	int PageIdx, int PageSize, 
	ELeaderboardStartAt StartAt,
	const TArray<FString>& UserIDs,
	FGetEntriesByIds InGetEntriesByIdsDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::GetEntriesByIds"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		Subsystem->GetPicoLeaderboardsInterface()->GetEntriesByIds(LeaderboardName, PageIdx, PageSize, (ppfLeaderboardStartAt)StartAt, UserIDs, InGetEntriesByIdsDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("GetEntriesByIds Failed, PicoLeaderboardsInterface Not Vailed!"));
		InGetEntriesByIdsDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoLeaderboardsFunction::WriteEntry(
	UObject* WorldContextObject,
	const FString& LeaderboardName,
	const FString& Score,
	const FString& ExtraData,
	bool ForceUpdate,
	FWriteEntry InWriteEntryDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::WriteEntry"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		int64 score = FCString::Strtoi64(*Score, NULL, 10);
		Subsystem->GetPicoLeaderboardsInterface()->WriteEntry(LeaderboardName, score, ExtraData, ForceUpdate, InWriteEntryDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntry Failed, PicoLeaderboardsInterface Not Vailed!"));
		InWriteEntryDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), false);
	}
}

void UOnlinePicoLeaderboardsFunction::WriteEntryWithSupplementaryMetric(
	UObject* WorldContextObject,
	const FString& LeaderboardName,
	const FString& Score,
	const FString& SupplementaryMetric,
	const FString& ExtraData,
	bool ForceUpdate,
	FWriteEntryWithSupplementaryMetric InWriteEntryWithSupplementaryMetricDelegate)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UOnlinePicoLeaderboardsFunction::WriteEntryWithSupplementaryMetric"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoLeaderboardsInterface())
	{
		int64 score = FCString::Strtoi64(*Score, NULL, 10);
		int64 supplementaryMetric = FCString::Strtoi64(*SupplementaryMetric, NULL, 10);
		Subsystem->GetPicoLeaderboardsInterface()->WriteEntryWithSupplementaryMetric(LeaderboardName, score, supplementaryMetric, ExtraData, ForceUpdate, InWriteEntryWithSupplementaryMetricDelegate);
	}
	else
	{
		UE_LOG(PicoLeaderboards, Log, TEXT("WriteEntryWithSupplementaryMetric Failed, PicoLeaderboardsInterface Not Vailed!"));
		InWriteEntryWithSupplementaryMetricDelegate.ExecuteIfBound(true, FString(TEXT("PicoLeaderboardsInterface Not Vailed")), false);
	}
}


// UPico_LeaderboardEntry
void UPico_LeaderboardEntry::InitParams(ppfLeaderboardEntryHandle ppfLeaderboardEntryHandle)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardEntry::InitParams"));
	DisplayScore = UTF8_TO_TCHAR(ppf_LeaderboardEntry_GetDisplayScore(ppfLeaderboardEntryHandle));
	ID = ppf_LeaderboardEntry_GetID(ppfLeaderboardEntryHandle);
	Rank = ppf_LeaderboardEntry_GetRank(ppfLeaderboardEntryHandle);
	Score = ppf_LeaderboardEntry_GetScore(ppfLeaderboardEntryHandle);
	Timestamp = ppf_LeaderboardEntry_GetTimestamp(ppfLeaderboardEntryHandle);
	if (User == nullptr)
	{
		User = NewObject<UPico_User>(this);
	}
	User->InitParams(ppf_LeaderboardEntry_GetUser(ppfLeaderboardEntryHandle));
	// ExtraData
	int size = ppf_LeaderboardEntry_GetExtraDataLength(ppfLeaderboardEntryHandle);
	auto extraData = (uint8*)ppf_LeaderboardEntry_GetExtraData(ppfLeaderboardEntryHandle);
	for (int i = 0; i < size; i++)
	{
		ExtraData.Add(*(extraData + i));
	}
	ppfSupplementaryMetricHandle SupplementaryMetricHandle = ppf_LeaderboardEntry_GetSupplementaryMetric(ppfLeaderboardEntryHandle);
	if (SupplementaryMetricHandle != nullptr)
	{
		SupplementaryMetricOptional.ID = FString::Printf(TEXT("%llu"), ppf_SupplementaryMetric_GetID(SupplementaryMetricHandle));
		SupplementaryMetricOptional.Metric = FString::Printf(TEXT("%lld"), ppf_SupplementaryMetric_GetMetric(SupplementaryMetricHandle));
	}
}

FString UPico_LeaderboardEntry::GetID()
{
	return FString::Printf(TEXT("%llu"), ID);
}

FString UPico_LeaderboardEntry::GetDisplayScore()
{
	return DisplayScore;
}

int32 UPico_LeaderboardEntry::GetRank()
{
	return Rank;
}

int64 UPico_LeaderboardEntry::GetScore()
{
	return Score;
}

FPicoSupplementaryMetric UPico_LeaderboardEntry::GetSupplementaryMetricOptional()
{
	return SupplementaryMetricOptional;
}

FString UPico_LeaderboardEntry::GetTimestamp()
{
	return FString::Printf(TEXT("%llu"), Timestamp);
}

FDateTime UPico_LeaderboardEntry::GetTimestampDateTime()
{
	FDateTime Time = FDateTime::FromUnixTimestamp(Timestamp);
	return Time;
}

UPico_User* UPico_LeaderboardEntry::GetUser()
{
	return User;
}

FString UPico_LeaderboardEntry::GetExtraDataString()
{
	const std::string cstr(reinterpret_cast<const char*>(ExtraData.GetData()), ExtraData.Num());  
	FString ExtraDataString = UTF8_TO_TCHAR(cstr.c_str());
	return ExtraDataString;
}




// UPico_Leaderboard
void UPico_Leaderboard::InitParams(ppfLeaderboard* ppfLeaderboardHandle)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_Leaderboard::InitParams"));
	ApiName = UTF8_TO_TCHAR(ppf_Leaderboard_GetApiName(ppfLeaderboardHandle));
	ID = ppf_Leaderboard_GetID(ppfLeaderboardHandle);
	ppfDestinationHandle DestinationHandle = ppf_Leaderboard_GetDestination(ppfLeaderboardHandle);
	if (DestinationHandle != nullptr)
	{
		DestinationOptional.ApiName = UTF8_TO_TCHAR(ppf_Destination_GetApiName(DestinationHandle));
		DestinationOptional.DeepLinkMessage = UTF8_TO_TCHAR(ppf_Destination_GetDeeplinkMessage(DestinationHandle));
		DestinationOptional.DisplayName = UTF8_TO_TCHAR(ppf_Destination_GetDisplayName(DestinationHandle));
	}
}

FString UPico_Leaderboard::GetApiName()
{
	return ApiName;
}

FString UPico_Leaderboard::GetID()
{
	return FString::Printf(TEXT("%llu"), ID);
}

FPicoDestination UPico_Leaderboard::GetDestinationOptional()
{
	return DestinationOptional;
}





// UPico_LeaderboardEntryArray
void UPico_LeaderboardEntryArray::InitParams(ppfLeaderboardEntryArrayHandle InppfLeaderboardEntryArrayHandle)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardEntryArray::InitParams"));
	Size = ppf_LeaderboardEntryArray_GetSize(InppfLeaderboardEntryArrayHandle);
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardEntryArray::InitParams ppf_LeaderboardEntryArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_LeaderboardEntry* ThisElement = NewObject<UPico_LeaderboardEntry>(this);
		ThisElement->InitParams(ppf_LeaderboardEntryArray_GetElement(InppfLeaderboardEntryArrayHandle, i));
		LeaderboardEntryArray.Add(ThisElement);
	}
	bHasNextPage = ppf_LeaderboardEntryArray_HasNextPage(InppfLeaderboardEntryArrayHandle);
	bHasPreviousPage = ppf_LeaderboardEntryArray_HasPreviousPage(InppfLeaderboardEntryArrayHandle);
	TotalSize = ppf_LeaderboardEntryArray_GetTotalCount(InppfLeaderboardEntryArrayHandle);
}

UPico_LeaderboardEntry* UPico_LeaderboardEntryArray::GetElement(int32 Index)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardEntryArray::GetElement Index: %d"), Index);
	if (LeaderboardEntryArray.IsValidIndex(Index))
	{
		return LeaderboardEntryArray[Index];
	}
	return nullptr;
}

int32 UPico_LeaderboardEntryArray::GetSize()
{
	return Size;
}

int32 UPico_LeaderboardEntryArray::GetTotalSize()
{
	return TotalSize;
}

bool UPico_LeaderboardEntryArray::HasNextPage()
{
	return bHasNextPage;
}

bool UPico_LeaderboardEntryArray::HasPreviousPage()
{
	return bHasPreviousPage;
}

FString UPico_LeaderboardEntryArray::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("LeaderboardEntryArray DebugString:\nTotalSize: %d\nSize: %d\nbHasNextPage: %s\nbHasPreviousPage: %s\n"), GetTotalSize(), GetSize(), bHasNextPage?TEXT("true"):TEXT("false")
		, bHasPreviousPage?TEXT("true"):TEXT("false")));
	
	return Log;
}






// UPico_LeaderboardArray
void UPico_LeaderboardArray::InitParams(ppfLeaderboardArrayHandle InppfLeaderboardArrayHandle)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardArray::InitParams"));
	Size = ppf_LeaderboardArray_GetSize(InppfLeaderboardArrayHandle);
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardArray::InitParams ppf_LeaderboardArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_Leaderboard* ThisElement = NewObject<UPico_Leaderboard>(this);
		ThisElement->InitParams(ppf_LeaderboardArray_GetElement(InppfLeaderboardArrayHandle, i));
		LeaderboardArray.Add(ThisElement);
	}
	bHasNextPage = ppf_LeaderboardArray_HasNextPage(InppfLeaderboardArrayHandle);
	TotalSize = ppf_LeaderboardArray_GetTotalCount(InppfLeaderboardArrayHandle);
}

UPico_Leaderboard* UPico_LeaderboardArray::GetElement(int32 Index)
{
	UE_LOG(PicoLeaderboards, Log, TEXT("UPico_LeaderboardArray::GetElement Index: %d"), Index);
	if (LeaderboardArray.IsValidIndex(Index))
	{
		return LeaderboardArray[Index];
	}
	return nullptr;
}

int32 UPico_LeaderboardArray::GetSize()
{
	return Size;
}

int32 UPico_LeaderboardArray::GetTotalSize()
{
	return TotalSize;
}

bool UPico_LeaderboardArray::HasNextPage()
{
	return bHasNextPage;
}

FString UPico_LeaderboardArray::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("LeaderboardArray DebugString:\nTotalSize: %d\nSize: %d\nbHasNextPage: %s\n"), GetTotalSize(), GetSize(), bHasNextPage?TEXT("true"):TEXT("false")));
	
	return Log;
}