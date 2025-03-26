// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "OnlineSubsystemPicoNames.h"


class FOnlinePicoFriend;

/// @file PicoPresenceInterface.h

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup Presence Presence
 *  This is the Presence group
 *  @{
 */



DECLARE_LOG_CATEGORY_EXTERN(PresenceInterface, Log, All);

// Request
DECLARE_DELEGATE_TwoParams(FOnPresenceClearComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnReadInvitableUserComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetDestinationComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetIsJoinableComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetLobbySessionComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetMatchSessionComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnPresenceSetPresenceExtraComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnReadSentInvitesComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnSentInvitesComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnGetDestinationsComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnLaunchInvitePanelComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);
DECLARE_DELEGATE_TwoParams(FOnShareMediaComplete, bool /*IsSuccessed*/, const FString& /*Error Message*/);


DECLARE_MULTICAST_DELEGATE_FiveParams(FJoinIntentReceived, const FString& /*DeeplinkMessage*/, const FString& /*DestinationApiName*/, const FString&/*LobbySessionId*/, const FString& /*MatchSessionId*/, const FString& /*Extra*/);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FLeaveIntentReceived, const FString& /*DestinationApiName*/, const FString&/*LobbySessionId*/, const FString& /*MatchSessionId*/);

/// <summary>Pico Presence interface class.</summary>
class ONLINESUBSYSTEMPICO_API FPicoPresenceInterface
{

private:

    FOnlineSubsystemPico& PicoSubsystem;

	TMap<FString, TSharedRef<FOnlinePicoFriend>> InvitableUsers;

	TArray<FPicoApplicationInvite> InvitesArray;

	TArray<FPicoDestination> DestinationArray;

public:
	FPicoPresenceInterface(FOnlineSubsystemPico& InSubsystem);
	~FPicoPresenceInterface();

