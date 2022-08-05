// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#include "OnlineIdentityPico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineError.h"



bool FUserOnlineAccountPico::GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const
{
    const FString* FoundAttr = UserAttributes.Find(AttrName);
    if (FoundAttr != nullptr)
    {
        OutAttrValue = *FoundAttr;
        return true;
    }
    return false;
}

bool FUserOnlineAccountPico::SetUserAttribute(const FString& AttrName, const FString& AttrValue)
{
    const FString* FoundAttr = UserAttributes.Find(AttrName);
    if (FoundAttr == nullptr || *FoundAttr != AttrValue)
    {
        UserAttributes.Add(AttrName, AttrValue);
        return true;
    }
    return false;
}

bool FUserOnlineAccountPico::GetAuthAttribute(const FString& AttrName, FString& OutAttrValue) const
{
    const FString* FoundAttr = AdditionalAuthData.Find(AttrName);
    if (FoundAttr != nullptr)
    {
        OutAttrValue = *FoundAttr;
        return true;
    }
    return false;
}

bool FOnlineIdentityPico::Login(int32 LocalUserNum, const FOnlineAccountCredentials& AccountCredentials)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::Login"));
#if PLATFORM_ANDROID
    FString ErrorStr;
    TSharedPtr<FUserOnlineAccountPico> UserAccountPtr;

    if (LocalUserNum < 0 || LocalUserNum >= MAX_LOCAL_PLAYERS)
    {
        ErrorStr = FString::Printf(TEXT("Invalid LocalUserNum=%d"), LocalUserNum);
    }
    else
    {
        FUniqueNetIdRef* UserId = UserIds.Find(LocalUserNum);
        if (UserId == nullptr)
        {
            UE_LOG_ONLINE_IDENTITY(Log, TEXT("Login Request"));
            PicoSubsystem.AddAsyncTask
            (
                ppf_User_GetLoggedInUser(),
                FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineIdentityPico::OnLoginComplete, LocalUserNum)
            );
            return true;
        }
        else
        {
            UE_LOG_ONLINE_IDENTITY(Log, TEXT("Local user vaild."));
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, **UserId, *ErrorStr);
        }
    }
    if (!ErrorStr.IsEmpty())
    {
        UE_LOG_ONLINE_IDENTITY(Warning, TEXT("Failed Pico login. %s"), *ErrorStr);
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, *FUniqueNetIdPico::EmptyId(), ErrorStr);
    }
#endif
    return false;   
}

bool FOnlineIdentityPico::Logout(int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::Logout"));
#if PLATFORM_ANDROID
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        UserAccounts.Remove(UserId.ToSharedRef());
        UserIds.Remove(LocalUserNum);
        TriggerOnLogoutCompleteDelegates(LocalUserNum, true);
        TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::LoggedIn, ELoginStatus::NotLoggedIn, *UserId);
        return true;
    }
    else
    {
        UE_LOG_ONLINE_IDENTITY(Warning, TEXT("No logged in user found for LocalUserNum=%d."), LocalUserNum);
        TriggerOnLogoutCompleteDelegates(LocalUserNum, false);
    }
#endif
    return false;
}

bool FOnlineIdentityPico::AutoLogin(int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::AutoLogin"));
    return Login(0, FOnlineAccountCredentials(FString(), FString(), FString()));
}

TSharedPtr<FUserOnlineAccount> FOnlineIdentityPico::GetUserAccount(const FUniqueNetId& UserId) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUserAccount"));
    TSharedPtr<FUserOnlineAccount> Result;
    const TSharedRef<FUserOnlineAccountPico>* FoundUserAccount = UserAccounts.Find(UserId.AsShared());
    if (FoundUserAccount != nullptr)
    {
        Result = *FoundUserAccount;
    }
    return Result;
}

TArray<TSharedPtr<FUserOnlineAccount> > FOnlineIdentityPico::GetAllUserAccounts() const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetAllUserAccounts"));
    TArray<TSharedPtr<FUserOnlineAccount>> Result;
    for (TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>>::TConstIterator It(UserAccounts); It; ++It)
    {
        Result.Add(It.Value());
    }
    return Result;
}

FUniqueNetIdPtr FOnlineIdentityPico::GetUniquePlayerId(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUniquePlayerId"));
    if (const FUniqueNetIdRef* FoundId = UserIds.Find(LocalUserNum))
    {
        return *FoundId;
    }
    return nullptr;
}

FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(uint8* Bytes, int32 Size)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::CreateUniquePlayerId"));
    if (Bytes != nullptr && Size == sizeof(ppfID))
    {
        uint64* RawUniqueId = (uint64*)Bytes;
        ppfID PicoId(*RawUniqueId);
        return FUniqueNetIdPico::Create(PicoId);
    }
    return nullptr;
}

FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(const FString& Str)
{
    return FUniqueNetIdPico::Create(Str);
}

ELoginStatus::Type FOnlineIdentityPico::GetLoginStatus(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetLoginStatus"));
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        return GetLoginStatus(*UserId);
    }
    return ELoginStatus::NotLoggedIn;
}

ELoginStatus::Type FOnlineIdentityPico::GetLoginStatus(const FUniqueNetId& UserId) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetLoginStatus"));
    TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(UserId);
    if (UserAccount.IsValid() &&
        UserAccount->GetUserId()->IsValid())
    {
        return ELoginStatus::LoggedIn;
    }
    return ELoginStatus::NotLoggedIn;
}

