// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "Pico_Notification.h"
#include "OnlineSubsystemUtils.h"

DEFINE_LOG_CATEGORY(PicoNotification);

void UOnlinePicoNotificationFunction::GetRoomInviteNotifications(UObject* WorldContextObject, int PageIdx, int PageSize, FNotificationRoomInviteNotifications OnRoomInviteNotificationsCallback)
{
	UE_LOG(PicoNotification, Log, TEXT("UOnlinePicoNotificationFunction::GetRoomInviteNotifications"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoNotificationInterface())
	{
		Subsystem->GetPicoNotificationInterface()->GetRoomInviteNotifications(PageIdx, PageSize, OnRoomInviteNotificationsCallback);
	}
	else
	{
		UE_LOG(PicoNotification, Log, TEXT("GetRoomInviteNotifications Failed, PicoNotificationInterface Not Vailed!"));
		OnRoomInviteNotificationsCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoNotificationInterface Not Vailed")), nullptr);
	}
}

void UOnlinePicoNotificationFunction::MarkAsRead(UObject* WorldContextObject, const FString& NotificationID, FNotificationMarkAsRead OnMarkAsReadCallback)
{
	UE_LOG(PicoNotification, Log, TEXT("UOnlinePicoNotificationFunction::MarkAsRead"));
	FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
	if (Subsystem && Subsystem->GetPicoNotificationInterface())
	{
		Subsystem->GetPicoNotificationInterface()->MarkAsRead(NotificationID, OnMarkAsReadCallback);
	}
	else
	{
		UE_LOG(PicoNotification, Log, TEXT("MarkAsRead Failed, PicoNotificationInterface Not Vailed!"));
		OnMarkAsReadCallback.ExecuteIfBound(true, -1, FString(TEXT("PicoNotificationInterface Not Vailed")));
	}
}





FPicoNotificationInterface::FPicoNotificationInterface(FOnlineSubsystemPico& InSubsystem) : PicoSubsystem(InSubsystem)
{
	
}

FPicoNotificationInterface::~FPicoNotificationInterface()
{
	
}

bool FPicoNotificationInterface::GetRoomInviteNotifications(int PageIdx, int PageSize, FNotificationRoomInviteNotifications OnRoomInviteNotificationsCallback)
{
	UE_LOG(PicoNotification, Log, TEXT("FPicoNotificationInterface::GetRoomInviteNotifications"));
	ppfRequest RequestId = ppf_Notification_GetRoomInvites(PageIdx, PageSize);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnRoomInviteNotificationsCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const ppfErrorHandle Error = ppf_Message_GetError(Message);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				const int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoNotification, Log, TEXT("GetRoomInviteNotifications return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->RoomInviteNotificationsDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
				OnRoomInviteNotificationsCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
			}
			else
			{
				UE_LOG(PicoNotification, Log, TEXT("GetRoomInviteNotifications Successfully"));
				UPico_RoomInviteNotificationArray* Pico_RoomInviteNotificationArray = NewObject<UPico_RoomInviteNotificationArray>();
				Pico_RoomInviteNotificationArray->InitParams(ppf_Message_GetRoomInviteNotificationArray(Message));
				this->RoomInviteNotificationsDelegate.ExecuteIfBound(false, 0, FString(), Pico_RoomInviteNotificationArray);
				OnRoomInviteNotificationsCallback.ExecuteIfBound(false, 0, FString(), Pico_RoomInviteNotificationArray);
			}
		}));
	return true;
}

bool FPicoNotificationInterface::MarkAsRead(const FString& NotificationID, FNotificationMarkAsRead OnMarkAsReadCallback)
{
	UE_LOG(PicoNotification, Log, TEXT("FPicoNotificationInterface::MarkAsRead"));
	ppfID ppfNotificationID = FCString::Strtoui64(*NotificationID, NULL, 10);
	ppfRequest RequestId = ppf_Notification_MarkAsRead(ppfNotificationID);
	PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
		[OnMarkAsReadCallback, this](ppfMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				const ppfErrorHandle Error = ppf_Message_GetError(Message);
				const FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
				const int ErrorCode = ppf_Error_GetCode(Error);
				UE_LOG(PicoNotification, Log, TEXT("MarkAsRead return failed: %d, %s"), ErrorCode, *ErrorMessage);
				this->MarkAsReadDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
				OnMarkAsReadCallback.ExecuteIfBound(true, ErrorCode, ErrorMessage);
			}
			else
			{
				UE_LOG(PicoNotification, Log, TEXT("MarkAsRead Successfully"));
				this->MarkAsReadDelegate.ExecuteIfBound(false, 0, FString());
				OnMarkAsReadCallback.ExecuteIfBound(false, 0, FString());
			}
		}));
	return true;
}





