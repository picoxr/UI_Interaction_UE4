// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#include "Pico_Room.h"
#include "Pico_User.h"
#include "Pico_DataStore.h"

DEFINE_LOG_CATEGORY(PicoRoom);

void UPico_Room::InitParams(ppfRoom* InRoomHandle)
{
    UE_LOG(PicoRoom, Log, TEXT("Pico room init!"));
    DataStore = NewObject<UPico_DataStore>();
    DataStore->InitParams(ppf_Room_GetDataStore(InRoomHandle));
    Owner = NewObject<UPico_User>();
    Owner->InitParams(ppf_Room_GetOwner(InRoomHandle));
    Users = NewObject<UPico_UserArray>();
    Users->InitParams(ppf_Room_GetUsers(InRoomHandle));
    Description = UTF8_TO_TCHAR(ppf_Room_GetDescription(InRoomHandle));
    ID = ppf_Room_GetID(InRoomHandle);
    RoomID = FString::Printf(TEXT("%llu"), ID);
    bIsMembershipLocked = ppf_Room_GetIsMembershipLocked(InRoomHandle);
    ppfRoomJoinPolicy ppfRoomJP = ppf_Room_GetJoinPolicy(InRoomHandle);
    switch (ppfRoomJP)
    {
    case ppfRoom_JoinPolicyNone:
        RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyNone;
        break;
    case ppfRoom_JoinPolicyEveryone:
        RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyEveryone;
        break;
    case ppfRoom_JoinPolicyFriendsOfMembers:
        RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyFriendsOfMembers;
        break;
    case ppfRoom_JoinPolicyFriendsOfOwner:
        RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyFriendsOfOwner;
        break;
    case ppfRoom_JoinPolicyInvitedUsers:
        RoomJoinPolicy = ERoomJoinPolicy::JoinPolicyInvitedUsers;
        break;
    default:
        break;
    }
    ppfRoomJoinability ppfRoomJoin = ppf_Room_GetJoinability(InRoomHandle);
    switch (ppfRoomJoin)
    {
    case ppfRoom_JoinabilityAreIn:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityAreIn;
        break;
    case ppfRoom_JoinabilityAreKicked:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityAreKicked;
        break;
    case ppfRoom_JoinabilityCanJoin:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityCanJoin;
        break;
    case ppfRoom_JoinabilityIsFull:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityIsFull;
        break;
    case ppfRoom_JoinabilityNoViewer:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityNoViewer;
        break;
    case ppfRoom_JoinabilityPolicyPrevents:
        RoomJoinabilit = ERoomJoinabilit::JoinabilityPolicyPrevents;
        break;
    default:
        break;
    }
    MaxUserNum = ppf_Room_GetMaxUsers(InRoomHandle);
    ppfRoomType ppfRT = ppf_Room_GetType(InRoomHandle);
    switch (ppfRT)
    {
    case ppfRoom_TypeMatchmaking:
        RoomType = ERoomType::TypeMatchmaking;
        break;
    case ppfRoom_TypeModerated:
        RoomType = ERoomType::TypeModerated;
        break;
    case ppfRoom_TypePrivate:
        RoomType = ERoomType::TypePrivate;
        break;
    default:
        break;
    }
}

UPico_DataStore* UPico_Room::GetDataStore()
{
    return DataStore;
}

UPico_User* UPico_Room::GetOwner()
{
    return Owner;
}

UPico_UserArray* UPico_Room::GetUsers()
{
    return Users;
}

FString UPico_Room::GetDescription()
{
    return Description;
}
ppfID UPico_Room::GetppfID()
{
    return ID;
}

FString UPico_Room::GetRoomID()
{
    return RoomID;
}

bool UPico_Room::GetIsMembershipLocked()
{
    return bIsMembershipLocked;
}

ERoomJoinPolicy UPico_Room::GetJoinPolicy()
{
    return RoomJoinPolicy;
}

ERoomJoinabilit UPico_Room::GetJoinability()
{
    return RoomJoinabilit;
}

int32 UPico_Room::GetMaxUsers()
{
    return MaxUserNum;
}

ERoomType UPico_Room::GetRoomType()
{
    return RoomType;
}
