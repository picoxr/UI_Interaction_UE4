// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlineAchievementsInterfacePico.h"

//#include "DetailLayoutBuilder.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineIdentityPico.h"
#include "OnlineMessageMultiTaskPico.h"
#include "OnlineSubsystemPicoPackage.h"
#include "Templates/SharedPointer.h"
#include "Misc/FileHelper.h"

class FOnlineMessageMultiTaskPicoWriteAchievements : public FOnlineMessageMultiTaskPico,
                                                     public TSharedFromThis<
	                                                     FOnlineMessageMultiTaskPicoWriteAchievements>
{
private:
	FUniqueNetIdPico PlayerId;
	FOnlineAchievementsWriteRef WriteObject;
	FOnAchievementsWrittenDelegate AchievementDelegate;

	// private to force the use of FOnlineMessageMultiTaskPicoWriteAchievements::Create()
	FOnlineMessageMultiTaskPicoWriteAchievements(FOnlineSubsystemPico& InPicoSubsystem,
	                                             const FUniqueNetIdPico& InPlayerId,
	                                             FOnlineAchievementsWriteRef& InWriteObject,
	                                             const FOnAchievementsWrittenDelegate& InAchievementDelegate)
		: FOnlineMessageMultiTaskPico(InPicoSubsystem,
		                              FOnlineMessageMultiTaskPico::FFinalizeDelegate::CreateRaw(
			                              this, &FOnlineMessageMultiTaskPicoWriteAchievements::Finalize))
		  , PlayerId(InPlayerId)
		  , WriteObject(InWriteObject)
		  , AchievementDelegate(InAchievementDelegate)
	{
	}

	static TSet<TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements>> ActiveAchievementWriteTasks;

PACKAGE_SCOPE:
	static TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> Create(
		FOnlineSubsystemPico& InPicoSubsystem,
		const FUniqueNetIdPico& InPlayerId,
		FOnlineAchievementsWriteRef& InWriteObject,
		const FOnAchievementsWrittenDelegate& InAchievementDelegate)
	{
		TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> NewTask = MakeShareable(
			new FOnlineMessageMultiTaskPicoWriteAchievements(InPicoSubsystem, InPlayerId, InWriteObject,
			                                                 InAchievementDelegate));
		ActiveAchievementWriteTasks.Add(NewTask);

		return NewTask;
	}

	void Finalize()
	{
		WriteObject->WriteState = (bDidAllRequestsFinishedSuccessfully)
			                          ? EOnlineAsyncTaskState::Done
			                          : EOnlineAsyncTaskState::Failed;
		AchievementDelegate.ExecuteIfBound(PlayerId, true);

		// this should delete this task object, make sure it happens last
		ActiveAchievementWriteTasks.Remove(AsShared());
	}

	static void ClearAllActiveTasks()
	{
		ActiveAchievementWriteTasks.Empty();
	}
};

TSet<TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements>>
FOnlineMessageMultiTaskPicoWriteAchievements::ActiveAchievementWriteTasks;

