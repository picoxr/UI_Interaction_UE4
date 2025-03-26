// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineError.h"
#include "OnlineSubsystemPicoPackage.h"

const FString FOnlineFriendsPico::FriendsListInviteableUsers = TEXT("invitableUsers");
void FOnlineFriendsPico::OnQueryFriendsComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum, const FString& ListName, TMap<FString, TSharedRef<FOnlineFriend>>& OutList, bool bAppendToExistingMap, const FOnReadFriendsListComplete& Delegate)
{
    UE_LOG_ONLINE_FRIEND(Log, TEXT("PPF_GAME FOnlineFriendsPico::On Query Friends Complete Recive!"));
    FString ErrorStr;
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        auto ErrorMessage = ppf_Error_GetMessage(Error);
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        FString ErrorMessageStr = UTF8_TO_TCHAR(ErrorMessage) + FString(". Error Code: ") + ErrorCode;
        UE_LOG_ONLINE_FRIEND(Log, TEXT("PPF_GAME FOnlineFriendsPico::On Query Friends Complete Recive Failed :%s"), *ErrorMessageStr);
        ErrorStr = UTF8_TO_TCHAR(ErrorMessage);
        if (bAppendToExistingMap)
        {
            Delegate.ExecuteIfBound(LocalUserNum, true, ListName, ErrorStr);
            return;
        }
        Delegate.ExecuteIfBound(LocalUserNum, false, ListName, ErrorStr);
        return;
    }
    auto UserArray = ppf_Message_GetUserArray(Message);
    auto UserNum = ppf_UserArray_GetSize(UserArray);
    UE_LOG_ONLINE_FRIEND(Log, TEXT("PPF_GAME FOnlineFriendsPico::On Query Friends Complete FriendNum :%i"), UserNum);
    if (!bAppendToExistingMap)
    {
        OutList.Empty(UserNum);
    }

    for (size_t FriendIndex = 0; FriendIndex < UserNum; ++FriendIndex)
    {
        auto Friend = ppf_UserArray_GetElement(UserArray, FriendIndex);
        FString FriendId = UTF8_TO_TCHAR(ppf_User_GetID(Friend));
        FString FriendDisplayName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(Friend));
        auto FriendInviteToken = ppf_User_GetInviteToken(Friend);
        FString FriendInviteTokenString(UTF8_TO_TCHAR((FriendInviteToken != nullptr) ? FriendInviteToken : ""));
        FString SmallImageUrl = UTF8_TO_TCHAR(ppf_User_GetSmallImageUrl(Friend));
        FString PresencePackage = UTF8_TO_TCHAR(ppf_User_GetPresencePackage(Friend));
        FString ImageUrl = UTF8_TO_TCHAR(ppf_User_GetImageUrl(Friend));
        ppfGender Gender = ppf_User_GetGender(Friend);
        FString Presence = UTF8_TO_TCHAR(ppf_User_GetPresence(Friend));
        FString PresenceDeeplinkMessage = UTF8_TO_TCHAR(ppf_User_GetPresenceDeeplinkMessage(Friend));
        FString PresenceDestinationApiName = UTF8_TO_TCHAR(ppf_User_GetPresenceDestinationApiName(Friend));
        FString PresenceLobbySessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceLobbySessionId(Friend));
        FString PresenceMatchSessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceMatchSessionId(Friend));
        auto FriendPresenceStatus = ppf_User_GetPresenceStatus(Friend);
        FString PresenceExtra = ppf_User_GetPresenceExtra(Friend);
        TSharedRef<FOnlinePicoFriend> OnlineFriend(new FOnlinePicoFriend(FriendId, FriendDisplayName, FriendPresenceStatus, FriendInviteTokenString,
            ImageUrl, Gender, SmallImageUrl, PresencePackage, Presence, PresenceDeeplinkMessage, PresenceDestinationApiName, PresenceLobbySessionId,
            PresenceMatchSessionId, PresenceExtra));

        UE_LOG_ONLINE(Display, TEXT("PPF_GAME add friend in outlist: FriendId: %s, DisplayName: %s, InviteToken: %s"), *FriendId, *FriendDisplayName, *FriendInviteTokenString);
        OutList.Add(FriendId, OnlineFriend);
    }
    bool bHasPaging = ppf_UserArray_HasNextPage(UserArray);
    if (bHasPaging)
    {
        UE_LOG_ONLINE_FRIEND(Log, TEXT("FOnlineFriendsPico::GetNextUserArray!"));
        PicoSubsystem.AddAsyncTask
        (
            ppf_User_GetNextUserArrayPage(ppf_UserArray_GetNextPageParam(UserArray)),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, LocalUserNum, ListName, &OutList, Delegate](ppfMessageHandle InMessage, bool bInIsError)
                {
                    OnQueryFriendsComplete(InMessage, bInIsError, LocalUserNum, ListName, OutList, /* bAppendToExistingMap */ true, Delegate);
                }
            )
        );
    }
    else
    {
        Delegate.ExecuteIfBound(LocalUserNum, true, ListName, ErrorStr);
    }
}

