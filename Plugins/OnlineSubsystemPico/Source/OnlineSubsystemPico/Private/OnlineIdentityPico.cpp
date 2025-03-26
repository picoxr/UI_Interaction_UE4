// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
    Logout(LocalUserNum);
    FString ErrorStr;
    TSharedPtr<FUserOnlineAccountPico> UserAccountPtr;

    if (LocalUserNum < 0 || LocalUserNum >= MAX_LOCAL_PLAYERS)
    {
        ErrorStr = FString::Printf(TEXT("Invalid LocalUserNum=%d"), LocalUserNum);
    }
    else
    {
#if ENGINE_MAJOR_VERSION > 4
        FUniqueNetIdRef* UserId = UserIds.Find(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 26
        FUniqueNetIdRef* UserId = UserIds.Find(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 24
        TSharedPtr<const FUniqueNetId>* UserId = UserIds.Find(LocalUserNum);
#endif

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
#if ENGINE_MAJOR_VERSION > 4
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, **UserId, *ErrorStr);
#elif ENGINE_MINOR_VERSION > 26
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, **UserId, *ErrorStr);
#elif ENGINE_MINOR_VERSION > 24
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, *UserId->Get(), *ErrorStr);
#endif
        }
    }
    if (!ErrorStr.IsEmpty())
    {
        UE_LOG_ONLINE_IDENTITY(Warning, TEXT("Failed Pico login. %s"), *ErrorStr);
#if ENGINE_MAJOR_VERSION > 4
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, *FUniqueNetIdPico::EmptyId(), ErrorStr);
#elif ENGINE_MINOR_VERSION > 26
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, *FUniqueNetIdPico::EmptyId(), ErrorStr);
#elif ENGINE_MINOR_VERSION > 24
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, FUniqueNetIdPico(), ErrorStr);
#endif
    }
    return false;
}

bool FOnlineIdentityPico::Logout(int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::Logout"));
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        UserAccounts.Remove(UserId.ToSharedRef());
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        UserAccounts.Remove(UserId.ToSharedRef());
#elif ENGINE_MINOR_VERSION > 24
    TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
    if (UserId.IsValid())
    {
        UserAccounts.Remove(FUniqueNetIdPico(*UserId));
#endif
        UserIds.Remove(LocalUserNum);
        LoginPicoUserMap.Remove(LocalUserNum);
        TriggerOnLogoutCompleteDelegates(LocalUserNum, true);
        TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::LoggedIn, ELoginStatus::NotLoggedIn, *UserId);
        return true;
    }
    else
    {
        UE_LOG_ONLINE_IDENTITY(Warning, TEXT("No logged in user found for LocalUserNum=%d."), LocalUserNum);
        TriggerOnLogoutCompleteDelegates(LocalUserNum, false);
    }
    return false;
    }

bool FOnlineIdentityPico::AutoLogin(int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::AutoLogin"));
    return Login(0, FOnlineAccountCredentials(FString(), FString(), FString()));
}

TSharedPtr<FUserOnlineAccount> FOnlineIdentityPico::GetUserAccount(const FUniqueNetId & UserId) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUserAccount"));
    TSharedPtr<FUserOnlineAccount> Result;
#if ENGINE_MAJOR_VERSION > 4
    const TSharedRef<FUserOnlineAccountPico>* FoundUserAccount = UserAccounts.Find(UserId.AsShared());
#elif ENGINE_MINOR_VERSION > 26
    const TSharedRef<FUserOnlineAccountPico>* FoundUserAccount = UserAccounts.Find(UserId.AsShared());
#elif ENGINE_MINOR_VERSION > 24
    FUniqueNetIdPico PicoUserId(UserId);
    const TSharedRef<FUserOnlineAccountPico>* FoundUserAccount = UserAccounts.Find(PicoUserId);
#endif
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
#if ENGINE_MAJOR_VERSION > 4
    for (TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>>::TConstIterator It(UserAccounts); It; ++It)
#elif ENGINE_MINOR_VERSION > 26
    for (TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>>::TConstIterator It(UserAccounts); It; ++It)
