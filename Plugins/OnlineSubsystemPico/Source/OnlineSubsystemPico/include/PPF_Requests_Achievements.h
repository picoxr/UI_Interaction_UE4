#ifndef PPF_REQUESTS_ACHIEVEMENTS_H
#define PPF_REQUESTS_ACHIEVEMENTS_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_AchievementDefinitionArray.h"
#include "PPF_AchievementProgressArray.h"

/// \file
/// Achievements Overview
///
/// *** Achievement Objects:
///
/// The API exposes two object types related to achievements, achievement definition
/// objects and achievement progress objects.
///
/// Achievement Definitions:
/// Achievement definition objects define your game's achievements. They comprise an
/// internal name, an achievement type, and the target which much be reached to
/// unlock that achievement
///
/// Achievement Progress:
/// Achievement progress objects represent the progress that a player has made
/// toward an achievement. They comprise a name, whether or not the achievement is
/// unlocked, the time at which it was unlocked, an achievement type, and, depending
/// on the type, the progress made towards unlocking it.
///
///
/// *** Achievement Types:
///
/// Achievements come in three flavors: Simple achievements, count achievements, and
/// bitfield achievements.
///
/// Simple Achievements:
/// Simple achievements are either locked or unlocked, with no notion of progress.
/// Examples could include "Beat Level 3" or "Give Josh A Bad Performance Review
/// Because He Made Me Write This Boring Achievements Documentation". Call
/// ppf_Achievements_Unlock() to unlock a simple achievement.
///
/// Count Achievements:
/// Count achievements have an integer target and are unlocked when that target is
/// reached. Call ppf_AchievementDefinition_GetTarget() to get the target, and
/// ppf_Achievements_AddCount() to add progress towards the target of a bitfield
/// achievement. Examples could include "Collect 100 Coins" or "Avoid 5 Tedious
/// Meetings About Improving The Achievements API By Hiding In The Utility Closet"
///
/// Bitfield Achievements:
/// Bitfield achievement have a fixed number of fields which are either true or
/// false, and an integer target which represents the number of fields which must be
/// true for the achievement to be unlocked. This makes it possible to create N of M
/// achievements, such as "Visit 4 of the 7 Continents" or "Fix 3 of 10 Crash Bugs
/// In The Achievements API, But Leave The Rest In, Because Life Would be Boring
/// Without A Little Unpredictability". Call ppf_Achievements_AddFields() to unlock
/// the fields of a bitfield achievement

/// Add 'count' to the achievement with the given name. This must be a COUNT
/// achievement. The largest number that is supported by this method is the max
/// value of a signed 64-bit integer. If the number is larger than that, it is
/// clamped to that max value before being passed to the servers.
///
/// A message with type ::ppfMessage_Achievements_AddCount will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementUpdate().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_AddCount(const char *name, long long count, const void *extra_data, unsigned int extra_data_length);

/// Unlock fields of a BITFIELD achievement.
/// \param name The name of the achievement to unlock
/// \param fields A string containing either '0' or '1' characters. Every '1' will unlock the field in the corresponding position.
///
/// A message with type ::ppfMessage_Achievements_AddFields will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementUpdate().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_AddFields(const char *name, const char *fields, const void *extra_data, unsigned int extra_data_length);

/// Request all achievement definitions for the app.
///
/// A message with type ::ppfMessage_Achievements_GetAllDefinitions will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementDefinitionArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementDefinitionArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_GetAllDefinitions(int pageIdx, int pageSize);

/// Request the progress for the user on all achievements in the app.
///
/// A message with type ::ppfMessage_Achievements_GetAllProgress will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementProgressArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementProgressArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_GetAllProgress(int pageIdx, int pageSize);

/// Request the achievement definitions that match the specified names.
///
/// A message with type ::ppfMessage_Achievements_GetDefinitionsByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementDefinitionArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementDefinitionArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_GetDefinitionsByName(const char **names, int count);

/// Request the user's progress on the specified achievements.
///
/// A message with type ::ppfMessage_Achievements_GetProgressByName will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementProgressArrayHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementProgressArray().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_GetProgressByName(const char **names, int count);

/// Unlock the achievement with the given name. This can be of any achievement
/// type.
///
/// A message with type ::ppfMessage_Achievements_Unlock will be generated in response.
///
/// First call ::ppf_Message_IsError() to check if an error occurred.
///
/// If no error occurred, the message will contain a payload of type ::ppfAchievementUpdateHandle.
/// Extract the payload from the message handle with ::ppf_Message_GetAchievementUpdate().
PPF_PUBLIC_FUNCTION(ppfRequest) ppf_Achievements_Unlock(const char *name, const void *extra_data, unsigned int extra_data_length);

#endif