FOnlineAchievementsPico::FOnlineAchievementsPico(class FOnlineSubsystemPico& InSubsystem)
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
	if (AchievementDescriptions.Num() == 0)
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements AchievementDescriptions.Num() is 0")));
		// we don't have achievements
		WriteObject->WriteState = EOnlineAsyncTaskState::Failed;
		Delegate.ExecuteIfBound(PlayerId, false);
		return;
	}

	auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
	if (!(LoggedInPlayerId.IsValid() && PlayerId == *LoggedInPlayerId))
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements Can only write achievements for logged in player id")));
		WriteObject->WriteState = EOnlineAsyncTaskState::Failed;
		Delegate.ExecuteIfBound(PlayerId, false);
		return;
	}

	// Nothing to write
	if (WriteObject->Properties.Num() == 0)
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject->Properties.Num() is 0")));
		WriteObject->WriteState = EOnlineAsyncTaskState::Done;
		Delegate.ExecuteIfBound(PlayerId, true);
		return;
	}
	WriteObject->WriteState = EOnlineAsyncTaskState::InProgress;
	TSharedRef<FOnlineMessageMultiTaskPicoWriteAchievements> MultiTask =
		FOnlineMessageMultiTaskPicoWriteAchievements::Create(PicoSubsystem, static_cast<const FUniqueNetIdPico&>(PlayerId),
															 WriteObject, Delegate);
	if (WriteObject->FindStatByName(USE_PICO_ACHIEVEMENT_WRITE) != nullptr)
	{
		FOnlineAchievementsWritePico* PicoWriteObject = static_cast<FOnlineAchievementsWritePico*>(&WriteObject.Get());
		SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("WriteAchievements PicoWriteObject->PicoProperties.Num(): %d"), PicoWriteObject->Properties.Num()));
		// treat each achievement as unlocked
		for (auto It = PicoWriteObject->PicoProperties.CreateConstIterator(); It; ++It)
		{
			const FString AchievementId = It.Key();
			// SaveLog(ELogVerbosity::Type::Display, FString::Printf(TEXT("WriteAchievements PicoWriteObject AchievementId: %s"), *AchievementId));
			auto VariantData = It.Value();
			auto AchievementDesc = AchievementDescriptions.Find(AchievementId);
			if (AchievementDesc == nullptr || !AchievementId.Equals(AchievementDesc->Name))
			{
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements cannot find AchievementDesc")));
				PicoWriteObject->WriteState = EOnlineAsyncTaskState::Failed;
				Delegate.ExecuteIfBound(PlayerId, false);
				return;
			}
			ppfRequest RequestId = 0;
			switch (AchievementDesc->Type)
			{
			case EAchievementType::Simple:
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements PicoWriteObject ppf_Achievements_Unlock AchievementId: %s"), *AchievementId));
					RequestId = ppf_Achievements_Unlock(TCHAR_TO_ANSI(*AchievementId), nullptr, 0);
					break;
				}
			case EAchievementType::Count:
				{
					long long Count;
					GetWriteAchievementCountValue(VariantData, Count);
					RequestId = ppf_Achievements_AddCount(TCHAR_TO_ANSI(*AchievementId), Count, nullptr, 0);
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements PicoWriteObject AchievementId: %s, AddCount: %lld"), *AchievementId, Count));
					break;
				}
			case EAchievementType::Bitfield:
				{
					FString Bitfield;
					GetWriteAchievementBitfieldValue(VariantData, Bitfield, AchievementDesc->BitfieldLength);
					RequestId = ppf_Achievements_AddFields(
						TCHAR_TO_ANSI(*AchievementId), TCHAR_TO_ANSI(*Bitfield), nullptr, 0);
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements PicoWriteObject AchievementId: %s, AddFields Bitfield: %s"), *AchievementId, *Bitfield));
					break;
				}
			default:
				{
					SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("WriteAchievements PicoWriteObject Unknown achievement type")));
					break;
				}
			}

			if (RequestId != 0)
			{
				MultiTask->AddNewRequest(RequestId);
			}
		}
	}
	else
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject->Properties.Num(): %d"), WriteObject->Properties.Num()));
		// treat each achievement as unlocked
		for (FStatPropertyArray::TConstIterator It(WriteObject->Properties); It; ++It)
		{
			const FString AchievementId = It.Key().ToString();
			// SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject AchievementId: %s"), *AchievementId));
			auto VariantData = It.Value();
			auto AchievementDesc = AchievementDescriptions.Find(AchievementId);
			if (AchievementDesc == nullptr || !AchievementId.Equals(AchievementDesc->Name))
			{
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject cannot find AchievementDesc")));
				WriteObject->WriteState = EOnlineAsyncTaskState::Failed;
				Delegate.ExecuteIfBound(PlayerId, false);
				return;
			}
			ppfRequest RequestId = 0;
			switch (AchievementDesc->Type)
			{
			case EAchievementType::Simple:
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject ppf_Achievements_Unlock AchievementId: %s"), *AchievementId));
					RequestId = ppf_Achievements_Unlock(TCHAR_TO_ANSI(*AchievementId), nullptr, 0);
					break;
				}
			case EAchievementType::Count:
				{
					long long Count;
					GetWriteAchievementCountValue(VariantData, Count);
					RequestId = ppf_Achievements_AddCount(TCHAR_TO_ANSI(*AchievementId), Count, nullptr, 0);
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject AchievementId: %s, AddCount: %lld"), *AchievementId, Count));
					break;
				}
			case EAchievementType::Bitfield:
				{
					FString Bitfield;
					GetWriteAchievementBitfieldValue(VariantData, Bitfield, AchievementDesc->BitfieldLength);
					RequestId = ppf_Achievements_AddFields(
						TCHAR_TO_ANSI(*AchievementId), TCHAR_TO_ANSI(*Bitfield), nullptr, 0);
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("WriteAchievements WriteObject AchievementId: %s, AddFields Bitfield: %s"), *AchievementId, *Bitfield));
					break;
				}
			default:
				{
					SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("WriteAchievements WriteObject Unknown achievement type")));
					break;
				}
			}

			if (RequestId != 0)
			{
				MultiTask->AddNewRequest(RequestId);
			}
		}
	}
};

