// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

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
    auto UserArrayHandle = ppf_LaunchDetails_GetUsers(LaunchDetailsHandle);
    UPico_UserArray* UserArray = NewObject<UPico_UserArray>();
    UserArray->InitParams(UserArrayHandle);
    LaunchDetails.UserArray = UserArray;
    LaunchDetails.DeeplinkMessage = UTF8_TO_TCHAR(ppf_LaunchDetails_GetDeeplinkMessage(LaunchDetailsHandle));
    LaunchDetails.DestinationApiName = UTF8_TO_TCHAR(ppf_LaunchDetails_GetDestinationApiName(LaunchDetailsHandle));
    LaunchDetails.LaunchSource = UTF8_TO_TCHAR(ppf_LaunchDetails_GetLaunchSource(LaunchDetailsHandle));
    LaunchDetails.LobbySessionID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetLobbySessionID(LaunchDetailsHandle));
    LaunchDetails.MatchSessionID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetMatchSessionID(LaunchDetailsHandle));
    LaunchDetails.Extra = UTF8_TO_TCHAR(ppf_LaunchDetails_GetExtra(LaunchDetailsHandle));
    ppfID ID = ppf_LaunchDetails_GetRoomID(LaunchDetailsHandle);
    FString IDstr = FString::Printf(TEXT("%llu"), ID);
    LaunchDetails.RoomID = IDstr;
    LaunchDetails.TrackingID = UTF8_TO_TCHAR(ppf_LaunchDetails_GetTrackingID(LaunchDetailsHandle));
    ELaunchType LaunchType = ELaunchType::Unknown;
    ppfLaunchType pLaunchType = ppf_LaunchDetails_GetLaunchType(LaunchDetailsHandle);
    if (pLaunchType == ppfLaunchType_Normal)
    {
        LaunchType = ELaunchType::Normal;
    }
    else if (pLaunchType == ppfLaunchType_Invite)
    {
        LaunchType = ELaunchType::Invite;
    }
    else if (pLaunchType == ppfLaunchType_Coordinated)
    {
        LaunchType = ELaunchType::Coordinated;
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
