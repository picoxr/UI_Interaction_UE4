// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "Pico_Sport.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"

DEFINE_LOG_CATEGORY(PicoSport);




FPicoSportInterface::FPicoSportInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoSportInterface::~FPicoSportInterface()
{

}


bool FPicoSportInterface::GetDailySummary(int64 BeginTime, int64 EndTime, FGetDailySummary InGetDailySummaryDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("FPicoSportInterface::GetDailySummary"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Sport_GetDailySummary(BeginTime, EndTime);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetDailySummaryDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoSport, Log, TEXT("GetDailySummary return failed:%s"), *ErrorMessage);
                this->GetDailySummaryDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetDailySummaryDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoSport, Log, TEXT("GetDailySummary Successfully"));
                UPico_SportDailySummaryArray* SportDailySummaryArray = NewObject<UPico_SportDailySummaryArray>();
                SportDailySummaryArray->InitParams(ppf_Message_GetSportDailySummaryArray(Message));
                this->GetDailySummaryDelegate.ExecuteIfBound(false, FString(), SportDailySummaryArray);
                InGetDailySummaryDelegate.ExecuteIfBound(false, FString(), SportDailySummaryArray);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoSportInterface::GetSummary(int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("FPicoSportInterface::GetSummary"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Sport_GetSummary(BeginTime, EndTime);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetSummaryDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoSport, Log, TEXT("GetSummary return failed:%s"), *ErrorMessage);
                this->GetSummaryDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetSummaryDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoSport, Log, TEXT("GetSummary Successfully"));
                UPico_SportSummary* SportSummary = NewObject<UPico_SportSummary>();
                SportSummary->InitParams(ppf_Message_GetSportSummary(Message));
                this->GetSummaryDelegate.ExecuteIfBound(false, FString(), SportSummary);
                InGetSummaryDelegate.ExecuteIfBound(false, FString(), SportSummary);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoSportInterface::GetSportUserInfo(FGetSportUserInfo InGetSportUserInfoDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("FPicoSportInterface::GetSportUserInfo"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_Sport_GetUserInfo();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetSportUserInfoDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoSport, Log, TEXT("GetSportUserInfo return failed:%s"), *ErrorMessage);
                this->GetSportUserInfoDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetSportUserInfoDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoSport, Log, TEXT("GetSportUserInfo Successfully"));
                UPico_SportUserInfo* SportUserInfo = NewObject<UPico_SportUserInfo>();
                SportUserInfo->InitParams(ppf_Message_GetSportUserInfo(Message));
                this->GetSportUserInfoDelegate.ExecuteIfBound(false, FString(), SportUserInfo);
                InGetSportUserInfoDelegate.ExecuteIfBound(false, FString(), SportUserInfo);
            }
        }));
    return true;
#endif
    return false;
}