FOnlineFriendsPico::FOnlineFriendsPico(FOnlineSubsystemPico& InSubsystem)
    :PicoSubsystem(InSubsystem)
{

}

bool FOnlineFriendsPico::ReadFriendsList(int32 LocalUserNum, const FString& ListName, const FOnReadFriendsListComplete& Delegate /*= FOnReadFriendsListComplete()*/)
{
    UE_LOG_ONLINE_FRIEND(Log, TEXT("FOnlineFriendsPico::ReadFriendsList!"));
    if (ListName == EFriendsLists::ToString(EFriendsLists::Default) || ListName == EFriendsLists::ToString(EFriendsLists::OnlinePlayers))
    {
        PicoSubsystem.AddAsyncTask
        (
            ppf_User_GetLoggedInUserFriends(),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, LocalUserNum, ListName, Delegate](ppfMessageHandle Message, bool bIsError)
                {
                    OnQueryFriendsComplete(Message, bIsError, LocalUserNum, ListName, PlayerFriends, /*bAppendToExistingMap */ false, Delegate);
                }
            )
        );
        return true;
    }
    if (ListName == FriendsListInviteableUsers)
    {
        return false;
    }
    Delegate.ExecuteIfBound(LocalUserNum, false, ListName, TEXT("Invalid friends list"));
    return false;

}

bool FOnlineFriendsPico::ReadFriendsList(int32 LocalUserNum, const FString& ListName, ppfID RoomId, const FOnReadFriendsListComplete& Delegate /*= FOnReadFriendsListComplete()*/)
{
    if (ListName == FriendsListInviteableUsers)
    {
        auto RoomOptions = ppf_RoomOptions_Create();
        ppf_RoomOptions_SetRoomId(RoomOptions, RoomId);

        PicoSubsystem.AddAsyncTask
        (
            ppf_Room_GetInvitableUsers2(RoomOptions),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, LocalUserNum, ListName, Delegate](ppfMessageHandle Message, bool bIsError)
                {
                    OnQueryFriendsComplete(Message, bIsError, LocalUserNum, ListName, InvitableUsers, /* bAppendToExistingMap */ false, Delegate);
                }
            )
        );
        ppf_RoomOptions_Destroy(RoomOptions);
        return true;
    }
    Delegate.ExecuteIfBound(LocalUserNum, false, ListName, TEXT("List invaild, Invitablelist only."));
    return false;
}

bool FOnlineFriendsPico::DeleteFriendsList(int32 LocalUserNum, const FString& ListName, const FOnDeleteFriendsListComplete& Delegate /*= FOnDeleteFriendsListComplete()*/)
{
    // Not Supported
    Delegate.ExecuteIfBound(LocalUserNum, false, ListName, TEXT("Not implemented"));
    return false;
}

bool FOnlineFriendsPico::SendInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnSendInviteComplete& Delegate /*= FOnSendInviteComplete()*/)
{
    // Not Supported
    Delegate.ExecuteIfBound(LocalUserNum, false, FriendId, ListName, TEXT("Not implemented"));
    return false;
}

bool FOnlineFriendsPico::AcceptInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnAcceptInviteComplete& Delegate /*= FOnAcceptInviteComplete()*/)
{
    // Not Supported
    Delegate.ExecuteIfBound(LocalUserNum, false, FriendId, ListName, TEXT("Not implemented"));
    return false;
}

bool FOnlineFriendsPico::RejectInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName)
{
    // Not Supported
    return false;
}

void FOnlineFriendsPico::SetFriendAlias(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FString& Alias, const FOnSetFriendAliasComplete& Delegate /*= FOnSetFriendAliasComplete()*/)
{
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdRef FriendIdRef = FriendId.AsShared();
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdRef FriendIdRef = FriendId.AsShared();
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetId> FriendIdRef = FriendId.AsShared();
#endif
    PicoSubsystem.ExecuteNextTick
    (
        [LocalUserNum, FriendIdRef, ListName, Delegate]()
        {
            UE_LOG_ONLINE_FRIEND(Warning, TEXT("FOnlineFriendsPico::SetFriendAlias is not implemented"));
            Delegate.ExecuteIfBound(LocalUserNum, *FriendIdRef, ListName, FOnlineError(EOnlineErrorResult::NotImplemented));
        }
    );
}

