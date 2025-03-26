// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "Pico_Challenges.h"
#include "Pico_User.h"
#include "Pico_Leaderboards.h"

#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PicoChallenges);


// FPicoChallengesInterface
FPicoChallengesInterface::FPicoChallengesInterface(FOnlineSubsystemPico& InSubsystem) :
	PicoSubsystem(InSubsystem)
{
	ChallengeInviteAcceptedOrLaunchAppHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Challenge_LaunchByInvite)
		.AddRaw(this, &FPicoChallengesInterface::OnChallengeInviteAcceptedOrLaunchAppNotification);
}

FPicoChallengesInterface::~FPicoChallengesInterface()
{
	if (ChallengeInviteAcceptedOrLaunchAppHandle.IsValid())
	{
		ChallengeInviteAcceptedOrLaunchAppHandle.Reset();
	}
}
void FPicoChallengesInterface::OnChallengeInviteAcceptedOrLaunchAppNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::OnChallengeInviteAcceptedOrLaunchAppNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoChallenges, Error, TEXT("OnChallengeInviteAcceptedOrLaunchAppNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		ChallengeInviteAcceptedOrLaunchAppNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, FString());
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("OnChallengeInviteAcceptedOrLaunchAppNotification success!"));
		const FString ChallengeID = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
		ChallengeInviteAcceptedOrLaunchAppNotify.Broadcast(bIsError, 0, FString(), ChallengeID);
	}
}

bool FPicoChallengesInterface::Get(const FString& ChallengeID, FChallengeGet InGetDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::Get"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	ppfRequest RequestId = ppf_Challenges_Get(ID);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InGetDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("Get return failed:%s"), *ErrorMessage);
				this->GetDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InGetDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("Get Successfully"));
				UPico_Challenge* Pico_Challenge = NewObject<UPico_Challenge>();
				Pico_Challenge->InitParams(ppf_Message_GetChallenge(Message));
				this->GetDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
				InGetDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::GetEntries(const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardFilterType Filter, ELeaderboardStartAt StartAt, FChallengeGetEntries InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetEntries"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	ppfRequest RequestId = ppf_Challenges_GetEntries(ID, (ppfLeaderboardFilterType)Filter, (ppfLeaderboardStartAt)StartAt, PageIdx, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("GetEntries return failed:%s"), *ErrorMessage);
				this->GetEntriesDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("GetEntries Successfully"));
				UPico_ChallengeEntryArray* Pico_ChallengeEntryArray = NewObject<UPico_ChallengeEntryArray>();
				Pico_ChallengeEntryArray->InitParams(ppf_Message_GetChallengeEntryArray(Message));
				this->GetEntriesDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
				InDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
			}
		}));
	return true;
}
    
