// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pico_IAP.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UPico_Product;
class UPico_ProductArray;
class UPico_Purchase;
class UPico_PurchaseArray;
class UPico_SubscriptionStatus;
enum class EAddonsType : uint8;
enum class ECancelReason : uint8;
enum class EDiscountType : uint8;
enum class EEntitlementStatus : uint8;
enum class EPeriodType : uint8;
#ifdef ONLINESUBSYSTEMPICO_Pico_IAP_generated_h
#error "Pico_IAP.generated.h already included, missing '#pragma once' in Pico_IAP.h"
#endif
#define ONLINESUBSYSTEMPICO_Pico_IAP_generated_h

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_18_DELEGATE \
ONLINESUBSYSTEMPICO_API void FGetProductsBySKUDelegate_DelegateWrapper(const FScriptDelegate& GetProductsBySKUDelegate, bool bIsError, const FString& ErrorMessage, UPico_ProductArray* ProductArray);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_19_DELEGATE \
ONLINESUBSYSTEMPICO_API void FGetViewerPurchasesDelegate_DelegateWrapper(const FScriptDelegate& GetViewerPurchasesDelegate, bool bIsError, const FString& ErrorMessage, UPico_PurchaseArray* PurchaseArray);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_20_DELEGATE \
ONLINESUBSYSTEMPICO_API void FGetNextProductArrayPageDelegate_DelegateWrapper(const FScriptDelegate& GetNextProductArrayPageDelegate, bool bIsError, const FString& ErrorMessage, UPico_ProductArray* ProductArray);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_21_DELEGATE \
ONLINESUBSYSTEMPICO_API void FConsumePurchaseDelegate_DelegateWrapper(const FScriptDelegate& ConsumePurchaseDelegate, bool bIsError, const FString& ErrorMessage);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_22_DELEGATE \
ONLINESUBSYSTEMPICO_API void FGetNextPurchaseArrayPageDelegate_DelegateWrapper(const FScriptDelegate& GetNextPurchaseArrayPageDelegate, bool bIsError, const FString& ErrorMessage, UPico_PurchaseArray* PurchaseArray);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_23_DELEGATE \
ONLINESUBSYSTEMPICO_API void FLaunchCheckoutFlowDelegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlowDelegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_24_DELEGATE \
ONLINESUBSYSTEMPICO_API void FLaunchCheckoutFlow_V2Delegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlow_V2Delegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_25_DELEGATE \
ONLINESUBSYSTEMPICO_API void FGetSubscriptionStatusDelegate_DelegateWrapper(const FScriptDelegate& GetSubscriptionStatusDelegate, bool bIsError, const FString& ErrorMessage, UPico_SubscriptionStatus* SubscriptionStatus);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_26_DELEGATE \
ONLINESUBSYSTEMPICO_API void FLaunchCheckoutFlow_V3Delegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlow_V3Delegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLaunchCheckoutFlowV3); \
	DECLARE_FUNCTION(execGetSubscriptionStatus); \
	DECLARE_FUNCTION(execLaunchCheckoutFlowV2); \
	DECLARE_FUNCTION(execLaunchCheckoutFlow); \
	DECLARE_FUNCTION(execGetNextPurchaseArrayPage); \
	DECLARE_FUNCTION(execGetViewerPurchases); \
	DECLARE_FUNCTION(execGetNextProductsArrayPage); \
	DECLARE_FUNCTION(execGetProductsBySKU); \
	DECLARE_FUNCTION(execConsumePurchase);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoIAPFunction(); \
	friend struct Z_Construct_UClass_UOnlinePicoIAPFunction_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoIAPFunction, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoIAPFunction)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoIAPFunction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoIAPFunction(UOnlinePicoIAPFunction&&); \
	NO_API UOnlinePicoIAPFunction(const UOnlinePicoIAPFunction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoIAPFunction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoIAPFunction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoIAPFunction) \
	NO_API virtual ~UOnlinePicoIAPFunction();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_203_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_206_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoIAPFunction>();

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetIsContinuous); \
	DECLARE_FUNCTION(execGetOriginalPrice); \
	DECLARE_FUNCTION(execGetOuterId); \
	DECLARE_FUNCTION(execGetTrialPeriodValue); \
	DECLARE_FUNCTION(execGetTrialPeriodUnit); \
	DECLARE_FUNCTION(execGetPeriodType); \
	DECLARE_FUNCTION(execGetAddonsType); \
	DECLARE_FUNCTION(execGetIcon); \
	DECLARE_FUNCTION(execGetSKU); \
	DECLARE_FUNCTION(execGetName); \
	DECLARE_FUNCTION(execGetCurrency); \
	DECLARE_FUNCTION(execGetFormattedPrice); \
	DECLARE_FUNCTION(execGetPrice); \
	DECLARE_FUNCTION(execGetDetailDescription); \
	DECLARE_FUNCTION(execGetDescription);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_Product(); \
	friend struct Z_Construct_UClass_UPico_Product_Statics; \
