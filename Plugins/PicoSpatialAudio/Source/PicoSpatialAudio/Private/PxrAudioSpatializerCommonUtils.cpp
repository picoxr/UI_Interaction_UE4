//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PxrAudioSpatializerCommonUtils.h"

DEFINE_LOG_CATEGORY(LogPicoSpatialAudio);

namespace Pxr_Audio
{
	namespace Spatializer
	{
		void ConvertToPicoSpatialAudioCoordinates(const FVector& VectorUnrealCoordinate, float* VectorPicoCoordinate)
		{
			//	Unreal: Right:Y+, Up:Z+, Front:X+
			//	Pico:	X-: Right, Y+: Up, Z+: Front

			//	Pico.X
			VectorPicoCoordinate[0] = VectorUnrealCoordinate.Y / 100.f;
			//	Pico.Y
			VectorPicoCoordinate[1] = VectorUnrealCoordinate.Z / 100.f;
			//	Pico.Z
			VectorPicoCoordinate[2] = VectorUnrealCoordinate.X / -100.f;
		}

		void ConvertToPicoSpatialAudioCoordinates(const Audio::FChannelPositionInfo& PolarUnrealCoordinate,
		                                          float* CartesianPicoCoordinate)
		{
			CartesianPicoCoordinate[0] = 100.0f * PolarUnrealCoordinate.Radius *
				FMath::Sin(PolarUnrealCoordinate.Azimuth) * FMath::Cos(PolarUnrealCoordinate.Elevation);
			CartesianPicoCoordinate[1] = 100.0f * PolarUnrealCoordinate.Radius *
				FMath::Sin(PolarUnrealCoordinate.Azimuth) * FMath::Sin(PolarUnrealCoordinate.Elevation);
			CartesianPicoCoordinate[2] = 100.0f * PolarUnrealCoordinate.Radius * FMath::Cos(
				PolarUnrealCoordinate.Azimuth);
		}

		void ConvertToPicoSpatialAudioCoordinates(const FTransform& TransformUnrealCoordinate,
		                                          float TransformPicoCoordinate[16])
		{
			// UE:	 x:forward, y:right, z:up
			// Pico:  x:right,   y:up,	z:backward
			const FVector Right = TransformUnrealCoordinate.GetScaledAxis(EAxis::Y);
			const FVector Up = TransformUnrealCoordinate.GetScaledAxis(EAxis::Z);
			const FVector Backward = -TransformUnrealCoordinate.GetScaledAxis(EAxis::X);
			const FVector Position = TransformUnrealCoordinate.GetLocation() * 0.01f;

			//	Col 0
			TransformPicoCoordinate[0] = Right.Y;
			TransformPicoCoordinate[1] = Right.Z;
			TransformPicoCoordinate[2] = -Right.X;
			TransformPicoCoordinate[3] = 0.0f;

			//	Col 1
			TransformPicoCoordinate[4] = Up.Y;
			TransformPicoCoordinate[5] = Up.Z;
			TransformPicoCoordinate[6] = -Up.X;
			TransformPicoCoordinate[7] = 0.0f;

			//	Col 2
			TransformPicoCoordinate[8] = Backward.Y;
			TransformPicoCoordinate[9] = Backward.Z;
			TransformPicoCoordinate[10] = -Backward.X;
			TransformPicoCoordinate[11] = 0.0f;

			//	Col 3
			TransformPicoCoordinate[12] = Position.Y;
			TransformPicoCoordinate[13] = Position.Z;
			TransformPicoCoordinate[14] = -Position.X;
			TransformPicoCoordinate[15] = 1.0f;
		}

		PxrAudioSpatializer_RenderingMode ConvertToInternalRenderingMode(
			const EPxrAudioSpatializer_RenderingMode RenderingModeUe)
		{
			switch (RenderingModeUe)
			{
			case EPxrAudioSpatializer_RenderingMode::Low_Quality:
				return PASP_LOW_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::Medium_Quality:
				return PASP_MEDIUM_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::High_Quality:
				return PASP_HIGH_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order:
				return PASP_AMBISONIC_FIRST_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order:
				return PASP_AMBISONIC_SECOND_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order:
				return PASP_AMBISONIC_THIRD_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order:
				return PASP_AMBISONIC_FOURTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order:
				return PASP_AMBISONIC_FIFTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order:
				return PASP_AMBISONIC_SIXTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order:
				return PASP_AMBISONIC_SEVENTH_ORDER;
			default:
				return PASP_MEDIUM_QUALITY;
			}
		}

		void InterleavedToPlannerBuffer(const Audio::AlignedFloatBuffer& InterleavedBuffer,
		                                TArray<Audio::AlignedFloatBuffer>& PlannerBuffers)
		{
			const int32 NumChannels = PlannerBuffers.Num();
			const int32 NumFrames = InterleavedBuffer.Num() / NumChannels;

			for (int32 frame = 0; frame < NumFrames; ++frame)
			{
				for (int32 channel = 0; channel < NumChannels; ++channel)
				{
					PlannerBuffers[channel][frame] = InterleavedBuffer[frame * NumChannels + channel];
				}
			}
		}

		float DB2Mag(const float DB)
		{
			return FMath::Pow(10.0f, DB / 20.0f);
		}

		int32 ChannelCount2AmbisonicOrder(int32 InNumChannel)
		{
			return FMath::RoundToInt(FMath::Sqrt(static_cast<float>(InNumChannel))) - 1;
		}
	}
}
