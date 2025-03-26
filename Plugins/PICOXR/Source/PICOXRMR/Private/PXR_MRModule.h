// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "IPXR_MRModule.h"
#include "PXR_HMD.h"

#define LOCTEXT_NAMESPACE "PICOMRModule"

class FPICOXRMRModule : public IPICOXRMRModule
{
public:

	FPICOXRMRModule();
	~FPICOXRMRModule();

	static inline FPICOXRMRModule& Get()
	{
		return FModuleManager::GetModuleChecked<FPICOXRMRModule>("PICOXRMR");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

	FPICOXRHMD* PICOXRHMD;
};

#undef LOCTEXT_NAMESPACE