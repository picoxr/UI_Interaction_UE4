// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "UObject/Object.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "PicoUpdateSessionCallbackProxy.generated.h"

/**
 * Exposes UpdateSession of the Platform SDK for blueprint use.
 */
UCLASS(MinimalAPI)
class UPicoUpdateSessionCallbackProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

	// Called when the session was updated successfully
	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess;

	// Called when there was an error updating the session
	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure;

	// Kick off UpdateSession check. Asynchronous-- see OnUpdateCompleteDelegate for results.
	UFUNCTION(BlueprintCallable, Category = "Pico|Session", meta = (BlueprintInternalUseOnly = "true"))
	static UPicoUpdateSessionCallbackProxy* SetSessionEnqueue(bool bShouldEnqueueInMatchmakingPool);

	/** UOnlineBlueprintCallProxyBase interface */
	virtual void Activate() override;

private:
	// Internal callback when session updates completes
	void OnUpdateCompleted(FName SessionName, bool bWasSuccessful);

	// The delegate executed by the online subsystem
	FOnUpdateSessionCompleteDelegate UpdateCompleteDelegate;

	// Handles to the registered delegates above
	FDelegateHandle UpdateCompleteDelegateHandle;

	bool bShouldEnqueueInMatchmakingPool;

};
