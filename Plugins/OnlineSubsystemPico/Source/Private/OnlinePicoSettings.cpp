// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "OnlinePicoSettings.h"

UOnlinePicoSettings::UOnlinePicoSettings(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer),
bEnablePaymentModule(false),
bIsForeign(false),
bStartTimeEntitlementCheck(false),
bEntitlementCheckSimulation(false)
{	
}

void UOnlinePicoSettings::PostInitProperties()
{
	Super::PostInitProperties();
}