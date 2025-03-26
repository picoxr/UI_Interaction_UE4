#ifndef PPF_REQUESTS_MATCHMAKING_H
#define PPF_REQUESTS_MATCHMAKING_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_MatchmakingOptions.h"
#include "PPF_MatchmakingStatApproach.h"
#include "PPF_KeyValuePairArray.h"
#include <stdbool.h>

/// @file PPF_Requests_Matchmaking.h
/// @ingroup Game

/// @brief Browse pool for joinable rooms
/// @param pool Name of the matchmaking pool(BROWSE type)
/// @param matchmakingOptions Browse options
/// @return The request ID of this async function.
/// 
/// Modes: BROWSE
///
/// Return a list of matchmaking rooms in the current pool filtered by skill.
/// When the user has made a selection, call ppf_Room_Join2() on one of
/// the rooms that was returned. If the user stops browsing, call
/// ppf_Matchmaking_Cancel2().
/// A message with type ::ppfMessageType_Matchmaking_Browse2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingBrowseResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingBrowseResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_Browse2(const char *pool, ppfMatchmakingOptionsHandle matchmakingOptions);

/// @brief Browse pool for joinable rooms
/// @param pool Name of the matchmaking pool(BROWSE type)
/// @param matchmakingOptions Browse options
/// @return The request ID of this async function.
/// 
/// Modes: BROWSE
///
/// Return a list of matchmaking rooms in the current pool filtered by skill.
/// When the user has made a selection, call ppf_Room_Join2() on one of
/// the rooms that was returned. If the user stops browsing, call
/// ppf_Matchmaking_Cancel2().
/// A message with type ::ppfMessageType_Matchmaking_Browse2CustomPage will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingBrowseCustomPageResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingBrowseCustomPageResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_Browse2CustomPage(const char *pool, ppfMatchmakingOptionsHandle matchmakingOptions, int pageIndex, int pageSize);

/// @brief Cancel previous matchmaking request
/// @return The request ID of this async function.
/// 
/// Modes: QUICKMATCH, BROWSE
///
/// Makes a best effort to cancel a previous Enqueue request before a match
/// occurs. Typically triggered when a user gives up waiting. If you don't cancel but
/// the user goes offline, the user/room will be timed out accord to dashboard setting 'reserve period'.
///
/// A message with type ::ppfMessageType_Matchmaking_Cancel2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_Cancel2();

/// @brief Create a matchmaking room, and enqueue it to pool
/// @param pool The matchmaking pool to use, which is defined in dashboard.
/// @param matchmakingOptions Additional matchmaking configuration for this request. Optional.
/// @return The request ID of this async function.
/// 
/// Modes: BROWSE, QUICKMATCH (Advanced; Can Users Create Rooms = true)
///
/// A message with type ::ppfMessageType_Matchmaking_CreateAndEnqueueRoom2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingEnqueueResultAndRoomHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingEnqueueResultAndRoom().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_CreateAndEnqueueRoom2(const char *pool, ppfMatchmakingOptionsHandle matchmakingOptions);

/// @brief Enqueue to await an available matchmaking room
/// @param pool The matchmaking pool to use, which is defined in dashboard.
/// @param matchmakingOptions Additional matchmaking configuration for this request. Optional.
/// @return The request ID of this async function.
///
/// Modes: QUICKMATCH
///
/// The platform will returns a ppfNotification_Matchmaking_MatchFound message when a match is
/// found. Call ppf_Room_Join2() on the returned room. 
///
/// If the user stops waiting, call ppf_Matchmaking_Cancel2().
///
/// A message with type ::ppfMessageType_Matchmaking_Enqueue2 will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingEnqueueResultHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingEnqueueResult().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_Enqueue2(const char *pool, ppfMatchmakingOptionsHandle matchmakingOptions);

/// @brief Used to debug the state of the current matchmaking pool queue, not intended to be used in production.
/// @return The request ID of this async function.
///
/// Modes: QUICKMATCH, BROWSE
///
/// A message with type ::ppfMessageType_Matchmaking_GetAdminSnapshot will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingAdminSnapshotHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingAdminSnapshot().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_GetAdminSnapshot();

/// @brief Gets the matchmaking stats for the current user
/// @param pool The pool to look in
/// @param maxLevel (beta feature, don't use it)
/// @param approach (beta feature, don't use it)
/// @return The request ID of this async function.
///
/// Modes: QUICKMATCH, BROWSE
///
/// Given a pool it will look up the current user's wins, loss, draws and skill
/// level. The skill level return will be between 1 and maxLevel. The approach
/// will dictate how should the skill level rise toward the max level.
///
/// A message with type ::ppfMessageType_Matchmaking_GetStats will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfMatchmakingStatsHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetMatchmakingStats().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_GetStats(const char* pool, unsigned int maxLevel, ppfMatchmakingStatApproach approach);

/// @brief Report the result of a rated skill match
/// @param roomID The room ID
/// @param data key value pairs
/// @param numItems The length of data
/// @return The request ID of this async function.
///
/// Modes: QUICKMATCH, BROWSE (+ Skill Pool)
///
/// Only for pools with skill-based matching. 
/// Call this after calling ppf_Matchmaking_StartMatch() to begin a rated skill
/// match and after the match finishes. The service will record the result and
/// update the skills of all players involved, based on the results. This
/// method is insecure because, as a client API, it is susceptible to tampering
/// and therefore cheating to manipulate skill ratings.
///
/// A message with type ::ppfMessageType_Matchmaking_ReportResultInsecure will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_ReportResultInsecure(ppfID roomID, ppfKeyValuePairArray data, unsigned int numItems);

/// @brief Report that a rated skill match started
/// @param roomID The room ID
/// @return The request ID of this async function.
///
/// Modes: QUICKMATCH, BROWSE (+ Skill Pool)
///
/// Only for pools with skill-based matching. 
/// Call after calling ppf_Room_Join2() when the players are present to begin a
/// rated match for which you plan to report the results (using ppf_Matchmaking_ReportResultInsecure()).
///
/// A message with type ::ppfMessageType_Matchmaking_StartMatch will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// This response has no payload. If no error occurred, the request was successful. Yay!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_StartMatch(ppfID roomID);

/// CRASH TEST !!!
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Matchmaking_CrashTest();


#endif
