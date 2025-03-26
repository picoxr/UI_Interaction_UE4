// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "OnlinePicoFunctionLibrary.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystem.h"
#include "OnlinePicoSettings.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPicoManager.h"
#include "Interfaces/OnlineLeaderboardInterface.h"
#include "OnlineSessionInterfacePico.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "OnlineSubsystemPicoTypes.h"
#include "PICOPlatformSubsystem.h"
#include "Subsystems/SubsystemBlueprintLibrary.h"
#include "OnlineIdentityPico.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif



UOnlineSubsystemPicoManager* UOnlinePicoFunctionLibrary::PicoSubsystemManager = nullptr;
UObject* UOnlinePicoFunctionLibrary::World = nullptr;
UOnlinePicoFunctionLibrary::UOnlinePicoFunctionLibrary()
{
}

void UOnlinePicoFunctionLibrary::PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->PicoReadFriendList(WorldContextObject, LocalUserNum, ListName, InReadFriendListDelegate);
    }
}

void UOnlinePicoFunctionLibrary::PicoGetFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, TArray<FPicoUserInfo>& OutFriends)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->PicoGetFriendList(WorldContextObject, LocalUserNum, ListName, OutFriends);
    }
}

FPicoUserInfo UOnlinePicoFunctionLibrary::PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName)
{
    FPicoUserInfo NewFriend;
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        NewFriend = GetOnlineSubsystemPicoManager(WorldContextObject)->PicoGetFriend(WorldContextObject, LocalUserNum, FriendId, ListName);
    }
    return NewFriend;
}

ERtcEngineInitResult UOnlinePicoFunctionLibrary::PicoGetRtcEngineInit(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PicoRtcEngineInit(WorldContextObject);
    }
    return ERtcEngineInitResult::None;
}

UOnlineSubsystemPicoManager* UOnlinePicoFunctionLibrary::GetOnlineSubsystemPicoManager(UObject* WorldContextObject)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    check(Subsystem);
    UPICOPlatformSubsystem* System = CastChecked<UPICOPlatformSubsystem>(USubsystemBlueprintLibrary::GetGameInstanceSubsystem(WorldContextObject, UPICOPlatformSubsystem::StaticClass()), ECastCheckedType::NullChecked);
    // If System is nullptr, please check you game instance. Whether the initialization function of the parent class is called(Super::Init()).
    return System->ConstructPicoManager();
}


bool UOnlinePicoFunctionLibrary::ParseErrorInfo(FString InErrorMessage, int32& ErrorCode)
{
    ErrorCode = -1;
    int32 ErrorCodeStart = InErrorMessage.Find(TEXT("Error Code: "));
    if (ErrorCodeStart == -1)
    {
        return false;
    }
    FString ErrorCodeStr = InErrorMessage.RightChop(ErrorCodeStart + 12);
    ErrorCode = FCString::Atoi(*ErrorCodeStr);
    return true;
}

void UOnlinePicoFunctionLibrary::FindFileOrForder(TArray<FString>& OutFindArray, const FString& FindName, const FString& FindPath, bool IsFile /*= false*/, bool IsInDirectories /*= true*/)
{
    OutFindArray.Empty();
    class FFileMatch : public IPlatformFile::FDirectoryVisitor
    {
    public:
        TArray<FString>& Result;
        FString WildCard;
        bool bFiles;
        bool bDirectories;
        FFileMatch(TArray<FString>& InResult, const FString& InWildCard, bool bInFiles, bool bInDirectories)
            : Result(InResult)
            , WildCard(InWildCard)
            , bFiles(bInFiles)
            , bDirectories(bInDirectories)
        {
        }
        virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
        {
            if (!bDirectories && bIsDirectory)
            {
                return false;
            }
            if (((bIsDirectory && bDirectories) || (!bIsDirectory && bFiles))
                && FPaths::GetCleanFilename(FilenameOrDirectory).MatchesWildcard(WildCard))
            {
                FString LongPackageName;
                Result.Add(FilenameOrDirectory);
            }
            return true;
        }
    };
    const FString CleanFilename = TEXT("*") + FindName;
    FFileMatch FileMatch(OutFindArray, CleanFilename, IsFile, IsInDirectories);

    IFileManager::Get().IterateDirectoryRecursively(*FindPath, FileMatch);
}

