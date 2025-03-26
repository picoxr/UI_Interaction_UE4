// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineStats.h"
#include "OnlineSubsystemPicoNames.generated.h"


#ifndef PICO_SUBSYSTEM
#define PICO_SUBSYSTEM FName(TEXT("Pico"))
#endif
class UPico_UserArray;

/// @file OnlineSubsystemPicoNames.h

 /** @defgroup Data Data
  *  This is the Data group
  *  @{
  */

/* PPF_UserPresenceStatus.h */
/// <summary>User's current online status.</summary>
UENUM(BlueprintType)
enum class EUserPresenceStatus : uint8
{
    Unknow, /**< Unknown */
    OnLine, /**< Online */
    OffLine /**< Offline */
};

/* PPF_Gender.h   */
/// <summary>User's gender.</summary>
UENUM(BlueprintType)
enum class EUserGender : uint8
{
    Unknow, /**< Unknown */
    Male, /**< Male */
    Female /**< Female */
};

/* PPF_User.h  */
/// <summary>User's information.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "OnlinePicoUserInfo"))
struct FPicoUserInfo
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString UserId; /*!< User's ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString DisplayName; /*!< User's display name */ 

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    EUserPresenceStatus UserPresenceStatus; /*!< User's current online status */ 

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString InviteToken; /*!< User's invite token */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString ImageUrl; /*!< User's image URL */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString SmallImageUrl; /*!< User's small image URL */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresencePackage; /*!< The package name of the app corresponding to the presence */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceStr; /*!< The name of the user's current presence */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceDeeplinkMessage; /*!< User's presence deeplink message */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceDestinationApiName; /*!< User's presence destination API name */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceLobbySessionId; /*!< User's presence lobby session ID */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceMatchSessionId; /*!< User's presence match session ID */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    FString PresenceExtra; /*!< User's extra presence info */

    UPROPERTY(BlueprintReadWrite, Category = "OnlinePicoUserInfo")
    EUserGender Gender; /*!< User's presence gender */
};

/* ppf_LaunchType.h */

/// <summary>App launch type.</summary>
UENUM(BlueprintType, meta = (DisplayName = "LaunchType"))
enum class ELaunchType : uint8
{
    Unknown, /**< Unknown */
    Normal, /**< Normal */
    RoomInvite, /**< Room Invite */
    Deeplink, /**< Deeplink */
    ChallengeInvite /**< Challenge Invite */
};

/* ppf_LaunchResult.h */

/// <summary>App launch result.</summary>
UENUM(BlueprintType, meta = (DisplayName = "LaunchResult"))
enum class ELaunchResult : uint8
{
    Unknown,
    Success,
    FailedRoomFull, 
    FailedGameAlreadyStarted,
    FailedRoomNotFound, 
    FailedUserDeclined, 
    FailedOtherReason
};

/* ppf_LaunchDetails.h */

/// <summary>App launch details when succeeded.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "LaunchDetails"))
struct FLaunchDetails
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString DeeplinkMessage; /*!< The deeplink message */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString DestinationApiName; /*!< The destination's API name */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString LobbySessionID; /*!< The lobby session ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString MatchSessionID; /*!< The match session ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString Extra; /*!< The extra presence info */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString RoomID; /*!< The room ID */

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString ChallengeID; /*!< The challenge ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    FString TrackingID; /*!< The tracking ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "ApplicationLifecycle")
    ELaunchType LaunchType; /*!< The launch type */ 

};

/// <summary>The type of room you can create.</summary>
UENUM(BlueprintType, meta = (DisplayName = "RoomType"))
enum class ERoomType : uint8
{
    TypeUnknown, /**< Unknown */
    TypeMatchmaking, /**< Matchmaking room */
    TypeModerated, /**< Moderated room */
    TypePrivate /**< Private room */
};

