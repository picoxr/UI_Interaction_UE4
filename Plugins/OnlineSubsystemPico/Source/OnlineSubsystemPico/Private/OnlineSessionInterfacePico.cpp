// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlineSessionInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystemPicoTypes.h"
#include "Misc/FileHelper.h"
#include "Misc/MessageDialog.h"
#include "Online/OnlineSessionNames.h"

FOnlineSessionInfoPico::FOnlineSessionInfoPico(ppfID RoomId) :
#if ENGINE_MAJOR_VERSION > 4
    SessionId(FUniqueNetIdPico::Create(RoomId))
#elif ENGINE_MINOR_VERSION > 26

    SessionId(FUniqueNetIdPico::Create(RoomId))
#elif ENGINE_MINOR_VERSION > 24
    SessionId(FUniqueNetIdPico(RoomId))
#endif
{
}

/**
* FOnlineSessionPico
*/

FOnlineSessionPico::FOnlineSessionPico(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    InviteAcceptedRoomID = 0;
    OnRoomNotificationUpdateHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Room_RoomUpdate)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdate);

    OnRoomNotificationInviteAcceptedHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Room_InviteAccepted)
        .AddRaw(this, &FOnlineSessionPico::OnRoomInviteAccepted);

    OnMatchmakingNotificationMatchFoundHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Matchmaking_MatchFound)
        .AddRaw(this, &FOnlineSessionPico::OnMatchmakingNotificationMatchFound);


    OnNetNotificationConnectionHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Game_ConnectionEvent)
        .AddRaw(this, &FOnlineSessionPico::OnNetNotificationConnection);

    OnNetNotificationRequestFailedHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Game_RequestFailed)
        .AddRaw(this, &FOnlineSessionPico::OnNetNotificationRequestFailed);

    OnNetNotificationGameStateResetHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Game_StateReset)
        .AddRaw(this, &FOnlineSessionPico::OnNetNotificationGameStateReset);

    OnMatchmakingNotificationCancel2Handle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Matchmaking_Cancel2)
        .AddRaw(this, &FOnlineSessionPico::OnMatchmakingNotificationCancel2);

    OnRoomNotificationLeaveHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_Leave)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationLeave);

    OnRoomNotificationJoin2Handle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_Join2)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationJoin2);

    OnRoomNotificationSetDescriptionHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_SetDescription)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationSetDescription);

    OnRoomNotificationKickUserHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_KickUser)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationKickUser);

    OnRoomNotificationUpdateOwnerHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_UpdateOwner)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateOwner);

    OnRoomNotificationUpdateDataStoreHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_UpdateDataStore)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateDataStore);

    OnRoomNotificationUpdateMembershipLockStatusHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_UpdateMembershipLockStatus)
        .AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateMembershipLockStatus);
}

FOnlineSessionPico::~FOnlineSessionPico()
{
	if (OnRoomNotificationUpdateHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Room_RoomUpdate, OnRoomNotificationUpdateHandle);
		OnRoomNotificationUpdateHandle.Reset();
	}

	if (OnRoomNotificationInviteAcceptedHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Room_InviteAccepted, OnRoomNotificationInviteAcceptedHandle);
		OnRoomNotificationInviteAcceptedHandle.Reset();
	}

	if (OnMatchmakingNotificationMatchFoundHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Matchmaking_MatchFound, OnMatchmakingNotificationMatchFoundHandle);
		OnMatchmakingNotificationMatchFoundHandle.Reset();
	}
	
	if (OnNetNotificationConnectionHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Game_ConnectionEvent, OnNetNotificationConnectionHandle);
		OnNetNotificationConnectionHandle.Reset();
	}
	
	if (OnNetNotificationRequestFailedHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Game_RequestFailed, OnNetNotificationRequestFailedHandle);
		OnNetNotificationRequestFailedHandle.Reset();
	}
	
	if (OnNetNotificationGameStateResetHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Notification_Game_StateReset, OnNetNotificationGameStateResetHandle);
		OnNetNotificationGameStateResetHandle.Reset();
	}
	
	if (OnMatchmakingNotificationCancel2Handle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Matchmaking_Cancel2, OnMatchmakingNotificationCancel2Handle);
		OnMatchmakingNotificationCancel2Handle.Reset();
	}

	if (OnRoomNotificationLeaveHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_Leave, OnRoomNotificationLeaveHandle);
		OnRoomNotificationLeaveHandle.Reset();
	}

	if (OnRoomNotificationJoin2Handle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_Join2, OnRoomNotificationJoin2Handle);
		OnRoomNotificationJoin2Handle.Reset();
	}

	if (OnRoomNotificationSetDescriptionHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_SetDescription, OnRoomNotificationSetDescriptionHandle);
		OnRoomNotificationSetDescriptionHandle.Reset();
	}

	if (OnRoomNotificationKickUserHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_KickUser, OnRoomNotificationKickUserHandle);
		OnRoomNotificationKickUserHandle.Reset();
	}

	if (OnRoomNotificationUpdateOwnerHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_UpdateOwner, OnRoomNotificationUpdateOwnerHandle);
		OnRoomNotificationUpdateOwnerHandle.Reset();
	}

	if (OnRoomNotificationUpdateDataStoreHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_UpdateDataStore, OnRoomNotificationUpdateDataStoreHandle);
		OnRoomNotificationUpdateDataStoreHandle.Reset();
	}

	if (OnRoomNotificationUpdateMembershipLockStatusHandle.IsValid())
	{
		//PicoSubsystem.RemoveNotifyDelegate(ppfMessageType_Room_UpdateMembershipLockStatus, OnRoomNotificationUpdateMembershipLockStatusHandle);
		OnRoomNotificationUpdateMembershipLockStatusHandle.Reset();
	}
	
	PendingInviteAcceptedSessions.Empty();
	InviteAcceptedRoomID = 0;

	// Make sure the player leaves all the sessions they were in before destroying this
	for (auto It = Sessions.CreateConstIterator(); It; ++It)
	{
		TSharedPtr<FNamedOnlineSession> Session = It.Value();
		if (Session.IsValid())
		{
			ppfID RoomId = GetRoomIDOfSession(*Session);
			if (RoomId != 0)
			{
				ppf_Room_Leave(RoomId);
			}

			if (!Session.IsUnique())
			{
				SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("~FOnlineSessionPico Session (room %llu) is not unique"), RoomId));
			}
			Session->SessionState = EOnlineSessionState::Destroying;
		}
		else
		{
			SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("~FOnlineSessionPico session is invalid!")));
		}
	}
	Sessions.Empty();
};
// todo
ppfID FOnlineSessionPico::GetRoomIDOfSession(const FNamedOnlineSession& Session) const
{
    if (!Session.SessionInfo.IsValid() || !Session.SessionInfo.Get()->IsValid())
    {
        SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("GetRoomIDOfSession SessionInfoPtr is invalid or SessionInfo is invalid")));
        return 0;
    }
    const FUniqueNetIdPico& PicoId = FUniqueNetIdPico::Cast(Session.SessionInfo->GetSessionId());
    // if (!PicoId.IsValid())
    // {
    // 	SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("GetRoomIDOfSession PicoId is invalid")));
    // 	return 0;
    // }
    SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("GetRoomIDOfSession PicoId.GetID(): %llu"), PicoId.GetID()));
    return PicoId.GetID();
}

bool FOnlineSessionPico::CreateSession(int32 HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("CreateSession %s"), *InitStateErrorMessage));
        return false;
    }
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("CreateSession Cannot create session '%s': session already exists."), *SessionName.ToString()));
        return false;
    }
    IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
    if (!Identity.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("CreateSession pico identity is invalid")));
        return false;
    }
    if (NewSessionSettings.NumPrivateConnections > 0)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("CreateSession Pico NumPrivateConnections need be zero")));
        return false;
    }
    Session = AddNamedSession(SessionName, NewSessionSettings);
    check(Session);
    Session->SessionState = EOnlineSessionState::Creating;
    Session->NumOpenPrivateConnections = NewSessionSettings.NumPrivateConnections;
    Session->NumOpenPublicConnections = NewSessionSettings.NumPublicConnections;
    Session->HostingPlayerNum = HostingPlayerNum;
    Session->LocalOwnerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(HostingPlayerNum);
    Session->SessionSettings.BuildUniqueId = GetBuildUniqueId();
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateSession LocalOwnerId: %s, SessionSettings.BuildUniqueId: %d"),
        Session->LocalOwnerId != nullptr ? *(Session->LocalOwnerId->ToString()) : TEXT("nullptr"), Session->SessionSettings.BuildUniqueId));

    // only private room can set joinpolicy. matchmaking room joinpolicy is everyone.
    ppfRoomJoinPolicy JoinPolicy = ppfRoom_JoinPolicyEveryone;
    // create matchmaking room
    if (NewSessionSettings.Settings.Contains(SETTING_PICO_POOL))
    {
        return CreateMatchmakingSession(*Session, JoinPolicy);
    }
    JoinPolicy = ppfRoom_JoinPolicyInvitedUsers;
    if (NewSessionSettings.bShouldAdvertise)
    {
        if (NewSessionSettings.bAllowJoinViaPresenceFriendsOnly)
        {
            JoinPolicy = ppfRoom_JoinPolicyFriendsOfMembers;
        }
        else if (NewSessionSettings.bAllowInvites && !NewSessionSettings.bAllowJoinViaPresence)
        {
            JoinPolicy = ppfRoom_JoinPolicyInvitedUsers;
        }
        else
        {
            JoinPolicy = ppfRoom_JoinPolicyEveryone;
        }
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateSession JoinPolicy: %d"), JoinPolicy));
    // create private room
    return CreateRoomSession(*Session, JoinPolicy);
}