void UOnlinePicoFunctionLibrary::PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& UserId, const FString& InToken, const FString& InType, FOnlineManagerLoginCompleteDelegate InLoginComleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->PicoLogin(WorldContextObject, LocalUserNum, UserId, InType, InToken, InLoginComleteDelegate);
    }
}


void UOnlinePicoFunctionLibrary::PicoGetOpenIDToken(UObject* WorldContextObject, FGetIDToken OnGetIdTokenComplete)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetIdentityInterface())
    {
        TSharedPtr<FOnlineIdentityPico, ESPMode::ThreadSafe> IdentityInterfacePicoPtr = StaticCastSharedPtr<FOnlineIdentityPico>(Subsystem->GetIdentityInterface());
        if (IdentityInterfacePicoPtr.IsValid())
        {
            IdentityInterfacePicoPtr->GetLoginUserOpenID(OnGetIdTokenComplete);
            return;
        }
    }
    else
    {
        OnGetIdTokenComplete.ExecuteIfBound(true, FString(), FString());
    }

}

FString UOnlinePicoFunctionLibrary::PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum)
{
    FString NickName = FString();
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        NickName = GetOnlineSubsystemPicoManager(WorldContextObject)->PicoGetNickName(WorldContextObject, LocalUserNum);
    }
    return NickName;
}

UPico_User* UOnlinePicoFunctionLibrary::GetLoginPicoUser(UObject* WorldContextObject, int32 LocalUserNum)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetLoginPicoUser(WorldContextObject, LocalUserNum);
    }
    return nullptr;
}

void UOnlinePicoFunctionLibrary::PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->PicoRtcGetToken(WorldContextObject, UserId, RoomId, Ttl, InValue, InRtcGetTokenDelegate);
    }
}

int UOnlinePicoFunctionLibrary::PicoRtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->RtcJoinRoom(WorldContextObject, RoomId, UserId, Token, UserExtra, InRoomProfileType, bIsAutoSubscribeAudio);
    }
    return 999;
}

int UOnlinePicoFunctionLibrary::RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->RtcDestroyRoom(WorldContextObject, RoomId);
    }
    return 999;
}

void UOnlinePicoFunctionLibrary::RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcEnableAudioPropertiesReport(WorldContextObject, Interval);
    }
}

int UOnlinePicoFunctionLibrary::RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->RtcLeaveRoom(WorldContextObject, RoomId);
    }
    return 999;
}

void UOnlinePicoFunctionLibrary::RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcMuteLocalAudio(WorldContextObject, InRtcMuteState);
    }
}

void UOnlinePicoFunctionLibrary::RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcPublishRoom(WorldContextObject, RoomId);
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcRoomPauseAllSubscribedStream(WorldContextObject, RoomId, InPauseResumeMediaType);
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcRoomResumeAllSubscribedStream(WorldContextObject, RoomId, InPauseResumeMediaType);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetAudioPlaybackDevice(WorldContextObject, InRtcAudioPlaybackDevice);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetAudioScenario(WorldContextObject, InRtcAudioScenarioType);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetCaptureVolume(WorldContextObject, InRtcStreamIndex, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetEarMonitorMode(WorldContextObject, InRtcEarMonitorMode);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetEarMonitorVolume(WorldContextObject, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcSetPlaybackVolume(WorldContextObject, InVolume);
    }
}

void UOnlinePicoFunctionLibrary::RtcStartAudioCapture(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcStartAudioCapture(WorldContextObject);
    }
}

void UOnlinePicoFunctionLibrary::RtcStopAudioCapture(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcStopAudioCapture(WorldContextObject);
    }
}

void UOnlinePicoFunctionLibrary::RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcUnPublishRoom(WorldContextObject, RoomId);
    }
}

void UOnlinePicoFunctionLibrary::RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->RtcUpdateToken(WorldContextObject, RoomId, Token);
    }
}

