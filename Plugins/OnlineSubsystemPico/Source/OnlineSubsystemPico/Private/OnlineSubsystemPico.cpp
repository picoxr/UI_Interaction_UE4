// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlineSubsystemPico.h"
#include "OnlineIdentityPico.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "RTCPicoUserInterface.h"
#include "OnlineSessionInterfacePico.h"
#include "PicoPresenceInterface.h"
#include "PicoApplicationInterface.h"
#include "ApplicationLifecycleInterface.h"
#include "Pico_IAP.h"
#include "Pico_User.h"
#include "OnlineLeaderboardInterfacePico.h"
#include "Pico_Sport.h"
#include "Pico_AssetFile.h"
#include "Pico_Achievements.h"
#include "Pico_Leaderboards.h"
#include "Pico_Challenges.h"
#include "Pico_Room.h"
#include "Pico_Networking.h"
#include "Pico_Compliance.h"
#include "Pico_Speech.h"
#include "Pico_Highlight.h"
#include "Pico_CloudStorage.h"

#include "OnlineAchievementsInterfacePico.h"
#include "Pico_Matchmaking.h"
#include "Pico_Notification.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializerMacros.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"

#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#endif


namespace FNetworkProtocolTypes
{
    const FLazyName Pico(TEXT("Pico"));
}

IOnlineSessionPtr FOnlineSubsystemPico::GetSessionInterface() const
{
    return GameSessionInterface;
}

IOnlineFriendsPtr FOnlineSubsystemPico::GetFriendsInterface() const
{
    return FriendsInterface;
}

IOnlinePartyPtr FOnlineSubsystemPico::GetPartyInterface() const
{
    return nullptr;
}

IOnlineGroupsPtr FOnlineSubsystemPico::GetGroupsInterface() const
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
}

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
    return IdentityInterface;
}

IOnlineTitleFilePtr FOnlineSubsystemPico::GetTitleFileInterface() const
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
    return AchievementInterface;
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
TSharedPtr<FRTCPicoUserInterface> FOnlineSubsystemPico::GetRtcUserInterface() const
{
    return RtcPicoUserInterface;
}

TSharedPtr<FPicoApplicationInterface> FOnlineSubsystemPico::GetApplicationInterface() const
{
    return PicoApplicationInterface;
}

TSharedPtr<FApplicationLifecycleInterface> FOnlineSubsystemPico::GetApplicationLifecycleInterface() const
{
    return PicoApplicationLifecycleInterface;
}

TSharedPtr<FPicoIAPInterface> FOnlineSubsystemPico::GetPicoIAPInterface() const
{
    return PicoIAPInterface;
}

TSharedPtr<FPicoUserInterface> FOnlineSubsystemPico::GetPicoUserInterface() const
{
    return PicoUserInterface;
}

TSharedPtr<FPicoPresenceInterface> FOnlineSubsystemPico::GetPicoPresenceInterface() const
{
    return PicoPresenceInterface;
}

TSharedPtr<FPicoSportInterface> FOnlineSubsystemPico::GetPicoSportInterface() const
{
    return PicoSportInterface;
}

TSharedPtr<FPicoAssetFileInterface> FOnlineSubsystemPico::GetPicoAssetFileInterface() const
{
    return PicoAssetFileInterface;
}

FOnlineSessionPicoPtr FOnlineSubsystemPico::GetGameSessionInterface() const
{
    return GameSessionInterface;
}

TSharedPtr<FPicoAchievementsInterface> FOnlineSubsystemPico::GetPicoAchievementsInterface() const
{
    return PicoAchievementsInterface;
}
TSharedPtr<FPicoLeaderboardsInterface> FOnlineSubsystemPico::GetPicoLeaderboardsInterface() const
{
    return PicoLeaderboardsInterface;
}
TSharedPtr<FPicoChallengesInterface> FOnlineSubsystemPico::GetPicoChallengesInterface() const
{
    return PicoChallengesInterface;
}
TSharedPtr<FPicoRoomInterface> FOnlineSubsystemPico::GetPicoRoomInterface() const
{
    return PicoRoomInterface;
}
TSharedPtr<FPicoMatchmakingInterface> FOnlineSubsystemPico::GetPicoMatchmakingInterface() const
{
    return PicoMatchmakingInterface;
}
TSharedPtr<FPicoNotificationInterface> FOnlineSubsystemPico::GetPicoNotificationInterface() const
{
    return PicoNotificationInterface;
}

