// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_User.h"
#include "Pico_Room.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PicoUser);

void UOnlinePicoUserFunction::PicoGetLoggedInUserAndRoom(UObject* WorldContextObject, FGetLoggedInUserFriendsAndRooms InGetLoggedInuserFriendsAndRoomsCallback)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::PicoGetLoggedInUserAndRoom"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        Subsystem->GetPicoUserInterface()->GetLoggedInUserAndRoom(InGetLoggedInuserFriendsAndRoomsCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("PicoGetLoggedInUserAndRoom Failed, PicoUserInterface Not Vailed!"));
        InGetLoggedInuserFriendsAndRoomsCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoUserFunction::PicoGetNextUserAndRoomArrayPage(UObject* WorldContextObject, UPico_UserAndRoomArray* InUserAndRoomArray, FGetNextUserAndRoomArrayPage InGetNextUserAndRoomArrayPageCallback)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::PicoGetNextUserAndRoomArrayPage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        Subsystem->GetPicoUserInterface()->GetNextUserAndRoomArrayPage(InUserAndRoomArray, InGetNextUserAndRoomArrayPageCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("PicoGetNextUserAndRoomArrayPage Failed, PicoUserInterface Not Vailed!"));
        InGetNextUserAndRoomArrayPageCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoUserFunction::PicoGetUserFriends(UObject* WorldContextObject, FGetLoggedInUserFriends InGetLoggedInUserFriendsDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::PicoGetUserFriends"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        Subsystem->GetPicoUserInterface()->GetUserFriends(InGetLoggedInUserFriendsDelegate);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("PicoGetUserFriends Failed, PicoUserInterface Not Vailed!"));
        InGetLoggedInUserFriendsDelegate.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoUserFunction::PicoGetNextUserPage(UObject* WorldContextObject, UPico_UserArray* InUserArray, FGetNextUserPage InGetNextUserPageDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::PicoGetNextUserPage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        Subsystem->GetPicoUserInterface()->GetNextUserPage(InUserArray, InGetNextUserPageDelegate);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("PicoGetNextUserFriendsPage Failed, PicoUserInterface Not Vailed!"));
        InGetNextUserPageDelegate.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
    }
}

bool UOnlinePicoUserFunction::GetLoginUser(UObject* WorldContextObject, FGetLoginUser InGetLoginUserDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::GetLoginUser"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetLoginUser(InGetLoginUserDelegate);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetLoginUser Failed, PicoUserInterface Not Vailed!"));
        InGetLoginUserDelegate.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoUserFunction::GetPicoUserInfo(UObject* WorldContextObject, const FString& UserId, FGetUserInfo InGetUserInfoDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("UOnlinePicoUserFunction::GetPicoUserInfo"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetUserInfo(UserId, InGetUserInfoDelegate);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetPicoUserInfo Failed, PicoUserInterface Not Vailed!"));
        InGetUserInfoDelegate.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoUserFunction::GetAuthorizePermissions(UObject* WorldContextObject, FGetPermissionResult OnGetPermissionResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetAuthorizePermissions(OnGetPermissionResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetAuthorizePermissions Failed, PicoUserInterface Not Vailed!"));
        OnGetPermissionResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoUserFunction::RequestUserPermissions(UObject* WorldContextObject, TArray<FString> Permissions, FGetPermissionResult OnGetPermissionResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->RequestUserPermissions(Permissions, OnGetPermissionResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("RequestUserPermissions Failed, PicoUserInterface Not Vailed!"));
        OnGetPermissionResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}


bool UOnlinePicoUserFunction::LaunchFriendRequestFlow(UObject* WorldContextObject, const FString UserId, FLaunchFriendRequestResult OnLaunchFriendRequestResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->LaunchFriendRequestFlow(UserId, OnLaunchFriendRequestResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("LaunchFriendRequestFlow Failed, PicoUserInterface Not Vailed!"));
        OnLaunchFriendRequestResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), false, false);
        return false;
    }
}

bool UOnlinePicoUserFunction::GetAccessToken(UObject* WorldContextObject, FGetAccessTokenResult OnGetAccessTokenResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetAccessToken(OnGetAccessTokenResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetAccessToken Failed, PicoUserInterface Not Vailed!"));
        OnGetAccessTokenResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), FString());
        return false;
    }
}


