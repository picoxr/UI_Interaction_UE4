// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PPF_Platform.h"
#include "OnlineSubsystemPico.h"
#include "Pico_IAP.generated.h"

/// @file Pico_IAP.h

DECLARE_LOG_CATEGORY_EXTERN(PicoIAP, Log, All);
/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetProductsBySKUDelegate, bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray*, ProductArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetViewerPurchasesDelegate, bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetNextProductArrayPageDelegate, bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray*, ProductArray);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FConsumePurchaseDelegate, bool, bIsError, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FGetNextPurchaseArrayPageDelegate, bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray*, PurchaseArray);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FLaunchCheckoutFlowDelegate, bool, bIsError, const FString&, ErrorMessage, UPico_Purchase*, Purchase);

/** @addtogroup Function Function
 *  This is the Function group
 *  @{
 */

/** @defgroup IAP IAP
 *  This is the IAP group
 *  @{
 */

/// @brief PicoIAPInterface class.
class ONLINESUBSYSTEMPICO_API FPicoIAPInterface
{
private:

    FOnlineSubsystemPico& PicoSubsystem;

public:
	FPicoIAPInterface(FOnlineSubsystemPico& InSubsystem);
    ~FPicoIAPInterface();

	FConsumePurchaseDelegate ConsumePurchaseDelegate;
	FGetProductsBySKUDelegate GetProductsBySKUDelegate;
	FGetNextProductArrayPageDelegate GetNextProductArrayPageDelegate;
	FGetViewerPurchasesDelegate GetViewerPurchasesDelegate;
	FGetNextPurchaseArrayPageDelegate GetNextPurchaseArrayPageDelegate;
	FLaunchCheckoutFlowDelegate LaunchCheckoutFlowDelegate;

    /// <summary>Records the order fulfillment result for a consumable.
    /// @note Users are unable to repurchase the same consumable until the previous order is fulfilled.
    /// </summary>
    /// <param name ="SKU">The SKU of the product.</param> 
    /// <param name ="InConsumePurchaseDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool ConsumePurchase(const FString& SKU, FConsumePurchaseDelegate InConsumePurchaseDelegate);

    /// <summary>Gets a list of purchasable products in the current app.</summary>
    /// <param name ="ProductSKUs">The SKUs of products. If this parameter is empty, all purchasable products will be returned.
    /// If SKUs are specified, products with corresponding SKUs will be returned.</param>
    /// <param name ="Count">The number of 'ProductSKUs' arrays to return.</param> 
    /// <param name ="InGetProductsBySKUDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool GetProductsBySKU(TArray<FString> ProductSKUs, int32 Count, FGetProductsBySKUDelegate InGetProductsBySKUDelegate);

    /// <summary>Gets the next page of purchasable products.</summary>
    /// <param name ="InProductArray">The current object of product array.</param> 
    /// <param name ="InGetNextProductArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool GetNextProductsArrayPage(UPico_ProductArray* InProductArray, FGetNextProductArrayPageDelegate InGetNextProductArrayPageDelegate);

    /// <summary>Gets a list of purchased products for a user.
    /// @note This list includes consumables that have not been fulfilled and products that are permanently available after one purchase.
    /// </summary>
    /// <param name ="InGetViewerPurchasesDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool GetViewerPurchases(FGetViewerPurchasesDelegate InGetViewerPurchasesDelegate);

    /// <summary>Gets the next page of purchased products.</summary>
    /// <param name ="InPurchaseArray">The current object of purchase array.</param> 
    /// <param name ="InGetNextPurchaseArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool GetNextPurchaseArrayPage(UPico_PurchaseArray* InPurchaseArray, FGetNextPurchaseArrayPageDelegate InGetNextPurchaseArrayPageDelegate);

    /// <summary>
    /// Launches the checkout flow to pay for a product.
    /// @note PICO tries to handle and fix as many errors as possible. Home returns the
    /// appropriate error message and how to resolve it if possible. Returns a
    /// purchase on success, empty purchase on cancel, and an error on error.
    /// </summary>
    /// <param name ="SKU">The SKU of the product the user wants to purchase.</param> 
    /// <param name ="Price">The price for the product.</param> 
    /// <param name ="Currency">The currency of the payment.</param> 
    /// <param name ="InLaunchCheckoutFlowDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	bool LaunchCheckoutFlow(const FString& SKU, const FString& Price, const FString& Currency, FLaunchCheckoutFlowDelegate InLaunchCheckoutFlowDelegate);

};

/** @} */
/** @} */

/** @addtogroup BlueprintFunction BlueprintFunction
 *  This is the BlueprintFunction group
 *  @{
 */

/** @defgroup BP_IAP BP_IAP
 *  This is the BP_IAP group
 *  @{
 */

