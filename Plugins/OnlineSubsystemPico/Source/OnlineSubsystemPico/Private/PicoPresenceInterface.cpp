// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "PicoPresenceInterface.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineFriendsInterfacePico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PresenceInterface);

FPicoPresenceInterface::FPicoPresenceInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    OnJoinIntentReceivedHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Presence_JoinIntentReceived)
        .AddRaw(this, &FPicoPresenceInterface::OnJoinIntentReceiveResult);

    //OnLeaveIntentReceivedHandle =
    //    PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Presence_LeaveIntentReceived)
    //    .AddRaw(this, &FPicoPresenceInterface::OnLeaveIntentReceiveResult);
}

FPicoPresenceInterface::~FPicoPresenceInterface()
{
    if (OnJoinIntentReceivedHandle.IsValid())
    {
        OnJoinIntentReceivedHandle.Reset();
    }
    if (OnLeaveIntentReceivedHandle.IsValid())
    {
        OnLeaveIntentReceivedHandle.Reset();
    }
}

bool FPicoPresenceInterface::PresenceClear(const FOnPresenceClearComplete& Delegate /*= FOnPresenceClearComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceClear"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_Clear(),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceClearComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceClearComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceClearComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceClearComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::ReadInvitableUser(TArray<FString> SuggestedUserList, const FOnReadInvitableUserComplete& Delegate /*= FOnReadInvitableUserComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::ReadInvitableUser"));
    auto InviteOptionsHandle = ppf_InviteOptions_Create();
    ppf_InviteOptions_ClearSuggestedUsers(InviteOptionsHandle);
    for (FString User : SuggestedUserList)
    {
        ppf_InviteOptions_AddSuggestedUser(InviteOptionsHandle, TCHAR_TO_UTF8(*User));
    }

    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_GetInvitableUsers(InviteOptionsHandle),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryReadInvitableUserComplete(Message, bIsError, InvitableUsers, /*bAppendToExistingMap */ false, Delegate);
            }
        )
    );
    ppf_InviteOptions_Destroy(InviteOptionsHandle);
    return true;
}

void FPicoPresenceInterface::OnQueryReadInvitableUserComplete(ppfMessageHandle Message, bool bIsError, TMap<FString, TSharedRef<FOnlinePicoFriend>>& OutList, bool bAppendToExistingMap, const FOnReadInvitableUserComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryReadInvitableUserComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        UE_LOG_ONLINE_FRIEND(Log, TEXT("FPicoPresenceInterface::On Read Invitable User Complete Recive Failed :%s"), *ErrorMessage);
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    auto UserArray = ppf_Message_GetUserArray(Message);
    auto UserNum = ppf_UserArray_GetSize(UserArray);

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

        OutList.Add(FriendId, OnlineFriend);
    }
    bool bHasPaging = ppf_UserArray_HasNextPage(UserArray);
    if (bHasPaging)
    {

        PicoSubsystem.AddAsyncTask
        (
            ppf_User_GetNextUserArrayPage(ppf_UserArray_GetNextPageParam(UserArray)),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, &OutList, Delegate](ppfMessageHandle InMessage, bool bInIsError)
                {
                    OnQueryReadInvitableUserComplete(InMessage, bInIsError, OutList, /* bAppendToExistingMap */ true, Delegate);
                }
            )
        );
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::GetInvitableFriendList(TArray<TSharedRef<FOnlinePicoFriend>>& OutFriends)
{
    InvitableUsers.GenerateValueArray(OutFriends);
    return true;
}