bool UOnlinePicoUserFunction::GetRelations(UObject* WorldContextObject, TArray<FString> UserIDs, FGetUserRelationResult OnGetUserRelationResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetRelations(UserIDs, OnGetUserRelationResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetRelations Failed, PicoUserInterface Not Vailed!"));
        OnGetUserRelationResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoUserFunction::EntitlementCheck(UObject* WorldContextObject, bool bKillApp, FEntitlementCheckResult OnEntitlementCheckResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->EntitlementCheck(bKillApp, OnEntitlementCheckResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("EntitlementCheck Failed, PicoUserInterface Not Vailed!"));
        OnEntitlementCheckResultCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoUserFunction::GetIDToken(UObject* WorldContextObject, FGetIDToken OnGetIDTokenResultCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetIDToken(OnGetIDTokenResultCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("GetIDToken Failed, PicoUserInterface Not Vailed!"));
        OnGetIDTokenResultCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), FString());
        return false;
    }
}

bool UOnlinePicoUserFunction::GetOrgScopedID(UObject* WorldContextObject, const FString& UserId, FGetOrgScopedID OnGetOrgScopedIDCallback)
{
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoUserInterface())
    {
        return Subsystem->GetPicoUserInterface()->GetOrgScopedID(UserId, OnGetOrgScopedIDCallback);
    }
    else
    {
        UE_LOG(PicoUser, Log, TEXT("EntitlementCheck Failed, PicoUserInterface Not Vailed!"));
        OnGetOrgScopedIDCallback.ExecuteIfBound(true, FString(TEXT("PicoUserInterface Not Vailed")), nullptr);
        return false;
    }
}

void UPico_User::InitParams(ppfUser* ppfUserHandle)
{
    UE_LOG(PicoUser, Log, TEXT("UPico_User::InitParams"));

    DisplayName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(ppfUserHandle));
    ImageUrl = UTF8_TO_TCHAR(ppf_User_GetImageUrl(ppfUserHandle));
    ID = UTF8_TO_TCHAR(ppf_User_GetID(ppfUserHandle));
    InviteToken = UTF8_TO_TCHAR(ppf_User_GetInviteToken(ppfUserHandle));
    SmallImageUrl = UTF8_TO_TCHAR(ppf_User_GetSmallImageUrl(ppfUserHandle));
    PresencePackage = UTF8_TO_TCHAR(ppf_User_GetPresencePackage(ppfUserHandle));
    ppfUserPresenceStatus ppfUPS = ppf_User_GetPresenceStatus(ppfUserHandle);
    if (ppfUPS == ppfUserPresenceStatus_OffLine)
    {
        UserPresenceStatus = EUserPresenceStatus::OffLine;
    }
    else if (ppfUPS == ppfUserPresenceStatus_OnLine)
    {
        UserPresenceStatus = EUserPresenceStatus::OnLine;
    }
    ppfGender ppfG = ppf_User_GetGender(ppfUserHandle);
    if (ppfG == ppfGender_Female)
    {
        UserGender = EUserGender::Female;
    }
    else if (ppfG == ppfGender_Male)
    {
        UserGender = EUserGender::Male;
    }
    Presence = UTF8_TO_TCHAR(ppf_User_GetPresence(ppfUserHandle));
    PresenceDeeplinkMessage = UTF8_TO_TCHAR(ppf_User_GetPresenceDeeplinkMessage(ppfUserHandle));
    PresenceDestinationApiName = UTF8_TO_TCHAR(ppf_User_GetPresenceDestinationApiName(ppfUserHandle));
    PresenceLobbySessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceLobbySessionId(ppfUserHandle));
    PresenceMatchSessionId = UTF8_TO_TCHAR(ppf_User_GetPresenceMatchSessionId(ppfUserHandle));
    PresenceExtra = UTF8_TO_TCHAR(ppf_User_GetPresenceExtra(ppfUserHandle));
    StoreRegion = UTF8_TO_TCHAR(ppf_User_GetStoreRegion(ppfUserHandle));
