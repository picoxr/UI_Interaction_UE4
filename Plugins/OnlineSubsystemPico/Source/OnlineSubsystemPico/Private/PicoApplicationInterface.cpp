// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


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
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(FString(), false, ErrorMessage);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}

bool FPicoApplicationInterface::GetVersion(const FOnGetVersionComplete& Delegate /*= FOnGetVersion()*/)
{
#if PLATFORM_ANDROID
    PicoSubsystem.AddAsyncTask
    (
        ppf_Application_GetVersion(),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryGetVersionComplete(Message, bIsError, Delegate);
            }
        )
    );

    return true;
#endif
    return false;
}

void FPicoApplicationInterface::OnQueryGetVersionComplete(ppfMessageHandle Message, bool bIsError, const FOnGetVersionComplete& Delegate)
{
#if PLATFORM_ANDROID
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(0, FString(), 0, FString(), false, ErrorMessage);
        return;
    }
    else
    {
        auto ApplicationVersion = ppf_Message_GetApplicationVersion(Message);
        int64 CurrentCode = ppf_ApplicationVersion_GetCurrentCode(ApplicationVersion);
        FString CurrentName = UTF8_TO_TCHAR(ppf_ApplicationVersion_GetCurrentName(ApplicationVersion));
        int64 LatestCode = ppf_ApplicationVersion_GetLatestCode(ApplicationVersion);
        FString LatestName = ppf_ApplicationVersion_GetLatestName(ApplicationVersion);
        Delegate.ExecuteIfBound(CurrentCode, CurrentName, LatestCode, LatestName, true, FString());
    }
#endif
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
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(FString(), false, ErrorMessage);
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
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(FString(), false, ErrorMessage);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}

bool FPicoApplicationInterface::LaunchStore(const FOnLaunchStoreComplete& Delegate /*= FOnLaunchStoreComplete()*/)
{
#if PLATFORM_ANDROID
    PicoSubsystem.AddAsyncTask
    (
        ppf_Application_LaunchStore(),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryLaunchStoreComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
#endif
    return false;
}

void FPicoApplicationInterface::OnQueryLaunchStoreComplete(ppfMessageHandle Message, bool bIsError, const FOnLaunchStoreComplete& Delegate)
{
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(FString(), false, ErrorMessage);
        return;
    }
    else
    {
        FString PayloadMessage = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
        Delegate.ExecuteIfBound(PayloadMessage, true, FString());
    }
}
