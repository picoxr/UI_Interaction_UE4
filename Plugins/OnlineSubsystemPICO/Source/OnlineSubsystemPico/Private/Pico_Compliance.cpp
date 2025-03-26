// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 


#include "Pico_Compliance.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"

DEFINE_LOG_CATEGORY(PicoCompliance);

FPicoComplianceInterface::FPicoComplianceInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoComplianceInterface::~FPicoComplianceInterface()
{

}

bool FPicoComplianceInterface::DetectSensitive(EDetectSensitiveScene DetectSensitiveScene, const FString& InDetectContent, FDetectSensitive InDelegate)
{
    UE_LOG(PicoCompliance, Log, TEXT("FPicoComplianceInterface::DetectSensitive"));
#if PLATFORM_ANDROID
    
    ppfDetectSensitiveScene pDetectSensitiveScene = ppfDetectSensitiveScene_UserName;
    if (DetectSensitiveScene == EDetectSensitiveScene::RoomChat)
    {
        pDetectSensitiveScene = ppfDetectSensitiveScene_RoomChat;
    }
    else if (DetectSensitiveScene == EDetectSensitiveScene::RoomName)
    {
        pDetectSensitiveScene = ppfDetectSensitiveScene_RoomName;
    }

    ppfRequest RequestId = ppf_Compliance_DetectSensitive(pDetectSensitiveScene, TCHAR_TO_UTF8(*InDetectContent));

    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                int ErrorCode = ppf_Error_GetCode(Error);
                UE_LOG(PicoCompliance, Log, TEXT("DetectSensitive return failed: %d, %s"), ErrorCode, *ErrorMessage);
                this->DetectSensitiveDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
                InDelegate.ExecuteIfBound(true, ErrorCode, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoCompliance, Log, TEXT("DetectSensitive Successfully"));
                UPico_DetectSensitiveResult* Result = NewObject<UPico_DetectSensitiveResult>();
                Result->InitParams(ppf_Message_GetDetectSensitiveResult(Message));
                this->DetectSensitiveDelegate.ExecuteIfBound(false, 0, FString(), Result);
                InDelegate.ExecuteIfBound(false, 0, FString(), Result);
            }
        }));
    return true;
#endif
    return false;
}

bool UOnlinePicoComplianceFunction::DetectSensitive(UObject* WorldContextObject, EDetectSensitiveScene DetectSensitiveScene, const FString& InDetectContent, FDetectSensitive InDelegate)
{
    UE_LOG(PicoCompliance, Log, TEXT("UOnlinePicoComplianceFunction::DetectSensitive"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoComplianceInterface())
    {
        return Subsystem->GetPicoComplianceInterface()->DetectSensitive(DetectSensitiveScene, InDetectContent, InDelegate);
    }
    else
    {
        UE_LOG(PicoCompliance, Log, TEXT("DetectSensitive Failed, PicoComplianceInterface Not Vailed!"));
        InDelegate.ExecuteIfBound(true, 0, FString(TEXT("PicoComplianceInterface Not Vailed")), nullptr);
        return false;
    }
}


void UPico_DetectSensitiveResult::InitParams(ppfDetectSensitiveResult* ppfDetectSensitiveResultHandle)
{
    UE_LOG(PicoCompliance, Log, TEXT("UPico_DetectSensitiveResult::InitParams"));
#if PLATFORM_ANDROID
    FilteredText = UTF8_TO_TCHAR(ppf_DetectSensitiveResult_GetFilteredText(ppfDetectSensitiveResultHandle));
    ppfSensitiveProposal pSensitiveProposal = ppf_DetectSensitiveResult_GetProposal(ppfDetectSensitiveResultHandle);
    
    switch (pSensitiveProposal)
    {
    case ppfSensitiveProposal_Pass:
        SensitiveProposal = ESensitiveProposal::Pass;
        break;
    case ppfSensitiveProposal_OnlySelfVisible:
        SensitiveProposal = ESensitiveProposal::OnlySelfVisible;
        break;
    case ppfSensitiveProposal_UserMute:
        SensitiveProposal = ESensitiveProposal::UserMute;
        break;
    case ppfSensitiveProposal_RejectSubmit:
        SensitiveProposal = ESensitiveProposal::RejectSubmit;
        break;
    default:
        break;
    }
#endif
}

ESensitiveProposal UPico_DetectSensitiveResult::GetSensitiveProposal()
{
    return SensitiveProposal;
}

FString UPico_DetectSensitiveResult::GetFilteredText()
{
    return FilteredText;
}

