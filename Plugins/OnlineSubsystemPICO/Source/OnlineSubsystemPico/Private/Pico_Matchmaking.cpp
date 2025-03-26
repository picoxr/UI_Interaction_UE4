// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_Matchmaking.h"
#include "OnlineSubsystemUtils.h"
#include "Pico_Room.h"
// #include "Pico_User.h"
// #include "Pico_DataStore.h"


DEFINE_LOG_CATEGORY(PicoMatchmaking);

// FPicoMatchmakingInterface
FPicoMatchmakingInterface::FPicoMatchmakingInterface(FOnlineSubsystemPico& InSubsystem) :
	PicoSubsystem(InSubsystem)
{
	MatchmakingCancelHandle =
				PicoSubsystem.GetOrAddNotify(ppfMessageType_Matchmaking_Cancel2)
				.AddRaw(this, &FPicoMatchmakingInterface::OnMatchmakingCancelNotification);

	MatchmakingMatchFoundHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Matchmaking_MatchFound)
		.AddRaw(this, &FPicoMatchmakingInterface::OnMatchmakingMatchFoundNotification);
}
FPicoMatchmakingInterface::~FPicoMatchmakingInterface()
{
	if (MatchmakingCancelHandle.IsValid())
	{
		MatchmakingCancelHandle.Reset();
	}
	if (MatchmakingMatchFoundHandle.IsValid())
	{
		MatchmakingMatchFoundHandle.Reset();
	}
}

void FPicoMatchmakingInterface::OnMatchmakingMatchFoundNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::OnMatchmakingMatchFoundNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoMatchmaking, Error, TEXT("MatchmakingMatchFoundNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		MatchmakingMatchFoundNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, nullptr);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("MatchmakingMatchFoundNotification success!"));
		UPico_Room* Room = NewObject<UPico_Room>();
		Room->InitParams(ppf_Message_GetRoom(Message));
		MatchmakingMatchFoundNotify.Broadcast(bIsError, 0, FString(), Room);
	}
}
void FPicoMatchmakingInterface::OnMatchmakingCancelNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::OnMatchmakingCancelNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoMatchmaking, Error, TEXT("MatchmakingCancelNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		MatchmakingCancelNotify.Broadcast(bIsError, ErrorCode, ErrorMessage);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("MatchmakingCancelNotification success!"));
		MatchmakingCancelNotify.Broadcast(bIsError, 0, FString());
	}
}

