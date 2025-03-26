// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineSubsystemPicoNames.h"
#include <string>

using namespace std;
const string HEX = "0123456789abcdef";

/// @file RTCPicoUserInterface.h


/// @cond
DECLARE_LOG_CATEGORY_EXTERN(RtcInterface, Log, All);

// <summary>Rtc engine privilege enum.</summary>
UENUM(BlueprintType)
enum class ERtcPrivilege : uint8
{
    PublishStream,
    PublishAudioStream,
    PublishVideoStream,
    SubscribeStream,
    None
};

// <summary>Rtc engine init result enum.</summary>
UENUM(BlueprintType)
enum class ERtcEngineInitResult : uint8
{
    Unknow,
    AlreadyInitialized,
    InvalidConfig,
    Success,
    None
};

// <summary>Rtc engine room profile type enum.</summary>
UENUM(BlueprintType)
enum class ERtcRoomProfileType : uint8
{
    Communication,
    LiveBroadcasting,
    Game,
    CloundGame,
    LowLatency,
    None
};

// <summary>Rtc mute state enum.</summary>
UENUM(BlueprintType)
enum class ERtcMuteState : uint8
{
    Off,
    On,
    None
};

// <summary>Rtc pause or resume media type enum.</summary>
UENUM(BlueprintType)
enum class ERtcPauseResumeMediaType : uint8
{
    Audio,
    Video,
    AudioAndVideo,
    None
};

// <summary>Rtc audio playback device enum.</summary>
UENUM(BlueprintType)
enum class ERtcAudioPlaybackDevice : uint8
{
    Headset,
    EarPiece,
    SpeakerPhone,
    HeadsetBlueTooth,
    HeadsetUsb,
    None
};

// <summary>Rtc audio scenario type enum.</summary>
UENUM(BlueprintType)
enum class ERtcAudioScenarioType : uint8
{
    Music,
    HighQualityCommunication,
    Communication,
    Media,
    GameStreaming,
    None
};

// <summary>Rtc audio stream index enum.</summary>
UENUM(BlueprintType)
enum class ERtcStreamIndex : uint8
{
    Main,
    Screen,
    None
};

// <summary>Rtc ear monitor mode enum.</summary>
UENUM(BlueprintType)
enum class ERtcEarMonitorMode : uint8
{
    Off,
    On,
    None
};

// <summary>Rtc join room type enum.</summary>
UENUM(BlueprintType)
enum class ERtcJoinRoomType : uint8
{
    First,
    Reconnected,
    None
};

// <summary>Rtc user leave reason type.</summary>
UENUM(BlueprintType)
enum class ERtcUserLeaveReasonType : uint8
{
    Quit,
    Dropped,
    None
};

// <summary>Rtc media device type.</summary>
UENUM(BlueprintType)
enum class ERtcMediaDeviceType : uint8
{
    AudioUnknown,
    AudioRenderDevice,
    AudioCaptureDevice,
    None
};

// <summary>Rtc media device state.</summary>
UENUM(BlueprintType)
enum class ERtcMediaDeviceState : uint8
{
    Started,
    Stopped,
    RuntimeError,
    Added,
    Removed,
    None
};

// <summary>Rtc media device error type.</summary>
UENUM(BlueprintType)
enum class ERtcMediaDeviceError : uint8
{
    Ok,
    NoPermission,
    DeviceBusy,
    DeviceFailure,
    DeviceNotFound,
    DeviceDisconnected,
    DeviceNoCallback,
    UnSupporttedFormat,
    None
};

UENUM(BlueprintType)
enum class ERtcSyncInfoStreamType : uint8
{
    Audio,
    None
};

UENUM(BlueprintType)
enum class ERtcMediaStreamType : uint8
{
    Audio,
    Video,
    Both,
    None
};

UENUM(BlueprintType)
enum class ERtcStreamRemoveReason : uint8
{
    Unpublish,
    PublishFailed,
    KeepLiveFailed,
    ClientDisconnected,
    Republish,
    Other,
    None
};
// Request
DECLARE_DELEGATE_ThreeParams(FOnGetTokenComplete, const FString& /*String Token*/, bool /*IsSuccessed*/, const FString& /*Error Message*/);

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