void FOnlineAchievementsPico::QueryAchievements(const FUniqueNetId& PlayerId,
                                                const FOnQueryAchievementsCompleteDelegate& Delegate)
{
	auto LoggedInPlayerId = PicoSubsystem.GetIdentityInterface()->GetUniquePlayerId(0);
	if (!(LoggedInPlayerId.IsValid() && PlayerId == *LoggedInPlayerId))
	{
		GetAllProgressIndex = 0;
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements Can only query for logged in player id")));
		Delegate.ExecuteIfBound(PlayerId, false);
		return;
	}

	const FUniqueNetIdPico& PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements GetAllProgressIndex: %d, MAX_REQUEST_SIZE: %d, ppf_Achievements_GetAllProgress PicoPlayerId: %s"), GetAllProgressIndex, MAX_REQUEST_SIZE, *PicoPlayerId.ToString()));

	if (GetAllProgressIndex == 0)
	{
		PlayerAchievements.Remove(PicoPlayerId);
	}
	PicoSubsystem.AddAsyncTask(
		ppf_Achievements_GetAllProgress(GetAllProgressIndex, MAX_REQUEST_SIZE),
		FPicoMessageOnCompleteDelegate::CreateLambda(
			[this, PicoPlayerId, Delegate](ppfMessageHandle Message, bool bIsError)
			{
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements ppf_Achievements_GetAllProgress OnComplete")));
				if (bIsError)
				{
					GetAllProgressIndex = 0;
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements ppf_Achievements_GetAllProgress is error")));
					Delegate.ExecuteIfBound(PicoPlayerId, false);
					return;
				}

				auto AchievementProgressArray = ppf_Message_GetAchievementProgressArray(Message);
				const size_t AchievementProgressNum = ppf_AchievementProgressArray_GetSize(AchievementProgressArray);
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements ppf_AchievementProgressArray_GetSize: %zu"), AchievementProgressNum));
				// new array
				TArray<FOnlineAchievement> AchievementsForPlayer;

				// keep track of existing achievements
				TSet<FString> InProgressAchievements;
				for (size_t AchievementProgressIndex = 0; AchievementProgressIndex < AchievementProgressNum; ++AchievementProgressIndex)
				{
					auto AchievementProgress = ppf_AchievementProgressArray_GetElement(AchievementProgressArray, AchievementProgressIndex);
					FOnlineAchievementPico NewAchievement(AchievementProgress);
					NewAchievement.Progress = CalculatePlayerAchievementProgress(NewAchievement);
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements NewAchievement.Id: %s, NewAchievement.Progress: %f, Count: %lld"), *NewAchievement.Id, NewAchievement.Progress, NewAchievement.Count));

					FOnlineAchievementDescPico* AchDesc = AchievementDescriptions.Find(NewAchievement.Id);
					if (AchDesc != nullptr && AchDesc->Name.Equals(NewAchievement.Id))
					{
						AchDesc->UnlockTime = FDateTime::FromUnixTimestamp(ppf_AchievementProgress_GetUnlockTime(AchievementProgress));

						int year = AchDesc->UnlockTime.GetYear();
						int month = AchDesc->UnlockTime.GetMonth();
						int day = AchDesc->UnlockTime.GetDay();
						int hour = AchDesc->UnlockTime.GetHour();
						int minute = AchDesc->UnlockTime.GetMinute();
						int second = AchDesc->UnlockTime.GetSecond();
						SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements ppf_AchievementProgress_GetUnlockTime(AchievementProgress): %llu [%d.%d.%d %d:%d:%d]"), ppf_AchievementProgress_GetUnlockTime(AchievementProgress), year, month, day, hour, minute, second));
					}

					AchievementsForPlayer.Add(NewAchievement);
					InProgressAchievements.Add(NewAchievement.Id);
				}

				// if there are any achievements that the player has not made any progress toward,
				// fill them out as empty achievements
				for (auto const& it : AchievementDescriptions)
				{
					auto bFoundAchievement = InProgressAchievements.Find(it.Key);
					if (bFoundAchievement == nullptr || !bFoundAchievement->Equals(it.Key))
					{
						FOnlineAchievementPico NewAchievement(it.Value);
						AchievementsForPlayer.Add(NewAchievement);
					}
				}

				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements PlayerAchievements add: PicoPlayerId: %s"), *PicoPlayerId.ToString()));
				// should replace any already existing values
				if (PlayerAchievements.Contains(PicoPlayerId))
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements PlayerAchievements Contains PicoPlayerId")));
					PlayerAchievements[PicoPlayerId].Append(AchievementsForPlayer);
				}
				else
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements PlayerAchievements not Contains PicoPlayerId")));
					PlayerAchievements.Add(PicoPlayerId, AchievementsForPlayer);
				}

				GetAllProgressIndex++;
				size_t TotalSize = ppf_AchievementProgressArray_GetTotalSize(AchievementProgressArray);
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements TotalSize: %zu"), TotalSize));
				if (GetAllProgressIndex * MAX_REQUEST_SIZE >= TotalSize)
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements GetAllProgressIndex * MAX_REQUEST_SIZE >= TotalSize stop query")));
					GetAllProgressIndex = 0;
					Delegate.ExecuteIfBound(PicoPlayerId, true);
				}
				else
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievements GetAllProgressIndex: %d"), GetAllProgressIndex));
					QueryAchievements(PicoPlayerId, Delegate);
				}
			}));
}

