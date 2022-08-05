// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "OnlineSubsystem.h"
#include "OnlineSubsystemImpl.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineMessageTaskManagerPico.h"
#include "OnlineSubsystemPicoNames.h"

/// @file OnlineSubsystemPico.h

/** Forward declarations of all interface classes */
//typedef TSharedPtr<class FOnlineSessionPico, ESPMode::ThreadSafe> FOnlineSessionPicoPtr;
//typedef TSharedPtr<class FOnlineProfilePico, ESPMode::ThreadSafe> FOnlineProfilePicoPtr;
//typedef TSharedPtr<class FOnlineUserCloudPico, ESPMode::ThreadSafe> FOnlineUserCloudPicoPtr;
//typedef TSharedPtr<class FOnlineLeaderboardPico, ESPMode::ThreadSafe> FOnlineLeaderboardsPicoPtr;
//typedef TSharedPtr<class FOnlineVoicePico, ESPMode::ThreadSafe> FOnlineVoicePicoPtr;
//typedef TSharedPtr<class FOnlineExternalUIPico, ESPMode::ThreadSafe> FOnlineExternalUIPicoPtr;
//typedef TSharedPtr<class FRTCPicoUserInterface, ESPMode::ThreadSafe> FRTCPicoUserInterfacePtr;
//typedef TSharedPtr<class FOnlineAchievementsPico, ESPMode::ThreadSafe> FOnlineAchievementsPicoPtr;

typedef TSharedPtr<class FOnlineIdentityPico, ESPMode::ThreadSafe> FOnlineIdentityPicoPtr;
typedef TSharedPtr<class FOnlineFriendsPico, ESPMode::ThreadSafe> FOnlineFriendsPicoPtr;

class FOnlineSessionPico;
typedef TSharedPtr<class FOnlineSessionPico, ESPMode::ThreadSafe> FOnlineSessionPicoPtr;

class FRTCPicoUserInterface;

/// @brief OnlineSubsystemPico class inherited from FOnlineSubsystemImpl(Unreal Engine)
class ONLINESUBSYSTEMPICO_API FOnlineSubsystemPico : public FOnlineSubsystemImpl
{
public:
	virtual ~FOnlineSubsystemPico() = default;

    virtual IOnlineSessionPtr GetSessionInterface() const override;

    /// @brief Get friends interface of Pico
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

    /// @brief Get identity interface of Pico
    virtual IOnlineIdentityPtr GetIdentityInterface() const override;
    virtual IOnlineTitleFilePtr GetTitleFileInterface() const override;
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

    // FTickerObjectBase

    virtual bool Tick(float DeltaTime) override;

    //Rtc

    /// @brief Get RTC interface of Pico
    TSharedPtr<FRTCPicoUserInterface> GetRtcUserInterface() const;
    // FOnlineSubsystemPico

    // Game
    FOnlineSessionPicoPtr GetGameSessionInterface() const;


    void AddAsyncTask(ppfRequest RequestId, FPicoMessageOnCompleteDelegate Delegate);

    FPicoMulticastMessageOnCompleteDelegate& GetOrAddNotify(ppfMessageType MessageType) const;

    void RemoveNotifyDelegate(ppfMessageType MessageType, const FDelegateHandle& Delegate) const;

PACKAGE_SCOPE:

    /** Only the factory makes instances */
    FOnlineSubsystemPico() = delete;
    explicit FOnlineSubsystemPico(FName InInstanceName) :
        FOnlineSubsystemImpl(PICO_SUBSYSTEM, InInstanceName),
        bPicoInit(false)
    {}

    bool IsInitialized() const;

private:

    bool bPicoInit;

#if PLATFORM_WINDOWS
    bool InitWithWindowsPlatform() const;
#elif PLATFORM_ANDROID
    bool InitWithAndroidPlatform();
#endif

    /** Interface to the identity registration/auth services */
    FOnlineIdentityPicoPtr IdentityInterface;

    /** Interface for friends */
    FOnlineFriendsPicoPtr FriendsInterface;

    TSharedPtr<FRTCPicoUserInterface> RtcPicoUserInterface;

    FOnlineSessionPicoPtr GameSessionInterface;

    /** Online async task runnable */
    class FOnlineAsyncTaskManagerPico* OnlineAsyncTaskThreadRunnable;

    /** Online async task thread */
    class FRunnableThread* OnlineAsyncTaskThread;

};
namespace FNetworkProtocolTypes
{
    ONLINESUBSYSTEMPICO_API extern const FLazyName Pico;
}

typedef TSharedPtr<FOnlineSubsystemPico, ESPMode::ThreadSafe> FOnlineSubsystemPicoPtr;