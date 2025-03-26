// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#pragma once
#include "IPXR_InputModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"
#include "PXR_HMD.h"

class FPICOXRInputModule : public IPICOXRInputModule
{
public:
	FPICOXRInputModule();
	virtual ~FPICOXRInputModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
private:
	TSharedPtr<class FPICOXRInput> InputDevice;
};