void FOnlineAchievementsPico::QueryAchievementDescriptions(const FUniqueNetId& PlayerId,
                                                           const FOnQueryAchievementsCompleteDelegate& Delegate)
{
	const FUniqueNetIdPico& PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions ppf_Achievements_GetAllDefinitions GetAllDefinitionIndex: %d, MAX_REQUEST_SIZE: %d,  PicoPlayerId: %s"), GetAllDefinitionIndex, MAX_REQUEST_SIZE, *PicoPlayerId.ToString()));
	PicoSubsystem.AddAsyncTask(
		ppf_Achievements_GetAllDefinitions(GetAllDefinitionIndex, MAX_REQUEST_SIZE),
		FPicoMessageOnCompleteDelegate::CreateLambda(
			[this, PicoPlayerId, Delegate](ppfMessageHandle Message, bool bIsError)
			{
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions ppf_Achievements_GetAllDefinitions OnComplete")));
				if (bIsError)
				{
					GetAllDefinitionIndex = 0;
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions error")));
					Delegate.ExecuteIfBound(PicoPlayerId, false);
					return;
				}

				const auto AchievementDefinitionArray = ppf_Message_GetAchievementDefinitionArray(Message);
				const size_t AchievementDefinitionNum = ppf_AchievementDefinitionArray_GetSize(AchievementDefinitionArray);
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions AchievementDefinitionNum: %zu"), AchievementDefinitionNum));
				for (size_t AchievementDefinitionIndex = 0; AchievementDefinitionIndex < AchievementDefinitionNum; ++AchievementDefinitionIndex)
				{
					const auto AchievementDefinition = ppf_AchievementDefinitionArray_GetElement(AchievementDefinitionArray, AchievementDefinitionIndex);
					FOnlineAchievementDescPico NewAchievementDesc;
					FString Title(UTF8_TO_TCHAR(ppf_AchievementDefinition_GetTitle(AchievementDefinition)));
					NewAchievementDesc.Title = FText::FromString(Title);
					auto AchievementType = ppf_AchievementDefinition_GetType(AchievementDefinition);
					NewAchievementDesc.Type = static_cast<EAchievementType>(AchievementType);
					NewAchievementDesc.Target = ppf_AchievementDefinition_GetTarget(AchievementDefinition);
					NewAchievementDesc.BitfieldLength = ppf_AchievementDefinition_GetBitfieldLength(AchievementDefinition);
					NewAchievementDesc.WritePolicy = static_cast<EAchievementWritePolicy>(ppf_AchievementDefinition_GetWritePolicy(AchievementDefinition));
					// FString Name(UTF8_TO_TCHAR(ppf_AchievementDefinition_GetName(AchievementDefinition)));
					NewAchievementDesc.Name = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetName(AchievementDefinition));
					NewAchievementDesc.IsArchived = ppf_AchievementDefinition_IsArchived(AchievementDefinition);
					NewAchievementDesc.bIsHidden = ppf_AchievementDefinition_IsSecret(AchievementDefinition);
					NewAchievementDesc.LockedDesc = FText::FromString(UTF8_TO_TCHAR(ppf_AchievementDefinition_GetDescription(AchievementDefinition)));
					NewAchievementDesc.UnlockedDesc = FText::FromString(UTF8_TO_TCHAR(ppf_AchievementDefinition_GetUnlockedDescription(AchievementDefinition)));
					NewAchievementDesc.LockedImageURL = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetLockedImageURL(AchievementDefinition));
					NewAchievementDesc.UnlockedImageURL = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetUnlockedImageURL(AchievementDefinition));
					
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions AchievementDescriptions add Name: %s, DebugString: %s")
						, *NewAchievementDesc.Name, *NewAchievementDesc.ToDebugString()));
					AchievementDescriptions.Add(NewAchievementDesc.Name, NewAchievementDesc);
				}
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions AchievementDescriptions.Num(): %d"), AchievementDescriptions.Num()));

				GetAllDefinitionIndex++;
				size_t TotalSize = ppf_AchievementDefinitionArray_GetTotalSize(AchievementDefinitionArray);
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions TotalSize: %zu"), TotalSize));
				if (GetAllDefinitionIndex * MAX_REQUEST_SIZE >= TotalSize)
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions GetAllDefinitionIndex * MAX_REQUEST_SIZE >= TotalSize stop query")));
					GetAllDefinitionIndex = 0;
					Delegate.ExecuteIfBound(PicoPlayerId, true);
				}
				else
				{
					SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("QueryAchievementDescriptions GetAllDefinitionIndex: %d"), GetAllDefinitionIndex));
					QueryAchievementDescriptions(PicoPlayerId, Delegate);
				}
			}));
}

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievement(const FUniqueNetId& PlayerId,
                                                                        const FString& AchievementId,
                                                                        FOnlineAchievement& OutAchievement)
{
	if (AchievementDescriptions.Num() == 0)
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("GetCachedAchievement AchievementDescriptions.Num() is 0")));
		return EOnlineCachedResult::NotFound;
	}

	const FUniqueNetIdPico& PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	const TArray<FOnlineAchievement>* PlayerAch = PlayerAchievements.Find(PicoPlayerId);
	if (PlayerAch == nullptr)
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("GetCachedAchievement achievements haven't been read for a player")));
		// achievements haven't been read for a player
		return EOnlineCachedResult::NotFound;
	}

	const int32 AchNum = PlayerAch->Num();
	for (int32 AchIdx = 0; AchIdx < AchNum; ++AchIdx)
	{
		if ((*PlayerAch)[AchIdx].Id.Equals(AchievementId))
		{
			// if (OutAchievement.Id.Equals(USE_PICO_ACHIEVEMENT.ToString()))
			// {
			// 	FOnlineAchievementPico& temp = static_cast<FOnlineAchievementPico&>(OutAchievement);
			// 	temp = (*PlayerAch)[AchIdx];
			// }
			// else
			{
				SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("GetCachedAchievement find set OutAchievement Id: %s, AchievementId: %s, Progress: %f"), *((*PlayerAch)[AchIdx].Id), *AchievementId, (*PlayerAch)[AchIdx].Progress));
				OutAchievement.Id = (*PlayerAch)[AchIdx].Id;
				OutAchievement.Progress = (*PlayerAch)[AchIdx].Progress;
			}
			return EOnlineCachedResult::Success;
		}
	}
	
	SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("GetCachedAchievement no such achievement")));
	return EOnlineCachedResult::NotFound;
};

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievements(
	const FUniqueNetId& PlayerId, TArray<FOnlineAchievement>& OutAchievements)
{
	if (AchievementDescriptions.Num() == 0)
	{
		// we don't have achievements
		return EOnlineCachedResult::NotFound;
	}

	const FUniqueNetIdPico& PicoPlayerId = static_cast<const FUniqueNetIdPico&>(PlayerId);
	const TArray<FOnlineAchievement>* PlayerAch = PlayerAchievements.Find(PicoPlayerId);
	if (PlayerAch == nullptr)
	{
		// achievements haven't been read for a player
		return EOnlineCachedResult::NotFound;
	}
	// for (int32 AchIdx = 0; AchIdx < PlayerAch->Num(); ++AchIdx)
	// {
	// 	FOnlineAchievement Achievement;
	// 	Achievement.Id = (*PlayerAch)[AchIdx].Id;
	// 	Achievement.Progress = (*PlayerAch)[AchIdx].Progress;
	// 	OutAchievements.Add(Achievement);
	// }

	OutAchievements = *PlayerAch;
	return EOnlineCachedResult::Success;
};