/// <summary>The join policy type of a room.</summary>
UENUM(BlueprintType, meta = (DisplayName = "RoomJoinPolicy"))
enum class ERoomJoinPolicy : uint8
{
    JoinPolicyNone, /**< None */
    JoinPolicyEveryone, /**< Everyone */
    JoinPolicyFriendsOfMembers, /**< Friends of room members */
    JoinPolicyFriendsOfOwner, /**< Friends of the room owner */
    JoinPolicyInvitedUsers, /**< Invited users */
    JoinPolicyUnknown /**< Unknown */
};

/// <summary>The joinability of a room.</summary>
UENUM(BlueprintType, meta = (DisplayName = "RoomJoinabilit"))
enum class ERoomJoinabilit : uint8
{
    JoinabilityUnknown, /**< Unknown */
    JoinabilityAreIn, /**< The user is already in the room */
    JoinabilityAreKicked, /**< The user has been kicked out of the room */
    JoinabilityCanJoin, /**< The user is able to join the room */
    JoinabilityIsFull, /**< The room is full */
    JoinabilityNoViewer, /**< Not used */
    JoinabilityPolicyPrevents /**< The user is prevented by the room's join policy */
};

/* PPF_Destination.h */
/// <summary>The destination information.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoDestination"))
struct FPicoDestination
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString ApiName; /*!< The destination's API name */ 

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString DeepLinkMessage; /*!< The destination's deeplink message */ 

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString DisplayName; /*!< The destination's display name */ 
};

/* PPF_ApplicationInvite.h  */
/// <summary>The app's invite information.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoApplicationInvite"))
struct FPicoApplicationInvite
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FPicoUserInfo Recipent; /*!< Information about the person who accepted the invitation */ 

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FPicoDestination Destination; /*!< The destination information */

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString ID; /*!< The app's invite ID */

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    bool bIsActive; /*!< Whether the app invite is active */

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString LobbySessionId; /*!< The lobby session ID */ 

    UPROPERTY(BlueprintReadWrite, Category = "Destination")
    FString MatchSessionId; /*!< The match session ID */ 
};

UENUM(BlueprintType)
enum class EOnlineAsyncTaskStatePicoType : uint8
{
    NotStarted,
    InProgress,
    Done,
    Failed
};

/// <summary>Error message for joining a session.</summary>
UENUM(BlueprintType)
enum class EOnJoinSessionCompleteResultPicoType : uint8
{
    Success, /**< Success */
    SessionIsFull, /**< The session is full. When `ppf_Room_GetJoinability` return `ppfRoom_JoinabilityIsFull` */
    SessionDoesNotExist, /**< The session does not exist. When use `JoinSession` with invalid `sessionInfo` */
    CouldNotRetrieveAddress, /**< Not used */
    AlreadyInSession, /**< Already in the session. When `ppf_Room_GetJoinability` return `ppfRoom_JoinabilityAreIn` */
    UnknownError /**< Unknown. Default failure reason */
};

/// <summary>The state of the session.</summary>
UENUM(BlueprintType)
enum class EOnlineSessionStatePicoType : uint8
{
    NoSession, /**< Not in the session */
    Creating, /**< The session is being created */
    Pending, /**< The session has been created */
    Starting, /**< Not used */
    InProgress, /**< The session is in progress, which means the user has joined a session */
    Ending, /**< Not used */
    Ended, /**< After calling `EndSession`, the state of an in-progress session will turn to 'ended' */
    Destroying /**< The user has left the session */
};

