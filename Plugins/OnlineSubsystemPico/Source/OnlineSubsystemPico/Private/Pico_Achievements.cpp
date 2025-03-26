// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


// #include "Pico_Room.h"
#include "Pico_Achievements.h"

#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PicoAchievements);


// UOnlinePicoAchievementsFunction
void UOnlinePicoAchievementsFunction::PicoAddCount(UObject* WorldContextObject, const FString& Name, const FString& Count, const FString& ExtraData, FAddCount InAddCountCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoAddCount"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        int64 count = FCString::Strtoi64(*Count, NULL, 10);
        Subsystem->GetPicoAchievementsInterface()->AddCount(Name, count, ExtraData, InAddCountCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoAddCount Failed, PicoAchievementsInterface Not Vailed!"));
        InAddCountCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoAddFields(UObject* WorldContextObject, const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoAddFields"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->AddFields(Name, Fields, ExtraData, InAddFieldsCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoAddFields Failed, PicoAchievementsInterface Not Vailed!"));
        InAddFieldsCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoUnlock(UObject* WorldContextObject, const FString& Name, const FString& ExtraData, FUnlock InUnlockCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoUnlock"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->Unlock(Name, ExtraData, InUnlockCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoUnlock Failed, PicoAchievementsInterface Not Vailed!"));
        InUnlockCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoGetAllDefinitions(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoGetAllDefinitions"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->GetAllDefinitions(PageIndex, PageSize, InGetAllDefinitionsCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoGetAllDefinitions Failed, PicoAchievementsInterface Not Vailed!"));
        InGetAllDefinitionsCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoGetAllProgress(UObject* WorldContextObject, int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoGetAllProgress"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->GetAllProgress(PageIndex, PageSize, InGetAllProgressCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoGetAllProgress Failed, PicoAchievementsInterface Not Vailed!"));
        InGetAllProgressCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoGetDefinitionsByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoGetDefinitionsByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->GetDefinitionsByName(NameArray, InGetDefinitionsByNameCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoGetDefinitionsByName Failed, PicoAchievementsInterface Not Vailed!"));
        InGetDefinitionsByNameCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}

