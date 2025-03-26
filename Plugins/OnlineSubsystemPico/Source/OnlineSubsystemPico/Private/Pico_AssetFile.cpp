// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_AssetFile.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"

DEFINE_LOG_CATEGORY(PicoAssetFile);

FPicoAssetFileInterface::FPicoAssetFileInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{
    AssetFileDownloadUpdateHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_AssetFile_DownloadUpdate)
        .AddRaw(this, &FPicoAssetFileInterface::OnAssetFileDownloadUpdate);

    AssetFileDeleteForSafetyHandle =
        PicoSubsystem.GetOrAddNotify(ppfMessageType_Notification_AssetFile_DeleteForSafety)
        .AddRaw(this, &FPicoAssetFileInterface::OnAssetFileDeleteForSafety);
}

FPicoAssetFileInterface::~FPicoAssetFileInterface()
{
    if (AssetFileDownloadUpdateHandle.IsValid())
    {
        AssetFileDownloadUpdateHandle.Reset();
    }

    if (AssetFileDeleteForSafetyHandle.IsValid())
    {
        AssetFileDeleteForSafetyHandle.Reset();
    }
}

bool FPicoAssetFileInterface::DeleteByID(FString AssetFileID, FAssetFileDeleteResult InDeleteByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DeleteByID"));
#if PLATFORM_ANDROID
    //ppfID FileID = FCString::Strtoui64(*AssetFileID, NULL, 10);
    ppfRequest RequestId = ppf_AssetFile_DeleteById(FStringTouint64(AssetFileID));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDeleteByIDDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DeleteByID return failed:%s"), *ErrorMessage);
                this->DeleteByIDDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDeleteByIDDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DeleteByID Successfully"));
                UPico_AssetFileDeleteResult* Pico_AssetFileDeleteResult = NewObject<UPico_AssetFileDeleteResult>();
                Pico_AssetFileDeleteResult->InitParams(ppf_Message_GetAssetFileDeleteResult(Message));
                this->DeleteByIDDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDeleteResult);
                InDeleteByIDDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDeleteResult);
            }
        }));
    return true;
#endif
    return false;

}

