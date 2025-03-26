// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPicoNames.h"
#include "Pico_User.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPicoTypes.h"

/**
///
 */

 /// @file OnlineIdentityPico.h
DECLARE_DELEGATE_ThreeParams(FOnGetUserAndRoomDelegate, const FString& /**/, bool /*IsError*/, const FString& /*Error Message*/);
/// @brief UserOnlineAccountPico class inherited from FUserOnlineAccount(Unreal Engine).
class FUserOnlineAccountPico : public FUserOnlineAccount
{
public:

#if ENGINE_MAJOR_VERSION > 4
    FUserOnlineAccountPico(const FUniqueNetIdRef& InUserId, const FString& InName)
#elif ENGINE_MINOR_VERSION > 26
    FUserOnlineAccountPico(const FUniqueNetIdRef& InUserId, const FString& InName)
#elif ENGINE_MINOR_VERSION > 24
    FUserOnlineAccountPico(const TSharedRef<const FUniqueNetId>& InUserId, const FString& InName)
#endif
        : UserId(InUserId),
        Name(InName)
    { }
    /// <summary>
    /// 
    /// </summary>
    virtual ~FUserOnlineAccountPico()
    {
    }


    /** User Id represented as a FUniqueNetId */
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdRef UserId;
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdRef UserId;
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetId> UserId;
#endif
    /** Additional key/value pair data related to auth */
    TMap<FString, FString> AdditionalAuthData;
    /** Additional key/value pair data related to user attribution */
    TMap<FString, FString> UserAttributes;


    // FOnlineUser


    // @return The ID associated with the user account provided by the online service during registration.
#if ENGINE_MAJOR_VERSION > 4
    virtual FUniqueNetIdRef GetUserId() const override { return UserId; };
#elif ENGINE_MINOR_VERSION > 26
    virtual FUniqueNetIdRef GetUserId() const override { return UserId; };
#elif ENGINE_MINOR_VERSION > 24
    virtual TSharedRef<const FUniqueNetId> GetUserId() const override { return UserId; }
#endif
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

 /** @defgroup Identity Identity(OnlineSub)
  *  This is the Identity(OnlineSub) group
  *  @{
  */

  /// @brief OnlineIdentityPico class inherited from IOnlineIdentity(Unreal Engine)
class FOnlineIdentityPico : public IOnlineIdentity
{
public:

    /// <summary>Gets the account login information for a user.
    /// @note Will call the `OnLoginComplete()` delegate when the async task is complete.
    /// </summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <param name="AccountCredentials">Should pass `null`.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: the account login information has been found</li>
    /// <li>`false`: otherwise</li>
    /// </ul>
    /// </returns>
    virtual bool Login(int32 LocalUserNum, const FOnlineAccountCredentials& AccountCredentials) override;

    /// <summary>Clears the account login information for a user.
    /// @note Will call the `OnLogoutComplete()` delegate when the async task is complete.
    /// </summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: the account login information has been cleared</li>
    /// <li>`false`: otherwise</li>
    /// </ul>
    /// </returns>
    virtual bool Logout(int32 LocalUserNum) override;

    /// <summary>Logs a user in to the online service.</summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    virtual bool AutoLogin(int32 LocalUserNum) override;

    /// <summary>Gets the account information of a registered user.</summary>
    /// <param name="UserId">The ID of the user to search for.</param>
    /// <returns>
    /// The user's account information if found, `NULL` otherwise.
    /// </returns>
    virtual TSharedPtr<FUserOnlineAccount> GetUserAccount(const FUniqueNetId& UserId) const override;

    /// <summary>Gets the account information of all known/registered users.</summary>
    /// <returns>
    /// The account information of all known/registered users if found, `NULL` otherwise.
    /// <ul>
    /// <li></li>
    /// <li>`NULL`: otherwise</li>
    /// </ul>
    /// </returns>
    virtual TArray<TSharedPtr<FUserOnlineAccount> > GetAllUserAccounts() const override;

    /// <summary>Gets the platform-specific unique ID for a user.</summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <returns>
    /// The valid user ID object if the call succeeds, `NULL` otherwise.
    /// </returns>
/// @cond
#if ENGINE_MAJOR_VERSION > 4
    virtual FUniqueNetIdPtr GetUniquePlayerId(int32 LocalUserNum) const override;
#elif ENGINE_MINOR_VERSION > 26
    virtual FUniqueNetIdPtr GetUniquePlayerId(int32 LocalUserNum) const override;
#elif ENGINE_MINOR_VERSION > 24
/// @endcond
    virtual TSharedPtr<const FUniqueNetId> GetUniquePlayerId(int32 LocalUserNum) const override;
#endif