void UOnlinePicoAchievementsFunction::PicoGetProgressByName(UObject* WorldContextObject, const TArray<FString>& NameArray, FGetProgressByName InGetProgressByNameCallback)
{
    UE_LOG(PicoAchievements, Log, TEXT("UOnlinePicoAchievementsFunction::PicoGetProgressByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAchievementsInterface())
    {
        Subsystem->GetPicoAchievementsInterface()->GetProgressByName(NameArray, InGetProgressByNameCallback);
    }
    else
    {
        UE_LOG(PicoAchievements, Log, TEXT("PicoGetProgressByName Failed, PicoAchievementsInterface Not Vailed!"));
        InGetProgressByNameCallback.ExecuteIfBound(true, FString(TEXT("PicoAchievementsInterface Not Vailed")), nullptr);
    }
}



// FPicoAchievementsInterface
FPicoAchievementsInterface::FPicoAchievementsInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoAchievementsInterface::~FPicoAchievementsInterface()
{

}

bool FPicoAchievementsInterface::AddCount(const FString& Name, const int64& Count, const FString& ExtraData, FAddCount InAddCountDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::AddCount"));
    const TCHAR* StrPtr = *ExtraData;
    FTCHARToUTF8 UTF8String(StrPtr);
    int32 Size = UTF8String.Length();
    TArray<uint8> UTF8Data;
    UTF8Data.SetNum(Size);
    memcpy(UTF8Data.GetData(), UTF8String.Get(), Size);

    ppfRequest RequestId = ppf_Achievements_AddCount(TCHAR_TO_UTF8(*Name), Count, UTF8Data.GetData(), Size);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InAddCountDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("AddCount return failed:%s"), *ErrorMessage);
                this->AddCountDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InAddCountDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("AddCount Successfully"));
                UPico_AchievementUpdate* Pico_AchievementUpdate = NewObject<UPico_AchievementUpdate>();
                Pico_AchievementUpdate->InitParams(ppf_Message_GetAchievementUpdate(Message));
                this->AddCountDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
                InAddCountDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::AddFields(const FString& Name, const FString& Fields, const FString& ExtraData, FAddFields InAddFieldsDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::AddFields"));
    const TCHAR* StrPtr = *ExtraData;
    FTCHARToUTF8 UTF8String(StrPtr);
    int32 Size = UTF8String.Length();
    TArray<uint8> UTF8Data;
    UTF8Data.SetNum(Size);
    memcpy(UTF8Data.GetData(), UTF8String.Get(), Size);

    ppfRequest RequestId = ppf_Achievements_AddFields(TCHAR_TO_UTF8(*Name), TCHAR_TO_UTF8(*Fields), UTF8Data.GetData(), Size);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InAddFieldsDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("AddFields return failed:%s"), *ErrorMessage);
                this->AddFieldsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InAddFieldsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("AddFields Successfully"));
                UPico_AchievementUpdate* Pico_AchievementUpdate = NewObject<UPico_AchievementUpdate>();
                Pico_AchievementUpdate->InitParams(ppf_Message_GetAchievementUpdate(Message));
                this->AddFieldsDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
                InAddFieldsDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::Unlock(const FString& Name, const FString& ExtraData, FUnlock InUnlockDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::Unlock"));
    const TCHAR* StrPtr = *ExtraData;
    FTCHARToUTF8 UTF8String(StrPtr);
    int32 Size = UTF8String.Length();
    TArray<uint8> UTF8Data;
    UTF8Data.SetNum(Size);
    memcpy(UTF8Data.GetData(), UTF8String.Get(), Size);

    ppfRequest RequestId = ppf_Achievements_Unlock(TCHAR_TO_UTF8(*Name), UTF8Data.GetData(), Size);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InUnlockDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("AddFields return failed:%s"), *ErrorMessage);
                this->UnlockDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InUnlockDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("AddFields Successfully"));
                UPico_AchievementUpdate* Pico_AchievementUpdate = NewObject<UPico_AchievementUpdate>();
                Pico_AchievementUpdate->InitParams(ppf_Message_GetAchievementUpdate(Message));
                this->UnlockDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
                InUnlockDelegate.ExecuteIfBound(false, FString(), Pico_AchievementUpdate);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::GetAllDefinitions(int32 PageIndex, int32 PageSize, FGetAllDefinitions InGetAllDefinitionsDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::GetAllDefinitions"));
    ppfRequest RequestId = ppf_Achievements_GetAllDefinitions(PageIndex, PageSize);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetAllDefinitionsDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("GetAllDefinitions return failed:%s"), *ErrorMessage);
                this->GetAllDefinitionsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetAllDefinitionsDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("GetAllDefinitions Successfully"));
                UPico_AchievementDefinitionArray* Pico_AchievementDefinitionArray = NewObject<UPico_AchievementDefinitionArray>();
                Pico_AchievementDefinitionArray->InitParams(ppf_Message_GetAchievementDefinitionArray(Message));
                this->GetAllDefinitionsDelegate.ExecuteIfBound(false, FString(), Pico_AchievementDefinitionArray);
                InGetAllDefinitionsDelegate.ExecuteIfBound(false, FString(), Pico_AchievementDefinitionArray);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::GetAllProgress(int32 PageIndex, int32 PageSize, FGetAllProgress InGetAllProgressDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::GetAllProgress"));
    ppfRequest RequestId = ppf_Achievements_GetAllProgress(PageIndex, PageSize);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetAllProgressDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("GetAllProgress return failed:%s"), *ErrorMessage);
                this->GetAllProgressDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetAllProgressDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("GetAllProgress Successfully"));
                UPico_AchievementProgressArray* Pico_AchievementProgressArray = NewObject<UPico_AchievementProgressArray>();
                Pico_AchievementProgressArray->InitParams(ppf_Message_GetAchievementProgressArray(Message));
                this->GetAllProgressDelegate.ExecuteIfBound(false, FString(), Pico_AchievementProgressArray);
                InGetAllProgressDelegate.ExecuteIfBound(false, FString(), Pico_AchievementProgressArray);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::GetDefinitionsByName(const TArray<FString>& NameArray, FGetDefinitionsByName InGetDefinitionsByNameDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::GetDefinitionsByName"));
    int32 Length = NameArray.Num();
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < NameArray.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(NameArray[i]))));
    }
    std::vector<const char*> Names;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        Names.push_back(StringArray[i].c_str());
    }
    ppfRequest RequestId = ppf_Achievements_GetDefinitionsByName(Names.data(), NameArray.Num());
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetDefinitionsByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("GetDefinitionsByName return failed:%s"), *ErrorMessage);
                this->GetDefinitionsByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetDefinitionsByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("GetDefinitionsByName Successfully"));
                UPico_AchievementDefinitionArray* Pico_AchievementDefinitionArray = NewObject<UPico_AchievementDefinitionArray>();
                Pico_AchievementDefinitionArray->InitParams(ppf_Message_GetAchievementDefinitionArray(Message));
                this->GetDefinitionsByNameDelegate.ExecuteIfBound(false, FString(), Pico_AchievementDefinitionArray);
                InGetDefinitionsByNameDelegate.ExecuteIfBound(false, FString(), Pico_AchievementDefinitionArray);
            }
        }));
    return true;
}

