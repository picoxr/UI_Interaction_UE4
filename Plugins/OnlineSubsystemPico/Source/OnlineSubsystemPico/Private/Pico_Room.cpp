// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_Room.h"
#include "OnlineSubsystemUtils.h"
#include "Pico_User.h"
#include "Pico_DataStore.h"

DEFINE_LOG_CATEGORY(PicoRoom);


void UOnlinePicoRoomFunction::LaunchInvitableUserFlow(UObject* WorldContextObject, const FString& RoomID, FRoomLaunchInvitableUserFlow OnLaunchInvitableUserFlowCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::LaunchInvitableUserFlow"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->LaunchInvitableUserFlow(RoomID, OnLaunchInvitableUserFlowCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("LaunchInvitableUserFlow Failed, PicoRoomInterface Not Vailed!"));
		OnLaunchInvitableUserFlowCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")));
	}
}

void UOnlinePicoRoomFunction::UpdateDataStore(UObject* WorldContextObject, const FString& RoomID, const TMap<FString, FString>& Data,
                            FRoomUpdateDataStore OnUpdateDataStoreCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::UpdateDataStore"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->UpdateDataStore(RoomID, Data, OnUpdateDataStoreCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("UpdateDataStore Failed, PicoRoomInterface Not Vailed!"));
		OnUpdateDataStoreCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::CreateAndJoinPrivate2(UObject* WorldContextObject, ERoomJoinPolicy JoinPolicy, int32 MaxUsers,
                                  FPicoRoomOptions RoomOptions,
                                  FRoomCreateAndJoinPrivate2 OnCreateAndJoinPrivate2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::CreateAndJoinPrivate2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->CreateAndJoinPrivate2(JoinPolicy, MaxUsers, RoomOptions, OnCreateAndJoinPrivate2Callback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("CreateAndJoinPrivate2 Failed, PicoRoomInterface Not Vailed!"));
		OnCreateAndJoinPrivate2Callback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::Get(UObject* WorldContextObject, const FString& RoomID, FRoomGet OnGetCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::Get"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->Get(RoomID, OnGetCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("Get Failed, PicoRoomInterface Not Vailed!"));
		OnGetCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::GetCurrent(UObject* WorldContextObject, FRoomGetCurrent OnGetCurrentCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetCurrent"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->GetCurrent(OnGetCurrentCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("GetCurrent Failed, PicoRoomInterface Not Vailed!"));
		OnGetCurrentCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::GetCurrentForUser(UObject* WorldContextObject, const FString& UserId,
                              FRoomGetCurrentForUser OnGetCurrentForUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetCurrentForUser"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->GetCurrentForUser(UserId, OnGetCurrentForUserCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("GetCurrentForUser Failed, PicoRoomInterface Not Vailed!"));
		OnGetCurrentForUserCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::GetInvitableUsers2(UObject* WorldContextObject, FPicoRoomOptions RoomOptions,
                               FRoomGetInvitableUsers2 OnGetInvitableUsers2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetInvitableUsers2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->GetInvitableUsers2(RoomOptions, OnGetInvitableUsers2Callback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("GetInvitableUsers2 Failed, PicoRoomInterface Not Vailed!"));
		OnGetInvitableUsers2Callback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::GetModeratedRooms(UObject* WorldContextObject, int PageIndex, int PageSize,
                              FRoomGetModeratedRooms OnGetModeratedRoomsCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetModeratedRooms"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->GetModeratedRooms(PageIndex, PageSize, OnGetModeratedRoomsCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("GetModeratedRooms Failed, PicoRoomInterface Not Vailed!"));
		OnGetModeratedRoomsCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::InviteUser(UObject* WorldContextObject, const FString& RoomID, const FString& Token,
                       FRoomInviteUser OnInviteUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::InviteUser"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->InviteUser(RoomID, Token, OnInviteUserCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("InviteUser Failed, PicoRoomInterface Not Vailed!"));
		OnInviteUserCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::Join2(UObject* WorldContextObject, const FString& RoomID, FPicoRoomOptions RoomOptions,
                  FRoomJoin2 OnJoin2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::Join2"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->Join2(RoomID, RoomOptions, OnJoin2Callback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("Join2 Failed, PicoRoomInterface Not Vailed!"));
		OnJoin2Callback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::KickUser(UObject* WorldContextObject, const FString& RoomID, const FString& UserID,
                     int32 KickDurationSeconds, FRoomKickUser OnKickUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::KickUser"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->KickUser(RoomID, UserID, KickDurationSeconds, OnKickUserCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("KickUser Failed, PicoRoomInterface Not Vailed!"));
		OnKickUserCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::Leave(UObject* WorldContextObject, const FString& RoomID, FRoomLeave OnLeaveCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::Leave"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->Leave(RoomID, OnLeaveCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("Leave Failed, PicoRoomInterface Not Vailed!"));
		OnLeaveCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::SetDescription(UObject* WorldContextObject, const FString& RoomID, const FString& Description,
                           FRoomSetDescription OnSetDescriptionCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::SetDescription"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->SetDescription(RoomID, Description, OnSetDescriptionCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("SetDescription Failed, PicoRoomInterface Not Vailed!"));
		OnSetDescriptionCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::UpdateMembershipLockStatus(UObject* WorldContextObject, const FString& RoomID,
                                       ERoomMembershipLockStatus MembershipLockStatus,
                                       FRoomUpdateMembershipLockStatus OnUpdateMembershipLockStatusCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::UpdateMembershipLockStatus"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->UpdateMembershipLockStatus(RoomID, MembershipLockStatus, OnUpdateMembershipLockStatusCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("UpdateMembershipLockStatus Failed, PicoRoomInterface Not Vailed!"));
		OnUpdateMembershipLockStatusCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::UpdateOwner(UObject* WorldContextObject, const FString& RoomID, const FString& UserID,
                        FRoomUpdateOwner OnUpdateOwnerCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::UpdateOwner"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->UpdateOwner(RoomID, UserID, OnUpdateOwnerCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("UpdateOwner Failed, PicoRoomInterface Not Vailed!"));
		OnUpdateOwnerCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")));
	}
}

void UOnlinePicoRoomFunction::UpdatePrivateRoomJoinPolicy(UObject* WorldContextObject, const FString& RoomID, ERoomJoinPolicy JoinPolicy,
                                        FRoomUpdatePrivateRoomJoinPolicy OnUpdatePrivateRoomJoinPolicyCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::UpdatePrivateRoomJoinPolicy"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->UpdatePrivateRoomJoinPolicy(RoomID, JoinPolicy, OnUpdatePrivateRoomJoinPolicyCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("UpdatePrivateRoomJoinPolicy Failed, PicoRoomInterface Not Vailed!"));
		OnUpdatePrivateRoomJoinPolicyCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}


void UOnlinePicoRoomFunction::GetNamedRooms(UObject* WorldContextObject, int PageIndex, int PageSize, FRoomGetNamedRooms OnGetNamedRoomsCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetNamedRooms"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->GetNamedRooms(PageIndex, PageSize, OnGetNamedRoomsCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("GetNamedRooms Failed, PicoRoomInterface Not Vailed!"));
		OnGetNamedRoomsCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoRoomFunction::JoinOrCreateNamedRoom(UObject* WorldContextObject, ERoomJoinPolicy JoinPolicy, bool CreateIfNotExist, int32 MaxUsers
	, FPicoRoomOptions Options, FRoomJoinOrCreateNamedRoom OnRoomJoinOrCreateNamedRoomCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::JoinOrCreateNamedRoom"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoRoomInterface())
	{
		Subsystem->GetPicoRoomInterface()->JoinOrCreateNamedRoom(JoinPolicy, CreateIfNotExist, MaxUsers, Options, OnRoomJoinOrCreateNamedRoomCallback);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("JoinOrCreateNamedRoom Failed, PicoRoomInterface Not Vailed!"));
		OnRoomJoinOrCreateNamedRoomCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoRoomInterface Not Vailed")), nullptr);
	}
}

FPicoRoomOptions UOnlinePicoRoomFunction::GetCreatePrivateRoomOptions(const FString& DataStoreKey, const FString& DataStoreValue)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetPrivateRoomOptions"));
	FPicoRoomOptions Options;
	Options.DataStoreKey = DataStoreKey;
	Options.DataStoreValue = DataStoreValue;
	return Options;
}

FPicoRoomOptions UOnlinePicoRoomFunction::GetJoinOrCreateNamedRoomOptions(const FString& DataStoreKey, const FString& DataStoreValue, const FString& Name, const FString& Password)
{
	UE_LOG(PicoRoom, Log, TEXT("UOnlinePicoRoomFunction::GetNamedRoomOptions"));
	FPicoRoomOptions Options;
	Options.DataStoreKey = DataStoreKey;
	Options.DataStoreValue = DataStoreValue;
	Options.RoomName = Name;
	Options.RoomPassword = Password;
	return Options;
}

// FPicoRoomInterface
FPicoRoomInterface::FPicoRoomInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
	RoomUpdateHandle =
			PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Room_RoomUpdate)
			.AddRaw(this, &FPicoRoomInterface::OnRoomUpdateNotification);

	RoomUpdateOwnerHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_UpdateOwner)
		.AddRaw(this, &FPicoRoomInterface::OnRoomUpdateOwnerNotification);

	RoomJoinHandle =
			PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_Join2)
			.AddRaw(this, &FPicoRoomInterface::OnRoomJoinNotification);

	RoomLeaveHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessageType_Room_Leave)
		.AddRaw(this, &FPicoRoomInterface::OnRoomLeaveNotification);

	RoomInviteAcceptedHandle =
		PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_Room_InviteAccepted)
		.AddRaw(this, &FPicoRoomInterface::OnRoomInviteAcceptedNotification);
}
void FPicoRoomInterface::OnRoomUpdateNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::OnRoomUpdateNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoRoom, Error, TEXT("RoomUpdateNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		RoomUpdateNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, nullptr);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("RoomUpdateNotification success!"));
		UPico_Room* Room = NewObject<UPico_Room>();
		Room->InitParams(ppf_Message_GetRoom(Message));
		RoomUpdateNotify.Broadcast(bIsError, 0, FString(), Room);
	}
}

void FPicoRoomInterface::OnRoomUpdateOwnerNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::OnRoomUpdateOwnerNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoRoom, Error, TEXT("RoomUpdateOwnerNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		RoomUpdateOwnerNotify.Broadcast(bIsError, ErrorCode, ErrorMessage);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("RoomUpdateOwnerNotification success!"));
		RoomUpdateOwnerNotify.Broadcast(bIsError, 0, FString());
	}
}

void FPicoRoomInterface::OnRoomJoinNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::OnRoomJoinNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoRoom, Error, TEXT("RoomJoinNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		RoomJoinNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, nullptr);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("RoomJoinNotification success!"));
		UPico_Room* Room = NewObject<UPico_Room>();
		Room->InitParams(ppf_Message_GetRoom(Message));
		RoomJoinNotify.Broadcast(bIsError, 0, FString(), Room);
	}
}

void FPicoRoomInterface::OnRoomLeaveNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::OnRoomLeaveNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoRoom, Error, TEXT("RoomLeaveNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		RoomUpdateNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, nullptr);
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("RoomLeaveNotification success!"));
		UPico_Room* Room = NewObject<UPico_Room>();
		Room->InitParams(ppf_Message_GetRoom(Message));
		RoomUpdateNotify.Broadcast(bIsError, 0, FString(), Room);
	}
}