/// @brief OnlinePicoIAP Blueprint Function class.
UCLASS()
class ONLINESUBSYSTEMPICO_API UOnlinePicoIAPFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:


	/// <summary>Records the order fulfillment result for a consumable.
	/// @note Users are unable to repurchase the same consumable until the previous order is fulfilled.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SKU">The SKU of the product.</param> 
    /// <param name ="InConsumePurchaseDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool ConsumePurchase(UObject* WorldContextObject,const FString& SKU, FConsumePurchaseDelegate InConsumePurchaseDelegate);

    /// <summary>Gets a list of purchasable products in the current app.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="ProductSKUs">The SKUs of products.</param> 
    /// <param name ="Count">The number of ProductSKUs arrays to return.</param> 
    /// <param name ="InGetProductsBySKUDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool GetProductsBySKU(UObject* WorldContextObject, TArray<FString> ProductSKUs, int32 Count, FGetProductsBySKUDelegate InGetProductsBySKUDelegate);

    /// <summary>Gets the next page of purchasable products.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="InProductArray">The current object of product array.</param> 
    /// <param name ="InGetNextProductArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool GetNextProductsArrayPage(UObject* WorldContextObject, UPico_ProductArray* InProductArray, FGetNextProductArrayPageDelegate InGetNextProductArrayPageDelegate);

    /// <summary>Gets a list of purchased products for a user in the current app.
	/// @note This list includes consumables that have not been fulfilled and products that are permanently available after one purchase.
	/// </summary>
	/// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="InGetViewerPurchasesDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool GetViewerPurchases(UObject* WorldContextObject, FGetViewerPurchasesDelegate InGetViewerPurchasesDelegate);

    /// <summary>Gets the next page of purchased products.</summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="InPurchaseArray">The current object of purchase array.</param> 
    /// <param name ="InGetNextPurchaseArrayPageDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool GetNextPurchaseArrayPage(UObject* WorldContextObject, UPico_PurchaseArray* InPurchaseArray, FGetNextPurchaseArrayPageDelegate InGetNextPurchaseArrayPageDelegate);

    /// <summary>
    /// Launches the checkout flow to purchase a product.
    /// @note PICO tries to handle and fix as many errors as possible. Home returns the
    /// appropriate error message and how to resolve it if possible. Returns a
    /// purchase on success, empty purchase on cancel, and an error on error.
    /// </summary>
    /// <param name ="WorldContextObject">Used to get the information about the current world.</param> 
    /// <param name ="SKU">The SKU of the product to purchase.</param> 
    /// <param name ="Price">The price for the product.</param> 
    /// <param name ="Currency">The currency of the payment.</param> 
    /// <param name ="InLaunchCheckoutFlowDelegate">Will be executed when the request has been completed. Delegate will contain the requested object class.</param> 
    /// <returns>Bool: 
    /// <ul>
    /// <li>`true`: success</li>
    /// <li>`false`: failure</li>
    /// </ul>
    /// </returns>
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"), Category = "OnlinePico|IAP")
	static bool LaunchCheckoutFlow(UObject* WorldContextObject, const FString& SKU, const FString& Price, const FString& Currency, FLaunchCheckoutFlowDelegate InLaunchCheckoutFlowDelegate);
};

/** @} */
/** @} */

/**
 * PPF_Product.h
 */
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Product : public UObject
{
	GENERATED_BODY()

private:
	FString Description = FString();
	FString FormattedPrice = FString();
	FString Price = FString();
	FString Currency = FString();
	FString Name = FString();
	FString SKU = FString();
public:
	void InitParams(ppfProduct* InppfProductHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetDescription();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetFormattedPrice();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetPrice();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetCurrency();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetName();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product")
	FString GetSKU();
};

/**
 * PPF_ProductArray.h
 */
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_ProductArray : public UObject
{
	GENERATED_BODY()

private:

    UPROPERTY()
	TArray<UPico_Product*> ProductArray;
	int32 Size = 0;
	bool bHasNextPage;
	FString NextPageParam = FString();

public:
	void InitParams(ppfProductArray* InppfProductArrayHandle);

    UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product Array")
	UPico_Product* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product Array")
    FString GetNextPageParam();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product Array")
    int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Product Array")
    bool HasNextPage();
};

/**
 * PPF_Purchase.h
 */
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_Purchase : public UObject
{
	GENERATED_BODY()

private:
	int64 ExpirationTime = 0;
	int64 GrantTime = 0;
	FString ID = FString();
	FString SKU = FString();
public:
	void InitParams(ppfPurchase* InppfPurchaseHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase")
	int64 GetExpirationTime();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase")
	int64 GetGrantTime();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase")
	FString GetID();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase")
	FString GetSKU();
};

/**
 * PPF_PurchaseArray.h
 */
UCLASS(BlueprintType)
class ONLINESUBSYSTEMPICO_API UPico_PurchaseArray : public UObject
{
	GENERATED_BODY()

private:

    UPROPERTY()
	TArray<UPico_Purchase*> PurchaseArray;
	int32 Size = 0;
	bool bHasNextPage;
	FString NextPageParam = FString();

public:
	void InitParams(ppfPurchaseArray* InppfPurchaseArrayHandle);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase Array")
	UPico_Purchase* GetElement(int32 Index);

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase Array")
	FString GetNextPageParam();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase Array")
	int32 GetSize();

	UFUNCTION(BlueprintPure, Category = "Pico Platform|IAP|Purchase Array")
	bool HasNextPage();
};