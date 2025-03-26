// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
class FOnlineLeaderboardPico;
typedef TSharedPtr<class FOnlineLeaderboardPico, ESPMode::ThreadSafe> FOnlineLeaderboardPicoPtr;
class FOnlineAchievementsPico;
typedef TSharedPtr<class FOnlineAchievementsPico, ESPMode::ThreadSafe> FOnlineAchievementPicoPtr;

class FRTCPicoUserInterface;
class FPicoApplicationInterface;
class FPicoPresenceInterface;
class FApplicationLifecycleInterface;
class FPicoIAPInterface;
class FPicoUserInterface;
class FPicoAssetFileInterface;
class FPicoSportInterface;
class FPicoLeaderboardsInterface;
class FPicoAchievementsInterface;
class FPicoChallengesInterface;
class FPicoRoomInterface;
class FPicoMatchmakingInterface;
class FPicoNotificationInterface;
class FPicoNetworkingInterface;
class FPicoComplianceInterface;
class FPicoSpeechInterface;
class FPicoHighlightInterface;
class FPicoCloudStorageInterface;

/// @brief OnlineSubsystemPico class inherited from FOnlineSubsystemImpl(Unreal Engine)
class ONLINESUBSYSTEMPICO_API FOnlineSubsystemPico : public FOnlineSubsystemImpl
{
public:
    virtual ~FOnlineSubsystemPico() = default;

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


    TSharedPtr<FRTCPicoUserInterface> GetRtcUserInterface() const;

    TSharedPtr<FPicoApplicationInterface> GetApplicationInterface() const;

    TSharedPtr<FApplicationLifecycleInterface> GetApplicationLifecycleInterface() const;

    TSharedPtr<FPicoIAPInterface> GetPicoIAPInterface() const;

    TSharedPtr<FPicoUserInterface> GetPicoUserInterface() const;

    TSharedPtr<FPicoPresenceInterface> GetPicoPresenceInterface() const;

    TSharedPtr<FPicoAssetFileInterface> GetPicoAssetFileInterface() const;

    TSharedPtr<FPicoSportInterface> GetPicoSportInterface() const;


    // Game
    FOnlineSessionPicoPtr GetGameSessionInterface() const;

    TSharedPtr<FPicoAchievementsInterface> GetPicoAchievementsInterface() const;

    TSharedPtr<FPicoLeaderboardsInterface> GetPicoLeaderboardsInterface() const;

    TSharedPtr<FPicoChallengesInterface> GetPicoChallengesInterface() const;

    TSharedPtr<FPicoRoomInterface> GetPicoRoomInterface() const;

    TSharedPtr<FPicoMatchmakingInterface> GetPicoMatchmakingInterface() const;

    TSharedPtr<FPicoNotificationInterface> GetPicoNotificationInterface() const;

    TSharedPtr<FPicoNetworkingInterface> GetPicoNetworkingInterface() const;

    TSharedPtr<FPicoComplianceInterface> GetPicoComplianceInterface() const;

    TSharedPtr<FPicoSpeechInterface> GetPicoSpeechInterface() const;

    TSharedPtr<FPicoHighlightInterface> GetPicoHighlightInterface() const;    
    
    TSharedPtr<FPicoCloudStorageInterface> GetPicoCloudStorageInterface() const;

    /**
     * Allows for the PicoSDK calls to be used directly with the Delegates in the Pico PSS
     */
    void AddAsyncTask(ppfRequest RequestId, FPicoMessageOnCompleteDelegate Delegate);

    //    void AddAsyncTask(ppfRequest RequestId, FPicoMessageOnCompleteDelegate Delegate);

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

    bool GetWindowsDebugInfo(FString& OutJsonString, FString& OutLogPath) const;
#elif PLATFORM_ANDROID
    bool InitWithAndroidPlatform();
#endif

    /** Interface to the identity registration/auth services */
    FOnlineIdentityPicoPtr IdentityInterface;

    /** Interface for friends */
    FOnlineFriendsPicoPtr FriendsInterface;

    TSharedPtr<FRTCPicoUserInterface> RtcPicoUserInterface;

    TSharedPtr<FPicoApplicationInterface> PicoApplicationInterface;

    TSharedPtr<FPicoPresenceInterface> PicoPresenceInterface;

    TSharedPtr<FApplicationLifecycleInterface> PicoApplicationLifecycleInterface;

    TSharedPtr<FPicoIAPInterface> PicoIAPInterface;

    TSharedPtr<FPicoUserInterface> PicoUserInterface;

    TSharedPtr<FPicoAssetFileInterface> PicoAssetFileInterface;

    TSharedPtr<FPicoSportInterface> PicoSportInterface;

    FOnlineSessionPicoPtr GameSessionInterface;

    FOnlineLeaderboardPicoPtr LeaderboardInterface;

    FOnlineAchievementPicoPtr AchievementInterface;

    TSharedPtr<FPicoLeaderboardsInterface> PicoLeaderboardsInterface;

    TSharedPtr<FPicoAchievementsInterface> PicoAchievementsInterface;

    TSharedPtr<FPicoChallengesInterface> PicoChallengesInterface;

    TSharedPtr<FPicoRoomInterface> PicoRoomInterface;

    TSharedPtr<FPicoMatchmakingInterface> PicoMatchmakingInterface;
    
    TSharedPtr<FPicoNotificationInterface> PicoNotificationInterface;

    TSharedPtr<FPicoNetworkingInterface> PicoNetworkingInterface;

    TSharedPtr<FPicoComplianceInterface> PicoComplianceInterface;
    TSharedPtr<FPicoSpeechInterface> PicoSpeechInterface;

    TSharedPtr<FPicoHighlightInterface> PicoHighlightInterface;    

    TSharedPtr<FPicoCloudStorageInterface> PicoCloudStorageInterface;
    /** Online async task runnable */
    class FOnlineAsyncTaskManagerPico* OnlineAsyncTaskThreadRunnable;

};
namespace FNetworkProtocolTypes
{
    ONLINESUBSYSTEMPICO_API extern const FLazyName Pico;
}

typedef TSharedPtr<FOnlineSubsystemPico, ESPMode::ThreadSafe> FOnlineSubsystemPicoPtr;