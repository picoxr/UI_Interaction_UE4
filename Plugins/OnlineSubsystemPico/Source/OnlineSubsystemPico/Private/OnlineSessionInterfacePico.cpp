// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#include "OnlineSessionInterfacePico.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineFriendsInterfacePico.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystemPicoTypes.h"
#include "Misc/MessageDialog.h"

FOnlineSessionInfoPico::FOnlineSessionInfoPico(ppfID RoomId) :
	SessionId(FUniqueNetIdPico::Create(RoomId))
{
}

/**
* FOnlineSessionPico
*/

FOnlineSessionPico::FOnlineSessionPico(FOnlineSubsystemPico& InSubsystem) :
	PicoSubsystem(InSubsystem)
{
	OnRoomNotificationUpdateHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Room_RoomUpdate)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdate);

	OnRoomNotificationInviteAcceptedHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Room_InviteAccepted)
		.AddRaw(this, &FOnlineSessionPico::OnRoomInviteAccepted);

	OnMatchmakingNotificationMatchFoundHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Matchmaking_MatchFound)
		.AddRaw(this, &FOnlineSessionPico::OnMatchmakingNotificationMatchFound);


	OnNetNotificationConnectionHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Game_ConnectionEvent)
		.AddRaw(this, &FOnlineSessionPico::OnNetNotificationConnection);

	OnNetNotificationRequestFailedHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Game_RequestFailed)
		.AddRaw(this, &FOnlineSessionPico::OnNetNotificationRequestFailed);

	OnNetNotificationGameStateResetHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Notification_Game_StateReset)
		.AddRaw(this, &FOnlineSessionPico::OnNetNotificationGameStateReset);

	OnMatchmakingNotificationCancel2Handle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Matchmaking_Cancel2)
		.AddRaw(this, &FOnlineSessionPico::OnMatchmakingNotificationCancel2);

	OnRoomNotificationLeaveHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_Leave)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationLeave);

	OnRoomNotificationJoin2Handle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_Join2)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationJoin2);

	OnRoomNotificationSetDescriptionHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_SetDescription)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationSetDescription);

	OnRoomNotificationKickUserHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_KickUser)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationKickUser);

	OnRoomNotificationUpdateOwnerHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_UpdateOwner)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateOwner);

	OnRoomNotificationUpdateDataStoreHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_UpdateDataStore)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateDataStore);

	OnRoomNotificationUpdateMembershipLockStatusHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessage_Room_UpdateMembershipLockStatus)
		.AddRaw(this, &FOnlineSessionPico::OnRoomNotificationUpdateMembershipLockStatus);
}

FOnlineSessionPico::~FOnlineSessionPico()
{
#if PLATFORM_ANDROID
	if (OnRoomNotificationUpdateHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Room_RoomUpdate, OnRoomNotificationUpdateHandle);
		OnRoomNotificationUpdateHandle.Reset();
	}

	if (OnRoomNotificationInviteAcceptedHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Room_InviteAccepted, OnRoomNotificationInviteAcceptedHandle);
		OnRoomNotificationInviteAcceptedHandle.Reset();
	}

	if (OnMatchmakingNotificationMatchFoundHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Matchmaking_MatchFound, OnMatchmakingNotificationMatchFoundHandle);
		OnMatchmakingNotificationMatchFoundHandle.Reset();
	}
	
	if (OnNetNotificationConnectionHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Game_ConnectionEvent, OnNetNotificationConnectionHandle);
		OnNetNotificationConnectionHandle.Reset();
	}
	
	if (OnNetNotificationRequestFailedHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Game_RequestFailed, OnNetNotificationRequestFailedHandle);
		OnNetNotificationRequestFailedHandle.Reset();
	}
	
	if (OnNetNotificationGameStateResetHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Notification_Game_StateReset, OnNetNotificationGameStateResetHandle);
		OnNetNotificationGameStateResetHandle.Reset();
	}
	
	if (OnMatchmakingNotificationCancel2Handle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Matchmaking_Cancel2, OnMatchmakingNotificationCancel2Handle);
		OnMatchmakingNotificationCancel2Handle.Reset();
	}

	if (OnRoomNotificationLeaveHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_Leave, OnRoomNotificationLeaveHandle);
		OnRoomNotificationLeaveHandle.Reset();
	}

	if (OnRoomNotificationJoin2Handle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_Join2, OnRoomNotificationJoin2Handle);
		OnRoomNotificationJoin2Handle.Reset();
	}

	if (OnRoomNotificationSetDescriptionHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_SetDescription, OnRoomNotificationSetDescriptionHandle);
		OnRoomNotificationSetDescriptionHandle.Reset();
	}

	if (OnRoomNotificationKickUserHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_KickUser, OnRoomNotificationKickUserHandle);
		OnRoomNotificationKickUserHandle.Reset();
	}

	if (OnRoomNotificationUpdateOwnerHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_UpdateOwner, OnRoomNotificationUpdateOwnerHandle);
		OnRoomNotificationUpdateOwnerHandle.Reset();
	}

	if (OnRoomNotificationUpdateDataStoreHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_UpdateDataStore, OnRoomNotificationUpdateDataStoreHandle);
		OnRoomNotificationUpdateDataStoreHandle.Reset();
	}

	if (OnRoomNotificationUpdateMembershipLockStatusHandle.IsValid())
	{
		PicoSubsystem.RemoveNotifyDelegate(ppfMessage_Room_UpdateMembershipLockStatus, OnRoomNotificationUpdateMembershipLockStatusHandle);
		OnRoomNotificationUpdateMembershipLockStatusHandle.Reset();
	}
#endif
	
	InviteAcceptedSessions.Empty();

	for (auto It = Sessions.CreateConstIterator(); It; ++It)
	{
		TSharedPtr<FNamedOnlineSession> Session = It.Value();
		if (Session.IsValid())
		{
			ppfID RoomId = GetRoomIDOfSession(*Session);
			if (RoomId != 0)
			{
#if PLATFORM_ANDROID
				ppf_Room_Leave(RoomId);
#endif
			}

			if (!Session.IsUnique())
			{
				UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME ~FOnlineSessionPico Session (room %llu) is not unique"), RoomId);
			}
			Session->SessionState = EOnlineSessionState::Destroying;
		}
		else
		{
			UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME ~FOnlineSessionPico session is invalid!"));
		}
	}
	Sessions.Empty();
};
// todo
ppfID FOnlineSessionPico::GetRoomIDOfSession(const FNamedOnlineSession& Session) const
{
	if (!Session.SessionInfo.IsValid() || !Session.SessionInfo.Get()->IsValid())
	{
		return 0;// FString("");
	}
	const FUniqueNetIdPico& PicoId = FUniqueNetIdPico::Cast(Session.SessionInfo->GetSessionId());
	return PicoId.GetID();// PicoId.GetStringID();
}

bool FOnlineSessionPico::CreateSession(int32 HostingPlayerNum, FName SessionName, const FOnlineSessionSettings& NewSessionSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME CreateSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME CreateSession Cannot create session '%s': session already exists."), *SessionName.ToString());
		return false;
	}
	IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
	if (!Identity.IsValid())
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME CreateSession pico identity is invalid"));
		return false;
	}
	if (NewSessionSettings.NumPrivateConnections > 0)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME CreateSession Pico NumPrivateConnections need be zero"));
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
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateSession LocalOwnerId: %s, SessionSettings.BuildUniqueId: %d"),
		Session->LocalOwnerId != nullptr ? *(Session->LocalOwnerId->ToString()) : TEXT("nullptr"), Session->SessionSettings.BuildUniqueId);
	
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
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateSession JoinPolicy: %d"), JoinPolicy);
	// create private room
	return CreateRoomSession(*Session, JoinPolicy);