//V2
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcUserPublishInfo, const FString& /*RoomId*/, const FString& /*UserId*/, ERtcMediaStreamType /*MediaStreamType*/)
DECLARE_MULTICAST_DELEGATE_FourParams(FRtcUserUnPublishInfo, const FString& /*RoomId*/, const FString& /*UserId*/, ERtcMediaStreamType /*MediaStreamType*/, ERtcStreamRemoveReason /*Reason*/)
DECLARE_MULTICAST_DELEGATE_FiveParams(FGetRtcStreamSyncInfo, const FString& /*RoomId*/, const FString& /*UserId*/, ERtcStreamIndex /*StreamIndex*/, ERtcSyncInfoStreamType /*RtcSyncInfoStreamType*/, const FString& /*Info*/)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcMessageSendResult, int64 /*MessageId*/, int32 /*Error*/, const FString& /*RoomId*/)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcBinaryMessageReceived, const FString& /*RoomId*/, const FString& /*UserId*/, const FString& /*Info*/)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcBinaryArrayMessageReceived, const FString& /*RoomId*/, const FString& /*UserId*/, TArray<uint8> /*BinaryArray*/)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcRoomMessageReceived, const FString& /*RoomId*/, const FString& /*UserId*/, const FString& /*Message*/)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FRtcUserMessageReceived, const FString& /*RoomId*/, const FString& /*UserId*/, const FString& /*Message*/)
/// @endcond

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

 /** @defgroup RTC RTC
  *  This is the RTC group
  *  @{
  */

  /// <summary>Pico RTC interface class.</summary>
class ONLINESUBSYSTEMPICO_API FRTCPicoUserInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;