bool FPicoAssetFileInterface::DeleteByName(FString AssetFileName, FAssetFileDeleteResult InDeleteByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DeleteByName"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_DeleteByName(TCHAR_TO_UTF8(*AssetFileName));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDeleteByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DeleteByName return failed:%s"), *ErrorMessage);
                this->DeleteByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDeleteByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DeleteByName Successfully"));
                UPico_AssetFileDeleteResult* Pico_AssetFileDeleteResult = NewObject<UPico_AssetFileDeleteResult>();
                Pico_AssetFileDeleteResult->InitParams(ppf_Message_GetAssetFileDeleteResult(Message));
                this->DeleteByNameDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDeleteResult);
                InDeleteByNameDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDeleteResult);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::DownloadById(FString AssetFileID, FAssetFileDownloadResult InDownloadByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DownloadById"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_DownloadById(FStringTouint64(AssetFileID));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDownloadByIDDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadById return failed:%s"), *ErrorMessage);
                this->DownloadByIdDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDownloadByIDDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadById Successfully"));
                UPico_AssetFileDownloadResult* Pico_AssetFileDownloadResult = NewObject<UPico_AssetFileDownloadResult>();
                Pico_AssetFileDownloadResult->InitParams(ppf_Message_GetAssetFileDownloadResult(Message));
                this->DownloadByIdDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDownloadResult);
                InDownloadByIDDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDownloadResult);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::DownloadByName(FString AssetFileName, FAssetFileDownloadResult InDownloadByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DownloadByName"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_DownloadByName(TCHAR_TO_UTF8(*AssetFileName));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDownloadByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadByName return failed:%s"), *ErrorMessage);
                this->DownloadByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDownloadByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadByName Successfully"));
                UPico_AssetFileDownloadResult* Pico_AssetFileDownloadResult = NewObject<UPico_AssetFileDownloadResult>();
                Pico_AssetFileDownloadResult->InitParams(ppf_Message_GetAssetFileDownloadResult(Message));
                this->DownloadByNameDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDownloadResult);
                InDownloadByNameDelegate.ExecuteIfBound(false, FString(), Pico_AssetFileDownloadResult);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::DownloadCancelById(FString AssetFileID, FAssetFileDownloadCancelResult InDownloadCancelByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DownloadCancelById"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_DownloadCancelById(FStringTouint64(AssetFileID));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDownloadCancelByIDDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelById return failed:%s"), *ErrorMessage);
                this->DownloadCancelByIdDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDownloadCancelByIDDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelById Successfully"));
                UPico_AssetFileDownloadCancelResult* AssetFileDownloadCancelResult = NewObject<UPico_AssetFileDownloadCancelResult>();
                AssetFileDownloadCancelResult->InitParams(ppf_Message_GetAssetFileDownloadCancelResult(Message));
                this->DownloadCancelByIdDelegate.ExecuteIfBound(false, FString(), AssetFileDownloadCancelResult);
                InDownloadCancelByIDDelegate.ExecuteIfBound(false, FString(), AssetFileDownloadCancelResult);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::DownloadCancelByName(FString AssetFileName, FAssetFileDownloadCancelResult InDownloadCancelByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::DownloadCancelByName"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_DownloadCancelByName(TCHAR_TO_UTF8(*AssetFileName));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDownloadCancelByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelByName return failed:%s"), *ErrorMessage);
                this->DownloadCancelNameIdDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InDownloadCancelByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelByName Successfully"));
                UPico_AssetFileDownloadCancelResult* AssetFileDownloadCancelResult = NewObject<UPico_AssetFileDownloadCancelResult>();
                AssetFileDownloadCancelResult->InitParams(ppf_Message_GetAssetFileDownloadCancelResult(Message));
                this->DownloadCancelNameIdDelegate.ExecuteIfBound(false, FString(), AssetFileDownloadCancelResult);
                InDownloadCancelByNameDelegate.ExecuteIfBound(false, FString(), AssetFileDownloadCancelResult);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::GetAssetFileList(FGetAssetFileList InGetAssetFileListDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::GetAssetFileList"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_GetList();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetAssetFileListDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileList return failed:%s"), *ErrorMessage);
                this->GetAssetFileListDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetAssetFileListDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileList Successfully"));
                UPico_AssetDetailsArray* AssetDetailsArray = NewObject<UPico_AssetDetailsArray>();
                AssetDetailsArray->InitParams(ppf_Message_GetAssetDetailsArray(Message));
                this->GetAssetFileListDelegate.ExecuteIfBound(false, FString(), AssetDetailsArray);
                InGetAssetFileListDelegate.ExecuteIfBound(false, FString(), AssetDetailsArray);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::GetNextAssetDetailsArrayPage(UPico_AssetDetailsArray* InAssetDetailsArray, FGetAssetFileList InGetNextAssetDetailsArrayPageDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::GetNextAssetDetailsArrayPage"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_GetNextAssetDetailsArrayPage(TCHAR_TO_UTF8(*InAssetDetailsArray->GetNextPageParam()));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetNextAssetDetailsArrayPageDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("GetNextAssetDetailsArrayPage return failed:%s"), *ErrorMessage);
                this->GetNextAssetDetailsArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetNextAssetDetailsArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("GetNextAssetDetailsArrayPage Successfully"));
                UPico_AssetDetailsArray* AssetDetailsArray = NewObject<UPico_AssetDetailsArray>();
                AssetDetailsArray->InitParams(ppf_Message_GetAssetDetailsArray(Message));
                this->GetNextAssetDetailsArrayPageDelegate.ExecuteIfBound(false, FString(), AssetDetailsArray);
                InGetNextAssetDetailsArrayPageDelegate.ExecuteIfBound(false, FString(), AssetDetailsArray);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::GetAssetFileStatusById(FString AssetFileID, FGetAssetFileStatus InGetAssetFileStatusByIdDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::GetAssetFileStatusById"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_StatusById(FStringTouint64(AssetFileID));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetAssetFileStatusByIdDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusById return failed:%s"), *ErrorMessage);
                this->GetAssetFileStatusByIdDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetAssetFileStatusByIdDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusById Successfully"));
                UPico_AssetStatus* AssetFileStatus = NewObject<UPico_AssetStatus>();
                AssetFileStatus->InitParams(ppf_Message_GetAssetStatus(Message));
                this->GetAssetFileStatusByIdDelegate.ExecuteIfBound(false, FString(), AssetFileStatus);
                InGetAssetFileStatusByIdDelegate.ExecuteIfBound(false, FString(), AssetFileStatus);
            }
        }));
    return true;
