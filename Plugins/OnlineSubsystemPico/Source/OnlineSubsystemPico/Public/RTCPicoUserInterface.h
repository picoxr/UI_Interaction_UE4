// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineSubsystemPicoNames.h"

/// @file RTCPicoUserInterface.h

DECLARE_LOG_CATEGORY_EXTERN(RtcInterface, Log, All);

/// @brief Rtc engine privilege enum.
UENUM(BlueprintType)
enum class ERtcPrivilege : uint8
{
    None,
    PublishStream,
    PublishAudioStream,
    PublishVideoStream,
    SubscribeStream
};

/// @brief Rtc engine init result enum.
UENUM(BlueprintType)
enum class ERtcEngineInitResult : uint8
{
    None,
    Unknow,
    AlreadyInitialized,
    InvalidConfig,
    Success
};

/// @brief Rtc engine room profile type enum.
UENUM(BlueprintType)
enum class ERtcRoomProfileType : uint8
{
    None,
    Communication,
    LiveBroadcasting,
    Game,
    CloundGame,
    LowLatency
};

/// @brief Rtc mute state enum.
UENUM(BlueprintType)
enum class ERtcMuteState : uint8
{
    None,
    Off,
    On
};

/// @brief Rtc pause or resume media type enum.
UENUM(BlueprintType)
enum class ERtcPauseResumeMediaType : uint8
{
    None,
    Audio,
    Video,
    AudioAndVideo
};

/// @brief Rtc audio playback device enum.
UENUM(BlueprintType)
enum class ERtcAudioPlaybackDevice : uint8
{
    None,
    Headset,
    EarPiece,
    SpeakerPhone,
    HeadsetBlueTooth,
    HeadsetUsb
};

/// @brief Rtc audio scenario type enum.
UENUM(BlueprintType)
enum class ERtcAudioScenarioType : uint8
{
    None,
    Music,
    HighQualityCommunication,
    Communication,
    Media,
    GameStreaming
};

/// @brief Rtc audio stream index enum.
UENUM(BlueprintType)
enum class ERtcStreamIndex : uint8
{
    None,
    Main,
    Screen
};

/// @brief Rtc ear monitor mode enum.
UENUM(BlueprintType)
enum class ERtcEarMonitorMode : uint8
{
    None,
    Off,
    On
};

/// @brief Rtc join room type enum.
UENUM(BlueprintType)
enum class ERtcJoinRoomType : uint8
{
    None,
    First,
    Reconnected
};

/// @brief Rtc user leave reason type.
UENUM(BlueprintType)
enum class ERtcUserLeaveReasonType : uint8
{
    None,
    Quit,
    Dropped
};

/// @brief Rtc media device type.
UENUM(BlueprintType)
enum class ERtcMediaDeviceType : uint8
{
    None,
    AudioUnknown,
    AudioRenderDevice,
    AudioCaptureDevice
};

/// @brief Rtc media device state.
UENUM(BlueprintType)
enum class ERtcMediaDeviceState : uint8
{
    None,
    Started,
    Stopped,
    RuntimeError,
    Added,
    Removed
};

/// @brief Rtc media device error type.
UENUM(BlueprintType)
enum class ERtcMediaDeviceError : uint8
{
    None,
    Ok,
    NoPermission,
    DeviceBusy,
    DeviceFailure,
    DeviceNotFound,
    DeviceDisconnected,
    DeviceNoCallback,
    UnSupporttedFormat
};

// Request
DECLARE_DELEGATE_ThreeParams(FOnGetTokenComplete, const FString& /*String Token*/, bool /*IsError*/, const FString& /*Error Message*/);

// Notification
DECLARE_MULTICAST_DELEGATE_FiveParams(FRtcJoinRoomResult, const FString& /*RoomId*/, const FString& /*UserId*/, int /*ErrorCode*/, int /*Elapsed*/, ERtcJoinRoomType /*JoinRoomType*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FRtcLeaveRoomReault, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcRoomState, int /*TotalDuration*/, int /*UserCount*/, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FRtcUserJoinInfo, const FString& /*UserId*/, const FString& /*UserExtra*/, int /*Elapsed*/, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcUserLeaveInfo, const FString& /*UserId*/, ERtcUserLeaveReasonType /*RtcUserLeaveReasonType*/, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FRtcRoomWarn, int /*Code*/, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FRtcRoomError, int /*Code*/, const FString& /*RoomId*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FRtcUserMuteAudioInfo, const FString& /*UserId*/, ERtcMuteState /*RtcMuteState*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FRtcAudioChangePlaybackDevice, ERtcAudioPlaybackDevice /*RtcAudioPlaybackDevice*/);
DECLARE_MULTICAST_DELEGATE_FourParams(FRtcMediaDeviceChangeInfo, const FString& /*DeviceId*/, ERtcMediaDeviceType /*MediaDeciveType*/, ERtcMediaDeviceState /*MediaDeviceState*/, ERtcMediaDeviceError /*MediaDeviceError*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FRtcLocalAudioPropertiesReport, TArray<ERtcStreamIndex>  /*StreamIndex*/, TArray<int> /*Volume Array*/);
DECLARE_MULTICAST_DELEGATE_FiveParams(FRtcRemoteAudioPropertiesReport, int /*TotalRemoteVolume*/, TArray<int> /*Volume Array*/, const TArray<FString>& /*RoomId Array*/, const TArray<FString>&  /*UserId Array*/, TArray<ERtcStreamIndex>  /*StreamIndex Array*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FRtcStringResult, const FString& /*MessageString*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FRtcIntResult, int /*MessageCode*/);