bool FOnlineSessionPico::CreateMatchmakingSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("CreateMatchmakingSession %s"), *InitStateErrorMessage));
        return false;
    }
    auto PoolSettings = Session.SessionSettings.Settings.Find(SETTING_PICO_POOL);
    FString Pool;
    PoolSettings->Data.GetValue(Pool);
    unsigned int MaxUsers = Session.SessionSettings.NumPublicConnections + Session.SessionSettings.NumPrivateConnections;
    ppfMatchmakingOptionsHandle MatchmakingOptions = ppf_MatchmakingOptions_Create();
    ppf_MatchmakingOptions_SetCreateRoomJoinPolicy(MatchmakingOptions, JoinPolicy);
    if (MaxUsers > 0)
    {
        ppf_MatchmakingOptions_SetCreateRoomMaxUsers(MatchmakingOptions, MaxUsers);
    }
    for (auto& item : Session.SessionSettings.Settings)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateMatchmakingSession set matchmakingoptions datastore: key: %s, value: %s"), *item.Key.ToString(), *item.Value.Data.ToString()));
        ppf_MatchmakingOptions_SetCreateRoomDataStoreString(MatchmakingOptions,
            TCHAR_TO_UTF8(*item.Key.ToString()),
            TCHAR_TO_UTF8(*item.Value.Data.ToString())
        );
    };
    auto BuildUniqueIdString = FString::FromInt(Session.SessionSettings.BuildUniqueId);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateMatchmakingSession set matchmakingoptions datastore SessionSettings.BuildUniqueId: %s"), *BuildUniqueIdString));
    ppf_MatchmakingOptions_SetCreateRoomDataStoreString(
        MatchmakingOptions,
        TCHAR_TO_UTF8(*SETTING_PICO_BUILD_UNIQUE_ID.ToString()),
        TCHAR_TO_UTF8(*BuildUniqueIdString)
    );

    auto RequestId = ppf_Matchmaking_CreateAndEnqueueRoom2(TCHAR_TO_ANSI(*Pool), MatchmakingOptions);
    PicoSubsystem.AddAsyncTask(
        RequestId,
        FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnCreateRoomComplete, Session.SessionName));
    ppf_MatchmakingOptions_Destroy(MatchmakingOptions);
    return true;
}

bool FOnlineSessionPico::CreateRoomSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("CreateRoomSession %s"), *InitStateErrorMessage));
        return false;
    }
    ppfRoomOptionsHandle RoomOptions = ppf_RoomOptions_Create();
    for (auto& item : Session.SessionSettings.Settings)
    {
        ppf_RoomOptions_SetDataStoreString(
            RoomOptions,
            TCHAR_TO_UTF8(*item.Key.ToString()),
            TCHAR_TO_UTF8(*item.Value.Data.ToString())
        );
    };
    auto BuildUniqueIdString = FString::FromInt(Session.SessionSettings.BuildUniqueId);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateRoomSession set roomoptions datastore SessionSettings.BuildUniqueId: %s"), *BuildUniqueIdString));
    ppf_RoomOptions_SetDataStoreString(
        RoomOptions,
        TCHAR_TO_UTF8(*SETTING_PICO_BUILD_UNIQUE_ID.ToString()),
        TCHAR_TO_UTF8(*BuildUniqueIdString)
    );
    unsigned int MaxUsers = Session.SessionSettings.NumPublicConnections + Session.SessionSettings.NumPrivateConnections;
    PicoSubsystem.AddAsyncTask(
        ppf_Room_CreateAndJoinPrivate2(JoinPolicy, MaxUsers, RoomOptions),
        FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnCreateRoomComplete, Session.SessionName));
    ppf_RoomOptions_Destroy(RoomOptions);
    return true;
}

void FOnlineSessionPico::OnCreateRoomComplete(ppfMessageHandle Message, bool bIsError, FName SessionName)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnCreateRoomComplete %s"), *InitStateErrorMessage));
        return;
    }
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnCreateRoomComplete ErrorMessage: %s"), *FString(ErrorMessage)));
        RemoveNamedSession(SessionName);
        TriggerOnCreateSessionCompleteDelegates(SessionName, false);
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnCreateRoomComplete SessionName: %s"), *SessionName.ToString()));
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnCreateRoomComplete cannot find session: %s"), *SessionName.ToString()));
        TriggerOnCreateSessionCompleteDelegates(SessionName, false);
        return;
    }
    if (Session->SessionState != EOnlineSessionState::Creating)
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnCreateRoomComplete Session %s existed!"), *SessionName.ToString()));
        TriggerOnCreateSessionCompleteDelegates(SessionName, false);
        return;
    }

    ppfRoomHandle Room;
    ppfID RoomId;
    auto MessageType = ppf_Message_GetType(Message);
    if (MessageType == ppfMessageType::ppfMessageType_Matchmaking_CreateAndEnqueueRoom2)
    {
        auto EnqueueResultAndRoom = ppf_Message_GetMatchmakingEnqueueResultAndRoom(Message);
        Room = ppf_MatchmakingEnqueueResultAndRoom_GetRoom(EnqueueResultAndRoom);
    }
    else
    {
        Room = ppf_Message_GetRoom(Message);
    }
    RoomId = ppf_Room_GetID(Room);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnCreateRoomComplete RoomId: %llu"), RoomId));
    Session->SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomId));
    UpdateSessionFromRoom(*Session, Room);
    Session->SessionState = EOnlineSessionState::Pending;
    TriggerOnCreateSessionCompleteDelegates(SessionName, true);
}

bool FOnlineSessionPico::CreateSession(const FUniqueNetId& HostingPlayerId, FName SessionName, const FOnlineSessionSettings& NewSessionSettings)
{
    return CreateSession(0, SessionName, NewSessionSettings);
}

bool FOnlineSessionPico::StartSession(FName SessionName)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("StartSession %s"), *InitStateErrorMessage));
        return false;
    }
    auto Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartSession cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    if (Session->SessionState != EOnlineSessionState::Pending && Session->SessionState != EOnlineSessionState::Ended)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartSession Session: %s State is %s, cannot start!"),
            *SessionName.ToString(),
            EOnlineSessionState::ToString(Session->SessionState)));
        TriggerOnStartSessionCompleteDelegates(SessionName, false);
        return false;
    }
    Session->SessionState = EOnlineSessionState::InProgress;
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("StartSession set current SessionState: InProgress")));
    TriggerOnStartSessionCompleteDelegates(SessionName, true);
    return true;
}

bool FOnlineSessionPico::UpdateSession(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, bool bShouldRefreshOnlineData)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateSession %s"), *InitStateErrorMessage));
        return false;
    }
    auto Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("UpdateSession cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSession LoggedInPlayerId: %s, Session->OwningUserId: %s"),
        LoggedInPlayerId.IsValid() ? *(LoggedInPlayerId->ToString()) : TEXT("invalid"), *(Session->OwningUserId->ToString())));
    if (!LoggedInPlayerId.IsValid() || Session->OwningUserId.ToSharedRef().Get() != *LoggedInPlayerId)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("UpdateSession You are not the owner of the session: %s. Current Owner: %s"),
            *SessionName.ToString(), *Session->OwningUserName));
        return false;
    }
    if (Session->SessionSettings.Settings.Contains(SETTING_PICO_POOL))
    {
        Session->SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
    }
    return UpdateRoomDataStore(SessionName, UpdatedSessionSettings);
}

bool FOnlineSessionPico::UpdateRoomDataStore(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateRoomDataStore %s"), *InitStateErrorMessage));
        return false;
    }
    auto Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("UpdateRoomDataStore cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    int NewDataStoreSize = 0;
    for (auto Setting : UpdatedSessionSettings.Settings)
    {
        NewDataStoreSize++;
    }
    int index = 0;

    ppfKeyValuePairArray DataStore = ppf_KeyValuePairArray_Create(NewDataStoreSize);
    for (auto& Setting : UpdatedSessionSettings.Settings)
    {
        auto Key = new FTCHARToUTF8(*Setting.Key.ToString());
        auto Value = new FTCHARToUTF8(*Setting.Value.Data.ToString());
        auto item = ppf_KeyValuePairArray_GetElement(DataStore, index);
        ppf_KeyValuePair_SetKey(item, Key->Get());
        ppf_KeyValuePair_SetStringValue(item, Value->Get());
        index++;
    }

    if (NewDataStoreSize > 0)
    {
        PicoSubsystem.AddAsyncTask(
            ppf_Room_UpdateDataStore(GetRoomIDOfSession(*Session), DataStore, NewDataStoreSize),
            FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName](ppfMessageHandle Message, bool bIsError)
                {
                    if (bIsError)
                    {
                        auto Error = ppf_Message_GetError(Message);
                        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateRoomDataStore ErrorMessage: %s"), *FString(ErrorMessage)));
                        TriggerOnUpdateSessionCompleteDelegates(SessionName, false);
                        return;
                    }

                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateRoomDataStore no error")));
                    auto NewSession = GetNamedSession(SessionName);
                    if (NewSession == nullptr)
                    {
                        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateRoomDataStore Session: %s does not exist"), *SessionName.ToString()));
                        TriggerOnUpdateSessionCompleteDelegates(SessionName, false);
                        return;
                    }
                    auto Room = ppf_Message_GetRoom(Message);
                    UpdateSessionFromRoom(*NewSession, Room);
                    TriggerOnUpdateSessionCompleteDelegates(SessionName, true);
                }));
        ppf_KeyValuePairArray_Destroy(DataStore);
    }
    else
    {
        TriggerOnUpdateSessionCompleteDelegates(SessionName, true);
    }
    return true;
}

bool FOnlineSessionPico::EndSession(FName SessionName)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("EndSession %s"), *InitStateErrorMessage));
        return false;
    }
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("EndSession cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    if (Session->SessionState != EOnlineSessionState::InProgress)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("EndSession Session: %s, SessionState: %s"),
            *SessionName.ToString(),
            EOnlineSessionState::ToString(Session->SessionState)));
        TriggerOnEndSessionCompleteDelegates(SessionName, false);
        return false;
    }
    Session->SessionState = EOnlineSessionState::Ended;
    TriggerOnEndSessionCompleteDelegates(SessionName, true);
    return true;
}

bool FOnlineSessionPico::DestroySession(FName SessionName, const FOnDestroySessionCompleteDelegate& CompletionDelegate)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("DestroySession %s"), *InitStateErrorMessage));
        return false;
    }
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("DestroySession cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    auto RoomId = GetRoomIDOfSession(*Session);
    Session->SessionState = EOnlineSessionState::Destroying;
    PicoSubsystem.AddAsyncTask(
        ppf_Room_Leave(RoomId),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName, Session, CompletionDelegate](ppfMessageHandle Message, bool bIsError)
            {
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("DestroySession error! ErrorMessage: %s"), *FString(ErrorMessage)));
                    CompletionDelegate.ExecuteIfBound(SessionName, false);
                    TriggerOnDestroySessionCompleteDelegates(SessionName, false);
                    return;
                }

                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("DestroySession no error")));
                RemoveNamedSession(SessionName);
                CompletionDelegate.ExecuteIfBound(SessionName, true);
                TriggerOnDestroySessionCompleteDelegates(SessionName, true);
            }));
    return true;
}

