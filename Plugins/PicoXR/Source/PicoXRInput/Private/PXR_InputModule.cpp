// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

#include "PXR_InputModule.h"
#include "PXR_Input.h"

#define LOCTEXT_NAMESPACE "FPicoXRInputModule"

FPicoXRInputModule::FPicoXRInputModule()
	:InputDevice(nullptr)
{
}

FPicoXRInputModule::~FPicoXRInputModule()
{
}

void FPicoXRInputModule::StartupModule()
{
	IInputDeviceModule::StartupModule();
	InputDevice = MakeShared<FPicoXRInput>();
}

void FPicoXRInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPicoXRInputModule::CreateInputDevice( const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler )
{
	if (InputDevice)
	{
		InputDevice->SetMessageHandler(InMessageHandler);
	}	
	return InputDevice;
}

IMPLEMENT_MODULE(FPicoXRInputModule, PicoXRInput)
#undef LOCTEXT_NAMESPACE