void UPico_RoomInviteNotification::InitParams(ppfRoomInviteNotificationHandle InRoomInviteNotificationHandle)
{
	UE_LOG(PicoNotification, Log, TEXT("UPico_RoomInviteNotification::InitParams"));
	ID = ppf_RoomInviteNotification_GetID(InRoomInviteNotificationHandle);
	RoomID = ppf_RoomInviteNotification_GetRoomID(InRoomInviteNotificationHandle);
	SenderID = ppf_RoomInviteNotification_GetSenderID(InRoomInviteNotificationHandle);
	SentTime = ppf_RoomInviteNotification_GetSentTime(InRoomInviteNotificationHandle);
}

FString UPico_RoomInviteNotification::GetID()
{
	return FString::Printf(TEXT("%llu"), ID);
}

FString UPico_RoomInviteNotification::GetRoomID()
{
	return FString::Printf(TEXT("%llu"), RoomID);
}

FString UPico_RoomInviteNotification::GetSenderID()
{
	return SenderID;
}

FString UPico_RoomInviteNotification::GetSentTime()
{
	return FString::Printf(TEXT("%llu"), SentTime);
}

FDateTime UPico_RoomInviteNotification::GetSentDateTime()
{
	FDateTime Time = FDateTime::FromUnixTimestamp(SentTime);
	return Time;
}

FString UPico_RoomInviteNotification::GetDebugString()
{
	FString Log;
	FDateTime Time = GetSentDateTime() + (FDateTime::Now() - FDateTime::UtcNow());
	Log.Append(FString::Printf(TEXT("RoomInviteNotification DebugString:\nID: %s\nRoomID: %s\nSentTime: %s\nSenderID: %s\n")
		, *GetID(), *GetRoomID(), *Time.ToString(), *GetSenderID()));
	return Log;
}






void UPico_RoomInviteNotificationArray::InitParams(ppfRoomInviteNotificationArrayHandle InRoomInviteNotificationArrayHandle)
{
	UE_LOG(PicoNotification, Log, TEXT("UPico_RoomInviteNotificationArray::InitParams"));
	Size = ppf_RoomInviteNotificationArray_GetSize(InRoomInviteNotificationArrayHandle);
	UE_LOG(PicoNotification, Log, TEXT("UPico_RoomInviteNotificationArray::InitParams ppf_RoomInviteNotificationArray_GetSize: %d"), Size);
	for (int32 i = 0; i < Size; i++)
	{
		UPico_RoomInviteNotification* ThisElement = NewObject<UPico_RoomInviteNotification>(this);
		ThisElement->InitParams(ppf_RoomInviteNotificationArray_GetElement(InRoomInviteNotificationArrayHandle, i));
		RoomInviteNotificationArray.Add(ThisElement);
	}
	bHasNextPage = ppf_RoomInviteNotificationArray_HasNextPage(InRoomInviteNotificationArrayHandle);
	TotalSize = ppf_RoomInviteNotificationArray_GetTotalCount(InRoomInviteNotificationArrayHandle);
}

UPico_RoomInviteNotification* UPico_RoomInviteNotificationArray::GetElement(int32 Index)
{
	UE_LOG(PicoNotification, Log, TEXT("UPico_RoomInviteNotificationArray::GetElement Index: %d"), Index);
	if (RoomInviteNotificationArray.IsValidIndex(Index))
	{
		return RoomInviteNotificationArray[Index];
	}
	return nullptr;
}

int32 UPico_RoomInviteNotificationArray::GetSize()
{
	return Size;
}
    
int32 UPico_RoomInviteNotificationArray::GetTotalSize()
{
	return TotalSize;
}

bool UPico_RoomInviteNotificationArray::HasNextPage()
{
	return bHasNextPage;
}
	
FString UPico_RoomInviteNotificationArray::GetDebugString()
{
	FString Log;
	Log.Append(FString::Printf(TEXT("RoomInviteNotificationArray DebugString:\nTotalSize: %d\nSize: %d\nbHasNextPage: %s\n"), GetTotalSize(), GetSize(), bHasNextPage?TEXT("true"):TEXT("false")));
	for (int32 i = 0; i < Size; i++)
	{
		Log.Append(FString::Printf(TEXT("%d:\n%s\n"), i, *RoomInviteNotificationArray[i]->GetDebugString()));
	}
	
	return Log;
}