int32 UOnlinePicoFunctionLibrary::RtcSendStreamSyncInfo(UObject* WorldContextObject, int32 Info, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendStreamSyncInfo"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendStreamSyncInfo(Info, InStreamIndex, RepeatCount, InSyncInfoStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendStreamSyncInfo Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int32 UOnlinePicoFunctionLibrary::RtcSendStreamSyncBytesInfo(UObject* WorldContextObject, TArray<uint8> Bytes, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendStreamSyncBytesInfo"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendStreamSyncInfo(Bytes, InStreamIndex, RepeatCount, InSyncInfoStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendStreamSyncBytesInfo Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomPublishStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomPublishStream(RoomId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomPublishStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomSetRemoteAudioPlaybackVolume(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, int32 Volume)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomSetRemoteAudioPlaybackVolume"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomSetRemoteAudioPlaybackVolume(RoomId, UserId, Volume);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomSetRemoteAudioPlaybackVolume Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomSubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomSubscribeStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomSubscribeStream(RoomId, UserId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomSubscribeStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomUnPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomUnPublishStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomUnPublishStream(RoomId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomUnPublishStream Failed, RtcUserInterface Not Vailed!"));
    }
}

void UOnlinePicoFunctionLibrary::RtcRoomUnsubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcRoomUnsubscribeStream"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        Subsystem->GetRtcUserInterface()->RtcRoomUnsubscribeStream(RoomId, UserId, InRtcMediaStreamType);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcRoomUnsubscribeStream Failed, RtcUserInterface Not Vailed!"));
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendRoomBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& MessageInfo)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendRoomBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendRoomBinaryMessage(RoomId, MessageInfo);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendRoomBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendRoomBytesBinaryMessage(UObject* WorldContextObject, const FString& RoomId, TArray<uint8> Bytes)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendRoomBytesBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendRoomBinaryMessage(RoomId, Bytes);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendRoomBytesBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendRoomMessage(UObject* WorldContextObject, const FString& RoomId, const FString& Message)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendRoomMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendRoomMessage(RoomId, Message);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendRoomMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendUserBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& MessageInfo)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendUserBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendUserBinaryMessage(RoomId, UserId, MessageInfo);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendUserBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendUserBytesBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, TArray<uint8> Bytes)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendUserBytesBinaryMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendUserBinaryMessage(RoomId, UserId, Bytes);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendUserBytesBinaryMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

int64 UOnlinePicoFunctionLibrary::RtcSendUserMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Message)
{
    UE_LOG_ONLINE(Log, TEXT("UOnlinePicoFunctionLibrary::RtcSendUserMessage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetRtcUserInterface())
    {
        return Subsystem->GetRtcUserInterface()->RtcSendUserMessage(RoomId, UserId, Message);
    }
    else
    {
        UE_LOG_ONLINE(Log, TEXT("RtcSendUserMessage Failed, RtcUserInterface Not Vailed!"));
        return -1;
    }
}

// Game
bool UOnlinePicoFunctionLibrary::IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    bool Valid = UpdatedSessionSettings.ValueArray.Num() == UpdatedSessionSettings.KeyArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSettingsDataStoreValid keys count != values count"));
    }
    return Valid;
}

bool UOnlinePicoFunctionLibrary::IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& SessionSearch)
{
    bool Valid = SessionSearch.QuerySettingsKeyArray.Num() == SessionSearch.QuerySettingsValueArray.Num();
    if (!Valid)
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME IsInputSessionSearchQueryDataValid keys count != values count"));
    }
    return Valid;
}

FOnlineSessionSettings UOnlinePicoFunctionLibrary::GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings)
{
    FOnlineSessionSettings SessionSettings;
    SessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    SessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    SessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    SessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    SessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    SessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    SessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    if (UpdatedSessionSettings.ValueArray.Num() != UpdatedSessionSettings.KeyArray.Num())
    {
        UE_LOG_ONLINE(Error, TEXT("PPF_GAME GetOnlineSessionSettings keys count != values count"));
        return SessionSettings;
    }
    for (int i = 0; i < UpdatedSessionSettings.KeyArray.Num(); i++)
    {
        FName Key = FName(*UpdatedSessionSettings.KeyArray[i]);
        FString Value = UpdatedSessionSettings.ValueArray[i];
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME GetOnlineSessionSettings Key: %s, Value: %s"), *UpdatedSessionSettings.KeyArray[i], *Value);
        SessionSettings.Settings.Add(Key, Value);
    }
    return SessionSettings;
}

