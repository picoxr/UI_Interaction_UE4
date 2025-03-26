// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/RTCPicoUserInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTCPicoUserInterface() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcPrivilege;
	static UEnum* ERtcPrivilege_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcPrivilege.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcPrivilege.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcPrivilege"));
		}
		return Z_Registration_Info_UEnum_ERtcPrivilege.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPrivilege>()
	{
		return ERtcPrivilege_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enumerators[] = {
		{ "ERtcPrivilege::PublishStream", (int64)ERtcPrivilege::PublishStream },
		{ "ERtcPrivilege::PublishAudioStream", (int64)ERtcPrivilege::PublishAudioStream },
		{ "ERtcPrivilege::PublishVideoStream", (int64)ERtcPrivilege::PublishVideoStream },
		{ "ERtcPrivilege::SubscribeStream", (int64)ERtcPrivilege::SubscribeStream },
		{ "ERtcPrivilege::None", (int64)ERtcPrivilege::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc engine privilege enum.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcPrivilege::None" },
		{ "PublishAudioStream.Name", "ERtcPrivilege::PublishAudioStream" },
		{ "PublishStream.Name", "ERtcPrivilege::PublishStream" },
		{ "PublishVideoStream.Name", "ERtcPrivilege::PublishVideoStream" },
		{ "SubscribeStream.Name", "ERtcPrivilege::SubscribeStream" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc engine privilege enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcPrivilege",
		"ERtcPrivilege",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege()
	{
		if (!Z_Registration_Info_UEnum_ERtcPrivilege.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcPrivilege.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcPrivilege.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcEngineInitResult;
	static UEnum* ERtcEngineInitResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcEngineInitResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcEngineInitResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcEngineInitResult"));
		}
		return Z_Registration_Info_UEnum_ERtcEngineInitResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEngineInitResult>()
	{
		return ERtcEngineInitResult_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enumerators[] = {
		{ "ERtcEngineInitResult::Unknow", (int64)ERtcEngineInitResult::Unknow },
		{ "ERtcEngineInitResult::AlreadyInitialized", (int64)ERtcEngineInitResult::AlreadyInitialized },
		{ "ERtcEngineInitResult::InvalidConfig", (int64)ERtcEngineInitResult::InvalidConfig },
		{ "ERtcEngineInitResult::Success", (int64)ERtcEngineInitResult::Success },
		{ "ERtcEngineInitResult::None", (int64)ERtcEngineInitResult::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enum_MetaDataParams[] = {
		{ "AlreadyInitialized.Name", "ERtcEngineInitResult::AlreadyInitialized" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc engine init result enum.</summary>\n" },
#endif
		{ "InvalidConfig.Name", "ERtcEngineInitResult::InvalidConfig" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcEngineInitResult::None" },
		{ "Success.Name", "ERtcEngineInitResult::Success" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc engine init result enum.</summary>" },
#endif
		{ "Unknow.Name", "ERtcEngineInitResult::Unknow" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcEngineInitResult",
		"ERtcEngineInitResult",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult()
	{
		if (!Z_Registration_Info_UEnum_ERtcEngineInitResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcEngineInitResult.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcEngineInitResult.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcRoomProfileType;
	static UEnum* ERtcRoomProfileType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcRoomProfileType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcRoomProfileType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcRoomProfileType"));
		}
		return Z_Registration_Info_UEnum_ERtcRoomProfileType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcRoomProfileType>()
	{
		return ERtcRoomProfileType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enumerators[] = {
		{ "ERtcRoomProfileType::Communication", (int64)ERtcRoomProfileType::Communication },
		{ "ERtcRoomProfileType::LiveBroadcasting", (int64)ERtcRoomProfileType::LiveBroadcasting },
		{ "ERtcRoomProfileType::Game", (int64)ERtcRoomProfileType::Game },
		{ "ERtcRoomProfileType::CloundGame", (int64)ERtcRoomProfileType::CloundGame },
		{ "ERtcRoomProfileType::LowLatency", (int64)ERtcRoomProfileType::LowLatency },
		{ "ERtcRoomProfileType::None", (int64)ERtcRoomProfileType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CloundGame.Name", "ERtcRoomProfileType::CloundGame" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc engine room profile type enum.</summary>\n" },
#endif
		{ "Communication.Name", "ERtcRoomProfileType::Communication" },
		{ "Game.Name", "ERtcRoomProfileType::Game" },
		{ "LiveBroadcasting.Name", "ERtcRoomProfileType::LiveBroadcasting" },
		{ "LowLatency.Name", "ERtcRoomProfileType::LowLatency" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcRoomProfileType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc engine room profile type enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcRoomProfileType",
		"ERtcRoomProfileType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType()
	{
		if (!Z_Registration_Info_UEnum_ERtcRoomProfileType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcRoomProfileType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcRoomProfileType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcMuteState;
	static UEnum* ERtcMuteState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcMuteState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcMuteState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMuteState"));
		}
		return Z_Registration_Info_UEnum_ERtcMuteState.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMuteState>()
	{
		return ERtcMuteState_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enumerators[] = {
		{ "ERtcMuteState::Off", (int64)ERtcMuteState::Off },
		{ "ERtcMuteState::On", (int64)ERtcMuteState::On },
		{ "ERtcMuteState::None", (int64)ERtcMuteState::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc mute state enum.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcMuteState::None" },
		{ "Off.Name", "ERtcMuteState::Off" },
		{ "On.Name", "ERtcMuteState::On" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc mute state enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcMuteState",
		"ERtcMuteState",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState()
	{
		if (!Z_Registration_Info_UEnum_ERtcMuteState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcMuteState.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcMuteState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcPauseResumeMediaType;
	static UEnum* ERtcPauseResumeMediaType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcPauseResumeMediaType"));
		}
		return Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPauseResumeMediaType>()
	{
		return ERtcPauseResumeMediaType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enumerators[] = {
		{ "ERtcPauseResumeMediaType::Audio", (int64)ERtcPauseResumeMediaType::Audio },
		{ "ERtcPauseResumeMediaType::Video", (int64)ERtcPauseResumeMediaType::Video },
		{ "ERtcPauseResumeMediaType::AudioAndVideo", (int64)ERtcPauseResumeMediaType::AudioAndVideo },
		{ "ERtcPauseResumeMediaType::None", (int64)ERtcPauseResumeMediaType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enum_MetaDataParams[] = {
		{ "Audio.Name", "ERtcPauseResumeMediaType::Audio" },
		{ "AudioAndVideo.Name", "ERtcPauseResumeMediaType::AudioAndVideo" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc pause or resume media type enum.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcPauseResumeMediaType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc pause or resume media type enum.</summary>" },
#endif
		{ "Video.Name", "ERtcPauseResumeMediaType::Video" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcPauseResumeMediaType",
		"ERtcPauseResumeMediaType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType()
	{
		if (!Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcPauseResumeMediaType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice;
	static UEnum* ERtcAudioPlaybackDevice_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcAudioPlaybackDevice"));
		}
		return Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioPlaybackDevice>()
	{
		return ERtcAudioPlaybackDevice_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enumerators[] = {
		{ "ERtcAudioPlaybackDevice::Headset", (int64)ERtcAudioPlaybackDevice::Headset },
		{ "ERtcAudioPlaybackDevice::EarPiece", (int64)ERtcAudioPlaybackDevice::EarPiece },
		{ "ERtcAudioPlaybackDevice::SpeakerPhone", (int64)ERtcAudioPlaybackDevice::SpeakerPhone },
		{ "ERtcAudioPlaybackDevice::HeadsetBlueTooth", (int64)ERtcAudioPlaybackDevice::HeadsetBlueTooth },
		{ "ERtcAudioPlaybackDevice::HeadsetUsb", (int64)ERtcAudioPlaybackDevice::HeadsetUsb },
		{ "ERtcAudioPlaybackDevice::None", (int64)ERtcAudioPlaybackDevice::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc audio playback device enum.</summary>\n" },
#endif
		{ "EarPiece.Name", "ERtcAudioPlaybackDevice::EarPiece" },
		{ "Headset.Name", "ERtcAudioPlaybackDevice::Headset" },
		{ "HeadsetBlueTooth.Name", "ERtcAudioPlaybackDevice::HeadsetBlueTooth" },
		{ "HeadsetUsb.Name", "ERtcAudioPlaybackDevice::HeadsetUsb" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcAudioPlaybackDevice::None" },
		{ "SpeakerPhone.Name", "ERtcAudioPlaybackDevice::SpeakerPhone" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc audio playback device enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcAudioPlaybackDevice",
		"ERtcAudioPlaybackDevice",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice()
	{
		if (!Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcAudioScenarioType;
	static UEnum* ERtcAudioScenarioType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcAudioScenarioType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcAudioScenarioType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcAudioScenarioType"));
		}
		return Z_Registration_Info_UEnum_ERtcAudioScenarioType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioScenarioType>()
	{
		return ERtcAudioScenarioType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enumerators[] = {
		{ "ERtcAudioScenarioType::Music", (int64)ERtcAudioScenarioType::Music },
		{ "ERtcAudioScenarioType::HighQualityCommunication", (int64)ERtcAudioScenarioType::HighQualityCommunication },
		{ "ERtcAudioScenarioType::Communication", (int64)ERtcAudioScenarioType::Communication },
		{ "ERtcAudioScenarioType::Media", (int64)ERtcAudioScenarioType::Media },
		{ "ERtcAudioScenarioType::GameStreaming", (int64)ERtcAudioScenarioType::GameStreaming },
		{ "ERtcAudioScenarioType::None", (int64)ERtcAudioScenarioType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc audio scenario type enum.</summary>\n" },
#endif
		{ "Communication.Name", "ERtcAudioScenarioType::Communication" },
		{ "GameStreaming.Name", "ERtcAudioScenarioType::GameStreaming" },
		{ "HighQualityCommunication.Name", "ERtcAudioScenarioType::HighQualityCommunication" },
		{ "Media.Name", "ERtcAudioScenarioType::Media" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "Music.Name", "ERtcAudioScenarioType::Music" },
		{ "None.Name", "ERtcAudioScenarioType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc audio scenario type enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcAudioScenarioType",
		"ERtcAudioScenarioType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType()
	{
		if (!Z_Registration_Info_UEnum_ERtcAudioScenarioType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcAudioScenarioType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcAudioScenarioType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcStreamIndex;
	static UEnum* ERtcStreamIndex_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcStreamIndex.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcStreamIndex.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcStreamIndex"));
		}
		return Z_Registration_Info_UEnum_ERtcStreamIndex.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamIndex>()
	{
		return ERtcStreamIndex_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enumerators[] = {
		{ "ERtcStreamIndex::Main", (int64)ERtcStreamIndex::Main },
		{ "ERtcStreamIndex::Screen", (int64)ERtcStreamIndex::Screen },
		{ "ERtcStreamIndex::None", (int64)ERtcStreamIndex::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc audio stream index enum.</summary>\n" },
#endif
		{ "Main.Name", "ERtcStreamIndex::Main" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcStreamIndex::None" },
		{ "Screen.Name", "ERtcStreamIndex::Screen" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc audio stream index enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcStreamIndex",
		"ERtcStreamIndex",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex()
	{
		if (!Z_Registration_Info_UEnum_ERtcStreamIndex.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcStreamIndex.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcStreamIndex.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcEarMonitorMode;
	static UEnum* ERtcEarMonitorMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcEarMonitorMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcEarMonitorMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcEarMonitorMode"));
		}
		return Z_Registration_Info_UEnum_ERtcEarMonitorMode.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEarMonitorMode>()
	{
		return ERtcEarMonitorMode_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enumerators[] = {
		{ "ERtcEarMonitorMode::Off", (int64)ERtcEarMonitorMode::Off },
		{ "ERtcEarMonitorMode::On", (int64)ERtcEarMonitorMode::On },
		{ "ERtcEarMonitorMode::None", (int64)ERtcEarMonitorMode::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc ear monitor mode enum.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcEarMonitorMode::None" },
		{ "Off.Name", "ERtcEarMonitorMode::Off" },
		{ "On.Name", "ERtcEarMonitorMode::On" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc ear monitor mode enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcEarMonitorMode",
		"ERtcEarMonitorMode",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode()
	{
		if (!Z_Registration_Info_UEnum_ERtcEarMonitorMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcEarMonitorMode.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcEarMonitorMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcJoinRoomType;
	static UEnum* ERtcJoinRoomType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcJoinRoomType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcJoinRoomType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcJoinRoomType"));
		}
		return Z_Registration_Info_UEnum_ERtcJoinRoomType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcJoinRoomType>()
	{
		return ERtcJoinRoomType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enumerators[] = {
		{ "ERtcJoinRoomType::First", (int64)ERtcJoinRoomType::First },
		{ "ERtcJoinRoomType::Reconnected", (int64)ERtcJoinRoomType::Reconnected },
		{ "ERtcJoinRoomType::None", (int64)ERtcJoinRoomType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc join room type enum.</summary>\n" },
#endif
		{ "First.Name", "ERtcJoinRoomType::First" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcJoinRoomType::None" },
		{ "Reconnected.Name", "ERtcJoinRoomType::Reconnected" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc join room type enum.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcJoinRoomType",
		"ERtcJoinRoomType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType()
	{
		if (!Z_Registration_Info_UEnum_ERtcJoinRoomType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcJoinRoomType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcJoinRoomType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcUserLeaveReasonType;
	static UEnum* ERtcUserLeaveReasonType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcUserLeaveReasonType"));
		}
		return Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcUserLeaveReasonType>()
	{
		return ERtcUserLeaveReasonType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enumerators[] = {
		{ "ERtcUserLeaveReasonType::Quit", (int64)ERtcUserLeaveReasonType::Quit },
		{ "ERtcUserLeaveReasonType::Dropped", (int64)ERtcUserLeaveReasonType::Dropped },
		{ "ERtcUserLeaveReasonType::None", (int64)ERtcUserLeaveReasonType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc user leave reason type.</summary>\n" },
#endif
		{ "Dropped.Name", "ERtcUserLeaveReasonType::Dropped" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcUserLeaveReasonType::None" },
		{ "Quit.Name", "ERtcUserLeaveReasonType::Quit" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc user leave reason type.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcUserLeaveReasonType",
		"ERtcUserLeaveReasonType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType()
	{
		if (!Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcUserLeaveReasonType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcMediaDeviceType;
	static UEnum* ERtcMediaDeviceType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcMediaDeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceType"));
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceType>()
	{
		return ERtcMediaDeviceType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enumerators[] = {
		{ "ERtcMediaDeviceType::AudioUnknown", (int64)ERtcMediaDeviceType::AudioUnknown },
		{ "ERtcMediaDeviceType::AudioRenderDevice", (int64)ERtcMediaDeviceType::AudioRenderDevice },
		{ "ERtcMediaDeviceType::AudioCaptureDevice", (int64)ERtcMediaDeviceType::AudioCaptureDevice },
		{ "ERtcMediaDeviceType::None", (int64)ERtcMediaDeviceType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enum_MetaDataParams[] = {
		{ "AudioCaptureDevice.Name", "ERtcMediaDeviceType::AudioCaptureDevice" },
		{ "AudioRenderDevice.Name", "ERtcMediaDeviceType::AudioRenderDevice" },
		{ "AudioUnknown.Name", "ERtcMediaDeviceType::AudioUnknown" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc media device type.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcMediaDeviceType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc media device type.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcMediaDeviceType",
		"ERtcMediaDeviceType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcMediaDeviceType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcMediaDeviceState;
	static UEnum* ERtcMediaDeviceState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcMediaDeviceState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceState"));
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceState.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceState>()
	{
		return ERtcMediaDeviceState_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enumerators[] = {
		{ "ERtcMediaDeviceState::Started", (int64)ERtcMediaDeviceState::Started },
		{ "ERtcMediaDeviceState::Stopped", (int64)ERtcMediaDeviceState::Stopped },
		{ "ERtcMediaDeviceState::RuntimeError", (int64)ERtcMediaDeviceState::RuntimeError },
		{ "ERtcMediaDeviceState::Added", (int64)ERtcMediaDeviceState::Added },
		{ "ERtcMediaDeviceState::Removed", (int64)ERtcMediaDeviceState::Removed },
		{ "ERtcMediaDeviceState::None", (int64)ERtcMediaDeviceState::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enum_MetaDataParams[] = {
		{ "Added.Name", "ERtcMediaDeviceState::Added" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc media device state.</summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcMediaDeviceState::None" },
		{ "Removed.Name", "ERtcMediaDeviceState::Removed" },
		{ "RuntimeError.Name", "ERtcMediaDeviceState::RuntimeError" },
		{ "Started.Name", "ERtcMediaDeviceState::Started" },
		{ "Stopped.Name", "ERtcMediaDeviceState::Stopped" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc media device state.</summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcMediaDeviceState",
		"ERtcMediaDeviceState",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcMediaDeviceState.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcMediaDeviceError;
	static UEnum* ERtcMediaDeviceError_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceError.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcMediaDeviceError.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceError"));
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceError.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceError>()
	{
		return ERtcMediaDeviceError_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enumerators[] = {
		{ "ERtcMediaDeviceError::Ok", (int64)ERtcMediaDeviceError::Ok },
		{ "ERtcMediaDeviceError::NoPermission", (int64)ERtcMediaDeviceError::NoPermission },
		{ "ERtcMediaDeviceError::DeviceBusy", (int64)ERtcMediaDeviceError::DeviceBusy },
		{ "ERtcMediaDeviceError::DeviceFailure", (int64)ERtcMediaDeviceError::DeviceFailure },
		{ "ERtcMediaDeviceError::DeviceNotFound", (int64)ERtcMediaDeviceError::DeviceNotFound },
		{ "ERtcMediaDeviceError::DeviceDisconnected", (int64)ERtcMediaDeviceError::DeviceDisconnected },
		{ "ERtcMediaDeviceError::DeviceNoCallback", (int64)ERtcMediaDeviceError::DeviceNoCallback },
		{ "ERtcMediaDeviceError::UnSupporttedFormat", (int64)ERtcMediaDeviceError::UnSupporttedFormat },
		{ "ERtcMediaDeviceError::None", (int64)ERtcMediaDeviceError::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// <summary>Rtc media device error type.</summary>\n" },
#endif
		{ "DeviceBusy.Name", "ERtcMediaDeviceError::DeviceBusy" },
		{ "DeviceDisconnected.Name", "ERtcMediaDeviceError::DeviceDisconnected" },
		{ "DeviceFailure.Name", "ERtcMediaDeviceError::DeviceFailure" },
		{ "DeviceNoCallback.Name", "ERtcMediaDeviceError::DeviceNoCallback" },
		{ "DeviceNotFound.Name", "ERtcMediaDeviceError::DeviceNotFound" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcMediaDeviceError::None" },
		{ "NoPermission.Name", "ERtcMediaDeviceError::NoPermission" },
		{ "Ok.Name", "ERtcMediaDeviceError::Ok" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Rtc media device error type.</summary>" },
#endif
		{ "UnSupporttedFormat.Name", "ERtcMediaDeviceError::UnSupporttedFormat" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcMediaDeviceError",
		"ERtcMediaDeviceError",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaDeviceError.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcMediaDeviceError.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcMediaDeviceError.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcSyncInfoStreamType;
	static UEnum* ERtcSyncInfoStreamType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcSyncInfoStreamType"));
		}
		return Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcSyncInfoStreamType>()
	{
		return ERtcSyncInfoStreamType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enumerators[] = {
		{ "ERtcSyncInfoStreamType::Audio", (int64)ERtcSyncInfoStreamType::Audio },
		{ "ERtcSyncInfoStreamType::None", (int64)ERtcSyncInfoStreamType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enum_MetaDataParams[] = {
		{ "Audio.Name", "ERtcSyncInfoStreamType::Audio" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcSyncInfoStreamType::None" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcSyncInfoStreamType",
		"ERtcSyncInfoStreamType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType()
	{
		if (!Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcSyncInfoStreamType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcSyncInfoStreamType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcMediaStreamType;
	static UEnum* ERtcMediaStreamType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaStreamType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcMediaStreamType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaStreamType"));
		}
		return Z_Registration_Info_UEnum_ERtcMediaStreamType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaStreamType>()
	{
		return ERtcMediaStreamType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enumerators[] = {
		{ "ERtcMediaStreamType::Audio", (int64)ERtcMediaStreamType::Audio },
		{ "ERtcMediaStreamType::Video", (int64)ERtcMediaStreamType::Video },
		{ "ERtcMediaStreamType::Both", (int64)ERtcMediaStreamType::Both },
		{ "ERtcMediaStreamType::None", (int64)ERtcMediaStreamType::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enum_MetaDataParams[] = {
		{ "Audio.Name", "ERtcMediaStreamType::Audio" },
		{ "BlueprintType", "true" },
		{ "Both.Name", "ERtcMediaStreamType::Both" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcMediaStreamType::None" },
		{ "Video.Name", "ERtcMediaStreamType::Video" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcMediaStreamType",
		"ERtcMediaStreamType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType()
	{
		if (!Z_Registration_Info_UEnum_ERtcMediaStreamType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcMediaStreamType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaStreamType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcMediaStreamType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERtcStreamRemoveReason;
	static UEnum* ERtcStreamRemoveReason_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERtcStreamRemoveReason.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERtcStreamRemoveReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcStreamRemoveReason"));
		}
		return Z_Registration_Info_UEnum_ERtcStreamRemoveReason.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamRemoveReason>()
	{
		return ERtcStreamRemoveReason_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enumerators[] = {
		{ "ERtcStreamRemoveReason::Unpublish", (int64)ERtcStreamRemoveReason::Unpublish },
		{ "ERtcStreamRemoveReason::PublishFailed", (int64)ERtcStreamRemoveReason::PublishFailed },
		{ "ERtcStreamRemoveReason::KeepLiveFailed", (int64)ERtcStreamRemoveReason::KeepLiveFailed },
		{ "ERtcStreamRemoveReason::ClientDisconnected", (int64)ERtcStreamRemoveReason::ClientDisconnected },
		{ "ERtcStreamRemoveReason::Republish", (int64)ERtcStreamRemoveReason::Republish },
		{ "ERtcStreamRemoveReason::Other", (int64)ERtcStreamRemoveReason::Other },
		{ "ERtcStreamRemoveReason::None", (int64)ERtcStreamRemoveReason::None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClientDisconnected.Name", "ERtcStreamRemoveReason::ClientDisconnected" },
		{ "KeepLiveFailed.Name", "ERtcStreamRemoveReason::KeepLiveFailed" },
		{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
		{ "None.Name", "ERtcStreamRemoveReason::None" },
		{ "Other.Name", "ERtcStreamRemoveReason::Other" },
		{ "PublishFailed.Name", "ERtcStreamRemoveReason::PublishFailed" },
		{ "Republish.Name", "ERtcStreamRemoveReason::Republish" },
		{ "Unpublish.Name", "ERtcStreamRemoveReason::Unpublish" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERtcStreamRemoveReason",
		"ERtcStreamRemoveReason",
		Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason()
	{
		if (!Z_Registration_Info_UEnum_ERtcStreamRemoveReason.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERtcStreamRemoveReason.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamRemoveReason_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERtcStreamRemoveReason.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h_Statics::EnumInfo[] = {
		{ ERtcPrivilege_StaticEnum, TEXT("ERtcPrivilege"), &Z_Registration_Info_UEnum_ERtcPrivilege, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1602453822U) },
		{ ERtcEngineInitResult_StaticEnum, TEXT("ERtcEngineInitResult"), &Z_Registration_Info_UEnum_ERtcEngineInitResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3908106620U) },
		{ ERtcRoomProfileType_StaticEnum, TEXT("ERtcRoomProfileType"), &Z_Registration_Info_UEnum_ERtcRoomProfileType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 810122025U) },
		{ ERtcMuteState_StaticEnum, TEXT("ERtcMuteState"), &Z_Registration_Info_UEnum_ERtcMuteState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2512930427U) },
		{ ERtcPauseResumeMediaType_StaticEnum, TEXT("ERtcPauseResumeMediaType"), &Z_Registration_Info_UEnum_ERtcPauseResumeMediaType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2242579442U) },
		{ ERtcAudioPlaybackDevice_StaticEnum, TEXT("ERtcAudioPlaybackDevice"), &Z_Registration_Info_UEnum_ERtcAudioPlaybackDevice, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2148689909U) },
		{ ERtcAudioScenarioType_StaticEnum, TEXT("ERtcAudioScenarioType"), &Z_Registration_Info_UEnum_ERtcAudioScenarioType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1127386998U) },
		{ ERtcStreamIndex_StaticEnum, TEXT("ERtcStreamIndex"), &Z_Registration_Info_UEnum_ERtcStreamIndex, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1282499610U) },
		{ ERtcEarMonitorMode_StaticEnum, TEXT("ERtcEarMonitorMode"), &Z_Registration_Info_UEnum_ERtcEarMonitorMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4136591821U) },
		{ ERtcJoinRoomType_StaticEnum, TEXT("ERtcJoinRoomType"), &Z_Registration_Info_UEnum_ERtcJoinRoomType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4252363224U) },
		{ ERtcUserLeaveReasonType_StaticEnum, TEXT("ERtcUserLeaveReasonType"), &Z_Registration_Info_UEnum_ERtcUserLeaveReasonType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1235459387U) },
		{ ERtcMediaDeviceType_StaticEnum, TEXT("ERtcMediaDeviceType"), &Z_Registration_Info_UEnum_ERtcMediaDeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1131326753U) },
		{ ERtcMediaDeviceState_StaticEnum, TEXT("ERtcMediaDeviceState"), &Z_Registration_Info_UEnum_ERtcMediaDeviceState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 240893743U) },
		{ ERtcMediaDeviceError_StaticEnum, TEXT("ERtcMediaDeviceError"), &Z_Registration_Info_UEnum_ERtcMediaDeviceError, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1069356809U) },
		{ ERtcSyncInfoStreamType_StaticEnum, TEXT("ERtcSyncInfoStreamType"), &Z_Registration_Info_UEnum_ERtcSyncInfoStreamType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3271249062U) },
		{ ERtcMediaStreamType_StaticEnum, TEXT("ERtcMediaStreamType"), &Z_Registration_Info_UEnum_ERtcMediaStreamType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1326565376U) },
		{ ERtcStreamRemoveReason_StaticEnum, TEXT("ERtcStreamRemoveReason"), &Z_Registration_Info_UEnum_ERtcStreamRemoveReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4256790858U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h_1188710943(TEXT("/Script/OnlineSubsystemPico"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