    /// <summary>Clears a user's presence data in the current app.</summary>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceClear(const FOnPresenceClearComplete& Delegate = FOnPresenceClearComplete());
	void OnQueryPresenceClearComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceClearComplete& Delegate);

    /// <summary>Reads a list of invitable users for a user.
    /// @note Call `GetInvitableFriendList` after the Delegate has been executed.
    /// </summary>
    /// <param name ="SuggestedUserList">The ID list of users suggested being invited.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool ReadInvitableUser(TArray<FString> SuggestedUserList, const FOnReadInvitableUserComplete& Delegate = FOnReadInvitableUserComplete());
	void OnQueryReadInvitableUserComplete(ppfMessageHandle Message, bool bIsError, TMap<FString, TSharedRef<FOnlinePicoFriend>>& OutList, bool bAppendToExistingMap, const FOnReadInvitableUserComplete& Delegate);

    /// <summary>Gets a list of invitable friends for a user. These friends are previously retrieved from the online service when `PresenceGetDestinations` is complete.</summary>
    /// <param name ="OutFriends">The [out] array that receives the copied data.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool GetInvitableFriendList(TArray<TSharedRef<FOnlinePicoFriend>>& OutFriends);

    /// <summary>
    /// Sets presence data for a user in the current app.
    /// </summary>
    /// <param name ="ApiName">The API name of the destination.</param> 
    /// <param name ="LobbySessionId">The lobby session ID of the presence, which identifies a user group or team. Users with the same lobby session ID can play together or form a team in a game.</param> 
    /// <param name ="MatchSessionId">The match session ID of the presence, which identifies all users within the same destination, such as maps and levels. Users with different lobby session IDs will have the same match session ID when playing the same match.</param> 
    /// <param name ="bIsJoinable">Defines whether the presence is joinable:
    /// * `true`: joinable
    /// * `false`: not joinable
    /// </param> 
    /// <param name ="Extra">Extra presence data defined by the developer.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceSet(const FString& ApiName, const FString& LobbySessionId, const FString& MatchSessionId, bool bIsJoinable, const FString& Extra, const FOnPresenceSetComplete& Delegate = FOnPresenceSetComplete());
	void OnQueryPresenceSetComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetComplete& Delegate);

    /// <summary>Replaces a user's current destination with the provided one.
    /// @note Other presence-related parameters will remain the same.
    /// </summary>
    /// <param name ="ApiName">The API name of the new destination.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceSetDestination(const FString& ApiName, const FOnPresenceSetDestinationComplete& Delegate = FOnPresenceSetDestinationComplete());
	void OnQueryPresenceSetDestinationComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetDestinationComplete& Delegate);

    /// <summary>Sets whether a user is joinable.
	/// @note Other presence-related parameters will remain the same. If the destination or session
	/// ID has not been set up for the user, the user cannot be set as "joinable".
    /// </summary>
    /// <param name ="bIsJoinable">Defines whether the user is joinable:
    /// * `true`: joinable
    /// * `false`: not joinable
    /// </param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool PresenceSetSetIsJoinable(bool bIsJoinable, const FOnPresenceSetIsJoinableComplete& Delegate = FOnPresenceSetIsJoinableComplete());
    void OnQueryPresenceSetSetIsJoinableComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetIsJoinableComplete& Delegate);

    /// <summary>Replaces a user's current lobby session ID with the provided one.
    /// @note Other presence parameter settings will remain the same.
    /// </summary>
    /// <param name ="LobbySession">The new lobby session ID.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool PresenceSetLobbySession(const FString& LobbySession, const FOnPresenceSetLobbySessionComplete& Delegate = FOnPresenceSetLobbySessionComplete());
    void OnQueryPresenceSetLobbySessionComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetLobbySessionComplete& Delegate);

    /// <summary>Replaces a user's current match session ID with the provided one.
    /// @note Other presence parameter settings will remain the same.
    /// </summary>
    /// <param name ="MatchSession">The new match session ID.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
    bool PresenceSetMatchSession(const FString& MatchSession, const FOnPresenceSetMatchSessionComplete& Delegate = FOnPresenceSetMatchSessionComplete());
    void OnQueryPresenceSetMatchSessionComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetMatchSessionComplete& Delegate);

    /// <summary> 
    /// Sets extra presence data for a user.
    /// </summary>
    /// <param name ="Extra">Extra presence data defined by the developer.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceSetExtra(const FString& Extra, const FOnPresenceSetPresenceExtraComplete& Delegate = FOnPresenceSetPresenceExtraComplete());
	void OnQueryPresenceSetExtraComplete(ppfMessageHandle Message, bool bIsError, const FOnPresenceSetPresenceExtraComplete& Delegate);

    /// <summary>Reads a list of sent invitations.
    /// @note Call `GetSendInvitesList` after the Delegate has been executed.
    /// </summary>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceReadSendInvites(const FOnReadSentInvitesComplete& Delegate = FOnReadSentInvitesComplete());
	void OnQueryPresenceReadSendInvitesComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoApplicationInvite>& OutList, bool bAppendToExistingArray, const FOnReadSentInvitesComplete& Delegate);

	/// <summary>Sends invitations to users.
	/// @note Call `GetSendInvitesList` after the Delegate has been executed.
    /// </summary>
    /// <param name ="UserIdArray">The ID array of the users to invite.</param> 
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceSendInvites(TArray<FString> UserIdArray, const FOnSentInvitesComplete& Delegate = FOnSentInvitesComplete());
	void OnQuerySendInvitesComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoApplicationInvite>& OutList, bool bAppendToExistingArray, const FOnSentInvitesComplete& Delegate);

    /// <summary>Gets a list of sent invitations when `PresenceSendInvites` or `PresenceReadSendInvites` is complete.</summary>
    /// <param name ="OutList">The [out] array that receives the copied data.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool GetSendInvitesList(TArray<FPicoApplicationInvite>& OutList);

    /// <summary>Gets all the destinations that can be set for a user.
    /// @note Call `PresenceGetDescriptionList` after the Delegate has been executed.
    /// </summary>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceGetDestinations(const FOnGetDestinationsComplete& Delegate = FOnGetDestinationsComplete());
	void OnQueryGetDestinationsComplete(ppfMessageHandle Message, bool bIsError, TArray<FPicoDestination>& OutList, bool bAppendToExistingArray, const FOnGetDestinationsComplete& Delegate);

    /// <summary>Gets a list of destinations when `PresenceGetDestinations` is complete.</summary>
    /// <param name ="OutList">The [out] array that receives the copied data.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: Sending request succeeded</li>
    /// <li>`false`: Sending request failed</li>
    /// </ul>
    /// </returns>
	bool PresenceGetDestnationsList(TArray<FPicoDestination>& OutList);

    /// <summary>Call up the system panel to invite friends.</summary>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    bool LaunchInvitePanel(const FOnLaunchInvitePanelComplete& Delegate = FOnLaunchInvitePanelComplete());

    /// <summary>Share videos or images to Douyin (a video app in Mainland China). Currently, this function is available in Mainland China only.
    /// @note
    /// * Video file requirements:
    /// For a better viewing experience, it is recommended to upload a 16:9 vertical video with a resolution of 720p(1280x720) and above
    /// Support common video formats, mp4 and webm are recommended.
    /// The video file size should not exceed 128M and the duration should be within 15 minutes.
    /// Videos over 50m are recommended to be uploaded in multiple segments, and the total video size should be within 4GB. A single shard is recommended to be 20MB, with a minimum of 5MB.
    /// * Image file requirements :
    /// The total size of the picture does not exceed 100M
    /// Up to 35 sheets at a time
    /// </summary>
    /// <param name="InMediaType">The media type:
    /// * `0`: Video
    /// * `1`: Image
    /// * `2`: None
    /// </param>
    /// <param name="InVideoPath">The path to the video file.</param> 
    /// <param name="InVideoThumbPath">The path to the video thumbnail. If not defined, the first frame of the video will become the video thumbnail.</param> 
    /// <param name="InImagePaths">The array of image paths.</param> 
    /// <param name="InShareType">The share type:
    /// * `0`: Douyin
    /// * `1`: None
    /// </param>
    /// <param name ="Delegate">Will be executed when the request has been completed.  
    /// Delegate will contain the requested object class (bool /*IsSuccessed*/, const FString& /*Error Message*/).</param>
    /// <returns>Bool:
    /// * `true`: success
    /// * `false`: failure
    /// </returns>
    bool ShareMedia(EShareMediaType InMediaType, const FString& InVideoPath, const FString& InVideoThumbPath, TArray<FString> InImagePaths, EShareAppTyp InShareType, const FOnShareMediaComplete& Delegate = FOnShareMediaComplete());
	
PACKAGE_SCOPE:

    FDelegateHandle OnJoinIntentReceivedHandle;
    void OnJoinIntentReceiveResult(ppfMessageHandle Message, bool bIsError);

    FDelegateHandle OnLeaveIntentReceivedHandle;
    void OnLeaveIntentReceiveResult(ppfMessageHandle Message, bool bIsError);
public:

    /// @brief Gets notified when the join intent has been received.
	FJoinIntentReceived JoinIntentReceivedCallback;

    // unavailable
	FLeaveIntentReceived LeaveIntentReceivedCallback;
};
/** @} */ // end of Presence
/** @} */ // end of Function