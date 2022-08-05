// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#include "OnlineSubsystemPico.h"
#include "OnlineIdentityPico.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "RTCPicoUserInterface.h"
#include "OnlineSessionInterfacePico.h"

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
	return nullptr;
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
	return nullptr;
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
FOnlineSessionPicoPtr FOnlineSubsystemPico::GetGameSessionInterface() const
{
    return GameSessionInterface;
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
        OnlineAsyncTaskThread = FRunnableThread::Create(OnlineAsyncTaskThreadRunnable, *FString::Printf(TEXT("OnlineAsyncTaskThreadPico %s"), *InstanceName.ToString()), 128 * 1024, TPri_Normal);
        check(OnlineAsyncTaskThread);
        UE_LOG_ONLINE(Verbose, TEXT("Created thread (ID:%d)."), OnlineAsyncTaskThread->GetThreadID());

		IdentityInterface = MakeShareable(new FOnlineIdentityPico(*this));
        FriendsInterface = MakeShareable(new FOnlineFriendsPico(*this));
        RtcPicoUserInterface = MakeShareable(new FRTCPicoUserInterface(*this));
        GameSessionInterface = MakeShareable(new FOnlineSessionPico(*this));
        GameSessionInterface->Uninitialize();
        GameSessionInterface->Initialize();
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
    FriendsInterface.Reset();
    IdentityInterface.Reset();
    GameSessionInterface.Reset();

    if (OnlineAsyncTaskThread)
    {
        // Destroy the online async task thread
        delete OnlineAsyncTaskThread;
        OnlineAsyncTaskThread = nullptr;
    }

    if (OnlineAsyncTaskThreadRunnable)
    {
        delete OnlineAsyncTaskThreadRunnable;
        OnlineAsyncTaskThreadRunnable = nullptr;
    }

    bPicoInit = false;

    return true;
}

FString FOnlineSubsystemPico::GetAppId() const
{
    return GConfig->GetStr(TEXT("OnlineSubsystemPico"), TEXT("PicoAppId"), GEngineIni);
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

    if (OnlineAsyncTaskThreadRunnable)
    {
        OnlineAsyncTaskThreadRunnable->GameTick();
    }
    return true;
}



void FOnlineSubsystemPico::AddAsyncTask(ppfRequest RequestId, FPicoMessageOnCompleteDelegate Delegate)
{
    check(OnlineAsyncTaskThreadRunnable);
    FOnlineAsyncTaskPico* NewTask = new FOnlineAsyncTaskPico(this, RequestId, Delegate);
    OnlineAsyncTaskThreadRunnable->CollectedRequestTask(RequestId, NewTask);
    OnlineAsyncTaskThreadRunnable->AddToInQueue(NewTask);
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
	return true;
}

#elif PLATFORM_ANDROID
bool FOnlineSubsystemPico::InitWithAndroidPlatform()
{
	UE_LOG_ONLINE(Display, TEXT("FOnlineSubsystemPico::InitWithAndroidPlatform()"));
	auto PicoAppId = GetAppId();
    if (PicoAppId.IsEmpty())
    {
        UE_LOG_ONLINE(Error, TEXT("Missing PicoAppId key in OnlineSubsystemPico of DefaultEngine.ini"));
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
    return true;
}

#endif