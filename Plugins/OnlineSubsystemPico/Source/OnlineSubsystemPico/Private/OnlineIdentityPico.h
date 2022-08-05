// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineSubsystemPicoTypes.h"
#include "PPF_Platform.h"
/**
/// 
 */

 /// @file OnlineIdentityPico.h

/// @brief User gender.
enum class EUserGender : uint8
{
    Unknow,
    Male,
    Female
};

/// @brief User presence state.
enum class EUserPresenceStatus : uint8
{
    Unknow,
    OnLine,
    OffLine
};

/// @brief User information including user ID, image URL, display name, gender, and presence state.
struct FUserInformation  
{
    EUserGender Gender;
    FString UserId;
    FString ImageUrl;
    FString DisplayName;
    EUserPresenceStatus UserPresenceStatus;
};

DECLARE_DELEGATE_ThreeParams(FOnGetUserAndRoomDelegate, const FString& /**/, bool /*IsError*/, const FString& /*Error Message*/);

/// @brief UserOnlineAccountPico class inherited from FUserOnlineAccount(Unreal Engine).
class FUserOnlineAccountPico : public FUserOnlineAccount
{
public:


    FUserOnlineAccountPico(const FUniqueNetIdRef& InUserId, const FString& InName)
        : UserId(InUserId),
        Name(InName)
    { }

    virtual ~FUserOnlineAccountPico()
    {
    }


    /** User Id represented as a FUniqueNetId */
    FUniqueNetIdRef UserId;

    /** Additional key/value pair data related to auth */
    TMap<FString, FString> AdditionalAuthData;
    /** Additional key/value pair data related to user attribution */
    TMap<FString, FString> UserAttributes;


    // FOnlineUser


    // @return The ID associated with the user account provided by the online service during registration.
    virtual FUniqueNetIdRef GetUserId() const override { return UserId; };

    // @return The real name for the user if known.
    virtual FString GetRealName() const override { return Name; }

    // @return The nickname of the user if known.
    virtual FString GetDisplayName(const FString& Platform = FString()) const override { return Name; }

    // @return Any additional user data associated with a registered user.
    virtual bool GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const override;

    // @return Whether a local attribute for a user was successfully set.
    virtual bool SetUserAttribute(const FString& AttrName, const FString& AttrValue) override;

    // FUserOnlineAccount


    // @return The access token which is provided to user once authenticated by the online service.
    virtual FString GetAccessToken() const override { return TEXT("ACCESSTOKEN"); }


    // @return Any additional auth data associated with a registered user.
    virtual bool GetAuthAttribute(const FString& AttrName, FString& OutAttrValue) const override;

private:
    FString Name;
    FString AccessToken;
};

/**
* Pico service implementation of the online identity interface
*/

/** @defgroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Identity Identity
 *  This is the Identity group
 *  @{
 */

/// @brief OnlineIdentityPico class inherited from IOnlineIdentity(Unreal Engine)
class FOnlineIdentityPico : public IOnlineIdentity
{
public:

    /// @brief Gets the account login information for the current device.
    /// Will call `OnLoginComplete()` delegate when async task completes.
    /// @param LocalUserNum The controller number of the associated user.
    /// @param AccountCredentials The user account credentials needed to sign in to the online service.
    /// @return Bool: `true` if login task was started, `false` otherwise.
    virtual bool Login(int32 LocalUserNum, const FOnlineAccountCredentials& AccountCredentials) override;

    /// @brief Signs the player out of the online service.
    /// Will call the `OnLogoutComplete()` delegate when async task completes.
    /// @param LocalUserNum The controller number of the associated user.
    /// @return Bool: `true` if logout task was started, `false` otherwise.
    virtual bool Logout(int32 LocalUserNum) override;

    /// @brief Auto login.
    /// @param LocalUserNum The controller number of the associated user.
    /// @return Bool: `true`-success; `false`-failure.
    virtual bool AutoLogin(int32 LocalUserNum) override;

