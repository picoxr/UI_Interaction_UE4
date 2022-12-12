#include "PxrAudioSpatializerContextSingleton.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		FContextSingleton* FContextSingleton::Instance = nullptr;
		std::atomic<bool> FContextSingleton::Initialized(false);

		PxrAudioSpatializer_Result FContextSingleton::Init(const PxrAudioSpatializer_RenderingMode Quality,
		                                                   const size_t FramesPerBuffer,
		                                                   const size_t SampleRate)
		{
			if (Instance != nullptr)
				return PASP_SUCCESS;

			Instance = new FContextSingleton();
			//	TODO: Add wwise api impl by condition  
			Instance->Api = MakeShared<APINative, ESPMode::ThreadSafe>();

			auto Result = Instance->Api->CreateContext(Quality, FramesPerBuffer, SampleRate);
			PXR_AUDIO_CHECK_RESULT(Result);
			Result = Instance->Api->InitializeContext();

			if (Result == PASP_SUCCESS)
				Initialized = true;
			return Result;
		}

		bool FContextSingleton::IsInitialized()
		{
			return Initialized;
		}

		PxrAudioSpatializer_Result FContextSingleton::Destroy()
		{
			if (Instance == nullptr)
				return PASP_CONTEXT_NOT_CREATED;
			Initialized = false;

			const auto Result = Instance->Api->Destroy();
			PXR_AUDIO_CHECK_RESULT(Result);

			delete Instance;
			Instance = nullptr;

			return PASP_SUCCESS;
		}

		FContextSingleton* FContextSingleton::GetInstance()
		{
			return Instance;
		}

		const char* FContextSingleton::GetVersion(int* Major, int* Minor, int* Patch) const
		{
			return Api->GetVersion(Major, Minor, Patch);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitMesh(
			const float* Vertices,
			int VerticesCount, const int* Indices,
			int IndicesCount,
			PxrAudioSpatializer_AcousticsMaterial Material,
			int* GeometryId) const
		{
			return Api->SubmitMesh(Vertices, VerticesCount, Indices, IndicesCount, Material, GeometryId);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitMeshAndMaterialFactor(
			const float* Vertices, int VerticesCount,
			const int* Indices, int IndicesCount,
			const float* AbsorptionFactor,
			float ScatteringFactor,
			float TransmissionFactor,
			int* GeometryId) const
		{
			return Api->SubmitMeshAndMaterialFactor(Vertices, VerticesCount, Indices, IndicesCount,
			                                        AbsorptionFactor, ScatteringFactor, TransmissionFactor, GeometryId);
		}

		PxrAudioSpatializer_Result FContextSingleton::RemoveMesh(int GeometryId) const
		{
			return Api->RemoveMesh(GeometryId);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetAbsorptionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material,
			float* AbsorptionFactor) const
		{
			return Api->GetAbsorptionFactor(Material, AbsorptionFactor);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetScatteringFactor(
			PxrAudioSpatializer_AcousticsMaterial Material,
			float* ScatteringFactor) const
		{
			return Api->GetScatteringFactor(Material, ScatteringFactor);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetTransmissionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material,
			float* TransmissionFactor) const
		{
			return Api->GetTransmissionFactor(Material, TransmissionFactor);
		}

		PxrAudioSpatializer_Result FContextSingleton::CommitScene() const
		{
			return Api->CommitScene();
		}

		PxrAudioSpatializer_Result FContextSingleton::AddSource(
			PxrAudioSpatializer_SourceMode SourceMode,
			const float* Position,
			int* SourceId, bool bIsAsync) const
		{
			return Api->AddSource(SourceMode, Position, SourceId, bIsAsync);
		}

		PxrAudioSpatializer_Result FContextSingleton::AddSourceWithOrientation(
			PxrAudioSpatializer_SourceMode Mode,
			const float* Position,
			const float* Front,
			const float* Up,
			float Radius, int* SourceId,
			bool bIsAsync) const
		{
			return Api->AddSourceWithOrientation(Mode, Position, Front, Up, Radius, SourceId, bIsAsync);
		}

		PxrAudioSpatializer_Result FContextSingleton::AddSourceWithConfig(
			const PxrAudioSpatializer_SourceConfig*
			SourceConfig,
			int* SourceId, bool bIsAsync) const
		{
			return Api->AddSourceWithConfig(SourceConfig, SourceId, bIsAsync);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetSourceAttenuationMode(
			int SourceId,
			PxrAudioSpatializer_SourceAttenuationMode Mode,
			DistanceAttenuationCallback
			DirectDistanceAttenuationCallback,
			DistanceAttenuationCallback
			IndirectDistanceAttenuationCallback) const
		{
			return Api->SetSourceAttenuationMode(SourceId, Mode, DirectDistanceAttenuationCallback,
			                                     IndirectDistanceAttenuationCallback);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetSourceRange(int SourceId,
		                                                             float RangeMin, float RangeMax) const
		{
			return Api->SetSourceRange(SourceId, RangeMin, RangeMax);
		}

		PxrAudioSpatializer_Result FContextSingleton::RemoveSource(int SourceId) const
		{
			return Api->RemoveSource(SourceId);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitSourceBuffer(int SourceId,
		                                                                 const float* InputBufferPtr,
		                                                                 size_t NumFrames) const
		{
			return Api->SubmitSourceBuffer(SourceId, InputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitAmbisonicChannelBuffer(
			const float* AmbisonicChannelBuffer,
			int Order, int Degree,
			PxrAudioSpatializer_AmbisonicNormalizationType
			NormType, float Gain, int ParentAmbisonicOrder) const
		{
			return Api->SubmitAmbisonicChannelBuffer(AmbisonicChannelBuffer, Order, Degree, NormType, Gain,
			                                         ParentAmbisonicOrder);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitInterleavedAmbisonicBuffer(
			const float* AmbisonicBuffer,
			int AmbisonicOrder,
			PxrAudioSpatializer_AmbisonicNormalizationType
			NormType,
			float Gain) const
		{
			return Api->SubmitInterleavedAmbisonicBuffer(AmbisonicBuffer, AmbisonicOrder, NormType, Gain);
		}

		PxrAudioSpatializer_Result FContextSingleton::SubmitMatrixInputBuffer(
			const float* InputBuffer,
			int InputChannelIndex) const
		{
			return Api->SubmitMatrixInputBuffer(InputBuffer, InputChannelIndex);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetInterleavedBinauralBuffer(
			float* OutputBufferPtr, size_t NumFrames,
			bool bIsAccumulative) const
		{
			return Api->GetInterleavedBinauralBuffer(OutputBufferPtr, NumFrames, bIsAccumulative);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetPlanarBinauralBuffer(
			float* const* OutputBufferPtr,
			size_t NumFrames,
			bool bIsAccumulative) const
		{
			return Api->GetPlanarBinauralBuffer(OutputBufferPtr, NumFrames, bIsAccumulative);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetInterleavedLoudspeakersBuffer(
			float* OutputBufferPtr, size_t NumFrames) const
		{
			return Api->GetInterleavedLoudspeakersBuffer(OutputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result FContextSingleton::GetPlanarLoudspeakersBuffer(
			float* const* OutputBufferPtr,
			size_t NumFrames) const
		{
			return Api->GetPlanarLoudspeakersBuffer(OutputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result FContextSingleton::UpdateScene() const
		{
			return Api->UpdateScene();
		}

		PxrAudioSpatializer_Result FContextSingleton::SetDopplerEffect(int SourceId,
		                                                               int On) const
		{
			return Api->SetDopplerEffect(SourceId, On);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetPlaybackMode(
			PxrAudioSpatializer_PlaybackMode PlaybackMode)
		const
		{
			return Api->SetPlaybackMode(PlaybackMode);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetLoudspeakerArray(
			const float* Positions,
			int NumLoudspeakers) const
		{
			return Api->SetLoudspeakerArray(Positions, NumLoudspeakers);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetMappingMatrix(
			const float* Matrix,
			int NumInputChannels,
			int NumOutputChannels) const
		{
			return Api->SetMappingMatrix(Matrix, NumInputChannels, NumOutputChannels);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetAmbisonicOrientation(
			const float* Front, const float* Up) const
		{
			return Api->SetAmbisonicOrientation(Front, Up);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetListenerPosition(
			const float* Position) const
		{
			return Api->SetListenerPosition(Position);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetListenerOrientation(
			const float* Front, const float* Up) const
		{
			return Api->SetListenerOrientation(Front, Up);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetListenerPose(
			const float* Position,
			const float* Front, const float* Up) const
		{
			return Api->SetListenerPose(Position, Front, Up);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetSourcePosition(int SourceId,
		                                                                const float* Position) const
		{
			return Api->SetSourcePosition(SourceId, Position);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetSourceGain(int SourceId,
		                                                            float Gain) const
		{
			return Api->SetSourceGain(SourceId, Gain);
		}

		PxrAudioSpatializer_Result FContextSingleton::SetSourceSize(int SourceId,
		                                                            float VolumetricSize) const
		{
			return Api->SetSourceSize(SourceId, VolumetricSize);
		}

		PxrAudioSpatializer_Result FContextSingleton::UpdateSourceMode(int SourceId,
		                                                               PxrAudioSpatializer_SourceMode Mode) const
		{
			return Api->UpdateSourceMode(SourceId, Mode);
		}
	}
}