bool FPicoPresenceInterface::PresenceSet(const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, const FOnPresenceSetComplete& Delegate /*= FOnPresenceSetComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSet"));
    auto PresenceOptions = ppf_PresenceOptions_Create();
    ppf_PresenceOptions_SetDestinationApiName(PresenceOptions, TCHAR_TO_UTF8(*ApiName));
    ppf_PresenceOptions_SetLobbySessionId(PresenceOptions, TCHAR_TO_UTF8(*LobbySessionId));
    ppf_PresenceOptions_SetMatchSessionId(PresenceOptions, TCHAR_TO_UTF8(*MatchSessionId));
    ppf_PresenceOptions_SetExtra(PresenceOptions, TCHAR_TO_UTF8(*Extra));
    ppf_PresenceOptions_SetIsJoinable(PresenceOptions, bIsJoinable);
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_Set(PresenceOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetComplete(Message, bIsError, Delegate);
            }
        )
    );
    ppf_PresenceOptions_Destroy(PresenceOptions);
    return true;

}

void FPicoPresenceInterface::OnQueryPresenceSetComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceSetDestination(const FString& ApiName, const FOnPresenceSetDestinationComplete& Delegate /*= FOnPresenceSetDestinationComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSetDestination"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SetDestination(TCHAR_TO_UTF8(*ApiName)),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetDestinationComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceSetDestinationComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetDestinationComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetDestinationComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceSetSetIsJoinable(bool bIsJoinable, const FOnPresenceSetIsJoinableComplete& Delegate /*= FOnPresenceSetIsJoinableComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSetSetIsJoinable"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SetIsJoinable(bIsJoinable),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetSetIsJoinableComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceSetSetIsJoinableComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetIsJoinableComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetSetIsJoinableComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceSetLobbySession(const FString& LobbySession, const FOnPresenceSetLobbySessionComplete& Delegate /*= FOnPresenceSetLobbySessionComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSetLobbySession"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SetLobbySession(TCHAR_TO_UTF8(*LobbySession)),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetLobbySessionComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceSetLobbySessionComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetLobbySessionComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetLobbySessionComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);

        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceSetMatchSession(const FString& MatchSession, const FOnPresenceSetMatchSessionComplete& Delegate /*= FOnPresenceSetMatchSessionComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSetMatchSession"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SetMatchSession(TCHAR_TO_UTF8(*MatchSession)),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetMatchSessionComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceSetMatchSessionComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetMatchSessionComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetMatchSessionComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceSetExtra(const FString& Extra, const FOnPresenceSetPresenceExtraComplete& Delegate /*= FOnPresenceSetPresenceExtraComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSetExtra"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SetExtra(TCHAR_TO_UTF8(*Extra)),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceSetExtraComplete(Message, bIsError, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceSetExtraComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetPresenceExtraComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceSetExtraComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceReadSendInvites(const FOnReadSentInvitesComplete& Delegate /*= FOnReadGetSentInvitesComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceReadSendInvites"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_GetSentInvites(),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryPresenceReadSendInvitesComplete(Message, bIsError, InvitesArray, /*bAppendToExistingMap */ false, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryPresenceReadSendInvitesComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoApplicationInvite>& OutList, bool bAppendToExistingMap, const FOnReadSentInvitesComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryPresenceReadSendInvitesComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    auto ApplicationInviteArray = ppf_Message_GetApplicationInviteArray(Message);
    auto ApplicationInviteArraySize = ppf_ApplicationInviteArray_GetSize(ApplicationInviteArray);

    if (!bAppendToExistingMap)
    {
        OutList.Empty(ApplicationInviteArraySize);
    }

    for (size_t ArrayIndex = 0; ArrayIndex < ApplicationInviteArraySize; ++ArrayIndex)
    {
        auto ApplicationInviteElement = ppf_ApplicationInviteArray_GetElement(ApplicationInviteArray, ArrayIndex);
        auto ApplicationInviteElementDestination = ppf_ApplicationInvite_GetDestination(ApplicationInviteElement);
        FPicoDestination Destination;
        Destination.ApiName = UTF8_TO_TCHAR(ppf_Destination_GetApiName(ApplicationInviteElementDestination));
        Destination.DeepLinkMessage = UTF8_TO_TCHAR(ppf_Destination_GetDeeplinkMessage(ApplicationInviteElementDestination));
        Destination.DisplayName = UTF8_TO_TCHAR(ppf_Destination_GetDisplayName(ApplicationInviteElementDestination));
        ppfID ID = ppf_ApplicationInvite_GetID(ApplicationInviteElement);
        // Do cast failed
        FString StrID = FString::Printf(TEXT("%llu"), ID);
        bool bIsActive = ppf_ApplicationInvite_GetIsActive(ApplicationInviteElement);
        FString LobbySessionId = UTF8_TO_TCHAR(ppf_ApplicationInvite_GetLobbySessionId(ApplicationInviteElement));
        FString MatchSessionId = UTF8_TO_TCHAR(ppf_ApplicationInvite_GetMatchSessionId(ApplicationInviteElement));
        auto ApplicationInviteElementUser = ppf_ApplicationInvite_GetRecipient(ApplicationInviteElement);
        FString FriendId = UTF8_TO_TCHAR(ppf_User_GetID(ApplicationInviteElementUser));
        FString FriendDisplayName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(ApplicationInviteElementUser));
        auto FriendInviteToken = ppf_User_GetInviteToken(ApplicationInviteElementUser);
        FString FriendInviteTokenString(UTF8_TO_TCHAR((FriendInviteToken != nullptr) ? FriendInviteToken : ""));
        FString SmallImageUrl = UTF8_TO_TCHAR(ppf_User_GetSmallImageUrl(ApplicationInviteElementUser));
        FString PresencePackage = UTF8_TO_TCHAR(ppf_User_GetPresencePackage(ApplicationInviteElementUser));
        FString ImageUrl = UTF8_TO_TCHAR(ppf_User_GetImageUrl(ApplicationInviteElementUser));
        ppfGender Gender = ppf_User_GetGender(ApplicationInviteElementUser);
        FString Presence = UTF8_TO_TCHAR(ppf_User_GetPresence(ApplicationInviteElementUser));
        FString PresenceDeeplinkMessage = UTF8_TO_TCHAR(ppf_User_GetPresenceDeeplinkMessage(ApplicationInviteElementUser));
        FString PresenceDestinationApiName = UTF8_TO_TCHAR(ppf_User_GetPresenceDestinationApiName(ApplicationInviteElementUser));
        FString PresenceLobbySessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceLobbySessionId(ApplicationInviteElementUser));
        FString PresenceMatchSessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceMatchSessionId(ApplicationInviteElementUser));
        auto FriendPresenceStatus = ppf_User_GetPresenceStatus(ApplicationInviteElementUser);
        FString PresenceExtra = ppf_User_GetPresenceExtra(ApplicationInviteElementUser);
        TSharedRef<FOnlinePicoFriend> OnlineFriend(new FOnlinePicoFriend(FriendId, FriendDisplayName, FriendPresenceStatus, FriendInviteTokenString,
            ImageUrl, Gender, SmallImageUrl, PresencePackage, Presence, PresenceDeeplinkMessage, PresenceDestinationApiName, PresenceLobbySessionId,
            PresenceMatchSessionId, PresenceExtra));
        EUserPresenceStatus PresenceStatus;
        if (FriendPresenceStatus == ppfUserPresenceStatus_OffLine)
        {
            PresenceStatus = EUserPresenceStatus::OffLine;
        }
        else if (FriendPresenceStatus == ppfUserPresenceStatus_OnLine)
        {
            PresenceStatus = EUserPresenceStatus::OnLine;
        }
        else
        {
            PresenceStatus = EUserPresenceStatus::Unknow;
        }
        FPicoUserInfo Friend;
        Friend.DisplayName = FriendDisplayName;
        Friend.UserPresenceStatus = PresenceStatus;
        Friend.UserId = FriendId;
        FPicoApplicationInvite PicoApplicationInvite;
        //       PicoApplicationInvite.Recipent = OnlineFriend;
        PicoApplicationInvite.Recipent = Friend;
        PicoApplicationInvite.bIsActive = bIsActive;
        PicoApplicationInvite.Destination = Destination;
        //        PicoApplicationInvite.Id = ID;
        PicoApplicationInvite.ID = StrID;
        PicoApplicationInvite.LobbySessionId = LobbySessionId;
        PicoApplicationInvite.MatchSessionId = MatchSessionId;
        OutList.Add(PicoApplicationInvite);
    }
    bool bHasPaging = ppf_ApplicationInviteArray_HasNextPage(ApplicationInviteArray);
    if (bHasPaging)
    {

        PicoSubsystem.AddAsyncTask
        (
            ppf_Presence_GetNextApplicationInviteArrayPage(ppf_ApplicationInviteArray_GetNextPageParam(ApplicationInviteArray)),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, &OutList, Delegate](ppfMessageHandle InMessage, bool bInIsError)
                {
                    OnQueryPresenceReadSendInvitesComplete(InMessage, bInIsError, OutList, /* bAppendToExistingMap */ true, Delegate);
                }
            )
        );
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::GetSendInvitesList(TArray<FPicoApplicationInvite>& OutList)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::GetSendInvitesList"));
    if (InvitesArray.Num() > 0)
    {
        OutList = InvitesArray;
        return true;
    }
    return false;
}

