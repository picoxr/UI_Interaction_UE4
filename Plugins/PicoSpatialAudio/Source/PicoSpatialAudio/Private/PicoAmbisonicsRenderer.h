//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "IAudioExtensionPlugin.h"
#include "SoundFieldRendering.h"
#include "PxrAudioSpatializerContextSingleton.h"
#include "PicoAmbisonicsSettings.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FAmbisonicsPacket : public ISoundfieldAudioPacket
		{
		public:
			FAmbisonicsPacket(int32 InOrder = 1, int32 InNumFrames = 0, FQuat InRotation = FQuat::Identity,
			                  const Audio::AlignedFloatBuffer* InAudioBuffer = nullptr);

			virtual void Serialize(FArchive& Ar) override;
			virtual TUniquePtr<ISoundfieldAudioPacket> Duplicate() const override;
			virtual void Reset() override;
			int32 GetOrder() const;
			void Reset(int32 InOrder, int32 InNumFrames, FQuat InRotation);
			
			Audio::AlignedFloatBuffer AudioBuffer;
			FQuat Rotation;
		private:
			int32 Order;
			int32 NumChannels;
			int32 NumFrames;
		};

		class FAmbisonicsEncoder : public ISoundfieldEncoderStream
		{
		public:
			FAmbisonicsEncoder(int32 InNumChannels, int32 InNumFrames);
			virtual ~FAmbisonicsEncoder();
			virtual void Encode(const FSoundfieldEncoderInputData& InputData,
			                    ISoundfieldAudioPacket& OutputData) override;
			virtual void EncodeAndMixIn(const FSoundfieldEncoderInputData& InputData,
			                            ISoundfieldAudioPacket& OutputData) override;
		private:
			TArray<int> InternalSourceIds;
			TArray<Audio::AlignedFloatBuffer> TempPlannerBuffers;
			int32 NumChannels;
			int32 NumFrames;

			void UpdateNumChannels(int32 NewNumChannels)
			{
				//	Remove unwanted sources
				for (int32 i = NumChannels - 1; i >= NewNumChannels; --i)
				{
					FContextSingleton::GetInstance()->RemoveSource(InternalSourceIds[i]);
					TempPlannerBuffers.Pop();
				}

				//	Add newly-needed sources
				for (int32 i = NumChannels; i < NewNumChannels; ++i)
				{
					FContextSingleton::GetInstance()->RemoveSource(InternalSourceIds[i]);
					TempPlannerBuffers.AddDefaulted();
				}
			}
		};

		class FAmbisonicsDecoder : public ISoundfieldDecoderStream
		{
		public:
			FAmbisonicsDecoder();

			virtual ~FAmbisonicsDecoder();
			virtual void Decode(const FSoundfieldDecoderInputData& InputData,
			                    FSoundfieldDecoderOutputData& OutputData) override;
			virtual void DecodeAndMixIn(const FSoundfieldDecoderInputData& InputData,
			                            FSoundfieldDecoderOutputData& OutputData) override;
		};

		class FAmbisonicsTranscoder : public ISoundfieldTranscodeStream
		{
		public:
			FAmbisonicsTranscoder();
			virtual ~FAmbisonicsTranscoder() override;
			virtual void Transcode(const ISoundfieldAudioPacket& InputData,
			                       const ISoundfieldEncodingSettingsProxy& InputSettings,
			                       ISoundfieldAudioPacket& OutputData,
			                       const ISoundfieldEncodingSettingsProxy& OutputSettings) override;
			virtual void TranscodeAndMixIn(const ISoundfieldAudioPacket& InputData,
			                               const ISoundfieldEncodingSettingsProxy& InputSettings,
			                               ISoundfieldAudioPacket& PacketToMixTo,
			                               const ISoundfieldEncodingSettingsProxy& OutputSettings) override;
		};

		class FAmbisonicsMixer : public ISoundfieldMixerStream
		{
		public:
			FAmbisonicsMixer(int AmbisonicOrder);
			virtual ~FAmbisonicsMixer() override;
			virtual void MixTogether(const FSoundfieldMixerInputData& InputData,
			                         ISoundfieldAudioPacket& PacketToMixInto) override;
		};

		class FAmbisonicsFactory : public ISoundfieldFactory
		{
		public:
			FAmbisonicsFactory();
			virtual ~FAmbisonicsFactory();

			// Begin IAmbisonicsMixer
			virtual FName GetSoundfieldFormatName() override;
			virtual TUniquePtr<ISoundfieldEncoderStream> CreateEncoderStream(
				const FAudioPluginInitializationParams& InitInfo,
				const ISoundfieldEncodingSettingsProxy& InitialSettings) override;
			virtual TUniquePtr<ISoundfieldDecoderStream> CreateDecoderStream(
				const FAudioPluginInitializationParams& InitInfo,
				const ISoundfieldEncodingSettingsProxy& InitialSettings) override;
			virtual TUniquePtr<ISoundfieldTranscodeStream> CreateTranscoderStream(
				const FName SourceFormat, const ISoundfieldEncodingSettingsProxy& InitialSourceSettings,
				const FName DestinationFormat, const ISoundfieldEncodingSettingsProxy& InitialDestinationSettings,
				const FAudioPluginInitializationParams& InitInfo) override;
			virtual TUniquePtr<ISoundfieldMixerStream> CreateMixerStream(
				const ISoundfieldEncodingSettingsProxy& InitialSettings) override;
			virtual TUniquePtr<ISoundfieldAudioPacket> CreateEmptyPacket() override;
			virtual bool IsTranscodeRequiredBetweenSettings(const ISoundfieldEncodingSettingsProxy& SourceSettings,
			                                                const ISoundfieldEncodingSettingsProxy&
			                                                DestinationSettings) override;
			virtual bool CanTranscodeFromSoundfieldFormat(FName SourceFormat,
			                                              const ISoundfieldEncodingSettingsProxy&
			                                              SourceEncodingSettings) override;
			virtual bool CanTranscodeToSoundfieldFormat(FName DestinationFormat,
			                                            const ISoundfieldEncodingSettingsProxy&
			                                            DestinationEncodingSettings) override;
			virtual UClass* GetCustomEncodingSettingsClass() const override;
			virtual const USoundfieldEncodingSettingsBase* GetDefaultEncodingSettings() override;
			//~ IAmbisonicsMixer
		};
	}
}
