// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "OnlineSubsystem.h"
#include "OnlineSubsystemImpl.h"
#include "OnlineMessageTaskManagerPico.h"
#include "OnlineSubsystemPicoModule.h"

typedef TUniquePtr<class FOnlineMessageTaskManagerPico> FOnlineMessageTaskManagerPicoPtr;
typedef TSharedPtr<class FOnlineAchievementsPico, ESPMode::ThreadSafe> FOnlineAchievementsPicoPtr;

class ONLINESUBSYSTEMPICO_API FOnlineSubsystemPico:public FOnlineSubsystemImpl
{
public:
	virtual ~FOnlineSubsystemPico() = default;
	
	// IOnlineSubsystem
	virtual IOnlineSessionPtr GetSessionInterface() const override;
	virtual IOnlineFriendsPtr GetFriendsInterface() const override;
	virtual IOnlinePartyPtr GetPartyInterface() const override;
	virtual IOnlineGroupsPtr GetGroupsInterface() const override;
	virtual IOnlineSharedCloudPtr GetSharedCloudInterface() const override;
	virtual IOnlineUserCloudPtr GetUserCloudInterface() const override;
	virtual IOnlineEntitlementsPtr GetEntitlementsInterface() const override;
	virtual IOnlineLeaderboardsPtr GetLeaderboardsInterface() const override;
	virtual IOnlineVoicePtr GetVoiceInterface() const override;
	virtual IOnlineExternalUIPtr GetExternalUIInterface() const override;
	virtual IOnlineTimePtr GetTimeInterface() const override;
	virtual IOnlineIdentityPtr GetIdentityInterface() const override;
	virtual IOnlineTitleFilePtr GetTitleFileInterface() const override;
#if ENGINE_MINOR_VERSION < 26
	virtual IOnlineStorePtr GetStoreInterface() const override;
#endif
	virtual IOnlineStoreV2Ptr GetStoreV2Interface() const override;
	virtual IOnlinePurchasePtr GetPurchaseInterface() const override;
	virtual IOnlineEventsPtr GetEventsInterface() const override;
	virtual IOnlineAchievementsPtr GetAchievementsInterface() const override;
	virtual IOnlineSharingPtr GetSharingInterface() const override;
	virtual IOnlineUserPtr GetUserInterface() const override;
	virtual IOnlineMessagePtr GetMessageInterface() const override;
	virtual IOnlinePresencePtr GetPresenceInterface() const override;
	virtual IOnlineChatPtr GetChatInterface() const override;
	virtual IOnlineStatsPtr GetStatsInterface() const override;
	virtual IOnlineTurnBasedPtr GetTurnBasedInterface() const override;
	virtual IOnlineTournamentPtr GetTournamentInterface() const override;

	virtual bool Init() override;
	virtual bool Shutdown() override;
	virtual FString GetAppId() const override;
	virtual bool Exec(class UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	virtual FText GetOnlineServiceName() const override;

	virtual bool Tick(float DeltaTime) override;

	void AddRequestDelegate(uint64 RequestId, FPicoMessageOnCompleteDelegate&& Delegate) const;

	FPicoMulticastMessageOnCompleteDelegate& GetNotifyDelegate(EOnlineMessageType MessageType) const;
	void RemoveNotifyDelegate(EOnlineMessageType MessageType, const FDelegateHandle& Delegate) const;

    FOnlineSubsystemPico() = delete;
	explicit FOnlineSubsystemPico(FName InInstanceName)
	:FOnlineSubsystemImpl(PICO_SUBSYSTEM, InInstanceName)
	,bPicoInit(false)
	{
	}

	bool IsInitialized() const{return bPicoInit;};

	bool InitWithAndroidPlatform(FPicoInitOnCompleteDelegate&& Delegate);

private:

	bool bPicoInit;
	
	FOnlineMessageTaskManagerPicoPtr MessageTaskManager;

	FOnlineAchievementsPicoPtr AchievementsInterface;

};

namespace FNetworkProtocolTypes
{
	ONLINESUBSYSTEMPICO_API extern const FName Pico;
}

typedef TSharedPtr<FOnlineSubsystemPico, ESPMode::ThreadSafe> FOnlineSubsystemPicoPtr;
