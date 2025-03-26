//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoAmbisonicsRenderer.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		//	Implements of FAmbisonicsPacket
#pragma region FAmbisonicsPacket_Impl
		FAmbisonicsPacket::FAmbisonicsPacket(int32 InOrder, int32 InNumFrames, FQuat InRotation,
		                                     const Audio::AlignedFloatBuffer* InAudioBuffer)
			: Rotation(MoveTemp(InRotation)),
			  Order(InOrder),
			  NumChannels((Order + 1) * (Order + 1)),
			  NumFrames(InNumFrames)
		{
			if (InAudioBuffer == nullptr)
			{
				if (NumChannels * NumFrames > 0)
				{
					AudioBuffer.SetNumZeroed(NumChannels * NumFrames);
				}
			}
			else
			{
				AudioBuffer = *InAudioBuffer;
			}
		}

		void FAmbisonicsPacket::Serialize(FArchive& Ar)
		{
			Ar << AudioBuffer;
			Ar << Order;
		}

		TUniquePtr<ISoundfieldAudioPacket> FAmbisonicsPacket::Duplicate() const
		{
			return MakeUnique<FAmbisonicsPacket>(Order, NumFrames, Rotation, &AudioBuffer);
		}

		void FAmbisonicsPacket::Reset()
		{
			AudioBuffer.SetNumZeroed(AudioBuffer.Num());
		}

		int32 FAmbisonicsPacket::GetOrder() const
		{
			return Order;
		}

		void FAmbisonicsPacket::Reset(int32 InOrder, int32 InNumFrames, FQuat InRotation)
		{
			const int32 InNumChannels = (InOrder + 1) * (InOrder + 1);
			if (InNumChannels != NumChannels || InOrder != Order || InNumFrames != NumFrames)
			{
				Order = InOrder;
				NumChannels = InNumChannels;
				NumFrames = InNumFrames;
				AudioBuffer.SetNumZeroed(NumChannels * NumFrames);
			}
			Rotation = MoveTemp(InRotation);
		}
#pragma endregion FAmbisonicsPacket_Impl

		//	Implementation of FAmbisonicsEncoder, which input audio streams into Pico Spatial Audio System
#pragma region FAmbisonicsEncoder_Impl
		FAmbisonicsEncoder::FAmbisonicsEncoder(int32 InNumChannels, int32 InNumFrames)
			: NumChannels(InNumChannels), NumFrames(InNumFrames)
		{
			if (FContextSingleton::IsInitialized())
			{
				//	Add input channels as sound sources
				if (InNumChannels > 1)
				{
					TempPlannerBuffers.Reset();
					for (int32 i = 0; i < InNumChannels; ++i)
					{
						TempPlannerBuffers.AddDefaulted();
						TempPlannerBuffers.Top().SetNumZeroed(InNumFrames);
					}
				}

				for (int32 i = 0; i < InNumChannels; ++i)
				{
					PxrAudioSpatializer_SourceConfig SourceConfig;
					const auto Result = FContextSingleton::GetInstance()->AddSourceWithConfig(
						&SourceConfig, &InternalSourceIds[i]);
					if (Result == PASP_SUCCESS)
					{
						UE_LOG(LogPicoSpatialAudio, Display,
						       TEXT("Initialized Source when creating Ambisonic Encoder (Internal source ID: %i)"),
						       InternalSourceIds[i]);
					}
					else
					{
						UE_LOG(LogPicoSpatialAudio, Error,
						       TEXT("Failed to add source when creating Ambisonic Encoder, error code: %d"), Result);
					}
				}
			}
		}

		FAmbisonicsEncoder::~FAmbisonicsEncoder()
		{
			if (FContextSingleton::IsInitialized())
			{
				//	Removed added sources
				for (const int InternalSourceId : InternalSourceIds)
				{
					const auto Result = FContextSingleton::GetInstance()->RemoveSource(InternalSourceId);
					if (Result != PASP_SUCCESS)
					{
						UE_LOG(LogPicoSpatialAudio, Error,
						       TEXT(
							       "Failed to remove source when destroying Ambisonic Encoder (Internal source ID: %i), error code: %d"
						       ),
						       InternalSourceId, Result);
					}
				}
			}
		}

		void FAmbisonicsEncoder::Encode(const FSoundfieldEncoderInputData& InputData,
		                                ISoundfieldAudioPacket& OutputData)
		{
			EncodeAndMixIn(InputData, OutputData);
		}

		void FAmbisonicsEncoder::EncodeAndMixIn(const FSoundfieldEncoderInputData& InputData,
		                                        ISoundfieldAudioPacket& OutputData)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}
			const Audio::AlignedFloatBuffer& InputAudio = InputData.AudioBuffer;
			const FSoundfieldSpeakerPositionalData& PositionalData = InputData.PositionalData;

			//	Setup source properties
			if (PositionalData.ChannelPositions != nullptr)
			{
				//	Setup source num if necessary
				if (PositionalData.ChannelPositions->Num() != NumChannels)
				{
					UpdateNumChannels(PositionalData.ChannelPositions->Num());
				}

				//	Setup source positions
				const auto& SourcePositionPolarUnreal = *PositionalData.ChannelPositions;
				float TempSourcePositionPico[3] = {0.f};
				for (int i = 0; i < PositionalData.NumChannels; ++i)
				{
					ConvertToPicoSpatialAudioCoordinates(SourcePositionPolarUnreal[i], TempSourcePositionPico);
					FContextSingleton::GetInstance()->SetSourcePosition(InternalSourceIds[i], TempSourcePositionPico);
				}
			}

			//	Submit source buffer for each channel
			if (PositionalData.NumChannels == 1) //	Use input data directly
			{
				FContextSingleton::GetInstance()->SubmitSourceBuffer(InternalSourceIds[0], InputAudio.GetData(),
				                                                     InputAudio.Num());
			}
			else
			{
				//	De-interleave input buffer
				InterleavedToPlannerBuffer(InputAudio, TempPlannerBuffers);

				for (int i = 0; i < PositionalData.NumChannels; ++i)
				{
					const auto& SourceInput = TempPlannerBuffers[i];
					FContextSingleton::GetInstance()->SubmitSourceBuffer(
						InternalSourceIds[i], SourceInput.GetData(), SourceInput.Num());
				}
			}
		}