bool FPicoAchievementsInterface::GetProgressByName(const TArray<FString>& NameArray, FGetProgressByName InGetProgressByNameDelegate)
{
    UE_LOG(PicoAchievements, Log, TEXT("FPicoAchievementsInterface::GetProgressByName"));
    int32 Length = NameArray.Num();
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < NameArray.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(NameArray[i]))));
    }
    std::vector<const char*> Names;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        Names.push_back(StringArray[i].c_str());
    }
    ppfRequest RequestId = ppf_Achievements_GetProgressByName(Names.data(), NameArray.Num());
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetProgressByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAchievements, Log, TEXT("GetProgressByName return failed:%s"), *ErrorMessage);
                this->GetProgressByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetProgressByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAchievements, Log, TEXT("GetProgressByName Successfully"));
                UPico_AchievementProgressArray* Pico_AchievementProgressArray = NewObject<UPico_AchievementProgressArray>();
                Pico_AchievementProgressArray->InitParams(ppf_Message_GetAchievementProgressArray(Message));
                this->GetProgressByNameDelegate.ExecuteIfBound(false, FString(), Pico_AchievementProgressArray);
                InGetProgressByNameDelegate.ExecuteIfBound(false, FString(), Pico_AchievementProgressArray);
            }
        }));
    return true;
}



// UPico_AchievementUpdate
void UPico_AchievementUpdate::InitParams(ppfAchievementUpdateHandle ppfAchievementUpdateHandle)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementUpdate::InitParams"));
    Name = UTF8_TO_TCHAR(ppf_AchievementUpdate_GetName(ppfAchievementUpdateHandle));
    JustUnlocked = ppf_AchievementUpdate_GetJustUnlocked(ppfAchievementUpdateHandle);
}

FString UPico_AchievementUpdate::GetName()
{
    return Name;
}

bool UPico_AchievementUpdate::GetJustUnlocked()
{
    return JustUnlocked;
}




