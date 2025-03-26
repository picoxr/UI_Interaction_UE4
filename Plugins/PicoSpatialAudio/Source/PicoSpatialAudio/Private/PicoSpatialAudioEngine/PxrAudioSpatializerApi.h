//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "pxr_audio_spatializer_types.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		//	API base for API implementation for various audio engine host (Unreal, Wwise, etc.) 
		class API
		{
		public:
			API() = default;
			virtual ~API() = default;

			virtual const char* GetVersion(int* Major, int* Minor, int* Patch) = 0;
			virtual PxrAudioSpatializer_Result CreateContext(PxrAudioSpatializer_RenderingMode Mode,
			                                                 size_t FramesPerBuffer,
			                                                 size_t SampleRate) = 0;
			virtual PxrAudioSpatializer_Result InitializeContext() = 0;
			virtual PxrAudioSpatializer_Result SubmitMesh(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				PxrAudioSpatializer_AcousticsMaterial
				Material,
				int* GeometryId) = 0;
			virtual PxrAudioSpatializer_Result SubmitMeshAndMaterialFactor(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				const float* AbsorptionFactor,
				float ScatteringFactor,
				float TransmissionFactor,
				int* GeometryId) = 0;
			virtual PxrAudioSpatializer_Result SubmitMeshWithConfig(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				const PxrAudioSpatializer_AcousticMeshConfig* Config,
				int* GeometryId) = 0;
			virtual PxrAudioSpatializer_Result RemoveMesh(int GeometryId) = 0;
			virtual PxrAudioSpatializer_Result SetMeshEnable(int GeometryId, bool Enable) = 0;
			virtual PxrAudioSpatializer_Result
			SetMeshConfig(int GeometryId,
			              const PxrAudioSpatializer_AcousticMeshConfig* Config,
			              unsigned int PropertyMask = PASP_MeshProperty_All) = 0;
			virtual PxrAudioSpatializer_Result GetAbsorptionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor) = 0;
			virtual PxrAudioSpatializer_Result GetScatteringFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor) = 0;
			virtual PxrAudioSpatializer_Result GetTransmissionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor) = 0;
			virtual PxrAudioSpatializer_Result CommitScene() = 0;
			virtual PxrAudioSpatializer_Result AddSource(
				PxrAudioSpatializer_SourceMode SourceMode,
				const float* Position,
				int* SourceId,
				bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result AddSourceWithOrientation(
				PxrAudioSpatializer_SourceMode Mode,
				const float* Position,
				const float* Front,
				const float* Up,
				float Radius,
				int* SourceId,
				bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result AddSourceWithConfig(
				const PxrAudioSpatializer_SourceConfig* SourceConfig,
				int* SourceId,
				bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result SetSourceConfig(const int SourceId,
			                                                   const PxrAudioSpatializer_SourceConfig* SourceConfig,
			                                                   unsigned int PropertyMask = PASP_SourceProperty_All) = 0;
			virtual PxrAudioSpatializer_Result GetSourceConfig(const int source_id,
			                                                   PxrAudioSpatializer_SourceConfig* source_config) = 0;
			virtual PxrAudioSpatializer_Result SetSourceAttenuationMode(
				int SourceId,
				PxrAudioSpatializer_SourceAttenuationMode Mode,
				DistanceAttenuationCallback DirectDistanceAttenuationCallback = nullptr,
				DistanceAttenuationCallback IndirectDistanceAttenuationCallback = nullptr) = 0;
			virtual PxrAudioSpatializer_Result SetSourceRange(
				int SourceId, float RangeMin, float RangeMax) = 0;
			virtual PxrAudioSpatializer_Result RemoveSource(
				int SourceId) = 0;
			virtual PxrAudioSpatializer_Result SubmitSourceBuffer(
				int SourceId,
				const float* InputBufferPtr,
				size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result
			SubmitAmbisonicChannelBuffer(
				const float* AmbisonicChannelBuffer,
				int Order,
				int Degree,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain,
				int ParentAmbisonicOrder) = 0;
			virtual PxrAudioSpatializer_Result SubmitInterleavedAmbisonicBuffer(

				const float* AmbisonicBuffer,
				int AmbisonicOrder,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain) = 0;
			virtual PxrAudioSpatializer_Result SubmitMatrixInputBuffer(
				const float* InputBuffer,
				int InputChannelIndex) = 0;
			virtual PxrAudioSpatializer_Result GetInterleavedBinauralBuffer(

				float* OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) = 0;
			virtual PxrAudioSpatializer_Result GetPlanarBinauralBuffer(
				float* const * OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) = 0;
			virtual PxrAudioSpatializer_Result GetInterleavedLoudspeakersBuffer(

				float* OutputBufferPtr,
				size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result GetPlanarLoudspeakersBuffer(

				float* const * OutputBufferPtr,
				size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result UpdateScene() = 0;
			virtual PxrAudioSpatializer_Result SetDopplerEffect(
				int SourceId, int On) = 0;
			virtual PxrAudioSpatializer_Result SetPlaybackMode(
				PxrAudioSpatializer_PlaybackMode PlaybackMode) = 0;
			virtual PxrAudioSpatializer_Result SetLoudspeakerArray(
				const float* Positions, int NumLoudspeakers) = 0;
			virtual PxrAudioSpatializer_Result SetMappingMatrix(
				const float* Matrix,
				int NumInputChannels,
				int NumOutputChannels) = 0;
			virtual PxrAudioSpatializer_Result SetAmbisonicOrientation(
				const float* Front, const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetListenerPosition(
				const float* Position) = 0;
			virtual PxrAudioSpatializer_Result SetListenerOrientation(
				const float* Front, const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetListenerPose(
				const float* Position,
				const float* Front,
				const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetSourcePosition(
				int SourceId, const float* Position) = 0;
			virtual PxrAudioSpatializer_Result SetSourceGain(
				int SourceId, float Gain) = 0;
			virtual PxrAudioSpatializer_Result SetSourceSize(
				int SourceId, float VolumetricSize) = 0;
			virtual PxrAudioSpatializer_Result UpdateSourceMode(
				int SourceId,
				PxrAudioSpatializer_SourceMode Mode) = 0;
			virtual PxrAudioSpatializer_Result Destroy() = 0;
		};
	}
}