#elif ENGINE_MINOR_VERSION > 24
    for (TMap<FUniqueNetIdPico, TSharedRef<FUserOnlineAccountPico>>::TConstIterator It(UserAccounts); It; ++It)
#endif
    {
        Result.Add(It.Value());
    }
    return Result;
}

#if ENGINE_MAJOR_VERSION > 4
FUniqueNetIdPtr FOnlineIdentityPico::GetUniquePlayerId(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUniquePlayerId"));
    if (const FUniqueNetIdRef* FoundId = UserIds.Find(LocalUserNum))
#elif ENGINE_MINOR_VERSION > 26
FUniqueNetIdPtr FOnlineIdentityPico::GetUniquePlayerId(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUniquePlayerId"));
    if (const FUniqueNetIdRef* FoundId = UserIds.Find(LocalUserNum))
#elif ENGINE_MINOR_VERSION > 24
TSharedPtr<const FUniqueNetId> FOnlineIdentityPico::GetUniquePlayerId(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetUniquePlayerId"));
    const TSharedPtr<const FUniqueNetId>* FoundId = UserIds.Find(LocalUserNum);
    if (FoundId != nullptr)
#endif
    {
        return *FoundId;
    }
    return nullptr;
}

#if ENGINE_MAJOR_VERSION > 4
FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(uint8 * Bytes, int32 Size)
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

FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(const FString & Str)
{
    return FUniqueNetIdPico::Create(Str);
}
#elif ENGINE_MINOR_VERSION > 26
FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(uint8 * Bytes, int32 Size)
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

FUniqueNetIdPtr FOnlineIdentityPico::CreateUniquePlayerId(const FString & Str)
{
    return FUniqueNetIdPico::Create(Str);
}

#elif ENGINE_MINOR_VERSION > 24
TSharedPtr<const FUniqueNetId> FOnlineIdentityPico::CreateUniquePlayerId(uint8 * Bytes, int32 Size)
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::CreateUniquePlayerId"));
    if (Bytes != nullptr && Size == sizeof(ppfID))
    {
        uint64* RawUniqueId = (uint64*)Bytes;
        ppfID PicoId(*RawUniqueId);
        return MakeShareable(new FUniqueNetIdPico(PicoId));
    }
    return nullptr;
}

TSharedPtr<const FUniqueNetId> FOnlineIdentityPico::CreateUniquePlayerId(const FString & Str)
{
    return MakeShareable(new FUniqueNetIdPico(Str));
}
#endif



ELoginStatus::Type FOnlineIdentityPico::GetLoginStatus(int32 LocalUserNum) const
{
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("FOnlineIdentityPico::GetLoginStatus"));
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 24
    TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
#endif
    if (UserId.IsValid())
    {
        return GetLoginStatus(*UserId);
    }
    return ELoginStatus::NotLoggedIn;
}

ELoginStatus::Type FOnlineIdentityPico::GetLoginStatus(const FUniqueNetId & UserId) const
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
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdPtr UniqueId = GetUniquePlayerId(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdPtr UniqueId = GetUniquePlayerId(LocalUserNum);
#elif ENGINE_MINOR_VERSION > 24
    TSharedPtr<const FUniqueNetId> UniqueId = GetUniquePlayerId(LocalUserNum);
#endif
    if (UniqueId.IsValid())
    {
        return GetPlayerNickname(*UniqueId);
    }

    return TEXT("Pico User");
}

FString FOnlineIdentityPico::GetPlayerNickname(const FUniqueNetId & UserId) const
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

    return AuthToken;
//#if ENGINE_MAJOR_VERSION > 4
//    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
//#elif ENGINE_MINOR_VERSION > 26
//    FUniqueNetIdPtr UserId = GetUniquePlayerId(LocalUserNum);
//#elif ENGINE_MINOR_VERSION > 24
//    TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
//#endif
//
//    if (UserId.IsValid())
//    {
//        TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(*UserId);
//        if (UserAccount.IsValid())
//        {
//            return UserAccount->GetAccessToken();
//        }
//    }
//    return FString();
}

