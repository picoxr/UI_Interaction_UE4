// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RTCPicoUserInterface.h"
#include "PicoPresenceInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystemPicoManager.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Pico_User.h"
#include "OnlinePicoFunctionLibrary.generated.h"

/// @file OnlinePicoFunctionLibrary.h
 

/// @brief Pico blueprint function library.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UOnlinePicoFunctionLibrary();
private:

	static UOnlineSubsystemPicoManager* PicoSubsystemManager;

    static UObject* World;

    /** @defgroup BlueprintFunction BlueprintFunction
     *  This is the BlueprintFunction group
     *  @{
     */

    /** @defgroup BP_Identity BP_Identity(OnlineSub)
     *  This is the BP_Identity(OnlineSub) group
     *  @{
     */

public:
    // Pico Identity 
    
    /// <summary>Gets the account login information for the current device.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalUserNum">The controller number of the user to get login information for.</param>   
    /// <param name ="UserId">User ID.</param>
    /// <param name ="InToken">User token.</param>
    /// <param name ="InType">User type.</param>
    /// <param name ="InLoginComleteDelegate">Callback function proxy(int, LocalUserNum, const FString, UserId, bool, bIsSuccessed, const FString, ErrorMessage).</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static void PicoLogin(UObject* WorldContextObject, int32 LocalUserNum, const FString& UserId, const FString& InToken, const FString& InType, FOnlineManagerLoginCompleteDelegate InLoginComleteDelegate);

    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static void PicoGetOpenIDToken(UObject* WorldContextObject, FGetIDToken OnGetIdTokenComplete);
    /// <summary>Gets a user's nickname.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalUserNum">The controller number of the user to get nickname for.</param>   
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static FString PicoGetNickName(UObject* WorldContextObject, int32 LocalUserNum);

    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Identity")
    static UPico_User* GetLoginPicoUser(UObject* WorldContextObject, int32 LocalUserNum);


    /** @} */ // end of BP_Identity(OnlineSub)

    /** @defgroup BP_Friends BP_Friends(OnlineSub)
     *  This is the BP_Friends(OnlineSub) group
     *  @{
     */

	// Pico FriendInterface
    
    
    /// <summary>Reads user's friend list by account number.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalUserNum">User's account number.</param>
    /// <param name ="ListName">The name of the list. Valid value is `Default` or `OnlinePlayers`.</param>
    /// <param name ="InReadFriendListDelegate">Callback function proxy(int, LocalUserNum, bool, bWasSuccessful, const FString, ListName, const FString, ErrorStr).</param> 
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static void PicoReadFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, FOnlineManagerReadFriendListDelegate InReadFriendListDelegate);

    
    /// <summary>Gets an arrary of friends for a specified user by friend list name.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalUserNum">User's account number.</param>
    /// <param name ="ListName">The name of the list. Valid value is `Default` or `OnlinePlayers`.</param>
    /// <param name ="OutFriends">Returns an array of friends.</param>   
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static void PicoGetFriendList(UObject* WorldContextObject, int32 LocalUserNum, const FString& ListName, TArray<FPicoUserInfo> &OutFriends);


    
    /// <summary>Gets a user's friends by friend list name and friend ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalUserNum">User's account number.</param>
    /// <param name ="FriendId">Friend ID.</param>
    /// <param name ="ListName">The name of the list. Valid value is `Default` or `OnlinePlayers`.</param>
    /// <returns>FPicoFriend Pico friend struct.</returns>  
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Friend")
	static FPicoUserInfo PicoGetFriend(UObject* WorldContextObject, int32 LocalUserNum, const FString& FriendId, const FString& ListName);


    /** @} */ // end of BP_Friends(OnlineSub)


    /** @defgroup BP_RTC BP_RTC
     *  This is the BP_RTC group
     *  @{
     */

	// Pico RtcInterface
    
    /// <summary>Gets the RTC token.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="UserId">User ID.</param>
    /// <param name ="RoomId">Room ID.</param>
    /// <param name ="Ttl">The effective duration of the room (in seconds).</param>
    /// <param name ="InValue">Channel effective time (in seconds).</param>
    /// <param name ="InRtcGetTokenDelegate">Callback function proxy( FString, Token, bool, IsSuccessed, FString, ErrorMessage).</param>  
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
	static void PicoRtcGetToken(UObject* WorldContextObject, const FString& UserId, const FString& RoomId, int Ttl, int InValue, FOnlineManagerRtcGetTokenDelegate InRtcGetTokenDelegate);

    // Function Call

    
    /// <summary>Initializes the RTC engine.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <returns>Voice the initialization result.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static ERtcEngineInitResult PicoGetRtcEngineInit(UObject* WorldContextObject);

    
    /// <summary>Joins a user to a RTC room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">Room ID.</param>
    /// <param name ="UserId">User ID.</param>
    /// <param name ="Token">Room token.</param>
    /// <param name ="UserExtra">Extra information added by the user.</param>
    /// <param name ="InRoomProfileType">Room type: 
    /// <ul>
    /// <li>`0`: communication room</li>
    /// <li>`1`: live broadcasting room</li> 
    /// <li>`2`: game room</li> 
    /// <li>`3`: cloud game room</li>
    /// <li>`4`: low-latency room</li>
    /// </ul>
    /// </param>
    /// <param name ="bIsAutoSubscribeAudio">Whether to automatically subscribe to the audio of the room: 
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
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
	static int PicoRtcJoinRoom(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Token, const FString& UserExtra, ERtcRoomProfileType InRoomProfileType, bool bIsAutoSubscribeAudio);

    
    /// <summary>Destroys a room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">The ID of the room to destroy.</param>
    /// <returns>Int: 
    /// <ul>
    /// <li>`0`: Sending request succeeded</li>
    /// <li>Other values: Sending request failed</li>
    /// </ul>
    /// </returns>    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int RtcDestroyRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// <summary>Enables audio properties report. When this switch is turned on, you will regularly receive a statistical report of audio data.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="Interval">The interval (in milliseconds) between one report and the next. 
    /// You can set this parameter to `0` or any negative integer to stop receiving audio properties report. 
    /// For any integer between (0, 100), the SDK will regard it as invalid and automatically set this parameter to `100`; 
    /// Any integer equals to or greater than `100` is valid. 
    /// </param>   
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcEnableAudioPropertiesReport(UObject* WorldContextObject, int Interval);

    /// <summary>Leaves a RTC room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">Room ID.</param>
    /// <returns>
    /// <ul>
    /// <li>`0`: Sending request succeeded</li>
    /// <li>Other values: Sending request failed</li>
    /// </ul>
    /// </returns> 
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int RtcLeaveRoom(UObject* WorldContextObject, const FString& RoomId);


    /// <summary>Mutes local audio to make a user's voice cannot be heard by other users in the same room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InRtcMuteState">The state of local audio:
    /// <ul>
    /// <li>`0`: off</li>
    /// <li>`1`: on</li>
    /// </ul>
    /// </param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcMuteLocalAudio(UObject* WorldContextObject, ERtcMuteState InRtcMuteState);

    
    /// <summary>Publishes local audio stream to a room so that the voice can be heard by other users in the same room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">Room ID.</param>     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcPublishRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// <summary>Stops publishing local audio stream to a room so that other users in the same room cannot hear the voice.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">Room ID.</param>        
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcUnPublishRoom(UObject* WorldContextObject, const FString& RoomId);

    
    /// <summary>Pauses all subscribed streams of a room. Once paused, the voice of users in the room is blocked so nothing can be heard from this room.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="RoomId">Room ID.</param> 
    /// <param name ="InPauseResumeMediaType">Media type.</param>  
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomPauseAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    
    /// <summary>Resumes all subscribed streams of a room. Once resumed, the voice of users in the room can be heard again.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">The ID of the room to resume subscribed streams for.</param>
    /// <param name ="InPauseResumeMediaType">Media type.</param>     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomResumeAllSubscribedStream(UObject* WorldContextObject, const FString& RoomId, ERtcPauseResumeMediaType InPauseResumeMediaType);

    
    /// <summary>Sets the type of audio playback device.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InRtcAudioPlaybackDevice">Device type.</param>      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetAudioPlaybackDevice(UObject* WorldContextObject, ERtcAudioPlaybackDevice InRtcAudioPlaybackDevice);

    
    /// <summary>Sets audio scenario type.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InRtcAudioScenarioType">Audio scenario type: 
    /// <ul>
    /// <li>`0`: Music</li> 
    /// <li>`1`: HighQualityCommunication</li>  
    /// <li>`2`: Communication</li>  
    /// <li>`3`: Media</li> 
    /// <li>`4`: GameStreaming</li>  
    /// </ul>
    /// </param>     
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetAudioScenario(UObject* WorldContextObject, ERtcAudioScenarioType InRtcAudioScenarioType);

    
    /// <summary>Sets volume for audio capturing.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InRtcStreamIndex">Stream index main/screen.</param>
    /// <param name ="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>       
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetCaptureVolume(UObject* WorldContextObject, ERtcStreamIndex InRtcStreamIndex, int InVolume);

    
    /// <summary>Sets the in-ear monitoring mode.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InRtcEarMonitorMode">The state of in-ear monitoring mode: 
    /// <ul>
    /// <li>`0`: off</li>
    /// <li>`1`: on</li>
    /// </ul>
    /// </param>      
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetEarMonitorMode(UObject* WorldContextObject, ERtcEarMonitorMode InRtcEarMonitorMode);

    
    /// <summary>Sets the volume for in-ear monitoring.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>       
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetEarMonitorVolume(UObject* WorldContextObject, int InVolume);

    
    /// <summary>Sets the playback volume.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="InVolume">The volume. 
    /// The valid value ranges from `0` to `400`. 
    /// `100` indicates keeping the original volume.
    /// </param>    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcSetPlaybackVolume(UObject* WorldContextObject, int InVolume);

    
    /// <summary>Starts audio capturing.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcStartAudioCapture(UObject* WorldContextObject);

    
    /// <summary>Stops audio capturing.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>        
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcStopAudioCapture(UObject* WorldContextObject);

    
    /// <summary>Updates room token.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="RoomId">Room ID.</param>
    /// <param name ="Token">The new token.</param>    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcUpdateToken(UObject* WorldContextObject, const FString& RoomId, const FString& Token);

    // Rtc v2

    /// <summary>
    /// Sends stream sync info. The sync info data will be sent in the same packet with the audio data. Users who subscribe to this audio stream will receive the stream sync info message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Info">The stream sync info.</param>
    /// <param name="InStreamIndex">The Stream index:
    /// * `0`: Main
    /// * `1`: Screen
    /// * `2`: None
    /// </param>
    /// <param name="RepeatCount">The stream sync info will be sent repeatedly for the times set in `repeatCount`.
    /// It's designed to avoid losing package and to ensure that the sync info can be sent successfully.
    /// However, if `repeatCount` is too large, it will cause the sync info to pile up in the queue.
    /// It is recommended to set this parameter to `1`.
    /// </param>
    /// <param name="InSyncInfoStreamType">The sync info stream type:
    /// * `0`: Audio
    /// * `1`: None
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
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send Stream Sync int Info"))
    static int32 RtcSendStreamSyncInfo(UObject* WorldContextObject, int32 Info, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType);

    /// <summary>
    /// Sends stream sync info. The sync info data will be sent in the same packet with the audio data. Users who subscribe to this audio stream will receive the stream sync info message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="Bytes">The stream sync bytes info.</param>
    /// <param name="InStreamIndex">The Stream index:
    /// * `0`: Main
    /// * `1`: Screen
    /// * `2`: None
    /// </param>
    /// <param name="RepeatCount">The stream sync info will be sent repeatedly for the times set in `repeatCount`.
    /// It's designed to avoid losing package and to ensure that the sync info can be sent successfully.
    /// However, if `repeatCount` is too large, it will cause the sync info to pile up in the queue.
    /// It is recommended to set this parameter to `1`.
    /// </param>
    /// <param name="InSyncInfoStreamType">The sync info stream type:
    /// * `0`: Audio
    /// * `1`: None
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
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send Stream Sync Bytes Info"))
    static int32 RtcSendStreamSyncBytesInfo(UObject* WorldContextObject, TArray<uint8> Bytes, ERtcStreamIndex InStreamIndex, int32 RepeatCount, ERtcSyncInfoStreamType InSyncInfoStreamType);

    /// <summary>
    /// Publishes the local audio stream to a room so that the local user's voice can be heard by other users in the same room.
    /// @note
    /// * A user can only publish the local audio stream to one room at the same time.
    /// * If a user wants to publish the local audio stream to another room, 
    /// `UnPublishRoom(oldRoomId)` should be called first to stop publishing the local audio stream to the current room and then `Publish(newRoomId)` should be called.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room that the local audio stream is published to.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Sets the volume for a remote user in a room.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the remote user.</param>
    /// <param name="Volume">The volume to set for the remote user, which ranges from `0` to `400`. `100` indicates the default volume.</param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomSetRemoteAudioPlaybackVolume(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, int32 Volume);

    /// <summary>
    /// Subscribes to the audio stream of a specific user in a room.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the user in the room.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomSubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Stops publishing the local audio stream to a room, so that the other in-room users cannot hear the local user's voice.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room to stop publishing the local audio stream to.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomUnPublishStream(UObject* WorldContextObject, const FString& RoomId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Unsubscribes from the audio stream of a specific user in a room.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">Room ID.</param>
    /// <param name="UserId">The ID of the user in the room.</param>
    /// <param name="InRtcMediaStreamType">The media stream type:
    /// * `0`: Audio
    /// * `1`: Video
    /// * `2`: Both
    /// * `3`: None
    /// </param>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static void RtcRoomUnsubscribeStream(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, ERtcMediaStreamType InRtcMediaStreamType);

    /// <summary>
    /// Sends a binary message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room to which the binary message is to be sent.</param>
    /// <param name="MessageInfo">The binary message to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send String Binary Message"))
    static int64 RtcSendRoomBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& MessageInfo);


    /// <summary>
    /// Sends a binary message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room to which the binary message is to be sent.</param>
    /// <param name="Bytes">The binary array to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send Bytes Binary Message"))
    static int64 RtcSendRoomBytesBinaryMessage(UObject* WorldContextObject, const FString& RoomId, TArray<uint8> Bytes);

    /// <summary>
    /// Sends a text message to a room. All in-room users will receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room to which the text message is to be sent.</param>
    /// <param name="Message">The message to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int64 RtcSendRoomMessage(UObject* WorldContextObject, const FString& RoomId, const FString& Message);

    /// <summary>
    /// Sends a binary message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user the message is sent to.</param>
    /// <param name="MessageInfo">The message to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send User String Binary Message"))
    static int64 RtcSendUserBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& MessageInfo);

    /// <summary>
    /// Sends a binary message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user the message is sent to.</param>
    /// <param name="Bytes">The message to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc", Meta = (DisplayName = "Rtc Send User Bytes Binary Message"))
    static int64 RtcSendUserBytesBinaryMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, TArray<uint8> Bytes);

    /// <summary>
    /// Sends a text message to a user. Only the user can receive this message.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="RoomId">The ID of the room the user is in.</param>
    /// <param name="UserId">The ID of the user the message is sent to.</param>
    /// <param name="Message">The message to be sent.</param>
    /// <returns>A room message ID of type int64, which is automatically generated and incremented.</returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Rtc")
    static int64 RtcSendUserMessage(UObject* WorldContextObject, const FString& RoomId, const FString& UserId, const FString& Message);




    /** @} */ // end of BP_RTC

    /** @defgroup BP_Session BP_Session(OnlineSub)
     *  This is the BP_Session(OnlineSub) group
     *  @{
     */

	// Game
	/// <summary>Is game initialize success.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool IsGameInitSuccess(UObject* WorldContextObject);
	/// <summary>Game initialize.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool GameInitialize(UObject* WorldContextObject);
	
	/// <summary>Game uninitialize.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
	/// <returns>Bool: 
	/// <ul>
	/// <li>`true`: Sending request succeeded</li>
	/// <li>`false`: Sending request failed</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool GameUninitialize(UObject* WorldContextObject);

    /// <summary>Creates a private session or a matchmaking session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="HostingPlayerNum">The index in the current userId array.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="NewSessionSettings">The session settings.</param> 
    /// <param name ="OnCreateSessionCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool CreateSession(UObject* WorldContextObject, int HostingPlayerNum, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, FPicoManagerOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate);

    /// <summary>Changes the session state to `InProgress`.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="OnStartSessionCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool StartSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate);

    /// <summary>Updates the datastore of a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="UpdatedSessionSettings">The settings with new datastore.</param> 
    /// <param name ="OnUpdateSessionCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param> 
    /// <param name ="bShouldRefreshOnlineData">(not used)</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool UpdateSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& UpdatedSessionSettings, FPicoManagerOnUpdateSessionCompleteDelegate OnUpdateSessionCompleteDelegate, bool bShouldRefreshOnlineData = true);

    /// <summary>Changes the session state to `Ended`.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="OnEndSessionCompleteDelegate">Will be executed when the request has been completed( FName, SessionName, bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool EndSession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnEndSessionCompleteDelegate OnEndSessionCompleteDelegate);

    /// <summary>Destroys the current session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="OnDestroySessionCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool DestroySession(UObject* WorldContextObject, FName SessionName, FPicoManagerOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate);

    /// <summary>Checks whether a player is in a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SessionName">The session name.</param> 
    /// <param name ="UniqueId">The unique ID of the player.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool IsPlayerInSession(UObject* WorldContextObject, FName SessionName, const FString& UniqueId);

    /// <summary>Starts matchmaking for a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="LocalPlayers">The logged-in users in the session.</param>
    /// <param name ="SessionName">The session name.</param>
    /// <param name ="NewSessionSettings">Set `NumPrivateConnections` to `0`.</param>
    /// <param name ="NewSessionSearch">Used to modify the search state.</param>
    /// <param name ="OnMatchmakingCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool StartMatchmaking(UObject* WorldContextObject, const TArray<FString>& LocalPlayers, FName SessionName, const FPicoOnlineSessionSettings& NewSessionSettings, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnMatchmakingCompleteDelegate OnMatchmakingCompleteDelegate);

    /// <summary>Cancels matchmaking for a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SearchingPlayerNum">(not used)</param>
    /// <param name ="SessionName">The session name.</param>
    /// <param name ="OnCancelMatchmakingCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, bool, bWasSuccessful).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool CancelMatchmaking(UObject* WorldContextObject, int SearchingPlayerNum, FName SessionName, FPicoManagerOnCancelMatchmakingCompleteDelegate OnCancelMatchmakingCompleteDelegate);

    /// <summary>Finds matchmaking sessions or moderated sessions.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SearchingPlayerNum">(not used)</param>
    /// <param name ="NewSessionSearch">The search settings.</param>
    /// <param name ="OnFindSessionCompleteDelegate">Will be executed when the request has been completed(bool, bWasSuccessful).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool FindSessions(UObject* WorldContextObject, int32 SearchingPlayerNum, UPARAM(ref)FPicoOnlineSessionSearch& NewSessionSearch, FPicoManagerOnFindSessionCompleteDelegate OnFindSessionCompleteDelegate);

    /// <summary>Gets session data by session ID.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SearchingUserId">The ID of the logged-in player. If the played has not logged in, the session data will be unable to get.</param>
    /// <param name ="SessionId">The session ID.</param>
    /// <param name ="OnSingleSessionResultCompleteDelegate">Will be executed when the request has been completed(int32, LocalUserNum, bool, bWasSuccessful, const FPicoOnlineSessionSearchResult&, SearchResult).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
    static bool FindSessionById(UObject* WorldContextObject, const FString& SearchingUserId, const FString& SessionId, FPicoManagerOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate);

    /// <summary>Joins a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="PlayerNum">The `LocalOwnerId` of the session.</param>
    /// <param name ="SessionName">The name of the session to join.</param>
    /// <param name ="SearchResult">The search session result settings.</param>
    /// <param name ="OnJoinSessionCompleteDelegate">Will be executed when the request has been completed(FName, SessionName, EOnJoinSessionCompleteResultPicoType , Type).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool JoinSession(UObject* WorldContextObject, int PlayerNum, FName SessionName, const FPicoOnlineSessionSearchResult& SearchResult, FPicoManagerOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate);

    /// <summary>Dumps a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static void DumpSessionState(UObject* WorldContextObject);

    /// <summary>Gets the state of a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SessionName">The name of the session to get state for.</param>
    /// <returns>The state of the session.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static EOnlineSessionStatePicoType GetSessionState(UObject* WorldContextObject, FName SessionName);

    /// <summary>Gets the data about a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SessionName">The session name.</param>
    /// <returns>The data about the session.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession GetNamedSession(UObject* WorldContextObject, FName SessionName);

    /// <summary>Adds session by session settings.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SessionName">The session name.</param>
    /// <param name ="SessionSettings">The settings of the session.</param>
    /// <returns>The session added.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession AddNamedSessionBySettings(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSessionSettings& SessionSettings);

    /// <summary>Adds a session.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="SessionName">The session name.</param>
    /// <param name ="Session">The session will be added.</param>
    /// <returns>The session added.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoNamedOnlineSession AddNamedSession(UObject* WorldContextObject, FName SessionName, const FPicoOnlineSession& Session);

	/// <summary>Gets the settings of a session.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name ="SessionName">The session name.</param>
	/// <returns>The settings of the session.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static FPicoOnlineSessionSettings GetSessionSettings(UObject* WorldContextObject, FName SessionName);

	
	/// <summary>Invites a friend to the session.</summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param>
	/// <param name ="LocalUserNum">The controller number of the friend to invite.</param>
	/// <param name ="SessionName">The session name.</param>
	/// <param name ="Friend">The name of the friend to invite.</param>
	/// <returns>The settings of the session.</returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Game")
	static bool SendSessionInviteToFriend(UObject* WorldContextObject, int32 LocalUserNum, FName SessionName, const FString& Friend);

    /** @} */ // end of BP_Session(OnlineSub)
	