bool FOnlineSessionPico::IsPlayerInSession(FName SessionName, const FUniqueNetId& UniqueId)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("IsPlayerInSession %s"), *InitStateErrorMessage));
        return false;
    }
    auto Session = GetNamedSession(SessionName);
    if (Session == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("IsPlayerInSession cannot find session: %s"), *SessionName.ToString()));
        return false;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("IsPlayerInSession UniqueId.ToString(): %s"), *UniqueId.ToString()));
    for (auto Player : Session->RegisteredPlayers)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("IsPlayerInSession Player->ToString(): %s"), *Player->ToString()));
        if (*Player == UniqueId)
        {
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("IsPlayerInSession: true")));
            return true;
        }
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("IsPlayerInSession: false")));
    return false;
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineSessionPico::StartMatchmaking(const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineSessionPico::StartMatchmaking(const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineSessionPico::StartMatchmaking(const TArray< TSharedRef<const FUniqueNetId> >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings)
#endif
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("StartMatchmaking %s"), *InitStateErrorMessage));
        return false;
    }
    if (LocalPlayers.Num() > 1)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartMatchmaking LocalPlayers.Num() > 1 cannot start matchmaking")));
        return false;
    }
    FString Pool;
    if (!SearchSettings->QuerySettings.Get(SETTING_PICO_POOL, Pool))
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartMatchmaking Please set SETTING_PICO_POOL: %s"), *SETTING_PICO_POOL.ToString()));
        if (!SearchSettings->QuerySettings.Get(SETTING_MAPNAME, Pool))
        {
            return false;
        }
    }
    if (NewSessionSettings.NumPrivateConnections > 0)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartMatchmaking Pico does not support NumPrivateConnections > 0")));
        return false;
    }
    if (IsInMatchmakingProgress())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("StartMatchmaking You are already in matchmaking progress")));
        return false;
    }
    if (InProgressMatchmakingSearch.IsValid())
    {
        InProgressMatchmakingSearch.Reset();
    }
    SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
    InProgressMatchmakingSearch = SearchSettings;
    InProgressMatchmakingSearchName = SessionName;
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("StartMatchmaking PoolName: %s"), *Pool));
    ppfMatchmakingOptionsHandle MatchmakingOptions = ppf_MatchmakingOptions_Create();
    PicoSubsystem.AddAsyncTask(
        ppf_Matchmaking_Enqueue2(TCHAR_TO_UTF8(*Pool), MatchmakingOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName, SearchSettings](ppfMessageHandle Message, bool bIsError)
            {
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("StartMatchmaking OnComplete ErrorMessage: %s"), *FString(ErrorMessage)));
                    SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
                    if (InProgressMatchmakingSearch.IsValid())
                    {
                        InProgressMatchmakingSearch.Reset();
                    }
                    TriggerOnMatchmakingCompleteDelegates(SessionName, false);
                }
                else
                {
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("StartMatchmaking OnComplete no error")));
                }
            }));
    ppf_MatchmakingOptions_Destroy(MatchmakingOptions);
    return true;
}

bool FOnlineSessionPico::CancelMatchmaking(int32 SearchingPlayerNum, FName SessionName)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("CancelMatchmaking %s"), *InitStateErrorMessage));
        return false;
    }
    PicoSubsystem.AddAsyncTask(
        ppf_Matchmaking_Cancel2(),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName](ppfMessageHandle Message, bool bIsError)
            {
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("CancelMatchmaking OnComplete ErrorMessage: %s"), *FString(ErrorMessage)));
                    TriggerOnCancelMatchmakingCompleteDelegates(SessionName, false);
                    return;
                }
                if (InProgressMatchmakingSearch.IsValid() && SessionName == InProgressMatchmakingSearchName)
                {
                    InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Failed;
                    InProgressMatchmakingSearch = nullptr;
                }
                TriggerOnCancelMatchmakingCompleteDelegates(SessionName, true);
            }));
    return true;
}

bool FOnlineSessionPico::CancelMatchmaking(const FUniqueNetId& SearchingPlayerId, FName SessionName)
{
    return CancelMatchmaking(0, SessionName);
}

bool FOnlineSessionPico::FindSessions(int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindSessions %s"), *InitStateErrorMessage));
        return false;
    }
    if (SearchSettings->MaxSearchResults <= 0)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindSessions MaxSearchResults <= 0")));
        SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
        TriggerOnFindSessionsCompleteDelegates(false);
        return false;
    }
    bool bFindOnlyModeratedRooms = false;
    auto GetValueResult = SearchSettings->QuerySettings.Get(SEARCH_PICO_MODERATED_ROOMS_ONLY, bFindOnlyModeratedRooms);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessions GetValueResult: %d, bFindOnlyModeratedRooms: %d"), GetValueResult, bFindOnlyModeratedRooms));
    if (GetValueResult && bFindOnlyModeratedRooms)
    {
        return FindModeratedRoomSessions(SearchSettings);
    }
    FString Pool;
    if (SearchSettings->QuerySettings.Get(SETTING_PICO_POOL, Pool))
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessions FindMatchmakingSessions Pool: %s"), *Pool));
        return FindMatchmakingSessions(Pool, SearchSettings);
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessions Nothing to find")));
    SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
    TriggerOnFindSessionsCompleteDelegates(false);
    return false;
}

bool FOnlineSessionPico::FindSessions(const FUniqueNetId& SearchingPlayerId, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
    return FindSessions(0, SearchSettings);
}

bool FOnlineSessionPico::FindModeratedRoomSessions(const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindModeratedRoomSessions %s"), *InitStateErrorMessage));
        return false;
    }
    FString PageIndex;
    if (!SearchSettings->QuerySettings.Get(GET_MODERATEDROOMS_PAGEINDEX, PageIndex))
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindModeratedRoomSessions Error: Cannot get GET_MODERATEDROOMS_PAGEINDEX")));
        return false;
    }
    FString PageSize;
    if (!SearchSettings->QuerySettings.Get(GET_MODERATEDROOMS_PAGESIZE, PageSize))
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindModeratedRoomSessions Error: Cannot get GET_MODERATEDROOMS_PAGESIZE")));
        return false;
    }

    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindModeratedRoomSessions PageIndex: %s, PageSize: %s"), *PageIndex, *PageSize));
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindModeratedRoomSessions PageIndex: %d, PageSize: %d"), FCString::Atoi(*PageIndex), FCString::Atoi(*PageSize)));
    SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
    PicoSubsystem.AddAsyncTask(
        ppf_Room_GetModeratedRooms(FCString::Atoi(*PageIndex), FCString::Atoi(*PageSize)),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SearchSettings](ppfMessageHandle Message, bool bIsError)
            {
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindModeratedRoomSessions OnComplete ErrorMessage: %s"), *FString(ErrorMessage)));
                    SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
                    TriggerOnFindSessionsCompleteDelegates(false);
                    return;
                }
                auto RoomArray = ppf_Message_GetRoomArray(Message);
                auto SearchResultsSize = ppf_RoomArray_GetSize(RoomArray);
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindModeratedRoomSessions SearchResultsSize: %zu"), SearchResultsSize));
                if (SearchResultsSize > SearchSettings->MaxSearchResults)
                {
                    SearchResultsSize = SearchSettings->MaxSearchResults;
                }
                SearchSettings->SearchResults.Reset(SearchResultsSize);
                int32 BuildUniqueId = GetBuildUniqueId();
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindModeratedRoomSessions GetBuildUniqueId(): %d"), BuildUniqueId));
                for (size_t i = 0; i < SearchResultsSize; i++)
                {
                    auto Room = ppf_RoomArray_GetElement(RoomArray, i);
                    int32 ServerBuildId = GetRoomBuildUniqueId(Room);
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindModeratedRoomSessions ServerBuildId: %d"), ServerBuildId));
                    if (ServerBuildId != 0 && ServerBuildId != BuildUniqueId)
                    {
                        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindModeratedRoomSessions ServerBuildId != 0 && ServerBuildId != BuildUniqueId")));
                        // continue;
                    }
                    auto Session = CreateSessionFromRoom(Room);
                    auto SearchResult = FOnlineSessionSearchResult();
                    SearchResult.Session = Session.Get();
                    SearchResult.PingInMs = 0;
                    SearchSettings->SearchResults.Add(MoveTemp(SearchResult));
                }
                SearchSettings->SearchState = EOnlineAsyncTaskState::Done;
                TriggerOnFindSessionsCompleteDelegates(true);
            }));
    return true;
}

bool FOnlineSessionPico::FindMatchmakingSessions(const FString Pool, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindMatchmakingSessions %s"), *InitStateErrorMessage));
        return false;
    }
    if (InProgressMatchmakingSearch.IsValid())
    {
        InProgressMatchmakingSearch.Reset();
    }
    SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
    InProgressMatchmakingSearch = SearchSettings;
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindMatchmakingSessions begin ppf_Matchmaking_Browse2 Pool: %s"), *Pool));
    ppfMatchmakingOptionsHandle MatchmakingOptions = ppf_MatchmakingOptions_Create();
    PicoSubsystem.AddAsyncTask(
        ppf_Matchmaking_Browse2(TCHAR_TO_UTF8(*Pool), MatchmakingOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SearchSettings](ppfMessageHandle Message, bool bIsError)
            {
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindMatchmakingSessions OnComplete ErrorMessage: %s"), *FString(ErrorMessage)));
                    SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
                    TriggerOnFindSessionsCompleteDelegates(false);
                    return;
                }
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindMatchmakingSessions OnComplete no error")));
                auto BrowseResult = ppf_Message_GetMatchmakingBrowseResult(Message);
                auto RoomArray = ppf_MatchmakingBrowseResult_GetRooms(BrowseResult);
                auto SearchResultsSize = ppf_MatchmakingRoomArray_GetSize(RoomArray);
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindMatchmakingSessions SearchResultsSize: %zu, MaxSearchResults: %d"), SearchResultsSize, SearchSettings->MaxSearchResults));
                if (SearchResultsSize > SearchSettings->MaxSearchResults)
                {
                    SearchResultsSize = SearchSettings->MaxSearchResults;
                }
                SearchSettings->SearchResults.Reset(SearchResultsSize);
                int32 BuildUniqueId = GetBuildUniqueId();
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindMatchmakingSessions GetBuildUniqueId(): %d"), BuildUniqueId));
                for (size_t i = 0; i < SearchResultsSize; i++)
                {
                    auto MatchmakingRoom = ppf_MatchmakingRoomArray_GetElement(RoomArray, i);
                    auto Room = ppf_MatchmakingRoom_GetRoom(MatchmakingRoom);
                    int32 ServerBuildId = GetRoomBuildUniqueId(Room);
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindMatchmakingSessions ServerBuildId: %d"), ServerBuildId));
                    if (ServerBuildId != BuildUniqueId)
                    {
                        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindMatchmakingSessions ServerBuildId != BuildUniqueId")));
                        // continue;
                    }
                    auto Session = CreateSessionFromRoom(Room);
                    auto SearchResult = FOnlineSessionSearchResult();
                    SearchResult.Session = Session.Get();
                    SearchResult.PingInMs = ppf_MatchmakingRoom_HasPingTime(MatchmakingRoom) ? ppf_MatchmakingRoom_GetPingTime(MatchmakingRoom) : 0;
                    SearchSettings->SearchResults.Add(MoveTemp(SearchResult));
                }
                SearchSettings->SearchState = EOnlineAsyncTaskState::Done;
                TriggerOnFindSessionsCompleteDelegates(true);
            }));
    ppf_MatchmakingOptions_Destroy(MatchmakingOptions);
    return true;
}