FPicoOnlineSessionSettings UOnlinePicoFunctionLibrary::GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings)
{
    FPicoOnlineSessionSettings SessionSettings;
    SessionSettings.NumPublicConnections = UpdatedSessionSettings.NumPublicConnections;
    SessionSettings.NumPrivateConnections = UpdatedSessionSettings.NumPrivateConnections;
    SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    SessionSettings.bAllowInvites = UpdatedSessionSettings.bAllowInvites;
    SessionSettings.bUsesPresence = UpdatedSessionSettings.bUsesPresence;
    SessionSettings.bAllowJoinViaPresence = UpdatedSessionSettings.bAllowJoinViaPresence;
    SessionSettings.bAllowJoinViaPresenceFriendsOnly = UpdatedSessionSettings.bAllowJoinViaPresenceFriendsOnly;
    SessionSettings.BuildUniqueId = UpdatedSessionSettings.BuildUniqueId;
    for (auto& item : UpdatedSessionSettings.Settings)
    {
        SessionSettings.KeyArray.Add(*item.Key.ToString());
        SessionSettings.ValueArray.Add(*item.Value.Data.ToString());
    };
    return SessionSettings;
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::GetPicoOnlineSession(const FNamedOnlineSession& Session)
{
    FPicoNamedOnlineSession PicoSession;
    PicoSession.bHosting = Session.bHosting;
    PicoSession.SessionName = Session.SessionName.ToString();
    PicoSession.SessionSettings = GetPicoOnlineSessionSettings(Session.SessionSettings);
    PicoSession.SessionState = (EOnlineSessionStatePicoType)Session.SessionState;
    PicoSession.HostingPlayerNum = Session.HostingPlayerNum;
    if (Session.LocalOwnerId.IsValid())
    {
        PicoSession.LocalOwnerId = *Session.LocalOwnerId->ToString();
    }
    if (Session.OwningUserId.IsValid())
    {
        PicoSession.OwningUserId = *Session.OwningUserId->ToString();
    }
    PicoSession.OwningUserName = Session.OwningUserName;
    PicoSession.NumOpenPrivateConnections = Session.NumOpenPrivateConnections;
    PicoSession.NumOpenPublicConnections = Session.NumOpenPublicConnections;
    if (Session.SessionInfo.IsValid())
    {
        auto SessionInfoPtr = static_cast<const FOnlineSessionInfoPico*>(Session.SessionInfo.Get());
        PicoSession.SessionInfoRoomID = SessionInfoPtr->GetSessionId().ToString();
    }
    PicoSession.RegisteredPlayers.Reset();
    for (int i = 0; i < Session.RegisteredPlayers.Num(); i++)
    {
        //if (Session.RegisteredPlayers[i].IsValid()) // todo
        {
            PicoSession.RegisteredPlayers.Add(Session.RegisteredPlayers[i]->ToString());
        }
    }
    return PicoSession;
}

FOnlineSession UOnlinePicoFunctionLibrary::GetOnlineSession(const FPicoOnlineSession& PicoSession)
{
    FOnlineSession Session;
    Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(FCString::Strtoui64(*PicoSession.SessionInfoRoomID, NULL, 10)));
    Session.SessionSettings = GetOnlineSessionSettings(PicoSession.SessionSettings);
#if ENGINE_MAJOR_VERSION > 4
    Session.OwningUserId = FUniqueNetIdPico::Create(PicoSession.OwningUserId);
#elif ENGINE_MINOR_VERSION > 26
    Session.OwningUserId = FUniqueNetIdPico::Create(PicoSession.OwningUserId);
#elif ENGINE_MINOR_VERSION > 24
    Session.OwningUserId = MakeShareable(new FUniqueNetIdPico(PicoSession.OwningUserId));
#endif
    Session.OwningUserName = PicoSession.OwningUserName;
    Session.NumOpenPrivateConnections = PicoSession.NumOpenPrivateConnections;
    Session.NumOpenPublicConnections = PicoSession.NumOpenPublicConnections;
    return Session;
}

