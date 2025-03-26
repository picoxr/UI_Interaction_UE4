// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineDelegateMacros.h"
#include "OnlineMessageTaskManagerPico.h"
#include "OnlineSubsystemPicoPackage.h"

/**
 *
 */
class FOnlineMessageMultiTaskPico
{
private:
	/** Requests that are waiting to be completed */
	TArray<ppfRequest> InProgressRequests;

protected:
	bool bDidAllRequestsFinishedSuccessfully = true;

	DECLARE_DELEGATE(FFinalizeDelegate);

	FOnlineMessageMultiTaskPico::FFinalizeDelegate Delegate;

PACKAGE_SCOPE:
	FOnlineSubsystemPico& PicoSubsystem;

	FOnlineMessageMultiTaskPico(
		FOnlineSubsystemPico& InPicoSubsystem,
		const FOnlineMessageMultiTaskPico::FFinalizeDelegate& InDelegate)
		: Delegate(InDelegate)
		, PicoSubsystem(InPicoSubsystem)
	{
	}

	void AddNewRequest(ppfRequest RequestId);
};