bool FPicoMatchmakingInterface::ReportResultsInsecure(const FString& RoomID, const TMap<FString, int>& Data, FMatchmakingReportResultsInsecure InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::ReportResultsInsecure"));
	ppfKeyValuePairArray KeyValuePairArray = ppf_KeyValuePairArray_Create(Data.Num());
	unsigned int n = 0;
	for (auto Iter = Data.CreateConstIterator(); Iter;++ Iter)
	{
		ppfKeyValuePairHandle item = ppf_KeyValuePairArray_GetElement(KeyValuePairArray, n);
		UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::ReportResultsInsecure key: %s, value: %d"), *Iter.Key(), Iter.Value());
		ppf_KeyValuePair_SetKey(item, TCHAR_TO_UTF8(*Iter.Key()));
		ppf_KeyValuePair_SetIntValue(item, Iter.Value());
		n++;
	}
	
	ppfRequest RequestId = ppf_Matchmaking_ReportResultInsecure(GetppfID(RoomID), KeyValuePairArray, n);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("ReportResultsInsecure return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->ReportResultsInsecureDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("ReportResultsInsecure Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->ReportResultsInsecureDelegate.ExecuteIfBound(false, 0, FString());
				InDelegate.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::GetStats(const FString& Pool, uint32 MaxLevel, EMatchmakingStatApproach Approach, FMatchmakingGetStats InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::GetStats"));
	
	ppfRequest RequestId = ppf_Matchmaking_GetStats(TCHAR_TO_UTF8(*Pool), MaxLevel, GetppfMatchmakingStatApproach(Approach));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("GetStats return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetStatsDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("GetStats Successfully"));
				UPico_MatchmakingStats* Pico_MatchmakingStats = NewObject<UPico_MatchmakingStats>();
				Pico_MatchmakingStats->InitParams(ppf_Message_GetMatchmakingStats(Message));
				this->GetStatsDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingStats);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingStats);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::Browse2(const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingBrowse2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::Browse2"));
	
	ppfRequest RequestId = ppf_Matchmaking_Browse2(TCHAR_TO_UTF8(*Pool), GetppfMatchmakingOptions(MatchmakingOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("Browse2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->Browse2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("Browse2 Successfully"));
				UPico_MatchmakingBrowseResult* Pico_MatchmakingBrowseResult = NewObject<UPico_MatchmakingBrowseResult>();
				Pico_MatchmakingBrowseResult->InitParams(ppf_Message_GetMatchmakingBrowseResult(Message));
				this->Browse2Delegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingBrowseResult);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingBrowseResult);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::Browse2CustomPage(const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, int PageIndex, int PageSize, FMatchmakingBrowse2CustomPage InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::Browse2CustomPage"));
	ppfRequest RequestId = ppf_Matchmaking_Browse2CustomPage(TCHAR_TO_UTF8(*Pool), GetppfMatchmakingOptions(MatchmakingOptions), PageIndex, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("Browse2CustomPage return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->Browse2CustomPageDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("Browse2CustomPage Successfully"));
				UPico_MatchmakingBrowseResult* Pico_MatchmakingBrowseResult = NewObject<UPico_MatchmakingBrowseResult>();
				Pico_MatchmakingBrowseResult->InitParams(ppf_Message_GetMatchmakingBrowseCustomPageResult(Message));
				this->Browse2CustomPageDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingBrowseResult);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingBrowseResult);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::Cancel(FMatchmakingCancel InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::Cancel"));
	
	ppfRequest RequestId = ppf_Matchmaking_Cancel2();
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("Cancel return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->CancelDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("Cancel Successfully"));
				this->CancelDelegate.ExecuteIfBound(false, 0, FString());
				InDelegate.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::CreateAndEnqueueRoom2(const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingCreateAndEnqueueRoom2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::CreateAndEnqueueRoom2"));
	
	ppfRequest RequestId = ppf_Matchmaking_CreateAndEnqueueRoom2(TCHAR_TO_UTF8(*Pool), GetppfMatchmakingOptions(MatchmakingOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("CreateAndEnqueueRoom2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->CreateAndEnqueueRoom2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("CreateAndEnqueueRoom2 Successfully"));
				UPico_MatchmakingEnqueueResultAndRoom* Pico_MatchmakingEnqueueResultAndRoom = NewObject<UPico_MatchmakingEnqueueResultAndRoom>();
				Pico_MatchmakingEnqueueResultAndRoom->InitParams(ppf_Message_GetMatchmakingEnqueueResultAndRoom(Message));
				this->CreateAndEnqueueRoom2Delegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingEnqueueResultAndRoom);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingEnqueueResultAndRoom);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::Enqueue2(const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingEnqueue2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::Enqueue2"));
	
	ppfRequest RequestId = ppf_Matchmaking_Enqueue2(TCHAR_TO_UTF8(*Pool), GetppfMatchmakingOptions(MatchmakingOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("Enqueue2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->Enqueue2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("Enqueue2 Successfully"));
				UPico_MatchmakingEnqueueResult* Pico_MatchmakingEnqueueResult = NewObject<UPico_MatchmakingEnqueueResult>();
				Pico_MatchmakingEnqueueResult->InitParams(ppf_Message_GetMatchmakingEnqueueResult(Message));
				this->Enqueue2Delegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingEnqueueResult);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingEnqueueResult);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::GetAdminSnapshot(FMatchmakingGetAdminSnapshot InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::GetAdminSnapshot"));
	
	ppfRequest RequestId = ppf_Matchmaking_GetAdminSnapshot();
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("GetAdminSnapshot return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetAdminSnapshotDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("GetAdminSnapshot Successfully"));
				UPico_MatchmakingAdminSnapshot* Pico_MatchmakingAdminSnapshot = NewObject<UPico_MatchmakingAdminSnapshot>();
				Pico_MatchmakingAdminSnapshot->InitParams(ppf_Message_GetMatchmakingAdminSnapshot(Message));
				this->GetAdminSnapshotDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingAdminSnapshot);
				InDelegate.ExecuteIfBound(false, 0, FString(), Pico_MatchmakingAdminSnapshot);
			}
		}));
	return true;
}
bool FPicoMatchmakingInterface::StartMatch(const FString& RoomID, FMatchmakingStartMatch InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("FPicoMatchmakingInterface::StartMatch"));
	
	ppfRequest RequestId = ppf_Matchmaking_StartMatch(GetppfID(RoomID));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoMatchmaking, Log, TEXT("StartMatch return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->StartMatchDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoMatchmaking, Log, TEXT("StartMatch Successfully"));
				this->StartMatchDelegate.ExecuteIfBound(false, 0, FString());
				InDelegate.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}
ppfMatchmakingOptions* FPicoMatchmakingInterface::GetppfMatchmakingOptions(FPicoMatchmakingOptions PicoMatchmakingOptions)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("GetppfMatchmakingOptions begin"));
	ppfMatchmakingOptions* ppfMatchmakingOptionsHandle = ppf_MatchmakingOptions_Create();

	ppf_MatchmakingOptions_SetCreateRoomDataStoreString(ppfMatchmakingOptionsHandle, TCHAR_TO_ANSI(*PicoMatchmakingOptions.DataStoreKey), TCHAR_TO_ANSI(*PicoMatchmakingOptions.DataStoreValue));
	ppf_MatchmakingOptions_SetCreateRoomMaxUsers(ppfMatchmakingOptionsHandle, PicoMatchmakingOptions.RoomMaxUsers);
	ppf_MatchmakingOptions_SetEnqueueIsDebug(ppfMatchmakingOptionsHandle, PicoMatchmakingOptions.bEnqueueIsDebug);
	ppf_MatchmakingOptions_SetEnqueueQueryKey(ppfMatchmakingOptionsHandle, TCHAR_TO_UTF8(*PicoMatchmakingOptions.EnqueueQueryKey));

	for (auto It = PicoMatchmakingOptions.EnqueueDataSettingsInt.CreateConstIterator(); It; ++It)
	{
		ppf_MatchmakingOptions_SetEnqueueDataSettingsInt(ppfMatchmakingOptionsHandle, TCHAR_TO_UTF8(*It.Key()), It.Value());
	}
	for (auto It = PicoMatchmakingOptions.EnqueueDataSettingsFloat.CreateConstIterator(); It; ++It)
	{
		ppf_MatchmakingOptions_SetEnqueueDataSettingsDouble(ppfMatchmakingOptionsHandle, TCHAR_TO_UTF8(*It.Key()), It.Value());
	}
	for (auto It = PicoMatchmakingOptions.EnqueueDataSettingsString.CreateConstIterator(); It; ++It)
	{
		ppf_MatchmakingOptions_SetEnqueueDataSettingsString(ppfMatchmakingOptionsHandle, TCHAR_TO_UTF8(*It.Key()), TCHAR_TO_UTF8(*It.Value()));
	}

	switch (PicoMatchmakingOptions.RoomJoinPolicy)
	{
	case ERoomJoinPolicy::JoinPolicyEveryone:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyEveryone);
		break;
	case ERoomJoinPolicy::JoinPolicyNone:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyNone);
		break;
	case ERoomJoinPolicy::JoinPolicyUnknown:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyUnknown);
		break;
	case ERoomJoinPolicy::JoinPolicyInvitedUsers:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyInvitedUsers);
		break;
	case ERoomJoinPolicy::JoinPolicyFriendsOfMembers:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyFriendsOfMembers);
		break;
	case ERoomJoinPolicy::JoinPolicyFriendsOfOwner:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyFriendsOfOwner);
		break;
	default:
		ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(ppfMatchmakingOptionsHandle, ppfRoom_JoinPolicyUnknown);
		break;
	}
	return ppfMatchmakingOptionsHandle;
}
ppfMatchmakingStatApproach FPicoMatchmakingInterface::GetppfMatchmakingStatApproach(EMatchmakingStatApproach MatchmakingStatApproach)
{
	switch (MatchmakingStatApproach)
	{
	case EMatchmakingStatApproach::Swingy:
		return ppfMatchmakingStatApproach_Swingy;
	case EMatchmakingStatApproach::Trailing:
		return ppfMatchmakingStatApproach_Trailing;
	case EMatchmakingStatApproach::Unknown:
		return ppfMatchmakingStatApproach_Unknown;
	
	default:
		return ppfMatchmakingStatApproach_Unknown;
	}
}
ppfID FPicoMatchmakingInterface::GetppfID(const FString& StringID)
{
	return FCString::Strtoui64(*StringID, NULL, 10);
}




