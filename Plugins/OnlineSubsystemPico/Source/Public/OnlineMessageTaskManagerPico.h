// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "OnlineMessageType.h"

DECLARE_DELEGATE_OneParam(FPicoInitOnCompleteDelegate, bool);
DECLARE_DELEGATE_TwoParams(FPicoMessageOnCompleteDelegate, FOnlineMessageHandle, bool);
DECLARE_MULTICAST_DELEGATE_TwoParams(FPicoMulticastMessageOnCompleteDelegate, FOnlineMessageHandle, bool);
class FOnlineMessageTaskManagerPico
{
	void OnReceiveMessage(FOnlineMessageHandle Message);

	TMap<uint64, FPicoMessageOnCompleteDelegate> RequestDelegates;

	TMap<EOnlineMessageType, FPicoMulticastMessageOnCompleteDelegate> NotifyDelegates;

public:

	static uint64 InitRequestID;

	void AddRequestDelegate(uint64 RequestId, FPicoMessageOnCompleteDelegate&& Delegate);

	FPicoMulticastMessageOnCompleteDelegate& GetNotifyDelegate(EOnlineMessageType MessageType);

	void RemoveNotifyDelegate(EOnlineMessageType MessageType, const FDelegateHandle& Delegate);

	bool Tick(float DeltaTime);
};
