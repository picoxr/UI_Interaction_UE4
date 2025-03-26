// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "UObject/Object.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "PicoCreateSessionCallbackProxy.generated.h"

/**
 * Exposes CreateSession of the Platform SDK for blueprint use.
 */
UCLASS(MinimalAPI)
class UPicoCreateSessionCallbackProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

	// Called when the session was created successfully
	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess;

	// Called when there was an error creating the session
	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure;

	// Kick off CreateSession check. Asynchronous-- see OnCreateSessionCompleteDelegate for results.
	UFUNCTION(BlueprintCallable, Category = "Pico|Session", meta = (BlueprintInternalUseOnly = "true"))
	static UPicoCreateSessionCallbackProxy* CreateSession(int32 PublicConnections, FString PicoMatchmakingPool);

	/** UOnlineBlueprintCallProxyBase interface */
	virtual void Activate() override;

private:
	// Internal callback when session creation completes, calls StartSession
	void OnCreateCompleted(FName SessionName, bool bWasSuccessful);

	// Internal callback when session starts completes
	void OnStartCompleted(FName SessionName, bool bWasSuccessful);

	// The delegate executed by the online subsystem
	FOnCreateSessionCompleteDelegate CreateCompleteDelegate;

	// The delegate executed by the online subsystem
	FOnStartSessionCompleteDelegate StartCompleteDelegate;

	// Handles to the registered delegates above
	FDelegateHandle CreateCompleteDelegateHandle;
	FDelegateHandle StartCompleteDelegateHandle;

	// Number of public connections
	int NumPublicConnections;

	// Optional: if this session should be put in a matchmaking pool
	FString PicoPool;

};