/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup RTC RTC
 *  This is the RTC group
 *  @{
 */

/// @brief Pico RTC interface class.
class ONLINESUBSYSTEMPICO_API FRTCPicoUserInterface
{
private:

	FOnlineSubsystemPico& PicoSubsystem;

	
public:
	FRTCPicoUserInterface(FOnlineSubsystemPico& InSubsystem);
	~FRTCPicoUserInterface();

	// Rtc Function


    /// @brief Initializes the RTC engine.
    /// @return The initialization result.
	ERtcEngineInitResult RtcEngineInit();


    /// @brief Joins a user to a room.
    /// @param RoomId Room ID.
    /// @param UserId User ID.
    /// @param Token Room token.
    /// @param UserExtra Extra information added by the user.
    /// @param InRoomProfileType Room type: `0`-communication room; `1`-live broadcasting room; `2`-game room; `3`-cloud game room; `4`-low-latency room.
    /// @param bIsAutoSubscribeAudio Whether to automatically subscribe to the audio of the room: `true`-yes; `false`-no.
    /// @return Int: `0` indicates success, and other values indicate failure.
	int RtcJoinRoom(const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio);
	

    /// @brief Destroys a room.
    /// @param RoomId Room ID.
    /// @return Int: `0` indicates success, and other values indicate failure.
    int RtcDestroyRoom(const FString& RoomId);


    /// @brief Enables audio properties report. When this switch is turned on, you will regularly receive a statistical report of audio data.
    /// @param Interval The interval (in milliseconds) between one report and the next. You can set this parameter to `0` or any negative integer to stop receiving audio properties report. For any integer between (0, 100), the SDK will regard it as invalid and automatically set this parameter to `100`; any integer equal to or greater than `100` is valid.
	void RtcEnableAudioPropertiesReport(int Interval);


    /// @brief Leave a room.
    /// @param RoomId Room ID.
    /// @return Int: `0` indicates success, and other values indicate failure.
	int RtcLeaveRoom(const FString& RoomId);


    /// @brief Mutes local audio to make one's voice unable to be heard be others in the same room.
    /// @param InRtcMuteState The state of local audio: `0`-off; `1`-on.
	void RtcMuteLocalAudio(ERtcMuteState InRtcMuteState);


    /// @brief Publishes local audio stream to a room, thereby making the voice heard be others in the same room.
    /// @param RoomId Room ID.
	void RtcPublishRoom(const FString& RoomId);


    /// @brief Pauses all subscribed streams of a room. Once paused, the voice of users in the room is blocked so nothing can be heard from this room.
    /// @param RoomId Room id.
    /// @param InPauseResumeMediaType Media type.
	void RtcRoomPauseAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);


    /// @brief Resumes all subscribed streams of a room. Once resumed, the voice of users in the room can be heard again.
    /// @param RoomId Room ID.
    /// @param InPauseResumeMediaType Media type.
	void RtcRoomResumeAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);


    /// @brief Sets the audio playback device.
	/// @param InRtcAudioPlaybackDevice Device type: `1`-Headset; `2`-EarPiece; `3`-SpeakerPhone; `4`-HeadsetBlueTooth; `5`-HeadsetUsb.
	void RtcSetAudioPlaybackDevice(ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice);


    /// @brief Sets audio scenario type.
    /// @param InRtcAudioScenarioType Audio scenario type: `0`-Music; `1`-HighQualityCommunication; `2`-Communication; `3`-Media; `4`-GameStreaming.
	void RtcSetAudioScenario(ERtcAudioScenarioType InRtcAudioScenarioType);


    /// @brief Sets volume for audio capture.
    /// @param InRtcStreamIndex Stream index main/screen.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.
	void RtcSetCaptureVolume(ERtcStreamIndex InRtcStreamIndex, int InVolume);


    /// @brief Sets the in-ear monitoring mode.
    /// @param InRtcEarMonitorMode The state of in-ear monitoring mode: `0`-off; `1`-on.
	void RtcSetEarMonitorMode(ERtcEarMonitorMode InRtcEarMonitorMode);


    /// @brief Sets volume for in-ear monitoring.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.
	void RtcSetEarMonitorVolume(int InVolume);


    /// @brief Sets the playback volume.
    /// @param InVolume The volume. The valid value ranges from `0` to `400`. `100` indicates keeping the original volume.
	void RtcSetPlaybackVolume(int InVolume);


    /// @brief Starts audio capture.
	void RtcStartAudioCapture();


    /// @brief Stops audio capture.
	void RtcStopAudioCatpure();


    /// @brief Stops publishing local audio stream to a room, so others in the same room cannot hear the voice.
    /// @param RoomId Room ID.
	void RtcUnPublishRoom(const FString& RoomId);


    /// @brief Updates room token.
    /// @param RoomId Room ID.
    /// @param Token The new token.
	void RtcUpdateToken(const FString& RoomId, const FString& Token);

    //Request

    /// @brief Gets the token.
    /// @param UserId User id.
    /// @param RoomId Room id.
    /// @param Ttl Effective duration of room (s).
    /// @param InValue Channel effective time (s).
    /// @param InRtcGetTokenDelegate Callback function proxy.
    void GetToken(const FString& UserId, const FString& RoomId, int Ttl, int InValue, const FOnGetTokenComplete& Delegate = FOnGetTokenComplete());