/// <summary>The settings of a session. Similar to `FOnlineSessionSettings`.
/// @note
/// | Private Room's Join Policy | Settings |
/// |--|--|
/// | `InvitedUsers` | <ul><li>(Default) `bShouldAdvertise`=`false`</li><br>or</br><li> (`bShouldAdvertise` & `bAllowInvites`=`true`) and (`bAllowJoinViaPresence` & `bAllowJoinViaPresenceFriendsOnly`=`false`)</li></ul> |
/// | `FriendsOfMembers` | `bShouldAdvertise` & `bAllowJoinViaPresenceFriendsOnly`=`true` |
/// | `Everyone` | `bShouldAdvertise`=`true` and (`bAllowJoinViaPresence`=`true` or `bAllowInvites`=`false`) |
/// </summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSettings"))
struct FPicoOnlineSessionSettings
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int NumPublicConnections; /*!< The maximum number of users allowed for the session */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int NumPrivateConnections; /*!< Need to be zero */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bShouldAdvertise; /*!< When creating a private room, this field will affect the room's join policy. */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowInvites; /*!< When creating a private room, this field will affect the room's join policy */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bUsesPresence; /*!< When creating a private room, this field will affect the room's join policy */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowJoinViaPresence; /*!< When creating a private room, this field will affect the room's join policy */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    bool bAllowJoinViaPresenceFriendsOnly; /*!< When creating a private room, this field will affect the room's join policy */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    int BuildUniqueId; /*!< Will be saved in datastore with the key `PICOSESSIONBUILDUNIQUEID`. You don't need to use this field */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    TArray<FString> KeyArray; /*!< Datastore keys. When creating a matchmaking room, you need to add the key `PICOPOOL` */ 

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSettings")
    TArray<FString> ValueArray; /*!< Datastore values. When creating a matchmaking room, you need to add the value of the key `PICOPOOL` */ 
};

/// <summary>Basic session information. Similar to `FOnlineSession`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSession"))
struct FPicoOnlineSession
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString OwningUserId; /*!< The ID of the session owner */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString OwningUserName; /*!< The name of the session owner */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FPicoOnlineSessionSettings SessionSettings; /*!< The settings associated with this session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    FString SessionInfoRoomID; /*!< The ID of the room of this session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    int32 NumOpenPrivateConnections; /*!< Zero, you don't need to use this field */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSession")
    int32 NumOpenPublicConnections; /*!< The number of people who can still enter the room */
};
/// <summary>Holds the per session information for named sessions. Similar to `FNamedOnlineSession`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoNamedOnlineSession"))
struct FPicoNamedOnlineSession
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString SessionName; /*!< The name of the session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 HostingPlayerNum; /*!< The number when you use `PicoSubsystem.GetIdentityInterface()` -> `GetUniquePlayerId` */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    bool bHosting; /*!< Not used */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString LocalOwnerId; /*!< NetId of the local player that created this named session. */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    TArray< FString > RegisteredPlayers; /*!< The players in the room */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    EOnlineSessionStatePicoType SessionState; /*!< State of the session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString OwningUserId; /*!< The ID of the session owner */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString OwningUserName; /*!< The name of the session owner */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FPicoOnlineSessionSettings SessionSettings; /*!< The settings associated with this session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    FString SessionInfoRoomID; /*!< The ID of the room of this session */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 NumOpenPrivateConnections; /*!< Zero, you don't need to use this field */

    UPROPERTY(BlueprintReadWrite, Category = "PicoNamedOnlineSession")
    int32 NumOpenPublicConnections; /*!< The number of people who can still enter the room */
};
/// <summary>Representation of a single search result. Similar to `FOnlineSessionSearchResult`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSearchResult"))
struct FPicoOnlineSessionSearchResult
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearchResult")
    FPicoOnlineSession Session; /*!< Searched room information */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearchResult")
    int32 PingInMs; /*!< Not used */
};

/// <summary>Representation of a single search result. Similar to FOnlineSessionSearch.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineSessionSearch"))
struct FPicoOnlineSessionSearch
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FPicoOnlineSessionSearchResult> SearchResults; /*!< Array of all sessions found when searching by the given criteria */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    EOnlineAsyncTaskStatePicoType SearchState; /*!< State of the search */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 MaxSearchResults; /*!< The number of query results will be limited by the maximum number of searches */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FString> QuerySettingsKeyArray; /*!< Key for query.
    If you need to query matchmaking rooms, you need to add a key: `PICOPOOL`.
    If you need to query the moderated rooms, you need to add three keys: `PICOMODERATEDROOMSONLY`, `GETMODERATEDROOMSPAGEINDEX`, `GETMODERATEDROOMSPAGESIZE`
    */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    TArray<FString> QuerySettingsValueArray; /*!< Value for query. Need to exist in pair with keys */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    bool bIsLanQuery; /*!< Not used */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 PingBucketSize; /*!< Not used */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    int32 PlatformHash; /*!< Not used */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineSessionSearch")
    float TimeoutInSeconds; /*!< Not used */
};