EOnlineCachedResult::Type FOnlineAchievementsPico::GetCachedAchievementDescription(
	const FString& AchievementId, FOnlineAchievementDesc& OutAchievementDesc)
{
	if (AchievementDescriptions.Num() == 0)
	{
		// we don't have achievements
		return EOnlineCachedResult::NotFound;
	}

	// uint32 Hash = TDefaultMapHashableKeyFuncs<FString, FOnlineAchievementDescPico, false>::GetKeyHash(AchievementId);
	// FOnlineAchievementDescPico* AchDesc = AchievementDescriptions.FindByHash(Hash, AchievementId);
	FOnlineAchievementDescPico* AchDesc = AchievementDescriptions.Find(AchievementId);
	if (AchDesc == nullptr || !AchDesc->Name.Equals(AchievementId))
	{
		// no such achievement
		return EOnlineCachedResult::NotFound;
	}
	
	
	if (OutAchievementDesc.Title.EqualTo(FText::FromName(USE_PICO_ACHIEVEMENT_DESC)))
	{
		FOnlineAchievementDescPico& temp = static_cast<FOnlineAchievementDescPico&>(OutAchievementDesc);
		temp = *AchDesc;
	}
	else
	{
		OutAchievementDesc.Title = FText::FromString(AchDesc->Name);
		OutAchievementDesc.bIsHidden = AchDesc->bIsHidden;
		OutAchievementDesc.LockedDesc = AchDesc->LockedDesc;
		OutAchievementDesc.UnlockedDesc = AchDesc->UnlockedDesc;
		OutAchievementDesc.UnlockTime = AchDesc->UnlockTime;
	}
	return EOnlineCachedResult::Success;
};