#if PLATFORM_ANDROID
    PresenceIsJoinable = ppf_User_GetPresenceIsJoinable(ppfUserHandle);
#endif

}

FString UPico_User::GetDisplayName()
{
    return DisplayName;
}

FString UPico_User::GetImageURL()
{
    return ImageUrl;
}

FString UPico_User::GetID()
{
    return ID;
}

FString UPico_User::GetInviteToken()
{
    return InviteToken;
}

FString UPico_User::GetSmallImageUrl()
{
    return SmallImageUrl;
}

FString UPico_User::GetPresencePackage()
{
    return PresencePackage;
}

EUserPresenceStatus UPico_User::GetUserPresenceStatus()
{
    return UserPresenceStatus;
}

EUserGender UPico_User::GetGender()
{
    return UserGender;
}

FString UPico_User::GetPresence()
{
    return Presence;
}

FString UPico_User::GetPresenceDeeplinkMessage()
{
    return PresenceDeeplinkMessage;
}

FString UPico_User::GetPresenceDestinationApiName()
{
    return PresenceDestinationApiName;
}

FString UPico_User::GetPresenceLobbySessionId()
{
    return PresenceLobbySessionId;
}

FString UPico_User::GetPresenceMatchSessionId()
{
    return PresenceMatchSessionId;
}

FString UPico_User::GetPresenceExtra()
{
    return PresenceExtra;
}

FString UPico_User::GetStoreRegion()
{
    return StoreRegion;
}

bool UPico_User::GetPresenceIsJoinable()
{
    return PresenceIsJoinable;
}

void UPico_UserArray::InitParams(ppfUserArray* InppfUserArrayHandle)
{
    UE_LOG(PicoUser, Log, TEXT("UPico_UserArray::InitParams"));
    Size = ppf_UserArray_GetSize(InppfUserArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_User* ThisElement = NewObject<UPico_User>();
        ThisElement->InitParams(ppf_UserArray_GetElement(InppfUserArrayHandle, i));
        UserArray.Add(ThisElement);
    }
    bHasNextPage = ppf_UserArray_HasNextPage(InppfUserArrayHandle);

    NextPageParam = FString();
    if (bHasNextPage)
    {
        NextPageParam = ppf_UserArray_GetNextPageParam(InppfUserArrayHandle);
    }
}

UPico_User* UPico_UserArray::GetElement(int32 Index)
{
    if (UserArray.IsValidIndex(Index))
    {
        return UserArray[Index];
    }
    return nullptr;
}

FString UPico_UserArray::GetNextPageParam()
{
    return NextPageParam;
}

int32 UPico_UserArray::GetSize()
{
    return Size;
}

bool UPico_UserArray::HasNextPage()
{
    return bHasNextPage;
}

void UPico_UserAndRoom::InitParams(ppfUserAndRoom* InppfUserAndRoomHandle)
{
    UE_LOG(PicoUser, Log, TEXT("UPico_UserAndRoom::InitParams"));
    Room = NewObject<UPico_Room>();
    Room->InitParams(ppf_UserAndRoom_GetRoom(InppfUserAndRoomHandle));
    User = NewObject<UPico_User>();
    User->InitParams(ppf_UserAndRoom_GetUser(InppfUserAndRoomHandle));
}

UPico_Room* UPico_UserAndRoom::GetRoom()
{
    return Room;
}

UPico_User* UPico_UserAndRoom::GetUser()
{
    return User;
}



