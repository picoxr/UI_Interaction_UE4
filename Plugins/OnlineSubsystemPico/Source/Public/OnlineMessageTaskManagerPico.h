// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "OnlineMessageType.h"

DECLARE_DELEGATE_OneParam(FPicoInitOnCompleteDelegate, bool);
DECLARE_DELEGATE_TwoParams(FPicoMessageOnCompleteDelegate, FOnlineMessageHandle, bool);
DECLARE_MULTICAST_DELEGATE_TwoParams(FPicoMulticastMessageOnCompleteDelegate, FOnlineMessageHandle, bool);
class FOnlineMessageTaskManagerPico
{
	void OnReceiveMessage(FOnlineMessageHandle Message);

	/** Direct Requests waiting for a Message response */
	TMap<uint64, FPicoMessageOnCompleteDelegate> RequestDelegates;

	/** Notify Requests waiting for a Message response */
	TMap<EOnlineMessageType, FPicoMulticastMessageOnCompleteDelegate> NotifyDelegates;

public:

	static uint64 InitRequestID;

	void AddRequestDelegate(uint64 RequestId, FPicoMessageOnCompleteDelegate&& Delegate);

	FPicoMulticastMessageOnCompleteDelegate& GetNotifyDelegate(EOnlineMessageType MessageType);

	void RemoveNotifyDelegate(EOnlineMessageType MessageType, const FDelegateHandle& Delegate);

	bool Tick(float DeltaTime);
};