#pragma endregion FAmbisonicsEncoder_Impl

		//	Implementation of FAmbisonicsDecoder, which outputs encoded ambisonics to output endpoint
#pragma region FAmbisonicsDecoder_Impl
		FAmbisonicsDecoder::FAmbisonicsDecoder()
		{
		}

		FAmbisonicsDecoder::~FAmbisonicsDecoder()
		{
		}

		void FAmbisonicsDecoder::Decode(const FSoundfieldDecoderInputData& InputData,
		                                FSoundfieldDecoderOutputData& OutputData)
		{
			DecodeAndMixIn(InputData, OutputData);
		}

		void FAmbisonicsDecoder::DecodeAndMixIn(const FSoundfieldDecoderInputData& InputData,
		                                        FSoundfieldDecoderOutputData& OutputData)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}
			const int32 NumOutputChannels = InputData.PositionalData.NumChannels;

			//	We only input current ambisonic packet; listener plugin will take care of output
			const FAmbisonicsPacket& InputAudio = DowncastSoundfieldRef<const FAmbisonicsPacket>(
				InputData.SoundfieldBuffer);
			check(InputAudio.GetOrder() != 0)
			if (InputAudio.AudioBuffer.Num() == 0)
			{
				return;
			}
			//	Calculate input packet front and up
			float FrontPicoCoordinate[3] = {0.f};
			float UpPicoCoordinate[3] = {0.f};
			ConvertToPicoSpatialAudioCoordinates(InputAudio.Rotation.GetForwardVector() * 100.0f,
			                                     FrontPicoCoordinate);
			ConvertToPicoSpatialAudioCoordinates(InputAudio.Rotation.GetUpVector() * 100.0f,
			                                     UpPicoCoordinate);
			auto Result = FContextSingleton::GetInstance()->SetAmbisonicOrientation(
				FrontPicoCoordinate, UpPicoCoordinate);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to set ambisonic buffer orientation before buffer submission, error code is: %d"),
			        Result);
			Result = FContextSingleton::GetInstance()->SubmitInterleavedAmbisonicBuffer(
				InputAudio.AudioBuffer.GetData(), InputAudio.GetOrder(), PASP_SN3D, 1.0f);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to submit ambisonic buffer for decoding, error code is: %d"), Result);
		}
#pragma endregion FAmbisonicsDecoder_Impl

		//	Implementation of FAmbisonicsTranscoder, which converts ambisonics packet of unreal native into ours