#else
	return false;
#endif
}

bool FOnlineSessionPico::CreateMatchmakingSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME CreateMatchmakingSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
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
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateMatchmakingSession set matchmakingoptions datastore: key: %s, value: %s"), *item.Key.ToString(), *item.Value.Data.ToString());
		ppf_MatchmakingOptions_SetCreateRoomDataStoreString(MatchmakingOptions,
			TCHAR_TO_UTF8(*item.Key.ToString()),
			TCHAR_TO_UTF8(*item.Value.Data.ToString())
		);
	};
	auto BuildUniqueIdString = FString::FromInt(Session.SessionSettings.BuildUniqueId);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateMatchmakingSession set matchmakingoptions datastore SessionSettings.BuildUniqueId: %s"), *BuildUniqueIdString);
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
#else
	return false;
#endif 
}

bool FOnlineSessionPico::CreateRoomSession(FNamedOnlineSession& Session, ppfRoomJoinPolicy JoinPolicy)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME CreateRoomSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
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
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateRoomSession set roomoptions datastore SessionSettings.BuildUniqueId: %s"), *BuildUniqueIdString);
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
#else
	return false;
#endif
}

void FOnlineSessionPico::OnCreateRoomComplete(ppfMessageHandle Message, bool bIsError, FName SessionName)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnCreateRoomComplete %s"), *InitStateErrorMessage);
		return;
	}
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnCreateRoomComplete ErrorMessage: %s"), *FString(ErrorMessage));
		RemoveNamedSession(SessionName);
		TriggerOnCreateSessionCompleteDelegates(SessionName, false);
		return;
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnCreateRoomComplete SessionName: %s"), *SessionName.ToString());
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnCreateRoomComplete cannot find session: %s"), *SessionName.ToString());
		TriggerOnCreateSessionCompleteDelegates(SessionName, false);
		return;
	}
	if (Session->SessionState != EOnlineSessionState::Creating)
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnCreateRoomComplete Session %s existed!"), *SessionName.ToString());
		TriggerOnCreateSessionCompleteDelegates(SessionName, false);
		return;
	}

	ppfRoomHandle Room;
	ppfID RoomId;
	auto MessageType = ppf_Message_GetType(Message);
	if (MessageType == ppfMessageType::ppfMessage_Matchmaking_CreateAndEnqueueRoom2)
	{
		auto EnqueueResultAndRoom = ppf_Message_GetMatchmakingEnqueueResultAndRoom(Message);
		Room = ppf_MatchmakingEnqueueResultAndRoom_GetRoom(EnqueueResultAndRoom);
	}
	else
	{
		Room = ppf_Message_GetRoom(Message);
	}
	RoomId = ppf_Room_GetID(Room);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnCreateRoomComplete RoomId: %llu"), RoomId);
	Session->SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomId));
	UpdateSessionFromRoom(*Session, Room);
	Session->SessionState = EOnlineSessionState::Pending;
	TriggerOnCreateSessionCompleteDelegates(SessionName, true);
#endif
}

bool FOnlineSessionPico::CreateSession(const FUniqueNetId& HostingPlayerId, FName SessionName, const FOnlineSessionSettings& NewSessionSettings)
{
	return CreateSession(0, SessionName, NewSessionSettings);
}

bool FOnlineSessionPico::StartSession(FName SessionName)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME StartSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartSession cannot find session: %s"), *SessionName.ToString());
		return false;
	}
	if (Session->SessionState != EOnlineSessionState::Pending && Session->SessionState != EOnlineSessionState::Ended)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartSession Session: %s State is %s, cannot start!"),
			*SessionName.ToString(),
			EOnlineSessionState::ToString(Session->SessionState));
		TriggerOnStartSessionCompleteDelegates(SessionName, false);
		return false;
	}
	Session->SessionState = EOnlineSessionState::InProgress;
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME StartSession set current SessionState: InProgress"));
	TriggerOnStartSessionCompleteDelegates(SessionName, true);
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::UpdateSession(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings, bool bShouldRefreshOnlineData)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME UpdateSession cannot find session: %s"), *SessionName.ToString());
		return false;
	}
	auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSession LoggedInPlayerId: %s, Session->OwningUserId: %s"),
		LoggedInPlayerId.IsValid()? *(LoggedInPlayerId->ToString()) : TEXT("invalid"), *(Session->OwningUserId->ToString()));
	if (!LoggedInPlayerId.IsValid() || Session->OwningUserId.ToSharedRef().Get() != *LoggedInPlayerId)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME UpdateSession You are not the owner of the session: %s. Current Owner: %s"),
			*SessionName.ToString(), *Session->OwningUserName);
		return false;
	}
	if (Session->SessionSettings.Settings.Contains(SETTING_PICO_POOL))
	{
		Session->SessionSettings.bShouldAdvertise = UpdatedSessionSettings.bShouldAdvertise;
	}
	return UpdateRoomDataStore(SessionName, UpdatedSessionSettings);
#else
	return false;
#endif
}

bool FOnlineSessionPico::UpdateRoomDataStore(FName SessionName, FOnlineSessionSettings& UpdatedSessionSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateRoomDataStore %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME UpdateRoomDataStore cannot find session: %s"), *SessionName.ToString());
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
						auto ErrorMessage = ppf_Error_GetMessage(Error);
						UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateRoomDataStore ErrorMessage: %s"), *FString(ErrorMessage));
						TriggerOnUpdateSessionCompleteDelegates(SessionName, false);
						return;
					}

					UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateRoomDataStore no error"));
					auto NewSession = GetNamedSession(SessionName);
					if (NewSession == nullptr)
					{
						UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateRoomDataStore Session: %s does not exist"), *SessionName.ToString());
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
#else
	return false;
#endif
}

bool FOnlineSessionPico::EndSession(FName SessionName)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME EndSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME EndSession cannot find session: %s"), *SessionName.ToString());
		return false;
	}
	if (Session->SessionState != EOnlineSessionState::InProgress)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME EndSession Session: %s, SessionState: %s"),
			*SessionName.ToString(),
			EOnlineSessionState::ToString(Session->SessionState));
		TriggerOnEndSessionCompleteDelegates(SessionName, false);
		return false;
	}
	Session->SessionState = EOnlineSessionState::Ended;
	TriggerOnEndSessionCompleteDelegates(SessionName, true);
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::DestroySession(FName SessionName, const FOnDestroySessionCompleteDelegate& CompletionDelegate)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME DestroySession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME DestroySession cannot find session: %s"), *SessionName.ToString());
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
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME DestroySession error! ErrorMessage: %s"), *FString(ErrorMessage));
					CompletionDelegate.ExecuteIfBound(SessionName, false);
					TriggerOnDestroySessionCompleteDelegates(SessionName, false);
					return;
				}

				UE_LOG_ONLINE(Display, TEXT("PPF_GAME DestroySession no error"));
				RemoveNamedSession(SessionName);
				CompletionDelegate.ExecuteIfBound(SessionName, true);
				TriggerOnDestroySessionCompleteDelegates(SessionName, true);
			}));
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::IsPlayerInSession(FName SessionName, const FUniqueNetId& UniqueId)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME IsPlayerInSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto Session = GetNamedSession(SessionName);
	if (Session == nullptr)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME IsPlayerInSession cannot find session: %s"), *SessionName.ToString());
		return false;
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME IsPlayerInSession UniqueId.ToString(): %s"), *UniqueId.ToString());
	for (auto Player : Session->RegisteredPlayers)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME IsPlayerInSession Player->ToString(): %s"), *Player->ToString());
		if (*Player == UniqueId)
		{
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME IsPlayerInSession: true"));
			return true;
		}
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME IsPlayerInSession: false"));
	return false;
