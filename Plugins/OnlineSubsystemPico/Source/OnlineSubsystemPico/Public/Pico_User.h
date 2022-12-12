// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "OnlineSubsystemPico.h"
#include "Pico_Room.h"
#include "Pico_User.generated.h"

/// @file Pico_User.h

DECLARE_LOG_CATEGORY_EXTERN(PicoUser, Log, All);

class UPico_Room;

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetLoggedInUserFriendsAndRooms, bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray*, UserAndRoomArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetNextUserAndRoomArrayPage, bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray*, UserAndRoomArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetLoggedInUserFriends, bool, bIsError, const FString&, ErrorMessage, UPico_UserArray*, UserArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetNextUserPage, bool, bIsError, const FString&, ErrorMessage, UPico_UserArray*, UserArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetLoginUser, bool, bIsError, const FString&, ErrorMessage, UPico_User*, User);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetUserInfo, bool, bIsError, const FString&, ErrorMessage, UPico_User*, User);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetPermissionResult, bool, bIsError, const FString&, ErrorMessage, UPico_PermissionResult*, PermissionResult);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetAccessTokenResult, bool, bIsError, const FString&, ErrorMessage, const FString&, AccessToken);
DECLARE_DYNAMIC_DELEGATE_FourParams(FLaunchFriendRequestResult, bool, bIsError, const FString&, ErrorMessage, bool, bDidCancel, bool, bDidSendRequest);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup User User
 *  This is the User group
 *  @{
 */

/// @brief PicoUserInterface class.
class ONLINESUBSYSTEMPICO_API FPicoUserInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
    FPicoUserInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoUserInterface();

    FGetLoginUser GetLoginUserDelegate;
    FGetLoggedInUserFriendsAndRooms GetLoggedInUserFriendsAndRoomsDelegate;
    FGetNextUserAndRoomArrayPage GetNextUserAndRoomArrayPageDelegate;
    FGetLoggedInUserFriends GetLoggedInUserFriendsDelegate;
    FGetNextUserPage GetNextUserFriendsPageDelegate;
    FGetUserInfo GetUserInfoDelegate;
    FGetPermissionResult GetAuthorizePermissionsDelegate;
    FGetPermissionResult RequestUserPermissionsDelegate;
    FLaunchFriendRequestResult LaunchFriendRequestDelegate;
    FGetAccessTokenResult GetAccesstokenDelegate;

    /// <summary>Gets the information about the current logged-in user.</summary>
    /// <param name="InGetLoginUserDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetLoginUser(FGetLoginUser InGetLoginUserDelegate);

    /// <summary>Gets the information by user ID.</summary>
    /// <param name="UserId">The ID of the user.</param>    
    /// <param name="InGetUserInfoDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetUserInfo(const FString& UserId, FGetUserInfo InGetUserInfoDelegate);

    /// <summary>Gets the friends of the logged-in user and the rooms the friends might be in. If a friend is not in any room, the 'room' field will be null.</summary>
    /// <param name="OnGetLoggedInuserFriendsAndRoomsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    bool GetLoggedInUserAndRoom(FGetLoggedInUserFriendsAndRooms OnGetLoggedInuserFriendsAndRoomsCallback);

    /// <summary>Gets the friend list of the current user.</summary>
    /// <param name="InUserAndRoomArray">The current object of user and room array.</param>
    /// <param name="OnGetNextUserAndRoomArrayPageCallback">Will be executed when the request has been completed.
    /// Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetNextUserAndRoomArrayPage(UPico_UserAndRoomArray* InUserAndRoomArray, FGetNextUserAndRoomArrayPage OnGetNextUserAndRoomArrayPageCallback);

    /// <summary>Gets the friend list of the current user. Friends who don't use this app won't appear in this list.</summary>
    /// <param name="OnGetLoggedInUserFriendsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetUserFriends(FGetLoggedInUserFriends OnGetLoggedInUserFriendsCallback);

    /// <summary>Gets the next page of user list.</summary>
    /// <param name="InUserArray">The current object of the user array.</param>
    /// <param name="OnGetNextUserPageCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetNextUserPage(UPico_UserArray* InUserArray, FGetNextUserPage OnGetNextUserPageCallback);

    /// <summary>
    /// Gets the authorized permissions.
    /// </summary>
    /// <param name="OnGetPermissionResultCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool GetAuthorizePermissions(FGetPermissionResult OnGetPermissionResultCallback);

    /// <summary>
    /// Requests user permissions. The user will received a pop-up notification window.
    /// </summary>
    /// <param name="Permissions">Will be executed when the request has been completed. Delegate will contain the requested object class.
    /// * `user_info`: The permission to get the user's basic information, such as the user's nickname and profile picture.
    /// * `friend_relation`: The permission to get the user's friend list and invitable users.
    /// * `sports_userinfo`: The permission to get the user's information set in the sport center.
    /// * `sports_summarydata`: The permission to get a summary of the user's exercise data.
    /// </param>
    /// <param name="OnGetPermissionResultCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool RequestUserPermissions(TArray<FString> Permissions, FGetPermissionResult OnGetPermissionResultCallback);

    /// <summary>
    /// Launches the flow to apply for friendship with someone.
    /// </summary>
    /// <param name="UserId">The ID of the user that the friend request is sent to.</param>
    /// <param name="OnLaunchFriendRequestResultCallback">Will be executed when the request has been completed. Delegate will contain the requested info.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    bool LaunchFriendRequestFlow(const FString UserId, FLaunchFriendRequestResult OnLaunchFriendRequestResultCallback);

    bool GetAccessToken(FGetAccessTokenResult OnGetAccessTokenResultCallback);
};
/** @} */
/** @} */