void UPico_UserAndRoomArray::InitParams(ppfUserAndRoomArray* InppfUserAndRoomArrayHandle)
{
    UE_LOG(PicoUser, Log, TEXT("UPico_UserAndRoomArray::InitParams"));
    Size = ppf_UserAndRoomArray_GetSize(InppfUserAndRoomArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_UserAndRoom* ThisElement = NewObject<UPico_UserAndRoom>();
        ThisElement->InitParams(ppf_UserAndRoomArray_GetElement(InppfUserAndRoomArrayHandle, i));
        UserAndRoomArray.Add(ThisElement);
    }
    bHasNextPage = ppf_UserAndRoomArray_HasNextPage(InppfUserAndRoomArrayHandle);
    NextPageParam = FString();
    if (bHasNextPage)
    {
        NextPageParam = ppf_UserAndRoomArray_GetNextPageParam(InppfUserAndRoomArrayHandle);
    }
}

UPico_UserAndRoom* UPico_UserAndRoomArray::GetElement(int32 Index)
{
    if (UserAndRoomArray.IsValidIndex(Index))
    {
        return UserAndRoomArray[Index];
    }
    return nullptr;
}

FString UPico_UserAndRoomArray::GetNextPageParam()
{
    return NextPageParam;
}

int32 UPico_UserAndRoomArray::GetSize()
{
    return Size;
}

bool UPico_UserAndRoomArray::HasNextPage()
{
    return bHasNextPage;
}

FPicoUserInterface::FPicoUserInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoUserInterface::~FPicoUserInterface()
{

}

