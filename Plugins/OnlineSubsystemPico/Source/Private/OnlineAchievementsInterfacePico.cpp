#include "OnlineAchievementsInterfacePico.h"

#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineMessageMultiTaskPico.h"
#include "OnlinePlatformInterfacePico.h"
#include "Interfaces/OnlineAchievementsInterface.h"


class FOnlineMessageMultiTaskPicoWriteAchievements : public FOnlineMessageMultiTaskPico, public TSharedFromThis<FOnlineMessageMultiTaskPicoWriteAchievements>
{
private:
	FUniqueNetIdPico PlayerID;
	FOnlineAchievementsWriteRef WriteObject;
	FOnAchievementsWrittenDelegate AchievementDelegate;

	// private to force the use of FOnlineMessageMultiTaskPicoWriteAchievements::Create()
	FOnlineMessageMultiTaskPicoWriteAchievements(FOnlineSubsystemPico& InPicoSubsystem, const FUniqueNetIdPico& InPlayerId, FOnlineAchievementsWriteRef& InWriteObject, const FOnAchievementsWrittenDelegate& InAchievementDelegate)
	: FOnlineMessageMultiTaskPico(InPicoSubsystem, FOnlineMessageMultiTaskPico::FFinalizeDelegate::CreateRaw(this, &FOnlineMessageMultiTaskPicoWriteAchievements::Finalize))
	, PlayerID(InPlayerId)
	, WriteObject(InWriteObject)
	, AchievementDelegate(InAchievementDelegate)
	{
		
	}

	static TSet< TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> > ActiveAchievementWriteTasks;

public:

	static TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> Create(
		FOnlineSubsystemPico& InPicoSubsystem,
		const FUniqueNetIdPico& InPlayerId,
		FOnlineAchievementsWriteRef& InWriteObject,
		const FOnAchievementsWrittenDelegate& InAchievementDelegate)
	{
		TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> NewTask = MakeShareable(new FOnlineMessageMultiTaskPicoWriteAchievements(InPicoSubsystem, InPlayerId, InWriteObject, InAchievementDelegate));
		ActiveAchievementWriteTasks.Add(NewTask);

		return NewTask;
	}

	void Finalize()
	{
		WriteObject->WriteState = (bDidAllRequestsFinishedSuccessfully) ? EOnlineAsyncTaskState::Done : EOnlineAsyncTaskState::Failed;
		AchievementDelegate.ExecuteIfBound(PlayerID, bDidAllRequestsFinishedSuccessfully);

		// this should delete this task object, make sure it happens last
		ActiveAchievementWriteTasks.Remove(AsShared());
	}

	static void ClearAllActiveTasks()
	{
		ActiveAchievementWriteTasks.Empty();
	}
};
TSet< TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> > FOnlineMessageMultiTaskPicoWriteAchievements::ActiveAchievementWriteTasks;

