// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.


#include "Pico_IAP.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystemPico.h"
#include <vector>
#include <string>

DEFINE_LOG_CATEGORY(PicoIAP);

bool UOnlinePicoIAPFunction::ConsumePurchase(UObject* WorldContextObject, const FString& SKU, FConsumePurchaseDelegate InConsumePurchaseDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::ConsumePurchase"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->ConsumePurchase(SKU, InConsumePurchaseDelegate);
    }
    return false;
}

bool UOnlinePicoIAPFunction::GetProductsBySKU(UObject* WorldContextObject, TArray<FString> ProductSKUs, int32 Count, FGetProductsBySKUDelegate OnGetProductsBySKUCompleteDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::GetProductsBySKU"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->GetProductsBySKU(ProductSKUs, Count, OnGetProductsBySKUCompleteDelegate);
    }
    return false;
}

bool UOnlinePicoIAPFunction::GetNextProductsArrayPage(UObject* WorldContextObject, UPico_ProductArray* InProductArray, FGetNextProductArrayPageDelegate InGetNextProductArrayPageDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::GetNextProductsArrayPage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->GetNextProductsArrayPage(InProductArray, InGetNextProductArrayPageDelegate);
    }
    return false;
}

bool UOnlinePicoIAPFunction::GetViewerPurchases(UObject* WorldContextObject, FGetViewerPurchasesDelegate InGetViewerPurchasesDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::GetViewerPurchases"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->GetViewerPurchases(InGetViewerPurchasesDelegate);
    }
    return false;
}

bool UOnlinePicoIAPFunction::GetNextPurchaseArrayPage(UObject* WorldContextObject, UPico_PurchaseArray* InPurchaseArray, FGetNextPurchaseArrayPageDelegate InGetNextPurchaseArrayPageDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::GetNextPurchaseArrayPage"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->GetNextPurchaseArrayPage(InPurchaseArray, InGetNextPurchaseArrayPageDelegate);
    }
    return false;
}

bool UOnlinePicoIAPFunction::LaunchCheckoutFlow(UObject* WorldContextObject, const FString& SKU, const FString& Price, const FString& Currency, FLaunchCheckoutFlowDelegate InLaunchCheckoutFlowDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("UOnlinePicoIAPFunction::LaunchCheckoutFlow"));
    FOnlineSubsystemPico* Subsystem = static_cast<FOnlineSubsystemPico*>(Online::GetSubsystem(GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull), PICO_SUBSYSTEM));
    if (Subsystem && Subsystem->GetPicoIAPInterface())
    {
        return Subsystem->GetPicoIAPInterface()->LaunchCheckoutFlow(SKU, Price, Currency, InLaunchCheckoutFlowDelegate);
    }
    return false;
}

bool FPicoIAPInterface::ConsumePurchase(const FString& SKU, FConsumePurchaseDelegate InConsumePurchaseDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::ConsumePurchase"));
    ppfRequest RequestId = ppf_IAP_ConsumePurchase(TCHAR_TO_UTF8(*SKU));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InConsumePurchaseDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("PicoConsumePurchase return failed:%s"), *ErrorMessage);
                this->ConsumePurchaseDelegate.ExecuteIfBound(true, ErrorMessage);
                InConsumePurchaseDelegate.ExecuteIfBound(true, ErrorMessage);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("PicoConsumePurchase Successfully"));
                this->ConsumePurchaseDelegate.ExecuteIfBound(false, FString());
                InConsumePurchaseDelegate.ExecuteIfBound(false, FString());
            }
        }));
    return true;
}

bool FPicoIAPInterface::GetProductsBySKU(TArray<FString> ProductSKUs, int32 Count, FGetProductsBySKUDelegate InGetProductsBySKUDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::GetProductsBySKU"));
    //char* SKUsArray = NULL;
    //SKUsArray = new char[ProductSKUs.Num()];
    //for (size_t i = 0; i < ProductSKUs.Num(); i++)
    //{
    //    SKUsArray[i] = FCString::Atoi(*ProductSKUs[i]);
    //}
    //const char**  SKUsArray2 = NULL;
    //SKUsArray2 = new const char*[ProductSKUs.Num()];
    //for (size_t i = 0; i < ProductSKUs.Num(); i++)
    //{
    //    SKUsArray2[i] = &SKUsArray[i];
    //}
    std::vector<std::string> StringArray;
    for (size_t i = 0; i < ProductSKUs.Num(); i++)
    {
        StringArray.push_back(std::string(TCHAR_TO_UTF8(*(ProductSKUs[i]))));
    }
    std::vector<const char*> CharPtrArray;
    for (size_t i = 0; i < StringArray.size(); i++)
    {
        CharPtrArray.push_back(StringArray[i].c_str());
    }
    ppfRequest RequestId = ppf_IAP_GetProductsBySKU(CharPtrArray.data(), Count);
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetProductsBySKUDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("GetProductsBySKU return failed:%s"), *ErrorMessage);
                this->GetProductsBySKUDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetProductsBySKUDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("GetProductsBySKU Successfully"));
                UPico_ProductArray* Pico_ProductArray = NewObject<UPico_ProductArray>();
                Pico_ProductArray->InitParams(ppf_Message_GetProductArray(Message));
                this->GetProductsBySKUDelegate.ExecuteIfBound(false, FString(), Pico_ProductArray);
                InGetProductsBySKUDelegate.ExecuteIfBound(false, FString(), Pico_ProductArray);
            }
        }));
    return true;
}

