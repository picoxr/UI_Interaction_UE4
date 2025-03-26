//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "pxr_audio_spatializer_types.h"
#include "PicoSpatialAudioEngine/PxrAudioSpatializerApiNative.h"
#include "PxrAudioSpatializerCommonUtils.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FContextSingleton
		{
		public:
			FContextSingleton()
				: Api(nullptr)
			{
			}

			static PxrAudioSpatializer_Result Init(PxrAudioSpatializer_RenderingMode Quality, size_t FramesPerBuffer,
			                                       size_t SampleRate);
			static bool IsInitialized();
			static PxrAudioSpatializer_Result Destroy();
			static FContextSingleton* GetInstance();

			//	Singleton Access of API functions
			const char* GetVersion(int* Major, int* Minor, int* Patch) const;
			PxrAudioSpatializer_Result SubmitMesh(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				PxrAudioSpatializer_AcousticsMaterial
				Material,
				int* GeometryId) const;
			PxrAudioSpatializer_Result SubmitMeshAndMaterialFactor(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				const float* AbsorptionFactor,
				float ScatteringFactor,
				float TransmissionFactor,
				int* GeometryId) const;
			PxrAudioSpatializer_Result SubmitMeshWithConfig(
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				const PxrAudioSpatializer_AcousticMeshConfig* Config,
				int* GeometryId) const;
			PxrAudioSpatializer_Result RemoveMesh(int GeometryId) const;
			PxrAudioSpatializer_Result SetMeshEnable(int GeometryId, bool Enable) const;
			PxrAudioSpatializer_Result
			SetMeshConfig(int GeometryId,
			              const PxrAudioSpatializer_AcousticMeshConfig* Config,
			              unsigned int PropertyMask = PASP_MeshProperty_All) const;
			PxrAudioSpatializer_Result GetAbsorptionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor) const;
			PxrAudioSpatializer_Result GetScatteringFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor) const;
			PxrAudioSpatializer_Result GetTransmissionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor) const;
			PxrAudioSpatializer_Result CommitScene() const;
			PxrAudioSpatializer_Result AddSource(
				PxrAudioSpatializer_SourceMode SourceMode,
				const float* Position,
				int* SourceId,
				bool bIsAsync = false) const;
			PxrAudioSpatializer_Result AddSourceWithOrientation(

				PxrAudioSpatializer_SourceMode Mode,
				const float* Position,
				const float* Front,
				const float* Up,
				float Radius,
				int* SourceId,
				bool bIsAsync = false) const;
			PxrAudioSpatializer_Result AddSourceWithConfig(
				const PxrAudioSpatializer_SourceConfig* SourceConfig,
				int* SourceId,
				bool bIsAsync = false) const;
			PxrAudioSpatializer_Result SetSourceConfig(const int SourceId,
			                                           const PxrAudioSpatializer_SourceConfig* SourceConfig,
			                                           unsigned PropertyMask = PASP_SourceProperty_All) const;
			PxrAudioSpatializer_Result GetSourceConfig(const int SourceId,
			                                           PxrAudioSpatializer_SourceConfig* SourceConfig) const;
			PxrAudioSpatializer_Result SetSourceAttenuationMode(

				int SourceId,
				PxrAudioSpatializer_SourceAttenuationMode Mode,
				DistanceAttenuationCallback DirectDistanceAttenuationCallback = nullptr,
				DistanceAttenuationCallback IndirectDistanceAttenuationCallback = nullptr) const;
			PxrAudioSpatializer_Result SetSourceRange(
				int SourceId, float RangeMin, float RangeMax) const;
			PxrAudioSpatializer_Result RemoveSource(
				int SourceId) const;
			PxrAudioSpatializer_Result SubmitSourceBuffer(
				int SourceId,
				const float* InputBufferPtr,
				size_t NumFrames) const;
			PxrAudioSpatializer_Result
			SubmitAmbisonicChannelBuffer(
				const float* AmbisonicChannelBuffer,
				int Order,
				int Degree,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain,
				int ParentAmbisonicOrder) const;
			PxrAudioSpatializer_Result SubmitInterleavedAmbisonicBuffer(

				const float* AmbisonicBuffer,
				int AmbisonicOrder,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain) const;
			PxrAudioSpatializer_Result SubmitMatrixInputBuffer(
				const float* InputBuffer,
				int InputChannelIndex) const;
			PxrAudioSpatializer_Result GetInterleavedBinauralBuffer(

				float* OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) const;
			PxrAudioSpatializer_Result GetPlanarBinauralBuffer(
				float* const * OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) const;
			PxrAudioSpatializer_Result GetInterleavedLoudspeakersBuffer(

				float* OutputBufferPtr,
				size_t NumFrames) const;
			PxrAudioSpatializer_Result GetPlanarLoudspeakersBuffer(

				float* const * OutputBufferPtr,
				size_t NumFrames) const;
			PxrAudioSpatializer_Result UpdateScene() const;
			PxrAudioSpatializer_Result SetDopplerEffect(
				int SourceId, int On) const;
			PxrAudioSpatializer_Result SetPlaybackMode(
				PxrAudioSpatializer_PlaybackMode PlaybackMode) const;
			PxrAudioSpatializer_Result SetLoudspeakerArray(
				const float* Positions, int NumLoudspeakers) const;
			PxrAudioSpatializer_Result SetMappingMatrix(
				const float* Matrix,
				int NumInputChannels,
				int NumOutputChannels) const;
			PxrAudioSpatializer_Result SetAmbisonicOrientation(
				const float* Front, const float* Up) const;
			PxrAudioSpatializer_Result SetListenerPosition(
				const float* Position) const;
			PxrAudioSpatializer_Result SetListenerOrientation(
				const float* Front, const float* Up) const;
			PxrAudioSpatializer_Result SetListenerPose(
				const float* Position,
				const float* Front,
				const float* Up) const;
			PxrAudioSpatializer_Result SetSourcePosition(
				int SourceId, const float* Position) const;
			PxrAudioSpatializer_Result SetSourceGain(
				int SourceId, float Gain) const;
			PxrAudioSpatializer_Result SetSourceSize(
				int SourceId, float VolumetricSize) const;
			PxrAudioSpatializer_Result UpdateSourceMode(
				int SourceId,
				PxrAudioSpatializer_SourceMode Mode) const;

		private:
			TSharedPtr<API, ESPMode::ThreadSafe> Api;
			static FContextSingleton* Instance;
			static std::atomic<bool> Initialized;
		};
	}
}