/// <summary>The score type used in `FOnlineLeaderboardPico`.</summary>
UENUM(BlueprintType)
enum class EPicoOnlineKeyValuePairDataType : uint8
{
    Empty,
    Int32,
    UInt32, 
    Int64, 
    UInt64, 
    Double, 
    String,
    Float, 
    Blob, 
    Bool,
    Json, 
    MAX 
};

/// <summary>Container for storing data of variable type. Similar to `FVariantData`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "FVariantDataPico"))
struct  FVariantDataPico
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineStatsRow")
    EPicoOnlineKeyValuePairDataType Type;

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineStatsRow")
    FString Value;
};

/// <summary>Column metadata for this leaderboard.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "FPicoColumnMetaData"))
struct FPicoColumnMetaData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "FPicoColumnMetaData")
    FString ColumnName; /*!< The name of the column */

    UPROPERTY(BlueprintReadWrite, Category = "FPicoColumnMetaData")
    EPicoOnlineKeyValuePairDataType DataType; /*!< The data type of the ColumnMetadata */
};

/// <summary>Representation of a single row in a retrieved leaderboard. Similar to `FOnlineStatsRow`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "FPicoOnlineStatsRow"))
struct FPicoOnlineStatsRow
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(BlueprintReadWrite, Category = "FPicoOnlineStatsRow")
    FString NickName; /*!< Name of the player in this row. It will be the result of `ppf_User_GetDisplayName` */

    UPROPERTY(BlueprintReadWrite, Category = "FPicoOnlineStatsRow")
    FString PlayerId; /*!< Unique ID for the player in this row */

    UPROPERTY(BlueprintReadWrite, Category = "FPicoOnlineStatsRow")
    int32 Rank; /*!< Player's rank in this leaderboard */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineStatsRow")
    TMap<FName, FVariantDataPico> Columns; /*!< All requested data on the leaderboard for this player */
};

/// <summary>Interface for reading data from a leaderboard service. Similar to `FOnlineLeaderboardRead`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineLeaderboardRead"))
struct FPicoOnlineLeaderboardRead
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    FString LeaderboardName; /*!< The name of the leaderboard to read */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    FString SortedColumn; /*!< The column this leaderboard is sorted by */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    TArray<FPicoOnlineStatsRow> Rows; /*!< The array of ranked users retrieved */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    EOnlineAsyncTaskStatePicoType ReadState; /*!< Indicates an error reading data occurred while processing */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    TArray<FPicoColumnMetaData> ColumnMetadata; /*!< Column metadata for this leaderboard */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    int PageIndex; /*!< The page number where the leaderboard you want to read begins. Start from `0` */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardRead")
    int PageSize; /*!< The number of leaderboards to be returned on each page */

};

/// <summary>The update method type used in `FOnlineLeaderboardPico`.</summary>
UENUM(BlueprintType)
enum class ELeaderboardUpdateMethodPicoType : uint8
{
    KeepBest, /**< Keep the best score */
    Force /**< Force update the score */
};

/// <summary>Interface for writing data to a leaderboard. Similar to `FOnlineLeaderboardWrite`.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoOnlineLeaderboardWrite"))
struct FPicoOnlineLeaderboardWrite
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardWrite")
    ELeaderboardUpdateMethodPicoType UpdateMethod; /*!< Update method */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardWrite")
    TArray<FString> LeaderboardNames; /*!< Names of the leaderboards to write data to */
    
    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardWrite")
    FString RatedStat; /*!< Name of the stat that the leaderboard is rated by */

    UPROPERTY(BlueprintReadWrite, Category = "PicoOnlineLeaderboardWrite")
    int32 ValueToWrite; /*!< The score you want to write in a leaderboard */
};

