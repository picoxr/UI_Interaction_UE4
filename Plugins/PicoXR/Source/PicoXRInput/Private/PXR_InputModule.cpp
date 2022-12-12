//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_InputModule.h"
#include "IPXR_HMDModule.h"
#include "PXR_Input.h"

#define LOCTEXT_NAMESPACE "FPICOXRInputModule"

FPICOXRInputModule::FPICOXRInputModule()
	:InputDevice(nullptr)
{
}

FPICOXRInputModule::~FPICOXRInputModule()
{
}

void FPICOXRInputModule::StartupModule()
{
	IInputDeviceModule::StartupModule();
}

void FPICOXRInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPICOXRInputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	if (IPICOXRHMDModule::IsAvailable())
	{
		if (UPICOXRHMDFunctionLibrary::GetPICOXRHMD())
		{
			InputDevice = MakeShared<FPICOXRInput>();
			if (InputDevice)
			{
				InputDevice->SetMessageHandler(InMessageHandler);
			}
			return InputDevice;
		}
	}
	return nullptr;
}

IMPLEMENT_MODULE(FPICOXRInputModule, PICOXRInput)
#undef LOCTEXT_NAMESPACE