bool FPicoIAPInterface::GetNextProductsArrayPage(UPico_ProductArray* InProductArray, FGetNextProductArrayPageDelegate InGetNextProductArrayPageDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::GetNextProductsArrayPage"));
    ppfRequest RequestId = ppf_IAP_GetNextProductArrayPage(TCHAR_TO_UTF8(*InProductArray->GetNextPageParam()));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetNextProductArrayPageDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("GetNextProductsArrayPage return failed:%s"), *ErrorMessage);
                this->GetNextProductArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetNextProductArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("GetNextProductsArrayPage Successfully"));
                UPico_ProductArray* Pico_ProductArray = NewObject<UPico_ProductArray>();
                Pico_ProductArray->InitParams(ppf_Message_GetProductArray(Message));
                this->GetNextProductArrayPageDelegate.ExecuteIfBound(false, FString(), Pico_ProductArray);
                InGetNextProductArrayPageDelegate.ExecuteIfBound(false, FString(), Pico_ProductArray);
            }
        }));
    return true;
}

bool FPicoIAPInterface::GetViewerPurchases(FGetViewerPurchasesDelegate InGetViewerPurchasesDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::GetViewerPurchases"));
    ppfRequest RequestId = ppf_IAP_GetViewerPurchases();
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetViewerPurchasesDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("GetViewerPurchases return failed:%s"), *ErrorMessage);
                this->GetViewerPurchasesDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetViewerPurchasesDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("GetViewerPurchases Successfully"));
                UPico_PurchaseArray* Pico_PurchaseArray = NewObject<UPico_PurchaseArray>();
                Pico_PurchaseArray->InitParams(ppf_Message_GetPurchaseArray(Message));
                this->GetViewerPurchasesDelegate.ExecuteIfBound(false, FString(), Pico_PurchaseArray);
                InGetViewerPurchasesDelegate.ExecuteIfBound(false, FString(), Pico_PurchaseArray);
            }
        }));
    return true;
}

bool FPicoIAPInterface::GetNextPurchaseArrayPage(UPico_PurchaseArray* InPurchaseArray, FGetNextPurchaseArrayPageDelegate InGetNextPurchaseArrayPageDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::GetNextPurchaseArrayPage"));
    ppfRequest RequestId = ppf_IAP_GetNextPurchaseArrayPage(TCHAR_TO_UTF8(*InPurchaseArray->GetNextPageParam()));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InGetNextPurchaseArrayPageDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("GetNextPurchaseArrayPage return failed:%s"), *ErrorMessage);
                this->GetNextPurchaseArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InGetNextPurchaseArrayPageDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("GetNextPurchaseArrayPage Successfully"));
                UPico_PurchaseArray* Pico_PurchaseArray = NewObject<UPico_PurchaseArray>();
                Pico_PurchaseArray->InitParams(ppf_Message_GetPurchaseArray(Message));
                this->GetNextPurchaseArrayPageDelegate.ExecuteIfBound(false, FString(), Pico_PurchaseArray);
                InGetNextPurchaseArrayPageDelegate.ExecuteIfBound(false, FString(), Pico_PurchaseArray);
            }
        }));
    return true;
}

bool FPicoIAPInterface::LaunchCheckoutFlow(const FString& SKU, const FString& Price, const FString& Currency, FLaunchCheckoutFlowDelegate InLaunchCheckoutFlowDelegate)
{
    UE_LOG(PicoIAP, Log, TEXT("FPicoIAPInterface::LaunchCheckoutFlow"));
    ppfRequest RequestId = ppf_IAP_LaunchCheckoutFlow(TCHAR_TO_UTF8(*SKU), TCHAR_TO_UTF8(*Price), TCHAR_TO_UTF8(*Currency));
    PicoSubsystem.AddAsyncTask(RequestId, FPicoMessageOnCompleteDelegate::CreateLambda(
        [InLaunchCheckoutFlowDelegate, this](ppfMessageHandle Message, bool bIsError)
        {
            if (bIsError)
            {
                auto Error = ppf_Message_GetError(Message);
                FString ErrorMessage = UTF8_TO_TCHAR(ppf_Error_GetMessage(Error));
                UE_LOG(PicoIAP, Log, TEXT("LaunchCheckoutFlow return failed:%s"), *ErrorMessage);
                this->LaunchCheckoutFlowDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
                InLaunchCheckoutFlowDelegate.ExecuteIfBound(true, ErrorMessage, nullptr);
            }
            else
            {
                UE_LOG(PicoIAP, Log, TEXT("LaunchCheckoutFlow Successfully"));
                UPico_Purchase* Pico_Purchase = NewObject<UPico_Purchase>();
                Pico_Purchase->InitParams(ppf_Message_GetPurchase(Message));
                this->LaunchCheckoutFlowDelegate.ExecuteIfBound(false, FString(), Pico_Purchase);
                InLaunchCheckoutFlowDelegate.ExecuteIfBound(false, FString(), Pico_Purchase);
            }
        }));
    return true;
}