/// <summary>User's exercise goals.</summary>
UENUM(BlueprintType)
enum class ESportTarget : uint8
{
    None, /**< None */
    LoseFat, /**< Lose fat */
    KeepFit /**< Keep fit */
};

/// <summary>The type of the achievement.</summary>
UENUM(BlueprintType)
enum class EAchievementType : uint8
{
    Unknown,
    Simple,
    Count,
    Bitfield,
};
/// <summary>The write policy of the achievement.</summary>
UENUM(BlueprintType)
enum class EAchievementWritePolicy : uint8
{
    Unknown, /**< Unknown */
    Client, /**< Both the client and server can write data to the leaderboard */
    Server, /**< Only the server can write data to the leaderboard */
};

/// <summary>The status of the file in the file download process.</summary>
UENUM(BlueprintType)
enum class EAssetFileDownloadCompleteStatus : uint8
{
    Downloading, /**< File is downloading */
    Succeed, /**< The file has been downloaded successfully */
    Failed, /**< File download failed */
    Unkonw /**< Unknown */
};

/// <summary>Share media type.</summary>
UENUM(BlueprintType)
enum class EShareMediaType : uint8
{
    Video, /**< Video */
    Image, /**< Image */
    None /**< None */
};

/// <summary>Share to app type.</summary>
UENUM(BlueprintType)
enum class EShareAppTyp : uint8
{
    Douyin, /**< Douyin */
    None /**< None */
};

inline uint64 FStringTouint64(FString InStr)
{
    return FCString::Strtoui64(*InStr, NULL, 10);
};

inline FString uint64ToFString(uint64 Inuint64)
{
    return FString::Printf(TEXT("%llu"), Inuint64);
};


/// <summary>The creator of the challenge.</summary>
UENUM(BlueprintType)
enum class EChallengeCreationType : uint8
{
    Unknown, /**< Unknown */
    UserCreated, /**< User */
    DeveloperCreated /**< Developer */
};

/// <summary>The visibility type of the challenge.</summary>
UENUM(BlueprintType)
enum class EChallengeVisibility : uint8
{
    Unknown, /**< Unknown */
    InviteOnly, /**< Visible to invited users only */
    Public, /**< Visible to all users */
    Private /**< Visible to the creator only */
};

/// <summary>The challenge viewer filter.</summary>
UENUM(BlueprintType)
enum class EChallengeViewerFilter : uint8 {
    Unknown, /**< Unknown */
    AllVisible, /**< Challenges that are visible to all users */
    Participating, /**< Challenges that you are participating in  */
    Invited, /**< Challenge that you have been invited to */
    ParticipatingOrInvited /**< Challenges that you are participating in or have been invited to */
};

/// <summary>The type of sorting to use when getting leaderboard or challenge entries. </summary>
UENUM(BlueprintType)
enum class ELeaderboardStartAt : uint8
{
    Top, /**< Return entries from top 1 */
    CenteredOnViewer, /**< Place the current logged-in user's entry in the middle of the list on the first page.
    For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed
    on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be
    displayed on the second page */
    CenteredOnViewerOrTop, /**< Place the current logged-in user's entry on the top of the list on the first page.
    For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,
    the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,
    and top 10 will be displayed on the second page */
    Unknown /**< Unknown */
};

/// <summary>The type of filter to use when using leaderboards or challenges.</summary>
UENUM(BlueprintType)
enum class ELeaderboardFilterType : uint8
{
    None, /**< Returns all entries */
    Friends, /**< Returns your and your friends' entries */
    Unknown, /**< Returns no entry */
    UserIds /**< Returns no entry */
};

/// <summary>Supplementary metrics for leaderboards.</summary>
USTRUCT(BlueprintType, meta = (DisplayName = "PicoSupplementaryMetric"))
struct FPicoSupplementaryMetric
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "SupplementaryMetric")
    FString ID; /*!< The ID of the supplementary metric */

    UPROPERTY(BlueprintReadWrite, Category = "SupplementaryMetric")
    FString Metric; /*!< The value of the supplementary metric */
};

