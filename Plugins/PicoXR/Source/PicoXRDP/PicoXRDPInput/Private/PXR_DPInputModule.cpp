//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_DPInputModule.h"
#include "PXR_DPHMD.h"
#include "PXR_DPInput.h"

#define LOCTEXT_NAMESPACE "FPicoXRDPInputModule"

FPicoXRDPInputModule::FPicoXRDPInputModule()
	:InputDevice(nullptr)
{
}

FPicoXRDPInputModule::~FPicoXRDPInputModule()
{
}

void FPicoXRDPInputModule::StartupModule()
{
	IInputDeviceModule::StartupModule();
	FPicoXRDPInput::RegisterKeys();
}

void FPicoXRDPInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPicoXRDPInputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	InputDevice = MakeShared<FPicoXRDPInput>();
	if (InputDevice)
	{
		InputDevice->SetMessageHandler(InMessageHandler);
	}
	return InputDevice;
}

IMPLEMENT_MODULE(FPicoXRDPInputModule, PicoXRDPInput)
#undef LOCTEXT_NAMESPACE