    /// <summary>Creates a unique ID from binary data (used during replication).</summary>
    /// <param name="Bytes">The opaque data from the appropriate platform.</param>
    /// <param name="Size">The size of opaque data.</param>
    /// <returns>
    /// The unique ID from the given data, `NULL` otherwise.
    /// </returns>
/// @cond
#if ENGINE_MAJOR_VERSION > 4
    virtual FUniqueNetIdPtr CreateUniquePlayerId(uint8* Bytes, int32 Size) override;
#elif ENGINE_MINOR_VERSION > 26
    virtual FUniqueNetIdPtr CreateUniquePlayerId(uint8* Bytes, int32 Size) override;
#elif ENGINE_MINOR_VERSION > 24
/// @endcond
    virtual TSharedPtr<const FUniqueNetId> CreateUniquePlayerId(uint8* Bytes, int32 Size) override;
#endif

    /// <summary>Creates a unique ID from string.</summary>
    /// <param name="Str">The string that holds the textual representation of an ID.</param>
    /// <returns>
    /// The unique ID from the given data, `NULL` otherwise.
    /// </returns>
/// @cond 
#if ENGINE_MAJOR_VERSION > 4
    virtual FUniqueNetIdPtr CreateUniquePlayerId(const FString& Str) override;
#elif ENGINE_MINOR_VERSION > 26
    virtual FUniqueNetIdPtr CreateUniquePlayerId(const FString& Str) override;
#elif ENGINE_MINOR_VERSION > 24
/// @endcond
    virtual TSharedPtr<const FUniqueNetId> CreateUniquePlayerId(const FString& Str) override;
#endif


    /// <summary>Gets a user's login status by controller number.</summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <returns>The enum value of that user's login status.</returns>
    virtual ELoginStatus::Type GetLoginStatus(int32 LocalUserNum) const override;

    /// <summary>Gets a user's login status by unique net ID.</summary>
    /// <param name="UserId">The unique net ID of the associated user.</param>
    /// <returns>The enum value of the user's login status.</returns>
    virtual ELoginStatus::Type GetLoginStatus(const FUniqueNetId& UserId) const override;

    /// <summary>Gets a users's nickname from the online service by controller number.</summary>
    /// <param name="LocalUserNum">The controller number of the associated user.</param>
    /// <returns>A string containing the user's nickname.</returns>
    virtual FString GetPlayerNickname(int32 LocalUserNum) const override;

    /// <summary>Gets a user's nickname from the online service by unique net ID.</summary>
    /// <param name="UserId">The unique net ID of the associated user.</param>
    /// <returns>A string containing the user's nickname.</returns>
    virtual FString GetPlayerNickname(const FUniqueNetId& UserId) const override;


    virtual FString GetAuthToken(int32 LocalUserNum) const override;

    // Not Supported
    virtual void RevokeAuthToken(const FUniqueNetId& UserId, const FOnRevokeAuthTokenCompleteDelegate& Delegate) override;


    // Not Supported
    virtual void GetUserPrivilege(const FUniqueNetId& UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate& Delegate) override;

    // Not Supported
    virtual FPlatformUserId GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) const override;

#if ENGINE_MINOR_VERSION > 26
    virtual void GetLinkedAccountAuthToken(int32 LocalUserNum, const FOnGetLinkedAccountAuthTokenCompleteDelegate& Delegate) const override;
#endif
    /// <summary>Gets the auth type associated with accounts for this platform.</summary>
    /// <returns>The auth type associated with accounts for this platform.</returns>
    virtual FString GetAuthType() const override;

    UPico_User* GetLoginPicoUser(int32 LocalUserNum);

    void GetLoginUserOpenID(FGetIDToken OnGetIdTokenDelegate);

    // FOnlineIdentityPico

    // <summary>The constructor.</summary>
    // <param name="InSubsystem">The online subsystem being used.</param>
    FOnlineIdentityPico(FOnlineSubsystemPico& InSubsystem);

    // The default destructor.
    virtual ~FOnlineIdentityPico() = default;

PACKAGE_SCOPE:

    /**
    /// ** INTERNAL **
    /// Called when we get the results back from the MessageQueue.
    */
    void OnLoginComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum);

private:

    // @brief Reference to the main Pico subsystem.
    FOnlineSubsystemPico& PicoSubsystem;

    // @brief IDs mapped to locally registered users.
#if ENGINE_MAJOR_VERSION > 4
    TMap<int32, FUniqueNetIdRef> UserIds;
#elif ENGINE_MINOR_VERSION > 26
    TMap<int32, FUniqueNetIdRef> UserIds;
#elif ENGINE_MINOR_VERSION > 24
    TMap<int32, TSharedPtr<const FUniqueNetId>> UserIds;
#endif
    TMap<int32, UPico_User*> LoginPicoUserMap;

    FString AuthToken;
    /// @brief IDs mapped to locally registered user accounts.
#if ENGINE_MAJOR_VERSION > 4
    TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>> UserAccounts;
#elif ENGINE_MINOR_VERSION > 26
    TUniqueNetIdMap<TSharedRef<FUserOnlineAccountPico>> UserAccounts;
#elif ENGINE_MINOR_VERSION > 24
    TMap<FUniqueNetIdPico, TSharedRef<FUserOnlineAccountPico>> UserAccounts;
#endif

};
/** @} */ // end of Identity(OnlineSub)
/** @} */ // end of Function
typedef TSharedPtr<FOnlineIdentityPico, ESPMode::ThreadSafe> FOnlineIdentityPicoPtr;