bool FOnlineSessionPico::FindSessionById(const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FOnSingleSessionResultCompleteDelegate& CompletionDelegate)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindSessionById %s"), *InitStateErrorMessage));
        return false;
    }
    auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
    if (LoggedInPlayerId.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById LoggedInPlayerId: %s"), *LoggedInPlayerId->ToString()));
    }
    if (!LoggedInPlayerId.IsValid() || SearchingUserId != *LoggedInPlayerId)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindSessionById Need login first or SearchingUserId != LoggedInPlayerId")));
        return false;
    }
    if (FriendId.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindSessionById FriendId is not supported")));
        return false;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById SessionId: %s"), *SessionId.ToString()));
    const FUniqueNetIdPico& RoomId = static_cast<const FUniqueNetIdPico&>(SessionId);
    ppfID ppfIDRoomID = FCString::Strtoui64(*RoomId.GetStringID(), NULL, 10);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById ppf_Room_Get RoomId: %s, %llu"), *RoomId.GetStringID(), ppfIDRoomID));
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById begin ppf_Room_Get")));
    PicoSubsystem.AddAsyncTask(
        ppf_Room_Get(ppfIDRoomID),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, CompletionDelegate](ppfMessageHandle Message, bool bIsError)
            {
                auto SearchResult = FOnlineSessionSearchResult();
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindSessionById ErrorMessage: %s"), *FString(ErrorMessage)));
                    CompletionDelegate.ExecuteIfBound(0, false, SearchResult);
                    return;
                }
                auto Room = ppf_Message_GetRoom(Message);
                if (Room == nullptr)
                {
                    CompletionDelegate.ExecuteIfBound(0, false, SearchResult);
                    return;
                }
                int32 BuildUniqueId = GetBuildUniqueId();
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById GetBuildUniqueId(): %d"), BuildUniqueId));
                int32 ServerBuildId = GetRoomBuildUniqueId(Room);
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById ServerBuildId: %d"), ServerBuildId));
                if (ServerBuildId != 0 && ServerBuildId != BuildUniqueId)
                {
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindSessionById ServerBuildId != BuildUniqueId")));
                    // CompletionDelegate.ExecuteIfBound(0, false, SearchResult);
                    // return;
                }
                auto Session = CreateSessionFromRoom(Room);
                SearchResult.Session = Session.Get();
                auto RoomJoinability = ppf_Room_GetJoinability(Room);
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindSessionById RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability])));
                CompletionDelegate.ExecuteIfBound(0, RoomJoinability == ppfRoom_JoinabilityCanJoin, SearchResult);
            }));
    return true;
}

bool FOnlineSessionPico::CancelFindSessions()
{
    return false;
}

bool FOnlineSessionPico::JoinSession(int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("JoinSession %s"), *InitStateErrorMessage));
        return false;
    }
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("JoinSession Already in Session: %s"), *SessionName.ToString()));
        TriggerOnJoinSessionCompleteDelegates(SessionName, EOnJoinSessionCompleteResult::AlreadyInSession);
        return false;
    }
    if (!DesiredSession.Session.SessionInfo.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("JoinSession SessionInfo is invalid")));
        TriggerOnJoinSessionCompleteDelegates(SessionName, EOnJoinSessionCompleteResult::SessionDoesNotExist);
        return false;
    }
    Session = AddNamedSession(SessionName, DesiredSession.Session);
    check(Session);
    Session->SessionState = EOnlineSessionState::Creating;
    Session->HostingPlayerNum = PlayerNum;
    Session->LocalOwnerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(PlayerNum);
    auto SearchSessionInfo = static_cast<const FOnlineSessionInfoPico*>(DesiredSession.Session.SessionInfo.Get());
    auto RoomId = FUniqueNetIdPico::Cast(SearchSessionInfo->GetSessionId()).GetID();
    auto RoomOptions = ppf_RoomOptions_Create();
    ppf_RoomOptions_SetTurnOffUpdates(RoomOptions, true);
    // SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("JoinSession befor ppf_Room_Join2 RoomId: %s"), SearchSessionInfo->GetSessionId()));
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("JoinSession befor ppf_Room_Join2 RoomId: %llu"), RoomId));
    PicoSubsystem.AddAsyncTask(
        ppf_Room_Join2(RoomId, RoomOptions),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName, Session](ppfMessageHandle Message, bool bIsError)
            {
                auto Room = ppf_Message_GetRoom(Message);
                if (bIsError)
                {
                    auto Error = ppf_Message_GetError(Message);
                    FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                    FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                    ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                    SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("JoinSession OnComplete ErrorMessage: %s"), *FString(ErrorMessage)));
                    RemoveNamedSession(SessionName);
                    auto RoomJoinability = ppf_Room_GetJoinability(Room);
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("JoinSession RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability])));
                    EOnJoinSessionCompleteResult::Type FailureReason;
                    if (RoomJoinability == ppfRoom_JoinabilityIsFull)
                    {
                        FailureReason = EOnJoinSessionCompleteResult::SessionIsFull;
                    }
                    else if (RoomJoinability == ppfRoom_JoinabilityAreIn)
                    {
                        FailureReason = EOnJoinSessionCompleteResult::AlreadyInSession;
                    }
                    else
                    {
                        FailureReason = EOnJoinSessionCompleteResult::UnknownError;
                    }
                    TriggerOnJoinSessionCompleteDelegates(SessionName, FailureReason);
                    return;
                }
            
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("JoinSession OnComplete no error")));
                UpdateSessionFromRoom(*Session, Room);
                TriggerOnJoinSessionCompleteDelegates(SessionName, EOnJoinSessionCompleteResult::Success);
            }));
    return true;
}

bool FOnlineSessionPico::JoinSession(const FUniqueNetId& PlayerId, FName SessionName, const FOnlineSessionSearchResult& DesiredSession)
{
    return JoinSession(0, SessionName, DesiredSession);
}

bool FOnlineSessionPico::FindFriendSession(int32 LocalUserNum, const FUniqueNetId& Friend)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("FindFriendSession %s"), *InitStateErrorMessage));
        return false;
    }
    auto PicoId = static_cast<const FUniqueNetIdPico&>(Friend);
    PicoSubsystem.AddAsyncTask(
        ppf_Room_GetCurrentForUser(TCHAR_TO_ANSI(*PicoId.GetStringID())),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, LocalUserNum](ppfMessageHandle Message, bool bIsError)
            {
                TArray<FOnlineSessionSearchResult> SearchResult;
                SearchResult.Add(FOnlineSessionSearchResult());
                if (bIsError)
                {
                    TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, false, SearchResult);
                    return;
                }
                auto Room = ppf_Message_GetRoom(Message);
                if (Room == nullptr)
                {
                    TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, false, SearchResult);
                    return;
                }
                int32 BuildUniqueId = GetBuildUniqueId();
                int32 ServerBuildId = GetRoomBuildUniqueId(Room);
                if (ServerBuildId != BuildUniqueId)
                {
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("FindFriendSession ServerBuildId != BuildUniqueId")));
                    // TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, false, SearchResult);
                    // return;
                }
                auto Session = CreateSessionFromRoom(Room);
                SearchResult[0].Session = Session.Get();
                auto RoomJoinability = ppf_Room_GetJoinability(Room);
                //SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("FindFriendSession RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability])));
                TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, RoomJoinability == ppfRoom_JoinabilityCanJoin, SearchResult);
            }));
    return true;
};

bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const FUniqueNetId& Friend)
{
    return FindFriendSession(0, Friend);
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<FUniqueNetIdRef>& FriendList)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<FUniqueNetIdRef>& FriendList)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<TSharedRef<const FUniqueNetId>>& FriendList)
#endif
{
    // todo
    return false;
}

bool FOnlineSessionPico::SendSessionInviteToFriend(int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("SendSessionInviteToFriend %s"), *InitStateErrorMessage));
        return false;
    }
#if ENGINE_MAJOR_VERSION > 4
    TArray< FUniqueNetIdRef > Friends;
    const FUniqueNetIdPico& PicoFriend = static_cast<const FUniqueNetIdPico&>(Friend);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriend PicoFriend StrID: %s"), *PicoFriend.GetStringID()));
    auto NewFriend = FUniqueNetIdPico::Create(PicoFriend.GetStringID());
#elif ENGINE_MINOR_VERSION > 26
    TArray< FUniqueNetIdRef > Friends;
    const FUniqueNetIdPico& PicoFriend = static_cast<const FUniqueNetIdPico&>(Friend);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriend PicoFriend StrID: %s"), *PicoFriend.GetStringID()));
    auto NewFriend = FUniqueNetIdPico::Create(PicoFriend.GetStringID());
#elif ENGINE_MINOR_VERSION > 24
    TArray< TSharedRef<const FUniqueNetId> > Friends;
    const FUniqueNetIdPico& PicoFriend = static_cast<const FUniqueNetIdPico&>(Friend);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriend PicoFriend StrID: %s"), *PicoFriend.GetStringID()));
    TSharedRef<const FUniqueNetId> NewFriend = MakeShareable(new FUniqueNetIdPico(PicoFriend.GetStringID()));
#endif
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriend NewFriend StrID: %s"), *NewFriend->ToString()));
    Friends.Add(NewFriend);

    return SendSessionInviteToFriends(LocalUserNum, SessionName, Friends);
};

