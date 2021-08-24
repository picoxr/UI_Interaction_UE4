// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "OnlineMessageTaskManagerPico.h"


#include "OnlinePlatformInterfacePico.h"
#include "OnlineSubsystem.h"


uint64 FOnlineMessageTaskManagerPico::InitRequestID = 0;

void FOnlineMessageTaskManagerPico::OnReceiveMessage(FOnlineMessageHandle Message)
{
	auto RequestId = Message.GetMessageID();
	bool bIsError = Message.IsError();
	auto MessageType = Message.GetMessageType();
	UE_LOG(LogTemp,Log,TEXT("OnReceiveMessage RequestId :%llu,bIsError %d,MessageType %x, "),RequestId,bIsError,MessageType);
	if (RequestId == FOnlineMessageTaskManagerPico::InitRequestID)
	{
		if (MessageType == EOnlineMessageType::Message_Achievements_verify_access_token)
		{
			uint64 InitID = 999;
			RequestDelegates[InitID].ExecuteIfBound(Message, bIsError);

			// Remove the delegate
			RequestDelegates[InitID].Unbind();
			RequestDelegates.Remove(InitID);
			return;
		}
	}
	if (RequestDelegates.Contains(RequestId))
	{
		RequestDelegates[RequestId].ExecuteIfBound(Message, bIsError);

		// Remove the delegate
		RequestDelegates[RequestId].Unbind();
		RequestDelegates.Remove(RequestId);
	}
	else
	{
		
		if (NotifyDelegates.Contains(MessageType))
		{
			if (!bIsError)
			{
				NotifyDelegates[MessageType].Broadcast(Message, bIsError);
			}
		}
		else
		{
			UE_LOG_ONLINE(Verbose, TEXT("Unhandled request id: %llu type: %d"), RequestId, MessageType);
		}
	}
	//ovr_FreeMessage(Message);
	//TODO:delete message
}

void FOnlineMessageTaskManagerPico::AddRequestDelegate(uint64 RequestId, FPicoMessageOnCompleteDelegate&& Delegate)
{
	RequestDelegates.Emplace(RequestId, Delegate);
}

FPicoMulticastMessageOnCompleteDelegate& FOnlineMessageTaskManagerPico::GetNotifyDelegate(EOnlineMessageType MessageType)
{
	return NotifyDelegates.FindOrAdd(MessageType);
}

void FOnlineMessageTaskManagerPico::RemoveNotifyDelegate(EOnlineMessageType MessageType, const FDelegateHandle& Delegate)
{
	NotifyDelegates.FindOrAdd(MessageType).Remove(Delegate);
}

bool FOnlineMessageTaskManagerPico::Tick(float DeltaTime)
{
#if PLATFORM_ANDROID
	for (;;)
	{
		auto Message = OnlinePlatformInterfacePico::PopMessage();	
		if (!Message)
		{
			break;
		}
		FOnlineMessageHandle MessageHandle;
		MessageHandle.MessageType = static_cast<EOnlineMessageType>(OnlinePlatformInterfacePico::GetMessageHandleType(Message));
		MessageHandle.bIsError = OnlinePlatformInterfacePico::GetMessageIsError(Message);
		MessageHandle.MessageID = OnlinePlatformInterfacePico::GetMessageId(Message);
		MessageHandle.JavaMessage = Message;
		if (MessageHandle.MessageID>998)
		{
			OnReceiveMessage(MessageHandle);
		}	
	}
#endif
	if (DeltaTime > 4.0f) 
	{
		UE_LOG_ONLINE(Warning, TEXT("DeltaTime was %f seconds.  Time sensitive Pico notifications may time out."), DeltaTime);
	}

	return true;
}

#if PLATFORM_ANDROID
extern "C" JNIEXPORT void  JNICALL Java_com_epicgames_ue4_GameActivity_SetInitRequestID(JNIEnv * env, jclass clazz, jlong RequestID)
{
	FOnlineMessageTaskManagerPico::InitRequestID = (uint64)RequestID;
}
#endif