bool FPicoPresenceInterface::PresenceGetDestinations(const FOnGetDestinationsComplete& Delegate /*= FOnGetDestinationsComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceGetDestinations"));
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_GetDestinations(),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQueryGetDestinationsComplete(Message, bIsError, DestinationArray, /*bAppendToExistingMap */ false, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQueryGetDestinationsComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoDestination>& OutList, bool bAppendToExistingArray, const FOnGetDestinationsComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQueryGetDestinationsComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    auto GetDestinationArray = ppf_Message_GetDestinationArray(Message);
    auto DestinationArraySize = ppf_DestinationArray_GetSize(GetDestinationArray);

    if (!bAppendToExistingArray)
    {
        OutList.Empty(DestinationArraySize);
    }

    for (size_t ArrayIndex = 0; ArrayIndex < DestinationArraySize; ++ArrayIndex)
    {
        auto DestinationArrayElement = ppf_DestinationArray_GetElement(GetDestinationArray, ArrayIndex);
        FPicoDestination Destination;
        Destination.ApiName = UTF8_TO_TCHAR(ppf_Destination_GetApiName(DestinationArrayElement));
        Destination.DeepLinkMessage = UTF8_TO_TCHAR(ppf_Destination_GetDeeplinkMessage(DestinationArrayElement));
        Destination.DisplayName = UTF8_TO_TCHAR(ppf_Destination_GetDisplayName(DestinationArrayElement));

        OutList.Add(Destination);
    }
    bool bHasPaging = ppf_DestinationArray_HasNextPage(GetDestinationArray);
    if (bHasPaging)
    {

        PicoSubsystem.AddAsyncTask
        (
            ppf_Presence_GetNextDestinationArrayPage(ppf_DestinationArray_GetNextPageParam(GetDestinationArray)),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, &OutList, Delegate](ppfMessageHandle InMessage, bool bInIsError)
                {
                    OnQueryGetDestinationsComplete(InMessage, bInIsError, OutList, /* bAppendToExistingMap */ true, Delegate);
                }
            )
        );
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}