bool FPicoChallengesInterface::GetEntriesAfterRank(ppfID ChallengeID, int PageIdx, int PageSize, unsigned long long AfterRank, FChallengeGetEntriesAfterRank InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetEntriesAfterRank"));
	ppfRequest RequestId = ppf_Challenges_GetEntriesAfterRank(ChallengeID, AfterRank, PageIdx, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("GetEntriesAfterRank return failed:%s"), *ErrorMessage);
				this->GetEntriesAfterRankDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("GetEntriesAfterRank Successfully"));
				UPico_ChallengeEntryArray* Pico_ChallengeEntryArray = NewObject<UPico_ChallengeEntryArray>();
				Pico_ChallengeEntryArray->InitParams(ppf_Message_GetChallengeEntryArray(Message));
				this->GetEntriesAfterRankDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
				InDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::GetEntriesByIds(const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FChallengeGetEntriesByIds InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetEntriesByIds"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	int32 Length = UserIDs.Num();
	std::vector<std::string> StringArray;
	for (size_t i = 0; i < UserIDs.Num(); i++)
	{
		StringArray.push_back(std::string(TCHAR_TO_UTF8(*(UserIDs[i]))));
	}
	std::vector<const char*> userIDs;
	for (size_t i = 0; i < StringArray.size(); i++)
	{
		userIDs.push_back(StringArray[i].c_str());
	}
	ppfRequest RequestId = ppf_Challenges_GetEntriesByIds(ID, (ppfLeaderboardStartAt)StartAt, userIDs.data(), UserIDs.Num(), PageIdx, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("GetEntriesByIds return failed:%s"), *ErrorMessage);
				this->GetEntriesByIdsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("GetEntriesByIds Successfully"));
				UPico_ChallengeEntryArray* Pico_ChallengeEntryArray = NewObject<UPico_ChallengeEntryArray>();
				Pico_ChallengeEntryArray->InitParams(ppf_Message_GetChallengeEntryArray(Message));
				this->GetEntriesByIdsDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
				InDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeEntryArray);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::GetList(FPico_ChallengeOptions ChallengeOptions, int PageIdx, int PageSize, FChallengeGetList InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList"));
	auto ppfChallengeOptionsHandle = ppf_ChallengeOptions_Create();

	ppf_ChallengeOptions_SetEndDate(ppfChallengeOptionsHandle, ChallengeOptions.EndDate);
	ppf_ChallengeOptions_SetIncludeActiveChallenges(ppfChallengeOptionsHandle, ChallengeOptions.bIncludeActiveChallenges);
	ppf_ChallengeOptions_SetIncludeFutureChallenges(ppfChallengeOptionsHandle, ChallengeOptions.bIncludeFutureChallenges);
	ppf_ChallengeOptions_SetIncludePastChallenges(ppfChallengeOptionsHandle, ChallengeOptions.bIncludePastChallenges);
	ppf_ChallengeOptions_SetLeaderboardName(ppfChallengeOptionsHandle, TCHAR_TO_ANSI(*ChallengeOptions.LeaderboardName));
	ppf_ChallengeOptions_SetStartDate(ppfChallengeOptionsHandle, ChallengeOptions.StartDate);
	ppf_ChallengeOptions_SetTitle(ppfChallengeOptionsHandle, TCHAR_TO_ANSI(*ChallengeOptions.Title));
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList StartDate: %d"), ChallengeOptions.StartDate);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList EndDate: %d"), ChallengeOptions.EndDate);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList bIncludeActiveChallenges: %d"), ChallengeOptions.bIncludeActiveChallenges);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList bIncludeFutureChallenges: %d"), ChallengeOptions.bIncludeFutureChallenges);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList bIncludePastChallenges: %d"), ChallengeOptions.bIncludePastChallenges);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList LeaderboardName: %s"), *ChallengeOptions.LeaderboardName);
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Title: %s"), *ChallengeOptions.Title);
	switch (ChallengeOptions.Visibility)
	{
	case EChallengeVisibility::Unknown: ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle, ppfChallengeVisibility_Unknown); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Visibility: ppfChallengeVisibility_Unknown"));
	case EChallengeVisibility::InviteOnly: ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle, ppfChallengeVisibility_InviteOnly); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Visibility: ppfChallengeVisibility_InviteOnly"));
	case EChallengeVisibility::Public: ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle, ppfChallengeVisibility_Public); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Visibility: ppfChallengeVisibility_Public"));
	case EChallengeVisibility::Private: ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle, ppfChallengeVisibility_Private); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Visibility: ppfChallengeVisibility_Private"));
	default: ppf_ChallengeOptions_SetVisibility(ppfChallengeOptionsHandle, ppfChallengeVisibility_Unknown); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList Visibility: ppfChallengeVisibility_Unknown"));
	}
	switch (ChallengeOptions.ViewerFilter)
	{
	case EChallengeViewerFilter::Unknown: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_Unknown); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_Unknown"));
	case EChallengeViewerFilter::AllVisible: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_AllVisible); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_AllVisible"));
	case EChallengeViewerFilter::Participating: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_Participating); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_Participating"));
	case EChallengeViewerFilter::Invited: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_Invited); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_Invited"));
	case EChallengeViewerFilter::ParticipatingOrInvited: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_ParticipatingOrInvited); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_ParticipatingOrInvited"));
	default: ppf_ChallengeOptions_SetViewerFilter(ppfChallengeOptionsHandle, ppfChallengeViewerFilter_Unknown); break;
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::GetList ViewerFilter: ppfChallengeViewerFilter_Unknown"));
	}
		
	
	ppfRequest RequestId = ppf_Challenges_GetList(ppfChallengeOptionsHandle, PageIdx, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("GetList return failed:%s"), *ErrorMessage);
				this->GetListDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("GetList Successfully"));
				UPico_ChallengeArray* Pico_ChallengeArray = NewObject<UPico_ChallengeArray>();
				Pico_ChallengeArray->InitParams(ppf_Message_GetChallengeArray(Message));
				this->GetListDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeArray);
				InDelegate.ExecuteIfBound(false, FString(), Pico_ChallengeArray);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::Join(const FString& ChallengeID, FChallengeJoin InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::Join"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	ppfRequest RequestId = ppf_Challenges_Join(ID);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("Join return failed:%s"), *ErrorMessage);
				this->JoinDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("Join Successfully"));
				UPico_Challenge* Pico_Challenge = NewObject<UPico_Challenge>();
				Pico_Challenge->InitParams(ppf_Message_GetChallenge(Message));
				this->JoinDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
				InDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::Leave( const FString& ChallengeID, FChallengeLeave InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::Leave"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	ppfRequest RequestId = ppf_Challenges_Leave(ID);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("Leave return failed:%s"), *ErrorMessage);
				this->LeaveDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("Leave Successfully"));
				UPico_Challenge* Pico_Challenge = NewObject<UPico_Challenge>();
				Pico_Challenge->InitParams(ppf_Message_GetChallenge(Message));
				this->LeaveDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
				InDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
			}
		}));
	return true;
}