#endif
    return false;
}

bool FPicoAssetFileInterface::GetAssetFileStatusByName(FString AssetFileName, FGetAssetFileStatus InGetAssetFileStatusByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::GetAssetFileStatusByName"));
#if PLATFORM_ANDROID
    ppfRequest RequestId = ppf_AssetFile_StatusByName(TCHAR_TO_UTF8(*AssetFileName));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetAssetFileStatusByNameDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                FString ErrorCode = FString::FromInt(ppf_Error_GetCode(Error));
                ErrorMessage = ErrorMessage + FString(". Error Code: ") + ErrorCode;
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusByName return failed:%s"), *ErrorMessage);
                this->GetAssetFileStatusByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetAssetFileStatusByNameDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusByName Successfully"));
                UPico_AssetStatus* AssetFileStatus = NewObject<UPico_AssetStatus>();
                AssetFileStatus->InitParams(ppf_Message_GetAssetStatus(Message));
                this->GetAssetFileStatusByNameDelegate.ExecuteIfBound(false, FString(), AssetFileStatus);
                InGetAssetFileStatusByNameDelegate.ExecuteIfBound(false, FString(), AssetFileStatus);
            }
        }));
    return true;
#endif
    return false;
}

void FPicoAssetFileInterface::OnAssetFileDownloadUpdate(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::OnAssetFileDownloadUpdate"));
    if (bIsError)
    {
        UE_LOG(PicoAssetFile, Error, TEXT("AssetFileDownloadUpdate error!"));
    }

#if PLATFORM_ANDROID
    UPico_AssetFileDownloadUpdate* AssetFileDownloadUpdate = NewObject<UPico_AssetFileDownloadUpdate>();
    AssetFileDownloadUpdate->InitParams(ppf_Message_GetAssetFileDownloadUpdate(Message));
    AssetFileDownloadUpdateCallback.Broadcast(AssetFileDownloadUpdate);
#endif
}

void FPicoAssetFileInterface::OnAssetFileDeleteForSafety(ppfMessageHandle Message, bool bIsError)
{
    UE_LOG(PicoAssetFile, Log, TEXT("FPicoAssetFileInterface::OnAssetFileDeleteForSafety"));
    if (bIsError)
    {
        UE_LOG(PicoAssetFile, Error, TEXT("AssetFileDeleteForSafety error!"));
    }

#if PLATFORM_ANDROID
    UPico_AssetFileDeleteForSafety* AssetFileDeleteForSafety = NewObject<UPico_AssetFileDeleteForSafety>();
    AssetFileDeleteForSafety->InitParams(ppf_Message_GetAssetFileDeleteForSafety(Message));
    AssetFileDeleteForSafetyCallback.Broadcast(AssetFileDeleteForSafety);
#endif
}

bool UOnlinePicoAssetFileFunction::DeleteByID(UObject* WorldContextObject, FString AssetFileID, FAssetFileDeleteResult InDeleteByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DeleteByID"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DeleteByID(AssetFileID, InDeleteByIDDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DeleteByID Failed, PicoAssetFileInterface Not Vailed!"));
        InDeleteByIDDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}


