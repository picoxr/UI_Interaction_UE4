// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "Interfaces/OnlineFriendsInterface.h"
#include "Interfaces/OnlinePresenceInterface.h"
#include "OnlineSubsystemPicoTypes.h"
#include "OnlineSubsystemPicoPackage.h"


/// @file OnlineFriendsInterfacePico.h

/// @brief OnlinePicoFriend class inherited from FOnlineFriend(Unreal Engine).
class FOnlinePicoFriend : public FOnlineFriend
{
private:
    FUniqueNetIdPicoRef UserId;
    const FString StrUserId;
    const FString DisplayName;
    FOnlineUserPresence Presence;

    const FString InviteToken;
public:
    FOnlinePicoFriend(/*const ppfID ID*/const FString StrId, const FString& InDisplayName, ppfUserPresenceStatus FriendPresenceStatus, const FString& InInviteToken) :
        UserId(FUniqueNetIdPico::Create(StrId)),
        StrUserId(StrId),
        DisplayName(InDisplayName),
        InviteToken(InInviteToken)
    {
        Presence.bIsOnline = FriendPresenceStatus == ppfUserPresenceStatus_OnLine;
    }

    virtual FUniqueNetIdRef GetUserId() const override
    {
        return UserId;
    }
    
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
};

/**
*	IOnlineFriends - Interface class for Friends
*/

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Friends Friends
 *  This is the Friends group
 *  @{
 */

/// @brief OnlineFriendsPico class inherited from IOnlineFriends(Unreal Engine).
class FOnlineFriendsPico : public IOnlineFriends
{
private:

    /// @brief Reference to the main Pico subsystem.
    FOnlineSubsystemPico& PicoSubsystem;

    /// @brief Current player friends map.
    TMap<FString, TSharedRef<FOnlineFriend>> PlayerFriends;

    /// @brief Current friends map can user invite.
    TMap<FString, TSharedRef<FOnlineFriend>> InvitableUsers;

PACKAGE_SCOPE:

   
    void OnQueryFriendsComplete(ppfMessageHandle Message, bool bIsError, int32 LocalUserNum, const FString& ListName, TMap<FString, TSharedRef<FOnlineFriend>>& OutList, bool bAppendToExistingMap, const FOnReadFriendsListComplete& Delegate);

public:

    static const FString FriendsListInviteableUsers;

   
    /// @brief The constructor.
    /// @param InSubsystem A reference to the online subsystem.
    FOnlineFriendsPico(FOnlineSubsystemPico& InSubsystem);

   
    /// The default destructor.
    virtual ~FOnlineFriendsPico() = default;

    // Begin IOnlineFriends interface

    /// @brief Starts an async task that reads the named friends list for the player.
    /// @param LocalUserNum The controller number of the user to read the friends list of.
    /// @param ListName The name of the friends list to read.
    /// @return Bool: `true`-success; `false`-falure.
    virtual bool ReadFriendsList(int32 LocalUserNum, const FString & ListName, const FOnReadFriendsListComplete & Delegate = FOnReadFriendsListComplete()) override;
   
    // To do(Not implement).
    virtual bool DeleteFriendsList(int32 LocalUserNum, const FString & ListName, const FOnDeleteFriendsListComplete & Delegate = FOnDeleteFriendsListComplete()) override;
     
    // To do(Not implement).
    virtual bool SendInvite(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName, const FOnSendInviteComplete & Delegate = FOnSendInviteComplete()) override;
      
    // To do(Not implement).
    virtual bool AcceptInvite(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName, const FOnAcceptInviteComplete & Delegate = FOnAcceptInviteComplete()) override;
   
    // To do(Not implement).
    virtual bool RejectInvite(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName) override;
      
    // To do(Not implement).
    virtual void SetFriendAlias(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName, const FString & Alias, const FOnSetFriendAliasComplete & Delegate = FOnSetFriendAliasComplete()) override;
   
    // To do(Not implement).
    virtual void DeleteFriendAlias(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName, const FOnDeleteFriendAliasComplete & Delegate = FOnDeleteFriendAliasComplete()) override;
   
    // To do(Not implement).
    virtual bool DeleteFriend(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName) override;
  
    /// @brief Gets the list of friends for the player previously retrieved from the online service.
    /// @param LocalUserNum The controller number of the user to read the friends list of.
    /// @param ListName The name of the friends list to read.
    /// @param OutFriends The [out] array that receives the copied data.
    /// @return Bool: `true` if friends list was found, `false` otherwise.
    virtual bool GetFriendsList(int32 LocalUserNum, const FString & ListName, TArray< TSharedRef<FOnlineFriend> >&OutFriends) override;

    /// @brief Gets the cached friend entry if found.
    /// @param LocalUserNum The controller number of the user to read the friends list of.
    /// @param ListName The name of the friends list to read.
    /// @param OutFriends The [out] array that receives the copied data.
    /// @return null ptr if not found.
    virtual TSharedPtr<FOnlineFriend> GetFriend(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName) override;
   
    /// @brief Checks that a unique player ID is part of the specified user's friends list.
    /// @param LocalUserNum The controller number of the associated user that made the request.
    /// @param FriendId The ID of the player being checked for friendship.
    /// @param ListName The name of the friends list to read.
    /// @return `true` if friends list was found and the friend was valid, `false` otherwise.
    virtual bool IsFriend(int32 LocalUserNum, const FUniqueNetId & FriendId, const FString & ListName) override;
   
    // To do(Not implement).
    virtual bool QueryRecentPlayers(const FUniqueNetId & UserId, const FString & Namespace) override;
   
    // To do(Not implement).
    virtual bool GetRecentPlayers(const FUniqueNetId & UserId, const FString & Namespace, TArray< TSharedRef<FOnlineRecentPlayer> >&OutRecentPlayers) override;
   
    // To do(Not implement).
    virtual void DumpRecentPlayers() const override;
      
    // To do(Not implement).
    virtual bool BlockPlayer(int32 LocalUserNum, const FUniqueNetId & PlayerId) override;   
   
    // To do(Not implement).
    virtual bool UnblockPlayer(int32 LocalUserNum, const FUniqueNetId & PlayerId) override; 
   
    // To do(Not implement).
    virtual bool QueryBlockedPlayers(const FUniqueNetId & UserId) override;
     
    // To do(Not implement).
    virtual bool GetBlockedPlayers(const FUniqueNetId & UserId, TArray< TSharedRef<FOnlineBlockedPlayer> >&OutBlockedPlayers) override;
  
    // To do(Not implement).
    virtual void DumpBlockedPlayers() const override;
    // End IOnlineFriends interface
};
/** @} */ // end of Friends
/** @} */ // end of Function