    /// @brief Obtains online account info for a user that has been registered.
    /// @param UserId The ID of the user to search for.
    /// @return The info about the user if found, `NULL` otherwise.
    virtual TSharedPtr<FUserOnlineAccount> GetUserAccount(const FUniqueNetId& UserId) const override;

    /// @brief Obtains the list of all known/registered user accounts.
    /// @return The info about the users if found, `NULL` otherwise.
    virtual TArray<TSharedPtr<FUserOnlineAccount> > GetAllUserAccounts() const override;

    /// @brief Gets the platform-specific unique ID for the specified player.
    /// @param LocalUserNum The controller number of the associated user.
    /// @return The valid player ID object if the call succeeded, `NULL` otherwise.
    virtual FUniqueNetIdPtr GetUniquePlayerId(int32 LocalUserNum) const override;

    /// @brief Creates a unique ID from binary data (used during replication).
    /// @param Bytes The opaque data from the appropriate platform.
    /// @param Size The size of opaque data.
    /// @return The unique ID from the given data, `NULL` otherwise.
    virtual FUniqueNetIdPtr CreateUniquePlayerId(uint8* Bytes, int32 Size) override;

    /// @brief Creates a unique ID from string.
    /// @param Str The string that holds the textual representation of an ID.
    /// @return The unique ID from the given data, `NULL` otherwise.
    virtual FUniqueNetIdPtr CreateUniquePlayerId(const FString& Str) override;

    /// @brief Gets the login status for a given player.
    /// @param LocalUserNum The controller number of the associated user.
    /// @return The enum value of that player's status.
    virtual ELoginStatus::Type GetLoginStatus(int32 LocalUserNum) const override;

    /// @brief Gets the login status for a given player.
    /// @param UserId The unique net ID of the associated user.
    /// @return The enum value of the player's status.
    virtual ELoginStatus::Type GetLoginStatus(const FUniqueNetId& UserId) const override;

    /// @brief Reads the player's nickname from the online service.
    /// @param LocalUserNum The controller number of the associated user.
    /// @return A string containing the player's nickname.
    virtual FString GetPlayerNickname(int32 LocalUserNum) const override;

    /// @brief Reads the player's nickname from the online service.
    /// @param UserId The unique net ID of the associated user.
    /// @return A string containing the player's nickname.
    virtual FString GetPlayerNickname(const FUniqueNetId& UserId) const override;

    // Not Supported
    virtual FString GetAuthToken(int32 LocalUserNum) const override;

    // Not Supported
    virtual void RevokeAuthToken(const FUniqueNetId& UserId, const FOnRevokeAuthTokenCompleteDelegate& Delegate) override;


    // Not Supported
    virtual void GetUserPrivilege(const FUniqueNetId& UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate& Delegate) override;
    
    // Not Supported
    virtual FPlatformUserId GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) const override;

    /// @brief Gets the auth type associated with accounts for this platform.
    /// @return The auth type associated with accounts for this platform.
    virtual FString GetAuthType() const override;



    // FOnlineIdentityPico

    /// @brief The constructor.
    /// @param InSubsystem The online subsystem being used.
    FOnlineIdentityPico(FOnlineSubsystemPico& InSubsystem);

    /// The default destructor.
    virtual ~FOnlineIdentityPico() = default;

PACKAGE_SCOPE:

    /**
    /// ** INTERNAL **
    /// Called when we get the results back from the MessageQueue.
    */
    void OnLoginComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum);

private:

    /// @brief Reference to the main Pico subsystem.
    FOnlineSubsystemPico& PicoSubsystem;

    /// @brief IDs mapped to locally registered users.
    TMap<int32, FUniqueNetIdRef> UserIds;



    /// @brief IDs mapped to locally registered user accounts.
    TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>> UserAccounts;

public:

    /// @brief User information map.
    TMap<int32, FUserInformation> UserInfos;
};
/** @} */ // end of Identity
/** @} */ // end of Function
typedef TSharedPtr<FOnlineIdentityPico, ESPMode::ThreadSafe> FOnlineIdentityPicoPtr;