void FOnlineAchievementsPico::GetWriteAchievementCountValue(FVariantData VariantData, uint64& OutData) const
{
	switch (VariantData.GetType())
	{
	case EOnlineKeyValuePairDataType::Int32:
		{
			int32 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<uint64>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::Int64:
		{
			int64 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<uint64>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::UInt32:
		{
			uint32 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<uint64>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::UInt64:
		{
			VariantData.GetValue(OutData);
			break;
		}
	default:
		{
			UE_LOG_ONLINE_ACHIEVEMENTS(Warning, TEXT("Could not %s convert to uint64"), VariantData.GetTypeString());
			OutData = 0;
			break;
		}
	}
}

void FOnlineAchievementsPico::GetWriteAchievementBitfieldValue(FVariantData VariantData, FString& OutData,uint32 BitfieldLength) const
{
	switch (VariantData.GetType())
	{
	case EOnlineKeyValuePairDataType::Int32:
		{
			int32 Value;
			VariantData.GetValue(Value);
			auto UnpaddedBitfield = FString::FromInt(Value);
			int32 PaddingLength = BitfieldLength - UnpaddedBitfield.Len();
			OutData = TEXT("");
			if (PaddingLength>0)
			{	
				for (int32 i = 0; i < PaddingLength; ++i)
				{
					OutData.AppendChar('0');
				}
				OutData.Append(UnpaddedBitfield);
			}else
			{
				OutData = UnpaddedBitfield;
			}	
			break;
		}
	case EOnlineKeyValuePairDataType::String:
		{
			VariantData.GetValue(OutData);
			break;
		}
	default:
		{
			UE_LOG_ONLINE_ACHIEVEMENTS(Warning, TEXT("Could not %s convert to string"), VariantData.GetTypeString());
			break;
		}
	}
}

double FOnlineAchievementsPico::CalculatePlayerAchievementProgress(const FOnlineAchievementPico Achievement)
{
	if (Achievement.bIsUnlocked)
	{
		return 100.0;
	}

	auto Desc = AchievementDescriptions.Find(Achievement.Id);
	if (Desc == nullptr)
	{
		UE_LOG_ONLINE_ACHIEVEMENTS(Warning, TEXT("Could not calculate progress for Achievement: '%s'"), *Achievement.Id);
		return 0.0;
	}

	double Progress;
	switch (Desc->Type)
	{
	case EAchievementType::Count:
		{
			Progress = Achievement.Count * 100.0 / Desc->Target;
			break;
		}
	case EAchievementType::Bitfield:
		{
			int BitfieldCount = 0;
			UE_LOG(LogTemp,Log,TEXT("Achievement: %s,Bitfield:%s,BitfieldLength:%d"),*Achievement.Id,*Achievement.Bitfield,Achievement.Bitfield.Len());
			for (int32 i = 0; i < Achievement.Bitfield.Len(); ++i)
			{
				if (Achievement.Bitfield[i] == '1')
				{
					++BitfieldCount;
				}
			}
			UE_LOG(LogTemp,Log,TEXT("Achievement: %s,BitfieldCount:%d,Desc->Target:%llu"),*Achievement.Id,BitfieldCount,Desc->Target);
			Progress = BitfieldCount * 100.0 / Desc->Target;
			break;
		}
	default:
		{
			Progress = 0.0;
			break;
		}
	}

	// Cap the progress to 100
	return (Progress <= 100.0) ? Progress : 100.0;
}



FOnlineAchievementsPico::FOnlineAchievementsPico(FOnlineSubsystemPico& InSubsystem)
: PicoSubsystem(InSubsystem)
{
	
}

FOnlineAchievementsPico::~FOnlineAchievementsPico()
{
	FOnlineMessageMultiTaskPicoWriteAchievements::ClearAllActiveTasks();
}

void FOnlineAchievementsPico::WriteAchievements(const FUniqueNetId& PlayerId, FOnlineAchievementsWriteRef& WriteObject,
	const FOnAchievementsWrittenDelegate& Delegate)
{
#if !PLATFORM_ANDROID
	Delegate.ExecuteIfBound(PlayerId, false);
	return;
#endif
	if (AchievementDescriptions.Num() == 0)
	{
		// we don't have achievements
		WriteObject->WriteState = EOnlineAsyncTaskState::Failed;
		Delegate.ExecuteIfBound(PlayerId, false);
		return;
	}

	// Nothing to write
	if (WriteObject->Properties.Num() == 0)
	{
		WriteObject->WriteState = EOnlineAsyncTaskState::Done;
		Delegate.ExecuteIfBound(PlayerId, true);
		return;
	}
	
	WriteObject->WriteState = EOnlineAsyncTaskState::InProgress;
	TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> MultiTask = FOnlineMessageMultiTaskPicoWriteAchievements::Create(PicoSubsystem, static_cast<FUniqueNetIdPico>(PlayerId), WriteObject, Delegate);

	// treat each achievement as unlocked
	for (FStatPropertyArray::TConstIterator It(WriteObject->Properties); It; ++It)
	{
		const FString AchievementId = It.Key().ToString();
		auto VariantData = It.Value();
		auto AchievementDesc = AchievementDescriptions.Find(AchievementId);
		if (AchievementDesc == nullptr)
		{
			WriteObject->WriteState = EOnlineAsyncTaskState::Failed;
			Delegate.ExecuteIfBound(PlayerId, false);
			return;
		}

		UE_LOG_ONLINE_ACHIEVEMENTS(Verbose, TEXT("WriteObject AchievementId: '%s'"), *AchievementId);

		uint64 RequestId = 0;

		switch (AchievementDesc->Type)
		{
			case EAchievementType::Simple:
			{
				RequestId = OnlinePlatformInterfacePico::Achievement_Unlock(TCHAR_TO_ANSI(*AchievementId));
				break;
			}
			case EAchievementType::Count:
			{
				uint64 Count;
				GetWriteAchievementCountValue(VariantData, Count);
				RequestId = OnlinePlatformInterfacePico::Achievement_AddCount(TCHAR_TO_ANSI(*AchievementId), Count);
				break;
			}
			case EAchievementType::Bitfield:
			{
				FString Bitfield;
				GetWriteAchievementBitfieldValue(VariantData, Bitfield, AchievementDesc->BitfieldLength);
				RequestId = OnlinePlatformInterfacePico::Achievement_AddFields(TCHAR_TO_ANSI(*AchievementId), TCHAR_TO_ANSI(*Bitfield));
				break;
			}
			default:
			{
				UE_LOG_ONLINE_ACHIEVEMENTS(Warning, TEXT("Unknown achievement type"));
				break;
			}
		}

		if (RequestId != 0)
		{
			MultiTask->AddNewRequest(RequestId);
		}
	}
}

void FOnlineAchievementsPico::QueryAchievements(const FUniqueNetId& PlayerId,const FOnQueryAchievementsCompleteDelegate& Delegate)
{
#if !PLATFORM_ANDROID
	Delegate.ExecuteIfBound(PlayerId, false);
	return;
#endif
	auto PicoPlayerId = static_cast<FUniqueNetIdPico>(PlayerId);
	auto RequestID = OnlinePlatformInterfacePico::Achievement_GetAllProgress();
	if (RequestID <1000)
	{
		Delegate.ExecuteIfBound(PicoPlayerId, false);
	}
	else 
	{
		PicoSubsystem.AddRequestDelegate(RequestID, FPicoMessageOnCompleteDelegate::CreateLambda([this, PicoPlayerId, Delegate](FOnlineMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				Delegate.ExecuteIfBound(PicoPlayerId, false);
				return;
			}
			PlayerAchievements.Empty();
			// new array
			TArray<FOnlineAchievement> AchievementsForPlayer;
			// keep track of existing achievements
			TSet<FString> InProgressAchievements;
#if PLATFORM_ANDROID
			int32 AchievementProgressNum = OnlinePlatformInterfacePico::AchievementProgressArray_GetSize(Message.JavaMessage);
			for (int32 AchievementProgressIndex = 0; AchievementProgressIndex < AchievementProgressNum; ++AchievementProgressIndex)
			{
				auto AchievementProgress = OnlinePlatformInterfacePico::AchievementProgressArray_GetElement(Message.JavaMessage, AchievementProgressIndex);
				FOnlineAchievementPico NewAchievement;
				NewAchievement.Id = OnlinePlatformInterfacePico::AchievementProgress_GetName(AchievementProgress);
				NewAchievement.bIsUnlocked = OnlinePlatformInterfacePico::AchievementProgress_GetIsUnlocked(AchievementProgress);
				NewAchievement.Bitfield = OnlinePlatformInterfacePico::AchievementProgress_GetBitfield(AchievementProgress);
				NewAchievement.Count = OnlinePlatformInterfacePico::AchievementProgress_GetCount(AchievementProgress);
				
				NewAchievement.Progress = CalculatePlayerAchievementProgress(NewAchievement);
				UE_LOG(LogTemp,Log,TEXT("QueryAchievementsProgress ID:%s,bIsUnlocked:%d,Bitfield:%s,Count:%llu,Progress:%lf"),*NewAchievement.Id,NewAchievement.bIsUnlocked,*NewAchievement.Bitfield,NewAchievement.Count,NewAchievement.Progress);
				AchievementsForPlayer.Add(NewAchievement);
				InProgressAchievements.Add(NewAchievement.Id);
			}

			if (OnlinePlatformInterfacePico::AchievementProgressArray_HasNextPage(Message.JavaMessage))
			{
				PlayerAchievements.Add(PicoPlayerId, AchievementsForPlayer);
				UE_LOG(LogTemp,Log,TEXT("AchievementProgressArray_GetNextUrl "));
                auto NextUrl = OnlinePlatformInterfacePico::AchievementProgressArray_GetNextUrl(Message.JavaMessage);
				QueryAchievementsByNextUrl(PicoPlayerId,NextUrl,Delegate);
            }else
            {
            	for (auto const &it : AchievementDescriptions)
            	{
                    auto bFoundAchievement = InProgressAchievements.Find(it.Key);
                    if (bFoundAchievement == nullptr)
                    {
                        FOnlineAchievementPico NewAchievement(it.Value);
                        AchievementsForPlayer.Add(NewAchievement);
                    }
                }
            	PlayerAchievements.Add(PicoPlayerId, AchievementsForPlayer);
            	UE_LOG(LogTemp,Log,TEXT("QueryAchievements Finish Length :%d"),AchievementsForPlayer.Num());
	            Delegate.ExecuteIfBound(PicoPlayerId, true);
            }
#endif		
		}));
	}	
}

void FOnlineAchievementsPico::QueryAchievementsByNextUrl(const FUniqueNetId& PlayerId,FString InNextUrl,	const FOnQueryAchievementsCompleteDelegate& Delegate)
{
	auto PicoPlayerId = static_cast<FUniqueNetIdPico>(PlayerId);
	auto RequestID = OnlinePlatformInterfacePico::Achievements_GetAllProgressByUrl(InNextUrl);
	if (RequestID <1000)
	{
		Delegate.ExecuteIfBound(PicoPlayerId, false);
	}
	else 
	{
		PicoSubsystem.AddRequestDelegate(RequestID, FPicoMessageOnCompleteDelegate::CreateLambda([this, PicoPlayerId, Delegate](FOnlineMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				Delegate.ExecuteIfBound(PicoPlayerId, false);
				return;
			}
			// new array
			TArray<FOnlineAchievement> AchievementsForPlayer;
			// keep track of existing achievements
			TSet<FString> InProgressAchievements;
#if PLATFORM_ANDROID
			int32 AchievementProgressNum = OnlinePlatformInterfacePico::AchievementProgressArray_GetSize(Message.JavaMessage);
			for (int32 AchievementProgressIndex = 0; AchievementProgressIndex < AchievementProgressNum; ++AchievementProgressIndex)
			{
				auto AchievementProgress = OnlinePlatformInterfacePico::AchievementProgressArray_GetElement(Message.JavaMessage, AchievementProgressIndex);
				FOnlineAchievementPico NewAchievement;
				NewAchievement.Id = OnlinePlatformInterfacePico::AchievementProgress_GetName(AchievementProgress);
				NewAchievement.bIsUnlocked = OnlinePlatformInterfacePico::AchievementProgress_GetIsUnlocked(AchievementProgress);
				NewAchievement.Bitfield = OnlinePlatformInterfacePico::AchievementProgress_GetBitfield(AchievementProgress);
				NewAchievement.Count = OnlinePlatformInterfacePico::AchievementProgress_GetCount(AchievementProgress);
				NewAchievement.Progress = CalculatePlayerAchievementProgress(NewAchievement);
				UE_LOG(LogTemp,Log,TEXT("QueryAchievementsProgressByNextUrl ID:%s,bIsUnlocked:%d,Bitfield:%s,Count:%llu,Progress:%lf"),*NewAchievement.Id,NewAchievement.bIsUnlocked,*NewAchievement.Bitfield,NewAchievement.Count,NewAchievement.Progress);
				AchievementsForPlayer.Add(NewAchievement);
				InProgressAchievements.Add(NewAchievement.Id);
			}
			
			// should replace any already existing values
			TArray<FOnlineAchievement>* ExitAchievements = PlayerAchievements.Find(PicoPlayerId);
			for (int32 i = 0;i<AchievementsForPlayer.Num();i++)
			{
				ExitAchievements->Add(AchievementsForPlayer[i]);
			}
			if (OnlinePlatformInterfacePico::AchievementProgressArray_HasNextPage(Message.JavaMessage))
			{
				UE_LOG(LogTemp,Log,TEXT("AchievementProgressArray_GetNextUrl "));
                auto NextUrl = OnlinePlatformInterfacePico::AchievementProgressArray_GetNextUrl(Message.JavaMessage);
				QueryAchievementsByNextUrl(PicoPlayerId,NextUrl,Delegate);
              
            }else
            {
            	// if there are any achievements that the player has not made any progress toward,
	            // fill them out as empty achievements
            	TArray<FOnlineAchievement>* NowExitAchievements = PlayerAchievements.Find(PicoPlayerId);
            	TSet<FString> NowExitAchievementsName;
            	for (auto  Achievement : *NowExitAchievements)
            	{
            		NowExitAchievementsName.Add(Achievement.Id);
            	}
            		
	            for (auto const &it : AchievementDescriptions)
	            {
	                auto bFoundAchievement = NowExitAchievementsName.Find(it.Key);
	                if (bFoundAchievement == nullptr)
	                {
	                    UE_LOG(LogTemp,Log,TEXT("Add Empty Progress  %s"),*it.Key);
	                    FOnlineAchievementPico NewAchievement(it.Value);
	                    NowExitAchievements->Add(NewAchievement);
	                }
	            }
            	Delegate.ExecuteIfBound(PicoPlayerId, true);
            }
#endif		
		}));
	}	
}

void FOnlineAchievementsPico::QueryAchievementDescriptions(const FUniqueNetId& PlayerId,const FOnQueryAchievementsCompleteDelegate& Delegate)
{
#if !PLATFORM_ANDROID
	Delegate.ExecuteIfBound(PlayerId, false);
	return;
#endif
	auto PicoPlayerId = static_cast<FUniqueNetIdPico>(PlayerId);
	auto RequestID = OnlinePlatformInterfacePico::Achievement_GetAllDefinitions(PicoSubsystem.GetAppId());
	if (RequestID<1000)
	{
		Delegate.ExecuteIfBound(PicoPlayerId, false);
	}else
	{
		PicoSubsystem.AddRequestDelegate(RequestID, FPicoMessageOnCompleteDelegate::CreateLambda([this, PicoPlayerId, Delegate](FOnlineMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				Delegate.ExecuteIfBound(PicoPlayerId, false);
				return;
			}
			AchievementDescriptions.Empty();
#if PLATFORM_ANDROID
			int32 AchievementDefinitionNum = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetSize(Message.JavaMessage);
			for (int32 AchievementDefinitionIndex = 0; AchievementDefinitionIndex < AchievementDefinitionNum; ++AchievementDefinitionIndex)
			{
				auto AchievementDefinition = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetElement(Message.JavaMessage, AchievementDefinitionIndex);
				FOnlineAchievementDescPico NewAchievementDesc;
				FString Title(OnlinePlatformInterfacePico::AchievementDefinition_GetName(AchievementDefinition));
				FString LockedDesc(OnlinePlatformInterfacePico::AchievementDefinition_GetDescription(AchievementDefinition));
				FString UnLockedDesc(OnlinePlatformInterfacePico::AchievementDefinition_GetUnlockedDescription(AchievementDefinition));
				NewAchievementDesc.Title = FText::FromString(Title);
				NewAchievementDesc.LockedDesc = FText::FromString(LockedDesc);
				NewAchievementDesc.UnlockedDesc = FText::FromString(UnLockedDesc);
				NewAchievementDesc.bIsHidden = false;
				auto AchievementType = OnlinePlatformInterfacePico::AchievementDefinition_GetType(AchievementDefinition);
				NewAchievementDesc.Type = static_cast<EAchievementType>(AchievementType);
				NewAchievementDesc.Target = OnlinePlatformInterfacePico::AchievementDefinition_GetTarget(AchievementDefinition);
				NewAchievementDesc.BitfieldLength = OnlinePlatformInterfacePico::AchievementDefinition_GetBitfieldLength(AchievementDefinition);
				UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptions Title:%s , AchievementType :%d,Target:%llu,But:%lu"),*Title, NewAchievementDesc.Type, NewAchievementDesc.Target, NewAchievementDesc.BitfieldLength);
				AchievementDescriptions.Add(Title, NewAchievementDesc);
			}
			UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptions : Desc Length :%d"), AchievementDescriptions.Num());
			if (OnlinePlatformInterfacePico::AchievementDefinitionArray_HasNextPage(Message.JavaMessage))
			{
				auto NextUrl = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetNextUrl(Message.JavaMessage);
				QueryAchievementDescriptionsByNextUrl(PicoPlayerId,NextUrl,Delegate);
			}else
			{
				UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptionsFinish Length:%d"),AchievementDescriptions.Num());
				Delegate.ExecuteIfBound(PicoPlayerId, true);
			}
#endif	
		}));
	}
}