#else
	return false;
#endif
}

bool FOnlineSessionPico::StartMatchmaking(const TArray< FUniqueNetIdRef >& LocalPlayers, FName SessionName, const FOnlineSessionSettings& NewSessionSettings, TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME StartMatchmaking %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	if (LocalPlayers.Num() > 1)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartMatchmaking LocalPlayers.Num() > 1 cannot start matchmaking"));
		return false;
	}
	FString Pool;
	if (!SearchSettings->QuerySettings.Get(SETTING_PICO_POOL, Pool))
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartMatchmaking Please set SETTING_PICO_POOL: %s"), *SETTING_PICO_POOL.ToString());
		if (!SearchSettings->QuerySettings.Get(SETTING_MAPNAME, Pool))
		{
			return false;
		}
	}
	if (NewSessionSettings.NumPrivateConnections > 0)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartMatchmaking Pico does not support NumPrivateConnections > 0"));
		return false;
	}
	// todo
	if (IsInMatchmakingProgress())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME StartMatchmaking You are already in matchmaking progress"));
		return false;
	}
	if (InProgressMatchmakingSearch.IsValid())
	{
		InProgressMatchmakingSearch.Reset();
	}
	SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
	InProgressMatchmakingSearch = SearchSettings;
	InProgressMatchmakingSearchName = SessionName;
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME StartMatchmaking PoolName: %s"), *Pool);
	PicoSubsystem.AddAsyncTask(
		ppf_Matchmaking_Enqueue2(TCHAR_TO_UTF8(*Pool), nullptr),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName, SearchSettings](ppfMessageHandle Message, bool bIsError)
			{
				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME StartMatchmaking OnComplete ErrorMessage: %s"), *FString(ErrorMessage));
					SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
					if (InProgressMatchmakingSearch.IsValid())
					{
						InProgressMatchmakingSearch.Reset();
					}
					TriggerOnMatchmakingCompleteDelegates(SessionName, false);
				}
				else
				{
					UE_LOG_ONLINE(Display, TEXT("PPF_GAME StartMatchmaking OnComplete no error"));
				}
			}));
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::CancelMatchmaking(int32 SearchingPlayerNum, FName SessionName)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME CancelMatchmaking %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	PicoSubsystem.AddAsyncTask(
		ppf_Matchmaking_Cancel2(),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName](ppfMessageHandle Message, bool bIsError)
			{
				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME CancelMatchmaking OnComplete ErrorMessage: %s"), *FString(ErrorMessage));
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
#else
	return false;
#endif
}

bool FOnlineSessionPico::CancelMatchmaking(const FUniqueNetId& SearchingPlayerId, FName SessionName)
{
	return CancelMatchmaking(0, SessionName);
}

bool FOnlineSessionPico::FindSessions(int32 SearchingPlayerNum, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindSessions %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	if (SearchSettings->MaxSearchResults <= 0)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindSessions MaxSearchResults <= 0"));
		SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
		TriggerOnFindSessionsCompleteDelegates(false);
		return false;
	}
	bool bFindOnlyModeratedRooms = false;
	auto GetValueResult = SearchSettings->QuerySettings.Get(SEARCH_PICO_MODERATED_ROOMS_ONLY, bFindOnlyModeratedRooms);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessions GetValueResult: %d, bFindOnlyModeratedRooms: %d"), GetValueResult, bFindOnlyModeratedRooms);
	if (GetValueResult && bFindOnlyModeratedRooms)
	{
		return FindModeratedRoomSessions(SearchSettings);
	}
	FString Pool;
	if (SearchSettings->QuerySettings.Get(SETTING_PICO_POOL, Pool))
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessions FindMatchmakingSessions Pool: %s"), *Pool);
		return FindMatchmakingSessions(Pool, SearchSettings);
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessions Nothing to find"));
	SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
	TriggerOnFindSessionsCompleteDelegates(false);
	return false;
#else
	return false;
#endif
}

bool FOnlineSessionPico::FindSessions(const FUniqueNetId& SearchingPlayerId, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
	return FindSessions(0, SearchSettings);
}

