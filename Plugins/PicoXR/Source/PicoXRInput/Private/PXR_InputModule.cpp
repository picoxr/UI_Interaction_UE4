// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_InputModule.h"
#include "IPXR_HMDModule.h"
#include "PXR_Input.h"
#include "Interfaces/IPluginManager.h"

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
	FPICOXRInput::PreInit();
}

void FPICOXRInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPICOXRInputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	if (IPICOXRHMDModule::IsAvailable())
	{
		if (FPICOXRHMDModule::Get().PreInit())
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