// UOnlinePicoMatchmakingFunction
void UOnlinePicoMatchmakingFunction::ReportResultsInsecure(UObject* WorldContextObject, const FString& RoomID, const TMap<FString, int>& Data, FMatchmakingReportResultsInsecure InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::ReportResultsInsecure"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->ReportResultsInsecure(RoomID, Data, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("ReportResultsInsecure Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")));
	}
}
void UOnlinePicoMatchmakingFunction::GetStats(UObject* WorldContextObject, const FString& Pool, int32 MaxLevel, EMatchmakingStatApproach Approach, FMatchmakingGetStats InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::GetStats"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->GetStats(Pool, MaxLevel, Approach, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("GetStats Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::Browse2(UObject* WorldContextObject, const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingBrowse2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::Browse2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->Browse2(Pool, MatchmakingOptions, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("Browse2 Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::Browse2CustomPage(UObject* WorldContextObject, const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, int PageIndex, int PageSize, FMatchmakingBrowse2CustomPage InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::Browse2CustomPage"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->Browse2CustomPage(Pool, MatchmakingOptions, PageIndex, PageSize, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("Browse2CustomPage Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::Cancel(UObject* WorldContextObject, FMatchmakingCancel InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::Cancel"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->Cancel(InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("Cancel Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")));
	}
}
void UOnlinePicoMatchmakingFunction::CreateAndEnqueueRoom2(UObject* WorldContextObject, const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingCreateAndEnqueueRoom2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::CreateAndEnqueueRoom2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->CreateAndEnqueueRoom2(Pool, MatchmakingOptions, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("CreateAndEnqueueRoom2 Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::Enqueue2(UObject* WorldContextObject, const FString& Pool, FPicoMatchmakingOptions MatchmakingOptions, FMatchmakingEnqueue2 InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::Enqueue2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->Enqueue2(Pool, MatchmakingOptions, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("Enqueue2 Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::GetAdminSnapshot(UObject* WorldContextObject, FMatchmakingGetAdminSnapshot InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::GetAdminSnapshot"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->GetAdminSnapshot(InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("GetAdminSnapshot Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoMatchmakingFunction::StartMatch(UObject* WorldContextObject, const FString& RoomID, FMatchmakingStartMatch InDelegate)
{
	UE_LOG(PicoMatchmaking, Log, TEXT("UOnlinePicoMatchmakingFunction::StartMatch"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoMatchmakingInterface())
	{
		Subsystem->GetPicoMatchmakingInterface()->StartMatch(RoomID, InDelegate);
	}
	else
	{
		UE_LOG(PicoMatchmaking, Log, TEXT("StartMatch Failed, PicoMatchmakingInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoMatchmakingInterface Not Vailed")));
	}
}


void UPico_MatchmakingStats::InitParams(ppfMatchmakingStatsHandle InHandle)
{
	DrawCount = ppf_MatchmakingStats_GetDrawCount(InHandle);
	LossCount = ppf_MatchmakingStats_GetLossCount(InHandle);
	SkillLevel = ppf_MatchmakingStats_GetSkillLevel(InHandle);
	SkillMean = ppf_MatchmakingStats_GetSkillMean(InHandle);
	SkillStandardDeviation = ppf_MatchmakingStats_GetSkillStandardDeviation(InHandle);
	WinCount = ppf_MatchmakingStats_GetWinCount(InHandle);
}
int32 UPico_MatchmakingStats::GetDrawCount()
{
	return DrawCount;
}

int32 UPico_MatchmakingStats::GetLossCount()
{
	return LossCount;
}

int32 UPico_MatchmakingStats::GetSkillLevel()
{
	return SkillLevel;
}

float UPico_MatchmakingStats::GetSkillMean()
{
	return SkillMean;
}

float UPico_MatchmakingStats::GetSkillStandardDeviation()
{
	return SkillStandardDeviation;
}

int32 UPico_MatchmakingStats::GetWinCount()
{
	return WinCount;
}
FString UPico_MatchmakingStats::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingStats DebugString:\nDrawCount: %d\nLossCount: %d\nSkillLevel: %d\nSkillMean: %f\nSkillStandardDeviation: %f\nWinCount: %d\n")
		, GetDrawCount(), GetLossCount(), GetSkillLevel(), GetSkillMean(), GetSkillStandardDeviation(), GetWinCount()));
	
	return Log;
}




void UPico_MatchmakingBrowseResult::InitParams(ppfMatchmakingBrowseResultHandle InHandle)
{
	EnqueueResult = NewObject<UPico_MatchmakingEnqueueResult>(this);
	EnqueueResult->InitParams(ppf_MatchmakingBrowseResult_GetEnqueueResult(InHandle));
	MatchmakingRooms = NewObject<UPico_MatchmakingRoomList>(this);
	MatchmakingRooms->InitParams(ppf_MatchmakingBrowseResult_GetRooms(InHandle));
}
UPico_MatchmakingEnqueueResult* UPico_MatchmakingBrowseResult::GetMatchmakingEnqueueResult()
{
	return EnqueueResult;
}
UPico_MatchmakingRoomList* UPico_MatchmakingBrowseResult::GetMatchmakingRooms()
{
	return MatchmakingRooms;
}
FString UPico_MatchmakingBrowseResult::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingBrowseResult DebugString:\nMatchmakingEnqueueResult:\n%s\nMatchmakingRooms:\n%s\n")
		, *GetMatchmakingEnqueueResult()->GetDebugString(), *GetMatchmakingRooms()->GetDebugString()));
	
	return Log;
}








void UPico_MatchmakingRoomList::InitParams(ppfMatchmakingRoomArrayHandle InHandle)
{
	UE_LOG(PicoRoom, Log, TEXT("UPico_MatchmakingRoomList::InitParams"));
	Size = ppf_MatchmakingRoomArray_GetSize(InHandle);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_MatchmakingRoom* ThisElement = NewObject<UPico_MatchmakingRoom>(this);
		ThisElement->InitParams(ppf_MatchmakingRoomArray_GetElement(InHandle, i));
		MatchmakingRoomArray.Add(ThisElement);
	}
	TotalSize = ppf_MatchmakingRoomArray_GetTotalCount(InHandle);
}
UPico_MatchmakingRoom* UPico_MatchmakingRoomList::GetElement(int32 Index)
{
	if (MatchmakingRoomArray.IsValidIndex(Index))
	{
		return MatchmakingRoomArray[Index];
	}
	return nullptr; 
}
int32 UPico_MatchmakingRoomList::GetSize()
{
	return Size;
}
int32 UPico_MatchmakingRoomList::GetTotalSize()
{
	return TotalSize;
}
FString UPico_MatchmakingRoomList::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingRoomList DebugString:\nSize: %d\nTotalSize: %d\n"), GetSize(), GetTotalSize()));
	for (int32 i = 0; i < Size; i++)
	{
		Log.Append(FString::Printf(TEXT("%d:\n%s\n"), i, *MatchmakingRoomArray[i]->GetDebugString()));
	}
	
	return Log;
}










