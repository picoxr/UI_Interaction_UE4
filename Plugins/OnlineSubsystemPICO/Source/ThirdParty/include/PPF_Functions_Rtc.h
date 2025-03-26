

#ifndef PPF_FUNCTIONS_RTC_H
#define PPF_FUNCTIONS_RTC_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"
#include "PPF_RtcMuteState.h"
#include "PPF_RtcPauseResumeMediaType.h"
#include "PPF_RtcMediaStreamType.h"
#include "PPF_RtcEngineInitResult.h"
#include "PPF_RtcEarMonitorMode.h"
#include "PPF_RtcAudioPropertyOptions.h"
#include "PPF_RtcStreamSyncInfoOptions.h"
#include "PPF_RtcScreenMediaType.h"
#include "PPF_RtcAudioScenarioType.h"
#include "PPF_RtcAudioPlaybackDevice.h"
#include "PPF_RtcRoomOptions.h"
#include "PPF_RtcAudioSourceType.h"
#include "PPF_RtcStreamIndex.h"
#include "PPF_RtcVideoEncoderOptions.h"
#include "PPF_RtcVideoSourceType.h"
#include "PPF_RtcAudioFrameOptions.h"
#include "PPF_RtcVideoFrameOptions.h"

#ifdef __ANDROID__

#include <jni.h>
PPF_PUBLIC_FUNCTION(bool) ppf_Rtc_SetHardWareEncodeContext(jobject j_egl_context);
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_ClearHardWareEncodeContext();
#endif
/// @file PPF_Functions_Rtc.h
/// @ingroup RTC

/// @brief Initialize the RTC engine.
///
/// @return The initialize result.
///
/// Should call this function before using RTC related functions.
PPF_PUBLIC_FUNCTION(ppfRtcEngineInitResult) ppf_Rtc_InitRtcEngine();
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_UnInitRtcEngine();

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


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_PublishScreen(const char* roomId,ppfRtcMediaStreamType streamType);

PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomPublishStream(const char* roomId,ppfRtcMediaStreamType streamType);

PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomSetRemoteAudioPlaybackVolume(const char* roomId,const char*userId,int volume);

// v3
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomSubscribeStream(const char* roomId,const char* userId,ppfRtcMediaStreamType mediaType);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomUnPublishStream(const char* roomId,ppfRtcMediaStreamType streamType);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RoomUnsubscribeStream(const char* roomId,const char* userId,ppfRtcMediaStreamType mediaType);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Rtc_SendRoomBinaryMessage(const char* roomId,UInt8Array message,int length);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Rtc_SendRoomMessage(const char* roomId,const char* message);

// engine 8个
PPF_PUBLIC_FUNCTION(int) ppf_Rtc_SendStreamSyncInfo(UInt8Array data,int length,ppfRtcStreamSyncInfoOptionsHandle config);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Rtc_SendUserBinaryMessage(const char* roomId,const char* userId,UInt8Array message,int length);


PPF_PUBLIC_FUNCTION(int64_t) ppf_Rtc_SendUserMessage(const char* roomId,const char* userId,const char* message);


PPF_PUBLIC_FUNCTION(int) ppf_Rtc_SetAudioSourceType(ppfRtcAudioSourceType type);


// 视频相关
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetScreenAudioSourceType(ppfRtcAudioSourceType sourceType);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetScreenAudioStreamIndex(ppfRtcStreamIndex index);


PPF_PUBLIC_FUNCTION(int) ppf_Rtc_SetScreenVideoEncoderConfig(ppfRtcVideoEncoderOptionsHandle config);

/*
i32 PushScreenAudioFrame(1:AudioFrame audioFrame);
i32 PushScreenFrame(1:VideoFrame videoFrame);
i32 PushExternalAudioFrame(1:AudioFrame audioFrame);
i32 PushExternalVideoFrame(1:VideoFrame videoFrame);
*/

PPF_PUBLIC_FUNCTION(int) ppf_Rtc_SetVideoEncoderConfig(ppfRtcVideoEncoderOptionsHandle config);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_SetVideoSourceType(ppfRtcStreamIndex streamIndex,ppfRtcVideoSourceType type);

PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StartScreenCapture(ppfRtcScreenMediaType mediaType,void* context);


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StartVideoCapture();

PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StopScreenCapture();


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_StopVideoCapture();


PPF_PUBLIC_FUNCTION(void) ppf_Rtc_UnPublishScreen(const char* roomId,ppfRtcMediaStreamType streamType);


PPF_PUBLIC_FUNCTION(int) ppf_Rtc_PushExternalAudioFrame(ppfRtcAudioFrameOptionsHandle audioFrame);


PPF_PUBLIC_FUNCTION(int) ppf_Rtc_PushExternalVideoFrame(ppfRtcVideoFrameOptionsHandle videoFrame);

// 自定义视频流和音频流
PPF_PUBLIC_FUNCTION(int) ppf_Rtc_PushScreenAudioFrame(ppfRtcAudioFrameOptionsHandle audioFrame);


PPF_PUBLIC_FUNCTION(int) ppf_Rtc_PushScreenVideoFrame(ppfRtcVideoFrameOptionsHandle videoFrame);

typedef int ppf_Rtc_ProcessAudioFrameFunction(void* audioFrameHandle);
PPF_PUBLIC_FUNCTION(void) ppf_Rtc_RegisterLocalAudioProcessor(ppf_Rtc_ProcessAudioFrameFunction processAudioFrameFunction,ppfRtcAudioChannel channel,ppfRtcAudioSampleRate sampleRate);
#endif