bool FOnlineSessionPico::FindModeratedRoomSessions(const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindModeratedRoomSessions %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FString PageIndex;
	if (!SearchSettings->QuerySettings.Get(GET_MODERATEDROOMS_PAGEINDEX, PageIndex))
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindModeratedRoomSessions Error: Cannot get GET_MODERATEDROOMS_PAGEINDEX"));
		return false;
	}
	FString PageSize;
	if (!SearchSettings->QuerySettings.Get(GET_MODERATEDROOMS_PAGESIZE, PageSize))
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindModeratedRoomSessions Error: Cannot get GET_MODERATEDROOMS_PAGESIZE"));
		return false;
	}

	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindModeratedRoomSessions PageIndex: %s, PageSize: %s"), *PageIndex, *PageSize);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindModeratedRoomSessions PageIndex: %d, PageSize: %d"), FCString::Atoi(*PageIndex), FCString::Atoi(*PageSize));
	SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
	PicoSubsystem.AddAsyncTask(
		ppf_Room_GetModeratedRooms(FCString::Atoi(*PageIndex), FCString::Atoi(*PageSize)),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, SearchSettings](ppfMessageHandle Message, bool bIsError)
			{
				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindModeratedRoomSessions OnComplete ErrorMessage: %s"), *FString(ErrorMessage));
					SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
					TriggerOnFindSessionsCompleteDelegates(false);
					return;
				}
				auto RoomArray = ppf_Message_GetRoomArray(Message);
				auto SearchResultsSize = ppf_RoomArray_GetSize(RoomArray);
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindModeratedRoomSessions SearchResultsSize: %zu"), SearchResultsSize);
				if (SearchResultsSize > SearchSettings->MaxSearchResults)
				{
					SearchResultsSize = SearchSettings->MaxSearchResults;
				}
				SearchSettings->SearchResults.Reset(SearchResultsSize);
				int32 BuildUniqueId = GetBuildUniqueId();
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindModeratedRoomSessions GetBuildUniqueId(): %d"), BuildUniqueId);
				for (size_t i = 0; i < SearchResultsSize; i++)
				{
					auto Room = ppf_RoomArray_GetElement(RoomArray, i);
					int32 ServerBuildId = GetRoomBuildUniqueId(Room);
					UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindModeratedRoomSessions ServerBuildId: %d"), ServerBuildId);
					if (ServerBuildId != 0 && ServerBuildId != BuildUniqueId)
					{
						UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindModeratedRoomSessions ServerBuildId != 0 && ServerBuildId != BuildUniqueId"));
						continue;
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
#else
	return false;
#endif
}

bool FOnlineSessionPico::FindMatchmakingSessions(const FString Pool, const TSharedRef<FOnlineSessionSearch>& SearchSettings)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindMatchmakingSessions %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	if (InProgressMatchmakingSearch.IsValid())
	{
		InProgressMatchmakingSearch.Reset();
	}
	SearchSettings->SearchState = EOnlineAsyncTaskState::InProgress;
	InProgressMatchmakingSearch = SearchSettings;
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindMatchmakingSessions begin ppf_Matchmaking_Browse2 Pool: %s"), *Pool);
	PicoSubsystem.AddAsyncTask(
		ppf_Matchmaking_Browse2(TCHAR_TO_UTF8(*Pool), nullptr),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, SearchSettings](ppfMessageHandle Message, bool bIsError)
			{
				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindMatchmakingSessions OnComplete ErrorMessage: %s"), *FString(ErrorMessage));
					SearchSettings->SearchState = EOnlineAsyncTaskState::Failed;
					TriggerOnFindSessionsCompleteDelegates(false);
					return;
				}
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindMatchmakingSessions OnComplete no error"));
				auto BrowseResult = ppf_Message_GetMatchmakingBrowseResult(Message);
				auto RoomArray = ppf_MatchmakingBrowseResult_GetRooms(BrowseResult);
				auto SearchResultsSize = ppf_MatchmakingRoomArray_GetSize(RoomArray);
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindMatchmakingSessions SearchResultsSize: %zu, MaxSearchResults: %d"), SearchResultsSize, SearchSettings->MaxSearchResults);
				if (SearchResultsSize > SearchSettings->MaxSearchResults)
				{
					SearchResultsSize = SearchSettings->MaxSearchResults;
				}
				SearchSettings->SearchResults.Reset(SearchResultsSize);
				int32 BuildUniqueId = GetBuildUniqueId();
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindMatchmakingSessions GetBuildUniqueId(): %d"), BuildUniqueId);
				for (size_t i = 0; i < SearchResultsSize; i++)
				{
					auto MatchmakingRoom = ppf_MatchmakingRoomArray_GetElement(RoomArray, i);
					auto Room = ppf_MatchmakingRoom_GetRoom(MatchmakingRoom);
					int32 ServerBuildId = GetRoomBuildUniqueId(Room);
					UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindMatchmakingSessions ServerBuildId: %d"), ServerBuildId);
					if (ServerBuildId != BuildUniqueId)
					{
						UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindMatchmakingSessions ServerBuildId != BuildUniqueId"));
						continue;
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
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::FindSessionById(const FUniqueNetId& SearchingUserId, const FUniqueNetId& SessionId, const FUniqueNetId& FriendId, const FOnSingleSessionResultCompleteDelegate& CompletionDelegate)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindSessionById %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
	if (LoggedInPlayerId.IsValid())
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById LoggedInPlayerId: %s"), *LoggedInPlayerId->ToString());
	}
	if (!LoggedInPlayerId.IsValid() || SearchingUserId != *LoggedInPlayerId)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindSessionById Need login first or SearchingUserId != LoggedInPlayerId"));
		return false;
	}
	if (FriendId.IsValid())
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindSessionById FriendId is not supported"));
		return false;
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById SessionId: %s"), *SessionId.ToString());
	const FUniqueNetIdPico& RoomId = static_cast<const FUniqueNetIdPico&>(SessionId);
	ppfID ppfIDRoomID = FCString::Strtoui64(*RoomId.GetStringID(), NULL, 10);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById ppf_Room_Get RoomId: %s, %llu"), *RoomId.GetStringID(), ppfIDRoomID);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById begin ppf_Room_Get"));
	PicoSubsystem.AddAsyncTask(
		ppf_Room_Get(ppfIDRoomID),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, CompletionDelegate](ppfMessageHandle Message, bool bIsError)
			{
				auto SearchResult = FOnlineSessionSearchResult();
				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindSessionById ErrorMessage: %s"), *FString(ErrorMessage));
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
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById GetBuildUniqueId(): %d"), BuildUniqueId);
				int32 ServerBuildId = GetRoomBuildUniqueId(Room);
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById ServerBuildId: %d"), ServerBuildId);
				if (ServerBuildId != BuildUniqueId)
				{
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindSessionById ServerBuildId != BuildUniqueId"));
					CompletionDelegate.ExecuteIfBound(0, false, SearchResult);
					return;
				}
				auto Session = CreateSessionFromRoom(Room);
				SearchResult.Session = Session.Get();
				auto RoomJoinability = ppf_Room_GetJoinability(Room);
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindSessionById RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability]));
				CompletionDelegate.ExecuteIfBound(0, RoomJoinability == ppfRoom_JoinabilityCanJoin, SearchResult);
			}));
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::CancelFindSessions()
{
	return false;
}

bool FOnlineSessionPico::JoinSession(int32 PlayerNum, FName SessionName, const FOnlineSessionSearchResult& DesiredSession)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME JoinSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME JoinSession Already in Session: %s"), *SessionName.ToString());
		TriggerOnJoinSessionCompleteDelegates(SessionName, EOnJoinSessionCompleteResult::AlreadyInSession);
		return false;
	}
	if (!DesiredSession.Session.SessionInfo.IsValid())
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME JoinSession SessionInfo is invalid"));
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
	PicoSubsystem.AddAsyncTask(
		ppf_Room_Join2(RoomId, RoomOptions),
		FPicoMessageOnCompleteDelegate::CreateLambda([this, SessionName, Session](ppfMessageHandle Message, bool bIsError)
			{
				auto Room = ppf_Message_GetRoom(Message);

				if (bIsError)
				{
					auto Error = ppf_Message_GetError(Message);
					auto ErrorMessage = ppf_Error_GetMessage(Error);
					UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME JoinSession OnComplete ErrorMessage: %s"), *FString(ErrorMessage));
					RemoveNamedSession(SessionName);
					auto RoomJoinability = ppf_Room_GetJoinability(Room);
					UE_LOG_ONLINE(Display, TEXT("PPF_GAME JoinSession RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability]));
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
				UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME JoinSession OnComplete no error"));
				UpdateSessionFromRoom(*Session, Room);
				TriggerOnJoinSessionCompleteDelegates(SessionName, EOnJoinSessionCompleteResult::Success);
			}));
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::JoinSession(const FUniqueNetId& PlayerId, FName SessionName, const FOnlineSessionSearchResult& DesiredSession)
{
	return JoinSession(0, SessionName, DesiredSession);
}

bool FOnlineSessionPico::FindFriendSession(int32 LocalUserNum, const FUniqueNetId& Friend)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME FindFriendSession %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
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
					UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME FindFriendSession ServerBuildId != BuildUniqueId"));
					TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, false, SearchResult);
					return;
				}
				auto Session = CreateSessionFromRoom(Room);
				SearchResult[0].Session = Session.Get();
				auto RoomJoinability = ppf_Room_GetJoinability(Room);
				//UE_LOG_ONLINE(Display, TEXT("PPF_GAME FindFriendSession RoomJoinability: %s"), *FString(JoinabilityNames[RoomJoinability]));
				TriggerOnFindFriendSessionCompleteDelegates(LocalUserNum, RoomJoinability == ppfRoom_JoinabilityCanJoin, SearchResult);
			}));
	return true;
#else
	return false;
#endif
};

bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const FUniqueNetId& Friend)
{
	return FindFriendSession(0, Friend);
}

bool FOnlineSessionPico::FindFriendSession(const FUniqueNetId& LocalUserId, const TArray<FUniqueNetIdRef>& FriendList)
{
	// todo
	return false;
}

bool FOnlineSessionPico::SendSessionInviteToFriend(int32 LocalUserNum, FName SessionName, const FUniqueNetId& Friend)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME SendSessionInviteToFriend %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	TArray< FUniqueNetIdRef > Friends;
	Friends.Add(FUniqueNetIdPico::Create(Friend));
	return SendSessionInviteToFriends(LocalUserNum, SessionName, Friends);
#else
	return false;
#endif
};

