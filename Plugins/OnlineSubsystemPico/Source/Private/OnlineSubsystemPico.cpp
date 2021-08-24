// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "OnlineSubsystemPico.h"
#include "Misc/ConfigCacheIni.h"
#include "OnlinePlatformInterfacePico.h"
#include "OnlineLeaderboardInterfacePico.h"
#include "OnlineAchievementsInterfacePico.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif


namespace FNetworkProtocolTypes
{
	const FName Pico(TEXT("Pico"));
}


IOnlineSessionPtr FOnlineSubsystemPico::GetSessionInterface() const
{
	return nullptr;
}

IOnlineGroupsPtr FOnlineSubsystemPico::GetGroupsInterface() const
{
	return nullptr;
}

IOnlineFriendsPtr FOnlineSubsystemPico::GetFriendsInterface() const
{
	return nullptr;
}

IOnlineSharedCloudPtr FOnlineSubsystemPico::GetSharedCloudInterface() const
{
	return nullptr;
}

IOnlineUserCloudPtr FOnlineSubsystemPico::GetUserCloudInterface() const
{
	return nullptr;
}

IOnlineEntitlementsPtr FOnlineSubsystemPico::GetEntitlementsInterface() const
{
	return nullptr;
};

IOnlineLeaderboardsPtr FOnlineSubsystemPico::GetLeaderboardsInterface() const
{
	return LeaderboardInterface;
}

IOnlineVoicePtr FOnlineSubsystemPico::GetVoiceInterface() const
{
	return nullptr;
}

IOnlineExternalUIPtr FOnlineSubsystemPico::GetExternalUIInterface() const
{
	return nullptr;
}

IOnlineTimePtr FOnlineSubsystemPico::GetTimeInterface() const
{
	return nullptr;
}

IOnlineIdentityPtr FOnlineSubsystemPico::GetIdentityInterface() const
{
	return nullptr;
}

IOnlinePartyPtr FOnlineSubsystemPico::GetPartyInterface() const
{
	return nullptr;
}

IOnlineTitleFilePtr FOnlineSubsystemPico::GetTitleFileInterface() const
{
	return nullptr;
}

IOnlineStorePtr FOnlineSubsystemPico::GetStoreInterface() const
{
	return nullptr;
}

IOnlineStoreV2Ptr FOnlineSubsystemPico::GetStoreV2Interface() const
{
	return nullptr;
}

IOnlinePurchasePtr FOnlineSubsystemPico::GetPurchaseInterface() const
{
	return nullptr;
}

IOnlineEventsPtr FOnlineSubsystemPico::GetEventsInterface() const
{
	return nullptr;
}

IOnlineAchievementsPtr FOnlineSubsystemPico::GetAchievementsInterface() const
{
	return AchievementsInterface;
}

IOnlineSharingPtr FOnlineSubsystemPico::GetSharingInterface() const
{
	return nullptr;
}

IOnlineUserPtr FOnlineSubsystemPico::GetUserInterface() const
{
	return nullptr;
}

IOnlineMessagePtr FOnlineSubsystemPico::GetMessageInterface() const
{
	return nullptr;
}

IOnlinePresencePtr FOnlineSubsystemPico::GetPresenceInterface() const
{
	return nullptr;
}

IOnlineChatPtr FOnlineSubsystemPico::GetChatInterface() const
{
	return nullptr;
}

IOnlineStatsPtr FOnlineSubsystemPico::GetStatsInterface() const
{
	return nullptr;
}

IOnlineTurnBasedPtr FOnlineSubsystemPico::GetTurnBasedInterface() const
{
	return nullptr;
}

IOnlineTournamentPtr FOnlineSubsystemPico::GetTournamentInterface() const
{
	return nullptr;
}

bool FOnlineSubsystemPico::Init()
{
	UE_LOG(LogTemp,Log,TEXT("FOnlineSubsystemPico::Init"));
	MessageTaskManager = MakeUnique<FOnlineMessageTaskManagerPico>();
	check(MessageTaskManager);
	AchievementsInterface = MakeShareable(new FOnlineAchievementsPico(*this));
	LeaderboardInterface = MakeShareable(new FOnlineLeaderboardPico(*this));

	StartTicker();
	return true;
}

bool FOnlineSubsystemPico::Tick(float DeltaTime)
{	
	if (!FOnlineSubsystemImpl::Tick(DeltaTime))
	{
		return false;
	}
	if (MessageTaskManager.IsValid())
	{
		if (!MessageTaskManager->Tick(DeltaTime))
		{
			UE_LOG_ONLINE(Error, TEXT("An error occured when processing the message queue"));
		}
	}
	return true;
}

void FOnlineSubsystemPico::AddRequestDelegate(uint64 RequestId, FPicoMessageOnCompleteDelegate&& Delegate) const
{
	check(MessageTaskManager);
	UE_LOG(LogTemp, Log, TEXT("AddRequestDelegate %llu"), RequestId);
	MessageTaskManager->AddRequestDelegate(RequestId, MoveTemp(Delegate));
}

FPicoMulticastMessageOnCompleteDelegate& FOnlineSubsystemPico::GetNotifyDelegate(EOnlineMessageType MessageType) const
{
	check(MessageTaskManager);
	return MessageTaskManager->GetNotifyDelegate(MessageType);
}

void FOnlineSubsystemPico::RemoveNotifyDelegate(EOnlineMessageType MessageType, const FDelegateHandle& Delegate) const
{
	check(MessageTaskManager);
	return MessageTaskManager->RemoveNotifyDelegate(MessageType, Delegate);
}

bool FOnlineSubsystemPico::InitWithAndroidPlatform(FPicoInitOnCompleteDelegate&& Delegate)
{
#if !PLATFORM_ANDROID
	Delegate.ExecuteIfBound(false);
	return false;
#endif
	OnlinePlatformInterfacePico::Achievement_Init();
	AddRequestDelegate(999, FPicoMessageOnCompleteDelegate::CreateLambda([this, Delegate](FOnlineMessageHandle Message, bool bIsError)
	{
		Delegate.ExecuteIfBound(!bIsError);
	}));
	return true;
}

bool FOnlineSubsystemPico::Shutdown()
{
	FOnlineSubsystemImpl::Shutdown();
	return true;
}

FString FOnlineSubsystemPico::GetAppId() const
{
	//return "1";
	return GConfig->GetStr(TEXT("/Script/PicoMobile.PicoMobileSettings"), TEXT("appID"), GEngineIni);
}

bool FOnlineSubsystemPico::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return false;
}

FText FOnlineSubsystemPico::GetOnlineServiceName() const
{
	return NSLOCTEXT("OnlineSubsystemPico", "OnlineServiceName", "Pico Platform");
}