void UPico_MatchmakingRoom::InitParams(ppfMatchmakingRoomHandle InHandle)
{
	PingTime = ppf_MatchmakingRoom_GetPingTime(InHandle);
	Room = NewObject<UPico_Room>(this);
	Room->InitParams(ppf_MatchmakingRoom_GetRoom(InHandle));
	HasPingTime = ppf_MatchmakingRoom_HasPingTime(InHandle);
}
UPico_Room* UPico_MatchmakingRoom::GetRoom()
{
	return Room;
}
int32 UPico_MatchmakingRoom::GetPingTime()
{
	return PingTime;
}
bool UPico_MatchmakingRoom::GetHasPingTime()
{
	return HasPingTime;
}
FString UPico_MatchmakingRoom::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingRoom DebugString:\nHasPingTime: %s\nPingTime: %d\nRoom:\n%s\n")
		, GetHasPingTime()?TEXT("true"):TEXT("false"), GetPingTime(), *GetRoom()->GetDebugString()));
	
	return Log;
}




void UPico_MatchmakingEnqueueResultAndRoom::InitParams(ppfMatchmakingEnqueueResultAndRoomHandle InHandle)
{
	MatchmakingEnqueueResult = NewObject<UPico_MatchmakingEnqueueResult>(this);
	MatchmakingEnqueueResult->InitParams(ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(InHandle));
	Room = NewObject<UPico_Room>(this);
	Room->InitParams(ppf_MatchmakingEnqueueResultAndRoom_GetRoom(InHandle));
}
UPico_MatchmakingEnqueueResult* UPico_MatchmakingEnqueueResultAndRoom::GetMatchmakingEnqueueResult()
{
	return MatchmakingEnqueueResult;
}
UPico_Room* UPico_MatchmakingEnqueueResultAndRoom::GetRoom()
{
	return Room;
}
FString UPico_MatchmakingEnqueueResultAndRoom::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingEnqueueResultAndRoom DebugString:\nRoom:\n%s\nMatchmakingEnqueueResult:\n%s\n"), *GetRoom()->GetDebugString(), *GetMatchmakingEnqueueResult()->GetDebugString()));
	
	return Log;
}




