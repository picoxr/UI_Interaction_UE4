// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlineMessageMultiTaskPico.h"
#include "OnlineSubsystemPicoPrivate.h"


void FOnlineMessageMultiTaskPico::AddNewRequest(ppfRequest RequestId)
{
	InProgressRequests.Add(RequestId);
	PicoSubsystem.AddAsyncTask(
		RequestId,
		FPicoMessageOnCompleteDelegate::CreateLambda([this, RequestId](ppfMessageHandle Message, bool bIsError)
	{
		InProgressRequests.Remove(RequestId);
		if (bIsError)
		{
			bDidAllRequestsFinishedSuccessfully = false;
		}

		if (InProgressRequests.Num() == 0)
		{
			Delegate.ExecuteIfBound();
		}
	}));
}
