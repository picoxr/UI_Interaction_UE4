// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.
#include "PXR_GameFrame.h"

FPXRGameFrame::FPXRGameFrame()
	: FrameNumber(0)
	, ViewNumber(0)
	, predictedDisplayTimeMs(0)
	, WorldToMetersScale(100)
	, ShowFlags(ESFIM_All0)
{
	Flags.Raw = 0;
	Position = FVector::ZeroVector;
	Orientation = FQuat::Identity;
	AngularVelocity = FVector::ZeroVector;
	Acceleration = FVector::ZeroVector;
	AngularAcceleration = FVector::ZeroVector;
	Velocity = FVector::ZeroVector;
}

TSharedPtr<FPXRGameFrame, ESPMode::ThreadSafe> FPXRGameFrame::CloneMyself() const
{
	TSharedPtr<FPXRGameFrame, ESPMode::ThreadSafe> NewFrame = MakeShareable(new FPXRGameFrame(*this));
	return NewFrame;
}