void UPico_MatchmakingEnqueueResult::InitParams(ppfMatchmakingEnqueueResultHandle InHandle)
{
	ppfMatchmakingAdminSnapshotHandle pointer = ppf_MatchmakingEnqueueResult_GetAdminSnapshot(InHandle);
	if (pointer == nullptr)
	{
		AdminSnapshotOptional = nullptr;
	}
	else
	{
		AdminSnapshotOptional = NewObject<UPico_MatchmakingAdminSnapshot>(this);
		AdminSnapshotOptional->InitParams(pointer);
	}

	AverageWait = ppf_MatchmakingEnqueueResult_GetAverageWait(InHandle);
	MatchesInLastHourCount = ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount(InHandle);
	MaxExpectedWait = ppf_MatchmakingEnqueueResult_GetMaxExpectedWait(InHandle);
	Pool = ppf_MatchmakingEnqueueResult_GetPool(InHandle);
	RecentMatchPercentage = ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage(InHandle);
}
UPico_MatchmakingAdminSnapshot* UPico_MatchmakingEnqueueResult::GetAdminSnapshotOptional()
{
	return AdminSnapshotOptional;
}
int32 UPico_MatchmakingEnqueueResult::GetAverageWait()
{
	return AverageWait;
}
int32 UPico_MatchmakingEnqueueResult::GetMatchesInLastHourCount()
{
	return MatchesInLastHourCount;
}
int32 UPico_MatchmakingEnqueueResult::GetMaxExpectedWait()
{
	return MaxExpectedWait;
}
FString UPico_MatchmakingEnqueueResult::GetPool()
{
	return Pool;
}
int32 UPico_MatchmakingEnqueueResult::GetRecentMatchPercentage()
{
	return RecentMatchPercentage;
}
FString UPico_MatchmakingEnqueueResult::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingEnqueueResult DebugString:\nAverageWait: %d\nMatchesInLastHourCount: %d\nGetMaxExpectedWait: %d\nPool: %s\nRecentMatchPercentage: %d\nAdminSnapshotOptional: %s\n")
		, GetAverageWait(), GetMatchesInLastHourCount(), GetMaxExpectedWait(), *GetPool(), GetRecentMatchPercentage(), *GetAdminSnapshotOptional()->GetDebugString()));
	
	return Log;
}