void FOnlineIdentityPico::RevokeAuthToken(const FUniqueNetId & UserId, const FOnRevokeAuthTokenCompleteDelegate & Delegate)
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::RevokeAuthToken not implemented"));
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdRef UserIdRef(UserId.AsShared());
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdRef UserIdRef(UserId.AsShared());
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetId> UserIdRef(UserId.AsShared());
#endif
    PicoSubsystem.ExecuteNextTick([UserIdRef, Delegate]()
        {
            Delegate.ExecuteIfBound(*UserIdRef, FOnlineError(FString(TEXT("RevokeAuthToken not implemented"))));
        });
}

void FOnlineIdentityPico::GetUserPrivilege(const FUniqueNetId & UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate & Delegate)
{
    // Not Supported
    Delegate.ExecuteIfBound(UserId, Privilege, (uint32)EPrivilegeResults::NoFailures);
}

FPlatformUserId FOnlineIdentityPico::GetPlatformUserIdFromUniqueNetId(const FUniqueNetId & UniqueNetId) const
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::GetPlatformUserIdFromUniqueNetId"));
    for (int i = 0; i < MAX_LOCAL_PLAYERS; ++i)
    {
        auto CurrentUniqueId = GetUniquePlayerId(i);
        if (CurrentUniqueId.IsValid() && (*CurrentUniqueId == UniqueNetId))
        {
#if ENGINE_MAJOR_VERSION > 4
            return GetPlatformUserIdFromLocalUserNum(i);
#elif ENGINE_MINOR_VERSION > 24
            return i;
#endif
        }
    }

    return PLATFORMUSERID_NONE;
}

#if ENGINE_MINOR_VERSION > 26
void FOnlineIdentityPico::GetLinkedAccountAuthToken(int32 LocalUserNum, const FOnGetLinkedAccountAuthTokenCompleteDelegate& Delegate) const
{
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_User_GetIdToken();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [Delegate, LocalUserNum](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FExternalAuthToken EmptyToken;
                Delegate.ExecuteIfBound(LocalUserNum, false, EmptyToken);
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                FString IDToken = ppf_Message_GetString(Message);
                FExternalAuthToken Token;
                Token.TokenString = IDToken;
                Delegate.ExecuteIfBound(LocalUserNum, true, Token);
            }
        }));
#endif
    FExternalAuthToken EmptyToken;
    Delegate.ExecuteIfBound(LocalUserNum, false, EmptyToken);
}
#endif

FString FOnlineIdentityPico::GetAuthType() const
{
    return TEXT("Pico");
}


UPico_User* FOnlineIdentityPico::GetLoginPicoUser(int32 LocalUserNum)
{
    if (LoginPicoUserMap.Contains(LocalUserNum))
    {
        return *LoginPicoUserMap.Find(LocalUserNum);
    }
    return nullptr;
}

void FOnlineIdentityPico::GetLoginUserOpenID(FGetIDToken OnGetIdTokenDelegate)
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::GetLoginUserOpenID"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_User_GetIdToken();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetIdTokenDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                OnGetIdTokenDelegate.ExecuteIfBound(true, ErrorMessage, FString());
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                FString IDToken = ppf_Message_GetString(Message);
                this->AuthToken = IDToken;
                OnGetIdTokenDelegate.ExecuteIfBound(false, FString(), IDToken);
            }
        }));
#endif
}

FOnlineIdentityPico::FOnlineIdentityPico(FOnlineSubsystemPico & InSubsystem)
    : PicoSubsystem(InSubsystem)
{
}

