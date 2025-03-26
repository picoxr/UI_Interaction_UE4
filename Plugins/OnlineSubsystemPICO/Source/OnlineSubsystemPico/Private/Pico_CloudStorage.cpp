// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_CloudStorage.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"

DEFINE_LOG_CATEGORY(PicoCloudStorage);

FPicoCloudStorageInterface::FPicoCloudStorageInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoCloudStorageInterface::~FPicoCloudStorageInterface()
{

}

bool FPicoCloudStorageInterface::StartNewBackup(FStartNewCloud_Backup InDelegate)
{
    UE_LOG(PicoCloudStorage, Log, TEXT("FPicoCloudStorageInterface::StartNewBackup"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_CloudStorage_StartNewBackup();

    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoCloudStorage, Log, TEXT("StartNewBackup return failed: %d, %s"), ErrorCode, *ErrorMessage);
                this->CloudStartNewBackupDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
                InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage);
            }
            else
            {
                UE_LOG(PicoCloudStorage, Log, TEXT("StartNewBackup Successfully"));
                this->CloudStartNewBackupDelegate.ExecuteIfBound(false, 0, FString());
                InDelegate.ExecuteIfBound(false, 0, FString());
            }
        }));
    return true;
#endif
    return false;
}

bool UOnlinePicoCloudStorageFunction::StartNewBackup(UObject* WorldContextObject, FStartNewCloud_Backup InDelegate)
{
    UE_LOG(PicoCloudStorage, Log, TEXT("UOnlinePicoCloudStorageFunction::StartNewBackup"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoCloudStorageInterface())
    {
        return Subsystem->GetPicoCloudStorageInterface()->StartNewBackup(InDelegate);
    }
    else
    {
        UE_LOG(PicoCloudStorage, Log, TEXT("StartNewBackup Failed, PicoCloudBackupInterface Not Vailed!"));
        InDelegate.ExecuteIfBound(true, 0, FString(TEXT("PicoCloudBackupInterface Not Vailed")));
        return false;
    }
}
