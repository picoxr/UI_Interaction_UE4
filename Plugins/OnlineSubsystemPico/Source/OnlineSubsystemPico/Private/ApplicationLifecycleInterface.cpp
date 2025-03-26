// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "ApplicationLifecycleInterface.h"
#include "Pico_User.h"
DEFINE_LOG_CATEGORY(ApplicationLifecycleInterface);
FApplicationLifecycleInterface::FApplicationLifecycleInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    OnLaunchIntentChangedNotificationHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_ApplicationLifecycle_LaunchIntentChanged)
        .AddRaw(this, &FApplicationLifecycleInterface::OnLaunchIntentChangedNotification);
}

FApplicationLifecycleInterface::~FApplicationLifecycleInterface()
{
    if (OnLaunchIntentChangedNotificationHandle.IsValid())
    {
        OnLaunchIntentChangedNotificationHandle.Reset();
    }
}



bool FApplicationLifecycleInterface::ReadLaunchDetails()
{
    FLaunchDetails NewLaunchDetails;
    LaunchDetails = NewLaunchDetails;
    auto LaunchDetailsHandle = ppf_ApplicationLifecycle_GetLaunchDetails();
    LaunchDetails.DeeplinkMessage = UTF8_TO_TCHAR(ppf_LaunchDetails_GetDeeplinkMessage(LaunchDetailsHandle));
    LaunchDetails.DestinationApiName = UTF8_TO_TCHAR(ppf_LaunchDetails_GetDestinationApiName(LaunchDetailsHandle));
    LaunchDetails.LobbySessionID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetLobbySessionID(LaunchDetailsHandle));
    LaunchDetails.MatchSessionID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetMatchSessionID(LaunchDetailsHandle));
    LaunchDetails.Extra = UTF8_TO_TCHAR(ppf_LaunchDetails_GetExtra(LaunchDetailsHandle));
    ppfID ID = ppf_LaunchDetails_GetRoomID(LaunchDetailsHandle);
    FString IDstr = FString::Printf(TEXT("%llu"), ID);
    LaunchDetails.RoomID = IDstr;
    LaunchDetails.TrackingID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetTrackingID(LaunchDetailsHandle));
#if PLATFORM_ANDROID
    ppfID ChallengeID = ppf_LaunchDetails_GetChallengeID(LaunchDetailsHandle);
    FString ChallengeIDStr = FString::Printf(TEXT("%llu"), ChallengeID);
    LaunchDetails.ChallengeID = ChallengeIDStr;
#endif
    ELaunchType LaunchType = ELaunchType::Unknown;
    ppfLaunchType pLaunchType = ppf_LaunchDetails_GetLaunchType(LaunchDetailsHandle);
    if (pLaunchType == ppfLaunchType_Normal)
    {
        LaunchType = ELaunchType::Normal;
    }
    else if (pLaunchType == ppfLaunchType_RoomInvite)
    {
        LaunchType = ELaunchType::RoomInvite;
    }
    else if (pLaunchType == ppfLaunchType_ChallengeInvite)
    {
        LaunchType = ELaunchType::ChallengeInvite;
    }
    else if (pLaunchType == ppfLaunchType_Deeplink)
    {
        LaunchType = ELaunchType::Deeplink;
    }
    LaunchDetails.LaunchType = LaunchType;
    return true;

}

bool FApplicationLifecycleInterface::GetLaunchDetails(FLaunchDetails& OutLaunchDetails)
{
    ReadLaunchDetails();
    OutLaunchDetails = LaunchDetails;
    return true;
}

bool FApplicationLifecycleInterface::LogDeeplinkResult(const FString& TrackingID, ELaunchResult LaunchResult)
{
    ppfLaunchResult Result = ppfLaunchResult_Unknown;
    switch (LaunchResult)
    {
    case ELaunchResult::Unknown:
        Result = ppfLaunchResult_Unknown;
        break;
    case ELaunchResult::Success:
        Result = ppfLaunchResult_Success;
        break;
    case ELaunchResult::FailedUserDeclined:
        Result = ppfLaunchResult_FailedUserDeclined;
        break;
    case ELaunchResult::FailedOtherReason:
        Result = ppfLaunchResult_FailedOtherReason;
        break;
    case ELaunchResult::FailedRoomNotFound:
        Result = ppfLaunchResult_FailedRoomNotFound;
        break;
    case ELaunchResult::FailedGameAlreadyStarted:
        Result = ppfLaunchResult_FailedGameAlreadyStarted;
        break;
    case ELaunchResult::FailedRoomFull:
        Result = ppfLaunchResult_FailedRoomFull;
        break;
    default:
        break;
    }
    ppf_ApplicationLifecycle_LogDeeplinkResult(TCHAR_TO_UTF8(*TrackingID), Result);
    return true;
}

bool FApplicationLifecycleInterface::GetSystemInfo(FPicoSystemInfo& SystemInfo)
{
#if PLATFORM_ANDROID
    auto PicoSystemInfo = ppf_Application_GetSystemInfo();
    SystemInfo.ROMVersion = UTF8_TO_TCHAR(ppf_SystemInfo_GetROMVersion(PicoSystemInfo));
    SystemInfo.Locale = UTF8_TO_TCHAR(ppf_SystemInfo_GetLocale(PicoSystemInfo));
    SystemInfo.ProductName = UTF8_TO_TCHAR(ppf_SystemInfo_GetProductName(PicoSystemInfo));
    SystemInfo.bIsCnDevice = ppf_SystemInfo_GetIsCnDevice(PicoSystemInfo);
    SystemInfo.MatrixVersionName = UTF8_TO_TCHAR(ppf_SystemInfo_GetMatrixVersionName(PicoSystemInfo));
    SystemInfo.MatrixVersionCode = ppf_SystemInfo_GetMatrixVersionCode(PicoSystemInfo);
    return true;
#endif
    return false;
}

void FApplicationLifecycleInterface::OnLaunchIntentChangedNotification(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        UE_LOG(ApplicationLifecycleInterface, Error, TEXT("OnLaunchIntentChangedNotification error!"));
        return;
    }
    FString MessageString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    LaunchIntentChangedCallback.Broadcast(MessageString);
}