TSharedPtr<FPicoNetworkingInterface> FOnlineSubsystemPico::GetPicoNetworkingInterface() const
{
    return PicoNetworkingInterface;
}

TSharedPtr<FPicoComplianceInterface> FOnlineSubsystemPico::GetPicoComplianceInterface() const
{
    return PicoComplianceInterface;
}

TSharedPtr<FPicoSpeechInterface> FOnlineSubsystemPico::GetPicoSpeechInterface() const
{
    return PicoSpeechInterface;
}

TSharedPtr<FPicoHighlightInterface> FOnlineSubsystemPico::GetPicoHighlightInterface() const
{
    return PicoHighlightInterface;
}

TSharedPtr<FPicoCloudStorageInterface> FOnlineSubsystemPico::GetPicoCloudStorageInterface() const
{
    return PicoCloudStorageInterface;
}

bool FOnlineSubsystemPico::Init()
{
    if (bPicoInit)
    {
        return bPicoInit;
    }
    bPicoInit = false;
#if PLATFORM_WINDOWS
    bPicoInit = InitWithWindowsPlatform();
#elif PLATFORM_ANDROID
    bPicoInit = InitWithAndroidPlatform();
#endif
    if (bPicoInit)
    {
        // Create the online async task thread
        OnlineAsyncTaskThreadRunnable = new FOnlineAsyncTaskManagerPico(this);
        check(OnlineAsyncTaskThreadRunnable);

        IdentityInterface = MakeShareable(new FOnlineIdentityPico(*this));
        FriendsInterface = MakeShareable(new FOnlineFriendsPico(*this));
        RtcPicoUserInterface = MakeShareable(new FRTCPicoUserInterface(*this));
        PicoPresenceInterface = MakeShareable(new FPicoPresenceInterface(*this));
        PicoApplicationInterface = MakeShareable(new FPicoApplicationInterface(*this));
        PicoApplicationLifecycleInterface = MakeShareable(new FApplicationLifecycleInterface(*this));
        PicoIAPInterface = MakeShareable(new FPicoIAPInterface(*this));
        PicoUserInterface = MakeShareable(new FPicoUserInterface(*this));
        PicoAssetFileInterface = MakeShareable(new FPicoAssetFileInterface(*this));
        PicoSportInterface = MakeShareable(new FPicoSportInterface(*this));

        GameSessionInterface = MakeShareable(new FOnlineSessionPico(*this));
        GameSessionInterface->Uninitialize();
        GameSessionInterface->Initialize();
        LeaderboardInterface = MakeShareable(new FOnlineLeaderboardPico(*this));
        AchievementInterface = MakeShareable(new FOnlineAchievementsPico(*this));
        PicoLeaderboardsInterface = MakeShareable(new FPicoLeaderboardsInterface(*this));
        PicoAchievementsInterface = MakeShareable(new FPicoAchievementsInterface(*this));
        PicoChallengesInterface = MakeShareable(new FPicoChallengesInterface(*this));
        PicoRoomInterface = MakeShareable(new FPicoRoomInterface(*this));
        PicoMatchmakingInterface = MakeShareable(new FPicoMatchmakingInterface(*this));
        PicoNotificationInterface = MakeShareable(new FPicoNotificationInterface(*this));
        PicoNetworkingInterface = MakeShareable(new FPicoNetworkingInterface(*this));
        PicoComplianceInterface = MakeShareable(new FPicoComplianceInterface(*this));
        PicoSpeechInterface = MakeShareable(new FPicoSpeechInterface(*this));
        PicoHighlightInterface = MakeShareable(new FPicoHighlightInterface(*this));
        PicoCloudStorageInterface = MakeShareable(new FPicoCloudStorageInterface(*this));
#if WITH_EDITOR
        StartTicker();
#endif
    }
    else
    {
        FOnlineSubsystemImpl::Shutdown();
    }
    return bPicoInit;
}