bool FPicoChallengesInterface::Invite(const FString& ChallengeID, const TArray<FString>& UserIDs, FChallengeInvite InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::Invite"));
	int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	int32 Length = UserIDs.Num();
	std::vector<std::string> StringArray;
	for (size_t i = 0; i < UserIDs.Num(); i++)
	{
		StringArray.push_back(std::string(TCHAR_TO_UTF8(*(UserIDs[i]))));
	}
	std::vector<const char*> userIDs;
	for (size_t i = 0; i < StringArray.size(); i++)
	{
		userIDs.push_back(StringArray[i].c_str());
	}
	ppfRequest RequestId = ppf_Challenges_Invites(ID, userIDs.data(), UserIDs.Num());
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("Invite return failed:%s"), *ErrorMessage);
				this->InviteDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
				InDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("Invite Successfully"));
				UPico_Challenge* Pico_Challenge = NewObject<UPico_Challenge>();
				Pico_Challenge->InitParams(ppf_Message_GetChallenge(Message));
				this->InviteDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
				InDelegate.ExecuteIfBound(false, FString(), Pico_Challenge);
			}
		}));
	return true;
}
bool FPicoChallengesInterface::LaunchInvitableUserFlow(const FString& ChallengeID, FChallengeLaunchInvitableUserFlow InDelegate)
{
#if PLATFORM_ANDROID
	UE_LOG(PicoChallenges, Log, TEXT("FPicoChallengesInterface::LaunchInvitableUserFlow"));
	const int64 ID = FCString::Strtoi64(*ChallengeID, NULL, 10);
	ppfRequest RequestId = ppf_Challenges_LaunchInvitableUserFlow(ID);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[InDelegate, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const ppfErrorHandle Error = ppf_Message_GetError(Message);
				const int ErrorCode = ppf_Error_GetCode(Error);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				UE_LOG(PicoChallenges, Log, TEXT("LaunchInvitableUserFlow return failed:%s"), *ErrorMessage);
				this->LaunchInvitableUserFlowDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoChallenges, Log, TEXT("LaunchInvitableUserFlow Successfully"));
				this->LaunchInvitableUserFlowDelegate.ExecuteIfBound(false, 0, FString());
				InDelegate.ExecuteIfBound(false, 0, FString());
			}
		}));
