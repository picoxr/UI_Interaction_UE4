//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PxrAudioSpatializerApiNative.h"
#include "PicoSpatialAudioEventTracker.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		const char* APINative::GetVersion(int* Major, int* Minor, int* Patch)
		{
			return PxrAudioSpatializer_GetVersion(Major, Minor, Patch);
		}

		PxrAudioSpatializer_Result APINative::CreateContext(
			PxrAudioSpatializer_RenderingMode Mode,
			size_t FramesPerBuffer,
			size_t SampleRate)
		{
			PicoSpatialAudioEventTracker::LogSdkApi("pico_spatial_audio_create_context|unreal_native");
			return PxrAudioSpatializer_CreateContext(&Context, Mode, FramesPerBuffer, SampleRate);
		}

		PxrAudioSpatializer_Result APINative::InitializeContext()
		{
			return PxrAudioSpatializer_InitializeContext(Context);
		}

		PxrAudioSpatializer_Result APINative::SubmitMesh(
			const float* Vertices,
			int VerticesCount,
			const int* Indices,
			int IndicesCount,
			PxrAudioSpatializer_AcousticsMaterial
			Material,
			int* GeometryId)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitMesh(Context, Vertices, VerticesCount, Indices, IndicesCount,
				                                        Material,
				                                        GeometryId);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SubmitMeshAndMaterialFactor(
			const float* Vertices,
			int VerticesCount,
			const int* Indices,
			int IndicesCount,
			const float* AbsorptionFactor,
			float ScatteringFactor,
			float TransmissionFactor,
			int* GeometryId)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitMeshAndMaterialFactor(
					Context, Vertices, VerticesCount, Indices, IndicesCount,
					AbsorptionFactor, ScatteringFactor,
					TransmissionFactor,
					GeometryId);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SubmitMeshWithConfig(const float* Vertices, int VerticesCount,
		                                                           const int* Indices, int IndicesCount,
		                                                           const PxrAudioSpatializer_AcousticMeshConfig* Config,
		                                                           int* GeometryId)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitMeshWithConfig(Context, Vertices, VerticesCount, Indices,
				                                                  IndicesCount, Config, GeometryId);
				PicoSpatialAudioEventTracker::LogSdkApi("pico_spatial_audio_submit_mesh_with_config|unreal_native");
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::RemoveMesh(int GeometryId)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_RemoveMesh(Context, GeometryId);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetMeshEnable(int GeometryId, bool Enable)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetMeshEnable(Context, GeometryId, Enable);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetMeshConfig(int GeometryId,
		                                                    const PxrAudioSpatializer_AcousticMeshConfig* Config,
		                                                    unsigned PropertyMask)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetMeshConfig(Context, GeometryId, Config, PropertyMask);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetAbsorptionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor)
		{
			return PxrAudioSpatializer_GetAbsorptionFactor(Material, AbsorptionFactor);
		}

		PxrAudioSpatializer_Result APINative::GetScatteringFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor)
		{
			return PxrAudioSpatializer_GetScatteringFactor(Material, ScatteringFactor);
		}

		PxrAudioSpatializer_Result APINative::GetTransmissionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor)
		{
			return PxrAudioSpatializer_GetTransmissionFactor(Material, TransmissionFactor);
		}

		PxrAudioSpatializer_Result APINative::CommitScene()
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_CommitScene(Context);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::AddSource(
			PxrAudioSpatializer_SourceMode SourceMode,
			const float* Position,
			int* SourceId,
			bool bIsAsync)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_AddSource(Context, SourceMode, Position, SourceId, bIsAsync);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::AddSourceWithOrientation(PxrAudioSpatializer_SourceMode Mode,
		                                                               const float* Position,
		                                                               const float* Front,
		                                                               const float* Up,
		                                                               float Radius,
		                                                               int* SourceId,
		                                                               bool bIsAsync)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_AddSourceWithOrientation(Context, Mode, Position, Front, Up, Radius,
				                                                      SourceId,
				                                                      bIsAsync);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::AddSourceWithConfig(
			const PxrAudioSpatializer_SourceConfig* SourceConfig,
			int* SourceId,
			bool bIsAsync)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_AddSourceWithConfig(Context, SourceConfig, SourceId, bIsAsync);
				PicoSpatialAudioEventTracker::LogSdkApi("pico_spatial_audio_add_source_with_config|unreal_native");
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourceConfig(const int SourceId,
		                                                      const PxrAudioSpatializer_SourceConfig* SourceConfig,
		                                                      unsigned int PropertyMask)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourceConfig(Context, SourceId, SourceConfig, PropertyMask);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetSourceConfig(const int SourceId,
		                                                      PxrAudioSpatializer_SourceConfig* SourceConfig)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_GetSourceConfig(Context, SourceId, SourceConfig);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourceAttenuationMode(int SourceId,
		                                                               PxrAudioSpatializer_SourceAttenuationMode Mode,
		                                                               DistanceAttenuationCallback
		                                                               DirectDistanceAttenuationCallback,
		                                                               DistanceAttenuationCallback
		                                                               IndirectDistanceAttenuationCallback)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourceAttenuationMode(Context, SourceId, Mode,
				                                                      DirectDistanceAttenuationCallback,
				                                                      IndirectDistanceAttenuationCallback);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourceRange(
			int SourceId, float RangeMin, float RangeMax)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourceRange(Context, SourceId, RangeMin, RangeMax);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::RemoveSource(
			int SourceId)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_RemoveSource(Context, SourceId);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SubmitSourceBuffer(
			int SourceId,
			const float* InputBufferPtr,
			size_t NumFrames)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitSourceBuffer(Context, SourceId, InputBufferPtr, NumFrames);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result
		APINative::SubmitAmbisonicChannelBuffer(
			const float* AmbisonicChannelBuffer,
			int Order,
			int Degree,
			PxrAudioSpatializer_AmbisonicNormalizationType NormType,
			float Gain,
			int ParentAmbisonicOrder)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitAmbisonicChannelBuffer(
					Context, AmbisonicChannelBuffer, Order, Degree,
					NormType,
					Gain,
					ParentAmbisonicOrder);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SubmitInterleavedAmbisonicBuffer(const float* AmbisonicBuffer,
		                                                                       int AmbisonicOrder,
		                                                                       PxrAudioSpatializer_AmbisonicNormalizationType
		                                                                       NormType,
		                                                                       float Gain)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitInterleavedAmbisonicBuffer(
					Context, AmbisonicBuffer, AmbisonicOrder, NormType,
					Gain);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SubmitMatrixInputBuffer(
			const float* InputBuffer,
			int InputChannelIndex)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SubmitMatrixInputBuffer(Context, InputBuffer, InputChannelIndex);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetInterleavedBinauralBuffer(float* OutputBufferPtr,
		                                                                   size_t NumFrames,
		                                                                   bool bIsAccumulative)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_GetInterleavedBinauralBuffer(
					Context, OutputBufferPtr, NumFrames, bIsAccumulative);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetPlanarBinauralBuffer(
			float* const * OutputBufferPtr,
			size_t NumFrames,
			bool bIsAccumulative)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_GetPlanarBinauralBuffer(Context, OutputBufferPtr, NumFrames,
				                                                     bIsAccumulative);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetInterleavedLoudspeakersBuffer(
			float* OutputBufferPtr, size_t NumFrames)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer(Context, OutputBufferPtr, NumFrames);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::GetPlanarLoudspeakersBuffer(
			float* const* OutputBufferPtr,
			size_t NumFrames)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_GetPlanarLoudspeakersBuffer(Context, OutputBufferPtr, NumFrames);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		DECLARE_CYCLE_STAT(TEXT("APINative::UpdateScene"), STAT_APINative_UpdateScene, STATGROUP_PicoSpatialAudio)
		PxrAudioSpatializer_Result APINative::UpdateScene()
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				{
					SCOPE_CYCLE_COUNTER(STAT_APINative_UpdateScene)
					Result = PxrAudioSpatializer_UpdateScene(Context);
				}
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetDopplerEffect(int SourceId, int On)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetDopplerEffect(Context, SourceId, On);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetPlaybackMode(
			PxrAudioSpatializer_PlaybackMode PlaybackMode)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetPlaybackMode(Context, PlaybackMode);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetLoudspeakerArray(
			const float* Positions,
			int NumLoudspeakers)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetLoudspeakerArray(Context, Positions, NumLoudspeakers);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetMappingMatrix(const float* Matrix,
		                                                       int NumInputChannels, int NumOutputChannels)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetMappingMatrix(Context, Matrix, NumInputChannels, NumOutputChannels);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetAmbisonicOrientation(
			const float* Front,
			const float* Up)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetAmbisonicOrientation(Context, Front, Up);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetListenerPosition(
			const float* Position)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetListenerPosition(Context, Position);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetListenerOrientation(
			const float* Front,
			const float* Up)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetListenerOrientation(Context, Front, Up);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetListenerPose(const float* Position,
		                                                      const float* Front, const float* Up)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetListenerPose(Context, Position, Front, Up);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourcePosition(int SourceId,
		                                                        const float* Position)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourcePosition(Context, SourceId, Position);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourceGain(int SourceId, float Gain)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourceGain(Context, SourceId, Gain);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::SetSourceSize(int SourceId,
		                                                    float VolumetricSize)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_SetSourceSize(Context, SourceId, VolumetricSize);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::UpdateSourceMode(int SourceId,
		                                                       PxrAudioSpatializer_SourceMode Mode)
		{
			PxrAudioSpatializer_Result Result = PASP_SUCCESS;
			if (ContextDestructionMutex.try_lock_shared())
			{
				Result = PxrAudioSpatializer_UpdateSourceMode(Context, SourceId, Mode);
				ContextDestructionMutex.unlock_shared();
			}
			return Result;
		}

		PxrAudioSpatializer_Result APINative::Destroy()
		{
			ContextDestructionMutex.lock();
			const auto Result = PxrAudioSpatializer_Destroy(Context);
			Context = nullptr;
			ContextDestructionMutex.unlock();
			return Result;
		}
	}
}
