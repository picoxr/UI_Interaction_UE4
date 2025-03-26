// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_HMDPrivate.h"
#include "RHICommandList.h"
#include "RenderingThread.h"

bool InGameThread()
{
	if (GIsGameThreadIdInitialized)
	{
		return FPlatformTLS::GetCurrentThreadId() == GGameThreadId;
	}
	else
	{
		return true;
	}
}


bool InRenderThread()
{
	if (GIsThreadedRendering && !GIsRenderingThreadSuspended.Load(EMemoryOrder::Relaxed))
	{
		return IsInActualRenderingThread();
	}
	else
	{
		return InGameThread();
	}
}


bool InRHIThread()
{
	if (GIsThreadedRendering && !GIsRenderingThreadSuspended.Load(EMemoryOrder::Relaxed))
	{
		if (IsRHIThreadRunning())
		{
			if (IsInRHIThread())
			{
				return true;
			}

			if (IsInActualRenderingThread())
			{
				return GetImmediateCommandList_ForRenderCommand().Bypass();
			}

			return false;
		}
		else
		{
			return IsInActualRenderingThread();
		}
	}
	else
	{
		return InGameThread();
	}
}

FString FormatToHexString(uint64 From)
{
	if (From == 0)
	{
		return TEXT("0");
	}

	FString To;

	static FString Hex = TEXT("0123456789abcdef");

	uint64 HexNumber = From;
	while (HexNumber)
	{
		int32 Index = HexNumber & 0x0f;
		To += Hex[Index];
		HexNumber >>= 4;
	}

	return To.Reverse();
}

bool ConvertPose_Private(const FPose& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
{
	OutPose.Orientation = BaseOrientation.Inverse() * InPose.Orientation;
	OutPose.Orientation.Normalize();

	OutPose.Position = (InPose.Position - BaseOffset) * WorldToMetersScale;
	OutPose.Position = BaseOrientation.Inverse().RotateVector(OutPose.Position);

	return true;
}

bool ConvertPose_Private(const PxrPosef& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
{
	return ConvertPose_Private(FPose(ToFQuat(InPose.orientation), ToFVector(InPose.position)), OutPose, BaseOrientation, BaseOffset, WorldToMetersScale);
}

bool ConvertPose_Private(const FPose& InPose, PxrPosef& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
{
	OutPose.orientation = ToPxrQuatf(BaseOrientation * InPose.Orientation);
	OutPose.position = ToPxrVector3f(BaseOrientation.RotateVector(InPose.Position) / WorldToMetersScale + BaseOffset);
	return true;
}

bool IsPICOHMDConnected()
{
#if PLATFORM_WINDOWS && WITH_EDITOR
	return false;
#endif
	return true;
}

bool GetSourceNameForHandEnum(const EControllerHand& Hand, FName& OutSource)
{
	static TMap<EControllerHand, FName> EControllerHandToMotionSourceMap;
	if (EControllerHandToMotionSourceMap.Num() == 0)
	{
		EControllerHandToMotionSourceMap.Reserve(18);

		EControllerHandToMotionSourceMap.Add(EControllerHand::Left, IMotionController::LeftHandSourceId);
		EControllerHandToMotionSourceMap.Add(EControllerHand::Right, IMotionController::RightHandSourceId);
		EControllerHandToMotionSourceMap.Add(EControllerHand::AnyHand, TEXT("AnyHand"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::Pad, TEXT("Pad"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::ExternalCamera, TEXT("ExternalCamera"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::Gun, TEXT("Gun"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::HMD, TEXT("HMD"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::Chest, TEXT("Chest"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::LeftShoulder, TEXT("LeftShoulder"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::RightShoulder, TEXT("RightShoulder"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::LeftElbow, TEXT("LeftElbow"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::RightElbow, TEXT("RightElbow"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::Waist, TEXT("Waist"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::LeftKnee, TEXT("LeftKnee"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::RightKnee, TEXT("RightKnee"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::LeftFoot, TEXT("LeftFoot"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::RightFoot, TEXT("RightFoot"));
		EControllerHandToMotionSourceMap.Add(EControllerHand::Special, TEXT("Special"));
	}

	FName* FoundSource = EControllerHandToMotionSourceMap.Find(Hand);
	if (FoundSource != nullptr)
	{
		OutSource = *FoundSource;
		return true;
	}
	else
	{
		return false;
	}
}