#pragma region FAmbisonicsTranscoder_Impl
		FAmbisonicsTranscoder::FAmbisonicsTranscoder()
		{
		}

		FAmbisonicsTranscoder::~FAmbisonicsTranscoder()
		{
		}

		void FAmbisonicsTranscoder::Transcode(const ISoundfieldAudioPacket& InputData,
		                                      const ISoundfieldEncodingSettingsProxy& InputSettings,
		                                      ISoundfieldAudioPacket& OutputData,
		                                      const ISoundfieldEncodingSettingsProxy& OutputSettings)
		{
			FAmbisonicsPacket& OutputPacketPico = DowncastSoundfieldRef<FAmbisonicsPacket>(OutputData);
			ZeroOutAudioBuffer(OutputPacketPico.AudioBuffer);
			TranscodeAndMixIn(InputData, InputSettings, OutputData, OutputSettings);
		}

		void FAmbisonicsTranscoder::TranscodeAndMixIn(const ISoundfieldAudioPacket& InputData,
		                                              const ISoundfieldEncodingSettingsProxy& InputSettings,
		                                              ISoundfieldAudioPacket& PacketToMixTo,
		                                              const ISoundfieldEncodingSettingsProxy& OutputSettings)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}
			const FAmbisonicsSoundfieldBuffer& InputPacketUnreal = DowncastSoundfieldRef<const
				FAmbisonicsSoundfieldBuffer>(InputData);
			FAmbisonicsPacket& OutputPacketPico = DowncastSoundfieldRef<FAmbisonicsPacket>(PacketToMixTo);
			const FAmbisonicsEncodingSettings& OutputPacketSettings = DowncastSoundfieldRef<const
				FAmbisonicsEncodingSettings>(OutputSettings);

			//	Get output ambisonic channel count
			const int32 InputChannelsCount = InputPacketUnreal.NumChannels;
			const int32 OutputChannelsCount = (OutputPacketSettings.Order + 1) * (OutputPacketSettings.Order + 1);
			const int32 InputNumFrames = InputPacketUnreal.AudioBuffer.Num() / InputChannelsCount;

			OutputPacketPico.Reset(OutputPacketSettings.Order, InputNumFrames, InputPacketUnreal.Rotation);

			//	When mixing in, we discard extra channels in input packets
			// Sum InputAudio directly into the corresponding channels in OutputAudio.
			if (InputChannelsCount != OutputChannelsCount)
			{
				int32 NumChannelsToCopy = FMath::Min(InputChannelsCount, OutputChannelsCount);
				for (int32 FrameIndex = 0; FrameIndex < InputNumFrames; FrameIndex++)
				{
					for (int32 ChannelIndex = 0; ChannelIndex < NumChannelsToCopy; ChannelIndex++)
					{
						const int32 InputIndex = FrameIndex * InputChannelsCount + ChannelIndex;
						const int32 OutputIndex = FrameIndex * OutputChannelsCount + ChannelIndex;
						OutputPacketPico.AudioBuffer[OutputIndex] += InputPacketUnreal.AudioBuffer[InputIndex];
					}
				}
			}
			else
			{
				Audio::MixInBufferFast(InputPacketUnreal.AudioBuffer, OutputPacketPico.AudioBuffer, 1.0f);
			}
		}
#pragma endregion FAmbisonicsTranscoder_Impl

		//	Implementation of FAmbisonicsMixer, which sums ambisonic streams together
#pragma region FAmbisonicsMixer_Impl
		FAmbisonicsMixer::FAmbisonicsMixer(int AmbisonicOrder)
		{
		}

		FAmbisonicsMixer::~FAmbisonicsMixer()
		{
		}

		void FAmbisonicsMixer::MixTogether(const FSoundfieldMixerInputData& InputData,
		                                   ISoundfieldAudioPacket& PacketToMixInto)
		{
			if (!FContextSingleton::IsInitialized())
			{
				return;
			}
			const FAmbisonicsPacket& InputPacketPico = DowncastSoundfieldRef<const
				FAmbisonicsPacket>(InputData.InputPacket);
			FAmbisonicsPacket& OutputPacketPico = DowncastSoundfieldRef<FAmbisonicsPacket>(PacketToMixInto);

			if (InputPacketPico.AudioBuffer.Num() == 0)
			{
				return;
			}
			//	Calculate input packet front and up
			float FrontPicoCoordinate[3] = {0.f};
			float UpPicoCoordinate[3] = {0.f};
			ConvertToPicoSpatialAudioCoordinates(InputPacketPico.Rotation.GetForwardVector() * 100.0f,
			                                     FrontPicoCoordinate);
			ConvertToPicoSpatialAudioCoordinates(InputPacketPico.Rotation.GetUpVector() * 100.0f,
			                                     UpPicoCoordinate);
			auto Result = FContextSingleton::GetInstance()->SetAmbisonicOrientation(
				FrontPicoCoordinate, UpPicoCoordinate);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to set ambisonic buffer orientation before buffer submission, error code is: %d"),
			        Result);
			Result = FContextSingleton::GetInstance()->SubmitInterleavedAmbisonicBuffer(
				InputPacketPico.AudioBuffer.GetData(), InputPacketPico.GetOrder(), PASP_SN3D, InputData.SendLevel);
			UE_CLOG(Result != PASP_SUCCESS, LogPicoSpatialAudio, Error,
			        TEXT("Failed to submit ambisonic buffer for decoding, error code is: %d"), Result);
		}
