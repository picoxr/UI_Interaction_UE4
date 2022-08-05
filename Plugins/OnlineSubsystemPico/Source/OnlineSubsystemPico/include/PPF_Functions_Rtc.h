// This file is generated automatically. Please don't edit it.

#ifndef PPF_FUNCTIONS_RTC_H
#define PPF_FUNCTIONS_RTC_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
#include "PPF_RtcEarMonitorMode.h"
#include "PPF_RtcAudioScenarioType.h"
#include "PPF_RtcPauseResumeMediaType.h"
#include "PPF_RtcAudioPlaybackDevice.h"
#include "PPF_RtcRoomOptions.h"
#include "PPF_RtcEngineInitResult.h"
#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcMuteState.h"
#include "PPF_RtcAudioPropertyOptions.h"

/// @file PPF_Functions_Rtc.h
/// @ingroup RTC

/// @brief Initialize the RTC engine.
///
/// @return The initialize result.
///
/// Should call this function before using RTC related functions.
PPF_PUBLIC_FUNCTION(ppfRtcEngineInitResult) ppf_Rtc_InitRtcEngine();

/// @brief Create or join a RTC room.
///
/// @param roomOptions The options to create RTC room.
/// @return The join room result.
PPF_PUBLIC_FUNCTION(int) ppf_Rtc_JoinRoom(ppfRtcRoomOptionsHandle roomOptions);


/// @brief Leave a RTC room.
///
/// @param roomId Which room to leave.
/// @return The leave room result.
PPF_PUBLIC_FUNCTION(int) ppf_Rtc_LeaveRoom(const char* roomId);


/// @brief Destory a RTC room.
///
/// @param roomId Which room to be destroyed.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_DestroyRoom(const char* roomId);


/// @brief Publish a RTC room.
///
/// @param roomId Which room to be published.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_PublishRoom(const char* roomId);

/// @brief Unpublish a RTC room.
///
/// @param roomId Which room to be unpublished.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_UnPublishRoom(const char* roomId);


/// @brief Update RTC token.
///
/// @param roomId Which room's token to be updated.
/// @param token The old token which will be updated.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_UpdateToken(const char* roomId,const char* token);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_EnableAudioPropertiesReport(ppfRtcAudioPropertyOptionsHandle config);

/// @brief Enable or disable local audio.
///
/// @param muteState enable or disable.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_MuteLocalAudio(ppfRtcMuteState muteState);

/// @brief Pause subscribe all media stream for specified room.
///
/// @param roomId the specified room.
/// @param mediaType the media stream type.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomPauseAllSubscribedStream(const char* roomId,ppfRtcPauseResumeMediaType mediaType);

/// @brief Resume subscribe all media stream for specified room.
///
/// @param roomId the specified room.
/// @param mediaType the media stream type.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomResumeAllSubscribedStream(const char* roomId,ppfRtcPauseResumeMediaType mediaType);

/// @brief Set on which device to playback audio.
///
/// @param device The device to be used.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetAudioPlaybackDevice(ppfRtcAudioPlaybackDevice device);


/// @brief Set the audio scenario.
///
/// @param scenario The scenario to be set.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetAudioScenario(ppfRtcAudioScenarioType scenario);


/// @brief Set audio capture's volume.
///
/// @param index Which audio stream source.
/// @param volume The audio capture volume to be set.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetCaptureVolume(ppfRtcStreamIndex index,int volume);

/// @brief Set the ear monitor mode.
///
/// @param earMonitorMode The ear monitor mode to be set.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetEarMonitorMode(ppfRtcEarMonitorMode earMonitorMode);

/// @brief Set the ear monitor volume.
///
/// @param volume The ear monitor volume to be set.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetEarMonitorVolume(int volume);

/// @brief Set audio playback's volume.
///
/// @param volume The audio playback volume to be set.
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetPlaybackVolume(int volume);

/// @brief Start audio capture.
///
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StartAudioCapture();

/// @brief Stop audio capture.
///
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StopAudioCapture();


#endif