bool UOnlinePicoSportFunction::GetDailySummary(UObject* WorldContextObject, int64 BeginTime, int64 EndTime, FGetDailySummary InGetDailySummaryDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("UOnlinePicoSportFunction::GetDailySummary"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSportInterface())
    {
        return Subsystem->GetPicoSportInterface()->GetDailySummary(BeginTime, EndTime, InGetDailySummaryDelegate);
    }
    else
    {
        UE_LOG(PicoSport, Log, TEXT("GetDailySummary Failed, PicoSportInterface Not Vailed!"));
        InGetDailySummaryDelegate.ExecuteIfBound(true, FString(TEXT("PicoSportInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoSportFunction::GetSummary(UObject* WorldContextObject, int64 BeginTime, int64 EndTime, FGetSummary InGetSummaryDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("UOnlinePicoSportFunction::GetSummary"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSportInterface())
    {
        return Subsystem->GetPicoSportInterface()->GetSummary(BeginTime, EndTime, InGetSummaryDelegate);
    }
    else
    {
        UE_LOG(PicoSport, Log, TEXT("GetSummary Failed, PicoSportInterface Not Vailed!"));
        InGetSummaryDelegate.ExecuteIfBound(true, FString(TEXT("PicoSportInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoSportFunction::GetSportUserInfo(UObject* WorldContextObject, FGetSportUserInfo InGetSportUserInfoDelegate)
{
    UE_LOG(PicoSport, Log, TEXT("UOnlinePicoSportFunction::GetSportUserInfo"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoSportInterface())
    {
        return Subsystem->GetPicoSportInterface()->GetSportUserInfo(InGetSportUserInfoDelegate);
    }
    else
    {
        UE_LOG(PicoSport, Log, TEXT("GetSportUserInfo Failed, PicoSportInterface Not Vailed!"));
        InGetSportUserInfoDelegate.ExecuteIfBound(true, FString(TEXT("PicoSportInterface Not Vailed")), nullptr);
        return false;
    }
}

int64 UOnlinePicoSportFunction::ConvertDateTimeToInt64(FDateTime InDateTime)
{
    // ms
    FTimespan DiffTicks = FDateTime::Now() - FDateTime::UtcNow();
    InDateTime = InDateTime.operator-(DiffTicks);
    return InDateTime.ToUnixTimestamp() * 1000;
}


FDateTime UOnlinePicoSportFunction::ConvertInt64ToDateTime(int64 InValue)
{
    // ms
    FTimespan DiffTicks = FDateTime::Now() - FDateTime::UtcNow();
    return FDateTime::FromUnixTimestamp(InValue / 1000) + DiffTicks;
}

void UPico_SportDailySummary::InitParams(ppfSportDailySummary* ppfSportDailySummaryHandle)
{
    UE_LOG(PicoSport, Log, TEXT("UPico_SportDailySummary::InitParams"));
#if PLATFORM_ANDROID
    ID = ppf_SportDailySummary_GetId(ppfSportDailySummaryHandle);
    Date = ppf_SportDailySummary_GetDate(ppfSportDailySummaryHandle);
    FString DateStr = FString::Printf(TEXT("%lld"), Date);
    UE_LOG(PicoSport, Log, TEXT("Date: %s"), *DateStr);
    DurationInSeconds = ppf_SportDailySummary_GetDurationInSeconds(ppfSportDailySummaryHandle);
    PlanDurationInMinutes = ppf_SportDailySummary_GetPlanDurationInMinutes(ppfSportDailySummaryHandle);
    Calorie = ppf_SportDailySummary_GetCalorie(ppfSportDailySummaryHandle);
    PlanCalorie = ppf_SportDailySummary_GetPlanCalorie(ppfSportDailySummaryHandle);
#endif
}

int64 UPico_SportDailySummary::GetID()
{
    return ID;
}

int64 UPico_SportDailySummary::GetDate()
{
    return Date;
}

int32 UPico_SportDailySummary::GetDurationInSeconds()
{
    return DurationInSeconds;
}

int32 UPico_SportDailySummary::GetPlanDurationInMinutes()
{
    return PlanDurationInMinutes;
}

float UPico_SportDailySummary::GetCalorie()
{
    return Calorie;
}

float UPico_SportDailySummary::GetPlanCalorie()
{
    return PlanCalorie;
}

void UPico_SportDailySummaryArray::InitParams(ppfSportDailySummaryArray* ppfSportDailySummaryArrayHandle)
{
    UE_LOG(PicoSport, Log, TEXT("UPico_SportDailySummaryArray::InitParams"));
#if PLATFORM_ANDROID
    Size = ppf_SportDailySummaryArray_GetSize(ppfSportDailySummaryArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_SportDailySummary* ThisElement = NewObject<UPico_SportDailySummary>();
        ThisElement->InitParams(ppf_SportDailySummaryArray_GetElement(ppfSportDailySummaryArrayHandle, i));
        SportDailySummaryArray.Add(ThisElement);
    }
#endif
}

int32 UPico_SportDailySummaryArray::GetSize()
{
    return Size;
}

UPico_SportDailySummary* UPico_SportDailySummaryArray::GetElement(int32 Index)
{
    if (SportDailySummaryArray.IsValidIndex(Index))
    {
        return SportDailySummaryArray[Index];
    }
    return nullptr;
}

void UPico_SportSummary::InitParams(ppfSportSummary* ppfSportSummaryHandle)
{
    UE_LOG(PicoSport, Log, TEXT("UPico_SportSummary::InitParams"));
#if PLATFORM_ANDROID
    DurationInSeconds = ppf_SportSummary_GetDurationInSeconds(ppfSportSummaryHandle);
    Calorie = ppf_SportSummary_GetCalorie(ppfSportSummaryHandle);

    StartTime = ppf_SportSummary_GetStartTime(ppfSportSummaryHandle);
    FString StartTimeStr = FString::Printf(TEXT("%lld"), StartTime);
    UE_LOG(PicoSport, Log, TEXT("StartTimeStr: %s"), *StartTimeStr);
    EndTime = ppf_SportSummary_GetEndTime(ppfSportSummaryHandle);
    FString EndTimeStr = FString::Printf(TEXT("%lld"), EndTime);
    UE_LOG(PicoSport, Log, TEXT("EndTimeStr: %s"), *EndTimeStr);
#endif
}

int64 UPico_SportSummary::GetDurationInSeconds()
{
    return DurationInSeconds;
}

float UPico_SportSummary::GetCalorie()
{
    return Calorie;
}

int64 UPico_SportSummary::GetStartTime()
{
    return StartTime;
}

int64 UPico_SportSummary::GetEndTime()
{
    return EndTime;
}

void UPico_SportUserInfo::InitParams(ppfSportUserInfo* ppfSportUserInfoHandle)
{
    UE_LOG(PicoSport, Log, TEXT("UPico_SportUserInfo::InitParams"));
#if PLATFORM_ANDROID
    ppfGender pGender = ppf_SportUserInfo_GetGender(ppfSportUserInfoHandle);
    if (pGender == ppfGender_Female)
    {
        Gender = EUserGender::Female;
    }
    else if (pGender == ppfGender_Male)
    {
        Gender = EUserGender::Male;
    }
    Birthday = ppf_SportUserInfo_GetBirthday(ppfSportUserInfoHandle);
    FString BirthdayStr = FString::Printf(TEXT("%lld"), Birthday);
    UE_LOG(PicoSport, Log, TEXT("BirthdayStr: %s"), *BirthdayStr);
    Stature = ppf_SportUserInfo_GetStature(ppfSportUserInfoHandle);
    Weight = ppf_SportUserInfo_GetWeight(ppfSportUserInfoHandle);
    SportLevel = ppf_SportUserInfo_GetSportLevel(ppfSportUserInfoHandle);
    DailyDurationInMinutes = ppf_SportUserInfo_GetDailyDurationInMinutes(ppfSportUserInfoHandle);
    DaysPerWeek = ppf_SportUserInfo_GetDaysPerWeek(ppfSportUserInfoHandle);
    ppfSportTarget pSportTarget = ppf_SportUserInfo_GetSportTarget(ppfSportUserInfoHandle);
    if (pSportTarget == ppfSportTarget_KeepFit)
    {
        SportTarget = ESportTarget::KeepFit;
    }
    else if (pSportTarget == ppfSportTarget_LoseFat)
    {
        SportTarget = ESportTarget::LoseFat;
    }
#endif
}

EUserGender UPico_SportUserInfo::GetGender()
{
    return Gender;
}

int64 UPico_SportUserInfo::GetBirthday()
{
    return Birthday;
}

int32 UPico_SportUserInfo::GetStature()
{
    return Stature;
}

int32 UPico_SportUserInfo::GetWeight()
{
    return Weight;
}

int32 UPico_SportUserInfo::GetSportLevel()
{
    return SportLevel;
}

int32 UPico_SportUserInfo::GetDailyDurationInMinutes()
{
    return DailyDurationInMinutes;
}

int32 UPico_SportUserInfo::GetDaysPerWeek()
{
    return DaysPerWeek;
}

ESportTarget UPico_SportUserInfo::GetSportTarget()
{
    return SportTarget;
}


