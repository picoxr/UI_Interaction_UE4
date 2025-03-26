
#ifndef PPF_REQUESTS_CHALLENGES_H
#define PPF_REQUESTS_CHALLENGES_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_ChallengeArray.h"
#include "PPF_ChallengeEntryArray.h"
#include "PPF_ChallengeOptions.h"
#include "PPF_LeaderboardFilterType.h"
#include "PPF_LeaderboardStartAt.h"
#include <stdbool.h>

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ppfMessage_Challenges_Create will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
/// PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Create(const char *leaderboardName, ppfChallengeOptionsHandle challengeOptions);

/// Invite a user to a challenge.
/// \param challengeID The id of the challenge.
/// \param userIDs Defines a list of user ids to be invited.
/// \param userIDLength The number of user IDs provided.
/// A message with type ::ppfMessage_Challenges_Invite will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Invites(ppfID challengeID, const char** userIDs, unsigned int userIDLength);

/// DEPRECATED. Use IM call instead.
/// 
/// If the current user has an invite to the challenge, decline the invite
///
/// A message with type ::ppfMessage_Challenges_DeclineInvite will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
/// PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_DeclineInvite(ppfID challengeID);

/// If the current user has an invite to the challenge, accept the invite
///
/// A message with type ::ppfMessage_Challenges_AcceptInvite will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
/// PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_AcceptInvite(ppfID challengeID);

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ppfMessage_Challenges_Delete will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
/// PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Delete(ppfID challengeID);

/// Gets the information for a single challenge
/// \param challengeID The id of the challenge whose entries to return.
///
/// A message with type ::ppfMessage_Challenges_Get will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Get(ppfID challengeID);

/// Requests a block of challenge entries.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit Defines the maximum number of entries to return.
/// \param filter Allows you to restrict the returned values by friends.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge.
///
/// A message with type ::ppfMessage_Challenges_GetEntries will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallengeEntryArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_GetEntries(ppfID challengeID, ppfLeaderboardFilterType filter, ppfLeaderboardStartAt startAt, int pageIdx, int pageSize);

/// Requests a block of challenge entries.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit The maximum number of entries to return.
/// \param afterRank The position after which to start.  For example, 10 returns challenge results starting with the 11th user.
///
/// A message with type ::ppfMessage_Challenges_GetEntriesAfterRank will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallengeEntryArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_GetEntriesAfterRank(ppfID challengeID, unsigned long long afterRank, int pageIdx, int pageSize);

/// Requests a block of challenge entries. Will return only entries matching
/// the user IDs passed in.
/// \param challengeID The id of the challenge whose entries to return.
/// \param limit Defines the maximum number of entries to return.
/// \param startAt Defines whether to center the query on the user or start at the top of the challenge. If this is ppfLeaderboard_StartAtCenteredOnViewer or ppfLeaderboard_StartAtCenteredOnViewerOrTop, then the current user's ID will be automatically added to the query.
/// \param userIDs Defines a list of user ids to get entries for.
/// \param userIDLength The number of user IDs provided.
///
/// A message with type ::ppfMessage_Challenges_GetEntriesByIds will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeEntryArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallengeEntryArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_GetEntriesByIds(ppfID challengeID, ppfLeaderboardStartAt startAt, const char** userIDs, unsigned int userIDLength, int pageIdx, int pageSize);

/// Requests for a list of challenge
///
/// A message with type ::ppfMessage_Challenges_GetList will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallengeArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_GetList(ppfChallengeOptionsHandle challengeOptions, int pageIdx, int pageSize);

/// If the current user has permission, join the challenge
///
/// A message with type ::ppfMessage_Challenges_Join will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Join(ppfID challengeID);

/// If the current user has permission, leave the challenge
///
/// A message with type ::ppfMessage_Challenges_Leave will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_Leave(ppfID challengeID);

/// DEPRECATED. Use server-to-server API call instead.
///
/// A message with type ::ppfMessage_Challenges_UpdateInfo will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfChallengeHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetChallenge().
/// PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_UpdateInfo(ppfID challengeID, ppfChallengeOptionsHandle challengeOptions);

/// @brief Launch the invitable user flow to invite to the challenge
/// @param challengeID The challenge to be invited.
/// @return The request ID of this async function.
///
/// This is intended to be a nice shortcut for developers not wanting to
/// build out their own Invite UI although it has the same rules as if you
/// build it yourself.
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Challenges_LaunchInvitableUserFlow(ppfID challengeID);

#endif