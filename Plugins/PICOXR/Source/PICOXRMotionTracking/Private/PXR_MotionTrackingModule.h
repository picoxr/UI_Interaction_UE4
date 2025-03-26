// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once
#include "IPXR_MotionTrackingModule.h"
#include "PXR_MotionTracking.h"

class FPICOXRMotionTrackingModule : public IPICOXRMotionTrackingModule
{
public:
	FPICOXRMotionTrackingModule();

	static inline FPICOXRMotionTrackingModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FPICOXRMotionTrackingModule>("PICOXRMotionTracking");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