// UPico_AchievementProgress
void UPico_AchievementProgress::InitParams(ppfAchievementProgressHandle ppfAchievementProgressHandle)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementProgress::InitParams"));
    Bitfield = UTF8_TO_TCHAR(ppf_AchievementProgress_GetBitfield(ppfAchievementProgressHandle));
    Count = ppf_AchievementProgress_GetCount(ppfAchievementProgressHandle);
    IsUnlocked = ppf_AchievementProgress_GetIsUnlocked(ppfAchievementProgressHandle);
    Name = UTF8_TO_TCHAR(ppf_AchievementProgress_GetName(ppfAchievementProgressHandle));
    ID = ppf_AchievementProgress_GetID(ppfAchievementProgressHandle);
    unsigned size = ppf_AchievementProgress_GetExtraDataLength(ppfAchievementProgressHandle);
    auto extraData = (uint8*)ppf_AchievementProgress_GetExtraData(ppfAchievementProgressHandle);
    for (int i = 0; i < (int)size; i++)
    {
        ExtraData.Add(*(extraData + i));
    }
    UnlockTime = ppf_AchievementProgress_GetUnlockTime(ppfAchievementProgressHandle);
}

FString UPico_AchievementProgress::GetBitfield()
{
    return Bitfield;
}

int64 UPico_AchievementProgress::GetCount()
{
    return Count;
}

bool UPico_AchievementProgress::GetIsUnlocked()
{
    return IsUnlocked;
}

FString UPico_AchievementProgress::GetName()
{
    return Name;
}

FString UPico_AchievementProgress::GetUnlockTime()
{
    return FString::Printf(TEXT("%llu"), UnlockTime);
}

FDateTime UPico_AchievementProgress::GetUnlockDateTime()
{
    FDateTime Time = FDateTime::FromUnixTimestamp(UnlockTime);
    return Time;
}

FString UPico_AchievementProgress::GetID()
{
    return FString::Printf(TEXT("%llu"), ID);
}

TArray<uint8> UPico_AchievementProgress::GetExtraData()
{
    return ExtraData;
}

FString UPico_AchievementProgress::GetExtraDataString()
{
    const std::string cstr(reinterpret_cast<const char*>(ExtraData.GetData()), ExtraData.Num());
    FString ExtraDataString = UTF8_TO_TCHAR(cstr.c_str());
    return ExtraDataString;
}



// UPico_AchievementDefinition
void UPico_AchievementDefinition::InitParams(ppfAchievementDefinition* ppfAchievementDefinitionHandle)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementDefinition::InitParams"));
    Type = (EAchievementType)ppf_AchievementDefinition_GetType(ppfAchievementDefinitionHandle);
    Name = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetName(ppfAchievementDefinitionHandle));
    BitfieldLength = ppf_AchievementDefinition_GetBitfieldLength(ppfAchievementDefinitionHandle);
    Target = ppf_AchievementDefinition_GetTarget(ppfAchievementDefinitionHandle);
    Description = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetDescription(ppfAchievementDefinitionHandle));
    Title = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetTitle(ppfAchievementDefinitionHandle));
    IsArchived = ppf_AchievementDefinition_IsArchived(ppfAchievementDefinitionHandle);
    IsSecret = ppf_AchievementDefinition_IsSecret(ppfAchievementDefinitionHandle);
    ID = ppf_AchievementDefinition_GetID(ppfAchievementDefinitionHandle);
    UnlockedDescription = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetUnlockedDescription(ppfAchievementDefinitionHandle));
    WritePolicy = (EAchievementWritePolicy)ppf_AchievementDefinition_GetWritePolicy(ppfAchievementDefinitionHandle);
    LockedImageURL = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetLockedImageURL(ppfAchievementDefinitionHandle));
    UnlockedImageURL = UTF8_TO_TCHAR(ppf_AchievementDefinition_GetUnlockedImageURL(ppfAchievementDefinitionHandle));
}

FString UPico_AchievementDefinition::GetName()
{
    return Name;
}

FString UPico_AchievementDefinition::GetBitfieldLength()
{
    return FString::Printf(TEXT("%u"), BitfieldLength);
}

int64 UPico_AchievementDefinition::GetTarget()
{
    return Target;
}

EAchievementType UPico_AchievementDefinition::GetType()
{
    return Type;
}