bool FOnlineSessionPico::SendSessionInviteToFriend(const FUniqueNetId& LocalUserId, FName SessionName, const FUniqueNetId& Friend)
{
    return SendSessionInviteToFriend(0, SessionName, Friend);
}
#if ENGINE_MAJOR_VERSION > 4
bool FOnlineSessionPico::SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineSessionPico::SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineSessionPico::SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Friends)
#endif
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("SendSessionInviteToFriends %s"), *InitStateErrorMessage));
        return false;
    }
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (!Session)
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("SendSessionInviteToFriends Cannot find Session: %s"), *SessionName.ToString()));
        return false;
    }
    IOnlineFriendsPtr FriendsInterface = PicoSubsystem.GetFriendsInterface();
    if (!FriendsInterface.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("SendSessionInviteToFriends FriendsInterface is invalid")));
        return false;
    }
    auto RoomId = GetRoomIDOfSession(*Session);
    TSharedPtr<FOnlineFriendsPico, ESPMode::ThreadSafe> FriendsInterfacePicoPtr = StaticCastSharedPtr<FOnlineFriendsPico>(FriendsInterface);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriends RoomId: %llu"), RoomId));
    FriendsInterfacePicoPtr->ReadFriendsList(
        LocalUserNum,
        FOnlineFriendsPico::FriendsListInviteableUsers,
        RoomId,
        FOnReadFriendsListComplete::CreateLambda([RoomId, FriendsInterface, Friends](int32 InLocalUserNum, bool bWasSuccessful, const FString& ListName, const FString& ErrorName) {
            if (!bWasSuccessful)
            {
                SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("SendSessionInviteToFriends ReadFriendsList OnComplete ErrorName: %s"), *ErrorName));
                return;
            }
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriends ReadFriendsList OnComplete no error")));
            for (auto FriendId : Friends)
            {
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriends InLocalUserNum: %d"), InLocalUserNum));
                auto Friend = FriendsInterface->GetFriend(InLocalUserNum, FriendId.Get(), ListName);
                if (Friend.IsValid())
                {
                    auto PicoFriend = static_cast<const FOnlinePicoFriend&>(*Friend);
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriends ppf_Room_InviteUser InviteToken: %s"), *PicoFriend.GetInviteToken()));
                    ppf_Room_InviteUser(RoomId, TCHAR_TO_UTF8(*PicoFriend.GetInviteToken()));
                }
                else
                {
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("SendSessionInviteToFriends Friend is invalid.")));
                }
            }
            }));
    return true;
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineSessionPico::SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineSessionPico::SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineSessionPico::SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Friends)
#endif
{
    return SendSessionInviteToFriends(0, SessionName, Friends);
}

bool FOnlineSessionPico::PingSearchResults(const FOnlineSessionSearchResult& SearchResult)
{
    return false;
}

bool FOnlineSessionPico::GetResolvedConnectString(FName SessionName, FString& ConnectInfo, FName PortType)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("GetResolvedConnectString %s"), *InitStateErrorMessage));
        return false;
    }
    auto Session = GetNamedSession(SessionName);
    if (Session != nullptr)
    {
        auto OwnerId = static_cast<const FUniqueNetIdPico*>(Session->OwningUserId.Get());
        ConnectInfo = FString::Printf(TEXT("%llu.pico"), OwnerId->GetID()); // todo
        return true;
    }
    return false;
}

bool FOnlineSessionPico::GetResolvedConnectString(const FOnlineSessionSearchResult& SearchResult, FName PortType, FString& ConnectInfo)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("GetResolvedConnectString %s"), *InitStateErrorMessage));
        return false;
    }
    if (SearchResult.IsValid())
    {
        auto Session = SearchResult.Session;
        auto OwnerId = static_cast<const FUniqueNetIdPico*>(Session.OwningUserId.Get());
        ConnectInfo = FString::Printf(TEXT("%llu.pico"), OwnerId->GetID()); // todo
        return true;
    }
    return false;
}

FOnlineSessionSettings* FOnlineSessionPico::GetSessionSettings(FName SessionName)
{
    FNamedOnlineSession* Session = GetNamedSession(SessionName);
    if (Session)
    {
        return &Session->SessionSettings;
    }
    return nullptr;
}

bool FOnlineSessionPico::RegisterPlayer(FName SessionName, const FUniqueNetId& PlayerId, bool bWasInvited)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("RegisterPlayer %s"), *InitStateErrorMessage));
        return false;
    }
#if ENGINE_MAJOR_VERSION > 4
    TArray< FUniqueNetIdRef > Players;
    Players.Add(FUniqueNetIdPico::Create(PlayerId));
#elif ENGINE_MINOR_VERSION > 26
    TArray< FUniqueNetIdRef > Players;
    Players.Add(FUniqueNetIdPico::Create(PlayerId));
#elif ENGINE_MINOR_VERSION > 24
    TArray< TSharedRef<const FUniqueNetId> > Players;
    Players.Add(MakeShareable(new FUniqueNetIdPico(PlayerId)));
#endif
    TriggerOnRegisterPlayersCompleteDelegates(SessionName, Players, true);
    return true;
}

bool FOnlineSessionPico::RegisterPlayers(FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Players, bool bWasInvited)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("RegisterPlayers %s"), *InitStateErrorMessage));
        return false;
    }
    TriggerOnRegisterPlayersCompleteDelegates(SessionName, Players, true);
    return true;
}


bool FOnlineSessionPico::UnregisterPlayer(FName SessionName, const FUniqueNetId& PlayerId)
{
    return false;
}

#if ENGINE_MAJOR_VERSION > 4
bool FOnlineSessionPico::UnregisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players)
#elif ENGINE_MINOR_VERSION > 26
bool FOnlineSessionPico::UnregisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players)
#elif ENGINE_MINOR_VERSION > 24
bool FOnlineSessionPico::UnregisterPlayers(FName SessionName, const TArray< TSharedRef<const FUniqueNetId> >& Players)
#endif
{
    return false;
}

int32 FOnlineSessionPico::GetNumSessions()
{
    return Sessions.Num();
}

void FOnlineSessionPico::DumpSessionState()
{
    for (auto Session : Sessions)
    {
        TestDumpNamedSession(Session.Value.Get());
    }
}

void FOnlineSessionPico::RegisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnRegisterLocalPlayerCompleteDelegate& Delegate)
{
    Delegate.ExecuteIfBound(PlayerId, EOnJoinSessionCompleteResult::UnknownError);
}

void FOnlineSessionPico::UnregisterLocalPlayer(const FUniqueNetId& PlayerId, FName SessionName, const FOnUnregisterLocalPlayerCompleteDelegate& Delegate)
{
    Delegate.ExecuteIfBound(PlayerId, false);
}

#if ENGINE_MAJOR_VERSION > 4
FUniqueNetIdPtr FOnlineSessionPico::CreateSessionIdFromString(const FString& SessionIdStr)
{
    FUniqueNetIdPtr SessionId;
#elif ENGINE_MINOR_VERSION > 26
FUniqueNetIdPtr FOnlineSessionPico::CreateSessionIdFromString(const FString & SessionIdStr)
{
    FUniqueNetIdPtr SessionId;
#elif ENGINE_MINOR_VERSION > 24
TSharedPtr<const FUniqueNetId> FOnlineSessionPico::CreateSessionIdFromString(const FString & SessionIdStr)
{
    TSharedPtr<const FUniqueNetId> SessionId;
#endif
    return SessionId;
}

FNamedOnlineSession* FOnlineSessionPico::GetNamedSession(FName SessionName)
{
    if (Sessions.Contains(SessionName))
    {
        return Sessions[SessionName].Get();
    }
    return nullptr;
}

void FOnlineSessionPico::RemoveNamedSession(FName SessionName)
{
    if (Sessions.Contains(SessionName))
    {
        Sessions.Remove(SessionName);
    }
}

EOnlineSessionState::Type FOnlineSessionPico::GetSessionState(FName SessionName) const
{
    if (Sessions.Contains(SessionName))
    {
        return Sessions[SessionName]->SessionState;
    }
    return EOnlineSessionState::NoSession;
}

bool FOnlineSessionPico::HasPresenceSession()
{
    for (auto it = Sessions.CreateIterator(); it; ++it)
    {
        if (it.Value()->SessionSettings.bUsesPresence)
        {
            return true;
        }
    }
    return false;
}

FNamedOnlineSession* FOnlineSessionPico::AddNamedSession(FName SessionName, const FOnlineSessionSettings & SessionSettings)
{
    TSharedPtr<FNamedOnlineSession> Session = MakeShareable(new FNamedOnlineSession(SessionName, SessionSettings));
    Sessions.Add(SessionName, Session);
    return Session.Get();
}

FNamedOnlineSession* FOnlineSessionPico::AddNamedSession(FName SessionName, const FOnlineSession & Session)
{
    TSharedPtr<FNamedOnlineSession> NamedSession = MakeShareable(new FNamedOnlineSession(SessionName, Session));
    Sessions.Add(SessionName, NamedSession);
    return NamedSession.Get();
}

TSharedRef<FOnlineSession> FOnlineSessionPico::CreateSessionFromRoom(ppfRoomHandle Room) const
{
    auto RoomId = ppf_Room_GetID(Room);
    auto RoomOwner = ppf_Room_GetOwner(Room);
    auto RoomMaxUsers = ppf_Room_GetMaxUsers(Room);
    auto RoomUsers = ppf_Room_GetUsers(Room);
    auto RoomCurrentUsersSize = ppf_UserArray_GetSize(RoomUsers);
    auto RoomDataStore = ppf_Room_GetDataStore(Room);
    auto RoomPolicy = ppf_Room_GetJoinPolicy(Room);
    auto RoomJoinability = ppf_Room_GetJoinability(Room);
    auto RoomType = ppf_Room_GetType(Room);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateSessionFromRoom RoomId: %llu, RoomMaxUsers: %d, RoomCurrentUsersSize: %zu, RoomPolicy: %s, RoomType: %s, RoomJoinability: %s")
        , RoomId, RoomMaxUsers, RoomCurrentUsersSize, *FString(JoinPolicyNames[RoomPolicy]), *FString(RoomTypeNames[RoomType]), *FString(JoinabilityNames[RoomJoinability])));
    for (size_t UserIndex = 0; UserIndex < RoomCurrentUsersSize; ++UserIndex)
    {
        auto User = ppf_UserArray_GetElement(RoomUsers, UserIndex);
        FString RoomOwnerIdString = UTF8_TO_TCHAR(ppf_User_GetID(User));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("CreateSessionFromRoom UserIndex: %zu, UserId: %s"), UserIndex, *RoomOwnerIdString));
    }
    auto SessionSettings = FOnlineSessionSettings();
    SessionSettings.NumPublicConnections = RoomMaxUsers;
    SessionSettings.NumPrivateConnections = 0;
    UpdateSessionSettingsFromDataStore(SessionSettings, RoomDataStore);
    auto Session = new FOnlineSession(SessionSettings);
#if ENGINE_MAJOR_VERSION > 4
    Session->OwningUserId = FUniqueNetIdPico::Create(UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner)));
#elif ENGINE_MINOR_VERSION > 26
    Session->OwningUserId = FUniqueNetIdPico::Create(UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner)));
#elif ENGINE_MINOR_VERSION > 24
    Session->OwningUserId = MakeShareable(new FUniqueNetIdPico(UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner))));
#endif
    // FUniqueNetIdPico::Create(UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner)));
    Session->OwningUserName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(RoomOwner));
    auto RemainingConnections = RoomMaxUsers - RoomCurrentUsersSize;
    Session->NumOpenPublicConnections = (RemainingConnections > 0) ? RemainingConnections : 0;
    Session->NumOpenPrivateConnections = 0;
    Session->SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomId));
    TestDumpSession(Session);
    return MakeShareable(Session);
}

