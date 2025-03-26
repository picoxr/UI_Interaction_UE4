//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "PxrAudioSpatializerApi.h"
#include "pxr_audio_spatializer.h"
#include "pxr_audio_spatializer_types.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include <shared_mutex>

namespace Pxr_Audio
{
	namespace Spatializer
	{
		//	Implement API for Unreal native audio engine
		class APINative final : public API
		{
		public:
			APINative() : Context(nullptr)
			{
			}

			virtual ~APINative() override = default;

			virtual const char* GetVersion(int* Major, int* Minor, int* Patch) override;
			virtual PxrAudioSpatializer_Result CreateContext(PxrAudioSpatializer_RenderingMode Mode,
			                                                 size_t FramesPerBuffer,
			                                                 size_t SampleRate) override;
			virtual PxrAudioSpatializer_Result InitializeContext() override;
			virtual PxrAudioSpatializer_Result SubmitMesh(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				PxrAudioSpatializer_AcousticsMaterial
				Material,
				int* GeometryId) override;
			virtual PxrAudioSpatializer_Result SubmitMeshAndMaterialFactor(const float* Vertices,
			                                                               int VerticesCount,
			                                                               const int* Indices,
			                                                               int IndicesCount,
			                                                               const float* AbsorptionFactor,
			                                                               float ScatteringFactor,
			                                                               float TransmissionFactor,
			                                                               int* GeometryId) override;
			virtual PxrAudioSpatializer_Result SubmitMeshWithConfig(const float* Vertices, int VerticesCount,
			                                                        const int* Indices, int IndicesCount,
			                                                        const PxrAudioSpatializer_AcousticMeshConfig*
			                                                        Config,
			                                                        int* GeometryId) override;
			virtual PxrAudioSpatializer_Result RemoveMesh(int GeometryId) override;
			virtual PxrAudioSpatializer_Result SetMeshEnable(int GeometryId, bool Enable) override;
			virtual PxrAudioSpatializer_Result SetMeshConfig(int GeometryId,
			                                                 const PxrAudioSpatializer_AcousticMeshConfig* Config,
			                                                 unsigned PropertyMask) override;
			virtual PxrAudioSpatializer_Result GetAbsorptionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor) override;
			virtual PxrAudioSpatializer_Result GetScatteringFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor) override;
			virtual PxrAudioSpatializer_Result GetTransmissionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor) override;
			virtual PxrAudioSpatializer_Result CommitScene() override;
			virtual PxrAudioSpatializer_Result AddSource(
				PxrAudioSpatializer_SourceMode SourceMode,
				const float* Position,
				int* SourceId,
				bool bIsAsync = false) override;
			virtual PxrAudioSpatializer_Result AddSourceWithOrientation(PxrAudioSpatializer_SourceMode Mode,
			                                                            const float* Position,
			                                                            const float* Front,
			                                                            const float* Up,
			                                                            float Radius,
			                                                            int* SourceId,
			                                                            bool bIsAsync = false) override;
			virtual PxrAudioSpatializer_Result AddSourceWithConfig(
				const PxrAudioSpatializer_SourceConfig* SourceConfig,
				int* SourceId,
				bool bIsAsync = false) override;
			virtual PxrAudioSpatializer_Result SetSourceConfig(const int SourceId,
			                                                   const PxrAudioSpatializer_SourceConfig* SourceConfig,
			                                                   unsigned int PropertyMask =
				                                                   PASP_SourceProperty_All) override;
			virtual PxrAudioSpatializer_Result GetSourceConfig(const int SourceId,
			                                                   PxrAudioSpatializer_SourceConfig* SourceConfig) override;
			virtual PxrAudioSpatializer_Result SetSourceAttenuationMode(int SourceId,
			                                                            PxrAudioSpatializer_SourceAttenuationMode Mode,
			                                                            DistanceAttenuationCallback
			                                                            DirectDistanceAttenuationCallback = nullptr,
			                                                            DistanceAttenuationCallback
			                                                            IndirectDistanceAttenuationCallback =
				                                                            nullptr) override;
			virtual PxrAudioSpatializer_Result SetSourceRange(
				int SourceId, float RangeMin, float RangeMax) override;
			virtual PxrAudioSpatializer_Result RemoveSource(
				int SourceId) override;
			virtual PxrAudioSpatializer_Result SubmitSourceBuffer(
				int SourceId,
				const float* InputBufferPtr,
				size_t NumFrames) override;
			virtual PxrAudioSpatializer_Result
			SubmitAmbisonicChannelBuffer(
				const float* AmbisonicChannelBuffer,
				int Order,
				int Degree,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain,
				int ParentAmbisonicOrder) override;
			virtual PxrAudioSpatializer_Result SubmitInterleavedAmbisonicBuffer(
				const float* AmbisonicBuffer,
				int AmbisonicOrder,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain) override;
			virtual PxrAudioSpatializer_Result SubmitMatrixInputBuffer(
				const float* InputBuffer,
				int InputChannelIndex) override;
			virtual PxrAudioSpatializer_Result GetInterleavedBinauralBuffer(
				float* OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) override;
			virtual PxrAudioSpatializer_Result GetPlanarBinauralBuffer(
				float* const * OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) override;
			virtual PxrAudioSpatializer_Result GetInterleavedLoudspeakersBuffer(float* OutputBufferPtr,
				size_t NumFrames) override;
			virtual PxrAudioSpatializer_Result GetPlanarLoudspeakersBuffer(float* const * OutputBufferPtr,
			                                                               size_t NumFrames) override;
			virtual PxrAudioSpatializer_Result UpdateScene() override;
			virtual PxrAudioSpatializer_Result SetDopplerEffect(
				int SourceId, int On) override;
			virtual PxrAudioSpatializer_Result SetPlaybackMode(
				PxrAudioSpatializer_PlaybackMode PlaybackMode) override;
			virtual PxrAudioSpatializer_Result SetLoudspeakerArray(
				const float* Positions, int NumLoudspeakers) override;
			virtual PxrAudioSpatializer_Result SetMappingMatrix(
				const float* Matrix,
				int NumInputChannels,
				int NumOutputChannels) override;
			virtual PxrAudioSpatializer_Result SetAmbisonicOrientation(
				const float* Front, const float* Up) override;
			virtual PxrAudioSpatializer_Result SetListenerPosition(
				const float* Position) override;
			virtual PxrAudioSpatializer_Result SetListenerOrientation(
				const float* Front, const float* Up) override;
			virtual PxrAudioSpatializer_Result SetListenerPose(
				const float* Position,
				const float* Front,
				const float* Up) override;
			virtual PxrAudioSpatializer_Result SetSourcePosition(
				int SourceId, const float* Position) override;
			virtual PxrAudioSpatializer_Result SetSourceGain(
				int SourceId, float Gain) override;
			virtual PxrAudioSpatializer_Result SetSourceSize(
				int SourceId, float VolumetricSize) override;
			virtual PxrAudioSpatializer_Result UpdateSourceMode(
				int SourceId,
				PxrAudioSpatializer_SourceMode Mode) override;
			virtual PxrAudioSpatializer_Result Destroy() override;

		private:
			PxrAudioSpatializer_Context* Context;
			std::shared_timed_mutex ContextDestructionMutex;
		};
	}
}