bool FPicoUserInterface::GetLoginUser(FGetLoginUser InGetLoginUserDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetLoginUser"));
    ppfRequest RequestId = ppf_User_GetLoggedInUser();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetLoginUserDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetLoginUser return failed:%s"), *ErrorMessage);
                this->GetLoginUserDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetLoginUserDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetLoginUser Successfully"));
                UPico_User* Pico_User = NewObject<UPico_User>();
                Pico_User->InitParams(ppf_Message_GetUser(Message));
                this->GetLoginUserDelegate.ExecuteIfBound(false, FString(), Pico_User);
                InGetLoginUserDelegate.ExecuteIfBound(false, FString(), Pico_User);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetUserInfo(const FString& UserId, FGetUserInfo InGetUserInfoDelegate)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetUserInfo"));
    ppfRequest RequestId = ppf_User_Get(TCHAR_TO_UTF8(*UserId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetUserInfoDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetUserInfo return failed:%s"), *ErrorMessage);
                this->GetUserInfoDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetUserInfoDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetUserInfo Successfully"));
                UPico_User* Pico_User = NewObject<UPico_User>();
                Pico_User->InitParams(ppf_Message_GetUser(Message));
                this->GetUserInfoDelegate.ExecuteIfBound(false, FString(), Pico_User);
                InGetUserInfoDelegate.ExecuteIfBound(false, FString(), Pico_User);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetLoggedInUserAndRoom(FGetLoggedInUserFriendsAndRooms InGetLoggedInuserFriendsAndRoomsCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetLoggedInUserAndRoom"));
    ppfRequest RequestId = ppf_User_GetLoggedInUserFriendsAndRooms();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetLoggedInuserFriendsAndRoomsCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetLoggedInUserAndRoom return failed:%s"), *ErrorMessage);
                this->GetLoggedInUserFriendsAndRoomsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetLoggedInuserFriendsAndRoomsCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetLoggedInUserAndRoom Successfully"));
                UPico_UserAndRoomArray* LoggedInUserFriendsAndRooms = NewObject<UPico_UserAndRoomArray>();
                LoggedInUserFriendsAndRooms->InitParams(ppf_Message_GetUserAndRoomArray(Message));
                this->GetLoggedInUserFriendsAndRoomsDelegate.ExecuteIfBound(false, FString(), LoggedInUserFriendsAndRooms);
                InGetLoggedInuserFriendsAndRoomsCallback.ExecuteIfBound(false, FString(), LoggedInUserFriendsAndRooms);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetNextUserAndRoomArrayPage(UPico_UserAndRoomArray* InUserAndRoomArray, FGetNextUserAndRoomArrayPage InGetNextUserAndRoomArrayPageCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetNextUserAndRoomArrayPage"));
    ppfRequest RequestId = ppf_User_GetNextUserAndRoomArrayPage(TCHAR_TO_UTF8(*InUserAndRoomArray->GetNextPageParam()));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetNextUserAndRoomArrayPageCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetNextUserAndRoomArrayPage return failed:%s"), *ErrorMessage);
                this->GetNextUserAndRoomArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetNextUserAndRoomArrayPageCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetNextUserAndRoomArrayPage Successfully"));
                UPico_UserAndRoomArray* NextUserAndRoomArrayPage = NewObject<UPico_UserAndRoomArray>();
                NextUserAndRoomArrayPage->InitParams(ppf_Message_GetUserAndRoomArray(Message));
                this->GetNextUserAndRoomArrayPageDelegate.ExecuteIfBound(false, FString(), NextUserAndRoomArrayPage);
                InGetNextUserAndRoomArrayPageCallback.ExecuteIfBound(false, FString(), NextUserAndRoomArrayPage);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetUserFriends(FGetLoggedInUserFriends InGetLoggedInUserFriendsCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetUserFriends"));
    ppfRequest RequestId = ppf_User_GetLoggedInUserFriends();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetLoggedInUserFriendsCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetUserFriends return failed:%s"), *ErrorMessage);
                this->GetLoggedInUserFriendsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetLoggedInUserFriendsCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetUserFriends return Sucessed"));
                auto LoggedInUserFriends = NewObject<UPico_UserArray>();
                LoggedInUserFriends->InitParams(ppf_Message_GetUserArray(Message));
                this->GetLoggedInUserFriendsDelegate.ExecuteIfBound(false, FString(), LoggedInUserFriends);
                InGetLoggedInUserFriendsCallback.ExecuteIfBound(false, FString(), LoggedInUserFriends);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetNextUserPage(UPico_UserArray* InUserArray, FGetNextUserPage OnGetNextUserPageCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetNextUserPage"));
    ppfRequest RequestId = ppf_User_GetNextUserArrayPage(TCHAR_TO_UTF8(*InUserArray->GetNextPageParam()));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetNextUserPageCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetNextUserPage return failed:%s"), *ErrorMessage);
                this->GetNextUserFriendsPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                OnGetNextUserPageCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                UE_LOG(PicoUser, Log, TEXT("GetNextUserPage Successfully"));
                UPico_UserArray* NextUserArrayPage = NewObject<UPico_UserArray>();
                NextUserArrayPage->InitParams(ppf_Message_GetUserArray(Message));
                this->GetNextUserFriendsPageDelegate.ExecuteIfBound(false, FString(), NextUserArrayPage);
                OnGetNextUserPageCallback.ExecuteIfBound(false, FString(), NextUserArrayPage);
            }
        }));
    return true;
}

bool FPicoUserInterface::LaunchFriendRequestFlow(const FString& UserId, FLaunchFriendRequestResult OnLaunchFriendRequestResultCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::LaunchFriendRequestFlow"));
    ppfRequest RequestId = ppf_User_LaunchFriendRequestFlow(TCHAR_TO_UTF8(*UserId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnLaunchFriendRequestResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("LaunchFriendRequestFlow return failed:%s"), *ErrorMessage);
                this->LaunchFriendRequestDelegate.ExecuteIfBound(true, ErrorMessage, false, false);
                OnLaunchFriendRequestResultCallback.ExecuteIfBound(true, ErrorMessage, false, false);
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                UE_LOG(PicoUser, Log, TEXT("LaunchFriendRequestFlow Successfully"));
                auto LaunchFriendRequestFlowResult = ppf_Message_GetLaunchFriendRequestFlowResult(Message);
                bool bDidCancel = ppf_LaunchFriendRequestFlowResult_GetDidCancel(LaunchFriendRequestFlowResult);
                bool bDidSendRequest = ppf_LaunchFriendRequestFlowResult_GetDidSendRequest(LaunchFriendRequestFlowResult);
                this->LaunchFriendRequestDelegate.ExecuteIfBound(false, FString(), bDidCancel, bDidSendRequest);
                OnLaunchFriendRequestResultCallback.ExecuteIfBound(false, FString(), bDidCancel, bDidSendRequest);
            }
        }));
    return true;
}

