//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "pxr_audio_spatializer_types.h"
#include "PicoSpatialAudioEnums.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPicoSpatialAudio, Display, All);

DECLARE_STATS_GROUP(TEXT("PicoSpatialAudio"), STATGROUP_PicoSpatialAudio, STATCAT_Advanced)

#define PXR_AUDIO_CHECK_RESULT(Result) if ((Result) != PASP_SUCCESS) return (Result);

namespace Pxr_Audio
{
	namespace Spatializer
	{
		void ConvertToPicoSpatialAudioCoordinates(const FVector& VectorUnrealCoordinate, float* VectorPicoCoordinate);
		void ConvertToPicoSpatialAudioCoordinates(const Audio::FChannelPositionInfo& PolarUnrealCoordinate,
		                                          float* CartesianPicoCoordinate);
		void ConvertToPicoSpatialAudioCoordinates(const FTransform& TransformUnrealCoordinate,
		                                          float TransformPicoCoordinate[16]);
		PxrAudioSpatializer_RenderingMode ConvertToInternalRenderingMode(
			EPxrAudioSpatializer_RenderingMode RenderingModeUe);
		void InterleavedToPlannerBuffer(const Audio::AlignedFloatBuffer& InterleavedBuffer,
		                                TArray<Audio::AlignedFloatBuffer>& PlannerBuffers);


		float DB2Mag(float DB);

		int32 ChannelCount2AmbisonicOrder(int32 InNumChannel);

		inline void ZeroOutAudioBuffer(Audio::AlignedFloatBuffer& buffer)
		{
			const int32 Size = buffer.Num();
			buffer.Reset();
			buffer.SetNumZeroed(Size);
		}
	}
}