void UPico_Product::InitParams(ppfProduct* InppfProductHandle)
{
    UE_LOG(PicoIAP, Log, TEXT("UPico_Product::InitParams"));
    Description = UTF8_TO_TCHAR(ppf_Product_GetDescription(InppfProductHandle));
    FormattedPrice = UTF8_TO_TCHAR(ppf_Product_GetFormattedPrice(InppfProductHandle));
    Price = UTF8_TO_TCHAR(ppf_Product_GetPrice(InppfProductHandle));
    Currency = UTF8_TO_TCHAR(ppf_Product_GetCurrency(InppfProductHandle));
    Name = UTF8_TO_TCHAR(ppf_Product_GetName(InppfProductHandle));
    SKU = UTF8_TO_TCHAR(ppf_Product_GetSKU(InppfProductHandle));
}

FString UPico_Product::GetDescription()
{
    return Description;
}

FString UPico_Product::GetFormattedPrice()
{
    return FormattedPrice;
}

FString UPico_Product::GetPrice()
{
    return Price;
}

FString UPico_Product::GetCurrency()
{
    return Currency;
}

FString UPico_Product::GetName()
{
    return Name;
}

FString UPico_Product::GetSKU()
{
    return SKU;
}

void UPico_ProductArray::InitParams(ppfProductArray* InppfProductArrayHandle)
{
    UE_LOG(PicoIAP, Log, TEXT("UPico_ProductArray::InitParams"));
    Size = ppf_ProductArray_GetSize(InppfProductArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_Product* ThisElement = NewObject<UPico_Product>();
        ThisElement->InitParams(ppf_ProductArray_GetElement(InppfProductArrayHandle, i));
        ProductArray.Add(ThisElement);
    }
    bHasNextPage = ppf_ProductArray_HasNextPage(InppfProductArrayHandle);
    if (bHasNextPage)
    {
        NextPageParam = ppf_ProductArray_GetNextPageParam(InppfProductArrayHandle);
    }
}

UPico_Product* UPico_ProductArray::GetElement(int32 Index)
{
    if (ProductArray.IsValidIndex(Index))
    {
        return ProductArray[Index];
    }
    return nullptr;
}

FString UPico_ProductArray::GetNextPageParam()
{
    return NextPageParam;
}

int32 UPico_ProductArray::GetSize()
{
    return Size;
}

bool UPico_ProductArray::HasNextPage()
{
    return bHasNextPage;
}

void UPico_Purchase::InitParams(ppfPurchase* InppfPurchaseHandle)
{
    UE_LOG(PicoIAP, Log, TEXT("UPico_Purchase::InitParams"));
    ExpirationTime = ppf_Purchase_GetExpirationTime(InppfPurchaseHandle);
    GrantTime = ppf_Purchase_GetGrantTime(InppfPurchaseHandle);
    ID = ppf_Purchase_GetID(InppfPurchaseHandle);
    SKU = ppf_Purchase_GetSKU(InppfPurchaseHandle);
}

int64 UPico_Purchase::GetExpirationTime()
{
    return ExpirationTime;
}

int64 UPico_Purchase::GetGrantTime()
{
    return GrantTime;
}

FString UPico_Purchase::GetID()
{
    return ID;
}

FString UPico_Purchase::GetSKU()
{
    return SKU;
}

void UPico_PurchaseArray::InitParams(ppfPurchaseArray* InppfPurchaseArrayHandle)
{
    UE_LOG(PicoIAP, Log, TEXT("UPico_PurchaseArray::InitParams"));
    Size = ppf_PurchaseArray_GetSize(InppfPurchaseArrayHandle);
    for (int32 i = 0; i < Size; i++)
    {
        UPico_Purchase* ThisElement = NewObject<UPico_Purchase>();
        ThisElement->InitParams(ppf_PurchaseArray_GetElement(InppfPurchaseArrayHandle, i));
        PurchaseArray.Add(ThisElement);
    }
    bHasNextPage = ppf_PurchaseArray_HasNextPage(InppfPurchaseArrayHandle);
    if (bHasNextPage)
    {
        NextPageParam = ppf_PurchaseArray_GetNextPageParam(InppfPurchaseArrayHandle);
    }
}

UPico_Purchase* UPico_PurchaseArray::GetElement(int32 Index)
{
    if (PurchaseArray.IsValidIndex(Index))
    {
        return PurchaseArray[Index];
    }
    return nullptr;
}

FString UPico_PurchaseArray::GetNextPageParam()
{
    return NextPageParam;
}

int32 UPico_PurchaseArray::GetSize()
{
    return Size;
}

bool UPico_PurchaseArray::HasNextPage()
{
    return bHasNextPage;
}

FPicoIAPInterface::FPicoIAPInterface(FOnlineSubsystemPico& InSubsystem) :
    PicoSubsystem(InSubsystem)
{

}

FPicoIAPInterface::~FPicoIAPInterface()
{

}