void UPico_MatchmakingAdminSnapshot::InitParams(ppfMatchmakingAdminSnapshotHandle InHandle)
{
	CandidateList = NewObject<UPico_MatchmakingAdminSnapshotCandidateList>(this);
	CandidateList->InitParams(ppf_MatchmakingAdminSnapshot_GetCandidates(InHandle));
	MyCurrentThreshold = ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold(InHandle);
}
UPico_MatchmakingAdminSnapshotCandidateList* UPico_MatchmakingAdminSnapshot::GetCandidateList()
{
	return CandidateList;
}
float UPico_MatchmakingAdminSnapshot::GetMyCurrentThreshold()
{
	return MyCurrentThreshold;
}
FString UPico_MatchmakingAdminSnapshot::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingEnqueueResult DebugString:\nMyCurrentThreshold: %f\nCandidateList: %s\n")
		, GetMyCurrentThreshold(), *GetCandidateList()->GetDebugString()));
	
	return Log;
}







void UPico_MatchmakingAdminSnapshotCandidateList::InitParams(ppfMatchmakingAdminSnapshotCandidateArrayHandle InHandle)
{
	UE_LOG(PicoRoom, Log, TEXT("UPico_MatchmakingRoomList::InitParams"));
	TotalSize = ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount(InHandle);
	Size = ppf_MatchmakingAdminSnapshotCandidateArray_GetSize(InHandle);
	for (int32 i = 0; i < TotalSize; i++)
	{
		UPico_MatchmakingAdminSnapshotCandidate* ThisElement = NewObject<UPico_MatchmakingAdminSnapshotCandidate>(this);
		ThisElement->InitParams(ppf_MatchmakingAdminSnapshotCandidateArray_GetElement(InHandle, i));
		MatchmakingAdminSnapshotCandidateArray.Add(ThisElement);
	}
}
UPico_MatchmakingAdminSnapshotCandidate* UPico_MatchmakingAdminSnapshotCandidateList::GetElement(int32 Index)
{
	if (MatchmakingAdminSnapshotCandidateArray.IsValidIndex(Index))
	{
		return MatchmakingAdminSnapshotCandidateArray[Index];
	}
	return nullptr; 
}
int32 UPico_MatchmakingAdminSnapshotCandidateList::GetTotalSize()
{
	return TotalSize;
}
int32 UPico_MatchmakingAdminSnapshotCandidateList::GetSize()
{
	return Size;
}
FString UPico_MatchmakingAdminSnapshotCandidateList::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingAdminSnapshotCandidateList DebugString:\nTotalSize: %d\nSize: %d\n"), GetTotalSize(), GetSize()));
	for (int32 i = 0; i < TotalSize; i++)
	{
		Log.Append(FString::Printf(TEXT("%d:\n%s\n"), i, *MatchmakingAdminSnapshotCandidateArray[i]->GetDebugString()));
	}
	
	return Log;
}





void UPico_MatchmakingAdminSnapshotCandidate::InitParams(ppfMatchmakingAdminSnapshotCandidateHandle InHandle)
{
	CanMatch = ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch(InHandle);
	MyTotalScore = ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore(InHandle);
	TheirCurrentThreshold = ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold(InHandle);
}
bool UPico_MatchmakingAdminSnapshotCandidate::GetCanMatch()
{
	return CanMatch;
}
float UPico_MatchmakingAdminSnapshotCandidate::GetMyTotalScore()
{
	return MyTotalScore;
}
float UPico_MatchmakingAdminSnapshotCandidate::GetTheirCurrentThreshold()
{
	return TheirCurrentThreshold;
}
FString UPico_MatchmakingAdminSnapshotCandidate::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("MatchmakingAdminSnapshotCandidate DebugString:\nCanMatch: %s\nMyTotalScore: %f\nTheirCurrentThreshold: %f\n"), GetCanMatch() ? TEXT("true") : TEXT("false")
		, GetMyTotalScore(), GetTheirCurrentThreshold()));
	
	return Log;
}