void FOnlineSessionPico::LogRoomData(ppfRoomHandle Room) const
{
    auto RoomId = ppf_Room_GetID(Room);
    auto RoomOwner = ppf_Room_GetOwner(Room);
    auto RoomMaxUsers = ppf_Room_GetMaxUsers(Room);
    auto RoomUsers = ppf_Room_GetUsers(Room);
    auto RoomCurrentUsersSize = ppf_UserArray_GetSize(RoomUsers);
    auto RoomDataStore = ppf_Room_GetDataStore(Room);
    auto RoomPolicy = ppf_Room_GetJoinPolicy(Room);
    auto RoomJoinability = ppf_Room_GetJoinability(Room);
    auto RoomType = ppf_Room_GetType(Room);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("LogRoomData RoomId: %llu, RoomMaxUsers: %d, RoomCurrentUsersSize: %zu, RoomPolicy: %s, RoomType: %s, RoomJoinability: %s")
        , RoomId, RoomMaxUsers, RoomCurrentUsersSize, *FString(JoinPolicyNames[RoomPolicy]), *FString(RoomTypeNames[RoomType]), *FString(JoinabilityNames[RoomJoinability])));
}

void FOnlineSessionPico::UpdateSessionFromRoom(FNamedOnlineSession & Session, ppfRoomHandle Room) const
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateSessionFromRoom %s"), *InitStateErrorMessage));
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom begin")));
    LogRoomData(Room);
    auto UserArray = ppf_Room_GetUsers(Room);
    auto UserArraySize = ppf_UserArray_GetSize(UserArray);
#if ENGINE_MAJOR_VERSION > 4
    TArray< FUniqueNetIdRef > Players;
#elif ENGINE_MINOR_VERSION > 26
    TArray< FUniqueNetIdRef > Players;
#elif ENGINE_MINOR_VERSION > 24
    TArray< TSharedRef<const FUniqueNetId> > Players;
#endif
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom UserArraySize: %zu"), UserArraySize));
    for (size_t UserIndex = 0; UserIndex < UserArraySize; ++UserIndex)
    {
        auto User = ppf_UserArray_GetElement(UserArray, UserIndex);
        FString UserId = UTF8_TO_TCHAR(ppf_User_GetID(User));
#if ENGINE_MAJOR_VERSION > 4
        auto PlayerId = FUniqueNetIdPico::Create(UserId);
#elif ENGINE_MINOR_VERSION > 26
        auto PlayerId = FUniqueNetIdPico::Create(UserId);
#elif ENGINE_MINOR_VERSION > 24
        TSharedRef<const FUniqueNetId>  PlayerId = MakeShareable(new FUniqueNetIdPico(UserId));
#endif
        Players.Add(PlayerId);
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom UserIndex: %zu, UserId: %s, PlayerId: %s, PlayerId->IsValid(): %d"), UserIndex, *UserId, *PlayerId->ToString(), PlayerId->IsValid()));
    }
    Session.RegisteredPlayers = Players;
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom NumPublicConnections: %d"), Session.SessionSettings.NumPublicConnections));
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom ppf_Room_GetMaxUsers: %d"), ppf_Room_GetMaxUsers(Room)));
    Session.SessionSettings.NumPublicConnections = ppf_Room_GetMaxUsers(Room);
    auto RemainingConnections = Session.SessionSettings.NumPublicConnections - UserArraySize;
    Session.NumOpenPublicConnections = (RemainingConnections > 0) ? RemainingConnections : 0;
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom set NumOpenPublicConnections: %d"), Session.NumOpenPublicConnections));
    Session.NumOpenPrivateConnections = 0;
    auto RoomOwner = ppf_Room_GetOwner(Room);
    FString RoomOwnerIdString = UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner));
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom RoomOwnerIdString: %s"), *RoomOwnerIdString));
    //auto RoomOwnerUniqueIdPtr = FUniqueNetIdPico::Create(RoomOwnerIdString);

#if ENGINE_MAJOR_VERSION > 4
    auto RoomOwnerUniqueIdPtr = FUniqueNetIdPico::Create(RoomOwnerIdString);
#elif ENGINE_MINOR_VERSION > 26
    auto RoomOwnerUniqueIdPtr = FUniqueNetIdPico::Create(RoomOwnerIdString);
#elif ENGINE_MINOR_VERSION > 24
    TSharedRef<const FUniqueNetId> RoomOwnerUniqueIdPtr = MakeShareable(new FUniqueNetIdPico(RoomOwnerIdString));
#endif
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom RoomOwnerUniqueId: %s"), *RoomOwnerUniqueIdPtr->ToString()));

    if (!Session.OwningUserId.IsValid() || Session.OwningUserId.ToSharedRef().Get() != *RoomOwnerUniqueIdPtr)
    {
        Session.OwningUserId = RoomOwnerUniqueIdPtr;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom set OwningUserId: %s"), *(Session.OwningUserId->ToString())));
        Session.OwningUserName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(RoomOwner));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom set OwningUserName : %s"), *Session.OwningUserName));
        if (Session.LocalOwnerId.IsValid())
        {
            Session.bHosting = Session.OwningUserId.ToSharedRef().Get() == *Session.LocalOwnerId;
        }
        else
        {
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom Session.LocalOwnerId is invalid")));
            Session.bHosting = false;
        }
    }
    TestDumpNamedSession(&Session);
    auto RoomDataStore = ppf_Room_GetDataStore(Room);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionFromRoom end ppf_Room_GetDataStore")));
    UpdateSessionSettingsFromDataStore(Session.SessionSettings, RoomDataStore);
}

void FOnlineSessionPico::UpdateSessionSettingsFromDataStore(FOnlineSessionSettings & SessionSettings, ppfDataStoreHandle DataStore) const
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore %s"), *InitStateErrorMessage));
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore begin")));
    if (DataStore == nullptr)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore DataStore is nullptr")));
    }
    auto DataStoreSize = ppf_DataStore_GetNumKeys(DataStore);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore DataStoreSize: %zu"), DataStoreSize));
    SessionSettings.Settings.Empty(DataStoreSize);
    for (size_t DataStoreIndex = 0; DataStoreIndex < DataStoreSize; DataStoreIndex++)
    {
        auto SrcKey = ppf_DataStore_GetKey(DataStore, DataStoreIndex);
        auto DataStoreKey = FName(UTF8_TO_TCHAR(SrcKey));
        auto DataStoreValue = ppf_DataStore_GetValue(DataStore, SrcKey);
        FString SetValue = UTF8_TO_TCHAR(DataStoreValue);
        if (DataStoreKey == SETTING_NUMBOTS
            || DataStoreKey == SETTING_BEACONPORT
            || DataStoreKey == SETTING_QOS
            || DataStoreKey == SETTING_NEEDS
            || DataStoreKey == SETTING_NEEDSSORT)
        {
            int32 IntDataStoreValue = FCString::Atoi(UTF8_TO_TCHAR(DataStoreValue));
            SessionSettings.Set(
                DataStoreKey,
                IntDataStoreValue,
                EOnlineDataAdvertisementType::ViaOnlineService
            );
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore Key: %s, Value: %d"), *DataStoreKey.ToString(), IntDataStoreValue));
        }
        else if (DataStoreKey == SETTING_PICO_BUILD_UNIQUE_ID)
        {
            SessionSettings.BuildUniqueId = FCString::Atoi(UTF8_TO_TCHAR(DataStoreValue));
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore set SessionSettings.BuildUniqueId DataStoreValue: %d"), SessionSettings.BuildUniqueId));
        }
        else
        {
            SessionSettings.Set(
                DataStoreKey,
                SetValue,
                EOnlineDataAdvertisementType::ViaOnlineService
            );
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("UpdateSessionSettingsFromDataStore Key: %s, Value: %s"), *DataStoreKey.ToString(), *SetValue));
        }
    }
}

void FOnlineSessionPico::TickPendingInvites(float DeltaTime)
{
    if (PendingInviteAcceptedSessions.Num() > 0 && (OnSessionUserInviteAcceptedDelegates.IsBound() || RoomInviteAcceptedCallback.IsBound()))
    {
        IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
        auto PlayerId = Identity->GetUniquePlayerId(0);
        for (auto PendingInviteAcceptedSession : PendingInviteAcceptedSessions)
        {
            if (RoomInviteAcceptedCallback.IsBound())
            {
                FString RoomId = PendingInviteAcceptedSession.Get().GetSessionIdStr();
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("TickPendingInvites RoomInviteAcceptedCallback RoomId: %s"), *RoomId));
                RoomInviteAcceptedCallback.Broadcast(RoomId, true);
            }
            TriggerOnSessionUserInviteAcceptedDelegates(true, 0, PlayerId, PendingInviteAcceptedSession.Get());
        }
        PendingInviteAcceptedSessions.Empty();
    }
    if (InviteAcceptedRoomID != 0 && IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("TickPendingInvites InviteAcceptedRoomID: %llu"), InviteAcceptedRoomID));
        OnRoomInviteAccepted(InviteAcceptedRoomID);
        InviteAcceptedRoomID = 0;
    }
}

int32 FOnlineSessionPico::GetRoomBuildUniqueId(const ppfRoomHandle Room)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("GetRoomBuildUniqueId %s"), *InitStateErrorMessage));
        return 0;
    }
    auto RoomDataStore = ppf_Room_GetDataStore(Room);
    auto ServerBuildId = ppf_DataStore_GetValue(RoomDataStore, TCHAR_TO_UTF8(*SETTING_PICO_BUILD_UNIQUE_ID.ToString()));
    if (!ServerBuildId)
    {
        return 0;
    }

    return FCString::Atoi(UTF8_TO_TCHAR(ServerBuildId));
}


/////////////////////////////////////////