#endif
	return true;
}




// UOnlinePicoChallengesFunction
void UOnlinePicoChallengesFunction::Get(UObject* WorldContextObject, const FString& ChallengeID, FChallengeGet InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::Get"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->Get(ChallengeID, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("Get Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::GetEntries(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardFilterType Filter, ELeaderboardStartAt StartAt, FChallengeGetEntries InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::GetEntries"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->GetEntries(ChallengeID, PageIdx, PageSize, Filter, StartAt, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("GetEntries Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::GetEntriesAfterRank(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize, const FString& AfterRank, FChallengeGetEntriesAfterRank InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::GetEntriesAfterRank"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		if (ChallengeID.Contains(TEXT("-")))
		{
			UE_LOG(PicoChallenges, Log, TEXT("GetEntriesAfterRank Failed, input parameters error!"));
			InDelegate.ExecuteIfBound(true, FString(TEXT("Input parameters error!")), nullptr);
		}
		else
		{
			uint64 ID = FCString::Strtoui64(*ChallengeID, NULL, 10);
			uint64 afterRank = FCString::Strtoui64(*AfterRank, NULL, 10);
			Subsystem->GetPicoChallengesInterface()->GetEntriesAfterRank(ID, PageIdx, PageSize, afterRank, InDelegate);	
		}
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("GetEntriesAfterRank Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::GetEntriesByIds(UObject* WorldContextObject, const FString& ChallengeID, int PageIdx, int PageSize, ELeaderboardStartAt StartAt, const TArray<FString>& UserIDs, FChallengeGetEntriesByIds InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::GetEntriesByIds"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->GetEntriesByIds(ChallengeID, PageIdx, PageSize, StartAt, UserIDs, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("GetEntriesByIds Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::GetList(UObject* WorldContextObject, FPico_ChallengeOptions ChallengeOptions, int PageIdx, int PageSize, FChallengeGetList InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::GetList"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{	
		Subsystem->GetPicoChallengesInterface()->GetList(ChallengeOptions, PageIdx, PageSize, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("GetList Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::Join(UObject* WorldContextObject, const FString& ChallengeID, FChallengeJoin InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::Join"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->Join(ChallengeID, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("Join Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::Leave(UObject* WorldContextObject, const FString& ChallengeID, FChallengeLeave InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::Leave"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->Leave(ChallengeID, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("Leave Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoChallengesFunction::Invite(UObject* WorldContextObject, const FString& ChallengeID, const TArray<FString>& UserIDs, FChallengeInvite InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::Invite"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->Invite(ChallengeID, UserIDs, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("Invite Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, FString(TEXT("PicoChallengesInterface Not Vailed")), nullptr);
	}
}
void UOnlinePicoChallengesFunction::LaunchInvitableUserFlow(UObject* WorldContextObject, const FString& ChallengeID, FChallengeLaunchInvitableUserFlow InDelegate)
{
	UE_LOG(PicoChallenges, Log, TEXT("UOnlinePicoChallengesFunction::LaunchInvitableUserFlow"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoChallengesInterface())
	{
		Subsystem->GetPicoChallengesInterface()->LaunchInvitableUserFlow(ChallengeID, InDelegate);
	}
	else
	{
		UE_LOG(PicoChallenges, Log, TEXT("Invite Failed, PicoChallengesInterface Not Vailed!"));
		InDelegate.ExecuteIfBound(true, -1, FString(TEXT("PicoChallengesInterface Not Vailed")));
	}
}







// UPico_Challenge
void UPico_Challenge::InitParams(ppfChallenge* ppfChallengeHandle)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_Challenge::InitParams"));
	CreationType = ppf_Challenge_GetCreationType(ppfChallengeHandle);
	EndDate = ppf_Challenge_GetEndDate(ppfChallengeHandle);
	StartDate = ppf_Challenge_GetStartDate(ppfChallengeHandle);
	ID = ppf_Challenge_GetID(ppfChallengeHandle);
	Title = UTF8_TO_TCHAR(ppf_Challenge_GetTitle(ppfChallengeHandle));
	Visibility = ppf_Challenge_GetVisibility(ppfChallengeHandle);
	if (InvitedUsersOptional == nullptr)
	{
		InvitedUsersOptional = NewObject<UPico_UserArray>(this);
	}
	InvitedUsersOptional->InitParams(ppf_Challenge_GetInvitedUsers(ppfChallengeHandle));
	if (ParticipantsOptional == nullptr)
	{
		ParticipantsOptional = NewObject<UPico_UserArray>(this);
	}
	ParticipantsOptional->InitParams(ppf_Challenge_GetParticipants(ppfChallengeHandle));
	if (Leaderboard == nullptr)
	{
		Leaderboard = NewObject<UPico_Leaderboard>(this);
	}
	Leaderboard->InitParams(ppf_Challenge_GetLeaderboard(ppfChallengeHandle));
}

EChallengeCreationType UPico_Challenge::GetCreationType()
{
	return (EChallengeCreationType)CreationType;
}

FDateTime UPico_Challenge::GetEndDateTime()
{
	FDateTime Time = FDateTime::FromUnixTimestamp(EndDate);
	return Time;
}

FDateTime UPico_Challenge::GetStartDateTime()
{
	FDateTime Time = FDateTime::FromUnixTimestamp(StartDate);
	return Time;
}
FString UPico_Challenge::GetEndDate()
{
	return FString::Printf(TEXT("%llu"), EndDate);
}

FString UPico_Challenge::GetStartDate()
{
	return FString::Printf(TEXT("%llu"), StartDate);
}

FString UPico_Challenge::GetID()
{
	return FString::Printf(TEXT("%llu"), ID);
}

FString UPico_Challenge::GetTitle()
{
	return Title;
}

EChallengeVisibility UPico_Challenge::GetVisibility()
{
	return (EChallengeVisibility)Visibility;
}

UPico_UserArray* UPico_Challenge::GetInvitedUsersOptional()
{
	return InvitedUsersOptional;
}

UPico_Leaderboard* UPico_Challenge::GetLeaderboard()
{
	return Leaderboard;
}

UPico_UserArray* UPico_Challenge::GetParticipantsOptional()
{
	return ParticipantsOptional;
}






// UPico_ChallengeEntry
void UPico_ChallengeEntry::InitParams(ppfChallengeEntryHandle ppfChallengeEntryHandle)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeEntry::InitParams"));
	DisplayScore = UTF8_TO_TCHAR(ppf_ChallengeEntry_GetDisplayScore(ppfChallengeEntryHandle));
	ID = ppf_ChallengeEntry_GetID(ppfChallengeEntryHandle);
	Rank = ppf_ChallengeEntry_GetRank(ppfChallengeEntryHandle);
	Score = ppf_ChallengeEntry_GetScore(ppfChallengeEntryHandle);
	Timestamp = ppf_ChallengeEntry_GetTimestamp(ppfChallengeEntryHandle);
	if (User == nullptr)
	{
		User = NewObject<UPico_User>(this);
	}
	User->InitParams(ppf_ChallengeEntry_GetUser(ppfChallengeEntryHandle));
	// ExtraData
	int size = ppf_ChallengeEntry_GetExtraDataLength(ppfChallengeEntryHandle);
	auto extraData = (uint8*)ppf_ChallengeEntry_GetExtraData(ppfChallengeEntryHandle);
	for (int i = 0; i < size; i++)
	{
		ExtraData.Add(*(extraData + i));
	}
}

FString UPico_ChallengeEntry::GetDisplayScore()
{
	return DisplayScore;
}

TArray<uint8> UPico_ChallengeEntry::GetExtraData()
{
	return ExtraData;
}

FString UPico_ChallengeEntry::GetExtraDataString()
{
	const std::string cstr(reinterpret_cast<const char*>(ExtraData.GetData()), ExtraData.Num());  
	FString ExtraDataString = UTF8_TO_TCHAR(cstr.c_str());
	return ExtraDataString;
}

FString UPico_ChallengeEntry::GetID()
{
	return FString::Printf(TEXT("%llu"), ID);
}

int32 UPico_ChallengeEntry::GetRank()
{
	return Rank;
}

int64 UPico_ChallengeEntry::GetScore()
{
	return Score;
}

FDateTime UPico_ChallengeEntry::GetTimestamp()
{
	FDateTime Time = FDateTime::FromUnixTimestamp(Timestamp);
	return Time;
}

UPico_User* UPico_ChallengeEntry::GetUser()
{
	return User;
}




// UPico_ChallengeEntryArray
void UPico_ChallengeEntryArray::InitParams(ppfChallengeEntryArrayHandle InppfChallengeEntryArrayHandle)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeEntryArray::InitParams"));
	Size = ppf_ChallengeEntryArray_GetSize(InppfChallengeEntryArrayHandle);
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeEntryArray::InitParams ppf_ChallengeEntryArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_ChallengeEntry* ThisElement = NewObject<UPico_ChallengeEntry>(this);
		ThisElement->InitParams(ppf_ChallengeEntryArray_GetElement(InppfChallengeEntryArrayHandle, i));
		ChallengeEntryArray.Add(ThisElement);
	}
	bHasNextPage = ppf_ChallengeEntryArray_HasNextPage(InppfChallengeEntryArrayHandle);
	TotalCount = ppf_ChallengeEntryArray_GetTotalCount(InppfChallengeEntryArrayHandle);
	bHasPreviousPage = ppf_ChallengeEntryArray_HasPreviousPage(InppfChallengeEntryArrayHandle);
}

UPico_ChallengeEntry* UPico_ChallengeEntryArray::GetElement(int32 Index)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeEntryArray::GetElement Index: %d"), Index);
	if (ChallengeEntryArray.IsValidIndex(Index))
	{
		return ChallengeEntryArray[Index];
	}
	return nullptr;
}

int32 UPico_ChallengeEntryArray::GetSize()
{
	return Size;
}

bool UPico_ChallengeEntryArray::HasNextPage()
{
	return bHasNextPage;
}

bool UPico_ChallengeEntryArray::HasPreviousPage()
{
	return bHasPreviousPage;
}

int32 UPico_ChallengeEntryArray::GetTotalCount()
{
	return TotalCount;
}






// UPico_ChallengeArray
void UPico_ChallengeArray::InitParams(ppfChallengeArrayHandle InppfChallengeArrayHandle)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeArray::InitParams"));
	Size = ppf_ChallengeArray_GetSize(InppfChallengeArrayHandle);
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeArray::InitParams ppf_ChallengeArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_Challenge* ThisElement = NewObject<UPico_Challenge>(this);
		ThisElement->InitParams(ppf_ChallengeArray_GetElement(InppfChallengeArrayHandle, i));
		ChallengeArray.Add(ThisElement);
	}
	bHasNextPage = ppf_ChallengeArray_HasNextPage(InppfChallengeArrayHandle);
	TotalCount = ppf_ChallengeArray_GetTotalCount(InppfChallengeArrayHandle);
	bHasPreviousPage = ppf_ChallengeArray_HasPreviousPage(InppfChallengeArrayHandle);
}

UPico_Challenge* UPico_ChallengeArray::GetElement(int32 Index)
{
	UE_LOG(PicoChallenges, Log, TEXT("UPico_ChallengeArray::GetElement Index: %d"), Index);
	if (ChallengeArray.IsValidIndex(Index))
	{
		return ChallengeArray[Index];
	}
	return nullptr;
}

int32 UPico_ChallengeArray::GetSize()
{
	return Size;
}

bool UPico_ChallengeArray::HasNextPage()
{
	return bHasNextPage;
}

bool UPico_ChallengeArray::HasPreviousPage()
{
	return bHasPreviousPage;
}

int32 UPico_ChallengeArray::GetTotalCount()
{
	return TotalCount;
}