bool FPicoPresenceInterface::PresenceGetDestnationsList(TArray<FPicoDestination>& OutList)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceGetDescriptionList"));
    if (InvitesArray.Num() > 0)
    {
        OutList = DestinationArray;
        return true;
    }
    return false;
}

bool FPicoPresenceInterface::LaunchInvitePanel(const FOnLaunchInvitePanelComplete& Delegate /*= FOnLaunchInvitePanelComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::LaunchInvitePanel"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Presence_LaunchInvitePanel();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [Delegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PresenceInterface, Log, TEXT("LaunchInvitePanel return failed:%s"), *ErrorMessage);
                Delegate.ExecuteIfBound(false, ErrorMessage);
            }
            else
            {
                UE_LOG(PresenceInterface, Log, TEXT("LaunchInvitePanel return Sucessed"));
                Delegate.ExecuteIfBound(true, FString());
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoPresenceInterface::ShareMedia(EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, const FOnShareMediaComplete& Delegate /*= FOnShareMediaComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::ShareMedia"));
    if (InMediaType == EShareMediaType::None || InShareType == EShareAppTyp::None)
    {
        return false;
    }
#if PLATFORM_ANDROID
    auto ShareMediaOptions = ppf_ShareMediaOptions_Create();
    if (InMediaType == EShareMediaType::Video)
    {
        ppf_ShareMediaOptions_SetShareMediaType(ShareMediaOptions, ppfShareMediaType_Video);
    }
    else if (InMediaType == EShareMediaType::Image)
    {
        ppf_ShareMediaOptions_SetShareMediaType(ShareMediaOptions, ppfShareMediaType_Image);
    }
    ppf_ShareMediaOptions_SetVideoPath(ShareMediaOptions, TCHAR_TO_UTF8(*InVideoPath));
    ppf_ShareMediaOptions_SetVideoThumbPath(ShareMediaOptions, TCHAR_TO_UTF8(*InVideoThumbPath));
    for (FString Each : InImagePaths)
    {
        ppf_ShareMediaOptions_AddImagePath(ShareMediaOptions, TCHAR_TO_UTF8(*Each));
    }
    ppf_ShareMediaOptions_SetShareAppType(ShareMediaOptions, ppfShareAppType_Douyin);

    ppfRequest RequestId = ppf_Presence_ShareMedia(ShareMediaOptions);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [Delegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PresenceInterface, Log, TEXT("ShareMedia return failed:%s"), *ErrorMessage);
                Delegate.ExecuteIfBound(false, ErrorMessage);
            }
            else
            {
                UE_LOG(PresenceInterface, Log, TEXT("ShareMedia return Sucessed"));
                Delegate.ExecuteIfBound(true, FString());
            }
        }));
    ppf_ShareMediaOptions_Destroy(ShareMediaOptions);
    return true;
#endif
    return false;
}

void FPicoPresenceInterface::OnJoinIntentReceiveResult(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        UE_LOG(PresenceInterface, Error, TEXT("OnJoinIntentReceiveResult error!"));
        return;
    }
    auto PresenceJoinIntent = ppf_Message_GetPresenceJoinIntent(Message);
    FString DeeplinkMessage = UTF8_TO_TCHAR((ppf_PresenceJoinIntent_GetDeeplinkMessage(PresenceJoinIntent)));
    FString DestinationApiName = UTF8_TO_TCHAR((ppf_PresenceJoinIntent_GetDestinationApiName(PresenceJoinIntent)));
    FString LobbySessionId = UTF8_TO_TCHAR((ppf_PresenceJoinIntent_GetLobbySessionId(PresenceJoinIntent)));
    FString MatchSessionId = UTF8_TO_TCHAR((ppf_PresenceJoinIntent_GetMatchSessionId(PresenceJoinIntent)));
    FString Extra;
#if PLATFORM_ANDROID
    Extra = UTF8_TO_TCHAR((ppf_PresenceJoinIntent_GetExtra(PresenceJoinIntent)));
#endif
    UE_LOG(PresenceInterface, Log, TEXT("OnJoinIntentReceiveResult DeeplinkMessage: %s, DestinationApiName: %s, LobbySessionId: %s, MatchSessionId: %s, Extra: %s.!"), *DeeplinkMessage, *DestinationApiName, *LobbySessionId, *MatchSessionId, *Extra);
    JoinIntentReceivedCallback.Broadcast(DeeplinkMessage, DestinationApiName, LobbySessionId, MatchSessionId, Extra);
}

void FPicoPresenceInterface::OnLeaveIntentReceiveResult(ppfMessageHandle Message, bool bIsError)
{
    //if (bIsError)
    //{
    //    UE_LOG(PresenceInterface, Error, TEXT("OnLeaveIntentReceiveResult error!"));
    //    return;
    //}
    //auto PresenceLeaveIntent = ppf_Message_GetPresenceLeaveIntent(Message);
    //FString DestinationApiName = UTF8_TO_TCHAR((ppf_PresenceLeaveIntent_GetDestinationApiName(PresenceLeaveIntent)));
    //FString LobbySessionId = UTF8_TO_TCHAR((ppf_PresenceLeaveIntent_GetLobbySessionId(PresenceLeaveIntent)));
    //FString MatchSessionId = UTF8_TO_TCHAR((ppf_PresenceLeaveIntent_GetMatchSessionId(PresenceLeaveIntent)));

    //LeaveIntentReceivedCallback.Broadcast(DestinationApiName, LobbySessionId, MatchSessionId);
}

bool FPicoPresenceInterface::PresenceSendInvites(TArray<FString> UserIdArray, const FOnSentInvitesComplete& Delegate /*= FOnSentInvitesComplete()*/)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::PresenceSentInvites"));
    int32 Length = UserIdArray.Num();
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < UserIdArray.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(UserIdArray[i]))));
    }
    std::vector<const char*> CharPtrArray;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        CharPtrArray.push_back(StringArray[i].c_str());
    }
    PicoSubsystem.AddAsyncTask
    (
        ppf_Presence_SendInvites(CharPtrArray.data(), Length),
        FPicoMessageOnCompleteDelegate::CreateLambda
        (
            [this, Delegate](ppfMessageHandle Message, bool bIsError)
            {
                OnQuerySendInvitesComplete(Message, bIsError, InvitesArray, /*bAppendToExistingMap */ false, Delegate);
            }
        )
    );
    return true;
}