bool FOnlineSessionPico::SendSessionInviteToFriend(const FUniqueNetId& LocalUserId, FName SessionName, const FUniqueNetId& Friend)
{
	return SendSessionInviteToFriend(0, SessionName, Friend);
}

bool FOnlineSessionPico::SendSessionInviteToFriends(int32 LocalUserNum, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME SendSessionInviteToFriends %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (!Session)
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME SendSessionInviteToFriends Cannot find Session: %s"), *SessionName.ToString());
		return false;
	}
	IOnlineFriendsPtr FriendsInterface = PicoSubsystem.GetFriendsInterface();
	if (!FriendsInterface.IsValid())
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME SendSessionInviteToFriends FriendsInterface is invalid"));
		return false;
	}
	auto RoomId = GetRoomIDOfSession(*Session);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME SendSessionInviteToFriends RoomId: %llu"), RoomId);
	FriendsInterface->ReadFriendsList(
		LocalUserNum,
		FOnlineFriendsPico::FriendsListInviteableUsers,
		FOnReadFriendsListComplete::CreateLambda([RoomId, FriendsInterface, Friends](int32 InLocalUserNum, bool bWasSuccessful, const FString& ListName, const FString& ErrorName) {
			if (!bWasSuccessful)
			{
				UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME SendSessionInviteToFriends ReadFriendsList OnComplete ErrorName: %s"), *ErrorName);
				return;
			}
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME SendSessionInviteToFriends ReadFriendsList OnComplete no error"));
			for (auto FriendId : Friends)
			{
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME SendSessionInviteToFriends InLocalUserNum: %d"), InLocalUserNum);
				auto Friend = FriendsInterface->GetFriend(InLocalUserNum, FriendId.Get(), ListName);
				if (Friend.IsValid())
				{
					auto PicoFriend = static_cast<const FOnlinePicoFriend&>(*Friend);
					UE_LOG_ONLINE(Display, TEXT("PPF_GAME SendSessionInviteToFriends ppf_Room_InviteUser InviteToken: %s"), *PicoFriend.GetInviteToken());
					ppf_Room_InviteUser(RoomId, TCHAR_TO_UTF8(*PicoFriend.GetInviteToken()));
				}
			}
			}));
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::SendSessionInviteToFriends(const FUniqueNetId& LocalUserId, FName SessionName, const TArray< FUniqueNetIdRef >& Friends)
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
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME GetResolvedConnectString %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	auto Session = GetNamedSession(SessionName);
	if (Session != nullptr)
	{
		auto OwnerId = static_cast<const FUniqueNetIdPico*>(Session->OwningUserId.Get());
		ConnectInfo = FString::Printf(TEXT("%llu.pico"), OwnerId->GetID()); // todo
		return true;
	}
	return false;
#else
	return false;
#endif
}

bool FOnlineSessionPico::GetResolvedConnectString(const FOnlineSessionSearchResult& SearchResult, FName PortType, FString& ConnectInfo)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME GetResolvedConnectString %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	if (SearchResult.IsValid())
	{
		auto Session = SearchResult.Session;
		auto OwnerId = static_cast<const FUniqueNetIdPico*>(Session.OwningUserId.Get());
		ConnectInfo = FString::Printf(TEXT("%llu.pico"), OwnerId->GetID()); // todo
		return true;
	}
	return false;
#else
	return false;
#endif
}

FOnlineSessionSettings* FOnlineSessionPico::GetSessionSettings(FName SessionName)
{
#if PLATFORM_ANDROID
	FNamedOnlineSession* Session = GetNamedSession(SessionName);
	if (Session)
	{
		return &Session->SessionSettings;
	}
	return nullptr;
#else
	return nullptr;
#endif
}

bool FOnlineSessionPico::RegisterPlayer(FName SessionName, const FUniqueNetId& PlayerId, bool bWasInvited)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME RegisterPlayer %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	TArray< FUniqueNetIdRef > Players;
	Players.Add(FUniqueNetIdPico::Create(PlayerId));
	TriggerOnRegisterPlayersCompleteDelegates(SessionName, Players, true);
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::RegisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players, bool bWasInvited)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME RegisterPlayers %s"), *InitStateErrorMessage);
		return false;
	}
#if PLATFORM_ANDROID
	TriggerOnRegisterPlayersCompleteDelegates(SessionName, Players, true);
	return true;
#else
	return false;
#endif
}

bool FOnlineSessionPico::UnregisterPlayer(FName SessionName, const FUniqueNetId& PlayerId)
{
	return false;
}

bool FOnlineSessionPico::UnregisterPlayers(FName SessionName, const TArray< FUniqueNetIdRef >& Players)
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

FUniqueNetIdPtr FOnlineSessionPico::CreateSessionIdFromString(const FString& SessionIdStr)
{
	FUniqueNetIdPtr SessionId;
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

FNamedOnlineSession* FOnlineSessionPico::AddNamedSession(FName SessionName, const FOnlineSessionSettings& SessionSettings)
{
	TSharedPtr<FNamedOnlineSession> Session = MakeShareable(new FNamedOnlineSession(SessionName, SessionSettings));
	Sessions.Add(SessionName, Session);
	return Session.Get();
}

FNamedOnlineSession* FOnlineSessionPico::AddNamedSession(FName SessionName, const FOnlineSession& Session)
{
	TSharedPtr<FNamedOnlineSession> NamedSession = MakeShareable(new FNamedOnlineSession(SessionName, Session));
	Sessions.Add(SessionName, NamedSession);
	return NamedSession.Get();
}

TSharedRef<FOnlineSession> FOnlineSessionPico::CreateSessionFromRoom(ppfRoomHandle Room) const
{
#if PLATFORM_ANDROID
	auto RoomId = ppf_Room_GetID(Room);
	auto RoomOwner = ppf_Room_GetOwner(Room);
	auto RoomMaxUsers = ppf_Room_GetMaxUsers(Room);
	auto RoomUsers = ppf_Room_GetUsers(Room);
	auto RoomCurrentUsersSize = ppf_UserArray_GetSize(RoomUsers);
	auto RoomDataStore = ppf_Room_GetDataStore(Room);
	auto RoomPolicy = ppf_Room_GetJoinPolicy(Room);
	auto RoomJoinability = ppf_Room_GetJoinability(Room);
	auto RoomType = ppf_Room_GetType(Room);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateSessionFromRoom RoomId: %llu, RoomMaxUsers: %d, RoomCurrentUsersSize: %lld, RoomPolicy: %s, RoomType: %s, RoomJoinability: %s")
		, RoomId, RoomMaxUsers, RoomCurrentUsersSize, *FString(JoinPolicyNames[RoomPolicy]), *FString(RoomTypeNames[RoomType]), *FString(JoinabilityNames[RoomJoinability]));
	for (size_t UserIndex = 0; UserIndex < RoomCurrentUsersSize; ++UserIndex)
	{
		auto User = ppf_UserArray_GetElement(RoomUsers, UserIndex);
		FString RoomOwnerIdString = UTF8_TO_TCHAR(ppf_User_GetID(User));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME CreateSessionFromRoom UserIndex: %zu, UserId: %s"), UserIndex, *RoomOwnerIdString);
	}
#endif
	auto SessionSettings = FOnlineSessionSettings();
#if PLATFORM_ANDROID
	SessionSettings.NumPublicConnections = RoomMaxUsers;
	SessionSettings.NumPrivateConnections = 0;
	UpdateSessionSettingsFromDataStore(SessionSettings, RoomDataStore);
#endif
	auto Session = new FOnlineSession(SessionSettings);
#if PLATFORM_ANDROID
	Session->OwningUserId = FUniqueNetIdPico::Create(UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner)));
	Session->OwningUserName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(RoomOwner));
	auto RemainingConnections = RoomMaxUsers - RoomCurrentUsersSize;
	Session->NumOpenPublicConnections = (RemainingConnections > 0) ? RemainingConnections : 0;
	Session->NumOpenPrivateConnections = 0;
	Session->SessionInfo = MakeShareable(new FOnlineSessionInfoPico(RoomId));
	TestDumpSession(Session);
