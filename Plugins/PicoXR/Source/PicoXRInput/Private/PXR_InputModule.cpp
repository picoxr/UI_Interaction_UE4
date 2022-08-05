//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_InputModule.h"
#include "IPXR_HMDModule.h"
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
}

void FPicoXRInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPicoXRInputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	if (IPicoXRHMDModule::IsAvailable())
	{
		if (UPicoXRHMDFunctionLibrary::GetPicoXRHMD())
		{
			InputDevice = MakeShared<FPicoXRInput>();
			if (InputDevice)
			{
				InputDevice->SetMessageHandler(InMessageHandler);
			}
			return InputDevice;
		}
	}
	return nullptr;
}

IMPLEMENT_MODULE(FPicoXRInputModule, PicoXRInput)
#undef LOCTEXT_NAMESPACE