bool UOnlinePicoAssetFileFunction::DeleteByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDeleteResult InDeleteByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DeleteByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DeleteByName(AssetFileName, InDeleteByNameDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DeleteByName Failed, PicoAssetFileInterface Not Vailed!"));
        InDeleteByNameDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::DownloadById(UObject* WorldContextObject, FString AssetFileID, FAssetFileDownloadResult InDownloadByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DownloadById"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DownloadById(AssetFileID, InDownloadByIDDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DownloadById Failed, PicoAssetFileInterface Not Vailed!"));
        InDownloadByIDDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::DownloadByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDownloadResult InDownloadByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DownloadByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DownloadByName(AssetFileName, InDownloadByNameDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DownloadByName Failed, PicoAssetFileInterface Not Vailed!"));
        InDownloadByNameDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::DownloadCancelById(UObject* WorldContextObject, FString AssetFileID, FAssetFileDownloadCancelResult InDownloadCancelByIDDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DownloadCancelById"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DownloadCancelById(AssetFileID, InDownloadCancelByIDDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelById Failed, PicoAssetFileInterface Not Vailed!"));
        InDownloadCancelByIDDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::DownloadCancelByName(UObject* WorldContextObject, FString AssetFileName, FAssetFileDownloadCancelResult InDownloadCancelByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::DownloadCancelByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->DownloadCancelByName(AssetFileName, InDownloadCancelByNameDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("DownloadCancelByName Failed, PicoAssetFileInterface Not Vailed!"));
        InDownloadCancelByNameDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::GetAssetFileList(UObject* WorldContextObject, FGetAssetFileList InGetAssetFileListDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::GetAssetFileList"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->GetAssetFileList(InGetAssetFileListDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileList Failed, PicoAssetFileInterface Not Vailed!"));
        InGetAssetFileListDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::GetNextAssetDetailsArrayPage(UObject* WorldContextObject, UPico_AssetDetailsArray* InAssetDetailsArray, FGetAssetFileList InGetNextAssetDetailsArrayPageDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::GetNextAssetDetailsArrayPage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->GetNextAssetDetailsArrayPage(InAssetDetailsArray, InGetNextAssetDetailsArrayPageDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("GetNextAssetDetailsArrayPage Failed, PicoAssetFileInterface Not Vailed!"));
        InGetNextAssetDetailsArrayPageDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::GetAssetFileStatusById(UObject* WorldContextObject, FString AssetFileID, FGetAssetFileStatus InGetAssetFileStatusByIdDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::GetAssetFileStatusById"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->GetAssetFileStatusById(AssetFileID, InGetAssetFileStatusByIdDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusById Failed, PicoAssetFileInterface Not Vailed!"));
        InGetAssetFileStatusByIdDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

bool UOnlinePicoAssetFileFunction::GetAssetFileStatusByName(UObject* WorldContextObject, FString AssetFileName, FGetAssetFileStatus InGetAssetFileStatusByNameDelegate)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UOnlinePicoAssetFileFunction::GetAssetFileStatusByName"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoAssetFileInterface())
    {
        return Subsystem->GetPicoAssetFileInterface()->GetAssetFileStatusByName(AssetFileName, InGetAssetFileStatusByNameDelegate);
    }
    else
    {
        UE_LOG(PicoAssetFile, Log, TEXT("GetAssetFileStatusByName Failed, PicoAssetFileInterface Not Vailed!"));
        InGetAssetFileStatusByNameDelegate.ExecuteIfBound(true, FString(TEXT("PicoAssetFileInterface Not Vailed")), nullptr);
        return false;
    }
}

void UPico_AssetFileDeleteResult::InitParams(ppfAssetFileDeleteResult* InppfAssetFileDeleteResultHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetFileDeleteResult::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetFileDeleteResult_GetAssetId(InppfAssetFileDeleteResultHandle);
    AssetId = uint64ToFString(ppfAssetId);
    FilePath = UTF8_TO_TCHAR(ppf_AssetFileDeleteResult_GetFilepath(InppfAssetFileDeleteResultHandle));
    bIsSuccessed = ppf_AssetFileDeleteResult_GetSuccess(InppfAssetFileDeleteResultHandle);
#endif
}

FString UPico_AssetFileDeleteResult::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetFileDeleteResult::GetFilePath()
{
    return FilePath;
}

bool UPico_AssetFileDeleteResult::GetSuccess()
{
    return bIsSuccessed;
}

ppfID UPico_AssetFileDeleteResult::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetDetails::InitParams(ppfAssetDetails* InppfAssetDetailsHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetDetails::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetDetails_GetAssetId(InppfAssetDetailsHandle);
    AssetId = uint64ToFString(ppfAssetId);
    FilePath = UTF8_TO_TCHAR(ppf_AssetDetails_GetFilepath(InppfAssetDetailsHandle));
    AssetType = UTF8_TO_TCHAR(ppf_AssetDetails_GetAssetType(InppfAssetDetailsHandle));
    DownloadStatus = UTF8_TO_TCHAR(ppf_AssetDetails_GetDownloadStatus(InppfAssetDetailsHandle));
    IapStatus = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapStatus(InppfAssetDetailsHandle));
    Metadata = UTF8_TO_TCHAR(ppf_AssetDetails_GetMetadata(InppfAssetDetailsHandle));
    Filename = UTF8_TO_TCHAR(ppf_AssetDetails_GetFilename(InppfAssetDetailsHandle));
    Version = ppf_AssetDetails_GetVersion(InppfAssetDetailsHandle);
    IapSku = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapSku(InppfAssetDetailsHandle));
    IapName = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapName(InppfAssetDetailsHandle));
    IapPrice = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapPrice(InppfAssetDetailsHandle));
    IapCurrency = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapCurrency(InppfAssetDetailsHandle));
    IapDescription = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapDescription(InppfAssetDetailsHandle));
    IapIconUrl = UTF8_TO_TCHAR(ppf_AssetDetails_GetIapIcon(InppfAssetDetailsHandle));