bool FPicoUserInterface::GetAccessToken(FGetAccessTokenResult OnGetAccessTokenResultCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetAccessToken"));
    ppfRequest RequestId = ppf_User_GetAccessToken();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetAccessTokenResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetAccessToken return failed:%s"), *ErrorMessage);
                this->GetAccesstokenDelegate.ExecuteIfBound(true, ErrorMessage, FString());
                OnGetAccessTokenResultCallback.ExecuteIfBound(true, ErrorMessage, FString());
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                UE_LOG(PicoUser, Log, TEXT("GetAccessToken Successfully"));
                FString AccessToken = ppf_Message_GetString(Message);
                this->GetAccesstokenDelegate.ExecuteIfBound(false, FString(), AccessToken);
                OnGetAccessTokenResultCallback.ExecuteIfBound(false, FString(), AccessToken);
            }
        }));
    return true;
}


bool FPicoUserInterface::GetRelations(TArray<FString> UserIDs, FGetUserRelationResult OnGetUserRelationResultCallback)
{
#if PLATFORM_ANDROID
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetRelations"));
    int32 Size = UserIDs.Num();
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < UserIDs.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(UserIDs[i]))));
    }
    std::vector<const char*> UserIDsCharArray;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        UserIDsCharArray.push_back(StringArray[i].c_str());
    }
    ppfRequest RequestId = ppf_User_GetRelations(UserIDsCharArray.data(), Size);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetUserRelationResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetRelations return failed:%s"), *ErrorMessage);
                this->GetUserRelationDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                OnGetUserRelationResultCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetRelations return Sucessed"));
                auto Res = NewObject<UPico_UserRelationResult>();
                Res->InitParams(ppf_Message_GetUserRelationResult(Message));
                this->GetUserRelationDelegate.ExecuteIfBound(false, FString(), Res);
                OnGetUserRelationResultCallback.ExecuteIfBound(false, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoUserInterface::EntitlementCheck(bool bKillApp, FEntitlementCheckResult OnEntitlementCheckResultCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::EntitlementCheck"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_User_EntitlementCheck(bKillApp);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnEntitlementCheckResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoUser, Log, TEXT("EntitlementCheck return failed: %d, %s"), ErrorCode, *ErrorMessage);
                this->EntitlementCheckResultDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
                OnEntitlementCheckResultCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("EntitlementCheck Successfully"));
                auto Res = NewObject<UPico_EntitlementCheckResult>();
                Res->InitParams(ppf_Message_GetEntitlementCheckResult(Message));
                this->EntitlementCheckResultDelegate.ExecuteIfBound(false, 0, FString(), Res);
                OnEntitlementCheckResultCallback.ExecuteIfBound(false, 0, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoUserInterface::GetIDToken(FGetIDToken OnGetIDTokenResultCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetIDToken"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_User_GetIdToken();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetIDTokenResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetIDToken return failed:%s"), *ErrorMessage);
                this->GetIDTokenDelegate.ExecuteIfBound(true, ErrorMessage, FString());
                OnGetIDTokenResultCallback.ExecuteIfBound(true, ErrorMessage, FString());
            }
            else
            {
                ppfMessageType messageType = ppf_Message_GetType(Message);
                UE_LOG(PicoUser, Log, TEXT("GetIDToken Successfully"));
                FString IDToken = ppf_Message_GetString(Message);
                this->GetIDTokenDelegate.ExecuteIfBound(false, FString(), IDToken);
                OnGetIDTokenResultCallback.ExecuteIfBound(false, FString(), IDToken);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoUserInterface::GetOrgScopedID(const FString& UserId, FGetOrgScopedID OnGetOrgScopedIDCallback)
{
    UE_LOG(PicoUser, Log, TEXT("FPicoUserInterface::GetOrgScopedID"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_User_GetOrgScopedID(TCHAR_TO_UTF8(*UserId));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetOrgScopedIDCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                const ppfErrorHandle Error = ppf_Message_GetError(Message);
                const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                const int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoUser, Log, TEXT("GetOrgScopedID return failed: %d, %s"), ErrorCode, *ErrorMessage);
                this->GetOrgScopedIDDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                OnGetOrgScopedIDCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetOrgScopedID Successfully"));
                auto Res = NewObject<UPico_OrgScopedID>();
                Res->InitParams(ppf_Message_GetOrgScopedID(Message));
                this->GetOrgScopedIDDelegate.ExecuteIfBound(false, FString(), Res);
                OnGetOrgScopedIDCallback.ExecuteIfBound(false, FString(), Res);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoUserInterface::GetAuthorizePermissions(FGetPermissionResult OnGetPermissionResultCallback)
{
    ppfRequest RequestId = ppf_User_GetAuthorizedPermissions();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetPermissionResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("GetAuthorizePermissions return failed:%s"), *ErrorMessage);
                this->GetAuthorizePermissionsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                OnGetPermissionResultCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("GetAuthorizePermissions return Sucessed"));
                auto PermissionResult = NewObject<UPico_PermissionResult>();
                PermissionResult->InitParams(ppf_Message_GetPermissionResult(Message));
                this->GetAuthorizePermissionsDelegate.ExecuteIfBound(false, FString(), PermissionResult);
                OnGetPermissionResultCallback.ExecuteIfBound(false, FString(), PermissionResult);
            }
        }));
    return true;
}