void FPicoRoomInterface::OnRoomInviteAcceptedNotification(ppfMessageHandle Message, bool bIsError)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::OnRoomInviteAcceptedNotification"));
	if (bIsError)
	{
		const ppfErrorHandle Error = ppf_Message_GetError(Message);
		const int ErrorCode = ppf_Error_GetCode(Error);
		const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
		UE_LOG(PicoRoom, Error, TEXT("RoomInviteAcceptedNotification error! ErrorCode: %d, ErrorMessage: %s"), ErrorCode, *ErrorMessage);
		RoomInviteAcceptedNotify.Broadcast(bIsError, ErrorCode, ErrorMessage, FString());
	}
	else
	{
		UE_LOG(PicoRoom, Log, TEXT("RoomInviteAcceptedNotification success!"));
		const FString RoomID = UTF8_TO_TCHAR(ppf_Message_GetString(Message));
		RoomInviteAcceptedNotify.Broadcast(bIsError, 0, FString(), RoomID);
	}
}

FPicoRoomInterface::~FPicoRoomInterface()
{
    if (RoomUpdateHandle.IsValid())
    {
		RoomUpdateHandle.Reset();
    }

    if (RoomUpdateOwnerHandle.IsValid())
    {
		RoomUpdateOwnerHandle.Reset();
    }

    if (RoomJoinHandle.IsValid())
    {
		RoomJoinHandle.Reset();
    }

    if (RoomLeaveHandle.IsValid())
    {
		RoomLeaveHandle.Reset();
    }

    if (RoomInviteAcceptedHandle.IsValid())
    {
		RoomInviteAcceptedHandle.Reset();
    }
}
bool FPicoRoomInterface::LaunchInvitableUserFlow(const FString& RoomID, FRoomLaunchInvitableUserFlow OnLaunchInvitableUserFlowCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::LaunchInvitableUserFlow"));
	ppfRequest RequestId = ppf_Room_LaunchInvitableUserFlow(GetppfID(RoomID));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnLaunchInvitableUserFlowCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const ppfErrorHandle Error = ppf_Message_GetError(Message);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				const int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("LaunchInvitableUserFlow return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->LaunchInvitableUserFlowDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				OnLaunchInvitableUserFlowCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("LaunchInvitableUserFlow Successfully"));
				this->LaunchInvitableUserFlowDelegate.ExecuteIfBound(false, 0, FString());
				OnLaunchInvitableUserFlowCallback.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}
bool FPicoRoomInterface::UpdateDataStore(const FString& RoomID, const TMap<FString, FString>& Data, FRoomUpdateDataStore OnUpdateDataStoreCallback)
{
    UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::UpdateDataStore"));

	ppfKeyValuePairArray KeyValuePairArray = ppf_KeyValuePairArray_Create(Data.Num());
	unsigned n = 0;
	for (auto Iter = Data.CreateConstIterator(); Iter;++ Iter)
	{
		ppfKeyValuePairHandle item = ppf_KeyValuePairArray_GetElement(KeyValuePairArray, n);
		ppf_KeyValuePair_SetKey(item, TCHAR_TO_UTF8(*Iter.Key()));
		ppf_KeyValuePair_SetStringValue(item, TCHAR_TO_UTF8(*Iter.Value()));
		n++;
	}
	
    ppfRequest RequestId = ppf_Room_UpdateDataStore(GetppfID(RoomID), KeyValuePairArray, n);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [OnUpdateDataStoreCallback, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
            	int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoRoom, Log, TEXT("UpdateDataStore return failed: %d, %s"), ErrorCode, *ErrorMessage);
                this->UpdateDataStoreDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
                OnUpdateDataStoreCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoRoom, Log, TEXT("UpdateDataStore Successfully"));
                UPico_Room* Pico_Room = NewObject<UPico_Room>();
                Pico_Room->InitParams(ppf_Message_GetRoom(Message));
                this->UpdateDataStoreDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
                OnUpdateDataStoreCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
            }
        }));
    return true;
}
bool FPicoRoomInterface::CreateAndJoinPrivate2(ERoomJoinPolicy JoinPolicy, uint32 MaxUsers, FPicoRoomOptions RoomOptions, FRoomCreateAndJoinPrivate2 OnCreateAndJoinPrivate2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::CreateAndJoinPrivate2"));
	ppfRequest RequestId = ppf_Room_CreateAndJoinPrivate2(GetppfRoomJoinPolicy(JoinPolicy), MaxUsers, GetppfRoomOptions(RoomOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnCreateAndJoinPrivate2Callback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("CreateAndJoinPrivate2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->CreateAndJoinPrivate2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnCreateAndJoinPrivate2Callback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("CreateAndJoinPrivate2 Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->CreateAndJoinPrivate2Delegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnCreateAndJoinPrivate2Callback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::Get(const FString& RoomID, FRoomGet OnGetCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::Get"));
	ppfRequest RequestId = ppf_Room_Get(GetppfID(RoomID));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("Get return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("Get Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->GetDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnGetCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::GetCurrent(FRoomGetCurrent OnGetCurrentCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::GetCurrent"));
	ppfRequest RequestId = ppf_Room_GetCurrent();
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetCurrentCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("GetCurrent return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetCurrentDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetCurrentCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("GetCurrent Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->GetCurrentDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnGetCurrentCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::GetCurrentForUser(const FString& UserId, FRoomGetCurrentForUser OnGetCurrentForUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::GetCurrentForUser"));
	ppfRequest RequestId = ppf_Room_GetCurrentForUser(TCHAR_TO_UTF8(*UserId));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetCurrentForUserCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("GetCurrentForUser return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetCurrentForUserDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetCurrentForUserCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("GetCurrentForUser Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->GetCurrentForUserDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnGetCurrentForUserCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}  
bool FPicoRoomInterface::GetInvitableUsers2(FPicoRoomOptions RoomOptions, FRoomGetInvitableUsers2 OnGetInvitableUsers2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::GetInvitableUsers2"));
	ppfRequest RequestId = ppf_Room_GetInvitableUsers2(GetppfRoomOptions(RoomOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetInvitableUsers2Callback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("GetInvitableUsers2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetInvitableUsers2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetInvitableUsers2Callback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("GetInvitableUsers2 Successfully"));
				UPico_UserArray* Pico_UserArray = NewObject<UPico_UserArray>();
				Pico_UserArray->InitParams(ppf_Message_GetUserArray(Message));
				this->GetInvitableUsers2Delegate.ExecuteIfBound(false, 0, FString(), Pico_UserArray);
				OnGetInvitableUsers2Callback.ExecuteIfBound(false, 0, FString(), Pico_UserArray);
			}
		}));
	return true;
}
bool FPicoRoomInterface::GetModeratedRooms(int PageIndex, int PageSize, FRoomGetModeratedRooms OnGetModeratedRoomsCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::GetModeratedRooms"));
	ppfRequest RequestId = ppf_Room_GetModeratedRooms(PageIndex, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetModeratedRoomsCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("GetModeratedRooms return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetModeratedRoomsDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetModeratedRoomsCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("GetModeratedRooms Successfully"));
				UPico_RoomArray* Pico_RoomArray = NewObject<UPico_RoomArray>();
				Pico_RoomArray->InitParams(ppf_Message_GetRoomArray(Message));
				this->GetModeratedRoomsDelegate.ExecuteIfBound(false, 0, FString(), Pico_RoomArray);
				OnGetModeratedRoomsCallback.ExecuteIfBound(false, 0, FString(), Pico_RoomArray);
			}
		}));
	return true;
}
bool FPicoRoomInterface::InviteUser(const FString& RoomID, const FString& Token, FRoomInviteUser OnInviteUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::InviteUser"));
	ppfRequest RequestId = ppf_Room_InviteUser(GetppfID(RoomID), TCHAR_TO_UTF8(*Token));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnInviteUserCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("InviteUser return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->InviteUserDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnInviteUserCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("InviteUser Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->InviteUserDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnInviteUserCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::Join2(const FString& RoomID, FPicoRoomOptions RoomOptions, FRoomJoin2 OnJoin2Callback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::Join2"));
	ppfRequest RequestId = ppf_Room_Join2(GetppfID(RoomID), GetppfRoomOptions(RoomOptions));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnJoin2Callback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("Join2 return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->Join2Delegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnJoin2Callback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("Join2 Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->Join2Delegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnJoin2Callback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::KickUser(const FString& RoomID, const FString& UserID, int KickDurationSeconds, FRoomKickUser OnKickUserCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::KickUser"));
	ppfRequest RequestId = ppf_Room_KickUser(GetppfID(RoomID), TCHAR_TO_UTF8(*UserID), KickDurationSeconds);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnKickUserCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("KickUser return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->KickUserDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnKickUserCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("KickUser Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->KickUserDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnKickUserCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::Leave(const FString& RoomID, FRoomLeave OnLeaveCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::Leave"));
	ppfRequest RequestId = ppf_Room_Leave(GetppfID(RoomID));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnLeaveCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("Leave return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->LeaveDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnLeaveCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("Leave Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->LeaveDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnLeaveCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::SetDescription(const FString& RoomID, const FString& Description, FRoomSetDescription OnSetDescriptionCallback){
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::SetDescription"));
	ppfRequest RequestId = ppf_Room_SetDescription(GetppfID(RoomID), TCHAR_TO_UTF8(*Description));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnSetDescriptionCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("SetDescription return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->SetDescriptionDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnSetDescriptionCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("SetDescription Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->SetDescriptionDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnSetDescriptionCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::UpdateMembershipLockStatus(const FString& RoomID, ERoomMembershipLockStatus MembershipLockStatus, FRoomUpdateMembershipLockStatus OnUpdateMembershipLockStatusCallback){
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::UpdateMembershipLockStatus"));
	ppfRequest RequestId = ppf_Room_UpdateMembershipLockStatus(GetppfID(RoomID), GetppfRoomMembershipLockStatus(MembershipLockStatus));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnUpdateMembershipLockStatusCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("UpdateMembershipLockStatus return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->UpdateMembershipLockStatusDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnUpdateMembershipLockStatusCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("UpdateMembershipLockStatus Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->UpdateMembershipLockStatusDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnUpdateMembershipLockStatusCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::UpdateOwner(const FString& RoomID, const FString& UserID, FRoomUpdateOwner OnUpdateOwnerCallback){
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::UpdateOwner"));
	ppfRequest RequestId = ppf_Room_UpdateOwner(GetppfID(RoomID), TCHAR_TO_UTF8(*UserID));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnUpdateOwnerCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("UpdateOwner return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->UpdateOwnerDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				OnUpdateOwnerCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("UpdateOwner Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->UpdateOwnerDelegate.ExecuteIfBound(false, 0, FString());
				OnUpdateOwnerCallback.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}
bool FPicoRoomInterface::UpdatePrivateRoomJoinPolicy(const FString& RoomID, ERoomJoinPolicy JoinPolicy, FRoomUpdatePrivateRoomJoinPolicy OnUpdatePrivateRoomJoinPolicyCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::UpdatePrivateRoomJoinPolicy"));
	ppfRequest RequestId = ppf_Room_UpdatePrivateRoomJoinPolicy(GetppfID(RoomID), GetppfRoomJoinPolicy(JoinPolicy));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnUpdatePrivateRoomJoinPolicyCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				auto Error = ppf_Message_GetError(Message);
				FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("UpdatePrivateRoomJoinPolicy return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->UpdatePrivateRoomJoinPolicyDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnUpdatePrivateRoomJoinPolicyCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("UpdatePrivateRoomJoinPolicy Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->UpdatePrivateRoomJoinPolicyDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnUpdatePrivateRoomJoinPolicyCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}
bool FPicoRoomInterface::GetNamedRooms(int PageIndex, int PageSize, FRoomGetNamedRooms OnGetNamedRoomsCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::GetNamedRooms"));
	const ppfRequest RequestId = ppf_Room_GetNamedRooms(PageIndex, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnGetNamedRoomsCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const auto Error = ppf_Message_GetError(Message);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				const int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("GetNamedRooms return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->GetNamedRoomsDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnGetNamedRoomsCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("GetNamedRooms Successfully"));
				UPico_RoomArray* Pico_RoomArray = NewObject<UPico_RoomArray>();
				Pico_RoomArray->InitParams(ppf_Message_GetRoomArray(Message));
				this->GetNamedRoomsDelegate.ExecuteIfBound(false, 0, FString(), Pico_RoomArray);
				OnGetNamedRoomsCallback.ExecuteIfBound(false, 0, FString(), Pico_RoomArray);
			}
		}));
	return true;
}
bool FPicoRoomInterface::JoinOrCreateNamedRoom(ERoomJoinPolicy JoinPolicy, bool CreateIfNotExist, uint32 MaxUsers, FPicoRoomOptions Options, FRoomJoinOrCreateNamedRoom OnRoomJoinOrCreateNamedRoomCallback)
{
	UE_LOG(PicoRoom, Log, TEXT("FPicoRoomInterface::JoinOrCreateNamedRoom"));
	const ppfRequest RequestId = ppf_Room_JoinNamed(GetppfRoomJoinPolicy(JoinPolicy), CreateIfNotExist, MaxUsers, GetppfRoomOptions(Options));
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnRoomJoinOrCreateNamedRoomCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const auto Error = ppf_Message_GetError(Message);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				const int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoRoom, Log, TEXT("JoinOrCreateNamedRoom return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->JoinOrCreateNamedRoomDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnRoomJoinOrCreateNamedRoomCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoRoom, Log, TEXT("JoinOrCreateNamedRoom Successfully"));
				UPico_Room* Pico_Room = NewObject<UPico_Room>();
				Pico_Room->InitParams(ppf_Message_GetRoom(Message));
				this->JoinOrCreateNamedRoomDelegate.ExecuteIfBound(false, 0, FString(), Pico_Room);
				OnRoomJoinOrCreateNamedRoomCallback.ExecuteIfBound(false, 0, FString(), Pico_Room);
			}
		}));
	return true;
}



ppfRoomOptions* FPicoRoomInterface::GetppfRoomOptions(FPicoRoomOptions PicoRoomOptions)
{
	ppfRoomOptions* ppfRoomOptionsHandle = ppf_RoomOptions_Create();

	ppf_RoomOptions_SetDataStoreString(ppfRoomOptionsHandle, TCHAR_TO_UTF8(*PicoRoomOptions.DataStoreKey), TCHAR_TO_UTF8(*PicoRoomOptions.DataStoreValue));
	ppf_RoomOptions_SetExcludeRecentlyMet(ppfRoomOptionsHandle, PicoRoomOptions.bExcludeRecentlyMet);
	ppf_RoomOptions_SetMaxUserResults(ppfRoomOptionsHandle, PicoRoomOptions.MaxUserResults);
	ppf_RoomOptions_SetTurnOffUpdates(ppfRoomOptionsHandle, PicoRoomOptions.bTurnOffUpdates);
	ppf_RoomOptions_SetName(ppfRoomOptionsHandle, TCHAR_TO_UTF8(*PicoRoomOptions.RoomName));
	ppf_RoomOptions_SetPassword(ppfRoomOptionsHandle, TCHAR_TO_UTF8(*PicoRoomOptions.RoomPassword));

	ppf_RoomOptions_SetRoomId(ppfRoomOptionsHandle, GetppfID(PicoRoomOptions.RoomId));
	switch (PicoRoomOptions.Ordering)
	{
	case EUserOrdering::None:
		ppf_RoomOptions_SetOrdering(ppfRoomOptionsHandle, ppfUserOrdering_None);
		break;
	case EUserOrdering::PresenceAlphabetical:
		ppf_RoomOptions_SetOrdering(ppfRoomOptionsHandle, ppfUserOrdering_PresenceAlphabetical);
		break;
	default:
		ppf_RoomOptions_SetOrdering(ppfRoomOptionsHandle, ppfUserOrdering_None);
		break;
	}
	ppf_RoomOptions_SetRecentlyMetTimeWindow(ppfRoomOptionsHandle, static_cast<int64_t>(PicoRoomOptions.TimeWindow));
	return ppfRoomOptionsHandle;
}
ppfRoomJoinPolicy FPicoRoomInterface::GetppfRoomJoinPolicy(ERoomJoinPolicy JoinPolicy)
{
	switch (JoinPolicy)
	{
	case ERoomJoinPolicy::JoinPolicyNone:
		return ppfRoom_JoinPolicyNone;
	case ERoomJoinPolicy::JoinPolicyEveryone:
		return ppfRoom_JoinPolicyEveryone;
	case ERoomJoinPolicy::JoinPolicyFriendsOfMembers:
		return ppfRoom_JoinPolicyFriendsOfMembers;
	case ERoomJoinPolicy::JoinPolicyFriendsOfOwner:
		return ppfRoom_JoinPolicyFriendsOfOwner;
	case ERoomJoinPolicy::JoinPolicyInvitedUsers:
		return ppfRoom_JoinPolicyInvitedUsers;
	case ERoomJoinPolicy::JoinPolicyUnknown:
		return ppfRoom_JoinPolicyUnknown;
	default:
		return ppfRoom_JoinPolicyUnknown;
	}
}
ppfID FPicoRoomInterface::GetppfID(const FString& StringID)
{
	return FCString::Strtoui64(*StringID, NULL, 10);
}

ppfRoomMembershipLockStatus FPicoRoomInterface::GetppfRoomMembershipLockStatus(ERoomMembershipLockStatus RoomMembershipLockStatus)
{
	switch (RoomMembershipLockStatus)
	{
	case ERoomMembershipLockStatus::Lock:
		return ppfRoomMembershipLockStatus_Lock;
	case ERoomMembershipLockStatus::Unknown:
		return ppfRoomMembershipLockStatus_Unknown;
	case ERoomMembershipLockStatus::Unlock:
		return ppfRoomMembershipLockStatus_Unlock;
	default:
		return ppfRoomMembershipLockStatus_Unknown;
	}
}














void UPico_Room::InitParams(ppfRoomHandle InRoomHandle)
{
	UE_LOG(PicoRoom, Log, TEXT("Pico room init!"));
	DataStore = NewObject<UPico_DataStore>(this);
	DataStore->InitParams(ppf_Room_GetDataStore(InRoomHandle));
	Owner = NewObject<UPico_User>(this);
	Owner->InitParams(ppf_Room_GetOwner(InRoomHandle));
	Users = NewObject<UPico_UserArray>(this);
	Users->InitParams(ppf_Room_GetUsers(InRoomHandle));
	Description = UTF8_TO_TCHAR(ppf_Room_GetDescription(InRoomHandle));
	ID = ppf_Room_GetID(InRoomHandle);
	RoomID = FString::Printf(TEXT("%llu"), ID);
	RoomName = UTF8_TO_TCHAR(ppf_Room_GetName(InRoomHandle));
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
	PlayerNum = ppf_Room_GetPlayerNumber(InRoomHandle);
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

FString UPico_Room::GetName()
{
	return RoomName;
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

int32 UPico_Room::GetPlayerNumber()
{
	return PlayerNum;
}

ERoomType UPico_Room::GetRoomType()
{
	return RoomType;
}

FString UPico_Room::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("Room DebugString:\nID: %s\nDescription: %s\nMaxUsers: %d\nIsMembershipLocked: %s\nName: %s\nPlayerNum: %d\n")
		, *GetRoomID(), *GetDescription(), GetMaxUsers(), GetIsMembershipLocked()? TEXT("true") : TEXT("false"), *GetName(), GetPlayerNumber()));
	UEnum* const EnumRoomType = StaticEnum<ERoomType>();
	if (EnumRoomType)
	{
		Log.Append(FString::Printf(TEXT("RoomType: %s\n"), *EnumRoomType->GetDisplayNameTextByValue(static_cast<uint8>(GetRoomType())).ToString()));
	}
	UEnum* const EnumJoinability = StaticEnum<ERoomJoinabilit>();
	if (EnumJoinability)
	{
		Log.Append(FString::Printf(TEXT("Joinability: %s\n"), *EnumJoinability->GetDisplayNameTextByValue(static_cast<uint8>(GetJoinability())).ToString()));
	}
	UEnum* const EnumJoinPolicy = StaticEnum<ERoomJoinPolicy>();
	if (EnumJoinPolicy)
	{
		Log.Append(FString::Printf(TEXT("JoinPolicy: %s\n"), *EnumJoinPolicy->GetDisplayNameTextByValue(static_cast<uint8>(GetJoinPolicy())).ToString()));
	}
	UPico_DataStore* TempDataStore = GetDataStore();
	for (int i = 0; i < TempDataStore->GetNumKeys(); i++)
	{
		FString Key = TempDataStore->GetKey(i);
		Log.Append(FString::Printf(TEXT("DataStore[%d]: Key: %s, Value: %s\n"), i, *Key, *TempDataStore->GetValue(Key)));
	}
	// owner
	UPico_User* TempOwner = GetOwner();
	Log.Append(FString::Printf(TEXT("Owner ID: %s\nOwner DisplayName: %s\nOwner InviteToken: %s\n"), *TempOwner->GetID(), *TempOwner->GetDisplayName(), *TempOwner->GetInviteToken()));
	
	// user
	UPico_UserArray* TempUsers = GetUsers();
	for (int i = 0; i < TempUsers->GetSize(); i++)
	{
		UPico_User* TempUser = TempUsers->GetElement(i);
		Log.Append(FString::Printf(TEXT("Users[%d]:\nID: %s\nDisplayName: %s\nInviteToken: %s\n"), i, *TempUser->GetID(), *TempUser->GetDisplayName(), *TempUser->GetInviteToken()));
	}
	
	return Log;
}



// UPico_RoomArray
void UPico_RoomArray::InitParams(ppfRoomArrayHandle InppfRoomArrayHandle)
{
	UE_LOG(PicoRoom, Log, TEXT("UPico_RoomArray::InitParams"));
	Size = ppf_RoomArray_GetSize(InppfRoomArrayHandle);
	UE_LOG(PicoRoom, Log, TEXT("UPico_RoomArray::InitParams ppf_RoomArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_Room* ThisElement = NewObject<UPico_Room>(this);
		ThisElement->InitParams(ppf_RoomArray_GetElement(InppfRoomArrayHandle, i));
		RoomArray.Add(ThisElement);
	}
	bHasNextPage = ppf_RoomArray_HasNextPage(InppfRoomArrayHandle);
	PageIndex = ppf_RoomArray_GetPageIndex(InppfRoomArrayHandle);
	PageSize = ppf_RoomArray_GetPageSize(InppfRoomArrayHandle);
	TotalSize = ppf_RoomArray_GetTotalCount(InppfRoomArrayHandle);
}

UPico_Room* UPico_RoomArray::GetElement(int32 Index)
{
	UE_LOG(PicoRoom, Log, TEXT("UPico_RoomArray::GetElement Index: %d"), Index);
	if (RoomArray.IsValidIndex(Index))
	{
		return RoomArray[Index];
	}
	return nullptr;
}

int32 UPico_RoomArray::GetSize()
{
	return Size;
}

int32 UPico_RoomArray::GetTotalSize()
{
	return TotalSize;
}

bool UPico_RoomArray::HasNextPage()
{
	return bHasNextPage;
}

int32 UPico_RoomArray::GetPageIndex()
{
	return PageIndex;
}

int32 UPico_RoomArray::GetPageSize()
{
	return PageSize;
}

FString UPico_RoomArray::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("RoomArray DebugString:\nTotalSize: %d\nSize: %d\nPageIndex: %d\nPageSize: %d\nbHasNextPage: %s\n"), GetTotalSize(), GetSize(), GetPageIndex(), GetPageSize(), bHasNextPage?TEXT("true"):TEXT("false")));
	for (int32 i = 0; i < Size; i++)
	{
		Log.Append(FString::Printf(TEXT("%d:\n%s\n"), i, *RoomArray[i]->GetDebugString()));
	}
	
	return Log;
}