bool FOnlineSubsystemPico::Shutdown()
{
    UE_LOG_ONLINE(Display, TEXT("FOnlineSubsystemPico::Shutdown()"));

    FOnlineSubsystemImpl::Shutdown();
    RtcPicoUserInterface.Reset();
    PicoPresenceInterface.Reset();
    PicoApplicationInterface.Reset();
    PicoApplicationLifecycleInterface.Reset();
    FriendsInterface.Reset();
    IdentityInterface.Reset();
    PicoIAPInterface.Reset();
    PicoUserInterface.Reset();
    GameSessionInterface.Reset();
    LeaderboardInterface.Reset();
    AchievementInterface.Reset();
    PicoAssetFileInterface.Reset();
    PicoSportInterface.Reset();
    PicoAchievementsInterface.Reset();
    PicoLeaderboardsInterface.Reset();
    PicoChallengesInterface.Reset();
    PicoRoomInterface.Reset();
    PicoMatchmakingInterface.Reset();
    PicoNotificationInterface.Reset();
    PicoNetworkingInterface.Reset();
    PicoComplianceInterface.Reset();
    PicoSpeechInterface.Reset();
    PicoHighlightInterface.Reset();
    PicoCloudStorageInterface.Reset();
    if (OnlineAsyncTaskThreadRunnable)
    {
        delete OnlineAsyncTaskThreadRunnable;
        OnlineAsyncTaskThreadRunnable = nullptr;
    }
    bPicoInit = false;
#if PLATFORM_WINDOWS    
    ppf_PcUnInitialize();
#endif
    return true;
}

FString FOnlineSubsystemPico::GetAppId() const
{
    FString AppID = GConfig->GetStr(TEXT("OnlineSubsystemPico"), TEXT("PicoAppId"), GEngineIni);
    if (AppID.IsEmpty())
    {
        AppID = GConfig->GetStr(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("AppID"), GEngineIni);
    }
    return AppID;
}

bool FOnlineSubsystemPico::Exec(class UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
    return false;
}

FText FOnlineSubsystemPico::GetOnlineServiceName() const
{
    return NSLOCTEXT("OnlineSubsystemPico", "OnlineServiceName", "Pico Platform");
}

bool FOnlineSubsystemPico::Tick(float DeltaTime)
{
    QUICK_SCOPE_CYCLE_COUNTER(STAT_FOnlineSubsystemPico_Tick);

    if (!FOnlineSubsystemImpl::Tick(DeltaTime))
    {
        return false;
    }
    if (GameSessionInterface.IsValid())
    {
        GameSessionInterface->TickPendingInvites(DeltaTime);
    }

    if (OnlineAsyncTaskThreadRunnable)
    {
        OnlineAsyncTaskThreadRunnable->TickTask();
    }
    return true;
}



void FOnlineSubsystemPico::AddAsyncTask(ppfRequest RequestId, FPicoMessageOnCompleteDelegate Delegate)
{
    check(OnlineAsyncTaskThreadRunnable);
    if (RequestId == 0)
    {  
        UE_LOG_ONLINE(Error, TEXT("Wrong request id!"));
        return;
    }
    FOnlineAsyncTaskPico* NewTask = new FOnlineAsyncTaskPico(this, RequestId, Delegate);
    OnlineAsyncTaskThreadRunnable->CollectedRequestTask(RequestId, NewTask);
}


FPicoMulticastMessageOnCompleteDelegate& FOnlineSubsystemPico::GetOrAddNotify(ppfMessageType MessageType) const
{
    check(OnlineAsyncTaskThreadRunnable);
    return OnlineAsyncTaskThreadRunnable->GetOrAddNotifyDelegate(MessageType);
}

void FOnlineSubsystemPico::RemoveNotifyDelegate(ppfMessageType MessageType, const FDelegateHandle& Delegate) const
{
    check(OnlineAsyncTaskThreadRunnable);
    return OnlineAsyncTaskThreadRunnable->RemoveNotifyDelegate(MessageType, Delegate);
}

bool FOnlineSubsystemPico::IsInitialized() const
{
    return bPicoInit;
}

