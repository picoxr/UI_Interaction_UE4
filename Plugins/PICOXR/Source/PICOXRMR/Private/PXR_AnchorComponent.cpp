// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_AnchorComponent.h"
#include "PXR_ProviderManager.h"

UPICOAnchorComponent::UPICOAnchorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AnchorHandle = 0;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
}

void UPICOAnchorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPICOAnchorComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsAnchorValid()&&IsValid(GetOwner()) && IsValid(GetWorld()))
	{
		EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
		PXR_AnchorProvider::GetInstance()->UpdateAnchor(this,OutResult);
		PXR_LOGV(PxrMR, "UpdateAnchor Result:%d", OutResult);
	}
}

void UPICOAnchorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (IsAnchorValid())
	{
		if(FPICOProviderManager::ShouldUseLegacyMR())
		{
			PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandleLegacy(AnchorHandle);
		}
		else
		{
			EPICOResult OutResult=EPICOResult::PXR_Error_Unknow;
			PXR_AnchorProvider::GetInstance()->DestroyAnchorByHandle(AnchorHandle,OutResult);
			PXR_LOGV(PxrMR, "DestroyAnchorByHandle Result:%d", OutResult);
		}
		ResetAnchorHandle();
	}
}

void UPICOAnchorComponent::ResetAnchorHandle()
{
	AnchorHandle.Reset();
}