bool FOnlineSessionPico::Uninitialize()
{
    SetInitState(false);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("Uninitialize")));
    auto Result = ppf_Game_UnInitialize();
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("Uninitialize Result: %d"), Result));
    return Result;
}
void FOnlineSessionPico::Initialize()
{
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("Initialize")));
    SetInitState(false);
    // PicoSubsystem.AddAsyncTask(
    // 	ppf_User_GetAccessToken(),
    // 	FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnGetAccessTokenComplete));
    PicoSubsystem.AddAsyncTask(
        ppf_Game_InitializeAuto(),
        FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnGameInitializeComplete));
}
void FOnlineSessionPico::OnGetAccessTokenComplete(ppfMessageHandle Message, bool bIsError)
{
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnGetAccessTokenComplete")));
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnGetAccessTokenComplete ErrorMessage: %s"), *ErrorMessage));
        //Initialize();
        return;
    }

    auto MessageType = ppf_Message_GetType(Message);
    auto token = ppf_Message_GetString(Message);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnGetAccessTokenComplete token: %s"), *FString(token)));
    PicoSubsystem.AddAsyncTask(
        ppf_Game_InitializeWithToken(token),
        FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnGameInitializeComplete));
}
void FOnlineSessionPico::OnGameInitializeComplete(ppfMessageHandle Message, bool bIsError)
{
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnGameInitializeComplete")));
    if (bIsError)
    {
        const auto Error = ppf_Message_GetError(Message);
        const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        const int ErrorCode = ppf_Error_GetCode(Error);
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnGameInitializeComplete ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *FString(ErrorMessage)));
        GameInitializeCompleteCallback.Broadcast(false, ErrorCode, ErrorMessage, -1);
        return;
    }

    const auto MessageType = ppf_Message_GetType(Message);
    if (MessageType == ppfMessageType::ppfMessageType_PlatformGameInitializeAsynchronous)
    {
        const auto objHandle = ppf_Message_GetPlatformGameInitialize(Message);
        const auto obj = ppf_PlatformGameInitialize_GetResult(objHandle);
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnGameInitializeComplete Result: %d"), obj));
        if (obj == ppfPlatformGameInitialize_Success)
        {
            SetInitState(true);
            GameInitializeCompleteCallback.Broadcast(true, 0, FString(), ppfPlatformGameInitialize_Success);
        }
        else
        {
            GameInitializeCompleteCallback.Broadcast(false, 0, FString(), obj);
        }
    }
}
void FOnlineSessionPico::SetInitState(bool State)
{
    InitSuccess = State;
}
bool FOnlineSessionPico::IsInitSuccess() const
{
    return InitSuccess;
}
void FOnlineSessionPico::OnForcedCancelMatchmaking()
{
    if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
    {
        InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Failed;
        InProgressMatchmakingSearch = nullptr;
        TriggerOnCancelMatchmakingCompleteDelegates(InProgressMatchmakingSearchName, false);
    }
}
void FOnlineSessionPico::OnForcedLeaveRoom(ppfID RoomID)
{
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnForcedLeaveRoom Server leave RoomID: %d"), RoomID));
    for (auto It = Sessions.CreateConstIterator(); It; ++It)
    {
        TSharedPtr<FNamedOnlineSession> Session = It.Value();
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnForcedLeaveRoom GetRoomIDOfSession(Session): %d"), GetRoomIDOfSession(*Session)));
        if (Session.IsValid() && (RoomID == 0 || GetRoomIDOfSession(*Session) == RoomID))
        {
            Session->SessionState = EOnlineSessionState::Destroying;
            // callback
            //CompletionDelegate.ExecuteIfBound(Session.SessionName, true); // todo
            TriggerOnDestroySessionCompleteDelegates(Session->SessionName, true);
        }
        else
        {
            SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnForcedLeaveRoom Invalid session during shutdown!")));
        }
    }
    Sessions.Empty();
}
bool FOnlineSessionPico::OnUpdateRoomData(ppfRoomHandle Room, ppfID RoomId)
{
    SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnUpdateRoomData begin RoomId: %llu"), RoomId));
    for (auto SessionKV : Sessions)
    {
        SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnUpdateRoomData each item begin: SessionKV.Key: %s"), *SessionKV.Key.ToString()));
        if (SessionKV.Value.IsValid())
        {
            auto Session = SessionKV.Value.Get();
            if (Session)
            {
                auto SessionRoomId = GetRoomIDOfSession(*Session);
                SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnUpdateRoomData SessionRoomId: %llu"), SessionRoomId));
                if (RoomId == SessionRoomId)
                {
                    UpdateSessionFromRoom(*Session, Room);
                    return true;
                }
            }
            else
            {
                SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnUpdateRoomData session is null")));
            }
        }
    }
    SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnUpdateRoomData return false")));
    return false;
}
bool FOnlineSessionPico::IsInMatchmakingProgress()
{
    return InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress;
}

// Basic Notifications
void FOnlineSessionPico::OnRoomNotificationUpdate(ppfMessageHandle Message, bool bIsError)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnRoomNotificationUpdate %s"), *InitStateErrorMessage));
        RoomUpdateCallback.Broadcast(FString(), false, -1, FString("IsInitSuccess is false"));
        return;
    }
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        int ErrorCode = ppf_Error_GetCode(Error);
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + FString::FromInt(ErrorCode);
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnRoomNotificationUpdate Error on getting a room notification update")));
        RoomUpdateCallback.Broadcast(FString(), false, ErrorCode, FString(ErrorMessage));
        return;
    }
    auto Room = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(Room);
    bool Update = OnUpdateRoomData(Room, RoomId);
    if (Update)
    {
        SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnRoomNotificationUpdate Update room success")));
        RoomUpdateCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true, 0, FString());
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Log, FString::Printf(TEXT("OnRoomNotificationUpdate Update false Session was gone before the notif update came back")));
        RoomUpdateCallback.Broadcast(FString(), false, -1, FString("cannot find session"));
    }
}
void FOnlineSessionPico::OnRoomInviteAccepted(ppfMessageHandle Message, bool bIsError)
{
    FOnlineSessionSearchResult SearchResult;
    IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
    auto PlayerId = Identity->GetUniquePlayerId(0);
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnRoomInviteAccepted ErrorMessage: %s"), *ErrorMessage));
        if (RoomInviteAcceptedCallback.IsBound())
        {
            RoomInviteAcceptedCallback.Broadcast(ErrorMessage, false);
        }
        TriggerOnSessionUserInviteAcceptedDelegates(false, 0, PlayerId, SearchResult);
        return;
    }

    FString RoomIdString = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
    ppfID RoomId = FCString::Strtoui64(*RoomIdString, NULL, 10);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomInviteAccepted RoomId: %llu"), RoomId));

    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnRoomInviteAccepted %s"), *InitStateErrorMessage));
        InviteAcceptedRoomID = RoomId;
        if (RoomInviteAcceptedCallback.IsBound())
        {
            RoomInviteAcceptedCallback.Broadcast(FString::Printf(TEXT("%s, RoomId: %llu"), *InitStateErrorMessage, RoomId), false);
        }
        TriggerOnSessionUserInviteAcceptedDelegates(false, 0, PlayerId, SearchResult);
        return;
    }
    OnRoomInviteAccepted(RoomId);
}
void FOnlineSessionPico::OnRoomInviteAccepted(ppfID RoomId)
{
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomInviteAccepted RoomId: %llu"), RoomId));
    IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
    if (!Identity.IsValid())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnRoomInviteAccepted pico identity is invalid")));
        return;
    }
    auto PlayerId = Identity->GetUniquePlayerId(0);
    PicoSubsystem.AddAsyncTask(
        ppf_Room_Get(RoomId),
        FPicoMessageOnCompleteDelegate::CreateLambda([this, PlayerId, RoomId](ppfMessageHandle InMessage, bool bInIsError)
            {
                FOnlineSessionSearchResult LocalSearchResult;
                if (bInIsError)
                {
                    SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("Could not get room details")));
                    if (RoomInviteAcceptedCallback.IsBound())
                    {
                        RoomInviteAcceptedCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), false);
                    }
                    TriggerOnSessionUserInviteAcceptedDelegates(false, 0, PlayerId, LocalSearchResult);
                    return;
                }
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomInviteAccepted no error")));

                auto Room = ppf_Message_GetRoom(InMessage);
                auto Session = CreateSessionFromRoom(Room);

                // check if there's a delegate bound, if not save this session for later.
                if (!OnSessionUserInviteAcceptedDelegates.IsBound() && !RoomInviteAcceptedCallback.IsBound())
                {
                    // No delegates are bound, just save this for later
                    TSharedRef<FOnlineSessionSearchResult> SearchResultPtr = MakeShareable(new FOnlineSessionSearchResult());
                    SearchResultPtr->Session = Session.Get();
                    PendingInviteAcceptedSessions.Add(SearchResultPtr);
                    return;
                }

                LocalSearchResult.Session = Session.Get();
                if (RoomInviteAcceptedCallback.IsBound())
                {
                    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomInviteAccepted RoomInviteAcceptedCallback Broadcast RoomId: %llu"), RoomId));
                    RoomInviteAcceptedCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
                }
                TriggerOnSessionUserInviteAcceptedDelegates(true, 0, PlayerId, LocalSearchResult);
            }));
}
void FOnlineSessionPico::OnMatchmakingNotificationMatchFound(ppfMessageHandle Message, bool bIsError)
{
    if (!IsInitSuccess())
    {
        SaveLog(ELogVerbosity::Type::Error, FString::Printf(TEXT("OnMatchmakingNotificationMatchFound %s"), *InitStateErrorMessage));
        MatchmakingFoundCallback.Broadcast(FString(), false, -1, FString("IsInitSuccess is false"));
        return;
    }
    // if (!InProgressMatchmakingSearch.IsValid())
    // {
    //     SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnMatchmakingNotificationMatchFound No matchmaking searches in progress")));
    //     MatchmakingFoundCallback.Broadcast(FString(), false, -1, FString("InProgressMatchmakingSearch is invalid"));
    //     return;
    // }

    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        int ErrorCode = ppf_Error_GetCode(Error);
        
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnMatchmakingNotificationMatchFound error")));
        InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Failed;
        InProgressMatchmakingSearch = nullptr;
        TriggerOnMatchmakingCompleteDelegates(InProgressMatchmakingSearchName, false);
        MatchmakingFoundCallback.Broadcast(FString(), false, ErrorCode, ErrorMessage);
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnMatchmakingNotificationMatchFound no error")));
    auto Room = ppf_Message_GetRoom(Message);
    ppfID RoomID = ppf_Room_GetID(Room);
    FString RoomStrID = FString::Printf(TEXT("%llu"), RoomID);
    if (InProgressMatchmakingSearch.IsValid())
    {
        FOnlineSessionSearchResult SearchResult;
        auto Session = CreateSessionFromRoom(Room);
        SearchResult.Session = Session.Get();
        InProgressMatchmakingSearch->SearchResults.Add(SearchResult);
        InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Done;
        InProgressMatchmakingSearch = nullptr;
    }
    
    TriggerOnMatchmakingCompleteDelegates(InProgressMatchmakingSearchName, true);
    MatchmakingFoundCallback.Broadcast(RoomStrID, true, 0, FString());
}