FString UPico_AchievementDefinition::GetDescription()
{
    return Description;
}

FString UPico_AchievementDefinition::GetTitle()
{
    return Title;
}

bool UPico_AchievementDefinition::GetIsArchived()
{
    return IsArchived;
}

bool UPico_AchievementDefinition::GetIsSecret()
{
    return IsSecret;
}

FString UPico_AchievementDefinition::GetID()
{
    return FString::Printf(TEXT("%llu"), ID);
}

FString UPico_AchievementDefinition::GetUnlockedDescription()
{
    return UnlockedDescription;
}

EAchievementWritePolicy UPico_AchievementDefinition::GetWritePolicy()
{
    return WritePolicy;
}

FString UPico_AchievementDefinition::GetLockedImageURL()
{
    return LockedImageURL;
}

FString UPico_AchievementDefinition::GetUnlockedImageURL()
{
    return UnlockedImageURL;
}



// UPico_AchievementProgressArray
void UPico_AchievementProgressArray::InitParams(ppfAchievementProgressArrayHandle InppfAchievementProgressArrayHandle)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementProgressArray::InitParams"));
    Size = ppf_AchievementProgressArray_GetSize(InppfAchievementProgressArrayHandle);
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementProgressArray::InitParams ppf_AchievementProgressArray_GetSize: %d"), Size);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_AchievementProgress* ThisElement = NewObject<UPico_AchievementProgress>();
        ThisElement->InitParams(ppf_AchievementProgressArray_GetElement(InppfAchievementProgressArrayHandle, i));
        AchievementProgressArray.Add(ThisElement);
    }
    bHasNextPage = ppf_AchievementProgressArray_HasNextPage(InppfAchievementProgressArrayHandle);
    TotalSize = ppf_AchievementProgressArray_GetTotalSize(InppfAchievementProgressArrayHandle);
}

UPico_AchievementProgress* UPico_AchievementProgressArray::GetElement(int32 Index)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementProgressArray::GetElement Index: %d"), Index);
    if (AchievementProgressArray.IsValidIndex(Index))
    {
        return AchievementProgressArray[Index];
    }
    return nullptr;
}

int32 UPico_AchievementProgressArray::GetSize()
{
    return Size;
}

int32 UPico_AchievementProgressArray::GetTotalSize()
{
    return TotalSize;
}

bool UPico_AchievementProgressArray::HasNextPage()
{
    return bHasNextPage;
}




// UPico_AchievementDefinitionArray
void UPico_AchievementDefinitionArray::InitParams(ppfAchievementDefinitionArrayHandle InppfAchievementDefinitionArrayHandle)
{
    UE_LOG(PicoAchievements, Log, TEXT("UPico_AchievementDefinitionArray::InitParams"));
    Size = ppf_AchievementDefinitionArray_GetSize(InppfAchievementDefinitionArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_AchievementDefinition* ThisElement = NewObject<UPico_AchievementDefinition>();
        ThisElement->InitParams(ppf_AchievementDefinitionArray_GetElement(InppfAchievementDefinitionArrayHandle, i));
        AchievementDefinitionArray.Add(ThisElement);
    }
    bHasNextPage = ppf_AchievementDefinitionArray_HasNextPage(InppfAchievementDefinitionArrayHandle);
    TotalSize = ppf_AchievementDefinitionArray_GetTotalSize(InppfAchievementDefinitionArrayHandle);
}

UPico_AchievementDefinition* UPico_AchievementDefinitionArray::GetElement(int32 Index)
{
    if (AchievementDefinitionArray.IsValidIndex(Index))
    {
        return AchievementDefinitionArray[Index];
    }
    return nullptr;
}

int32 UPico_AchievementDefinitionArray::GetSize()
{
    return Size;
}

int32 UPico_AchievementDefinitionArray::GetTotalSize()
{
    return TotalSize;
}

bool UPico_AchievementDefinitionArray::HasNextPage()
{
    return bHasNextPage;
}