#endif
	return MakeShareable(Session);
}

void FOnlineSessionPico::LogRoomData(ppfRoomHandle Room) const
{
#if PLATFORM_ANDROID
	auto RoomId = ppf_Room_GetID(Room);
	auto RoomOwner = ppf_Room_GetOwner(Room);
	auto RoomMaxUsers = ppf_Room_GetMaxUsers(Room);
	auto RoomUsers = ppf_Room_GetUsers(Room);
	auto RoomCurrentUsersSize = ppf_UserArray_GetSize(RoomUsers);
	auto RoomDataStore = ppf_Room_GetDataStore(Room);
	auto RoomPolicy = ppf_Room_GetJoinPolicy(Room);
	auto RoomJoinability = ppf_Room_GetJoinability(Room);
	auto RoomType = ppf_Room_GetType(Room);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME LogRoomData RoomId: %llu, RoomMaxUsers: %d, RoomCurrentUsersSize: %lld, RoomPolicy: %s, RoomType: %s, RoomJoinability: %s")
		, RoomId, RoomMaxUsers, RoomCurrentUsersSize, *FString(JoinPolicyNames[RoomPolicy]), *FString(RoomTypeNames[RoomType]), *FString(JoinabilityNames[RoomJoinability]));
#endif
}

void FOnlineSessionPico::UpdateSessionFromRoom(FNamedOnlineSession& Session, ppfRoomHandle Room) const
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateSessionFromRoom %s"), *InitStateErrorMessage);
		return;
	}
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom begin"));
	LogRoomData(Room);
	auto UserArray = ppf_Room_GetUsers(Room);
	auto UserArraySize = ppf_UserArray_GetSize(UserArray);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom UserArraySize: %zu"), UserArraySize);
	TArray< FUniqueNetIdRef > Players;
	for (size_t UserIndex = 0; UserIndex < UserArraySize; ++UserIndex)
	{
		auto User = ppf_UserArray_GetElement(UserArray, UserIndex);
		FString UserId = UTF8_TO_TCHAR(ppf_User_GetID(User));
		auto PlayerId = FUniqueNetIdPico::Create(UserId);
		Players.Add(PlayerId);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom UserIndex: %zu, UserId: %s, PlayerId: %s"), UserIndex, *UserId, *PlayerId->ToString());
	}
	Session.RegisteredPlayers = Players;
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom NumPublicConnections: %d"), Session.SessionSettings.NumPublicConnections);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom ppf_Room_GetMaxUsers: %d"), ppf_Room_GetMaxUsers(Room));
	Session.SessionSettings.NumPublicConnections = ppf_Room_GetMaxUsers(Room);
	auto RemainingConnections = Session.SessionSettings.NumPublicConnections - UserArraySize;
	Session.NumOpenPublicConnections = (RemainingConnections > 0) ? RemainingConnections : 0;
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom set NumOpenPublicConnections: %d"), Session.NumOpenPublicConnections);
	Session.NumOpenPrivateConnections = 0;
	auto RoomOwner = ppf_Room_GetOwner(Room);
	FString RoomOwnerIdString = UTF8_TO_TCHAR(ppf_User_GetID(RoomOwner));
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom RoomOwnerIdString: %s"), *RoomOwnerIdString);
	auto RoomOwnerUniqueIdPtr = FUniqueNetIdPico::Create(RoomOwnerIdString);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom RoomOwnerUniqueId: %s"), *RoomOwnerUniqueIdPtr->ToString());

	if (!Session.OwningUserId.IsValid() || Session.OwningUserId.ToSharedRef().Get() != *RoomOwnerUniqueIdPtr)
	{
		Session.OwningUserId = RoomOwnerUniqueIdPtr;
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom set OwningUserId: %s"), *(Session.OwningUserId->ToString()));
		Session.OwningUserName = UTF8_TO_TCHAR(ppf_User_GetDisplayName(RoomOwner));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom set OwningUserName : %s"), *Session.OwningUserName);
		if (Session.LocalOwnerId.IsValid())
		{
			Session.bHosting = Session.OwningUserId.ToSharedRef().Get() == *Session.LocalOwnerId;
		}
		else
		{
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom Session.LocalOwnerId is invalid")); 
			Session.bHosting = false;
		}
	}
	TestDumpNamedSession(&Session);
	auto RoomDataStore = ppf_Room_GetDataStore(Room);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionFromRoom end ppf_Room_GetDataStore"));
	UpdateSessionSettingsFromDataStore(Session.SessionSettings, RoomDataStore);
#endif
}

void FOnlineSessionPico::UpdateSessionSettingsFromDataStore(FOnlineSessionSettings& SessionSettings, ppfDataStoreHandle DataStore) const
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore %s"), *InitStateErrorMessage);
		return;
	}
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore begin"));
	if (DataStore == nullptr)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore DataStore is nullptr"));
	}
	auto DataStoreSize = ppf_DataStore_GetNumKeys(DataStore);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore DataStoreSize: %zu"), DataStoreSize);
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
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore Key: %s, Value: %d"), *DataStoreKey.ToString(), IntDataStoreValue);
		}
		else if (DataStoreKey == SETTING_PICO_BUILD_UNIQUE_ID)
		{
			SessionSettings.BuildUniqueId = FCString::Atoi(UTF8_TO_TCHAR(DataStoreValue));
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore set SessionSettings.BuildUniqueId DataStoreValue: %d"), SessionSettings.BuildUniqueId);
		}
		else
		{
			SessionSettings.Set(
				DataStoreKey,
				SetValue,
				EOnlineDataAdvertisementType::ViaOnlineService
			);
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME UpdateSessionSettingsFromDataStore Key: %s, Value: %s"), *DataStoreKey.ToString(), *SetValue);
		}
	}
#endif
}

void FOnlineSessionPico::TickPendingInvites(float DeltaTime)
{
#if PLATFORM_ANDROID
	if (InviteAcceptedSessions.Num() > 0 && OnSessionUserInviteAcceptedDelegates.IsBound())
	{
		IOnlineIdentityPtr Identity = PicoSubsystem.GetIdentityInterface();
		auto PlayerId = Identity->GetUniquePlayerId(0);
		for (auto PendingInviteAcceptedSession : InviteAcceptedSessions)
		{
			TriggerOnSessionUserInviteAcceptedDelegates(true, 0, PlayerId, PendingInviteAcceptedSession.Get());
		}
		InviteAcceptedSessions.Empty();
	}
#endif
}

int32 FOnlineSessionPico::GetRoomBuildUniqueId(const ppfRoomHandle Room)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME GetRoomBuildUniqueId %s"), *InitStateErrorMessage);
		return 0;
	}
#if PLATFORM_ANDROID
	auto RoomDataStore = ppf_Room_GetDataStore(Room);
	auto ServerBuildId = ppf_DataStore_GetValue(RoomDataStore, TCHAR_TO_UTF8(*SETTING_PICO_BUILD_UNIQUE_ID.ToString()));
	if (!ServerBuildId)
	{
		return 0;
	}

	return FCString::Atoi(UTF8_TO_TCHAR(ServerBuildId));
#endif
	return 0;
}


