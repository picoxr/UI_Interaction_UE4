// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RTCPicoUserInterface.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ONLINESUBSYSTEMPICO_RTCPicoUserInterface_generated_h
#error "RTCPicoUserInterface.generated.h already included, missing '#pragma once' in RTCPicoUserInterface.h"
#endif
#define ONLINESUBSYSTEMPICO_RTCPicoUserInterface_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_RTCPicoUserInterface_h


#define FOREACH_ENUM_ERTCPRIVILEGE(op) \
	op(ERtcPrivilege::PublishStream) \
	op(ERtcPrivilege::PublishAudioStream) \
	op(ERtcPrivilege::PublishVideoStream) \
	op(ERtcPrivilege::SubscribeStream) \
	op(ERtcPrivilege::None) 

enum class ERtcPrivilege : uint8;
template<> struct TIsUEnumClass<ERtcPrivilege> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPrivilege>();

#define FOREACH_ENUM_ERTCENGINEINITRESULT(op) \
	op(ERtcEngineInitResult::Unknow) \
	op(ERtcEngineInitResult::AlreadyInitialized) \
	op(ERtcEngineInitResult::InvalidConfig) \
	op(ERtcEngineInitResult::Success) \
	op(ERtcEngineInitResult::None) 

enum class ERtcEngineInitResult : uint8;
template<> struct TIsUEnumClass<ERtcEngineInitResult> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEngineInitResult>();

#define FOREACH_ENUM_ERTCROOMPROFILETYPE(op) \
	op(ERtcRoomProfileType::Communication) \
	op(ERtcRoomProfileType::LiveBroadcasting) \
	op(ERtcRoomProfileType::Game) \
	op(ERtcRoomProfileType::CloundGame) \
	op(ERtcRoomProfileType::LowLatency) \
	op(ERtcRoomProfileType::None) 

enum class ERtcRoomProfileType : uint8;
template<> struct TIsUEnumClass<ERtcRoomProfileType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcRoomProfileType>();

#define FOREACH_ENUM_ERTCMUTESTATE(op) \
	op(ERtcMuteState::Off) \
	op(ERtcMuteState::On) \
	op(ERtcMuteState::None) 

enum class ERtcMuteState : uint8;
template<> struct TIsUEnumClass<ERtcMuteState> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMuteState>();

#define FOREACH_ENUM_ERTCPAUSERESUMEMEDIATYPE(op) \
	op(ERtcPauseResumeMediaType::Audio) \
	op(ERtcPauseResumeMediaType::Video) \
	op(ERtcPauseResumeMediaType::AudioAndVideo) \
	op(ERtcPauseResumeMediaType::None) 

enum class ERtcPauseResumeMediaType : uint8;
template<> struct TIsUEnumClass<ERtcPauseResumeMediaType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPauseResumeMediaType>();

#define FOREACH_ENUM_ERTCAUDIOPLAYBACKDEVICE(op) \
	op(ERtcAudioPlaybackDevice::Headset) \
	op(ERtcAudioPlaybackDevice::EarPiece) \
	op(ERtcAudioPlaybackDevice::SpeakerPhone) \
	op(ERtcAudioPlaybackDevice::HeadsetBlueTooth) \
	op(ERtcAudioPlaybackDevice::HeadsetUsb) \
	op(ERtcAudioPlaybackDevice::None) 

enum class ERtcAudioPlaybackDevice : uint8;
template<> struct TIsUEnumClass<ERtcAudioPlaybackDevice> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioPlaybackDevice>();

#define FOREACH_ENUM_ERTCAUDIOSCENARIOTYPE(op) \
	op(ERtcAudioScenarioType::Music) \
	op(ERtcAudioScenarioType::HighQualityCommunication) \
	op(ERtcAudioScenarioType::Communication) \
	op(ERtcAudioScenarioType::Media) \
	op(ERtcAudioScenarioType::GameStreaming) \
	op(ERtcAudioScenarioType::None) 

enum class ERtcAudioScenarioType : uint8;
template<> struct TIsUEnumClass<ERtcAudioScenarioType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioScenarioType>();

#define FOREACH_ENUM_ERTCSTREAMINDEX(op) \
	op(ERtcStreamIndex::Main) \
	op(ERtcStreamIndex::Screen) \
	op(ERtcStreamIndex::None) 

enum class ERtcStreamIndex : uint8;
template<> struct TIsUEnumClass<ERtcStreamIndex> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamIndex>();