/// <summary>Add-on type.</summary>
UENUM(BlueprintType)
enum class EAddonsType : uint8
{
    Invalid, /**< Invalid */
    Durable, /**< A durable is permanently available after one purchase */
    Consumable, /**< A consumable will be used up and can be purchased again */
    Subscription, /**< Subscription add-ons can be subscribed to, renewed, and unsubscribed from */
    Unknown /**< Unknown */
};

/// <summary>Subscription period type.</summary>
UENUM(BlueprintType)
enum class EPeriodType : uint8
{
    Invalid, /**< Invalid type*/
    None, /**< None */
    Hour, /**< Hourly */
    Day, /**< Daily */
    Week, /**< Weekly */
    Month, /**< Monthly */
    Quarter, /**< Quarterly */
    Year, /**< Annually */
    Unknown /**< Unknown */
};

/// <summary>Discount type.</summary>
UENUM(BlueprintType)
enum class EDiscountType : uint8
{
    Invalid, /**< Invalid */
    Null, /**< Null*/
    FreeTrial, /**< Free trial */
    Discount, /**< Discounted */
    Unknown /**< Unknown */
};

/// <summary>The subscription entitlement status type.</summary>
UENUM(BlueprintType)
enum class EEntitlementStatus : uint8
{
    None,  /**< None */
    Valid, /**< Valid */
    Invalid, /**< Invalid */
    GracePeriod, /**< Grace period */
    Pause, /**< Paused */
    Expired, /**< Expired */
    Cancel /**< Cancelled */
};

/// <summary>The subscription entitlement cancel reason type.</summary>
UENUM(BlueprintType)
enum class ECancelReason : uint8
{
    None,  /**< None */
    UserCancelsExpiration,  /**< User unsubscribes and the subscription expires */
    DeductionFailedExpired,  /**< Auto-Deduction fails and subscription expires */
    NoMainApplicationInterest  /**< The user does not have the current app */
};

/// <summary>User ordering.</summary>
UENUM(BlueprintType)
enum class EUserOrdering : uint8
{
    None,
    PresenceAlphabetical
};

/// <summary>Time window used in room options.</summary>
UENUM(BlueprintType)
enum class ETimeWindow : uint8
{
    Unknown,
    OneHour,
    OneDay,
    OneWeek,
    ThirtyDays,
    NinetyDays
};
/// <summary>Room options.</summary>
USTRUCT(BlueprintType)
struct FPicoRoomOptions
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") FString RoomId;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") FString RoomName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") FString RoomPassword;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") int32 MaxUserResults;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") bool bExcludeRecentlyMet;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") EUserOrdering Ordering;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") ETimeWindow TimeWindow; 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") bool bTurnOffUpdates;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") FString DataStoreKey;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Room|Room Options") FString DataStoreValue;
};

/// <summary>Room membership lock status.</summary>
UENUM(BlueprintType)
enum class ERoomMembershipLockStatus : uint8
{
    Unknown,
    Lock,
    Unlock
};
/// <summary>Matchmaking options.</summary>
USTRUCT(BlueprintType)
struct FPicoMatchmakingOptions
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") int32 RoomMaxUsers;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") ERoomJoinPolicy RoomJoinPolicy;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") bool bEnqueueIsDebug;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") FString DataStoreKey;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") FString DataStoreValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") FString EnqueueQueryKey;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") TMap<FString, int> EnqueueDataSettingsInt;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") TMap<FString, float> EnqueueDataSettingsFloat;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|Matchmaking|Matchmaking Options") TMap<FString, FString> EnqueueDataSettingsString;
};
/// <summary>Matchmaking stat approach.</summary>
UENUM(BlueprintType)
enum class EMatchmakingStatApproach : uint8
{
    Unknown,
    Trailing,
    Swingy
};