void FOnlineIdentityPico::OnLoginComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum)
{
    UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::OnLoginComplete"));
    if (!Message)
    {
        return;
    }
    UE_LOG_ONLINE_IDENTITY(Log, TEXT("Login Complete!"));
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        ErrorStr = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorStr = ErrorStr + FString(". Error Code: ") + ErrorCode;
    }
    else
    {
        auto User = ppf_Message_GetUser(Message);

        UPico_User* Userobj = NewObject<UPico_User>();
        Userobj->InitParams(User);
        FString Id = UTF8_TO_TCHAR(ppf_User_GetID(User));
        UE_LOG_ONLINE_IDENTITY(Display, TEXT("FOnlineIdentityPico::OnLoginComplete, %s"), *Id);

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
        FPicoUserInfo UserInfo;
        UserInfo.DisplayName = Name;
        UserInfo.Gender = Gender;
        UserInfo.ImageUrl = ImageUrl;
        UserInfo.UserId = Id;
        UserInfo.UserPresenceStatus = UserPresenceStatus;
        UE_LOG_ONLINE_IDENTITY(Log, TEXT("Pico login. %s"), *Id);
#if ENGINE_MAJOR_VERSION > 4
        FUniqueNetIdRef LocalUserId = FUniqueNetIdPico::Create(Id);
        if (!LocalUserId->IsValid())
        {
            ErrorStr = FString(TEXT("Unable to get a valid ID"));
        }
        else
        {
            UserIds.Add(LocalUserNum, LocalUserId);
            LoginPicoUserMap.Add(LocalUserNum, Userobj);
            // update/add cached entry for user
            UserAccounts.Add(LocalUserId, TSharedRef<FUserOnlineAccountPico>(new FUserOnlineAccountPico(LocalUserId, Name)));
            //UserInfos.Add(LocalUserNum, UserInfo);
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, *LocalUserId, *ErrorStr);
            TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::NotLoggedIn, ELoginStatus::LoggedIn, *LocalUserId);
            return;

        }
#elif ENGINE_MINOR_VERSION > 26
        FUniqueNetIdRef LocalUserId = FUniqueNetIdPico::Create(Id);
        if (!LocalUserId->IsValid())
        {
            ErrorStr = FString(TEXT("Unable to get a valid ID"));
        }
        else
        {
            UserIds.Add(LocalUserNum, LocalUserId);
            LoginPicoUserMap.Add(LocalUserNum, Userobj);
            // update/add cached entry for user
            UserAccounts.Add(LocalUserId, TSharedRef<FUserOnlineAccountPico>(new FUserOnlineAccountPico(LocalUserId, Name)));
            //UserInfos.Add(LocalUserNum, UserInfo);
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, *LocalUserId, *ErrorStr);
            TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::NotLoggedIn, ELoginStatus::LoggedIn, *LocalUserId);
            return;

        }
#elif ENGINE_MINOR_VERSION > 24
        TSharedPtr<const FUniqueNetId>* NewUserId = UserIds.Find(LocalUserNum);
        if (NewUserId == nullptr || !NewUserId->IsValid() || static_cast<const FUniqueNetIdPico>(*NewUserId->Get()).ToString() != Id)
        {
            UserIds.Add(LocalUserNum, MakeShareable(new FUniqueNetIdPico(Id)));
            NewUserId = UserIds.Find(LocalUserNum);
        }

        if (!NewUserId->IsValid())
        {
            ErrorStr = FString(TEXT("Unable to get a valid ID"));
        }
        else
        {
            TSharedRef<FUserOnlineAccountPico> UserAccountRef(new FUserOnlineAccountPico(NewUserId->ToSharedRef(), Name));
            LoginPicoUserMap.Add(LocalUserNum, Userobj);
            // update/add cached entry for user
            UserAccounts.Add(static_cast<FUniqueNetIdPico>(*UserAccountRef->GetUserId()), UserAccountRef);

            TriggerOnLoginCompleteDelegates(LocalUserNum, true, *UserAccountRef->GetUserId(), *ErrorStr);
            TriggerOnLoginStatusChangedDelegates(LocalUserNum, ELoginStatus::NotLoggedIn, ELoginStatus::LoggedIn, *UserAccountRef->GetUserId());
            return;
        }
#endif
    
    }

    TriggerOnLoginCompleteDelegates(LocalUserNum, false, *FUniqueNetIdPico::EmptyId(), *ErrorStr);

}

