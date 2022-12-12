// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "PicoApplicationInterface.h"


DEFINE_LOG_CATEGORY(ApplicationInterface);

FPicoApplicationInterface::FPicoApplicationInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{


}

FPicoApplicationInterface::~FPicoApplicationInterface()
{
}


bool FPicoApplicationInterface::LaunchOtherApp(const FString& PackageName, const FString& Message, const FOnLaunchOtherAppComplete& Delegate /*= FOnGetTokenComplete()*/)
{
    auto ApplicationOptions = ppf_ApplicationOptions_Create();
    ppf_ApplicationOptions_SetDeeplinkMessage(ApplicationOptions, TCHAR_TO_UTF8(*Message));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Application_LaunchOtherApp(TCHAR_TO_UTF8(*PackageName), ApplicationOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryLaunchOtherAppComplete(Message, bIsError, Delegate);
            }
        )
    );
    ppf_ApplicationOptions_Destroy(ApplicationOptions);
    return true;
}

void FPicoApplicationInterface::OnQueryLaunchOtherAppComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppComplete& Delegate)
{
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        auto ErrorMessage = ppf_Error_GetMessage(Error);
        ErrorStr = FString(ErrorMessage);
        Delegate.ExecuteIfBound(FString(), false, ErrorStr);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}

bool FPicoApplicationInterface::GetVersion(const FOnGetVersion& Delegate /*= FOnGetVersion()*/)
{
    //#if CHECK_PLATFORM
    //    PicoSubsystem.AddRequestDelegate
    //    (
    //        ppf_Application_GetVersion(),
    //        FPicoMessageOnCompleteDelegate::CreateLambda
    //        (
    //            [this, Delegate](ppfMessageHandle Message, bool bIsError)
    //            {
    //                OnQueryGetVersionComplete(Message, bIsError, Delegate);
    //            }
    //        )
    //    );
    //
    //    return true;
    //#endif
    return false;
}

void FPicoApplicationInterface::OnQueryGetVersionComplete(ppfMessageHandle Message, bool bIsError, const FOnGetVersion& Delegate)
{
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        auto ErrorMessage = ppf_Error_GetMessage(Error);
        ErrorStr = FString(ErrorMessage);
        Delegate.ExecuteIfBound(FString(), false, ErrorStr);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}

bool FPicoApplicationInterface::LaunchOtherAppByPresence(const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, const FOnLaunchOtherAppByPresenceComplete& Delegate /*= FOnLaunchOtherAppByPresenceComplete()*/)
{
    auto ApplicationByPresenceOptions = ppf_ApplicationByPresenceOptions_Create();
    ppf_ApplicationByPresenceOptions_SetDeeplinkMessage(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*Message));
    ppf_ApplicationByPresenceOptions_SetDestinationApiName(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*ApiName));
    ppf_ApplicationByPresenceOptions_SetLobbySessionId(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*LobbySessionId));
    ppf_ApplicationByPresenceOptions_SetMatchSessionId(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*MatchSessionId));
    ppf_ApplicationByPresenceOptions_SetTrackingId(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*TrackId));
    ppf_ApplicationByPresenceOptions_SetExtra(ApplicationByPresenceOptions, TCHAR_TO_UTF8(*Extra));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Application_LaunchOtherAppByPresence(TCHAR_TO_UTF8(*AppID), TCHAR_TO_UTF8(*PackageName), ApplicationByPresenceOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryLaunchOtherAppByPresenceComplete(Message, bIsError, Delegate);
            }
        )
    );

    ppf_ApplicationByPresenceOptions_Destroy(ApplicationByPresenceOptions);
    return true;
}

void FPicoApplicationInterface::OnQueryLaunchOtherAppByPresenceComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppByPresenceComplete& Delegate)
{
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        auto ErrorMessage = ppf_Error_GetMessage(Error);
        ErrorStr = FString(ErrorMessage);
        Delegate.ExecuteIfBound(FString(), false, ErrorStr);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}

bool FPicoApplicationInterface::LaunchOtherAppByAppId(const FString& AppId, const FString& Message, const FOnLaunchOtherAppByAppIdComplete& Delegate /*= FOnLaunchOtherAppByAppIdComplete()*/)
{
#if PLATFORM_ANDROID
    auto ApplicationOptions = ppf_ApplicationOptions_Create();
    ppf_ApplicationOptions_SetDeeplinkMessage(ApplicationOptions, TCHAR_TO_UTF8(*Message));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Application_LaunchOtherAppByAppID(TCHAR_TO_UTF8(*AppId), ApplicationOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryLaunchOtherAppByAppIdComplete(Message, bIsError, Delegate);
            }
        )
    );
    ppf_ApplicationOptions_Destroy(ApplicationOptions);
    return true;
#endif
    return false;
}

void FPicoApplicationInterface::OnQueryLaunchOtherAppByAppIdComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchOtherAppByAppIdComplete& Delegate)
{
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        auto ErrorMessage = ppf_Error_GetMessage(Error);
        ErrorStr = FString(ErrorMessage);
        Delegate.ExecuteIfBound(FString(), false, ErrorStr);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}