/////////////////////////////////////////

bool FOnlineSessionPico::Uninitialize()
{
#if PLATFORM_ANDROID
	SetInitState(false);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME Uninitialize"));
	auto Result = ppf_Game_UnInitialize();
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME Uninitialize Result: %d"), Result);
	return Result;
#endif
	return false;
}
void FOnlineSessionPico::Initialize()
{
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME Initialize"));
	SetInitState(false);
	PicoSubsystem.AddAsyncTask(
		ppf_User_GetAccessToken(),
		FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnGetAccessTokenComplete));
#endif
}
void FOnlineSessionPico::OnGetAccessTokenComplete(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnGetAccessTokenComplete"));
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		FString ErrorMessageStr = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnGetAccessTokenComplete ErrorMessage: %s"), *ErrorMessageStr);
		//Initialize();
		return;
	}

	auto MessageType = ppf_Message_GetType(Message);
	auto token = ppf_Message_GetString(Message);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnGetAccessTokenComplete token: %s"), *FString(token));

	PicoSubsystem.AddAsyncTask(
		ppf_Game_InitializeWithToken(token),
		FPicoMessageOnCompleteDelegate::CreateRaw(this, &FOnlineSessionPico::OnGameInitializeComplete));

#endif
}
void FOnlineSessionPico::OnGameInitializeComplete(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnGameInitializeComplete"));
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnGameInitializeComplete ErrorMessage: %s"), *FString(ErrorMessage));
		Uninitialize();
		Initialize();
		return;
	}

	auto MessageType = ppf_Message_GetType(Message);
	if (MessageType == ppfMessageType::ppfMessage_PlatformGameInitializeAsynchronous)
	{
		auto objHandle = ppf_Message_GetPlatformGameInitialize(Message);
		auto obj = ppf_PlatformGameInitialize_GetResult(objHandle);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnGameInitializeComplete Result: %d"), obj);
		if (obj == ppfPlatformGameInitialize_Success)
		{
			SetInitState(true);
		}
		else
		{
			Uninitialize();
			Initialize();
		}
	}
#endif
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
#if PLATFORM_ANDROID
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnForcedLeaveRoom Server leave RoomID: %d"), RoomID);
	for (auto It = Sessions.CreateConstIterator(); It; ++It)
	{
		TSharedPtr<FNamedOnlineSession> Session = It.Value();
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnForcedLeaveRoom GetRoomIDOfSession(Session): %d"), GetRoomIDOfSession(*Session));
		if (Session.IsValid() && (RoomID == 0 || GetRoomIDOfSession(*Session) == RoomID))
		{
			Session->SessionState = EOnlineSessionState::Destroying;
			// callback
			//CompletionDelegate.ExecuteIfBound(Session.SessionName, true); // todo
			TriggerOnDestroySessionCompleteDelegates(Session->SessionName, true);
		}
		else
		{
			UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnForcedLeaveRoom Invalid session during shutdown!"));
		}
	}
	Sessions.Empty();
#endif
}
bool FOnlineSessionPico::OnUpdateRoomData(ppfRoomHandle Room, ppfID RoomId)
{
	for (auto SessionKV : Sessions)
	{
		if (SessionKV.Value.IsValid())
		{
			auto Session = SessionKV.Value.Get();
			auto SessionRoomId = GetRoomIDOfSession(*Session);
			if (RoomId == SessionRoomId)
			{
				UpdateSessionFromRoom(*Session, Room);
				return true;
			}
		}
	}
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
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnRoomNotificationUpdate %s"), *InitStateErrorMessage);
		RoomUpdateCallback.Broadcast(FString("IsInitSuccess is false"), false);
		return;
	}
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationUpdate Error on getting a room notification update"));
		RoomUpdateCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	auto Room = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(Room);
	bool Update = OnUpdateRoomData(Room, RoomId);
	if (Update)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdate Update room success"));
		RoomUpdateCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
	}
	else
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationUpdate Session was gone before the notif update came back"));
		RoomUpdateCallback.Broadcast(FString("cannot find session"), false);
	}
#endif
}
void FOnlineSessionPico::OnRoomInviteAccepted(ppfMessageHandle Message, bool bIsError)
{
	// 4.8.0
}
void FOnlineSessionPico::OnMatchmakingNotificationMatchFound(ppfMessageHandle Message, bool bIsError)
{
	if (!IsInitSuccess())
	{
		UE_LOG_ONLINE_SESSION(Error, TEXT("PPF_GAME OnMatchmakingNotificationMatchFound %s"), *InitStateErrorMessage);
		return;
	}
#if PLATFORM_ANDROID
	if (!InProgressMatchmakingSearch.IsValid())
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnMatchmakingNotificationMatchFound No matchmaking searches in progress"));
		return;
	}

	if (bIsError)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnMatchmakingNotificationMatchFound error"));
		InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Failed;
		InProgressMatchmakingSearch = nullptr;
		TriggerOnMatchmakingCompleteDelegates(InProgressMatchmakingSearchName, false);
		return;
	}
	else
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnMatchmakingNotificationMatchFound no error"));
	}

	auto Room = ppf_Message_GetRoom(Message);
	FOnlineSessionSearchResult SearchResult;
	auto Session = CreateSessionFromRoom(Room);
	SearchResult.Session = Session.Get();
	InProgressMatchmakingSearch->SearchResults.Add(SearchResult);
	InProgressMatchmakingSearch->SearchState = EOnlineAsyncTaskState::Done;
	InProgressMatchmakingSearch = nullptr;
	TriggerOnMatchmakingCompleteDelegates(InProgressMatchmakingSearchName, true);
#endif
}


// Notifications
void FOnlineSessionPico::OnNetNotificationConnection(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationConnection error ErrorMessage: %s"), *FString(ErrorMessage));
		GameConnectionCallback.Broadcast(-1, false);
		return;
	}
	auto ConnectionResult = ppf_Message_GetGameConnectionEvent(Message);
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationConnection ConnectionResult: %s"), *FString(ConnectionResultNames[ConnectionResult]));
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
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationConnection click ok button."));
				Initialize();
			}
			else
			{
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationConnection click cancel button."));
			}
		}
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
		GameConnectionCallback.Broadcast((int)ConnectionResult, false);
		Uninitialize();
		Initialize();
	}
#endif
}
void FOnlineSessionPico::OnNetNotificationRequestFailed(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationRequestFailed error ErrorMessage: %s"), *FString(ErrorMessage));
		GameRequestFailedCallback.Broadcast(-1, false);
		return;
	}
	else
	{
		auto FailedReason = ppf_Message_GetGameRequestFailedReason(Message);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationRequestFailed FailedReason: %d"), FailedReason);
		GameRequestFailedCallback.Broadcast((int)FailedReason, true);
	}
#endif
}
void FOnlineSessionPico::OnNetNotificationGameStateReset(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationGameStateReset error ErrorMessage: %s"), *FString(ErrorMessage));
		GameStateResetCallback.Broadcast(false);
		return;
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnNetNotificationGameStateReset no error"));
	if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
	{ // in matchmaking
		OnForcedCancelMatchmaking();
	}
	else
	{ // in room
		OnForcedLeaveRoom(0);
	}
	GameStateResetCallback.Broadcast(true);
#endif
}
void FOnlineSessionPico::OnMatchmakingNotificationCancel2(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnMatchmakingNotificationCancel2 error ErrorMessage: %s"), *FString(ErrorMessage));
		MatchmakingCancel2Callback.Broadcast(false);
		return;
	}
	else
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnMatchmakingNotificationCancel2 no error"));
		if (InProgressMatchmakingSearch.IsValid() && InProgressMatchmakingSearch->SearchState == EOnlineAsyncTaskState::InProgress)
		{ // in matchmaking
			OnForcedCancelMatchmaking();
		}
		MatchmakingCancel2Callback.Broadcast(true);
	}