/// <summary>Used to write achievements progress or unlock achievements.</summary>
class FOnlineAchievementsWritePico : public FOnlineAchievementsWrite
{
public:
    FOnlineAchievementsWritePico()
    {

    }
    FOnlineKeyValuePairs<FString, FVariantData> PicoProperties;
    void SetPicoIntStat(const FString& StatName, int32 Value)
    {
        FVariantData* Stat = PicoProperties.Find(StatName);;
        if (Stat != NULL && Stat->GetType() == EOnlineKeyValuePairDataType::Int32)
        {
            // Set the value
            Stat->SetValue(Value);
        }
        else
        {
            FVariantData NewValue(Value);
            PicoProperties.Add(StatName, NewValue);
        }
    }
};

typedef TSharedRef<FOnlineAchievementsWritePico, ESPMode::ThreadSafe> FOnlineAchievementsWritePicoRef;
typedef TSharedPtr<FOnlineAchievementsWritePico, ESPMode::ThreadSafe> FOnlineAchievementsWritePicoPtr;


/// <summary>Used to write leaderboards data.</summary>
class Pico_OnlineLeaderboardWrite : public FOnlineLeaderboardWrite
{
private:
public:
    TArray<FString> PicoLeaderboardNames;
    Pico_OnlineLeaderboardWrite(const TArray<FString> InLeaderboardNames)
    {
        for (const auto& LeaderboardName : InLeaderboardNames)
        {
            PicoLeaderboardNames.Add(LeaderboardName);
            // LeaderboardNames.Add(FName(LeaderboardName));
        }
    }
    Pico_OnlineLeaderboardWrite()
    {
		
    }
};

/// <summary>Used to read leaderboards data.</summary>
class Pico_OnlineLeaderboardRead : public FOnlineLeaderboardRead
{
public:
    FString PicoLeaderboardName;
    int PicoPageIndex;
    int PicoPageSize;
    Pico_OnlineLeaderboardRead(const FString& InLeaderboardName, int PageIndex, int PageSize)
    {
        PicoLeaderboardName = InLeaderboardName;
        // LeaderboardName = FName(InLeaderboardName);
        PicoPageIndex = PageIndex;
        PicoPageSize = PageSize;
    }
};

/// <summary>User relation type.</summary>
UENUM(BlueprintType)
enum class EUserRelationType : uint8
{
    Unknown, /**< Unknown */
    IsFriend, /**< Is friend*/
    NotFriend, /**< Not friend */
    Blocked, /**< Blocked */
    BlockedBy, /**< Blocked by ask */
    ApplyingFriend /**< Applying friend */
};


/// <summary>Detect sensitive scene type.</summary>
UENUM(BlueprintType)
enum class EDetectSensitiveScene : uint8
{
    None, /**< None*/
    UserName, /**< User name */
    RoomName, /**< Room name */
    RoomChat, /**< Room chat */
};

/// <summary>Sensitive proposal type.</summary>
UENUM(BlueprintType)
enum class ESensitiveProposal : uint8
{
    None, /**< None*/
    Pass, /**< Do not handle the text*/
    OnlySelfVisible, /**< Make the text only visible to the sender*/
    UserMute, /**< Disable the user from sending messages*/
    RejectSubmit, /**< Reject the user's submission */
};

/// <summary>System Information.</summary>
USTRUCT(BlueprintType)
struct FPicoSystemInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info") 
    FString ROMVersion;/*!< The ROM version of the device system */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info")
    FString Locale;/*!< The region of the device system */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info") 
    FString ProductName;/*!< The product name of the device system */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info") 
    bool bIsCnDevice;/*!< Whether the device is global or in mainland China */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info") 
    FString MatrixVersionName;/*!< The matrix version name of the device system*/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OnlinePico|ApplicationLifecycle|System Info") 
    int64 MatrixVersionCode;/*!< The matrix version code of the device system */
};

/// <summary>AsrEngine Init Result.</summary>
UENUM(BlueprintType)
enum class EAsrEngineInitResult : uint8
{
    None, /**< None*/
    Unknown, /**< Unknown*/
    Arch32BitNotSupported, /**< Arch32BitNotSupported*/
    InvalidConfig, /**< InvalidConfig*/
    AlreadyInitialized, /**< AlreadyInitialized*/
    Success, /**< Success */
};


/** @} */ // end of Data