public:
    FRTCPicoUserInterface(FOnlineSubsystemPico& InSubsystem);
    ~FRTCPicoUserInterface();

    // Rtc Function


    /// <summary>Initializes the RTC engine.</summary>
    /// <returns>The initialization result.</returns>
    ERtcEngineInitResult RtcEngineInit();

    /// <summary>Joins a user to a room.</summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">User ID.</param>
    /// <param name="Token">Room token.</param>
    /// <param name="UserExtra">Extra information added by the user.</param>
    /// <param name="InRoomProfileType">Type of the room to join the user in:
    /// <ul>
    /// <li>`0`: communication room</li>
    /// <li>`1`: live broadcasting room</li> 
    /// <li>`2`: game room</li>
    /// <li>`3`: cloud game room</li>
    /// <li>`4`: low-latency room</li>
    /// </ul>
    /// </param>
    /// <param name="bIsAutoSubscribeAudio">Whether to automatically subscribe to the audio of the room: 
    /// <ul>
    /// <li>`true`: yes</li>
    /// <li>`false`: no</li>
    /// </ul>
    /// </param>
    /// <returns>Int:
    /// <ul>
    /// <li>`0`: Sending request succeeded</li> 
    /// <li>Other values: Sending request failed</li>
    /// </ul>
    /// </returns>
    int RtcJoinRoom(const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio);

    /// <summary>Destroys a room.</summary>
    /// <param name="RoomId">The ID of the room to be destroyed.</param>
    /// <returns>Int:
    /// <ul>
    /// <li>`0`: Sending request succeeded</li> 
    /// <li>Other values: Sending request failed</li>
    /// </ul>
    /// </returns>
    int RtcDestroyRoom(const FString& RoomId);

    /// <summary>Enables audio properties report. When this switch is turned on, you will regularly receive a statistical report of audio data.</summary>
    /// <param name="Interval">The interval (in milliseconds) between one report and the next. 
    /// You can set this parameter to `0` or any negative integer to stop receiving audio properties report. 
    /// For any integer between (0, 100), the SDK will regard it as invalid and automatically set this parameter to `100`; 
    /// Any integer equals to or greater than `100` is valid.
    /// </param>
    void RtcEnableAudioPropertiesReport(int Interval);

    /// <summary>Leaves a room.</summary>
    /// <param name="RoomId">Room ID.</param>
    /// <returns>Int:
    /// <ul>
    /// <li>`0`: Sending request succeeded</li> 
    /// <li>Other values: Sending request failed</li>
    /// </ul>
    /// </returns>
    int RtcLeaveRoom(const FString& RoomId);

    /// <summary>Mutes local audio to make one's voice cannot be heard by other users in the same room.</summary>
    /// <param name="InRtcMuteState">The state of local audio: 
    /// <ul>
    /// <li>`0`: off</li>
    /// <li>`1`: on</li>
    /// </ul>
    /// </param>
    void RtcMuteLocalAudio(ERtcMuteState InRtcMuteState);

    /// <summary>Publishes local audio stream to a room so that the voice can be heard by other users in the same room.</summary>
    /// <param name="RoomId">Room ID.</param>
    void RtcPublishRoom(const FString& RoomId);

    /// <summary>Pauses all subscribed streams of a room. Once paused, the voice of users in the room is blocked so nothing can be heard from this room.</summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="InPauseResumeMediaType">Media type.</param>
    void RtcRoomPauseAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    /// <summary>Resumes all subscribed streams of a room. Once resumed, the voice of users in the room can be heard again.</summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="InPauseResumeMediaType">Media type.</param>
    void RtcRoomResumeAllSubscribedStream(const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    /// <summary>Sets the audio playback device.</summary>
    /// <param name="InRtcAudioPlaybackDevice">Device type:
    /// <ul>
    /// <li>`1`: Headset</li>
    /// <li>`2`: EarPiece</li>
    /// <li>`3`: SpeakerPhone</li>
    /// <li>`4`: HeadsetBlueTooth</li>
    /// <li>`5`: HeadsetUsb</li>
    /// </ul>
    /// </param>
    void RtcSetAudioPlaybackDevice(ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice);

    /// <summary>Sets audio scenario type.</summary>
    /// <param name="InRtcAudioScenarioType">Audio scenario type: 
    /// <ul>
    /// <li>`0`: Music</li> 
    /// <li>`1`: HighQualityCommunication</li> 
    /// <li>`2`: Communication</li> 
    /// <li>`3`: Media</li>
    /// <li>`4`: GameStreaming</li>
    /// </ul>
    /// </param>
    void RtcSetAudioScenario(ERtcAudioScenarioType InRtcAudioScenarioType);

    /// <summary>Sets volume for audio capturing.</summary>
    /// <param name="InRtcStreamIndex">Stream index main/screen.</param>
    /// <param name="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>
    void RtcSetCaptureVolume(ERtcStreamIndex InRtcStreamIndex, int InVolume);

    /// <summary>Sets the in-ear monitoring mode.</summary>
    /// <param name="InRtcEarMonitorMode">The state of in-ear monitoring mode:
    /// <ul>
    /// <li>`0`: off</li>
    /// <li>`1`: on</li>
    /// </ul>
    /// </param>
    void RtcSetEarMonitorMode(ERtcEarMonitorMode InRtcEarMonitorMode);

    /// <summary>Sets volume for in-ear monitoring.</summary>
    /// <param name="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>
    void RtcSetEarMonitorVolume(int InVolume);

    /// <summary>Sets the playback volume.</summary>
    /// <param name="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>
    void RtcSetPlaybackVolume(int InVolume);

    /// <summary>Starts audio capturing.</summary>
    void RtcStartAudioCapture();

    /// <summary>Stops audio capturing.</summary>
    void RtcStopAudioCatpure();

    /// <summary>Stops publishing local audio stream to a room so that the other users in the same room cannot hear the voice.</summary>
    /// <param name="RoomId">Room ID.</param>
    void RtcUnPublishRoom(const FString& RoomId);

    /// <summary>Updates room token.</summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="Token">The new token.</param>
    void RtcUpdateToken(const FString& RoomId, const FString& Token);

    //Request

    /// <summary>Gets the token.</summary>
    /// <param name="UserId">User ID.</param>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="Ttl">The effective duration (in seconds) of room.</param>
    /// <param name="InValue">Channel effective time (in seconds).</param>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (const FString& /*String Token*/, bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    void GetToken(const FString& UserId, const FString& RoomId, int Ttl, int InValue, const FOnGetTokenComplete& Delegate = FOnGetTokenComplete());

    // V2

    /// <summary>
    /// Sends stream sync info. The sync info data will be sent in the same packet with the audio data. Users who subscribe to this audio stream will receive the stream sync info message.
    /// </summary>
    /// <param name="Info">The stream sync info.</param>
    /// <param name="InStreamIndex">The stream index:
    /// <ul>
    /// <li> `0`: Main</li>
    /// <li> `1`: Screen</li>
    /// <li> `2`: None</li>
    /// </ul>
    /// </param>
    /// <param name="RepeatCount">The stream sync info will be sent repeatedly for the times set in `repeatCount`.
    /// It's designed to avoid losing package and ensuring that the sync info can be sent successfully.
    /// However, if `repeatCount` is too large, it will cause the sync info to pile up in the queue.
    /// It is recommended to set this parameter to `1`.
    /// </param>
    /// <param name="InSyncInfoStreamType">The sync info stream type:
    /// <ul>
    /// <li>`0`: Audio</li>
    /// <li>`1`: None</li>
    /// </ul>
    /// </param>
    /// <returns>Any code which equals to or below `0` indicates success, and other codes indicate failure. 
    /// | Code | Description|
    /// |---|---|
    /// |>=0|Send successfully. Indicates the times sent successfully.|
    /// |-1|Send Failed. Message length exceeded 255B.|
    /// |-2|Send Failed. The data is empty.|
    /// |-3|Send Failed. Send sync info with a un-publish screen stream.|
    /// |-4|Send Failed. Send sync info with a un-publish audio stream.|
    /// </returns>
    int32 RtcSendStreamSyncInfo(int32 Info, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType);

    /// <summary>
    /// Sends stream sync info. The sync info data will be sent in the same packet with the audio data. Users who subscribe to this audio stream will receive the stream sync info message.
    /// </summary>
    /// <param name="Bytes">The stream sync info.</param>
    /// <param name="InStreamIndex">The stream index:
    /// <ul>
    /// <li> `0`: Main</li>
    /// <li> `1`: Screen</li>
    /// <li> `2`: None</li>
    /// </ul>
    /// </param>
    /// <param name="RepeatCount">The stream sync info will be sent repeatedly for the times set in `repeatCount`.
    /// It's designed to avoid losing package and ensuring that the sync info can be sent successfully.
    /// However, if `repeatCount` is too large, it will cause the sync info to pile up in the queue.
    /// It is recommended to set this parameter to `1`.
    /// </param>
    /// <param name="InSyncInfoStreamType">The sync info stream type:
    /// <ul>
    /// <li>`0`: Audio</li>
    /// <li>`1`: None</li>
    /// </ul>
    /// </param>
    /// <returns>Any code which equals to or below `0` indicates success, and other codes indicate failure. 
    /// | Code | Description|
    /// |---|---|
    /// |>=0|Send successfully. Indicates the times sent successfully.|
    /// |-1|Send Failed. Message length exceeded 255B.|
    /// |-2|Send Failed. The data is empty.|
    /// |-3|Send Failed. Send sync info with a un-publish screen stream.|
    /// |-4|Send Failed. Send sync info with a un-publish audio stream.|
    /// </returns>
    int32 RtcSendStreamSyncInfo(TArray<uint8> Bytes, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType);

    /// <summary>
    /// Publishes the local audio stream to a room so that the local user's voice can be heard by other users in the same room.
    /// @note
    /// * A user can only publish the local audio stream to one room at the same time.
    /// * If a user wants to publish the local audio stream to another room, 
    /// `UnPublishRoom(oldRoomId)` should be called first to stop publishing the local audio stream to the current room and then `Publish(newRoomId)` should be called.
    /// </summary>
    /// <param name="RoomId">The ID of the room that the local audio stream is published to.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    void RtcRoomPublishStream(const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Sets the volume for a remote user in a room.
    /// </summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the remote user.</param>
    /// <param name="Volume">The volume to set for the remote user, which ranges from `0` to `400`. `100` indicates the default volume.</param>
    void RtcRoomSetRemoteAudioPlaybackVolume(const FString& RoomId, const FString& UserId, int32 Volume);

    /// <summary>
    /// Subscribes to the audio stream of a specific user in a room.
    /// </summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the user in the room.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    void RtcRoomSubscribeStream(const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Stops publishing the local audio stream to a room so that the other in-room users cannot hear the local user's voice.
    /// </summary>
    /// <param name="RoomId">The ID of the room to stop publishing the local audio stream to.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    void RtcRoomUnPublishStream(const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Unsubscribes from the audio stream of a specific user in a room.
    /// </summary>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the user in the room.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    void RtcRoomUnsubscribeStream(const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Sends a binary message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room to which the binary message is to be sent.</param>
    /// <param name="MessageInfo">The binary message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendRoomBinaryMessage(const FString& RoomId, const FString& MessageInfo);

    /// <summary>
    /// Sends a binary message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room to which the binary message is to be sent.</param>
    /// <param name="Bytes">The binary message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendRoomBinaryMessage(const FString& RoomId, TArray<uint8> Bytes);

    /// <summary>
    /// Sends a text message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room to which the text message is to be sent.</param>
    /// <param name="Message">The text message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendRoomMessage(const FString& RoomId, const FString& Message);


    /// <summary>
    /// Sends a binary message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user to whom the binary message is to be sent.</param>
    /// <param name="MessageInfo">The binary message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendUserBinaryMessage(const FString& RoomId, const FString& UserId, const FString& MessageInfo);

    /// <summary>
    /// Sends a binary message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user to whom the binary message is to be sent.</param>
    /// <param name="Bytes">The binary message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendUserBinaryMessage(const FString& RoomId, const FString& UserId, TArray<uint8> Bytes);

    /// <summary>
    /// Sends a text message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user to whom the text message is to be sent.</param>
    /// <param name="Message">The text message to be sent.</param>
    /// <returns>A user message ID of type int64, which is automatically generated and incremented.</returns>
    int64 RtcSendUserMessage(const FString& RoomId, const FString& UserId, const FString& Message);

private:
    TArray<uint8> GetBytesByInt(int32 Inint);


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

    FDelegateHandle OnRtcUserPublishInfoNotificationHandle;
    void OnRtcUserPublishInfoNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcUserUnPublishInfoNotificationHandle;
    void OnRtcUserUnPublishInfoNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnGetRtcStreamSyncInfoNotificationHandle;
    void OnGetRtcStreamSyncInfoNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcUserMessageSendResultNotificationHandle;
    FDelegateHandle OnRtcRoomMessageSendResultNotificationHandle;
    void OnRtcMessageSendResultNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcUserBinaryMessageReceivedNotificationHandle;
    FDelegateHandle OnRtcRoomBinaryMessageReceivedNotificationHandle;
    void OnRtcBinaryMessageReceivedNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcRoomMessageReceivedNotificationHandle;
    void OnRtcRoomMessageReceivedNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcUserMessageReceivedNotificationHandle;
    void OnRtcUserMessageReceivedNotification(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnRtcTokenWilExpireNotificationHandle;
    void OnRtcTokenWilExpireNotification(ppfMessageHandle Message, bool bIsError);

public:

    /// <summary>Gets notified after the user has joined the room.</summary>
    FRtcJoinRoomResult RtcJoinRoomCallback;

    /// <summary>Gets notified after the user has left the room.</summary>
    FRtcLeaveRoomReault RtcLeaveRoomCallback;

    /// <summary>Gets notified when other users have joined the room.</summary>
    FRtcUserJoinInfo RtcUserJoinInfoCallback;

    /// <summary>Gets notified when other users have left the room.</summary>
    FRtcUserLeaveInfo RtcUserLeaveInfoCallback;

    /// <summary>Gets notified of room information.</summary>
    FRtcRoomState RtcRoomStateCallback;

    /// <summary>Gets the warning from the room.</summary>
    FRtcRoomWarn RtcRoomWarnCallback;

    /// <summary>Gets the error occurred in the room.</summary>
    FRtcRoomError RtcRoomErrorCallback;

    /// <summary>Gets notified when the audio playback device has been changed.</summary>
    FRtcAudioChangePlaybackDevice RtcAudioPlaybackDeviceChangeCallback;

    /// <summary>Gets the volume of each user's voice.</summary>
    FRtcRemoteAudioPropertiesReport RtcRemoteAudioPropertiesReportCallback;

    /// <summary>Gets the volume of the current user's voice.</summary>
    FRtcLocalAudioPropertiesReport RtcLocalAudioPropertiesReportCallback;

    /// <summary>Gets notified when the user has been muted.</summary>
    FRtcUserMuteAudioInfo RtcUserMuteAudioInfoCallback;

    /// <summary>Gets notified when the media device has been changed.</summary>
    FRtcMediaDeviceChangeInfo RtcMediaDeviceChangeInfoCallback;

    /// <summary>Gets the warning from the RTC engine.</summary>
    FRtcIntResult RtcWarnCallback;

    /// <summary>Gets the error from the RTC engine.</summary>
    FRtcIntResult RtcErrorCallback;

    /// <summary>Gets notified when the network connection status has changed.</summary>
    FRtcStringResult RtcConnectStateChangedCallback;

    /// <summary>Gets notified when the user has turned on audio capturing.</summary>
    FRtcStringResult RtcUserStartAudioCaptureCallback;

    /// <summary>Gets notified when the user has turned off audio capturing.</summary>
    FRtcStringResult RtcUserStopAudioCaptureCallback;


    // V2

    /// <summary>
    /// Sets the callback to get notified when a remote user publishes audio stream.
    /// </summary>
    FRtcUserPublishInfo RtcUserPublishInfoCallback;

    /// <summary>
    /// Sets the callback to get notified when a remote user cancels publishing audio stream.
    /// </summary>
    FRtcUserUnPublishInfo RtcUserUnPublishInfoCallback;

    /// <summary>
    /// Sets the callback to get notified when the stream sync info is received.
    /// </summary>
    FGetRtcStreamSyncInfo RtcStreamSyncInfoCallback;

    /// <summary>
    /// Sets the callback to get whether the to-room or to-user message is sent successfully.
    /// </summary>
    FRtcMessageSendResult RtcMessageSendResultCallback;

    /// <summary>
    /// Sets the callback to get notified when a to-room binary message is received.
    /// </summary>
    FRtcBinaryMessageReceived RtcBinaryMessageReceivedCallback;

    /// <summary>
    /// Sets the callback to get notified when a to-room binary message is received(As TArray<uint8>).
    /// </summary>
    FRtcBinaryArrayMessageReceived RtcBinaryArrayMessageReceivedCallback;

    /// <summary>
    /// Sets the callback to get notified when a to-room message is received.
    /// </summary>
    FRtcRoomMessageReceived RtcRoomMessageReceivedCallback;

    /// <summary>
    /// Sets the callback to get notified when a to-user message is received.
    /// </summary>
    FRtcUserMessageReceived RtcUserMessageReceivedCallback;

    /// <summary>
    /// Sets the callback to get notified when the token is about to expire.
    /// @note The token will expire in 30 seconds after you receive this notification.
    /// <ul>
    /// <li>If you still want to stay in the room, you can get a new token by calling `UpdateToken`.</li>
    /// <li>If you do not update the token after receiving this notification, you will be kicked out of the room in 30 seconds.</li>
    /// </ul>
    /// </summary>
    FRtcStringResult RtcTokenWillExpireCallback;
};
/** @} */ // end of RTC
/** @} */ // end of Function