void FPicoPresenceInterface::OnQuerySendInvitesComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoApplicationInvite>& OutList, bool bAppendToExistingMap, const FOnSentInvitesComplete& Delegate)
{
    UE_LOG(PresenceInterface, Log, TEXT("FPicoPresenceInterface::OnQuerySendInvitesComplete"));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        Delegate.ExecuteIfBound(false, ErrorMessage);
        return;
    }
    auto SendInvitesResult = ppf_Message_GetSendInvitesResult(Message);
    auto ApplicationInviteArray = ppf_SendInvitesResult_GetInvites(SendInvitesResult);
    auto ApplicationInviteArraySize = ppf_ApplicationInviteArray_GetSize(ApplicationInviteArray);

    if (!bAppendToExistingMap)
    {
        OutList.Empty(ApplicationInviteArraySize);
    }

    for (size_t ArrayIndex = 0; ArrayIndex < ApplicationInviteArraySize; ++ArrayIndex)
    {
        auto ApplicationInviteElement = ppf_ApplicationInviteArray_GetElement(ApplicationInviteArray, ArrayIndex);
        auto ApplicationInviteElementDestination = ppf_ApplicationInvite_GetDestination(ApplicationInviteElement);
        FPicoDestination Destination;
        Destination.ApiName = UTF8_TO_TCHAR(ppf_Destination_GetApiName(ApplicationInviteElementDestination));
        Destination.DeepLinkMessage = UTF8_TO_TCHAR(ppf_Destination_GetDeeplinkMessage(ApplicationInviteElementDestination));
        Destination.DisplayName = UTF8_TO_TCHAR(ppf_Destination_GetDisplayName(ApplicationInviteElementDestination));
        ppfID ID = ppf_ApplicationInvite_GetID(ApplicationInviteElement);
        // Do cast failed
        FString StrID = FString::Printf(TEXT("%llu"), ID);
        bool bIsActive = ppf_ApplicationInvite_GetIsActive(ApplicationInviteElement);
        FString LobbySessionId = UTF8_TO_TCHAR(ppf_ApplicationInvite_GetLobbySessionId(ApplicationInviteElement));
        FString MatchSessionId = UTF8_TO_TCHAR(ppf_ApplicationInvite_GetMatchSessionId(ApplicationInviteElement));
        auto ApplicationInviteElementUser = ppf_ApplicationInvite_GetRecipient(ApplicationInviteElement);
        FString FriendId = UTF8_TO_TCHAR(ppf_User_GetID(ApplicationInviteElementUser));
        FString FriendDisplayName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(ApplicationInviteElementUser));
        auto FriendInviteToken = ppf_User_GetInviteToken(ApplicationInviteElementUser);
        FString FriendInviteTokenString(UTF8_TO_TCHAR((FriendInviteToken != nullptr) ? FriendInviteToken : ""));
        FString SmallImageUrl = UTF8_TO_TCHAR(ppf_User_GetSmallImageUrl(ApplicationInviteElementUser));
        FString PresencePackage = UTF8_TO_TCHAR(ppf_User_GetPresencePackage(ApplicationInviteElementUser));
        FString ImageUrl = UTF8_TO_TCHAR(ppf_User_GetImageUrl(ApplicationInviteElementUser));
        ppfGender Gender = ppf_User_GetGender(ApplicationInviteElementUser);
        FString Presence = UTF8_TO_TCHAR(ppf_User_GetPresence(ApplicationInviteElementUser));
        FString PresenceDeeplinkMessage = UTF8_TO_TCHAR(ppf_User_GetPresenceDeeplinkMessage(ApplicationInviteElementUser));
        FString PresenceDestinationApiName = UTF8_TO_TCHAR(ppf_User_GetPresenceDestinationApiName(ApplicationInviteElementUser));
        FString PresenceLobbySessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceLobbySessionId(ApplicationInviteElementUser));
        FString PresenceMatchSessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceMatchSessionId(ApplicationInviteElementUser));
        auto FriendPresenceStatus = ppf_User_GetPresenceStatus(ApplicationInviteElementUser);
        FString PresenceExtra = ppf_User_GetPresenceExtra(ApplicationInviteElementUser);
        TSharedRef<FOnlinePicoFriend> OnlineFriend(new FOnlinePicoFriend(FriendId, FriendDisplayName, FriendPresenceStatus, FriendInviteTokenString,
            ImageUrl, Gender, SmallImageUrl, PresencePackage, Presence, PresenceDeeplinkMessage, PresenceDestinationApiName, PresenceLobbySessionId,
            PresenceMatchSessionId, PresenceExtra));
        EUserPresenceStatus PresenceStatus;
        if (FriendPresenceStatus == ppfUserPresenceStatus_OffLine)
        {
            PresenceStatus = EUserPresenceStatus::OffLine;
        }
        else if (FriendPresenceStatus == ppfUserPresenceStatus_OnLine)
        {
            PresenceStatus = EUserPresenceStatus::OnLine;
        }
        else
        {
            PresenceStatus = EUserPresenceStatus::Unknow;
        }
        FPicoUserInfo Friend;
        Friend.DisplayName = FriendDisplayName;
        Friend.UserPresenceStatus = PresenceStatus;
        Friend.UserId = FriendId;
        FPicoApplicationInvite PicoApplicationInvite;
        //       PicoApplicationInvite.Recipent = OnlineFriend;
        PicoApplicationInvite.Recipent = Friend;
        PicoApplicationInvite.ID = StrID;
        PicoApplicationInvite.bIsActive = bIsActive;
        PicoApplicationInvite.Destination = Destination;
        //        PicoApplicationInvite.Id = ID;
        PicoApplicationInvite.LobbySessionId = LobbySessionId;
        PicoApplicationInvite.MatchSessionId = MatchSessionId;
        OutList.Add(PicoApplicationInvite);
    }
    bool bHasPaging = ppf_ApplicationInviteArray_HasNextPage(ApplicationInviteArray);
    if (bHasPaging)
    {

        PicoSubsystem.AddAsyncTask
        (
            ppf_Presence_GetNextApplicationInviteArrayPage(ppf_ApplicationInviteArray_GetNextPageParam(ApplicationInviteArray)),
            FPicoMessageOnCompleteDelegate::CreateLambda
            (
                [this, &OutList, Delegate](ppfMessageHandle InMessage, bool bInIsError)
                {
                    OnQueryPresenceReadSendInvitesComplete(InMessage, bInIsError, OutList, /* bAppendToExistingMap */ true, Delegate);
                }
            )
        );
    }
    else
    {
        Delegate.ExecuteIfBound(true, FString());
    }
}
