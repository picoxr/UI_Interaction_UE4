// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 
#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineFriendsInterface.h"
#include "Interfaces/OnlinePresenceInterface.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoTypes.h"
#include "OnlineSubsystemPicoPackage.h"

/// @file OnlineFriendsInterfacePico.h




/// @brief OnlinePicoFriend class inherited from FOnlineFriend(Unreal Engine).
class FOnlinePicoFriend : public FOnlineFriend
{

private:

#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdPicoRef UserId;
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdPicoRef UserId;
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetIdPico> UserId;
#endif

    const FString StrUserId;
    const FString DisplayName;
    FOnlineUserPresence Presence;
    const FString InviteToken;
    const FString ImageUrl;
    ppfGender Gender;
    const FString SmallImageUrl;
    const FString PresencePackage;
    ppfUserPresenceStatus UserPresenceStatus;
    const FString Presencestr;
    const FString PresenceDeeplinkMessage;
    const FString PresenceDestinationApiName;
    const FString PresenceLobbySessionId;
    const FString PresenceMatchSessionId;
    const FString PresenceExtra;
public:
    FOnlinePicoFriend(/*const ppfID ID*/const FString StrId, const FString& InDisplayName, ppfUserPresenceStatus FriendPresenceStatus,
        const FString& InInviteToken, const FString& InImageUrl, ppfGender InGender, const FString& InSmallImageUrl,
        const FString& InPresencePackage, const FString& InPresence, const FString& InPresenceDeeplinkMessage,
        const FString& InPresenceDestinationApiName, const FString& InPresenceLobbySessionId, const FString& InPresenceMatchSessionId,
        const FString& InExtra) :

#if ENGINE_MAJOR_VERSION > 4
        UserId(FUniqueNetIdPico::Create(StrId)),
#elif ENGINE_MINOR_VERSION > 26
        UserId(FUniqueNetIdPico::Create(StrId)),
#elif ENGINE_MINOR_VERSION > 24
        UserId(new FUniqueNetIdPico(StrId)),
#endif
        StrUserId(StrId),
        DisplayName(InDisplayName),
        InviteToken(InInviteToken),
        ImageUrl(InImageUrl),
        Gender(InGender),
        SmallImageUrl(InSmallImageUrl),
        PresencePackage(InPresencePackage),
        UserPresenceStatus(FriendPresenceStatus),
        Presencestr(InPresence),
        PresenceDeeplinkMessage(InPresenceDeeplinkMessage),
        PresenceDestinationApiName(InPresenceDestinationApiName),
        PresenceLobbySessionId(InPresenceLobbySessionId),
        PresenceMatchSessionId(InPresenceMatchSessionId),
        PresenceExtra(InExtra)
    {
        Presence.bIsOnline = FriendPresenceStatus == ppfUserPresenceStatus_OnLine;
    }
#if ENGINE_MAJOR_VERSION > 4
    virtual FUniqueNetIdRef GetUserId() const override
    {
        return UserId;
    }
#elif ENGINE_MINOR_VERSION > 26
    virtual FUniqueNetIdRef GetUserId() const override
    {
        return UserId;
    }
#elif ENGINE_MINOR_VERSION > 24
    virtual TSharedRef<const FUniqueNetId> GetUserId() const override
    {
        return UserId;
    }
#endif


    FString GetUserStrId() const
    {
        return StrUserId;
    }

    virtual FString GetRealName() const override
    {
        return TEXT("");
    }

    virtual FString GetDisplayName(const FString& Platform = FString()) const override
    {
        return DisplayName;
    }

    virtual bool GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const override
    {
        return false;
    }

    virtual EInviteStatus::Type GetInviteStatus() const override
    {
        return EInviteStatus::Accepted;
    }

    virtual const FOnlineUserPresence& GetPresence() const override
    {
        return Presence;
    }

    FString GetInviteToken() const
    {
        return InviteToken;
    }

    FString GetImageUrl() const
    {
        return ImageUrl;
    }

    FString GetPresencePackage() const
    {
        return PresencePackage;
    }
    FString GetPresencechar() const
    {
        return Presencestr;
    }
    FString GetPresenceDeeplinkMessage() const
    {
        return PresenceDeeplinkMessage;
    }

    FString GetPresenceDestinationApiName() const
    {
        return PresenceDestinationApiName;
    }

    FString GetPresenceLobbySessionId() const
    {
        return PresenceLobbySessionId;
    }

    FString GetPresenceMatchSessionId() const
    {
        return PresenceMatchSessionId;
    }

    FString GetPresenceExtra() const
    {
        return PresenceExtra;
    }

    FString GetSmallImageUrl() const
    {
        return SmallImageUrl;
    }
    ppfUserPresenceStatus GetUserPresenceStates() const
    {
        return UserPresenceStatus;
    }

    ppfGender GetGender() const
    {
        return Gender;
    }

};