#if PLATFORM_WINDOWS
bool FOnlineSubsystemPico::InitWithWindowsPlatform() const
{
    UE_LOG_ONLINE(Display, TEXT("FOnlineSubsystemPico::InitWithWindowsPlatform()"));
    auto PicoAppId = GetAppId();
    if (PicoAppId.IsEmpty())
    {
        UE_LOG_ONLINE(Display, TEXT("Missing PicoAppId key in [OnlineSubsystemPico] of DefaultEngine.ini"));
        return false;
    }
    FString DebugInfo;
    FString WindowsDebugLogPath;
    if (!GetWindowsDebugInfo(DebugInfo, WindowsDebugLogPath))
    {
        UE_LOG_ONLINE(Display, TEXT("The windows debug profile is not set correctly!"));
        return false;
    }
    //return false;
    auto InitResult = ppf_PcInitWrapper(TCHAR_TO_UTF8(*PicoAppId), TCHAR_TO_UTF8(*DebugInfo), TCHAR_TO_UTF8(*WindowsDebugLogPath));
    if (InitResult != ppfPlatformInitializeResult_Success)
    {
        UE_LOG_ONLINE(Warning, TEXT("Failed to initialize Pico Platform SDK! Error code: %d"), (int)InitResult);
        return false;
    }
    UE_LOG_ONLINE(Log, TEXT("Pico Platform SDK initialize success!"));
    return true;
}

bool FOnlineSubsystemPico::GetWindowsDebugInfo(FString& OutJsonString, FString& OutLogPath) const
{
    FString BaseDir = IPluginManager::Get().FindPlugin("OnlineSubsystemPico")->GetBaseDir();
    OutLogPath = BaseDir + TEXT("/WindowsDebug/");
    FString ConfigFilePath = BaseDir + TEXT("/WindowsDebug/PicoWindowConfig.json");
    if (FFileHelper::LoadFileToString(OutJsonString, *ConfigFilePath))
    {
        TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(OutJsonString);
        if (FJsonSerializer::Deserialize(Reader, RootObject))
        {
            FString Region, AccessToken, PackageName, PackageVersionName;
            int32 PackageVersionCode;
            const TSharedPtr<FJsonObject>* GeneralObj;
            if (!RootObject->TryGetObjectField(TEXT("general"), GeneralObj))
            {
                return false;
            }
            if (!(*GeneralObj)->TryGetStringField(TEXT("region"), Region))
            {
                return false;
            }
            const TSharedPtr<FJsonObject>* AccountObj;
            if (!RootObject->TryGetObjectField(TEXT("account"), AccountObj))
            {
                return false;
            }
            if (!(*AccountObj)->TryGetStringField(TEXT("access_token"), AccessToken))
            {
                return false;
            }
            const TSharedPtr<FJsonObject>* PackageObj;
            if (!RootObject->TryGetObjectField(TEXT("package"), PackageObj))
            {
                return false;
            }
            if (!(*PackageObj)->TryGetStringField(TEXT("package_name"), PackageName))
            {
                return false;
            }
            if (!(*PackageObj)->TryGetStringField(TEXT("package_version_name"), PackageVersionName))
            {
                return false;
            }
            if (!(*PackageObj)->TryGetNumberField(TEXT("package_version_code"), PackageVersionCode))
            {
                return false;
            }
            if (Region.IsEmpty() || AccessToken.IsEmpty() || PackageVersionName.IsEmpty() || PackageName.IsEmpty())
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

#elif PLATFORM_ANDROID
bool FOnlineSubsystemPico::InitWithAndroidPlatform()
{
    UE_LOG_ONLINE(Display, TEXT("FOnlineSubsystemPico::InitWithAndroidPlatform()"));
    auto PicoAppId = GetAppId();
    if (PicoAppId.IsEmpty())
    {
        UE_LOG_ONLINE(Error, TEXT("Missing PicoAppId key in [OnlineSubsystemPico] of DefaultEngine.ini"));
        return false;
    }

    JNIEnv* Env = FAndroidApplication::GetJavaEnv();

    if (Env == nullptr)
    {
        UE_LOG_ONLINE(Error, TEXT("JNIEnv Error"));
        return false;
    }
    jobject UseJob = FAndroidApplication::GetGameActivityThis();

    auto InitResult = ppf_InitializeAndroid(TCHAR_TO_ANSI(*PicoAppId), UseJob, Env);
    if (InitResult != ppfPlatformInitializeResult_Success)
    {
        UE_LOG_ONLINE(Error, TEXT("Failed to initialize Pico Platform SDK! Error code: %d"), (int)InitResult);
        return false;
    }
    UE_LOG_ONLINE(Log, TEXT("Pico Platform SDK initialize success!"));
    return true;
}

#endif