void FOnlineAchievementsPico::QueryAchievementDescriptionsByNextUrl(const FUniqueNetId& PlayerId,FString InNextUrl,
	const FOnQueryAchievementsCompleteDelegate& Delegate)
{
	auto PicoPlayerId = static_cast<FUniqueNetIdPico>(PlayerId);
	auto RequestID = OnlinePlatformInterfacePico::Achievements_GetAllDefinitionsByUrl(InNextUrl);
	if (RequestID<1000)
	{
		Delegate.ExecuteIfBound(PicoPlayerId, false);
	}else
	{
#if PLATFORM_ANDROID
		PicoSubsystem.AddRequestDelegate(RequestID, FPicoMessageOnCompleteDelegate::CreateLambda([this, PicoPlayerId, Delegate](FOnlineMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                Delegate.ExecuteIfBound(PicoPlayerId, false);
                return;
            }

            int32 AchievementDefinitionNum = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetSize(Message.JavaMessage);
            for (int32 AchievementDefinitionIndex = 0; AchievementDefinitionIndex < AchievementDefinitionNum; ++AchievementDefinitionIndex)
            {
                auto AchievementDefinition = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetElement(Message.JavaMessage, AchievementDefinitionIndex);
                FOnlineAchievementDescPico NewAchievementDesc;
            	FString Title(OnlinePlatformInterfacePico::AchievementDefinition_GetName(AchievementDefinition));
                FString LockedDesc(OnlinePlatformInterfacePico::AchievementDefinition_GetDescription(AchievementDefinition));
                FString UnLockedDesc(OnlinePlatformInterfacePico::AchievementDefinition_GetUnlockedDescription(AchievementDefinition));
                NewAchievementDesc.Title = FText::FromString(Title);
                NewAchievementDesc.LockedDesc = FText::FromString(LockedDesc);
                NewAchievementDesc.UnlockedDesc = FText::FromString(UnLockedDesc);
                NewAchievementDesc.bIsHidden = false;
                auto AchievementType = OnlinePlatformInterfacePico::AchievementDefinition_GetType(AchievementDefinition);
                NewAchievementDesc.Type = static_cast<EAchievementType>(AchievementType);
                NewAchievementDesc.Target = OnlinePlatformInterfacePico::AchievementDefinition_GetTarget(AchievementDefinition);
                NewAchievementDesc.BitfieldLength = OnlinePlatformInterfacePico::AchievementDefinition_GetBitfieldLength(AchievementDefinition);
                UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptionsByNextUrl Title:%s , AchievementType :%d,Target:%llu,But:%lu"),*Title, NewAchievementDesc.Type, NewAchievementDesc.Target, NewAchievementDesc.BitfieldLength);
                AchievementDescriptions.Add(Title, NewAchievementDesc);
            }

            if (OnlinePlatformInterfacePico::AchievementDefinitionArray_HasNextPage(Message.JavaMessage))
            {
            	UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptionsByNextUrl"));
                auto NextUrl = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetNextUrl(Message.JavaMessage);
                QueryAchievementDescriptionsByNextUrl(PicoPlayerId,NextUrl,Delegate);
            }else
            {
            	UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptionsFinish Length:%d"),AchievementDescriptions.Num());
                Delegate.ExecuteIfBound(PicoPlayerId, true);
            }	

        }));
#endif
	}
}