bool UOnlinePicoFunctionLibrary::IsGameInitSuccess(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->IsGameInitSuccess(WorldContextObject);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GameInitialize(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GameInitialize(WorldContextObject);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GameUninitialize(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GameUninitialize(WorldContextObject);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        if (!IsInputSessionSettingsDataStoreValid(NewSessionSettings))
        {
            return false;
        }
        auto SessionSettings = GetOnlineSessionSettings(NewSessionSettings);
        return GetOnlineSubsystemPicoManager(WorldContextObject)->CreateSession(WorldContextObject, HostingPlayerNum, SessionName, SessionSettings, OnCreateSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->StartSession(WorldContextObject, SessionName, OnStartSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::UpdateSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        if (!IsInputSessionSettingsDataStoreValid(UpdatedSessionSettings))
        {
            return false;
        }
        auto SessionSettings = GetOnlineSessionSettings(UpdatedSessionSettings);
        return GetOnlineSubsystemPicoManager(WorldContextObject)->UpdateSession(WorldContextObject, SessionName, SessionSettings, OnUpdateSessionCompleteDelegate, bShouldRefreshOnlineData);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->EndSession(WorldContextObject, SessionName, OnEndSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->DestroySession(WorldContextObject, SessionName, OnDestroySessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FString& UniqueId)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto NetId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(UniqueId).ToSharedRef();
        return GetOnlineSubsystemPicoManager(WorldContextObject)->IsPlayerInSession(WorldContextObject, SessionName, NetId.Get());
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::StartMatchmaking(UObject* WorldContextObject, const TArray<FString>& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {


        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        TArray<TSharedRef<const FUniqueNetId>> GameLocalPlayers;
        for (int i = 0; i < LocalPlayers.Num(); i++)
        {
            auto UniqueNetIdRef = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(LocalPlayers[i]).ToSharedRef();
            GameLocalPlayers.Add(UniqueNetIdRef);
        }
        return GetOnlineSubsystemPicoManager(WorldContextObject)->StartMatchmaking(WorldContextObject, GameLocalPlayers, SessionName, NewSessionSettings, NewSessionSearch, OnMatchmakingCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::CancelMatchmaking(UObject* WorldContextObject, int SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->CancelMatchmaking(WorldContextObject, SearchingPlayerNum, SessionName, OnCancelMatchmakingCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->FindSessions(WorldContextObject, SearchingPlayerNum, NewSessionSearch, OnFindSessionCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::FindSessionById(UObject* WorldContextObject, const FString& SearchingUserId, const FString& SessionId, FPicoManagerOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto SearchingUserIdPtr = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(SearchingUserId).ToSharedRef();
        auto SessionIdIdPtr = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(SessionId).ToSharedRef();
#if ENGINE_MAJOR_VERSION > 4
        FUniqueNetIdStringRef FriendId = FUniqueNetIdString::Create(FString(), FName("PicoSubsystem"));
        return GetOnlineSubsystemPicoManager(WorldContextObject)->FindSessionById(WorldContextObject, SearchingUserIdPtr.Get(), SessionIdIdPtr.Get(), FriendId.Get(), OnSingleSessionResultCompleteDelegate);
#elif ENGINE_MINOR_VERSION > 24
        FUniqueNetIdString FriendId = FUniqueNetIdString();
        return GetOnlineSubsystemPicoManager(WorldContextObject)->FindSessionById(WorldContextObject, SearchingUserIdPtr.Get(), SessionIdIdPtr.Get(), FriendId, OnSingleSessionResultCompleteDelegate);
#endif

    }
    return false;
}

bool UOnlinePicoFunctionLibrary::JoinSession(UObject* WorldContextObject, int PlayerNum, FName SessionName, const FPicoOnlineSessionSearchResult& SearchResult, FPicoManagerOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        auto newSession = SearchResult.Session;
        FOnlineSessionSearchResult newResult;
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto OwningUserId = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(newSession.OwningUserId).ToSharedRef();
        newResult.Session.OwningUserId = OwningUserId;
        newResult.Session.OwningUserName = newSession.OwningUserName;
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME FunctionLibrary JoinSession RoomID: %s"), *newSession.SessionInfoRoomID);
        ppfID RoomID = FCString::Strtoui64(*newSession.SessionInfoRoomID, NULL, 10);
        UE_LOG_ONLINE(Display, TEXT("PPF_GAME FunctionLibrary JoinSession RoomID: %llu"), RoomID);
        newResult.Session.SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomID));
        newResult.Session.SessionSettings = GetOnlineSessionSettings(newSession.SessionSettings);
        newResult.Session.NumOpenPrivateConnections = newSession.NumOpenPrivateConnections;
        newResult.Session.NumOpenPublicConnections = newSession.NumOpenPublicConnections;
        newResult.PingInMs = SearchResult.PingInMs;
        return GetOnlineSubsystemPicoManager(WorldContextObject)->JoinSession(WorldContextObject, PlayerNum, SessionName, newResult, OnJoinSessionCompleteDelegate);
    }
    return false;
}

void UOnlinePicoFunctionLibrary::DumpSessionState(UObject* WorldContextObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->DumpSessionState(WorldContextObject);
    }
}

EOnlineSessionStatePicoType UOnlinePicoFunctionLibrary::GetSessionState(UObject* WorldContextObject, FName SessionName)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return (EOnlineSessionStatePicoType)GetOnlineSubsystemPicoManager(WorldContextObject)->GetSessionState(WorldContextObject, SessionName);
    }
    return EOnlineSessionStatePicoType::NoSession;
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::GetNamedSession(UObject* WorldContextObject, FName SessionName)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        auto SessionPtr = GetOnlineSubsystemPicoManager(WorldContextObject)->GetNamedSession(WorldContextObject, SessionName);
        if (SessionPtr == nullptr)
            return FPicoNamedOnlineSession();
        return GetPicoOnlineSession(*SessionPtr);
    }
    return FPicoNamedOnlineSession();
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::AddNamedSessionBySettings(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& SessionSettings)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetPicoOnlineSession(*GetOnlineSubsystemPicoManager(WorldContextObject)->AddNamedSession(WorldContextObject, SessionName, GetOnlineSessionSettings(SessionSettings)));
    }
    return FPicoNamedOnlineSession();
}

FPicoNamedOnlineSession UOnlinePicoFunctionLibrary::AddNamedSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSession& Session)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetPicoOnlineSession(*GetOnlineSubsystemPicoManager(WorldContextObject)->AddNamedSession(WorldContextObject, SessionName, GetOnlineSession(Session)));
    }
    return FPicoNamedOnlineSession();
}