#pragma endregion FAmbisonicsMixer_Impl

#pragma region FAmbisonicsFactory_Impl
		FAmbisonicsFactory::FAmbisonicsFactory()
		{
			ISoundfieldFactory::RegisterSoundfieldFormat(this);
		}

		FAmbisonicsFactory::~FAmbisonicsFactory()
		{
			ISoundfieldFactory::UnregisterSoundfieldFormat(this);
		}

		FName FAmbisonicsFactory::GetSoundfieldFormatName()
		{
			static FName Name(TEXT("Pico Spatial Audio Ambisonics Renderer"));
			return Name;
		}

		TUniquePtr<ISoundfieldEncoderStream> FAmbisonicsFactory::CreateEncoderStream(
			const FAudioPluginInitializationParams& InitInfo, const ISoundfieldEncodingSettingsProxy& InitialSettings)
		{
			return TUniquePtr<ISoundfieldEncoderStream>(
				new FAmbisonicsEncoder(InitInfo.NumOutputChannels, InitInfo.BufferLength));
		}

		TUniquePtr<ISoundfieldDecoderStream> FAmbisonicsFactory::CreateDecoderStream(
			const FAudioPluginInitializationParams& InitInfo, const ISoundfieldEncodingSettingsProxy& InitialSettings)
		{
			return TUniquePtr<ISoundfieldDecoderStream>(new FAmbisonicsDecoder());
		}

		TUniquePtr<ISoundfieldTranscodeStream> FAmbisonicsFactory::CreateTranscoderStream(const FName SourceFormat,
			const ISoundfieldEncodingSettingsProxy& InitialSourceSettings, const FName DestinationFormat,
			const ISoundfieldEncodingSettingsProxy& InitialDestinationSettings,
			const FAudioPluginInitializationParams& InitInfo)
		{
			check(SourceFormat == GetUnrealAmbisonicsFormatName());
			check(DestinationFormat == GetSoundfieldFormatName());
			return TUniquePtr<ISoundfieldTranscodeStream>(new FAmbisonicsTranscoder());
		}

		TUniquePtr<ISoundfieldMixerStream> FAmbisonicsFactory::CreateMixerStream(
			const ISoundfieldEncodingSettingsProxy& InitialSettings)
		{
			const FAmbisonicsEncodingSettings& Settings = DowncastSoundfieldRef<const FAmbisonicsEncodingSettings>(
				InitialSettings);
			return TUniquePtr<ISoundfieldMixerStream>(new FAmbisonicsMixer(Settings.Order));
		}

		TUniquePtr<ISoundfieldAudioPacket> FAmbisonicsFactory::CreateEmptyPacket()
		{
			return TUniquePtr<ISoundfieldAudioPacket>(new FAmbisonicsPacket());
		}

		bool FAmbisonicsFactory::IsTranscodeRequiredBetweenSettings(
			const ISoundfieldEncodingSettingsProxy& SourceSettings,
			const ISoundfieldEncodingSettingsProxy& DestinationSettings)
		{
			return false;
		}

		bool FAmbisonicsFactory::CanTranscodeFromSoundfieldFormat(FName SourceFormat,
		                                                          const ISoundfieldEncodingSettingsProxy&
		                                                          SourceEncodingSettings)
		{
			return SourceFormat == GetUnrealAmbisonicsFormatName();
		}

		bool FAmbisonicsFactory::CanTranscodeToSoundfieldFormat(FName DestinationFormat,
		                                                        const ISoundfieldEncodingSettingsProxy&
		                                                        DestinationEncodingSettings)
		{
			return false;
		}

		UClass* FAmbisonicsFactory::GetCustomEncodingSettingsClass() const
		{
			return UPicoAmbisonicsSettings::StaticClass();
		}

		const USoundfieldEncodingSettingsBase* FAmbisonicsFactory::GetDefaultEncodingSettings()
		{
			return GetDefault<UPicoAmbisonicsSettings>();
		}
#pragma endregion FAmbisonicsFactory_Impl
	}
}