/**
*	IOnlineFriends - Interface class for Friends
*/

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup Friends Friends(OnlineSub)
  *  This is the Friends(OnlineSub) group
  *  @{
  */

  /// @brief OnlineFriendsPico class inherited from IOnlineFriends(Unreal Engine).
class FOnlineFriendsPico : public IOnlineFriends
{
private:

    // @brief Reference to the main Pico subsystem.
    FOnlineSubsystemPico& PicoSubsystem;

    // @brief Current player friends map.
    TMap<FString, TSharedRef<FOnlineFriend>> PlayerFriends;

    // @brief Current friends map can user invite.
    TMap<FString, TSharedRef<FOnlineFriend>> InvitableUsers;

PACKAGE_SCOPE:


    void OnQueryFriendsComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum, const FString& ListName, TMap<FString, TSharedRef<FOnlineFriend>>& OutList, bool bAppendToExistingMap, const FOnReadFriendsListComplete& Delegate);

public:

    static const FString FriendsListInviteableUsers;


    // <summary>The constructor.</summary>
    // <param name="InSubsystem">A reference to the online subsystem.</param>
    FOnlineFriendsPico(FOnlineSubsystemPico& InSubsystem);


    // The default destructor.
    virtual ~FOnlineFriendsPico() = default;

    // Begin IOnlineFriends interface

    /// <summary>Starts an async task that reads the named friend list for a user.</summary>
    /// <param name="LocalUserNum">The controller number of the user to read the friend list for.</param>
    /// <param name="ListName">The name of the friend list to read.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    virtual bool ReadFriendsList(int32 LocalUserNum, const FString& ListName, const FOnReadFriendsListComplete& Delegate = FOnReadFriendsListComplete()) override;

    bool ReadFriendsList(int32 LocalUserNum, const FString& ListName, ppfID RoomId, const FOnReadFriendsListComplete& Delegate = FOnReadFriendsListComplete());

    // To do(Not implement).
    virtual bool DeleteFriendsList(int32 LocalUserNum, const FString& ListName, const FOnDeleteFriendsListComplete& Delegate = FOnDeleteFriendsListComplete()) override;

    // To do(Not implement).
    virtual bool SendInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnSendInviteComplete& Delegate = FOnSendInviteComplete()) override;

    // To do(Not implement).
    virtual bool AcceptInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnAcceptInviteComplete& Delegate = FOnAcceptInviteComplete()) override;

    // To do(Not implement).
    virtual bool RejectInvite(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName) override;

    // To do(Not implement).
    virtual void SetFriendAlias(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FString& Alias, const FOnSetFriendAliasComplete& Delegate = FOnSetFriendAliasComplete()) override;

    // To do(Not implement).
    virtual void DeleteFriendAlias(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName, const FOnDeleteFriendAliasComplete& Delegate = FOnDeleteFriendAliasComplete()) override;

    // To do(Not implement).
    virtual bool DeleteFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName) override;

    /// <summary>Gets a list of friends previously retrieved from the online service for a user.</summary>
    /// <param name="LocalUserNum">The controller number of the user to get the friend list for.</param>
    /// <param name="ListName">The name of the friends list to read.</param>
    /// <param name="OutFriends">The [out] array that receives the copied data.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: the friend list has been found</li>
    /// <li>`false`: otherwise</li>
    /// </ul>
    /// </returns>
    virtual bool GetFriendsList(int32 LocalUserNum, const FString& ListName, TArray< TSharedRef<FOnlineFriend> >& OutFriends) override;

    /// <summary>Gets the cached friend entry if found.</summary>
    /// <param name="LocalUserNum">The controller number of the user to get the cached friend entry for.</param>
    /// <param name="ListName">The name of the friends list to read.</param>
    /// <param name="OutFriends">The [out] array that receives the copied data.</param>
    /// <returns>null ptr if not found.</returns>
    virtual TSharedPtr<FOnlineFriend> GetFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName) override;

    /// <summary>Checks whether someone is the friend of a user.</summary>
    /// <param name="LocalUserNum">The controller number of the user that made the request.</param>
    /// <param name="FriendId">The ID of the user (someone) being checked for friendship.</param>
    /// <param name="ListName">The name of the friends list to read.</param>
    /// <returns>Bool:
    /// <ul>
    /// <li>`true`: the friend list has been found and the friend is valid</li>
    /// <li>`false`: otherwise</li>
    /// </ul>
    /// </returns>
    virtual bool IsFriend(int32 LocalUserNum, const FUniqueNetId& FriendId, const FString& ListName) override;

    // To do(Not implement).
    virtual bool QueryRecentPlayers(const FUniqueNetId& UserId, const FString& Namespace) override;

    // To do(Not implement).
    virtual bool GetRecentPlayers(const FUniqueNetId& UserId, const FString& Namespace, TArray< TSharedRef<FOnlineRecentPlayer> >& OutRecentPlayers) override;

    // To do(Not implement).
    virtual void DumpRecentPlayers() const override;

    // To do(Not implement).
    virtual bool BlockPlayer(int32 LocalUserNum, const FUniqueNetId& PlayerId) override;

    // To do(Not implement).
    virtual bool UnblockPlayer(int32 LocalUserNum, const FUniqueNetId& PlayerId) override;

    // To do(Not implement).
    virtual bool QueryBlockedPlayers(const FUniqueNetId& UserId) override;

    // To do(Not implement).
    virtual bool GetBlockedPlayers(const FUniqueNetId& UserId, TArray< TSharedRef<FOnlineBlockedPlayer> >& OutBlockedPlayers) override;

    // To do(Not implement).
    virtual void DumpBlockedPlayers() const override;
    // End IOnlineFriends interface
};
/** @} */ // end of Friends(OnlineSub)
/** @} */ // end of Function