#endif
}

FString UPico_AssetDetails::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetDetails::GetFilePath()
{
    return FilePath;
}

FString UPico_AssetDetails::GetAssetType()
{
    return AssetType;
}

FString UPico_AssetDetails::GetDownloadStatus()
{
    return DownloadStatus;
}

FString UPico_AssetDetails::GetIapStatus()
{
    return IapStatus;
}

FString UPico_AssetDetails::GetMetadata()
{
    return Metadata;
}

FString UPico_AssetDetails::GetFilename()
{
    return Filename;
}

int32 UPico_AssetDetails::GetVersion()
{
    return Version;
}

FString UPico_AssetDetails::GetIapSku()
{
    return IapSku;
}

FString UPico_AssetDetails::GetIapName()
{
    return IapName;
}

FString UPico_AssetDetails::GetIapPrice()
{
    return IapPrice;
}

FString UPico_AssetDetails::GetIapCurrency()
{
    return IapCurrency;
}

FString UPico_AssetDetails::GetIapDescription()
{
    return IapDescription;
}

FString UPico_AssetDetails::GetIapIconUrl()
{
    return IapIconUrl;
}

ppfID UPico_AssetDetails::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetFileDownloadResult::InitParams(ppfAssetFileDownloadResult* InppfAssetFileDownloadResultHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetFileDownloadResult::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetFileDownloadResult_GetAssetId(InppfAssetFileDownloadResultHandle);
    AssetId = uint64ToFString(ppfAssetId);
    FilePath = UTF8_TO_TCHAR(ppf_AssetFileDownloadResult_GetFilepath(InppfAssetFileDownloadResultHandle));
#endif
}

FString UPico_AssetFileDownloadResult::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetFileDownloadResult::GetFilePath()
{
    return FilePath;
}

ppfID UPico_AssetFileDownloadResult::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetDetailsArray::InitParams(ppfAssetDetailsArray* InppfAssetDetailsArrayHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetDetailsArray::InitParams"));
#if PLATFORM_ANDROID
    Size = ppf_AssetDetailsArray_GetSize(InppfAssetDetailsArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_AssetDetails* ThisElement = NewObject<UPico_AssetDetails>();
        ThisElement->InitParams(ppf_AssetDetailsArray_GetElement(InppfAssetDetailsArrayHandle, i));
        AssetDetailsArray.Add(ThisElement);
    }
    bHasNextPage = ppf_AssetDetailsArray_HasNextPage(InppfAssetDetailsArrayHandle);
    if (bHasNextPage)
    {
        NextPageParam = ppf_AssetDetailsArray_GetNextPageParam(InppfAssetDetailsArrayHandle);
    }
#endif
}

UPico_AssetDetails* UPico_AssetDetailsArray::GetElement(int32 Index)
{
    if (AssetDetailsArray.IsValidIndex(Index))
    {
        return AssetDetailsArray[Index];
    }
    return nullptr;
}

int32 UPico_AssetDetailsArray::GetSize()
{
    return Size;
}

bool UPico_AssetDetailsArray::GetHasNextPage()
{
    return bHasNextPage;
}

FString UPico_AssetDetailsArray::GetNextPageParam()
{
    return NextPageParam;
}

void UPico_AssetFileDownloadCancelResult::InitParams(ppfAssetFileDownloadCancelResult* InppfAssetFileDownloadCancelResultHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetFileDownloadCancelResult::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetFileDownloadCancelResult_GetAssetId(InppfAssetFileDownloadCancelResultHandle);
    AssetId = uint64ToFString(ppfAssetId);
    FilePath = UTF8_TO_TCHAR(ppf_AssetFileDownloadCancelResult_GetFilepath(InppfAssetFileDownloadCancelResultHandle));
    bIsSuccessed = ppf_AssetFileDownloadCancelResult_GetSuccess(InppfAssetFileDownloadCancelResultHandle);
#endif
}

