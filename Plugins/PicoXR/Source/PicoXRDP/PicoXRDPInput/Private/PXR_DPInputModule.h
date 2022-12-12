//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "IPXR_DPInputModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

class FPICOXRDPInputModule : public IPICOXRDPInputModule
{
public:
	FPICOXRDPInputModule();
	virtual ~FPICOXRDPInputModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) override;
private:
	TSharedPtr<class FPICOXRDPInput> InputDevice;
};