#endif
}
void FOnlineSessionPico::OnRoomNotificationLeave(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationLeave error ErrorMessage: %s"), *FString(ErrorMessage));
		RoomLeaveCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationLeave no error."));
	auto RoomHandle = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(RoomHandle);
	LogRoomData(RoomHandle);
	OnForcedLeaveRoom(RoomId);
	RoomLeaveCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
#endif
}
void FOnlineSessionPico::OnRoomNotificationJoin2(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationJoin2 error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomJoin2Callback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	auto Room = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(Room);
	bool Update = OnUpdateRoomData(Room, RoomId);
	if (Update)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationJoin2 Update room success"));
		RoomJoin2Callback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
	}
	else
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationJoin2 Session was gone before the notif update came back"));
		RoomJoin2Callback.Broadcast(FString("cannot find session"), false);
	}
#endif
}
void FOnlineSessionPico::OnRoomNotificationSetDescription(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationSetDescription error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomSetDescriptionCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	auto Room = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(Room);
	bool Update = OnUpdateRoomData(Room, RoomId);
	if (Update)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationSetDescription Update room success"));
		RoomSetDescriptionCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
	}
	else
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationSetDescription Session was gone before the notif update came back"));
		RoomSetDescriptionCallback.Broadcast(FString("cannot find session"), false);
	}
#endif
}
void FOnlineSessionPico::OnRoomNotificationKickUser(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationKickUser error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomKickUserCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	// todo check
	UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationKickUser no error."));
	auto RoomHandle = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(RoomHandle);
	LogRoomData(RoomHandle);
	OnForcedLeaveRoom(RoomId);
	RoomKickUserCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
#endif
}
void FOnlineSessionPico::OnRoomNotificationUpdateOwner(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateOwner error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomUpdateOwnerCallback.Broadcast(false);
		return;
	}
	else
	{
		// todo
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateOwner no error"));
		RoomUpdateOwnerCallback.Broadcast(true);
	}
#endif
}
void FOnlineSessionPico::OnRoomNotificationUpdateDataStore(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateDataStore error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomUpdateDataStoreCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	auto Room = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(Room);
	bool Update = OnUpdateRoomData(Room, RoomId);
	if (Update)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateDataStore Update room success"));
		RoomUpdateDataStoreCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
	}
	else
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationUpdateDataStore Session was gone before the notif update came back"));
		RoomUpdateDataStoreCallback.Broadcast(FString("cannot find session"), false);
	}
#endif	
}
void FOnlineSessionPico::OnRoomNotificationUpdateMembershipLockStatus(ppfMessageHandle Message, bool bIsError)
{
#if PLATFORM_ANDROID
	if (bIsError)
	{
		auto Error = ppf_Message_GetError(Message);
		auto ErrorMessage = ppf_Error_GetMessage(Error);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateMembershipLockStatus error. ErrorMessage: %s"), *FString(ErrorMessage));
		RoomUpdateMembershipLockStatusCallback.Broadcast(FString(ErrorMessage), false);
		return;
	}
	auto Room = ppf_Message_GetRoom(Message);
	auto RoomId = ppf_Room_GetID(Room);
	bool Update = OnUpdateRoomData(Room, RoomId);
	if (Update)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME OnRoomNotificationUpdateMembershipLockStatus Update room success"));
		RoomUpdateMembershipLockStatusCallback.Broadcast(FString::Printf(TEXT("%llu"), RoomId), true);
	}
	else
	{
		UE_LOG_ONLINE_SESSION(Warning, TEXT("PPF_GAME OnRoomNotificationUpdateMembershipLockStatus Session was gone before the notif update came back"));
		RoomUpdateMembershipLockStatusCallback.Broadcast(FString("cannot find session"), false);
	}
#endif	
}
// Log
void FOnlineSessionPico::TestDumpNamedSession(const FNamedOnlineSession* NamedSession) const
{
	if (NamedSession != NULL)
	{
		//LOG_SCOPE_VERBOSITY_OVERRIDE(LogOnlineSession, ELogVerbosity::VeryVerbose);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME dumping NamedSession: "));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	SessionName: %s"), *NamedSession->SessionName.ToString());
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	HostingPlayerNum: %d"), NamedSession->HostingPlayerNum);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	SessionState: %s"), EOnlineSessionState::ToString(NamedSession->SessionState));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	RegisteredPlayers: "));
		if (NamedSession->RegisteredPlayers.Num())
		{
			for (int32 UserIdx = 0; UserIdx < NamedSession->RegisteredPlayers.Num(); UserIdx++)
			{
				UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	    %d: %s"), UserIdx, *NamedSession->RegisteredPlayers[UserIdx]->ToString());
			}
		}
		else
		{
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	    0 registered players"));
		}

		TestDumpSession(NamedSession);
	}
}
void FOnlineSessionPico::TestDumpSession(const FOnlineSession* Session) const
{
	if (Session != NULL)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME dumping Session: "));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	OwningPlayerName: %s"), *Session->OwningUserName);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	OwningPlayerId: %s"), Session->OwningUserId.IsValid() ? *Session->OwningUserId->ToString() : TEXT(""));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	NumOpenPrivateConnections: %d"), Session->NumOpenPrivateConnections);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	NumOpenPublicConnections: %d"), Session->NumOpenPublicConnections);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME 	SessionInfo: %s"), Session->SessionInfo.IsValid() ? *Session->SessionInfo->ToDebugString() : TEXT("NULL"));
		TestDumpSessionSettings(&Session->SessionSettings);
	}
	else
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME dumping Session is null"));
	}
}
void FOnlineSessionPico::TestDumpSessionSettings(const FOnlineSessionSettings* SessionSettings) const
{
	if (SessionSettings != NULL)
	{
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME dumping SessionSettings: "));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tNumPublicConnections: %d"), SessionSettings->NumPublicConnections);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tNumPrivateConnections: %d"), SessionSettings->NumPrivateConnections);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbIsLanMatch: %s"), SessionSettings->bIsLANMatch ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbIsDedicated: %s"), SessionSettings->bIsDedicated ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbUsesStats: %s"), SessionSettings->bUsesStats ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbShouldAdvertise: %s"), SessionSettings->bShouldAdvertise ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbAllowJoinInProgress: %s"), SessionSettings->bAllowJoinInProgress ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbAllowInvites: %s"), SessionSettings->bAllowInvites ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbUsesPresence: %s"), SessionSettings->bUsesPresence ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbAllowJoinViaPresence: %s"), SessionSettings->bAllowJoinViaPresence ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tbAllowJoinViaPresenceFriendsOnly: %s"), SessionSettings->bAllowJoinViaPresenceFriendsOnly ? TEXT("true") : TEXT("false"));
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tBuildUniqueId: 0x%08x"), SessionSettings->BuildUniqueId);
		UE_LOG_ONLINE(Display, TEXT("PPF_GAME \tSettings:"));
		for (FSessionSettings::TConstIterator It(SessionSettings->Settings); It; ++It)
		{
			FName Key = It.Key();
			const FOnlineSessionSetting& Setting = It.Value();
			UE_LOG_ONLINE(Display, TEXT("PPF_GAME \t\t%s=%s"), *Key.ToString(), *Setting.ToString());
		}
	}
}