FString FOnlineIdentityPico::GetPlayerNickname(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetPlayerNickname"));
    FUniqueNetIdPtr UniqueId = GetUniquePlayerId(LocalUserNum);
    if (UniqueId.IsValid())
    {
        return GetPlayerNickname(*UniqueId);
    }

    return TEXT("Pico User");
}

FString FOnlineIdentityPico::GetPlayerNickname(const FUniqueNetId& UserId) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetPlayerNickname"));
    auto UserAccount = GetUserAccount(UserId);
    if (UserAccount.IsValid())
    {
        return UserAccount->GetDisplayName();
    }
    return UserId.ToString();
}

FString FOnlineIdentityPico::GetAuthToken(int32 LocalUserNum) const
{
    // Testing
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetAuthToken"));
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(*UserId);
        if (UserAccount.IsValid())
        {
            return UserAccount->GetAccessToken();
        }
    }
    return FString();
}

void FOnlineIdentityPico::RevokeAuthToken(const FUniqueNetId& UserId, const FOnRevokeAuthTokenCompleteDelegate& Delegate)
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::RevokeAuthToken not implemented"));
    FUniqueNetIdRef UserIdRef(UserId.AsShared());
    PicoSubsystem.ExecuteNextTick([UserIdRef, Delegate]()
        {
            Delegate.ExecuteIfBound(*UserIdRef, FOnlineError(FString(TEXT("RevokeAuthToken not implemented"))));
        });
}

void FOnlineIdentityPico::GetUserPrivilege(const FUniqueNetId& UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate& Delegate)
{
    // Not Supported
    Delegate.ExecuteIfBound(UserId, Privilege, (uint32)EPrivilegeResults::NoFailures);
}

FPlatformUserId FOnlineIdentityPico::GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) const
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::GetPlatformUserIdFromUniqueNetId"));
    for (int i = 0; i < MAX_LOCAL_PLAYERS; ++i)
    {
        auto CurrentUniqueId = GetUniquePlayerId(i);
        if (CurrentUniqueId.IsValid() && (*CurrentUniqueId == UniqueNetId))
        {
            return i;
        }
    }

    return PLATFORMUSERID_NONE;
}

FString FOnlineIdentityPico::GetAuthType() const
{
    return TEXT("Pico");
}


FOnlineIdentityPico::FOnlineIdentityPico(FOnlineSubsystemPico& InSubsystem)
    : PicoSubsystem(InSubsystem)
{
//    FOnlineIdentityPico::AutoLogin(0);
}

void FOnlineIdentityPico::OnLoginComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("Login Complete!"));
#if PLATFORM_ANDROID
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        ErrorStr = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
    }
    else
    {
        auto User = ppf_Message_GetUser(Message);
        FString Id = UTF8_TO_TCHAR(ppf_User_GetID(User));

        // GetPicoID ?
        FString Name = UTF8_TO_TCHAR(ppf_User_GetDisplayName(User));
        FString ImageUrl = UTF8_TO_TCHAR(ppf_User_GetImageUrl(User));
        ppfUserPresenceStatus ppfUPS = ppf_User_GetPresenceStatus(User);
        ppfGender ppfG = ppf_User_GetGender(User);
        EUserGender Gender = EUserGender::Unknow;
        if (ppfG == ppfGender_Female)
        {
            Gender = EUserGender::Female;
        }
        else if (ppfG == ppfGender_Male)
        {
            Gender = EUserGender::Male;
        }
        EUserPresenceStatus UserPresenceStatus = EUserPresenceStatus::Unknow;
        if (ppfUPS == ppfUserPresenceStatus_OffLine)
        {
            UserPresenceStatus = EUserPresenceStatus::OffLine;
        }
        else if (ppfUPS == ppfUserPresenceStatus_OnLine)
        {
            UserPresenceStatus = EUserPresenceStatus::OnLine;
        }
        FUserInformation UserInfo;
        UserInfo.DisplayName = Name;
        UserInfo.Gender = Gender;
        UserInfo.ImageUrl = ImageUrl;
        UserInfo.UserId = Id;
        UserInfo.UserPresenceStatus = UserPresenceStatus;
        UE_LOG_ONLINE_IDENTITY(Log, TEXT("Pico login. %s"), *Id);
        FUniqueNetIdRef LocalUserId = FUniqueNetIdPico::Create(Id);

        if (!LocalUserId->IsValid())
        {
            ErrorStr = FString(TEXT("Unable to get a valid ID"));
        }
        else
        {
            UserIds.Add(LocalUserNum, LocalUserId);

            // update/add cached entry for user
            UserAccounts.Add(LocalUserId, TSharedRef<FUserOnlineAccountPico>(new FUserOnlineAccountPico(LocalUserId, Name)));

            UserInfos.Add(LocalUserNum, UserInfo);
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, *LocalUserId, *ErrorStr);
            TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::NotLoggedIn, ELoginStatus::LoggedIn, *LocalUserId);
            return;

        }
    }

    TriggerOnLoginCompleteDelegates(LocalUserNum, false, *FUniqueNetIdPico::EmptyId(), *ErrorStr);
#endif

}