PACKAGE_SCOPE:


	void OnQueryGetTokenComplete(ppfMessageHandle Message, bool bIsError, const FOnGetTokenComplete& Delegate);


	// Notification

	FDelegateHandle OnJoinRoomNotificationResultHandle;
	void OnJoinRoomResult(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnLeaveRoomNotificationResultHandle;
	void OnLeaveRoomResult(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnUserJoinRoomNotificationResultHandle;
	void OnUserJoinRoomResult(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnUserLeaveRoomNotificationResultHandle;
	void OnUserLeaveRoomResult(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomStatsNotificationHandle;
	void OnRoomStatsNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnWarnNotificationHandle;
	void OnWarnNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnErrorNotificationHandle;
	void OnErrorNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomWarnNotificationHandle;
	void OnRoomWarnNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRoomErrorNotificationHandle;
	void OnRoomErrorNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnConnectionStateChangeNotificationHandle;
	void OnConnectionStateChangeNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnUserStartAudioCaptureNotificationHandle;
	void OnUserStartAudioCaptureNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnUserStopAudioCaptureNotificationHandle;
	void OnUserStopAudioCaptureNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnAudioPlaybackDeviceChangedNotificationHandle;
	void OnAudioPlaybackDeviceChangeNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnRemoteAudioPropertiesReportNotificationHandle;
	void OnRemoteAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnLocalAudioPropertiesReportNotificationHandle;
	void OnLocalAudioPropertiesReportNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnUserMuteAudioNotificationHandle;
	void OnUserMuteAudioNotification(ppfMessageHandle Message, bool bIsError);

	FDelegateHandle OnMediaDeviceStateChangedNotificationHandle;
	void OnMediaDeviceStateChangedNotification(ppfMessageHandle Message, bool bIsError);


public:

    /// @brief Gets notified after the user has joined the room.
	FRtcJoinRoomResult RtcJoinRoomCallback;

    /// @brief Gets notified after the user has left the room.
	FRtcLeaveRoomReault RtcLeaveRoomCallback;

    /// @brief Gets notified when other users have joined the room.
	FRtcUserJoinInfo RtcUserJoinInfoCallback;

    /// @brief Gets notified when other users have left the room.
	FRtcUserLeaveInfo RtcUserLeaveInfoCallback;

    /// @brief Gets notified of room information.
	FRtcRoomState RtcRoomStateCallback;

    /// @brief Gets the warning from the room.
	FRtcRoomWarn RtcRoomWarnCallback;

    /// @brief Gets the error occurred in the room.
	FRtcRoomError RtcRoomErrorCallback;

    /// @brief Gets notified when the audio playback device has been changed.
	FRtcAudioChangePlaybackDevice RtcAudioPlaybackDeviceChangeCallback;

    /// @brief Gets the volume of each user's voice.
	FRtcRemoteAudioPropertiesReport RtcRemoteAudioPropertiesReportCallback;

    /// @brief Gets the volume of the current user's voice.
	FRtcLocalAudioPropertiesReport RtcLocalAudioPropertiesReportCallback;

    /// @brief Gets notified when the user has been muted.
	FRtcUserMuteAudioInfo RtcUserMuteAudioInfoCallback;

    /// @brief Gets notified by the media device has been changed.
	FRtcMediaDeviceChangeInfo RtcMediaDeviceChangeInfoCallback;

    /// @brief Gets the warning from the RTC engine.
    FRtcIntResult RtcWarnCallback;

    /// @brief Gets the error from the RTC engine.
    FRtcIntResult RtcErrorCallback;

    /// @brief Gets notified when the network connection status has changed.
    FRtcStringResult RtcConnectStateChangedCallback;

    /// @brief Gets notified when the user has turned on audio capture.
    FRtcStringResult RtcUserStartAudioCaptureCallback;

    /// @brief Gets notified when the user has turned off audio capture.
    FRtcStringResult RtcUserStopAudioCaptureCallback;

};
/** @} */ // end of RTC
/** @} */ // end of Function