public: \
	DECLARE_CLASS(UPico_Product, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_Product)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_Product(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_Product(UPico_Product&&); \
	NO_API UPico_Product(const UPico_Product&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_Product); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_Product); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_Product) \
	NO_API virtual ~UPico_Product();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_367_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_370_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_Product>();

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHasNextPage); \
	DECLARE_FUNCTION(execGetSize); \
	DECLARE_FUNCTION(execGetNextPageParam); \
	DECLARE_FUNCTION(execGetElement);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_ProductArray(); \
	friend struct Z_Construct_UClass_UPico_ProductArray_Statics; \
public: \
	DECLARE_CLASS(UPico_ProductArray, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_ProductArray)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_ProductArray(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_ProductArray(UPico_ProductArray&&); \
	NO_API UPico_ProductArray(const UPico_ProductArray&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_ProductArray); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_ProductArray); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_ProductArray) \
	NO_API virtual ~UPico_ProductArray();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_460_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_463_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_ProductArray>();

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetOrderComment); \
	DECLARE_FUNCTION(execGetDiscountType); \
	DECLARE_FUNCTION(execGetNextPayTime); \
	DECLARE_FUNCTION(execGetOuterId); \
	DECLARE_FUNCTION(execGetNextPeriodType); \
	DECLARE_FUNCTION(execGetCurrentPeriodType); \
	DECLARE_FUNCTION(execGetAddonsType); \
	DECLARE_FUNCTION(execGetIcon); \
	DECLARE_FUNCTION(execGetSKU); \
	DECLARE_FUNCTION(execGetID); \
	DECLARE_FUNCTION(execGetGrantTime); \
	DECLARE_FUNCTION(execGetExpirationTime);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_Purchase(); \
	friend struct Z_Construct_UClass_UPico_Purchase_Statics; \
public: \
	DECLARE_CLASS(UPico_Purchase, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_Purchase)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_Purchase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_Purchase(UPico_Purchase&&); \
	NO_API UPico_Purchase(const UPico_Purchase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_Purchase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_Purchase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_Purchase) \
	NO_API virtual ~UPico_Purchase();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_497_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_500_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_Purchase>();

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHasNextPage); \
	DECLARE_FUNCTION(execGetSize); \
	DECLARE_FUNCTION(execGetNextPageParam); \
	DECLARE_FUNCTION(execGetElement);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_PurchaseArray(); \
	friend struct Z_Construct_UClass_UPico_PurchaseArray_Statics; \
public: \
	DECLARE_CLASS(UPico_PurchaseArray, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_PurchaseArray)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_PurchaseArray(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_PurchaseArray(UPico_PurchaseArray&&); \
	NO_API UPico_PurchaseArray(const UPico_PurchaseArray&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_PurchaseArray); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_PurchaseArray); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_PurchaseArray) \
	NO_API virtual ~UPico_PurchaseArray();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_573_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_576_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_PurchaseArray>();

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetNextPeriod); \
	DECLARE_FUNCTION(execGetIsFreeTrial); \
	DECLARE_FUNCTION(execGetCancelReason); \
	DECLARE_FUNCTION(execGetEntitlementStatus); \
	DECLARE_FUNCTION(execGetCurrentPeriodType); \
	DECLARE_FUNCTION(execGetEndTime); \
	DECLARE_FUNCTION(execGetStartTime); \
	DECLARE_FUNCTION(execGetOuterId); \
	DECLARE_FUNCTION(execGetSKU);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_SubscriptionStatus(); \
	friend struct Z_Construct_UClass_UPico_SubscriptionStatus_Statics; \
public: \
	DECLARE_CLASS(UPico_SubscriptionStatus, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_SubscriptionStatus)


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_SubscriptionStatus(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_SubscriptionStatus(UPico_SubscriptionStatus&&); \
	NO_API UPico_SubscriptionStatus(const UPico_SubscriptionStatus&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_SubscriptionStatus); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_SubscriptionStatus); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_SubscriptionStatus) \
	NO_API virtual ~UPico_SubscriptionStatus();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_610_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_613_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_SubscriptionStatus>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