private:
	static FOnlineSessionSettings GetOnlineSessionSettings(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	static FPicoOnlineSessionSettings GetPicoOnlineSessionSettings(const FOnlineSessionSettings& UpdatedSessionSettings);
	static FPicoNamedOnlineSession GetPicoOnlineSession(const FNamedOnlineSession& Session);
	static FOnlineSession GetOnlineSession(const FPicoOnlineSession& PicoSession);
	static bool IsInputSessionSettingsDataStoreValid(const FPicoOnlineSessionSettings& UpdatedSessionSettings);
	static bool IsInputSessionSearchQueryDataValid(const FPicoOnlineSessionSearch& SessionSearch);
	
public:

    /** @defgroup BP_Presence BP_Presence
     *  This is the BP_Presence group
     *  @{
     */

    //  Presence

    /// <summary>Clears a user's presence data in the current app.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InPresenceClearDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceClear(UObject* WorldContextObject, FOnlineManagerPresenceClearDelegate InPresenceClearDelegate);

    /// <summary>Reads a list of invitable users for a user. 
    /// @note Call `GetInvitableFriendList` after the Delegate has been executed.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="SuggestedUserList">The ID list of the users suggested being invited.</param>
    /// <param name="InReadInvitableUserDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static void ReadInvitableUser(UObject* WorldContextObject, TArray<FString> SuggestedUserList, FOnlineManagerPresenceReadInvitableUserDelegate InReadInvitableUserDelegate);

    /// <summary>Gets a list of invitable friends for a user. These friends are previously retrieved from the online service when `PresenceGetDestinations` is complete.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>    
    /// <param name="OutFriendsList">The [out] array that receives the copied data.</param>
    /// <returns>Bool:
    /// * `true`: the friend list has been found.
    /// * `false`: otherwise
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool GetInvitableFriendList(UObject* WorldContextObject, TArray<FPicoUserInfo>& OutFriendsList);

    /// <summary>Sets presence data for a user in the current app.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>    
    /// <param name="ApiName">The API name of the destination.</param> 
    /// <param name="LobbySessionId">Lobby session ID is used to identify a user group or team. Users with the same lobby session ID can play together or form a team in a game.</param> 
    /// <param name="MatchSessionId">Match session ID is used to identify all users within a same destination, such as maps and levels. Users with different lobby session IDs will have the same match session ID when playing the same match.</param> 
    /// <param name="bIsJoinable">Defines whether the user is joinable:
    /// * `true`: joinable
    /// * `false`: not joinable
    /// </param> 
    /// <param name="Extra">Extra presence data defined by the developer.</param> 
    /// <param name="InPresenceSetDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSet(UObject* WorldContextObject, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, FOnlineManagerPresenceSetDelegate InPresenceSetDelegate);

    /// <summary>Replaces a user's current destination with the provided one.
    /// @note Other presence parameter settings will remain the same.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>   
    /// <param name="ApiName">The API name of the new destination.</param>
    /// <param name="InPresenceSetDestinationDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSetDestination(UObject* WorldContextObject, const FString& ApiName, FOnlineManagerPresenceSetDestinationDelegate InPresenceSetDestinationDelegate);

    /// <summary>Sets whether a user is joinable.
    /// @note Other presence parameter settings will remain the same. If the destination or session
    /// ID has not been set up for the user, the user cannot be set to "joinable".
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>  
    /// <param name="bIsJoinable">Defines whether the user is joinable:
    /// * `true`: joinable
    /// * `false`: not joinable
    /// </param>
    /// <param name="InPresenceSetIsJoinableDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSetIsJoinable(UObject* WorldContextObject, bool bIsJoinable, FOnlineManagerPresenceSetIsJoinableDelegate InPresenceSetIsJoinableDelegate);

    /// <summary>Replaces a user's current lobby session ID with the provided one.
    /// @note Other presence parameter settings will remain the same.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>  
    /// <param name="LobbySession">The new lobby session ID.</param>
    /// <param name="InPresenceSetLobbySessionDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSetLobbySession(UObject* WorldContextObject, const FString& LobbySession, FOnlineManagerPresenceSetLobbySessionDelegate InPresenceSetLobbySessionDelegate);

    /// <summary>Replaces a user's current match session ID with the provided one.
    /// @note Other presence-realated parameters will remain the same.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="MatchSession">The new match session ID.</param>
    /// <param name="InPresenceSetMatchSessionDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSetMatchSession(UObject* WorldContextObject, const FString& MatchSession, FOnlineManagerPresenceSetMatchSessionDelegate InPresenceSetMatchSessionDelegate);

    /// <summary>Sets extra presence data for a user.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="Extra">The extra presence data defined by the developer.</param> 
    /// <param name="InPresenceSetExtraDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSetExtra(UObject* WorldContextObject, const FString& Extra, FOnlineManagerPresenceSetExtraDelegate InPresenceSetExtraDelegate);

    /// <summary>Reads a list of sent invitations. 
    /// @note Call `GetSendInvitesList` after the Delegate has been executed.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="InPresenceReadSendInvitesDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceReadSendInvites(UObject* WorldContextObject, FOnlineManagerPresenceReadSentInvitesDelegate InPresenceReadSendInvitesDelegate);

    /// <summary>Sends invitations to users.
    /// @note Call `GetSendInvitesList` after the Delegate has been executed.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="UserIdArray">The ID array of the users to invite.</param>
    /// <param name="InPresenceSentInvitesDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceSendInvites(UObject* WorldContextObject, TArray<FString> UserIdArray, FOnlineManagerPresenceSentInvitesDelegate InPresenceSentInvitesDelegate);

    /// <summary>Gets a list of sent invitations when `PresenceSendInvites` or `PresenceReadSendInvites` is complete.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="OutList">The [out] array that receives the copied data.</param>
    /// <returns>Bool:
    /// * `true`: the invitation list has been found.
    /// * `false`: otherwise
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool GetSendInvitesList(UObject* WorldContextObject, TArray<FPicoApplicationInvite>& OutList);

    /// <summary>Gets all the destinations that can be set for a user.
    /// @note Call `PresenceGetDescriptionList` after the Delegate has been executed.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="InPresenceGetDestinationsDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceGetDestinations(UObject* WorldContextObject, FOnlineManagerPresenceGetDestinationsDelegate InPresenceGetDestinationsDelegate);

    /// <summary>Gets a list of destinations when `PresenceGetDestinations` is complete.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="OutList">The [out] array that receives the copied data.</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool PresenceGetDestinationsList(UObject* WorldContextObject, TArray<FPicoDestination>& OutList);

    /// <summary>Call up the system panel to invite friends.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="InLaunchInvitePanelDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool LaunchInvitePanel(UObject* WorldContextObject, FOnlineManagerLaunchInvitePanelDelegate InLaunchInvitePanelDelegate);

    /// <summary>Share videos or pictures to different platforms, currently only support sharing to Douyin apps.
    /// @note Video file requirements:
    /// For a better viewing experience, it is recommended to upload a 16:9 vertical video with a resolution of 720p(1280x720) and above
    /// Support common video formats, mp4 and webm are recommended
    /// The video file size should not exceed 128M and the duration should be within 15 minutes
    /// Videos over 50m are recommended to be uploaded in multiple segments, and the total video size should be within 4GB.A single shard is recommended to be 20MB, with a minimum of 5MB
    /// Image file requirements :
    /// The total size of the picture does not exceed 100M
    /// Up to 35 sheets at a time
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="InMediaType">The media type:
    /// * `0`: Video
    /// * `1`: Image
    /// * `2`: None
    /// </param>
    /// <param name="InVideoPath">The video file path.</param> 
    /// <param name="InVideoThumbPath">The path of the video cover or the first few frames of the video as the video thumb.</param> 
    /// <param name="InImagePaths">The array of image paths.</param> 
    /// <param name="InShareType">The share type:
    /// * `0`: Douyin
    /// * `1`: None
    /// </param>
    /// <param name="InShareMediaDelegate">Will be executed when the request has been completed(bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Presence")
    static bool ShareMedia(UObject* WorldContextObject, EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, FOnlineManagerShareMediaDelegate InShareMediaDelegate);

    /** @} */ // end of BP_Presence

    /** @defgroup BP_Application BP_Application
     *  This is the BP_Application group
     *  @{
     */

    // Application

    /// <summary>Launches a different app in a user's library.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="PackageName">The package name of the app to launch.</param>
    /// <param name="Message">A message to be passed to the launched app.</param> 
    /// <param name="InLaunchOtherAppDelegate">Will be executed when the request has been completed(FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Application")
    static bool LaunchOtherApp(UObject* WorldContextObject, const FString& PackageName, const FString& Message, FOnlineManagerLaunchOtherAppDelegate InLaunchOtherAppDelegate);


    /// <summary>
    /// Gets the current app's latest version in the PICO Store.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="InGetVersionDelegate">Will be executed when the request has been completed(int64, CurrentCode, FString, CurrentName, int64, LatestCode, FString, LatestName, bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Application")
    static bool GetVersion(UObject* WorldContextObject, FOnlineManagerGetVersionDelegate InGetVersionDelegate);

    /// <summary>Launches a different app in a user's library.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="AppID">The ID of the app to launch.</param>
    /// <param name="PackageName">The package name of the app to launch.</param>
    /// <param name="Message">A message to be passed to the launched app.</param>
    /// <param name="ApiName">The API name of the destination in the app.</param>
    /// <param name="LobbySessionId">The lobby session ID of the user's presence, which identifies a user group or team. Users with the same lobby session ID can play together or form a team in a game.</param>
    /// <param name="MatchSessionId">The match session ID of the user's presence, which identifies all users within the same destination, such as maps and levels. Users with different lobby session IDs will have the same match session ID when playing the same match.</param>
    /// <param name="TrackId">The tracking ID of the app launch event.</param>
    /// <param name="Extra">Extra data defined by the developer.</param>
    /// <param name="InLaunchOtherAppByPresenceDelegate">Will be executed when the request has been completed(FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Application")
    static bool LaunchOtherAppByPresence(UObject* WorldContextObject, const FString& AppID, const FString& PackageName, const FString& Message, const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, const FString& TrackId, const FString& Extra, FOnlineManagerLaunchOtherAppByPresenceDelegate InLaunchOtherAppByPresenceDelegate);

    /// <summary>Launches a different app in a user's library.
    /// @note If the user does not have that app installed, the user will be directed to that app's page on the PICO Store.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="AppId">The app id of the app to launch.</param>
    /// <param name="Message">A message to be passed to the launched app.</param> 
    /// <param name="InLaunchOtherAppByAppIdDelegate">Will be executed when the request has been completed(FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Application")
    static bool LaunchOtherAppByAppId(UObject* WorldContextObject, const FString& AppId, const FString& Message, FOnlineManagerLaunchOtherAppByAppIdDelegate InLaunchOtherAppByAppIdDelegate);


    /// <summary>
    /// Launches the PICO Store and jump to the details page of the current app.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world(FString, StringMessage, bool, IsSuccessed, FString, ErrorMessage).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Application")
    static bool LaunchStore(UObject* WorldContextObject, FOnlineManagerLaunchStoreDelegate InLaunchStoreDelegate);

    /** @} */ // end of BP_Application

    /** @defgroup BP_ApplicationLifecycle BP_ApplicationLifecycle
     *  This is the BP_ApplicationLifecycle group
     *  @{
     */

    // ApplicationLifecycle

    /// <summary>Gets information about how the app was launched.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="OutLaunchDetails">The [out] struct of launch details.</param> 
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|ApplicationLifecycle")
    static bool GetLaunchDetails(UObject* WorldContextObject, FLaunchDetails& OutLaunchDetails);

    /// <summary>Logs if the user has been successfully directed to the desired destination via a deep link.</summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name="TrackingID">The tracking ID of the app launch event.</param>
    /// <param name="LaunchResult">Enumerations of the launch result:
    /// * `Unknown`
    /// * `Success`
    /// * `FailedRoomFull`
    /// * `FailedGameAlreadyStarted`
    /// * `FailedRoomNotFound`
    /// * `FailedUserDeclined`
    /// * `FailedOtherReason`
    /// </param>
    /// <returns>Bool:
    /// * `true`: the result has been logged.
    /// * `false`: failed to log the result.
    /// </returns>
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|ApplicationLifecycle")
    static bool LogDeeplinkResult(UObject* WorldContextObject, const FString& TrackingID, ELaunchResult LaunchResult);

    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|ApplicationLifecycle")
    static bool GetSystemInfo(UObject* WorldContextObject, FPicoSystemInfo& SystemInfo);

    /** @} */ // end of BP_ApplicationLifecycle

    /** @defgroup BP_Leaderboard BP_Leaderboard(OnlineSub)
     *  This is the BP_Leaderboard(OnlineSub) group
     *  @{
     */

	// Leaderboard
	
    /// <summary>Get entries of a leaderboard.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name ="Players">If the num of players is bigger than zero, and the only player in it is the logged-in player, then the value of StartAt will be 'ppfLeaderboard_StartAtCenteredOnViewer'.</param>
    /// <param name ="PicoReadObject">Set leaderboard name in it.</param>
    /// <param name ="OnReadLeaderboardsCompleteDelegate">Executes this parameter after the request has been completed(bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboard")
	static bool ReadLeaderboards(UObject* WorldContextObject, const TArray<FString>& Players, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
	
	/// <summary>Get entries of a leaderboard.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="LocalUserNum">Not used.</param>
    /// <param name="PicoReadObject">Set leaderboard name in it.</param>
    /// <param name ="OnReadLeaderboardsCompleteDelegate">Executes this parameter after the request has been completed(bool, bWasSuccessful).</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboard")
	static bool ReadLeaderboardsForFriends(UObject* WorldContextObject, int32 LocalUserNum, UPARAM(ref)FPicoOnlineLeaderboardRead& PicoReadObject, FPicoManagerOnReadLeaderboardsCompleteDelegate OnReadLeaderboardsCompleteDelegate);
	
	/// <summary>Writes a entry of a leaderboard.
    /// </summary>
    /// <param name="WorldContextObject">Used to get the information about the current world.</param>
    /// <param name="SessionName">Not used.</param>
    /// <param name="Player">Need to be the logged-in player.</param>
    /// <param name="PicoWriteObject">Set leaderboard name and the score in it.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|Leaderboard")
	static bool WriteLeaderboards(UObject* WorldContextObject, const FString& SessionName, const FString& Player, UPARAM(ref)FPicoOnlineLeaderboardWrite& PicoWriteObject);
    /** @} */ // end of BP_Leaderboard(OnlineSub)
	
public:

    /** @defgroup BP_Common BP_Common
     *  This is the BP_Common group
     *  @{
     */

    /// <summary>Gets the class of online subsystem Pico manager for binding notifications.</summary>
    /// <returns>The UOnlineSubsystemPicoManager class.</returns>
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico")
    static UOnlineSubsystemPicoManager* GetOnlineSubsystemPicoManager(UObject* WorldContextObject);

    /// <summary>Extract ErrorCode from ErrorMessage.</summary>
    /// <param name="InErrorMessage">Returned from the OnlineSubsystem interface.</param>
    /// <param name="ErrorCode">Error code returned as a reference.</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico")
    static bool ParseErrorInfo(FString InErrorMessage, int32& ErrorCode);


    UFUNCTION(BlueprintCallable, Category = "OnlinePico")
    static void FindFileOrForder(TArray<FString>& OutFindArray, const FString& FindName, const FString& FindPath, bool IsFile = false, bool IsInDirectories = true);


    /** @} */ // end of BP_Common
    /** @} */ // end of BlueprintFunction

};