#if !UE_BUILD_SHIPPING
bool FOnlineAchievementsPico::ResetAchievements(const FUniqueNetId& PlayerId)
{
	// We cannot reset achievements from the client
	SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("ResetAchievements Achievements cannot be reset here")));
	return false;
};
#endif // !UE_BUILD_SHIPPING

void FOnlineAchievementsPico::GetWriteAchievementCountValue(FVariantData VariantData, long long& OutData) const
{
	switch (VariantData.GetType())
	{
	case EOnlineKeyValuePairDataType::Int32:
		{
			int32 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<long long>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::Int64:
		{
			int64 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<long long>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::UInt32:
		{
			uint32 Value;
			VariantData.GetValue(Value);
			OutData = static_cast<long long>(Value);
			break;
		}
	case EOnlineKeyValuePairDataType::UInt64:
		{
			VariantData.GetValue(OutData);
			break;
		}
	default:
		{
			SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("GetWriteAchievementCountValue Could not %s convert to uint64"), VariantData.GetTypeString()));
			OutData = 0;
			break;
		}
	}
}

void FOnlineAchievementsPico::GetWriteAchievementBitfieldValue(FVariantData VariantData, FString& OutData,
                                                               uint32 BitfieldLength) const
{
	switch (VariantData.GetType())
	{
	case EOnlineKeyValuePairDataType::Int32:
		{
			int32 Value;
			VariantData.GetValue(Value);
			auto UnpaddedBitfield = FString::FromInt(Value);
			auto PaddingLength = BitfieldLength - UnpaddedBitfield.Len();
			SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("GetWriteAchievementBitfieldValue UnpaddedBitfield: %s, BitfieldLength: %u, PaddingLength: %d"), *UnpaddedBitfield, BitfieldLength, PaddingLength));
			OutData = TEXT("");
			for (uint32 i = 0; i < PaddingLength; ++i)
			{
				OutData.AppendChar('0');
			}
			OutData.Append(UnpaddedBitfield);
			break;
		}
	case EOnlineKeyValuePairDataType::String:
		{
			VariantData.GetValue(OutData);
			break;
		}
	default:
		{
			SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("GetWriteAchievementBitfieldValue Could not %s convert to string"), VariantData.GetTypeString()));
			break;
		}
	}
}

