// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ONLINESUBSYSTEMPICO_RTCPicoUserInterface_generated_h
#error "RTCPicoUserInterface.generated.h already included, missing '#pragma once' in RTCPicoUserInterface.h"
#endif
#define ONLINESUBSYSTEMPICO_RTCPicoUserInterface_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h


#define FOREACH_ENUM_ERTCMEDIADEVICEERROR(op) \
	op(ERtcMediaDeviceError::None) \
	op(ERtcMediaDeviceError::Ok) \
	op(ERtcMediaDeviceError::NoPermission) \
	op(ERtcMediaDeviceError::DeviceBusy) \
	op(ERtcMediaDeviceError::DeviceFailure) \
	op(ERtcMediaDeviceError::DeviceNotFound) \
	op(ERtcMediaDeviceError::DeviceDisconnected) \
	op(ERtcMediaDeviceError::DeviceNoCallback) \
	op(ERtcMediaDeviceError::UnSupporttedFormat) 

enum class ERtcMediaDeviceError : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceError>();

#define FOREACH_ENUM_ERTCMEDIADEVICESTATE(op) \
	op(ERtcMediaDeviceState::None) \
	op(ERtcMediaDeviceState::Started) \
	op(ERtcMediaDeviceState::Stopped) \
	op(ERtcMediaDeviceState::RuntimeError) \
	op(ERtcMediaDeviceState::Added) \
	op(ERtcMediaDeviceState::Removed) 

enum class ERtcMediaDeviceState : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceState>();

#define FOREACH_ENUM_ERTCMEDIADEVICETYPE(op) \
	op(ERtcMediaDeviceType::None) \
	op(ERtcMediaDeviceType::AudioUnknown) \
	op(ERtcMediaDeviceType::AudioRenderDevice) \
	op(ERtcMediaDeviceType::AudioCaptureDevice) 

enum class ERtcMediaDeviceType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceType>();

#define FOREACH_ENUM_ERTCUSERLEAVEREASONTYPE(op) \
	op(ERtcUserLeaveReasonType::None) \
	op(ERtcUserLeaveReasonType::Quit) \
	op(ERtcUserLeaveReasonType::Dropped) 

enum class ERtcUserLeaveReasonType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcUserLeaveReasonType>();

#define FOREACH_ENUM_ERTCJOINROOMTYPE(op) \
	op(ERtcJoinRoomType::None) \
	op(ERtcJoinRoomType::First) \
	op(ERtcJoinRoomType::Reconnected) 

enum class ERtcJoinRoomType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcJoinRoomType>();

#define FOREACH_ENUM_ERTCEARMONITORMODE(op) \
	op(ERtcEarMonitorMode::None) \
	op(ERtcEarMonitorMode::Off) \
	op(ERtcEarMonitorMode::On) 

enum class ERtcEarMonitorMode : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEarMonitorMode>();

#define FOREACH_ENUM_ERTCSTREAMINDEX(op) \
	op(ERtcStreamIndex::None) \
	op(ERtcStreamIndex::Main) \
	op(ERtcStreamIndex::Screen) 

enum class ERtcStreamIndex : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamIndex>();

#define FOREACH_ENUM_ERTCAUDIOSCENARIOTYPE(op) \
	op(ERtcAudioScenarioType::None) \
	op(ERtcAudioScenarioType::Music) \
	op(ERtcAudioScenarioType::HighQualityCommunication) \
	op(ERtcAudioScenarioType::Communication) \
	op(ERtcAudioScenarioType::Media) \
	op(ERtcAudioScenarioType::GameStreaming) 

enum class ERtcAudioScenarioType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioScenarioType>();

#define FOREACH_ENUM_ERTCAUDIOPLAYBACKDEVICE(op) \
	op(ERtcAudioPlaybackDevice::None) \
	op(ERtcAudioPlaybackDevice::Headset) \
	op(ERtcAudioPlaybackDevice::EarPiece) \
	op(ERtcAudioPlaybackDevice::SpeakerPhone) \
	op(ERtcAudioPlaybackDevice::HeadsetBlueTooth) \
	op(ERtcAudioPlaybackDevice::HeadsetUsb) 

enum class ERtcAudioPlaybackDevice : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioPlaybackDevice>();

#define FOREACH_ENUM_ERTCPAUSERESUMEMEDIATYPE(op) \
	op(ERtcPauseResumeMediaType::None) \
	op(ERtcPauseResumeMediaType::Audio) \
	op(ERtcPauseResumeMediaType::Video) \
	op(ERtcPauseResumeMediaType::AudioAndVideo) 

enum class ERtcPauseResumeMediaType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPauseResumeMediaType>();

#define FOREACH_ENUM_ERTCMUTESTATE(op) \
	op(ERtcMuteState::None) \
	op(ERtcMuteState::Off) \
	op(ERtcMuteState::On) 

enum class ERtcMuteState : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMuteState>();

#define FOREACH_ENUM_ERTCROOMPROFILETYPE(op) \
	op(ERtcRoomProfileType::None) \
	op(ERtcRoomProfileType::Communication) \
	op(ERtcRoomProfileType::LiveBroadcasting) \
	op(ERtcRoomProfileType::Game) \
	op(ERtcRoomProfileType::CloundGame) \
	op(ERtcRoomProfileType::LowLatency) 

enum class ERtcRoomProfileType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcRoomProfileType>();

#define FOREACH_ENUM_ERTCENGINEINITRESULT(op) \
	op(ERtcEngineInitResult::None) \
	op(ERtcEngineInitResult::Unknow) \
	op(ERtcEngineInitResult::AlreadyInitialized) \
	op(ERtcEngineInitResult::InvalidConfig) \
	op(ERtcEngineInitResult::Success) 

enum class ERtcEngineInitResult : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEngineInitResult>();

#define FOREACH_ENUM_ERTCPRIVILEGE(op) \
	op(ERtcPrivilege::None) \
	op(ERtcPrivilege::PublishStream) \
	op(ERtcPrivilege::PublishAudioStream) \
	op(ERtcPrivilege::PublishVideoStream) \
	op(ERtcPrivilege::SubscribeStream) 

enum class ERtcPrivilege : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPrivilege>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