/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_User BP_User
 *  This is the BP_User group
 *  @{
 */

/// @brief OnlinePicoUser Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoUserFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()


public:

    /// <summary>Gets the friends of the logged-in user and the rooms the friends might be in. If a friend is not in any room, the 'room' field will be null.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetLoggedInuserFriendsAndRoomsCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static void PicoGetLoggedInUserAndRoom(UObject* WorldContextObject, FGetLoggedInUserFriendsAndRooms InGetLoggedInuserFriendsAndRoomsCallback);

    /// <summary>Gets the friend list of the current user.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InUserAndRoomArray">The current object of user and room array.</param>    
    /// <param name="InGetNextUserAndRoomArrayPageCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static void PicoGetNextUserAndRoomArrayPage(UObject* WorldContextObject, UPico_UserAndRoomArray* InUserAndRoomArray, FGetNextUserAndRoomArrayPage InGetNextUserAndRoomArrayPageCallback);


    /// <summary>Gets the friend list of the current user. Friends who don't use this app won't appear in this list.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetLoggedInUserFriendsDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static void PicoGetUserFriends(UObject* WorldContextObject, FGetLoggedInUserFriends InGetLoggedInUserFriendsDelegate);

    /// <summary>Gets the next page of a user list.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InUserArray">The current object of user array.</param>    
    /// <param name="InGetNextUserPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static void PicoGetNextUserPage(UObject* WorldContextObject, UPico_UserArray* InUserArray, FGetNextUserPage InGetNextUserPageDelegate);

    /// <summary>Gets the information about the current logged-in user.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InGetLoginUserDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool GetLoginUser(UObject* WorldContextObject, FGetLoginUser InGetLoginUserDelegate);

    /// <summary>Gets user information by user ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="UserId">The ID of the user.</param>    
    /// <param name="InGetUserInfoDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool GetPicoUserInfo(UObject* WorldContextObject, const FString& UserId, FGetUserInfo InGetUserInfoDelegate);

    /// <summary>
    /// Gets the authorized permissions.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="OnGetPermissionResultCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool GetAuthorizePermissions(UObject* WorldContextObject, FGetPermissionResult OnGetPermissionResultCallback);


    /// <summary>
    /// Requests user permissions. The user will received a pop-up notification window.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Permissions">Will be executed when the request has been completed. Delegate will contain the requested object class.
    /// * `user_info`: The permission to get the user's basic information, such as the user's nickname and profile picture.
    /// * `friend_relation`: The permission to get the user's friend list and invitable users.
    /// * `sports_userinfo`: The permission to get the user's information set in the sport center.
    /// * `sports_summarydata`: The permission to get a summary of the user's exercise data.
    /// </param>
    /// <param name="OnGetPermissionResultCallback">Will be executed when the request has been completed. Delegate will contain the requested object class.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool RequestUserPermissions(UObject* WorldContextObject, TArray<FString> Permissions, FGetPermissionResult OnGetPermissionResultCallback);

    /// <summary>
    /// Launches the flow to apply for friendship with someone.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="UserId">The ID of the user that the friend request is sent to.</param>
    /// <param name="OnLaunchFriendRequestResultCallback">Will be executed when the request has been completed. Delegate will contain the requested info.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool LaunchFriendRequestFlow(UObject* WorldContextObject, const FString UserId, FLaunchFriendRequestResult OnLaunchFriendRequestResultCallback);

    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|User")
    static bool GetAccessToken(UObject* WorldContextObject, FGetAccessTokenResult OnGetAccessTokenResultCallback);
};