FString UPico_AssetFileDownloadCancelResult::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetFileDownloadCancelResult::GetFilePath()
{
    return FilePath;
}

bool UPico_AssetFileDownloadCancelResult::GetSuccess()
{
    return bIsSuccessed;
}

ppfID UPico_AssetFileDownloadCancelResult::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetFileDownloadUpdate::InitParams(ppfAssetFileDownloadUpdate* InppfAssetFileDownloadUpdateHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetFileDownloadUpdate::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetFileDownloadUpdate_GetAssetId(InppfAssetFileDownloadUpdateHandle);
    AssetId = uint64ToFString(ppfAssetId);
    BytesTotal = ppf_AssetFileDownloadUpdate_GetBytesTotal(InppfAssetFileDownloadUpdateHandle);
    BytesTransferred = ppf_AssetFileDownloadUpdate_GetBytesTransferred(InppfAssetFileDownloadUpdateHandle);
    ppfAssetFileDownloadCompleteStatus pAssetFileDownloadCompleteStatus = ppf_AssetFileDownloadUpdate_GetCompleteStatus(InppfAssetFileDownloadUpdateHandle);
    if (pAssetFileDownloadCompleteStatus == ppfAssetFileDownloadCompleteStatus_Downloading)
    {
        AssetFileDownloadCompleteStatus = EAssetFileDownloadCompleteStatus::Downloading;
    }
    else if (pAssetFileDownloadCompleteStatus == ppfAssetFileDownloadCompleteStatus_Succeed)
    {
        AssetFileDownloadCompleteStatus = EAssetFileDownloadCompleteStatus::Succeed;
    }
    else
    {
        AssetFileDownloadCompleteStatus = EAssetFileDownloadCompleteStatus::Failed;
    }
#endif
}

FString UPico_AssetFileDownloadUpdate::GetAssetId()
{
    return AssetId;
}

int64 UPico_AssetFileDownloadUpdate::GetBytesTotal()
{
    return BytesTotal;
}

int64 UPico_AssetFileDownloadUpdate::GetBytesTransferred()
{
    return BytesTransferred;
}

EAssetFileDownloadCompleteStatus UPico_AssetFileDownloadUpdate::GetCompleteStatus()
{
    return AssetFileDownloadCompleteStatus;
}

ppfID UPico_AssetFileDownloadUpdate::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetStatus::InitParams(ppfAssetStatus* InppfAssetStatusHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetStatus::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetStatus_GetAssetId(InppfAssetStatusHandle);
    AssetId = uint64ToFString(ppfAssetId);
    FileName = UTF8_TO_TCHAR(ppf_AssetStatus_GetFilename(InppfAssetStatusHandle));
    FilePath = UTF8_TO_TCHAR(ppf_AssetStatus_GetFilepath(InppfAssetStatusHandle));
    DownloadStatus = UTF8_TO_TCHAR(ppf_AssetStatus_GetDownloadStatus(InppfAssetStatusHandle));
#endif
}

FString UPico_AssetStatus::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetStatus::GetFilePath()
{
    return FilePath;
}

FString UPico_AssetStatus::GetFileName()
{
    return FileName;
}

FString UPico_AssetStatus::GetDownloadStatus()
{
    return DownloadStatus;
}

ppfID UPico_AssetStatus::GetppfAssetId()
{
    return ppfAssetId;
}

void UPico_AssetFileDeleteForSafety::InitParams(ppfAssetFileDeleteForSafety* InppfAssetFileDeleteForSafetyHandle)
{
    UE_LOG(PicoAssetFile, Log, TEXT("UPico_AssetFileDeleteForSafety::InitParams"));
#if PLATFORM_ANDROID
    ppfAssetId = ppf_AssetFileDeleteForSafety_GetAssetId(InppfAssetFileDeleteForSafetyHandle);
    AssetId = uint64ToFString(ppfAssetId);
    Reason = UTF8_TO_TCHAR(ppf_AssetFileDeleteForSafety_GetReason(InppfAssetFileDeleteForSafetyHandle));
#endif
}

FString UPico_AssetFileDeleteForSafety::GetAssetId()
{
    return AssetId;
}

FString UPico_AssetFileDeleteForSafety::GetReason()
{
    return Reason;
}

ppfID UPico_AssetFileDeleteForSafety::GetppfAssetId()
{
    return ppfAssetId;
}