void FOnlineAchievementsPico::QueryAchievementDescriptionsByName(const FUniqueNetId& PlayerId,TArray<FString>AchievementIds, const FOnQueryAchievementsCompleteDelegate& Delegate)
{
#if !PLATFORM_ANDROID
	Delegate.ExecuteIfBound(PlayerId, false);
	return;
#endif
	auto PicoPlayerId = static_cast<FUniqueNetIdPico>(PlayerId);
	auto RequestID = OnlinePlatformInterfacePico::Achievement_GetDefinitionsByName(AchievementIds);
	if (RequestID<1000)
	{
		Delegate.ExecuteIfBound(PicoPlayerId, false);
	}else
	{
		PicoSubsystem.AddRequestDelegate(RequestID, FPicoMessageOnCompleteDelegate::CreateLambda([this, PicoPlayerId, Delegate](FOnlineMessageHandle Message, bool bIsError)
		{
			if (bIsError)
			{
				Delegate.ExecuteIfBound(PicoPlayerId, false);
				return;
			}
			AchievementDescriptions.Empty();
#if PLATFORM_ANDROID
			int32 AchievementDefinitionNum = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetSize(Message.JavaMessage);
			for (int32 AchievementDefinitionIndex = 0; AchievementDefinitionIndex < AchievementDefinitionNum; ++AchievementDefinitionIndex)
			{
				auto AchievementDefinition = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetElement(Message.JavaMessage, AchievementDefinitionIndex);
				FOnlineAchievementDescPico NewAchievementDesc;
				FString Title(OnlinePlatformInterfacePico::AchievementDefinition_GetName(AchievementDefinition));
				NewAchievementDesc.Title = FText::FromString(Title);
				NewAchievementDesc.bIsHidden = false;
				auto AchievementType = OnlinePlatformInterfacePico::AchievementDefinition_GetType(AchievementDefinition);
				NewAchievementDesc.Type = static_cast<EAchievementType>(AchievementType);
				NewAchievementDesc.Target = OnlinePlatformInterfacePico::AchievementDefinition_GetTarget(AchievementDefinition);
				NewAchievementDesc.BitfieldLength = OnlinePlatformInterfacePico::AchievementDefinition_GetBitfieldLength(AchievementDefinition);
				UE_LOG(LogTemp,Log,TEXT("QueryAchievementDescriptionsByName Title:%s , AchievementType :%d,Target:%llu,But:%lu"),*Title, NewAchievementDesc.Type, NewAchievementDesc.Target, NewAchievementDesc.BitfieldLength);
				AchievementDescriptions.Add(Title, NewAchievementDesc);
			}
			if (OnlinePlatformInterfacePico::AchievementDefinitionArray_HasNextPage(Message.JavaMessage))
			{
				auto NextUrl = OnlinePlatformInterfacePico::AchievementDefinitionArray_GetNextUrl(Message.JavaMessage);
				//TODO:Get next URL message
			}
#endif
			Delegate.ExecuteIfBound(PicoPlayerId, true);
		}));
	}
}

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievement(const FUniqueNetId& PlayerId,const FString& AchievementId, FOnlineAchievement& OutAchievement)
{
	if (AchievementDescriptions.Num() == 0)
	{
		return EOnlineCachedResult::NotFound;
	}
	auto PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	const TArray<FOnlineAchievement> * PlayerAch = PlayerAchievements.Find(PicoPlayerId);
	if (PlayerAch == nullptr)
	{
		return EOnlineCachedResult::NotFound;
	}

	const int32 AchNum = PlayerAch->Num();
	for (int32 AchIdx = 0; AchIdx < AchNum; ++AchIdx)
	{
		if ((*PlayerAch)[AchIdx].Id == AchievementId)
		{
			OutAchievement = (*PlayerAch)[AchIdx];
			return EOnlineCachedResult::Success;
		}
	}
	// no such achievement
	return EOnlineCachedResult::NotFound;
}

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievements(const FUniqueNetId& PlayerId,TArray<FOnlineAchievement>& OutAchievements)
{
	if (AchievementDescriptions.Num() == 0)
	{
		return EOnlineCachedResult::NotFound;
	}
	
	auto PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	const TArray<FOnlineAchievement> * PlayerAch = PlayerAchievements.Find(PicoPlayerId);
	
	if (PlayerAch == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("GetCacheAchievements PlayerAch  is null "));
		return EOnlineCachedResult::NotFound;
	}
	OutAchievements = *PlayerAch;
	return EOnlineCachedResult::Success;
}

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievementDescription(const FString& AchievementId,FOnlineAchievementDesc& OutAchievementDesc)
{
	if (AchievementDescriptions.Num() == 0)
	{
		// we don't have achievements
		return EOnlineCachedResult::NotFound;
	}

	FOnlineAchievementDesc * AchDesc = AchievementDescriptions.Find(AchievementId);
	if (AchDesc == nullptr)
	{
		// no such achievement
		return EOnlineCachedResult::NotFound;
	}
	
	OutAchievementDesc = *AchDesc;
	return EOnlineCachedResult::Success;
}


#if !UE_BUILD_SHIPPING
bool FOnlineAchievementsPico::ResetAchievements(const FUniqueNetId& PlayerId)
{
	// We cannot reset achievements from the client
	UE_LOG_ONLINE_ACHIEVEMENTS(Error, TEXT("Achievements cannot be reset here"));
	return false;
};
#endif // !UE_BUILD_SHIPPING