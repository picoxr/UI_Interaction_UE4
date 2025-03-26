// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "Interfaces/OnlineAchievementsInterface.h"
#include "OnlineIdentityPico.h"
#include "OnlineSubsystemPicoPackage.h"

#define USE_PICO_ACHIEVEMENT_DESC FName(TEXT("USE_PICO_ACHIEVEMENT_DESC"))
#define USE_PICO_ACHIEVEMENT FName(TEXT("USE_PICO_ACHIEVEMNT"))
#define USE_PICO_ACHIEVEMENT_WRITE FName(TEXT("USE_PICO_ACHIEVEMENT_WRITE"))

/**
*	FOnlineAchievementDescPico - Interface class for accessing the pico achievement description information
*/
struct FOnlineAchievementDescPico : FOnlineAchievementDesc
{
    /** The way this achievement is unlocked */
    EAchievementType Type;

    /** The target to reach for unlocking a count achievement. */
    uint64 Target;

    /** The target to reach for unlocking a bitfield achievement. */
    uint32 BitfieldLength;

	/** The write policy of the achievement. */
    EAchievementWritePolicy WritePolicy;

	/** Whether the achievement is archieved. */
    bool IsArchived;

	/** Achievement name. */
    FString Name;

	/** The URL of the image displayed when the achievement is still locked. */
    FString LockedImageURL;

	/** The URL of the image displayed when the achievement is unlocked. */
    FString UnlockedImageURL;				

    FString ToDebugString() const
    {
        return FString::Printf( TEXT("Name=%s\nTitle=%s\nLockedDesc=%s\nUnlockedDesc=%s\nbIsHidden=%s\nType=%d\nTarget=%llu\nBitfieldLength=%u\nIsArchived: %s\nLockedImageURL: %s\nUnlockedImageURL: %s\nWritePolicy: %d\n"),
            *Name, *Title.ToString(),
            *LockedDesc.ToString(),
            *UnlockedDesc.ToString(),
            bIsHidden ? TEXT("true") : TEXT("false"),
            Type,
            Target,
            BitfieldLength,
            IsArchived ? TEXT("true") : TEXT("false"),
            *LockedImageURL,
            *UnlockedImageURL,
            WritePolicy
            );
    }

};

/**
*	FOnlineAchievementPico - Interface class for accessing the pico achievement information
*/
struct FOnlineAchievementPico : FOnlineAchievement
{
    /** The player's current progress toward a targeted numeric goal */
    long long Count;

    /** The player's current progress toward a set of goals that doesn't have to be completed in order */
    FString Bitfield;

    /** Whether or not this achievement was unlocked */
    bool bIsUnlocked;
    
    FOnlineAchievementPico(const ppfAchievementProgressHandle& AchievementProgress) //:
        // Count(ppf_AchievementProgress_GetCount(AchievementProgress)),
        // Bitfield(ppf_AchievementProgress_GetBitfield(AchievementProgress)),
        // bIsUnlocked(ppf_AchievementProgress_GetIsUnlocked(AchievementProgress))
    {
    	Count = ppf_AchievementProgress_GetCount(AchievementProgress);
    	Bitfield = ppf_AchievementProgress_GetBitfield(AchievementProgress);
    	bIsUnlocked = ppf_AchievementProgress_GetIsUnlocked(AchievementProgress);
    	
        FString AchievementName = UTF8_TO_TCHAR(ppf_AchievementProgress_GetName(AchievementProgress));
        UE_LOG_ONLINE_ACHIEVEMENTS(Display, TEXT("PPF_GAME FOnlineAchievementPico constructor ppf_AchievementProgress_GetName: %s, ppf_AchievementProgress_GetCount: %lld"), *AchievementName, ppf_AchievementProgress_GetCount(AchievementProgress));
        Id = AchievementName;
    }

    FOnlineAchievementPico(const FOnlineAchievementDescPico& AchievementDesc) :
        Count(0),
        bIsUnlocked(false)
    {
        UE_LOG_ONLINE_ACHIEVEMENTS(Display, TEXT("PPF_GAME FOnlineAchievementPico constructor by FOnlineAchievementDescPico AchievementDesc.Name: %s"), *AchievementDesc.Name);
        Id = AchievementDesc.Name;
        Progress = 0;
        if (AchievementDesc.Type == EAchievementType::Bitfield)
        {
            Bitfield = TEXT("");
            for (uint32 i = 0; i < AchievementDesc.BitfieldLength; ++i)
            {
                Bitfield.AppendChar('0');
            }
        }
    }
    FOnlineAchievementPico(const FOnlineAchievement& OnlineAchievementPico) :
        Count(0),
        bIsUnlocked(false)
    {
        UE_LOG_ONLINE_ACHIEVEMENTS(Display, TEXT("PPF_GAME FOnlineAchievementPico constructor by FOnlineAchievement Id: %s"), *OnlineAchievementPico.Id);
        Id = OnlineAchievementPico.Id;
        Progress =  OnlineAchievementPico.Progress;
    }
};


/**
*	IOnlineAchievements - Interface class for achievements
*/
class FOnlineAchievementsPico : public IOnlineAchievements
{
private:
	