#define FOREACH_ENUM_ERTCEARMONITORMODE(op) \
	op(ERtcEarMonitorMode::Off) \
	op(ERtcEarMonitorMode::On) \
	op(ERtcEarMonitorMode::None) 

enum class ERtcEarMonitorMode : uint8;
template<> struct TIsUEnumClass<ERtcEarMonitorMode> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEarMonitorMode>();

#define FOREACH_ENUM_ERTCJOINROOMTYPE(op) \
	op(ERtcJoinRoomType::First) \
	op(ERtcJoinRoomType::Reconnected) \
	op(ERtcJoinRoomType::None) 

enum class ERtcJoinRoomType : uint8;
template<> struct TIsUEnumClass<ERtcJoinRoomType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcJoinRoomType>();

#define FOREACH_ENUM_ERTCUSERLEAVEREASONTYPE(op) \
	op(ERtcUserLeaveReasonType::Quit) \
	op(ERtcUserLeaveReasonType::Dropped) \
	op(ERtcUserLeaveReasonType::None) 

enum class ERtcUserLeaveReasonType : uint8;
template<> struct TIsUEnumClass<ERtcUserLeaveReasonType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcUserLeaveReasonType>();

#define FOREACH_ENUM_ERTCMEDIADEVICETYPE(op) \
	op(ERtcMediaDeviceType::AudioUnknown) \
	op(ERtcMediaDeviceType::AudioRenderDevice) \
	op(ERtcMediaDeviceType::AudioCaptureDevice) \
	op(ERtcMediaDeviceType::None) 

enum class ERtcMediaDeviceType : uint8;
template<> struct TIsUEnumClass<ERtcMediaDeviceType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceType>();

#define FOREACH_ENUM_ERTCMEDIADEVICESTATE(op) \
	op(ERtcMediaDeviceState::Started) \
	op(ERtcMediaDeviceState::Stopped) \
	op(ERtcMediaDeviceState::RuntimeError) \
	op(ERtcMediaDeviceState::Added) \
	op(ERtcMediaDeviceState::Removed) \
	op(ERtcMediaDeviceState::None) 

enum class ERtcMediaDeviceState : uint8;
template<> struct TIsUEnumClass<ERtcMediaDeviceState> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceState>();

#define FOREACH_ENUM_ERTCMEDIADEVICEERROR(op) \
	op(ERtcMediaDeviceError::Ok) \
	op(ERtcMediaDeviceError::NoPermission) \
	op(ERtcMediaDeviceError::DeviceBusy) \
	op(ERtcMediaDeviceError::DeviceFailure) \
	op(ERtcMediaDeviceError::DeviceNotFound) \
	op(ERtcMediaDeviceError::DeviceDisconnected) \
	op(ERtcMediaDeviceError::DeviceNoCallback) \
	op(ERtcMediaDeviceError::UnSupporttedFormat) \
	op(ERtcMediaDeviceError::None) 

enum class ERtcMediaDeviceError : uint8;
template<> struct TIsUEnumClass<ERtcMediaDeviceError> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceError>();

#define FOREACH_ENUM_ERTCSYNCINFOSTREAMTYPE(op) \
	op(ERtcSyncInfoStreamType::Audio) \
	op(ERtcSyncInfoStreamType::None) 

enum class ERtcSyncInfoStreamType : uint8;
template<> struct TIsUEnumClass<ERtcSyncInfoStreamType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcSyncInfoStreamType>();

#define FOREACH_ENUM_ERTCMEDIASTREAMTYPE(op) \
	op(ERtcMediaStreamType::Audio) \
	op(ERtcMediaStreamType::Video) \
	op(ERtcMediaStreamType::Both) \
	op(ERtcMediaStreamType::None) 

enum class ERtcMediaStreamType : uint8;
template<> struct TIsUEnumClass<ERtcMediaStreamType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaStreamType>();

#define FOREACH_ENUM_ERTCSTREAMREMOVEREASON(op) \
	op(ERtcStreamRemoveReason::Unpublish) \
	op(ERtcStreamRemoveReason::PublishFailed) \
	op(ERtcStreamRemoveReason::KeepLiveFailed) \
	op(ERtcStreamRemoveReason::ClientDisconnected) \
	op(ERtcStreamRemoveReason::Republish) \
	op(ERtcStreamRemoveReason::Other) \
	op(ERtcStreamRemoveReason::None) 

enum class ERtcStreamRemoveReason : uint8;
template<> struct TIsUEnumClass<ERtcStreamRemoveReason> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamRemoveReason>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
