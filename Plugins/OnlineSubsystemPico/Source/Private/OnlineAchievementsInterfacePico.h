#pragma once
#include "OnlineMessageType.h"
#include "OnlineSubsystemPico.h"
#include "OnlineUniqueNetIdPico.h"
#include "Interfaces/OnlineAchievementsInterface.h"



struct FOnlineAchievementPico : FOnlineAchievement
{
	FOnlineAchievementPico()
	: Count(0)
	, Bitfield("")
	, bIsUnlocked(false)
	{

	}
	FOnlineAchievementPico(const OnlineAchievementProgressMessage& AchievementProgress)
	:Count(AchievementProgress.Count)
	,Bitfield(AchievementProgress.Bitfield)
	,bIsUnlocked(AchievementProgress.bIsUnlocked)
	{
		const FString AchievementName(AchievementProgress.Name);
		Id = AchievementName;
	}

	FOnlineAchievementPico(const FOnlineAchievementDescPico& AchievementDesc) :
        Count(0),
        bIsUnlocked(false)
	{
		Id = AchievementDesc.Title.ToString();
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

	/** The player's current progress toward a targeted numeric goal */
	uint64 Count;

	/** The player's current progress toward a set of goals that doesn't have to be completed in order */
	FString Bitfield;

	/** Whether or not this achievement was unlocked */
	bool bIsUnlocked;

};
class FOnlineAchievementsPico : public IOnlineAchievements
{
private:
	
	/** Reference to the owning subsystem */
	FOnlineSubsystemPico& PicoSubsystem;

	/** Mapping of players to their achievements */
	TMap<FUniqueNetIdPico, TArray<FOnlineAchievement>> PlayerAchievements;

	/** Cached achievements (not player-specific) */
	TMap<FString, FOnlineAchievementDescPico> AchievementDescriptions;

	void GetWriteAchievementCountValue(FVariantData VariantData, uint64& OutData) const;
	void GetWriteAchievementBitfieldValue(FVariantData VariantData, FString& OutData, uint32 BitfieldLength) const;
	double CalculatePlayerAchievementProgress(const FOnlineAchievementPico Achievement);

	void QueryAchievementsByNextUrl(const FUniqueNetId& PlayerId,FString NextUrl ,const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate());
	void QueryAchievementDescriptionsByNextUrl(const FUniqueNetId& PlayerId,FString NextUrl , const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate());
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
	virtual void WriteAchievements(const FUniqueNetId& PlayerId, FOnlineAchievementsWriteRef& WriteObject, const FOnAchievementsWrittenDelegate& Delegate = FOnAchievementsWrittenDelegate()) override;
	virtual void QueryAchievements(const FUniqueNetId& PlayerId, const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate()) override;
	virtual void QueryAchievementDescriptions(const FUniqueNetId& PlayerId, const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate()) override;
	void QueryAchievementDescriptionsByName(const FUniqueNetId& PlayerId,TArray<FString>AchievementIds, const FOnQueryAchievementsCompleteDelegate& Delegate = FOnQueryAchievementsCompleteDelegate());
	virtual EOnlineCachedResult::Type GetCachedAchievement(const FUniqueNetId& PlayerId, const FString& AchievementId, FOnlineAchievement& OutAchievement) override;
	virtual EOnlineCachedResult::Type GetCachedAchievements(const FUniqueNetId& PlayerId, TArray<FOnlineAchievement> & OutAchievements) override;
	virtual EOnlineCachedResult::Type GetCachedAchievementDescription(const FString& AchievementId, FOnlineAchievementDesc& OutAchievementDesc) override;
#if !UE_BUILD_SHIPPING
	virtual bool ResetAchievements(const FUniqueNetId& PlayerId) override;
#endif // !UE_BUILD_SHIPPING
	// End IOnlineAchievements interface
};