FPicoOnlineSessionSettings UOnlinePicoFunctionLibrary::GetSessionSettings(UObject* WorldContextObject, FName SessionName)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        FOnlineSessionSettings* Settings = GetOnlineSubsystemPicoManager(WorldContextObject)->GetSessionSettings(WorldContextObject, SessionName);
        return GetPicoOnlineSessionSettings(*Settings);
    }
    return FPicoOnlineSessionSettings();
}

bool UOnlinePicoFunctionLibrary::SendSessionInviteToFriend(UObject* WorldContextObject, int32 LocalUserNum, FName SessionName, const FString& Friend)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        auto ID = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Friend).ToSharedRef();
        return GetOnlineSubsystemPicoManager(WorldContextObject)->SendSessionInviteToFriend(WorldContextObject, LocalUserNum, SessionName, ID.Get());
    }
    return false;
}

// Presence
bool UOnlinePicoFunctionLibrary::PresenceClear(UObject* WorldContextObject, FOnlineManagerPresenceClearDelegate InPresenceClearDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceClear(WorldContextObject, InPresenceClearDelegate);
    }
    return false;
}

void UOnlinePicoFunctionLibrary::ReadInvitableUser(UObject* WorldContextObject, TArray<FString> SuggestedUserList, FOnlineManagerPresenceReadInvitableUserDelegate InReadInvitableUserDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        GetOnlineSubsystemPicoManager(WorldContextObject)->ReadInvitableUser(WorldContextObject, SuggestedUserList, InReadInvitableUserDelegate);
    }
}