bool FPicoUserInterface::RequestUserPermissions(TArray<FString> Permissions, FGetPermissionResult OnGetPermissionResultCallback)
{
    int32 Size = Permissions.Num();
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < Permissions.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(Permissions[i]))));
    }
    std::vector<const char*> PermissionsCharArray;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        PermissionsCharArray.push_back(StringArray[i].c_str());
    }
    ppfRequest RequestId = ppf_User_RequestUserPermissions(PermissionsCharArray.data(), Size);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnGetPermissionResultCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoUser, Log, TEXT("RequestUserPermissions return failed:%s"), *ErrorMessage);
                this->RequestUserPermissionsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                OnGetPermissionResultCallback.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoUser, Log, TEXT("RequestUserPermissions return Sucessed"));
                auto PermissionResult = NewObject<UPico_PermissionResult>();
                PermissionResult->InitParams(ppf_Message_GetPermissionResult(Message));
                this->RequestUserPermissionsDelegate.ExecuteIfBound(false, FString(), PermissionResult);
                OnGetPermissionResultCallback.ExecuteIfBound(false, FString(), PermissionResult);
            }
        }));
    return true;
}

void UPico_PermissionResult::InitParams(ppfPermissionResult* InppfPermissionResultHandle)
{
    Size = ppf_PermissionResult_GetAuthorizedPermissionsSize(InppfPermissionResultHandle);
    for (int32 i = 0; i < Size; i++)
    {
        FString Permission = UTF8_TO_TCHAR(ppf_PermissionResult_GetAuthorizedPermissions(InppfPermissionResultHandle, i));
        AuthorizedPermissions.Add(Permission);
    }
    AccessionToken = UTF8_TO_TCHAR(ppf_PermissionResult_GetAccessToken(InppfPermissionResultHandle));
    UserID = UTF8_TO_TCHAR(ppf_PermissionResult_GetUserID(InppfPermissionResultHandle));
}

FString UPico_PermissionResult::GetAuthorizedPermission(int32 Index)
{
    if (AuthorizedPermissions.IsValidIndex(Index))
    {
        return AuthorizedPermissions[Index];
    }
    return FString();
}

int32 UPico_PermissionResult::GetSize()
{
    return Size;
}

FString UPico_PermissionResult::GetAccessToken()
{
    return AccessionToken;
}

FString UPico_PermissionResult::GetUserID()
{
    return UserID;
}