double FOnlineAchievementsPico::CalculatePlayerAchievementProgress(const FOnlineAchievementPico Achievement)
{
	if (Achievement.bIsUnlocked)
	{
		SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("CalculatePlayerAchievementProgress Id: %s is unlocked."), *Achievement.Id));
		return 100.0;
	}

	auto Desc = AchievementDescriptions.Find(Achievement.Id);
	if (Desc == nullptr || !Desc->Name.Equals(Achievement.Id))
	{
		SaveLog(ELogVerbosity::Type::Warning, FString::Printf(TEXT("CalculatePlayerAchievementProgress Could not calculate progress for Achievement: '%s'"), *Achievement.Id));
		return 0.0;
	}

	double Progress;
	switch (Desc->Type)
	{
	case EAchievementType::Count:
		{
			Progress = Achievement.Count * 100.0 / Desc->Target;
			SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("CalculatePlayerAchievementProgress Id: %s, Count: %lld, target: %llu, Progress: %f"), *Achievement.Id, Achievement.Count, Desc->Target, Progress));
			break;
		}
	case EAchievementType::Bitfield:
		{
			int BitfieldCount = 0;
			for (int32 i = 0; i < Achievement.Bitfield.Len(); ++i)
			{
				if (Achievement.Bitfield[i] == '1')
				{
					++BitfieldCount;
				}
			}
			SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("CalculatePlayerAchievementProgress Id: %s, BitfieldCount: %d, target: %llu"), *Achievement.Id, BitfieldCount, Desc->Target));
			Progress = BitfieldCount * 100.0 / Desc->Target;
			break;
		}
	default:
		{
			Progress = 0.0;
			break;
		}
	}
	SaveLog(ELogVerbosity::Type::Verbose, FString::Printf(TEXT("CalculatePlayerAchievementProgress Id: %s, Progress: %f"), *Achievement.Id, (Progress <= 100.0) ? Progress : 100.0));
	// Cap the progress to 100
	return (Progress <= 100.0) ? Progress : 100.0;
}

void FOnlineAchievementsPico::SaveLog(const ELogVerbosity::Type Verbosity, const FString & Log) const
{
	switch (Verbosity)
	{
	case ELogVerbosity::Type::Error:
		UE_LOG_ONLINE_ACHIEVEMENTS(Error, TEXT("PPF_GAME %s"), *Log);
		break;
	case ELogVerbosity::Type::Warning:
		UE_LOG_ONLINE_ACHIEVEMENTS(Warning, TEXT("PPF_GAME %s"), *Log);
		break;
	default:
		UE_LOG_ONLINE_ACHIEVEMENTS(Log, TEXT("PPF_GAME %s"), *Log);
		break;
	}

	FDateTime Time = FDateTime::Now();
	int year = Time.GetYear();
	int month = Time.GetMonth();
	int day = Time.GetDay();
	int hour = Time.GetHour();
	int minute = Time.GetMinute();
	int second = Time.GetSecond();
    
	// FString WriteLog = FString::Printf(TEXT("[%d.%d.%d %d:%d:%d]%s\n"), year, month, day, hour, minute, second, *Log);
	// FString TextPath = FPaths::ProjectPersistentDownloadDir() + TEXT("Log-OnlineAchievementInterfacePico.txt");
	// FFileHelper::SaveStringToFile(*WriteLog, *TextPath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}