bool UOnlinePicoFunctionLibrary::GetInvitableFriendList(UObject* WorldContextObject, TArray<FPicoUserInfo>& OutFriendsList)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetInvitableFriendList(WorldContextObject, OutFriendsList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSet(UObject* WorldContextObject, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, FOnlineManagerPresenceSetDelegate InPresenceSetDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSet(WorldContextObject, ApiName, LobbySessionId, MatchSessionId, bIsJoinable, Extra, InPresenceSetDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetDestination(UObject* WorldContextObject, const FString& ApiName, FOnlineManagerPresenceSetDestinationDelegate InPresenceSetDestinationDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSetDestination(WorldContextObject, ApiName, InPresenceSetDestinationDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetIsJoinable(UObject* WorldContextObject, bool bIsJoinable, FOnlineManagerPresenceSetIsJoinableDelegate InPresenceSetIsJoinableDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSetIsJoinable(WorldContextObject, bIsJoinable, InPresenceSetIsJoinableDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetLobbySession(UObject* WorldContextObject, const FString& LobbySession, FOnlineManagerPresenceSetLobbySessionDelegate InPresenceSetLobbySessionDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSetLobbySession(WorldContextObject, LobbySession, InPresenceSetLobbySessionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetMatchSession(UObject* WorldContextObject, const FString& MatchSession, FOnlineManagerPresenceSetMatchSessionDelegate InPresenceSetMatchSessionDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSetMatchSession(WorldContextObject, MatchSession, InPresenceSetMatchSessionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSetExtra(UObject* WorldContextObject, const FString& Extra, FOnlineManagerPresenceSetExtraDelegate InPresenceSetExtraDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSetExtra(WorldContextObject, Extra, InPresenceSetExtraDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceReadSendInvites(UObject* WorldContextObject, FOnlineManagerPresenceReadSentInvitesDelegate InPresenceReadSendInvitesDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceReadSendInvites(WorldContextObject, InPresenceReadSendInvitesDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceSendInvites(UObject* WorldContextObject, TArray<FString> UserIdArray, FOnlineManagerPresenceSentInvitesDelegate InPresenceSentInvitesDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceSendInvites(WorldContextObject, UserIdArray, InPresenceSentInvitesDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetSendInvitesList(UObject* WorldContextObject, TArray<FPicoApplicationInvite>& OutList)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetSendInvitesList(WorldContextObject, OutList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceGetDestinations(UObject* WorldContextObject, FOnlineManagerPresenceGetDestinationsDelegate InPresenceGetDestinationsDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceGetDestinations(WorldContextObject, InPresenceGetDestinationsDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::PresenceGetDestinationsList(UObject* WorldContextObject, TArray<FPicoDestination>& OutList)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->PresenceGetDestinationsList(WorldContextObject, OutList);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchInvitePanel(UObject* WorldContextObject, FOnlineManagerLaunchInvitePanelDelegate InLaunchInvitePanelDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LaunchInvitePanel(WorldContextObject, InLaunchInvitePanelDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::ShareMedia(UObject* WorldContextObject, EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, FOnlineManagerShareMediaDelegate InShareMediaDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->ShareMedia(WorldContextObject, InMediaType, InVideoPath, InVideoThumbPath, InImagePaths, InShareType, InShareMediaDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherApp(UObject* WorldContextObject, const FString& PackageName, const FString& Message, FOnlineManagerLaunchOtherAppDelegate InLaunchOtherAppDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LaunchOtherApp(WorldContextObject, PackageName, Message, InLaunchOtherAppDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetVersion(UObject* WorldContextObject, FOnlineManagerGetVersionDelegate InGetVersionDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetVersion(WorldContextObject, InGetVersionDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherAppByPresence(UObject* WorldContextObject, const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, FOnlineManagerLaunchOtherAppByPresenceDelegate InLaunchOtherAppByPresenceDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LaunchOtherAppByPresence(WorldContextObject, AppID, PackageName, Message, ApiName, LobbySessionId, MatchSessionId, TrackId, Extra, InLaunchOtherAppByPresenceDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchOtherAppByAppId(UObject* WorldContextObject, const FString& AppId, const FString& Message, FOnlineManagerLaunchOtherAppByAppIdDelegate InLaunchOtherAppByAppIdDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LaunchOtherAppByAppId(WorldContextObject, AppId, Message, InLaunchOtherAppByAppIdDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LaunchStore(UObject* WorldContextObject, FOnlineManagerLaunchStoreDelegate InLaunchStoreDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LaunchStore(WorldContextObject, InLaunchStoreDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetLaunchDetails(UObject* WorldContextObject, FLaunchDetails& OutLaunchDetails)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetLaunchDetails(WorldContextObject, OutLaunchDetails);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::LogDeeplinkResult(UObject* WorldContextObject, const FString& TrackingID, ELaunchResult LaunchResult)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->LogDeeplinkResult(WorldContextObject, TrackingID, LaunchResult);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::GetSystemInfo(UObject* WorldContextObject, FPicoSystemInfo& SystemInfo)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->GetSystemInfo(WorldContextObject, SystemInfo);
    }
    return false;
}

// Leaderboard
bool UOnlinePicoFunctionLibrary::ReadLeaderboards(UObject* WorldContextObject, const TArray<FString>& Players, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        // Players
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        TArray<TSharedRef<const FUniqueNetId>> LeaderboardPlayers;
        for (int i = 0; i < Players.Num(); i++)
        {
            UE_LOG_ONLINE_LEADERBOARD(Display, TEXT("PPF_GAME Library ReadLeaderboards Players[%d]: %s"), i, *Players[i]);
            auto UniqueNetIdRef = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Players[i]).ToSharedRef();
            LeaderboardPlayers.Add(UniqueNetIdRef);
        }
        return GetOnlineSubsystemPicoManager(WorldContextObject)->ReadLeaderboards(WorldContextObject, LeaderboardPlayers, PicoReadObject, OnReadLeaderboardsCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::ReadLeaderboardsForFriends(UObject* WorldContextObject, int32 LocalUserNum, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        return GetOnlineSubsystemPicoManager(WorldContextObject)->ReadLeaderboardsForFriends(WorldContextObject, LocalUserNum, PicoReadObject, OnReadLeaderboardsCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoFunctionLibrary::WriteLeaderboards(UObject* WorldContextObject, const FString& SessionName, const FString& Player, UPARAM(ref)FPicoOnlineLeaderboardWrite& PicoWriteObject)
{
    if (GetOnlineSubsystemPicoManager(WorldContextObject))
    {
        IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get(TEXT("Pico"));
        UE_LOG_ONLINE_LEADERBOARD(Display, TEXT("PPF_GAME Library WriteLeaderboards begin"));
        auto LeaderboardPlayer = Subsystem->GetIdentityInterface()->CreateUniquePlayerId(Player).ToSharedRef();

        TSharedPtr<FOnlineLeaderboardWrite, ESPMode::ThreadSafe> PicoWritePtr = MakeShareable(new Pico_OnlineLeaderboardWrite(PicoWriteObject.LeaderboardNames));
        PicoWritePtr->UpdateMethod = (ELeaderboardUpdateMethod::Type)PicoWriteObject.UpdateMethod;
        PicoWritePtr->RatedStat = FName(PicoWriteObject.RatedStat);
        PicoWritePtr->SetIntStat(PicoWritePtr->RatedStat, PicoWriteObject.ValueToWrite);
        TSharedRef<FOnlineLeaderboardWrite, ESPMode::ThreadSafe> PicoWriteRef = PicoWritePtr.ToSharedRef();

        return GetOnlineSubsystemPicoManager(WorldContextObject)->WriteLeaderboards(WorldContextObject, FName(SessionName), LeaderboardPlayer.Get(), PicoWriteRef.Get());
    }
    return false;
}


