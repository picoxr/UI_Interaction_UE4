//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_DPInputModule.h"
#include "PXR_DPHMD.h"
#include "PXR_DPInput.h"

#define LOCTEXT_NAMESPACE "FPICOXRDPInputModule"

FPICOXRDPInputModule::FPICOXRDPInputModule()
	:InputDevice(nullptr)
{
}

FPICOXRDPInputModule::~FPICOXRDPInputModule()
{
}

void FPICOXRDPInputModule::StartupModule()
{
	IInputDeviceModule::StartupModule();
	FPICOXRDPInput::RegisterKeys();
	//Add Sample Inputs
	FPICOXRDPInput::AddSampleInputs();
}

void FPICOXRDPInputModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

TSharedPtr< class IInputDevice > FPICOXRDPInputModule::CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler)
{
	InputDevice = MakeShared<FPICOXRDPInput>();
	if (InputDevice)
	{
		InputDevice->SetMessageHandler(InMessageHandler);
	}
	return InputDevice;
}

IMPLEMENT_MODULE(FPICOXRDPInputModule, PICOXRDPInput)
#undef LOCTEXT_NAMESPACE

