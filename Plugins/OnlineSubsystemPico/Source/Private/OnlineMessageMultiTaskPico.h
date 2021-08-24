// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"

class FOnlineMessageMultiTaskPico
{
private:
	/** Requests that are waiting to be completed */
	TArray<uint64> InProgressRequests;

protected:
	bool bDidAllRequestsFinishedSuccessfully = true;

	DECLARE_DELEGATE(FFinalizeDelegate);

	FOnlineMessageMultiTaskPico::FFinalizeDelegate Delegate;

public:

	FOnlineSubsystemPico& PicoSubsystem;

	FOnlineMessageMultiTaskPico(
        FOnlineSubsystemPico& InOculusSubsystem,
        const FOnlineMessageMultiTaskPico::FFinalizeDelegate& InDelegate)
        : Delegate(InDelegate)
        , PicoSubsystem(InOculusSubsystem)
	{
	}

	void AddNewRequest(uint64 RequestId);
};