/** @} */ // end of BP_User
/** @} */ // end of BlueprintFunction

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_User : public UObject
{
    GENERATED_BODY()
public:
    void InitParams(ppfUser* ppfUserHandle);

private:
    FString DisplayName = FString();
    FString ImageUrl = FString();
    FString ID = FString();
    FString InviteToken = FString();
    FString SmallImageUrl = FString();
    FString PresencePackage = FString();
    EUserPresenceStatus UserPresenceStatus = EUserPresenceStatus::Unknow;
    EUserGender UserGender = EUserGender::Unknow;
    FString Presence = FString();
    FString PresenceDeeplinkMessage = FString();
    FString PresenceDestinationApiName = FString();
    FString PresenceLobbySessionId = FString();
    FString PresenceMatchSessionId = FString();
    FString PresenceExtra = FString();
    FString StoreRegion = FString();

public:
    
    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetDisplayName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetImageURL();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetID();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetInviteToken();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetSmallImageUrl();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresencePackage();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    EUserPresenceStatus GetUserPresenceStatus();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    EUserGender GetGender();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresence();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresenceDeeplinkMessage();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresenceDestinationApiName();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresenceLobbySessionId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresenceMatchSessionId();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetPresenceExtra();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User")
    FString GetStoreRegion();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_UserArray : public UObject
{

    GENERATED_BODY()

public:
    void InitParams(ppfUserArray* InppfUserArrayHandle);

private:
    UPROPERTY()
    TArray<UPico_User*> UserArray;
    FString NextPageParam;
    int32 Size;
    bool bHasNextPage;

public:


    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User Array")
    UPico_User* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User Array")
    FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User Array")
    int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User Array")
    bool HasNextPage();
    
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_UserAndRoom : public UObject
{

    GENERATED_BODY()
private:
    UPROPERTY()
    UPico_Room* Room = nullptr;

    UPROPERTY()
    UPico_User* User = nullptr;
public:
    void InitParams(ppfUserAndRoom* InppfUserAndRoomHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room")
    UPico_Room* GetRoom();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room")
    UPico_User* GetUser();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_UserAndRoomArray : public UObject
{

    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<UPico_UserAndRoom*> UserAndRoomArray;
    FString NextPageParam = FString();
    int32 Size = 0;
    bool bHasNextPage;
public:
    void InitParams(ppfUserAndRoomArray* InppfUserAndRoomArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room Array")
    UPico_UserAndRoom* GetElement(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room Array")
    FString GetNextPageParam();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room Array")
    int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|User And Room Array")
    bool HasNextPage();
};

UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_PermissionResult : public UObject
{
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<FString> AuthorizedPermissions;
    int32 Size = 0;
    FString AccessionToken = FString();
    FString UserID = FString();
public:
    void InitParams(ppfPermissionResult* InppfPermissionResultHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|Permission")
    FString GetAuthorizedPermission(int32 Index);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|Permission")
    int32 GetSize();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|Permission")
    FString GetAccessToken();

    UFUNCTION(BlueprintPure, Category = "Pico Platform|User|Permission")
    FString GetUserID();
};

// 