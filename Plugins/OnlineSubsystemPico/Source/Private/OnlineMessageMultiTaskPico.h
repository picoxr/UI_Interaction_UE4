// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"

class FOnlineMessageMultiTaskPico
{
private:

	TArray<uint64> InProgressRequests;

protected:
	bool bDidAllRequestsFinishedSuccessfully = true;

	DECLARE_DELEGATE(FFinalizeDelegate);

	FOnlineMessageMultiTaskPico::FFinalizeDelegate Delegate;

public:

	FOnlineSubsystemPico& PicoSubsystem;

	FOnlineMessageMultiTaskPico(FOnlineSubsystemPico& InPicoSubsystem,const FOnlineMessageMultiTaskPico::FFinalizeDelegate& InDelegate)
       : Delegate(InDelegate), 
		 PicoSubsystem(InPicoSubsystem)
	{
	}

	void AddNewRequest(uint64 RequestId);
};