void FOnlineFriendsPico::DeleteFriendAlias(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnDeleteFriendAliasComplete& Delegate /*= FOnDeleteFriendAliasComplete()*/)
{
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdRef FriendIdRef = FriendId.AsShared();
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdRef FriendIdRef = FriendId.AsShared();
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetId> FriendIdRef = FriendId.AsShared();
#endif
    PicoSubsystem.ExecuteNextTick
    (
        [LocalUserNum, FriendIdRef, ListName, Delegate]()
        {
            UE_LOG_ONLINE_FRIEND(Warning, TEXT("FOnlineFriendsPico::DeleteFriendAlias is not implemented"));
            Delegate.ExecuteIfBound(LocalUserNum, *FriendIdRef, ListName, FOnlineError(EOnlineErrorResult::NotImplemented));
        }
    );
}

bool FOnlineFriendsPico::DeleteFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName)
{
    // Not Supported
    return false;
}

bool FOnlineFriendsPico::GetFriendsList(int32 LocalUserNum, const FString& ListName, TArray< TSharedRef<FOnlineFriend> >& OutFriends)
{
    UE_LOG_ONLINE_FRIEND(Log, TEXT("FOnlineFriendsPico::GetFriendsList!"));
    if (ListName == EFriendsLists::ToString(EFriendsLists::Default))
    {
        PlayerFriends.GenerateValueArray(OutFriends);
        return true;
    }
    if (ListName == EFriendsLists::ToString(EFriendsLists::OnlinePlayers))
    {
        for (auto Friend : PlayerFriends)
        {
            if (Friend.Value->GetPresence().bIsOnline)
            {
                OutFriends.Add(Friend.Value);
            }
        }
        return true;
    }
    if (ListName == FriendsListInviteableUsers)
    {
        InvitableUsers.GenerateValueArray(OutFriends);
        return true;
    }

    return false;
}

TSharedPtr<FOnlineFriend> FOnlineFriendsPico::GetFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName)
{
    UE_LOG_ONLINE_FRIEND(Log, TEXT("FOnlineFriendsPico::GetFriend!"));
    auto PicoFriendId = static_cast<const FUniqueNetIdPico&>(FriendId);

    UE_LOG_ONLINE(Display, TEXT("PPF_GAME GetFriend PicoFriendId.GetStringID(): %s"), *PicoFriendId.GetStringID());
    if (ListName == EFriendsLists::ToString(EFriendsLists::Default))
    {
        if (!PlayerFriends.Contains(PicoFriendId.GetStringID()))
        {
            return nullptr;
        }
        return PlayerFriends[PicoFriendId.GetStringID()];
    }

    if (ListName == EFriendsLists::ToString(EFriendsLists::OnlinePlayers))
    {
        if (!PlayerFriends.Contains(PicoFriendId.GetStringID()))
        {
            return nullptr;
        }

        auto Friend = PlayerFriends[PicoFriendId.GetStringID()];
        if (!Friend->GetPresence().bIsOnline)
        {
            return nullptr;
        }

        return Friend;
    }

    if (ListName == FriendsListInviteableUsers)
    {
        if (!InvitableUsers.Contains(PicoFriendId.GetStringID()))
        {
            return nullptr;
        }
        return InvitableUsers[PicoFriendId.GetStringID()];
    }

    return nullptr;
}

bool FOnlineFriendsPico::IsFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName)
{
    UE_LOG_ONLINE_FRIEND(Log, TEXT("FOnlineFriendsPico::IsFriend!"));
    auto Friend = GetFriend(0, FriendId, ListName);
    return Friend.IsValid();
}

bool FOnlineFriendsPico::QueryRecentPlayers(const FUniqueNetId& UserId, const FString& Namespace)
{
    // Not Supported
    return false;
}

bool FOnlineFriendsPico::GetRecentPlayers(const FUniqueNetId& UserId, const FString& Namespace, TArray< TSharedRef<FOnlineRecentPlayer> >& OutRecentPlayers)
{
    // Not Supported
    return false;
}

void FOnlineFriendsPico::DumpRecentPlayers() const
{

}

bool FOnlineFriendsPico::BlockPlayer(int32 LocalUserNum, const FUniqueNetId& PlayerId)
{
    // Not Supported
    return false;
}

bool FOnlineFriendsPico::UnblockPlayer(int32 LocalUserNum, const FUniqueNetId& PlayerId)
{
    // Not Supported
    return false;
}

bool FOnlineFriendsPico::QueryBlockedPlayers(const FUniqueNetId& UserId)
{
    // Not Supported
    return false;
}

bool FOnlineFriendsPico::GetBlockedPlayers(const FUniqueNetId& UserId, TArray< TSharedRef<FOnlineBlockedPlayer> >& OutBlockedPlayers)
{
    // Not Supported
    return false;
}

void FOnlineFriendsPico::DumpBlockedPlayers() const
{
    // Not Supported
}