	/** Reference to the owning subsystem */
	FOnlineSubsystemPico& PicoSubsystem;

	/** Mapping of players to their achievements */
	TMap<FUniqueNetIdPico, TArray<FOnlineAchievement>> PlayerAchievements;

	/** Cached achievements (not player-specific) */
	TMap<FString, FOnlineAchievementDescPico> AchievementDescriptions;

	void GetWriteAchievementCountValue(FVariantData VariantData, long long& OutData) const;
	void GetWriteAchievementBitfieldValue(FVariantData VariantData, FString& OutData, uint32 BitfieldLength) const;
	double CalculatePlayerAchievementProgress(const FOnlineAchievementPico Achievement);

	
	void SaveLog(const ELogVerbosity::Type Verbosity, const FString & Log) const;

	/** The maximum number of items that can be obtained in a single request */
	const int MAX_REQUEST_SIZE = 50;
	int GetAllProgressIndex = 0;
	int GetAllDefinitionIndex = 0;

public:

	/**
	* Constructor
	*
	* @param InSubsystem - A reference to the owning subsystem
	*/
	FOnlineAchievementsPico(FOnlineSubsystemPico& InSubsystem);

	/**
	* Default destructor
	*/
	virtual ~FOnlineAchievementsPico();

	// Begin IOnlineAchievements interface
	
	/// <summary> Refresh achievement progress data to the server, or unlock an achievement.
	/// If the achievement type is Simple, it will unlock an achievement.
	/// If the achievement type is Count, it will add the count of the achievement.
	/// If the achievement type is Bitfield, it will add the fields of the achievement.</summary>
	/// <param name="PlayerId"> The uid of the player we are writing achievements for. </param>
	/// <param name="WriteObject"> The stats holder containing the achievements we are writing. You can save data in its param: Properties. </param>
	/// <param name="Delegate"> The delegate to call when the write has completed or failed. </param>
	virtual void WriteAchievements(const FUniqueNetId& PlayerId, FOnlineAchievementsWriteRef& WriteObject, const FOnAchievementsWrittenDelegate& Delegate = FOnAchievementsWrittenDelegate()) override;
	
	/// <summary> Read achievement ids and progress from the server. You must use QueryAchievementDescriptions first to get more information about the achievements. </summary>
	/// <param name="PlayerId"> The id of the player we are reading achievements for. </param>
	/// <param name="Delegate"> The delegate to trigger when the query is complete. </param>
	virtual void QueryAchievements(const FUniqueNetId& PlayerId, const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate()) override;
	
	/// <summary> Read achievement descriptions from the server for displaying achievements in game. </summary>
	/// <param name="PlayerId"> The id of the player we are reading achievements for. </param>
	/// <param name="Delegate"> The delegate to trigger when the query is complete. </param>
	virtual void QueryAchievementDescriptions(const FUniqueNetId& PlayerId, const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate()) override;

	/// <summary> Get cached achievement data. </summary>
	/// <param name="PlayerId"> The uid of the player we are searching achievements for. </param>
	/// <param name="AchievementId"> The name of the achievement.</param>
	/// <param name="OutAchievement"> The progress data of the achievement. </param>
	/// <returns>Bool: 
	/// <ul>
	/// <li>`Success`: There is an achievement you want to query in the cache</li>
	/// <li>`NotFound`: The achievement you want cannot be found in the cache</li>
	/// </ul>
	/// </returns>
	virtual EOnlineCachedResult::Type GetCachedAchievement(const FUniqueNetId& PlayerId, const FString& AchievementId, FOnlineAchievement& OutAchievement) override;

	/// <summary> Get cached achievements data. </summary>
	/// <param name="PlayerId"> The uid of the player we are searching achievements for. </param>
	/// <param name="OutAchievements"> The progress data of the achievements. </param>
	/// <returns> EOnlineCachedResult::Type: 
	/// <ul>
	/// <li>`Success`: Find success. </li>
	/// <li>`NotFound`: Find failed. </li>
	/// </ul>
	/// </returns>
	virtual EOnlineCachedResult::Type GetCachedAchievements(const FUniqueNetId& PlayerId, TArray<FOnlineAchievement> & OutAchievements) override;

	/// <summary> The lookup achievement data was found in the cache. </summary>
	/// <param name="AchievementId"> The name of the achievement to look for. </param>
	/// <param name="OutAchievementDesc"> The achievement description data.</param>
	/// <returns> EOnlineCachedResult::Type: 
	/// <ul>
	/// <li>`Success`: There is an achievement you want to query in the cache</li>
	/// <li>`NotFound`: The achievement you want cannot be found in the cache</li>
	/// </ul>
	/// </returns>
	virtual EOnlineCachedResult::Type GetCachedAchievementDescription(const FString& AchievementId, FOnlineAchievementDesc& OutAchievementDesc) override;
#if !UE_BUILD_SHIPPING
	virtual bool ResetAchievements(const FUniqueNetId& PlayerId) override;
#endif // !UE_BUILD_SHIPPING
	// End IOnlineAchievements interface
};