// Notifications
void FOnlineSessionPico::OnNetNotificationConnection(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationConnection error ErrorMessage: %s"), *FString(ErrorMessage)));
        GameConnectionCallback.Broadcast(-1, false);
        return;
    }
    const auto ConnectionResult = ppf_Message_GetGameConnectionEvent(Message);
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationConnection ConnectionResult: %s"), *FString(ConnectionResultNames[ConnectionResult])));
    if (ConnectionResult == ppfPlatformGameConnectionEvent_Resumed)
    {
        SetInitState(true);
        GameConnectionCallback.Broadcast((int)ConnectionResult, true);
        return;
    }
    if (!IsInitSuccess())
    {
        return;
    }
    if (ConnectionResult == ppfPlatformGameConnectionEvent_Lost)
    {
        SetInitState(false);
        GameConnectionCallback.Broadcast((int)ConnectionResult, false);
    }
    else if (ConnectionResult == ppfPlatformGameConnectionEvent_KickedByRelogin
        || ConnectionResult == ppfPlatformGameConnectionEvent_KickedByGameServer)
    {
        if (GameConnectionCallback.IsBound())
        {
            SetInitState(false);
            GameConnectionCallback.Broadcast((int)ConnectionResult, false);
        }
        else
        {
            SetInitState(false);
            if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
            { // in matchmaking
                OnForcedCancelMatchmaking();
            }
            else
            { // in room
                OnForcedLeaveRoom(0);
            }
            Uninitialize();
            EAppReturnType::Type ReturnType = FMessageDialog::Open(EAppMsgType::OkCancel, FText::FromString(TEXT("You are kicked off the game. Click OK to reinitialize. Or you can set the GameConnectionCallback to customize the handling of this message. ")));
            if (ReturnType == EAppReturnType::Type::Ok)
            {
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationConnection click ok button.")));
                Initialize();
            }
            else
            {
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationConnection click cancel button.")));
            }
        }
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationConnection others")));
        SetInitState(false);
        if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
        { // in matchmaking
            OnForcedCancelMatchmaking();
        }
        else
        { // in room
            OnForcedLeaveRoom(0);
        }
        GameConnectionCallback.Broadcast((int)ConnectionResult, false);
    }
}
void FOnlineSessionPico::OnNetNotificationRequestFailed(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationRequestFailed error ErrorMessage: %s"), *FString(ErrorMessage)));
        GameRequestFailedCallback.Broadcast(-1, false);
        return;
    }
    else
    {
        auto FailedReason = ppf_Message_GetGameRequestFailedReason(Message);
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationRequestFailed FailedReason: %d"), FailedReason));
        GameRequestFailedCallback.Broadcast((int)FailedReason, true);
    }
}
void FOnlineSessionPico::OnNetNotificationGameStateReset(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationGameStateReset error ErrorMessage: %s"), *FString(ErrorMessage)));
        GameStateResetCallback.Broadcast(false);
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnNetNotificationGameStateReset no error")));
    if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
    { // in matchmaking
        OnForcedCancelMatchmaking();
    }
    else
    { // in room
        OnForcedLeaveRoom(0);
    }
    GameStateResetCallback.Broadcast(true);
}
void FOnlineSessionPico::OnMatchmakingNotificationCancel2(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnMatchmakingNotificationCancel2 error ErrorMessage: %s"), *FString(ErrorMessage)));
        MatchmakingCancel2Callback.Broadcast(false);
        return;
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnMatchmakingNotificationCancel2 no error")));
        if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
        { // in matchmaking
            OnForcedCancelMatchmaking();
        }
        MatchmakingCancel2Callback.Broadcast(true);
    }
}
void FOnlineSessionPico::OnRoomNotificationLeave(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationLeave error ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomLeaveCallback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationLeave no error.")));
    auto RoomHandle = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(RoomHandle);
    LogRoomData(RoomHandle);
    OnForcedLeaveRoom(RoomId);
    RoomLeaveCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
}
void FOnlineSessionPico::OnRoomNotificationJoin2(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationJoin2 error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomJoin2Callback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    auto Room = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(Room);
    bool Update = OnUpdateRoomData(Room, RoomId);
    if (Update)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationJoin2 Update room success")));
        RoomJoin2Callback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnRoomNotificationJoin2 Session was gone before the notif update came back")));
        RoomJoin2Callback.Broadcast(FString("cannot find session"), false);
    }
}
void FOnlineSessionPico::OnRoomNotificationSetDescription(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationSetDescription error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomSetDescriptionCallback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    auto Room = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(Room);
    bool Update = OnUpdateRoomData(Room, RoomId);
    if (Update)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationSetDescription Update room success")));
        RoomSetDescriptionCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnRoomNotificationSetDescription Session was gone before the notif update came back")));
        RoomSetDescriptionCallback.Broadcast(FString("cannot find session"), false);
    }
}
void FOnlineSessionPico::OnRoomNotificationKickUser(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationKickUser error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomKickUserCallback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    // todo check
    SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationKickUser no error.")));
    auto RoomHandle = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(RoomHandle);
    LogRoomData(RoomHandle);
    OnForcedLeaveRoom(RoomId);
    RoomKickUserCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
}
void FOnlineSessionPico::OnRoomNotificationUpdateOwner(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateOwner error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomUpdateOwnerCallback.Broadcast(false);
    }
    else
    {
        // todo
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateOwner no error")));
        RoomUpdateOwnerCallback.Broadcast(true);
    }
}
void FOnlineSessionPico::OnRoomNotificationUpdateDataStore(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateDataStore error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomUpdateDataStoreCallback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    auto Room = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(Room);
    bool Update = OnUpdateRoomData(Room, RoomId);
    if (Update)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateDataStore Update room success")));
        RoomUpdateDataStoreCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnRoomNotificationUpdateDataStore Session was gone before the notif update came back")));
        RoomUpdateDataStoreCallback.Broadcast(FString("cannot find session"), false);
    }
}
void FOnlineSessionPico::OnRoomNotificationUpdateMembershipLockStatus(ppfMessageHandle Message, bool bIsError)
{
    if (bIsError)
    {
        auto Error = ppf_Message_GetError(Message);
        FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
        FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
        ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateMembershipLockStatus error. ErrorMessage: %s"), *FString(ErrorMessage)));
        RoomUpdateMembershipLockStatusCallback.Broadcast(FString(ErrorMessage), false);
        return;
    }
    auto Room = ppf_Message_GetRoom(Message);
    auto RoomId = ppf_Room_GetID(Room);
    bool Update = OnUpdateRoomData(Room, RoomId);
    if (Update)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("OnRoomNotificationUpdateMembershipLockStatus Update room success")));
        RoomUpdateMembershipLockStatusCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("OnRoomNotificationUpdateMembershipLockStatus Session was gone before the notif update came back")));
        RoomUpdateMembershipLockStatusCallback.Broadcast(FString("cannot find session"), false);
    }
}
// Log
void FOnlineSessionPico::TestDumpNamedSession(const FNamedOnlineSession * NamedSession) const
{
    if (NamedSession != NULL)
    {
        //LOG_SCOPE_VERBOSITY_OVERRIDE(LogOnlineSession, ELogVerbosity::VeryVerbose);
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("dumping NamedSession: ")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	SessionName: %s"), *NamedSession->SessionName.ToString()));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	HostingPlayerNum: %d"), NamedSession->HostingPlayerNum));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	SessionState: %s"), EOnlineSessionState::ToString(NamedSession->SessionState)));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	RegisteredPlayers: ")));
        if (NamedSession->RegisteredPlayers.Num())
        {
            for (int32 UserIdx = 0; UserIdx < NamedSession->RegisteredPlayers.Num(); UserIdx++)
            {
                SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	    %d: %s"), UserIdx, *NamedSession->RegisteredPlayers[UserIdx]->ToString()));
            }
        }
        else
        {
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	    0 registered players")));
        }

        TestDumpSession(NamedSession);
    }
}
void FOnlineSessionPico::TestDumpSession(const FOnlineSession * Session) const
{
    if (Session != NULL)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("dumping Session: ")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	OwningPlayerName: %s"), *Session->OwningUserName));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	OwningPlayerId: %s"), Session->OwningUserId.IsValid() ? *Session->OwningUserId->ToString() : TEXT("")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	NumOpenPrivateConnections: %d"), Session->NumOpenPrivateConnections));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	NumOpenPublicConnections: %d"), Session->NumOpenPublicConnections));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("	SessionInfo: %s"), Session->SessionInfo.IsValid() ? *Session->SessionInfo->ToDebugString() : TEXT("NULL")));
        TestDumpSessionSettings(&Session->SessionSettings);
    }
    else
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("dumping Session is null")));
    }
}
void FOnlineSessionPico::TestDumpSessionSettings(const FOnlineSessionSettings * SessionSettings) const
{
    if (SessionSettings != NULL)
    {
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("dumping SessionSettings: ")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tNumPublicConnections: %d"), SessionSettings->NumPublicConnections));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tNumPrivateConnections: %d"), SessionSettings->NumPrivateConnections));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbIsLanMatch: %s"), SessionSettings->bIsLANMatch ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbIsDedicated: %s"), SessionSettings->bIsDedicated ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbUsesStats: %s"), SessionSettings->bUsesStats ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbShouldAdvertise: %s"), SessionSettings->bShouldAdvertise ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbAllowJoinInProgress: %s"), SessionSettings->bAllowJoinInProgress ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbAllowInvites: %s"), SessionSettings->bAllowInvites ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbUsesPresence: %s"), SessionSettings->bUsesPresence ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbAllowJoinViaPresence: %s"), SessionSettings->bAllowJoinViaPresence ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tbAllowJoinViaPresenceFriendsOnly: %s"), SessionSettings->bAllowJoinViaPresenceFriendsOnly ? TEXT("true") : TEXT("false")));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tBuildUniqueId: 0x%08x"), SessionSettings->BuildUniqueId));
        SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\tSettings:")));
        for (FSessionSettings::TConstIterator It(SessionSettings->Settings); It; ++It)
        {
            FName Key = It.Key();
            const FOnlineSessionSetting& Setting = It.Value();
            SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("\t\t%s=%s"), *Key.ToString(), *Setting.ToString()));
        }
    }
}
void FOnlineSessionPico::SaveLog(const ELogVerbosity::Type Verbosity, const FString & Log)
{
    switch (Verbosity)
    {
    case ELogVerbosity::Type::Error:
        UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME %s"), *Log);
        break;
    case ELogVerbosity::Type::Warning:
        UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME %s"), *Log);
        break;
    default:
        UE_LOG_ONLINE_SESSION(Log, TEXT("PPF_GAME %s"), *Log);
        break;
    }

    FDateTime Time = FDateTime::Now();
    int year = Time.GetYear();
    int month = Time.GetMonth();
    int day = Time.GetDay();
    int hour = Time.GetHour();
    int minute = Time.GetMinute();
    int second = Time.GetSecond();
    
    // FString WriteLog = FString::Printf(TEXT("[%d.%d.%d %d:%d:%d]%s\n"), year, month, day, hour, minute, second, *Log);
    // FString TextPath = FPaths::ProjectPersistentDownloadDir() + TEXT("Log-OnlineSessionInterfacePico.txt");
    // FFileHelper::SaveStringToFile(*WriteLog, *TextPath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}