void UPico_UserRelationResult::InitParams(ppfUserRelationResult* InppfUserRelationResultHandle)
{
#if PLATFORM_ANDROID
    UE_LOG(PicoUser, Log, TEXT("User Relation Result init!"));
    RelationMapSize = ppf_UserRelationResult_GetRelationsSize(InppfUserRelationResultHandle);
    UE_LOG(PicoUser, Log, TEXT("User Relation Result GetRelationsSize:%i"), RelationMapSize);
    for (int i = 0; i < RelationMapSize; i++)
    {
        FString Key = UTF8_TO_TCHAR(ppf_UserRelationResult_GetRelationsKey(InppfUserRelationResultHandle, i));
        UE_LOG(PicoUser, Log, TEXT("UPico_DataStore::InitParams GetRelationsKey:%s"), *Key);
        UserIDArray.Add(Key);
        EUserRelationType Value = EUserRelationType::Unknown;
        ppfUserRelationType pUserRelationType = ppf_UserRelationResult_GetRelationsValue(InppfUserRelationResultHandle, i);
        switch (pUserRelationType)
        {
        case ppfUserRelationType_IsFriend:
            Value = EUserRelationType::IsFriend;
            break;
        case ppfUserRelationType_NotFriend:
            Value = EUserRelationType::NotFriend;
            break;
        case ppfUserRelationType_Blocked:
            Value = EUserRelationType::Blocked;
            break;
        case ppfUserRelationType_BlockedBy:
            Value = EUserRelationType::BlockedBy;
            break;
        case ppfUserRelationType_ApplyingFriend:
            Value = EUserRelationType::ApplyingFriend;
            break;
        default:
            break;
        }
        UserRelationMap.Add(Key, Value);
    }
#endif
}

int32 UPico_UserRelationResult::Contains(FString Key)
{
    return UserIDArray.Find(Key);
}

FString UPico_UserRelationResult::GetUserID(int32 Index)
{
    if (UserIDArray.IsValidIndex(Index))
    {
        return UserIDArray[Index];
    }
    UE_LOG(PicoUser, Log, TEXT("GetKey : Not vaild index %i"), Index);
    return FString();
}

int32 UPico_UserRelationResult::GetRelationMapSize()
{
    return RelationMapSize;
}

EUserRelationType UPico_UserRelationResult::GetRelationTypeValue(FString UserID)
{
    if (UserRelationMap.Contains(UserID))
    {
        return *UserRelationMap.Find(UserID);
    }
    UE_LOG(PicoUser, Log, TEXT("GetValue : Not vaild key: %s"), *UserID);
    return EUserRelationType::Unknown;
}

void UPico_EntitlementCheckResult::InitParams(ppfEntitlementCheckResult* InppfEntitlementCheckResultHandle)
{
    UE_LOG(PicoUser, Log, TEXT("User EntitlementCheck Result init!"));
#if PLATFORM_ANDROID
    bHasEntitlement = ppf_EntitlementCheckResult_GetHasEntitlement(InppfEntitlementCheckResultHandle);
    StatusMessage = UTF8_TO_TCHAR(ppf_EntitlementCheckResult_GetStatusMessage(InppfEntitlementCheckResultHandle));
    StatusCode = ppf_EntitlementCheckResult_GetStatusCode(InppfEntitlementCheckResultHandle);
#endif
}

bool UPico_EntitlementCheckResult::GetHasEntitlement()
{
    return bHasEntitlement;
}

int32 UPico_EntitlementCheckResult::GetStatusCode()
{
    return StatusCode;
}

FString UPico_EntitlementCheckResult::GetStatusMessage()
{
    return StatusMessage;
}

void UPico_OrgScopedID::InitParams(ppfOrgScopedID* InppfOrgScopedIDHandle)
{
    UE_LOG(PicoUser, Log, TEXT("User OrgScopedID init!"));
#if PLATFORM_ANDROID
    ID = UTF8_TO_TCHAR(ppf_OrgScopedID_GetID(InppfOrgScopedIDHandle));
#endif
}

FString UPico_OrgScopedID::GetID()
{
    return ID;
}
